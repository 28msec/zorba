
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
#line 932 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"

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
#line 816 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 268 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 114: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 815 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 277 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 138: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 814 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 286 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 295 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 304 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 313 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 322 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "Prolog" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 331 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 340 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 349 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 358 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 367 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 376 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 828 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->pair_vector); };

/* Line 480 of lalr1.cc  */
#line 385 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 828 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->pair); };

/* Line 480 of lalr1.cc  */
#line 394 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 403 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 412 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 421 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 430 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 439 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 448 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 457 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 466 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 475 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 484 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 493 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 502 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 511 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 520 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 529 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 538 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 547 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 556 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 565 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 828 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 574 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 583 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 592 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "CollPropertyList" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 601 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "CollProperty" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 610 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "NodeModifier" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 619 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 628 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "IndexProperties" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 637 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "IndexProperties2" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 646 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "IndexProperties3" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 655 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 664 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 673 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 682 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 691 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 828 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 700 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 709 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "Block" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 718 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "BlockDecls" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 727 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "BlockVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 736 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "BlockVarDecl" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 745 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "AssignExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 754 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "ExitExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 763 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "WhileExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 772 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 781 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 790 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 799 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "FunctionDecl3" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 808 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "FunctionDecl4" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 817 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 835 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "EnclosedExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 844 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 853 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 862 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 871 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "ApplyExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 880 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "ConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 889 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 898 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 907 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 916 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 925 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 934 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 943 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 952 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 961 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 970 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 979 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 988 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 997 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1006 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1015 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "EvalVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1024 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1033 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1042 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1051 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1060 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1069 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "EvalVarDecl" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1078 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1087 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1096 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1105 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1114 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1123 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1132 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1141 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1150 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1159 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1168 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1177 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1186 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1195 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1204 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1213 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1222 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1231 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1240 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1249 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1258 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1267 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1276 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1285 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1294 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1303 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1312 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1321 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1330 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1339 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1348 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1357 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1366 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1375 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1384 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1393 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1402 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1411 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1420 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1429 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "PragmaList" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1438 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1447 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1456 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1465 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1474 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1483 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1492 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1501 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1510 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1519 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1528 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1537 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1546 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1555 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1564 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1573 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1582 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1591 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1600 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1609 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1618 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1627 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1636 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1645 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1654 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1663 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1672 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1681 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1690 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1699 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1708 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1717 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1726 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1735 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "Opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1744 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1753 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "Opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1762 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1771 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1780 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1789 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1798 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1807 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1816 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1825 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1834 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1843 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1852 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1861 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1870 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1879 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1888 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1897 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1906 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1915 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1924 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1933 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1942 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1951 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1960 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1969 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1978 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1987 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1996 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2005 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2014 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2023 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2032 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2041 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2050 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2059 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2068 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2077 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2086 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2095 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2104 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2113 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2122 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2131 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2140 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2149 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2158 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 828 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2167 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2176 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "EvalExpr" */

/* Line 480 of lalr1.cc  */
#line 826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 950 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 960 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		}
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 965 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<MainModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr ((yyval.node));
		}
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 971 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
       driver.set_expr ((yyval.node));
		}
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 976 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
       driver.set_expr ((yyval.node));
		}
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 982 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
       driver.set_expr ((yyval.node));
    }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 987 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
       driver.set_expr ((yyval.node));
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 999 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)), encoding);
		}
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 1004 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
    }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1014 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)));
		}
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1021 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)),
                NULL);
		}
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1033 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC ((yyloc)), false,
                             static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)),
                             NULL);
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1039 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LibraryModule(LOC ((yyloc)), false,
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1051 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(6) - (3)].sval)),
								SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
      dynamic_cast<ModuleDecl *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
		}
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1064 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC ((yyloc)), true,
                             static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)),
                             NULL);
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1070 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LibraryModule(LOC ((yyloc)), true,
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1082 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleDecl(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)));
      // dynamic_cast<ModuleDecl *>($$)->setComment(SYMTAB($1));
		}
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1093 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)), NULL);
		}
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1097 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		}
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 1101 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC((yyloc)),
                      static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
                      static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 1113 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = new SIND_DeclList(LOC ((yyloc)));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		}
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 1119 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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
#line 1133 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = new VFO_DeclList(LOC ((yyloc)));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		}
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 1139 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (vfoList_p) {
				vfoList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1185 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].pair_vector));
      delete (yysemantic_stack_[(4) - (4)].pair_vector);
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1190 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr))->get_qname(), (yysemantic_stack_[(4) - (4)].pair_vector));
      delete (yysemantic_stack_[(4) - (3)].expr);
      delete (yysemantic_stack_[(4) - (4)].pair_vector);
    }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1199 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.pair_vector) = new std::vector<std::pair<std::string, std::string> > ();
      (yyval.pair_vector)->push_back(*(yysemantic_stack_[(1) - (1)].pair));
      delete (yysemantic_stack_[(1) - (1)].pair);
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1205 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].pair_vector)->push_back(*(yysemantic_stack_[(2) - (2)].pair));
      delete (yysemantic_stack_[(2) - (2)].pair);
      (yyval.pair_vector) = (yysemantic_stack_[(2) - (1)].pair_vector);
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1214 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *s = static_cast<StringLiteral *>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.pair) = new std::pair<std::string, std::string>((yysemantic_stack_[(3) - (1)].strval), s->get_strval());
      delete s;
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1222 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1223 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1224 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1225 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1226 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1227 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1228 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1229 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1230 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 1231 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1268 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1280 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		}
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1285 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		}
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1296 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_element_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1302 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_function_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1314 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OptionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
								SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
		}
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1327 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (3)].node));
		}
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1338 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		}
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1343 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		}
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1355 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		}
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1360 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		}
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1371 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::inherit_ns);
		}
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1377 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::no_inherit_ns);
		}
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1383 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::inherit_ns);
		}
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 1389 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::no_inherit_ns);
		}
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 1408 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)));
		}
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 1419 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		}
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1430 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		}
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1437 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)),
								NULL);
		}
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1444 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		}
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1451 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
		}
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1464 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = new URILiteralList(LOC ((yyloc)));
			uri_list_p->push_back(SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		}
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1470 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node));
			if (uri_list_p) {
				uri_list_p->push_back(SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1485 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1489 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		}
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1499 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)), false,
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1506 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)), false,
								SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
								SYMTAB ((yysemantic_stack_[(6) - (6)].sval)),
								NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
		}
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1514 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)), false,
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
		}
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1521 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)), false,
								SYMTAB ((yysemantic_stack_[(8) - (4)].sval)),
								SYMTAB ((yysemantic_stack_[(8) - (6)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
		}
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1529 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)), true,
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1536 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)), true,
								SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
								SYMTAB ((yysemantic_stack_[(6) - (6)].sval)),
								NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
		}
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1544 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)), true,
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
		}
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1551 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)), true,
								SYMTAB ((yysemantic_stack_[(8) - (4)].sval)),
								SYMTAB ((yysemantic_stack_[(8) - (6)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
		}
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1564 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1571 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->type = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1577 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1584 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(1) - (1)].node));
      d->ext = false;
      (yyval.node) = d;
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1590 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), NULL);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1594 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1601 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1612 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(), NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1617 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
                               dynamic_cast<SequenceType *> ((yysemantic_stack_[(3) - (3)].node)));
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1626 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(5) - (3)].varnametype)));
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								nt->name,
								nt->type,
								(yysemantic_stack_[(5) - (5)].expr));
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
		}
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 1635 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (3)].varnametype)));
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       NULL, true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
		}
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 1642 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(6) - (3)].varnametype)));
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       (yysemantic_stack_[(6) - (6)].expr), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
		}
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1652 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                               0, 
                               0, 
                               0);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1660 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                               0, 
                               static_cast<NodeModifier*>((yysemantic_stack_[(4) - (4)].node)), 
                               0);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1668 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                               0, 
                               0, 
                               static_cast<parsenode*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1676 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                               0, 
                               static_cast<NodeModifier*>((yysemantic_stack_[(6) - (4)].node)), 
                               static_cast<NodeModifier*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1684 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<CollPropertyList*>((yysemantic_stack_[(4) - (2)].node)), 0, 0);
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1690 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                               static_cast<CollPropertyList*>((yysemantic_stack_[(5) - (2)].node)), 
                               static_cast<NodeModifier*>((yysemantic_stack_[(5) - (5)].node)), 
                               0);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1698 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<CollPropertyList*>((yysemantic_stack_[(6) - (2)].node)), 
                               0, 
                               static_cast<parsenode*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1706 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(7) - (4)].expr)),
                               static_cast<CollPropertyList*>((yysemantic_stack_[(7) - (2)].node)), 
                               static_cast<NodeModifier*>((yysemantic_stack_[(7) - (5)].node)), 
                               static_cast<NodeModifier*>((yysemantic_stack_[(7) - (7)].node)));
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1717 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CollPropertyList* l = new CollPropertyList(LOC((yyloc)));
      l->addProperty(dynamic_cast<CollProperty*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1723 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<CollPropertyList*>((yysemantic_stack_[(2) - (1)].node))->addProperty(static_cast<CollProperty*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1731 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollProperty(LOC((yyloc)), StaticContextConsts::const_);
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1735 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollProperty(LOC((yyloc)), StaticContextConsts::append_only);
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1739 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollProperty(LOC((yyloc)), StaticContextConsts::queue);
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1743 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollProperty(LOC((yyloc)), StaticContextConsts::mutable_coll);
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1747 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollProperty(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1751 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollProperty(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1760 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1764 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1772 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(9) - (3)].expr)),
                         (yysemantic_stack_[(9) - (5)].expr),
                         dynamic_cast<IndexKeyList*>((yysemantic_stack_[(9) - (7)].node)),
                         dynamic_cast<IndexProperties*>((yysemantic_stack_[(9) - (9)].node)));
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1784 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1789 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      IndexProperties* p = dynamic_cast<IndexProperties*>((yysemantic_stack_[(2) - (2)].node));
      p->setUnique();
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1796 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1803 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1808 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      IndexProperties* p = dynamic_cast<IndexProperties*>((yysemantic_stack_[(2) - (2)].node));
      p->setOrdered();
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1815 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1821 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      // default properties: non-unique, non-ordered, manual
      (yyval.node) = new IndexProperties(LOC((yyloc)), false, false, false);
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1826 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexProperties(LOC((yyloc)), false, false, false);
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1831 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexProperties(LOC((yyloc)), false, false, true);
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1839 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* l = new IndexKeyList(LOC((yyloc)));
      l->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1845 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1854 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1859 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1866 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1873 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1885 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 145:

/* Line 678 of lalr1.cc  */
#line 1897 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 146:

/* Line 678 of lalr1.cc  */
#line 1909 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 147:

/* Line 678 of lalr1.cc  */
#line 1921 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 148:

/* Line 678 of lalr1.cc  */
#line 1934 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 149:

/* Line 678 of lalr1.cc  */
#line 1955 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.intval) = (yysemantic_stack_[(2) - (1)].intval) | (yysemantic_stack_[(2) - (2)].intval); }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1958 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.intval) = (yysemantic_stack_[(2) - (1)].intval) | (yysemantic_stack_[(2) - (2)].intval); }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1961 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.intval) = IntegrityConstraintDecl::IC_OPTION_CHECKED; // checked
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1966 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.intval) = IntegrityConstraintDecl::IC_OPTION_CHECKED; // checked
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1970 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.intval) = IntegrityConstraintDecl::IC_OPTION_UNCHECKED;  // unchecked
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1976 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.intval) = IntegrityConstraintDecl::IC_OPTION_SYNCH; // synchronous
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1981 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.intval) = IntegrityConstraintDecl::IC_OPTION_SYNCH; // synchronous
    }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1985 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.intval) = IntegrityConstraintDecl::IC_OPTION_ASYNCH;  // asynchronous
    }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 1996 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		}
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 2001 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		}
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 2013 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL);
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 2017 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 2021 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL, dynamic_cast<SequenceType *> ((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 2025 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType *> ((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 2032 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2039 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 165:

/* Line 678 of lalr1.cc  */
#line 2065 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (1)].node));
      std::auto_ptr<VFO_DeclList> vfo2(dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (2)].node)));
      if ((yysemantic_stack_[(3) - (1)].node) == NULL)
        vfo = new VFO_DeclList (LOC ((yyloc)));
      vfo->push_back (*(vfo2.get()));
      (yyval.node) = vfo;
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 2074 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL;
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 2081 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (1)].node));
      vfo->push_back ((yysemantic_stack_[(3) - (3)].node));
      (yyval.node) = vfo;
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 2087 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = new VFO_DeclList (LOC ((yyloc)));
      vfo->push_back ((yysemantic_stack_[(2) - (2)].node));
      (yyval.node) = vfo;
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 2096 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 170:

/* Line 678 of lalr1.cc  */
#line 2106 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 171:

/* Line 678 of lalr1.cc  */
#line 2119 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr (LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr))->get_qname(), (yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (3)].expr);
    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 2127 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr (LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 2134 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 174:

/* Line 678 of lalr1.cc  */
#line 2148 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 2152 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::CONTINUE);
    }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 2159 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<FunctionDecl *>((yysemantic_stack_[(2) - (2)].node))->setComment(SYMTAB((yysemantic_stack_[(2) - (1)].sval)));
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 2164 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
      d->deterministic = false;
      (yyval.node) = d;
    }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 2171 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<FunctionDecl *>((yysemantic_stack_[(3) - (3)].node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2179 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2183 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2187 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(2) - (2)].node));
      d->type = (d->type == ParseConstants::fn_extern)
        ? ParseConstants::fn_extern_update
        : ParseConstants::fn_update;
      (yyval.node) = d;
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 2195 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 2202 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								(yysemantic_stack_[(4) - (4)].expr),
								ParseConstants::fn_read);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 2211 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								NULL,
								ParseConstants::fn_extern);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 2223 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								(yysemantic_stack_[(4) - (4)].expr),
								ParseConstants::fn_sequential);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 2232 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								NULL,
								ParseConstants::fn_extern_sequential);
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 2245 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = new ParamList(LOC ((yyloc)));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)));
			}
			(yyval.node) = plist_p;
		}
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 2253 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 2267 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(),
								NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
		}
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 2274 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
      delete (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 2287 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 2295 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 2306 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QueryBody(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
		}
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 2321 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 2325 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<BlockBody> blk(dynamic_cast<BlockBody *>((yysemantic_stack_[(2) - (2)].expr)));

      BlockBody* blk2 = new BlockBody(LOC((yyloc)));

      blk2->add((yysemantic_stack_[(2) - (1)].expr));

      for (int i = 0; i < blk->size(); ++i)
        blk2->add((*blk)[i]);

      (yyval.expr) = blk2;
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 2341 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody (LOC ((yyloc)));
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 2345 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = dynamic_cast<BlockBody *>((yysemantic_stack_[(3) - (1)].expr));
      blk->add((yysemantic_stack_[(3) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 2354 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 2358 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 217:

/* Line 678 of lalr1.cc  */
#line 2403 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 218:

/* Line 678 of lalr1.cc  */
#line 2416 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 2423 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 2427 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 2435 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 2439 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 2443 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_only_end;
    }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 2450 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), dynamic_cast<WindowVars *> ((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr), (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 2454 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr), (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 2461 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(5) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window,
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(5) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (4)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 2469 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window,
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 2480 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause (LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 2499 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = new FLWORClauseList (LOC ((yyloc)));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 2505 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = dynamic_cast<FLWORClauseList *> ((yysemantic_stack_[(2) - (1)].node));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 2514 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = NULL;
    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 2518 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_ofor;
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 2528 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForClause(LOC ((yyloc)),
                         dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL);
		}
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 2539 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		}
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 2545 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vardecl_list_p) {
				vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2559 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (1)].expr);
		}
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 2567 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2576 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 247:

/* Line 678 of lalr1.cc  */
#line 2586 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 248:

/* Line 678 of lalr1.cc  */
#line 2597 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2606 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 250:

/* Line 678 of lalr1.cc  */
#line 2616 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 251:

/* Line 678 of lalr1.cc  */
#line 2626 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 252:

/* Line 678 of lalr1.cc  */
#line 2642 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
		}
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2655 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
		}
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 2667 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)));

		}
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 2679 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		}
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 2685 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 2697 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		}
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 2703 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2717 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
								NULL,
								NULL,
								(yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (1)].expr);
		}
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2726 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2736 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2745 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (1)].expr);
		}
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2758 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr))->get_qname(),
								NULL, (yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (2)].expr);
		}
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2765 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (2)].expr);
		}
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2777 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(), "", "");
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2782 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_curr (static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2791 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), dynamic_cast<PositionalVar *> ((yysemantic_stack_[(1) - (1)].node)), "", "", "");
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2795 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_posvar (dynamic_cast<PositionalVar *> ((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2804 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr))->get_qname(), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr))->get_qname());
      delete (yysemantic_stack_[(6) - (3)].expr);
      delete (yysemantic_stack_[(6) - (6)].expr);
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2810 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", "", static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2815 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname(), "");
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2823 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      std::string name = static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr))->get_qname();
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           name, NULL, NULL,
                           new VarRef (LOC ((yyloc)), name),
                           VarGetsDecl::eval_var);
      delete (yysemantic_stack_[(1) - (1)].expr);

    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2839 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2847 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 2854 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = new GroupSpecList(LOC((yyloc)));
      gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl_p;
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2860 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      if (gsl_p) {
        gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      }
      (yyval.node) = gsl_p;
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2871 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(),
                 NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2878 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
                 dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2888 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2898 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2903 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)),
								true);
		}
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2915 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		}
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2921 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node));
			if (osl_p) {
				osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2935 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		}
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2941 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
                         (yysemantic_stack_[(2) - (1)].expr),
                         dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2953 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
                               NULL,
                               NULL);
		}
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2960 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               NULL,
                               dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
                               NULL);
		}
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 2967 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               NULL,
                               NULL,
                               dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 2974 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                               dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                               NULL);
		}
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 2981 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                               NULL,
                               dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 2988 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               NULL,
                               dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                               dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 2995 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                               dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                               dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 3008 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		}
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 3012 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		}
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 3022 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC((yyloc)), StaticContextConsts::empty_greatest);
		}
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 3026 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC((yyloc)), StaticContextConsts::empty_least);
		}
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 3036 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		}
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 3047 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 3054 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3067 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;

		}
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3074 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3086 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
								(yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (1)].expr);
		}
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3093 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3107 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
								(yysemantic_stack_[(8) - (8)].expr));
		}
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3114 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(10) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
								static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr))->get_qname(),
								(yysemantic_stack_[(10) - (10)].expr));
      delete (yysemantic_stack_[(10) - (8)].expr);
		}
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3129 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		}
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3135 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3147 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3153 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr))->get_qname(),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
      delete (yysemantic_stack_[(7) - (3)].expr);
		}
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3167 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
		}
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3178 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3182 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3193 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3197 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3216 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3220 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3228 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      /*  ::=  "is" | "<<" | ">>" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3236 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3244 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3251 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { /* this call is needed */  driver.lexer->interpretAsLessThan(); }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3252 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3260 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_le),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3268 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3276 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3290 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3294 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		}
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3301 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3314 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3318 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3329 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3333 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3337 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3347 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3351 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3355 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3359 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3363 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3373 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3377 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3382 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3393 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3397 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3401 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3411 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3415 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3427 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3431 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3443 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3447 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3459 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3463 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3475 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3479 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3491 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		}
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3495 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		}
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3499 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3503 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3515 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3519 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3523 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3533 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		}
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3537 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		}
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3541 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		}
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3545 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		}
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3549 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		}
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3553 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		}
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3563 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		}
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3567 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		}
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3571 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		}
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3581 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3585 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3589 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3593 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                            dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(),
                            (yysemantic_stack_[(6) - (5)].expr));
    }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3605 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		}
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3611 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3623 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		}
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3629 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node));
			if (pragma_list_p) {
				pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3643 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));

		}
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3649 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval))),
								"");
    }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3691 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		}
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3695 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3699 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3703 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (rpe == NULL ?
             (yysemantic_stack_[(1) - (1)].expr) :
             new PathExpr(LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3715 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3725 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 388:

/* Line 678 of lalr1.cc  */
#line 3736 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3741 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3751 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3755 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3765 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		}
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3771 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3777 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		}
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3783 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3795 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		}
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3801 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3812 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		}
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3816 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		}
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3820 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		}
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3824 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		}
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3828 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		}
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3832 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		}
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3836 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		}
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3846 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node), false);
		}
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3850 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		}
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3860 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseStep(LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node));
		}
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3864 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC((yyloc)), rev_p, NULL);
		}
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3875 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		}
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3879 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		}
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3883 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		}
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3887 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		}
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3891 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		}
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3906 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3910 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3920 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3924 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3934 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        "",
                        ParseConstants::wild_all);
		}
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3941 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        ParseConstants::wild_elem);
		}
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3948 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        ParseConstants::wild_prefix);
		}
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3961 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3965 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
                          (yysemantic_stack_[(2) - (1)].expr),
                          dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3977 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		}
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 3983 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node));
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 3997 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 4008 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 4012 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 4016 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 4020 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 4024 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 4028 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 4032 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 4036 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 4046 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 4050 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 4060 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval));
      delete yylval.decval;
		}
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 4065 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival));
      delete yylval.ival;
		}
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4070 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval));
      delete yylval.dval;
		}
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4081 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new VarRef(LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname());
      delete (yysemantic_stack_[(2) - (2)].expr);
		}
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4092 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		}
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4096 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4107 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		}
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4117 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4128 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4184 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)),
								NULL);
		}
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4190 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4202 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = new ArgList(LOC ((yyloc)));
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		}
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4208 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4220 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4224 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4234 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4238 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4242 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4252 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
								NULL,
								NULL,
								NULL);
		}
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4260 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
								NULL,
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)),
								NULL);
		}
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4268 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(8) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr)),
								NULL,
								NULL);
		}
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4276 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
								NULL,
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node)));
		}
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4284 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
								NULL);
		}
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4292 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(10) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)),
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node)));
		}
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4307 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		}
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4313 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4325 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		}
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4331 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4344 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
		}
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4361 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		}
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4366 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		}
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4377 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		}
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4381 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4388 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		}
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4394 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		}
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4400 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4408 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4422 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		}
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4426 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4433 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		}
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4439 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		}
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4445 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4453 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4467 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4472 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4483 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4488 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4499 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		}
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4504 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4509 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		}
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4515 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		}
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4527 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4533 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		}
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4538 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		}
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4543 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4554 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4559 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4574 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4579 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		}
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4596 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CDataSection(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		}
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4611 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4615 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4619 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4623 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4627 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4631 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4641 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4652 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
								NULL);
		}
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4658 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4664 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4669 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4691 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (2)].expr),
								NULL);
		}
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4697 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4703 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4708 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4719 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4729 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4739 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		}
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4745 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4751 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4756 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4767 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		}
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4773 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		}
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4785 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
		}
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4796 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		}
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4802 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4808 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		}
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4845 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		}
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4850 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		}
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4855 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		}
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4866 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4870 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4874 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		}
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4884 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4895 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4899 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4903 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4907 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4911 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4915 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4919 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4923 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4927 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4937 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		}
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4947 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		}
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4951 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4956 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4967 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TextTest(LOC ((yyloc)));
		}
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4977 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		}
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4987 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		}
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4991 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		}
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4995 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		}
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 5005 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		}
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 5011 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
								NULL);
		}
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 5017 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		}
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 5023 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		}
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 5029 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		}
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 5041 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
		}
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 5052 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           NULL,
                           NULL,
                           true);
		}
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 5059 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                           NULL,
                           true);
		}
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 5066 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           false);
		}
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 5073 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           true);
		}
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 5080 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL,
									true);
		}
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 5087 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									false);
		}
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 5094 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									true);
		}
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 5107 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)));
		}
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 5128 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 5135 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)),
								true);
		}
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 5155 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 5195 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::strict_validation);
		}
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 5199 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::lax_validation);
    }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5203 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::skip_validation);
    }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5212 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5218 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5224 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5230 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5236 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5243 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5249 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5255 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5261 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5267 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5279 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5284 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5294 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5300 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5312 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5338 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5349 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       CopyVarList* lList = new CopyVarList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
		}
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5355 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
       VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
       lList->push_back(lBinding);
       (yyval.expr) = lList;
		}
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5368 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (1)].expr);
    }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5384 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5391 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5397 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* aCatchListExpr = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if (aCatchListExpr) {
        aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)));
      }
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5408 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(3) - (2)].name_test_list),
                          (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5415 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(7) - (2)].name_test_list),
                          static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr))->get_qname(),
                          (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (5)].expr);
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5425 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 595:

/* Line 678 of lalr1.cc  */
#line 5436 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 596:

/* Line 678 of lalr1.cc  */
#line 5452 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CatchExpr::NameTestList *name_test_list = new CatchExpr::NameTestList;
      name_test_list->push_back (static_cast<NameTest *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.name_test_list) = name_test_list;
    }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5458 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      CatchExpr::NameTestList *name_test_list =
        static_cast<CatchExpr::NameTestList *> ((yysemantic_stack_[(3) - (1)].name_test_list));
      name_test_list->push_back (static_cast<NameTest *> ((yysemantic_stack_[(3) - (3)].node)));
      (yyval.name_test_list) = name_test_list;
    }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5478 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
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

  case 601:

/* Line 678 of lalr1.cc  */
#line 5496 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5500 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5506 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("xquery"); }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5507 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty"); }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5508 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("attribute"); }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5509 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("comment"); }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5510 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document-node"); }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5511 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("element"); }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5512 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("item"); }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5513 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("if"); }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5514 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("node"); }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5515 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("processing-instruction"); }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5516 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-attribute"); }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5517 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-element"); }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5518 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("text"); }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5519 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("typeswitch"); }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5520 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty-sequence"); }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5521 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("boundary-space"); }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5522 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ft-option"); }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5523 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("base-uri"); }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5524 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lax"); }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5525 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strict"); }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5526 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("idiv"); }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5527 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document"); }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5528 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("not"); }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5529 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sensitive"); }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5530 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insensitive"); }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5531 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("diacritics"); }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5532 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("without"); }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5533 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stemming"); }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5534 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("thesaurus"); }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5535 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stop"); }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5536 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("wildcards"); }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5537 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("entire"); }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5538 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("content"); }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5539 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("word"); }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5540 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("start"); }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5541 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("end"); }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5542 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("most"); }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5543 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("skip"); }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5544 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy"); }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5545 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("value"); }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5546 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eq"); }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5547 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ne"); }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5548 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lt"); }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5549 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("le"); }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5550 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("gt"); }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5551 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ge"); }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5552 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("at"); }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5553 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("context"); }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5554 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("variable"); }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5555 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("return"); }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5556 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("for"); }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5557 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("outer"); }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5558 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sliding"); }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5559 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("tumbling"); }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5560 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("previous"); }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5561 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("next"); }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5562 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("only"); }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5563 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("when"); }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5564 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("count"); }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5565 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("in"); }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5566 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("let"); }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5567 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("where"); }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5568 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("by"); }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5569 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("group"); }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5570 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("order"); }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5571 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stable"); }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5572 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ascending"); }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5573 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("descending"); }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5574 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("greatest"); }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5575 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("least"); }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5576 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("collation"); }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5577 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("some"); }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5578 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("every"); }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5579 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("satisfies"); }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5580 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("case"); }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5581 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("as"); }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5582 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("then"); }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5583 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("else"); }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5584 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("or"); }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5585 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("and"); }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5586 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("instance"); }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5587 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("of"); }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5588 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("castable"); }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5589 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("to"); }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5590 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("div"); }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5591 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("mod"); }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5592 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("union"); }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5593 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("intersect"); }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5594 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("except"); }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5595 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("validate"); }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5596 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("cast"); }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5597 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("treat"); }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5598 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("is"); }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5599 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("preserve"); }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5600 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strip"); }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5601 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("namespace"); }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5602 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("external"); }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5603 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("encoding"); }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 5604 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-preserve"); }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5605 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("inherit"); }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 5606 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-inherit"); }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 5607 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("declare"); }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 5608 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("construction"); }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 5609 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordering"); }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 5610 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("default"); }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 5611 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy-namespaces"); }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 5612 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("option"); }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 5613 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("version"); }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 5614 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("import"); }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 5615 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema"); }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 5616 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("module"); }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 5617 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("function"); }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 5618 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("score"); }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 5619 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ftcontains"); }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 5620 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("weight"); }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 5621 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("window"); }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 5622 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("distance"); }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 5623 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("occurs"); }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 5624 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("times"); }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 5625 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("same"); }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 5626 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("different"); }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 5627 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lowercase"); }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 5628 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("uppercase"); }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 5629 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("relationship"); }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 5630 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("levels"); }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 5631 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("language"); }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 5632 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("any"); }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 5633 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("all"); }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 5634 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("phrase"); }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 5635 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exactly"); }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 5636 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("from"); }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 5637 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("words"); }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 5638 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentences"); }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 5639 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentence"); }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 5640 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("paragraph"); }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 5641 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("replace"); }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 5642 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("modify"); }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 5643 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("first"); }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 5644 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insert"); }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 5645 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("before"); }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 5646 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("after"); }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 5647 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("revalidation"); }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 5648 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("with"); }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 5649 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nodes"); }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 5650 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("rename"); }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 5651 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("last"); }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 5652 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("delete"); }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 5653 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("into"); }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 5654 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("simple"); }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 5655 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sequential"); }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 5656 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("updating"); }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 5657 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("deterministic"); }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 5658 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nondeterministic"); }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 5659 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordered"); }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 5660 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unordered"); }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 5661 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("returning"); }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 5662 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("block"); }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 5663 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exit"); }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 5664 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("loop"); }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 5665 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("while"); }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 5666 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("break"); }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 5667 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("continue"); }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 5668 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("try"); }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 5669 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("catch"); }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 5670 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eval"); }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 5671 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("using"); }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 5672 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("set"); }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 5673 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("index"); }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 5674 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unique"); }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 5675 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("non"); }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 5676 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("on"); }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 5677 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("manual"); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 5678 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("automatic"); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 5679 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("decimal-format"); }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 5680 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("decimal-separator"); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 5681 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("grouping-separator"); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 5682 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("infinity"); }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 5683 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("minus-sign"); }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 5684 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("NaN"); }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 5685 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("percent"); }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 5686 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("per-mille"); }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 5687 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("zero-digit"); }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 5688 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("digit"); }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 5689 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("pattern-separator"); }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 5690 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("collection"); }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 5691 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("datamodule"); }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 5692 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("const"); }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 5694 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("queue"); }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 5695 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("mutable"); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 5696 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("read-only"); }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 5697 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("checked"); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 5698 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unchecked"); }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 5699 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("asynchronous"); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 5700 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("synchronous"); }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 5701 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("integrity"); }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 5702 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("constraint"); }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 5703 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("check"); }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 5704 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("key"); }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 5705 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("foreach"); }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 5706 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("type"); }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 5707 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("foreign"); }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 5708 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("keys"); }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 5720 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)),
                          (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 5726 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 5743 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(1) - (1)].node)), NULL, NULL);
		}
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 5747 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(2) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(2) - (2)].node)), NULL);
		}
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 5751 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(3) - (1)].node)), NULL, static_cast<RangeExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		}
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 5755 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(4) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(4) - (2)].node)), static_cast<RangeExpr *> ((yysemantic_stack_[(4) - (4)].expr)));
		}
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 5765 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 5768 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 5771 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 5774 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 5783 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 5786 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 5795 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 5798 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 5807 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 5810 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 5819 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 5822 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 5831 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 5834 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 5837 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 5846 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 5849 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 5858 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), static_cast<StringLiteral *> ((yysemantic_stack_[(1) - (1)].expr)), NULL);
		}
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 5862 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 5872 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 5875 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 5878 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 5881 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 5884 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 5893 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 5902 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 5906 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 5910 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 5914 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 5918 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 5922 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 5926 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 5936 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 5939 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 5942 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 5945 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 5954 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 5957 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 5960 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 5963 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 5972 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 5975 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 5984 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 5987 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 5990 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 5993 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 5996 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 5999 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 6002 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 6011 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 6014 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 6023 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 6026 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 6029 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 6032 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 6041 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 6044 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 6047 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 6050 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 6053 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 6062 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6065 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6074 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6077 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6086 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6089 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6098 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6101 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 6110 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 6119 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 6122 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 6131 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 6134 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 6137 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 6146 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 6149 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 6152 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 6155 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 6158 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 6167 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 6171 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 6175 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 6179 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6189 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6198 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWindow (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (2)].expr)), static_cast<FTUnit *> ((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 6208 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 6217 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 898:

/* Line 678 of lalr1.cc  */
#line 6220 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 899:

/* Line 678 of lalr1.cc  */
#line 6229 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 900:

/* Line 678 of lalr1.cc  */
#line 6232 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 901:

/* Line 678 of lalr1.cc  */
#line 6235 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 902:

/* Line 678 of lalr1.cc  */
#line 6244 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 903:

/* Line 678 of lalr1.cc  */
#line 6247 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 904:

/* Line 678 of lalr1.cc  */
#line 6256 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTIgnoreOption (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		}
    break;



/* Line 678 of lalr1.cc  */
#line 10412 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1348;
  const short int
  xquery_parser::yypact_[] =
  {
      1593, -1348, -1348, -1348, -1348,   772,   -59,    50,   144,  8528,
     -21,   -31,   227, -1348, -1348, -1348, -1348, -1348, -1348,   204,
      -5,  7390, -1348,   328, -1348, -1348, -1348, -1348,   380,   413,
   -1348,   250,   338,   489, -1348, -1348, -1348, -1348, -1348, -1348,
   -1348, -1348, -1348,   405,   421, -1348, -1348, -1348, -1348, -1348,
   -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348,
   -1348, -1348, -1348, -1348, -1348, -1348,  8810, -1348,  6814, -1348,
   -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348,
   -1348, -1348, 10502, -1348, -1348, -1348, -1348, -1348, -1348, -1348,
   -1348,   476, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348,
   -1348, -1348, -1348,  1884, 10502, -1348, -1348, -1348, -1348, -1348,
   -1348,   455, -1348, -1348, -1348, -1348,  7962, -1348,  8246, -1348,
   -1348, -1348, -1348, -1348, 10502, -1348, -1348,  6524, -1348, -1348,
   -1348, -1348, -1348, -1348,   479, -1348, -1348, -1348, -1348, -1348,
   -1348, -1348, -1348,    31,   390, -1348, -1348, -1348, -1348, -1348,
   -1348, -1348, -1348,   430,   458,   444, -1348,   396,   231, -1348,
   -1348, -1348, -1348, -1348, -1348,   516, -1348, -1348,   498,   416,
     439, -1348,   457,   541,   552, -1348,   589, -1348, -1348, -1348,
   -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348,
   -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348,
   -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348,
   -1348, -1348, -1348,   563, -1348, -1348, -1348, -1348, -1348, -1348,
   -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348,
   -1348, -1348, -1348, -1348, -1348, -1348, -1348,  4494,   713, -1348,
    4784, -1348, -1348,   378, -1348,   378,  5074,   535,   537, -1348,
   -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348,
   -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348,
   -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348,
     -29, -1348, -1348, -1348, -1348,   360, 10502, -1348, -1348, -1348,
   -1348, -1348,   567,   635, -1348,   748,   469,   276,   299,   373,
     402, -1348,   656,   538,   638,   639,  5364, -1348, -1348, -1348,
     218, -1348, -1348,  6524, -1348,   452, -1348,   591,  6814, -1348,
     591,  6814, -1348, -1348, -1348, -1348,   591, -1348, -1348, -1348,
   -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348,
   -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348,
   -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348,
   -1348, -1348, -1348, -1348, -1348,   587, -1348, -1348, 10502,   702,
     703,   548,   548,   702, 10502,   226,   219,   718,   322,   363,
   10502,   598,   630,   308,  7962, -1348, -1348,   418,    66, 10502,
   -1348, -1348, -1348, -1348, 10502, -1348, -1348, -1348, -1348,   259,
   -1348,   449,   346,   387, -1348, -1348,  7962, 10502,  5074,   600,
     601,  5074, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348,
   -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348,
   -1348, -1348, -1348,  5074,  9092, -1348, -1348, -1348, -1348, -1348,
   -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348,
   -1348, -1348,   602,  5074,  5074,   571,  5074,   572,  5074,    68,
      59,    83, -1348,  5074,  7676,   606, -1348, 10502, 10502, 10502,
    5074,   481,   482, -1348,   642,   646, 10502,    24,  5074,  9374,
     615,   613,   614,   616,   617,   618, -1348, -1348, -1348, 10502,
   -1348,   585,   737,  5074,    33, -1348,   750,   592, -1348,  5074,
     566, -1348,   749,  5074,  5074,   596,  5074,  5074,  5074,  5074,
     553, 10502, -1348, -1348,  5074, -1348, -1348,  5074,  5074, 10502,
    7962, -1348, -1348, -1348, -1348, -1348,  1035,    -5, -1348, -1348,
   -1348,   378,   747,  5074, -1348,  5074,   619,   413,   338,   489,
     664,   620,   621,  5074,  5074, -1348, -1348, -1348, -1348, -1348,
   -1348, -1348,   676, -1348,   -24,  5654,  5654,  5654, -1348,  5654,
    5654, -1348,  5654, -1348,  5654, -1348, -1348, -1348, -1348, -1348,
   -1348, -1348,  5654,  5654,     2,  5654,  5654,  5654,  5654,  5654,
    5654,  5654,  5654,  5654,  5654,  5654,   556,   692,   695,   696,
   -1348, -1348, -1348,  2174, -1348, -1348,  6524,  6524,  5074,   591,
   -1348, -1348,   591, -1348,   591,  2464,   640, -1348, 10502, -1348,
   -1348, -1348, -1348,   763, -1348, -1348, -1348, -1348, -1348, -1348,
     685,   687, -1348, -1348,   576,   355, 10502,   468,   641,   647,
     576,   718,   670,   666, -1348, -1348, -1348,   381,    23,   383,
     769, -1348, -1348,   281, -1348, -1348, -1348, -1348, -1348, -1348,
   -1348, -1348,   -11,   508, 10502, -1348,   504, -1348, -1348,   677,
     658, -1348,   626,  5074,  5074,   627,   629, -1348,   -27,   -16,
    2754,   631,   633, -1348,   643, -1348,   637,  7962,   725,   784,
    7962,   718,   728,  7962,   729,   648,   644, -1348,   650,  3044,
      44, -1348,    -1,   689,   723, -1348,   -15,   654, -1348, -1348,
   10502,   -19, -1348,   652,   613,   405, -1348,   653,   657,   659,
   -1348,    19,    75,  3334,    72, -1348, 10502,   737, -1348,   -44,
     661, -1348, -1348, -1348, -1348,   662, -1348,     5, -1348, -1348,
   -1348,   119,   123,   743,   611,   624,    71, -1348,   708,  5944,
   -1348,   669,   673,    77, -1348, -1348,   719,   667, -1348,    -4,
   -1348, -1348,   -18,   688, 10502,  5074,   738, -1348, -1348,   739,
    9938,   740,  5074,   741,   -52,   716,   -50,   635, -1348, -1348,
   -1348, -1348, -1348,  5654, -1348, -1348, -1348,  5074,     2,   330,
   -1348,   586,   263,   604,   605, -1348, -1348,   599,   262,   299,
     299,   307,   373,   373,   373,   373,   402,   402, -1348, -1348,
    9938,  9938, 10502, 10502, -1348,   686, -1348, -1348,   690, -1348,
   -1348, -1348,    84,   -30,   385,   640, -1348,   342,   372, -1348,
   -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348,   576,
   -1348,   742, 10220,   730,  5074, -1348, -1348, -1348,   775,   733,
    5074,   718,   718,   576, -1348,   560,   718, -1348, -1348,   595,
   -1348, -1348,   608,   282, -1348, -1348, -1348, -1348, -1348, -1348,
     610, -1348, -1348,    90,   386,   782,  5074,    74, 10502,   718,
    5074, -1348,   699,   700,   781,   732, 10502, -1348, 10502, -1348,
   -1348,   711, -1348, -1348, -1348,   698,   764,   718,   736,   765,
     801,   718,   768,   718,   751, -1348, -1348, -1348,   724,   787,
    5074,  5074,   755,  5074,   788,  5074,   770,   -69, -1348,    41,
     655, -1348, -1348,   403,   -19, -1348, -1348, -1348,   758, 10502,
   -1348, 10502, -1348, -1348,   731,  5074,   877, -1348,   -10, -1348,
      36, -1348, -1348,   885, -1348,   438,  5074,  5074,  5074,   441,
    5074,  5074,  5074,  5074,  5074,  5074,   796,  5074,  5074,   630,
     -12,   735,   498,   674,   766,   803,   718,   747,   840, -1348,
    5074, -1348,   348,   815, -1348, 10502,   817, -1348, 10502,   773,
     774, -1348,   287, -1348, -1348, -1348, 10502, -1348, 10502,  5074,
     786,  5074,  5074,   -17,   789, -1348,   745,   752, -1348,   679,
   -1348,   -77, -1348,   351,    17,   681,     2,   351,  5654,  5654,
     461, -1348, -1348, -1348, -1348, -1348, -1348, -1348,     2,   795,
      17, -1348,   651,   873, -1348, -1348, -1348, -1348, -1348,   790,
   -1348, -1348, -1348,  5074, -1348, 10502,   847,   191, -1348, -1348,
    5074, -1348,   398, -1348, -1348, -1348, -1348, -1348,   914,   484,
   -1348, -1348, -1348,  5074, -1348, -1348, -1348, -1348, -1348, -1348,
     663,   195,   916, -1348,   409, -1348, -1348,   614,   616,   617,
     421,   618,   458, -1348, -1348, -1348,    90,   778,    90,   859,
    -125,   767,   776, -1348, -1348,  9656,   467, -1348,  3624,   777,
     779,   813,   780,   783, -1348,  5074,   718,   851, -1348, -1348,
   -1348,   718,   851,   718,   851,  3914, -1348, 10502, -1348, -1348,
    5074, -1348, 10502, -1348,  5074,  5074,   819,  5074,   821, -1348,
     843,   850,  5074, 10502,   622,   900, -1348, -1348, -1348,  4204,
     791,   793, -1348, -1348, -1348,   841, -1348,    39, -1348, -1348,
     958, -1348, -1348,  5074, 10502, -1348, -1348,   116, -1348, -1348,
   -1348,   792,   753,   754, -1348, -1348, -1348,   757,   760, -1348,
   -1348, -1348, -1348, -1348,   744, 10502,   798, -1348,   833, -1348,
     630, -1348, -1348, -1348,  7104,   674, -1348,  5074, 10502,   794,
     815, -1348,   718, -1348,   564, -1348,    48,   876, -1348,  5074,
     879,   738, -1348,   805,   808, -1348, -1348, -1348, -1348, -1348,
   -1348, -1348,  5074, -1348, -1348,  5074,   848,  5074, -1348, -1348,
    5654, -1348, -1348, -1348, -1348, -1348,   255,  5654,  5654,   284,
   -1348,   604, -1348, -1348,   -92,  5654, -1348, -1348,   605,     2,
     720, -1348, -1348, -1348, -1348,   775,  9938,   878,   901,   814,
   -1348, -1348, -1348, -1348, -1348,   213,   969,   970,   213,   -14,
     207,   215, -1348,   846, -1348,    90,    91,   697, -1348, -1348,
   10502,   820,   -32, -1348, -1348,   824, -1348, -1348, -1348, -1348,
   -1348,   881,   905,   718,   851,   912, -1348,   830, -1348, -1348,
   -1348, -1348, -1348,  5074, -1348,  5074, 10502, 10502, -1348,   427,
   -1348,  5074, -1348,   832, -1348, -1348,   877, 10502,   206, -1348,
     834,   877, 10502, -1348, -1348,  5074,  5074,  5074,  5074,  5074,
   -1348,  5074,  5074, -1348, -1348,   239, -1348,   835, -1348, -1348,
   -1348, -1348, -1348,   876, -1348, -1348, -1348,   718, -1348, -1348,
   -1348, -1348, -1348, -1348,  5074, -1348,   373,  5654,  5654,   373,
     392, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348,
   -1348, -1348,  9938, -1348,   195,   195,   213, -1348, -1348, -1348,
      29,   213,   985,   756,   920, -1348,   920, -1348,  5074,   225,
   -1348,   899, 10502,   761,   927,  5074, 10502,  5074, -1348,  5074,
     718, -1348,   718, -1348, -1348, -1348,   955, -1348, -1348, -1348,
   -1348,    -8,   877, 10502, -1348,   836,   877, -1348, -1348, -1348,
   -1348, -1348, -1348, -1348,   907,  7104, -1348, -1348, -1348, -1348,
   -1348,   373,   373,  5654, -1348, -1348, -1348, -1348, -1348, -1348,
      17, -1348,   229, -1348,   237, -1348,   459,  5074,    61, 10502,
     -71,   746,  9938, -1348,   844, -1348, -1348,   851,   851,   910,
     129,   249, -1348,   839,   877, -1348,   842, 10502, -1348,   373,
     771,   920, -1348, -1348, -1348,   348, -1348,   399,   399,   -96,
     762, -1348, -1348, -1348, -1348, -1348,   809, 10502,   811, 10502,
     854,  5074, 10502, -1348, -1348,   930,   187, -1348, -1348, -1348,
   -1348,   860,   315, -1348, -1348, -1348,   845, -1348,   238, -1348,
   -1348, -1348, -1348, -1348, -1348,   -96,   785,   759,   922,   823,
    5074, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348,
     937,   913, -1348,    90,  6234, 10502,   944, -1348, 10502, -1348,
     797,   799, -1348,   802, 10502,   258,  5074,   923,  5074,   804,
     947,   913, -1348,  5074, -1348,   931, 10502, -1348,   884,  5074,
     890, -1348,   892,   913,   888, -1348,   807, 10502,   864,   974,
   10502,   810,   940,  5074,   911, -1348
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   419,   420,   601,   566,   704,   713,   692,   616,   608,
     624,   615,   606,   714,   753,   752,   754,   755,   751,   610,
     711,   612,   639,   674,   668,   709,   636,   712,   769,   663,
     705,   767,   653,   654,   655,   656,   657,   658,   659,   660,
     661,   706,   620,   614,   607,   708,   683,   613,   618,   776,
     777,   778,   779,   780,   781,   782,   783,   784,   785,   786,
     410,   413,   682,   678,   669,   649,   605,   400,     0,   677,
     685,   693,   398,   673,   436,   650,   651,   707,   399,   402,
     670,   687,     0,   442,   408,   438,   680,   604,   671,   672,
     700,   675,   691,   699,   404,   403,   623,   662,   702,   437,
     690,   695,   609,     0,     0,   357,   688,   698,   703,   701,
     681,   756,   667,   665,   666,   409,     0,   356,     0,   412,
     411,   696,   652,   676,     0,   401,   386,     0,   418,   697,
     679,   686,   694,   689,   757,   643,   648,   647,   646,   645,
     644,   617,   664,     0,   603,   710,   637,   743,   742,   744,
     622,   621,   640,   749,   611,   741,   746,   747,   738,   642,
     684,   740,   750,   748,   739,   641,   745,   758,   759,   760,
     763,   761,   764,   762,   765,   766,   768,   730,   729,   626,
     619,   628,   627,   723,   719,   634,   638,   635,   732,   733,
     716,   625,   728,   727,   724,   720,   737,   731,   726,   722,
     715,   736,   735,   721,   725,   717,   718,   629,   630,   632,
     734,   631,   633,   788,   787,   789,   790,   791,   792,   771,
     772,   770,   774,   775,   773,   793,   794,   795,   796,   797,
     798,   799,   800,   801,   802,   803,   804,     0,     0,     2,
       0,     4,     6,    14,     8,    17,     0,     0,     0,    23,
      25,    39,    27,    28,    29,    55,    30,    34,    35,    59,
      60,    61,    56,    57,    63,    64,    32,    31,    36,    37,
      38,    58,   216,   215,   212,   213,   214,    33,    13,   193,
     194,   198,   200,   231,   237,     0,     0,   229,   230,   201,
     202,   203,   204,   313,   315,   317,   327,   330,   332,   335,
     340,   343,   346,   348,   350,   352,     0,   354,   360,   362,
       0,   378,   361,   382,   385,   387,   390,   392,     0,   397,
     394,     0,   405,   415,   417,   391,   421,   426,   434,   427,
     428,   429,   432,   433,   430,   431,   449,   451,   452,   453,
     450,   498,   499,   500,   501,   502,   503,   414,   540,   532,
     539,   538,   537,   534,   536,   533,   535,   435,    62,   205,
     206,   208,   207,   209,   210,   416,   602,   211,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   124,   125,     0,     0,     0,
     120,   121,   122,   123,     0,   152,   153,   156,   155,     0,
     118,     0,   154,   151,   176,   179,     0,     0,     0,     0,
       0,     0,   704,   713,   692,   616,   608,   624,   615,   606,
     610,   711,   612,   674,   769,   663,   767,   653,   654,   614,
     607,   605,   675,     0,     0,   756,   757,   603,   749,   611,
     741,   747,   738,   641,   759,   760,   763,   764,   762,   765,
     768,   788,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   599,     0,     0,     0,   600,     0,     0,     0,
       0,     0,     0,   239,     0,     0,     0,     0,     0,     0,
       0,   608,   615,   606,   612,   605,   406,   416,   439,     0,
     440,     0,   465,     0,     0,   381,     0,     0,   384,     0,
       0,   494,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   166,   163,     0,   174,   175,     0,     0,     0,
       0,     3,     1,     5,     7,     9,   151,     0,    15,    18,
      12,    20,    21,     0,   196,   195,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   217,   236,   232,   238,   233,
     235,   234,   241,   242,     0,     0,     0,     0,   371,     0,
       0,   369,     0,   322,     0,   370,   363,   368,   367,   366,
     365,   364,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     359,   358,   355,     0,   379,   383,     0,     0,     0,   393,
     423,   396,   395,   407,   422,     0,     0,   181,     0,   182,
     178,   177,   180,     0,   157,   158,    72,    73,   598,    81,
       0,     0,    66,    67,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   567,   568,   569,     0,     0,     0,
       0,   843,   844,     0,    71,   836,   837,   838,   839,   840,
     841,   842,   110,     0,     0,   119,     0,   149,   150,     0,
       0,   564,     0,     0,     0,     0,     0,   556,     0,     0,
       0,     0,     0,   545,     0,   546,     0,     0,    90,     0,
       0,     0,    82,     0,    94,     0,     0,   547,     0,     0,
       0,   302,     0,     0,   254,   255,     0,     0,   219,   220,
       0,     0,   240,     0,     0,     0,   542,     0,     0,     0,
     550,     0,     0,     0,     0,   441,   466,   465,   462,     0,
       0,   496,   495,   380,   555,     0,   493,     0,   580,   581,
     541,     0,     0,     0,     0,     0,     0,   586,     0,     0,
     172,     0,     0,     0,   257,   274,     0,     0,    24,   151,
      26,   199,     0,     0,     0,     0,     0,   218,   275,     0,
       0,     0,     0,     0,     0,     0,     0,   314,   316,   320,
     326,   325,   324,     0,   321,   318,   319,     0,     0,     0,
     828,   328,   807,   815,   817,   819,   821,   823,   826,   334,
     333,   331,   337,   338,   339,   336,   341,   342,   345,   344,
       0,     0,     0,     0,   376,     0,   388,   389,     0,   424,
     445,   447,     0,     0,     0,     0,    70,     0,     0,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    41,
      42,     0,     0,   102,     0,    98,   100,   101,   105,   108,
       0,     0,     0,    40,    80,     0,     0,   845,   846,     0,
     847,   851,     0,     0,   880,   849,   850,   879,   848,   852,
       0,   859,   881,     0,     0,   111,     0,   114,     0,     0,
       0,   372,     0,     0,     0,     0,     0,   560,     0,   557,
     505,     0,   504,   513,   514,     0,     0,     0,     0,     0,
      83,     0,     0,     0,     0,   549,   548,   515,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   806,     0,
       0,   221,   222,     0,   227,   563,   543,   544,     0,     0,
     553,     0,   551,   509,     0,     0,   465,   463,     0,   454,
       0,   443,   444,     0,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   704,
       0,     0,     0,     0,     0,     0,     0,    22,     0,   197,
       0,   228,   286,   282,   284,     0,   276,   277,     0,   609,
     617,   521,   522,   528,   529,   531,     0,   244,     0,     0,
       0,     0,     0,     0,     0,   323,     0,     0,   822,     0,
     329,     0,   835,     0,     0,     0,     0,     0,     0,     0,
     808,   812,   830,   811,   834,   832,   831,   833,     0,     0,
       0,   824,   887,   885,   889,   827,   347,   349,   351,   519,
     353,   377,   425,     0,   446,     0,   159,     0,   187,   184,
       0,   183,     0,    78,    79,    76,    77,    43,     0,     0,
     103,   104,   106,     0,   107,    68,    69,    74,    75,    65,
       0,     0,     0,   854,     0,   853,   870,     0,     0,     0,
       0,     0,     0,   112,   127,   126,     0,     0,     0,   115,
       0,     0,     0,   374,   373,     0,     0,   308,     0,     0,
       0,   564,     0,     0,   506,     0,     0,    92,    86,    89,
      88,     0,    84,     0,    96,     0,   516,     0,   300,   304,
       0,   171,     0,   259,     0,     0,     0,     0,     0,   223,
       0,     0,     0,     0,   268,     0,   265,   270,   226,     0,
       0,     0,   510,   301,   466,     0,   455,     0,   489,   486,
       0,   490,   491,     0,     0,   492,   485,     0,   460,   488,
     487,     0,     0,     0,   573,   574,   570,     0,     0,   578,
     579,   575,   584,   582,     0,     0,     0,   588,   169,   168,
       0,   165,   164,   173,     0,   589,   590,     0,     0,     0,
     283,   295,     0,   296,     0,   287,   288,   289,   290,     0,
     279,     0,   243,     0,     0,   525,   527,   526,   523,   252,
     253,   246,     0,   248,   245,     0,     0,     0,   829,   825,
       0,   882,   883,   903,   902,   898,     0,     0,     0,     0,
     884,   816,   897,   809,     0,     0,   814,   813,   818,     0,
       0,   888,   886,   520,   448,   189,     0,     0,   160,     0,
     186,   185,    44,    99,   109,   868,     0,     0,   866,   862,
       0,     0,   113,     0,   116,     0,     0,     0,    16,   375,
       0,     0,     0,   309,   507,     0,   561,   562,   565,   558,
     559,     0,    91,     0,    85,    95,   517,     0,   303,   305,
     256,   261,   260,     0,   263,     0,     0,     0,   225,   266,
     269,     0,   511,     0,   554,   552,   465,     0,     0,   497,
       0,   465,     0,   461,    11,     0,     0,     0,     0,     0,
     587,     0,     0,   167,   596,     0,   591,     0,   258,    19,
     299,   297,   298,   291,   292,   293,   285,     0,   280,   278,
     530,   524,   250,   247,     0,   249,   904,     0,     0,   890,
       0,   901,   900,   899,   894,   895,   810,   820,   896,   190,
     161,   188,     0,   192,     0,     0,   869,   871,   873,   875,
       0,   867,     0,     0,     0,   857,     0,   855,     0,     0,
     117,     0,     0,     0,     0,     0,     0,     0,   508,     0,
       0,    87,     0,   518,   262,   264,   273,   272,   267,   224,
     512,     0,   465,     0,   191,     0,   465,   571,   572,   576,
     577,   583,   585,   170,     0,     0,   592,   805,   294,   281,
     251,   892,   891,     0,   162,   878,   877,   872,   876,   874,
     863,   864,     0,   860,     0,   138,   140,     0,   135,     0,
       0,     0,     0,   310,     0,   306,   312,    93,    97,     0,
     475,   469,   464,     0,   465,   456,     0,     0,   597,   893,
       0,     0,   858,   856,   141,   142,   139,   135,   135,   135,
       0,   136,   137,   128,   129,   132,     0,     0,     0,     0,
       0,     0,     0,   483,   477,     0,   476,   478,   484,   481,
     471,     0,   470,   472,   482,   458,     0,   457,     0,   865,
     861,   143,   133,   134,   130,   135,     0,     0,     0,     0,
       0,   307,   271,   468,   479,   480,   467,   473,   474,   459,
       0,     0,   131,     0,     0,     0,     0,   311,     0,   593,
       0,   771,   144,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   147,     0,   146,     0,     0,   594,     0,     0,
       0,   145,     0,     0,     0,   595,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   148
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1348, -1348,   852, -1348,   855,   857, -1348,   861, -1348,   420,
   -1348,   559,   561,  -514, -1348,   470,  -268, -1348, -1348, -1348,
   -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348, -1348,
   -1348,  -867, -1348, -1348, -1348, -1348,    69,   274,   734, -1348,
   -1348, -1348,   712,   243, -1348, -1348, -1347,  -758, -1348,  -305,
   -1348, -1348,   710,   715, -1348,   300, -1348,  -844, -1348, -1348,
     -46, -1348, -1348, -1348, -1348, -1348,   321,   196, -1348, -1348,
    -109, -1348, -1278,   874,  -100, -1348,   584,    98, -1348, -1348,
   -1348, -1348,   208, -1348, -1348,   838, -1348, -1348, -1348, -1348,
   -1348,   156,  -517,  -668, -1348, -1348, -1348,    25, -1348, -1348,
    -153,    14,   -38, -1348, -1348, -1348,   -49, -1348, -1348,   169,
     -48, -1277, -1348,   -43, -1111, -1348,   645,    38, -1348, -1348,
      60, -1348, -1348,   582,   588, -1348,  -504,  -962,   565,   120,
    -573,   115,   124, -1348, -1348, -1348, -1348, -1348,   837, -1348,
   -1348, -1348, -1348, -1348,   853, -1348, -1348,  -113, -1348, -1348,
   -1348, -1348, -1348, -1348, -1348,   -39, -1139, -1348, -1348,   265,
      -6, -1348,  -572, -1348, -1348, -1348, -1348, -1348, -1348, -1348,
   -1348, -1348,  -911, -1348,    18, -1348,   431,  -713, -1348, -1348,
   -1348, -1348, -1348,  -325,  -317, -1091,  -978, -1348, -1348, -1348,
   -1348, -1348, -1348, -1348, -1348, -1348, -1348,   347,  -681,  -784,
   -1348,   319,  -102,  -750, -1348, -1348, -1348, -1348, -1348, -1348,
   -1348,   675,   680,  -490,   275,   118, -1348, -1348, -1348, -1348,
   -1348, -1348, -1348,     3, -1348, -1348,    -3, -1348,  -368,  -103,
      -9, -1348, -1348,   376, -1348, -1348,   164,   153,   -55,   388,
   -1348, -1348,   165, -1348,  -759, -1348, -1348, -1348, -1348,  -190,
    -833, -1348,   -70,  -634, -1348,  -727, -1348, -1348, -1348, -1348,
   -1009, -1348, -1348, -1348, -1348,   -45,   173, -1348
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   829,   830,   831,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,  1087,   681,   265,   266,   835,   836,   837,  1158,   267,
     268,   399,   400,   865,   269,  1453,  1454,  1455,  1359,  1415,
     270,   401,   402,   403,   271,   814,   272,   513,   739,   950,
    1159,   273,   274,   275,   276,   277,   404,   405,   609,  1027,
    1028,  1135,  1031,   278,   279,   535,   280,   281,   282,   545,
     474,   913,   914,   283,   546,   284,   548,   285,   286,   287,
     552,   553,  1114,   765,   288,   694,   743,   695,   701,  1115,
    1116,  1117,   744,   549,   550,   966,   967,  1318,   551,   963,
     964,  1175,  1176,  1177,  1178,   289,   690,   691,   290,  1076,
    1077,   291,   292,   293,   294,   773,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   572,
     573,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   599,
     600,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     812,   335,   336,   337,  1137,   717,   718,   719,  1432,  1471,
    1472,  1465,  1466,  1473,  1467,  1138,  1139,   338,   339,  1140,
     340,   341,   342,   343,   344,   345,   346,  1018,   766,   971,
    1188,   972,   973,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   660,  1080,   357,   358,   359,   360,   361,
     362,   363,   736,   737,   364,  1165,  1166,  1305,  1088,   465,
     365,   366,   367,   781,  1000,   782,   783,   784,   785,   786,
     787,   788,  1001,  1002,   644,   645,   646,   647,   648,  1412,
    1413,   649,  1346,  1238,  1350,  1347,   650,   651,  1004,  1015,
    1209,  1005,  1006,  1011,  1007,  1334,  1205,   990
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int xquery_parser::yytable_ninf_ = -152;
  const short int
  xquery_parser::yytable_[] =
  {
       452,  1220,   780,   491,   928,   792,   793,   794,   795,   619,
     974,   902,   466,   494,   498,   907,  1016,  1017,   750,  1136,
    1055,   459,     4,  1003,  1092,  1304,  1094,  1396,   906,   486,
     368,   369,   370,   371,   372,   373,  1213,   764,   761,  1457,
     721,   910,   374,   460,  1128,  1129,  1293,  1128,  1129,  1408,
     974,   974,   500,   769,   704,   770,   771,   480,   772,   487,
     774,  1447,   760,  1105,   761,  1314,  1315,   380,   775,   776,
     533,   760,   876,   488,  1206,   863,   929,  1430,  1366,   618,
    1025,   533,   974,   878,   979,   760,   982,  1160,   618,   705,
     406,   678,   682,   684,  1448,   492,   980,   582,   984,   381,
     382,   958,  1484,   618,    74,  1206,   583,   466,  1163,   496,
    1126,   454,   762,  1063,   455,   497,    85,   905,   919,  1195,
     704,   453,  1057,  1058,  1128,  1129,   933,   760,   849,  1201,
     954,  1130,  1059,  1463,  1130,   901,   407,  1128,  1502,  1444,
      99,   930,  1367,   899,   777,  1026,  1172,   778,   877,  1131,
     534,  1132,  1131,   385,  1132,   705,  1060,  1042,   637,   879,
    1068,   959,  1246,  1431,   679,  1174,  1331,  1161,  1481,  1202,
     946,   899,  1332,  1247,   921,  1127,   955,  1107,  1133,  1061,
    1333,  1133,   104,  1023,   934,   104,   386,   911,  1231,  1451,
    1452,  1463,   408,   763,   920,  1128,   722,  1293,   116,   706,
     595,   116,  1398,   864,  1409,   935,   780,   780,   680,   939,
     763,  1130,   763,  1125,  1128,  1129,  1136,   677,  1447,  1134,
     900,  1241,  1287,  1509,  1264,  1458,  1136,   912,  1108,  1131,
    1353,  1132,   683,   501,  1207,  1208,   388,   143,   763,  1106,
     143,  1217,  1131,  1527,  1132,   763,  1352,   763,   925,   983,
     922,  1448,  1464,  1336,   779,  1535,  1438,  1128,  1133,  1024,
     409,   410,   104,   844,   850,  1207,  1208,   124,  1469,   985,
     461,  1133,   389,   390,   391,   392,   393,   554,   116,   601,
     394,   633,   603,  1236,   395,   396,   397,   398,   864,   411,
    1227,  1251,   638,   851,   852,   947,   853,   854,  1327,  1292,
    1131,  1130,  1132,   659,  1062,  1361,  1354,   639,   662,   487,
    1494,   665,   487,   890,  1356,  1196,  1242,   143,  1244,  1131,
     640,  1132,   641,  1128,  1417,   974,   936,   937,  1441,  1133,
     940,   941,   642,   666,  1469,   643,  1441,  1500,   628,  1344,
    1237,   938,   629,  1449,  1450,   942,  1451,  1452,  1133,   458,
       4,   991,   104,   671,   672,   637,   674,  1520,   676,   606,
     593,   688,  1131,   685,  1132,   613,  1228,  1362,   116,   456,
    1052,   624,   457,  1470,  1328,   466,   616,  1136,   709,   630,
     652,  1030,  1355,   118,  1394,   653,  1079,  1053,  1082,  1383,
    1357,  1133,   470,   720,   471,   472,   614,   466,   661,   725,
    1418,  1440,  1345,   526,  1442,   536,   631,   143,   578,   617,
     615,   537,  1443,  1501,   538,   539,   385,   746,   742,   527,
     992,  1185,   540,   575,   780,   669,  1214,  1054,  1131,  1120,
    1132,  1121,    74,  1521,   579,  1171,   780,  1395,   467,  1497,
     576,   832,  1340,   750,    85,   509,  1172,   580,   473,   386,
     510,  1186,  1468,  1474,   575,   466,  1173,  1133,   692,   693,
     696,  1110,  1111,   577,  1112,  1174,   632,   703,    99,  1187,
     712,   576,   777,  1045,  1046,   778,   974,   620,  1049,  1033,
     692,   581,   833,   806,   807,  1110,  1111,   834,  1468,   638,
     468,   761,   621,   805,  1474,  1360,  1034,  1052,   808,  1012,
    1013,  1071,   738,  1427,   639,  1428,   993,   994,   995,  1035,
     745,   466,  1029,  1113,  1240,   761,   996,   640,   541,   641,
     542,  1014,   858,   469,   997,  1230,  1036,  1030,   584,   642,
     998,   999,   643,   622,   543,   654,   390,   391,   392,   393,
     512,   585,  1331,   475,  1339,   760,  1171,   623,  1332,   991,
     476,   859,   860,   637,   861,   862,  1333,  1172,  1404,  1075,
     544,  1037,   582,   872,   873,   607,   477,  1173,   697,   612,
     881,   583,  1252,  1381,   886,  1037,  1174,   889,  1385,  1403,
     892,   582,   368,   369,   370,   602,   489,   373,  1169,   898,
     583,   604,   974,   809,   502,   839,   809,   493,   809,   815,
     840,   728,   729,   505,   731,   732,   733,   734,  1480,  1203,
     508,   833,   740,   924,  1204,   741,   834,   838,   992,  1407,
     847,   499,   855,   848,  1407,   856,   511,  1326,   634,   635,
     636,   751,   596,   597,  1329,  1330,   397,   398,  1460,   951,
     512,   757,   758,   514,   503,   867,   504,   780,   819,   820,
     821,   822,   823,   824,   825,   826,   827,   828,   506,  1142,
     507,  1143,  1147,   528,  1148,   529,  1064,  1065,   466,  1433,
     515,   466,   974,  1436,   466,   395,   396,   986,  1047,  1048,
    1110,  1111,  1311,  1312,  1451,  1452,   517,   638,   516,  1482,
    1483,   909,   610,   611,   518,   789,   790,   796,   797,   519,
    1019,  1019,   639,   811,   993,   994,   995,   926,   798,   799,
    1405,  1406,   520,   522,   531,   640,   532,   641,  1262,   556,
     574,  1476,   997,   555,   586,  1265,   587,   642,  1215,   999,
     643,   588,   605,   589,   598,  1445,   368,   608,   618,   625,
     626,   656,   663,   664,   670,   961,   673,   675,   689,   698,
     699,   975,   700,  1510,  1401,  1402,   702,   713,   434,   455,
     715,   457,   464,   479,   716,   723,  1067,   724,   726,   727,
    1072,   730,   749,   735,   754,   759,   800,   753,   801,   755,
     756,   802,   803,   816,   817,   813,   818,   845,   846,   857,
     841,   975,   975,   975,   975,   866,   842,   868,   871,   869,
     870,   875,   874,   882,  1310,   883,   368,   369,   370,   371,
     372,   373,   885,   887,   888,   884,   891,   893,   374,   895,
     894,   903,   904,   975,   375,   896,   908,   915,   916,   943,
    1439,   918,   917,   931,   932,   376,   377,   944,   945,   378,
     948,   956,   379,   380,   952,   953,   957,   960,   965,   968,
     976,   978,   981,   962,  1008,   989,  1010,  1009,  1021,  1070,
     977,   760,   834,  1022,  1038,  1043,  1050,  1081,  1066,  1081,
     557,  1073,  1074,  1075,  1078,   381,   382,   383,   558,   559,
    1051,   560,  1056,  1084,  1085,  1089,  1086,  1090,   561,  1091,
    1093,  1100,   562,  1095,   563,  1371,  1096,  1097,  1102,   564,
    1119,  1109,  1104,  1122,  1124,  1141,  1155,  1162,  1167,  1164,
     661,   630,   661,  1168,  1179,   565,  1181,  1198,  1183,  1184,
    1222,   384,  1192,  1221,  1223,  1197,  1200,  1199,  1210,   385,
    1229,  1219,  1041,  1226,     4,  1235,  1239,  1243,  1044,   566,
     567,   568,   569,   570,   571,  1245,  1248,  1258,  1249,  1399,
    1263,  1273,  1256,  1276,  1257,  1259,  1180,  1275,  1260,   554,
    1277,  1281,   386,  1286,  1289,  1302,  1284,  1189,  1285,  1190,
    1299,  1294,  1301,  1309,  1172,  1295,  1296,  1317,  1255,  1297,
    1320,   387,  1298,  1321,  1324,  1338,  1343,  1342,  1025,  1348,
    1349,  1358,  1363,  1370,  1365,  1267,  1368,  1369,  1098,  1099,
    1372,  1101,  1373,  1103,  1380,  1410,  1384,  1397,  1052,  1419,
    1421,  1411,   388,  1422,  1429,  1493,  1225,  1437,  1461,  1283,
    1462,  1435,  1459,  1123,  1475,  1488,  1479,  1477,  1490,  1486,
    1499,  1496,  1505,  1290,  1144,  1145,  1146,  1506,  1149,  1150,
    1151,  1152,  1153,  1154,  1485,  1156,  1157,  1508,   389,   390,
     391,   392,   393,  1504,  1514,  1030,   394,  1526,   962,  1531,
     395,   396,   397,   398,  -151,  1533,   975,  1534,  1523,   368,
     369,   370,   371,   372,   373,  1536,  1529,  1191,  1539,  1193,
    1194,   374,  1503,  1537,  1540,  1543,  1545,   375,   692,   521,
     747,  1516,   748,   696,  1517,   523,  1518,   524,   376,   377,
     843,   525,   378,  1525,  1279,   379,   380,  1040,  1233,  1542,
    1069,   655,  1446,   658,  1303,  1032,   627,   657,  1341,   752,
     530,  1224,  1118,   547,  1182,  1291,  1378,  1270,  1280,  1170,
    1308,  1316,  1319,  1313,   714,  1268,  1253,   767,   381,   382,
     383,  1234,   791,   592,   768,  1288,   738,  1498,   927,  1495,
    1020,  1039,   707,  1083,   987,   487,  1232,   708,  1300,   745,
    1211,  1218,  1306,   594,  1337,  1216,  1414,   988,  1351,  1335,
    1212,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1261,   384,     0,     0,     0,     0,     0,
       0,     0,   385,     0,     0,     0,     0,     0,  1269,     0,
       0,     0,  1271,  1272,     0,  1274,     0,     0,     0,     0,
    1278,     0,     0,     0,     0,     0,     0,   975,     0,     0,
       0,     0,     0,     0,     0,   386,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1364,     0,     0,   387,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1307,     0,  1376,  1377,     0,
       0,     0,     0,     0,     0,   388,     0,   962,  1382,     0,
       0,     0,     0,  1386,     0,     0,     0,     0,     0,     0,
    1322,     0,     0,  1323,     0,  1325,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   389,   390,   391,   392,   393,     0,     0,     0,   394,
       0,     0,     0,   395,   396,   397,   398,     0,     0,     0,
       0,     0,     0,   975,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1420,     0,     0,     0,  1424,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1374,     0,  1375,  1434,     0,     0,     0,     0,  1379,
       0,     0,     0,     0,     0,     0,   487,     0,     0,     0,
       0,     0,     0,  1387,  1388,  1389,  1390,  1391,     0,  1392,
    1393,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1456,     0,     0,   975,     0,     0,     0,     0,     0,     0,
       0,     0,  1400,  1528,     0,     0,     0,     0,  1478,  1532,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1544,     0,     0,     0,     0,  1487,     0,
    1489,     0,     0,  1492,     0,     0,  1416,     0,     0,     0,
       0,     0,     0,  1423,     0,  1425,     0,  1426,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1513,     0,     0,  1515,
       0,     0,     0,     0,     0,  1519,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1416,     0,  1530,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1538,     0,
       0,  1541,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1491,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1507,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1512,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,  1522,     0,  1524,     0,     5,     6,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
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
       0,     0,   141,   142,   143,     0,   144,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,     0,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,   412,
     413,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,   421,    21,    22,    23,    24,
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
       0,     0,   119,   120,   121,     0,     0,     0,   122,   490,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   437,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   451,
     214,   215,     0,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,   412,
     413,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,   421,    21,    22,    23,    24,
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
       0,     0,   119,   120,   121,     0,   804,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   437,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   451,
     214,   215,     0,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,   412,
     413,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,   421,    21,    22,    23,    24,
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
       0,     0,   119,   120,   121,     0,     0,     0,   122,   810,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   437,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   451,
     214,   215,     0,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,   412,
     413,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,   421,    21,    22,    23,    24,
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
       0,     0,   119,   120,   121,     0,   880,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   437,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   451,
     214,   215,     0,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,   412,
     413,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,   421,    21,    22,    23,    24,
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
       0,     0,   119,   120,   121,     0,   897,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   437,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   451,
     214,   215,     0,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,   412,
     413,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,   421,    21,    22,    23,    24,
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
       0,     0,   119,   120,   121,     0,   923,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   437,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   451,
     214,   215,     0,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,   412,
     413,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,   421,    21,    22,    23,    24,
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
       0,     0,   119,   120,   121,     0,  1254,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   437,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   451,
     214,   215,     0,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,   412,
     413,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,   421,    21,    22,    23,    24,
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
       0,     0,   119,   120,   121,     0,  1266,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   437,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   451,
     214,   215,     0,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,   412,
     413,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,   421,    21,    22,    23,    24,
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
       0,     0,   119,   120,   121,     0,  1282,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   437,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   451,
     214,   215,     0,   216,   217,   218,   219,   220,   221,   222,
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
     140,     0,     0,   141,   142,   143,     0,   144,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,     0,   216,   217,   218,   219,   220,   221,   222,
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
     140,     0,     0,   141,   142,   143,     0,   437,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,     0,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,   412,
     413,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,   421,    21,    22,    23,    24,
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
     140,     0,     0,   141,   142,   143,     0,   437,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   451,
     214,   215,     0,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,   412,
     413,     0,     7,   415,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,   420,   421,    21,    22,   423,    24,
      25,    26,    27,     0,   424,   425,    30,   426,   427,   428,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
       0,    72,    73,     0,     0,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     0,    85,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,   432,
      92,    93,    94,    95,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,   103,
     104,   590,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     0,   591,   118,
       0,     0,   119,   120,   121,     0,     0,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   437,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   438,   154,   440,
     156,   441,   442,   159,   160,   161,   162,   163,   164,   443,
     166,   167,   444,   445,   446,   171,   447,   448,   449,   175,
     450,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   451,
     214,   215,     0,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,   412,
     413,     0,     7,   415,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,   420,   421,    21,    22,   423,    24,
      25,    26,    27,     0,   424,   425,    30,   426,   427,   428,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
       0,    72,    73,     0,     0,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     0,    85,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,   432,
      92,    93,    94,    95,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,   103,
     104,   105,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     0,   117,   118,
       0,     0,   119,   120,   121,     0,     0,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   437,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   438,   154,   440,
     156,   441,   442,   159,   160,   161,   162,   163,   164,   443,
     166,   167,   444,   445,   446,   171,   447,   448,   449,   175,
     450,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   451,
     214,   215,     0,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,   949,
     413,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,   421,    21,    22,    23,    24,
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
     140,     0,     0,   141,   142,   143,     0,   437,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   451,
     214,   215,     0,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,   412,
     413,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,   421,    21,    22,    23,    24,
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
     140,     0,     0,   141,   142,   143,     0,   437,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   451,
     214,   215,     0,   216,   217,   218,  1511,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,   412,
     413,     0,   414,   415,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,   420,   421,    21,    22,   423,    24,
      25,    26,    27,     0,   424,   425,    30,   426,   427,   428,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
       0,    72,    73,     0,     0,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     0,    85,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,   432,
      92,    93,    94,    95,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,   103,
     104,     0,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     0,     0,     0,
       0,     0,   119,   120,   121,     0,     0,     0,   122,     0,
     123,   124,   125,     0,     0,     0,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   437,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   438,   154,   440,
     156,   441,   442,   159,   160,   161,   162,   163,   164,   443,
     166,   167,   444,   445,   446,   171,   447,   448,   449,   175,
     450,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   451,
     214,   215,     0,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     0,     0,     0,     0,     0,   412,
     413,     0,   414,   415,   481,   417,   482,   483,    13,    14,
      15,    16,    17,    18,   420,   421,   484,    22,   423,    24,
      25,    26,    27,     0,   424,   425,    30,   426,   427,   428,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    62,     0,
      63,    64,    65,   485,     0,     0,    69,    70,    71,     0,
       0,     0,    73,     0,     0,     0,     0,    75,    76,    77,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,   432,
      92,    93,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,     0,   100,   101,   102,     0,     0,     0,     0,
       0,     0,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   435,   112,   113,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,   122,     0,
     123,   124,     0,     0,     0,     0,   128,     0,   129,     0,
     130,   131,   132,   133,   436,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,     0,     0,   437,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   438,   154,   440,
     156,   441,   442,   159,   160,   161,   162,   163,   164,   443,
     166,   167,   444,   445,   446,   171,   447,   448,   449,   175,
     450,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   451,
     214,   215,     0,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     0,     0,     0,     0,     0,   412,
     413,     0,   414,   415,   416,   417,   418,   419,    13,    14,
      15,    16,    17,    18,   420,   421,   422,    22,   423,    24,
      25,    26,    27,     0,   424,   425,    30,   426,   427,   428,
      34,    35,    36,    37,    38,    39,    40,    41,    42,   429,
     430,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    62,     0,
      63,    64,    65,   431,     0,     0,    69,    70,    71,     0,
       0,     0,    73,     0,     0,     0,     0,    75,    76,    77,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,   432,
      92,    93,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,     0,   100,   101,   102,     0,     0,     0,     0,
       0,     0,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   435,   112,   113,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,   122,     0,
     123,     0,     0,     0,     0,     0,   128,     0,   129,     0,
     130,   131,   132,   133,   436,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,     0,     0,   437,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   438,   439,   440,
     156,   441,   442,   159,   160,   161,   162,   163,   164,   443,
     166,   167,   444,   445,   446,   171,   447,   448,   449,   175,
     450,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   451,
     214,   215,     0,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   462,     0,     0,     0,     3,     0,
       0,     0,     0,     0,     0,   412,   413,     0,   414,   415,
     416,   417,   418,   419,    13,    14,    15,    16,    17,    18,
     420,   421,   422,    22,   423,    24,    25,    26,    27,     0,
     424,   425,    30,   426,   427,   428,    34,    35,    36,    37,
      38,    39,    40,    41,    42,   429,   430,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    62,     0,    63,    64,    65,   431,
       0,     0,    69,    70,    71,     0,     0,     0,    73,     0,
       0,     0,     0,    75,    76,    77,     0,     0,    80,    81,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,   432,    92,    93,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,     0,   100,
     101,   102,   463,     0,     0,   464,     0,     0,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   435,   112,   113,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,     0,     0,     0,   122,     0,   123,     0,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     436,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,     0,     0,   437,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   438,   439,   440,   156,   441,   442,   159,
     160,   161,   162,   163,   164,   443,   166,   167,   444,   445,
     446,   171,   447,   448,   449,   175,   450,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   451,   214,   215,     0,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     462,     0,     0,     0,     3,     0,   686,     0,     0,     0,
       0,   412,   413,     0,   414,   415,   416,   417,   418,   419,
      13,    14,    15,    16,    17,    18,   420,   421,   422,    22,
     423,    24,    25,    26,    27,     0,   424,   425,    30,   426,
     427,   428,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   429,   430,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   431,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   432,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   102,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   435,   112,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,   687,   123,     0,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   436,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   437,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   438,
     439,   440,   156,   441,   442,   159,   160,   161,   162,   163,
     164,   443,   166,   167,   444,   445,   446,   171,   447,   448,
     449,   175,   450,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   451,   214,   215,     0,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   462,     0,     0,     0,
       3,     0,     0,     0,     0,     0,     0,   412,   413,     0,
     414,   415,   416,   417,   418,   419,    13,    14,    15,    16,
      17,    18,   420,   421,   422,    22,   423,    24,    25,    26,
      27,     0,   424,   425,    30,   426,   427,   428,    34,    35,
      36,    37,    38,    39,    40,    41,    42,   429,   430,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     0,     0,    62,     0,    63,    64,
      65,   431,     0,     0,    69,    70,    71,     0,     0,     0,
      73,     0,     0,     0,     0,    75,    76,    77,     0,     0,
      80,    81,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   432,    92,    93,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
       0,   100,   101,   102,     0,     0,     0,     0,     0,     0,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   435,
     112,   113,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,     0,     0,     0,   122,     0,   123,     0,
       0,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   436,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,     0,     0,   437,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   438,   439,   440,   156,   441,
     442,   159,   160,   161,   162,   163,   164,   443,   166,   167,
     444,   445,   446,   171,   447,   448,   449,   175,   450,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   451,   214,   215,
       0,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   495,     0,     3,     0,     0,     0,     0,     0,
       0,   412,   413,     0,   414,   415,   416,   417,   418,   419,
      13,    14,    15,    16,    17,    18,   420,   421,   422,    22,
     423,    24,    25,    26,    27,     0,   424,   425,    30,   426,
     427,   428,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   429,   430,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   431,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   432,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   102,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   435,   112,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,     0,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   436,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   437,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   438,
     439,   440,   156,   441,   442,   159,   160,   161,   162,   163,
     164,   443,   166,   167,   444,   445,   446,   171,   447,   448,
     449,   175,   450,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   451,   214,   215,     0,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,     3,     0,     0,     0,
       0,     0,     0,   412,   413,     0,   414,   415,   416,   417,
     418,   419,    13,    14,    15,    16,    17,    18,   420,   421,
     422,    22,   423,    24,    25,    26,    27,     0,   424,   425,
      30,   426,   427,   428,    34,    35,    36,    37,    38,    39,
      40,    41,    42,   429,   430,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
       0,     0,    62,     0,    63,    64,    65,   431,     0,     0,
      69,    70,    71,     0,     0,     0,    73,     0,     0,     0,
       0,    75,    76,    77,     0,     0,    80,    81,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,   432,    92,    93,     0,     0,     0,     0,
       0,     0,     0,    96,    97,    98,     0,   100,   101,   102,
     433,     0,     0,   434,     0,     0,   106,   107,     0,     0,
       0,     0,   108,   109,   110,   435,   112,   113,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   121,     0,
       0,     0,   122,     0,   123,     0,     0,     0,     0,     0,
       0,     0,   129,     0,   130,   131,   132,   133,   436,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,     0,
       0,   437,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   438,   439,   440,   156,   441,   442,   159,   160,   161,
     162,   163,   164,   443,   166,   167,   444,   445,   446,   171,
     447,   448,   449,   175,   450,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   451,   214,   215,     0,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,     3,     0,
       0,     0,     0,     0,     0,   412,   413,     0,   414,   415,
     416,   417,   418,   419,    13,    14,    15,    16,    17,    18,
     420,   421,   422,    22,   423,    24,    25,    26,    27,     0,
     424,   425,    30,   426,   427,   428,    34,    35,    36,    37,
      38,    39,    40,    41,    42,   429,   430,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    62,     0,    63,    64,    65,   431,
       0,     0,    69,    70,    71,     0,     0,     0,    73,     0,
       0,     0,     0,    75,    76,    77,     0,     0,    80,    81,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,   432,    92,    93,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,     0,   100,
     101,   102,   478,     0,     0,   479,     0,     0,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   435,   112,   113,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,     0,     0,     0,   122,     0,   123,     0,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     436,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,     0,     0,   437,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   438,   439,   440,   156,   441,   442,   159,
     160,   161,   162,   163,   164,   443,   166,   167,   444,   445,
     446,   171,   447,   448,   449,   175,   450,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   451,   214,   215,     0,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
       3,     0,     0,     0,     0,     0,     0,   412,   413,     0,
     414,   415,   416,   417,   418,   419,    13,    14,    15,    16,
      17,    18,   420,   421,   422,    22,   423,    24,    25,    26,
      27,     0,   424,   425,    30,   426,   427,   428,    34,    35,
      36,    37,    38,    39,    40,    41,    42,   429,   430,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     0,     0,    62,     0,    63,    64,
      65,   431,     0,     0,    69,    70,    71,     0,     0,     0,
      73,     0,     0,     0,     0,    75,    76,    77,     0,     0,
      80,    81,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   432,    92,    93,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
       0,   100,   101,   102,     0,     0,     0,     0,     0,     0,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   435,
     112,   113,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,     0,     0,     0,   122,   667,   123,     0,
       0,     0,     0,     0,   668,     0,   129,     0,   130,   131,
     132,   133,   436,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,     0,     0,   437,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   438,   439,   440,   156,   441,
     442,   159,   160,   161,   162,   163,   164,   443,   166,   167,
     444,   445,   446,   171,   447,   448,   449,   175,   450,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   451,   214,   215,
       0,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,     3,     0,     0,     0,     0,     0,     0,   412,
     413,     0,   414,   415,   416,   417,   418,   419,    13,    14,
      15,    16,    17,    18,   420,   421,   422,    22,   423,    24,
      25,    26,    27,     0,   424,   425,    30,   426,   427,   428,
      34,    35,    36,    37,    38,    39,    40,    41,    42,   429,
     430,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    62,     0,
      63,    64,    65,   431,     0,     0,    69,    70,    71,     0,
       0,     0,    73,     0,     0,     0,     0,    75,    76,    77,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,   432,
      92,    93,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,     0,   100,   101,   102,     0,     0,     0,     0,
       0,     0,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   435,   112,   113,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,   122,   710,
     123,     0,     0,     0,     0,     0,   711,     0,   129,     0,
     130,   131,   132,   133,   436,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,     0,     0,   437,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   438,   439,   440,
     156,   441,   442,   159,   160,   161,   162,   163,   164,   443,
     166,   167,   444,   445,   446,   171,   447,   448,   449,   175,
     450,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   451,
     214,   215,     0,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,     3,     0,     0,     0,     0,     0,
       0,   412,   413,     0,   414,   415,   481,   417,   482,   483,
      13,    14,    15,    16,    17,    18,   420,   421,   484,    22,
     423,    24,    25,    26,    27,     0,   424,   425,    30,   426,
     427,   428,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   485,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,  1250,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   432,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   969,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   435,   112,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,   124,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   436,   135,   136,   137,
     138,   139,   140,     0,     0,   970,   142,     0,     0,   437,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   438,
     154,   440,   156,   441,   442,   159,   160,   161,   162,   163,
     164,   443,   166,   167,   444,   445,   446,   171,   447,   448,
     449,   175,   450,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   451,   214,   215,     0,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,     3,     0,     0,     0,
       0,     0,     0,   412,   413,     0,   414,   415,   481,   417,
     482,   483,    13,    14,    15,    16,    17,    18,   420,   421,
     484,    22,   423,    24,    25,    26,    27,     0,   424,   425,
      30,   426,   427,   428,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
       0,     0,    62,     0,    63,    64,    65,   485,     0,     0,
      69,    70,    71,     0,     0,     0,    73,     0,     0,     0,
       0,    75,    76,    77,     0,     0,    80,    81,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,   432,    92,    93,     0,     0,     0,     0,
       0,     0,     0,    96,    97,    98,     0,   100,   101,   969,
       0,     0,     0,     0,     0,     0,   106,   107,     0,     0,
       0,     0,   108,   109,   110,   435,   112,   113,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   121,     0,
       0,     0,   122,     0,   123,   124,     0,     0,     0,     0,
       0,     0,   129,     0,   130,   131,   132,   133,   436,   135,
     136,   137,   138,   139,   140,     0,     0,   970,   142,     0,
       0,   437,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   438,   154,   440,   156,   441,   442,   159,   160,   161,
     162,   163,   164,   443,   166,   167,   444,   445,   446,   171,
     447,   448,   449,   175,   450,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   451,   214,   215,     0,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,     3,     0,
       0,     0,     0,     0,     0,   412,   413,     0,   414,   415,
     481,   417,   482,   483,    13,    14,    15,    16,    17,    18,
     420,   421,   484,    22,   423,    24,    25,    26,    27,     0,
     424,   425,    30,   426,   427,   428,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    62,     0,    63,    64,    65,   485,
       0,     0,    69,    70,    71,     0,     0,     0,    73,     0,
       0,     0,     0,    75,    76,    77,     0,     0,    80,    81,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,   432,    92,    93,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,     0,   100,
     101,   969,     0,     0,     0,     0,     0,     0,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   435,   112,   113,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,     0,     0,     0,   122,     0,   123,   124,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     436,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,     0,     0,   437,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   438,   154,   440,   156,   441,   442,   159,
     160,   161,   162,   163,   164,   443,   166,   167,   444,   445,
     446,   171,   447,   448,   449,   175,   450,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   451,   214,   215,     0,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
       3,     0,     0,     0,     0,     0,     0,   412,   413,     0,
     414,   415,   416,   417,   418,   419,    13,    14,    15,    16,
      17,    18,   420,   421,   422,    22,   423,    24,    25,    26,
      27,     0,   424,   425,    30,   426,   427,   428,    34,    35,
      36,    37,    38,    39,    40,    41,    42,   429,   430,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     0,     0,    62,     0,    63,    64,
      65,   431,     0,     0,    69,    70,    71,     0,     0,     0,
      73,     0,     0,     0,     0,    75,    76,    77,     0,     0,
      80,    81,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   432,    92,    93,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
       0,   100,   101,   102,     0,     0,     0,     0,     0,     0,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   435,
     112,   113,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,     0,     0,     0,   122,     0,   123,     0,
       0,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   436,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,     0,     0,   437,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   438,   439,   440,   156,   441,
     442,   159,   160,   161,   162,   163,   164,   443,   166,   167,
     444,   445,   446,   171,   447,   448,   449,   175,   450,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   451,   214,   215,
       0,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         9,  1010,   574,   103,   717,   578,   579,   580,   581,   377,
     760,   692,    21,   116,   127,   696,   800,   801,   532,   930,
     853,    26,    20,   782,   891,  1164,   893,  1305,   696,    68,
      34,    35,    36,    37,    38,    39,   998,   554,    88,   110,
       7,    60,    46,    48,     8,     9,  1137,     8,     9,    20,
     800,   801,    21,   557,    30,   559,   560,    66,   562,    68,
     564,   157,    86,   132,    88,  1176,  1177,    71,   572,   573,
      99,    86,    99,    82,    88,    86,   120,    85,   110,    20,
     110,    99,   832,    99,   136,    86,   136,    99,    20,    65,
     149,   459,   460,   461,   190,   104,   764,   189,   766,   103,
     104,   105,  1449,    20,   102,    88,   198,   116,   952,   118,
     120,   142,   136,   863,   145,   124,   114,   132,    99,   136,
      30,   142,    32,    33,     8,     9,   121,    86,   105,   206,
      53,    95,    42,     4,    95,   136,    86,     8,  1485,  1416,
     138,   185,   174,    99,   142,   175,    98,   145,   175,   113,
     179,   115,   113,   157,   115,    65,    66,   838,    92,   175,
      86,   179,   287,   171,   105,   117,   258,   179,  1445,   246,
      99,    99,   264,   298,    99,   185,    99,   136,   142,    89,
     272,   142,   146,    99,   179,   146,   190,   206,  1032,   285,
     286,     4,   142,   262,   175,     8,   163,  1288,   162,   175,
     313,   162,  1313,   214,   175,    86,   778,   779,   149,    86,
     262,    95,   262,   926,     8,     9,  1127,   149,   157,   183,
     176,  1054,   183,  1501,  1091,   296,  1137,   246,   909,   113,
    1239,   115,   149,   202,   248,   249,   240,   201,   262,   907,
     201,  1000,   113,  1521,   115,   262,   260,   262,   176,   766,
     175,   190,   123,  1215,   252,  1533,  1395,     8,   142,   175,
     210,   211,   146,   631,   241,   248,   249,   177,    19,   773,
     275,   142,   276,   277,   278,   279,   280,   286,   162,   318,
     284,   384,   321,    88,   288,   289,   290,   291,   214,   145,
      99,  1075,   226,   270,   271,   224,   273,   274,    43,   183,
     113,    95,   115,   406,   214,   214,    99,   241,   408,   318,
     123,   411,   321,   681,    99,   983,  1066,   201,  1068,   113,
     254,   115,   256,     8,    99,  1075,   207,   208,    99,   142,
     207,   208,   266,   433,    19,   269,    99,    99,    30,   126,
     145,   222,    34,   282,   283,   222,   285,   286,   142,   145,
      20,    88,   146,   453,   454,    92,   456,    99,   458,   368,
     142,   464,   113,   463,   115,   374,   175,   276,   162,   142,
      88,   380,   145,   124,   119,   384,   157,  1288,   478,    71,
     389,   142,   175,   165,   145,   394,   876,   105,   878,   183,
     175,   142,   142,   493,    56,    57,   170,   406,   407,   499,
     175,  1410,   189,    25,   175,    45,    98,   201,   109,   190,
     184,    51,   175,   175,    54,    55,   157,   520,   518,    41,
     157,   134,    62,   147,   996,   434,   999,   145,   113,   919,
     115,   921,   102,   175,   135,    87,  1008,   198,   110,   124,
     164,    86,  1226,   957,   114,   214,    98,   148,   110,   190,
     219,   164,  1430,  1431,   147,   464,   108,   142,   467,   468,
     469,    58,    59,   187,    61,   117,   158,   476,   138,   182,
     479,   164,   142,   841,   842,   145,  1226,   155,   846,   137,
     489,   182,   127,   596,   597,    58,    59,   132,  1466,   226,
     110,    88,   170,   593,  1472,  1245,   154,    88,   598,   237,
     238,   869,   511,  1370,   241,  1372,   243,   244,   245,   137,
     519,   520,   127,   110,   105,    88,   253,   254,   158,   256,
     160,   259,   241,   110,   261,   127,   154,   142,   126,   266,
     267,   268,   269,   170,   174,   276,   277,   278,   279,   280,
     142,   139,   258,    54,  1225,    86,    87,   184,   264,    88,
     145,   270,   271,    92,   273,   274,   272,    98,  1342,    92,
     200,   829,   189,   663,   664,   369,   145,   108,   470,   373,
     670,   198,   105,  1286,   677,   843,   117,   680,  1291,   187,
     683,   189,    34,    35,    36,   320,   110,    39,   956,   689,
     198,   326,  1342,   599,   204,   127,   602,   142,   604,   608,
     132,   503,   504,   145,   506,   507,   508,   509,  1441,   258,
     214,   127,   514,   713,   263,   517,   132,   626,   157,  1346,
     239,   142,   239,   242,  1351,   242,   110,  1200,   210,   211,
     212,   533,   180,   181,  1207,  1208,   290,   291,  1422,   739,
     142,   543,   544,   227,   214,   654,   216,  1219,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,   214,   221,
     216,   223,   221,   243,   223,   245,   280,   281,   677,  1382,
     231,   680,  1422,  1386,   683,   288,   289,   777,   118,   119,
      58,    59,   118,   119,   285,   286,   145,   226,   231,  1447,
    1448,   700,   371,   372,   142,   575,   576,   582,   583,   110,
     802,   803,   241,   605,   243,   244,   245,   716,   584,   585,
    1344,  1345,   149,     0,   179,   254,   179,   256,  1086,    84,
     251,  1434,   261,   156,    68,  1093,   188,   266,   267,   268,
     269,    93,   145,    94,   143,  1416,    34,    34,    20,   141,
     110,   292,   142,   142,   142,   754,   175,   175,   142,   268,
     268,   760,   110,  1503,  1327,  1328,   110,   142,   145,   145,
     175,   145,   145,   145,    27,    15,   866,   175,   202,    20,
     870,   175,    25,   220,   110,    99,   220,   158,    86,   159,
     159,    86,    86,    20,    99,   145,    99,   117,   122,    20,
     149,   800,   801,   802,   803,   287,   149,   293,   172,   122,
     142,   172,   175,   172,  1172,   172,    34,    35,    36,    37,
      38,    39,   175,    88,    30,   172,    88,    88,    46,   175,
     172,   132,    99,   832,    52,   175,   172,   175,   175,    86,
    1403,   172,   175,   172,   172,    63,    64,   226,   214,    67,
     132,   122,    70,    71,   175,   172,   179,   159,   110,   110,
     110,   110,   136,   755,   250,   269,   257,   252,   172,   868,
     762,    86,   132,   173,   122,   132,   271,   876,    86,   878,
     122,   172,   172,    92,   142,   103,   104,   105,   130,   131,
     272,   133,   272,   172,   186,   149,   122,   122,   140,    88,
     122,   136,   144,   142,   146,  1263,   172,   110,   110,   151,
     142,   246,   132,   172,    27,    20,   110,   172,   142,   235,
     919,    71,   921,   110,    99,   167,    99,   172,   145,   145,
      47,   149,   136,   272,   134,   136,   247,   175,   247,   157,
    1030,   136,   834,    86,    20,   272,    20,   159,   840,   191,
     192,   193,   194,   195,   196,    86,   179,   134,   172,  1317,
      99,   132,   175,   110,   175,   175,   965,   136,   175,   968,
     110,    61,   190,   122,     6,   132,   175,   976,   175,   978,
     226,   179,   174,   179,    98,   222,   222,    98,  1078,   222,
     175,   209,   222,   175,   136,   265,   172,    86,   110,    20,
      20,   145,   295,    88,   174,  1095,   172,   116,   900,   901,
      88,   903,   172,   905,   172,    20,   172,   172,    88,   110,
     249,   255,   240,    86,    59,    85,  1025,   110,   174,  1119,
     110,   185,   276,   925,   185,   214,   255,   185,   174,   220,
     185,   171,   110,  1133,   936,   937,   938,   214,   940,   941,
     942,   943,   944,   945,   282,   947,   948,   110,   276,   277,
     278,   279,   280,   294,   110,   142,   284,   110,   960,   175,
     288,   289,   290,   291,   292,   175,  1075,   175,   145,    34,
      35,    36,    37,    38,    39,   187,   145,   979,   214,   981,
     982,    46,   297,   276,   110,   145,   175,    52,  1097,   237,
     531,   294,   531,  1102,   295,   240,   294,   240,    63,    64,
     630,   240,    67,   299,  1113,    70,    71,   833,  1039,   299,
     867,   399,  1417,   403,  1160,   815,   382,   402,  1227,   535,
     246,  1023,   914,   285,   968,  1134,  1279,  1102,  1114,   960,
    1168,  1179,  1181,  1176,   489,  1097,  1076,   555,   103,   104,
     105,  1043,   577,   306,   556,  1127,  1155,  1472,   717,  1466,
     803,   832,   477,   878,   778,  1164,  1038,   477,  1155,  1168,
     996,  1008,  1165,   310,  1219,  1000,  1356,   779,  1238,  1214,
     997,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1085,   149,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,  1100,    -1,
      -1,    -1,  1104,  1105,    -1,  1107,    -1,    -1,    -1,    -1,
    1112,    -1,    -1,    -1,    -1,    -1,    -1,  1226,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1250,    -1,    -1,   209,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1167,    -1,  1276,  1277,    -1,
      -1,    -1,    -1,    -1,    -1,   240,    -1,  1179,  1287,    -1,
      -1,    -1,    -1,  1292,    -1,    -1,    -1,    -1,    -1,    -1,
    1192,    -1,    -1,  1195,    -1,  1197,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   276,   277,   278,   279,   280,    -1,    -1,    -1,   284,
      -1,    -1,    -1,   288,   289,   290,   291,    -1,    -1,    -1,
      -1,    -1,    -1,  1342,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1362,    -1,    -1,    -1,  1366,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1273,    -1,  1275,  1383,    -1,    -1,    -1,    -1,  1281,
      -1,    -1,    -1,    -1,    -1,    -1,  1395,    -1,    -1,    -1,
      -1,    -1,    -1,  1295,  1296,  1297,  1298,  1299,    -1,  1301,
    1302,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1419,    -1,    -1,  1422,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1324,  1523,    -1,    -1,    -1,    -1,  1437,  1529,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1543,    -1,    -1,    -1,    -1,  1457,    -1,
    1459,    -1,    -1,  1462,    -1,    -1,  1358,    -1,    -1,    -1,
      -1,    -1,    -1,  1365,    -1,  1367,    -1,  1369,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1505,    -1,    -1,  1508,
      -1,    -1,    -1,    -1,    -1,  1514,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1417,    -1,  1526,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1537,    -1,
      -1,  1540,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1461,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1490,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1504,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,  1516,    -1,  1518,    -1,    25,    26,
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
     277,    -1,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,    10,    -1,    -1,    -1,    -1,    -1,
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
     276,   277,    -1,   279,   280,   281,   282,   283,   284,   285,
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
      -1,    -1,   168,   169,   170,    -1,   172,    -1,   174,    -1,
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
     276,   277,    -1,   279,   280,   281,   282,   283,   284,   285,
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
     276,   277,    -1,   279,   280,   281,   282,   283,   284,   285,
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
      -1,    -1,   168,   169,   170,    -1,   172,    -1,   174,    -1,
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
     276,   277,    -1,   279,   280,   281,   282,   283,   284,   285,
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
      -1,    -1,   168,   169,   170,    -1,   172,    -1,   174,    -1,
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
     276,   277,    -1,   279,   280,   281,   282,   283,   284,   285,
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
      -1,    -1,   168,   169,   170,    -1,   172,    -1,   174,    -1,
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
     276,   277,    -1,   279,   280,   281,   282,   283,   284,   285,
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
      -1,    -1,   168,   169,   170,    -1,   172,    -1,   174,    -1,
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
     276,   277,    -1,   279,   280,   281,   282,   283,   284,   285,
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
      -1,    -1,   168,   169,   170,    -1,   172,    -1,   174,    -1,
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
     276,   277,    -1,   279,   280,   281,   282,   283,   284,   285,
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
      -1,    -1,   168,   169,   170,    -1,   172,    -1,   174,    -1,
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
     276,   277,    -1,   279,   280,   281,   282,   283,   284,   285,
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
     276,   277,    -1,   279,   280,   281,   282,   283,   284,   285,
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
     276,   277,    -1,   279,   280,   281,   282,   283,   284,   285,
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
     276,   277,    -1,   279,   280,   281,   282,   283,   284,   285,
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
     276,   277,    -1,   279,   280,   281,   282,   283,   284,   285,
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
     276,   277,    -1,   279,   280,   281,   282,   283,   284,   285,
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
     276,   277,    -1,   279,   280,   281,   282,   283,   284,   285,
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
     276,   277,    -1,   279,   280,   281,   282,   283,   284,   285,
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
     146,    -1,   148,   149,    -1,    -1,    -1,    -1,   154,   155,
     156,   157,   158,   159,   160,   161,   162,    -1,    -1,    -1,
      -1,    -1,   168,   169,   170,    -1,    -1,    -1,   174,    -1,
     176,   177,   178,    -1,    -1,    -1,   182,    -1,   184,    -1,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,    -1,    -1,   199,   200,   201,    -1,   203,   204,    -1,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,    -1,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,    10,    -1,    -1,    -1,    -1,    -1,
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
     246,   247,   248,   249,    -1,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,    -1,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,    10,    -1,    -1,    -1,    -1,    -1,
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
     176,    -1,    -1,    -1,    -1,    -1,   182,    -1,   184,    -1,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,    -1,    -1,   199,   200,    -1,    -1,   203,   204,    -1,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,    -1,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,    14,    -1,    -1,    -1,    18,    -1,
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
     140,   141,   142,    -1,    -1,   145,    -1,    -1,   148,   149,
      -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,   159,
     160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     170,    -1,    -1,    -1,   174,    -1,   176,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   184,    -1,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,    -1,   199,
     200,    -1,    -1,   203,   204,    -1,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,    -1,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
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
     274,   275,   276,   277,    -1,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,    14,    -1,    -1,    -1,
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
      -1,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,    16,    -1,    18,    -1,    -1,    -1,    -1,    -1,
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
     244,   245,   246,   247,   248,   249,    -1,   251,   252,    -1,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,    -1,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,    18,    -1,    -1,    -1,
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
     142,    -1,    -1,   145,    -1,    -1,   148,   149,    -1,    -1,
      -1,    -1,   154,   155,   156,   157,   158,   159,   160,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,
      -1,    -1,   174,    -1,   176,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   184,    -1,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,    -1,    -1,   199,   200,    -1,
      -1,   203,   204,    -1,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,    -1,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,    18,    -1,
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
     140,   141,   142,    -1,    -1,   145,    -1,    -1,   148,   149,
      -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,   159,
     160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     170,    -1,    -1,    -1,   174,    -1,   176,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   184,    -1,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,    -1,   199,
     200,    -1,    -1,   203,   204,    -1,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,    -1,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
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
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
      -1,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,
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
      -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,   174,   175,
     176,    -1,    -1,    -1,    -1,    -1,   182,    -1,   184,    -1,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,    -1,    -1,   199,   200,    -1,    -1,   203,   204,    -1,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,    -1,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,    -1,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,    18,    -1,    -1,    -1,    -1,    -1,
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
     244,   245,   246,   247,   248,   249,    -1,   251,   252,    -1,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,    -1,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,    18,    -1,    -1,    -1,
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
      -1,    -1,   174,    -1,   176,   177,    -1,    -1,    -1,    -1,
      -1,    -1,   184,    -1,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,    -1,    -1,   199,   200,    -1,
      -1,   203,   204,    -1,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,    -1,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,    -1,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,    18,    -1,
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
     270,   271,   272,   273,   274,   275,   276,   277,    -1,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
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
      -1,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299
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
     272,   273,   274,   275,   276,   277,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   316,   317,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   348,   349,   354,   355,   359,
     365,   369,   371,   376,   377,   378,   379,   380,   388,   389,
     391,   392,   393,   398,   400,   402,   403,   404,   409,   430,
     433,   436,   437,   438,   439,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   486,   487,   488,   502,   503,
     505,   506,   507,   508,   509,   510,   511,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   530,   531,   532,
     533,   534,   535,   536,   539,   545,   546,   547,    34,    35,
      36,    37,    38,    39,    46,    52,    63,    64,    67,    70,
      71,   103,   104,   105,   149,   157,   190,   209,   240,   276,
     277,   278,   279,   280,   284,   288,   289,   290,   291,   356,
     357,   366,   367,   368,   381,   382,   149,    86,   142,   210,
     211,   145,    25,    26,    28,    29,    30,    31,    32,    33,
      40,    41,    42,    44,    50,    51,    53,    54,    55,    65,
      66,    89,   125,   142,   145,   157,   190,   203,   213,   214,
     215,   217,   218,   225,   228,   229,   230,   232,   233,   234,
     236,   275,   545,   142,   142,   145,   142,   145,   145,    26,
      48,   275,    14,   142,   145,   544,   545,   110,   110,   110,
     142,    56,    57,   110,   395,    54,   145,   145,   142,   145,
     545,    30,    32,    33,    42,    89,   470,   545,   545,   110,
     175,   389,   545,   142,   544,    16,   545,   545,   462,   142,
      21,   202,   204,   214,   216,   145,   214,   216,   214,   214,
     219,   110,   142,   372,   227,   231,   231,   145,   142,   110,
     149,   317,     0,   319,   320,   322,    25,    41,   324,   324,
     388,   179,   179,    99,   179,   390,    45,    51,    54,    55,
      62,   158,   160,   174,   200,   394,   399,   400,   401,   418,
     419,   423,   405,   406,   545,   156,    84,   122,   130,   131,
     133,   140,   144,   146,   151,   167,   191,   192,   193,   194,
     195,   196,   454,   455,   251,   147,   164,   187,   109,   135,
     148,   182,   189,   198,   126,   139,    68,   188,    93,    94,
     147,   164,   453,   142,   459,   462,   180,   181,   143,   474,
     475,   470,   474,   470,   474,   145,   545,   382,    34,   383,
     381,   381,   382,   545,   170,   184,   157,   190,    20,   543,
     155,   170,   170,   184,   545,   141,   110,   353,    30,    34,
      71,    98,   158,   544,   210,   211,   212,    92,   226,   241,
     254,   256,   266,   269,   559,   560,   561,   562,   563,   566,
     571,   572,   545,   545,   276,   357,   292,   368,   367,   544,
     528,   545,   389,   142,   142,   389,   389,   175,   182,   545,
     142,   389,   389,   175,   389,   175,   389,   149,   543,   105,
     149,   347,   543,   149,   543,   389,    20,   175,   544,   142,
     431,   432,   545,   545,   410,   412,   545,   392,   268,   268,
     110,   413,   110,   545,    30,    65,   175,   526,   527,   389,
     175,   182,   545,   142,   431,   175,    27,   490,   491,   492,
     389,     7,   163,    15,   175,   389,   202,    20,   392,   392,
     175,   392,   392,   392,   392,   220,   537,   538,   545,   373,
     392,   392,   389,   411,   417,   545,   544,   326,   327,    25,
     328,   392,   391,   158,   110,   159,   159,   392,   392,    99,
      86,    88,   136,   262,   407,   408,   513,   438,   439,   441,
     441,   441,   441,   440,   441,   441,   441,   142,   145,   252,
     477,   548,   550,   551,   552,   553,   554,   555,   556,   444,
     444,   443,   445,   445,   445,   445,   446,   446,   447,   447,
     220,    86,    86,    86,   172,   389,   462,   462,   389,   475,
     175,   392,   485,   145,   370,   545,    20,    99,    99,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,   330,
     331,   332,    86,   127,   132,   350,   351,   352,   545,   127,
     132,   149,   149,   330,   543,   117,   122,   239,   242,   105,
     241,   270,   271,   273,   274,   239,   242,    20,   241,   270,
     271,   273,   274,    86,   214,   358,   287,   545,   293,   122,
     142,   172,   389,   389,   175,   172,    99,   175,    99,   175,
     172,   389,   172,   172,   172,   175,   544,    88,    30,   544,
     543,    88,   544,    88,   172,   175,   175,   172,   389,    99,
     176,   136,   513,   132,    99,   132,   408,   513,   172,   545,
      60,   206,   246,   396,   397,   175,   175,   175,   172,    99,
     175,    99,   175,   172,   389,   176,   545,   491,   492,   120,
     185,   172,   172,   121,   179,    86,   207,   208,   222,    86,
     207,   208,   222,    86,   226,   214,    99,   224,   132,    25,
     374,   389,   175,   172,    53,    99,   122,   179,   105,   179,
     159,   545,   392,   424,   425,   110,   420,   421,   110,   141,
     199,   514,   516,   517,   518,   545,   110,   392,   110,   136,
     408,   136,   136,   407,   408,   441,   389,   548,   554,   269,
     582,    88,   157,   243,   244,   245,   253,   261,   267,   268,
     549,   557,   558,   559,   573,   576,   577,   579,   250,   252,
     257,   578,   237,   238,   259,   574,   514,   514,   512,   517,
     512,   172,   173,    99,   175,   110,   175,   384,   385,   127,
     142,   387,   370,   137,   154,   137,   154,   331,   122,   516,
     352,   392,   513,   132,   392,   543,   543,   118,   119,   543,
     271,   272,    88,   105,   145,   565,   272,    32,    33,    42,
      66,    89,   214,   518,   280,   281,    86,   389,    86,   358,
     545,   543,   389,   172,   172,    92,   434,   435,   142,   528,
     529,   545,   528,   529,   172,   186,   122,   346,   543,   149,
     122,    88,   346,   122,   346,   142,   172,   110,   392,   392,
     136,   392,   110,   392,   132,   132,   408,   136,   513,   246,
      58,    59,    61,   110,   407,   414,   415,   416,   397,   142,
     528,   528,   172,   392,    27,   492,   120,   185,     8,     9,
      95,   113,   115,   142,   183,   386,   487,   489,   500,   501,
     504,    20,   221,   223,   392,   392,   392,   221,   223,   392,
     392,   392,   392,   392,   392,   110,   392,   392,   353,   375,
      99,   179,   172,   372,   235,   540,   541,   142,   110,   543,
     424,    87,    98,   108,   117,   426,   427,   428,   429,    99,
     545,    99,   406,   145,   145,   134,   164,   182,   515,   545,
     545,   392,   136,   392,   392,   136,   408,   136,   172,   175,
     247,   206,   246,   258,   263,   581,    88,   248,   249,   575,
     247,   551,   581,   442,   445,   267,   557,   559,   552,   136,
     575,   272,    47,   134,   392,   545,    86,    99,   175,   389,
     127,   372,   530,   351,   392,   272,    88,   145,   568,    20,
     105,   565,   518,   159,   518,    86,   287,   298,   179,   172,
     110,   514,   105,   435,   172,   389,   175,   175,   134,   175,
     175,   392,   543,    99,   346,   543,   172,   389,   432,   392,
     412,   392,   392,   132,   392,   136,   110,   110,   392,   545,
     416,    61,   172,   389,   175,   175,   122,   183,   489,     6,
     389,   545,   183,   500,   179,   222,   222,   222,   222,   226,
     538,   174,   132,   375,   471,   542,   541,   392,   417,   179,
     543,   118,   119,   428,   429,   429,   425,    98,   422,   421,
     175,   175,   392,   392,   136,   392,   445,    43,   119,   445,
     445,   258,   264,   272,   580,   580,   442,   553,   265,   513,
     514,   385,    86,   172,   126,   189,   567,   570,    20,    20,
     569,   567,   260,   575,    99,   175,    99,   175,   145,   363,
     518,   214,   276,   295,   545,   174,   110,   174,   172,   116,
      88,   543,    88,   172,   392,   392,   545,   545,   415,   392,
     172,   492,   545,   183,   172,   492,   545,   392,   392,   392,
     392,   392,   392,   392,   145,   198,   387,   172,   429,   543,
     392,   445,   445,   187,   514,   568,   568,   570,    20,   175,
      20,   255,   564,   565,   564,   364,   392,    99,   175,   110,
     545,   249,    86,   392,   545,   392,   392,   346,   346,    59,
      85,   171,   493,   492,   545,   185,   492,   110,   471,   445,
     575,    99,   175,   175,   426,   513,   364,   157,   190,   282,
     283,   285,   286,   360,   361,   362,   545,   110,   296,   276,
     514,   174,   110,     4,   123,   496,   497,   499,   501,    19,
     124,   494,   495,   498,   501,   185,   492,   185,   545,   255,
     565,   426,   362,   362,   361,   282,   220,   545,   214,   545,
     174,   392,   545,    85,   123,   499,   171,   124,   498,   185,
      99,   175,   361,   297,   294,   110,   214,   392,   110,   387,
     518,   282,   392,   545,   110,   545,   294,   295,   294,   545,
      99,   175,   392,   145,   392,   299,   110,   387,   389,   145,
     545,   175,   389,   175,   175,   387,   187,   276,   545,   214,
     110,   545,   299,   145,   389,   175
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
     565,   566,   567,   568,   569
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   315,   316,   316,   317,   317,   317,   317,   317,   317,
     318,   318,   319,   319,   320,   320,   321,   322,   322,   323,
     324,   324,   324,   325,   325,   326,   326,   327,   327,   327,
     327,   328,   328,   328,   328,   328,   328,   328,   328,   328,
     329,   329,   330,   330,   331,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   333,   333,   333,   333,   333,
     333,   333,   333,   334,   334,   335,   336,   336,   337,   337,
     338,   339,   340,   340,   341,   341,   342,   342,   342,   342,
     343,   344,   345,   345,   345,   345,   346,   346,   347,   347,
     348,   348,   348,   348,   348,   348,   348,   348,   349,   350,
     350,   351,   351,   351,   352,   353,   353,   354,   354,   354,
     355,   355,   355,   355,   355,   355,   355,   355,   356,   356,
     357,   357,   357,   357,   357,   357,   358,   358,   359,   360,
     360,   360,   361,   361,   361,   362,   362,   362,   363,   363,
     364,   364,   364,   364,   365,   365,   365,   365,   365,   366,
     366,   367,   367,   367,   368,   368,   368,   369,   369,   370,
     370,   370,   370,   371,   372,   373,   373,   374,   374,   375,
     375,   376,   377,   378,   379,   379,   380,   380,   380,   381,
     381,   381,   381,   382,   382,   383,   383,   384,   384,   385,
     385,   386,   387,   388,   389,   389,   390,   390,   391,   391,
     392,   392,   392,   392,   392,   392,   392,   392,   392,   392,
     392,   392,   392,   392,   392,   392,   392,   393,   394,   395,
     395,   396,   396,   396,   397,   397,   398,   398,   399,   400,
     400,   400,   401,   401,   401,   401,   401,   402,   402,   403,
     403,   404,   405,   405,   406,   406,   406,   406,   406,   406,
     406,   406,   407,   408,   409,   410,   410,   411,   411,   412,
     412,   412,   412,   413,   413,   414,   414,   414,   415,   415,
     415,   416,   416,   416,   417,   418,   419,   420,   420,   421,
     421,   422,   423,   423,   424,   424,   425,   425,   426,   426,
     426,   426,   426,   426,   426,   427,   427,   428,   428,   429,
     430,   430,   431,   431,   432,   432,   433,   433,   434,   434,
     435,   435,   436,   437,   437,   438,   438,   439,   439,   439,
     439,   439,   440,   439,   439,   439,   439,   441,   441,   441,
     442,   442,   443,   443,   443,   444,   444,   444,   444,   444,
     445,   445,   445,   446,   446,   446,   447,   447,   448,   448,
     449,   449,   450,   450,   451,   451,   452,   452,   452,   452,
     453,   453,   453,   454,   454,   454,   454,   454,   454,   455,
     455,   455,   456,   456,   456,   456,   457,   457,   458,   458,
     459,   459,   460,   460,   460,   460,   461,   462,   462,   462,
     463,   463,   464,   464,   464,   464,   465,   465,   466,   466,
     466,   466,   466,   466,   466,   467,   467,   468,   468,   469,
     469,   469,   469,   469,   470,   470,   471,   471,   472,   472,
     472,   473,   473,   474,   474,   475,   476,   476,   476,   476,
     476,   476,   476,   476,   477,   477,   478,   478,   478,   479,
     480,   480,   481,   482,   483,   484,   484,   485,   485,   486,
     486,   487,   487,   487,   488,   488,   488,   488,   488,   488,
     489,   489,   490,   490,   491,   492,   492,   493,   493,   494,
     494,   495,   495,   495,   495,   496,   496,   497,   497,   497,
     497,   498,   498,   499,   499,   500,   500,   500,   500,   501,
     501,   501,   501,   502,   502,   503,   503,   504,   505,   505,
     505,   505,   505,   505,   506,   507,   507,   507,   507,   508,
     508,   508,   508,   509,   510,   511,   511,   511,   511,   512,
     512,   513,   514,   514,   514,   515,   515,   515,   516,   516,
     516,   517,   518,   518,   518,   518,   518,   518,   518,   518,
     518,   519,   520,   520,   520,   521,   522,   523,   523,   523,
     524,   524,   524,   524,   524,   525,   526,   526,   526,   526,
     526,   526,   526,   527,   528,   529,   530,   531,   531,   531,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     533,   533,   534,   534,   535,   536,   537,   537,   538,   539,
     540,   540,   541,   541,   541,   541,   542,   542,   543,   544,
     544,   545,   545,   546,   546,   546,   546,   546,   546,   546,
     546,   546,   546,   546,   546,   546,   546,   546,   546,   546,
     546,   546,   546,   546,   546,   546,   546,   546,   546,   546,
     546,   546,   546,   546,   546,   546,   546,   546,   546,   546,
     546,   546,   546,   546,   546,   546,   546,   546,   546,   546,
     546,   546,   546,   546,   546,   546,   546,   546,   546,   546,
     546,   546,   546,   546,   546,   546,   546,   546,   546,   546,
     546,   546,   546,   546,   546,   546,   546,   546,   546,   546,
     546,   546,   546,   546,   546,   546,   546,   546,   546,   546,
     546,   546,   546,   546,   546,   546,   546,   546,   546,   546,
     546,   546,   546,   546,   546,   546,   546,   546,   546,   546,
     546,   546,   546,   546,   546,   546,   546,   546,   546,   546,
     546,   546,   546,   546,   546,   546,   546,   546,   546,   546,
     546,   546,   546,   546,   546,   546,   546,   546,   546,   546,
     546,   546,   546,   546,   546,   546,   546,   546,   546,   546,
     546,   546,   546,   546,   546,   546,   546,   546,   546,   546,
     546,   546,   546,   546,   546,   546,   546,   546,   546,   546,
     546,   546,   546,   546,   546,   546,   546,   546,   546,   546,
     546,   546,   546,   546,   546,   546,   546,   546,   546,   546,
     546,   546,   546,   546,   546,   546,   546,   546,   546,   546,
     546,   546,   546,   546,   546,   547,   547,   548,   548,   548,
     548,   549,   549,   549,   549,   550,   550,   551,   551,   552,
     552,   553,   553,   554,   554,   554,   555,   555,   556,   556,
     557,   557,   557,   557,   557,   558,   559,   559,   559,   559,
     559,   559,   559,   560,   560,   560,   560,   561,   561,   561,
     561,   562,   562,   563,   563,   563,   563,   563,   563,   563,
     564,   564,   565,   565,   565,   565,   566,   566,   566,   566,
     566,   567,   567,   568,   568,   569,   569,   570,   570,   571,
     572,   572,   573,   573,   573,   574,   574,   574,   574,   574,
     575,   575,   575,   575,   576,   577,   578,   579,   579,   580,
     580,   580,   581,   581,   582
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  xquery_parser::yyr2_[] =
  {
         0,     2,     1,     2,     1,     2,     1,     2,     1,     2,
       4,     6,     2,     1,     1,     2,     6,     1,     2,     6,
       2,     2,     4,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     1,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     3,     3,     5,     5,
       4,     3,     3,     3,     5,     5,     5,     5,     5,     5,
       4,     3,     3,     4,     5,     6,     1,     3,     3,     3,
       3,     6,     5,     8,     3,     6,     5,     8,     4,     3,
       1,     1,     1,     2,     2,     2,     3,     5,     4,     6,
       3,     4,     5,     6,     4,     5,     6,     7,     1,     2,
       1,     1,     1,     1,     1,     1,     2,     2,     9,     1,
       2,     3,     1,     2,     2,     0,     1,     1,     2,     3,
       1,     2,     2,     3,    12,    16,    14,    14,    27,     2,
       2,     0,     1,     1,     0,     1,     1,     3,     3,     2,
       3,     4,     5,     2,     4,     3,     0,     3,     2,     1,
       3,     5,     3,     5,     2,     2,     2,     3,     3,     1,
       2,     2,     2,     4,     4,     4,     4,     1,     3,     2,
       3,     3,     3,     1,     1,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     1,     1,     2,     4,     3,     5,     4,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       3,     2,     1,     4,     3,     4,     4,     5,     4,     5,
       5,     6,     3,     3,     3,     1,     4,     1,     4,     3,
       4,     4,     5,     4,     5,     1,     2,     3,     1,     2,
       1,     6,     3,     3,     1,     2,     3,     1,     3,     2,
       3,     2,     3,     4,     1,     3,     1,     2,     1,     1,
       1,     2,     2,     2,     3,     1,     1,     2,     2,     2,
       5,     5,     1,     4,     3,     4,     8,    10,     1,     2,
       4,     7,     8,     1,     3,     1,     3,     1,     3,     3,
       3,     3,     0,     4,     3,     3,     3,     1,     3,     4,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     4,     1,     4,
       1,     4,     1,     4,     1,     2,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     5,     5,     6,     3,     4,     1,     2,
       3,     2,     1,     2,     2,     1,     1,     1,     3,     3,
       1,     1,     1,     2,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     3,     1,     4,     4,     3,     4,     1,     3,     1,
       1,     1,     1,     1,     4,     5,     8,     9,     9,    10,
       1,     2,     1,     2,     6,     0,     1,     3,     3,     0,
       1,     1,     1,     2,     2,     0,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     3,     3,     2,     1,     1,
       1,     1,     1,     1,     4,     4,     5,     6,     7,     4,
       5,     6,     7,     4,     4,     4,     5,     6,     7,     1,
       2,     2,     1,     2,     3,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     4,     4,     3,     3,     3,     4,     4,
       3,     4,     6,     4,     6,     3,     3,     4,     6,     6,
       4,     6,     6,     4,     1,     2,     1,     3,     3,     3,
       5,     7,     7,     5,     5,     5,     7,     7,     5,     5,
       3,     3,     5,     7,     5,     7,     1,     4,     3,     5,
       1,     2,     3,     7,    10,    13,     1,     3,     1,     1,
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
       1,     1,     1,     1,     1,     7,     4,     1,     2,     3,
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
  "\"'collection'\"", "\"'const'\"", "\"'append-only'\"", "\"'queue'\"",
  "\"'mutable'\"", "\"'read-only'\"", "\"'unique'\"", "\"'non'\"",
  "\"'index'\"", "\"'manual'\"", "\"'automatic'\"", "\"'on'\"",
  "\"'checked'\"", "\"'unchecked'\"", "\"'asynchronous'\"",
  "\"'synchronous'\"", "\"'integrity'\"", "\"'constraint'\"",
  "\"'check'\"", "\"'key'\"", "\"'foreach'\"", "\"'type'\"",
  "\"'foreign'\"", "\"'keys'\"", "\"'BOM_UTF8'\"", "FTCONTAINS_REDUCE",
  "RANGE_REDUCE", "ADDITIVE_REDUCE", "MULTIPLICATIVE_REDUCE",
  "UNION_REDUCE", "INTERSECT_EXCEPT_REDUCE", "QVARINDECLLIST_REDUCE",
  "COMMA_DOLLAR", "UNARY_PREC", "SEQUENCE_TYPE_REDUCE", "OCCURS_STAR",
  "OCCURS_PLUS", "OCCURS_HOOK", "STEP_REDUCE", "$accept", "Module",
  "ModuleWithoutBOM", "VersionDecl", "MainModule", "LibraryModule",
  "ModuleDecl", "DataModule", "DataModuleDecl", "Prolog", "SIND_DeclList",
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
       316,     0,    -1,   317,    -1,   300,   317,    -1,   319,    -1,
     318,   319,    -1,   320,    -1,   318,   320,    -1,   322,    -1,
     318,   322,    -1,   203,   204,    20,   179,    -1,   203,   204,
      20,   121,    20,   179,    -1,   324,   388,    -1,   388,    -1,
     321,    -1,   321,   324,    -1,    26,   149,   544,   122,   543,
     179,    -1,   323,    -1,   323,   324,    -1,   275,   149,   544,
     122,   543,   179,    -1,   325,   179,    -1,   326,   179,    -1,
     325,   179,   326,   179,    -1,   327,    -1,   325,   179,   327,
      -1,   328,    -1,   326,   179,   328,    -1,   333,    -1,   334,
      -1,   335,    -1,   337,    -1,   354,    -1,   349,    -1,   380,
      -1,   338,    -1,   339,    -1,   355,    -1,   359,    -1,   365,
      -1,   329,    -1,    25,   105,    71,   330,    -1,    25,    71,
     545,   330,    -1,   331,    -1,   330,   331,    -1,   332,   122,
     530,    -1,    72,    -1,    73,    -1,    74,    -1,    75,    -1,
      76,    -1,    77,    -1,    78,    -1,    79,    -1,    80,    -1,
      81,    -1,   336,    -1,   343,    -1,   344,    -1,   369,    -1,
     340,    -1,   341,    -1,   342,    -1,   531,    -1,   345,    -1,
     348,    -1,    25,   149,   544,   122,   543,    -1,    25,    70,
     170,    -1,    25,    70,   184,    -1,    25,   105,    30,   149,
     543,    -1,    25,   105,    34,   149,   543,    -1,    25,    46,
     545,    20,    -1,    25,   240,   559,    -1,    25,    63,   157,
      -1,    25,    63,   190,    -1,    25,   105,   158,   117,   118,
      -1,    25,   105,   158,   117,   119,    -1,    25,    67,   170,
      99,   137,    -1,    25,    67,   170,    99,   154,    -1,    25,
      67,   155,    99,   137,    -1,    25,    67,   155,    99,   154,
      -1,    25,   105,    98,   543,    -1,    25,    64,   543,    -1,
      41,    48,   543,    -1,    41,    48,   347,   543,    -1,    41,
      48,   543,    88,   346,    -1,    41,    48,   347,   543,    88,
     346,    -1,   543,    -1,   346,    99,   543,    -1,   149,   544,
     122,    -1,   105,    30,   149,    -1,    41,    26,   543,    -1,
      41,    26,   149,   544,   122,   543,    -1,    41,    26,   543,
      88,   346,    -1,    41,    26,   149,   544,   122,   543,    88,
     346,    -1,    41,   275,   543,    -1,    41,   275,   149,   544,
     122,   543,    -1,    41,   275,   543,    88,   346,    -1,    41,
     275,   149,   544,   122,   543,    88,   346,    -1,    25,   103,
     141,   350,    -1,    86,   516,   351,    -1,   351,    -1,   352,
      -1,   127,    -1,   127,   352,    -1,   132,   392,    -1,   110,
     545,    -1,   110,   545,   513,    -1,    25,   104,   353,   132,
     392,    -1,    25,   104,   353,   127,    -1,    25,   104,   353,
     127,   132,   392,    -1,    25,   276,   545,    -1,    25,   276,
     545,   358,    -1,    25,   276,   545,    86,   518,    -1,    25,
     276,   545,   358,    86,   518,    -1,    25,   356,   276,   545,
      -1,    25,   356,   276,   545,   358,    -1,    25,   356,   276,
     545,    86,   518,    -1,    25,   356,   276,   545,   358,    86,
     518,    -1,   357,    -1,   356,   357,    -1,   277,    -1,   278,
      -1,   279,    -1,   280,    -1,   157,    -1,   190,    -1,   214,
     281,    -1,   214,   280,    -1,    25,   284,   545,   287,   389,
     159,   363,   175,   360,    -1,   361,    -1,   282,   361,    -1,
     283,   282,   361,    -1,   362,    -1,   157,   362,    -1,   190,
     362,    -1,    -1,   285,    -1,   286,    -1,   145,   364,    -1,
     363,    99,   364,    -1,   392,    -1,   392,   426,    -1,   392,
     513,    -1,   392,   513,   426,    -1,    25,   366,   292,   293,
     545,   287,   276,   545,   110,   545,   294,   392,    -1,    25,
     366,   292,   293,   545,   287,   276,   545,   110,   545,   294,
     282,   295,   145,   389,   175,    -1,    25,   366,   292,   293,
     545,   287,   276,   545,   296,   214,   110,   545,   294,   392,
      -1,    25,   366,   292,   293,   545,   287,   214,   110,   545,
     220,   297,   518,   294,   392,    -1,    25,   366,   292,   293,
     545,   298,   295,   249,   276,   545,   214,   110,   545,   299,
     145,   389,   175,   187,   276,   545,   214,   110,   545,   299,
     145,   389,   175,    -1,   367,   368,    -1,   368,   367,    -1,
      -1,   288,    -1,   289,    -1,    -1,   291,    -1,   290,    -1,
      25,    52,   170,    -1,    25,    52,   184,    -1,   145,   175,
      -1,   145,   384,   175,    -1,   145,   175,    86,   514,    -1,
     145,   384,   175,    86,   514,    -1,   228,   372,    -1,   142,
     373,   389,   172,    -1,   373,   374,   179,    -1,    -1,   374,
      99,   375,    -1,    25,   375,    -1,   353,    -1,   353,   132,
     392,    -1,    50,   110,   545,   132,   392,    -1,   229,   227,
     392,    -1,   233,   145,   392,   175,   372,    -1,   230,   231,
      -1,   232,   231,    -1,    25,   381,    -1,    25,    38,   381,
      -1,    25,    37,   381,    -1,   382,    -1,    39,   382,    -1,
      35,   382,    -1,    36,   383,    -1,    34,   545,   370,   387,
      -1,    34,   545,   370,   127,    -1,    34,   545,   370,   372,
      -1,    34,   545,   370,   127,    -1,   385,    -1,   384,    99,
     385,    -1,   110,   545,    -1,   110,   545,   513,    -1,   142,
     389,   172,    -1,   142,   389,   172,    -1,   389,    -1,   391,
      -1,   391,   390,    -1,   179,    -1,   390,   391,   179,    -1,
     392,    -1,   391,    99,   392,    -1,   393,    -1,   430,    -1,
     433,    -1,   436,    -1,   437,    -1,   532,    -1,   533,    -1,
     535,    -1,   534,    -1,   536,    -1,   539,    -1,   547,    -1,
     377,    -1,   378,    -1,   379,    -1,   376,    -1,   371,    -1,
     402,   394,    -1,   174,   392,    -1,    56,   268,    -1,    57,
     268,    -1,   206,    -1,   246,    -1,    60,   246,    -1,   396,
     414,    61,   392,    -1,   396,    61,   392,    -1,    54,   395,
     413,   397,   397,    -1,    54,   395,   413,   397,    -1,    62,
     110,   545,    -1,   404,    -1,   409,    -1,   398,    -1,   400,
      -1,   418,    -1,   423,    -1,   419,    -1,   399,    -1,   400,
      -1,   402,   401,    -1,    54,   110,    -1,    55,    54,   110,
      -1,   403,   405,    -1,   406,    -1,   405,    99,   110,   406,
      -1,   545,   136,   392,    -1,   545,   513,   136,   392,    -1,
     545,   407,   136,   392,    -1,   545,   513,   407,   136,   392,
      -1,   545,   408,   136,   392,    -1,   545,   513,   408,   136,
     392,    -1,   545,   407,   408,   136,   392,    -1,   545,   513,
     407,   408,   136,   392,    -1,    88,   110,   545,    -1,   262,
     110,   545,    -1,    51,   110,   410,    -1,   412,    -1,   410,
      99,   110,   412,    -1,   417,    -1,   411,    99,   110,   417,
      -1,   545,   132,   392,    -1,   545,   513,   132,   392,    -1,
     545,   408,   132,   392,    -1,   545,   513,   408,   132,   392,
      -1,   110,   545,   136,   392,    -1,   110,   545,   513,   136,
     392,    -1,   415,    -1,   110,   545,    -1,   110,   545,   415,
      -1,   407,    -1,   407,   416,    -1,   416,    -1,    58,   110,
     545,    59,   110,   545,    -1,    59,   110,   545,    -1,    58,
     110,   545,    -1,   545,    -1,   200,   392,    -1,   160,   159,
     420,    -1,   421,    -1,   420,    99,   421,    -1,   110,   545,
      -1,   110,   545,   422,    -1,    98,   543,    -1,   158,   159,
     424,    -1,    45,   158,   159,   424,    -1,   425,    -1,   424,
      99,   425,    -1,   392,    -1,   392,   426,    -1,   427,    -1,
     428,    -1,   429,    -1,   427,   428,    -1,   427,   429,    -1,
     428,   429,    -1,   427,   428,   429,    -1,    87,    -1,   108,
      -1,   117,   118,    -1,   117,   119,    -1,    98,   543,    -1,
      44,   110,   431,   176,   392,    -1,   125,   110,   431,   176,
     392,    -1,   432,    -1,   431,    99,   110,   432,    -1,   545,
     136,   392,    -1,   545,   513,   136,   392,    -1,    29,   145,
     389,   175,   434,   105,   174,   392,    -1,    29,   145,   389,
     175,   434,   105,   110,   545,   174,   392,    -1,   435,    -1,
     434,   435,    -1,    92,   514,   174,   392,    -1,    92,   110,
     545,    86,   514,   174,   392,    -1,    40,   145,   389,   175,
     186,   392,   116,   392,    -1,   438,    -1,   437,   156,   438,
      -1,   439,    -1,   438,    84,   439,    -1,   441,    -1,   441,
     454,   441,    -1,   441,   455,   441,    -1,   441,   122,   441,
      -1,   441,   151,   441,    -1,    -1,   441,   146,   440,   441,
      -1,   441,   144,   441,    -1,   441,   133,   441,    -1,   441,
     131,   441,    -1,   442,    -1,   442,   251,   548,    -1,   442,
     251,   548,   582,    -1,   443,    -1,   443,   187,   443,    -1,
     444,    -1,   443,   164,   444,    -1,   443,   147,   444,    -1,
     445,    -1,   444,   182,   445,    -1,   444,   109,   445,    -1,
     444,   135,   445,    -1,   444,   148,   445,    -1,   446,    -1,
     445,   189,   446,    -1,   445,   198,   446,    -1,   447,    -1,
     446,   139,   447,    -1,   446,   126,   447,    -1,   448,    -1,
     448,    68,   220,   514,    -1,   449,    -1,   449,   188,    86,
     514,    -1,   450,    -1,   450,    93,    86,   512,    -1,   451,
      -1,   451,    94,    86,   512,    -1,   453,    -1,   452,   453,
      -1,   164,    -1,   147,    -1,   452,   164,    -1,   452,   147,
      -1,   456,    -1,   460,    -1,   457,    -1,   191,    -1,   196,
      -1,   195,    -1,   194,    -1,   193,    -1,   192,    -1,   140,
      -1,   167,    -1,   130,    -1,    28,   142,   389,   172,    -1,
      28,   211,   142,   389,   172,    -1,    28,   210,   142,   389,
     172,    -1,    28,    86,   528,   142,   389,   172,    -1,   458,
     142,   172,    -1,   458,   142,   389,   172,    -1,   459,    -1,
     458,   459,    -1,   165,   545,    15,    -1,   165,    16,    -1,
     461,    -1,   461,   462,    -1,   181,   462,    -1,   462,    -1,
     180,    -1,   463,    -1,   463,   180,   462,    -1,   463,   181,
     462,    -1,   464,    -1,   473,    -1,   465,    -1,   465,   474,
      -1,   468,    -1,   468,   474,    -1,   466,   470,    -1,   467,
      -1,    97,    -1,   106,    -1,    90,    -1,   178,    -1,   107,
      -1,   129,    -1,   128,    -1,   470,    -1,    91,   470,    -1,
     469,   470,    -1,   112,    -1,   161,    -1,    82,    -1,   169,
      -1,   168,    -1,    83,    -1,   518,    -1,   471,    -1,   545,
      -1,   472,    -1,   182,    -1,    10,    -1,    17,    -1,   476,
      -1,   476,   474,    -1,   475,    -1,   474,   475,    -1,   143,
     389,   173,    -1,   477,    -1,   479,    -1,   480,    -1,   481,
      -1,   484,    -1,   486,    -1,   482,    -1,   483,    -1,   478,
      -1,   530,    -1,   102,    -1,   138,    -1,   114,    -1,   110,
     545,    -1,   145,   175,    -1,   145,   389,   175,    -1,   111,
      -1,   157,   142,   389,   172,    -1,   190,   142,   389,   172,
      -1,   545,   145,   175,    -1,   545,   145,   485,   175,    -1,
     392,    -1,   485,    99,   392,    -1,   487,    -1,   505,    -1,
     488,    -1,   502,    -1,   503,    -1,   146,   545,   492,   120,
      -1,   146,   545,   490,   492,   120,    -1,   146,   545,   492,
     185,   183,   545,   492,   185,    -1,   146,   545,   492,   185,
     489,   183,   545,   492,   185,    -1,   146,   545,   490,   492,
     185,   183,   545,   492,   185,    -1,   146,   545,   490,   492,
     185,   489,   183,   545,   492,   185,    -1,   500,    -1,   489,
     500,    -1,   491,    -1,   490,   491,    -1,    27,   545,   492,
     122,   492,   493,    -1,    -1,    27,    -1,   171,   494,   171,
      -1,    85,   496,    85,    -1,    -1,   495,    -1,   124,    -1,
     498,    -1,   495,   124,    -1,   495,   498,    -1,    -1,   497,
      -1,   123,    -1,   499,    -1,   497,   123,    -1,   497,   499,
      -1,    19,    -1,   501,    -1,     4,    -1,   501,    -1,   487,
      -1,     9,    -1,   504,    -1,   501,    -1,     8,    -1,   113,
      -1,   115,    -1,   386,    -1,   201,    21,   202,    -1,   201,
     202,    -1,   162,   544,   163,    -1,   162,   544,     7,    -1,
      95,     6,    -1,   506,    -1,   507,    -1,   508,    -1,   509,
      -1,   510,    -1,   511,    -1,    31,   142,   389,   172,    -1,
      30,   545,   142,   172,    -1,    30,   545,   142,   389,   172,
      -1,    30,   142,   389,   172,   142,   172,    -1,    30,   142,
     389,   172,   142,   389,   172,    -1,    89,   545,   142,   172,
      -1,    89,   545,   142,   389,   172,    -1,    89,   142,   389,
     172,   142,   172,    -1,    89,   142,   389,   172,   142,   389,
     172,    -1,    32,   142,   389,   172,    -1,    33,   142,   389,
     172,    -1,    42,   544,   142,   172,    -1,    42,   544,   142,
     389,   172,    -1,    42,   142,   389,   172,   142,   172,    -1,
      42,   142,   389,   172,   142,   389,   172,    -1,   517,    -1,
     517,   134,    -1,    86,   514,    -1,   516,    -1,   516,   515,
      -1,   199,   145,   175,    -1,   134,    -1,   182,    -1,   164,
      -1,   517,    -1,   518,    -1,   141,   145,   175,    -1,   545,
      -1,   520,    -1,   526,    -1,   524,    -1,   527,    -1,   525,
      -1,   523,    -1,   522,    -1,   521,    -1,   519,    -1,   214,
     145,   175,    -1,    66,   145,   175,    -1,    66,   145,   526,
     175,    -1,    66,   145,   527,   175,    -1,    32,   145,   175,
      -1,    33,   145,   175,    -1,    42,   145,   175,    -1,    42,
     145,   544,   175,    -1,    42,   145,    20,   175,    -1,    89,
     145,   175,    -1,    89,   145,   545,   175,    -1,    89,   145,
     545,    99,   528,   175,    -1,    89,   145,   182,   175,    -1,
      89,   145,   182,    99,   528,   175,    -1,   177,   545,   175,
      -1,    30,   145,   175,    -1,    30,   145,   545,   175,    -1,
      30,   145,   545,    99,   528,   175,    -1,    30,   145,   545,
      99,   529,   175,    -1,    30,   145,   182,   175,    -1,    30,
     145,   182,    99,   528,   175,    -1,    30,   145,   182,    99,
     529,   175,    -1,    65,   145,   545,   175,    -1,   545,    -1,
     545,   134,    -1,    20,    -1,    25,   209,   210,    -1,    25,
     209,   211,    -1,    25,   209,   212,    -1,   215,   214,   392,
     222,   392,    -1,   215,   214,   392,    86,   221,   222,   392,
      -1,   215,   214,   392,    86,   223,   222,   392,    -1,   215,
     214,   392,   207,   392,    -1,   215,   214,   392,   208,   392,
      -1,   215,   216,   392,   222,   392,    -1,   215,   216,   392,
      86,   221,   222,   392,    -1,   215,   216,   392,    86,   223,
     222,   392,    -1,   215,   216,   392,   207,   392,    -1,   215,
     216,   392,   208,   392,    -1,   213,   214,   392,    -1,   213,
     216,   392,    -1,   218,   214,   392,   226,   392,    -1,   218,
     219,   220,   214,   392,   226,   392,    -1,   217,   214,   392,
      86,   392,    -1,   225,   110,   537,   224,   392,   174,   392,
      -1,   538,    -1,   537,    99,   110,   538,    -1,   545,   132,
     392,    -1,   234,   142,   389,   172,   540,    -1,   541,    -1,
     540,   541,    -1,   235,   542,   387,    -1,   235,   542,   145,
     110,   545,   175,   387,    -1,   235,   542,   145,   110,   545,
      99,   110,   545,   175,   387,    -1,   235,   542,   145,   110,
     545,    99,   110,   545,    99,   110,   545,   175,   387,    -1,
     471,    -1,   542,   198,   471,    -1,    20,    -1,    14,    -1,
     545,    -1,    18,    -1,   546,    -1,   203,    -1,   117,    -1,
      89,    -1,    33,    -1,    66,    -1,    30,    -1,   141,    -1,
      40,    -1,   214,    -1,    42,    -1,    69,    -1,    65,    -1,
      32,    -1,    29,    -1,   199,    -1,    70,    -1,   240,    -1,
      64,    -1,   211,    -1,   210,    -1,   135,    -1,    31,    -1,
     252,    -1,   239,    -1,   242,    -1,   241,    -1,   269,    -1,
     270,    -1,   273,    -1,   271,    -1,   274,    -1,   245,    -1,
     247,    -1,    47,    -1,   206,    -1,   246,    -1,    43,    -1,
     212,    -1,   225,    -1,   219,    -1,   191,    -1,   196,    -1,
     195,    -1,   194,    -1,   193,    -1,   192,    -1,    88,    -1,
     103,    -1,   104,    -1,   174,    -1,    54,    -1,    55,    -1,
      56,    -1,    57,    -1,    58,    -1,    59,    -1,    60,    -1,
      61,    -1,    62,    -1,   136,    -1,    51,    -1,   200,    -1,
     159,    -1,   160,    -1,   158,    -1,    45,    -1,    87,    -1,
     108,    -1,   118,    -1,   119,    -1,    98,    -1,    44,    -1,
     125,    -1,   176,    -1,    92,    -1,    86,    -1,   186,    -1,
     116,    -1,   156,    -1,    84,    -1,    68,    -1,   220,    -1,
      93,    -1,   187,    -1,   109,    -1,   148,    -1,   189,    -1,
     139,    -1,   126,    -1,    28,    -1,    94,    -1,   188,    -1,
     140,    -1,   170,    -1,   184,    -1,   149,    -1,   127,    -1,
     121,    -1,   155,    -1,   137,    -1,   154,    -1,    25,    -1,
      52,    -1,    63,    -1,   105,    -1,    67,    -1,    46,    -1,
     204,    -1,    41,    -1,    48,    -1,    26,    -1,    34,    -1,
     262,    -1,   251,    -1,   267,    -1,   268,    -1,   244,    -1,
     257,    -1,   265,    -1,   261,    -1,   243,    -1,   256,    -1,
     266,    -1,   260,    -1,   255,    -1,   254,    -1,   238,    -1,
     237,    -1,   259,    -1,   248,    -1,   249,    -1,   272,    -1,
     264,    -1,   263,    -1,   258,    -1,   218,    -1,   224,    -1,
     221,    -1,   215,    -1,   208,    -1,   207,    -1,   209,    -1,
     226,    -1,   216,    -1,   217,    -1,   223,    -1,   213,    -1,
     222,    -1,    39,    -1,    36,    -1,    35,    -1,    37,    -1,
      38,    -1,   157,    -1,   190,    -1,   227,    -1,   228,    -1,
     229,    -1,   231,    -1,   233,    -1,   230,    -1,   232,    -1,
     234,    -1,   235,    -1,    53,    -1,   236,    -1,    50,    -1,
     284,    -1,   282,    -1,   283,    -1,   287,    -1,   285,    -1,
     286,    -1,    71,    -1,    72,    -1,    73,    -1,    74,    -1,
      75,    -1,    76,    -1,    77,    -1,    78,    -1,    79,    -1,
      80,    -1,    81,    -1,   276,    -1,   275,    -1,   277,    -1,
     279,    -1,   280,    -1,   281,    -1,   288,    -1,   289,    -1,
     290,    -1,   291,    -1,   292,    -1,   293,    -1,   294,    -1,
     295,    -1,   296,    -1,   297,    -1,   298,    -1,   299,    -1,
     236,   110,   411,    53,   142,   392,   172,    -1,    53,   142,
     392,   172,    -1,   550,    -1,   550,   549,    -1,   550,   267,
     442,    -1,   550,   549,   267,   442,    -1,   559,    -1,   557,
      -1,   549,   559,    -1,   549,   557,    -1,   551,    -1,   550,
     253,   551,    -1,   552,    -1,   551,   250,   552,    -1,   553,
      -1,   552,   252,   136,   553,    -1,   554,    -1,   252,   554,
      -1,   555,    -1,   555,   578,    -1,   145,   548,   175,    -1,
     556,    -1,   556,   574,    -1,   477,    -1,   142,   389,   172,
      -1,   558,    -1,   577,    -1,   576,    -1,   579,    -1,   573,
      -1,   157,    -1,   560,    -1,   561,    -1,   562,    -1,   563,
      -1,   566,    -1,   571,    -1,   572,    -1,   256,    -1,   266,
      -1,    92,   239,    -1,    92,   242,    -1,   226,   241,    -1,
     269,   241,    -1,   241,   239,    -1,   241,   242,    -1,   226,
     270,    -1,   269,   270,    -1,   226,   273,   565,    -1,   226,
     273,   105,    -1,   226,   273,   145,   565,   175,    -1,   226,
     273,   145,   565,    99,   564,   175,    -1,   226,   273,   145,
     105,   175,    -1,   226,   273,   145,   105,    99,   564,   175,
      -1,   269,   273,    -1,   565,    -1,   564,    99,   565,    -1,
      88,    20,    -1,    88,    20,   260,    20,    -1,    88,    20,
     575,   255,    -1,    88,    20,   260,    20,   575,   255,    -1,
     226,   271,   272,   568,    -1,   226,   271,   272,   568,   567,
      -1,   226,   105,   271,   272,    -1,   226,   105,   271,   272,
     567,    -1,   269,   271,   272,    -1,   570,    -1,   567,   570,
      -1,    88,    20,    -1,   145,   569,   175,    -1,    20,    -1,
     569,    20,    -1,   189,   568,    -1,   126,   568,    -1,   254,
      20,    -1,   226,   274,    -1,   269,   274,    -1,    88,   206,
      -1,    88,   246,    -1,   245,   247,    -1,   238,    -1,   238,
      47,    -1,   237,    -1,   237,   272,    -1,   259,    -1,   248,
     445,    -1,    88,   119,   445,    -1,    88,    43,   445,    -1,
     249,   445,   187,   445,    -1,   244,   575,   580,    -1,   268,
     445,   580,    -1,   257,   575,   265,    -1,   261,   581,    -1,
     243,   581,    -1,   272,    -1,   264,    -1,   258,    -1,   263,
      -1,   258,    -1,   269,   247,   445,    -1
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
     113,   118,   123,   125,   128,   132,   134,   136,   138,   140,
     142,   144,   146,   148,   150,   152,   154,   156,   158,   160,
     162,   164,   166,   168,   170,   172,   178,   182,   186,   192,
     198,   203,   207,   211,   215,   221,   227,   233,   239,   245,
     251,   256,   260,   264,   269,   275,   282,   284,   288,   292,
     296,   300,   307,   313,   322,   326,   333,   339,   348,   353,
     357,   359,   361,   363,   366,   369,   372,   376,   382,   387,
     394,   398,   403,   409,   416,   421,   427,   434,   442,   444,
     447,   449,   451,   453,   455,   457,   459,   462,   465,   475,
     477,   480,   484,   486,   489,   492,   493,   495,   497,   500,
     504,   506,   509,   512,   516,   529,   546,   561,   576,   604,
     607,   610,   611,   613,   615,   616,   618,   620,   624,   628,
     631,   635,   640,   646,   649,   654,   658,   659,   663,   666,
     668,   672,   678,   682,   688,   691,   694,   697,   701,   705,
     707,   710,   713,   716,   721,   726,   731,   736,   738,   742,
     745,   749,   753,   757,   759,   761,   764,   766,   770,   772,
     776,   778,   780,   782,   784,   786,   788,   790,   792,   794,
     796,   798,   800,   802,   804,   806,   808,   810,   813,   816,
     819,   822,   824,   826,   829,   834,   838,   844,   849,   853,
     855,   857,   859,   861,   863,   865,   867,   869,   871,   874,
     877,   881,   884,   886,   891,   895,   900,   905,   911,   916,
     922,   928,   935,   939,   943,   947,   949,   954,   956,   961,
     965,   970,   975,   981,   986,   992,   994,   997,  1001,  1003,
    1006,  1008,  1015,  1019,  1023,  1025,  1028,  1032,  1034,  1038,
    1041,  1045,  1048,  1052,  1057,  1059,  1063,  1065,  1068,  1070,
    1072,  1074,  1077,  1080,  1083,  1087,  1089,  1091,  1094,  1097,
    1100,  1106,  1112,  1114,  1119,  1123,  1128,  1137,  1148,  1150,
    1153,  1158,  1166,  1175,  1177,  1181,  1183,  1187,  1189,  1193,
    1197,  1201,  1205,  1206,  1211,  1215,  1219,  1223,  1225,  1229,
    1234,  1236,  1240,  1242,  1246,  1250,  1252,  1256,  1260,  1264,
    1268,  1270,  1274,  1278,  1280,  1284,  1288,  1290,  1295,  1297,
    1302,  1304,  1309,  1311,  1316,  1318,  1321,  1323,  1325,  1328,
    1331,  1333,  1335,  1337,  1339,  1341,  1343,  1345,  1347,  1349,
    1351,  1353,  1355,  1360,  1366,  1372,  1379,  1383,  1388,  1390,
    1393,  1397,  1400,  1402,  1405,  1408,  1410,  1412,  1414,  1418,
    1422,  1424,  1426,  1428,  1431,  1433,  1436,  1439,  1441,  1443,
    1445,  1447,  1449,  1451,  1453,  1455,  1457,  1460,  1463,  1465,
    1467,  1469,  1471,  1473,  1475,  1477,  1479,  1481,  1483,  1485,
    1487,  1489,  1491,  1494,  1496,  1499,  1503,  1505,  1507,  1509,
    1511,  1513,  1515,  1517,  1519,  1521,  1523,  1525,  1527,  1529,
    1532,  1535,  1539,  1541,  1546,  1551,  1555,  1560,  1562,  1566,
    1568,  1570,  1572,  1574,  1576,  1581,  1587,  1596,  1606,  1616,
    1627,  1629,  1632,  1634,  1637,  1644,  1645,  1647,  1651,  1655,
    1656,  1658,  1660,  1662,  1665,  1668,  1669,  1671,  1673,  1675,
    1678,  1681,  1683,  1685,  1687,  1689,  1691,  1693,  1695,  1697,
    1699,  1701,  1703,  1705,  1709,  1712,  1716,  1720,  1723,  1725,
    1727,  1729,  1731,  1733,  1735,  1740,  1745,  1751,  1758,  1766,
    1771,  1777,  1784,  1792,  1797,  1802,  1807,  1813,  1820,  1828,
    1830,  1833,  1836,  1838,  1841,  1845,  1847,  1849,  1851,  1853,
    1855,  1859,  1861,  1863,  1865,  1867,  1869,  1871,  1873,  1875,
    1877,  1879,  1883,  1887,  1892,  1897,  1901,  1905,  1909,  1914,
    1919,  1923,  1928,  1935,  1940,  1947,  1951,  1955,  1960,  1967,
    1974,  1979,  1986,  1993,  1998,  2000,  2003,  2005,  2009,  2013,
    2017,  2023,  2031,  2039,  2045,  2051,  2057,  2065,  2073,  2079,
    2085,  2089,  2093,  2099,  2107,  2113,  2121,  2123,  2128,  2132,
    2138,  2140,  2143,  2147,  2155,  2166,  2180,  2182,  2186,  2188,
    2190,  2192,  2194,  2196,  2198,  2200,  2202,  2204,  2206,  2208,
    2210,  2212,  2214,  2216,  2218,  2220,  2222,  2224,  2226,  2228,
    2230,  2232,  2234,  2236,  2238,  2240,  2242,  2244,  2246,  2248,
    2250,  2252,  2254,  2256,  2258,  2260,  2262,  2264,  2266,  2268,
    2270,  2272,  2274,  2276,  2278,  2280,  2282,  2284,  2286,  2288,
    2290,  2292,  2294,  2296,  2298,  2300,  2302,  2304,  2306,  2308,
    2310,  2312,  2314,  2316,  2318,  2320,  2322,  2324,  2326,  2328,
    2330,  2332,  2334,  2336,  2338,  2340,  2342,  2344,  2346,  2348,
    2350,  2352,  2354,  2356,  2358,  2360,  2362,  2364,  2366,  2368,
    2370,  2372,  2374,  2376,  2378,  2380,  2382,  2384,  2386,  2388,
    2390,  2392,  2394,  2396,  2398,  2400,  2402,  2404,  2406,  2408,
    2410,  2412,  2414,  2416,  2418,  2420,  2422,  2424,  2426,  2428,
    2430,  2432,  2434,  2436,  2438,  2440,  2442,  2444,  2446,  2448,
    2450,  2452,  2454,  2456,  2458,  2460,  2462,  2464,  2466,  2468,
    2470,  2472,  2474,  2476,  2478,  2480,  2482,  2484,  2486,  2488,
    2490,  2492,  2494,  2496,  2498,  2500,  2502,  2504,  2506,  2508,
    2510,  2512,  2514,  2516,  2518,  2520,  2522,  2524,  2526,  2528,
    2530,  2532,  2534,  2536,  2538,  2540,  2542,  2544,  2546,  2548,
    2550,  2552,  2554,  2556,  2558,  2560,  2562,  2564,  2566,  2568,
    2570,  2572,  2574,  2576,  2578,  2580,  2582,  2584,  2586,  2588,
    2590,  2592,  2594,  2596,  2598,  2600,  2608,  2613,  2615,  2618,
    2622,  2627,  2629,  2631,  2634,  2637,  2639,  2643,  2645,  2649,
    2651,  2656,  2658,  2661,  2663,  2666,  2670,  2672,  2675,  2677,
    2681,  2683,  2685,  2687,  2689,  2691,  2693,  2695,  2697,  2699,
    2701,  2703,  2705,  2707,  2709,  2711,  2714,  2717,  2720,  2723,
    2726,  2729,  2732,  2735,  2739,  2743,  2749,  2757,  2763,  2771,
    2774,  2776,  2780,  2783,  2788,  2793,  2800,  2805,  2811,  2816,
    2822,  2826,  2828,  2831,  2834,  2838,  2840,  2843,  2846,  2849,
    2852,  2855,  2858,  2861,  2864,  2867,  2869,  2872,  2874,  2877,
    2879,  2882,  2886,  2890,  2895,  2899,  2903,  2907,  2910,  2913,
    2915,  2917,  2919,  2921,  2923
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   948,   948,   949,   959,   964,   970,   975,   981,   986,
     998,  1003,  1013,  1020,  1032,  1038,  1050,  1063,  1069,  1081,
    1092,  1096,  1100,  1112,  1118,  1132,  1138,  1152,  1153,  1154,
    1155,  1161,  1162,  1163,  1164,  1167,  1170,  1173,  1176,  1178,
    1184,  1189,  1198,  1204,  1213,  1222,  1223,  1224,  1225,  1226,
    1227,  1228,  1229,  1230,  1231,  1238,  1239,  1240,  1241,  1242,
    1243,  1244,  1247,  1254,  1255,  1267,  1279,  1284,  1295,  1301,
    1313,  1326,  1337,  1342,  1354,  1359,  1370,  1376,  1382,  1388,
    1407,  1418,  1429,  1436,  1443,  1450,  1463,  1469,  1484,  1488,
    1498,  1505,  1513,  1520,  1528,  1535,  1543,  1550,  1563,  1570,
    1576,  1583,  1589,  1593,  1600,  1611,  1616,  1625,  1634,  1641,
    1651,  1659,  1667,  1675,  1683,  1689,  1697,  1705,  1716,  1722,
    1730,  1734,  1738,  1742,  1746,  1750,  1759,  1763,  1771,  1783,
    1788,  1795,  1802,  1807,  1814,  1821,  1825,  1830,  1838,  1844,
    1853,  1858,  1865,  1872,  1883,  1895,  1907,  1919,  1931,  1954,
    1957,  1961,  1965,  1969,  1976,  1980,  1984,  1995,  2000,  2012,
    2016,  2020,  2024,  2031,  2038,  2064,  2074,  2080,  2086,  2095,
    2105,  2118,  2126,  2133,  2147,  2151,  2158,  2163,  2170,  2178,
    2182,  2186,  2194,  2201,  2210,  2222,  2231,  2244,  2252,  2266,
    2273,  2286,  2294,  2305,  2320,  2324,  2340,  2344,  2353,  2357,
    2374,  2375,  2376,  2377,  2378,  2381,  2382,  2383,  2384,  2385,
    2387,  2388,  2391,  2392,  2393,  2394,  2395,  2402,  2415,  2422,
    2426,  2434,  2438,  2442,  2449,  2453,  2460,  2468,  2479,  2489,
    2490,  2491,  2495,  2495,  2495,  2495,  2495,  2498,  2504,  2513,
    2517,  2527,  2538,  2544,  2558,  2566,  2575,  2585,  2596,  2605,
    2615,  2625,  2641,  2654,  2666,  2678,  2684,  2696,  2702,  2716,
    2725,  2735,  2744,  2757,  2764,  2775,  2776,  2781,  2790,  2794,
    2799,  2803,  2809,  2814,  2822,  2838,  2846,  2853,  2859,  2870,
    2877,  2887,  2897,  2902,  2914,  2920,  2934,  2940,  2952,  2959,
    2966,  2973,  2980,  2987,  2994,  3007,  3011,  3021,  3025,  3035,
    3046,  3053,  3066,  3073,  3085,  3092,  3106,  3113,  3128,  3134,
    3146,  3152,  3166,  3177,  3181,  3192,  3196,  3215,  3219,  3227,
    3235,  3243,  3251,  3251,  3259,  3267,  3275,  3289,  3293,  3300,
    3313,  3317,  3328,  3332,  3336,  3346,  3350,  3354,  3358,  3362,
    3372,  3376,  3381,  3392,  3396,  3400,  3410,  3414,  3426,  3430,
    3442,  3446,  3458,  3462,  3474,  3478,  3490,  3494,  3498,  3502,
    3514,  3518,  3522,  3532,  3536,  3540,  3544,  3548,  3552,  3562,
    3566,  3570,  3580,  3584,  3588,  3592,  3604,  3610,  3622,  3628,
    3642,  3649,  3690,  3694,  3698,  3702,  3714,  3724,  3735,  3740,
    3750,  3754,  3764,  3770,  3776,  3782,  3794,  3800,  3811,  3815,
    3819,  3823,  3827,  3831,  3835,  3845,  3849,  3859,  3863,  3874,
    3878,  3882,  3886,  3890,  3905,  3909,  3919,  3923,  3933,  3940,
    3947,  3960,  3964,  3976,  3982,  3996,  4007,  4011,  4015,  4019,
    4023,  4027,  4031,  4035,  4045,  4049,  4059,  4064,  4069,  4080,
    4091,  4095,  4106,  4116,  4127,  4183,  4189,  4201,  4207,  4219,
    4223,  4233,  4237,  4241,  4251,  4259,  4267,  4275,  4283,  4291,
    4306,  4312,  4324,  4330,  4343,  4352,  4354,  4360,  4365,  4377,
    4380,  4387,  4393,  4399,  4407,  4422,  4425,  4432,  4438,  4444,
    4452,  4466,  4471,  4482,  4487,  4498,  4503,  4508,  4514,  4526,
    4532,  4537,  4542,  4553,  4558,  4573,  4578,  4595,  4610,  4614,
    4618,  4622,  4626,  4630,  4640,  4651,  4657,  4663,  4668,  4690,
    4696,  4702,  4707,  4718,  4728,  4738,  4744,  4750,  4755,  4766,
    4772,  4784,  4795,  4801,  4807,  4844,  4849,  4854,  4865,  4869,
    4873,  4883,  4894,  4898,  4902,  4906,  4910,  4914,  4918,  4922,
    4926,  4936,  4946,  4950,  4955,  4966,  4976,  4986,  4990,  4994,
    5004,  5010,  5016,  5022,  5028,  5040,  5051,  5058,  5065,  5072,
    5079,  5086,  5093,  5106,  5127,  5134,  5154,  5194,  5198,  5202,
    5211,  5217,  5223,  5229,  5235,  5242,  5248,  5254,  5260,  5266,
    5278,  5283,  5293,  5299,  5311,  5337,  5348,  5354,  5367,  5383,
    5390,  5396,  5407,  5414,  5424,  5435,  5451,  5457,  5467,  5476,
    5477,  5495,  5499,  5506,  5507,  5508,  5509,  5510,  5511,  5512,
    5513,  5514,  5515,  5516,  5517,  5518,  5519,  5520,  5521,  5522,
    5523,  5524,  5525,  5526,  5527,  5528,  5529,  5530,  5531,  5532,
    5533,  5534,  5535,  5536,  5537,  5538,  5539,  5540,  5541,  5542,
    5543,  5544,  5545,  5546,  5547,  5548,  5549,  5550,  5551,  5552,
    5553,  5554,  5555,  5556,  5557,  5558,  5559,  5560,  5561,  5562,
    5563,  5564,  5565,  5566,  5567,  5568,  5569,  5570,  5571,  5572,
    5573,  5574,  5575,  5576,  5577,  5578,  5579,  5580,  5581,  5582,
    5583,  5584,  5585,  5586,  5587,  5588,  5589,  5590,  5591,  5592,
    5593,  5594,  5595,  5596,  5597,  5598,  5599,  5600,  5601,  5602,
    5603,  5604,  5605,  5606,  5607,  5608,  5609,  5610,  5611,  5612,
    5613,  5614,  5615,  5616,  5617,  5618,  5619,  5620,  5621,  5622,
    5623,  5624,  5625,  5626,  5627,  5628,  5629,  5630,  5631,  5632,
    5633,  5634,  5635,  5636,  5637,  5638,  5639,  5640,  5641,  5642,
    5643,  5644,  5645,  5646,  5647,  5648,  5649,  5650,  5651,  5652,
    5653,  5654,  5655,  5656,  5657,  5658,  5659,  5660,  5661,  5662,
    5663,  5664,  5665,  5666,  5667,  5668,  5669,  5670,  5671,  5672,
    5673,  5674,  5675,  5676,  5677,  5678,  5679,  5680,  5681,  5682,
    5683,  5684,  5685,  5686,  5687,  5688,  5689,  5690,  5691,  5692,
    5694,  5695,  5696,  5697,  5698,  5699,  5700,  5701,  5702,  5703,
    5704,  5705,  5706,  5707,  5708,  5719,  5725,  5742,  5746,  5750,
    5754,  5764,  5767,  5770,  5773,  5782,  5785,  5794,  5797,  5806,
    5809,  5818,  5821,  5830,  5833,  5836,  5845,  5848,  5857,  5861,
    5871,  5874,  5877,  5880,  5883,  5892,  5901,  5905,  5909,  5913,
    5917,  5921,  5925,  5935,  5938,  5941,  5944,  5953,  5956,  5959,
    5962,  5971,  5974,  5983,  5986,  5989,  5992,  5995,  5998,  6001,
    6010,  6013,  6022,  6025,  6028,  6031,  6040,  6043,  6046,  6049,
    6052,  6061,  6064,  6073,  6076,  6085,  6088,  6097,  6100,  6109,
    6118,  6121,  6130,  6133,  6136,  6145,  6148,  6151,  6154,  6157,
    6166,  6170,  6174,  6178,  6188,  6197,  6207,  6216,  6219,  6228,
    6231,  6234,  6243,  6246,  6255
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 10801;
  const int xquery_parser::yynnts_ = 268;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 522;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 315;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 569;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 14354 "/Users/dagraf/work/28msec/software/zorba/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6263 "/Users/dagraf/work/28msec/software/zorba/trunk/src/compiler/parser/xquery_parser.y"


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

