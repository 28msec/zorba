
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008 Free Software
   Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* First part of user declarations.  */

/* Line 311 of lalr1.cc  */
#line 60 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"


#include "common/common.h"

#ifdef _WIN32
#pragma warning(disable: 4786)
#endif

#include <string>

#include "compiler/parsetree/parsenodes.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/api/compilercb.h"
#include "store/api/update_consts.h"

#define SYMTAB( n ) driver.symtab.get ((off_t) n)
#define SYMTAB_PUT( s ) driver.symtab.put (s)
#define LOC( p ) driver.createQueryLoc(p)

namespace zorba
{
namespace parser
{
  extern const char *the_tumbling, *the_sliding, *the_start, *the_end, *the_only_end, *the_ofor, *the_declare, *the_create;
}
}

#define YYDEBUG 1



/* Line 311 of lalr1.cc  */
#line 75 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 914 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_driver.h"
#include "compiler/parser/xquery_scanner.h"
#undef yylex
#define yylex driver.lexer->lex


/* Line 317 of lalr1.cc  */
#line 92 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"

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

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

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

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


/* Line 380 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

namespace zorba {

/* Line 380 of lalr1.cc  */
#line 161 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
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
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
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
#endif

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
        case 102: /* "\"'DECIMAL'\"" */

/* Line 480 of lalr1.cc  */
#line 799 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 268 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 114: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 798 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 277 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 138: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 797 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 286 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 316: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 295 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 317: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 304 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 313 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 322 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "Prolog" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 331 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 340 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 349 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 358 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 367 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 376 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 810 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->pair_vector); };

/* Line 480 of lalr1.cc  */
#line 385 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 810 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->pair); };

/* Line 480 of lalr1.cc  */
#line 394 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 403 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 412 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 421 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 430 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 439 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 448 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 457 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 466 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 475 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 484 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 493 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 502 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 511 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 520 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 529 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 538 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 547 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 556 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 565 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 810 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 574 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 583 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "DeclPropertyList" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 592 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "DeclProperty" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 601 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 610 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "NodeModifier" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 619 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 628 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 637 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 646 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 655 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 664 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 810 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 673 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 682 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "Block" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 691 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "BlockDecls" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 700 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "BlockVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 709 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "BlockVarDecl" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 718 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "AssignExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 727 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "ExitExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 736 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "WhileExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 745 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 754 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 763 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 772 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "FunctionDecl3" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 781 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 790 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "FunctionDecl4" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 799 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 817 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "EnclosedExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 826 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 835 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 844 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 853 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "ApplyExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 862 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "ConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 871 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 880 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 889 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 898 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 907 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 916 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 925 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 934 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 943 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 952 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 961 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 970 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 979 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 988 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 997 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "EvalVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1006 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1015 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1024 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1033 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1042 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1051 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "EvalVarDecl" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1060 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1069 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1078 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1087 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1096 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1105 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1114 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1123 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1132 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1141 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1150 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1159 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1168 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1177 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1186 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1195 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1204 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1213 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1222 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1231 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1240 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1249 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1258 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1267 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1276 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1285 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1294 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1303 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1312 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1321 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1330 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1339 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1348 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1357 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1366 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1375 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1384 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1393 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1402 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1411 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "PragmaList" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1420 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1429 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1438 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1447 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1456 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1465 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1474 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1483 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1492 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1501 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1510 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1519 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1528 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1537 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1546 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1555 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1564 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1573 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1582 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1591 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1600 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1609 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1618 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1627 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1636 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1645 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1654 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1663 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1672 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1681 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1690 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1699 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1708 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1717 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "Opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1726 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1735 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "Opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1744 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1753 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1762 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1771 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1780 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1789 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1798 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1807 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1816 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1825 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1834 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1843 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1852 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1861 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1870 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1879 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1888 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1897 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1906 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1915 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1924 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1933 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1942 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1951 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1960 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1969 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1978 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1987 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1996 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2005 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2014 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2023 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2032 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2041 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2050 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2059 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2068 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2077 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2086 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2095 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2104 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2113 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2122 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2131 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2140 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 810 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2149 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2158 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "EvalExpr" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2167 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
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

#if YYDEBUG
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
#endif

  int
  xquery_parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    
/* Line 553 of lalr1.cc  */
#line 109 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename);
}

/* Line 553 of lalr1.cc  */
#line 2252 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"

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

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a lookahead token.  */
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

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
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

/* Line 678 of lalr1.cc  */
#line 932 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 942 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
            driver.set_expr ((yyval.node));
        }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 947 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<MainModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
            driver.set_expr ((yyval.node));
        }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 953 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
       driver.set_expr ((yyval.node));
        }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 958 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
       driver.set_expr ((yyval.node));
        }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 970 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)), encoding);
        }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 975 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 985 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new MainModule(LOC ((yyloc)),
                                static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)),
                                static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)));
        }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 992 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new MainModule(LOC ((yyloc)),
                                static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)),
                NULL);
        }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1004 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC ((yyloc)),
                             static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)),
                             NULL);
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1010 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LibraryModule(LOC ((yyloc)),
                                static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
                                static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1022 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ModuleDecl(LOC ((yyloc)),
                                SYMTAB ((yysemantic_stack_[(6) - (3)].sval)),
                                SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
      dynamic_cast<ModuleDecl *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
        }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1035 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)), NULL);
        }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1039 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
        }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1043 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Prolog(LOC((yyloc)),
                      static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
                      static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
        }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1055 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            SIND_DeclList* sindList_p = new SIND_DeclList(LOC ((yyloc)));
            sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
            (yyval.node) = sindList_p;
        }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1061 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            SIND_DeclList* sindList_p = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            if (sindList_p) {
                sindList_p->push_back((yysemantic_stack_[(3) - (3)].node));
            }
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1075 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList* vfoList_p = new VFO_DeclList(LOC ((yyloc)));
            vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
            (yyval.node) = vfoList_p;
        }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1081 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VFO_DeclList* vfoList_p = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
            if (vfoList_p) {
                vfoList_p->push_back((yysemantic_stack_[(3) - (3)].node));
            }
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 1127 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].pair_vector));
      delete (yysemantic_stack_[(4) - (4)].pair_vector);
    }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 1132 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr))->get_qname(), (yysemantic_stack_[(4) - (4)].pair_vector));
      delete (yysemantic_stack_[(4) - (3)].expr);
      delete (yysemantic_stack_[(4) - (4)].pair_vector);
    }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 1141 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.pair_vector) = new std::vector<std::pair<std::string, std::string> > ();
      (yyval.pair_vector)->push_back(*(yysemantic_stack_[(1) - (1)].pair));
      delete (yysemantic_stack_[(1) - (1)].pair);
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 1147 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].pair_vector)->push_back(*(yysemantic_stack_[(2) - (2)].pair));
      delete (yysemantic_stack_[(2) - (2)].pair);
      (yyval.pair_vector) = (yysemantic_stack_[(2) - (1)].pair_vector);
    }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1156 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *s = static_cast<StringLiteral *>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.pair) = new std::pair<std::string, std::string>((yysemantic_stack_[(3) - (1)].strval), s->get_strval());
      delete s;
    }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1164 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1165 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1166 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1167 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1168 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1169 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1170 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1171 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1172 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1173 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1210 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl(LOC ((yyloc)),
                                SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
                                SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
        }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1222 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
                                StaticContextConsts::preserve_space);
        }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1227 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
                                StaticContextConsts::strip_space);
        }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1238 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
                                ParseConstants::ns_element_default,
                                SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
        }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1244 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
                                ParseConstants::ns_function_default,
                                SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
        }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1256 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OptionDecl(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                                SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
        }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1269 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOptionDecl(LOC ((yyloc)),
                                (yysemantic_stack_[(3) - (3)].node));
        }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1280 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
                                StaticContextConsts::ordered);
        }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1285 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
                                StaticContextConsts::unordered);
        }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1297 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
                                StaticContextConsts::empty_greatest);
        }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1302 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
                                StaticContextConsts::empty_least);
        }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1313 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1319 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
                                StaticContextConsts::preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1325 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::inherit_ns);
        }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1331 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
                                StaticContextConsts::no_preserve_ns,
                                StaticContextConsts::no_inherit_ns);
        }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1350 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
                                SYMTAB ((yysemantic_stack_[(4) - (4)].sval)));
        }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1361 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new BaseURIDecl(LOC ((yyloc)),
                                SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
        }
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1372 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaImport(LOC ((yyloc)),
                                NULL,
                                SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
                                NULL);
        }
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1379 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaImport(LOC ((yyloc)),
                                dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                                SYMTAB ((yysemantic_stack_[(4) - (4)].sval)),
                                NULL);
        }
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 1386 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaImport(LOC ((yyloc)),
                                NULL,
                                SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
                                dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 1393 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaImport(LOC ((yyloc)),
                                dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                                SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
                                dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 1406 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            URILiteralList* uri_list_p = new URILiteralList(LOC ((yyloc)));
            uri_list_p->push_back(SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
            (yyval.node) = uri_list_p;
        }
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1412 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            URILiteralList* uri_list_p = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node));
            if (uri_list_p) {
                uri_list_p->push_back(SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
            }
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1427 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
        }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1431 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
        }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1441 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ModuleImport(LOC ((yyloc)), false,
                                SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
                                NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
        }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1448 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ModuleImport(LOC ((yyloc)), false,
                                SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
                                SYMTAB ((yysemantic_stack_[(6) - (6)].sval)),
                                NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
        }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1456 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ModuleImport(LOC ((yyloc)), false,
                                SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
                                dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
        }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1463 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ModuleImport(LOC ((yyloc)), false,
                                SYMTAB ((yysemantic_stack_[(8) - (4)].sval)),
                                SYMTAB ((yysemantic_stack_[(8) - (6)].sval)),
                                dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
        }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1476 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1483 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->type = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1489 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1496 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(1) - (1)].node));
      d->ext = false;
      (yyval.node) = d;
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1502 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), NULL);
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1506 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1513 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1524 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(), NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1529 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
                               dynamic_cast<SequenceType *> ((yysemantic_stack_[(3) - (3)].node)));
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1538 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(5) - (3)].varnametype)));
            (yyval.node) = new VarDecl(LOC ((yyloc)),
                                nt->name,
                                nt->type,
                                (yysemantic_stack_[(5) - (5)].expr));
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
        }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1547 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (3)].varnametype)));
            (yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       NULL, true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
        }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1554 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(6) - (3)].varnametype)));
            (yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       (yysemantic_stack_[(6) - (6)].expr), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
        }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1564 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      DeclPropertyList* l = new DeclPropertyList(LOC((yyloc)));
      l->addProperty(dynamic_cast<DeclProperty*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1570 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(2) - (1)].node))->addProperty(static_cast<DeclProperty*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1579 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DeclProperty(LOC((yyloc)), StaticContextConsts::decl_const);
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1583 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DeclProperty(LOC((yyloc)), StaticContextConsts::decl_append_only);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1587 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DeclProperty(LOC((yyloc)), StaticContextConsts::decl_queue);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1591 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DeclProperty(LOC((yyloc)), StaticContextConsts::decl_mutable);
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1595 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DeclProperty(LOC((yyloc)), StaticContextConsts::decl_ordered);
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 1599 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DeclProperty(LOC((yyloc)), StaticContextConsts::decl_unordered);
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 1603 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DeclProperty(LOC((yyloc)), StaticContextConsts::decl_value_equality);
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1607 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DeclProperty(LOC((yyloc)), StaticContextConsts::decl_value_range);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1611 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DeclProperty(LOC((yyloc)), StaticContextConsts::decl_unique);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1615 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DeclProperty(LOC((yyloc)), StaticContextConsts::decl_non_unique);
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1619 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DeclProperty(LOC((yyloc)), StaticContextConsts::decl_automatic);
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1623 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DeclProperty(LOC((yyloc)), StaticContextConsts::decl_manual);
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1631 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              0,
                              0,
                              0);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1639 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              0,
                              static_cast<NodeModifier*>((yysemantic_stack_[(4) - (4)].node)),
                              0);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1647 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1655 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                              0,
                              static_cast<NodeModifier*>((yysemantic_stack_[(6) - (6)].node)),
                              static_cast<SequenceType*>((yysemantic_stack_[(6) - (5)].node)));
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1663 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<DeclPropertyList*>((yysemantic_stack_[(4) - (2)].node)), 0, 0);
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1669 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                               static_cast<DeclPropertyList*>((yysemantic_stack_[(5) - (2)].node)),
                               static_cast<NodeModifier*>((yysemantic_stack_[(5) - (5)].node)),
                               0);
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1677 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<DeclPropertyList*>((yysemantic_stack_[(6) - (2)].node)),
                               0,
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1685 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(7) - (4)].expr)),
                               static_cast<DeclPropertyList*>((yysemantic_stack_[(7) - (2)].node)),
                               static_cast<NodeModifier*>((yysemantic_stack_[(7) - (7)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(7) - (6)].node)));
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1697 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = static_cast<parsenode*>(
           new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1702 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = static_cast<parsenode*>(
           new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1711 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1715 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1723 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                         (yysemantic_stack_[(8) - (6)].expr),
                         dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                         new DeclPropertyList(LOC((yyloc))));
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1731 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(9) - (4)].expr)),
                         (yysemantic_stack_[(9) - (7)].expr),
                         dynamic_cast<IndexKeyList*>((yysemantic_stack_[(9) - (9)].node)),
                         dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(9) - (2)].node)));
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1743 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1749 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1758 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<AtomicType*>((yysemantic_stack_[(3) - (3)].node)),
                            NULL);
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1765 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(4) - (1)].expr),
                            dynamic_cast<AtomicType*>((yysemantic_stack_[(4) - (3)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1777 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1787 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1797 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1808 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICForeignKey(LOC((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(22) - (4)].expr)),
                            static_cast<QName*>((yysemantic_stack_[(22) - (9)].expr)),
                            static_cast<QName*>((yysemantic_stack_[(22) - (12)].expr)),
                            (yysemantic_stack_[(22) - (14)].expr),
                            static_cast<QName*>((yysemantic_stack_[(22) - (17)].expr)),
                            static_cast<QName*>((yysemantic_stack_[(22) - (20)].expr)),
                            (yysemantic_stack_[(22) - (22)].expr));
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1825 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(LOC ((yyloc)),
                                StaticContextConsts::cons_preserve);
        }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1830 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ConstructionDecl(LOC ((yyloc)),
                                StaticContextConsts::cons_strip);
        }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1842 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL);
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1846 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL, dynamic_cast<SequenceType *> ((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1854 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList *>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1861 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1868 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      if ((yysemantic_stack_[(4) - (2)].node) == NULL)
      {
        (yyval.expr) = (yysemantic_stack_[(4) - (3)].expr);
      }
      else
      {
        BlockBody* b = dynamic_cast<BlockBody *>((yysemantic_stack_[(4) - (3)].expr));
        VFO_DeclList* vfo = dynamic_cast<VFO_DeclList *>((yysemantic_stack_[(4) - (2)].node));
        if (b == NULL)
        {
          b = new BlockBody((yysemantic_stack_[(4) - (3)].expr)->get_location(), vfo);
          b->add((yysemantic_stack_[(4) - (3)].expr));
        }
        else
        {
          b->set_decls(vfo);
        }

        (yyval.expr) = b;
      }
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1894 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (1)].node));
      std::auto_ptr<VFO_DeclList> vfo2(dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (2)].node)));
      if ((yysemantic_stack_[(3) - (1)].node) == NULL)
        vfo = new VFO_DeclList (LOC ((yyloc)));
      vfo->push_back (*(vfo2.get()));
      (yyval.node) = vfo;
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1903 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL;
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1910 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (1)].node));
      vfo->push_back ((yysemantic_stack_[(3) - (3)].node));
      (yyval.node) = vfo;
    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1916 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = new VFO_DeclList (LOC ((yyloc)));
      vfo->push_back ((yysemantic_stack_[(2) - (2)].node));
      (yyval.node) = vfo;
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1925 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(1) - (1)].varnametype)));
      VarDecl *vd = new VarDecl(LOC ((yyloc)),
                       nt->name,
                       nt->type,
                       NULL);
      vd->set_global (false);
            (yyval.node) = vd;
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1935 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (1)].varnametype)));
      VarDecl *vd = new VarDecl(LOC ((yyloc)),
                       nt->name,
                       nt->type,
                       (yysemantic_stack_[(3) - (3)].expr));
      vd->set_global (false);
            (yyval.node) = vd;
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1948 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr (LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr))->get_qname(), (yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (3)].expr);
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1956 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr (LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1963 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* b = dynamic_cast<BlockBody *>((yysemantic_stack_[(5) - (5)].expr));
      if (b == NULL)
      {
        b = new BlockBody((yysemantic_stack_[(5) - (5)].expr)->get_location());
        b->add((yysemantic_stack_[(5) - (5)].expr));
      }

      (yyval.expr) = new WhileExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), b);
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1977 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1981 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::CONTINUE);
    }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1988 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<FunctionDecl *>((yysemantic_stack_[(2) - (2)].node))->setComment(SYMTAB((yysemantic_stack_[(2) - (1)].sval)));
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 1993 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
      d->deterministic = false;
      (yyval.node) = d;
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 2000 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<FunctionDecl *>((yysemantic_stack_[(3) - (3)].node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 2008 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 2012 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 2016 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(2) - (2)].node));
      d->type = (d->type == ParseConstants::fn_extern)
        ? ParseConstants::fn_extern_update
        : ParseConstants::fn_update;
      (yyval.node) = d;
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 2024 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 2031 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
                                (yysemantic_stack_[(4) - (4)].expr),
                                ParseConstants::fn_read);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2040 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
                                NULL,
                                ParseConstants::fn_extern);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 2052 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                        static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                        &* (yysemantic_stack_[(6) - (3)].fnsig)->param, &* (yysemantic_stack_[(6) - (3)].fnsig)->ret,
                        (yysemantic_stack_[(6) - (5)].expr),
                        ParseConstants::fn_read);
      delete (yysemantic_stack_[(6) - (3)].fnsig);
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 2061 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                        static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                        &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
                        NULL,
                        ParseConstants::fn_extern);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 2073 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
                                (yysemantic_stack_[(4) - (4)].expr),
                                ParseConstants::fn_sequential);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 2082 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
                                NULL,
                                ParseConstants::fn_extern_sequential);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 2096 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            ParamList* plist_p = new ParamList(LOC ((yyloc)));
            if (plist_p) {
                plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)));
            }
            (yyval.node) = plist_p;
        }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 2104 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            ParamList* plist_p = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node));
            if (plist_p) {
                plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)));
            }
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 2118 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Param(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(),
                                NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
        }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 2125 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Param(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
                                dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
      delete (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 2138 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
                                (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 2146 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 2157 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QueryBody(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
        }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 2172 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 2176 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<BlockBody> blk(dynamic_cast<BlockBody *>((yysemantic_stack_[(2) - (2)].expr)));

      BlockBody* blk2 = new BlockBody(LOC((yyloc)));

      blk2->add((yysemantic_stack_[(2) - (1)].expr));

      for (int i = 0; i < blk->size(); ++i)
        blk2->add((*blk)[i]);

      (yyval.expr) = blk2;
    }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 2192 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody (LOC ((yyloc)));
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2196 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = dynamic_cast<BlockBody *>((yysemantic_stack_[(3) - (1)].expr));
      blk->add((yysemantic_stack_[(3) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2205 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2209 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            Expr* expr_p = dynamic_cast<Expr*>((yysemantic_stack_[(3) - (1)].expr));
            if (expr_p == NULL)
      {
        expr_p = new Expr(LOC((yyloc)));
        expr_p->push_back((yysemantic_stack_[(3) - (1)].expr));
      }
      expr_p->push_back((yysemantic_stack_[(3) - (3)].expr));
            (yyval.expr) = expr_p;
        }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 2254 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      ReturnExpr* lReturnExpr = dynamic_cast<ReturnExpr*>((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = new FLWORExpr(LOC((yyloc)),
                         dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node)),
                         lReturnExpr->get_return_val(),
                         lReturnExpr->get_location(),
                         driver.theCompilerCB->theConfig.force_gflwor);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 2267 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2274 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 2278 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 2286 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 2290 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 2294 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_only_end;
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 2301 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), dynamic_cast<WindowVars *> ((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr), (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 2305 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr), (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 2312 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(5) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window,
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(5) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (4)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 2320 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window,
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 2331 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause (LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 2350 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = new FLWORClauseList (LOC ((yyloc)));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 2356 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = dynamic_cast<FLWORClauseList *> ((yysemantic_stack_[(2) - (1)].node));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
    }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 2365 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = NULL;
    }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 2369 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_ofor;
    }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 2379 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForClause(LOC ((yyloc)),
                         dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL);
        }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 2390 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
            vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
            (yyval.node) = vardecl_list_p;
        }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 2396 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            if (vardecl_list_p) {
                vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
            }
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 2410 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VarInDecl(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
                                NULL,NULL,NULL,
                                (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (1)].expr);
        }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 2418 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VarInDecl(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
                                dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                                NULL,NULL,
                                (yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
        }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 2427 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VarInDecl(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
                                NULL,
                                dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
                                NULL,
                                (yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
        }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 2437 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VarInDecl(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr))->get_qname(),
                                dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                                dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
                                NULL,
                                (yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (1)].expr);
        }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 2448 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VarInDecl(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
                                NULL,NULL,
                                dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                                (yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
        }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 2457 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VarInDecl(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr))->get_qname(),
                                dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                                NULL,
                                dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                                (yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (1)].expr);
        }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 2467 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VarInDecl(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr))->get_qname(),
                                NULL,
                                dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
                                dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                                (yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (1)].expr);
        }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 2477 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VarInDecl(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr))->get_qname(),
                                dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (2)].node)),
                                dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
                                dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                                (yysemantic_stack_[(6) - (6)].expr));
      delete (yysemantic_stack_[(6) - (1)].expr);
        }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 2493 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PositionalVar(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
        }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 2506 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScoreVar(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
        }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 2518 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause(LOC ((yyloc)),
                                dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)));

        }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 2530 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
            vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
            (yyval.node) = vgdl_p;
        }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 2536 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
            if (vgdl_p) {
                vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
            }
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 2548 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
            vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
            (yyval.node) = vgdl_p;
        }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 2554 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
            if (vgdl_p) {
                vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
            }
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 2568 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
                                NULL,
                                NULL,
                                (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (1)].expr);
        }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 2577 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
                                dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                                NULL,
                                (yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
        }
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 2587 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
                                NULL,
                                dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                                (yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
        }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2596 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr))->get_qname(),
                                dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                                dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                                (yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (1)].expr);
        }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 2609 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr))->get_qname(),
                                NULL, (yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (2)].expr);
        }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2616 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr))->get_qname(),
                                dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                                (yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (2)].expr);
        }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2628 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(), "", "");
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2633 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_curr (static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2642 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), dynamic_cast<PositionalVar *> ((yysemantic_stack_[(1) - (1)].node)), "", "", "");
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2646 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_posvar (dynamic_cast<PositionalVar *> ((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2655 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr))->get_qname(), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr))->get_qname());
      delete (yysemantic_stack_[(6) - (3)].expr);
      delete (yysemantic_stack_[(6) - (6)].expr);
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 2661 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", "", static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 2666 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname(), "");
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 2674 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::string name = static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr))->get_qname();
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           name, NULL, NULL,
                           new VarRef (LOC ((yyloc)), name),
                           VarGetsDecl::eval_var);
      delete (yysemantic_stack_[(1) - (1)].expr);

    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 2690 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new WhereClause(LOC ((yyloc)),
                                (yysemantic_stack_[(2) - (2)].expr));
        }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 2698 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2705 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = new GroupSpecList(LOC((yyloc)));
      gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl_p;
    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2711 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      if (gsl_p) {
        gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      }
      (yyval.node) = gsl_p;
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2722 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(),
                 NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2729 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
                 dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2739 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2749 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(LOC ((yyloc)),
                                dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node)));
        }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2754 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(LOC ((yyloc)),
                                dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)),
                                true);
        }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2766 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
            osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
            (yyval.node) = osl_p;
        }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2772 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node));
            if (osl_p) {
                osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)));
            }
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2786 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(LOC ((yyloc)),
                                (yysemantic_stack_[(1) - (1)].expr),
                                NULL);
        }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2792 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(LOC ((yyloc)),
                         (yysemantic_stack_[(2) - (1)].expr),
                         dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2804 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
                               NULL,
                               NULL);
        }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2811 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               NULL,
                               dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
                               NULL);
        }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2818 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               NULL,
                               NULL,
                               dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
        }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2825 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                               dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                               NULL);
        }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2832 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                               NULL,
                               dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2839 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               NULL,
                               dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                               dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2846 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                               dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                               dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
        }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 2859 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
        }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2863 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
        }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2873 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(LOC((yyloc)), StaticContextConsts::empty_greatest);
        }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(LOC((yyloc)), StaticContextConsts::empty_least);
        }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2887 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec(LOC((yyloc)),    SYMTAB((yysemantic_stack_[(2) - (2)].sval)));
        }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2897 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(LOC((yyloc)),
                              ParseConstants::quant_some,
                              dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                              (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2904 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(LOC((yyloc)),
                              ParseConstants::quant_every,
                              dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                              (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2917 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
            (yyval.node) = qvid_list_p;

        }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2924 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
            (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
        }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2936 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QVarInDecl(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
                                (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (1)].expr);
        }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2943 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QVarInDecl(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
                                dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                                (yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
        }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2957 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                                (yysemantic_stack_[(8) - (3)].expr),
                                dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                                (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2964 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                                (yysemantic_stack_[(10) - (3)].expr),
                                dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                                static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr))->get_qname(),
                                (yysemantic_stack_[(10) - (10)].expr));
      delete (yysemantic_stack_[(10) - (8)].expr);
        }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 2979 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
            cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
            (yyval.node) = cc_list_p;
        }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 2985 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
            cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 2997 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CaseClause(LOC ((yyloc)),
                                dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                                (yysemantic_stack_[(4) - (4)].expr));
        }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 3003 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CaseClause(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr))->get_qname(),
                                dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                                (yysemantic_stack_[(7) - (7)].expr));
      delete (yysemantic_stack_[(7) - (3)].expr);
        }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 3017 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IfExpr(LOC ((yyloc)),
                                (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 3028 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 3032 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrExpr(LOC ((yyloc)),
                                (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 3043 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 3047 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr(LOC ((yyloc)),
                                (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 3058 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 3062 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
            (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                                dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
                                (yysemantic_stack_[(3) - (1)].expr),
                                (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 3070 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      /*  ::=  "is" | "<<" | ">>" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3078 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
            (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                                new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq),
                                (yysemantic_stack_[(3) - (1)].expr),
                                (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3086 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3093 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        /* this call is needed */
        driver.lexer->interpretAsLessThan();
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3097 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3105 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_le),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3113 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3121 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3134 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3138 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
                                (yysemantic_stack_[(3) - (1)].expr),
                                dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
                                NULL);
        }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3145 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
                                (yysemantic_stack_[(4) - (1)].expr),
                                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
                                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
        }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3158 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3162 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr(LOC ((yyloc)),
                                (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3173 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3177 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3181 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3191 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3195 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3199 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3203 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3207 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3217 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3221 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr(LOC ((yyloc)),
                                (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3226 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr(LOC ((yyloc)),
                                (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3237 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3241 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3245 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3255 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3259 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
                                (yysemantic_stack_[(4) - (1)].expr),
                                dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
        }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3271 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3275 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(LOC ((yyloc)),
                                (yysemantic_stack_[(4) - (1)].expr),
                                dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
        }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3287 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3291 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(LOC ((yyloc)),
                                (yysemantic_stack_[(4) - (1)].expr),
                                dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
        }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3303 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3307 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(LOC ((yyloc)),
                                (yysemantic_stack_[(4) - (1)].expr),
                                dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
        }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3319 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3323 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr(LOC ((yyloc)),
                                dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
                                (yysemantic_stack_[(2) - (2)].expr));
        }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3335 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList(LOC ((yyloc)), true);
        }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3339 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList(LOC ((yyloc)), false);
        }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3343 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3347 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
            if (slist_p) slist_p->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3359 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3363 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3367 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3377 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3381 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
        }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3385 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3389 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3393 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3397 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3407 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3411 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3415 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3425 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr));
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3429 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3433 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3437 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                            dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(),
                            (yysemantic_stack_[(6) - (5)].expr));
    }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3449 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
                                dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
                                NULL);
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3455 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
                                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                                (yysemantic_stack_[(4) - (3)].expr));
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3467 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
            pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
            (yyval.node) = pragma_list_p;
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3473 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            PragmaList* pragma_list_p = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node));
            if (pragma_list_p) {
                pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)));
            }
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3487 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                                SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));

        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3493 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma(LOC ((yyloc)),
                                new QName(LOC ((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval))),
                                "");
    }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3535 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3539 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3543 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3547 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (rpe == NULL ?
             (yysemantic_stack_[(1) - (1)].expr) :
             new PathExpr(LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3559 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3569 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       AxisStep *as = dynamic_cast<AxisStep *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (as != NULL ?
             new RelativePathExpr(LOC ((yyloc)),
                                  ParseConstants::st_slash,
                                  new ContextItemExpr(LOC((yyloc)), true),
                                  (yysemantic_stack_[(1) - (1)].expr)) :
             (yysemantic_stack_[(1) - (1)].expr));
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3580 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3585 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3595 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3599 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3609 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(LOC ((yyloc)),
                                dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
                                NULL);
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3615 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(LOC ((yyloc)),
                                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3621 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(LOC ((yyloc)),
                                dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
                                NULL);
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3627 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(LOC ((yyloc)),
                                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3639 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(LOC ((yyloc)),
                                dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
                                (yysemantic_stack_[(2) - (2)].node));
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3645 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(LOC ((yyloc)),
                                dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3656 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3660 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3664 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3668 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3672 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3676 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3680 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3690 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node), false);
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3694 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3704 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep(LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node));
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3708 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
            (yyval.node) = new ReverseStep(LOC((yyloc)), rev_p, NULL);
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3719 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3723 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3727 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
        }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3731 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3735 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3750 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3754 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3764 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest(LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3768 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3778 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        "",
                        ParseConstants::wild_all);
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3785 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Wildcard(LOC ((yyloc)),
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        ParseConstants::wild_elem);
        }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3792 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        ParseConstants::wild_prefix);
        }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3805 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3809 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FilterExpr(LOC ((yyloc)),
                          (yysemantic_stack_[(2) - (1)].expr),
                          dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3821 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
            pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
            (yyval.node) = pred_list_p;
        }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3827 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            PredicateList* pred_list_p = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node));
            if (pred_list_p) {
                pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
            }
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3841 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3852 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3856 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3860 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3864 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3868 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3872 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3876 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3880 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3890 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3894 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3904 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval));
      delete yylval.decval;
        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3909 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival));
      delete yylval.ival;
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3914 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval));
      delete yylval.dval;
        }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3925 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname());
      delete (yysemantic_stack_[(2) - (2)].expr);
        }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3936 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3940 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
                                (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 3951 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 3961 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr(LOC ((yyloc)),
                                (yysemantic_stack_[(4) - (3)].expr));
        }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 3972 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
                                (yysemantic_stack_[(4) - (3)].expr));
        }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 4028 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)),
                                NULL);
        }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 4034 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
        }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 4046 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            ArgList* a_list_p = new ArgList(LOC ((yyloc)));
            a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
            (yyval.node) = a_list_p;
        }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 4052 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
            if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 4064 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 4068 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 4078 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 4082 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 4086 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 4096 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                NULL,
                                NULL,
                                NULL);
        }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 4104 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                NULL,
                                dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)),
                                NULL);
        }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4112 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(8) - (2)].expr)),
                                static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr)),
                                NULL,
                                NULL);
        }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4120 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
                                static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
                                NULL,
                                dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node)));
        }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4128 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
                                static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
                                dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
                                NULL);
        }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4136 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(10) - (2)].expr)),
                                static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                                dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)),
                                dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node)));
        }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4151 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
            elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
            (yyval.node) = elem_content_list_p;
        }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4157 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4169 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
            at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
            (yyval.node) = at_list_p;
        }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4175 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if (at_list_p) {
                at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)));
            }
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4188 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4205 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue(LOC ((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4210 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue(LOC ((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4221 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
        }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4225 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4232 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
            qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
            (yyval.node) = qo_list_p;
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4238 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
            qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
            (yyval.node) = qo_list_p;
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4244 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (qo_list_p) {
                qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
            }
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4252 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (qo_list_p) {
                qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
            }
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4266 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList(LOC ((yyloc)));
        }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4270 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4277 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
            at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
            (yyval.node) = at_list_p;
        }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4283 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
            at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
            (yyval.node) = at_list_p;
        }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4289 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (at_list_p) {
                at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
            }
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4297 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (at_list_p) {
                at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
            }
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4311 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
                                SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
        }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4316 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
                                dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
        }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4327 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
                                SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
        }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4332 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
                                dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
        }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4343 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent(LOC ((yyloc)),
                                (yysemantic_stack_[(1) - (1)].expr));
        }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4348 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent(LOC ((yyloc)),
                                SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
        }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4353 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent(LOC ((yyloc)),
                                cdata_h);
        }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4359 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent(LOC ((yyloc)),
                                cont_h);
        }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4371 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
                                SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
        }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4377 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC ((yyloc)),
                                ParseConstants::cont_escape_lbrace);
        }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4382 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC ((yyloc)),
                                ParseConstants::cont_escape_rbrace);
        }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4387 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC ((yyloc)),
                                dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
        }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4398 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
                                SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
        }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4403 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4418 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
                                SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4423 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
                                SYMTAB ((yysemantic_stack_[(3) - (2)].sval)),
                                SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
        }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4440 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CDataSection(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
        }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4455 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4459 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4463 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4467 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4471 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4475 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4485 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
                                (yysemantic_stack_[(4) - (3)].expr));
        }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4496 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                NULL);
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4502 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                (yysemantic_stack_[(5) - (4)].expr));
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4508 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
                                (yysemantic_stack_[(6) - (3)].expr), NULL);
        }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4513 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
                                (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4535 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
                                (yysemantic_stack_[(4) - (2)].expr),
                                NULL);
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4541 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
                                (yysemantic_stack_[(5) - (2)].expr),
                                (yysemantic_stack_[(5) - (4)].expr));
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4547 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
                                (yysemantic_stack_[(6) - (3)].expr), NULL);
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4552 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
                                (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
        }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4563 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4573 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4583 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
                                SYMTAB ((yysemantic_stack_[(4) - (2)].sval)),
                                NULL);
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4589 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
                                SYMTAB ((yysemantic_stack_[(5) - (2)].sval)),
                                (yysemantic_stack_[(5) - (4)].expr));
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4595 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
                                (yysemantic_stack_[(6) - (3)].expr), NULL);
        }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4600 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
        }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4610 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false);
        }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4614 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true);
        }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4624 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4635 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL);
        }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4639 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4643 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), NULL, NULL);
        }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4680 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(LOC((yyloc)), ParseConstants::occurs_optionally);
        }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4684 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(LOC((yyloc)),   ParseConstants::occurs_zero_or_more);
        }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4688 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(LOC((yyloc)), ParseConstants::occurs_one_or_more);
        }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4698 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4702 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4706 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType(LOC ((yyloc)),true);
        }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4716 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4726 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4730 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4734 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4738 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4742 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4746 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4750 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4754 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4758 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4768 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest(LOC ((yyloc)));
        }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4778 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(LOC ((yyloc)));
        }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4782 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
        }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4786 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
        }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4796 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest(LOC ((yyloc)));
        }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4806 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest(LOC ((yyloc)));
        }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4816 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest(LOC ((yyloc)), "");
        }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4820 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
        }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4824 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
        }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4834 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(LOC ((yyloc)),
                                NULL,
                                NULL);
        }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4840 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                                NULL);
        }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4846 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
        }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4852 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(LOC ((yyloc)),
                                NULL,
                                NULL);
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4858 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(LOC ((yyloc)),
                                NULL,
                                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4870 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4881 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(LOC ((yyloc)),
                           NULL,
                           NULL,
                           true);
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4888 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                           NULL,
                           true);
        }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4895 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           false);
        }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4902 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           true);
        }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4909 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(LOC ((yyloc)),
                                    NULL,
                                    NULL,
                                    true);
        }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4916 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(LOC ((yyloc)),
                                    NULL,
                                    dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                                    false);
        }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4923 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(LOC ((yyloc)),
                                    NULL,
                                    dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                                    true);
        }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4936 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest(LOC ((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)));
        }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4957 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
        }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4964 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName(LOC ((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)),
                                true);
        }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4984 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
        }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 5024 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::strict_validation);
        }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 5028 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::lax_validation);
    }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 5032 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::skip_validation);
    }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 5041 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 5047 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
        }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 5053 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
        }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 5059 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 5065 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 5072 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 5078 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 5084 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
        }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 5090 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 5096 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 5108 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 5113 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 5123 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 5129 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
        }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 5141 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 5167 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 5178 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       CopyVarList* lList = new CopyVarList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5184 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
       VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
       lList->push_back(lBinding);
       (yyval.expr) = lList;
        }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5197 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (1)].expr);
    }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5213 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
                                       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5220 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5226 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* aCatchListExpr = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if (aCatchListExpr) {
        aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)));
      }
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5237 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(3) - (2)].name_test_list),
                          (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5244 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(7) - (2)].name_test_list),
                          static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr))->get_qname(),
                          (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (5)].expr);
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5254 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(10) - (2)].name_test_list),
                          static_cast<QName*>((yysemantic_stack_[(10) - (5)].expr))->get_qname(),
                          static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr))->get_qname(),
                          (yysemantic_stack_[(10) - (10)].expr));
       delete (yysemantic_stack_[(10) - (5)].expr);
       delete (yysemantic_stack_[(10) - (8)].expr);
       delete (yysemantic_stack_[(10) - (2)].name_test_list);
    }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5265 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(13) - (2)].name_test_list),
                          static_cast<QName*>((yysemantic_stack_[(13) - (5)].expr))->get_qname(),
                          static_cast<QName*>((yysemantic_stack_[(13) - (8)].expr))->get_qname(),
                          static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr))->get_qname(),
                          (yysemantic_stack_[(13) - (13)].expr));
       delete (yysemantic_stack_[(13) - (5)].expr);
       delete (yysemantic_stack_[(13) - (8)].expr);
       delete (yysemantic_stack_[(13) - (11)].expr);
       delete (yysemantic_stack_[(13) - (2)].name_test_list);
    }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5281 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CatchExpr::NameTestList *name_test_list = new CatchExpr::NameTestList;
      name_test_list->push_back (static_cast<NameTest *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.name_test_list) = name_test_list;
    }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5287 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CatchExpr::NameTestList *name_test_list =
        static_cast<CatchExpr::NameTestList *> ((yysemantic_stack_[(3) - (1)].name_test_list));
      name_test_list->push_back (static_cast<NameTest *> ((yysemantic_stack_[(3) - (3)].node)));
      (yyval.name_test_list) = name_test_list;
    }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5307 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<QName> lQName(static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
      std::string tmp = lQName->get_qname();
      if (tmp.find (':') != std::string::npos) {
        error((yylocation_stack_[(1) - (1)]), "A NCName is expected, found a QName");
        YYERROR;
      }
      (yyval.sval) = SYMTAB_PUT(tmp.c_str());
    }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5325 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5329 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5342 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)),
                          (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5348 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5355 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("xquery"); }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5356 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty"); }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5357 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("attribute"); }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5358 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("comment"); }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5359 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document-node"); }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5360 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("element"); }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5361 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("item"); }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5362 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("if"); }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5363 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("node"); }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5364 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("processing-instruction"); }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5365 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-attribute"); }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5366 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-element"); }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5367 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("text"); }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5368 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("typeswitch"); }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5369 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty-sequence"); }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5370 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("boundary-space"); }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5371 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ft-option"); }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5372 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("base-uri"); }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5373 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lax"); }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5374 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strict"); }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5375 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("idiv"); }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5376 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document"); }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5377 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("not"); }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5378 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sensitive"); }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5379 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insensitive"); }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5380 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("diacritics"); }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5381 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("without"); }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5382 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stemming"); }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5383 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("thesaurus"); }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5384 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stop"); }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5385 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("wildcards"); }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5386 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("entire"); }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5387 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("content"); }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5388 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("word"); }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5389 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("start"); }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5390 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("end"); }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5391 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("most"); }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5392 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("skip"); }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5393 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy"); }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5394 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("value"); }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5395 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eq"); }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5396 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ne"); }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5397 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lt"); }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5398 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("le"); }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5399 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("gt"); }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5400 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ge"); }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5401 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("at"); }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5402 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("context"); }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5403 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("variable"); }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5404 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("return"); }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5405 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("for"); }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5406 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("outer"); }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5407 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sliding"); }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5408 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("tumbling"); }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5409 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("previous"); }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5410 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("next"); }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5411 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("only"); }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5412 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("when"); }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5413 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("count"); }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5414 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("in"); }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5415 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("let"); }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5416 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("where"); }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5417 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("by"); }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5418 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("group"); }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5419 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("order"); }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5420 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stable"); }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5421 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ascending"); }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5422 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("descending"); }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5423 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("greatest"); }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5424 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("least"); }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5425 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("collation"); }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5426 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("some"); }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5427 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("every"); }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5428 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("satisfies"); }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5429 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("case"); }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5430 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("as"); }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5431 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("then"); }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5432 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("else"); }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5433 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("or"); }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5434 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("and"); }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5435 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("instance"); }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5436 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("of"); }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5437 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("castable"); }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5438 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("to"); }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5439 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("div"); }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5440 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("mod"); }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5441 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("union"); }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5442 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("intersect"); }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5443 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("except"); }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5444 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("validate"); }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5445 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("cast"); }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5446 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("treat"); }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5447 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("is"); }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5448 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("preserve"); }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5449 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strip"); }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5450 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("namespace"); }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5451 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("external"); }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5452 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("encoding"); }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5453 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-preserve"); }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5454 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("inherit"); }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5455 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-inherit"); }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5456 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("declare"); }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5457 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("construction"); }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5458 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordering"); }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5459 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("default"); }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5460 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy-namespaces"); }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5461 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("option"); }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5462 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("version"); }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5463 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("import"); }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5464 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema"); }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5465 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("module"); }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5466 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("function"); }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5467 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("score"); }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5468 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ftcontains"); }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 5469 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("weight"); }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5470 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("window"); }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 5471 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("distance"); }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 5472 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("occurs"); }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 5473 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("times"); }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 5474 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("same"); }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 5475 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("different"); }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 5476 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lowercase"); }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 5477 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("uppercase"); }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 5478 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("relationship"); }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 5479 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("levels"); }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 5480 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("language"); }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 5481 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("any"); }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 5482 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("all"); }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 5483 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("phrase"); }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 5484 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exactly"); }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 5485 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("from"); }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 5486 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("words"); }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 5487 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentences"); }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 5488 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentence"); }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 5489 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("paragraph"); }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 5490 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("replace"); }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 5491 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("modify"); }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 5492 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("first"); }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 5493 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insert"); }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 5494 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("before"); }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 5495 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("after"); }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 5496 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("revalidation"); }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 5497 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("with"); }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 5498 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nodes"); }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 5499 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("rename"); }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 5500 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("last"); }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 5501 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("delete"); }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 5502 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("into"); }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 5503 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("simple"); }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 5504 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sequential"); }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 5505 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("updating"); }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 5506 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("deterministic"); }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 5507 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nondeterministic"); }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 5508 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordered"); }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 5509 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unordered"); }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 5510 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("returning"); }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 5511 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("block"); }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 5512 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exit"); }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 5513 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("loop"); }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 5514 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("while"); }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 5515 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("break"); }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 5516 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("continue"); }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 5517 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("try"); }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 5518 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("catch"); }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 5519 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eval"); }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 5520 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("using"); }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 5521 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("set"); }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 5522 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("index"); }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 5523 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unique"); }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 5524 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("non"); }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 5525 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("on"); }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 5526 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("range"); }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 5527 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("equality"); }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 5528 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("manually"); }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 5529 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("automatically"); }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 5530 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("maintained"); }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 5531 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("decimal-format"); }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 5532 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("decimal-separator"); }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 5533 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("grouping-separator"); }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 5534 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("infinity"); }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 5535 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("minus-sign"); }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 5536 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("NaN"); }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 5537 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("percent"); }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 5538 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("per-mille"); }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 5539 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("zero-digit"); }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 5540 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("digit"); }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 5541 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("pattern-separator"); }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 5542 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("collection"); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 5543 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("const"); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 5544 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("append-only"); }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 5545 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("queue"); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 5546 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("mutable"); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 5547 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("read-only"); }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 5548 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("integrity"); }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 5549 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("constraint"); }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 5550 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("check"); }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 5551 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("key"); }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 5552 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("foreach"); }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 5553 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("foreign"); }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 5554 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("keys"); }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 5570 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(1) - (1)].node)), NULL, NULL);
        }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 5574 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(2) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(2) - (2)].node)), NULL);
        }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 5578 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(3) - (1)].node)), NULL, static_cast<RangeExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
        }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 5582 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(4) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(4) - (2)].node)), static_cast<RangeExpr *> ((yysemantic_stack_[(4) - (4)].expr)));
        }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 5592 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 5595 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 5598 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 5601 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 5610 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 5613 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 5622 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 5625 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 5634 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 5637 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 5646 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 5649 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 5658 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 5661 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 5664 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 5673 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 5676 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 5685 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue (LOC ((yyloc)), static_cast<StringLiteral *> ((yysemantic_stack_[(1) - (1)].expr)), NULL);
        }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 5689 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 5699 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 5702 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 5705 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 5708 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 5711 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 5720 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 5729 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 5733 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 5737 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 5741 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 5745 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 5749 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 5753 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 5763 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 5766 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 5769 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 5772 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 5781 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 5784 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 5787 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 5790 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 5799 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 5802 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 5811 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 5814 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 5817 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 5820 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 5823 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 5826 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 5829 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 5838 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 5841 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 5850 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 5853 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 5856 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 5859 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 5868 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 5871 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 5874 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 5877 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 5880 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 5889 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 5892 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 5901 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 5904 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 5913 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 5916 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 5925 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 5928 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 5937 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 5946 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 5949 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 5958 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 5961 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 5964 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 5973 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 5976 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 5979 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 5982 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 5985 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 5994 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
        }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 5998 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6002 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6006 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
        }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6016 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6025 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWindow (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (2)].expr)), static_cast<FTUnit *> ((yysemantic_stack_[(3) - (3)].node)));
        }
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6035 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6044 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6047 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 6056 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 6059 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 6062 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 6071 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 6074 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
        }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 6083 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTIgnoreOption (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
        }
    break;



/* Line 678 of lalr1.cc  */
#line 10182 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"
	default:
          break;
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
	/* If just tried and failed to reuse lookahead token after an
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

    /* Else will try to reuse lookahead token after shifting the error
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

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
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
    if (yychar != yyempty_)
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
  const short int xquery_parser::yypact_ninf_ = -1258;
  const short int
  xquery_parser::yypact_[] =
  {
      1479, -1258, -1258, -1258, -1258,   848,   204,   147,     4,  8366,
     198,   279,   356, -1258, -1258, -1258, -1258, -1258, -1258,   263,
      99,  7236, -1258,   317, -1258, -1258, -1258, -1258,   372,   392,
   -1258,   324,    72,   475, -1258, -1258, -1258, -1258, -1258, -1258,
   -1258, -1258, -1258,   399,   405, -1258, -1258, -1258, -1258, -1258,
   -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258,
   -1258, -1258, -1258, -1258, -1258, -1258,  8646, -1258,  6664, -1258,
   -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258,
   -1258, -1258, 10326, -1258, -1258, -1258, -1258, -1258, -1258, -1258,
   -1258,   460, -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258,
   -1258, -1258, -1258,  1768, 10326, -1258, -1258, -1258, -1258, -1258,
   -1258, -1258,   464, -1258, -1258, -1258,  7804, -1258,  8086, -1258,
   -1258, -1258, -1258, -1258, 10326, -1258, -1258,  6376, -1258, -1258,
   -1258, -1258, -1258, -1258,   467, -1258, -1258, -1258, -1258, -1258,
   -1258, -1258, -1258,    28,   417, -1258, -1258, -1258, -1258, -1258,
   -1258, -1258, -1258,   383,   482,   391, -1258,   424,   231, -1258,
   -1258, -1258, -1258, -1258, -1258,   530, -1258, -1258,   510,   430,
     434, -1258,   436,   537,   543, -1258,   579, -1258, -1258, -1258,
   -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258,
   -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258,
   -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258,
   -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258,
   -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258,
   -1258, -1258, -1258, -1258, -1258,  4360,   694, -1258,  4648, -1258,
   -1258,   139,  4936,   517,   527, -1258, -1258, -1258, -1258, -1258,
   -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258,
   -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258,
   -1258, -1258, -1258, -1258, -1258, -1258,   -17, -1258, -1258, -1258,
   -1258,   477, 10326, -1258, -1258, -1258, -1258, -1258,   556,   634,
   -1258,   776,   473,   269,   385,   348,   190, -1258,   654,   536,
     632,   636,  5224, -1258, -1258, -1258,   207, -1258, -1258,  6376,
   -1258,   411, -1258,   583,  6664, -1258,   583,  6664, -1258, -1258,
   -1258, -1258,   583, -1258, -1258, -1258, -1258, -1258, -1258, -1258,
   -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258,
   -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258,
   -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258,
   -1258,   588, -1258, -1258, 10326,   700,   701,   620,   620,   702,
   10326,   151,   -19,   719,   288,   291, 10326,   600,   635,   265,
    7804, -1258, -1258,   330,   312,     1, 10326, -1258, -1258, -1258,
   -1258, -1258,   462, 10326,   459,   465,   461,   346, -1258, -1258,
   -1258,  7804, 10326,  4936,   605,   609,  4936, -1258, -1258, -1258,
   -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258,
   -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258,  4936,  8926,
   -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258,
   -1258, -1258, -1258, -1258, -1258, -1258,   612,  4936,  4936,   580,
    4936,   581,  4936,   115,   111, -1258,  4936,  7520,   617, -1258,
   10326, 10326, 10326,  4936,   490,   491, -1258,   656,   671, 10326,
      26,  4936,  9206,   640,   642,   643,   644,   645,   646, -1258,
   -1258, -1258, 10326, -1258,   619,   765,  4936,    55, -1258,   780,
     621, -1258,  4936,   595, -1258,   778,  4936,  4936,   624,  4936,
    4936,  4936,  4936,   582, 10326, -1258, -1258,  4936, -1258, -1258,
    4936,  4936, 10326, -1258, -1258, -1258, -1258,   848,    99, -1258,
   -1258,   139,   775,  4936, -1258,  4936,   647,   392,    72,   475,
     691,   648,   649,  4936,  4936, -1258, -1258, -1258, -1258, -1258,
   -1258, -1258,   704, -1258,   -14,  5512,  5512,  5512, -1258,  5512,
    5512, -1258,  5512, -1258,  5512, -1258, -1258, -1258, -1258, -1258,
   -1258, -1258,  5512,  5512,    12,  5512,  5512,  5512,  5512,  5512,
    5512,  5512,  5512,  5512,  5512,  5512,   585,   720,   723,   724,
   -1258, -1258, -1258,  2056, -1258, -1258,  6376,  6376,  4936,   583,
   -1258, -1258,   583, -1258,   583,  2344,   666, 10326, -1258, 10326,
   -1258, -1258, -1258, -1258,   792, -1258, -1258, -1258, -1258, -1258,
   -1258,   714,   715, -1258, -1258,   699,   273, 10326,   416,   668,
     669,   699,   719,   698,   697, -1258, -1258, -1258, -1258, -1258,
     237,    71,   258,   800, -1258, -1258,   345, -1258, -1258, -1258,
   -1258, -1258, -1258, -1258, -1258,   -28, -1258,   533, -1258, -1258,
   10326, 10326, 10326, -1258,   703,   680, -1258,   651,  4936,  4936,
     652,   657, -1258,    62,    78,  2632,   658,   659, -1258,   660,
   -1258,   653,  7804,   736,   796,  7804,   719,   745,   662,   661,
   -1258,   663,  2920,    17, -1258,   234,   705,   740, -1258,   -22,
     670, -1258, -1258, 10326,    -7, -1258,   665,   642,   399, -1258,
     673,   675,   674, -1258,    80,    93,  3208,    52, -1258, 10326,
     765, -1258,    10,   679, -1258, -1258, -1258, -1258,   681, -1258,
     -10, -1258, -1258, -1258,   -20,    37,   749,   615,   629,     7,
   -1258,   713,  5800, -1258,   677,   682,    79, -1258, -1258,   678,
   -1258,     0, -1258, -1258,    18,   706, 10326,  4936,   746, -1258,
   -1258,   748,  9766,   750,  4936,   752,   -39,   728,   -37,   634,
   -1258, -1258, -1258, -1258, -1258,  5512, -1258, -1258, -1258,  4936,
      12,   458, -1258,   592,   446,   627,   610, -1258, -1258,   611,
     318,   385,   385,     6,   348,   348,   348,   348,   190,   190,
   -1258, -1258,  9766,  9766, 10326, 10326, -1258,   696, -1258, -1258,
     707, -1258, -1258, -1258,    95,    11,    33,   666,   666, -1258,
     208,   274, -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258,
   -1258, -1258,   699, -1258,   755, 10046,   747,  4936, -1258, -1258,
   -1258,   795,   756,  4936,   719,   719,   699, -1258,   501,   719,
   -1258, -1258,   623, -1258, -1258,   603,    39, -1258, -1258, -1258,
   -1258, -1258, -1258,   616, -1258, -1258,    35,   369, -1258,   676,
     209,     8,   607,   719,  4936, -1258,   721,   727,   804,   759,
   10326, -1258, 10326, -1258, -1258,   731, -1258, -1258, -1258,   722,
     783,   719,   761,   791,   826,   719,   779, -1258, -1258, -1258,
     751,   807,  4936,  4936,   788,  4936,   816,  4936,   797,   -62,
   -1258,   283,   685, -1258, -1258,   396,    -7, -1258, -1258, -1258,
     789, 10326, -1258, 10326, -1258, -1258,   758,  4936,   905, -1258,
     161, -1258,   202, -1258, -1258,   913, -1258,   338,  4936,  4936,
    4936,   395,  4936,  4936,  4936,  4936,  4936,  4936,   824,  4936,
    4936,   635,    38,   763,   510,   709,   794,   827,   775,   868,
   -1258,  4936, -1258,   315,   846, -1258, 10326,   847, -1258, 10326,
     803,   809, -1258,    -1, -1258, -1258, -1258, 10326, -1258, 10326,
    4936,   813,  4936,  4936,     5,   819, -1258,   784,   782, -1258,
     725, -1258,   -70, -1258,   123,    20,   726,    12,   123,  5512,
    5512,   487, -1258, -1258, -1258, -1258, -1258, -1258, -1258,    12,
     823,    20, -1258,   686,   915, -1258, -1258, -1258, -1258, -1258,
     829, -1258, -1258, -1258,  4936, -1258, 10326,   880,   175, -1258,
   -1258,  4936, -1258,   302,   320, -1258, -1258, -1258, -1258, -1258,
     953,   455, -1258, -1258, -1258,  4936, -1258, -1258, -1258, -1258,
   -1258, -1258,   708,    46,   954, -1258,   326, -1258, -1258,   643,
     644,   645,   405,   646,   482,   753,    -1,   762,   764,  6088,
     710,   683,    35, -1258,   766,   802,   812, -1258, -1258,  9486,
     242, -1258,  3496,   810,   814,   841,   815,   817, -1258,  4936,
     719,   888, -1258, -1258, -1258,   719,   888,  3784, -1258, 10326,
   -1258, -1258,  4936, -1258, 10326, -1258,  4936,  4936,   856,  4936,
     857, -1258,   884,   885,  4936, 10326,   602,   935, -1258, -1258,
   -1258,  4072,   825,   828, -1258, -1258, -1258,   876, -1258,   284,
   -1258, -1258,   993, -1258, -1258,  4936, 10326, -1258, -1258,   432,
   -1258, -1258, -1258,   822,   786,   787, -1258, -1258, -1258,   790,
     798, -1258, -1258, -1258, -1258, -1258,   785, 10326,   830, -1258,
     870, -1258,   635, -1258, -1258, -1258,  6952,   709, -1258,  4936,
   10326,   846, -1258,   719, -1258,   550, -1258,    42,   907, -1258,
    4936,   912,   746, -1258,   838,   839, -1258, -1258, -1258, -1258,
   -1258, -1258, -1258,  4936, -1258, -1258,  4936,   881,  4936, -1258,
   -1258,  5512, -1258, -1258, -1258, -1258, -1258,    47,  5512,  5512,
    -120, -1258,   627, -1258, -1258,   184,  5512, -1258, -1258,   610,
      12,   754, -1258, -1258, -1258, -1258,   795,  9766,   906,   932,
     849, -1258,  4936, -1258, -1258, -1258, -1258, -1258,    -6,   999,
    1002,    -6,   -25,   191,   201, -1258, -1258, -1258, -1258,   865,
   10326,   781,   753,  6088, -1258, -1258, 10326,   852,   -18, -1258,
   -1258,   858, -1258, -1258, -1258, -1258, -1258,   916,   940,   719,
     888, -1258,   859, -1258, -1258, -1258, -1258, -1258,  4936, -1258,
    4936, 10326, 10326, -1258,    84, -1258,  4936, -1258,   861, -1258,
   -1258,   905, 10326,   549, -1258,   862,   905, 10326, -1258, -1258,
    4936,  4936,  4936,  4936,  4936, -1258,  4936,  4936, -1258, -1258,
     236, -1258,   863, -1258, -1258, -1258, -1258,   907, -1258, -1258,
   -1258,   719, -1258, -1258, -1258, -1258, -1258, -1258,  4936, -1258,
     348,  5512,  5512,   348,   337, -1258, -1258, -1258, -1258, -1258,
   -1258, -1258, -1258, -1258, -1258, -1258,  9766, -1258,   219,    46,
      46,    -6, -1258, -1258, -1258,    49,    -6,  1016,   799,   949,
   -1258,   949, -1258,  6088,   -66,   767, -1258,   882,   956,  4936,
   10326,  4936, -1258,  4936,   719, -1258, -1258, -1258, -1258,   980,
   -1258, -1258, -1258, -1258,    34,   905, 10326, -1258,   855,   905,
   -1258, -1258, -1258, -1258, -1258, -1258, -1258,   934,  6952, -1258,
   -1258, -1258, -1258, -1258,   348,   348,  5512, -1258, -1258, -1258,
   -1258, -1258, -1258, -1258,    20, -1258,   214, -1258,   220,   946,
   -1258,   960, 10326,   938,   835, 10326,  6088,  9766, -1258,   878,
   -1258, -1258,   888,   944,   181,   188, -1258,   871,   905, -1258,
     873, 10326, -1258,   348,   801,   949, -1258, -1258,  6088, 10326,
     757, 10326,   951,   845,   946,   889,  4936, 10326, -1258, -1258,
     977,   294, -1258, -1258, -1258, -1258,   893,   375, -1258, -1258,
   -1258,   883, -1258,   223, -1258, -1258, -1258,   907,  4936,   772,
   10326,   959,  4936, -1258, -1258, -1258, -1258, -1258, -1258, -1258,
   -1258, -1258,   961,   924, -1258, -1258,   793,   777, 10326, -1258,
   10326, -1258,   805,  4936,   806,   229,  6088, -1258,  6088,   963,
     924, -1258,   887, 10326, -1258,   808,   901, 10326,   924,   864,
   -1258,   967, 10326,   811,  6088, -1258
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   401,   402,   583,   548,   688,   697,   676,   600,   592,
     608,   599,   590,   698,   737,   736,   738,   739,   735,   594,
     695,   596,   623,   658,   652,   693,   620,   696,   753,   647,
     689,   751,   637,   638,   639,   640,   641,   642,   643,   644,
     645,   690,   604,   598,   591,   692,   667,   597,   602,   763,
     764,   765,   766,   767,   768,   769,   770,   771,   772,   773,
     392,   395,   666,   662,   653,   633,   589,   382,     0,   661,
     669,   677,   380,   657,   418,   634,   635,   691,   381,   384,
     654,   671,     0,   424,   390,   420,   664,   588,   655,   656,
     684,   659,   675,   683,   386,   385,   607,   646,   686,   419,
     674,   679,   593,     0,     0,   339,   672,   682,   687,   685,
     665,   651,   740,   649,   650,   391,     0,   338,     0,   394,
     393,   680,   636,   660,     0,   383,   368,     0,   400,   681,
     663,   670,   678,   673,   741,   627,   632,   631,   630,   629,
     628,   601,   648,     0,   587,   694,   621,   727,   726,   728,
     606,   605,   624,   733,   595,   725,   730,   731,   722,   626,
     668,   724,   734,   732,   723,   625,   729,   742,   743,   744,
     747,   745,   748,   746,   749,   750,   752,   714,   713,   619,
     612,   707,   703,   622,   618,   716,   717,   700,   609,   603,
     611,   712,   711,   708,   704,   721,   715,   710,   706,   699,
     610,   720,   719,   614,   616,   615,   705,   709,   701,   617,
     702,   613,   718,   774,   775,   776,   777,   778,   779,   755,
     756,   754,   760,   761,   762,   757,   758,   759,   780,   781,
     782,   783,   784,   785,   786,     0,     0,     2,     0,     4,
       6,    12,     0,     0,     0,    18,    20,    34,    22,    23,
      24,    50,    25,    29,    30,    54,    55,    56,    51,    52,
      58,    59,    27,    26,    31,    32,    33,    53,   198,   197,
     194,   195,   196,    28,    11,   175,   176,   180,   182,   213,
     219,     0,     0,   211,   212,   183,   184,   185,   186,   295,
     297,   299,   309,   312,   314,   317,   322,   325,   328,   330,
     332,   334,     0,   336,   342,   344,     0,   360,   343,   364,
     367,   369,   372,   374,     0,   379,   376,     0,   387,   397,
     399,   373,   403,   408,   416,   409,   410,   411,   414,   415,
     412,   413,   431,   433,   434,   435,   432,   480,   481,   482,
     483,   484,   485,   396,   522,   514,   521,   520,   519,   516,
     518,   515,   517,   417,    57,   187,   188,   190,   189,   191,
     192,   398,   193,   584,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   107,   108,     0,     0,     0,     0,   103,   104,   105,
     106,   111,     0,     0,     0,     0,     0,     0,   101,   156,
     159,     0,     0,     0,     0,     0,     0,   688,   697,   676,
     600,   592,   608,   599,   590,   594,   695,   596,   658,   753,
     647,   751,   637,   638,   598,   591,   589,   659,     0,     0,
     740,   741,   587,   733,   595,   725,   731,   722,   625,   743,
     744,   747,   748,   746,   749,   752,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   581,     0,     0,     0,   582,
       0,     0,     0,     0,     0,     0,   221,     0,     0,     0,
       0,     0,     0,     0,   592,   599,   590,   596,   589,   388,
     398,   421,     0,   422,     0,   447,     0,     0,   363,     0,
       0,   366,     0,     0,   476,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   146,   143,     0,   154,   155,
       0,     0,     0,     3,     1,     5,     7,     0,     0,    13,
      10,    15,    16,     0,   178,   177,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   199,   218,   214,   220,   215,
     217,   216,   223,   224,     0,     0,     0,     0,   353,     0,
       0,   351,     0,   304,     0,   352,   345,   350,   349,   348,
     347,   346,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     341,   340,   337,     0,   361,   365,     0,     0,     0,   375,
     405,   378,   377,   389,   404,     0,     0,     0,   161,     0,
     162,   158,   157,   160,     0,   137,   138,    67,    68,   580,
      76,     0,     0,    61,    62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   549,   550,   551,   110,   109,
       0,     0,     0,     0,   823,   824,     0,    66,   816,   817,
     818,   819,   820,   821,   822,   115,   112,     0,   114,   113,
       0,     0,     0,   102,     0,     0,   546,     0,     0,     0,
       0,     0,   538,     0,     0,     0,     0,     0,   527,     0,
     528,     0,     0,    85,     0,     0,     0,    77,     0,     0,
     529,     0,     0,     0,   284,     0,     0,   236,   237,     0,
       0,   201,   202,     0,     0,   222,     0,     0,     0,   524,
       0,     0,     0,   532,     0,     0,     0,     0,   423,   448,
     447,   444,     0,     0,   478,   477,   362,   537,     0,   475,
       0,   562,   563,   523,     0,     0,     0,     0,     0,     0,
     568,     0,     0,   152,     0,     0,     0,   239,   256,     0,
      19,     0,    21,   181,     0,     0,     0,     0,     0,   200,
     257,     0,     0,     0,     0,     0,     0,     0,     0,   296,
     298,   302,   308,   307,   306,     0,   303,   300,   301,     0,
       0,     0,   808,   310,   787,   795,   797,   799,   801,   803,
     806,   316,   315,   313,   319,   320,   321,   318,   323,   324,
     327,   326,     0,     0,     0,     0,   358,     0,   370,   371,
       0,   406,   427,   429,     0,     0,     0,     0,     0,    65,
       0,     0,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    36,    37,     0,     0,    93,     0,    89,    91,
      92,    96,    99,     0,     0,     0,    35,    75,     0,     0,
     826,   825,     0,   827,   831,     0,     0,   860,   830,   829,
     859,   828,   832,     0,   839,   861,     0,     0,   116,     0,
       0,   119,     0,     0,     0,   354,     0,     0,     0,     0,
       0,   542,     0,   539,   487,     0,   486,   495,   496,     0,
       0,     0,     0,     0,    78,     0,     0,   531,   530,   497,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     586,     0,     0,   203,   204,     0,   209,   545,   525,   526,
       0,     0,   535,     0,   533,   491,     0,     0,   447,   445,
       0,   436,     0,   425,   426,     0,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   688,     0,     0,     0,     0,     0,     0,    17,     0,
     179,     0,   210,   268,   264,   266,     0,   258,   259,     0,
     593,   601,   503,   504,   510,   511,   513,     0,   226,     0,
       0,     0,     0,     0,     0,     0,   305,     0,     0,   802,
       0,   311,     0,   815,     0,     0,     0,     0,     0,     0,
       0,   788,   792,   810,   791,   814,   812,   811,   813,     0,
       0,     0,   804,   867,   865,   869,   807,   329,   331,   333,
     501,   335,   359,   407,     0,   428,     0,   139,     0,   169,
     164,     0,   163,     0,     0,    73,    74,    71,    72,    38,
       0,     0,    94,    95,    97,     0,    98,    63,    64,    69,
      70,    60,     0,     0,     0,   834,     0,   833,   850,     0,
       0,     0,     0,     0,     0,   117,   123,     0,     0,     0,
       0,     0,     0,   120,     0,     0,     0,   356,   355,     0,
       0,   290,     0,     0,     0,   546,     0,     0,   488,     0,
       0,    87,    81,    84,    83,     0,    79,     0,   498,     0,
     282,   286,     0,   151,     0,   241,     0,     0,     0,     0,
       0,   205,     0,     0,     0,     0,   250,     0,   247,   252,
     208,     0,     0,     0,   492,   283,   448,     0,   437,     0,
     471,   468,     0,   472,   473,     0,     0,   474,   467,     0,
     442,   470,   469,     0,     0,     0,   555,   556,   552,     0,
       0,   560,   561,   557,   566,   564,     0,     0,     0,   570,
     149,   148,     0,   145,   144,   153,     0,   571,   572,     0,
       0,   265,   277,     0,   278,     0,   269,   270,   271,   272,
       0,   261,     0,   225,     0,     0,   507,   509,   508,   505,
     234,   235,   228,     0,   230,   227,     0,     0,     0,   809,
     805,     0,   862,   863,   883,   882,   878,     0,     0,     0,
       0,   864,   796,   877,   789,     0,     0,   794,   793,   798,
       0,     0,   868,   866,   502,   430,   171,     0,     0,   140,
       0,   166,     0,   168,   167,    39,    90,   100,   848,     0,
       0,   846,   842,     0,     0,   118,   124,   126,   125,     0,
       0,     0,   121,     0,    14,   357,     0,     0,     0,   291,
     489,     0,   543,   544,   547,   540,   541,     0,    86,     0,
      80,   499,     0,   285,   287,   238,   243,   242,     0,   245,
       0,     0,     0,   207,   248,   251,     0,   493,     0,   536,
     534,   447,     0,     0,   479,     0,   447,     0,   443,     9,
       0,     0,     0,     0,     0,   569,     0,     0,   147,   578,
       0,   573,     0,   240,   281,   279,   280,   273,   274,   275,
     267,     0,   262,   260,   512,   506,   232,   229,     0,   231,
     884,     0,     0,   870,     0,   881,   880,   879,   874,   875,
     790,   800,   876,   172,   141,   170,     0,   174,     0,     0,
       0,   849,   851,   853,   855,     0,   847,     0,     0,     0,
     837,     0,   835,     0,     0,     0,   122,     0,     0,     0,
       0,     0,   490,     0,     0,    82,   500,   244,   246,   255,
     254,   249,   206,   494,     0,   447,     0,   173,     0,   447,
     553,   554,   558,   559,   565,   567,   150,     0,     0,   574,
     585,   276,   263,   233,   872,   871,     0,   142,   165,   858,
     857,   852,   856,   854,   843,   844,     0,   840,     0,   127,
     129,     0,     0,     0,     0,     0,     0,     0,   292,     0,
     288,   294,    88,     0,   457,   451,   446,     0,   447,   438,
       0,     0,   579,   873,     0,     0,   838,   836,     0,     0,
       0,     0,     0,     0,   128,     0,     0,     0,   465,   459,
       0,   458,   460,   466,   463,   453,     0,   452,   454,   464,
     440,     0,   439,     0,   845,   841,   130,   131,     0,     0,
       0,     0,     0,   289,   253,   450,   461,   462,   449,   455,
     456,   441,     0,     0,   132,   133,     0,     0,     0,   293,
       0,   575,     0,     0,     0,     0,     0,   135,     0,     0,
       0,   134,     0,     0,   576,     0,     0,     0,     0,     0,
     577,     0,     0,     0,     0,   136
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1258, -1258,   844, -1258,   843,   850, -1258,   842, -1258,   561,
     565,  -509, -1258,   466,  -345, -1258, -1258, -1258, -1258, -1258,
   -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258,  -881,
   -1258, -1258, -1258, -1258,    58,   264,   716, -1258, -1258,   695,
   -1258,    29,  -841, -1258,  -323,  -343, -1258, -1258,  -127, -1258,
    -859, -1258, -1258,   -55, -1258, -1258, -1258, -1258, -1258,   325,
     732, -1258, -1258, -1258,  -116, -1258, -1257,   866,   -96, -1258,
    -524,  -421, -1258, -1258, -1258, -1258,   197, -1258, -1258,   831,
   -1258, -1258, -1258, -1258, -1258,   145,  -511,  -660, -1258, -1258,
   -1258,    13, -1258, -1258,  -168,     3,   -50, -1258, -1258, -1258,
     -61, -1258, -1258,   162,   -56, -1258, -1258,   -52, -1140, -1258,
     637,    27, -1258, -1258,    48, -1258, -1258,   575,   576, -1258,
    -502,  -949,   554,   137,  -552,   132,   134, -1258, -1258, -1258,
   -1258, -1258,   821, -1258, -1258, -1258, -1258, -1258,   834, -1028,
   -1258,  -106, -1258, -1258, -1258, -1258, -1258, -1258, -1258,   -45,
   -1126, -1258, -1258,  -170,   -21, -1258,  -562, -1258, -1258, -1258,
   -1258, -1258, -1258, -1258, -1258, -1258,  -897, -1258,    16, -1258,
     419,  -705, -1258, -1258, -1258, -1258, -1258,  -321,  -314, -1041,
   -1083, -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258, -1258,
   -1258,   347,  -663,  -782,    85,   319,  -786,  -738, -1258, -1258,
   -1258, -1258, -1258, -1258, -1258,   684,   687,  -347,   271,   116,
   -1258, -1258, -1258, -1258, -1258, -1258, -1258,    -2, -1258, -1258,
      -8, -1258,  -370,   -92,    -9, -1258, -1258,   378, -1258, -1258,
     163,   153,   -57,   384, -1258, -1258,   165, -1258,  -733, -1258,
   -1258, -1258, -1258,  -193,  -840, -1258,   -72,  -625, -1258,  -757,
   -1258, -1258, -1258, -1258,  -986, -1258, -1258, -1258, -1258,   -44,
     172, -1258
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   822,   823,   824,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,  1081,
     676,   261,   262,   828,   829,   830,  1150,   263,   397,   398,
     264,  1055,   858,   265,  1409,  1410,   266,   267,   806,   268,
     506,   732,   942,  1151,   269,   270,   271,   272,   273,   399,
     400,   598,   600,  1018,  1019,  1127,  1022,   274,   275,   525,
     276,   277,   278,   535,   467,   905,   906,   279,   536,   280,
     538,   281,   282,   283,   542,   543,  1106,   757,   284,   687,
     736,   688,   694,  1107,  1108,  1109,   737,   539,   540,   957,
     958,  1312,   541,   954,   955,  1166,  1167,  1168,  1169,   285,
     683,   684,   286,  1070,  1071,   287,   288,   289,   290,   765,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   562,   563,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   589,   590,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   804,   331,   332,   333,  1129,   710,
     711,   712,  1426,  1456,  1457,  1450,  1451,  1458,  1452,  1130,
    1131,   334,   335,  1132,   336,   337,   338,   339,   340,   341,
     342,  1009,   758,   962,  1179,   963,   964,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   655,  1074,   353,
     354,   355,   356,   357,   358,   359,   729,   730,   360,  1157,
    1158,  1300,  1082,   458,   361,   362,   363,   773,   991,   774,
     775,   776,   777,   778,   779,   780,   992,   993,   637,   638,
     639,   640,   641,  1406,  1407,   642,  1341,  1231,  1345,  1342,
     643,   644,   995,  1006,  1200,   996,   997,  1002,   998,  1328,
    1196,   981
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       446,   744,   772,   610,  1086,   920,  1047,   484,  1010,  1010,
    1007,  1008,   459,   742,   965,  1211,   784,   785,   786,   787,
    1063,   491,   894,   479,   487,  1128,   899,  1308,  1309,   898,
    1299,  1239,     4,   756,   364,   365,   366,   367,   368,   369,
    1204,   994,   690,  1389,  1412,   761,   370,   762,   763,   493,
     764,   753,   766,   902,   965,   965,   697,   473,   856,   480,
     767,   768,   714,  1197,   752,   697,   927,  1049,  1050,  1402,
    1097,   376,   752,   481,   753,   721,   722,  1051,   724,   725,
     726,   727,   523,   673,   677,  1155,   733,   965,  1288,   734,
    1321,   698,  1360,   630,  1062,   485,   971,   970,   975,   973,
     698,  1052,   743,   377,   378,   949,   938,   459,  1197,   489,
     897,   925,   749,   750,    74,   490,   891,   523,  1056,  1424,
    1339,  1016,   754,   931,  1053,   453,    85,  1044,   464,   465,
     921,   609,   946,  1176,  1229,   609,  1192,  1152,  1325,   607,
    1163,  1186,  1102,  1103,  1045,  1326,   592,   454,  1413,   406,
      99,   891,   594,   565,   769,  1327,  1361,   770,   381,  1165,
    1020,   870,   524,  1177,   517,  1224,  1322,  1391,  1034,   926,
     566,   608,   753,  1193,   803,  1021,   842,   872,   947,   911,
     518,  1178,   466,  1340,  1046,  1448,  1017,   928,   929,  1120,
     382,  1230,   913,   892,  1014,   922,  1120,   950,   857,   903,
     755,   699,   930,   585,  1260,  1425,  1234,  1454,   772,   772,
    1120,  1121,   124,  1117,  1235,  1357,   674,  1153,   715,   384,
    1198,  1199,  1128,   755,  1403,   755,  1491,   631,   917,  1414,
     494,   939,  1128,   402,   857,  1347,   904,   871,  1100,  1098,
     755,   632,  1288,  1504,   932,   933,  1348,   974,   755,  1054,
     385,  1510,   837,   873,   633,   912,   634,  1330,  1208,   934,
     675,   771,  1432,   976,   672,  1198,  1199,   755,   914,   591,
    1015,   635,   593,   544,  1218,   636,   386,   387,   388,   389,
     390,  1118,   391,   392,   393,   394,   395,  1247,   624,   403,
    1349,   396,  1120,  1121,  1123,   619,  1124,  1122,  1448,   620,
    1351,  1123,  1120,  1124,  1449,   480,   884,   657,   480,   654,
     660,   843,  1455,  1435,  1187,  1123,   574,  1124,   523,  1435,
     752,   605,  1482,  1125,  1056,  1411,   953,  1484,  1499,   575,
    1125,   965,   661,   968,  1069,   606,   621,   844,   845,   846,
     447,  1453,  1459,   847,  1125,  1025,  1119,  1248,   104,   583,
    1219,   666,   667,   401,   669,   596,   671,   404,   405,   825,
     678,   604,  1026,   622,   116,   681,  1350,   615,  1453,   752,
     893,   459,   118,   572,  1459,   702,  1352,   645,  1021,  1122,
    1194,  1387,   573,  1120,   647,  1126,  1128,  1195,  1411,  1436,
     713,  1398,   459,   656,  1454,  1437,   718,  1123,  1483,  1124,
     826,  1356,  1162,   143,  1500,   827,  1033,  1123,   452,  1124,
    1411,  1027,  1036,  1163,  1044,   735,   565,  1476,  1434,  1099,
     664,   448,   623,  1164,   449,   772,  1125,   460,  1028,  1221,
     104,  1233,  1165,   566,  1388,  1334,  1125,   772,  1205,   742,
    1120,  1121,  1325,   611,  1222,   502,   116,  1223,   459,  1326,
     503,   685,   686,   689,  1102,  1103,   567,  1104,   612,  1327,
     696,   613,   505,   705,  1037,  1038,   463,  1282,  1501,  1041,
    1502,  1090,  1091,   685,  1093,   614,  1095,  1029,     4,   965,
     798,   799,   461,  1422,   753,   143,  1515,   797,  1123,   840,
    1124,  1029,   800,  1065,   568,   731,  1115,  1060,   450,  1479,
     841,   451,   462,   738,   381,  1061,  1105,  1136,  1137,  1138,
     848,  1141,  1142,  1143,  1144,  1145,  1146,  1125,  1148,  1149,
     569,   849,   526,  1073,  1396,  1076,   572,  1122,   527,   468,
     953,   528,   529,   570,   982,   573,   382,   572,   630,   530,
     625,   626,   627,   832,   469,  1123,   573,  1124,   833,  1182,
     470,  1184,  1185,  1333,  1397,  1003,  1004,  1120,  1121,  1134,
      74,  1135,   866,   867,  1112,   384,  1113,   571,   801,   875,
     482,   801,    85,   801,  1125,   982,  1374,  1005,   104,   630,
     880,  1378,   826,   883,  1401,   851,   890,   827,   807,  1401,
     808,   586,   587,  1215,   116,  1465,    99,   496,   965,   497,
     769,   628,   629,   770,   983,   499,   486,   500,   831,   492,
     916,   852,   853,   854,  1227,  1287,  1139,   855,  1140,  1039,
    1040,   495,   651,   387,   388,   389,   390,   498,   391,   392,
     652,   394,   395,   143,   531,  1445,   943,   532,   501,  1320,
     504,   860,   861,   862,  1122,   983,  1323,  1324,   772,  1057,
    1058,   533,   505,  1467,   364,   365,   366,   507,  1257,   369,
    1102,  1103,  1123,   459,  1124,   508,   459,   509,  1305,  1306,
    1427,  1264,   631,   977,  1430,  1266,  1267,   534,  1269,   965,
    1023,  1024,   510,  1273,   901,   511,   632,   984,   985,   512,
     986,  1125,   601,   602,   514,   104,   521,   987,  1338,   633,
     918,   634,   781,   782,   788,   789,   522,   988,   790,   791,
    1258,   116,   545,   631,  1399,  1400,   635,   989,   546,   990,
     636,   564,   576,  1461,   577,   578,   588,   632,   984,   985,
     579,   986,  1376,   595,   597,   599,   364,   952,  1302,   609,
     633,   616,   634,   966,   646,   617,   648,   658,   988,   953,
     143,   659,   649,   650,   665,   668,   670,   635,  1206,   682,
     990,   636,  1316,   691,   692,  1317,   693,  1319,  1066,  1394,
    1395,   812,   813,   814,   815,   816,   817,   818,   819,   820,
     821,   695,   706,   966,   966,   966,   966,   429,   449,   451,
     457,   472,   709,  1304,   708,   716,   717,   719,   720,   723,
     741,   746,   728,   751,   745,   792,   793,   747,   748,   794,
     795,   805,   809,   810,   811,   838,   966,   834,   835,   839,
     850,   859,   864,   865,   881,   863,   882,   868,   879,   869,
     876,   877,   878,   885,   886,   935,   887,   895,   888,   896,
     907,   936,   900,   937,  1433,   940,   910,  1367,   908,  1368,
     909,   923,   944,   924,   945,  1372,   956,   948,   959,  1000,
     967,  1075,   969,  1075,   972,   951,   980,  1001,  1012,  1380,
    1381,  1382,  1383,  1384,   999,  1385,  1386,  1030,  1043,   827,
    1013,   752,   364,   365,   366,   367,   368,   369,  1035,  1365,
    1042,  1048,  1059,  1067,   370,  1064,  1069,  1393,   547,  1068,
     371,  1072,   656,  1078,   656,  1080,   548,   549,  1079,   550,
    1083,   372,   373,  1084,  1085,   374,   551,  1089,   375,   376,
     552,  1087,   553,  1088,  1092,  1220,  1094,   554,  1101,  1096,
    1114,  1111,  1116,  1133,  1147,  1154,  1159,  1160,  1418,   621,
    1420,  1392,  1421,   555,  1156,  1170,  1172,  1171,  1174,  1183,
     544,   377,   378,   379,  1175,  1188,  1189,  1190,  1180,  1210,
    1181,  1212,  1213,  1214,  1191,  1201,  1217,   556,   557,   558,
     559,   560,   561,     4,  1232,  1254,  1251,  1241,  1237,   857,
    1238,  1244,  1243,  1228,  1245,  1252,  1240,  1259,  1268,  1253,
    1255,  1262,  1256,  1270,  1271,  1272,  1276,   380,  1281,  1284,
    1279,  1289,  1297,  1280,  1296,  1163,   381,  1216,  1290,  1291,
    1311,  1294,  1292,  1314,  1315,  1278,  1016,  1318,  1336,  1343,
    1293,  1337,  1344,  1332,  1353,  1473,  1359,  1355,  1364,  1285,
    1362,  1366,  1363,  1373,  1377,  1390,  1404,  1044,   382,  1423,
    1429,  1416,  1417,  1415,  1431,  1438,  1439,  1485,  1441,  1442,
    1468,  1489,  1446,  1405,  1447,  1464,  1460,   383,  1462,  1471,
     966,  1470,  1475,  1472,  1478,  1486,  1021,   384,  1481,  1488,
    1493,  1490,  1497,  1503,  1505,  1492,  1508,  1512,  1511,   513,
     685,   515,   739,   519,  1507,   689,   740,   836,   516,  1226,
    1032,  1242,   653,  1444,   618,  1466,  1274,  1298,   385,  1496,
    1498,   603,  1335,  1110,  1173,  1514,  1371,  1265,   520,  1275,
    1303,  1313,   537,  1161,  1310,  1307,  1263,  1286,  1249,   707,
     759,   783,   760,   582,   386,   387,   388,   389,   390,   919,
     391,   392,   393,   394,   395,  1283,  1480,  1477,   731,   396,
     584,  1236,  1011,  1077,  1031,  1295,  1225,   480,   978,  1301,
    1202,   738,  1209,  1331,   700,   979,  1207,   701,  1408,  1346,
    1203,  1329,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   966,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1354,     0,     0,     0,     0,     0,  1358,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1369,  1370,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1375,     0,     0,     0,     0,  1379,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   966,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1419,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1428,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   480,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1440,     0,     0,  1443,     0,   966,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1463,     0,     0,     0,     0,     0,     0,     0,
     966,     0,  1469,     0,     0,     0,     0,     0,  1474,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1487,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1494,
       0,  1495,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     0,     0,     0,  1506,     0,     2,     3,  1509,     4,
       0,     0,     0,  1513,     5,     6,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     0,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,     0,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,     0,    72,    73,     0,     0,
       0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,     0,    85,     0,    86,    87,    88,    89,     0,
      90,     0,     0,     0,    91,    92,    93,    94,    95,     0,
       0,     0,     0,     0,    96,    97,    98,    99,   100,   101,
     102,     0,     0,     0,   103,   104,   105,   106,   107,     0,
       0,     0,     0,   108,   109,   110,   111,   112,   113,   114,
     115,   116,     0,   117,   118,     0,     0,   119,   120,   121,
       0,     0,     0,   122,     0,   123,   124,   125,     0,   126,
     127,   128,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   144,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,     0,   187,   188,   189,
       0,   190,   191,   192,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,   407,   408,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,   416,
      21,    22,    23,    24,    25,    26,    27,     0,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,     0,    72,    73,     0,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,     0,    85,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,    91,    92,    93,    94,    95,     0,     0,
       0,     0,     0,    96,    97,    98,    99,   100,   101,   102,
       0,     0,     0,   103,   104,   105,   106,   107,     0,     0,
       0,     0,   108,   109,   110,   111,   112,   113,   114,   115,
     116,     0,   117,   118,     0,     0,   119,   120,   121,     0,
       0,     0,   122,   483,   123,   124,   125,     0,   126,   127,
     128,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   432,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,     0,   187,   188,   189,     0,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
       0,   407,   408,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,   416,    21,    22,
      23,    24,    25,    26,    27,     0,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,    72,    73,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,    96,    97,    98,    99,   100,   101,   102,     0,     0,
       0,   103,   104,   105,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   112,   113,   114,   115,   116,     0,
     117,   118,     0,     0,   119,   120,   121,     0,   796,     0,
     122,     0,   123,   124,   125,     0,   126,   127,   128,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   432,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,   407,
     408,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,   416,    21,    22,    23,    24,
      25,    26,    27,     0,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
       0,    72,    73,     0,     0,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     0,    85,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,    91,
      92,    93,    94,    95,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,   103,
     104,   105,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     0,   117,   118,
       0,     0,   119,   120,   121,     0,     0,     0,   122,   802,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   432,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,     0,   187,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,   407,   408,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,   416,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,     0,    72,
      73,     0,     0,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,    85,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,    91,    92,    93,
      94,    95,     0,     0,     0,     0,     0,    96,    97,    98,
      99,   100,   101,   102,     0,     0,     0,   103,   104,   105,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   111,
     112,   113,   114,   115,   116,     0,   117,   118,     0,     0,
     119,   120,   121,     0,   874,     0,   122,     0,   123,   124,
     125,     0,   126,   127,   128,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   432,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,     0,
     187,   188,   189,     0,   190,   191,   192,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,   407,   408,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,   416,    21,    22,    23,    24,    25,    26,    27,     0,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,     0,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,     0,    72,    73,     0,
       0,     0,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,     0,    85,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,    91,    92,    93,    94,    95,
       0,     0,     0,     0,     0,    96,    97,    98,    99,   100,
     101,   102,     0,     0,     0,   103,   104,   105,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   111,   112,   113,
     114,   115,   116,     0,   117,   118,     0,     0,   119,   120,
     121,     0,   889,     0,   122,     0,   123,   124,   125,     0,
     126,   127,   128,     0,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,   143,     0,   432,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,     0,   187,   188,
     189,     0,   190,   191,   192,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,   407,   408,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,   416,
      21,    22,    23,    24,    25,    26,    27,     0,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,     0,    72,    73,     0,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,     0,    85,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,    91,    92,    93,    94,    95,     0,     0,
       0,     0,     0,    96,    97,    98,    99,   100,   101,   102,
       0,     0,     0,   103,   104,   105,   106,   107,     0,     0,
       0,     0,   108,   109,   110,   111,   112,   113,   114,   115,
     116,     0,   117,   118,     0,     0,   119,   120,   121,     0,
     915,     0,   122,     0,   123,   124,   125,     0,   126,   127,
     128,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   432,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,     0,   187,   188,   189,     0,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
       0,   407,   408,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,   416,    21,    22,
      23,    24,    25,    26,    27,     0,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,    72,    73,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,    96,    97,    98,    99,   100,   101,   102,     0,     0,
       0,   103,   104,   105,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   112,   113,   114,   115,   116,     0,
     117,   118,     0,     0,   119,   120,   121,     0,  1250,     0,
     122,     0,   123,   124,   125,     0,   126,   127,   128,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   432,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,   407,
     408,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,   416,    21,    22,    23,    24,
      25,    26,    27,     0,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
       0,    72,    73,     0,     0,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     0,    85,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,    91,
      92,    93,    94,    95,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,   103,
     104,   105,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     0,   117,   118,
       0,     0,   119,   120,   121,     0,  1261,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   432,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,     0,   187,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,   407,   408,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,   416,    21,    22,    23,    24,    25,    26,
      27,     0,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,     0,    72,
      73,     0,     0,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,    85,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,    91,    92,    93,
      94,    95,     0,     0,     0,     0,     0,    96,    97,    98,
      99,   100,   101,   102,     0,     0,     0,   103,   104,   105,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   111,
     112,   113,   114,   115,   116,     0,   117,   118,     0,     0,
     119,   120,   121,     0,  1277,     0,   122,     0,   123,   124,
     125,     0,   126,   127,   128,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   432,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,     0,
     187,   188,   189,     0,   190,   191,   192,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,     5,     6,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,     0,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,     0,    72,    73,     0,
       0,     0,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,     0,    85,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,    91,    92,    93,    94,    95,
       0,     0,     0,     0,     0,    96,    97,    98,    99,   100,
     101,   102,     0,     0,     0,   103,   104,   105,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   111,   112,   113,
     114,   115,   116,     0,   117,   118,     0,     0,   119,   120,
     121,     0,     0,     0,   122,     0,   123,   124,   125,     0,
     126,   127,   128,     0,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,   143,     0,   144,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,     0,   187,   188,
     189,     0,   190,   191,   192,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,     5,     6,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     0,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,     0,    72,    73,     0,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,     0,    85,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,    91,    92,    93,    94,    95,     0,     0,
       0,     0,     0,    96,    97,    98,    99,   100,   101,   102,
       0,     0,     0,   103,   104,   105,   106,   107,     0,     0,
       0,     0,   108,   109,   110,   111,   112,   113,   114,   115,
     116,     0,   117,   118,     0,     0,   119,   120,   121,     0,
       0,     0,   122,     0,   123,   124,   125,     0,   126,   127,
     128,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   432,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,     0,   187,   188,   189,     0,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
       0,   407,   408,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,   416,    21,    22,
      23,    24,    25,    26,    27,     0,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,    72,    73,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,    96,    97,    98,    99,   100,   101,   102,     0,     0,
       0,   103,   104,   105,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   112,   113,   114,   115,   116,     0,
     117,   118,     0,     0,   119,   120,   121,     0,     0,     0,
     122,     0,   123,   124,   125,     0,   126,   127,   128,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   432,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,   407,
     408,     0,     7,   410,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,   415,   416,    21,    22,   418,    24,
      25,    26,    27,     0,   419,   420,    30,   421,   422,   423,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
       0,    72,    73,     0,     0,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     0,    85,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,   427,
      92,    93,    94,    95,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,   103,
     104,   580,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     0,   581,   118,
       0,     0,   119,   120,   121,     0,     0,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   432,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   433,   154,   435,
     156,   436,   437,   159,   160,   161,   162,   163,   164,   438,
     166,   167,   439,   440,   441,   171,   442,   443,   444,   175,
     445,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,     0,   187,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,   407,   408,     0,
       7,   410,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,   415,   416,    21,    22,   418,    24,    25,    26,
      27,     0,   419,   420,    30,   421,   422,   423,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,     0,    72,
      73,     0,     0,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,    85,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   427,    92,    93,
      94,    95,     0,     0,     0,     0,     0,    96,    97,    98,
      99,   100,   101,   102,     0,     0,     0,   103,   104,   105,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   111,
     112,   113,   114,   115,   116,     0,   117,   118,     0,     0,
     119,   120,   121,     0,     0,     0,   122,     0,   123,   124,
     125,     0,   126,   127,   128,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   432,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   433,   154,   435,   156,   436,
     437,   159,   160,   161,   162,   163,   164,   438,   166,   167,
     439,   440,   441,   171,   442,   443,   444,   175,   445,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,     0,
     187,   188,   189,     0,   190,   191,   192,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,   941,   408,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,   416,    21,    22,    23,    24,    25,    26,    27,     0,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,     0,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,     0,    72,    73,     0,
       0,     0,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,     0,    85,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,    91,    92,    93,    94,    95,
       0,     0,     0,     0,     0,    96,    97,    98,    99,   100,
     101,   102,     0,     0,     0,   103,   104,   105,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   111,   112,   113,
     114,   115,   116,     0,   117,   118,     0,     0,   119,   120,
     121,     0,     0,     0,   122,     0,   123,   124,   125,     0,
     126,   127,   128,     0,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,   143,     0,   432,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,     0,   187,   188,
     189,     0,   190,   191,   192,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,   407,   408,     0,   409,   410,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,   415,   416,
      21,    22,   418,    24,    25,    26,    27,     0,   419,   420,
      30,   421,   422,   423,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,     0,    72,    73,     0,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,     0,    85,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,   427,    92,    93,    94,    95,     0,     0,
       0,     0,     0,    96,    97,    98,    99,   100,   101,   102,
       0,     0,     0,   103,   104,     0,   106,   107,     0,     0,
       0,     0,   108,   109,   110,   111,   112,   113,   114,   115,
     116,     0,     0,     0,     0,     0,   119,   120,   121,     0,
       0,     0,   122,     0,   123,   124,   125,     0,   126,   127,
     128,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   432,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   433,   154,   435,   156,   436,   437,   159,   160,   161,
     162,   163,   164,   438,   166,   167,   439,   440,   441,   171,
     442,   443,   444,   175,   445,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,     0,   187,   188,   189,     0,
     190,   191,   192,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
       0,   407,   408,     0,   409,   410,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,   415,   416,    21,    22,
     418,    24,    25,    26,    27,     0,   419,   420,    30,   421,
     422,   423,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,    72,    73,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   427,    92,    93,    94,    95,     0,     0,     0,     0,
       0,    96,    97,    98,    99,   100,   101,   102,     0,     0,
       0,   103,   104,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   112,   113,   114,   115,   116,     0,
       0,     0,     0,     0,   119,   120,   121,     0,     0,     0,
     122,     0,   123,   124,   125,     0,     0,     0,   128,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   432,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   433,
     154,   435,   156,   436,   437,   159,   160,   161,   162,   163,
     164,   438,   166,   167,   439,   440,   441,   171,   442,   443,
     444,   175,   445,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     0,     0,     0,     0,     0,   407,
     408,     0,   409,   410,   474,   412,   475,   476,    13,    14,
      15,    16,    17,    18,   415,   416,   477,    22,   418,    24,
      25,    26,    27,     0,   419,   420,    30,   421,   422,   423,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    62,     0,
      63,    64,    65,   478,     0,     0,    69,    70,    71,     0,
       0,     0,    73,     0,     0,     0,     0,    75,    76,    77,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,   427,
      92,    93,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,     0,   100,   101,   102,     0,     0,     0,     0,
       0,     0,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   430,   113,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,   122,     0,
     123,   124,     0,     0,     0,     0,   128,     0,   129,     0,
     130,   131,   132,   133,   431,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,     0,     0,   432,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   433,   154,   435,
     156,   436,   437,   159,   160,   161,   162,   163,   164,   438,
     166,   167,   439,   440,   441,   171,   442,   443,   444,   175,
     445,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,     0,   187,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     0,     0,     0,     0,     0,   407,   408,     0,
     409,   410,   411,   412,   413,   414,    13,    14,    15,    16,
      17,    18,   415,   416,   417,    22,   418,    24,    25,    26,
      27,     0,   419,   420,    30,   421,   422,   423,    34,    35,
      36,    37,    38,    39,    40,    41,    42,   424,   425,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     0,     0,    62,     0,    63,    64,
      65,   426,     0,     0,    69,    70,    71,     0,     0,     0,
      73,     0,     0,     0,     0,    75,    76,    77,     0,     0,
      80,    81,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   427,    92,    93,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
       0,   100,   101,   102,     0,     0,     0,     0,     0,     0,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   111,
     430,   113,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,     0,     0,     0,   122,     0,   123,     0,
       0,     0,     0,     0,   128,     0,   129,     0,   130,   131,
     132,   133,   431,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,     0,     0,   432,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   433,   434,   435,   156,   436,
     437,   159,   160,   161,   162,   163,   164,   438,   166,   167,
     439,   440,   441,   171,   442,   443,   444,   175,   445,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,     0,
     187,   188,   189,     0,   190,   191,   192,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     455,     0,     0,     0,     3,     0,     0,     0,     0,     0,
       0,   407,   408,     0,   409,   410,   411,   412,   413,   414,
      13,    14,    15,    16,    17,    18,   415,   416,   417,    22,
     418,    24,    25,    26,    27,     0,   419,   420,    30,   421,
     422,   423,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   424,   425,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   426,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   427,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   102,   456,     0,
       0,   457,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   430,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,     0,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   431,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   432,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   433,
     434,   435,   156,   436,   437,   159,   160,   161,   162,   163,
     164,   438,   166,   167,   439,   440,   441,   171,   442,   443,
     444,   175,   445,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   455,     0,     0,     0,     3,     0,
     679,     0,     0,     0,     0,   407,   408,     0,   409,   410,
     411,   412,   413,   414,    13,    14,    15,    16,    17,    18,
     415,   416,   417,    22,   418,    24,    25,    26,    27,     0,
     419,   420,    30,   421,   422,   423,    34,    35,    36,    37,
      38,    39,    40,    41,    42,   424,   425,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    62,     0,    63,    64,    65,   426,
       0,     0,    69,    70,    71,     0,     0,     0,    73,     0,
       0,     0,     0,    75,    76,    77,     0,     0,    80,    81,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,   427,    92,    93,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,     0,   100,
     101,   102,     0,     0,     0,     0,     0,     0,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   111,   430,   113,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,     0,     0,     0,   122,   680,   123,     0,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     431,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,     0,     0,   432,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   433,   434,   435,   156,   436,   437,   159,
     160,   161,   162,   163,   164,   438,   166,   167,   439,   440,
     441,   171,   442,   443,   444,   175,   445,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,     0,   187,   188,
     189,     0,   190,   191,   192,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   455,     0,
       0,     0,     3,     0,     0,     0,     0,     0,     0,   407,
     408,     0,   409,   410,   411,   412,   413,   414,    13,    14,
      15,    16,    17,    18,   415,   416,   417,    22,   418,    24,
      25,    26,    27,     0,   419,   420,    30,   421,   422,   423,
      34,    35,    36,    37,    38,    39,    40,    41,    42,   424,
     425,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    62,     0,
      63,    64,    65,   426,     0,     0,    69,    70,    71,     0,
       0,     0,    73,     0,     0,     0,     0,    75,    76,    77,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,   427,
      92,    93,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,     0,   100,   101,   102,     0,     0,     0,     0,
       0,     0,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   430,   113,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,   122,     0,
     123,     0,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   431,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,     0,     0,   432,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   433,   434,   435,
     156,   436,   437,   159,   160,   161,   162,   163,   164,   438,
     166,   167,   439,   440,   441,   171,   442,   443,   444,   175,
     445,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,     0,   187,   188,   189,     0,   190,   191,   192,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   488,     0,     3,     0,     0,     0,     0,     0,
       0,   407,   408,     0,   409,   410,   411,   412,   413,   414,
      13,    14,    15,    16,    17,    18,   415,   416,   417,    22,
     418,    24,    25,    26,    27,     0,   419,   420,    30,   421,
     422,   423,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   424,   425,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   426,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   427,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   102,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   430,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,     0,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   431,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   432,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   433,
     434,   435,   156,   436,   437,   159,   160,   161,   162,   163,
     164,   438,   166,   167,   439,   440,   441,   171,   442,   443,
     444,   175,   445,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     3,     0,     0,     0,     0,     0,
       0,   407,   408,     0,   409,   410,   411,   412,   413,   414,
      13,    14,    15,    16,    17,    18,   415,   416,   417,    22,
     418,    24,    25,    26,    27,     0,   419,   420,    30,   421,
     422,   423,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   424,   425,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   426,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   427,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   102,   428,     0,
       0,   429,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   430,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,     0,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   431,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   432,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   433,
     434,   435,   156,   436,   437,   159,   160,   161,   162,   163,
     164,   438,   166,   167,   439,   440,   441,   171,   442,   443,
     444,   175,   445,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     3,     0,     0,     0,     0,     0,
       0,   407,   408,     0,   409,   410,   411,   412,   413,   414,
      13,    14,    15,    16,    17,    18,   415,   416,   417,    22,
     418,    24,    25,    26,    27,     0,   419,   420,    30,   421,
     422,   423,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   424,   425,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   426,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   427,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   102,   471,     0,
       0,   472,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   430,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,     0,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   431,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   432,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   433,
     434,   435,   156,   436,   437,   159,   160,   161,   162,   163,
     164,   438,   166,   167,   439,   440,   441,   171,   442,   443,
     444,   175,   445,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     3,     0,     0,     0,     0,     0,
       0,   407,   408,     0,   409,   410,   411,   412,   413,   414,
      13,    14,    15,    16,    17,    18,   415,   416,   417,    22,
     418,    24,    25,    26,    27,     0,   419,   420,    30,   421,
     422,   423,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   424,   425,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   426,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   427,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   102,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   430,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,   662,   123,     0,     0,     0,     0,     0,   663,     0,
     129,     0,   130,   131,   132,   133,   431,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   432,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   433,
     434,   435,   156,   436,   437,   159,   160,   161,   162,   163,
     164,   438,   166,   167,   439,   440,   441,   171,   442,   443,
     444,   175,   445,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     3,     0,     0,     0,     0,     0,
       0,   407,   408,     0,   409,   410,   411,   412,   413,   414,
      13,    14,    15,    16,    17,    18,   415,   416,   417,    22,
     418,    24,    25,    26,    27,     0,   419,   420,    30,   421,
     422,   423,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   424,   425,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   426,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   427,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   102,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   430,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,   703,   123,     0,     0,     0,     0,     0,   704,     0,
     129,     0,   130,   131,   132,   133,   431,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   432,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   433,
     434,   435,   156,   436,   437,   159,   160,   161,   162,   163,
     164,   438,   166,   167,   439,   440,   441,   171,   442,   443,
     444,   175,   445,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     3,     0,     0,     0,     0,     0,
       0,   407,   408,     0,   409,   410,   474,   412,   475,   476,
      13,    14,    15,    16,    17,    18,   415,   416,   477,    22,
     418,    24,    25,    26,    27,     0,   419,   420,    30,   421,
     422,   423,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   478,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,  1246,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   427,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   960,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   430,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,   124,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   431,   135,   136,   137,
     138,   139,   140,     0,     0,   961,   142,     0,     0,   432,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   433,
     154,   435,   156,   436,   437,   159,   160,   161,   162,   163,
     164,   438,   166,   167,   439,   440,   441,   171,   442,   443,
     444,   175,   445,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     3,     0,     0,     0,     0,     0,
       0,   407,   408,     0,   409,   410,   474,   412,   475,   476,
      13,    14,    15,    16,    17,    18,   415,   416,   477,    22,
     418,    24,    25,    26,    27,     0,   419,   420,    30,   421,
     422,   423,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   478,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   427,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   960,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   430,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,   124,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   431,   135,   136,   137,
     138,   139,   140,     0,     0,   961,   142,     0,     0,   432,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   433,
     154,   435,   156,   436,   437,   159,   160,   161,   162,   163,
     164,   438,   166,   167,   439,   440,   441,   171,   442,   443,
     444,   175,   445,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     3,     0,     0,     0,     0,     0,
       0,   407,   408,     0,   409,   410,   474,   412,   475,   476,
      13,    14,    15,    16,    17,    18,   415,   416,   477,    22,
     418,    24,    25,    26,    27,     0,   419,   420,    30,   421,
     422,   423,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   478,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   427,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   960,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   430,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,   124,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   431,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   432,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   433,
     154,   435,   156,   436,   437,   159,   160,   161,   162,   163,
     164,   438,   166,   167,   439,   440,   441,   171,   442,   443,
     444,   175,   445,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     3,     0,     0,     0,     0,     0,
       0,   407,   408,     0,   409,   410,   411,   412,   413,   414,
      13,    14,    15,    16,    17,    18,   415,   416,   417,    22,
     418,    24,    25,    26,    27,     0,   419,   420,    30,   421,
     422,   423,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   424,   425,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   426,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   427,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   102,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   430,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,     0,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   431,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   432,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   433,
     434,   435,   156,   436,   437,   159,   160,   161,   162,   163,
     164,   438,   166,   167,   439,   440,   441,   171,   442,   443,
     444,   175,   445,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         9,   525,   564,   373,   885,   710,   846,   103,   794,   795,
     792,   793,    21,   522,   752,  1001,   568,   569,   570,   571,
     861,   127,   685,    68,   116,   922,   689,  1167,  1168,   689,
    1156,  1059,    20,   544,    34,    35,    36,    37,    38,    39,
     989,   774,   463,  1300,   110,   547,    46,   549,   550,    21,
     552,    88,   554,    60,   792,   793,    30,    66,    86,    68,
     562,   563,     7,    88,    86,    30,    86,    32,    33,    20,
     132,    71,    86,    82,    88,   496,   497,    42,   499,   500,
     501,   502,    99,   453,   454,   944,   507,   825,  1129,   510,
      43,    65,   110,    92,    86,   104,   756,   136,   758,   136,
      65,    66,   523,   103,   104,   105,    99,   116,    88,   118,
     132,   121,   533,   534,   102,   124,    99,    99,   856,    85,
     126,   110,   136,    86,    89,    26,   114,    88,    56,    57,
     120,    20,    53,   134,    88,    20,   206,    99,   258,   158,
      98,   136,    58,    59,   105,   265,   316,    48,   214,   145,
     138,    99,   322,   147,   142,   275,   174,   145,   158,   117,
     127,    99,   179,   164,    25,  1024,   119,  1307,   831,   179,
     164,   190,    88,   243,   595,   142,   105,    99,    99,    99,
      41,   182,   110,   189,   145,     4,   175,   207,   208,     8,
     190,   145,    99,   176,    99,   185,     8,   179,   226,   206,
     262,   175,   222,   309,  1085,   171,  1046,    19,   770,   771,
       8,     9,   177,   918,  1055,  1243,   105,   179,   163,   219,
     245,   246,  1119,   262,   175,   262,  1483,   226,   176,   295,
     202,   224,  1129,    86,   226,   260,   243,   175,   901,   899,
     262,   240,  1283,  1500,   207,   208,  1232,   758,   262,   214,
     250,  1508,   622,   175,   253,   175,   255,  1206,   991,   222,
     149,   249,  1388,   765,   149,   245,   246,   262,   175,   314,
     175,   270,   317,   282,    99,   274,   276,   277,   278,   279,
     280,   120,   282,   283,   284,   285,   286,  1069,   380,   142,
      99,   291,     8,     9,   113,    30,   115,    95,     4,    34,
      99,   113,     8,   115,   123,   314,   676,   403,   317,   401,
     406,   240,   124,    99,   974,   113,   126,   115,    99,    99,
      86,   170,    99,   142,  1062,  1353,   747,  1467,    99,   139,
     142,  1069,   428,   754,    92,   184,    71,   266,   267,   268,
     142,  1424,  1425,   272,   142,   137,   185,   105,   146,   142,
     175,   447,   448,   149,   450,   364,   452,   210,   211,    86,
     456,   370,   154,    98,   162,   457,   175,   376,  1451,    86,
     136,   380,   165,   189,  1457,   471,   175,   386,   142,    95,
     257,   145,   198,     8,   393,   183,  1283,   264,  1416,   175,
     486,   172,   401,   402,    19,   175,   492,   113,   175,   115,
     127,  1242,    87,   201,   175,   132,   827,   113,   145,   115,
    1438,   137,   833,    98,    88,   511,   147,   123,  1404,   136,
     429,   142,   157,   108,   145,   987,   142,   110,   154,   127,
     146,   105,   117,   164,   198,  1217,   142,   999,   990,   948,
       8,     9,   258,   155,   142,   214,   162,   127,   457,   265,
     219,   460,   461,   462,    58,    59,   187,    61,   170,   275,
     469,   170,   142,   472,   834,   835,   142,   183,  1496,   839,
    1498,   892,   893,   482,   895,   184,   897,   822,    20,  1217,
     586,   587,   110,  1364,    88,   201,  1514,   583,   113,   252,
     115,   836,   588,   863,   109,   504,   917,   288,   142,   124,
     263,   145,   110,   512,   158,   296,   110,   928,   929,   930,
     252,   932,   933,   934,   935,   936,   937,   142,   939,   940,
     135,   263,    45,   870,   187,   872,   189,    95,    51,    54,
     951,    54,    55,   148,    88,   198,   190,   189,    92,    62,
     210,   211,   212,   127,   145,   113,   198,   115,   132,   970,
     145,   972,   973,  1216,  1336,   237,   238,     8,     9,   221,
     102,   223,   658,   659,   911,   219,   913,   182,   589,   665,
     110,   592,   114,   594,   142,    88,  1281,   259,   146,    92,
     672,  1286,   127,   675,  1341,   240,   682,   132,   597,  1346,
     599,   180,   181,  1014,   162,  1435,   138,   214,  1336,   216,
     142,   289,   290,   145,   158,   214,   142,   216,   617,   142,
     706,   266,   267,   268,  1035,   183,   221,   272,   223,   118,
     119,   204,   276,   277,   278,   279,   280,   145,   282,   283,
     284,   285,   286,   201,   157,  1417,   732,   160,   214,  1191,
     110,   650,   651,   652,    95,   158,  1198,  1199,  1210,   280,
     281,   174,   142,  1439,    34,    35,    36,   227,  1079,    39,
      58,    59,   113,   672,   115,   231,   675,   231,   118,   119,
    1375,  1092,   226,   769,  1379,  1096,  1097,   200,  1099,  1417,
     807,   808,   145,  1104,   693,   142,   240,   241,   242,   110,
     244,   142,   367,   368,     0,   146,   179,   251,  1222,   253,
     709,   255,   565,   566,   572,   573,   179,   261,   574,   575,
    1080,   162,   156,   226,  1339,  1340,   270,   271,    84,   273,
     274,   248,    68,  1428,   188,    93,   143,   240,   241,   242,
      94,   244,   183,   145,    34,    34,    34,   746,  1159,    20,
     253,   141,   255,   752,   282,   110,   287,   142,   261,  1170,
     201,   142,   287,   292,   142,   175,   175,   270,   271,   142,
     273,   274,  1183,   273,   273,  1186,   110,  1188,   864,  1321,
    1322,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,   110,   142,   792,   793,   794,   795,   145,   145,   145,
     145,   145,    27,  1163,   175,    15,   175,   202,    20,   175,
      25,   110,   220,    99,   157,   220,    86,   159,   159,    86,
      86,   145,    20,    99,    99,   117,   825,   149,   149,   122,
      20,   288,   142,   172,    88,   122,    30,   175,   175,   172,
     172,   172,   172,    88,   172,    86,   175,   132,   175,    99,
     175,   226,   172,   214,  1396,   132,   172,  1268,   175,  1270,
     175,   172,   175,   172,   172,  1276,   110,   179,   110,   249,
     110,   870,   110,   872,   136,   159,   274,   256,   172,  1290,
    1291,  1292,  1293,  1294,   247,  1296,  1297,   122,   275,   132,
     173,    86,    34,    35,    36,    37,    38,    39,   132,  1259,
     267,   275,   216,   172,    46,   288,    92,  1318,   122,   172,
      52,   142,   911,   172,   913,   122,   130,   131,   186,   133,
     149,    63,    64,   122,    88,    67,   140,   110,    70,    71,
     144,   142,   146,   172,   136,  1021,   110,   151,   243,   132,
     172,   142,    27,    20,   110,   172,   142,   110,  1359,    71,
    1361,  1311,  1363,   167,   235,    99,    99,   956,   145,   136,
     959,   103,   104,   105,   145,   136,   172,   175,   967,   136,
     969,   275,    47,   134,   239,   239,    86,   191,   192,   193,
     194,   195,   196,    20,    20,   134,  1072,   294,   216,   226,
     216,   179,   216,   275,   172,   175,   276,    99,   132,   175,
     175,  1087,   175,   136,   110,   110,    61,   149,   122,     6,
     175,   179,   132,   175,   174,    98,   158,  1016,   222,   222,
      98,   226,   222,   175,   175,  1111,   110,   136,    86,    20,
     222,   172,    20,   269,   159,  1446,   174,   246,    88,  1125,
     172,   172,   116,   172,   172,   172,    20,    88,   190,    59,
     185,   159,    86,   276,   110,    99,    86,  1468,   110,   214,
     293,  1472,   174,   254,   110,   254,   185,   209,   185,   214,
    1069,   110,    85,   174,   171,   293,   142,   219,   185,   110,
     293,   110,  1493,   110,   187,   282,   175,   110,   214,   235,
    1089,   238,   521,   241,   276,  1094,   521,   621,   238,  1031,
     826,  1062,   397,  1416,   378,  1438,  1105,  1152,   250,   294,
     294,   369,  1218,   906,   959,   294,  1274,  1094,   242,  1106,
    1160,  1172,   281,   951,  1170,  1167,  1089,  1126,  1070,   482,
     545,   567,   546,   302,   276,   277,   278,   279,   280,   710,
     282,   283,   284,   285,   286,  1119,  1457,  1451,  1147,   291,
     306,  1056,   795,   872,   825,  1147,  1030,  1156,   770,  1157,
     987,  1160,   999,  1210,   470,   771,   991,   470,  1351,  1231,
     988,  1205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1217,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1240,    -1,    -1,    -1,    -1,    -1,  1246,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1271,  1272,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1282,    -1,    -1,    -1,    -1,  1287,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1336,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1360,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1376,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1388,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1412,    -1,    -1,  1415,    -1,  1417,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1431,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1439,    -1,  1441,    -1,    -1,    -1,    -1,    -1,  1447,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1488,
      -1,  1490,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,
      -1,    -1,    -1,    -1,  1503,    -1,    17,    18,  1507,    20,
      -1,    -1,    -1,  1512,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    -1,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -1,    -1,    97,    98,    -1,    -1,
      -1,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,    -1,   114,    -1,   116,   117,   118,   119,    -1,
     121,    -1,    -1,    -1,   125,   126,   127,   128,   129,    -1,
      -1,    -1,    -1,    -1,   135,   136,   137,   138,   139,   140,
     141,    -1,    -1,    -1,   145,   146,   147,   148,   149,    -1,
      -1,    -1,    -1,   154,   155,   156,   157,   158,   159,   160,
     161,   162,    -1,   164,   165,    -1,    -1,   168,   169,   170,
      -1,    -1,    -1,   174,    -1,   176,   177,   178,    -1,   180,
     181,   182,    -1,   184,    -1,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,    -1,    -1,   199,   200,
     201,    -1,   203,   204,    -1,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,    -1,   248,   249,   250,
      -1,   252,   253,   254,   255,   256,   257,    -1,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    -1,    97,    98,    -1,    -1,    -1,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,    -1,   114,    -1,   116,   117,   118,   119,    -1,   121,
      -1,    -1,    -1,   125,   126,   127,   128,   129,    -1,    -1,
      -1,    -1,    -1,   135,   136,   137,   138,   139,   140,   141,
      -1,    -1,    -1,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,   154,   155,   156,   157,   158,   159,   160,   161,
     162,    -1,   164,   165,    -1,    -1,   168,   169,   170,    -1,
      -1,    -1,   174,   175,   176,   177,   178,    -1,   180,   181,
     182,    -1,   184,    -1,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,    -1,    -1,   199,   200,   201,
      -1,   203,   204,    -1,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,    -1,   248,   249,   250,    -1,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    -1,    97,    98,    -1,    -1,    -1,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,    -1,
     114,    -1,   116,   117,   118,   119,    -1,   121,    -1,    -1,
      -1,   125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,
      -1,   135,   136,   137,   138,   139,   140,   141,    -1,    -1,
      -1,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
     154,   155,   156,   157,   158,   159,   160,   161,   162,    -1,
     164,   165,    -1,    -1,   168,   169,   170,    -1,   172,    -1,
     174,    -1,   176,   177,   178,    -1,   180,   181,   182,    -1,
     184,    -1,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,    -1,    -1,   199,   200,   201,    -1,   203,
     204,    -1,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,    -1,   248,   249,   250,    -1,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    -1,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      -1,    97,    98,    -1,    -1,    -1,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,    -1,   114,    -1,
     116,   117,   118,   119,    -1,   121,    -1,    -1,    -1,   125,
     126,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,   135,
     136,   137,   138,   139,   140,   141,    -1,    -1,    -1,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,   164,   165,
      -1,    -1,   168,   169,   170,    -1,    -1,    -1,   174,   175,
     176,   177,   178,    -1,   180,   181,   182,    -1,   184,    -1,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,    -1,    -1,   199,   200,   201,    -1,   203,   204,    -1,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,    -1,   248,   249,   250,    -1,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    -1,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    97,
      98,    -1,    -1,    -1,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    -1,   114,    -1,   116,   117,
     118,   119,    -1,   121,    -1,    -1,    -1,   125,   126,   127,
     128,   129,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,
     138,   139,   140,   141,    -1,    -1,    -1,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,   154,   155,   156,   157,
     158,   159,   160,   161,   162,    -1,   164,   165,    -1,    -1,
     168,   169,   170,    -1,   172,    -1,   174,    -1,   176,   177,
     178,    -1,   180,   181,   182,    -1,   184,    -1,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    -1,
      -1,   199,   200,   201,    -1,   203,   204,    -1,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,    -1,
     248,   249,   250,    -1,   252,   253,   254,   255,   256,   257,
      -1,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    -1,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    -1,    97,    98,    -1,
      -1,    -1,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,    -1,   114,    -1,   116,   117,   118,   119,
      -1,   121,    -1,    -1,    -1,   125,   126,   127,   128,   129,
      -1,    -1,    -1,    -1,    -1,   135,   136,   137,   138,   139,
     140,   141,    -1,    -1,    -1,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,   159,
     160,   161,   162,    -1,   164,   165,    -1,    -1,   168,   169,
     170,    -1,   172,    -1,   174,    -1,   176,   177,   178,    -1,
     180,   181,   182,    -1,   184,    -1,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,    -1,   199,
     200,   201,    -1,   203,   204,    -1,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,    -1,   248,   249,
     250,    -1,   252,   253,   254,   255,   256,   257,    -1,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    -1,    97,    98,    -1,    -1,    -1,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,    -1,   114,    -1,   116,   117,   118,   119,    -1,   121,
      -1,    -1,    -1,   125,   126,   127,   128,   129,    -1,    -1,
      -1,    -1,    -1,   135,   136,   137,   138,   139,   140,   141,
      -1,    -1,    -1,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,   154,   155,   156,   157,   158,   159,   160,   161,
     162,    -1,   164,   165,    -1,    -1,   168,   169,   170,    -1,
     172,    -1,   174,    -1,   176,   177,   178,    -1,   180,   181,
     182,    -1,   184,    -1,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,    -1,    -1,   199,   200,   201,
      -1,   203,   204,    -1,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,    -1,   248,   249,   250,    -1,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    -1,    97,    98,    -1,    -1,    -1,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,    -1,
     114,    -1,   116,   117,   118,   119,    -1,   121,    -1,    -1,
      -1,   125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,
      -1,   135,   136,   137,   138,   139,   140,   141,    -1,    -1,
      -1,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
     154,   155,   156,   157,   158,   159,   160,   161,   162,    -1,
     164,   165,    -1,    -1,   168,   169,   170,    -1,   172,    -1,
     174,    -1,   176,   177,   178,    -1,   180,   181,   182,    -1,
     184,    -1,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,    -1,    -1,   199,   200,   201,    -1,   203,
     204,    -1,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,    -1,   248,   249,   250,    -1,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    -1,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      -1,    97,    98,    -1,    -1,    -1,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,    -1,   114,    -1,
     116,   117,   118,   119,    -1,   121,    -1,    -1,    -1,   125,
     126,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,   135,
     136,   137,   138,   139,   140,   141,    -1,    -1,    -1,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,   164,   165,
      -1,    -1,   168,   169,   170,    -1,   172,    -1,   174,    -1,
     176,   177,   178,    -1,   180,   181,   182,    -1,   184,    -1,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,    -1,    -1,   199,   200,   201,    -1,   203,   204,    -1,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,    -1,   248,   249,   250,    -1,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    -1,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    97,
      98,    -1,    -1,    -1,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    -1,   114,    -1,   116,   117,
     118,   119,    -1,   121,    -1,    -1,    -1,   125,   126,   127,
     128,   129,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,
     138,   139,   140,   141,    -1,    -1,    -1,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,   154,   155,   156,   157,
     158,   159,   160,   161,   162,    -1,   164,   165,    -1,    -1,
     168,   169,   170,    -1,   172,    -1,   174,    -1,   176,   177,
     178,    -1,   180,   181,   182,    -1,   184,    -1,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    -1,
      -1,   199,   200,   201,    -1,   203,   204,    -1,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,    -1,
     248,   249,   250,    -1,   252,   253,   254,   255,   256,   257,
      -1,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    -1,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    -1,    97,    98,    -1,
      -1,    -1,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,    -1,   114,    -1,   116,   117,   118,   119,
      -1,   121,    -1,    -1,    -1,   125,   126,   127,   128,   129,
      -1,    -1,    -1,    -1,    -1,   135,   136,   137,   138,   139,
     140,   141,    -1,    -1,    -1,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,   159,
     160,   161,   162,    -1,   164,   165,    -1,    -1,   168,   169,
     170,    -1,    -1,    -1,   174,    -1,   176,   177,   178,    -1,
     180,   181,   182,    -1,   184,    -1,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,    -1,   199,
     200,   201,    -1,   203,   204,    -1,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,    -1,   248,   249,
     250,    -1,   252,   253,   254,   255,   256,   257,    -1,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    -1,    97,    98,    -1,    -1,    -1,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,    -1,   114,    -1,   116,   117,   118,   119,    -1,   121,
      -1,    -1,    -1,   125,   126,   127,   128,   129,    -1,    -1,
      -1,    -1,    -1,   135,   136,   137,   138,   139,   140,   141,
      -1,    -1,    -1,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,   154,   155,   156,   157,   158,   159,   160,   161,
     162,    -1,   164,   165,    -1,    -1,   168,   169,   170,    -1,
      -1,    -1,   174,    -1,   176,   177,   178,    -1,   180,   181,
     182,    -1,   184,    -1,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,    -1,    -1,   199,   200,   201,
      -1,   203,   204,    -1,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,    -1,   248,   249,   250,    -1,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    -1,    97,    98,    -1,    -1,    -1,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,    -1,
     114,    -1,   116,   117,   118,   119,    -1,   121,    -1,    -1,
      -1,   125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,
      -1,   135,   136,   137,   138,   139,   140,   141,    -1,    -1,
      -1,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
     154,   155,   156,   157,   158,   159,   160,   161,   162,    -1,
     164,   165,    -1,    -1,   168,   169,   170,    -1,    -1,    -1,
     174,    -1,   176,   177,   178,    -1,   180,   181,   182,    -1,
     184,    -1,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,    -1,    -1,   199,   200,   201,    -1,   203,
     204,    -1,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,    -1,   248,   249,   250,    -1,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    -1,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      -1,    97,    98,    -1,    -1,    -1,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,    -1,   114,    -1,
     116,   117,   118,   119,    -1,   121,    -1,    -1,    -1,   125,
     126,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,   135,
     136,   137,   138,   139,   140,   141,    -1,    -1,    -1,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,   164,   165,
      -1,    -1,   168,   169,   170,    -1,    -1,    -1,   174,    -1,
     176,   177,   178,    -1,   180,   181,   182,    -1,   184,    -1,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,    -1,    -1,   199,   200,   201,    -1,   203,   204,    -1,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,    -1,   248,   249,   250,    -1,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    -1,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    -1,    97,
      98,    -1,    -1,    -1,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    -1,   114,    -1,   116,   117,
     118,   119,    -1,   121,    -1,    -1,    -1,   125,   126,   127,
     128,   129,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,
     138,   139,   140,   141,    -1,    -1,    -1,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,   154,   155,   156,   157,
     158,   159,   160,   161,   162,    -1,   164,   165,    -1,    -1,
     168,   169,   170,    -1,    -1,    -1,   174,    -1,   176,   177,
     178,    -1,   180,   181,   182,    -1,   184,    -1,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    -1,
      -1,   199,   200,   201,    -1,   203,   204,    -1,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,    -1,
     248,   249,   250,    -1,   252,   253,   254,   255,   256,   257,
      -1,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,
      20,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    -1,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    -1,    97,    98,    -1,
      -1,    -1,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,    -1,   114,    -1,   116,   117,   118,   119,
      -1,   121,    -1,    -1,    -1,   125,   126,   127,   128,   129,
      -1,    -1,    -1,    -1,    -1,   135,   136,   137,   138,   139,
     140,   141,    -1,    -1,    -1,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,   159,
     160,   161,   162,    -1,   164,   165,    -1,    -1,   168,   169,
     170,    -1,    -1,    -1,   174,    -1,   176,   177,   178,    -1,
     180,   181,   182,    -1,   184,    -1,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,    -1,   199,
     200,   201,    -1,   203,   204,    -1,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,    -1,   248,   249,
     250,    -1,   252,   253,   254,   255,   256,   257,    -1,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    -1,    97,    98,    -1,    -1,    -1,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,    -1,   114,    -1,   116,   117,   118,   119,    -1,   121,
      -1,    -1,    -1,   125,   126,   127,   128,   129,    -1,    -1,
      -1,    -1,    -1,   135,   136,   137,   138,   139,   140,   141,
      -1,    -1,    -1,   145,   146,    -1,   148,   149,    -1,    -1,
      -1,    -1,   154,   155,   156,   157,   158,   159,   160,   161,
     162,    -1,    -1,    -1,    -1,    -1,   168,   169,   170,    -1,
      -1,    -1,   174,    -1,   176,   177,   178,    -1,   180,   181,
     182,    -1,   184,    -1,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,    -1,    -1,   199,   200,   201,
      -1,   203,   204,    -1,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,    -1,   248,   249,   250,    -1,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    -1,    97,    98,    -1,    -1,    -1,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,    -1,
     114,    -1,   116,   117,   118,   119,    -1,   121,    -1,    -1,
      -1,   125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,
      -1,   135,   136,   137,   138,   139,   140,   141,    -1,    -1,
      -1,   145,   146,    -1,   148,   149,    -1,    -1,    -1,    -1,
     154,   155,   156,   157,   158,   159,   160,   161,   162,    -1,
      -1,    -1,    -1,    -1,   168,   169,   170,    -1,    -1,    -1,
     174,    -1,   176,   177,   178,    -1,    -1,    -1,   182,    -1,
     184,    -1,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,    -1,    -1,   199,   200,   201,    -1,   203,
     204,    -1,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,    -1,   248,   249,   250,    -1,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    -1,    -1,    84,    -1,
      86,    87,    88,    89,    -1,    -1,    92,    93,    94,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,   103,   104,   105,
      -1,    -1,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
     116,   117,   118,   119,    -1,   121,    -1,    -1,    -1,   125,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,
     136,   137,    -1,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,    -1,    -1,    -1,    -1,   154,   155,
     156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,   174,    -1,
     176,   177,    -1,    -1,    -1,    -1,   182,    -1,   184,    -1,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,    -1,    -1,   199,   200,    -1,    -1,   203,   204,    -1,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,    -1,   248,   249,   250,    -1,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    -1,    84,    -1,    86,    87,
      88,    89,    -1,    -1,    92,    93,    94,    -1,    -1,    -1,
      98,    -1,    -1,    -1,    -1,   103,   104,   105,    -1,    -1,
     108,   109,    -1,    -1,    -1,    -1,    -1,    -1,   116,   117,
     118,   119,    -1,   121,    -1,    -1,    -1,   125,   126,   127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,
      -1,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,    -1,    -1,    -1,    -1,   154,   155,   156,   157,
     158,   159,   160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   170,    -1,    -1,    -1,   174,    -1,   176,    -1,
      -1,    -1,    -1,    -1,   182,    -1,   184,    -1,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    -1,
      -1,   199,   200,    -1,    -1,   203,   204,    -1,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,    -1,
     248,   249,   250,    -1,   252,   253,   254,   255,   256,   257,
      -1,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
      14,    -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    -1,    -1,
      84,    -1,    86,    87,    88,    89,    -1,    -1,    92,    93,
      94,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,   103,
     104,   105,    -1,    -1,   108,   109,    -1,    -1,    -1,    -1,
      -1,    -1,   116,   117,   118,   119,    -1,   121,    -1,    -1,
      -1,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   135,   136,   137,    -1,   139,   140,   141,   142,    -1,
      -1,   145,    -1,    -1,   148,   149,    -1,    -1,    -1,    -1,
     154,   155,   156,   157,   158,   159,   160,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,
     174,    -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     184,    -1,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,    -1,    -1,   199,   200,    -1,    -1,   203,
     204,    -1,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,    -1,   248,   249,   250,    -1,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,    14,    -1,    -1,    -1,    18,    -1,
      20,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    -1,    -1,    84,    -1,    86,    87,    88,    89,
      -1,    -1,    92,    93,    94,    -1,    -1,    -1,    98,    -1,
      -1,    -1,    -1,   103,   104,   105,    -1,    -1,   108,   109,
      -1,    -1,    -1,    -1,    -1,    -1,   116,   117,   118,   119,
      -1,   121,    -1,    -1,    -1,   125,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   135,   136,   137,    -1,   139,
     140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,
      -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,   159,
     160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     170,    -1,    -1,    -1,   174,   175,   176,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   184,    -1,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,    -1,   199,
     200,    -1,    -1,   203,   204,    -1,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,    -1,   248,   249,
     250,    -1,   252,   253,   254,   255,   256,   257,    -1,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,    14,    -1,
      -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    -1,    -1,    84,    -1,
      86,    87,    88,    89,    -1,    -1,    92,    93,    94,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,   103,   104,   105,
      -1,    -1,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
     116,   117,   118,   119,    -1,   121,    -1,    -1,    -1,   125,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,
     136,   137,    -1,   139,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,   148,   149,    -1,    -1,    -1,    -1,   154,   155,
     156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,   174,    -1,
     176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   184,    -1,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,    -1,    -1,   199,   200,    -1,    -1,   203,   204,    -1,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,    -1,   248,   249,   250,    -1,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,    16,    -1,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    -1,    -1,
      84,    -1,    86,    87,    88,    89,    -1,    -1,    92,    93,
      94,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,   103,
     104,   105,    -1,    -1,   108,   109,    -1,    -1,    -1,    -1,
      -1,    -1,   116,   117,   118,   119,    -1,   121,    -1,    -1,
      -1,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   135,   136,   137,    -1,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,    -1,    -1,    -1,    -1,
     154,   155,   156,   157,   158,   159,   160,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,
     174,    -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     184,    -1,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,    -1,    -1,   199,   200,    -1,    -1,   203,
     204,    -1,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,    -1,   248,   249,   250,    -1,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    -1,    -1,
      84,    -1,    86,    87,    88,    89,    -1,    -1,    92,    93,
      94,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,   103,
     104,   105,    -1,    -1,   108,   109,    -1,    -1,    -1,    -1,
      -1,    -1,   116,   117,   118,   119,    -1,   121,    -1,    -1,
      -1,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   135,   136,   137,    -1,   139,   140,   141,   142,    -1,
      -1,   145,    -1,    -1,   148,   149,    -1,    -1,    -1,    -1,
     154,   155,   156,   157,   158,   159,   160,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,
     174,    -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     184,    -1,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,    -1,    -1,   199,   200,    -1,    -1,   203,
     204,    -1,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,    -1,   248,   249,   250,    -1,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    -1,    -1,
      84,    -1,    86,    87,    88,    89,    -1,    -1,    92,    93,
      94,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,   103,
     104,   105,    -1,    -1,   108,   109,    -1,    -1,    -1,    -1,
      -1,    -1,   116,   117,   118,   119,    -1,   121,    -1,    -1,
      -1,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   135,   136,   137,    -1,   139,   140,   141,   142,    -1,
      -1,   145,    -1,    -1,   148,   149,    -1,    -1,    -1,    -1,
     154,   155,   156,   157,   158,   159,   160,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,
     174,    -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     184,    -1,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,    -1,    -1,   199,   200,    -1,    -1,   203,
     204,    -1,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,    -1,   248,   249,   250,    -1,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    -1,    -1,
      84,    -1,    86,    87,    88,    89,    -1,    -1,    92,    93,
      94,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,   103,
     104,   105,    -1,    -1,   108,   109,    -1,    -1,    -1,    -1,
      -1,    -1,   116,   117,   118,   119,    -1,   121,    -1,    -1,
      -1,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   135,   136,   137,    -1,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,    -1,    -1,    -1,    -1,
     154,   155,   156,   157,   158,   159,   160,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,
     174,   175,   176,    -1,    -1,    -1,    -1,    -1,   182,    -1,
     184,    -1,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,    -1,    -1,   199,   200,    -1,    -1,   203,
     204,    -1,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,    -1,   248,   249,   250,    -1,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    -1,    -1,
      84,    -1,    86,    87,    88,    89,    -1,    -1,    92,    93,
      94,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,   103,
     104,   105,    -1,    -1,   108,   109,    -1,    -1,    -1,    -1,
      -1,    -1,   116,   117,   118,   119,    -1,   121,    -1,    -1,
      -1,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   135,   136,   137,    -1,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,    -1,    -1,    -1,    -1,
     154,   155,   156,   157,   158,   159,   160,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,
     174,   175,   176,    -1,    -1,    -1,    -1,    -1,   182,    -1,
     184,    -1,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,    -1,    -1,   199,   200,    -1,    -1,   203,
     204,    -1,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,    -1,   248,   249,   250,    -1,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    -1,    -1,
      84,    -1,    86,    87,    88,    89,    -1,    -1,    92,    93,
      94,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,   103,
     104,   105,    -1,    -1,   108,   109,   110,    -1,    -1,    -1,
      -1,    -1,   116,   117,   118,   119,    -1,   121,    -1,    -1,
      -1,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   135,   136,   137,    -1,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,    -1,    -1,    -1,    -1,
     154,   155,   156,   157,   158,   159,   160,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,
     174,    -1,   176,   177,    -1,    -1,    -1,    -1,    -1,    -1,
     184,    -1,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,    -1,    -1,   199,   200,    -1,    -1,   203,
     204,    -1,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,    -1,   248,   249,   250,    -1,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    -1,    -1,
      84,    -1,    86,    87,    88,    89,    -1,    -1,    92,    93,
      94,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,   103,
     104,   105,    -1,    -1,   108,   109,    -1,    -1,    -1,    -1,
      -1,    -1,   116,   117,   118,   119,    -1,   121,    -1,    -1,
      -1,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   135,   136,   137,    -1,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,    -1,    -1,    -1,    -1,
     154,   155,   156,   157,   158,   159,   160,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,
     174,    -1,   176,   177,    -1,    -1,    -1,    -1,    -1,    -1,
     184,    -1,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,    -1,    -1,   199,   200,    -1,    -1,   203,
     204,    -1,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,    -1,   248,   249,   250,    -1,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    -1,    -1,
      84,    -1,    86,    87,    88,    89,    -1,    -1,    92,    93,
      94,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,   103,
     104,   105,    -1,    -1,   108,   109,    -1,    -1,    -1,    -1,
      -1,    -1,   116,   117,   118,   119,    -1,   121,    -1,    -1,
      -1,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   135,   136,   137,    -1,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,    -1,    -1,    -1,    -1,
     154,   155,   156,   157,   158,   159,   160,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,
     174,    -1,   176,   177,    -1,    -1,    -1,    -1,    -1,    -1,
     184,    -1,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,    -1,    -1,   199,   200,    -1,    -1,   203,
     204,    -1,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,    -1,   248,   249,   250,    -1,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    -1,    -1,
      84,    -1,    86,    87,    88,    89,    -1,    -1,    92,    93,
      94,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,   103,
     104,   105,    -1,    -1,   108,   109,    -1,    -1,    -1,    -1,
      -1,    -1,   116,   117,   118,   119,    -1,   121,    -1,    -1,
      -1,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   135,   136,   137,    -1,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,    -1,    -1,    -1,    -1,
     154,   155,   156,   157,   158,   159,   160,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,
     174,    -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     184,    -1,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,    -1,    -1,   199,   200,    -1,    -1,   203,
     204,    -1,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,    -1,   248,   249,   250,    -1,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,    10,    17,    18,    20,    25,    26,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    97,    98,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   114,   116,   117,   118,   119,
     121,   125,   126,   127,   128,   129,   135,   136,   137,   138,
     139,   140,   141,   145,   146,   147,   148,   149,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   164,   165,   168,
     169,   170,   174,   176,   177,   178,   180,   181,   182,   184,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   199,   200,   201,   203,   204,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   248,   249,   250,
     252,   253,   254,   255,   256,   257,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   344,   345,   350,   353,   356,   359,   360,   362,   367,
     368,   369,   370,   371,   380,   381,   383,   384,   385,   390,
     392,   394,   395,   396,   401,   422,   425,   428,   429,   430,
     431,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   478,   479,   480,   494,   495,   497,   498,   499,   500,
     501,   502,   503,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   522,   523,   524,   525,   526,   527,   528,
     531,   537,   538,   539,    34,    35,    36,    37,    38,    39,
      46,    52,    63,    64,    67,    70,    71,   103,   104,   105,
     149,   158,   190,   209,   219,   250,   276,   277,   278,   279,
     280,   282,   283,   284,   285,   286,   291,   351,   352,   372,
     373,   149,    86,   142,   210,   211,   145,    25,    26,    28,
      29,    30,    31,    32,    33,    40,    41,    42,    44,    50,
      51,    53,    54,    55,    65,    66,    89,   125,   142,   145,
     158,   190,   203,   213,   214,   215,   217,   218,   225,   228,
     229,   230,   232,   233,   234,   236,   537,   142,   142,   145,
     142,   145,   145,    26,    48,    14,   142,   145,   536,   537,
     110,   110,   110,   142,    56,    57,   110,   387,    54,   145,
     145,   142,   145,   537,    30,    32,    33,    42,    89,   462,
     537,   537,   110,   175,   381,   537,   142,   536,    16,   537,
     537,   454,   142,    21,   202,   204,   214,   216,   145,   214,
     216,   214,   214,   219,   110,   142,   363,   227,   231,   231,
     145,   142,   110,   315,     0,   317,   318,    25,    41,   320,
     380,   179,   179,    99,   179,   382,    45,    51,    54,    55,
      62,   157,   160,   174,   200,   386,   391,   392,   393,   410,
     411,   415,   397,   398,   537,   156,    84,   122,   130,   131,
     133,   140,   144,   146,   151,   167,   191,   192,   193,   194,
     195,   196,   446,   447,   248,   147,   164,   187,   109,   135,
     148,   182,   189,   198,   126,   139,    68,   188,    93,    94,
     147,   164,   445,   142,   451,   454,   180,   181,   143,   466,
     467,   462,   466,   462,   466,   145,   537,    34,   374,    34,
     375,   372,   372,   373,   537,   170,   184,   158,   190,    20,
     535,   155,   170,   170,   184,   537,   141,   110,   349,    30,
      34,    71,    98,   157,   536,   210,   211,   212,   289,   290,
      92,   226,   240,   253,   255,   270,   274,   551,   552,   553,
     554,   555,   558,   563,   564,   537,   282,   537,   287,   287,
     292,   276,   284,   352,   536,   520,   537,   381,   142,   142,
     381,   381,   175,   182,   537,   142,   381,   381,   175,   381,
     175,   381,   149,   535,   105,   149,   343,   535,   381,    20,
     175,   536,   142,   423,   424,   537,   537,   402,   404,   537,
     384,   273,   273,   110,   405,   110,   537,    30,    65,   175,
     518,   519,   381,   175,   182,   537,   142,   423,   175,    27,
     482,   483,   484,   381,     7,   163,    15,   175,   381,   202,
      20,   384,   384,   175,   384,   384,   384,   384,   220,   529,
     530,   537,   364,   384,   384,   381,   403,   409,   537,   322,
     323,    25,   324,   384,   383,   157,   110,   159,   159,   384,
     384,    99,    86,    88,   136,   262,   399,   400,   505,   430,
     431,   433,   433,   433,   433,   432,   433,   433,   433,   142,
     145,   249,   469,   540,   542,   543,   544,   545,   546,   547,
     548,   436,   436,   435,   437,   437,   437,   437,   438,   438,
     439,   439,   220,    86,    86,    86,   172,   381,   454,   454,
     381,   467,   175,   384,   477,   145,   361,   537,   537,    20,
      99,    99,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,   326,   327,   328,    86,   127,   132,   346,   347,
     348,   537,   127,   132,   149,   149,   326,   535,   117,   122,
     252,   263,   105,   240,   266,   267,   268,   272,   252,   263,
      20,   240,   266,   267,   268,   272,    86,   226,   355,   288,
     537,   537,   537,   122,   142,   172,   381,   381,   175,   172,
      99,   175,    99,   175,   172,   381,   172,   172,   172,   175,
     536,    88,    30,   536,   535,    88,   172,   175,   175,   172,
     381,    99,   176,   136,   505,   132,    99,   132,   400,   505,
     172,   537,    60,   206,   243,   388,   389,   175,   175,   175,
     172,    99,   175,    99,   175,   172,   381,   176,   537,   483,
     484,   120,   185,   172,   172,   121,   179,    86,   207,   208,
     222,    86,   207,   208,   222,    86,   226,   214,    99,   224,
     132,    25,   365,   381,   175,   172,    53,    99,   179,   105,
     179,   159,   537,   384,   416,   417,   110,   412,   413,   110,
     141,   199,   506,   508,   509,   510,   537,   110,   384,   110,
     136,   400,   136,   136,   399,   400,   433,   381,   540,   546,
     274,   574,    88,   158,   241,   242,   244,   251,   261,   271,
     273,   541,   549,   550,   551,   565,   568,   569,   571,   247,
     249,   256,   570,   237,   238,   259,   566,   506,   506,   504,
     509,   504,   172,   173,    99,   175,   110,   175,   376,   377,
     127,   142,   379,   361,   361,   137,   154,   137,   154,   327,
     122,   508,   348,   384,   505,   132,   384,   535,   535,   118,
     119,   535,   267,   275,    88,   105,   145,   557,   275,    32,
      33,    42,    66,    89,   214,   354,   510,   280,   281,   216,
     288,   296,    86,   355,   288,   535,   381,   172,   172,    92,
     426,   427,   142,   520,   521,   537,   520,   521,   172,   186,
     122,   342,   535,   149,   122,    88,   342,   142,   172,   110,
     384,   384,   136,   384,   110,   384,   132,   132,   400,   136,
     505,   243,    58,    59,    61,   110,   399,   406,   407,   408,
     389,   142,   520,   520,   172,   384,    27,   484,   120,   185,
       8,     9,    95,   113,   115,   142,   183,   378,   479,   481,
     492,   493,   496,    20,   221,   223,   384,   384,   384,   221,
     223,   384,   384,   384,   384,   384,   384,   110,   384,   384,
     349,   366,    99,   179,   172,   363,   235,   532,   533,   142,
     110,   416,    87,    98,   108,   117,   418,   419,   420,   421,
      99,   537,    99,   398,   145,   145,   134,   164,   182,   507,
     537,   537,   384,   136,   384,   384,   136,   400,   136,   172,
     175,   239,   206,   243,   257,   264,   573,    88,   245,   246,
     567,   239,   543,   573,   434,   437,   271,   549,   551,   544,
     136,   567,   275,    47,   134,   384,   537,    86,    99,   175,
     381,   127,   142,   127,   363,   522,   347,   384,   275,    88,
     145,   560,    20,   105,   557,   355,   507,   216,   216,   452,
     276,   294,   354,   216,   179,   172,   110,   506,   105,   427,
     172,   381,   175,   175,   134,   175,   175,   384,   535,    99,
     342,   172,   381,   424,   384,   404,   384,   384,   132,   384,
     136,   110,   110,   384,   537,   408,    61,   172,   381,   175,
     175,   122,   183,   481,     6,   381,   537,   183,   492,   179,
     222,   222,   222,   222,   226,   530,   174,   132,   366,   463,
     534,   533,   384,   409,   535,   118,   119,   420,   421,   421,
     417,    98,   414,   413,   175,   175,   384,   384,   136,   384,
     437,    43,   119,   437,   437,   258,   265,   275,   572,   572,
     434,   545,   269,   505,   506,   377,    86,   172,   383,   126,
     189,   559,   562,    20,    20,   561,   559,   260,   567,    99,
     175,    99,   175,   159,   537,   246,   355,   452,   537,   174,
     110,   174,   172,   116,    88,   535,   172,   384,   384,   537,
     537,   407,   384,   172,   484,   537,   183,   172,   484,   537,
     384,   384,   384,   384,   384,   384,   384,   145,   198,   379,
     172,   421,   535,   384,   437,   437,   187,   506,   172,   560,
     560,   562,    20,   175,    20,   254,   556,   557,   556,   357,
     358,   452,   110,   214,   295,   276,   159,    86,   384,   537,
     384,   384,   342,    59,    85,   171,   485,   484,   537,   185,
     484,   110,   463,   437,   567,    99,   175,   175,    99,    86,
     537,   110,   214,   537,   357,   506,   174,   110,     4,   123,
     488,   489,   491,   493,    19,   124,   486,   487,   490,   493,
     185,   484,   185,   537,   254,   557,   358,   509,   293,   537,
     110,   214,   174,   384,   537,    85,   123,   491,   171,   124,
     490,   185,    99,   175,   421,   384,   293,   537,   110,   384,
     110,   379,   282,   293,   537,   537,   294,   384,   294,    99,
     175,   452,   452,   110,   379,   187,   537,   276,   175,   537,
     379,   214,   110,   537,   294,   452
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
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   313,   314,   314,   315,   315,   315,   315,   316,   316,
     317,   317,   318,   318,   319,   320,   320,   320,   321,   321,
     322,   322,   323,   323,   323,   323,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   325,   325,   326,   326,   327,
     328,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     329,   329,   329,   329,   329,   329,   329,   329,   330,   330,
     331,   332,   332,   333,   333,   334,   335,   336,   336,   337,
     337,   338,   338,   338,   338,   339,   340,   341,   341,   341,
     341,   342,   342,   343,   343,   344,   344,   344,   344,   345,
     346,   346,   347,   347,   347,   348,   349,   349,   350,   350,
     350,   351,   351,   352,   352,   352,   352,   352,   352,   352,
     352,   352,   352,   352,   352,   353,   353,   353,   353,   353,
     353,   353,   353,   354,   354,   355,   355,   356,   356,   357,
     357,   358,   358,   359,   359,   359,   359,   360,   360,   361,
     361,   361,   361,   362,   363,   364,   364,   365,   365,   366,
     366,   367,   368,   369,   370,   370,   371,   371,   371,   372,
     372,   372,   372,   373,   373,   374,   374,   375,   375,   376,
     376,   377,   377,   378,   379,   380,   381,   381,   382,   382,
     383,   383,   384,   384,   384,   384,   384,   384,   384,   384,
     384,   384,   384,   384,   384,   384,   384,   384,   384,   385,
     386,   387,   387,   388,   388,   388,   389,   389,   390,   390,
     391,   392,   392,   392,   393,   393,   393,   393,   393,   394,
     394,   395,   395,   396,   397,   397,   398,   398,   398,   398,
     398,   398,   398,   398,   399,   400,   401,   402,   402,   403,
     403,   404,   404,   404,   404,   405,   405,   406,   406,   406,
     407,   407,   407,   408,   408,   408,   409,   410,   411,   412,
     412,   413,   413,   414,   415,   415,   416,   416,   417,   417,
     418,   418,   418,   418,   418,   418,   418,   419,   419,   420,
     420,   421,   422,   422,   423,   423,   424,   424,   425,   425,
     426,   426,   427,   427,   428,   429,   429,   430,   430,   431,
     431,   431,   431,   431,   432,   431,   431,   431,   431,   433,
     433,   433,   434,   434,   435,   435,   435,   436,   436,   436,
     436,   436,   437,   437,   437,   438,   438,   438,   439,   439,
     440,   440,   441,   441,   442,   442,   443,   443,   444,   444,
     444,   444,   445,   445,   445,   446,   446,   446,   446,   446,
     446,   447,   447,   447,   448,   448,   448,   448,   449,   449,
     450,   450,   451,   451,   452,   452,   452,   452,   453,   454,
     454,   454,   455,   455,   456,   456,   456,   456,   457,   457,
     458,   458,   458,   458,   458,   458,   458,   459,   459,   460,
     460,   461,   461,   461,   461,   461,   462,   462,   463,   463,
     464,   464,   464,   465,   465,   466,   466,   467,   468,   468,
     468,   468,   468,   468,   468,   468,   469,   469,   470,   470,
     470,   471,   472,   472,   473,   474,   475,   476,   476,   477,
     477,   478,   478,   479,   479,   479,   480,   480,   480,   480,
     480,   480,   481,   481,   482,   482,   483,   484,   484,   485,
     485,   486,   486,   487,   487,   487,   487,   488,   488,   489,
     489,   489,   489,   490,   490,   491,   491,   492,   492,   492,
     492,   493,   493,   493,   493,   494,   494,   495,   495,   496,
     497,   497,   497,   497,   497,   497,   498,   499,   499,   499,
     499,   500,   500,   500,   500,   501,   502,   503,   503,   503,
     503,   504,   504,   505,   506,   506,   506,   507,   507,   507,
     508,   508,   508,   509,   510,   510,   510,   510,   510,   510,
     510,   510,   510,   511,   512,   512,   512,   513,   514,   515,
     515,   515,   516,   516,   516,   516,   516,   517,   518,   518,
     518,   518,   518,   518,   518,   519,   520,   521,   522,   523,
     523,   523,   524,   524,   524,   524,   524,   524,   524,   524,
     524,   524,   525,   525,   526,   526,   527,   528,   529,   529,
     530,   531,   532,   532,   533,   533,   533,   533,   534,   534,
     535,   536,   536,   537,   537,   538,   538,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   539,   539,   539,   539,   540,   540,   540,
     540,   541,   541,   541,   541,   542,   542,   543,   543,   544,
     544,   545,   545,   546,   546,   546,   547,   547,   548,   548,
     549,   549,   549,   549,   549,   550,   551,   551,   551,   551,
     551,   551,   551,   552,   552,   552,   552,   553,   553,   553,
     553,   554,   554,   555,   555,   555,   555,   555,   555,   555,
     556,   556,   557,   557,   557,   557,   558,   558,   558,   558,
     558,   559,   559,   560,   560,   561,   561,   562,   562,   563,
     564,   564,   565,   565,   565,   566,   566,   566,   566,   566,
     567,   567,   567,   567,   568,   569,   570,   571,   571,   572,
     572,   572,   573,   573,   574
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  xquery_parser::yyr2_[] =
  {
         0,     2,     1,     2,     1,     2,     1,     2,     4,     6,
       2,     1,     1,     2,     6,     2,     2,     4,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     3,     3,     5,     5,     4,     3,     3,     3,     5,
       5,     5,     5,     5,     5,     4,     3,     3,     4,     5,
       6,     1,     3,     3,     3,     3,     6,     5,     8,     4,
       3,     1,     1,     1,     2,     2,     2,     3,     5,     4,
       6,     1,     2,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     2,     2,     2,     3,     4,     5,     6,     4,
       5,     6,     7,     1,     2,     3,     3,     8,     9,     1,
       3,     3,     4,    11,    14,    13,    22,     3,     3,     2,
       3,     4,     5,     2,     4,     3,     0,     3,     2,     1,
       3,     5,     3,     5,     2,     2,     2,     3,     3,     1,
       2,     2,     2,     4,     4,     6,     4,     4,     4,     1,
       3,     2,     3,     3,     3,     1,     1,     2,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     1,     1,     2,     4,     3,     5,     4,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     3,     2,     1,     4,     3,     4,     4,     5,
       4,     5,     5,     6,     3,     3,     3,     1,     4,     1,
       4,     3,     4,     4,     5,     4,     5,     1,     2,     3,
       1,     2,     1,     6,     3,     3,     1,     2,     3,     1,
       3,     2,     3,     2,     3,     4,     1,     3,     1,     2,
       1,     1,     1,     2,     2,     2,     3,     1,     1,     2,
       2,     2,     5,     5,     1,     4,     3,     4,     8,    10,
       1,     2,     4,     7,     8,     1,     3,     1,     3,     1,
       3,     3,     3,     3,     0,     4,     3,     3,     3,     1,
       3,     4,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     4,
       1,     4,     1,     4,     1,     4,     1,     2,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     5,     5,     6,     3,     4,
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
       3,     5,     1,     2,     3,     7,    10,    13,     1,     3,
       1,     1,     1,     1,     1,     7,     4,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
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
  "\"'NCName_sval'\"", "\"'pragma literal'\"", "\"'QName #)'\"",
  "\"'*:QName'\"", "\"'QName_sval'\"", "\"'quote attribute content'\"",
  "\"'STRING'\"", "\"'XML comment'\"", "\"'URI'\"", "\"'NCName'\"",
  "\"'KEYWORD'\"", "\"'declare'\"", "\"'module'\"", "\"<blank>\"",
  "\"'validate'\"", "\"'typeswitch'\"", "\"'element'\"", "\"'document'\"",
  "\"'text'\"", "\"'comment'\"", "\"'function'\"", "\"'updating'\"",
  "\"'sequential'\"", "\"'deterministic'\"", "\"'nondeterministic'\"",
  "\"'simple'\"", "\"'if'\"", "\"'import'\"",
  "\"'processing-instruction'\"", "\"'most'\"", "\"'some'\"",
  "\"'stable'\"", "\"'option'\"", "\"'word'\"", "\"'schema'\"",
  "\"'space'\"", "\"'set'\"", "\"'let'\"", "\"'construction'\"",
  "\"'eval'\"", "\"'for'\"", "\"'outer'\"", "\"'sliding'\"",
  "\"'tumbling'\"", "\"'previous'\"", "\"'next'\"", "\"'only'\"",
  "\"'when'\"", "\"'count'\"", "\"'ordering'\"", "\"'base-uri'\"",
  "\"'schema-element'\"", "\"'document-node'\"", "\"'copy-namespaces'\"",
  "\"'instance'\"", "\"'schema-attribute'\"", "\"'boundary-space'\"",
  "\"'decimal-format'\"", "\"'decimal-separator'\"",
  "\"'grouping-separator'\"", "\"'infinity'\"", "\"'minus-sign'\"",
  "\"'NaN'\"", "\"'percent'\"", "\"'per-mille'\"", "\"'zero-digit'\"",
  "\"'digit'\"", "\"'pattern-separator'\"", "\"'ancestor::'\"",
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
  "\"'?""?'\"", "\"'<no inherit>'\"", "\"'<no preserve>'\"", "\"'or'\"",
  "\"'order'\"", "\"'ordered'\"", "\"'by'\"", "\"'group'\"",
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
  "\"'copy'\"", "\"'with'\"", "\"'returning'\"", "\"'block'\"",
  "\"'exit'\"", "\"'break'\"", "\"'loop'\"", "\"'continue'\"",
  "\"'while'\"", "\"'try'\"", "\"'catch'\"", "\"'using'\"", "\"'all'\"",
  "\"'any'\"", "\"'content'\"", "\"'diacritics'\"", "\"'different'\"",
  "\"'distance'\"", "\"'end'\"", "\"'entire'\"", "\"'exactly'\"",
  "\"'from'\"", "\"'ftand'\"", "\"'ftcontains'\"", "\"'not'\"",
  "\"'ft-option'\"", "\"'ftor'\"", "\"'insensitive'\"", "\"'language'\"",
  "\"'levels'\"", "\"'lowercase'\"", "\"'occurs'\"", "\"'paragraph'\"",
  "\"'paragraphs'\"", "\"'phrase'\"", "\"'relationship'\"", "\"'same'\"",
  "\"'score'\"", "\"'sensitive'\"", "\"'sentence'\"", "\"'sentences'\"",
  "\"'stemming'\"", "\"'stop'\"", "\"'thesaurus'\"", "\"'times'\"",
  "\"'uppercase'\"", "\"'weight'\"", "\"'wildcards'\"", "\"'window'\"",
  "\"'without'\"", "\"'words'\"", "\"'collection'\"", "\"'const'\"",
  "\"'append-only'\"", "\"'queue'\"", "\"'mutable'\"", "\"'read-only'\"",
  "\"'unique'\"", "\"'non'\"", "\"'index'\"", "\"'manually'\"",
  "\"'automatically'\"", "\"'maintained'\"", "\"'on'\"", "\"'range'\"",
  "\"'equality'\"", "\"'integrity'\"", "\"'constraint'\"", "\"'check'\"",
  "\"'key'\"", "\"'foreach'\"", "\"'foreign'\"", "\"'keys'\"",
  "\"'BOM_UTF8'\"", "FTCONTAINS_REDUCE", "RANGE_REDUCE", "ADDITIVE_REDUCE",
  "MULTIPLICATIVE_REDUCE", "UNION_REDUCE", "INTERSECT_EXCEPT_REDUCE",
  "QVARINDECLLIST_REDUCE", "COMMA_DOLLAR", "UNARY_PREC",
  "SEQUENCE_TYPE_REDUCE", "OCCURS_STAR", "OCCURS_PLUS", "OCCURS_HOOK",
  "STEP_REDUCE", "$accept", "Module", "ModuleWithoutBOM", "VersionDecl",
  "MainModule", "LibraryModule", "ModuleDecl", "Prolog", "SIND_DeclList",
  "VFO_DeclList", "SIND_Decl", "VFO_Decl", "DecimalFormatDecl",
  "DecimalFormatParamList", "DecimalFormatParam", "DecimalFormatParamName",
  "Setter", "Import", "NamespaceDecl", "BoundarySpaceDecl",
  "DefaultNamespaceDecl", "OptionDecl", "FTOptionDecl", "OrderingModeDecl",
  "EmptyOrderDecl", "CopyNamespacesDecl", "DefaultCollationDecl",
  "BaseURIDecl", "SchemaImport", "URILiteralList", "SchemaPrefix",
  "ModuleImport", "CtxItemDecl", "CtxItemDecl2", "CtxItemDecl3",
  "CtxItemDecl4", "VarNameAndType", "VarDecl", "DeclPropertyList",
  "DeclProperty", "CollectionDecl", "CollectionTypeDecl", "NodeModifier",
  "IndexDecl", "IndexKeyList", "IndexKeySpec", "IntegrityConstraintDecl",
  "ConstructionDecl", "FunctionSig", "BlockExpr", "Block", "BlockDecls",
  "BlockVarDeclList", "BlockVarDecl", "AssignExpr", "ExitExpr",
  "WhileExpr", "FlowCtlStatement", "FunctionDecl", "FunctionDecl2",
  "FunctionDecl3", "FunctionDeclUpdating", "FunctionDecl4", "ParamList",
  "Param", "EnclosedExpr", "BracedExpr", "QueryBody", "Expr", "ApplyExpr",
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
  "AndExpr", "ComparisonExpr", "$@1", "FTContainsExpr", "RangeExpr",
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
  "VarNameDecl", "TryExpr", "CatchListExpr", "CatchExpr", "NameTestList",
  "URI_LITERAL", "NCNAME", "QNAME", "EvalExpr", "KEYWORD", "FTSelection",
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
       314,     0,    -1,   315,    -1,   298,   315,    -1,   317,    -1,
     316,   317,    -1,   318,    -1,   316,   318,    -1,   203,   204,
      20,   179,    -1,   203,   204,    20,   121,    20,   179,    -1,
     320,   380,    -1,   380,    -1,   319,    -1,   319,   320,    -1,
      26,   149,   536,   122,   535,   179,    -1,   321,   179,    -1,
     322,   179,    -1,   321,   179,   322,   179,    -1,   323,    -1,
     321,   179,   323,    -1,   324,    -1,   322,   179,   324,    -1,
     329,    -1,   330,    -1,   331,    -1,   333,    -1,   350,    -1,
     345,    -1,   371,    -1,   334,    -1,   335,    -1,   353,    -1,
     356,    -1,   359,    -1,   325,    -1,    25,   105,    71,   326,
      -1,    25,    71,   537,   326,    -1,   327,    -1,   326,   327,
      -1,   328,   122,   522,    -1,    72,    -1,    73,    -1,    74,
      -1,    75,    -1,    76,    -1,    77,    -1,    78,    -1,    79,
      -1,    80,    -1,    81,    -1,   332,    -1,   339,    -1,   340,
      -1,   360,    -1,   336,    -1,   337,    -1,   338,    -1,   523,
      -1,   341,    -1,   344,    -1,    25,   149,   536,   122,   535,
      -1,    25,    70,   170,    -1,    25,    70,   184,    -1,    25,
     105,    30,   149,   535,    -1,    25,   105,    34,   149,   535,
      -1,    25,    46,   537,    20,    -1,    25,   250,   551,    -1,
      25,    63,   158,    -1,    25,    63,   190,    -1,    25,   105,
     157,   117,   118,    -1,    25,   105,   157,   117,   119,    -1,
      25,    67,   170,    99,   137,    -1,    25,    67,   170,    99,
     154,    -1,    25,    67,   155,    99,   137,    -1,    25,    67,
     155,    99,   154,    -1,    25,   105,    98,   535,    -1,    25,
      64,   535,    -1,    41,    48,   535,    -1,    41,    48,   343,
     535,    -1,    41,    48,   535,    88,   342,    -1,    41,    48,
     343,   535,    88,   342,    -1,   535,    -1,   342,    99,   535,
      -1,   149,   536,   122,    -1,   105,    30,   149,    -1,    41,
      26,   535,    -1,    41,    26,   149,   536,   122,   535,    -1,
      41,    26,   535,    88,   342,    -1,    41,    26,   149,   536,
     122,   535,    88,   342,    -1,    25,   103,   141,   346,    -1,
      86,   508,   347,    -1,   347,    -1,   348,    -1,   127,    -1,
     127,   348,    -1,   132,   384,    -1,   110,   537,    -1,   110,
     537,   505,    -1,    25,   104,   349,   132,   384,    -1,    25,
     104,   349,   127,    -1,    25,   104,   349,   127,   132,   384,
      -1,   352,    -1,   351,   352,    -1,   277,    -1,   278,    -1,
     279,    -1,   280,    -1,   158,    -1,   190,    -1,   219,   290,
      -1,   219,   289,    -1,   282,    -1,   283,   282,    -1,   286,
     287,    -1,   285,   287,    -1,    25,   276,   537,    -1,    25,
     276,   537,   355,    -1,    25,   276,   537,    86,   354,    -1,
      25,   276,   537,    86,   354,   355,    -1,    25,   351,   276,
     537,    -1,    25,   351,   276,   537,   355,    -1,    25,   351,
     276,   537,    86,   354,    -1,    25,   351,   276,   537,    86,
     354,   355,    -1,   510,    -1,   510,   507,    -1,   226,   281,
     216,    -1,   226,   280,   216,    -1,    25,   284,   537,   288,
     216,   452,   159,   357,    -1,    25,   351,   284,   537,   288,
     216,   452,   159,   357,    -1,   358,    -1,   357,    99,   358,
      -1,   452,    86,   509,    -1,   452,    86,   509,   421,    -1,
      25,   291,   292,   537,   288,   276,   537,   110,   537,   293,
     384,    -1,    25,   291,   292,   537,   288,   276,   537,   214,
     110,   537,   293,   282,   294,   452,    -1,    25,   291,   292,
     537,   288,   276,   537,   295,   214,   110,   537,   293,   384,
      -1,    25,   291,   292,   537,   296,   294,   246,   276,   537,
     214,   110,   537,   294,   452,   187,   276,   537,   214,   110,
     537,   294,   452,    -1,    25,    52,   170,    -1,    25,    52,
     184,    -1,   145,   175,    -1,   145,   376,   175,    -1,   145,
     175,    86,   506,    -1,   145,   376,   175,    86,   506,    -1,
     228,   363,    -1,   142,   364,   381,   172,    -1,   364,   365,
     179,    -1,    -1,   365,    99,   366,    -1,    25,   366,    -1,
     349,    -1,   349,   132,   384,    -1,    50,   110,   537,   132,
     384,    -1,   229,   227,   384,    -1,   233,   145,   384,   175,
     363,    -1,   230,   231,    -1,   232,   231,    -1,    25,   372,
      -1,    25,    38,   372,    -1,    25,    37,   372,    -1,   373,
      -1,    39,   373,    -1,    35,   374,    -1,    36,   375,    -1,
      34,   537,   361,   379,    -1,    34,   537,   361,   127,    -1,
      34,   537,   361,   142,   383,   172,    -1,    34,   537,   361,
     127,    -1,    34,   537,   361,   363,    -1,    34,   537,   361,
     127,    -1,   377,    -1,   376,    99,   377,    -1,   110,   537,
      -1,   110,   537,   505,    -1,   142,   381,   172,    -1,   142,
     381,   172,    -1,   381,    -1,   383,    -1,   383,   382,    -1,
     179,    -1,   382,   383,   179,    -1,   384,    -1,   383,    99,
     384,    -1,   385,    -1,   422,    -1,   425,    -1,   428,    -1,
     429,    -1,   524,    -1,   525,    -1,   527,    -1,   526,    -1,
     528,    -1,   531,    -1,   538,    -1,   368,    -1,   369,    -1,
     370,    -1,   367,    -1,   362,    -1,   394,   386,    -1,   174,
     384,    -1,    56,   273,    -1,    57,   273,    -1,   206,    -1,
     243,    -1,    60,   243,    -1,   388,   406,    61,   384,    -1,
     388,    61,   384,    -1,    54,   387,   405,   389,   389,    -1,
      54,   387,   405,   389,    -1,    62,   110,   537,    -1,   396,
      -1,   401,    -1,   390,    -1,   392,    -1,   410,    -1,   415,
      -1,   411,    -1,   391,    -1,   392,    -1,   394,   393,    -1,
      54,   110,    -1,    55,    54,   110,    -1,   395,   397,    -1,
     398,    -1,   397,    99,   110,   398,    -1,   537,   136,   384,
      -1,   537,   505,   136,   384,    -1,   537,   399,   136,   384,
      -1,   537,   505,   399,   136,   384,    -1,   537,   400,   136,
     384,    -1,   537,   505,   400,   136,   384,    -1,   537,   399,
     400,   136,   384,    -1,   537,   505,   399,   400,   136,   384,
      -1,    88,   110,   537,    -1,   262,   110,   537,    -1,    51,
     110,   402,    -1,   404,    -1,   402,    99,   110,   404,    -1,
     409,    -1,   403,    99,   110,   409,    -1,   537,   132,   384,
      -1,   537,   505,   132,   384,    -1,   537,   400,   132,   384,
      -1,   537,   505,   400,   132,   384,    -1,   110,   537,   136,
     384,    -1,   110,   537,   505,   136,   384,    -1,   407,    -1,
     110,   537,    -1,   110,   537,   407,    -1,   399,    -1,   399,
     408,    -1,   408,    -1,    58,   110,   537,    59,   110,   537,
      -1,    59,   110,   537,    -1,    58,   110,   537,    -1,   537,
      -1,   200,   384,    -1,   160,   159,   412,    -1,   413,    -1,
     412,    99,   413,    -1,   110,   537,    -1,   110,   537,   414,
      -1,    98,   535,    -1,   157,   159,   416,    -1,    45,   157,
     159,   416,    -1,   417,    -1,   416,    99,   417,    -1,   384,
      -1,   384,   418,    -1,   419,    -1,   420,    -1,   421,    -1,
     419,   420,    -1,   419,   421,    -1,   420,   421,    -1,   419,
     420,   421,    -1,    87,    -1,   108,    -1,   117,   118,    -1,
     117,   119,    -1,    98,   535,    -1,    44,   110,   423,   176,
     384,    -1,   125,   110,   423,   176,   384,    -1,   424,    -1,
     423,    99,   110,   424,    -1,   537,   136,   384,    -1,   537,
     505,   136,   384,    -1,    29,   145,   381,   175,   426,   105,
     174,   384,    -1,    29,   145,   381,   175,   426,   105,   110,
     537,   174,   384,    -1,   427,    -1,   426,   427,    -1,    92,
     506,   174,   384,    -1,    92,   110,   537,    86,   506,   174,
     384,    -1,    40,   145,   381,   175,   186,   384,   116,   384,
      -1,   430,    -1,   429,   156,   430,    -1,   431,    -1,   430,
      84,   431,    -1,   433,    -1,   433,   446,   433,    -1,   433,
     447,   433,    -1,   433,   122,   433,    -1,   433,   151,   433,
      -1,    -1,   433,   146,   432,   433,    -1,   433,   144,   433,
      -1,   433,   133,   433,    -1,   433,   131,   433,    -1,   434,
      -1,   434,   248,   540,    -1,   434,   248,   540,   574,    -1,
     435,    -1,   435,   187,   435,    -1,   436,    -1,   435,   164,
     436,    -1,   435,   147,   436,    -1,   437,    -1,   436,   182,
     437,    -1,   436,   109,   437,    -1,   436,   135,   437,    -1,
     436,   148,   437,    -1,   438,    -1,   437,   189,   438,    -1,
     437,   198,   438,    -1,   439,    -1,   438,   139,   439,    -1,
     438,   126,   439,    -1,   440,    -1,   440,    68,   220,   506,
      -1,   441,    -1,   441,   188,    86,   506,    -1,   442,    -1,
     442,    93,    86,   504,    -1,   443,    -1,   443,    94,    86,
     504,    -1,   445,    -1,   444,   445,    -1,   164,    -1,   147,
      -1,   444,   164,    -1,   444,   147,    -1,   448,    -1,   452,
      -1,   449,    -1,   191,    -1,   196,    -1,   195,    -1,   194,
      -1,   193,    -1,   192,    -1,   140,    -1,   167,    -1,   130,
      -1,    28,   142,   381,   172,    -1,    28,   211,   142,   381,
     172,    -1,    28,   210,   142,   381,   172,    -1,    28,    86,
     520,   142,   381,   172,    -1,   450,   142,   172,    -1,   450,
     142,   381,   172,    -1,   451,    -1,   450,   451,    -1,   165,
     537,    15,    -1,   165,    16,    -1,   453,    -1,   453,   454,
      -1,   181,   454,    -1,   454,    -1,   180,    -1,   455,    -1,
     455,   180,   454,    -1,   455,   181,   454,    -1,   456,    -1,
     465,    -1,   457,    -1,   457,   466,    -1,   460,    -1,   460,
     466,    -1,   458,   462,    -1,   459,    -1,    97,    -1,   106,
      -1,    90,    -1,   178,    -1,   107,    -1,   129,    -1,   128,
      -1,   462,    -1,    91,   462,    -1,   461,   462,    -1,   112,
      -1,   161,    -1,    82,    -1,   169,    -1,   168,    -1,    83,
      -1,   510,    -1,   463,    -1,   537,    -1,   464,    -1,   182,
      -1,    10,    -1,    17,    -1,   468,    -1,   468,   466,    -1,
     467,    -1,   466,   467,    -1,   143,   381,   173,    -1,   469,
      -1,   471,    -1,   472,    -1,   473,    -1,   476,    -1,   478,
      -1,   474,    -1,   475,    -1,   470,    -1,   522,    -1,   102,
      -1,   138,    -1,   114,    -1,   110,   537,    -1,   145,   175,
      -1,   145,   381,   175,    -1,   111,    -1,   158,   142,   381,
     172,    -1,   190,   142,   381,   172,    -1,   537,   145,   175,
      -1,   537,   145,   477,   175,    -1,   384,    -1,   477,    99,
     384,    -1,   479,    -1,   497,    -1,   480,    -1,   494,    -1,
     495,    -1,   146,   537,   484,   120,    -1,   146,   537,   482,
     484,   120,    -1,   146,   537,   484,   185,   183,   537,   484,
     185,    -1,   146,   537,   484,   185,   481,   183,   537,   484,
     185,    -1,   146,   537,   482,   484,   185,   183,   537,   484,
     185,    -1,   146,   537,   482,   484,   185,   481,   183,   537,
     484,   185,    -1,   492,    -1,   481,   492,    -1,   483,    -1,
     482,   483,    -1,    27,   537,   484,   122,   484,   485,    -1,
      -1,    27,    -1,   171,   486,   171,    -1,    85,   488,    85,
      -1,    -1,   487,    -1,   124,    -1,   490,    -1,   487,   124,
      -1,   487,   490,    -1,    -1,   489,    -1,   123,    -1,   491,
      -1,   489,   123,    -1,   489,   491,    -1,    19,    -1,   493,
      -1,     4,    -1,   493,    -1,   479,    -1,     9,    -1,   496,
      -1,   493,    -1,     8,    -1,   113,    -1,   115,    -1,   378,
      -1,   201,    21,   202,    -1,   201,   202,    -1,   162,   536,
     163,    -1,   162,   536,     7,    -1,    95,     6,    -1,   498,
      -1,   499,    -1,   500,    -1,   501,    -1,   502,    -1,   503,
      -1,    31,   142,   381,   172,    -1,    30,   537,   142,   172,
      -1,    30,   537,   142,   381,   172,    -1,    30,   142,   381,
     172,   142,   172,    -1,    30,   142,   381,   172,   142,   381,
     172,    -1,    89,   537,   142,   172,    -1,    89,   537,   142,
     381,   172,    -1,    89,   142,   381,   172,   142,   172,    -1,
      89,   142,   381,   172,   142,   381,   172,    -1,    32,   142,
     381,   172,    -1,    33,   142,   381,   172,    -1,    42,   536,
     142,   172,    -1,    42,   536,   142,   381,   172,    -1,    42,
     142,   381,   172,   142,   172,    -1,    42,   142,   381,   172,
     142,   381,   172,    -1,   509,    -1,   509,   134,    -1,    86,
     506,    -1,   508,    -1,   508,   507,    -1,   199,   145,   175,
      -1,   134,    -1,   182,    -1,   164,    -1,   509,    -1,   510,
      -1,   141,   145,   175,    -1,   537,    -1,   512,    -1,   518,
      -1,   516,    -1,   519,    -1,   517,    -1,   515,    -1,   514,
      -1,   513,    -1,   511,    -1,   214,   145,   175,    -1,    66,
     145,   175,    -1,    66,   145,   518,   175,    -1,    66,   145,
     519,   175,    -1,    32,   145,   175,    -1,    33,   145,   175,
      -1,    42,   145,   175,    -1,    42,   145,   536,   175,    -1,
      42,   145,    20,   175,    -1,    89,   145,   175,    -1,    89,
     145,   537,   175,    -1,    89,   145,   537,    99,   520,   175,
      -1,    89,   145,   182,   175,    -1,    89,   145,   182,    99,
     520,   175,    -1,   177,   537,   175,    -1,    30,   145,   175,
      -1,    30,   145,   537,   175,    -1,    30,   145,   537,    99,
     520,   175,    -1,    30,   145,   537,    99,   521,   175,    -1,
      30,   145,   182,   175,    -1,    30,   145,   182,    99,   520,
     175,    -1,    30,   145,   182,    99,   521,   175,    -1,    65,
     145,   537,   175,    -1,   537,    -1,   537,   134,    -1,    20,
      -1,    25,   209,   210,    -1,    25,   209,   211,    -1,    25,
     209,   212,    -1,   215,   214,   384,   222,   384,    -1,   215,
     214,   384,    86,   221,   222,   384,    -1,   215,   214,   384,
      86,   223,   222,   384,    -1,   215,   214,   384,   207,   384,
      -1,   215,   214,   384,   208,   384,    -1,   215,   216,   384,
     222,   384,    -1,   215,   216,   384,    86,   221,   222,   384,
      -1,   215,   216,   384,    86,   223,   222,   384,    -1,   215,
     216,   384,   207,   384,    -1,   215,   216,   384,   208,   384,
      -1,   213,   214,   384,    -1,   213,   216,   384,    -1,   218,
     214,   384,   226,   384,    -1,   218,   219,   220,   214,   384,
     226,   384,    -1,   217,   214,   384,    86,   384,    -1,   225,
     110,   529,   224,   384,   174,   384,    -1,   530,    -1,   529,
      99,   110,   530,    -1,   537,   132,   384,    -1,   234,   142,
     381,   172,   532,    -1,   533,    -1,   532,   533,    -1,   235,
     534,   379,    -1,   235,   534,   145,   110,   537,   175,   379,
      -1,   235,   534,   145,   110,   537,    99,   110,   537,   175,
     379,    -1,   235,   534,   145,   110,   537,    99,   110,   537,
      99,   110,   537,   175,   379,    -1,   463,    -1,   534,   198,
     463,    -1,    20,    -1,    14,    -1,   537,    -1,    18,    -1,
     539,    -1,   236,   110,   403,    53,   142,   384,   172,    -1,
      53,   142,   384,   172,    -1,   203,    -1,   117,    -1,    89,
      -1,    33,    -1,    66,    -1,    30,    -1,   141,    -1,    40,
      -1,   214,    -1,    42,    -1,    69,    -1,    65,    -1,    32,
      -1,    29,    -1,   199,    -1,    70,    -1,   250,    -1,    64,
      -1,   211,    -1,   210,    -1,   135,    -1,    31,    -1,   249,
      -1,   263,    -1,   252,    -1,   240,    -1,   274,    -1,   266,
      -1,   268,    -1,   267,    -1,   272,    -1,   244,    -1,   239,
      -1,    47,    -1,   206,    -1,   243,    -1,    43,    -1,   212,
      -1,   225,    -1,   219,    -1,   191,    -1,   196,    -1,   195,
      -1,   194,    -1,   193,    -1,   192,    -1,    88,    -1,   103,
      -1,   104,    -1,   174,    -1,    54,    -1,    55,    -1,    56,
      -1,    57,    -1,    58,    -1,    59,    -1,    60,    -1,    61,
      -1,    62,    -1,   136,    -1,    51,    -1,   200,    -1,   159,
      -1,   160,    -1,   157,    -1,    45,    -1,    87,    -1,   108,
      -1,   118,    -1,   119,    -1,    98,    -1,    44,    -1,   125,
      -1,   176,    -1,    92,    -1,    86,    -1,   186,    -1,   116,
      -1,   156,    -1,    84,    -1,    68,    -1,   220,    -1,    93,
      -1,   187,    -1,   109,    -1,   148,    -1,   189,    -1,   139,
      -1,   126,    -1,    28,    -1,    94,    -1,   188,    -1,   140,
      -1,   170,    -1,   184,    -1,   149,    -1,   127,    -1,   121,
      -1,   155,    -1,   137,    -1,   154,    -1,    25,    -1,    52,
      -1,    63,    -1,   105,    -1,    67,    -1,    46,    -1,   204,
      -1,    41,    -1,    48,    -1,    26,    -1,    34,    -1,   262,
      -1,   248,    -1,   271,    -1,   273,    -1,   242,    -1,   256,
      -1,   269,    -1,   261,    -1,   241,    -1,   255,    -1,   270,
      -1,   260,    -1,   254,    -1,   253,    -1,   238,    -1,   237,
      -1,   259,    -1,   245,    -1,   246,    -1,   275,    -1,   265,
      -1,   264,    -1,   257,    -1,   218,    -1,   224,    -1,   221,
      -1,   215,    -1,   208,    -1,   207,    -1,   209,    -1,   226,
      -1,   216,    -1,   217,    -1,   223,    -1,   213,    -1,   222,
      -1,    39,    -1,    36,    -1,    35,    -1,    37,    -1,    38,
      -1,   158,    -1,   190,    -1,   227,    -1,   228,    -1,   229,
      -1,   231,    -1,   233,    -1,   230,    -1,   232,    -1,   234,
      -1,   235,    -1,    53,    -1,   236,    -1,    50,    -1,   284,
      -1,   282,    -1,   283,    -1,   288,    -1,   289,    -1,   290,
      -1,   285,    -1,   286,    -1,   287,    -1,    71,    -1,    72,
      -1,    73,    -1,    74,    -1,    75,    -1,    76,    -1,    77,
      -1,    78,    -1,    79,    -1,    80,    -1,    81,    -1,   276,
      -1,   277,    -1,   278,    -1,   279,    -1,   280,    -1,   281,
      -1,   291,    -1,   292,    -1,   293,    -1,   294,    -1,   295,
      -1,   296,    -1,   297,    -1,   542,    -1,   542,   541,    -1,
     542,   271,   434,    -1,   542,   541,   271,   434,    -1,   551,
      -1,   549,    -1,   541,   551,    -1,   541,   549,    -1,   543,
      -1,   542,   251,   543,    -1,   544,    -1,   543,   247,   544,
      -1,   545,    -1,   544,   249,   136,   545,    -1,   546,    -1,
     249,   546,    -1,   547,    -1,   547,   570,    -1,   145,   540,
     175,    -1,   548,    -1,   548,   566,    -1,   469,    -1,   142,
     381,   172,    -1,   550,    -1,   569,    -1,   568,    -1,   571,
      -1,   565,    -1,   158,    -1,   552,    -1,   553,    -1,   554,
      -1,   555,    -1,   558,    -1,   563,    -1,   564,    -1,   255,
      -1,   270,    -1,    92,   263,    -1,    92,   252,    -1,   226,
     240,    -1,   274,   240,    -1,   240,   263,    -1,   240,   252,
      -1,   226,   266,    -1,   274,   266,    -1,   226,   268,   557,
      -1,   226,   268,   105,    -1,   226,   268,   145,   557,   175,
      -1,   226,   268,   145,   557,    99,   556,   175,    -1,   226,
     268,   145,   105,   175,    -1,   226,   268,   145,   105,    99,
     556,   175,    -1,   274,   268,    -1,   557,    -1,   556,    99,
     557,    -1,    88,    20,    -1,    88,    20,   260,    20,    -1,
      88,    20,   567,   254,    -1,    88,    20,   260,    20,   567,
     254,    -1,   226,   267,   275,   560,    -1,   226,   267,   275,
     560,   559,    -1,   226,   105,   267,   275,    -1,   226,   105,
     267,   275,   559,    -1,   274,   267,   275,    -1,   562,    -1,
     559,   562,    -1,    88,    20,    -1,   145,   561,   175,    -1,
      20,    -1,   561,    20,    -1,   189,   560,    -1,   126,   560,
      -1,   253,    20,    -1,   226,   272,    -1,   274,   272,    -1,
      88,   206,    -1,    88,   243,    -1,   244,   239,    -1,   238,
      -1,   238,    47,    -1,   237,    -1,   237,   275,    -1,   259,
      -1,   245,   437,    -1,    88,   119,   437,    -1,    88,    43,
     437,    -1,   246,   437,   187,   437,    -1,   242,   567,   572,
      -1,   273,   437,   572,    -1,   256,   567,   269,    -1,   261,
     573,    -1,   241,   573,    -1,   275,    -1,   265,    -1,   258,
      -1,   264,    -1,   257,    -1,   274,   239,   437,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  xquery_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    10,    13,    15,    18,    23,
      30,    33,    35,    37,    40,    47,    50,    53,    58,    60,
      64,    66,    70,    72,    74,    76,    78,    80,    82,    84,
      86,    88,    90,    92,    94,    96,   101,   106,   108,   111,
     115,   117,   119,   121,   123,   125,   127,   129,   131,   133,
     135,   137,   139,   141,   143,   145,   147,   149,   151,   153,
     155,   161,   165,   169,   175,   181,   186,   190,   194,   198,
     204,   210,   216,   222,   228,   234,   239,   243,   247,   252,
     258,   265,   267,   271,   275,   279,   283,   290,   296,   305,
     310,   314,   316,   318,   320,   323,   326,   329,   333,   339,
     344,   351,   353,   356,   358,   360,   362,   364,   366,   368,
     371,   374,   376,   379,   382,   385,   389,   394,   400,   407,
     412,   418,   425,   433,   435,   438,   442,   446,   455,   465,
     467,   471,   475,   480,   492,   507,   521,   544,   548,   552,
     555,   559,   564,   570,   573,   578,   582,   583,   587,   590,
     592,   596,   602,   606,   612,   615,   618,   621,   625,   629,
     631,   634,   637,   640,   645,   650,   657,   662,   667,   672,
     674,   678,   681,   685,   689,   693,   695,   697,   700,   702,
     706,   708,   712,   714,   716,   718,   720,   722,   724,   726,
     728,   730,   732,   734,   736,   738,   740,   742,   744,   746,
     749,   752,   755,   758,   760,   762,   765,   770,   774,   780,
     785,   789,   791,   793,   795,   797,   799,   801,   803,   805,
     807,   810,   813,   817,   820,   822,   827,   831,   836,   841,
     847,   852,   858,   864,   871,   875,   879,   883,   885,   890,
     892,   897,   901,   906,   911,   917,   922,   928,   930,   933,
     937,   939,   942,   944,   951,   955,   959,   961,   964,   968,
     970,   974,   977,   981,   984,   988,   993,   995,   999,  1001,
    1004,  1006,  1008,  1010,  1013,  1016,  1019,  1023,  1025,  1027,
    1030,  1033,  1036,  1042,  1048,  1050,  1055,  1059,  1064,  1073,
    1084,  1086,  1089,  1094,  1102,  1111,  1113,  1117,  1119,  1123,
    1125,  1129,  1133,  1137,  1141,  1142,  1147,  1151,  1155,  1159,
    1161,  1165,  1170,  1172,  1176,  1178,  1182,  1186,  1188,  1192,
    1196,  1200,  1204,  1206,  1210,  1214,  1216,  1220,  1224,  1226,
    1231,  1233,  1238,  1240,  1245,  1247,  1252,  1254,  1257,  1259,
    1261,  1264,  1267,  1269,  1271,  1273,  1275,  1277,  1279,  1281,
    1283,  1285,  1287,  1289,  1291,  1296,  1302,  1308,  1315,  1319,
    1324,  1326,  1329,  1333,  1336,  1338,  1341,  1344,  1346,  1348,
    1350,  1354,  1358,  1360,  1362,  1364,  1367,  1369,  1372,  1375,
    1377,  1379,  1381,  1383,  1385,  1387,  1389,  1391,  1393,  1396,
    1399,  1401,  1403,  1405,  1407,  1409,  1411,  1413,  1415,  1417,
    1419,  1421,  1423,  1425,  1427,  1430,  1432,  1435,  1439,  1441,
    1443,  1445,  1447,  1449,  1451,  1453,  1455,  1457,  1459,  1461,
    1463,  1465,  1468,  1471,  1475,  1477,  1482,  1487,  1491,  1496,
    1498,  1502,  1504,  1506,  1508,  1510,  1512,  1517,  1523,  1532,
    1542,  1552,  1563,  1565,  1568,  1570,  1573,  1580,  1581,  1583,
    1587,  1591,  1592,  1594,  1596,  1598,  1601,  1604,  1605,  1607,
    1609,  1611,  1614,  1617,  1619,  1621,  1623,  1625,  1627,  1629,
    1631,  1633,  1635,  1637,  1639,  1641,  1645,  1648,  1652,  1656,
    1659,  1661,  1663,  1665,  1667,  1669,  1671,  1676,  1681,  1687,
    1694,  1702,  1707,  1713,  1720,  1728,  1733,  1738,  1743,  1749,
    1756,  1764,  1766,  1769,  1772,  1774,  1777,  1781,  1783,  1785,
    1787,  1789,  1791,  1795,  1797,  1799,  1801,  1803,  1805,  1807,
    1809,  1811,  1813,  1815,  1819,  1823,  1828,  1833,  1837,  1841,
    1845,  1850,  1855,  1859,  1864,  1871,  1876,  1883,  1887,  1891,
    1896,  1903,  1910,  1915,  1922,  1929,  1934,  1936,  1939,  1941,
    1945,  1949,  1953,  1959,  1967,  1975,  1981,  1987,  1993,  2001,
    2009,  2015,  2021,  2025,  2029,  2035,  2043,  2049,  2057,  2059,
    2064,  2068,  2074,  2076,  2079,  2083,  2091,  2102,  2116,  2118,
    2122,  2124,  2126,  2128,  2130,  2132,  2140,  2145,  2147,  2149,
    2151,  2153,  2155,  2157,  2159,  2161,  2163,  2165,  2167,  2169,
    2171,  2173,  2175,  2177,  2179,  2181,  2183,  2185,  2187,  2189,
    2191,  2193,  2195,  2197,  2199,  2201,  2203,  2205,  2207,  2209,
    2211,  2213,  2215,  2217,  2219,  2221,  2223,  2225,  2227,  2229,
    2231,  2233,  2235,  2237,  2239,  2241,  2243,  2245,  2247,  2249,
    2251,  2253,  2255,  2257,  2259,  2261,  2263,  2265,  2267,  2269,
    2271,  2273,  2275,  2277,  2279,  2281,  2283,  2285,  2287,  2289,
    2291,  2293,  2295,  2297,  2299,  2301,  2303,  2305,  2307,  2309,
    2311,  2313,  2315,  2317,  2319,  2321,  2323,  2325,  2327,  2329,
    2331,  2333,  2335,  2337,  2339,  2341,  2343,  2345,  2347,  2349,
    2351,  2353,  2355,  2357,  2359,  2361,  2363,  2365,  2367,  2369,
    2371,  2373,  2375,  2377,  2379,  2381,  2383,  2385,  2387,  2389,
    2391,  2393,  2395,  2397,  2399,  2401,  2403,  2405,  2407,  2409,
    2411,  2413,  2415,  2417,  2419,  2421,  2423,  2425,  2427,  2429,
    2431,  2433,  2435,  2437,  2439,  2441,  2443,  2445,  2447,  2449,
    2451,  2453,  2455,  2457,  2459,  2461,  2463,  2465,  2467,  2469,
    2471,  2473,  2475,  2477,  2479,  2481,  2483,  2485,  2487,  2489,
    2491,  2493,  2495,  2497,  2499,  2501,  2503,  2505,  2507,  2509,
    2511,  2513,  2515,  2517,  2519,  2521,  2523,  2525,  2527,  2529,
    2531,  2533,  2535,  2537,  2539,  2541,  2543,  2545,  2547,  2550,
    2554,  2559,  2561,  2563,  2566,  2569,  2571,  2575,  2577,  2581,
    2583,  2588,  2590,  2593,  2595,  2598,  2602,  2604,  2607,  2609,
    2613,  2615,  2617,  2619,  2621,  2623,  2625,  2627,  2629,  2631,
    2633,  2635,  2637,  2639,  2641,  2643,  2646,  2649,  2652,  2655,
    2658,  2661,  2664,  2667,  2671,  2675,  2681,  2689,  2695,  2703,
    2706,  2708,  2712,  2715,  2720,  2725,  2732,  2737,  2743,  2748,
    2754,  2758,  2760,  2763,  2766,  2770,  2772,  2775,  2778,  2781,
    2784,  2787,  2790,  2793,  2796,  2799,  2801,  2804,  2806,  2809,
    2811,  2814,  2818,  2822,  2827,  2831,  2835,  2839,  2842,  2845,
    2847,  2849,  2851,  2853,  2855
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   930,   930,   931,   941,   946,   952,   957,   969,   974,
     984,   991,  1003,  1009,  1021,  1034,  1038,  1042,  1054,  1060,
    1074,  1080,  1094,  1095,  1096,  1097,  1103,  1104,  1105,  1106,
    1109,  1112,  1115,  1118,  1120,  1126,  1131,  1140,  1146,  1155,
    1164,  1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,  1173,
    1180,  1181,  1182,  1183,  1184,  1185,  1186,  1189,  1196,  1197,
    1209,  1221,  1226,  1237,  1243,  1255,  1268,  1279,  1284,  1296,
    1301,  1312,  1318,  1324,  1330,  1349,  1360,  1371,  1378,  1385,
    1392,  1405,  1411,  1426,  1430,  1440,  1447,  1455,  1462,  1475,
    1482,  1488,  1495,  1501,  1505,  1512,  1523,  1528,  1537,  1546,
    1553,  1563,  1569,  1578,  1582,  1586,  1590,  1594,  1598,  1602,
    1606,  1610,  1614,  1618,  1622,  1630,  1638,  1646,  1654,  1662,
    1668,  1676,  1684,  1696,  1701,  1710,  1714,  1722,  1730,  1742,
    1748,  1757,  1764,  1775,  1785,  1795,  1805,  1824,  1829,  1841,
    1845,  1849,  1853,  1860,  1867,  1893,  1903,  1909,  1915,  1924,
    1934,  1947,  1955,  1962,  1976,  1980,  1987,  1992,  1999,  2007,
    2011,  2015,  2023,  2030,  2039,  2051,  2060,  2072,  2081,  2095,
    2103,  2117,  2124,  2137,  2145,  2156,  2171,  2175,  2191,  2195,
    2204,  2208,  2225,  2226,  2227,  2228,  2229,  2232,  2233,  2234,
    2235,  2236,  2238,  2239,  2242,  2243,  2244,  2245,  2246,  2253,
    2266,  2273,  2277,  2285,  2289,  2293,  2300,  2304,  2311,  2319,
    2330,  2340,  2341,  2342,  2346,  2346,  2346,  2346,  2346,  2349,
    2355,  2364,  2368,  2378,  2389,  2395,  2409,  2417,  2426,  2436,
    2447,  2456,  2466,  2476,  2492,  2505,  2517,  2529,  2535,  2547,
    2553,  2567,  2576,  2586,  2595,  2608,  2615,  2626,  2627,  2632,
    2641,  2645,  2650,  2654,  2660,  2665,  2673,  2689,  2697,  2704,
    2710,  2721,  2728,  2738,  2748,  2753,  2765,  2771,  2785,  2791,
    2803,  2810,  2817,  2824,  2831,  2838,  2845,  2858,  2862,  2872,
    2876,  2886,  2896,  2903,  2916,  2923,  2935,  2942,  2956,  2963,
    2978,  2984,  2996,  3002,  3016,  3027,  3031,  3042,  3046,  3057,
    3061,  3069,  3077,  3085,  3093,  3093,  3104,  3112,  3120,  3133,
    3137,  3144,  3157,  3161,  3172,  3176,  3180,  3190,  3194,  3198,
    3202,  3206,  3216,  3220,  3225,  3236,  3240,  3244,  3254,  3258,
    3270,  3274,  3286,  3290,  3302,  3306,  3318,  3322,  3334,  3338,
    3342,  3346,  3358,  3362,  3366,  3376,  3380,  3384,  3388,  3392,
    3396,  3406,  3410,  3414,  3424,  3428,  3432,  3436,  3448,  3454,
    3466,  3472,  3486,  3493,  3534,  3538,  3542,  3546,  3558,  3568,
    3579,  3584,  3594,  3598,  3608,  3614,  3620,  3626,  3638,  3644,
    3655,  3659,  3663,  3667,  3671,  3675,  3679,  3689,  3693,  3703,
    3707,  3718,  3722,  3726,  3730,  3734,  3749,  3753,  3763,  3767,
    3777,  3784,  3791,  3804,  3808,  3820,  3826,  3840,  3851,  3855,
    3859,  3863,  3867,  3871,  3875,  3879,  3889,  3893,  3903,  3908,
    3913,  3924,  3935,  3939,  3950,  3960,  3971,  4027,  4033,  4045,
    4051,  4063,  4067,  4077,  4081,  4085,  4095,  4103,  4111,  4119,
    4127,  4135,  4150,  4156,  4168,  4174,  4187,  4196,  4198,  4204,
    4209,  4221,  4224,  4231,  4237,  4243,  4251,  4266,  4269,  4276,
    4282,  4288,  4296,  4310,  4315,  4326,  4331,  4342,  4347,  4352,
    4358,  4370,  4376,  4381,  4386,  4397,  4402,  4417,  4422,  4439,
    4454,  4458,  4462,  4466,  4470,  4474,  4484,  4495,  4501,  4507,
    4512,  4534,  4540,  4546,  4551,  4562,  4572,  4582,  4588,  4594,
    4599,  4609,  4613,  4623,  4634,  4638,  4642,  4679,  4683,  4687,
    4697,  4701,  4705,  4715,  4725,  4729,  4733,  4737,  4741,  4745,
    4749,  4753,  4757,  4767,  4777,  4781,  4785,  4795,  4805,  4815,
    4819,  4823,  4833,  4839,  4845,  4851,  4857,  4869,  4880,  4887,
    4894,  4901,  4908,  4915,  4922,  4935,  4956,  4963,  4983,  5023,
    5027,  5031,  5040,  5046,  5052,  5058,  5064,  5071,  5077,  5083,
    5089,  5095,  5107,  5112,  5122,  5128,  5140,  5166,  5177,  5183,
    5196,  5212,  5219,  5225,  5236,  5243,  5253,  5264,  5280,  5286,
    5296,  5305,  5306,  5324,  5328,  5341,  5347,  5355,  5356,  5357,
    5358,  5359,  5360,  5361,  5362,  5363,  5364,  5365,  5366,  5367,
    5368,  5369,  5370,  5371,  5372,  5373,  5374,  5375,  5376,  5377,
    5378,  5379,  5380,  5381,  5382,  5383,  5384,  5385,  5386,  5387,
    5388,  5389,  5390,  5391,  5392,  5393,  5394,  5395,  5396,  5397,
    5398,  5399,  5400,  5401,  5402,  5403,  5404,  5405,  5406,  5407,
    5408,  5409,  5410,  5411,  5412,  5413,  5414,  5415,  5416,  5417,
    5418,  5419,  5420,  5421,  5422,  5423,  5424,  5425,  5426,  5427,
    5428,  5429,  5430,  5431,  5432,  5433,  5434,  5435,  5436,  5437,
    5438,  5439,  5440,  5441,  5442,  5443,  5444,  5445,  5446,  5447,
    5448,  5449,  5450,  5451,  5452,  5453,  5454,  5455,  5456,  5457,
    5458,  5459,  5460,  5461,  5462,  5463,  5464,  5465,  5466,  5467,
    5468,  5469,  5470,  5471,  5472,  5473,  5474,  5475,  5476,  5477,
    5478,  5479,  5480,  5481,  5482,  5483,  5484,  5485,  5486,  5487,
    5488,  5489,  5490,  5491,  5492,  5493,  5494,  5495,  5496,  5497,
    5498,  5499,  5500,  5501,  5502,  5503,  5504,  5505,  5506,  5507,
    5508,  5509,  5510,  5511,  5512,  5513,  5514,  5515,  5516,  5517,
    5518,  5519,  5520,  5521,  5522,  5523,  5524,  5525,  5526,  5527,
    5528,  5529,  5530,  5531,  5532,  5533,  5534,  5535,  5536,  5537,
    5538,  5539,  5540,  5541,  5542,  5543,  5544,  5545,  5546,  5547,
    5548,  5549,  5550,  5551,  5552,  5553,  5554,  5569,  5573,  5577,
    5581,  5591,  5594,  5597,  5600,  5609,  5612,  5621,  5624,  5633,
    5636,  5645,  5648,  5657,  5660,  5663,  5672,  5675,  5684,  5688,
    5698,  5701,  5704,  5707,  5710,  5719,  5728,  5732,  5736,  5740,
    5744,  5748,  5752,  5762,  5765,  5768,  5771,  5780,  5783,  5786,
    5789,  5798,  5801,  5810,  5813,  5816,  5819,  5822,  5825,  5828,
    5837,  5840,  5849,  5852,  5855,  5858,  5867,  5870,  5873,  5876,
    5879,  5888,  5891,  5900,  5903,  5912,  5915,  5924,  5927,  5936,
    5945,  5948,  5957,  5960,  5963,  5972,  5975,  5978,  5981,  5984,
    5993,  5997,  6001,  6005,  6015,  6024,  6034,  6043,  6046,  6055,
    6058,  6061,  6070,  6073,  6082
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
	       << " (line " << yylno << "):" << std::endl;
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 10623;
  const int xquery_parser::yynnts_ = 262;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 514;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 313;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 567;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 14060 "/Users/pjl/src/flwor/zorba/trunk/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6088 "/Users/pjl/src/flwor/zorba/trunk/src/compiler/parser/xquery_parser.y"


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
/* vim:set et sw=4 ts=4: */

