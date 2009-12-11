
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
#line 59 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"


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
#line 75 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 925 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_driver.h"
#include "compiler/parser/xquery_scanner.h"
#undef yylex
#define yylex driver.lexer->lex


/* Line 317 of lalr1.cc  */
#line 92 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"

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
#line 161 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
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
#line 809 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 268 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 114: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 808 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 277 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 138: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 807 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 286 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 317: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 295 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 304 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 313 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 322 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "Prolog" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 331 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 340 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 349 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 358 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 367 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 376 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 821 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->pair_vector); };

/* Line 480 of lalr1.cc  */
#line 385 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 821 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->pair); };

/* Line 480 of lalr1.cc  */
#line 394 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 403 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 412 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 421 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 430 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 439 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 448 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 457 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 466 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 475 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 484 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 493 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 502 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 511 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 520 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 529 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 538 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 547 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 556 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 565 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 821 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 574 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 583 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 592 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "CollPropertyList" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 601 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "CollProperty" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 610 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "NodeModifier" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 619 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 628 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "IndexProperties" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 637 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "IndexProperties2" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 646 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "IndexProperties3" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 655 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 664 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 673 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 682 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 691 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 821 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 700 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 709 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "Block" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 718 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "BlockDecls" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 727 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "BlockVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 736 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "BlockVarDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 745 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "AssignExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 754 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "ExitExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 763 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "WhileExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 772 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 781 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 790 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 799 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "FunctionDecl3" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 808 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "FunctionDecl4" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 835 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "EnclosedExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 844 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 853 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 862 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 871 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "ApplyExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 880 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "ConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 889 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 898 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 907 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 916 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 925 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 934 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 943 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 952 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 961 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 970 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 979 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 988 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 997 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1006 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1015 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "EvalVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1024 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1033 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1042 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1051 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1060 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1069 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "EvalVarDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1078 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1087 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1096 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1105 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1114 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1123 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1132 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1141 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1150 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1159 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1168 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1177 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1186 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1195 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1204 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1213 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1222 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1231 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1240 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1249 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1258 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1267 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1276 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1285 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1294 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1303 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1312 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1321 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1330 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1339 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1348 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1357 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1366 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1375 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1384 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1393 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1402 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1411 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1420 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1429 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "PragmaList" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1438 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1447 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1456 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1465 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1474 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1483 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1492 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1501 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1510 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1519 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1528 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1537 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1546 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1555 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1564 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1573 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1582 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1591 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1600 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1609 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1618 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1627 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1636 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1645 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1654 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1663 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1672 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1681 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1690 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1699 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1708 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1717 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1726 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1735 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "Opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1744 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1753 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "Opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1762 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1771 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1780 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1789 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1798 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1807 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1816 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1825 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1834 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1843 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1852 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1861 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1870 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1879 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1888 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1897 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1906 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1915 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1924 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1933 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1942 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1951 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1960 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1969 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1978 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1987 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1996 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2005 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2014 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2023 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2032 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2041 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2050 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2059 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2068 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2077 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2086 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2095 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2104 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2113 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2122 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2131 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2140 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2149 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2158 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 821 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2167 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2176 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "EvalExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2185 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
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
#line 108 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename);
}

/* Line 553 of lalr1.cc  */
#line 2270 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"

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
#line 943 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 953 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		}
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 958 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<MainModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr ((yyval.node));
		}
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 964 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
       driver.set_expr ((yyval.node));
		}
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 969 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
       driver.set_expr ((yyval.node));
		}
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 981 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)), encoding);
		}
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 986 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 996 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)));
		}
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 1003 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)),
                NULL);
		}
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1015 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC ((yyloc)),
                             static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)),
                             NULL);
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1021 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LibraryModule(LOC ((yyloc)),
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1033 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(6) - (3)].sval)),
								SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
      dynamic_cast<ModuleDecl *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
		}
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1046 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)), NULL);
		}
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1050 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		}
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1054 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC((yyloc)),
                      static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
                      static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1066 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = new SIND_DeclList(LOC ((yyloc)));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		}
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1072 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1086 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = new VFO_DeclList(LOC ((yyloc)));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		}
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1092 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1138 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].pair_vector));
      delete (yysemantic_stack_[(4) - (4)].pair_vector);
    }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 1143 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr))->get_qname(), (yysemantic_stack_[(4) - (4)].pair_vector));
      delete (yysemantic_stack_[(4) - (3)].expr);
      delete (yysemantic_stack_[(4) - (4)].pair_vector);
    }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 1152 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.pair_vector) = new std::vector<std::pair<std::string, std::string> > ();
      (yyval.pair_vector)->push_back(*(yysemantic_stack_[(1) - (1)].pair));
      delete (yysemantic_stack_[(1) - (1)].pair);
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 1158 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].pair_vector)->push_back(*(yysemantic_stack_[(2) - (2)].pair));
      delete (yysemantic_stack_[(2) - (2)].pair);
      (yyval.pair_vector) = (yysemantic_stack_[(2) - (1)].pair_vector);
    }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1167 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *s = static_cast<StringLiteral *>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.pair) = new std::pair<std::string, std::string>((yysemantic_stack_[(3) - (1)].strval), s->get_strval());
      delete s;
    }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1175 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1176 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1177 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1178 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1179 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1180 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1181 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1182 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1183 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1184 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1221 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1233 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		}
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1238 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		}
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1249 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_element_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1255 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_function_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1267 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OptionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
								SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
		}
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1280 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (3)].node));
		}
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1291 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		}
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1296 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		}
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1308 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		}
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1313 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		}
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1324 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::inherit_ns);
		}
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1330 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::no_inherit_ns);
		}
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1336 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::inherit_ns);
		}
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1342 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::no_inherit_ns);
		}
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1361 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)));
		}
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1372 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		}
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1383 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		}
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1390 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)),
								NULL);
		}
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 1397 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		}
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 1404 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
		}
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 1417 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = new URILiteralList(LOC ((yyloc)));
			uri_list_p->push_back(SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		}
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1423 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1438 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1442 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		}
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1452 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)), false,
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1459 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1467 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)), false,
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
		}
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1474 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1487 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1494 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->type = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1500 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1507 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(1) - (1)].node));
      d->ext = false;
      (yyval.node) = d;
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1513 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), NULL);
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1517 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1524 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1535 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(), NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1540 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
                               dynamic_cast<SequenceType *> ((yysemantic_stack_[(3) - (3)].node)));
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1549 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1558 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (3)].varnametype)));
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       NULL, true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
		}
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1565 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(6) - (3)].varnametype)));
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       (yysemantic_stack_[(6) - (6)].expr), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
		}
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1575 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                               0, 
                               0, 
                               0);
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1583 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                               0, 
                               static_cast<NodeModifier*>((yysemantic_stack_[(4) - (4)].node)), 
                               0);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1591 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                               0, 
                               0, 
                               static_cast<parsenode*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1599 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                               0, 
                               static_cast<NodeModifier*>((yysemantic_stack_[(6) - (4)].node)), 
                               static_cast<NodeModifier*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1607 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<CollPropertyList*>((yysemantic_stack_[(4) - (2)].node)), 0, 0);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1613 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                               static_cast<CollPropertyList*>((yysemantic_stack_[(5) - (2)].node)), 
                               static_cast<NodeModifier*>((yysemantic_stack_[(5) - (5)].node)), 
                               0);
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1621 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<CollPropertyList*>((yysemantic_stack_[(6) - (2)].node)), 
                               0, 
                               static_cast<parsenode*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 1629 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(7) - (4)].expr)),
                               static_cast<CollPropertyList*>((yysemantic_stack_[(7) - (2)].node)), 
                               static_cast<NodeModifier*>((yysemantic_stack_[(7) - (5)].node)), 
                               static_cast<NodeModifier*>((yysemantic_stack_[(7) - (7)].node)));
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 1640 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CollPropertyList* l = new CollPropertyList(LOC((yyloc)));
      l->addProperty(dynamic_cast<CollProperty*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1646 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<CollPropertyList*>((yysemantic_stack_[(2) - (1)].node))->addProperty(static_cast<CollProperty*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1654 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollProperty(LOC((yyloc)), StaticContextConsts::const_);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1658 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollProperty(LOC((yyloc)), StaticContextConsts::append_only);
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1662 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollProperty(LOC((yyloc)), StaticContextConsts::queue);
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1666 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollProperty(LOC((yyloc)), StaticContextConsts::mutable_coll);
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1670 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollProperty(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1674 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollProperty(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1683 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1687 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1695 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(9) - (3)].expr)),
                         (yysemantic_stack_[(9) - (5)].expr),
                         dynamic_cast<IndexKeyList*>((yysemantic_stack_[(9) - (7)].node)),
                         dynamic_cast<IndexProperties*>((yysemantic_stack_[(9) - (9)].node)));
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1707 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1712 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      IndexProperties* p = dynamic_cast<IndexProperties*>((yysemantic_stack_[(2) - (2)].node));
      p->setUnique();
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1719 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1726 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1731 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      IndexProperties* p = dynamic_cast<IndexProperties*>((yysemantic_stack_[(2) - (2)].node));
      p->setOrdered();
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1738 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1744 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      // default properties: non-unique, non-ordered, manual
      (yyval.node) = new IndexProperties(LOC((yyloc)), false, false, false);
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1749 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexProperties(LOC((yyloc)), false, false, false);
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1754 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexProperties(LOC((yyloc)), false, false, true);
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1762 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* l = new IndexKeyList(LOC((yyloc)));
      l->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1768 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1777 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1782 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1789 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1796 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1808 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                            (yysemantic_stack_[(12) - (2)].intval) & IntegrityConstraintDecl::IC_OPTION_UNCHECKED,
                            (yysemantic_stack_[(12) - (2)].intval) & IntegrityConstraintDecl::IC_OPTION_ASYNCH,
                                 static_cast<QName*>((yysemantic_stack_[(12) - (5)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(12) - (8)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(12) - (10)].expr)),
                                 (yysemantic_stack_[(12) - (12)].expr));
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1820 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                            (yysemantic_stack_[(16) - (2)].intval) & IntegrityConstraintDecl::IC_OPTION_UNCHECKED,
                            (yysemantic_stack_[(16) - (2)].intval) & IntegrityConstraintDecl::IC_OPTION_ASYNCH,
                                    static_cast<QName*>((yysemantic_stack_[(16) - (5)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(16) - (8)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(16) - (10)].expr)),
                                    (yysemantic_stack_[(16) - (15)].expr));
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1832 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                            (yysemantic_stack_[(14) - (2)].intval) & IntegrityConstraintDecl::IC_OPTION_UNCHECKED,
                            (yysemantic_stack_[(14) - (2)].intval) & IntegrityConstraintDecl::IC_OPTION_ASYNCH,
                                    static_cast<QName*>((yysemantic_stack_[(14) - (5)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (8)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (12)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1844 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICNodeOfType(LOC((yyloc)),
                            (yysemantic_stack_[(14) - (2)].intval) & IntegrityConstraintDecl::IC_OPTION_UNCHECKED,
                            (yysemantic_stack_[(14) - (2)].intval) & IntegrityConstraintDecl::IC_OPTION_ASYNCH,
                            static_cast<QName*>((yysemantic_stack_[(14) - (5)].expr)),
                            static_cast<QName*>((yysemantic_stack_[(14) - (9)].expr)),
                            (yysemantic_stack_[(14) - (12)].node),
                            (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1857 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICForeignKey(LOC((yyloc)),
                            (yysemantic_stack_[(27) - (2)].intval) & IntegrityConstraintDecl::IC_OPTION_UNCHECKED,
                            (yysemantic_stack_[(27) - (2)].intval) & IntegrityConstraintDecl::IC_OPTION_ASYNCH,
                            static_cast<QName*>((yysemantic_stack_[(27) - (5)].expr)),
                            static_cast<QName*>((yysemantic_stack_[(27) - (10)].expr)),
                            static_cast<QName*>((yysemantic_stack_[(27) - (13)].expr)),
                            (yysemantic_stack_[(27) - (16)].expr),
                            static_cast<QName*>((yysemantic_stack_[(27) - (20)].expr)),
                            static_cast<QName*>((yysemantic_stack_[(27) - (23)].expr)),
                            (yysemantic_stack_[(27) - (26)].expr));
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1878 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.intval) = (yysemantic_stack_[(2) - (1)].intval) | (yysemantic_stack_[(2) - (2)].intval); }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1881 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.intval) = (yysemantic_stack_[(2) - (1)].intval) | (yysemantic_stack_[(2) - (2)].intval); }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1884 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.intval) = IntegrityConstraintDecl::IC_OPTION_CHECKED; // checked
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1889 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.intval) = IntegrityConstraintDecl::IC_OPTION_CHECKED; // checked
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1893 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.intval) = IntegrityConstraintDecl::IC_OPTION_UNCHECKED;  // unchecked
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1899 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.intval) = IntegrityConstraintDecl::IC_OPTION_SYNCH; // synchronous
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1904 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.intval) = IntegrityConstraintDecl::IC_OPTION_SYNCH; // synchronous
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1908 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.intval) = IntegrityConstraintDecl::IC_OPTION_ASYNCH;  // asynchronous
    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1919 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		}
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1924 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		}
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1936 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL);
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1940 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1944 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL, dynamic_cast<SequenceType *> ((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1948 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType *> ((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1955 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1962 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 156:

/* Line 678 of lalr1.cc  */
#line 1988 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (1)].node));
      std::auto_ptr<VFO_DeclList> vfo2(dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (2)].node)));
      if ((yysemantic_stack_[(3) - (1)].node) == NULL)
        vfo = new VFO_DeclList (LOC ((yyloc)));
      vfo->push_back (*(vfo2.get()));
      (yyval.node) = vfo;
    }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 1997 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL;
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 2004 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (1)].node));
      vfo->push_back ((yysemantic_stack_[(3) - (3)].node));
      (yyval.node) = vfo;
    }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 2010 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = new VFO_DeclList (LOC ((yyloc)));
      vfo->push_back ((yysemantic_stack_[(2) - (2)].node));
      (yyval.node) = vfo;
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 2019 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 161:

/* Line 678 of lalr1.cc  */
#line 2029 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 162:

/* Line 678 of lalr1.cc  */
#line 2042 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr (LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr))->get_qname(), (yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (3)].expr);
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 2050 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr (LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2057 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 165:

/* Line 678 of lalr1.cc  */
#line 2071 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 2075 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::CONTINUE);
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 2082 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<FunctionDecl *>((yysemantic_stack_[(2) - (2)].node))->setComment(SYMTAB((yysemantic_stack_[(2) - (1)].sval)));
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 2087 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
      d->deterministic = false;
      (yyval.node) = d;
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 2094 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<FunctionDecl *>((yysemantic_stack_[(3) - (3)].node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 2102 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 2106 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 2110 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(2) - (2)].node));
      d->type = (d->type == ParseConstants::fn_extern)
        ? ParseConstants::fn_extern_update
        : ParseConstants::fn_update;
      (yyval.node) = d;
    }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 2118 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 2125 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								(yysemantic_stack_[(4) - (4)].expr),
								ParseConstants::fn_read);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 2134 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								NULL,
								ParseConstants::fn_extern);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 2146 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								(yysemantic_stack_[(4) - (4)].expr),
								ParseConstants::fn_sequential);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 2155 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								NULL,
								ParseConstants::fn_extern_sequential);
    }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 2168 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = new ParamList(LOC ((yyloc)));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)));
			}
			(yyval.node) = plist_p;
		}
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2176 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2190 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(),
								NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
		}
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2197 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
      delete (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 2210 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 2218 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 2229 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QueryBody(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
		}
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 2244 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 2248 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<BlockBody> blk(dynamic_cast<BlockBody *>((yysemantic_stack_[(2) - (2)].expr)));

      BlockBody* blk2 = new BlockBody(LOC((yyloc)));

      blk2->add((yysemantic_stack_[(2) - (1)].expr));

      for (int i = 0; i < blk->size(); ++i)
        blk2->add((*blk)[i]);

      (yyval.expr) = blk2;
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 2264 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody (LOC ((yyloc)));
    }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 2268 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = dynamic_cast<BlockBody *>((yysemantic_stack_[(3) - (1)].expr));
      blk->add((yysemantic_stack_[(3) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 2277 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 2281 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 208:

/* Line 678 of lalr1.cc  */
#line 2326 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 209:

/* Line 678 of lalr1.cc  */
#line 2339 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 2346 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 2350 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 2358 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 2362 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 2366 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_only_end;
    }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 2373 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), dynamic_cast<WindowVars *> ((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr), (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 2377 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr), (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 2384 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(5) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window,
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(5) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (4)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 2392 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window,
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 2403 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause (LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 2422 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = new FLWORClauseList (LOC ((yyloc)));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 2428 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = dynamic_cast<FLWORClauseList *> ((yysemantic_stack_[(2) - (1)].node));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 2437 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = NULL;
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 2441 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_ofor;
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 2451 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForClause(LOC ((yyloc)),
                         dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL);
		}
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 2462 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		}
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 2468 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vardecl_list_p) {
				vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 2482 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (1)].expr);
		}
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 2490 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 2499 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 238:

/* Line 678 of lalr1.cc  */
#line 2509 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 239:

/* Line 678 of lalr1.cc  */
#line 2520 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 2529 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 241:

/* Line 678 of lalr1.cc  */
#line 2539 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 242:

/* Line 678 of lalr1.cc  */
#line 2549 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 243:

/* Line 678 of lalr1.cc  */
#line 2565 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
		}
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2578 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
		}
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 2590 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)));

		}
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2602 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		}
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 2608 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2620 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		}
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2626 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2640 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
								NULL,
								NULL,
								(yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (1)].expr);
		}
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2649 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 2659 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2668 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (1)].expr);
		}
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 2681 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr))->get_qname(),
								NULL, (yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (2)].expr);
		}
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 2688 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (2)].expr);
		}
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 2700 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(), "", "");
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 2705 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_curr (static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2714 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), dynamic_cast<PositionalVar *> ((yysemantic_stack_[(1) - (1)].node)), "", "", "");
    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2718 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_posvar (dynamic_cast<PositionalVar *> ((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2727 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr))->get_qname(), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr))->get_qname());
      delete (yysemantic_stack_[(6) - (3)].expr);
      delete (yysemantic_stack_[(6) - (6)].expr);
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2733 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", "", static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2738 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname(), "");
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2746 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::string name = static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr))->get_qname();
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           name, NULL, NULL,
                           new VarRef (LOC ((yyloc)), name),
                           VarGetsDecl::eval_var);
      delete (yysemantic_stack_[(1) - (1)].expr);

    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2762 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2770 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2777 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = new GroupSpecList(LOC((yyloc)));
      gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl_p;
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2783 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      if (gsl_p) {
        gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      }
      (yyval.node) = gsl_p;
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2794 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(),
                 NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2801 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
                 dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2811 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2821 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)),
								true);
		}
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2838 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		}
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2844 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node));
			if (osl_p) {
				osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 2858 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		}
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2864 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
                         (yysemantic_stack_[(2) - (1)].expr),
                         dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2876 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
                               NULL,
                               NULL);
		}
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2883 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               NULL,
                               dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
                               NULL);
		}
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2890 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               NULL,
                               NULL,
                               dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2897 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                               dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                               NULL);
		}
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2904 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                               NULL,
                               dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2911 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               NULL,
                               dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                               dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2918 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                               dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                               dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2931 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		}
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2935 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		}
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2945 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC((yyloc)), StaticContextConsts::empty_greatest);
		}
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2949 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC((yyloc)), StaticContextConsts::empty_least);
		}
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 2959 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		}
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 2970 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 2977 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 2990 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;

		}
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 2997 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 3009 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
								(yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (1)].expr);
		}
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 3016 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 3030 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
								(yysemantic_stack_[(8) - (8)].expr));
		}
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 3037 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(10) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
								static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr))->get_qname(),
								(yysemantic_stack_[(10) - (10)].expr));
      delete (yysemantic_stack_[(10) - (8)].expr);
		}
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 3052 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		}
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 3058 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 3070 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3076 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr))->get_qname(),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
      delete (yysemantic_stack_[(7) - (3)].expr);
		}
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3090 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
		}
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3101 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3105 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3116 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3120 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3139 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3143 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3151 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      /*  ::=  "is" | "<<" | ">>" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3159 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3167 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3174 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { /* this call is needed */  driver.lexer->interpretAsLessThan(); }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3175 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3183 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_le),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3191 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3199 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3213 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3217 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		}
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3224 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3237 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3241 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3252 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3256 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3260 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3270 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3274 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3278 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3282 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3286 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3296 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3300 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3305 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3316 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3320 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3324 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3334 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3338 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3350 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3354 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3366 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3370 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3382 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3386 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3398 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3402 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3414 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		}
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3418 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		}
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3422 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3426 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3438 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3442 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3446 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3456 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		}
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3460 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		}
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3464 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		}
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3468 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		}
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3472 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		}
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3476 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		}
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3486 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		}
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3490 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		}
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3494 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		}
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3504 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3508 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3512 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3516 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                            dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(),
                            (yysemantic_stack_[(6) - (5)].expr));
    }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3528 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		}
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3534 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3546 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		}
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3552 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node));
			if (pragma_list_p) {
				pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3566 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));

		}
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3572 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval))),
								"");
    }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3614 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		}
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3618 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3622 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3626 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (rpe == NULL ?
             (yysemantic_stack_[(1) - (1)].expr) :
             new PathExpr(LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3638 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3648 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 379:

/* Line 678 of lalr1.cc  */
#line 3659 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3664 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3674 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3678 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3688 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		}
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3694 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3700 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		}
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3706 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3718 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		}
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3724 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3735 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		}
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3739 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		}
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3743 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		}
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3747 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		}
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3751 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		}
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3755 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		}
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3759 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		}
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3769 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node), false);
		}
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3773 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		}
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3783 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseStep(LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node));
		}
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC((yyloc)), rev_p, NULL);
		}
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3798 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		}
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3802 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		}
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3806 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		}
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3810 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		}
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3814 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		}
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3829 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3833 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3843 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3847 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3857 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        "",
                        ParseConstants::wild_all);
		}
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3864 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        ParseConstants::wild_elem);
		}
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3871 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        ParseConstants::wild_prefix);
		}
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3884 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3888 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
                          (yysemantic_stack_[(2) - (1)].expr),
                          dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3900 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		}
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3906 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node));
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3920 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3931 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3935 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3939 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3943 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3947 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3951 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3955 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 3959 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 3969 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 3973 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 3983 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval));
      delete yylval.decval;
		}
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 3988 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival));
      delete yylval.ival;
		}
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 3993 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval));
      delete yylval.dval;
		}
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 4004 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new VarRef(LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname());
      delete (yysemantic_stack_[(2) - (2)].expr);
		}
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 4015 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		}
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 4019 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 4030 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		}
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 4040 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 4051 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 4107 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)),
								NULL);
		}
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 4113 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4125 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = new ArgList(LOC ((yyloc)));
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		}
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4131 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4143 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4147 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4157 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4161 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4165 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4175 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
								NULL,
								NULL,
								NULL);
		}
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4183 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
								NULL,
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)),
								NULL);
		}
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4191 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(8) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr)),
								NULL,
								NULL);
		}
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4199 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
								NULL,
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node)));
		}
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4207 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
								NULL);
		}
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4215 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(10) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)),
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node)));
		}
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4230 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		}
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4236 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4248 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		}
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4254 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4267 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
		}
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4284 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		}
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4289 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		}
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4300 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		}
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4304 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4311 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		}
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4317 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		}
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4323 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4331 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4345 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		}
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4349 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4356 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		}
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4362 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		}
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4368 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4376 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4390 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4395 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4406 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4411 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4422 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		}
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4427 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4432 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		}
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4438 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		}
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4450 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4456 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		}
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4461 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		}
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4466 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4477 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4482 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4497 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4502 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		}
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4519 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CDataSection(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		}
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4534 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4538 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4542 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4546 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4550 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4554 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4564 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4575 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
								NULL);
		}
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4581 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4587 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4592 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4614 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (2)].expr),
								NULL);
		}
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4620 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4626 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4631 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4642 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4652 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4662 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		}
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4668 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4674 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4679 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4690 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		}
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4696 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		}
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4708 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
		}
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4719 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		}
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4725 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4731 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		}
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4768 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		}
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4773 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		}
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4778 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		}
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4789 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4793 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4797 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		}
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4807 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4818 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4822 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4830 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4834 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4838 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4842 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4846 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4850 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4860 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		}
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4870 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		}
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4874 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4879 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4890 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TextTest(LOC ((yyloc)));
		}
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4900 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		}
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4910 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		}
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4914 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		}
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4918 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		}
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4928 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		}
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4934 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
								NULL);
		}
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4940 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		}
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4946 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		}
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4952 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		}
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4964 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
		}
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4975 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           NULL,
                           NULL,
                           true);
		}
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4982 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                           NULL,
                           true);
		}
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4989 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           false);
		}
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4996 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           true);
		}
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 5003 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL,
									true);
		}
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 5010 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									false);
		}
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 5017 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									true);
		}
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 5030 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)));
		}
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 5051 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 5058 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)),
								true);
		}
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 5078 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 5118 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::strict_validation);
		}
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 5122 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::lax_validation);
    }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 5126 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::skip_validation);
    }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 5135 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 5141 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 5147 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 5153 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 5159 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 5166 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 5172 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 5178 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5184 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5190 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5202 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5207 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5217 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5223 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5235 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5261 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5272 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       CopyVarList* lList = new CopyVarList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
		}
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5278 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
       VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
       lList->push_back(lBinding);
       (yyval.expr) = lList;
		}
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5291 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (1)].expr);
    }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5307 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5314 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5320 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* aCatchListExpr = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if (aCatchListExpr) {
        aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)));
      }
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5331 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(3) - (2)].name_test_list),
                          (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5338 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(7) - (2)].name_test_list),
                          static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr))->get_qname(),
                          (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (5)].expr);
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5348 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 586:

/* Line 678 of lalr1.cc  */
#line 5359 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 587:

/* Line 678 of lalr1.cc  */
#line 5375 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CatchExpr::NameTestList *name_test_list = new CatchExpr::NameTestList;
      name_test_list->push_back (static_cast<NameTest *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.name_test_list) = name_test_list;
    }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5381 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CatchExpr::NameTestList *name_test_list =
        static_cast<CatchExpr::NameTestList *> ((yysemantic_stack_[(3) - (1)].name_test_list));
      name_test_list->push_back (static_cast<NameTest *> ((yysemantic_stack_[(3) - (3)].node)));
      (yyval.name_test_list) = name_test_list;
    }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5401 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 592:

/* Line 678 of lalr1.cc  */
#line 5419 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5423 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5429 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("xquery"); }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5430 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty"); }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5431 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("attribute"); }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5432 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("comment"); }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5433 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document-node"); }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5434 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("element"); }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5435 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("item"); }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5436 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("if"); }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5437 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("node"); }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5438 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("processing-instruction"); }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5439 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-attribute"); }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5440 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-element"); }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5441 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("text"); }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5442 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("typeswitch"); }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5443 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty-sequence"); }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5444 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("boundary-space"); }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5445 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ft-option"); }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5446 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("base-uri"); }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5447 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lax"); }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5448 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strict"); }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5449 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("idiv"); }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5450 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document"); }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5451 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("not"); }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5452 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sensitive"); }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5453 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insensitive"); }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5454 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("diacritics"); }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5455 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("without"); }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5456 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stemming"); }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5457 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("thesaurus"); }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5458 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stop"); }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5459 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("wildcards"); }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5460 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("entire"); }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5461 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("content"); }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5462 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("word"); }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5463 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("start"); }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5464 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("end"); }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5465 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("most"); }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5466 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("skip"); }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5467 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy"); }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5468 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("value"); }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5469 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eq"); }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5470 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ne"); }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5471 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lt"); }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5472 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("le"); }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5473 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("gt"); }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5474 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ge"); }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5475 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("at"); }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5476 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("context"); }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5477 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("variable"); }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5478 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("return"); }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5479 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("for"); }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5480 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("outer"); }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5481 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sliding"); }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5482 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("tumbling"); }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5483 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("previous"); }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5484 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("next"); }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5485 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("only"); }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5486 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("when"); }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5487 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("count"); }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5488 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("in"); }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5489 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("let"); }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5490 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("where"); }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5491 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("by"); }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5492 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("group"); }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5493 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("order"); }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5494 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stable"); }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5495 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ascending"); }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5496 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("descending"); }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5497 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("greatest"); }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5498 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("least"); }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5499 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("collation"); }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5500 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("some"); }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5501 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("every"); }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5502 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("satisfies"); }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5503 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("case"); }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5504 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("as"); }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5505 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("then"); }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5506 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("else"); }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5507 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("or"); }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5508 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("and"); }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5509 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("instance"); }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5510 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("of"); }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5511 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("castable"); }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5512 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("to"); }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5513 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("div"); }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5514 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("mod"); }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5515 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("union"); }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5516 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("intersect"); }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5517 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("except"); }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5518 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("validate"); }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5519 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("cast"); }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5520 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("treat"); }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5521 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("is"); }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5522 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("preserve"); }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5523 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strip"); }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5524 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("namespace"); }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5525 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("external"); }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5526 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("encoding"); }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5527 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-preserve"); }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5528 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("inherit"); }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5529 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-inherit"); }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5530 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("declare"); }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5531 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("construction"); }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5532 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordering"); }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5533 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("default"); }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5534 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy-namespaces"); }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5535 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("option"); }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 5536 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("version"); }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5537 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("import"); }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 5538 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema"); }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 5539 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("module"); }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 5540 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("function"); }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 5541 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("score"); }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 5542 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ftcontains"); }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 5543 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("weight"); }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 5544 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("window"); }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 5545 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("distance"); }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 5546 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("occurs"); }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 5547 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("times"); }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 5548 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("same"); }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 5549 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("different"); }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 5550 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lowercase"); }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 5551 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("uppercase"); }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 5552 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("relationship"); }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 5553 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("levels"); }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 5554 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("language"); }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 5555 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("any"); }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 5556 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("all"); }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 5557 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("phrase"); }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 5558 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exactly"); }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 5559 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("from"); }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 5560 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("words"); }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 5561 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentences"); }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 5562 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentence"); }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 5563 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("paragraph"); }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 5564 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("replace"); }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 5565 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("modify"); }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 5566 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("first"); }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 5567 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insert"); }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 5568 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("before"); }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 5569 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("after"); }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 5570 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("revalidation"); }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 5571 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("with"); }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 5572 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nodes"); }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 5573 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("rename"); }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 5574 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("last"); }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 5575 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("delete"); }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 5576 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("into"); }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 5577 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("simple"); }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 5578 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sequential"); }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 5579 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("updating"); }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 5580 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("deterministic"); }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 5581 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nondeterministic"); }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 5582 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordered"); }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 5583 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unordered"); }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 5584 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("returning"); }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 5585 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("block"); }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 5586 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exit"); }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 5587 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("loop"); }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 5588 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("while"); }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 5589 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("break"); }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 5590 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("continue"); }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 5591 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("try"); }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 5592 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("catch"); }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 5593 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eval"); }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 5594 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("using"); }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 5595 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("set"); }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 5596 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("index"); }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 5597 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unique"); }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 5598 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("non"); }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 5599 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("on"); }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 5600 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("manual"); }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 5601 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("automatic"); }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 5602 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("decimal-format"); }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 5603 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("decimal-separator"); }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 5604 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("grouping-separator"); }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 5605 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("infinity"); }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 5606 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("minus-sign"); }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 5607 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("NaN"); }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 5608 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("percent"); }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 5609 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("per-mille"); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 5610 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("zero-digit"); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 5611 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("digit"); }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 5612 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("pattern-separator"); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 5613 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("collection"); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 5614 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("const"); }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 5615 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("append-only"); }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 5616 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("queue"); }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 5617 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("mutable"); }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 5618 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("read-only"); }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 5619 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("checked"); }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 5620 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unchecked"); }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 5621 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("asynchronous"); }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 5622 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("synchronous"); }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 5623 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("integrity"); }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 5624 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("constraint"); }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 5625 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("check"); }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 5626 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("key"); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 5627 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("foreach"); }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 5628 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("type"); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 5629 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("foreign"); }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 5630 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("keys"); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 5642 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)),
                          (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 5648 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 5665 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(1) - (1)].node)), NULL, NULL);
		}
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 5669 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(2) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(2) - (2)].node)), NULL);
		}
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 5673 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(3) - (1)].node)), NULL, static_cast<RangeExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		}
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 5677 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(4) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(4) - (2)].node)), static_cast<RangeExpr *> ((yysemantic_stack_[(4) - (4)].expr)));
		}
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 5687 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 5690 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 5693 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 5696 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 5705 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 5708 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 5717 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 5720 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 5729 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 5732 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 5741 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 5744 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 5753 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 5756 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 5759 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 5768 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 5771 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 5780 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), static_cast<StringLiteral *> ((yysemantic_stack_[(1) - (1)].expr)), NULL);
		}
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 5784 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 5794 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 5797 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 5800 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 5803 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 5806 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 5815 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 5824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 5828 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 5832 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 5836 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 5840 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 5844 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 5848 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 5858 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 5861 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 5864 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 5867 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 5876 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 5879 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 5882 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 5885 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 5894 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 5897 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 5906 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 5909 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 5912 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 5915 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 5918 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 5921 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 5924 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 5933 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 5936 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 5945 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 5948 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 5951 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 5954 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 5963 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 5966 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 5969 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 5972 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 5975 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 5984 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 5987 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 5996 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 5999 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 6008 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 6011 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 6020 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 6023 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 6032 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 6041 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6044 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6053 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6056 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6059 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6068 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6071 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6074 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 6077 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 6080 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 6089 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 6093 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 6097 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 6101 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 6111 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 6120 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWindow (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (2)].expr)), static_cast<FTUnit *> ((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 6130 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 6139 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 6142 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 6151 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 6154 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 6157 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 6166 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6169 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6178 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTIgnoreOption (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		}
    break;



/* Line 678 of lalr1.cc  */
#line 10309 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1262;
  const short int
  xquery_parser::yypact_[] =
  {
      1484, -1262, -1262, -1262, -1262,   928,   -67,   201,   113,  8395,
     198,   299,   455, -1262, -1262, -1262, -1262, -1262, -1262,   220,
     503,  7261, -1262,   295, -1262, -1262, -1262, -1262,   368,   391,
   -1262,   367,   269,   471, -1262, -1262, -1262, -1262, -1262, -1262,
   -1262, -1262, -1262,   422,   480, -1262, -1262, -1262, -1262, -1262,
   -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262,
   -1262, -1262, -1262, -1262, -1262, -1262,  8676, -1262,  6687, -1262,
   -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262,
   -1262, -1262, 10362, -1262, -1262, -1262, -1262, -1262, -1262, -1262,
   -1262,   431, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262,
   -1262, -1262, -1262,  1774, 10362, -1262, -1262, -1262, -1262, -1262,
   -1262,   447, -1262, -1262, -1262, -1262,  7831, -1262,  8114, -1262,
   -1262, -1262, -1262, -1262, 10362, -1262, -1262,  6398, -1262, -1262,
   -1262, -1262, -1262, -1262,   493, -1262, -1262, -1262, -1262, -1262,
   -1262, -1262, -1262,    17,   442, -1262, -1262, -1262, -1262, -1262,
   -1262, -1262, -1262,   -45,   524,   446, -1262,   -89,   -87, -1262,
   -1262, -1262, -1262, -1262, -1262,   564, -1262, -1262,   539,   466,
     475, -1262,   492,   566,   579, -1262,   618, -1262, -1262, -1262,
   -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262,
   -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262,
   -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262,
   -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262,
   -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262,
   -1262, -1262, -1262, -1262, -1262, -1262, -1262,  4375,   729, -1262,
    4664, -1262, -1262,   132,  4953,   552,   553, -1262, -1262, -1262,
   -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262,
   -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262,
   -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262,   -34, -1262,
   -1262, -1262, -1262,    25, 10362, -1262, -1262, -1262, -1262, -1262,
     577,   650, -1262,   794,   485,   -26,   305,   396,   194, -1262,
     669,   551,   647,   648,  5242, -1262, -1262, -1262,   -23, -1262,
   -1262,  6398, -1262,   418, -1262,   600,  6687, -1262,   600,  6687,
   -1262, -1262, -1262, -1262,   600, -1262, -1262, -1262, -1262, -1262,
   -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262,
   -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262,
   -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262,
   -1262, -1262, -1262,   599, -1262, -1262, 10362,   713,   714,   510,
     510,   713, 10362,   320,   225,   730,   264,   366, 10362,   610,
     642,    80,  7831, -1262, -1262,   430,    63, 10362, -1262, -1262,
   -1262, -1262, 10362, -1262, -1262, -1262, -1262,   125, -1262,   462,
     341,   385, -1262, -1262,  7831, 10362,  4953,   612,   613,  4953,
   -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262,
   -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262,
   -1262,  4953,  8957, -1262, -1262, -1262, -1262, -1262, -1262, -1262,
   -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262,   614,
    4953,  4953,   582,  4953,   583,  4953,    41,    44, -1262,  4953,
    7546,   619, -1262, 10362, 10362, 10362,  4953,   496,   498, -1262,
     658,   659, 10362,    51,  4953,  9238,   629,   615,   625,   627,
     630,   631, -1262, -1262, -1262, 10362, -1262,   598,   747,  4953,
      33, -1262,   762,   603, -1262,  4953,   584, -1262,   759,  4953,
    4953,   616,  4953,  4953,  4953,  4953,   565, 10362, -1262, -1262,
    4953, -1262, -1262,  4953,  4953, 10362, -1262, -1262, -1262, -1262,
    1023,   503, -1262, -1262,   132,   763,  4953, -1262,  4953,   632,
     391,   269,   471,   677,   633,   634,  4953,  4953, -1262, -1262,
   -1262, -1262, -1262, -1262, -1262,   690, -1262,   -28,  5531,  5531,
    5531, -1262,  5531,  5531, -1262,  5531, -1262,  5531, -1262, -1262,
   -1262, -1262, -1262, -1262, -1262,  5531,  5531,    -1,  5531,  5531,
    5531,  5531,  5531,  5531,  5531,  5531,  5531,  5531,  5531,   574,
     709,   711,   712, -1262, -1262, -1262,  2063, -1262, -1262,  6398,
    6398,  4953,   600, -1262, -1262,   600, -1262,   600,  2352,   654,
   -1262, 10362, -1262, -1262, -1262, -1262,   780, -1262, -1262, -1262,
   -1262, -1262, -1262,   702,   703, -1262, -1262,   576,   373, 10362,
     429,   655,   657,   576,   730,   686,   685, -1262, -1262, -1262,
     379,     6,   397,   788, -1262, -1262,   317, -1262, -1262, -1262,
   -1262, -1262, -1262, -1262, -1262,    -3,   523, 10362, -1262,   518,
   -1262, -1262,   689,   670, -1262,   649,  4953,  4953,   639,   652,
   -1262,   164,   172,  2641,   653,   660, -1262,   661, -1262,   651,
    7831,   734,   801,  7831,   730,   746,   663,   662, -1262,   664,
    2930,    -2, -1262,   238,   704,   739, -1262,   -30,   668, -1262,
   -1262, 10362,   -24, -1262,   666,   615,   422, -1262,   671,   672,
     673, -1262,   192,   196,  3219,    48, -1262, 10362,   747, -1262,
     -49,   676, -1262, -1262, -1262, -1262,   679, -1262,    -4, -1262,
   -1262, -1262,    42,    76,   757,   626,   640,    21, -1262,   721,
    5820, -1262,   680,   684,    71, -1262, -1262,   681, -1262,   540,
   -1262, -1262,   -15,   699, 10362,  4953,   751, -1262, -1262,   752,
    9800,   753,  4953,   764,   -74,   733,   -59,   650, -1262, -1262,
   -1262, -1262, -1262,  5531, -1262, -1262, -1262,  4953,    -1,   393,
   -1262,   604,   204,   622,   623, -1262, -1262,   620,   265,   305,
     305,    -8,   396,   396,   396,   396,   194,   194, -1262, -1262,
    9800,  9800, 10362, 10362, -1262,   706, -1262, -1262,   707, -1262,
   -1262, -1262,   215,   -32,   266,   654, -1262,   292,   330, -1262,
   -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262,   576,
   -1262,   754, 10081,   749,  4953, -1262, -1262, -1262,   793,   750,
    4953,   730,   730,   576, -1262,   561,   730, -1262, -1262,   617,
   -1262, -1262,   611,   206, -1262, -1262, -1262, -1262, -1262, -1262,
     621, -1262, -1262,     9,   405,   798,  4953,     7, 10362,   730,
    4953, -1262,   715,   717,   799,   743, 10362, -1262, 10362, -1262,
   -1262,   718, -1262, -1262, -1262,   700,   772,   730,   748,   773,
     811,   730,   760, -1262, -1262, -1262,   731,   791,  4953,  4953,
     768,  4953,   795,  4953,   774,   -82, -1262,   255,   665, -1262,
   -1262,   403,   -24, -1262, -1262, -1262,   765, 10362, -1262, 10362,
   -1262, -1262,   736,  4953,   882, -1262,   -20, -1262,    35, -1262,
   -1262,   890, -1262,   444,  4953,  4953,  4953,   445,  4953,  4953,
    4953,  4953,  4953,  4953,   802,  4953,  4953,   642,    77,   741,
     539,   682,   776,   804,   763,   844, -1262,  4953, -1262,   497,
     820, -1262, 10362,   822, -1262, 10362,   777,   778, -1262,   304,
   -1262, -1262, -1262, 10362, -1262, 10362,  4953,   792,  4953,  4953,
     -18,   796, -1262,   758,   756, -1262,   692, -1262,   175, -1262,
     343,   -40,   694,    -1,   343,  5531,  5531,   451, -1262, -1262,
   -1262, -1262, -1262, -1262, -1262,    -1,   800,   -40, -1262,   675,
     895, -1262, -1262, -1262, -1262, -1262,   810, -1262, -1262, -1262,
    4953, -1262, 10362,   843,   219, -1262, -1262,  4953, -1262,   310,
   -1262, -1262, -1262, -1262, -1262,   929,   490, -1262, -1262, -1262,
    4953, -1262, -1262, -1262, -1262, -1262, -1262,   678,   -16,   931,
   -1262,   432, -1262, -1262,   625,   627,   630,   480,   631,   524,
   -1262, -1262, -1262,     9,   812,     9,   866,   146,   779,   781,
   -1262, -1262,  9519,   448, -1262,  3508,   782,   784,   821,   785,
     797, -1262,  4953,   730,   870, -1262, -1262, -1262,   730,   870,
    3797, -1262, 10362, -1262, -1262,  4953, -1262, 10362, -1262,  4953,
    4953,   838,  4953,   837, -1262,   865,   867,  4953, 10362,   628,
     915, -1262, -1262, -1262,  4086,   803,   806, -1262, -1262, -1262,
     857, -1262,    45, -1262, -1262,   976, -1262, -1262,  4953, 10362,
   -1262, -1262,   144, -1262, -1262, -1262,   814,   775,   783, -1262,
   -1262, -1262,   786,   787, -1262, -1262, -1262, -1262, -1262,   770,
   10362,   826, -1262,   862, -1262,   642, -1262, -1262, -1262,  6976,
     682, -1262,  4953, 10362,   820, -1262,   730, -1262,   570, -1262,
     352,   903, -1262,  4953,   904,   751, -1262,   829,   831, -1262,
   -1262, -1262, -1262, -1262, -1262, -1262,  4953, -1262, -1262,  4953,
     874,  4953, -1262, -1262,  5531, -1262, -1262, -1262, -1262, -1262,
     136,  5531,  5531,   351, -1262,   622, -1262, -1262,    64,  5531,
   -1262, -1262,   623,    -1,   755, -1262, -1262, -1262, -1262,   793,
    9800,   901,   926,   841, -1262, -1262, -1262, -1262, -1262,     0,
     994,   995,     0,   -54,   231,   245, -1262,   871, -1262,     9,
     -83,   723, -1262, -1262, 10362,   845,   -41, -1262, -1262,   846,
   -1262, -1262, -1262, -1262, -1262,   906,   935,   730,   870, -1262,
     852, -1262, -1262, -1262, -1262, -1262,  4953, -1262,  4953, 10362,
   10362, -1262,   438, -1262,  4953, -1262,   853, -1262, -1262,   882,
   10362,   159, -1262,   854,   882, 10362, -1262, -1262,  4953,  4953,
    4953,  4953,  4953, -1262,  4953,  4953, -1262, -1262,   244, -1262,
     856, -1262, -1262, -1262, -1262,   903, -1262, -1262, -1262,   730,
   -1262, -1262, -1262, -1262, -1262, -1262,  4953, -1262,   396,  5531,
    5531,   396,   415, -1262, -1262, -1262, -1262, -1262, -1262, -1262,
   -1262, -1262, -1262, -1262,  9800, -1262,   -16,   -16,     0, -1262,
   -1262, -1262,    27,     0,  1009,   789,   942, -1262,   942, -1262,
    4953,   249, -1262,   924, 10362,   790,   949,  4953, 10362,  4953,
   -1262,  4953,   730, -1262, -1262, -1262, -1262,   977, -1262, -1262,
   -1262, -1262,   -17,   882, 10362, -1262,   855,   882, -1262, -1262,
   -1262, -1262, -1262, -1262, -1262,   927,  6976, -1262, -1262, -1262,
   -1262, -1262,   396,   396,  5531, -1262, -1262, -1262, -1262, -1262,
   -1262,   -40, -1262,   250, -1262,   251, -1262,   495,  4953,   103,
   10362,   -79,   766,  9800, -1262,   864, -1262, -1262,   870,   932,
     155,   222, -1262,   858,   882, -1262,   860, 10362, -1262,   396,
     808,   942, -1262, -1262, -1262,   497, -1262,   406,   406,    15,
     767, -1262, -1262, -1262, -1262, -1262,   827, 10362,   832, 10362,
     875,  4953, 10362, -1262, -1262,   965,   257, -1262, -1262, -1262,
   -1262,   880,   294, -1262, -1262, -1262,   869, -1262,   253, -1262,
   -1262, -1262, -1262, -1262, -1262,    15,   769,   771,   945,   877,
    4953, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262,
     956,   910, -1262,     9,  6109, 10362,   957, -1262, 10362, -1262,
     805,   807, -1262,   809, 10362,   256,  4953,   923,  4953,   813,
     961,   910, -1262,  4953, -1262,   934, 10362, -1262,   897,  4953,
     899, -1262,   905,   910,   889, -1262,   817, 10362,   881,   971,
   10362,   815,   938,  4953,   913, -1262
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   410,   411,   592,   557,   695,   704,   683,   607,   599,
     615,   606,   597,   705,   744,   743,   745,   746,   742,   601,
     702,   603,   630,   665,   659,   700,   627,   703,   760,   654,
     696,   758,   644,   645,   646,   647,   648,   649,   650,   651,
     652,   697,   611,   605,   598,   699,   674,   604,   609,   767,
     768,   769,   770,   771,   772,   773,   774,   775,   776,   777,
     401,   404,   673,   669,   660,   640,   596,   391,     0,   668,
     676,   684,   389,   664,   427,   641,   642,   698,   390,   393,
     661,   678,     0,   433,   399,   429,   671,   595,   662,   663,
     691,   666,   682,   690,   395,   394,   614,   653,   693,   428,
     681,   686,   600,     0,     0,   348,   679,   689,   694,   692,
     672,   747,   658,   656,   657,   400,     0,   347,     0,   403,
     402,   687,   643,   667,     0,   392,   377,     0,   409,   688,
     670,   677,   685,   680,   748,   634,   639,   638,   637,   636,
     635,   608,   655,     0,   594,   701,   628,   734,   733,   735,
     613,   612,   631,   740,   602,   732,   737,   738,   729,   633,
     675,   731,   741,   739,   730,   632,   736,   749,   750,   751,
     754,   752,   755,   753,   756,   757,   759,   721,   720,   617,
     610,   619,   618,   714,   710,   625,   629,   626,   723,   724,
     707,   616,   719,   718,   715,   711,   728,   722,   717,   713,
     706,   727,   726,   712,   716,   708,   709,   620,   621,   623,
     725,   622,   624,   778,   779,   780,   781,   782,   783,   762,
     763,   761,   765,   766,   764,   784,   785,   786,   787,   788,
     789,   790,   791,   792,   793,   794,   795,     0,     0,     2,
       0,     4,     6,    12,     0,     0,     0,    18,    20,    34,
      22,    23,    24,    50,    25,    29,    30,    54,    55,    56,
      51,    52,    58,    59,    27,    26,    31,    32,    33,    53,
     207,   206,   203,   204,   205,    28,    11,   184,   185,   189,
     191,   222,   228,     0,     0,   220,   221,   192,   193,   194,
     195,   304,   306,   308,   318,   321,   323,   326,   331,   334,
     337,   339,   341,   343,     0,   345,   351,   353,     0,   369,
     352,   373,   376,   378,   381,   383,     0,   388,   385,     0,
     396,   406,   408,   382,   412,   417,   425,   418,   419,   420,
     423,   424,   421,   422,   440,   442,   443,   444,   441,   489,
     490,   491,   492,   493,   494,   405,   531,   523,   530,   529,
     528,   525,   527,   524,   526,   426,    57,   196,   197,   199,
     198,   200,   201,   407,   593,   202,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   115,   116,     0,     0,     0,   111,   112,
     113,   114,     0,   143,   144,   147,   146,     0,   109,     0,
     145,   142,   167,   170,     0,     0,     0,     0,     0,     0,
     695,   704,   683,   607,   599,   615,   606,   597,   601,   702,
     603,   665,   760,   654,   758,   644,   645,   605,   598,   596,
     666,     0,     0,   747,   748,   594,   740,   602,   732,   738,
     729,   632,   750,   751,   754,   755,   753,   756,   759,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   590,     0,
       0,     0,   591,     0,     0,     0,     0,     0,     0,   230,
       0,     0,     0,     0,     0,     0,     0,   599,   606,   597,
     603,   596,   397,   407,   430,     0,   431,     0,   456,     0,
       0,   372,     0,     0,   375,     0,     0,   485,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   157,   154,
       0,   165,   166,     0,     0,     0,     3,     1,     5,     7,
     142,     0,    13,    10,    15,    16,     0,   187,   186,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   208,   227,
     223,   229,   224,   226,   225,   232,   233,     0,     0,     0,
       0,   362,     0,     0,   360,     0,   313,     0,   361,   354,
     359,   358,   357,   356,   355,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   350,   349,   346,     0,   370,   374,     0,
       0,     0,   384,   414,   387,   386,   398,   413,     0,     0,
     172,     0,   173,   169,   168,   171,     0,   148,   149,    67,
      68,   589,    76,     0,     0,    61,    62,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   558,   559,   560,
       0,     0,     0,     0,   834,   835,     0,    66,   827,   828,
     829,   830,   831,   832,   833,   101,     0,     0,   110,     0,
     140,   141,     0,     0,   555,     0,     0,     0,     0,     0,
     547,     0,     0,     0,     0,     0,   536,     0,   537,     0,
       0,    85,     0,     0,     0,    77,     0,     0,   538,     0,
       0,     0,   293,     0,     0,   245,   246,     0,     0,   210,
     211,     0,     0,   231,     0,     0,     0,   533,     0,     0,
       0,   541,     0,     0,     0,     0,   432,   457,   456,   453,
       0,     0,   487,   486,   371,   546,     0,   484,     0,   571,
     572,   532,     0,     0,     0,     0,     0,     0,   577,     0,
       0,   163,     0,     0,     0,   248,   265,     0,    19,   142,
      21,   190,     0,     0,     0,     0,     0,   209,   266,     0,
       0,     0,     0,     0,     0,     0,     0,   305,   307,   311,
     317,   316,   315,     0,   312,   309,   310,     0,     0,     0,
     819,   319,   798,   806,   808,   810,   812,   814,   817,   325,
     324,   322,   328,   329,   330,   327,   332,   333,   336,   335,
       0,     0,     0,     0,   367,     0,   379,   380,     0,   415,
     436,   438,     0,     0,     0,     0,    65,     0,     0,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    36,
      37,     0,     0,    93,     0,    89,    91,    92,    96,    99,
       0,     0,     0,    35,    75,     0,     0,   836,   837,     0,
     838,   842,     0,     0,   871,   840,   841,   870,   839,   843,
       0,   850,   872,     0,     0,   102,     0,   105,     0,     0,
       0,   363,     0,     0,     0,     0,     0,   551,     0,   548,
     496,     0,   495,   504,   505,     0,     0,     0,     0,     0,
      78,     0,     0,   540,   539,   506,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   797,     0,     0,   212,
     213,     0,   218,   554,   534,   535,     0,     0,   544,     0,
     542,   500,     0,     0,   456,   454,     0,   445,     0,   434,
     435,     0,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   695,     0,     0,
       0,     0,     0,     0,    17,     0,   188,     0,   219,   277,
     273,   275,     0,   267,   268,     0,   600,   608,   512,   513,
     519,   520,   522,     0,   235,     0,     0,     0,     0,     0,
       0,     0,   314,     0,     0,   813,     0,   320,     0,   826,
       0,     0,     0,     0,     0,     0,     0,   799,   803,   821,
     802,   825,   823,   822,   824,     0,     0,     0,   815,   878,
     876,   880,   818,   338,   340,   342,   510,   344,   368,   416,
       0,   437,     0,   150,     0,   178,   175,     0,   174,     0,
      73,    74,    71,    72,    38,     0,     0,    94,    95,    97,
       0,    98,    63,    64,    69,    70,    60,     0,     0,     0,
     845,     0,   844,   861,     0,     0,     0,     0,     0,     0,
     103,   118,   117,     0,     0,     0,   106,     0,     0,     0,
     365,   364,     0,     0,   299,     0,     0,     0,   555,     0,
       0,   497,     0,     0,    87,    81,    84,    83,     0,    79,
       0,   507,     0,   291,   295,     0,   162,     0,   250,     0,
       0,     0,     0,     0,   214,     0,     0,     0,     0,   259,
       0,   256,   261,   217,     0,     0,     0,   501,   292,   457,
       0,   446,     0,   480,   477,     0,   481,   482,     0,     0,
     483,   476,     0,   451,   479,   478,     0,     0,     0,   564,
     565,   561,     0,     0,   569,   570,   566,   575,   573,     0,
       0,     0,   579,   160,   159,     0,   156,   155,   164,     0,
     580,   581,     0,     0,   274,   286,     0,   287,     0,   278,
     279,   280,   281,     0,   270,     0,   234,     0,     0,   516,
     518,   517,   514,   243,   244,   237,     0,   239,   236,     0,
       0,     0,   820,   816,     0,   873,   874,   894,   893,   889,
       0,     0,     0,     0,   875,   807,   888,   800,     0,     0,
     805,   804,   809,     0,     0,   879,   877,   511,   439,   180,
       0,     0,   151,     0,   177,   176,    39,    90,   100,   859,
       0,     0,   857,   853,     0,     0,   104,     0,   107,     0,
       0,     0,    14,   366,     0,     0,     0,   300,   498,     0,
     552,   553,   556,   549,   550,     0,    86,     0,    80,   508,
       0,   294,   296,   247,   252,   251,     0,   254,     0,     0,
       0,   216,   257,   260,     0,   502,     0,   545,   543,   456,
       0,     0,   488,     0,   456,     0,   452,     9,     0,     0,
       0,     0,     0,   578,     0,     0,   158,   587,     0,   582,
       0,   249,   290,   288,   289,   282,   283,   284,   276,     0,
     271,   269,   521,   515,   241,   238,     0,   240,   895,     0,
       0,   881,     0,   892,   891,   890,   885,   886,   801,   811,
     887,   181,   152,   179,     0,   183,     0,     0,   860,   862,
     864,   866,     0,   858,     0,     0,     0,   848,     0,   846,
       0,     0,   108,     0,     0,     0,     0,     0,     0,     0,
     499,     0,     0,    82,   509,   253,   255,   264,   263,   258,
     215,   503,     0,   456,     0,   182,     0,   456,   562,   563,
     567,   568,   574,   576,   161,     0,     0,   583,   796,   285,
     272,   242,   883,   882,     0,   153,   869,   868,   863,   867,
     865,   854,   855,     0,   851,     0,   129,   131,     0,   126,
       0,     0,     0,     0,   301,     0,   297,   303,    88,     0,
     466,   460,   455,     0,   456,   447,     0,     0,   588,   884,
       0,     0,   849,   847,   132,   133,   130,   126,   126,   126,
       0,   127,   128,   119,   120,   123,     0,     0,     0,     0,
       0,     0,     0,   474,   468,     0,   467,   469,   475,   472,
     462,     0,   461,   463,   473,   449,     0,   448,     0,   856,
     852,   134,   124,   125,   121,   126,     0,     0,     0,     0,
       0,   298,   262,   459,   470,   471,   458,   464,   465,   450,
       0,     0,   122,     0,     0,     0,     0,   302,     0,   584,
       0,   762,   135,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,     0,   137,     0,     0,   585,     0,     0,
       0,   136,     0,     0,     0,   586,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   139
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1262, -1262,   859, -1262,   863,   868, -1262,   861, -1262,   573,
     575,  -509, -1262,   477,  -271, -1262, -1262, -1262, -1262, -1262,
   -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262,  -864,
   -1262, -1262, -1262, -1262,    79,   283,   727, -1262, -1262, -1262,
     719,   252, -1262, -1262, -1198,  -728, -1262,  -286, -1262, -1262,
     716,   720, -1262,   309, -1262,  -885, -1262, -1262,   -22, -1262,
   -1262, -1262, -1262, -1262,   332,   197, -1262, -1262,   -96, -1262,
   -1261,   878,   -97, -1262,   591,  -414, -1262, -1262, -1262, -1262,
     223, -1262, -1262,   847, -1262, -1262, -1262, -1262, -1262,   166,
    -521,  -662, -1262, -1262, -1262,    46, -1262, -1262,  -138,    30,
     -21, -1262, -1262, -1262,   -31, -1262, -1262,   188,   -27, -1109,
   -1262,   -19, -1094, -1262,   667,    56, -1262, -1262,    82, -1262,
   -1262,   594,   590, -1262,  -520,  -957,   578,   135,  -564,   133,
     147, -1262, -1262, -1262, -1262, -1262,   839, -1262, -1262, -1262,
   -1262, -1262,   842, -1262, -1262,  -107, -1262, -1262, -1262, -1262,
   -1262, -1262, -1262,   -50, -1128, -1262, -1262,   239,    37, -1262,
    -556, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262, -1262,
    -895, -1262,    34, -1262,   439,  -704, -1262, -1262, -1262, -1262,
   -1262,  -303,  -295, -1073,  -918, -1262, -1262, -1262, -1262, -1262,
   -1262, -1262, -1262, -1262, -1262,   360,  -682,  -777, -1262,   333,
     -66,  -687, -1262, -1262, -1262, -1262, -1262, -1262, -1262,   683,
     687,  -336,   286,   134, -1262, -1262, -1262, -1262, -1262, -1262,
   -1262,    18, -1262, -1262,    11, -1262,  -351,  -101,    -9, -1262,
   -1262,   389, -1262, -1262,   179,   168,   -39,   398, -1262, -1262,
     178, -1262,  -750, -1262, -1262, -1262, -1262,  -172,  -841, -1262,
     -53,  -613, -1262,  -709, -1262, -1262, -1262, -1262,  -994, -1262,
   -1262, -1262, -1262,   -25,   186, -1262
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   819,   820,   821,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,  1074,
     674,   263,   264,   825,   826,   827,  1143,   265,   266,   397,
     398,   855,   267,  1433,  1434,  1435,  1341,  1396,   268,   399,
     400,   401,   269,   804,   270,   509,   730,   938,  1144,   271,
     272,   273,   274,   275,   402,   403,   602,  1014,  1015,  1120,
    1018,   276,   277,   528,   278,   279,   280,   538,   470,   901,
     902,   281,   539,   282,   541,   283,   284,   285,   545,   546,
    1099,   755,   286,   685,   734,   686,   692,  1100,  1101,  1102,
     735,   542,   543,   953,   954,  1300,   544,   950,   951,  1159,
    1160,  1161,  1162,   287,   681,   682,   288,  1063,  1064,   289,
     290,   291,   292,   763,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   565,   566,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   592,   593,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   802,   333,
     334,   335,  1122,   708,   709,   710,  1412,  1451,  1452,  1445,
    1446,  1453,  1447,  1123,  1124,   336,   337,  1125,   338,   339,
     340,   341,   342,   343,   344,  1005,   756,   958,  1172,   959,
     960,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   653,  1067,   355,   356,   357,   358,   359,   360,   361,
     727,   728,   362,  1150,  1151,  1288,  1075,   461,   363,   364,
     365,   771,   987,   772,   773,   774,   775,   776,   777,   778,
     988,   989,   637,   638,   639,   640,   641,  1393,  1394,   642,
    1328,  1222,  1332,  1329,   643,   644,   991,  1002,  1193,   992,
     993,   998,   994,  1316,  1189,   977
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int xquery_parser::yytable_ninf_ = -143;
  const short int
  xquery_parser::yytable_[] =
  {
       449,   890,  1042,  1204,   916,   895,   487,   782,   783,   784,
     785,   770,   462,  1003,  1004,   490,   740,  1079,   482,     4,
     494,  1287,   990,  1121,   612,   894,   754,  1377,  1197,   751,
     759,  1437,   760,   761,  1190,   762,   898,   764,   496,   695,
     712,  1044,  1045,  1113,  1114,   765,   766,  1389,  1190,  1276,
    1090,  1046,   688,  1113,  1114,  1148,   750,   476,   750,   483,
     751,   611,   966,   961,   611,   526,  1296,  1297,  1410,  1348,
     529,   917,  1220,   484,   696,  1047,   530,   969,  1012,   531,
     532,   695,   404,   853,   526,   719,   720,   533,   722,   723,
     724,   725,   967,  1055,   971,   488,   731,   887,  1048,   732,
    1111,    74,   893,   961,   961,   671,   675,   462,   752,   492,
     621,   839,   741,    85,   622,   493,   696,   921,  1179,   586,
     934,   568,   747,   748,   942,   504,  1326,   505,   923,  1221,
    1115,  1343,   506,  1349,  1215,   961,   918,    99,   569,   568,
    1115,   767,   118,  1013,   768,   527,  1029,   887,  1116,   672,
    1117,   623,  1113,  1114,  1411,   630,   569,   520,  1116,  1443,
    1117,   570,   927,  1113,   946,  1112,  1050,  1113,  1114,   499,
     943,   500,  1427,   521,   888,   922,  1145,  1118,   624,  1309,
     753,   104,   899,   534,   801,   535,   124,  1118,   753,  1327,
     670,   104,  1344,   673,  1191,  1192,   713,   116,  1276,   536,
    1225,  1379,  1390,   753,   588,  1428,  1334,   116,  1191,  1192,
    1110,   854,   770,   770,  1248,  1093,  1438,  1121,  1119,   497,
    1489,   854,   900,  1049,   913,   537,   697,  1121,  1270,  1335,
    1113,  1464,   753,  1091,   753,   970,   143,  1201,   625,  1115,
    1507,  1449,  1318,   972,   753,   935,   143,   840,  1418,   924,
     925,   769,  1515,   575,  1115,  1310,  1146,  1116,   409,  1117,
    1427,  1443,   576,   866,   926,  1113,   594,  1482,  1116,   596,
    1117,   868,  1116,   834,  1117,   547,   841,   842,  1444,   843,
     844,   626,   383,   928,   929,  1235,  1118,   405,  1424,   631,
     104,   907,   978,  1428,  1039,   909,   630,  1118,   930,  1431,
    1432,  1118,  1113,   652,   632,   104,   116,   483,  1180,   655,
     483,  1040,   658,  1449,  1010,   384,  1461,   633,  1211,   634,
     577,   116,  1313,   880,   750,   467,   468,  1275,  1314,   635,
    1336,   949,   636,   578,   659,  1116,  1315,  1117,   964,   867,
     450,   750,  1364,   406,  1338,   143,  1450,   869,  1398,  1421,
    1421,  1041,  1480,   664,   665,  1500,   667,   599,   669,   679,
     143,   979,   676,   606,  1118,   455,  1226,   908,  1228,   617,
    1116,   910,  1117,   462,   889,   961,  1121,   700,   645,   469,
    1474,  1185,   609,   646,  1429,  1430,  1017,  1431,  1432,  1375,
    1011,  1092,   711,  1016,  1212,   462,   654,  1420,   716,  1118,
     647,   388,   389,   390,   391,   463,  1337,  1116,  1017,  1117,
    1028,   407,   408,     4,   571,   610,  1031,   733,  1477,   613,
    1339,  1186,  1198,   662,  1399,  1422,  1423,   770,  1481,  1020,
     631,  1501,  1230,  1322,   614,   740,  1118,  1214,  1169,   770,
     572,   451,  1376,  1231,   452,   632,  1021,   980,   981,   982,
    1156,   462,   508,   573,   683,   684,   687,   983,   633,   822,
     634,  1095,  1096,   694,  1097,   984,   703,  1022,  1170,  1158,
     635,   985,   986,   636,  1083,  1084,   683,  1086,   464,  1088,
    1032,  1033,   796,   797,  1023,  1036,  1171,   574,  1408,   795,
     607,   751,  1448,  1454,   798,    74,  1095,  1096,   729,  1108,
     823,   465,   999,  1000,   608,   824,   736,    85,  1058,   466,
    1129,  1130,  1131,  1098,  1134,  1135,  1136,  1137,  1138,  1139,
    1039,  1141,  1142,   961,  1001,   471,   751,  1321,  1448,   456,
    1066,    99,  1069,   949,  1454,   767,   615,  1224,   768,   978,
    1062,   485,  1342,   630,   366,   367,   368,  1385,  1024,   371,
     616,   457,  1175,  1236,  1177,  1178,   829,   595,   848,   862,
     863,   830,  1024,   597,   600,  1362,   871,   472,   605,   876,
    1366,  1105,   879,  1106,   366,   367,   368,   369,   370,   371,
    1460,   750,  1155,   886,  1155,   575,   372,   849,   850,   489,
     851,   852,   805,  1156,   576,  1156,  1208,   453,   589,   590,
     454,  1187,  1384,  1157,   575,  1157,  1188,   912,   979,  1313,
     828,   378,  1158,   576,  1158,  1314,  1218,   823,   837,  1388,
    1308,   838,   824,  1315,  1388,   473,  1440,  1311,  1312,   799,
     395,   396,   799,   939,   799,   495,   845,   961,   857,   846,
     627,   628,   629,   379,   380,   945,   498,   770,   809,   810,
     811,   812,   813,   814,   815,   816,   817,   818,  1245,  1413,
     502,   462,   503,  1416,   462,  1127,  1132,  1128,  1133,   501,
     973,  1252,   393,   394,   507,  1254,  1255,   631,  1257,  1034,
    1035,   508,   897,  1261,  1051,  1052,  1095,  1096,  1293,  1294,
    1431,  1432,   632,   510,   980,   981,   982,   383,   914,  1462,
    1463,   603,   604,   779,   780,   633,   511,   634,   786,   787,
    1456,   513,   984,  1386,  1387,  1425,   961,   635,  1199,   986,
     636,   514,  1246,   512,   788,   789,  1006,  1006,   515,   517,
     384,   524,   525,   548,   549,   948,   567,   579,  1290,   580,
     581,   962,   582,   591,   598,  1382,  1383,   366,   601,   949,
     611,   618,   619,   649,   656,   657,   663,   666,   668,  1054,
     432,   680,  1304,  1059,   689,  1305,   690,  1307,   691,   693,
     452,   704,   454,   706,   707,   460,   475,   714,   715,   718,
     386,   962,   962,   962,   962,   726,   717,   744,   739,   749,
     743,   721,   745,   746,   790,   791,  1490,   792,   793,   803,
     806,   807,   808,   835,   831,  1292,   832,   836,   847,   856,
     858,   859,   860,   962,   864,   387,   388,   389,   390,   391,
    1419,   861,   877,   392,   865,   872,   875,   393,   394,   395,
     396,   878,   873,   874,   881,   882,   891,   883,   892,   884,
     896,   903,  1355,   931,  1356,   906,   904,   905,   919,  1057,
    1360,   920,   932,   936,   933,   940,   941,  1068,   947,  1068,
     944,   952,   955,   963,  1368,  1369,  1370,  1371,  1372,   968,
    1373,  1374,   995,   976,   965,   996,  1025,   997,  1008,   750,
    1009,   824,  1030,  1038,  1053,  1065,  1072,  1060,  1037,  1061,
    1071,  1062,  1381,  1043,  1073,  1077,  1353,  1076,   654,  1078,
     654,  1082,  1080,  1081,  1085,  1087,  1089,  1104,  1107,  1109,
    1126,  1094,  1140,  1147,  1153,   623,   550,  1149,  1152,  1163,
    1213,  1165,  1167,  1168,   551,   552,  1397,   553,  1176,  1210,
    1182,  1183,  1181,  1404,   554,  1406,  1203,  1407,   555,  1184,
     556,  1194,  1206,  1164,  1207,   557,   547,  1205,  1380,     4,
    1219,  1223,  1229,  1233,  1173,  1242,  1174,  1240,  1232,  1241,
    1243,   558,   366,   367,   368,   369,   370,   371,  1239,  1247,
    1256,  1227,  1244,  1258,   372,  1259,  1264,  1260,  1267,  1269,
     373,  1268,  1272,  1250,  1397,   559,   560,   561,   562,   563,
     564,   374,   375,  1277,  1285,   376,  1282,  1278,   377,   378,
    1284,  1156,  1299,  1209,  1302,  1279,  1303,  1266,  1280,  1281,
    1306,  1012,  1324,  1325,  1330,  1331,  1340,  1345,  1350,  1347,
    1320,  1273,  1351,  1352,  1354,  1361,  1365,  1471,  1378,  1391,
    1039,   379,   380,   381,  1400,  1403,  1409,  1417,  1441,  1402,
    1415,  1439,  1442,  1455,  1392,  1457,  1468,  1466,  1465,  1470,
    1473,  1476,  1017,   962,  1479,  1485,  1487,   366,   367,   368,
     369,   370,   371,  1459,  1484,  1483,  1488,  1494,  1503,   372,
    1492,  1506,  1511,   683,  1513,   373,  1516,   382,   687,  1509,
    1514,  1520,  1502,  1523,  1504,   383,   374,   375,  1525,  1262,
     376,  1486,  1517,   377,   378,  1519,   516,   737,  1496,   738,
     833,  1497,  1498,   518,   522,  1217,  1027,   620,   519,  1056,
    1274,  1505,  1426,  1522,  1019,  1323,   648,   651,   384,   742,
     650,  1166,   523,  1286,  1359,  1103,   379,   380,   381,  1263,
     540,   729,  1291,  1253,  1301,  1154,  1298,   385,  1251,   758,
     483,  1295,   757,   585,   736,  1237,  1271,   915,   781,  1478,
     587,  1475,   705,  1007,  1070,  1026,   698,   974,  1283,  1216,
     699,  1289,  1195,  1202,  1319,  1200,  1395,   975,   386,  1333,
    1196,     0,   382,  1317,     0,     0,     0,     0,     0,     0,
     383,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   962,     0,   387,   388,   389,   390,   391,     0,     0,
       0,   392,     0,   384,     0,   393,   394,   395,   396,  -142,
       0,     0,     0,     0,     0,  1346,     0,     0,     0,     0,
       0,     0,   385,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1357,  1358,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1363,     0,   386,     0,     0,  1367,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   387,   388,
     389,   390,   391,     0,     0,     0,   392,     0,     0,     0,
     393,   394,   395,   396,     0,   962,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1401,     0,     0,     0,  1405,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1414,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   483,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1436,     0,     0,   962,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1508,     0,  1458,     0,
       0,     0,  1512,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1524,     0,  1467,     0,
    1469,     0,     0,  1472,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1493,     0,     0,  1495,
       0,     0,     0,     0,     0,  1499,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     0,  1510,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,  1518,     5,
       6,  1521,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
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
       0,     0,   119,   120,   121,     0,     0,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   144,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,   410,
     411,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,   419,    21,    22,    23,    24,
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
       0,     0,   119,   120,   121,     0,     0,     0,   122,   486,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   435,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,   410,   411,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,   419,    21,    22,    23,    24,    25,
      26,    27,     0,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,     0,
      72,    73,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,    85,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,    91,    92,
      93,    94,    95,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,     0,     0,     0,   103,   104,
     105,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     0,   117,   118,     0,
       0,   119,   120,   121,     0,   794,     0,   122,     0,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   435,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,   410,   411,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,   419,    21,    22,    23,    24,    25,    26,
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
     119,   120,   121,     0,     0,     0,   122,   800,   123,   124,
     125,     0,   126,   127,   128,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   435,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,   410,   411,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,   419,    21,    22,    23,    24,    25,    26,    27,
       0,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,     0,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,     0,    72,    73,
       0,     0,     0,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,     0,    85,     0,    86,    87,    88,
      89,     0,    90,     0,     0,     0,    91,    92,    93,    94,
      95,     0,     0,     0,     0,     0,    96,    97,    98,    99,
     100,   101,   102,     0,     0,     0,   103,   104,   105,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   111,   112,
     113,   114,   115,   116,     0,   117,   118,     0,     0,   119,
     120,   121,     0,   870,     0,   122,     0,   123,   124,   125,
       0,   126,   127,   128,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   435,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,   410,   411,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,   419,    21,    22,    23,    24,    25,    26,    27,     0,
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
     121,     0,   885,     0,   122,     0,   123,   124,   125,     0,
     126,   127,   128,     0,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,   143,     0,   435,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,   410,   411,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
     419,    21,    22,    23,    24,    25,    26,    27,     0,    28,
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
       0,   911,     0,   122,     0,   123,   124,   125,     0,   126,
     127,   128,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   435,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,     0,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,   410,   411,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,   419,
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
    1238,     0,   122,     0,   123,   124,   125,     0,   126,   127,
     128,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   435,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,   410,   411,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,   419,    21,
      22,    23,    24,    25,    26,    27,     0,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,     0,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,     0,    72,    73,     0,     0,     0,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
       0,    85,     0,    86,    87,    88,    89,     0,    90,     0,
       0,     0,    91,    92,    93,    94,    95,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,   103,   104,   105,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,   117,   118,     0,     0,   119,   120,   121,     0,  1249,
       0,   122,     0,   123,   124,   125,     0,   126,   127,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     435,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
       0,   410,   411,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,   419,    21,    22,
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
     117,   118,     0,     0,   119,   120,   121,     0,  1265,     0,
     122,     0,   123,   124,   125,     0,   126,   127,   128,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   435,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
       5,     6,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,     0,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,     0,    72,    73,     0,     0,     0,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,     0,    85,
       0,    86,    87,    88,    89,     0,    90,     0,     0,     0,
      91,    92,    93,    94,    95,     0,     0,     0,     0,     0,
      96,    97,    98,    99,   100,   101,   102,     0,     0,     0,
     103,   104,   105,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   111,   112,   113,   114,   115,   116,     0,   117,
     118,     0,     0,   119,   120,   121,     0,     0,     0,   122,
       0,   123,   124,   125,     0,   126,   127,   128,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,   143,     0,   144,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,     0,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,     5,
       6,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
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
       0,     0,   119,   120,   121,     0,     0,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   435,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,   410,   411,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,   419,    21,    22,    23,    24,    25,
      26,    27,     0,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,     0,
      72,    73,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,    85,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,    91,    92,
      93,    94,    95,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,     0,     0,     0,   103,   104,
     105,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     0,   117,   118,     0,
       0,   119,   120,   121,     0,     0,     0,   122,     0,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   435,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,   410,   411,     0,
       7,   413,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,   418,   419,    21,    22,   421,    24,    25,    26,
      27,     0,   422,   423,    30,   424,   425,   426,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,     0,    72,
      73,     0,     0,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,    85,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   430,    92,    93,
      94,    95,     0,     0,     0,     0,     0,    96,    97,    98,
      99,   100,   101,   102,     0,     0,     0,   103,   104,   583,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   111,
     112,   113,   114,   115,   116,     0,   584,   118,     0,     0,
     119,   120,   121,     0,     0,     0,   122,     0,   123,   124,
     125,     0,   126,   127,   128,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   435,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   436,   154,   438,   156,   439,
     440,   159,   160,   161,   162,   163,   164,   441,   166,   167,
     442,   443,   444,   171,   445,   446,   447,   175,   448,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,   410,   411,     0,     7,
     413,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,   418,   419,    21,    22,   421,    24,    25,    26,    27,
       0,   422,   423,    30,   424,   425,   426,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,     0,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,     0,    72,    73,
       0,     0,     0,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,     0,    85,     0,    86,    87,    88,
      89,     0,    90,     0,     0,     0,   430,    92,    93,    94,
      95,     0,     0,     0,     0,     0,    96,    97,    98,    99,
     100,   101,   102,     0,     0,     0,   103,   104,   105,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   111,   112,
     113,   114,   115,   116,     0,   117,   118,     0,     0,   119,
     120,   121,     0,     0,     0,   122,     0,   123,   124,   125,
       0,   126,   127,   128,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   435,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   436,   154,   438,   156,   439,   440,
     159,   160,   161,   162,   163,   164,   441,   166,   167,   442,
     443,   444,   171,   445,   446,   447,   175,   448,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,   937,   411,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,   419,    21,    22,    23,    24,    25,    26,    27,     0,
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
     142,   143,     0,   435,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,   410,   411,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
     419,    21,    22,    23,    24,    25,    26,    27,     0,    28,
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
     143,     0,   435,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,     0,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
    1491,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,   410,   411,     0,   412,   413,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,   418,   419,
      21,    22,   421,    24,    25,    26,    27,     0,   422,   423,
      30,   424,   425,   426,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,     0,    72,    73,     0,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,     0,    85,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,   430,    92,    93,    94,    95,     0,     0,
       0,     0,     0,    96,    97,    98,    99,   100,   101,   102,
       0,     0,     0,   103,   104,     0,   106,   107,     0,     0,
       0,     0,   108,   109,   110,   111,   112,   113,   114,   115,
     116,     0,     0,     0,     0,     0,   119,   120,   121,     0,
       0,     0,   122,     0,   123,   124,   125,     0,     0,     0,
     128,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   435,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   436,   154,   438,   156,   439,   440,   159,   160,   161,
     162,   163,   164,   441,   166,   167,   442,   443,   444,   171,
     445,   446,   447,   175,   448,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     0,     0,     0,
       0,     0,   410,   411,     0,   412,   413,   477,   415,   478,
     479,    13,    14,    15,    16,    17,    18,   418,   419,   480,
      22,   421,    24,    25,    26,    27,     0,   422,   423,    30,
     424,   425,   426,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,     0,
       0,    62,     0,    63,    64,    65,   481,     0,     0,    69,
      70,    71,     0,     0,     0,    73,     0,     0,     0,     0,
      75,    76,    77,     0,     0,    80,    81,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,     0,    90,     0,
       0,     0,   430,    92,    93,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,     0,   100,   101,   102,     0,
       0,     0,     0,     0,     0,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   433,   112,   113,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,     0,
       0,   122,     0,   123,   124,     0,     0,     0,     0,   128,
       0,   129,     0,   130,   131,   132,   133,   434,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,     0,     0,
     435,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     436,   154,   438,   156,   439,   440,   159,   160,   161,   162,
     163,   164,   441,   166,   167,   442,   443,   444,   171,   445,
     446,   447,   175,   448,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     0,     0,     0,     0,
       0,   410,   411,     0,   412,   413,   414,   415,   416,   417,
      13,    14,    15,    16,    17,    18,   418,   419,   420,    22,
     421,    24,    25,    26,    27,     0,   422,   423,    30,   424,
     425,   426,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   427,   428,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   429,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   430,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   102,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   433,   112,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,     0,     0,     0,     0,     0,   128,     0,
     129,     0,   130,   131,   132,   133,   434,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   435,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   436,
     437,   438,   156,   439,   440,   159,   160,   161,   162,   163,
     164,   441,   166,   167,   442,   443,   444,   171,   445,   446,
     447,   175,   448,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   458,     0,     0,     0,     3,
       0,     0,     0,     0,     0,     0,   410,   411,     0,   412,
     413,   414,   415,   416,   417,    13,    14,    15,    16,    17,
      18,   418,   419,   420,    22,   421,    24,    25,    26,    27,
       0,   422,   423,    30,   424,   425,   426,    34,    35,    36,
      37,    38,    39,    40,    41,    42,   427,   428,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,     0,    62,     0,    63,    64,    65,
     429,     0,     0,    69,    70,    71,     0,     0,     0,    73,
       0,     0,     0,     0,    75,    76,    77,     0,     0,    80,
      81,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,     0,    90,     0,     0,     0,   430,    92,    93,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    98,     0,
     100,   101,   102,   459,     0,     0,   460,     0,     0,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   433,   112,
     113,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,     0,     0,     0,   122,     0,   123,     0,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   434,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,     0,     0,   435,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   436,   437,   438,   156,   439,   440,
     159,   160,   161,   162,   163,   164,   441,   166,   167,   442,
     443,   444,   171,   445,   446,   447,   175,   448,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     458,     0,     0,     0,     3,     0,   677,     0,     0,     0,
       0,   410,   411,     0,   412,   413,   414,   415,   416,   417,
      13,    14,    15,    16,    17,    18,   418,   419,   420,    22,
     421,    24,    25,    26,    27,     0,   422,   423,    30,   424,
     425,   426,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   427,   428,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   429,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   430,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   102,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   433,   112,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,   678,   123,     0,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   434,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   435,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   436,
     437,   438,   156,   439,   440,   159,   160,   161,   162,   163,
     164,   441,   166,   167,   442,   443,   444,   171,   445,   446,
     447,   175,   448,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   458,     0,     0,     0,     3,
       0,     0,     0,     0,     0,     0,   410,   411,     0,   412,
     413,   414,   415,   416,   417,    13,    14,    15,    16,    17,
      18,   418,   419,   420,    22,   421,    24,    25,    26,    27,
       0,   422,   423,    30,   424,   425,   426,    34,    35,    36,
      37,    38,    39,    40,    41,    42,   427,   428,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,     0,    62,     0,    63,    64,    65,
     429,     0,     0,    69,    70,    71,     0,     0,     0,    73,
       0,     0,     0,     0,    75,    76,    77,     0,     0,    80,
      81,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,     0,    90,     0,     0,     0,   430,    92,    93,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    98,     0,
     100,   101,   102,     0,     0,     0,     0,     0,     0,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   433,   112,
     113,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,     0,     0,     0,   122,     0,   123,     0,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   434,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,     0,     0,   435,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   436,   437,   438,   156,   439,   440,
     159,   160,   161,   162,   163,   164,   441,   166,   167,   442,
     443,   444,   171,   445,   446,   447,   175,   448,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     491,     0,     3,     0,     0,     0,     0,     0,     0,   410,
     411,     0,   412,   413,   414,   415,   416,   417,    13,    14,
      15,    16,    17,    18,   418,   419,   420,    22,   421,    24,
      25,    26,    27,     0,   422,   423,    30,   424,   425,   426,
      34,    35,    36,    37,    38,    39,    40,    41,    42,   427,
     428,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    62,     0,
      63,    64,    65,   429,     0,     0,    69,    70,    71,     0,
       0,     0,    73,     0,     0,     0,     0,    75,    76,    77,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,   430,
      92,    93,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,     0,   100,   101,   102,     0,     0,     0,     0,
       0,     0,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   433,   112,   113,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,   122,     0,
     123,     0,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   434,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,     0,     0,   435,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   436,   437,   438,
     156,   439,   440,   159,   160,   161,   162,   163,   164,   441,
     166,   167,   442,   443,   444,   171,   445,   446,   447,   175,
     448,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     3,     0,     0,     0,     0,     0,     0,
     410,   411,     0,   412,   413,   414,   415,   416,   417,    13,
      14,    15,    16,    17,    18,   418,   419,   420,    22,   421,
      24,    25,    26,    27,     0,   422,   423,    30,   424,   425,
     426,    34,    35,    36,    37,    38,    39,    40,    41,    42,
     427,   428,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,     0,     0,    62,
       0,    63,    64,    65,   429,     0,     0,    69,    70,    71,
       0,     0,     0,    73,     0,     0,     0,     0,    75,    76,
      77,     0,     0,    80,    81,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,     0,    90,     0,     0,     0,
     430,    92,    93,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,     0,   100,   101,   102,   431,     0,     0,
     432,     0,     0,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   433,   112,   113,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,     0,     0,     0,   122,
       0,   123,     0,     0,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   434,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,     0,     0,   435,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   436,   437,
     438,   156,   439,   440,   159,   160,   161,   162,   163,   164,
     441,   166,   167,   442,   443,   444,   171,   445,   446,   447,
     175,   448,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,     0,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,     3,     0,     0,     0,     0,     0,
       0,   410,   411,     0,   412,   413,   414,   415,   416,   417,
      13,    14,    15,    16,    17,    18,   418,   419,   420,    22,
     421,    24,    25,    26,    27,     0,   422,   423,    30,   424,
     425,   426,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   427,   428,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   429,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   430,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   102,   474,     0,
       0,   475,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   433,   112,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,     0,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   434,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   435,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   436,
     437,   438,   156,   439,   440,   159,   160,   161,   162,   163,
     164,   441,   166,   167,   442,   443,   444,   171,   445,   446,
     447,   175,   448,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     3,     0,     0,     0,     0,
       0,     0,   410,   411,     0,   412,   413,   414,   415,   416,
     417,    13,    14,    15,    16,    17,    18,   418,   419,   420,
      22,   421,    24,    25,    26,    27,     0,   422,   423,    30,
     424,   425,   426,    34,    35,    36,    37,    38,    39,    40,
      41,    42,   427,   428,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,     0,
       0,    62,     0,    63,    64,    65,   429,     0,     0,    69,
      70,    71,     0,     0,     0,    73,     0,     0,     0,     0,
      75,    76,    77,     0,     0,    80,    81,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,     0,    90,     0,
       0,     0,   430,    92,    93,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,     0,   100,   101,   102,     0,
       0,     0,     0,     0,     0,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   433,   112,   113,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,     0,
       0,   122,   660,   123,     0,     0,     0,     0,     0,   661,
       0,   129,     0,   130,   131,   132,   133,   434,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,     0,     0,
     435,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     436,   437,   438,   156,   439,   440,   159,   160,   161,   162,
     163,   164,   441,   166,   167,   442,   443,   444,   171,   445,
     446,   447,   175,   448,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,     3,     0,     0,     0,
       0,     0,     0,   410,   411,     0,   412,   413,   414,   415,
     416,   417,    13,    14,    15,    16,    17,    18,   418,   419,
     420,    22,   421,    24,    25,    26,    27,     0,   422,   423,
      30,   424,   425,   426,    34,    35,    36,    37,    38,    39,
      40,    41,    42,   427,   428,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
       0,     0,    62,     0,    63,    64,    65,   429,     0,     0,
      69,    70,    71,     0,     0,     0,    73,     0,     0,     0,
       0,    75,    76,    77,     0,     0,    80,    81,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,   430,    92,    93,     0,     0,     0,     0,
       0,     0,     0,    96,    97,    98,     0,   100,   101,   102,
       0,     0,     0,     0,     0,     0,   106,   107,     0,     0,
       0,     0,   108,   109,   110,   433,   112,   113,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   121,     0,
       0,     0,   122,   701,   123,     0,     0,     0,     0,     0,
     702,     0,   129,     0,   130,   131,   132,   133,   434,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,     0,
       0,   435,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   436,   437,   438,   156,   439,   440,   159,   160,   161,
     162,   163,   164,   441,   166,   167,   442,   443,   444,   171,
     445,   446,   447,   175,   448,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     3,     0,     0,
       0,     0,     0,     0,   410,   411,     0,   412,   413,   477,
     415,   478,   479,    13,    14,    15,    16,    17,    18,   418,
     419,   480,    22,   421,    24,    25,    26,    27,     0,   422,
     423,    30,   424,   425,   426,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,     0,     0,    62,     0,    63,    64,    65,   481,     0,
       0,    69,    70,    71,     0,     0,     0,    73,     0,     0,
       0,     0,    75,    76,    77,     0,     0,    80,    81,  1234,
       0,     0,     0,     0,     0,    86,    87,    88,    89,     0,
      90,     0,     0,     0,   430,    92,    93,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,     0,   100,   101,
     956,     0,     0,     0,     0,     0,     0,   106,   107,     0,
       0,     0,     0,   108,   109,   110,   433,   112,   113,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
       0,     0,     0,   122,     0,   123,   124,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   434,
     135,   136,   137,   138,   139,   140,     0,     0,   957,   142,
       0,     0,   435,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   436,   154,   438,   156,   439,   440,   159,   160,
     161,   162,   163,   164,   441,   166,   167,   442,   443,   444,
     171,   445,   446,   447,   175,   448,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,     0,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,     3,     0,
       0,     0,     0,     0,     0,   410,   411,     0,   412,   413,
     477,   415,   478,   479,    13,    14,    15,    16,    17,    18,
     418,   419,   480,    22,   421,    24,    25,    26,    27,     0,
     422,   423,    30,   424,   425,   426,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    62,     0,    63,    64,    65,   481,
       0,     0,    69,    70,    71,     0,     0,     0,    73,     0,
       0,     0,     0,    75,    76,    77,     0,     0,    80,    81,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,   430,    92,    93,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,     0,   100,
     101,   956,     0,     0,     0,     0,     0,     0,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   433,   112,   113,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,     0,     0,     0,   122,     0,   123,   124,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     434,   135,   136,   137,   138,   139,   140,     0,     0,   957,
     142,     0,     0,   435,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   436,   154,   438,   156,   439,   440,   159,
     160,   161,   162,   163,   164,   441,   166,   167,   442,   443,
     444,   171,   445,   446,   447,   175,   448,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     3,
       0,     0,     0,     0,     0,     0,   410,   411,     0,   412,
     413,   477,   415,   478,   479,    13,    14,    15,    16,    17,
      18,   418,   419,   480,    22,   421,    24,    25,    26,    27,
       0,   422,   423,    30,   424,   425,   426,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,     0,    62,     0,    63,    64,    65,
     481,     0,     0,    69,    70,    71,     0,     0,     0,    73,
       0,     0,     0,     0,    75,    76,    77,     0,     0,    80,
      81,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,     0,    90,     0,     0,     0,   430,    92,    93,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    98,     0,
     100,   101,   956,     0,     0,     0,     0,     0,     0,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   433,   112,
     113,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,     0,     0,     0,   122,     0,   123,   124,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   434,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,     0,     0,   435,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   436,   154,   438,   156,   439,   440,
     159,   160,   161,   162,   163,   164,   441,   166,   167,   442,
     443,   444,   171,   445,   446,   447,   175,   448,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
       3,     0,     0,     0,     0,     0,     0,   410,   411,     0,
     412,   413,   414,   415,   416,   417,    13,    14,    15,    16,
      17,    18,   418,   419,   420,    22,   421,    24,    25,    26,
      27,     0,   422,   423,    30,   424,   425,   426,    34,    35,
      36,    37,    38,    39,    40,    41,    42,   427,   428,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     0,     0,    62,     0,    63,    64,
      65,   429,     0,     0,    69,    70,    71,     0,     0,     0,
      73,     0,     0,     0,     0,    75,    76,    77,     0,     0,
      80,    81,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   430,    92,    93,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
       0,   100,   101,   102,     0,     0,     0,     0,     0,     0,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   433,
     112,   113,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,     0,     0,     0,   122,     0,   123,     0,
       0,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   434,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,     0,     0,   435,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   436,   437,   438,   156,   439,
     440,   159,   160,   161,   162,   163,   164,   441,   166,   167,
     442,   443,   444,   171,   445,   446,   447,   175,   448,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         9,   683,   843,   997,   708,   687,   103,   571,   572,   573,
     574,   567,    21,   790,   791,   116,   525,   881,    68,    20,
     127,  1149,   772,   918,   375,   687,   547,  1288,   985,    88,
     550,   110,   552,   553,    88,   555,    60,   557,    21,    30,
       7,    32,    33,     8,     9,   565,   566,    20,    88,  1122,
     132,    42,   466,     8,     9,   940,    86,    66,    86,    68,
      88,    20,   136,   750,    20,    99,  1160,  1161,    85,   110,
      45,   120,    88,    82,    65,    66,    51,   136,   110,    54,
      55,    30,   149,    86,    99,   499,   500,    62,   502,   503,
     504,   505,   754,    86,   756,   104,   510,    99,    89,   513,
     120,   102,   132,   790,   791,   456,   457,   116,   136,   118,
      30,   105,   526,   114,    34,   124,    65,   121,   136,   142,
      99,   147,   536,   537,    53,   214,   126,   214,    86,   145,
      95,   214,   219,   174,  1019,   822,   185,   138,   164,   147,
      95,   142,   165,   175,   145,   179,   828,    99,   113,   105,
     115,    71,     8,     9,   171,    92,   164,    25,   113,     4,
     115,   187,    86,     8,   179,   185,   853,     8,     9,   214,
      99,   216,   157,    41,   176,   179,    99,   142,    98,    43,
     262,   146,   206,   158,   598,   160,   177,   142,   262,   189,
     149,   146,   275,   149,   248,   249,   163,   162,  1271,   174,
    1041,  1295,   175,   262,   311,   190,   260,   162,   248,   249,
     914,   214,   768,   769,  1078,   897,   295,  1112,   183,   202,
    1481,   214,   246,   214,   176,   200,   175,  1122,   183,  1223,
       8,  1429,   262,   895,   262,   756,   201,   987,   158,    95,
    1501,    19,  1199,   763,   262,   224,   201,   241,  1376,   207,
     208,   252,  1513,   189,    95,   119,   179,   113,   145,   115,
     157,     4,   198,    99,   222,     8,   316,  1465,   113,   319,
     115,    99,   113,   624,   115,   284,   270,   271,   123,   273,
     274,   382,   157,   207,   208,  1062,   142,    86,  1397,   226,
     146,    99,    88,   190,    88,    99,    92,   142,   222,   284,
     285,   142,     8,   404,   241,   146,   162,   316,   970,   406,
     319,   105,   409,    19,    99,   190,  1425,   254,    99,   256,
     126,   162,   258,   674,    86,    56,    57,   183,   264,   266,
      99,   745,   269,   139,   431,   113,   272,   115,   752,   175,
     142,    86,   183,   142,    99,   201,   124,   175,    99,    99,
      99,   145,    99,   450,   451,    99,   453,   366,   455,   460,
     201,   157,   459,   372,   142,   145,  1053,   175,  1055,   378,
     113,   175,   115,   382,   136,  1062,  1271,   474,   387,   110,
     123,   206,   157,   392,   281,   282,   142,   284,   285,   145,
     175,   136,   489,   127,   175,   404,   405,  1391,   495,   142,
     275,   276,   277,   278,   279,   110,   175,   113,   142,   115,
     824,   210,   211,    20,   109,   190,   830,   514,   124,   155,
     175,   246,   986,   432,   175,   175,   175,   983,   175,   137,
     226,   175,   286,  1210,   170,   944,   142,   127,   134,   995,
     135,   142,   198,   297,   145,   241,   154,   243,   244,   245,
      98,   460,   142,   148,   463,   464,   465,   253,   254,    86,
     256,    58,    59,   472,    61,   261,   475,   137,   164,   117,
     266,   267,   268,   269,   888,   889,   485,   891,   110,   893,
     831,   832,   589,   590,   154,   836,   182,   182,  1352,   586,
     170,    88,  1410,  1411,   591,   102,    58,    59,   507,   913,
     127,   110,   237,   238,   184,   132,   515,   114,   859,   142,
     924,   925,   926,   110,   928,   929,   930,   931,   932,   933,
      88,   935,   936,  1210,   259,    54,    88,  1209,  1446,    26,
     866,   138,   868,   947,  1452,   142,   170,   105,   145,    88,
      92,   110,  1229,    92,    34,    35,    36,  1324,   819,    39,
     184,    48,   966,   105,   968,   969,   127,   318,   241,   656,
     657,   132,   833,   324,   367,  1269,   663,   145,   371,   670,
    1274,   907,   673,   909,    34,    35,    36,    37,    38,    39,
    1421,    86,    87,   680,    87,   189,    46,   270,   271,   142,
     273,   274,   601,    98,   198,    98,  1010,   142,   180,   181,
     145,   258,   187,   108,   189,   108,   263,   704,   157,   258,
     619,    71,   117,   198,   117,   264,  1030,   127,   239,  1328,
    1184,   242,   132,   272,  1333,   145,  1403,  1191,  1192,   592,
     289,   290,   595,   730,   597,   142,   239,  1324,   647,   242,
     210,   211,   212,   103,   104,   105,   204,  1203,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,  1072,  1363,
     214,   670,   216,  1367,   673,   221,   221,   223,   223,   145,
     767,  1085,   287,   288,   110,  1089,  1090,   226,  1092,   118,
     119,   142,   691,  1097,   279,   280,    58,    59,   118,   119,
     284,   285,   241,   227,   243,   244,   245,   157,   707,  1427,
    1428,   369,   370,   568,   569,   254,   231,   256,   575,   576,
    1414,   145,   261,  1326,  1327,  1397,  1403,   266,   267,   268,
     269,   142,  1073,   231,   577,   578,   792,   793,   110,     0,
     190,   179,   179,   156,    84,   744,   251,    68,  1152,   188,
      93,   750,    94,   143,   145,  1309,  1310,    34,    34,  1163,
      20,   141,   110,   291,   142,   142,   142,   175,   175,   856,
     145,   142,  1176,   860,   268,  1179,   268,  1181,   110,   110,
     145,   142,   145,   175,    27,   145,   145,    15,   175,    20,
     240,   790,   791,   792,   793,   220,   202,   110,    25,    99,
     158,   175,   159,   159,   220,    86,  1483,    86,    86,   145,
      20,    99,    99,   117,   149,  1156,   149,   122,    20,   286,
     292,   122,   142,   822,   175,   275,   276,   277,   278,   279,
    1384,   172,    88,   283,   172,   172,   175,   287,   288,   289,
     290,    30,   172,   172,    88,   172,   132,   175,    99,   175,
     172,   175,  1256,    86,  1258,   172,   175,   175,   172,   858,
    1264,   172,   226,   132,   214,   175,   172,   866,   159,   868,
     179,   110,   110,   110,  1278,  1279,  1280,  1281,  1282,   136,
    1284,  1285,   250,   269,   110,   252,   122,   257,   172,    86,
     173,   132,   132,   272,    86,   142,   186,   172,   271,   172,
     172,    92,  1306,   272,   122,   122,  1247,   149,   907,    88,
     909,   110,   142,   172,   136,   110,   132,   142,   172,    27,
      20,   246,   110,   172,   110,    71,   122,   235,   142,    99,
    1017,    99,   145,   145,   130,   131,  1340,   133,   136,    86,
     172,   175,   136,  1347,   140,  1349,   136,  1351,   144,   247,
     146,   247,    47,   952,   134,   151,   955,   272,  1299,    20,
     272,    20,    86,   172,   963,   134,   965,   175,   179,   175,
     175,   167,    34,    35,    36,    37,    38,    39,  1065,    99,
     132,   159,   175,   136,    46,   110,    61,   110,   175,   122,
      52,   175,     6,  1080,  1398,   191,   192,   193,   194,   195,
     196,    63,    64,   179,   132,    67,   226,   222,    70,    71,
     174,    98,    98,  1012,   175,   222,   175,  1104,   222,   222,
     136,   110,    86,   172,    20,    20,   145,   294,   172,   174,
     265,  1118,   116,    88,   172,   172,   172,  1441,   172,    20,
      88,   103,   104,   105,   110,    86,    59,   110,   174,   249,
     185,   275,   110,   185,   255,   185,   214,   220,   281,   174,
      85,   171,   142,  1062,   185,   110,  1470,    34,    35,    36,
      37,    38,    39,   255,   293,   296,   110,   110,   145,    46,
    1484,   110,   175,  1082,   175,    52,   187,   149,  1087,   145,
     175,   110,  1496,   145,  1498,   157,    63,    64,   175,  1098,
      67,   214,   275,    70,    71,   214,   237,   524,   293,   524,
     623,   294,   293,   240,   243,  1026,   823,   380,   240,   857,
    1119,   298,  1398,   298,   805,  1211,   397,   401,   190,   528,
     400,   955,   244,  1145,  1262,   902,   103,   104,   105,  1099,
     283,  1140,  1153,  1087,  1165,   947,  1163,   209,  1082,   549,
    1149,  1160,   548,   304,  1153,  1063,  1112,   708,   570,  1452,
     308,  1446,   485,   793,   868,   822,   473,   768,  1140,  1025,
     473,  1150,   983,   995,  1203,   987,  1338,   769,   240,  1222,
     984,    -1,   149,  1198,    -1,    -1,    -1,    -1,    -1,    -1,
     157,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1210,    -1,   275,   276,   277,   278,   279,    -1,    -1,
      -1,   283,    -1,   190,    -1,   287,   288,   289,   290,   291,
      -1,    -1,    -1,    -1,    -1,  1234,    -1,    -1,    -1,    -1,
      -1,    -1,   209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1259,  1260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1270,    -1,   240,    -1,    -1,  1275,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,   276,
     277,   278,   279,    -1,    -1,    -1,   283,    -1,    -1,    -1,
     287,   288,   289,   290,    -1,  1324,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1344,    -1,    -1,    -1,  1348,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1364,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1376,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1400,    -1,    -1,  1403,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1503,    -1,  1417,    -1,
      -1,    -1,  1509,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1523,    -1,  1437,    -1,
    1439,    -1,    -1,  1442,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1485,    -1,    -1,  1488,
      -1,    -1,    -1,    -1,    -1,  1494,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    10,    -1,    -1,  1506,    -1,    -1,
      -1,    17,    18,    -1,    20,    -1,    -1,    -1,  1517,    25,
      26,  1520,    28,    29,    30,    31,    32,    33,    34,    35,
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
     246,   247,   248,   249,    -1,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,    10,    -1,    -1,    -1,    -1,    -1,
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
     246,   247,   248,   249,    -1,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    -1,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    -1,
      97,    98,    -1,    -1,    -1,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,    -1,   114,    -1,   116,
     117,   118,   119,    -1,   121,    -1,    -1,    -1,   125,   126,
     127,   128,   129,    -1,    -1,    -1,    -1,    -1,   135,   136,
     137,   138,   139,   140,   141,    -1,    -1,    -1,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,   154,   155,   156,
     157,   158,   159,   160,   161,   162,    -1,   164,   165,    -1,
      -1,   168,   169,   170,    -1,   172,    -1,   174,    -1,   176,
     177,   178,    -1,   180,   181,   182,    -1,   184,    -1,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      -1,    -1,   199,   200,   201,    -1,   203,   204,    -1,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,   251,   252,    -1,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
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
     168,   169,   170,    -1,    -1,    -1,   174,   175,   176,   177,
     178,    -1,   180,   181,   182,    -1,   184,    -1,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    -1,
      -1,   199,   200,   201,    -1,   203,   204,    -1,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    -1,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    -1,    97,    98,
      -1,    -1,    -1,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,    -1,   114,    -1,   116,   117,   118,
     119,    -1,   121,    -1,    -1,    -1,   125,   126,   127,   128,
     129,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,   138,
     139,   140,   141,    -1,    -1,    -1,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,
     159,   160,   161,   162,    -1,   164,   165,    -1,    -1,   168,
     169,   170,    -1,   172,    -1,   174,    -1,   176,   177,   178,
      -1,   180,   181,   182,    -1,   184,    -1,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    -1,    -1,
     199,   200,   201,    -1,   203,   204,    -1,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
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
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
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
      -1,   172,    -1,   174,    -1,   176,   177,   178,    -1,   180,
     181,   182,    -1,   184,    -1,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,    -1,    -1,   199,   200,
     201,    -1,   203,   204,    -1,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
     251,   252,    -1,   254,   255,   256,   257,   258,   259,   260,
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
     172,    -1,   174,    -1,   176,   177,   178,    -1,   180,   181,
     182,    -1,   184,    -1,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,    -1,    -1,   199,   200,   201,
      -1,   203,   204,    -1,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    -1,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    -1,    97,    98,    -1,    -1,    -1,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
      -1,   114,    -1,   116,   117,   118,   119,    -1,   121,    -1,
      -1,    -1,   125,   126,   127,   128,   129,    -1,    -1,    -1,
      -1,    -1,   135,   136,   137,   138,   139,   140,   141,    -1,
      -1,    -1,   145,   146,   147,   148,   149,    -1,    -1,    -1,
      -1,   154,   155,   156,   157,   158,   159,   160,   161,   162,
      -1,   164,   165,    -1,    -1,   168,   169,   170,    -1,   172,
      -1,   174,    -1,   176,   177,   178,    -1,   180,   181,   182,
      -1,   184,    -1,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,   199,   200,   201,    -1,
     203,   204,    -1,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,   251,   252,
      -1,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,    10,    -1,    -1,    -1,
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
     244,   245,   246,   247,   248,   249,    -1,   251,   252,    -1,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      -1,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    97,    98,    -1,    -1,    -1,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,    -1,   114,
      -1,   116,   117,   118,   119,    -1,   121,    -1,    -1,    -1,
     125,   126,   127,   128,   129,    -1,    -1,    -1,    -1,    -1,
     135,   136,   137,   138,   139,   140,   141,    -1,    -1,    -1,
     145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,
     155,   156,   157,   158,   159,   160,   161,   162,    -1,   164,
     165,    -1,    -1,   168,   169,   170,    -1,    -1,    -1,   174,
      -1,   176,   177,   178,    -1,   180,   181,   182,    -1,   184,
      -1,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,    -1,    -1,   199,   200,   201,    -1,   203,   204,
      -1,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,    10,    -1,    -1,    -1,    -1,    -1,
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
     246,   247,   248,   249,    -1,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    -1,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    -1,
      97,    98,    -1,    -1,    -1,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,    -1,   114,    -1,   116,
     117,   118,   119,    -1,   121,    -1,    -1,    -1,   125,   126,
     127,   128,   129,    -1,    -1,    -1,    -1,    -1,   135,   136,
     137,   138,   139,   140,   141,    -1,    -1,    -1,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,   154,   155,   156,
     157,   158,   159,   160,   161,   162,    -1,   164,   165,    -1,
      -1,   168,   169,   170,    -1,    -1,    -1,   174,    -1,   176,
     177,   178,    -1,   180,   181,   182,    -1,   184,    -1,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      -1,    -1,   199,   200,   201,    -1,   203,   204,    -1,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,   251,   252,    -1,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
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
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    -1,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    -1,    97,    98,
      -1,    -1,    -1,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,    -1,   114,    -1,   116,   117,   118,
     119,    -1,   121,    -1,    -1,    -1,   125,   126,   127,   128,
     129,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,   138,
     139,   140,   141,    -1,    -1,    -1,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,
     159,   160,   161,   162,    -1,   164,   165,    -1,    -1,   168,
     169,   170,    -1,    -1,    -1,   174,    -1,   176,   177,   178,
      -1,   180,   181,   182,    -1,   184,    -1,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    -1,    -1,
     199,   200,   201,    -1,   203,   204,    -1,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
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
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
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
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
     251,   252,    -1,   254,   255,   256,   257,   258,   259,   260,
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
      -1,    -1,    -1,   145,   146,    -1,   148,   149,    -1,    -1,
      -1,    -1,   154,   155,   156,   157,   158,   159,   160,   161,
     162,    -1,    -1,    -1,    -1,    -1,   168,   169,   170,    -1,
      -1,    -1,   174,    -1,   176,   177,   178,    -1,    -1,    -1,
     182,    -1,   184,    -1,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,    -1,    -1,   199,   200,   201,
      -1,   203,   204,    -1,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      -1,    84,    -1,    86,    87,    88,    89,    -1,    -1,    92,
      93,    94,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,
     103,   104,   105,    -1,    -1,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,   116,   117,   118,   119,    -1,   121,    -1,
      -1,    -1,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   135,   136,   137,    -1,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,    -1,    -1,    -1,
      -1,   154,   155,   156,   157,   158,   159,   160,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,
      -1,   174,    -1,   176,   177,    -1,    -1,    -1,    -1,   182,
      -1,   184,    -1,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,   199,   200,    -1,    -1,
     203,   204,    -1,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,   251,   252,
      -1,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,
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
     174,    -1,   176,    -1,    -1,    -1,    -1,    -1,   182,    -1,
     184,    -1,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,    -1,    -1,   199,   200,    -1,    -1,   203,
     204,    -1,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,   251,   252,    -1,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,    14,    -1,    -1,    -1,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    -1,    -1,    84,    -1,    86,    87,    88,
      89,    -1,    -1,    92,    93,    94,    -1,    -1,    -1,    98,
      -1,    -1,    -1,    -1,   103,   104,   105,    -1,    -1,   108,
     109,    -1,    -1,    -1,    -1,    -1,    -1,   116,   117,   118,
     119,    -1,   121,    -1,    -1,    -1,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,    -1,
     139,   140,   141,   142,    -1,    -1,   145,    -1,    -1,   148,
     149,    -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,
     159,   160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   170,    -1,    -1,    -1,   174,    -1,   176,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   184,    -1,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    -1,    -1,
     199,   200,    -1,    -1,   203,   204,    -1,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
      14,    -1,    -1,    -1,    18,    -1,    20,    -1,    -1,    -1,
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
     174,   175,   176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     184,    -1,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,    -1,    -1,   199,   200,    -1,    -1,   203,
     204,    -1,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,    -1,   251,   252,    -1,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,    14,    -1,    -1,    -1,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    -1,    -1,    84,    -1,    86,    87,    88,
      89,    -1,    -1,    92,    93,    94,    -1,    -1,    -1,    98,
      -1,    -1,    -1,    -1,   103,   104,   105,    -1,    -1,   108,
     109,    -1,    -1,    -1,    -1,    -1,    -1,   116,   117,   118,
     119,    -1,   121,    -1,    -1,    -1,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,    -1,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,    -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,
     159,   160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   170,    -1,    -1,    -1,   174,    -1,   176,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   184,    -1,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    -1,    -1,
     199,   200,    -1,    -1,   203,   204,    -1,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
      16,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,
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
     246,   247,   248,   249,    -1,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    -1,    -1,    84,
      -1,    86,    87,    88,    89,    -1,    -1,    92,    93,    94,
      -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,   103,   104,
     105,    -1,    -1,   108,   109,    -1,    -1,    -1,    -1,    -1,
      -1,   116,   117,   118,   119,    -1,   121,    -1,    -1,    -1,
     125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     135,   136,   137,    -1,   139,   140,   141,   142,    -1,    -1,
     145,    -1,    -1,   148,   149,    -1,    -1,    -1,    -1,   154,
     155,   156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,   174,
      -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   184,
      -1,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,    -1,    -1,   199,   200,    -1,    -1,   203,   204,
      -1,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,    18,    -1,    -1,    -1,    -1,    -1,
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
     244,   245,   246,   247,   248,   249,    -1,   251,   252,    -1,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    -1,
      -1,    84,    -1,    86,    87,    88,    89,    -1,    -1,    92,
      93,    94,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,
     103,   104,   105,    -1,    -1,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,   116,   117,   118,   119,    -1,   121,    -1,
      -1,    -1,   125,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   135,   136,   137,    -1,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,    -1,    -1,    -1,
      -1,   154,   155,   156,   157,   158,   159,   160,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,
      -1,   174,   175,   176,    -1,    -1,    -1,    -1,    -1,   182,
      -1,   184,    -1,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,   199,   200,    -1,    -1,
     203,   204,    -1,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,   251,   252,
      -1,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      -1,    -1,    84,    -1,    86,    87,    88,    89,    -1,    -1,
      92,    93,    94,    -1,    -1,    -1,    98,    -1,    -1,    -1,
      -1,   103,   104,   105,    -1,    -1,   108,   109,    -1,    -1,
      -1,    -1,    -1,    -1,   116,   117,   118,   119,    -1,   121,
      -1,    -1,    -1,   125,   126,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   135,   136,   137,    -1,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,    -1,    -1,
      -1,    -1,   154,   155,   156,   157,   158,   159,   160,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,
      -1,    -1,   174,   175,   176,    -1,    -1,    -1,    -1,    -1,
     182,    -1,   184,    -1,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,    -1,    -1,   199,   200,    -1,
      -1,   203,   204,    -1,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    -1,    -1,    84,    -1,    86,    87,    88,    89,    -1,
      -1,    92,    93,    94,    -1,    -1,    -1,    98,    -1,    -1,
      -1,    -1,   103,   104,   105,    -1,    -1,   108,   109,   110,
      -1,    -1,    -1,    -1,    -1,   116,   117,   118,   119,    -1,
     121,    -1,    -1,    -1,   125,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   135,   136,   137,    -1,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,    -1,
      -1,    -1,    -1,   154,   155,   156,   157,   158,   159,   160,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,
      -1,    -1,    -1,   174,    -1,   176,   177,    -1,    -1,    -1,
      -1,    -1,    -1,   184,    -1,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,    -1,    -1,   199,   200,
      -1,    -1,   203,   204,    -1,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,    -1,
     251,   252,    -1,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,
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
     170,    -1,    -1,    -1,   174,    -1,   176,   177,    -1,    -1,
      -1,    -1,    -1,    -1,   184,    -1,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,    -1,   199,
     200,    -1,    -1,   203,   204,    -1,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    -1,    -1,    84,    -1,    86,    87,    88,
      89,    -1,    -1,    92,    93,    94,    -1,    -1,    -1,    98,
      -1,    -1,    -1,    -1,   103,   104,   105,    -1,    -1,   108,
     109,    -1,    -1,    -1,    -1,    -1,    -1,   116,   117,   118,
     119,    -1,   121,    -1,    -1,    -1,   125,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,    -1,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,    -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,
     159,   160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   170,    -1,    -1,    -1,   174,    -1,   176,   177,    -1,
      -1,    -1,    -1,    -1,    -1,   184,    -1,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    -1,    -1,
     199,   200,    -1,    -1,   203,   204,    -1,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
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
      -1,    -1,    -1,    -1,    -1,    -1,   184,    -1,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    -1,
      -1,   199,   200,    -1,    -1,   203,   204,    -1,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298
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
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     251,   252,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   345,   346,   351,   352,   356,   362,   366,
     368,   373,   374,   375,   376,   377,   385,   386,   388,   389,
     390,   395,   397,   399,   400,   401,   406,   427,   430,   433,
     434,   435,   436,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   483,   484,   485,   499,   500,   502,   503,
     504,   505,   506,   507,   508,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   527,   528,   529,   530,   531,
     532,   533,   536,   542,   543,   544,    34,    35,    36,    37,
      38,    39,    46,    52,    63,    64,    67,    70,    71,   103,
     104,   105,   149,   157,   190,   209,   240,   275,   276,   277,
     278,   279,   283,   287,   288,   289,   290,   353,   354,   363,
     364,   365,   378,   379,   149,    86,   142,   210,   211,   145,
      25,    26,    28,    29,    30,    31,    32,    33,    40,    41,
      42,    44,    50,    51,    53,    54,    55,    65,    66,    89,
     125,   142,   145,   157,   190,   203,   213,   214,   215,   217,
     218,   225,   228,   229,   230,   232,   233,   234,   236,   542,
     142,   142,   145,   142,   145,   145,    26,    48,    14,   142,
     145,   541,   542,   110,   110,   110,   142,    56,    57,   110,
     392,    54,   145,   145,   142,   145,   542,    30,    32,    33,
      42,    89,   467,   542,   542,   110,   175,   386,   542,   142,
     541,    16,   542,   542,   459,   142,    21,   202,   204,   214,
     216,   145,   214,   216,   214,   214,   219,   110,   142,   369,
     227,   231,   231,   145,   142,   110,   316,     0,   318,   319,
      25,    41,   321,   385,   179,   179,    99,   179,   387,    45,
      51,    54,    55,    62,   158,   160,   174,   200,   391,   396,
     397,   398,   415,   416,   420,   402,   403,   542,   156,    84,
     122,   130,   131,   133,   140,   144,   146,   151,   167,   191,
     192,   193,   194,   195,   196,   451,   452,   251,   147,   164,
     187,   109,   135,   148,   182,   189,   198,   126,   139,    68,
     188,    93,    94,   147,   164,   450,   142,   456,   459,   180,
     181,   143,   471,   472,   467,   471,   467,   471,   145,   542,
     379,    34,   380,   378,   378,   379,   542,   170,   184,   157,
     190,    20,   540,   155,   170,   170,   184,   542,   141,   110,
     350,    30,    34,    71,    98,   158,   541,   210,   211,   212,
      92,   226,   241,   254,   256,   266,   269,   556,   557,   558,
     559,   560,   563,   568,   569,   542,   542,   275,   354,   291,
     365,   364,   541,   525,   542,   386,   142,   142,   386,   386,
     175,   182,   542,   142,   386,   386,   175,   386,   175,   386,
     149,   540,   105,   149,   344,   540,   386,    20,   175,   541,
     142,   428,   429,   542,   542,   407,   409,   542,   389,   268,
     268,   110,   410,   110,   542,    30,    65,   175,   523,   524,
     386,   175,   182,   542,   142,   428,   175,    27,   487,   488,
     489,   386,     7,   163,    15,   175,   386,   202,    20,   389,
     389,   175,   389,   389,   389,   389,   220,   534,   535,   542,
     370,   389,   389,   386,   408,   414,   542,   323,   324,    25,
     325,   389,   388,   158,   110,   159,   159,   389,   389,    99,
      86,    88,   136,   262,   404,   405,   510,   435,   436,   438,
     438,   438,   438,   437,   438,   438,   438,   142,   145,   252,
     474,   545,   547,   548,   549,   550,   551,   552,   553,   441,
     441,   440,   442,   442,   442,   442,   443,   443,   444,   444,
     220,    86,    86,    86,   172,   386,   459,   459,   386,   472,
     175,   389,   482,   145,   367,   542,    20,    99,    99,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,   327,
     328,   329,    86,   127,   132,   347,   348,   349,   542,   127,
     132,   149,   149,   327,   540,   117,   122,   239,   242,   105,
     241,   270,   271,   273,   274,   239,   242,    20,   241,   270,
     271,   273,   274,    86,   214,   355,   286,   542,   292,   122,
     142,   172,   386,   386,   175,   172,    99,   175,    99,   175,
     172,   386,   172,   172,   172,   175,   541,    88,    30,   541,
     540,    88,   172,   175,   175,   172,   386,    99,   176,   136,
     510,   132,    99,   132,   405,   510,   172,   542,    60,   206,
     246,   393,   394,   175,   175,   175,   172,    99,   175,    99,
     175,   172,   386,   176,   542,   488,   489,   120,   185,   172,
     172,   121,   179,    86,   207,   208,   222,    86,   207,   208,
     222,    86,   226,   214,    99,   224,   132,    25,   371,   386,
     175,   172,    53,    99,   179,   105,   179,   159,   542,   389,
     421,   422,   110,   417,   418,   110,   141,   199,   511,   513,
     514,   515,   542,   110,   389,   110,   136,   405,   136,   136,
     404,   405,   438,   386,   545,   551,   269,   579,    88,   157,
     243,   244,   245,   253,   261,   267,   268,   546,   554,   555,
     556,   570,   573,   574,   576,   250,   252,   257,   575,   237,
     238,   259,   571,   511,   511,   509,   514,   509,   172,   173,
      99,   175,   110,   175,   381,   382,   127,   142,   384,   367,
     137,   154,   137,   154,   328,   122,   513,   349,   389,   510,
     132,   389,   540,   540,   118,   119,   540,   271,   272,    88,
     105,   145,   562,   272,    32,    33,    42,    66,    89,   214,
     515,   279,   280,    86,   386,    86,   355,   542,   540,   386,
     172,   172,    92,   431,   432,   142,   525,   526,   542,   525,
     526,   172,   186,   122,   343,   540,   149,   122,    88,   343,
     142,   172,   110,   389,   389,   136,   389,   110,   389,   132,
     132,   405,   136,   510,   246,    58,    59,    61,   110,   404,
     411,   412,   413,   394,   142,   525,   525,   172,   389,    27,
     489,   120,   185,     8,     9,    95,   113,   115,   142,   183,
     383,   484,   486,   497,   498,   501,    20,   221,   223,   389,
     389,   389,   221,   223,   389,   389,   389,   389,   389,   389,
     110,   389,   389,   350,   372,    99,   179,   172,   369,   235,
     537,   538,   142,   110,   421,    87,    98,   108,   117,   423,
     424,   425,   426,    99,   542,    99,   403,   145,   145,   134,
     164,   182,   512,   542,   542,   389,   136,   389,   389,   136,
     405,   136,   172,   175,   247,   206,   246,   258,   263,   578,
      88,   248,   249,   572,   247,   548,   578,   439,   442,   267,
     554,   556,   549,   136,   572,   272,    47,   134,   389,   542,
      86,    99,   175,   386,   127,   369,   527,   348,   389,   272,
      88,   145,   565,    20,   105,   562,   515,   159,   515,    86,
     286,   297,   179,   172,   110,   511,   105,   432,   172,   386,
     175,   175,   134,   175,   175,   389,   540,    99,   343,   172,
     386,   429,   389,   409,   389,   389,   132,   389,   136,   110,
     110,   389,   542,   413,    61,   172,   386,   175,   175,   122,
     183,   486,     6,   386,   542,   183,   497,   179,   222,   222,
     222,   222,   226,   535,   174,   132,   372,   468,   539,   538,
     389,   414,   540,   118,   119,   425,   426,   426,   422,    98,
     419,   418,   175,   175,   389,   389,   136,   389,   442,    43,
     119,   442,   442,   258,   264,   272,   577,   577,   439,   550,
     265,   510,   511,   382,    86,   172,   126,   189,   564,   567,
      20,    20,   566,   564,   260,   572,    99,   175,    99,   175,
     145,   360,   515,   214,   275,   294,   542,   174,   110,   174,
     172,   116,    88,   540,   172,   389,   389,   542,   542,   412,
     389,   172,   489,   542,   183,   172,   489,   542,   389,   389,
     389,   389,   389,   389,   389,   145,   198,   384,   172,   426,
     540,   389,   442,   442,   187,   511,   565,   565,   567,    20,
     175,    20,   255,   561,   562,   561,   361,   389,    99,   175,
     110,   542,   249,    86,   389,   542,   389,   389,   343,    59,
      85,   171,   490,   489,   542,   185,   489,   110,   468,   442,
     572,    99,   175,   175,   423,   510,   361,   157,   190,   281,
     282,   284,   285,   357,   358,   359,   542,   110,   295,   275,
     511,   174,   110,     4,   123,   493,   494,   496,   498,    19,
     124,   491,   492,   495,   498,   185,   489,   185,   542,   255,
     562,   423,   359,   359,   358,   281,   220,   542,   214,   542,
     174,   389,   542,    85,   123,   496,   171,   124,   495,   185,
      99,   175,   358,   296,   293,   110,   214,   389,   110,   384,
     515,   281,   389,   542,   110,   542,   293,   294,   293,   542,
      99,   175,   389,   145,   389,   298,   110,   384,   386,   145,
     542,   175,   386,   175,   175,   384,   187,   275,   542,   214,
     110,   542,   298,   145,   386,   175
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
     565,   566,   567,   568
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   314,   315,   315,   316,   316,   316,   316,   317,   317,
     318,   318,   319,   319,   320,   321,   321,   321,   322,   322,
     323,   323,   324,   324,   324,   324,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   326,   326,   327,   327,   328,
     329,   329,   329,   329,   329,   329,   329,   329,   329,   329,
     330,   330,   330,   330,   330,   330,   330,   330,   331,   331,
     332,   333,   333,   334,   334,   335,   336,   337,   337,   338,
     338,   339,   339,   339,   339,   340,   341,   342,   342,   342,
     342,   343,   343,   344,   344,   345,   345,   345,   345,   346,
     347,   347,   348,   348,   348,   349,   350,   350,   351,   351,
     351,   352,   352,   352,   352,   352,   352,   352,   352,   353,
     353,   354,   354,   354,   354,   354,   354,   355,   355,   356,
     357,   357,   357,   358,   358,   358,   359,   359,   359,   360,
     360,   361,   361,   361,   361,   362,   362,   362,   362,   362,
     363,   363,   364,   364,   364,   365,   365,   365,   366,   366,
     367,   367,   367,   367,   368,   369,   370,   370,   371,   371,
     372,   372,   373,   374,   375,   376,   376,   377,   377,   377,
     378,   378,   378,   378,   379,   379,   380,   380,   381,   381,
     382,   382,   383,   384,   385,   386,   386,   387,   387,   388,
     388,   389,   389,   389,   389,   389,   389,   389,   389,   389,
     389,   389,   389,   389,   389,   389,   389,   389,   390,   391,
     392,   392,   393,   393,   393,   394,   394,   395,   395,   396,
     397,   397,   397,   398,   398,   398,   398,   398,   399,   399,
     400,   400,   401,   402,   402,   403,   403,   403,   403,   403,
     403,   403,   403,   404,   405,   406,   407,   407,   408,   408,
     409,   409,   409,   409,   410,   410,   411,   411,   411,   412,
     412,   412,   413,   413,   413,   414,   415,   416,   417,   417,
     418,   418,   419,   420,   420,   421,   421,   422,   422,   423,
     423,   423,   423,   423,   423,   423,   424,   424,   425,   425,
     426,   427,   427,   428,   428,   429,   429,   430,   430,   431,
     431,   432,   432,   433,   434,   434,   435,   435,   436,   436,
     436,   436,   436,   437,   436,   436,   436,   436,   438,   438,
     438,   439,   439,   440,   440,   440,   441,   441,   441,   441,
     441,   442,   442,   442,   443,   443,   443,   444,   444,   445,
     445,   446,   446,   447,   447,   448,   448,   449,   449,   449,
     449,   450,   450,   450,   451,   451,   451,   451,   451,   451,
     452,   452,   452,   453,   453,   453,   453,   454,   454,   455,
     455,   456,   456,   457,   457,   457,   457,   458,   459,   459,
     459,   460,   460,   461,   461,   461,   461,   462,   462,   463,
     463,   463,   463,   463,   463,   463,   464,   464,   465,   465,
     466,   466,   466,   466,   466,   467,   467,   468,   468,   469,
     469,   469,   470,   470,   471,   471,   472,   473,   473,   473,
     473,   473,   473,   473,   473,   474,   474,   475,   475,   475,
     476,   477,   477,   478,   479,   480,   481,   481,   482,   482,
     483,   483,   484,   484,   484,   485,   485,   485,   485,   485,
     485,   486,   486,   487,   487,   488,   489,   489,   490,   490,
     491,   491,   492,   492,   492,   492,   493,   493,   494,   494,
     494,   494,   495,   495,   496,   496,   497,   497,   497,   497,
     498,   498,   498,   498,   499,   499,   500,   500,   501,   502,
     502,   502,   502,   502,   502,   503,   504,   504,   504,   504,
     505,   505,   505,   505,   506,   507,   508,   508,   508,   508,
     509,   509,   510,   511,   511,   511,   512,   512,   512,   513,
     513,   513,   514,   515,   515,   515,   515,   515,   515,   515,
     515,   515,   516,   517,   517,   517,   518,   519,   520,   520,
     520,   521,   521,   521,   521,   521,   522,   523,   523,   523,
     523,   523,   523,   523,   524,   525,   526,   527,   528,   528,
     528,   529,   529,   529,   529,   529,   529,   529,   529,   529,
     529,   530,   530,   531,   531,   532,   533,   534,   534,   535,
     536,   537,   537,   538,   538,   538,   538,   539,   539,   540,
     541,   541,   542,   542,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   543,   543,   543,   543,
     543,   543,   543,   543,   543,   543,   544,   544,   545,   545,
     545,   545,   546,   546,   546,   546,   547,   547,   548,   548,
     549,   549,   550,   550,   551,   551,   551,   552,   552,   553,
     553,   554,   554,   554,   554,   554,   555,   556,   556,   556,
     556,   556,   556,   556,   557,   557,   557,   557,   558,   558,
     558,   558,   559,   559,   560,   560,   560,   560,   560,   560,
     560,   561,   561,   562,   562,   562,   562,   563,   563,   563,
     563,   563,   564,   564,   565,   565,   566,   566,   567,   567,
     568,   569,   569,   570,   570,   570,   571,   571,   571,   571,
     571,   572,   572,   572,   572,   573,   574,   575,   576,   576,
     577,   577,   577,   578,   578,   579
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
       6,     3,     4,     5,     6,     4,     5,     6,     7,     1,
       2,     1,     1,     1,     1,     1,     1,     2,     2,     9,
       1,     2,     3,     1,     2,     2,     0,     1,     1,     2,
       3,     1,     2,     2,     3,    12,    16,    14,    14,    27,
       2,     2,     0,     1,     1,     0,     1,     1,     3,     3,
       2,     3,     4,     5,     2,     4,     3,     0,     3,     2,
       1,     3,     5,     3,     5,     2,     2,     2,     3,     3,
       1,     2,     2,     2,     4,     4,     4,     4,     1,     3,
       2,     3,     3,     3,     1,     1,     2,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     1,     1,     2,     4,     3,     5,     4,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     3,     2,     1,     4,     3,     4,     4,     5,     4,
       5,     5,     6,     3,     3,     3,     1,     4,     1,     4,
       3,     4,     4,     5,     4,     5,     1,     2,     3,     1,
       2,     1,     6,     3,     3,     1,     2,     3,     1,     3,
       2,     3,     2,     3,     4,     1,     3,     1,     2,     1,
       1,     1,     2,     2,     2,     3,     1,     1,     2,     2,
       2,     5,     5,     1,     4,     3,     4,     8,    10,     1,
       2,     4,     7,     8,     1,     3,     1,     3,     1,     3,
       3,     3,     3,     0,     4,     3,     3,     3,     1,     3,
       4,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     4,     1,
       4,     1,     4,     1,     4,     1,     2,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     5,     5,     6,     3,     4,     1,
       2,     3,     2,     1,     2,     2,     1,     1,     1,     3,
       3,     1,     1,     1,     2,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     3,     1,     4,     4,     3,     4,     1,     3,
       1,     1,     1,     1,     1,     4,     5,     8,     9,     9,
      10,     1,     2,     1,     2,     6,     0,     1,     3,     3,
       0,     1,     1,     1,     2,     2,     0,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     3,     3,     2,     1,
       1,     1,     1,     1,     1,     4,     4,     5,     6,     7,
       4,     5,     6,     7,     4,     4,     4,     5,     6,     7,
       1,     2,     2,     1,     2,     3,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     4,     4,     3,     3,     3,     4,
       4,     3,     4,     6,     4,     6,     3,     3,     4,     6,
       6,     4,     6,     6,     4,     1,     2,     1,     3,     3,
       3,     5,     7,     7,     5,     5,     5,     7,     7,     5,
       5,     3,     3,     5,     7,     5,     7,     1,     4,     3,
       5,     1,     2,     3,     7,    10,    13,     1,     3,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     7,     4,     1,     2,
       3,     4,     1,     1,     2,     2,     1,     3,     1,     3,
       1,     4,     1,     2,     1,     2,     3,     1,     2,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     3,     3,     5,     7,     5,     7,
       2,     1,     3,     2,     4,     4,     6,     4,     5,     4,
       5,     3,     1,     2,     2,     3,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     1,     2,
       1,     2,     3,     3,     4,     3,     3,     3,     2,     2,
       1,     1,     1,     1,     1,     3
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
  "\"'copy'\"", "\"'with'\"", "\"'returning'\"", "\"'block'\"",
  "\"'exit'\"", "\"'break'\"", "\"'loop'\"", "\"'continue'\"",
  "\"'while'\"", "\"'try'\"", "\"'catch'\"", "\"'using'\"", "\"'all'\"",
  "\"'any'\"", "\"'casesensitive'\"", "\"'ft-option'\"",
  "\"'diacritics'\"", "\"'insensitive'\"", "\"'different'\"",
  "\"'distance'\"", "\"'entire'\"", "\"'end'\"", "\"'content'\"",
  "\"'exactly'\"", "\"'from'\"", "\"'&&'\"", "\"'ftcontains'\"",
  "\"'not'\"", "\"'||'\"", "\"'language'\"", "\"'levels'\"",
  "\"'lowercase'\"", "\"'occurs'\"", "\"'paragraph'\"", "\"'phrase'\"",
  "\"'relationship'\"", "\"'same'\"", "\"'score'\"", "\"'sentence'\"",
  "\"'sentences'\"", "\"'times'\"", "\"'uppercase'\"", "\"'weight'\"",
  "\"'window'\"", "\"'without'\"", "\"'stemming'\"", "\"'stop'\"",
  "\"'words'\"", "\"'thesaurus'\"", "\"'wildcards'\"", "\"'collection'\"",
  "\"'const'\"", "\"'append-only'\"", "\"'queue'\"", "\"'mutable'\"",
  "\"'read-only'\"", "\"'unique'\"", "\"'non'\"", "\"'index'\"",
  "\"'manual'\"", "\"'automatic'\"", "\"'on'\"", "\"'checked'\"",
  "\"'unchecked'\"", "\"'asynchronous'\"", "\"'synchronous'\"",
  "\"'integrity'\"", "\"'constraint'\"", "\"'check'\"", "\"'key'\"",
  "\"'foreach'\"", "\"'type'\"", "\"'foreign'\"", "\"'keys'\"",
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
  "CtxItemDecl4", "VarNameAndType", "VarDecl", "CollectionDecl",
  "CollPropertyList", "CollProperty", "NodeModifier", "IndexDecl",
  "IndexProperties", "IndexProperties2", "IndexProperties3",
  "IndexKeyList", "IndexKeySpec", "IntegrityConstraintDecl",
  "IntgCnstOptions", "IntgCnstUnchecked", "IntgCnstAsynch",
  "ConstructionDecl", "FunctionSig", "BlockExpr", "Block", "BlockDecls",
  "BlockVarDeclList", "BlockVarDecl", "AssignExpr", "ExitExpr",
  "WhileExpr", "FlowCtlStatement", "FunctionDecl", "FunctionDecl2",
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
  "URI_LITERAL", "NCNAME", "QNAME", "KEYWORD", "EvalExpr", "FTSelection",
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
       315,     0,    -1,   316,    -1,   299,   316,    -1,   318,    -1,
     317,   318,    -1,   319,    -1,   317,   319,    -1,   203,   204,
      20,   179,    -1,   203,   204,    20,   121,    20,   179,    -1,
     321,   385,    -1,   385,    -1,   320,    -1,   320,   321,    -1,
      26,   149,   541,   122,   540,   179,    -1,   322,   179,    -1,
     323,   179,    -1,   322,   179,   323,   179,    -1,   324,    -1,
     322,   179,   324,    -1,   325,    -1,   323,   179,   325,    -1,
     330,    -1,   331,    -1,   332,    -1,   334,    -1,   351,    -1,
     346,    -1,   377,    -1,   335,    -1,   336,    -1,   352,    -1,
     356,    -1,   362,    -1,   326,    -1,    25,   105,    71,   327,
      -1,    25,    71,   542,   327,    -1,   328,    -1,   327,   328,
      -1,   329,   122,   527,    -1,    72,    -1,    73,    -1,    74,
      -1,    75,    -1,    76,    -1,    77,    -1,    78,    -1,    79,
      -1,    80,    -1,    81,    -1,   333,    -1,   340,    -1,   341,
      -1,   366,    -1,   337,    -1,   338,    -1,   339,    -1,   528,
      -1,   342,    -1,   345,    -1,    25,   149,   541,   122,   540,
      -1,    25,    70,   170,    -1,    25,    70,   184,    -1,    25,
     105,    30,   149,   540,    -1,    25,   105,    34,   149,   540,
      -1,    25,    46,   542,    20,    -1,    25,   240,   556,    -1,
      25,    63,   157,    -1,    25,    63,   190,    -1,    25,   105,
     158,   117,   118,    -1,    25,   105,   158,   117,   119,    -1,
      25,    67,   170,    99,   137,    -1,    25,    67,   170,    99,
     154,    -1,    25,    67,   155,    99,   137,    -1,    25,    67,
     155,    99,   154,    -1,    25,   105,    98,   540,    -1,    25,
      64,   540,    -1,    41,    48,   540,    -1,    41,    48,   344,
     540,    -1,    41,    48,   540,    88,   343,    -1,    41,    48,
     344,   540,    88,   343,    -1,   540,    -1,   343,    99,   540,
      -1,   149,   541,   122,    -1,   105,    30,   149,    -1,    41,
      26,   540,    -1,    41,    26,   149,   541,   122,   540,    -1,
      41,    26,   540,    88,   343,    -1,    41,    26,   149,   541,
     122,   540,    88,   343,    -1,    25,   103,   141,   347,    -1,
      86,   513,   348,    -1,   348,    -1,   349,    -1,   127,    -1,
     127,   349,    -1,   132,   389,    -1,   110,   542,    -1,   110,
     542,   510,    -1,    25,   104,   350,   132,   389,    -1,    25,
     104,   350,   127,    -1,    25,   104,   350,   127,   132,   389,
      -1,    25,   275,   542,    -1,    25,   275,   542,   355,    -1,
      25,   275,   542,    86,   515,    -1,    25,   275,   542,   355,
      86,   515,    -1,    25,   353,   275,   542,    -1,    25,   353,
     275,   542,   355,    -1,    25,   353,   275,   542,    86,   515,
      -1,    25,   353,   275,   542,   355,    86,   515,    -1,   354,
      -1,   353,   354,    -1,   276,    -1,   277,    -1,   278,    -1,
     279,    -1,   157,    -1,   190,    -1,   214,   280,    -1,   214,
     279,    -1,    25,   283,   542,   286,   386,   159,   360,   175,
     357,    -1,   358,    -1,   281,   358,    -1,   282,   281,   358,
      -1,   359,    -1,   157,   359,    -1,   190,   359,    -1,    -1,
     284,    -1,   285,    -1,   145,   361,    -1,   360,    99,   361,
      -1,   389,    -1,   389,   423,    -1,   389,   510,    -1,   389,
     510,   423,    -1,    25,   363,   291,   292,   542,   286,   275,
     542,   110,   542,   293,   389,    -1,    25,   363,   291,   292,
     542,   286,   275,   542,   110,   542,   293,   281,   294,   145,
     386,   175,    -1,    25,   363,   291,   292,   542,   286,   275,
     542,   295,   214,   110,   542,   293,   389,    -1,    25,   363,
     291,   292,   542,   286,   214,   110,   542,   220,   296,   515,
     293,   389,    -1,    25,   363,   291,   292,   542,   297,   294,
     249,   275,   542,   214,   110,   542,   298,   145,   386,   175,
     187,   275,   542,   214,   110,   542,   298,   145,   386,   175,
      -1,   364,   365,    -1,   365,   364,    -1,    -1,   287,    -1,
     288,    -1,    -1,   290,    -1,   289,    -1,    25,    52,   170,
      -1,    25,    52,   184,    -1,   145,   175,    -1,   145,   381,
     175,    -1,   145,   175,    86,   511,    -1,   145,   381,   175,
      86,   511,    -1,   228,   369,    -1,   142,   370,   386,   172,
      -1,   370,   371,   179,    -1,    -1,   371,    99,   372,    -1,
      25,   372,    -1,   350,    -1,   350,   132,   389,    -1,    50,
     110,   542,   132,   389,    -1,   229,   227,   389,    -1,   233,
     145,   389,   175,   369,    -1,   230,   231,    -1,   232,   231,
      -1,    25,   378,    -1,    25,    38,   378,    -1,    25,    37,
     378,    -1,   379,    -1,    39,   379,    -1,    35,   379,    -1,
      36,   380,    -1,    34,   542,   367,   384,    -1,    34,   542,
     367,   127,    -1,    34,   542,   367,   369,    -1,    34,   542,
     367,   127,    -1,   382,    -1,   381,    99,   382,    -1,   110,
     542,    -1,   110,   542,   510,    -1,   142,   386,   172,    -1,
     142,   386,   172,    -1,   386,    -1,   388,    -1,   388,   387,
      -1,   179,    -1,   387,   388,   179,    -1,   389,    -1,   388,
      99,   389,    -1,   390,    -1,   427,    -1,   430,    -1,   433,
      -1,   434,    -1,   529,    -1,   530,    -1,   532,    -1,   531,
      -1,   533,    -1,   536,    -1,   544,    -1,   374,    -1,   375,
      -1,   376,    -1,   373,    -1,   368,    -1,   399,   391,    -1,
     174,   389,    -1,    56,   268,    -1,    57,   268,    -1,   206,
      -1,   246,    -1,    60,   246,    -1,   393,   411,    61,   389,
      -1,   393,    61,   389,    -1,    54,   392,   410,   394,   394,
      -1,    54,   392,   410,   394,    -1,    62,   110,   542,    -1,
     401,    -1,   406,    -1,   395,    -1,   397,    -1,   415,    -1,
     420,    -1,   416,    -1,   396,    -1,   397,    -1,   399,   398,
      -1,    54,   110,    -1,    55,    54,   110,    -1,   400,   402,
      -1,   403,    -1,   402,    99,   110,   403,    -1,   542,   136,
     389,    -1,   542,   510,   136,   389,    -1,   542,   404,   136,
     389,    -1,   542,   510,   404,   136,   389,    -1,   542,   405,
     136,   389,    -1,   542,   510,   405,   136,   389,    -1,   542,
     404,   405,   136,   389,    -1,   542,   510,   404,   405,   136,
     389,    -1,    88,   110,   542,    -1,   262,   110,   542,    -1,
      51,   110,   407,    -1,   409,    -1,   407,    99,   110,   409,
      -1,   414,    -1,   408,    99,   110,   414,    -1,   542,   132,
     389,    -1,   542,   510,   132,   389,    -1,   542,   405,   132,
     389,    -1,   542,   510,   405,   132,   389,    -1,   110,   542,
     136,   389,    -1,   110,   542,   510,   136,   389,    -1,   412,
      -1,   110,   542,    -1,   110,   542,   412,    -1,   404,    -1,
     404,   413,    -1,   413,    -1,    58,   110,   542,    59,   110,
     542,    -1,    59,   110,   542,    -1,    58,   110,   542,    -1,
     542,    -1,   200,   389,    -1,   160,   159,   417,    -1,   418,
      -1,   417,    99,   418,    -1,   110,   542,    -1,   110,   542,
     419,    -1,    98,   540,    -1,   158,   159,   421,    -1,    45,
     158,   159,   421,    -1,   422,    -1,   421,    99,   422,    -1,
     389,    -1,   389,   423,    -1,   424,    -1,   425,    -1,   426,
      -1,   424,   425,    -1,   424,   426,    -1,   425,   426,    -1,
     424,   425,   426,    -1,    87,    -1,   108,    -1,   117,   118,
      -1,   117,   119,    -1,    98,   540,    -1,    44,   110,   428,
     176,   389,    -1,   125,   110,   428,   176,   389,    -1,   429,
      -1,   428,    99,   110,   429,    -1,   542,   136,   389,    -1,
     542,   510,   136,   389,    -1,    29,   145,   386,   175,   431,
     105,   174,   389,    -1,    29,   145,   386,   175,   431,   105,
     110,   542,   174,   389,    -1,   432,    -1,   431,   432,    -1,
      92,   511,   174,   389,    -1,    92,   110,   542,    86,   511,
     174,   389,    -1,    40,   145,   386,   175,   186,   389,   116,
     389,    -1,   435,    -1,   434,   156,   435,    -1,   436,    -1,
     435,    84,   436,    -1,   438,    -1,   438,   451,   438,    -1,
     438,   452,   438,    -1,   438,   122,   438,    -1,   438,   151,
     438,    -1,    -1,   438,   146,   437,   438,    -1,   438,   144,
     438,    -1,   438,   133,   438,    -1,   438,   131,   438,    -1,
     439,    -1,   439,   251,   545,    -1,   439,   251,   545,   579,
      -1,   440,    -1,   440,   187,   440,    -1,   441,    -1,   440,
     164,   441,    -1,   440,   147,   441,    -1,   442,    -1,   441,
     182,   442,    -1,   441,   109,   442,    -1,   441,   135,   442,
      -1,   441,   148,   442,    -1,   443,    -1,   442,   189,   443,
      -1,   442,   198,   443,    -1,   444,    -1,   443,   139,   444,
      -1,   443,   126,   444,    -1,   445,    -1,   445,    68,   220,
     511,    -1,   446,    -1,   446,   188,    86,   511,    -1,   447,
      -1,   447,    93,    86,   509,    -1,   448,    -1,   448,    94,
      86,   509,    -1,   450,    -1,   449,   450,    -1,   164,    -1,
     147,    -1,   449,   164,    -1,   449,   147,    -1,   453,    -1,
     457,    -1,   454,    -1,   191,    -1,   196,    -1,   195,    -1,
     194,    -1,   193,    -1,   192,    -1,   140,    -1,   167,    -1,
     130,    -1,    28,   142,   386,   172,    -1,    28,   211,   142,
     386,   172,    -1,    28,   210,   142,   386,   172,    -1,    28,
      86,   525,   142,   386,   172,    -1,   455,   142,   172,    -1,
     455,   142,   386,   172,    -1,   456,    -1,   455,   456,    -1,
     165,   542,    15,    -1,   165,    16,    -1,   458,    -1,   458,
     459,    -1,   181,   459,    -1,   459,    -1,   180,    -1,   460,
      -1,   460,   180,   459,    -1,   460,   181,   459,    -1,   461,
      -1,   470,    -1,   462,    -1,   462,   471,    -1,   465,    -1,
     465,   471,    -1,   463,   467,    -1,   464,    -1,    97,    -1,
     106,    -1,    90,    -1,   178,    -1,   107,    -1,   129,    -1,
     128,    -1,   467,    -1,    91,   467,    -1,   466,   467,    -1,
     112,    -1,   161,    -1,    82,    -1,   169,    -1,   168,    -1,
      83,    -1,   515,    -1,   468,    -1,   542,    -1,   469,    -1,
     182,    -1,    10,    -1,    17,    -1,   473,    -1,   473,   471,
      -1,   472,    -1,   471,   472,    -1,   143,   386,   173,    -1,
     474,    -1,   476,    -1,   477,    -1,   478,    -1,   481,    -1,
     483,    -1,   479,    -1,   480,    -1,   475,    -1,   527,    -1,
     102,    -1,   138,    -1,   114,    -1,   110,   542,    -1,   145,
     175,    -1,   145,   386,   175,    -1,   111,    -1,   157,   142,
     386,   172,    -1,   190,   142,   386,   172,    -1,   542,   145,
     175,    -1,   542,   145,   482,   175,    -1,   389,    -1,   482,
      99,   389,    -1,   484,    -1,   502,    -1,   485,    -1,   499,
      -1,   500,    -1,   146,   542,   489,   120,    -1,   146,   542,
     487,   489,   120,    -1,   146,   542,   489,   185,   183,   542,
     489,   185,    -1,   146,   542,   489,   185,   486,   183,   542,
     489,   185,    -1,   146,   542,   487,   489,   185,   183,   542,
     489,   185,    -1,   146,   542,   487,   489,   185,   486,   183,
     542,   489,   185,    -1,   497,    -1,   486,   497,    -1,   488,
      -1,   487,   488,    -1,    27,   542,   489,   122,   489,   490,
      -1,    -1,    27,    -1,   171,   491,   171,    -1,    85,   493,
      85,    -1,    -1,   492,    -1,   124,    -1,   495,    -1,   492,
     124,    -1,   492,   495,    -1,    -1,   494,    -1,   123,    -1,
     496,    -1,   494,   123,    -1,   494,   496,    -1,    19,    -1,
     498,    -1,     4,    -1,   498,    -1,   484,    -1,     9,    -1,
     501,    -1,   498,    -1,     8,    -1,   113,    -1,   115,    -1,
     383,    -1,   201,    21,   202,    -1,   201,   202,    -1,   162,
     541,   163,    -1,   162,   541,     7,    -1,    95,     6,    -1,
     503,    -1,   504,    -1,   505,    -1,   506,    -1,   507,    -1,
     508,    -1,    31,   142,   386,   172,    -1,    30,   542,   142,
     172,    -1,    30,   542,   142,   386,   172,    -1,    30,   142,
     386,   172,   142,   172,    -1,    30,   142,   386,   172,   142,
     386,   172,    -1,    89,   542,   142,   172,    -1,    89,   542,
     142,   386,   172,    -1,    89,   142,   386,   172,   142,   172,
      -1,    89,   142,   386,   172,   142,   386,   172,    -1,    32,
     142,   386,   172,    -1,    33,   142,   386,   172,    -1,    42,
     541,   142,   172,    -1,    42,   541,   142,   386,   172,    -1,
      42,   142,   386,   172,   142,   172,    -1,    42,   142,   386,
     172,   142,   386,   172,    -1,   514,    -1,   514,   134,    -1,
      86,   511,    -1,   513,    -1,   513,   512,    -1,   199,   145,
     175,    -1,   134,    -1,   182,    -1,   164,    -1,   514,    -1,
     515,    -1,   141,   145,   175,    -1,   542,    -1,   517,    -1,
     523,    -1,   521,    -1,   524,    -1,   522,    -1,   520,    -1,
     519,    -1,   518,    -1,   516,    -1,   214,   145,   175,    -1,
      66,   145,   175,    -1,    66,   145,   523,   175,    -1,    66,
     145,   524,   175,    -1,    32,   145,   175,    -1,    33,   145,
     175,    -1,    42,   145,   175,    -1,    42,   145,   541,   175,
      -1,    42,   145,    20,   175,    -1,    89,   145,   175,    -1,
      89,   145,   542,   175,    -1,    89,   145,   542,    99,   525,
     175,    -1,    89,   145,   182,   175,    -1,    89,   145,   182,
      99,   525,   175,    -1,   177,   542,   175,    -1,    30,   145,
     175,    -1,    30,   145,   542,   175,    -1,    30,   145,   542,
      99,   525,   175,    -1,    30,   145,   542,    99,   526,   175,
      -1,    30,   145,   182,   175,    -1,    30,   145,   182,    99,
     525,   175,    -1,    30,   145,   182,    99,   526,   175,    -1,
      65,   145,   542,   175,    -1,   542,    -1,   542,   134,    -1,
      20,    -1,    25,   209,   210,    -1,    25,   209,   211,    -1,
      25,   209,   212,    -1,   215,   214,   389,   222,   389,    -1,
     215,   214,   389,    86,   221,   222,   389,    -1,   215,   214,
     389,    86,   223,   222,   389,    -1,   215,   214,   389,   207,
     389,    -1,   215,   214,   389,   208,   389,    -1,   215,   216,
     389,   222,   389,    -1,   215,   216,   389,    86,   221,   222,
     389,    -1,   215,   216,   389,    86,   223,   222,   389,    -1,
     215,   216,   389,   207,   389,    -1,   215,   216,   389,   208,
     389,    -1,   213,   214,   389,    -1,   213,   216,   389,    -1,
     218,   214,   389,   226,   389,    -1,   218,   219,   220,   214,
     389,   226,   389,    -1,   217,   214,   389,    86,   389,    -1,
     225,   110,   534,   224,   389,   174,   389,    -1,   535,    -1,
     534,    99,   110,   535,    -1,   542,   132,   389,    -1,   234,
     142,   386,   172,   537,    -1,   538,    -1,   537,   538,    -1,
     235,   539,   384,    -1,   235,   539,   145,   110,   542,   175,
     384,    -1,   235,   539,   145,   110,   542,    99,   110,   542,
     175,   384,    -1,   235,   539,   145,   110,   542,    99,   110,
     542,    99,   110,   542,   175,   384,    -1,   468,    -1,   539,
     198,   468,    -1,    20,    -1,    14,    -1,   542,    -1,    18,
      -1,   543,    -1,   203,    -1,   117,    -1,    89,    -1,    33,
      -1,    66,    -1,    30,    -1,   141,    -1,    40,    -1,   214,
      -1,    42,    -1,    69,    -1,    65,    -1,    32,    -1,    29,
      -1,   199,    -1,    70,    -1,   240,    -1,    64,    -1,   211,
      -1,   210,    -1,   135,    -1,    31,    -1,   252,    -1,   239,
      -1,   242,    -1,   241,    -1,   269,    -1,   270,    -1,   273,
      -1,   271,    -1,   274,    -1,   245,    -1,   247,    -1,    47,
      -1,   206,    -1,   246,    -1,    43,    -1,   212,    -1,   225,
      -1,   219,    -1,   191,    -1,   196,    -1,   195,    -1,   194,
      -1,   193,    -1,   192,    -1,    88,    -1,   103,    -1,   104,
      -1,   174,    -1,    54,    -1,    55,    -1,    56,    -1,    57,
      -1,    58,    -1,    59,    -1,    60,    -1,    61,    -1,    62,
      -1,   136,    -1,    51,    -1,   200,    -1,   159,    -1,   160,
      -1,   158,    -1,    45,    -1,    87,    -1,   108,    -1,   118,
      -1,   119,    -1,    98,    -1,    44,    -1,   125,    -1,   176,
      -1,    92,    -1,    86,    -1,   186,    -1,   116,    -1,   156,
      -1,    84,    -1,    68,    -1,   220,    -1,    93,    -1,   187,
      -1,   109,    -1,   148,    -1,   189,    -1,   139,    -1,   126,
      -1,    28,    -1,    94,    -1,   188,    -1,   140,    -1,   170,
      -1,   184,    -1,   149,    -1,   127,    -1,   121,    -1,   155,
      -1,   137,    -1,   154,    -1,    25,    -1,    52,    -1,    63,
      -1,   105,    -1,    67,    -1,    46,    -1,   204,    -1,    41,
      -1,    48,    -1,    26,    -1,    34,    -1,   262,    -1,   251,
      -1,   267,    -1,   268,    -1,   244,    -1,   257,    -1,   265,
      -1,   261,    -1,   243,    -1,   256,    -1,   266,    -1,   260,
      -1,   255,    -1,   254,    -1,   238,    -1,   237,    -1,   259,
      -1,   248,    -1,   249,    -1,   272,    -1,   264,    -1,   263,
      -1,   258,    -1,   218,    -1,   224,    -1,   221,    -1,   215,
      -1,   208,    -1,   207,    -1,   209,    -1,   226,    -1,   216,
      -1,   217,    -1,   223,    -1,   213,    -1,   222,    -1,    39,
      -1,    36,    -1,    35,    -1,    37,    -1,    38,    -1,   157,
      -1,   190,    -1,   227,    -1,   228,    -1,   229,    -1,   231,
      -1,   233,    -1,   230,    -1,   232,    -1,   234,    -1,   235,
      -1,    53,    -1,   236,    -1,    50,    -1,   283,    -1,   281,
      -1,   282,    -1,   286,    -1,   284,    -1,   285,    -1,    71,
      -1,    72,    -1,    73,    -1,    74,    -1,    75,    -1,    76,
      -1,    77,    -1,    78,    -1,    79,    -1,    80,    -1,    81,
      -1,   275,    -1,   276,    -1,   277,    -1,   278,    -1,   279,
      -1,   280,    -1,   287,    -1,   288,    -1,   289,    -1,   290,
      -1,   291,    -1,   292,    -1,   293,    -1,   294,    -1,   295,
      -1,   296,    -1,   297,    -1,   298,    -1,   236,   110,   408,
      53,   142,   389,   172,    -1,    53,   142,   389,   172,    -1,
     547,    -1,   547,   546,    -1,   547,   267,   439,    -1,   547,
     546,   267,   439,    -1,   556,    -1,   554,    -1,   546,   556,
      -1,   546,   554,    -1,   548,    -1,   547,   253,   548,    -1,
     549,    -1,   548,   250,   549,    -1,   550,    -1,   549,   252,
     136,   550,    -1,   551,    -1,   252,   551,    -1,   552,    -1,
     552,   575,    -1,   145,   545,   175,    -1,   553,    -1,   553,
     571,    -1,   474,    -1,   142,   386,   172,    -1,   555,    -1,
     574,    -1,   573,    -1,   576,    -1,   570,    -1,   157,    -1,
     557,    -1,   558,    -1,   559,    -1,   560,    -1,   563,    -1,
     568,    -1,   569,    -1,   256,    -1,   266,    -1,    92,   239,
      -1,    92,   242,    -1,   226,   241,    -1,   269,   241,    -1,
     241,   239,    -1,   241,   242,    -1,   226,   270,    -1,   269,
     270,    -1,   226,   273,   562,    -1,   226,   273,   105,    -1,
     226,   273,   145,   562,   175,    -1,   226,   273,   145,   562,
      99,   561,   175,    -1,   226,   273,   145,   105,   175,    -1,
     226,   273,   145,   105,    99,   561,   175,    -1,   269,   273,
      -1,   562,    -1,   561,    99,   562,    -1,    88,    20,    -1,
      88,    20,   260,    20,    -1,    88,    20,   572,   255,    -1,
      88,    20,   260,    20,   572,   255,    -1,   226,   271,   272,
     565,    -1,   226,   271,   272,   565,   564,    -1,   226,   105,
     271,   272,    -1,   226,   105,   271,   272,   564,    -1,   269,
     271,   272,    -1,   567,    -1,   564,   567,    -1,    88,    20,
      -1,   145,   566,   175,    -1,    20,    -1,   566,    20,    -1,
     189,   565,    -1,   126,   565,    -1,   254,    20,    -1,   226,
     274,    -1,   269,   274,    -1,    88,   206,    -1,    88,   246,
      -1,   245,   247,    -1,   238,    -1,   238,    47,    -1,   237,
      -1,   237,   272,    -1,   259,    -1,   248,   442,    -1,    88,
     119,   442,    -1,    88,    43,   442,    -1,   249,   442,   187,
     442,    -1,   244,   572,   577,    -1,   268,   442,   577,    -1,
     257,   572,   265,    -1,   261,   578,    -1,   243,   578,    -1,
     272,    -1,   264,    -1,   258,    -1,   263,    -1,   258,    -1,
     269,   247,   442,    -1
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
     344,   351,   355,   360,   366,   373,   378,   384,   391,   399,
     401,   404,   406,   408,   410,   412,   414,   416,   419,   422,
     432,   434,   437,   441,   443,   446,   449,   450,   452,   454,
     457,   461,   463,   466,   469,   473,   486,   503,   518,   533,
     561,   564,   567,   568,   570,   572,   573,   575,   577,   581,
     585,   588,   592,   597,   603,   606,   611,   615,   616,   620,
     623,   625,   629,   635,   639,   645,   648,   651,   654,   658,
     662,   664,   667,   670,   673,   678,   683,   688,   693,   695,
     699,   702,   706,   710,   714,   716,   718,   721,   723,   727,
     729,   733,   735,   737,   739,   741,   743,   745,   747,   749,
     751,   753,   755,   757,   759,   761,   763,   765,   767,   770,
     773,   776,   779,   781,   783,   786,   791,   795,   801,   806,
     810,   812,   814,   816,   818,   820,   822,   824,   826,   828,
     831,   834,   838,   841,   843,   848,   852,   857,   862,   868,
     873,   879,   885,   892,   896,   900,   904,   906,   911,   913,
     918,   922,   927,   932,   938,   943,   949,   951,   954,   958,
     960,   963,   965,   972,   976,   980,   982,   985,   989,   991,
     995,   998,  1002,  1005,  1009,  1014,  1016,  1020,  1022,  1025,
    1027,  1029,  1031,  1034,  1037,  1040,  1044,  1046,  1048,  1051,
    1054,  1057,  1063,  1069,  1071,  1076,  1080,  1085,  1094,  1105,
    1107,  1110,  1115,  1123,  1132,  1134,  1138,  1140,  1144,  1146,
    1150,  1154,  1158,  1162,  1163,  1168,  1172,  1176,  1180,  1182,
    1186,  1191,  1193,  1197,  1199,  1203,  1207,  1209,  1213,  1217,
    1221,  1225,  1227,  1231,  1235,  1237,  1241,  1245,  1247,  1252,
    1254,  1259,  1261,  1266,  1268,  1273,  1275,  1278,  1280,  1282,
    1285,  1288,  1290,  1292,  1294,  1296,  1298,  1300,  1302,  1304,
    1306,  1308,  1310,  1312,  1317,  1323,  1329,  1336,  1340,  1345,
    1347,  1350,  1354,  1357,  1359,  1362,  1365,  1367,  1369,  1371,
    1375,  1379,  1381,  1383,  1385,  1388,  1390,  1393,  1396,  1398,
    1400,  1402,  1404,  1406,  1408,  1410,  1412,  1414,  1417,  1420,
    1422,  1424,  1426,  1428,  1430,  1432,  1434,  1436,  1438,  1440,
    1442,  1444,  1446,  1448,  1451,  1453,  1456,  1460,  1462,  1464,
    1466,  1468,  1470,  1472,  1474,  1476,  1478,  1480,  1482,  1484,
    1486,  1489,  1492,  1496,  1498,  1503,  1508,  1512,  1517,  1519,
    1523,  1525,  1527,  1529,  1531,  1533,  1538,  1544,  1553,  1563,
    1573,  1584,  1586,  1589,  1591,  1594,  1601,  1602,  1604,  1608,
    1612,  1613,  1615,  1617,  1619,  1622,  1625,  1626,  1628,  1630,
    1632,  1635,  1638,  1640,  1642,  1644,  1646,  1648,  1650,  1652,
    1654,  1656,  1658,  1660,  1662,  1666,  1669,  1673,  1677,  1680,
    1682,  1684,  1686,  1688,  1690,  1692,  1697,  1702,  1708,  1715,
    1723,  1728,  1734,  1741,  1749,  1754,  1759,  1764,  1770,  1777,
    1785,  1787,  1790,  1793,  1795,  1798,  1802,  1804,  1806,  1808,
    1810,  1812,  1816,  1818,  1820,  1822,  1824,  1826,  1828,  1830,
    1832,  1834,  1836,  1840,  1844,  1849,  1854,  1858,  1862,  1866,
    1871,  1876,  1880,  1885,  1892,  1897,  1904,  1908,  1912,  1917,
    1924,  1931,  1936,  1943,  1950,  1955,  1957,  1960,  1962,  1966,
    1970,  1974,  1980,  1988,  1996,  2002,  2008,  2014,  2022,  2030,
    2036,  2042,  2046,  2050,  2056,  2064,  2070,  2078,  2080,  2085,
    2089,  2095,  2097,  2100,  2104,  2112,  2123,  2137,  2139,  2143,
    2145,  2147,  2149,  2151,  2153,  2155,  2157,  2159,  2161,  2163,
    2165,  2167,  2169,  2171,  2173,  2175,  2177,  2179,  2181,  2183,
    2185,  2187,  2189,  2191,  2193,  2195,  2197,  2199,  2201,  2203,
    2205,  2207,  2209,  2211,  2213,  2215,  2217,  2219,  2221,  2223,
    2225,  2227,  2229,  2231,  2233,  2235,  2237,  2239,  2241,  2243,
    2245,  2247,  2249,  2251,  2253,  2255,  2257,  2259,  2261,  2263,
    2265,  2267,  2269,  2271,  2273,  2275,  2277,  2279,  2281,  2283,
    2285,  2287,  2289,  2291,  2293,  2295,  2297,  2299,  2301,  2303,
    2305,  2307,  2309,  2311,  2313,  2315,  2317,  2319,  2321,  2323,
    2325,  2327,  2329,  2331,  2333,  2335,  2337,  2339,  2341,  2343,
    2345,  2347,  2349,  2351,  2353,  2355,  2357,  2359,  2361,  2363,
    2365,  2367,  2369,  2371,  2373,  2375,  2377,  2379,  2381,  2383,
    2385,  2387,  2389,  2391,  2393,  2395,  2397,  2399,  2401,  2403,
    2405,  2407,  2409,  2411,  2413,  2415,  2417,  2419,  2421,  2423,
    2425,  2427,  2429,  2431,  2433,  2435,  2437,  2439,  2441,  2443,
    2445,  2447,  2449,  2451,  2453,  2455,  2457,  2459,  2461,  2463,
    2465,  2467,  2469,  2471,  2473,  2475,  2477,  2479,  2481,  2483,
    2485,  2487,  2489,  2491,  2493,  2495,  2497,  2499,  2501,  2503,
    2505,  2507,  2509,  2511,  2513,  2515,  2517,  2519,  2521,  2523,
    2525,  2527,  2529,  2531,  2533,  2535,  2537,  2539,  2541,  2543,
    2545,  2547,  2549,  2551,  2553,  2555,  2557,  2565,  2570,  2572,
    2575,  2579,  2584,  2586,  2588,  2591,  2594,  2596,  2600,  2602,
    2606,  2608,  2613,  2615,  2618,  2620,  2623,  2627,  2629,  2632,
    2634,  2638,  2640,  2642,  2644,  2646,  2648,  2650,  2652,  2654,
    2656,  2658,  2660,  2662,  2664,  2666,  2668,  2671,  2674,  2677,
    2680,  2683,  2686,  2689,  2692,  2696,  2700,  2706,  2714,  2720,
    2728,  2731,  2733,  2737,  2740,  2745,  2750,  2757,  2762,  2768,
    2773,  2779,  2783,  2785,  2788,  2791,  2795,  2797,  2800,  2803,
    2806,  2809,  2812,  2815,  2818,  2821,  2824,  2826,  2829,  2831,
    2834,  2836,  2839,  2843,  2847,  2852,  2856,  2860,  2864,  2867,
    2870,  2872,  2874,  2876,  2878,  2880
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   941,   941,   942,   952,   957,   963,   968,   980,   985,
     995,  1002,  1014,  1020,  1032,  1045,  1049,  1053,  1065,  1071,
    1085,  1091,  1105,  1106,  1107,  1108,  1114,  1115,  1116,  1117,
    1120,  1123,  1126,  1129,  1131,  1137,  1142,  1151,  1157,  1166,
    1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,
    1191,  1192,  1193,  1194,  1195,  1196,  1197,  1200,  1207,  1208,
    1220,  1232,  1237,  1248,  1254,  1266,  1279,  1290,  1295,  1307,
    1312,  1323,  1329,  1335,  1341,  1360,  1371,  1382,  1389,  1396,
    1403,  1416,  1422,  1437,  1441,  1451,  1458,  1466,  1473,  1486,
    1493,  1499,  1506,  1512,  1516,  1523,  1534,  1539,  1548,  1557,
    1564,  1574,  1582,  1590,  1598,  1606,  1612,  1620,  1628,  1639,
    1645,  1653,  1657,  1661,  1665,  1669,  1673,  1682,  1686,  1694,
    1706,  1711,  1718,  1725,  1730,  1737,  1744,  1748,  1753,  1761,
    1767,  1776,  1781,  1788,  1795,  1806,  1818,  1830,  1842,  1854,
    1877,  1880,  1884,  1888,  1892,  1899,  1903,  1907,  1918,  1923,
    1935,  1939,  1943,  1947,  1954,  1961,  1987,  1997,  2003,  2009,
    2018,  2028,  2041,  2049,  2056,  2070,  2074,  2081,  2086,  2093,
    2101,  2105,  2109,  2117,  2124,  2133,  2145,  2154,  2167,  2175,
    2189,  2196,  2209,  2217,  2228,  2243,  2247,  2263,  2267,  2276,
    2280,  2297,  2298,  2299,  2300,  2301,  2304,  2305,  2306,  2307,
    2308,  2310,  2311,  2314,  2315,  2316,  2317,  2318,  2325,  2338,
    2345,  2349,  2357,  2361,  2365,  2372,  2376,  2383,  2391,  2402,
    2412,  2413,  2414,  2418,  2418,  2418,  2418,  2418,  2421,  2427,
    2436,  2440,  2450,  2461,  2467,  2481,  2489,  2498,  2508,  2519,
    2528,  2538,  2548,  2564,  2577,  2589,  2601,  2607,  2619,  2625,
    2639,  2648,  2658,  2667,  2680,  2687,  2698,  2699,  2704,  2713,
    2717,  2722,  2726,  2732,  2737,  2745,  2761,  2769,  2776,  2782,
    2793,  2800,  2810,  2820,  2825,  2837,  2843,  2857,  2863,  2875,
    2882,  2889,  2896,  2903,  2910,  2917,  2930,  2934,  2944,  2948,
    2958,  2969,  2976,  2989,  2996,  3008,  3015,  3029,  3036,  3051,
    3057,  3069,  3075,  3089,  3100,  3104,  3115,  3119,  3138,  3142,
    3150,  3158,  3166,  3174,  3174,  3182,  3190,  3198,  3212,  3216,
    3223,  3236,  3240,  3251,  3255,  3259,  3269,  3273,  3277,  3281,
    3285,  3295,  3299,  3304,  3315,  3319,  3323,  3333,  3337,  3349,
    3353,  3365,  3369,  3381,  3385,  3397,  3401,  3413,  3417,  3421,
    3425,  3437,  3441,  3445,  3455,  3459,  3463,  3467,  3471,  3475,
    3485,  3489,  3493,  3503,  3507,  3511,  3515,  3527,  3533,  3545,
    3551,  3565,  3572,  3613,  3617,  3621,  3625,  3637,  3647,  3658,
    3663,  3673,  3677,  3687,  3693,  3699,  3705,  3717,  3723,  3734,
    3738,  3742,  3746,  3750,  3754,  3758,  3768,  3772,  3782,  3786,
    3797,  3801,  3805,  3809,  3813,  3828,  3832,  3842,  3846,  3856,
    3863,  3870,  3883,  3887,  3899,  3905,  3919,  3930,  3934,  3938,
    3942,  3946,  3950,  3954,  3958,  3968,  3972,  3982,  3987,  3992,
    4003,  4014,  4018,  4029,  4039,  4050,  4106,  4112,  4124,  4130,
    4142,  4146,  4156,  4160,  4164,  4174,  4182,  4190,  4198,  4206,
    4214,  4229,  4235,  4247,  4253,  4266,  4275,  4277,  4283,  4288,
    4300,  4303,  4310,  4316,  4322,  4330,  4345,  4348,  4355,  4361,
    4367,  4375,  4389,  4394,  4405,  4410,  4421,  4426,  4431,  4437,
    4449,  4455,  4460,  4465,  4476,  4481,  4496,  4501,  4518,  4533,
    4537,  4541,  4545,  4549,  4553,  4563,  4574,  4580,  4586,  4591,
    4613,  4619,  4625,  4630,  4641,  4651,  4661,  4667,  4673,  4678,
    4689,  4695,  4707,  4718,  4724,  4730,  4767,  4772,  4777,  4788,
    4792,  4796,  4806,  4817,  4821,  4825,  4829,  4833,  4837,  4841,
    4845,  4849,  4859,  4869,  4873,  4878,  4889,  4899,  4909,  4913,
    4917,  4927,  4933,  4939,  4945,  4951,  4963,  4974,  4981,  4988,
    4995,  5002,  5009,  5016,  5029,  5050,  5057,  5077,  5117,  5121,
    5125,  5134,  5140,  5146,  5152,  5158,  5165,  5171,  5177,  5183,
    5189,  5201,  5206,  5216,  5222,  5234,  5260,  5271,  5277,  5290,
    5306,  5313,  5319,  5330,  5337,  5347,  5358,  5374,  5380,  5390,
    5399,  5400,  5418,  5422,  5429,  5430,  5431,  5432,  5433,  5434,
    5435,  5436,  5437,  5438,  5439,  5440,  5441,  5442,  5443,  5444,
    5445,  5446,  5447,  5448,  5449,  5450,  5451,  5452,  5453,  5454,
    5455,  5456,  5457,  5458,  5459,  5460,  5461,  5462,  5463,  5464,
    5465,  5466,  5467,  5468,  5469,  5470,  5471,  5472,  5473,  5474,
    5475,  5476,  5477,  5478,  5479,  5480,  5481,  5482,  5483,  5484,
    5485,  5486,  5487,  5488,  5489,  5490,  5491,  5492,  5493,  5494,
    5495,  5496,  5497,  5498,  5499,  5500,  5501,  5502,  5503,  5504,
    5505,  5506,  5507,  5508,  5509,  5510,  5511,  5512,  5513,  5514,
    5515,  5516,  5517,  5518,  5519,  5520,  5521,  5522,  5523,  5524,
    5525,  5526,  5527,  5528,  5529,  5530,  5531,  5532,  5533,  5534,
    5535,  5536,  5537,  5538,  5539,  5540,  5541,  5542,  5543,  5544,
    5545,  5546,  5547,  5548,  5549,  5550,  5551,  5552,  5553,  5554,
    5555,  5556,  5557,  5558,  5559,  5560,  5561,  5562,  5563,  5564,
    5565,  5566,  5567,  5568,  5569,  5570,  5571,  5572,  5573,  5574,
    5575,  5576,  5577,  5578,  5579,  5580,  5581,  5582,  5583,  5584,
    5585,  5586,  5587,  5588,  5589,  5590,  5591,  5592,  5593,  5594,
    5595,  5596,  5597,  5598,  5599,  5600,  5601,  5602,  5603,  5604,
    5605,  5606,  5607,  5608,  5609,  5610,  5611,  5612,  5613,  5614,
    5615,  5616,  5617,  5618,  5619,  5620,  5621,  5622,  5623,  5624,
    5625,  5626,  5627,  5628,  5629,  5630,  5641,  5647,  5664,  5668,
    5672,  5676,  5686,  5689,  5692,  5695,  5704,  5707,  5716,  5719,
    5728,  5731,  5740,  5743,  5752,  5755,  5758,  5767,  5770,  5779,
    5783,  5793,  5796,  5799,  5802,  5805,  5814,  5823,  5827,  5831,
    5835,  5839,  5843,  5847,  5857,  5860,  5863,  5866,  5875,  5878,
    5881,  5884,  5893,  5896,  5905,  5908,  5911,  5914,  5917,  5920,
    5923,  5932,  5935,  5944,  5947,  5950,  5953,  5962,  5965,  5968,
    5971,  5974,  5983,  5986,  5995,  5998,  6007,  6010,  6019,  6022,
    6031,  6040,  6043,  6052,  6055,  6058,  6067,  6070,  6073,  6076,
    6079,  6088,  6092,  6096,  6100,  6110,  6119,  6129,  6138,  6141,
    6150,  6153,  6156,  6165,  6168,  6177
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
     305,   306,   307,   308,   309,   310,   311,   312,   313
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 10660;
  const int xquery_parser::yynnts_ = 266;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 517;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 314;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 568;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 14208 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6185 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"


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

