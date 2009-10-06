
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
#line 45 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"


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
#line 893 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"

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
#line 777 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 268 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 114: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 776 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 277 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 138: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 775 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 286 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 308: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 295 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 309: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 304 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 310: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 313 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 311: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 322 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 314: /* "Prolog" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 331 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 315: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 340 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 316: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 349 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 317: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 358 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 367 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 376 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 789 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->pair_vector); };

/* Line 480 of lalr1.cc  */
#line 385 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 789 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->pair); };

/* Line 480 of lalr1.cc  */
#line 394 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 403 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 412 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 421 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 430 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 439 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 448 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 457 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 466 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 475 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 484 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 493 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 502 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 511 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 520 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 529 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 538 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 547 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 556 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 565 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 789 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 574 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 583 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 592 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "CollectionModifier" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 601 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "NodeModifier" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 610 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 619 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "IndexDecl2" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 628 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "IndexDecl3" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 637 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "IndexDeclSuffix" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 646 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 655 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 664 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "IndexKeySpec1" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 673 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 682 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 789 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 691 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 700 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "Block" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 709 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "BlockDecls" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 718 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "BlockVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 727 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "BlockVarDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 736 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "AssignExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 745 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "ExitExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 754 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "WhileExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 763 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 772 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 781 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 790 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "FunctionDecl3" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 799 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "FunctionDecl4" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 808 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "EnclosedExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 835 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 844 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 853 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 862 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "ApplyExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 871 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "ConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 880 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 889 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 898 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 907 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 916 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 925 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 934 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 943 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 952 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 961 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 970 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 979 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 988 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 997 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1006 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "EvalVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1015 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1024 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1033 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1042 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1051 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1060 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "EvalVarDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1069 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1078 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1087 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1096 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1105 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1114 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1123 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1132 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1141 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1150 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1159 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1168 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1177 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1186 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1195 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1204 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1213 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1222 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1231 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1240 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1249 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1258 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1267 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1276 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1285 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1294 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1303 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1312 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1321 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1330 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1339 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1348 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1357 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1366 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1375 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1384 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1393 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1402 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1411 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1420 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "PragmaList" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1429 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1438 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1447 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1456 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1465 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1474 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1483 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1492 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1501 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1510 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1519 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1528 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1537 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1546 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1555 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1564 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1573 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1582 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1591 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1600 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1609 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1618 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1627 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1636 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1645 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1654 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1663 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1672 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1681 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1690 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1699 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1708 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1717 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1726 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "Opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1735 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1744 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "Opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1753 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1762 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1771 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1780 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1789 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1798 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1807 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1816 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1825 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1834 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1843 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1852 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1861 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1870 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1879 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1888 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1897 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1906 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1915 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1924 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1933 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1942 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1951 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1960 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1969 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1978 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1987 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1996 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2005 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2014 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2023 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2032 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2041 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2050 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2059 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2068 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2077 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2086 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2095 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2104 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2113 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2122 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2131 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2140 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2149 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 789 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2158 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2167 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "EvalExpr" */

/* Line 480 of lalr1.cc  */
#line 787 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2176 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
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
#line 94 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename);
}

/* Line 553 of lalr1.cc  */
#line 2261 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"

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
#line 911 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 921 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		}
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 926 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<MainModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr ((yyval.node));
		}
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 932 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
       driver.set_expr ((yyval.node));
		}
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 937 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
       driver.set_expr ((yyval.node));
		}
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 943 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
       driver.set_expr ((yyval.node));
    }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 948 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
       driver.set_expr ((yyval.node));
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 960 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)), encoding);
		}
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 965 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
    }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 975 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)));
		}
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 982 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)),
                NULL);
		}
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 994 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC ((yyloc)), false,
                             static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)),
                             NULL);
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1000 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LibraryModule(LOC ((yyloc)), false,
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1012 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), 
								SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
      dynamic_cast<ModuleDecl *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
		}
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1025 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC ((yyloc)), true,
                             static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)),
                             NULL);
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1031 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LibraryModule(LOC ((yyloc)), true,
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1043 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), 
								SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
      dynamic_cast<ModuleDecl *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
		}
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1056 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)),
								NULL);
		}
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1062 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								NULL,
								static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		}
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 1068 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
								static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 1080 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = new SIND_DeclList(LOC ((yyloc)));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		}
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 1086 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (sindList_p) {
				sindList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 1100 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = new VFO_DeclList(LOC ((yyloc)));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		}
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 1106 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (vfoList_p) {
				vfoList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1149 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].pair_vector));
      delete (yysemantic_stack_[(4) - (4)].pair_vector);
    }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1154 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr))->get_qname(), (yysemantic_stack_[(4) - (4)].pair_vector)); 
      delete (yysemantic_stack_[(4) - (3)].expr);
      delete (yysemantic_stack_[(4) - (4)].pair_vector);
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1163 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { 
      (yyval.pair_vector) = new std::vector<std::pair<std::string, std::string> > ();
      (yyval.pair_vector)->push_back(*(yysemantic_stack_[(1) - (1)].pair));
      delete (yysemantic_stack_[(1) - (1)].pair);
    }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1169 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].pair_vector)->push_back(*(yysemantic_stack_[(2) - (2)].pair));
      delete (yysemantic_stack_[(2) - (2)].pair);
      (yyval.pair_vector) = (yysemantic_stack_[(2) - (1)].pair_vector);
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1178 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *s = static_cast<StringLiteral *>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.pair) = new std::pair<std::string, std::string>((yysemantic_stack_[(3) - (1)].strval), s->get_strval());
      delete s;
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1186 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1187 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1188 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1189 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1190 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1191 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1192 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1193 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1194 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1195 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1232 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1244 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		}
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1249 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		}
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1260 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_element_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1266 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_function_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1278 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OptionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
								SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
		}
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1291 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (3)].node));
		}
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1302 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		}
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1307 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		}
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1319 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		}
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1324 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		}
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1335 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::inherit_ns);
		}
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1341 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::no_inherit_ns);
		}
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1347 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::inherit_ns);
		}
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1353 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::no_inherit_ns);
		}
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 1372 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)));
		}
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 1383 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		}
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 1394 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		}
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1401 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)),
								NULL);
		}
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1408 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		}
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1415 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
		}
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1428 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = new URILiteralList(LOC ((yyloc)));
			uri_list_p->push_back(SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		}
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1434 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node));
			if (uri_list_p) {
				uri_list_p->push_back(SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1449 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1453 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		}
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1463 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)), false,
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1470 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)), false,
								SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
								SYMTAB ((yysemantic_stack_[(6) - (6)].sval)),
								NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
		}
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1478 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)), false,
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
		}
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1485 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)), false,
								SYMTAB ((yysemantic_stack_[(8) - (4)].sval)),
								SYMTAB ((yysemantic_stack_[(8) - (6)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
		}
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1493 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)), true,
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1500 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)), true,
								SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
								SYMTAB ((yysemantic_stack_[(6) - (6)].sval)),
								NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
		}
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1508 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)), true,
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
		}
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1515 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)), true,
								SYMTAB ((yysemantic_stack_[(8) - (4)].sval)),
								SYMTAB ((yysemantic_stack_[(8) - (6)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
		}
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1528 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1535 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->type = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1541 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1548 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(1) - (1)].node));
      d->ext = false;
      (yyval.node) = d;
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1554 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), NULL);
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1558 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1565 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1576 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(), NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1581 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
                               dynamic_cast<SequenceType *> ((yysemantic_stack_[(3) - (3)].node)));
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1590 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(5) - (3)].varnametype)));
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								nt->name,
								nt->type,
								(yysemantic_stack_[(5) - (5)].expr));
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
		}
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1599 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (3)].varnametype)));
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       NULL, true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
		}
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 1606 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(6) - (3)].varnametype)));
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       (yysemantic_stack_[(6) - (6)].expr), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
		}
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 1616 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                               0, 0, 0);
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1623 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                               (yysemantic_stack_[(5) - (5)].node), 
                               0, 0);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1630 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                               0, 
                               static_cast<CollectionModifier*>((yysemantic_stack_[(4) - (4)].node)), 
                               0);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1638 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                               (yysemantic_stack_[(6) - (5)].node), 
                               static_cast<CollectionModifier*>((yysemantic_stack_[(6) - (6)].node)), 
                               0);
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1646 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                               0, 
                               0, 
                               static_cast<NodeModifier*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1654 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                               (yysemantic_stack_[(6) - (5)].node), 
                               0, 
                               static_cast<NodeModifier*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1662 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                               0, 
                               static_cast<CollectionModifier*>((yysemantic_stack_[(5) - (4)].node)), 
                               static_cast<NodeModifier*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1670 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                               (yysemantic_stack_[(7) - (5)].node), 
                               static_cast<CollectionModifier*>((yysemantic_stack_[(7) - (6)].node)), 
                               static_cast<NodeModifier*>((yysemantic_stack_[(7) - (7)].node)));
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1681 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionModifier(LOC((yyloc)), CollectionModifier::const_);
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1685 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionModifier(LOC((yyloc)), CollectionModifier::append_only);
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1689 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionModifier(LOC((yyloc)), CollectionModifier::queue);
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1693 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionModifier(LOC((yyloc)), CollectionModifier::mutable_);
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1701 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), NodeModifier::read_only);
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1705 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), NodeModifier::mutable_);
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1713 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1717 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexDecl*>((yysemantic_stack_[(3) - (3)].node))->setUnique();
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1725 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1729 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1733 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexDecl*>((yysemantic_stack_[(2) - (2)].node))->setOrdered();
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1741 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1745 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1749 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexDecl*>((yysemantic_stack_[(2) - (2)].node))->setAutomatic();
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1757 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(7) - (2)].expr)),
                         (yysemantic_stack_[(7) - (4)].expr),
                         dynamic_cast<IndexKeyList*>((yysemantic_stack_[(7) - (6)].node)));
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1767 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* l = new IndexKeyList(LOC((yyloc)));
      l->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1773 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1781 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (1)].node))->setCollation(SYMTAB((yysemantic_stack_[(3) - (3)].sval)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1793 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL);
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1797 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1807 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		}
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1812 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		}
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL);
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1828 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1832 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL, dynamic_cast<SequenceType *> ((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1836 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType *> ((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1843 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1850 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1869 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (1)].node));
      std::auto_ptr<VFO_DeclList> vfo2(dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (2)].node)));
      if ((yysemantic_stack_[(3) - (1)].node) == NULL)
        vfo = new VFO_DeclList (LOC ((yyloc)));
      vfo->push_back (*(vfo2.get()));
      (yyval.node) = vfo;
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1878 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL;
    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1885 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (1)].node));
      vfo->push_back ((yysemantic_stack_[(3) - (3)].node));
      (yyval.node) = vfo;
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1891 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = new VFO_DeclList (LOC ((yyloc)));
      vfo->push_back ((yysemantic_stack_[(2) - (2)].node));
      (yyval.node) = vfo;
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1900 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 151:

/* Line 678 of lalr1.cc  */
#line 1910 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 152:

/* Line 678 of lalr1.cc  */
#line 1923 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr (LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr))->get_qname(), (yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (3)].expr);
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1931 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr (LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1938 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *b = dynamic_cast<BlockBody *> ((yysemantic_stack_[(5) - (5)].expr));
      if (b == NULL) {
        b = new BlockBody ((yysemantic_stack_[(5) - (5)].expr)->get_location ()); 
        b->add ((yysemantic_stack_[(5) - (5)].expr));
      }
      (yyval.expr) = new WhileExpr (LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), b);
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1950 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1954 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::CONTINUE);
    }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 1961 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { 
      dynamic_cast<FunctionDecl *>((yysemantic_stack_[(2) - (2)].node))->setComment(SYMTAB((yysemantic_stack_[(2) - (1)].sval)));
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 1966 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
      d->deterministic = false;
      (yyval.node) = d;
    }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 1973 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<FunctionDecl *>((yysemantic_stack_[(3) - (3)].node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 1981 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 1985 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 1989 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(2) - (2)].node));
      d->type = (d->type == ParseConstants::fn_extern)
        ? ParseConstants::fn_extern_update
        : ParseConstants::fn_update;
      (yyval.node) = d;
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 1997 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2004 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								(yysemantic_stack_[(4) - (4)].expr),
								ParseConstants::fn_read);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 2013 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								NULL,
								ParseConstants::fn_extern);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 2025 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								(yysemantic_stack_[(4) - (4)].expr),
								ParseConstants::fn_sequential);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 2034 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								NULL,
								ParseConstants::fn_extern_sequential);
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 2047 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = new ParamList(LOC ((yyloc)));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)));
			}
			(yyval.node) = plist_p;
		}
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 2055 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 2069 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(),
								NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
		}
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 2076 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
      delete (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 2089 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 2097 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 2108 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QueryBody(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
		}
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 2119 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 2123 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<BlockBody> blk(dynamic_cast<BlockBody *> ((yysemantic_stack_[(2) - (2)].expr)));
      BlockBody  *blk2 = new BlockBody (LOC ((yyloc)));
      (yyval.expr) = blk2;
      blk2->add ((yysemantic_stack_[(2) - (1)].expr));
      for (int i = 0; i < blk->size (); i++)
        blk2->add ((*blk) [i]);
    }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 2135 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody (LOC ((yyloc)));
    }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 2139 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = dynamic_cast<BlockBody *> ((yysemantic_stack_[(3) - (1)].expr));
      blk->add ((yysemantic_stack_[(3) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2148 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2152 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			Expr* expr_p = dynamic_cast<Expr*>((yysemantic_stack_[(3) - (1)].expr));
			if (expr_p == NULL) {
        expr_p = new Expr (LOC ((yyloc)));
        expr_p->push_back ((yysemantic_stack_[(3) - (1)].expr));
      }
      expr_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.expr) = expr_p;
		}
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 2196 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      ReturnExpr* lReturnExpr = dynamic_cast<ReturnExpr*>((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = new FLWORExpr (LOC ((yyloc)), dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node)), lReturnExpr->get_return_val(), lReturnExpr->get_location(), driver.theCompilerCB->m_config.force_gflwor);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 2205 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 2212 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2216 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 2224 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 2228 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 2232 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_only_end;
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 2239 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), dynamic_cast<WindowVars *> ((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr), (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 2243 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr), (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 2250 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(5) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window,
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(5) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (4)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 2258 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window,
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 2269 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause (LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 2288 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = new FLWORClauseList (LOC ((yyloc)));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 2294 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = dynamic_cast<FLWORClauseList *> ((yysemantic_stack_[(2) - (1)].node));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
    }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 2303 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = NULL;
    }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 2307 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_ofor;
    }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 2317 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForClause(LOC ((yyloc)),
                         dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL);
		}
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 2328 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		}
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 2334 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vardecl_list_p) {
				vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 2348 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (1)].expr);
		}
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 2356 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 2365 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 228:

/* Line 678 of lalr1.cc  */
#line 2375 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 229:

/* Line 678 of lalr1.cc  */
#line 2386 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 2395 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 231:

/* Line 678 of lalr1.cc  */
#line 2405 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 232:

/* Line 678 of lalr1.cc  */
#line 2415 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 233:

/* Line 678 of lalr1.cc  */
#line 2431 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
		}
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 2444 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
		}
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 2456 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)));
			
		}
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 2468 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		}
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 2474 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 2486 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		}
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 2492 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 2506 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
								NULL,
								NULL,
								(yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (1)].expr);
		}
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 2515 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 2525 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 2534 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (1)].expr);
		}
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2547 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr))->get_qname(),
								NULL, (yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (2)].expr);
		}
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 2554 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (2)].expr);
		}
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 2566 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(), "", "");
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2571 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_curr (static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2580 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), dynamic_cast<PositionalVar *> ((yysemantic_stack_[(1) - (1)].node)), "", "", "");
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2584 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_posvar (dynamic_cast<PositionalVar *> ((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 2593 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr))->get_qname(), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr))->get_qname());
      delete (yysemantic_stack_[(6) - (3)].expr);
      delete (yysemantic_stack_[(6) - (6)].expr);
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2599 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", "", static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 2604 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname(), "");
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 2612 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::string name = static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr))->get_qname();
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           name, NULL, NULL,
                           new VarRef (LOC ((yyloc)), name),
                           VarGetsDecl::eval_var);
      delete (yysemantic_stack_[(1) - (1)].expr);
                           
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 2628 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 2636 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 2643 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = new GroupSpecList(LOC((yyloc)));
      gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl_p;
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2649 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      if (gsl_p) {
        gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      }
      (yyval.node) = gsl_p;
    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2660 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(),
                 NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2667 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), 
                 static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(), 
                 dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node))); 
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2677 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2687 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2692 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)),
								true);
		}
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2704 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		}
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2710 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node));
			if (osl_p) {
				osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2724 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		}
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2730 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<OrderModifier*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2742 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL,
								NULL);
		}
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2749 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		}
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2756 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2763 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
								NULL);
		}
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2770 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2777 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2784 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2797 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		}
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 2801 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		}
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2811 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		}
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2816 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		}
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2827 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		}
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2838 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2845 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2858 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;
				
		}
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2865 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2877 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
								(yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (1)].expr);
		}
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2884 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2898 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
								(yysemantic_stack_[(8) - (8)].expr));
		}
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2905 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(10) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
								static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr))->get_qname(),
								(yysemantic_stack_[(10) - (10)].expr));
      delete (yysemantic_stack_[(10) - (8)].expr);
		}
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2920 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		}
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 2926 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 2938 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 2944 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr))->get_qname(),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
      delete (yysemantic_stack_[(7) - (3)].expr);
		}
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 2958 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
		}
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 2969 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 2973 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 2984 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 2988 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 3007 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 3011 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 3019 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      /*  ::=  "is" | "<<" | ">>" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 3027 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3035 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3042 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { /* this call is needed */  driver.lexer->interpretAsLessThan(); }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3043 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3051 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_le),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3059 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3067 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3081 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3085 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		}
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3092 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3105 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3109 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3120 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3124 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3128 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3138 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3142 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3146 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3150 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3154 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3164 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3168 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3173 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3184 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3188 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3192 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3202 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3206 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3218 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3222 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3234 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3238 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3250 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3254 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3266 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3270 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3282 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		}
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3286 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		}
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3290 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3294 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3306 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3310 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3314 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3324 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		}
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3328 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		}
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3332 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		}
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3336 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		}
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3340 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		}
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3344 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		}
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3354 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		}
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3358 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		}
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3362 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		}
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3372 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3376 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3380 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3384 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                            dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(),
                            (yysemantic_stack_[(6) - (5)].expr));
    }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3396 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		}
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3402 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3414 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		}
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3420 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node));
			if (pragma_list_p) {
				pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3434 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));

		}
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3440 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval))),
								"");      
    }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3482 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		}
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3486 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3490 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3494 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (rpe == NULL ?
             (yysemantic_stack_[(1) - (1)].expr) :
             new PathExpr(LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3506 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3516 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 369:

/* Line 678 of lalr1.cc  */
#line 3527 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3532 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3542 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3546 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3556 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		}
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3562 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3568 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		}
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3574 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3586 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		}
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3592 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3603 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		}
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3607 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		}
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3611 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		}
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3615 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		}
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3619 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		}
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3623 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		}
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3627 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		}
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3637 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node), false);
		}
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3641 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		}
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3651 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseStep(LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node));
		}
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3655 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC((yyloc)), rev_p, NULL);
		}
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3666 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		}
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3670 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		}
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3674 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		}
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3678 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		}
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3682 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		}
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3697 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3701 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3711 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3715 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3725 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        "",
                        ParseConstants::wild_all);
		}
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3732 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        ParseConstants::wild_elem);
		}
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3739 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        ParseConstants::wild_prefix);
		}
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3752 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3756 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
                          (yysemantic_stack_[(2) - (1)].expr),
                          dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3768 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		}
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3774 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node));
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3788 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3799 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3803 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3807 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3811 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3815 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3823 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3827 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3837 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3841 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3851 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval));
      delete yylval.decval;
		}
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3856 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival));
      delete yylval.ival;
		}
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3861 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval));
      delete yylval.dval;
		}
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3872 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new VarRef(LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname());
      delete (yysemantic_stack_[(2) - (2)].expr);
		}
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3883 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		}
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3887 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3898 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		}
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 3908 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 3919 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 3975 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)),
								NULL);
		}
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 3981 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 3993 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = new ArgList(LOC ((yyloc))); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		}
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 3999 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 4011 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 4015 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 4025 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 4029 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 4033 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 4043 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
								NULL,
								NULL,
								NULL);
		}
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 4051 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
								NULL,
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)), 
								NULL);
		}
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 4059 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(8) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr)),
								NULL,
								NULL);
		}
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4067 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
								NULL,
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node)));
		}
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4075 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
								NULL);
		}
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4083 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(10) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)), 
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node)));
		}
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4098 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		}
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4104 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4116 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		}
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4122 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4135 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
		}
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4152 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		}
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4157 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		}
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4168 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		}
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4172 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4179 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		}
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4185 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		}
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4191 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4199 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4213 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		}
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4217 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4224 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		}
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4230 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		}
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4236 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4244 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4258 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4263 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4274 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4279 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4290 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		}
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4295 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4300 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		}
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4306 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		}
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4318 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4324 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		}
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4329 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		}
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4334 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4345 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4350 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4365 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4370 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		}
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4387 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CDataSection(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		}
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4402 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4406 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4410 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4414 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4418 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4422 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4432 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4443 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
								NULL);
		}
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4449 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4455 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4460 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4482 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (2)].expr),
								NULL);
		}
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4488 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4494 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4499 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4510 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4520 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4530 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		}
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4536 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4542 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4547 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4558 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		}
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4564 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		}
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4576 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
		}
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4587 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		}
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4593 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4599 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		}
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4636 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		}
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4641 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		}
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4646 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		}
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4657 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4661 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4665 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		}
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4675 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4686 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4690 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4694 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4698 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4702 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4706 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4710 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4714 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4718 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4728 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		}
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4738 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		}
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4742 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4747 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4758 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TextTest(LOC ((yyloc)));
		}
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4768 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		}
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4778 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		}
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4782 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		}
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4786 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		}
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4796 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		}
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4802 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
								NULL);
		}
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4808 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		}
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4814 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		}
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4820 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		}
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4832 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
		}
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4843 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           NULL,
                           NULL,
                           true);
		}
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4850 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                           NULL,
                           true);
		}
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4857 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           false);
		}
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4864 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           true);
		}
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4871 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL,
									true);
		}
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4878 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									false);
		}
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4885 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									true);
		}
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4898 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)));
		}
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4919 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4926 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)),
								true);
		}
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4946 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4986 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::strict_validation);
		}
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4990 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::lax_validation);
    }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4994 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::skip_validation);
    }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 5003 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 5009 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 5015 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 5021 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 5027 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 5034 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 5040 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 5046 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 5052 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 5058 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 5070 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 5075 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 5085 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 5091 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 5103 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 5129 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 5140 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       CopyVarList* lList = new CopyVarList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
		}
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 5146 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
       VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
       lList->push_back(lBinding);
       (yyval.expr) = lList;
		}
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5159 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(), (yysemantic_stack_[(3) - (3)].expr));  
       delete (yysemantic_stack_[(3) - (1)].expr);
    }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5174 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5181 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5187 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* aCatchListExpr = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if (aCatchListExpr) {
        aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)));
      }
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5198 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(3) - (2)].name_test_list),
                          (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5205 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(7) - (2)].name_test_list),
                          static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr))->get_qname(),
                          (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (5)].expr);
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5215 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 576:

/* Line 678 of lalr1.cc  */
#line 5226 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 577:

/* Line 678 of lalr1.cc  */
#line 5242 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CatchExpr::NameTestList *name_test_list = new CatchExpr::NameTestList;
      name_test_list->push_back (static_cast<NameTest *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.name_test_list) = name_test_list;
    }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5248 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CatchExpr::NameTestList *name_test_list =
        static_cast<CatchExpr::NameTestList *> ((yysemantic_stack_[(3) - (1)].name_test_list));
      name_test_list->push_back (static_cast<NameTest *> ((yysemantic_stack_[(3) - (3)].node)));
      (yyval.name_test_list) = name_test_list;
    }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5268 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 582:

/* Line 678 of lalr1.cc  */
#line 5286 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { 
      (yyval.expr) = new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval))); 
    }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5290 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { 
      (yyval.expr) = new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval))); 
    }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5296 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("xquery"); }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5297 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty"); }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5298 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("attribute"); }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5299 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("comment"); }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5300 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document-node"); }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5301 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("element"); }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5302 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("item"); }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5303 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("if"); }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5304 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("node"); }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5305 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("processing-instruction"); }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5306 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-attribute"); }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5307 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-element"); }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5308 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("text"); }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5309 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("typeswitch"); }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5310 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty-sequence"); }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5311 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("boundary-space"); }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5312 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ft-option"); }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5313 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("base-uri"); }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5314 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lax"); }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5315 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strict"); }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5316 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("idiv"); }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5317 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document"); }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5318 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("not"); }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5319 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sensitive"); }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5320 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insensitive"); }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5321 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("diacritics"); }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5322 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("without"); }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5323 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stemming"); }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5324 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("thesaurus"); }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5325 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stop"); }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5326 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("wildcards"); }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5327 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("entire"); }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5328 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("content"); }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5329 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("word"); }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5330 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("start"); }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5331 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("end"); }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5332 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("most"); }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5333 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("skip"); }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5334 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy"); }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5335 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("value"); }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5336 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eq"); }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5337 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ne"); }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5338 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lt"); }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5339 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("le"); }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5340 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("gt"); }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5341 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ge"); }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5342 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("at"); }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5343 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("context"); }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5344 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("variable"); }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5345 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("return"); }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5346 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("for"); }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5347 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("outer"); }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5348 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sliding"); }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5349 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("tumbling"); }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5350 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("previous"); }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5351 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("next"); }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5352 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("only"); }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5353 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("when"); }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5354 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("count"); }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5355 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("in"); }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5356 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("let"); }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5357 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("where"); }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5358 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("by"); }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5359 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("group"); }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5360 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("order"); }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5361 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stable"); }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5362 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ascending"); }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5363 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("descending"); }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5364 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("greatest"); }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5365 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("least"); }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5366 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("collation"); }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5367 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("some"); }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5368 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("every"); }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5369 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("satisfies"); }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5370 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("case"); }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5371 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("as"); }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5372 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("then"); }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5373 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("else"); }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5374 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("or"); }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5375 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("and"); }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5376 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("instance"); }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5377 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("of"); }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5378 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("castable"); }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5379 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("to"); }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5380 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("div"); }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5381 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("mod"); }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5382 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("union"); }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5383 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("intersect"); }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5384 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("except"); }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5385 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("validate"); }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5386 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("cast"); }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5387 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("treat"); }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5388 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("is"); }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5389 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("preserve"); }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5390 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strip"); }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5391 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("namespace"); }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5392 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("external"); }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5393 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("encoding"); }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5394 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-preserve"); }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5395 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("inherit"); }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5396 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-inherit"); }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5397 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("declare"); }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5398 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("construction"); }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5399 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordering"); }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5400 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("default"); }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5401 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy-namespaces"); }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5402 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("option"); }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5403 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("version"); }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5404 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("import"); }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5405 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema"); }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5406 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("module"); }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5407 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("function"); }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5408 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("score"); }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5409 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ftcontains"); }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5410 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("weight"); }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5411 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("window"); }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5412 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("distance"); }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 5413 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("occurs"); }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5414 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("times"); }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 5415 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("same"); }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 5416 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("different"); }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 5417 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lowercase"); }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 5418 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("uppercase"); }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 5419 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("relationship"); }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 5420 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("levels"); }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 5421 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("language"); }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 5422 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("any"); }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 5423 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("all"); }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 5424 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("phrase"); }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 5425 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exactly"); }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 5426 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("from"); }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 5427 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("words"); }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 5428 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentences"); }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 5429 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentence"); }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 5430 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("paragraph"); }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 5431 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("replace"); }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 5432 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("modify"); }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 5433 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("first"); }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 5434 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insert"); }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 5435 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("before"); }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 5436 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("after"); }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 5437 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("revalidation"); }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 5438 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("with"); }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 5439 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nodes"); }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 5440 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("rename"); }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 5441 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("last"); }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 5442 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("delete"); }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 5443 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("into"); }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 5444 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("simple"); }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 5445 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sequential"); }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 5446 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("updating"); }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 5447 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("deterministic"); }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 5448 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nondeterministic"); }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 5449 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordered"); }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 5450 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unordered"); }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 5451 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("returning"); }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 5452 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("block"); }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 5453 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exit"); }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 5454 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("loop"); }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 5455 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("while"); }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 5456 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("break"); }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 5457 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("continue"); }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 5458 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("try"); }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 5459 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("catch"); }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 5460 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eval"); }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 5461 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("using"); }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 5462 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("set"); }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 5463 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("index"); }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 5464 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unique"); }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 5465 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("on"); }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 5466 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("manual"); }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 5467 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("automatic"); }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 5468 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("decimal-format"); }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 5469 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("decimal-separator"); }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 5470 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("grouping-separator"); }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 5471 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("infinity"); }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 5472 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("minus-sign"); }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 5473 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("NaN"); }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 5474 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("percent"); }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 5475 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("per-mille"); }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 5476 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("zero-digit"); }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 5477 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("digit"); }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 5478 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("pattern-separator"); }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 5490 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)),
                          (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 5496 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 5513 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(1) - (1)].node)), NULL, NULL);
		}
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 5517 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(2) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(2) - (2)].node)), NULL);
		}
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 5521 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(3) - (1)].node)), NULL, static_cast<RangeExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		}
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 5525 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(4) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(4) - (2)].node)), static_cast<RangeExpr *> ((yysemantic_stack_[(4) - (4)].expr)));
		}
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 5535 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 5538 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 5541 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 5544 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 5553 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 5556 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 5565 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 5568 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 5577 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 5580 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 5589 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 5592 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 5601 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 5604 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 5607 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 5616 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 5619 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 5628 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), static_cast<StringLiteral *> ((yysemantic_stack_[(1) - (1)].expr)), NULL);
		}
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 5632 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 5642 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 5645 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 5648 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 5651 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 5654 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 5663 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 5672 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 5676 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 5680 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 5684 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 5688 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 5692 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 5696 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 5706 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 5709 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 5712 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 5715 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 5724 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 5727 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 5730 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 5733 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 5742 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 5745 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 5754 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 5757 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 5760 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 5763 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 5766 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 5769 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 5772 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 5781 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 5784 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 5793 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 5796 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 5799 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 5802 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 5811 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 5814 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 5817 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 5820 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 5823 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 5832 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 5835 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 5844 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 5847 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 5856 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 5859 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 5868 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 5871 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 5880 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 5889 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 5892 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 5901 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 5904 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 5907 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 5916 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 5919 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 5922 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 5925 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 5928 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 5937 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 5941 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 5945 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 5949 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 5959 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 5968 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWindow (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (2)].expr)), static_cast<FTUnit *> ((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 5978 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 5987 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 5990 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 5999 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 6002 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 6005 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 6014 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 6017 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 6026 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTIgnoreOption (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		}
    break;



/* Line 678 of lalr1.cc  */
#line 10054 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1240;
  const short int
  xquery_parser::yypact_[] =
  {
      1417, -1240, -1240, -1240, -1240,   126,   115,    56,   -39,  7652,
      96,   473,   474, -1240, -1240, -1240, -1240, -1240, -1240,   125,
      -4,  6581, -1240,   181, -1240, -1240, -1240, -1240,   214,   265,
   -1240,   267,   348,   328, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240,   341,   357, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240,  7917, -1240,  6051, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240,  9507, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240,   421, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240,  1691,  9507, -1240, -1240, -1240, -1240, -1240,
   -1240,   393, -1240, -1240, -1240, -1240,  7122, -1240,  7387, -1240,
   -1240, -1240, -1240, -1240,  9507, -1240, -1240,  5786, -1240, -1240,
   -1240, -1240, -1240, -1240,   399, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240,    17,   380, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240,    84,   416,   311, -1240,   385,    54, -1240,
   -1240, -1240, -1240, -1240, -1240,   535, -1240, -1240,   481,   436,
     443, -1240,   448,   514,   524, -1240,   571, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240,   534, -1240, -1240, -1240, -1240, -1240,  1964,
     693, -1240,  2237, -1240, -1240,   409, -1240,   409,  4694,   517,
     521, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240,   -13, -1240, -1240, -1240, -1240,   296,  9507, -1240, -1240,
   -1240, -1240, -1240,   550,   631, -1240,   670,   466,   196,   330,
     -58,   378, -1240,   651,   537,   629,   635,  4967, -1240, -1240,
   -1240,   -29, -1240, -1240,  5786, -1240,   368, -1240,   607,  6051,
   -1240,   607,  6051, -1240, -1240, -1240, -1240,   607, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240,   610, -1240, -1240,  9507,
     724,   726,   634,   634,   724,  9507,   185,   -55,   750,   252,
     293,  9507,   630,   663,   350,  7122,   390,   390,   477,    76,
    9507,   149,  9507,   489,   489, -1240, -1240, -1240, -1240, -1240,
    7122,  9507,  4694,   636,   638,  4694, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240,  4694,  8182, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240,   639,  4694,  4694,   601,  4694,
     602,  4694,    43,    36,    45, -1240,  4694,  6857,   640, -1240,
    9507,  9507,  9507,  4694,   520,   522, -1240,   679,   683,  9507,
      51,  4694,  8447,   652,   653,   654,   657,   660,   661, -1240,
   -1240, -1240,  9507, -1240,   622,   777,  4694,    60, -1240,   792,
     637, -1240,  4694,   613, -1240,   789,  4694,  4694,   642,  4694,
    4694,  4694,  4694,   598,  9507, -1240, -1240,  4694, -1240, -1240,
    4694,  4694,  9507,  7122, -1240, -1240, -1240, -1240, -1240,   126,
      -4, -1240, -1240, -1240,   409,   794,  4694, -1240,  4694,   662,
     265,   348,   328,   712,   664,   665,  4694,  4694, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240,   728, -1240,   -37,  5240,  5240,
    5240, -1240,  5240,  5240, -1240,  5240, -1240,  5240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240,  5240,  5240,    97,  5240,  5240,
    5240,  5240,  5240,  5240,  5240,  5240,  5240,  5240,  5240,   605,
     742,   743,   744, -1240, -1240, -1240,  2510, -1240, -1240,  5786,
    5786,  4694,   607, -1240, -1240,   607, -1240,   607,  2783,   686,
   -1240,  9507, -1240, -1240, -1240, -1240,   812, -1240, -1240, -1240,
   -1240, -1240, -1240,   734,   735, -1240, -1240,   659,   292,  9507,
     298,   687,   689,   659,   750,   718,   717, -1240, -1240, -1240,
   -1240, -1240,   400,   116,   404,   821, -1240, -1240,   240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240,   413, -1240,   554,
   -1240, -1240,   722,   703, -1240,   674,  4694,  4694,   672,   676,
   -1240,   145,   146,  3056,   677,   678, -1240,   680, -1240,   681,
    7122,   763,   823,  7122,   750,   766,  7122,   767,   685,   684,
   -1240,   692,  3329,   -23, -1240,    15,   736,   759, -1240,   -28,
     688, -1240, -1240,  9507,   -24, -1240,   694,   653,   341, -1240,
     695,   696,   700, -1240,   147,   151,  3602,     4, -1240,  9507,
     777, -1240,   -38,   701, -1240, -1240, -1240, -1240,   702, -1240,
       9, -1240, -1240, -1240,    40,    89,   790,   649,   666,    13,
   -1240,   745,  5513, -1240,   706,   710,    92, -1240, -1240,   756,
     705, -1240,    -7, -1240, -1240,    -5,   730,  9507,  4694,   780,
   -1240, -1240,   781,  8977,   782,  4694,   783,    -2,   751,   -48,
     631, -1240, -1240, -1240, -1240, -1240,  5240, -1240, -1240, -1240,
    4694,    97,   475, -1240,   626,   441,   646,   645, -1240, -1240,
     641,  -145,   330,   330,   118,   -58,   -58,   -58,   -58,   378,
     378, -1240, -1240,  8977,  8977,  9507,  9507, -1240,   727, -1240,
   -1240,   729, -1240, -1240, -1240,   173,   -26,   302,   686, -1240,
     140,   261, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240,   659, -1240,   778,  9242,   769,  4694, -1240, -1240,
   -1240,   817,   772,  4694,   750,   750,   659, -1240,   509,   750,
   -1240, -1240,   647, -1240, -1240,   644,   249, -1240, -1240, -1240,
   -1240, -1240, -1240,   648, -1240, -1240,    78,   352,   388,   627,
   -1240,  4694,   750,  4694, -1240,   741,   747,   815,   775,  9507,
   -1240,  9507, -1240, -1240,   749, -1240, -1240, -1240,   737,   800,
     750,   776,   802,   838,   750,   805,   750,   786, -1240, -1240,
   -1240,   758,   824,  4694,  4694,   795,  4694,   825,  4694,   804,
     -78, -1240,   200,   697, -1240, -1240,   543,   -24, -1240, -1240,
   -1240,   796,  9507, -1240,  9507, -1240, -1240,   773,  4694,   912,
   -1240,   -33, -1240,   161, -1240, -1240,   921, -1240,   372,  4694,
    4694,  4694,   428,  4694,  4694,  4694,  4694,  4694,  4694,   834,
    4694,  4694,   663,    26,   774,   481,   713,   807,   837,   750,
     794,   879, -1240,  4694, -1240,   513,   852, -1240,  9507,   853,
   -1240,  9507,   808,   810, -1240,   312, -1240, -1240, -1240,  9507,
   -1240,  9507,  4694,   820,  4694,  4694,     1,   822, -1240,   785,
     784, -1240,   714, -1240,   113, -1240,   284,   -47,   715,    97,
     284,  5240,  5240,   518, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240,    97,   827,   -47, -1240,   698,   913, -1240, -1240, -1240,
   -1240, -1240,   830, -1240, -1240, -1240,  4694, -1240,  9507,   880,
     189, -1240, -1240,  4694, -1240,   358, -1240, -1240, -1240, -1240,
   -1240,   945,   476, -1240, -1240, -1240,  4694, -1240, -1240, -1240,
   -1240, -1240, -1240,   704,    50,   947, -1240,   369, -1240, -1240,
     654,   657,   660,   357,   661,   416,   420, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240,   809,   799,   797, -1240, -1240,  8712,
     432, -1240,  3875,   798,   806,   840,   811,   813, -1240,  4694,
     750,   881, -1240, -1240, -1240,   750,   881,   750,   881,  4148,
   -1240,  9507, -1240, -1240,  4694, -1240,  9507, -1240,  4694,  4694,
     850,  4694,   847, -1240,   874,   875,  4694,  9507,   597,   926,
   -1240, -1240, -1240,  4421,   816,   818, -1240, -1240, -1240,   868,
   -1240,   305, -1240, -1240,   986, -1240, -1240,  4694,  9507, -1240,
   -1240,   384, -1240, -1240, -1240,   819,   779,   788, -1240, -1240,
   -1240,   791,   793, -1240, -1240, -1240, -1240, -1240,   768,  9507,
     826, -1240,   864, -1240,   663, -1240, -1240, -1240,  6316,   713,
   -1240,  4694,  9507,   828,   852, -1240,   750, -1240,   585, -1240,
     187,   899, -1240,  4694,   901,   780, -1240,   829,   831, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240,  4694, -1240, -1240,  4694,
     866,  4694, -1240, -1240,  5240, -1240, -1240, -1240, -1240, -1240,
      57,  5240,  5240,   264, -1240,   646, -1240, -1240,   208,  5240,
   -1240, -1240,   645,    97,   738, -1240, -1240, -1240, -1240,   817,
    8977,   895,   922,   839, -1240, -1240, -1240, -1240, -1240,   -43,
     992,   994,   -43,    -8,   190,   206,   627, -1240,   871, -1240,
   -1240,  9507,   843,   -20, -1240, -1240,   846, -1240, -1240, -1240,
   -1240, -1240,   903,   932,   750,   881,   933, -1240,   851, -1240,
   -1240, -1240, -1240, -1240,  4694, -1240,  4694,  9507,  9507, -1240,
      69, -1240,  4694, -1240,   854, -1240, -1240,   912,  9507,   408,
   -1240,   855,   912,  9507, -1240, -1240,  4694,  4694,  4694,  4694,
    4694, -1240,  4694,  4694, -1240, -1240,   300, -1240,   857, -1240,
   -1240, -1240, -1240, -1240,   899, -1240, -1240, -1240,   750, -1240,
   -1240, -1240, -1240, -1240, -1240,  4694, -1240,   -58,  5240,  5240,
     -58,   345, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240,  8977, -1240,    50,    50,   -43, -1240, -1240,
   -1240,    49,   -43,  1002,   770,   936, -1240,   936, -1240, -1240,
    4694,   213,   944,  4694,  9507,  4694, -1240,  4694,   750, -1240,
     750, -1240, -1240, -1240,   972, -1240, -1240, -1240, -1240,   -32,
     912,  9507, -1240,   848,   912, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240,   924,  6316, -1240, -1240, -1240, -1240, -1240,   -58,
     -58,  5240, -1240, -1240, -1240, -1240, -1240, -1240,   -47, -1240,
     216, -1240,   226, -1240,   934,   817,  4694, -1240,  8977, -1240,
     861, -1240, -1240,   881,   881,   927,    58,   377, -1240,   856,
     912, -1240,   858,  9507, -1240,   -58,   787,   936, -1240, -1240,
     750, -1240, -1240,   862,  4694,  9507, -1240, -1240,   953,    64,
   -1240, -1240, -1240, -1240,   873,   463, -1240, -1240, -1240,   860,
   -1240,   228, -1240, -1240, -1240,  4694, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240,   929,   904, -1240,  9507, -1240,
     235,   937,   904,  9507, -1240,   876,   904, -1240
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   400,   401,   582,   547,   685,   694,   673,   597,   589,
     605,   596,   587,   695,   734,   733,   735,   736,   732,   591,
     692,   593,   620,   655,   649,   690,   617,   693,   750,   644,
     686,   748,   634,   635,   636,   637,   638,   639,   640,   641,
     642,   687,   601,   595,   588,   689,   664,   594,   599,   756,
     757,   758,   759,   760,   761,   762,   763,   764,   765,   766,
     391,   394,   663,   659,   650,   630,   586,   381,     0,   658,
     666,   674,   379,   654,   417,   631,   632,   688,   380,   383,
     651,   668,     0,   423,   389,   419,   661,   585,   652,   653,
     681,   656,   672,   680,   385,   384,   604,   643,   683,   418,
     671,   676,   590,     0,     0,   338,   669,   679,   684,   682,
     662,   737,   648,   646,   647,   390,     0,   337,     0,   393,
     392,   677,   633,   657,     0,   382,   367,     0,   399,   678,
     660,   667,   675,   670,   738,   624,   629,   628,   627,   626,
     625,   598,   645,     0,   584,   691,   618,   724,   723,   725,
     603,   602,   621,   730,   592,   722,   727,   728,   719,   623,
     665,   721,   731,   729,   720,   622,   726,   739,   740,   741,
     744,   742,   745,   743,   746,   747,   749,   711,   710,   607,
     600,   609,   608,   704,   700,   615,   619,   616,   713,   714,
     697,   606,   709,   708,   705,   701,   718,   712,   707,   703,
     696,   717,   716,   702,   706,   698,   699,   610,   611,   613,
     715,   612,   614,     0,   752,   751,   754,   755,   753,     0,
       0,     2,     0,     4,     6,    14,     8,    17,     0,     0,
       0,    23,    25,    38,    27,    28,    29,    54,    30,    34,
      35,    58,    59,    60,    55,    56,    62,    63,    32,    31,
      36,    37,    57,   197,   196,   193,   194,   195,    33,    13,
     174,   175,   179,   181,   212,   218,     0,     0,   210,   211,
     182,   183,   184,   185,   294,   296,   298,   308,   311,   313,
     316,   321,   324,   327,   329,   331,   333,     0,   335,   341,
     343,     0,   359,   342,   363,   366,   368,   371,   373,     0,
     378,   375,     0,   386,   396,   398,   372,   402,   407,   415,
     408,   409,   410,   413,   414,   411,   412,   430,   432,   433,
     434,   431,   479,   480,   481,   482,   483,   484,   395,   521,
     513,   520,   519,   518,   515,   517,   514,   516,   416,    61,
     186,   187,   189,   188,   190,   191,   397,   583,   192,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   123,   125,   128,   157,   160,
       0,     0,     0,     0,     0,     0,   685,   694,   673,   597,
     589,   605,   596,   587,   591,   692,   593,   655,   750,   644,
     748,   634,   635,   595,   588,   586,   656,     0,     0,   737,
     738,   584,   730,   592,   722,   728,   719,   622,   740,   741,
     744,   745,   743,   746,   749,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   580,     0,     0,     0,   581,
       0,     0,     0,     0,     0,     0,   220,     0,     0,     0,
       0,     0,     0,     0,   589,   596,   587,   593,   586,   387,
     397,   420,     0,   421,     0,   446,     0,     0,   362,     0,
       0,   365,     0,     0,   475,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   147,   144,     0,   155,   156,
       0,     0,     0,     0,     3,     1,     5,     7,     9,     0,
       0,    15,    18,    12,    20,    21,     0,   177,   176,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   198,   217,
     213,   219,   214,   216,   215,   222,   223,     0,     0,     0,
       0,   352,     0,     0,   350,     0,   303,     0,   351,   344,
     349,   348,   347,   346,   345,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   340,   339,   336,     0,   360,   364,     0,
       0,     0,   374,   404,   377,   376,   388,   403,     0,     0,
     162,     0,   163,   159,   158,   161,     0,   138,   139,    71,
      72,   579,    80,     0,     0,    65,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   127,   126,   548,
     549,   550,     0,     0,     0,     0,   805,   806,     0,    70,
     798,   799,   800,   801,   802,   803,   804,   109,   124,     0,
     129,   130,     0,     0,   545,     0,     0,     0,     0,     0,
     537,     0,     0,     0,     0,     0,   526,     0,   527,     0,
       0,    89,     0,     0,     0,    81,     0,    93,     0,     0,
     528,     0,     0,     0,   283,     0,     0,   235,   236,     0,
       0,   200,   201,     0,     0,   221,     0,     0,     0,   523,
       0,     0,     0,   531,     0,     0,     0,     0,   422,   447,
     446,   443,     0,     0,   477,   476,   361,   536,     0,   474,
       0,   561,   562,   522,     0,     0,     0,     0,     0,     0,
     567,     0,     0,   153,     0,     0,     0,   238,   255,     0,
       0,    24,     0,    26,   180,     0,     0,     0,     0,     0,
     199,   256,     0,     0,     0,     0,     0,     0,     0,     0,
     295,   297,   301,   307,   306,   305,     0,   302,   299,   300,
       0,     0,     0,   790,   309,   769,   777,   779,   781,   783,
     785,   788,   315,   314,   312,   318,   319,   320,   317,   322,
     323,   326,   325,     0,     0,     0,     0,   357,     0,   369,
     370,     0,   405,   426,   428,     0,     0,     0,     0,    69,
       0,     0,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    40,    41,     0,     0,   101,     0,    97,    99,
     100,   104,   107,     0,     0,     0,    39,    79,     0,     0,
     807,   808,     0,   809,   813,     0,     0,   842,   811,   812,
     841,   810,   814,     0,   821,   843,     0,     0,     0,   111,
     113,     0,     0,     0,   353,     0,     0,     0,     0,     0,
     541,     0,   538,   486,     0,   485,   494,   495,     0,     0,
       0,     0,     0,    82,     0,     0,     0,     0,   530,   529,
     496,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   768,     0,     0,   202,   203,     0,   208,   544,   524,
     525,     0,     0,   534,     0,   532,   490,     0,     0,   446,
     444,     0,   435,     0,   424,   425,     0,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   685,     0,     0,     0,     0,     0,     0,     0,
      22,     0,   178,     0,   209,   267,   263,   265,     0,   257,
     258,     0,   590,   598,   502,   503,   509,   510,   512,     0,
     225,     0,     0,     0,     0,     0,     0,     0,   304,     0,
       0,   784,     0,   310,     0,   797,     0,     0,     0,     0,
       0,     0,     0,   770,   774,   792,   773,   796,   794,   793,
     795,     0,     0,     0,   786,   849,   847,   851,   789,   328,
     330,   332,   500,   334,   358,   406,     0,   427,     0,   140,
       0,   168,   165,     0,   164,     0,    77,    78,    75,    76,
      42,     0,     0,   102,   103,   105,     0,   106,    67,    68,
      73,    74,    64,     0,     0,     0,   816,     0,   815,   832,
       0,     0,     0,     0,     0,     0,   110,   117,   118,   119,
     120,   122,   121,   115,     0,     0,     0,   355,   354,     0,
       0,   289,     0,     0,     0,   545,     0,     0,   487,     0,
       0,    91,    85,    88,    87,     0,    83,     0,    95,     0,
     497,     0,   281,   285,     0,   152,     0,   240,     0,     0,
       0,     0,     0,   204,     0,     0,     0,     0,   249,     0,
     246,   251,   207,     0,     0,     0,   491,   282,   447,     0,
     436,     0,   470,   467,     0,   471,   472,     0,     0,   473,
     466,     0,   441,   469,   468,     0,     0,     0,   554,   555,
     551,     0,     0,   559,   560,   556,   565,   563,     0,     0,
       0,   569,   150,   149,     0,   146,   145,   154,     0,   570,
     571,     0,     0,     0,   264,   276,     0,   277,     0,   268,
     269,   270,   271,     0,   260,     0,   224,     0,     0,   506,
     508,   507,   504,   233,   234,   227,     0,   229,   226,     0,
       0,     0,   791,   787,     0,   844,   845,   865,   864,   860,
       0,     0,     0,     0,   846,   778,   859,   771,     0,     0,
     776,   775,   780,     0,     0,   850,   848,   501,   429,   170,
       0,     0,   141,     0,   167,   166,    43,    98,   108,   830,
       0,     0,   828,   824,     0,     0,   112,   114,     0,    16,
     356,     0,     0,     0,   290,   488,     0,   542,   543,   546,
     539,   540,     0,    90,     0,    84,    94,   498,     0,   284,
     286,   237,   242,   241,     0,   244,     0,     0,     0,   206,
     247,   250,     0,   492,     0,   535,   533,   446,     0,     0,
     478,     0,   446,     0,   442,    11,     0,     0,     0,     0,
       0,   568,     0,     0,   148,   577,     0,   572,     0,   239,
      19,   280,   278,   279,   272,   273,   274,   266,     0,   261,
     259,   511,   505,   231,   228,     0,   230,   866,     0,     0,
     852,     0,   863,   862,   861,   856,   857,   772,   782,   858,
     171,   142,   169,     0,   173,     0,     0,   831,   833,   835,
     837,     0,   829,     0,     0,     0,   819,     0,   817,   116,
       0,     0,     0,     0,     0,     0,   489,     0,     0,    86,
       0,   499,   243,   245,   254,   253,   248,   205,   493,     0,
     446,     0,   172,     0,   446,   552,   553,   557,   558,   564,
     566,   151,     0,     0,   573,   767,   275,   262,   232,   854,
     853,     0,   143,   840,   839,   834,   838,   836,   825,   826,
       0,   822,     0,   132,   134,   136,     0,   131,     0,   291,
       0,   287,   293,    92,    96,     0,   456,   450,   445,     0,
     446,   437,     0,     0,   578,   855,     0,     0,   820,   818,
       0,   137,   133,     0,     0,     0,   464,   458,     0,   457,
     459,   465,   462,   452,     0,   451,   453,   463,   439,     0,
     438,     0,   827,   823,   135,     0,   288,   252,   449,   460,
     461,   448,   454,   455,   440,     0,     0,   292,     0,   574,
       0,     0,     0,     0,   575,     0,     0,   576
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1240, -1240,   833, -1240,   832,   835, -1240,   836, -1240,   435,
   -1240,   544,   545,  -489, -1240,   447,  -309, -1240, -1240, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240,  -849, -1240, -1240, -1240, -1240,    41,   253,   707, -1240,
   -1240,    24,  -821, -1240,   690,   347,   353, -1240,  -323, -1240,
   -1240,   276, -1240,  -850, -1240, -1240,   -69, -1240, -1240, -1240,
   -1240, -1240,   389,   155, -1240, -1240,  -135, -1240, -1239,   841,
     -98, -1240,   560,  -358, -1240, -1240, -1240, -1240,   184, -1240,
   -1240,   814, -1240, -1240, -1240, -1240, -1240,   131,  -503,  -648,
   -1240, -1240, -1240,    -3, -1240, -1240,  -176,   -12,   -67, -1240,
   -1240, -1240,   -76, -1240, -1240,   148,   -71, -1240, -1240,   -66,
   -1080, -1240,   621,    14, -1240, -1240,    37, -1240, -1240,   558,
     559, -1240,  -485,  -938,   539,   198,  -545,   193,   194, -1240,
   -1240, -1240, -1240, -1240,   803, -1240, -1240, -1240, -1240, -1240,
     801, -1240, -1240,  -108, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240,   -45, -1104, -1240, -1240,    72,    -6, -1240,  -543, -1240,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240, -1240,  -883, -1240,
     -10, -1240,   403,  -689, -1240, -1240, -1240, -1240, -1240,  -331,
    -324, -1056,  -771, -1240, -1240, -1240, -1240, -1240, -1240, -1240,
   -1240, -1240, -1240,   320,  -655,  -748, -1240,   295,   -19,  -731,
   -1240, -1240, -1240, -1240, -1240, -1240, -1240,   655,   656,  -270,
     246,    87, -1240, -1240, -1240, -1240, -1240, -1240, -1240,   -27,
   -1240, -1240,   -36, -1240,  -355,   -70,    -9, -1240, -1240,   356,
   -1240, -1240,   132,   123,   -85,   359, -1240, -1240,   136, -1240,
    -720, -1240, -1240, -1240, -1240,  -217,  -815, -1240,  -100,  -547,
   -1240,  -710, -1240, -1240, -1240, -1240,  -970, -1240, -1240, -1240,
   -1240,   -75,   144, -1240
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   802,   803,   804,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,  1061,   654,   247,   248,   808,   809,   810,  1132,   249,
     250,   839,   840,   251,   375,   376,   377,  1331,  1383,  1384,
     252,   787,   253,   486,   712,   923,  1133,   254,   255,   256,
     257,   258,   378,   379,   582,  1000,  1001,  1109,  1004,   259,
     260,   508,   261,   262,   263,   518,   447,   886,   887,   264,
     519,   265,   521,   266,   267,   268,   525,   526,  1088,   738,
     269,   667,   716,   668,   674,  1089,  1090,  1091,   717,   522,
     523,   939,   940,  1289,   524,   936,   937,  1149,  1150,  1151,
    1152,   270,   663,   664,   271,  1050,  1051,   272,   273,   274,
     275,   746,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   545,   546,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   572,   573,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   785,   316,   317,   318,
    1111,   690,   691,   692,  1398,  1424,  1425,  1418,  1419,  1426,
    1420,  1112,  1113,   319,   320,  1114,   321,   322,   323,   324,
     325,   326,   327,   991,   739,   944,  1162,   945,   946,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   633,
    1054,   338,   339,   340,   341,   342,   343,   344,   709,   710,
     345,  1139,  1140,  1276,  1062,   438,   346,   347,   348,   754,
     973,   755,   756,   757,   758,   759,   760,   761,   974,   975,
     619,   620,   621,   622,   623,  1380,  1381,   624,  1317,  1212,
    1321,  1318,   625,   626,   977,   988,  1183,   978,   979,   984,
     980,  1305,  1179,   963
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       425,   901,   947,   592,   753,   464,   765,   766,   767,   768,
     875,  1028,   439,  1194,   880,  1066,   723,  1068,  1043,   471,
    1110,   879,   432,   459,   737,   989,   990,   349,   350,   351,
     352,   353,   354,  1187,  1275,   976,   883,  1364,   473,   355,
     734,  1180,   947,   947,   433,   742,   467,   743,   744,   733,
     745,   734,   747,  1396,  1079,  1264,   591,   453,   733,   460,
     748,   749,  1416,   591,   361,   591,  1102,   694,  1416,  1376,
    1285,  1286,  1102,   461,   947,  1137,   872,   651,   655,   657,
    1180,   677,   902,  1315,   998,   670,   506,  1100,   955,   953,
    1334,   957,   985,   986,   506,   465,   362,   363,   931,   735,
    1298,   733,   589,   872,   878,  1036,   385,   439,   677,   469,
    1030,  1031,   919,   566,   987,   470,   678,     4,   701,   702,
    1032,   704,   705,   706,   707,  1134,   908,  1084,  1085,   713,
     906,   555,   714,   715,   952,   590,   118,  1169,  1210,  1397,
     556,   652,   381,   678,  1033,   927,  1316,   903,   724,   999,
     366,   874,  1101,   873,  1335,  1205,  1015,   734,   730,   731,
     349,   350,   351,   352,   353,   354,   507,  1034,   612,  1102,
    1103,  1105,   355,  1106,   932,   912,  1299,  1105,   356,  1106,
     898,  1417,   884,   367,   736,   653,   568,  1439,   907,   357,
     358,   928,   650,   359,   656,  1211,   360,   361,   382,    74,
    1107,  1181,  1182,  1264,  1366,  1135,  1107,  1449,   753,   753,
    1099,    85,  1215,  1454,   736,  1217,  1235,  1457,  1110,   474,
     784,   822,   885,   695,  1377,   736,   679,  1082,  1110,   362,
     363,   364,  1080,   369,   736,    99,   956,   920,   426,   750,
    1181,  1182,   751,  1324,   849,   851,   892,   909,   910,   817,
     894,  1307,  1323,  1191,   574,   124,  1104,   576,   527,  1404,
     736,   958,   911,   736,   380,   548,   383,   384,   482,   370,
     431,   434,   996,   483,  1105,   365,  1106,  1006,   371,   372,
     373,   374,   549,   366,   635,  1146,   733,   638,  1201,  1325,
     460,   440,  1035,   460,  1007,   606,   913,   914,   476,   863,
     477,  1222,   613,  1107,  1148,  1327,   366,   104,  1170,   639,
     632,   915,  1386,  1102,  1103,  1407,   367,   614,   947,  1175,
     850,   852,   893,   116,   441,  1407,   895,  1445,   644,   645,
     615,   647,   616,   649,  1451,   368,  1081,  1025,   658,   367,
     579,   509,   617,   548,  1108,   618,   586,   510,   997,   752,
     511,   512,   597,   682,  1026,   587,   439,   823,   513,  1176,
     549,   627,   143,   629,  1202,  1326,   369,   661,   693,   588,
     935,   439,   634,   575,   698,   442,  1110,   950,   805,   577,
     601,  1328,   448,   550,   602,  1102,   824,   825,  1387,   826,
     827,  1408,  1102,  1103,  1027,  1329,  1422,   555,  1008,   642,
    1104,  1409,   370,  1446,   444,   445,   556,   593,  1406,   443,
    1452,   371,   372,   373,   374,  1009,  1102,  1103,  1105,   806,
    1106,   603,   594,   719,   807,   812,   753,  1188,   439,  1002,
     813,   665,   666,   669,   499,   372,   373,   374,   753,   551,
     676,   723,  1003,   685,  1003,  1362,  1159,  1107,   604,  1014,
     500,   104,  1311,   665,   514,  1017,   515,  1025,   446,  1018,
    1019,   779,   780,   595,  1022,   552,  1302,   116,   778,   947,
     516,  1102,  1303,   781,  1214,   711,  1160,   596,   553,  1104,
    1304,   831,  1422,   718,   439,  1204,   449,  1045,  1258,  1393,
    1105,  1394,  1106,  1010,  1161,     4,   517,  1105,  1363,  1106,
     485,  1423,   450,  1104,   557,   580,   143,  1010,   605,   585,
     832,   833,   554,   834,   835,  1072,  1073,   558,  1075,  1107,
    1077,  1105,  1302,  1106,  1049,   479,  1107,   480,  1303,   964,
     104,   462,  1371,   612,   555,   466,  1304,  1223,   845,   846,
    1097,   472,  1177,   556,  1310,   854,   116,  1178,   569,   570,
    1107,  1118,  1119,  1120,   104,  1123,  1124,  1125,  1126,  1127,
    1128,   478,  1130,  1131,   871,  1372,   782,  1263,  1349,   782,
     116,   782,   788,  1353,  1143,   935,  1105,    74,  1106,  1053,
     859,  1056,   947,   862,   475,   143,   865,  1442,   897,    85,
     811,  1351,  1433,  1116,  1165,  1117,  1167,  1168,   965,   481,
    1145,  1084,  1085,   806,  1086,  1107,   964,  1375,   807,   143,
     612,  1146,  1375,    99,   924,   427,   429,   750,   428,   430,
     751,  1147,  1094,   485,  1095,  1421,  1427,  1020,  1021,  1297,
    1148,   734,  1037,  1038,  1039,  1040,  1300,  1301,  1198,   820,
    1413,   439,   821,   828,   439,   484,   829,   439,  1421,  1121,
     753,  1122,   959,  1087,  1427,  1084,  1085,   947,  1208,   490,
     501,  1399,   502,   487,   882,  1402,   491,   613,   349,   350,
     351,  1041,  1042,   354,   488,   965,   372,   373,   374,   489,
     899,   492,   614,   493,   966,   967,   968,   609,   610,   611,
     836,   837,   838,   495,   969,   615,   504,   616,   837,   838,
     505,  1232,   970,  1282,  1283,  1233,   528,   617,   971,   972,
     618,  1429,  1236,   607,   608,   529,  1240,   547,   934,   559,
    1242,  1243,   561,  1245,   948,   560,   630,   631,  1249,   562,
    1411,   792,   793,   794,   795,   796,   797,   798,   799,   800,
     801,   583,   584,  1044,   613,  1046,   762,   763,   769,   770,
     571,   771,   772,  1369,  1370,   578,   992,   992,   349,   614,
     581,   966,   967,   968,   948,   948,   948,   948,  1373,  1374,
     591,   598,   615,   599,   616,   372,   646,   648,   636,   970,
     637,   643,   662,  1278,   617,  1189,   972,   618,   671,   673,
     672,  1281,   530,   675,   686,   935,   948,   688,   408,   428,
     531,   532,   430,   533,   689,   437,   452,   696,  1293,   700,
     534,  1294,   697,  1296,   535,   699,   536,   703,   708,   722,
     726,   537,   727,   728,   729,   773,  1405,   732,   774,   775,
     776,   786,   789,   790,   791,   818,   814,   538,   815,   819,
    1055,   830,  1055,   841,   842,   843,   844,   847,   848,   855,
     856,   860,   857,   861,   864,   866,   858,   867,   877,   868,
     881,   539,   540,   541,   542,   543,   544,   869,   876,   888,
     889,   890,   891,   904,   905,   917,   916,   921,   929,  1339,
     918,   925,   926,   634,   930,   634,  1342,   954,  1343,   933,
     938,   941,   949,   951,  1347,   962,   981,   982,   983,   994,
    1011,   807,   995,   733,  1016,  1203,   838,  1049,  1355,  1356,
    1357,  1358,  1359,  1047,  1360,  1361,  1024,  1052,  1023,  1048,
    1029,  1058,  1060,  1059,  1064,  1063,  1065,  1067,  1069,  1154,
    1070,  1074,   527,  1367,  1071,  1076,  1078,  1368,  1093,  1098,
    1163,  1115,  1164,  1083,  1129,  1096,  1136,  1142,  1138,  1141,
     603,  1153,  1155,  1157,  1226,  1158,  1166,  1172,  1171,  1173,
    1196,  1174,  1184,  1193,  1197,     4,  1200,  1213,  1218,  1220,
    1195,  1238,  1385,  1227,  1229,  1389,  1209,  1391,  1219,  1392,
    1234,  1228,  1244,  1246,  1247,  1248,  1230,  1252,  1231,  1199,
    1257,  1255,  1260,  1256,  1270,  1254,  1273,  1146,  1265,  1288,
    1272,  1266,  1295,  1309,  1291,   998,  1292,  1280,  1313,  1261,
    1267,  1314,  1319,  1268,  1320,  1269,  1330,  1333,  1336,  1337,
    1338,  1340,  1378,  1341,  1025,  1379,  1348,  1352,  1385,  1365,
    1388,  1395,  1410,  1401,  1403,  1414,  1435,  1415,  1438,  1448,
     948,  1428,  1432,  1430,  1441,  1444,  1003,  1453,   720,   721,
     816,  1456,   494,  1207,   496,  1434,  1436,   497,   498,  1013,
    1216,   628,   665,  1412,  1005,  1274,  1312,   669,   725,   503,
     600,  1092,  1156,  1241,  1346,  1279,  1251,  1447,  1250,  1290,
     520,  1144,  1287,   687,  1284,  1239,   740,  1224,   741,   764,
     565,  1259,   567,   900,  1443,  1440,   993,  1057,  1206,  1262,
    1012,  1185,  1271,  1277,  1192,   680,   681,   960,  1308,  1190,
    1382,   961,  1322,  1306,  1186,     0,     0,     0,     0,     0,
     711,     0,     0,     0,     0,     0,     0,     0,     0,   460,
       0,     0,     0,   718,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   948,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1332,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1344,  1345,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1350,
       0,     0,     0,     0,  1354,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   948,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1390,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1400,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   460,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   948,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1431,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1437,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,  1450,
       0,     0,     5,     6,  1455,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
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
       0,   117,   118,     0,     0,   119,   120,   121,     0,     0,
       0,   122,     0,   123,   124,   125,     0,   126,   127,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     144,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,     0,     0,     0,     0,     0,     0,     0,
       0,     1,   214,   215,   216,   217,   218,   219,     2,     3,
       0,     4,     0,     0,     0,     0,   386,   387,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,   395,    21,    22,    23,    24,    25,    26,    27,
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
     120,   121,     0,     0,     0,   122,   463,   123,   124,   125,
       0,   126,   127,   128,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   411,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,   214,   215,   216,   217,
     218,     2,     3,     0,     4,     0,     0,     0,     0,     5,
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
     140,     0,     0,   141,   142,   143,     0,   144,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
       0,     0,     0,     0,     0,     0,     0,     1,     0,   214,
     215,   216,   217,   218,     2,     3,     0,     4,     0,     0,
       0,     0,     5,     6,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
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
       0,   117,   118,     0,     0,   119,   120,   121,     0,     0,
       0,   122,     0,   123,   124,   125,     0,   126,   127,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     411,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,     0,     0,     0,     0,     0,     0,     0,
       1,     0,   214,   215,   216,   217,   218,     2,     3,     0,
       4,     0,     0,     0,     0,   386,   387,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,   395,    21,    22,    23,    24,    25,    26,    27,     0,
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
     121,     0,   777,     0,   122,     0,   123,   124,   125,     0,
     126,   127,   128,     0,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,   143,     0,   411,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,   214,   215,   216,   217,   218,
       2,     3,     0,     4,     0,     0,     0,     0,   386,   387,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,   395,    21,    22,    23,    24,    25,
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
       0,   119,   120,   121,     0,     0,     0,   122,   783,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   411,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,   214,   215,
     216,   217,   218,     2,     3,     0,     4,     0,     0,     0,
       0,   386,   387,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,   395,    21,    22,
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
     117,   118,     0,     0,   119,   120,   121,     0,   853,     0,
     122,     0,   123,   124,   125,     0,   126,   127,   128,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   411,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,   214,   215,   216,   217,   218,     2,     3,     0,     4,
       0,     0,     0,     0,   386,   387,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
     395,    21,    22,    23,    24,    25,    26,    27,     0,    28,
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
       0,   870,     0,   122,     0,   123,   124,   125,     0,   126,
     127,   128,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   411,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,     0,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,   214,   215,   216,   217,   218,     2,
       3,     0,     4,     0,     0,     0,     0,   386,   387,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,   395,    21,    22,    23,    24,    25,    26,
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
     119,   120,   121,     0,   896,     0,   122,     0,   123,   124,
     125,     0,   126,   127,   128,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   411,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,   214,   215,   216,
     217,   218,     2,     3,     0,     4,     0,     0,     0,     0,
     386,   387,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,   395,    21,    22,    23,
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
     118,     0,     0,   119,   120,   121,     0,  1225,     0,   122,
       0,   123,   124,   125,     0,   126,   127,   128,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,   143,     0,   411,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,     0,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
     214,   215,   216,   217,   218,     2,     3,     0,     4,     0,
       0,     0,     0,   386,   387,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,   395,
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
    1237,     0,   122,     0,   123,   124,   125,     0,   126,   127,
     128,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   411,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,   214,   215,   216,   217,   218,     2,     3,
       0,     4,     0,     0,     0,     0,   386,   387,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,   395,    21,    22,    23,    24,    25,    26,    27,
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
     120,   121,     0,  1253,     0,   122,     0,   123,   124,   125,
       0,   126,   127,   128,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   411,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,   214,   215,   216,   217,
     218,     2,     3,     0,     4,     0,     0,     0,     0,   386,
     387,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,   395,    21,    22,    23,    24,
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
     140,     0,     0,   141,   142,   143,     0,   411,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,   214,
     215,   216,   217,   218,     2,     3,     0,     4,     0,     0,
       0,     0,   386,   387,     0,     7,   389,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,   394,   395,    21,
      22,   397,    24,    25,    26,    27,     0,   398,   399,    30,
     400,   401,   402,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,     0,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,     0,    72,    73,     0,     0,     0,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
       0,    85,     0,    86,    87,    88,    89,     0,    90,     0,
       0,     0,   406,    92,    93,    94,    95,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,   103,   104,   563,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,   564,   118,     0,     0,   119,   120,   121,     0,     0,
       0,   122,     0,   123,   124,   125,     0,   126,   127,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     411,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     412,   154,   414,   156,   415,   416,   159,   160,   161,   162,
     163,   164,   417,   166,   167,   418,   419,   420,   171,   421,
     422,   423,   175,   424,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,   214,   215,   216,   217,   218,     2,     3,     0,
       4,     0,     0,     0,     0,   386,   387,     0,     7,   389,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
     394,   395,    21,    22,   397,    24,    25,    26,    27,     0,
     398,   399,    30,   400,   401,   402,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,     0,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,     0,    72,    73,     0,
       0,     0,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,     0,    85,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,   406,    92,    93,    94,    95,
       0,     0,     0,     0,     0,    96,    97,    98,    99,   100,
     101,   102,     0,     0,     0,   103,   104,   105,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   111,   112,   113,
     114,   115,   116,     0,   117,   118,     0,     0,   119,   120,
     121,     0,     0,     0,   122,     0,   123,   124,   125,     0,
     126,   127,   128,     0,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,   143,     0,   411,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   412,   154,   414,   156,   415,   416,   159,
     160,   161,   162,   163,   164,   417,   166,   167,   418,   419,
     420,   171,   421,   422,   423,   175,   424,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,   214,   215,   216,   217,   218,
       2,     3,     0,     4,     0,     0,     0,     0,   922,   387,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,   395,    21,    22,    23,    24,    25,
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
       0,     0,   141,   142,   143,     0,   411,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,   214,   215,
     216,   217,   218,     2,     3,     0,     4,     0,     0,     0,
       0,   386,   387,     0,   388,   389,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,   394,   395,    21,    22,
     397,    24,    25,    26,    27,     0,   398,   399,    30,   400,
     401,   402,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,    72,    73,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   406,    92,    93,    94,    95,     0,     0,     0,     0,
       0,    96,    97,    98,    99,   100,   101,   102,     0,     0,
       0,   103,   104,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   112,   113,   114,   115,   116,     0,
       0,     0,     0,     0,   119,   120,   121,     0,     0,     0,
     122,     0,   123,   124,   125,     0,     0,     0,   128,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   411,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   412,
     154,   414,   156,   415,   416,   159,   160,   161,   162,   163,
     164,   417,   166,   167,   418,   419,   420,   171,   421,   422,
     423,   175,   424,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,   214,   215,   216,   217,   218,   386,   387,     0,   388,
     389,   454,   391,   455,   456,    13,    14,    15,    16,    17,
      18,   394,   395,   457,    22,   397,    24,    25,    26,    27,
       0,   398,   399,    30,   400,   401,   402,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,     0,    62,     0,    63,    64,    65,
     458,     0,     0,    69,    70,    71,     0,     0,     0,    73,
       0,     0,     0,     0,    75,    76,    77,     0,     0,    80,
      81,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,     0,    90,     0,     0,     0,   406,    92,    93,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    98,     0,
     100,   101,   102,     0,     0,     0,     0,     0,     0,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   409,   112,
     113,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,     0,     0,     0,   122,     0,   123,   124,     0,
       0,     0,     0,   128,     0,   129,     0,   130,   131,   132,
     133,   410,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,     0,     0,   411,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   412,   154,   414,   156,   415,   416,
     159,   160,   161,   162,   163,   164,   417,   166,   167,   418,
     419,   420,   171,   421,   422,   423,   175,   424,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,   214,   215,   216,   217,
     218,   386,   387,     0,   388,   389,   390,   391,   392,   393,
      13,    14,    15,    16,    17,    18,   394,   395,   396,    22,
     397,    24,    25,    26,    27,     0,   398,   399,    30,   400,
     401,   402,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   403,   404,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   405,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   406,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   102,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   409,   112,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,     0,     0,     0,     0,     0,   128,     0,
     129,     0,   130,   131,   132,   133,   410,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   411,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   412,
     413,   414,   156,   415,   416,   159,   160,   161,   162,   163,
     164,   417,   166,   167,   418,   419,   420,   171,   421,   422,
     423,   175,   424,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,     0,     0,     0,     0,   435,     0,     0,     0,     3,
       0,   214,   215,   216,   217,   218,   386,   387,     0,   388,
     389,   390,   391,   392,   393,    13,    14,    15,    16,    17,
      18,   394,   395,   396,    22,   397,    24,    25,    26,    27,
       0,   398,   399,    30,   400,   401,   402,    34,    35,    36,
      37,    38,    39,    40,    41,    42,   403,   404,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,     0,    62,     0,    63,    64,    65,
     405,     0,     0,    69,    70,    71,     0,     0,     0,    73,
       0,     0,     0,     0,    75,    76,    77,     0,     0,    80,
      81,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,     0,    90,     0,     0,     0,   406,    92,    93,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    98,     0,
     100,   101,   102,   436,     0,     0,   437,     0,     0,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   409,   112,
     113,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,     0,     0,     0,   122,     0,   123,     0,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   410,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,     0,     0,   411,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   412,   413,   414,   156,   415,   416,
     159,   160,   161,   162,   163,   164,   417,   166,   167,   418,
     419,   420,   171,   421,   422,   423,   175,   424,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   214,   215,   216,   217,
     218,   435,     0,     0,     0,     3,     0,   659,     0,     0,
       0,     0,   386,   387,     0,   388,   389,   390,   391,   392,
     393,    13,    14,    15,    16,    17,    18,   394,   395,   396,
      22,   397,    24,    25,    26,    27,     0,   398,   399,    30,
     400,   401,   402,    34,    35,    36,    37,    38,    39,    40,
      41,    42,   403,   404,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,     0,
       0,    62,     0,    63,    64,    65,   405,     0,     0,    69,
      70,    71,     0,     0,     0,    73,     0,     0,     0,     0,
      75,    76,    77,     0,     0,    80,    81,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,     0,    90,     0,
       0,     0,   406,    92,    93,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,     0,   100,   101,   102,     0,
       0,     0,     0,     0,     0,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   409,   112,   113,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,     0,
       0,   122,   660,   123,     0,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   410,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,     0,     0,
     411,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     412,   413,   414,   156,   415,   416,   159,   160,   161,   162,
     163,   164,   417,   166,   167,   418,   419,   420,   171,   421,
     422,   423,   175,   424,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,     0,     0,     0,     0,   435,     0,     0,     0,
       3,     0,   214,   215,   216,   217,   218,   386,   387,     0,
     388,   389,   390,   391,   392,   393,    13,    14,    15,    16,
      17,    18,   394,   395,   396,    22,   397,    24,    25,    26,
      27,     0,   398,   399,    30,   400,   401,   402,    34,    35,
      36,    37,    38,    39,    40,    41,    42,   403,   404,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     0,     0,    62,     0,    63,    64,
      65,   405,     0,     0,    69,    70,    71,     0,     0,     0,
      73,     0,     0,     0,     0,    75,    76,    77,     0,     0,
      80,    81,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   406,    92,    93,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
       0,   100,   101,   102,     0,     0,     0,     0,     0,     0,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   409,
     112,   113,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,     0,     0,     0,   122,     0,   123,     0,
       0,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   410,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,     0,     0,   411,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   412,   413,   414,   156,   415,
     416,   159,   160,   161,   162,   163,   164,   417,   166,   167,
     418,   419,   420,   171,   421,   422,   423,   175,   424,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,     0,     0,     0,
       0,     0,     0,   468,     0,     3,     0,   214,   215,   216,
     217,   218,   386,   387,     0,   388,   389,   390,   391,   392,
     393,    13,    14,    15,    16,    17,    18,   394,   395,   396,
      22,   397,    24,    25,    26,    27,     0,   398,   399,    30,
     400,   401,   402,    34,    35,    36,    37,    38,    39,    40,
      41,    42,   403,   404,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,     0,
       0,    62,     0,    63,    64,    65,   405,     0,     0,    69,
      70,    71,     0,     0,     0,    73,     0,     0,     0,     0,
      75,    76,    77,     0,     0,    80,    81,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,     0,    90,     0,
       0,     0,   406,    92,    93,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,     0,   100,   101,   102,     0,
       0,     0,     0,     0,     0,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   409,   112,   113,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,     0,
       0,   122,     0,   123,     0,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   410,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,     0,     0,
     411,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     412,   413,   414,   156,   415,   416,   159,   160,   161,   162,
     163,   164,   417,   166,   167,   418,   419,   420,   171,   421,
     422,   423,   175,   424,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     0,   214,   215,   216,   217,   218,   386,   387,     0,
     388,   389,   390,   391,   392,   393,    13,    14,    15,    16,
      17,    18,   394,   395,   396,    22,   397,    24,    25,    26,
      27,     0,   398,   399,    30,   400,   401,   402,    34,    35,
      36,    37,    38,    39,    40,    41,    42,   403,   404,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     0,     0,    62,     0,    63,    64,
      65,   405,     0,     0,    69,    70,    71,     0,     0,     0,
      73,     0,     0,     0,     0,    75,    76,    77,     0,     0,
      80,    81,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   406,    92,    93,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
       0,   100,   101,   102,   407,     0,     0,   408,     0,     0,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   409,
     112,   113,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,     0,     0,     0,   122,     0,   123,     0,
       0,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   410,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,     0,     0,   411,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   412,   413,   414,   156,   415,
     416,   159,   160,   161,   162,   163,   164,   417,   166,   167,
     418,   419,   420,   171,   421,   422,   423,   175,   424,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,     0,     0,     0,
       0,     0,     0,     0,     0,     3,     0,   214,   215,   216,
     217,   218,   386,   387,     0,   388,   389,   390,   391,   392,
     393,    13,    14,    15,    16,    17,    18,   394,   395,   396,
      22,   397,    24,    25,    26,    27,     0,   398,   399,    30,
     400,   401,   402,    34,    35,    36,    37,    38,    39,    40,
      41,    42,   403,   404,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,     0,
       0,    62,     0,    63,    64,    65,   405,     0,     0,    69,
      70,    71,     0,     0,     0,    73,     0,     0,     0,     0,
      75,    76,    77,     0,     0,    80,    81,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,     0,    90,     0,
       0,     0,   406,    92,    93,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,     0,   100,   101,   102,   451,
       0,     0,   452,     0,     0,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   409,   112,   113,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,     0,
       0,   122,     0,   123,     0,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   410,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,     0,     0,
     411,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     412,   413,   414,   156,   415,   416,   159,   160,   161,   162,
     163,   164,   417,   166,   167,   418,   419,   420,   171,   421,
     422,   423,   175,   424,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     0,   214,   215,   216,   217,   218,   386,   387,     0,
     388,   389,   390,   391,   392,   393,    13,    14,    15,    16,
      17,    18,   394,   395,   396,    22,   397,    24,    25,    26,
      27,     0,   398,   399,    30,   400,   401,   402,    34,    35,
      36,    37,    38,    39,    40,    41,    42,   403,   404,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     0,     0,    62,     0,    63,    64,
      65,   405,     0,     0,    69,    70,    71,     0,     0,     0,
      73,     0,     0,     0,     0,    75,    76,    77,     0,     0,
      80,    81,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   406,    92,    93,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
       0,   100,   101,   102,     0,     0,     0,     0,     0,     0,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   409,
     112,   113,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,     0,     0,     0,   122,   640,   123,     0,
       0,     0,     0,     0,   641,     0,   129,     0,   130,   131,
     132,   133,   410,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,     0,     0,   411,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   412,   413,   414,   156,   415,
     416,   159,   160,   161,   162,   163,   164,   417,   166,   167,
     418,   419,   420,   171,   421,   422,   423,   175,   424,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,     0,     0,     0,
       0,     0,     0,     0,     0,     3,     0,   214,   215,   216,
     217,   218,   386,   387,     0,   388,   389,   390,   391,   392,
     393,    13,    14,    15,    16,    17,    18,   394,   395,   396,
      22,   397,    24,    25,    26,    27,     0,   398,   399,    30,
     400,   401,   402,    34,    35,    36,    37,    38,    39,    40,
      41,    42,   403,   404,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,     0,
       0,    62,     0,    63,    64,    65,   405,     0,     0,    69,
      70,    71,     0,     0,     0,    73,     0,     0,     0,     0,
      75,    76,    77,     0,     0,    80,    81,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,     0,    90,     0,
       0,     0,   406,    92,    93,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,     0,   100,   101,   102,     0,
       0,     0,     0,     0,     0,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   409,   112,   113,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,     0,
       0,   122,   683,   123,     0,     0,     0,     0,     0,   684,
       0,   129,     0,   130,   131,   132,   133,   410,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,     0,     0,
     411,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     412,   413,   414,   156,   415,   416,   159,   160,   161,   162,
     163,   164,   417,   166,   167,   418,   419,   420,   171,   421,
     422,   423,   175,   424,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     0,   214,   215,   216,   217,   218,   386,   387,     0,
     388,   389,   454,   391,   455,   456,    13,    14,    15,    16,
      17,    18,   394,   395,   457,    22,   397,    24,    25,    26,
      27,     0,   398,   399,    30,   400,   401,   402,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     0,     0,    62,     0,    63,    64,
      65,   458,     0,     0,    69,    70,    71,     0,     0,     0,
      73,     0,     0,     0,     0,    75,    76,    77,     0,     0,
      80,    81,  1221,     0,     0,     0,     0,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   406,    92,    93,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
       0,   100,   101,   942,     0,     0,     0,     0,     0,     0,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   409,
     112,   113,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,     0,     0,     0,   122,     0,   123,   124,
       0,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   410,   135,   136,   137,   138,   139,   140,     0,
       0,   943,   142,     0,     0,   411,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   412,   154,   414,   156,   415,
     416,   159,   160,   161,   162,   163,   164,   417,   166,   167,
     418,   419,   420,   171,   421,   422,   423,   175,   424,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,     0,     0,     0,
       0,     0,     0,     0,     0,     3,     0,   214,   215,   216,
     217,   218,   386,   387,     0,   388,   389,   454,   391,   455,
     456,    13,    14,    15,    16,    17,    18,   394,   395,   457,
      22,   397,    24,    25,    26,    27,     0,   398,   399,    30,
     400,   401,   402,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,     0,
       0,    62,     0,    63,    64,    65,   458,     0,     0,    69,
      70,    71,     0,     0,     0,    73,     0,     0,     0,     0,
      75,    76,    77,     0,     0,    80,    81,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,     0,    90,     0,
       0,     0,   406,    92,    93,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,     0,   100,   101,   942,     0,
       0,     0,     0,     0,     0,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   409,   112,   113,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,     0,
       0,   122,     0,   123,   124,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   410,   135,   136,
     137,   138,   139,   140,     0,     0,   943,   142,     0,     0,
     411,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     412,   154,   414,   156,   415,   416,   159,   160,   161,   162,
     163,   164,   417,   166,   167,   418,   419,   420,   171,   421,
     422,   423,   175,   424,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     0,   214,   215,   216,   217,   218,   386,   387,     0,
     388,   389,   454,   391,   455,   456,    13,    14,    15,    16,
      17,    18,   394,   395,   457,    22,   397,    24,    25,    26,
      27,     0,   398,   399,    30,   400,   401,   402,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     0,     0,    62,     0,    63,    64,
      65,   458,     0,     0,    69,    70,    71,     0,     0,     0,
      73,     0,     0,     0,     0,    75,    76,    77,     0,     0,
      80,    81,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   406,    92,    93,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
       0,   100,   101,   942,     0,     0,     0,     0,     0,     0,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   409,
     112,   113,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,     0,     0,     0,   122,     0,   123,   124,
       0,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   410,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,     0,     0,   411,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   412,   154,   414,   156,   415,
     416,   159,   160,   161,   162,   163,   164,   417,   166,   167,
     418,   419,   420,   171,   421,   422,   423,   175,   424,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,     0,     0,     0,
       0,     0,     0,     0,     0,     3,     0,   214,   215,   216,
     217,   218,   386,   387,     0,   388,   389,   390,   391,   392,
     393,    13,    14,    15,    16,    17,    18,   394,   395,   396,
      22,   397,    24,    25,    26,    27,     0,   398,   399,    30,
     400,   401,   402,    34,    35,    36,    37,    38,    39,    40,
      41,    42,   403,   404,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,     0,
       0,    62,     0,    63,    64,    65,   405,     0,     0,    69,
      70,    71,     0,     0,     0,    73,     0,     0,     0,     0,
      75,    76,    77,     0,     0,    80,    81,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,     0,    90,     0,
       0,     0,   406,    92,    93,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,     0,   100,   101,   102,     0,
       0,     0,     0,     0,     0,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   409,   112,   113,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,     0,
       0,   122,     0,   123,     0,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   410,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,     0,     0,
     411,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     412,   413,   414,   156,   415,   416,   159,   160,   161,   162,
     163,   164,   417,   166,   167,   418,   419,   420,   171,   421,
     422,   423,   175,   424,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   214,   215,   216,   217,   218
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         9,   690,   733,   358,   547,   103,   551,   552,   553,   554,
     665,   826,    21,   983,   669,   864,   505,   866,   839,   127,
     903,   669,    26,    68,   527,   773,   774,    34,    35,    36,
      37,    38,    39,   971,  1138,   755,    60,  1276,    21,    46,
      88,    88,   773,   774,    48,   530,   116,   532,   533,    86,
     535,    88,   537,    85,   132,  1111,    20,    66,    86,    68,
     545,   546,     4,    20,    71,    20,     8,     7,     4,    20,
    1150,  1151,     8,    82,   805,   925,    99,   432,   433,   434,
      88,    30,   120,   126,   110,   443,    99,   120,   136,   737,
     110,   739,   237,   238,    99,   104,   103,   104,   105,   136,
      43,    86,   157,    99,   132,   836,   145,   116,    30,   118,
      32,    33,    99,   142,   259,   124,    65,    20,   476,   477,
      42,   479,   480,   481,   482,    99,    86,    58,    59,   487,
     121,   189,   490,   491,   136,   190,   165,   136,    88,   171,
     198,   105,    86,    65,    66,    53,   189,   185,   506,   175,
     157,   136,   185,   176,   174,  1005,   811,    88,   516,   517,
      34,    35,    36,    37,    38,    39,   179,    89,    92,     8,
       9,   113,    46,   115,   179,    86,   119,   113,    52,   115,
     176,   123,   206,   190,   262,   149,   294,   123,   179,    63,
      64,    99,   149,    67,   149,   145,    70,    71,   142,   102,
     142,   248,   249,  1259,  1284,   179,   142,  1446,   751,   752,
     899,   114,  1027,  1452,   262,  1036,  1065,  1456,  1101,   202,
     578,   105,   246,   163,   175,   262,   175,   882,  1111,   103,
     104,   105,   880,   240,   262,   138,   739,   224,   142,   142,
     248,   249,   145,  1213,    99,    99,    99,   207,   208,   604,
      99,  1189,   260,   973,   299,   177,    95,   302,   267,  1363,
     262,   746,   222,   262,   149,   147,   210,   211,   214,   276,
     145,   275,    99,   219,   113,   149,   115,   137,   285,   286,
     287,   288,   164,   157,   382,    98,    86,   385,    99,    99,
     299,   110,   214,   302,   154,   365,   207,   208,   214,   654,
     216,  1049,   226,   142,   117,    99,   157,   146,   956,   407,
     380,   222,    99,     8,     9,    99,   190,   241,  1049,   206,
     175,   175,   175,   162,   110,    99,   175,    99,   426,   427,
     254,   429,   256,   431,    99,   209,   136,    88,   436,   190,
     349,    45,   266,   147,   183,   269,   355,    51,   175,   252,
      54,    55,   361,   451,   105,   170,   365,   241,    62,   246,
     164,   370,   201,   372,   175,   175,   240,   437,   466,   184,
     728,   380,   381,   301,   472,   110,  1259,   735,    86,   307,
      30,   175,    54,   187,    34,     8,   270,   271,   175,   273,
     274,   175,     8,     9,   145,  1216,    19,   189,   137,   408,
      95,   175,   276,   175,    56,    57,   198,   155,  1378,   142,
     175,   285,   286,   287,   288,   154,     8,     9,   113,   127,
     115,    71,   170,   493,   132,   127,   969,   972,   437,   127,
     132,   440,   441,   442,    25,   286,   287,   288,   981,   109,
     449,   930,   142,   452,   142,   145,   134,   142,    98,   807,
      41,   146,  1200,   462,   158,   813,   160,    88,   110,   814,
     815,   569,   570,   170,   819,   135,   258,   162,   566,  1200,
     174,     8,   264,   571,   105,   484,   164,   184,   148,    95,
     272,   241,    19,   492,   493,   127,   145,   842,   183,  1338,
     113,  1340,   115,   802,   182,    20,   200,   113,   198,   115,
     142,   124,   145,    95,   126,   350,   201,   816,   158,   354,
     270,   271,   182,   273,   274,   873,   874,   139,   876,   142,
     878,   113,   258,   115,    92,   214,   142,   216,   264,    88,
     146,   110,   187,    92,   189,   142,   272,   105,   636,   637,
     898,   142,   258,   198,  1199,   643,   162,   263,   180,   181,
     142,   909,   910,   911,   146,   913,   914,   915,   916,   917,
     918,   145,   920,   921,   662,  1313,   572,   183,  1257,   575,
     162,   577,   581,  1262,   929,   933,   113,   102,   115,   849,
     650,   851,  1313,   653,   204,   201,   656,   124,   686,   114,
     599,   183,  1407,   221,   952,   223,   954,   955,   157,   214,
      87,    58,    59,   127,    61,   142,    88,  1317,   132,   201,
      92,    98,  1322,   138,   712,   142,   142,   142,   145,   145,
     145,   108,   892,   142,   894,  1396,  1397,   118,   119,  1174,
     117,    88,   280,   281,   282,   283,  1181,  1182,   996,   239,
    1388,   650,   242,   239,   653,   110,   242,   656,  1419,   221,
    1193,   223,   750,   110,  1425,    58,    59,  1388,  1016,   145,
     225,  1350,   227,   227,   673,  1354,   142,   226,    34,    35,
      36,   283,   284,    39,   231,   157,   286,   287,   288,   231,
     689,   110,   241,   149,   243,   244,   245,   210,   211,   212,
     277,   278,   279,     0,   253,   254,   179,   256,   278,   279,
     179,  1059,   261,   118,   119,  1060,   156,   266,   267,   268,
     269,  1400,  1067,   366,   367,    84,  1074,   251,   727,    68,
    1078,  1079,    93,  1081,   733,   188,   373,   374,  1086,    94,
    1385,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,   352,   353,   841,   226,   843,   548,   549,   555,   556,
     143,   557,   558,  1298,  1299,   145,   775,   776,    34,   241,
      34,   243,   244,   245,   773,   774,   775,   776,  1315,  1316,
      20,   141,   254,   110,   256,   286,   175,   175,   142,   261,
     142,   142,   142,  1141,   266,   267,   268,   269,   268,   110,
     268,  1146,   122,   110,   142,  1153,   805,   175,   145,   145,
     130,   131,   145,   133,    27,   145,   145,    15,  1166,    20,
     140,  1169,   175,  1171,   144,   202,   146,   175,   220,    25,
     158,   151,   110,   159,   159,   220,  1371,    99,    86,    86,
      86,   145,    20,    99,    99,   117,   149,   167,   149,   122,
     849,    20,   851,   289,   122,   142,   172,   175,   172,   172,
     172,    88,   172,    30,    88,    88,   175,   172,    99,   175,
     172,   191,   192,   193,   194,   195,   196,   175,   132,   175,
     175,   175,   172,   172,   172,   226,    86,   132,   122,  1234,
     214,   175,   172,   892,   179,   894,  1244,   136,  1246,   159,
     110,   110,   110,   110,  1252,   269,   250,   252,   257,   172,
     122,   132,   173,    86,   132,  1003,   279,    92,  1266,  1267,
    1268,  1269,  1270,   172,  1272,  1273,   272,   142,   271,   172,
     272,   172,   122,   186,   122,   149,    88,   122,   142,   938,
     172,   136,   941,  1288,   110,   110,   132,  1295,   142,    27,
     949,    20,   951,   246,   110,   172,   172,   110,   235,   142,
      71,    99,    99,   145,  1052,   145,   136,   172,   136,   175,
      47,   247,   247,   136,   134,    20,    86,    20,   159,   172,
     272,  1069,  1330,   175,   134,  1333,   272,  1335,   179,  1337,
      99,   175,   132,   136,   110,   110,   175,    61,   175,   998,
     122,   175,     6,   175,   226,  1093,   132,    98,   179,    98,
     174,   222,   136,   265,   175,   110,   175,   179,    86,  1107,
     222,   172,    20,   222,    20,   222,   145,   174,   172,   116,
      88,    88,    20,   172,    88,   255,   172,   172,  1386,   172,
      86,    59,    98,   185,   110,   174,   174,   110,    85,   110,
    1049,   185,   255,   185,   171,   185,   142,   110,   504,   504,
     603,   175,   219,  1012,   222,  1410,  1414,   222,   222,   806,
    1036,   371,  1071,  1386,   788,  1134,  1201,  1076,   508,   228,
     363,   887,   941,  1076,  1250,  1142,  1088,  1435,  1087,  1155,
     266,   933,  1153,   462,  1150,  1071,   528,  1050,   529,   550,
     287,  1101,   291,   690,  1425,  1419,   776,   851,  1011,  1108,
     805,   969,  1129,  1139,   981,   450,   450,   751,  1193,   973,
    1327,   752,  1212,  1188,   970,    -1,    -1,    -1,    -1,    -1,
    1129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1138,
      -1,    -1,    -1,  1142,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1200,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1247,  1248,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1258,
      -1,    -1,    -1,    -1,  1263,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1313,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1334,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1351,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1363,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1388,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1403,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1415,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,  1448,
      -1,    -1,    25,    26,  1453,    28,    29,    30,    31,    32,
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
      -1,   164,   165,    -1,    -1,   168,   169,   170,    -1,    -1,
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
     273,   274,   275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    10,   285,   286,   287,   288,   289,   290,    17,    18,
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
     169,   170,    -1,    -1,    -1,   174,   175,   176,   177,   178,
      -1,   180,   181,   182,    -1,   184,    -1,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    -1,    -1,
     199,   200,   201,    -1,   203,   204,    -1,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    10,    -1,   285,   286,   287,   288,
     289,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,   285,
     286,   287,   288,   289,    17,    18,    -1,    20,    -1,    -1,
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
      -1,   164,   165,    -1,    -1,   168,   169,   170,    -1,    -1,
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
     273,   274,   275,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      10,    -1,   285,   286,   287,   288,   289,    17,    18,    -1,
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
     270,   271,   272,   273,   274,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    -1,   285,   286,   287,   288,   289,
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
      -1,   168,   169,   170,    -1,    -1,    -1,   174,   175,   176,
     177,   178,    -1,   180,   181,   182,    -1,   184,    -1,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      -1,    -1,   199,   200,   201,    -1,   203,   204,    -1,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,   251,   252,    -1,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,   285,   286,
     287,   288,   289,    17,    18,    -1,    20,    -1,    -1,    -1,
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
     274,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,
      -1,   285,   286,   287,   288,   289,    17,    18,    -1,    20,
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
     271,   272,   273,   274,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    10,    -1,   285,   286,   287,   288,   289,    17,
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
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    10,    -1,   285,   286,   287,
     288,   289,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
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
     165,    -1,    -1,   168,   169,   170,    -1,   172,    -1,   174,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,
     285,   286,   287,   288,   289,    17,    18,    -1,    20,    -1,
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
     272,   273,   274,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    10,    -1,   285,   286,   287,   288,   289,    17,    18,
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
     269,   270,   271,   272,   273,   274,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    10,    -1,   285,   286,   287,   288,
     289,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,
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
     266,   267,   268,   269,   270,   271,   272,   273,   274,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,   285,
     286,   287,   288,   289,    17,    18,    -1,    20,    -1,    -1,
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
      -1,   164,   165,    -1,    -1,   168,   169,   170,    -1,    -1,
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
     273,   274,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      10,    -1,   285,   286,   287,   288,   289,    17,    18,    -1,
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
     270,   271,   272,   273,   274,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    10,    -1,   285,   286,   287,   288,   289,
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
     267,   268,   269,   270,   271,   272,   273,   274,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,   285,   286,
     287,   288,   289,    17,    18,    -1,    20,    -1,    -1,    -1,
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
     244,   245,   246,   247,   248,   249,    -1,   251,   252,    -1,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,   285,   286,   287,   288,   289,    25,    26,    -1,    28,
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
      -1,    -1,    -1,   182,    -1,   184,    -1,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    -1,    -1,
     199,   200,    -1,    -1,   203,   204,    -1,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    -1,   251,   252,    -1,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,   285,   286,   287,   288,
     289,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
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
     274,    -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,    18,
      -1,   285,   286,   287,   288,   289,    25,    26,    -1,    28,
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
     269,   270,   271,   272,   273,   274,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   285,   286,   287,   288,
     289,    14,    -1,    -1,    -1,    18,    -1,    20,    -1,    -1,
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
      -1,   174,   175,   176,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   184,    -1,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,   199,   200,    -1,    -1,
     203,   204,    -1,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,   251,   252,
      -1,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,    -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,
      18,    -1,   285,   286,   287,   288,   289,    25,    26,    -1,
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
     268,   269,   270,   271,   272,   273,   274,    -1,    -1,    -1,
      -1,    -1,    -1,    16,    -1,    18,    -1,   285,   286,   287,
     288,   289,    25,    26,    -1,    28,    29,    30,    31,    32,
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
      -1,   174,    -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   184,    -1,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,   199,   200,    -1,    -1,
     203,   204,    -1,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,   251,   252,
      -1,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,   285,   286,   287,   288,   289,    25,    26,    -1,
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
      -1,   139,   140,   141,   142,    -1,    -1,   145,    -1,    -1,
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
     268,   269,   270,   271,   272,   273,   274,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    -1,   285,   286,   287,
     288,   289,    25,    26,    -1,    28,    29,    30,    31,    32,
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
      -1,    -1,   135,   136,   137,    -1,   139,   140,   141,   142,
      -1,    -1,   145,    -1,    -1,   148,   149,    -1,    -1,    -1,
      -1,   154,   155,   156,   157,   158,   159,   160,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,
      -1,   174,    -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   184,    -1,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,   199,   200,    -1,    -1,
     203,   204,    -1,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,   251,   252,
      -1,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,   285,   286,   287,   288,   289,    25,    26,    -1,
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
      -1,    -1,   170,    -1,    -1,    -1,   174,   175,   176,    -1,
      -1,    -1,    -1,    -1,   182,    -1,   184,    -1,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    -1,
      -1,   199,   200,    -1,    -1,   203,   204,    -1,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    -1,   285,   286,   287,
     288,   289,    25,    26,    -1,    28,    29,    30,    31,    32,
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
     273,   274,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,   285,   286,   287,   288,   289,    25,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    -1,    -1,    84,    -1,    86,    87,
      88,    89,    -1,    -1,    92,    93,    94,    -1,    -1,    -1,
      98,    -1,    -1,    -1,    -1,   103,   104,   105,    -1,    -1,
     108,   109,   110,    -1,    -1,    -1,    -1,    -1,   116,   117,
     118,   119,    -1,   121,    -1,    -1,    -1,   125,   126,   127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,   136,   137,
      -1,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
     148,   149,    -1,    -1,    -1,    -1,   154,   155,   156,   157,
     158,   159,   160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   170,    -1,    -1,    -1,   174,    -1,   176,   177,
      -1,    -1,    -1,    -1,    -1,    -1,   184,    -1,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    -1,
      -1,   199,   200,    -1,    -1,   203,   204,    -1,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    -1,   285,   286,   287,
     288,   289,    25,    26,    -1,    28,    29,    30,    31,    32,
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
      -1,   174,    -1,   176,   177,    -1,    -1,    -1,    -1,    -1,
      -1,   184,    -1,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,   199,   200,    -1,    -1,
     203,   204,    -1,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,   251,   252,
      -1,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,   285,   286,   287,   288,   289,    25,    26,    -1,
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
      -1,    -1,   170,    -1,    -1,    -1,   174,    -1,   176,   177,
      -1,    -1,    -1,    -1,    -1,    -1,   184,    -1,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    -1,
      -1,   199,   200,    -1,    -1,   203,   204,    -1,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,    -1,   251,   252,    -1,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    -1,   285,   286,   287,
     288,   289,    25,    26,    -1,    28,    29,    30,    31,    32,
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
      -1,   174,    -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   184,    -1,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,   199,   200,    -1,    -1,
     203,   204,    -1,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,    -1,   251,   252,
      -1,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   285,   286,   287,   288,   289
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
     272,   273,   274,   275,   285,   286,   287,   288,   289,   290,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   338,   339,   344,
     345,   348,   355,   357,   362,   363,   364,   365,   366,   374,
     375,   377,   378,   379,   384,   386,   388,   389,   390,   395,
     416,   419,   422,   423,   424,   425,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   472,   473,   474,   488,
     489,   491,   492,   493,   494,   495,   496,   497,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   516,   517,
     518,   519,   520,   521,   522,   525,   531,   532,   533,    34,
      35,    36,    37,    38,    39,    46,    52,    63,    64,    67,
      70,    71,   103,   104,   105,   149,   157,   190,   209,   240,
     276,   285,   286,   287,   288,   349,   350,   351,   367,   368,
     149,    86,   142,   210,   211,   145,    25,    26,    28,    29,
      30,    31,    32,    33,    40,    41,    42,    44,    50,    51,
      53,    54,    55,    65,    66,    89,   125,   142,   145,   157,
     190,   203,   213,   214,   215,   217,   218,   225,   228,   229,
     230,   232,   233,   234,   236,   531,   142,   142,   145,   142,
     145,   145,    26,    48,   275,    14,   142,   145,   530,   531,
     110,   110,   110,   142,    56,    57,   110,   381,    54,   145,
     145,   142,   145,   531,    30,    32,    33,    42,    89,   456,
     531,   531,   110,   175,   375,   531,   142,   530,    16,   531,
     531,   448,   142,    21,   202,   204,   214,   216,   145,   214,
     216,   214,   214,   219,   110,   142,   358,   227,   231,   231,
     145,   142,   110,   149,   307,     0,   309,   310,   312,    25,
      41,   314,   314,   374,   179,   179,    99,   179,   376,    45,
      51,    54,    55,    62,   158,   160,   174,   200,   380,   385,
     386,   387,   404,   405,   409,   391,   392,   531,   156,    84,
     122,   130,   131,   133,   140,   144,   146,   151,   167,   191,
     192,   193,   194,   195,   196,   440,   441,   251,   147,   164,
     187,   109,   135,   148,   182,   189,   198,   126,   139,    68,
     188,    93,    94,   147,   164,   439,   142,   445,   448,   180,
     181,   143,   460,   461,   456,   460,   456,   460,   145,   531,
     368,    34,   369,   367,   367,   368,   531,   170,   184,   157,
     190,    20,   529,   155,   170,   170,   184,   531,   141,   110,
     343,    30,    34,    71,    98,   158,   530,   350,   350,   210,
     211,   212,    92,   226,   241,   254,   256,   266,   269,   545,
     546,   547,   548,   549,   552,   557,   558,   531,   349,   531,
     351,   351,   530,   514,   531,   375,   142,   142,   375,   375,
     175,   182,   531,   142,   375,   375,   175,   375,   175,   375,
     149,   529,   105,   149,   337,   529,   149,   529,   375,    20,
     175,   530,   142,   417,   418,   531,   531,   396,   398,   531,
     378,   268,   268,   110,   399,   110,   531,    30,    65,   175,
     512,   513,   375,   175,   182,   531,   142,   417,   175,    27,
     476,   477,   478,   375,     7,   163,    15,   175,   375,   202,
      20,   378,   378,   175,   378,   378,   378,   378,   220,   523,
     524,   531,   359,   378,   378,   378,   397,   403,   531,   530,
     316,   317,    25,   318,   378,   377,   158,   110,   159,   159,
     378,   378,    99,    86,    88,   136,   262,   393,   394,   499,
     424,   425,   427,   427,   427,   427,   426,   427,   427,   427,
     142,   145,   252,   463,   534,   536,   537,   538,   539,   540,
     541,   542,   430,   430,   429,   431,   431,   431,   431,   432,
     432,   433,   433,   220,    86,    86,    86,   172,   375,   448,
     448,   375,   461,   175,   378,   471,   145,   356,   531,    20,
      99,    99,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,   320,   321,   322,    86,   127,   132,   340,   341,
     342,   531,   127,   132,   149,   149,   320,   529,   117,   122,
     239,   242,   105,   241,   270,   271,   273,   274,   239,   242,
      20,   241,   270,   271,   273,   274,   277,   278,   279,   346,
     347,   289,   122,   142,   172,   375,   375,   175,   172,    99,
     175,    99,   175,   172,   375,   172,   172,   172,   175,   530,
      88,    30,   530,   529,    88,   530,    88,   172,   175,   175,
     172,   375,    99,   176,   136,   499,   132,    99,   132,   394,
     499,   172,   531,    60,   206,   246,   382,   383,   175,   175,
     175,   172,    99,   175,    99,   175,   172,   375,   176,   531,
     477,   478,   120,   185,   172,   172,   121,   179,    86,   207,
     208,   222,    86,   207,   208,   222,    86,   226,   214,    99,
     224,   132,    25,   360,   375,   175,   172,    53,    99,   122,
     179,   105,   179,   159,   531,   378,   410,   411,   110,   406,
     407,   110,   141,   199,   500,   502,   503,   504,   531,   110,
     378,   110,   136,   394,   136,   136,   393,   394,   427,   375,
     534,   540,   269,   568,    88,   157,   243,   244,   245,   253,
     261,   267,   268,   535,   543,   544,   545,   559,   562,   563,
     565,   250,   252,   257,   564,   237,   238,   259,   560,   500,
     500,   498,   503,   498,   172,   173,    99,   175,   110,   175,
     370,   371,   127,   142,   373,   356,   137,   154,   137,   154,
     321,   122,   502,   342,   378,   499,   132,   378,   529,   529,
     118,   119,   529,   271,   272,    88,   105,   145,   551,   272,
      32,    33,    42,    66,    89,   214,   504,   280,   281,   282,
     283,   283,   284,   347,   375,   529,   375,   172,   172,    92,
     420,   421,   142,   514,   515,   531,   514,   515,   172,   186,
     122,   336,   529,   149,   122,    88,   336,   122,   336,   142,
     172,   110,   378,   378,   136,   378,   110,   378,   132,   132,
     394,   136,   499,   246,    58,    59,    61,   110,   393,   400,
     401,   402,   383,   142,   514,   514,   172,   378,    27,   478,
     120,   185,     8,     9,    95,   113,   115,   142,   183,   372,
     473,   475,   486,   487,   490,    20,   221,   223,   378,   378,
     378,   221,   223,   378,   378,   378,   378,   378,   378,   110,
     378,   378,   343,   361,    99,   179,   172,   358,   235,   526,
     527,   142,   110,   529,   410,    87,    98,   108,   117,   412,
     413,   414,   415,    99,   531,    99,   392,   145,   145,   134,
     164,   182,   501,   531,   531,   378,   136,   378,   378,   136,
     394,   136,   172,   175,   247,   206,   246,   258,   263,   567,
      88,   248,   249,   561,   247,   537,   567,   428,   431,   267,
     543,   545,   538,   136,   561,   272,    47,   134,   378,   531,
      86,    99,   175,   375,   127,   358,   516,   341,   378,   272,
      88,   145,   554,    20,   105,   551,   346,   347,   159,   179,
     172,   110,   500,   105,   421,   172,   375,   175,   175,   134,
     175,   175,   378,   529,    99,   336,   529,   172,   375,   418,
     378,   398,   378,   378,   132,   378,   136,   110,   110,   378,
     531,   402,    61,   172,   375,   175,   175,   122,   183,   475,
       6,   375,   531,   183,   486,   179,   222,   222,   222,   222,
     226,   524,   174,   132,   361,   457,   528,   527,   378,   403,
     179,   529,   118,   119,   414,   415,   415,   411,    98,   408,
     407,   175,   175,   378,   378,   136,   378,   431,    43,   119,
     431,   431,   258,   264,   272,   566,   566,   428,   539,   265,
     499,   500,   371,    86,   172,   126,   189,   553,   556,    20,
      20,   555,   553,   260,   561,    99,   175,    99,   175,   347,
     145,   352,   531,   174,   110,   174,   172,   116,    88,   529,
      88,   172,   378,   378,   531,   531,   401,   378,   172,   478,
     531,   183,   172,   478,   531,   378,   378,   378,   378,   378,
     378,   378,   145,   198,   373,   172,   415,   529,   378,   431,
     431,   187,   500,   554,   554,   556,    20,   175,    20,   255,
     550,   551,   550,   353,   354,   378,    99,   175,    86,   378,
     531,   378,   378,   336,   336,    59,    85,   171,   479,   478,
     531,   185,   478,   110,   457,   431,   561,    99,   175,   175,
      98,   499,   353,   500,   174,   110,     4,   123,   482,   483,
     485,   487,    19,   124,   480,   481,   484,   487,   185,   478,
     185,   531,   255,   551,   529,   174,   378,   531,    85,   123,
     485,   171,   124,   484,   185,    99,   175,   378,   110,   373,
     531,    99,   175,   110,   373,   531,   175,   373
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
     555,   556,   557,   558,   559
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   305,   306,   306,   307,   307,   307,   307,   307,   307,
     308,   308,   309,   309,   310,   310,   311,   312,   312,   313,
     314,   314,   314,   315,   315,   316,   316,   317,   317,   317,
     317,   318,   318,   318,   318,   318,   318,   318,   318,   319,
     319,   320,   320,   321,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   323,   323,   323,   323,   323,   323,
     323,   323,   324,   324,   325,   326,   326,   327,   327,   328,
     329,   330,   330,   331,   331,   332,   332,   332,   332,   333,
     334,   335,   335,   335,   335,   336,   336,   337,   337,   338,
     338,   338,   338,   338,   338,   338,   338,   339,   340,   340,
     341,   341,   341,   342,   343,   343,   344,   344,   344,   345,
     345,   345,   345,   345,   345,   345,   345,   346,   346,   346,
     346,   347,   347,   348,   348,   349,   349,   349,   350,   350,
     350,   351,   352,   352,   353,   353,   354,   354,   355,   355,
     356,   356,   356,   356,   357,   358,   359,   359,   360,   360,
     361,   361,   362,   363,   364,   365,   365,   366,   366,   366,
     367,   367,   367,   367,   368,   368,   369,   369,   370,   370,
     371,   371,   372,   373,   374,   375,   375,   376,   376,   377,
     377,   378,   378,   378,   378,   378,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   378,   378,   379,   380,
     381,   381,   382,   382,   382,   383,   383,   384,   384,   385,
     386,   386,   386,   387,   387,   387,   387,   387,   388,   388,
     389,   389,   390,   391,   391,   392,   392,   392,   392,   392,
     392,   392,   392,   393,   394,   395,   396,   396,   397,   397,
     398,   398,   398,   398,   399,   399,   400,   400,   400,   401,
     401,   401,   402,   402,   402,   403,   404,   405,   406,   406,
     407,   407,   408,   409,   409,   410,   410,   411,   411,   412,
     412,   412,   412,   412,   412,   412,   413,   413,   414,   414,
     415,   416,   416,   417,   417,   418,   418,   419,   419,   420,
     420,   421,   421,   422,   423,   423,   424,   424,   425,   425,
     425,   425,   425,   426,   425,   425,   425,   425,   427,   427,
     427,   428,   428,   429,   429,   429,   430,   430,   430,   430,
     430,   431,   431,   431,   432,   432,   432,   433,   433,   434,
     434,   435,   435,   436,   436,   437,   437,   438,   438,   438,
     438,   439,   439,   439,   440,   440,   440,   440,   440,   440,
     441,   441,   441,   442,   442,   442,   442,   443,   443,   444,
     444,   445,   445,   446,   446,   446,   446,   447,   448,   448,
     448,   449,   449,   450,   450,   450,   450,   451,   451,   452,
     452,   452,   452,   452,   452,   452,   453,   453,   454,   454,
     455,   455,   455,   455,   455,   456,   456,   457,   457,   458,
     458,   458,   459,   459,   460,   460,   461,   462,   462,   462,
     462,   462,   462,   462,   462,   463,   463,   464,   464,   464,
     465,   466,   466,   467,   468,   469,   470,   470,   471,   471,
     472,   472,   473,   473,   473,   474,   474,   474,   474,   474,
     474,   475,   475,   476,   476,   477,   478,   478,   479,   479,
     480,   480,   481,   481,   481,   481,   482,   482,   483,   483,
     483,   483,   484,   484,   485,   485,   486,   486,   486,   486,
     487,   487,   487,   487,   488,   488,   489,   489,   490,   491,
     491,   491,   491,   491,   491,   492,   493,   493,   493,   493,
     494,   494,   494,   494,   495,   496,   497,   497,   497,   497,
     498,   498,   499,   500,   500,   500,   501,   501,   501,   502,
     502,   502,   503,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   505,   506,   506,   506,   507,   508,   509,   509,
     509,   510,   510,   510,   510,   510,   511,   512,   512,   512,
     512,   512,   512,   512,   513,   514,   515,   516,   517,   517,
     517,   518,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   519,   519,   520,   520,   521,   522,   523,   523,   524,
     525,   526,   526,   527,   527,   527,   527,   528,   528,   529,
     530,   530,   531,   531,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   533,   533,   534,
     534,   534,   534,   535,   535,   535,   535,   536,   536,   537,
     537,   538,   538,   539,   539,   540,   540,   540,   541,   541,
     542,   542,   543,   543,   543,   543,   543,   544,   545,   545,
     545,   545,   545,   545,   545,   546,   546,   546,   546,   547,
     547,   547,   547,   548,   548,   549,   549,   549,   549,   549,
     549,   549,   550,   550,   551,   551,   551,   551,   552,   552,
     552,   552,   552,   553,   553,   554,   554,   555,   555,   556,
     556,   557,   558,   558,   559,   559,   559,   560,   560,   560,
     560,   560,   561,   561,   561,   561,   562,   563,   564,   565,
     565,   566,   566,   566,   567,   567,   568
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  xquery_parser::yyr2_[] =
  {
         0,     2,     1,     2,     1,     2,     1,     2,     1,     2,
       4,     6,     2,     1,     1,     2,     6,     1,     2,     6,
       2,     2,     4,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     1,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     3,     3,     5,     5,     4,
       3,     3,     3,     5,     5,     5,     5,     5,     5,     4,
       3,     3,     4,     5,     6,     1,     3,     3,     3,     3,
       6,     5,     8,     3,     6,     5,     8,     4,     3,     1,
       1,     1,     2,     2,     2,     3,     5,     4,     6,     3,
       5,     4,     6,     4,     6,     5,     7,     2,     2,     2,
       2,     2,     2,     2,     3,     1,     2,     2,     1,     2,
       2,     7,     2,     3,     1,     3,     1,     2,     3,     3,
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
       1,     1,     1,     1,     1,     1,     1,     7,     4,     1,
       2,     3,     4,     1,     1,     2,     2,     1,     3,     1,
       3,     1,     4,     1,     2,     1,     2,     3,     1,     2,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     3,     3,     5,     7,     5,
       7,     2,     1,     3,     2,     4,     4,     6,     4,     5,
       4,     5,     3,     1,     2,     2,     3,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     2,     1,
       2,     1,     2,     3,     3,     4,     3,     3,     3,     2,
       2,     1,     1,     1,     1,     1,     3
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
  "\"'words'\"", "\"'thesaurus'\"", "\"'wildcards'\"", "\"'datamodule'\"",
  "\"'collection'\"", "\"'node-type'\"", "\"'collection-modifier'\"",
  "\"'node-modifier'\"", "\"'const'\"", "\"'append-only'\"", "\"'queue'\"",
  "\"'mutable'\"", "\"'read-only'\"", "\"'unique'\"", "\"'index'\"",
  "\"'manual'\"", "\"'automatic'\"", "\"'on'\"", "\"'BOM_UTF8'\"",
  "FTCONTAINS_REDUCE", "RANGE_REDUCE", "ADDITIVE_REDUCE",
  "MULTIPLICATIVE_REDUCE", "UNION_REDUCE", "INTERSECT_EXCEPT_REDUCE",
  "QVARINDECLLIST_REDUCE", "COMMA_DOLLAR", "UNARY_PREC",
  "SEQUENCE_TYPE_REDUCE", "OCCURS_STAR", "OCCURS_PLUS", "OCCURS_HOOK",
  "STEP_REDUCE", "$accept", "Module", "ModuleWithoutBOM", "VersionDecl",
  "MainModule", "LibraryModule", "ModuleDecl", "DataModule",
  "DataModuleDecl", "Prolog", "SIND_DeclList", "VFO_DeclList", "SIND_Decl",
  "VFO_Decl", "DecimalFormatDecl", "DecimalFormatParamList",
  "DecimalFormatParam", "DecimalFormatParamName", "Setter", "Import",
  "NamespaceDecl", "BoundarySpaceDecl", "DefaultNamespaceDecl",
  "OptionDecl", "FTOptionDecl", "OrderingModeDecl", "EmptyOrderDecl",
  "CopyNamespacesDecl", "DefaultCollationDecl", "BaseURIDecl",
  "SchemaImport", "URILiteralList", "SchemaPrefix", "ModuleImport",
  "CtxItemDecl", "CtxItemDecl2", "CtxItemDecl3", "CtxItemDecl4",
  "VarNameAndType", "VarDecl", "CollectionDecl", "CollectionModifier",
  "NodeModifier", "IndexDecl", "IndexDecl2", "IndexDecl3",
  "IndexDeclSuffix", "IndexKeyList", "IndexKeySpec", "IndexKeySpec1",
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
       306,     0,    -1,   307,    -1,   290,   307,    -1,   309,    -1,
     308,   309,    -1,   310,    -1,   308,   310,    -1,   312,    -1,
     308,   312,    -1,   203,   204,    20,   179,    -1,   203,   204,
      20,   121,    20,   179,    -1,   314,   374,    -1,   374,    -1,
     311,    -1,   311,   314,    -1,    26,   149,   530,   122,   529,
     179,    -1,   313,    -1,   313,   314,    -1,   275,   149,   530,
     122,   529,   179,    -1,   315,   179,    -1,   316,   179,    -1,
     315,   179,   316,   179,    -1,   317,    -1,   315,   179,   317,
      -1,   318,    -1,   316,   179,   318,    -1,   323,    -1,   324,
      -1,   325,    -1,   327,    -1,   344,    -1,   339,    -1,   366,
      -1,   328,    -1,   329,    -1,   345,    -1,   348,    -1,   319,
      -1,    25,   105,    71,   320,    -1,    25,    71,   531,   320,
      -1,   321,    -1,   320,   321,    -1,   322,   122,   516,    -1,
      72,    -1,    73,    -1,    74,    -1,    75,    -1,    76,    -1,
      77,    -1,    78,    -1,    79,    -1,    80,    -1,    81,    -1,
     326,    -1,   333,    -1,   334,    -1,   355,    -1,   330,    -1,
     331,    -1,   332,    -1,   517,    -1,   335,    -1,   338,    -1,
      25,   149,   530,   122,   529,    -1,    25,    70,   170,    -1,
      25,    70,   184,    -1,    25,   105,    30,   149,   529,    -1,
      25,   105,    34,   149,   529,    -1,    25,    46,   531,    20,
      -1,    25,   240,   545,    -1,    25,    63,   157,    -1,    25,
      63,   190,    -1,    25,   105,   158,   117,   118,    -1,    25,
     105,   158,   117,   119,    -1,    25,    67,   170,    99,   137,
      -1,    25,    67,   170,    99,   154,    -1,    25,    67,   155,
      99,   137,    -1,    25,    67,   155,    99,   154,    -1,    25,
     105,    98,   529,    -1,    25,    64,   529,    -1,    41,    48,
     529,    -1,    41,    48,   337,   529,    -1,    41,    48,   529,
      88,   336,    -1,    41,    48,   337,   529,    88,   336,    -1,
     529,    -1,   336,    99,   529,    -1,   149,   530,   122,    -1,
     105,    30,   149,    -1,    41,    26,   529,    -1,    41,    26,
     149,   530,   122,   529,    -1,    41,    26,   529,    88,   336,
      -1,    41,    26,   149,   530,   122,   529,    88,   336,    -1,
      41,   275,   529,    -1,    41,   275,   149,   530,   122,   529,
      -1,    41,   275,   529,    88,   336,    -1,    41,   275,   149,
     530,   122,   529,    88,   336,    -1,    25,   103,   141,   340,
      -1,    86,   502,   341,    -1,   341,    -1,   342,    -1,   127,
      -1,   127,   342,    -1,   132,   378,    -1,   110,   531,    -1,
     110,   531,   499,    -1,    25,   104,   343,   132,   378,    -1,
      25,   104,   343,   127,    -1,    25,   104,   343,   127,   132,
     378,    -1,    25,   276,   531,    -1,    25,   276,   531,   277,
     504,    -1,    25,   276,   531,   346,    -1,    25,   276,   531,
     277,   504,   346,    -1,    25,   276,   531,   347,    -1,    25,
     276,   531,   277,   504,   347,    -1,    25,   276,   531,   346,
     347,    -1,    25,   276,   531,   277,   504,   346,   347,    -1,
     278,   280,    -1,   278,   281,    -1,   278,   282,    -1,   278,
     283,    -1,   279,   284,    -1,   279,   283,    -1,    25,   349,
      -1,    25,   285,   349,    -1,   350,    -1,   190,   350,    -1,
     157,   350,    -1,   351,    -1,   287,   351,    -1,   288,   351,
      -1,   286,   531,   289,   375,   159,   352,   175,    -1,   145,
     353,    -1,   352,    99,   353,    -1,   354,    -1,   354,    98,
     529,    -1,   378,    -1,   378,   499,    -1,    25,    52,   170,
      -1,    25,    52,   184,    -1,   145,   175,    -1,   145,   370,
     175,    -1,   145,   175,    86,   500,    -1,   145,   370,   175,
      86,   500,    -1,   228,   358,    -1,   142,   359,   375,   172,
      -1,   359,   360,   179,    -1,    -1,   360,    99,   361,    -1,
      25,   361,    -1,   343,    -1,   343,   132,   378,    -1,    50,
     110,   531,   132,   378,    -1,   229,   227,   378,    -1,   233,
     145,   378,   175,   358,    -1,   230,   231,    -1,   232,   231,
      -1,    25,   367,    -1,    25,    38,   367,    -1,    25,    37,
     367,    -1,   368,    -1,    39,   368,    -1,    35,   368,    -1,
      36,   369,    -1,    34,   531,   356,   373,    -1,    34,   531,
     356,   127,    -1,    34,   531,   356,   358,    -1,    34,   531,
     356,   127,    -1,   371,    -1,   370,    99,   371,    -1,   110,
     531,    -1,   110,   531,   499,    -1,   142,   375,   172,    -1,
     142,   375,   172,    -1,   375,    -1,   377,    -1,   377,   376,
      -1,   179,    -1,   376,   377,   179,    -1,   378,    -1,   377,
      99,   378,    -1,   379,    -1,   416,    -1,   419,    -1,   422,
      -1,   423,    -1,   518,    -1,   519,    -1,   521,    -1,   520,
      -1,   522,    -1,   525,    -1,   533,    -1,   363,    -1,   364,
      -1,   365,    -1,   362,    -1,   357,    -1,   388,   380,    -1,
     174,   378,    -1,    56,   268,    -1,    57,   268,    -1,   206,
      -1,   246,    -1,    60,   246,    -1,   382,   400,    61,   378,
      -1,   382,    61,   378,    -1,    54,   381,   399,   383,   383,
      -1,    54,   381,   399,   383,    -1,    62,   110,   531,    -1,
     390,    -1,   395,    -1,   384,    -1,   386,    -1,   404,    -1,
     409,    -1,   405,    -1,   385,    -1,   386,    -1,   388,   387,
      -1,    54,   110,    -1,    55,    54,   110,    -1,   389,   391,
      -1,   392,    -1,   391,    99,   110,   392,    -1,   531,   136,
     378,    -1,   531,   499,   136,   378,    -1,   531,   393,   136,
     378,    -1,   531,   499,   393,   136,   378,    -1,   531,   394,
     136,   378,    -1,   531,   499,   394,   136,   378,    -1,   531,
     393,   394,   136,   378,    -1,   531,   499,   393,   394,   136,
     378,    -1,    88,   110,   531,    -1,   262,   110,   531,    -1,
      51,   110,   396,    -1,   398,    -1,   396,    99,   110,   398,
      -1,   403,    -1,   397,    99,   110,   403,    -1,   531,   132,
     378,    -1,   531,   499,   132,   378,    -1,   531,   394,   132,
     378,    -1,   531,   499,   394,   132,   378,    -1,   110,   531,
     136,   378,    -1,   110,   531,   499,   136,   378,    -1,   401,
      -1,   110,   531,    -1,   110,   531,   401,    -1,   393,    -1,
     393,   402,    -1,   402,    -1,    58,   110,   531,    59,   110,
     531,    -1,    59,   110,   531,    -1,    58,   110,   531,    -1,
     531,    -1,   200,   378,    -1,   160,   159,   406,    -1,   407,
      -1,   406,    99,   407,    -1,   110,   531,    -1,   110,   531,
     408,    -1,    98,   529,    -1,   158,   159,   410,    -1,    45,
     158,   159,   410,    -1,   411,    -1,   410,    99,   411,    -1,
     378,    -1,   378,   412,    -1,   413,    -1,   414,    -1,   415,
      -1,   413,   414,    -1,   413,   415,    -1,   414,   415,    -1,
     413,   414,   415,    -1,    87,    -1,   108,    -1,   117,   118,
      -1,   117,   119,    -1,    98,   529,    -1,    44,   110,   417,
     176,   378,    -1,   125,   110,   417,   176,   378,    -1,   418,
      -1,   417,    99,   110,   418,    -1,   531,   136,   378,    -1,
     531,   499,   136,   378,    -1,    29,   145,   375,   175,   420,
     105,   174,   378,    -1,    29,   145,   375,   175,   420,   105,
     110,   531,   174,   378,    -1,   421,    -1,   420,   421,    -1,
      92,   500,   174,   378,    -1,    92,   110,   531,    86,   500,
     174,   378,    -1,    40,   145,   375,   175,   186,   378,   116,
     378,    -1,   424,    -1,   423,   156,   424,    -1,   425,    -1,
     424,    84,   425,    -1,   427,    -1,   427,   440,   427,    -1,
     427,   441,   427,    -1,   427,   122,   427,    -1,   427,   151,
     427,    -1,    -1,   427,   146,   426,   427,    -1,   427,   144,
     427,    -1,   427,   133,   427,    -1,   427,   131,   427,    -1,
     428,    -1,   428,   251,   534,    -1,   428,   251,   534,   568,
      -1,   429,    -1,   429,   187,   429,    -1,   430,    -1,   429,
     164,   430,    -1,   429,   147,   430,    -1,   431,    -1,   430,
     182,   431,    -1,   430,   109,   431,    -1,   430,   135,   431,
      -1,   430,   148,   431,    -1,   432,    -1,   431,   189,   432,
      -1,   431,   198,   432,    -1,   433,    -1,   432,   139,   433,
      -1,   432,   126,   433,    -1,   434,    -1,   434,    68,   220,
     500,    -1,   435,    -1,   435,   188,    86,   500,    -1,   436,
      -1,   436,    93,    86,   498,    -1,   437,    -1,   437,    94,
      86,   498,    -1,   439,    -1,   438,   439,    -1,   164,    -1,
     147,    -1,   438,   164,    -1,   438,   147,    -1,   442,    -1,
     446,    -1,   443,    -1,   191,    -1,   196,    -1,   195,    -1,
     194,    -1,   193,    -1,   192,    -1,   140,    -1,   167,    -1,
     130,    -1,    28,   142,   375,   172,    -1,    28,   211,   142,
     375,   172,    -1,    28,   210,   142,   375,   172,    -1,    28,
      86,   514,   142,   375,   172,    -1,   444,   142,   172,    -1,
     444,   142,   375,   172,    -1,   445,    -1,   444,   445,    -1,
     165,   531,    15,    -1,   165,    16,    -1,   447,    -1,   447,
     448,    -1,   181,   448,    -1,   448,    -1,   180,    -1,   449,
      -1,   449,   180,   448,    -1,   449,   181,   448,    -1,   450,
      -1,   459,    -1,   451,    -1,   451,   460,    -1,   454,    -1,
     454,   460,    -1,   452,   456,    -1,   453,    -1,    97,    -1,
     106,    -1,    90,    -1,   178,    -1,   107,    -1,   129,    -1,
     128,    -1,   456,    -1,    91,   456,    -1,   455,   456,    -1,
     112,    -1,   161,    -1,    82,    -1,   169,    -1,   168,    -1,
      83,    -1,   504,    -1,   457,    -1,   531,    -1,   458,    -1,
     182,    -1,    10,    -1,    17,    -1,   462,    -1,   462,   460,
      -1,   461,    -1,   460,   461,    -1,   143,   375,   173,    -1,
     463,    -1,   465,    -1,   466,    -1,   467,    -1,   470,    -1,
     472,    -1,   468,    -1,   469,    -1,   464,    -1,   516,    -1,
     102,    -1,   138,    -1,   114,    -1,   110,   531,    -1,   145,
     175,    -1,   145,   375,   175,    -1,   111,    -1,   157,   142,
     375,   172,    -1,   190,   142,   375,   172,    -1,   531,   145,
     175,    -1,   531,   145,   471,   175,    -1,   378,    -1,   471,
      99,   378,    -1,   473,    -1,   491,    -1,   474,    -1,   488,
      -1,   489,    -1,   146,   531,   478,   120,    -1,   146,   531,
     476,   478,   120,    -1,   146,   531,   478,   185,   183,   531,
     478,   185,    -1,   146,   531,   478,   185,   475,   183,   531,
     478,   185,    -1,   146,   531,   476,   478,   185,   183,   531,
     478,   185,    -1,   146,   531,   476,   478,   185,   475,   183,
     531,   478,   185,    -1,   486,    -1,   475,   486,    -1,   477,
      -1,   476,   477,    -1,    27,   531,   478,   122,   478,   479,
      -1,    -1,    27,    -1,   171,   480,   171,    -1,    85,   482,
      85,    -1,    -1,   481,    -1,   124,    -1,   484,    -1,   481,
     124,    -1,   481,   484,    -1,    -1,   483,    -1,   123,    -1,
     485,    -1,   483,   123,    -1,   483,   485,    -1,    19,    -1,
     487,    -1,     4,    -1,   487,    -1,   473,    -1,     9,    -1,
     490,    -1,   487,    -1,     8,    -1,   113,    -1,   115,    -1,
     372,    -1,   201,    21,   202,    -1,   201,   202,    -1,   162,
     530,   163,    -1,   162,   530,     7,    -1,    95,     6,    -1,
     492,    -1,   493,    -1,   494,    -1,   495,    -1,   496,    -1,
     497,    -1,    31,   142,   375,   172,    -1,    30,   531,   142,
     172,    -1,    30,   531,   142,   375,   172,    -1,    30,   142,
     375,   172,   142,   172,    -1,    30,   142,   375,   172,   142,
     375,   172,    -1,    89,   531,   142,   172,    -1,    89,   531,
     142,   375,   172,    -1,    89,   142,   375,   172,   142,   172,
      -1,    89,   142,   375,   172,   142,   375,   172,    -1,    32,
     142,   375,   172,    -1,    33,   142,   375,   172,    -1,    42,
     530,   142,   172,    -1,    42,   530,   142,   375,   172,    -1,
      42,   142,   375,   172,   142,   172,    -1,    42,   142,   375,
     172,   142,   375,   172,    -1,   503,    -1,   503,   134,    -1,
      86,   500,    -1,   502,    -1,   502,   501,    -1,   199,   145,
     175,    -1,   134,    -1,   182,    -1,   164,    -1,   503,    -1,
     504,    -1,   141,   145,   175,    -1,   531,    -1,   506,    -1,
     512,    -1,   510,    -1,   513,    -1,   511,    -1,   509,    -1,
     508,    -1,   507,    -1,   505,    -1,   214,   145,   175,    -1,
      66,   145,   175,    -1,    66,   145,   512,   175,    -1,    66,
     145,   513,   175,    -1,    32,   145,   175,    -1,    33,   145,
     175,    -1,    42,   145,   175,    -1,    42,   145,   530,   175,
      -1,    42,   145,    20,   175,    -1,    89,   145,   175,    -1,
      89,   145,   531,   175,    -1,    89,   145,   531,    99,   514,
     175,    -1,    89,   145,   182,   175,    -1,    89,   145,   182,
      99,   514,   175,    -1,   177,   531,   175,    -1,    30,   145,
     175,    -1,    30,   145,   531,   175,    -1,    30,   145,   531,
      99,   514,   175,    -1,    30,   145,   531,    99,   515,   175,
      -1,    30,   145,   182,   175,    -1,    30,   145,   182,    99,
     514,   175,    -1,    30,   145,   182,    99,   515,   175,    -1,
      65,   145,   531,   175,    -1,   531,    -1,   531,   134,    -1,
      20,    -1,    25,   209,   210,    -1,    25,   209,   211,    -1,
      25,   209,   212,    -1,   215,   214,   378,   222,   378,    -1,
     215,   214,   378,    86,   221,   222,   378,    -1,   215,   214,
     378,    86,   223,   222,   378,    -1,   215,   214,   378,   207,
     378,    -1,   215,   214,   378,   208,   378,    -1,   215,   216,
     378,   222,   378,    -1,   215,   216,   378,    86,   221,   222,
     378,    -1,   215,   216,   378,    86,   223,   222,   378,    -1,
     215,   216,   378,   207,   378,    -1,   215,   216,   378,   208,
     378,    -1,   213,   214,   378,    -1,   213,   216,   378,    -1,
     218,   214,   378,   226,   378,    -1,   218,   219,   220,   214,
     378,   226,   378,    -1,   217,   214,   378,    86,   378,    -1,
     225,   110,   523,   224,   378,   174,   378,    -1,   524,    -1,
     523,    99,   110,   524,    -1,   531,   132,   378,    -1,   234,
     142,   378,   172,   526,    -1,   527,    -1,   526,   527,    -1,
     235,   528,   373,    -1,   235,   528,   145,   110,   531,   175,
     373,    -1,   235,   528,   145,   110,   531,    99,   110,   531,
     175,   373,    -1,   235,   528,   145,   110,   531,    99,   110,
     531,    99,   110,   531,   175,   373,    -1,   457,    -1,   528,
     198,   457,    -1,    20,    -1,    14,    -1,   531,    -1,    18,
      -1,   532,    -1,   203,    -1,   117,    -1,    89,    -1,    33,
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
      -1,    53,    -1,   236,    -1,    50,    -1,   286,    -1,   285,
      -1,   289,    -1,   287,    -1,   288,    -1,    71,    -1,    72,
      -1,    73,    -1,    74,    -1,    75,    -1,    76,    -1,    77,
      -1,    78,    -1,    79,    -1,    80,    -1,    81,    -1,   236,
     110,   397,    53,   142,   378,   172,    -1,    53,   142,   378,
     172,    -1,   536,    -1,   536,   535,    -1,   536,   267,   428,
      -1,   536,   535,   267,   428,    -1,   545,    -1,   543,    -1,
     535,   545,    -1,   535,   543,    -1,   537,    -1,   536,   253,
     537,    -1,   538,    -1,   537,   250,   538,    -1,   539,    -1,
     538,   252,   136,   539,    -1,   540,    -1,   252,   540,    -1,
     541,    -1,   541,   564,    -1,   145,   534,   175,    -1,   542,
      -1,   542,   560,    -1,   463,    -1,   142,   375,   172,    -1,
     544,    -1,   563,    -1,   562,    -1,   565,    -1,   559,    -1,
     157,    -1,   546,    -1,   547,    -1,   548,    -1,   549,    -1,
     552,    -1,   557,    -1,   558,    -1,   256,    -1,   266,    -1,
      92,   239,    -1,    92,   242,    -1,   226,   241,    -1,   269,
     241,    -1,   241,   239,    -1,   241,   242,    -1,   226,   270,
      -1,   269,   270,    -1,   226,   273,   551,    -1,   226,   273,
     105,    -1,   226,   273,   145,   551,   175,    -1,   226,   273,
     145,   551,    99,   550,   175,    -1,   226,   273,   145,   105,
     175,    -1,   226,   273,   145,   105,    99,   550,   175,    -1,
     269,   273,    -1,   551,    -1,   550,    99,   551,    -1,    88,
      20,    -1,    88,    20,   260,    20,    -1,    88,    20,   561,
     255,    -1,    88,    20,   260,    20,   561,   255,    -1,   226,
     271,   272,   554,    -1,   226,   271,   272,   554,   553,    -1,
     226,   105,   271,   272,    -1,   226,   105,   271,   272,   553,
      -1,   269,   271,   272,    -1,   556,    -1,   553,   556,    -1,
      88,    20,    -1,   145,   555,   175,    -1,    20,    -1,   555,
      20,    -1,   189,   554,    -1,   126,   554,    -1,   254,    20,
      -1,   226,   274,    -1,   269,   274,    -1,    88,   206,    -1,
      88,   246,    -1,   245,   247,    -1,   238,    -1,   238,    47,
      -1,   237,    -1,   237,   272,    -1,   259,    -1,   248,   431,
      -1,    88,   119,   431,    -1,    88,    43,   431,    -1,   249,
     431,   187,   431,    -1,   244,   561,   566,    -1,   268,   431,
     566,    -1,   257,   561,   265,    -1,   261,   567,    -1,   243,
     567,    -1,   272,    -1,   264,    -1,   258,    -1,   263,    -1,
     258,    -1,   269,   247,   431,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  xquery_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    10,    13,    15,    18,    20,
      23,    28,    35,    38,    40,    42,    45,    52,    54,    57,
      64,    67,    70,    75,    77,    81,    83,    87,    89,    91,
      93,    95,    97,    99,   101,   103,   105,   107,   109,   111,
     116,   121,   123,   126,   130,   132,   134,   136,   138,   140,
     142,   144,   146,   148,   150,   152,   154,   156,   158,   160,
     162,   164,   166,   168,   170,   176,   180,   184,   190,   196,
     201,   205,   209,   213,   219,   225,   231,   237,   243,   249,
     254,   258,   262,   267,   273,   280,   282,   286,   290,   294,
     298,   305,   311,   320,   324,   331,   337,   346,   351,   355,
     357,   359,   361,   364,   367,   370,   374,   380,   385,   392,
     396,   402,   407,   414,   419,   426,   432,   440,   443,   446,
     449,   452,   455,   458,   461,   465,   467,   470,   473,   475,
     478,   481,   489,   492,   496,   498,   502,   504,   507,   511,
     515,   518,   522,   527,   533,   536,   541,   545,   546,   550,
     553,   555,   559,   565,   569,   575,   578,   581,   584,   588,
     592,   594,   597,   600,   603,   608,   613,   618,   623,   625,
     629,   632,   636,   640,   644,   646,   648,   651,   653,   657,
     659,   663,   665,   667,   669,   671,   673,   675,   677,   679,
     681,   683,   685,   687,   689,   691,   693,   695,   697,   700,
     703,   706,   709,   711,   713,   716,   721,   725,   731,   736,
     740,   742,   744,   746,   748,   750,   752,   754,   756,   758,
     761,   764,   768,   771,   773,   778,   782,   787,   792,   798,
     803,   809,   815,   822,   826,   830,   834,   836,   841,   843,
     848,   852,   857,   862,   868,   873,   879,   881,   884,   888,
     890,   893,   895,   902,   906,   910,   912,   915,   919,   921,
     925,   928,   932,   935,   939,   944,   946,   950,   952,   955,
     957,   959,   961,   964,   967,   970,   974,   976,   978,   981,
     984,   987,   993,   999,  1001,  1006,  1010,  1015,  1024,  1035,
    1037,  1040,  1045,  1053,  1062,  1064,  1068,  1070,  1074,  1076,
    1080,  1084,  1088,  1092,  1093,  1098,  1102,  1106,  1110,  1112,
    1116,  1121,  1123,  1127,  1129,  1133,  1137,  1139,  1143,  1147,
    1151,  1155,  1157,  1161,  1165,  1167,  1171,  1175,  1177,  1182,
    1184,  1189,  1191,  1196,  1198,  1203,  1205,  1208,  1210,  1212,
    1215,  1218,  1220,  1222,  1224,  1226,  1228,  1230,  1232,  1234,
    1236,  1238,  1240,  1242,  1247,  1253,  1259,  1266,  1270,  1275,
    1277,  1280,  1284,  1287,  1289,  1292,  1295,  1297,  1299,  1301,
    1305,  1309,  1311,  1313,  1315,  1318,  1320,  1323,  1326,  1328,
    1330,  1332,  1334,  1336,  1338,  1340,  1342,  1344,  1347,  1350,
    1352,  1354,  1356,  1358,  1360,  1362,  1364,  1366,  1368,  1370,
    1372,  1374,  1376,  1378,  1381,  1383,  1386,  1390,  1392,  1394,
    1396,  1398,  1400,  1402,  1404,  1406,  1408,  1410,  1412,  1414,
    1416,  1419,  1422,  1426,  1428,  1433,  1438,  1442,  1447,  1449,
    1453,  1455,  1457,  1459,  1461,  1463,  1468,  1474,  1483,  1493,
    1503,  1514,  1516,  1519,  1521,  1524,  1531,  1532,  1534,  1538,
    1542,  1543,  1545,  1547,  1549,  1552,  1555,  1556,  1558,  1560,
    1562,  1565,  1568,  1570,  1572,  1574,  1576,  1578,  1580,  1582,
    1584,  1586,  1588,  1590,  1592,  1596,  1599,  1603,  1607,  1610,
    1612,  1614,  1616,  1618,  1620,  1622,  1627,  1632,  1638,  1645,
    1653,  1658,  1664,  1671,  1679,  1684,  1689,  1694,  1700,  1707,
    1715,  1717,  1720,  1723,  1725,  1728,  1732,  1734,  1736,  1738,
    1740,  1742,  1746,  1748,  1750,  1752,  1754,  1756,  1758,  1760,
    1762,  1764,  1766,  1770,  1774,  1779,  1784,  1788,  1792,  1796,
    1801,  1806,  1810,  1815,  1822,  1827,  1834,  1838,  1842,  1847,
    1854,  1861,  1866,  1873,  1880,  1885,  1887,  1890,  1892,  1896,
    1900,  1904,  1910,  1918,  1926,  1932,  1938,  1944,  1952,  1960,
    1966,  1972,  1976,  1980,  1986,  1994,  2000,  2008,  2010,  2015,
    2019,  2025,  2027,  2030,  2034,  2042,  2053,  2067,  2069,  2073,
    2075,  2077,  2079,  2081,  2083,  2085,  2087,  2089,  2091,  2093,
    2095,  2097,  2099,  2101,  2103,  2105,  2107,  2109,  2111,  2113,
    2115,  2117,  2119,  2121,  2123,  2125,  2127,  2129,  2131,  2133,
    2135,  2137,  2139,  2141,  2143,  2145,  2147,  2149,  2151,  2153,
    2155,  2157,  2159,  2161,  2163,  2165,  2167,  2169,  2171,  2173,
    2175,  2177,  2179,  2181,  2183,  2185,  2187,  2189,  2191,  2193,
    2195,  2197,  2199,  2201,  2203,  2205,  2207,  2209,  2211,  2213,
    2215,  2217,  2219,  2221,  2223,  2225,  2227,  2229,  2231,  2233,
    2235,  2237,  2239,  2241,  2243,  2245,  2247,  2249,  2251,  2253,
    2255,  2257,  2259,  2261,  2263,  2265,  2267,  2269,  2271,  2273,
    2275,  2277,  2279,  2281,  2283,  2285,  2287,  2289,  2291,  2293,
    2295,  2297,  2299,  2301,  2303,  2305,  2307,  2309,  2311,  2313,
    2315,  2317,  2319,  2321,  2323,  2325,  2327,  2329,  2331,  2333,
    2335,  2337,  2339,  2341,  2343,  2345,  2347,  2349,  2351,  2353,
    2355,  2357,  2359,  2361,  2363,  2365,  2367,  2369,  2371,  2373,
    2375,  2377,  2379,  2381,  2383,  2385,  2387,  2389,  2391,  2393,
    2395,  2397,  2399,  2401,  2403,  2405,  2407,  2409,  2411,  2413,
    2415,  2417,  2419,  2421,  2423,  2425,  2427,  2429,  2431,  2433,
    2435,  2437,  2439,  2441,  2443,  2445,  2447,  2449,  2457,  2462,
    2464,  2467,  2471,  2476,  2478,  2480,  2483,  2486,  2488,  2492,
    2494,  2498,  2500,  2505,  2507,  2510,  2512,  2515,  2519,  2521,
    2524,  2526,  2530,  2532,  2534,  2536,  2538,  2540,  2542,  2544,
    2546,  2548,  2550,  2552,  2554,  2556,  2558,  2560,  2563,  2566,
    2569,  2572,  2575,  2578,  2581,  2584,  2588,  2592,  2598,  2606,
    2612,  2620,  2623,  2625,  2629,  2632,  2637,  2642,  2649,  2654,
    2660,  2665,  2671,  2675,  2677,  2680,  2683,  2687,  2689,  2692,
    2695,  2698,  2701,  2704,  2707,  2710,  2713,  2716,  2718,  2721,
    2723,  2726,  2728,  2731,  2735,  2739,  2744,  2748,  2752,  2756,
    2759,  2762,  2764,  2766,  2768,  2770,  2772
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   909,   909,   910,   920,   925,   931,   936,   942,   947,
     959,   964,   974,   981,   993,   999,  1011,  1024,  1030,  1042,
    1055,  1061,  1067,  1079,  1085,  1099,  1105,  1119,  1120,  1121,
    1122,  1128,  1129,  1130,  1131,  1134,  1137,  1140,  1142,  1148,
    1153,  1162,  1168,  1177,  1186,  1187,  1188,  1189,  1190,  1191,
    1192,  1193,  1194,  1195,  1202,  1203,  1204,  1205,  1206,  1207,
    1208,  1211,  1218,  1219,  1231,  1243,  1248,  1259,  1265,  1277,
    1290,  1301,  1306,  1318,  1323,  1334,  1340,  1346,  1352,  1371,
    1382,  1393,  1400,  1407,  1414,  1427,  1433,  1448,  1452,  1462,
    1469,  1477,  1484,  1492,  1499,  1507,  1514,  1527,  1534,  1540,
    1547,  1553,  1557,  1564,  1575,  1580,  1589,  1598,  1605,  1615,
    1622,  1629,  1637,  1645,  1653,  1661,  1669,  1680,  1684,  1688,
    1692,  1700,  1704,  1712,  1716,  1724,  1728,  1732,  1740,  1744,
    1748,  1756,  1766,  1772,  1780,  1784,  1792,  1796,  1806,  1811,
    1823,  1827,  1831,  1835,  1842,  1849,  1868,  1878,  1884,  1890,
    1899,  1909,  1922,  1930,  1937,  1949,  1953,  1960,  1965,  1972,
    1980,  1984,  1988,  1996,  2003,  2012,  2024,  2033,  2046,  2054,
    2068,  2075,  2088,  2096,  2107,  2118,  2122,  2134,  2138,  2147,
    2151,  2167,  2168,  2169,  2170,  2171,  2174,  2175,  2176,  2177,
    2178,  2180,  2181,  2184,  2185,  2186,  2187,  2188,  2195,  2204,
    2211,  2215,  2223,  2227,  2231,  2238,  2242,  2249,  2257,  2268,
    2278,  2279,  2280,  2284,  2284,  2284,  2284,  2284,  2287,  2293,
    2302,  2306,  2316,  2327,  2333,  2347,  2355,  2364,  2374,  2385,
    2394,  2404,  2414,  2430,  2443,  2455,  2467,  2473,  2485,  2491,
    2505,  2514,  2524,  2533,  2546,  2553,  2564,  2565,  2570,  2579,
    2583,  2588,  2592,  2598,  2603,  2611,  2627,  2635,  2642,  2648,
    2659,  2666,  2676,  2686,  2691,  2703,  2709,  2723,  2729,  2741,
    2748,  2755,  2762,  2769,  2776,  2783,  2796,  2800,  2810,  2815,
    2826,  2837,  2844,  2857,  2864,  2876,  2883,  2897,  2904,  2919,
    2925,  2937,  2943,  2957,  2968,  2972,  2983,  2987,  3006,  3010,
    3018,  3026,  3034,  3042,  3042,  3050,  3058,  3066,  3080,  3084,
    3091,  3104,  3108,  3119,  3123,  3127,  3137,  3141,  3145,  3149,
    3153,  3163,  3167,  3172,  3183,  3187,  3191,  3201,  3205,  3217,
    3221,  3233,  3237,  3249,  3253,  3265,  3269,  3281,  3285,  3289,
    3293,  3305,  3309,  3313,  3323,  3327,  3331,  3335,  3339,  3343,
    3353,  3357,  3361,  3371,  3375,  3379,  3383,  3395,  3401,  3413,
    3419,  3433,  3440,  3481,  3485,  3489,  3493,  3505,  3515,  3526,
    3531,  3541,  3545,  3555,  3561,  3567,  3573,  3585,  3591,  3602,
    3606,  3610,  3614,  3618,  3622,  3626,  3636,  3640,  3650,  3654,
    3665,  3669,  3673,  3677,  3681,  3696,  3700,  3710,  3714,  3724,
    3731,  3738,  3751,  3755,  3767,  3773,  3787,  3798,  3802,  3806,
    3810,  3814,  3818,  3822,  3826,  3836,  3840,  3850,  3855,  3860,
    3871,  3882,  3886,  3897,  3907,  3918,  3974,  3980,  3992,  3998,
    4010,  4014,  4024,  4028,  4032,  4042,  4050,  4058,  4066,  4074,
    4082,  4097,  4103,  4115,  4121,  4134,  4143,  4145,  4151,  4156,
    4168,  4171,  4178,  4184,  4190,  4198,  4213,  4216,  4223,  4229,
    4235,  4243,  4257,  4262,  4273,  4278,  4289,  4294,  4299,  4305,
    4317,  4323,  4328,  4333,  4344,  4349,  4364,  4369,  4386,  4401,
    4405,  4409,  4413,  4417,  4421,  4431,  4442,  4448,  4454,  4459,
    4481,  4487,  4493,  4498,  4509,  4519,  4529,  4535,  4541,  4546,
    4557,  4563,  4575,  4586,  4592,  4598,  4635,  4640,  4645,  4656,
    4660,  4664,  4674,  4685,  4689,  4693,  4697,  4701,  4705,  4709,
    4713,  4717,  4727,  4737,  4741,  4746,  4757,  4767,  4777,  4781,
    4785,  4795,  4801,  4807,  4813,  4819,  4831,  4842,  4849,  4856,
    4863,  4870,  4877,  4884,  4897,  4918,  4925,  4945,  4985,  4989,
    4993,  5002,  5008,  5014,  5020,  5026,  5033,  5039,  5045,  5051,
    5057,  5069,  5074,  5084,  5090,  5102,  5128,  5139,  5145,  5158,
    5173,  5180,  5186,  5197,  5204,  5214,  5225,  5241,  5247,  5257,
    5266,  5267,  5285,  5289,  5296,  5297,  5298,  5299,  5300,  5301,
    5302,  5303,  5304,  5305,  5306,  5307,  5308,  5309,  5310,  5311,
    5312,  5313,  5314,  5315,  5316,  5317,  5318,  5319,  5320,  5321,
    5322,  5323,  5324,  5325,  5326,  5327,  5328,  5329,  5330,  5331,
    5332,  5333,  5334,  5335,  5336,  5337,  5338,  5339,  5340,  5341,
    5342,  5343,  5344,  5345,  5346,  5347,  5348,  5349,  5350,  5351,
    5352,  5353,  5354,  5355,  5356,  5357,  5358,  5359,  5360,  5361,
    5362,  5363,  5364,  5365,  5366,  5367,  5368,  5369,  5370,  5371,
    5372,  5373,  5374,  5375,  5376,  5377,  5378,  5379,  5380,  5381,
    5382,  5383,  5384,  5385,  5386,  5387,  5388,  5389,  5390,  5391,
    5392,  5393,  5394,  5395,  5396,  5397,  5398,  5399,  5400,  5401,
    5402,  5403,  5404,  5405,  5406,  5407,  5408,  5409,  5410,  5411,
    5412,  5413,  5414,  5415,  5416,  5417,  5418,  5419,  5420,  5421,
    5422,  5423,  5424,  5425,  5426,  5427,  5428,  5429,  5430,  5431,
    5432,  5433,  5434,  5435,  5436,  5437,  5438,  5439,  5440,  5441,
    5442,  5443,  5444,  5445,  5446,  5447,  5448,  5449,  5450,  5451,
    5452,  5453,  5454,  5455,  5456,  5457,  5458,  5459,  5460,  5461,
    5462,  5463,  5464,  5465,  5466,  5467,  5468,  5469,  5470,  5471,
    5472,  5473,  5474,  5475,  5476,  5477,  5478,  5489,  5495,  5512,
    5516,  5520,  5524,  5534,  5537,  5540,  5543,  5552,  5555,  5564,
    5567,  5576,  5579,  5588,  5591,  5600,  5603,  5606,  5615,  5618,
    5627,  5631,  5641,  5644,  5647,  5650,  5653,  5662,  5671,  5675,
    5679,  5683,  5687,  5691,  5695,  5705,  5708,  5711,  5714,  5723,
    5726,  5729,  5732,  5741,  5744,  5753,  5756,  5759,  5762,  5765,
    5768,  5771,  5780,  5783,  5792,  5795,  5798,  5801,  5810,  5813,
    5816,  5819,  5822,  5831,  5834,  5843,  5846,  5855,  5858,  5867,
    5870,  5879,  5888,  5891,  5900,  5903,  5906,  5915,  5918,  5921,
    5924,  5927,  5936,  5940,  5944,  5948,  5958,  5967,  5977,  5986,
    5989,  5998,  6001,  6004,  6013,  6016,  6025
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 9796;
  const int xquery_parser::yynnts_ = 264;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 495;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 305;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 559;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 13730 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6033 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"


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

