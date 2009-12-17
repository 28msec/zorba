
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
#line 59 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"


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
#line 75 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 924 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_driver.h"
#include "compiler/parser/xquery_scanner.h"
#undef yylex
#define yylex driver.lexer->lex


/* Line 317 of lalr1.cc  */
#line 92 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"

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
#line 161 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
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
#line 808 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 268 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 114: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 277 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 138: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 286 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 317: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 295 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 304 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 313 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 322 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "Prolog" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 331 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 340 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 349 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 358 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 367 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 376 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 820 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->pair_vector); };

/* Line 480 of lalr1.cc  */
#line 385 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 820 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->pair); };

/* Line 480 of lalr1.cc  */
#line 394 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 403 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 412 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 421 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 430 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 439 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 448 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 457 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 466 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 475 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 484 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 493 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 502 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 511 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 520 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 529 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 538 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 547 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 556 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 565 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 820 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 574 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 583 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 592 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "CollPropertyList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 601 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "CollProperty" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 610 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "NodeModifier" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 619 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 628 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "IndexPropertyList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 637 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "IndexProperty" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 646 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 655 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 664 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 673 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 682 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 820 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 691 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 700 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "Block" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 709 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "BlockDecls" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 718 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "BlockVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 727 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "BlockVarDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 736 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "AssignExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 745 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "ExitExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 754 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "WhileExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 763 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 772 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 781 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 790 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "FunctionDecl3" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 799 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "FunctionDecl4" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 808 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 817 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 826 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "EnclosedExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 835 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 844 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 862 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "ApplyExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 871 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "ConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 880 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 889 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 898 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 943 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 952 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 961 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 970 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 979 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 988 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 997 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1006 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "EvalVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1015 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1024 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1033 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1042 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1051 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1060 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "EvalVarDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1069 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1078 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1087 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1096 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1105 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1114 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1123 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1132 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1141 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1150 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1159 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1168 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1177 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1186 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1195 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1204 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1213 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1222 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1231 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1240 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1249 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1258 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1267 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1276 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1285 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1294 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1303 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1312 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1321 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1330 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1339 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1348 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1357 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1366 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1375 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1384 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1393 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1402 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1411 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1420 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "PragmaList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1429 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1438 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1447 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1456 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1465 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1474 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1483 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1492 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1501 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1510 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1519 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1528 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1537 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1546 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1555 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1564 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1573 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1582 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1591 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1600 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1609 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1618 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1627 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1636 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1645 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1654 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1663 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1672 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1681 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1690 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1699 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1708 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1717 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1726 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "Opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1735 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1744 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "Opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1753 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1762 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1771 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1780 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1789 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1798 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1807 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1816 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1825 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1834 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1843 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1852 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1861 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1870 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1879 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1888 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1897 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1906 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1915 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1924 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1933 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1942 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1951 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1960 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1969 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1978 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1987 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1996 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2005 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2014 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2023 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2032 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2041 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2050 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2059 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2068 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2077 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2086 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2095 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2104 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2113 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2122 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2131 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2140 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2149 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 820 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2158 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2167 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "EvalExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2176 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
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
#line 108 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename);
}

/* Line 553 of lalr1.cc  */
#line 2261 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"

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
#line 942 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 952 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		}
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 957 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<MainModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr ((yyval.node));
		}
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 963 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
       driver.set_expr ((yyval.node));
		}
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 968 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
       driver.set_expr ((yyval.node));
		}
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 980 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)), encoding);
		}
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 985 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 995 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)));
		}
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 1002 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)),
                NULL);
		}
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1014 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC ((yyloc)),
                             static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)),
                             NULL);
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1020 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LibraryModule(LOC ((yyloc)),
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1032 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(6) - (3)].sval)),
								SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
      dynamic_cast<ModuleDecl *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
		}
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1045 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)), NULL);
		}
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1049 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		}
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1053 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC((yyloc)),
                      static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
                      static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1065 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = new SIND_DeclList(LOC ((yyloc)));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		}
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1071 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1085 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = new VFO_DeclList(LOC ((yyloc)));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		}
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1091 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1137 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].pair_vector));
      delete (yysemantic_stack_[(4) - (4)].pair_vector);
    }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 1142 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr))->get_qname(), (yysemantic_stack_[(4) - (4)].pair_vector));
      delete (yysemantic_stack_[(4) - (3)].expr);
      delete (yysemantic_stack_[(4) - (4)].pair_vector);
    }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 1151 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.pair_vector) = new std::vector<std::pair<std::string, std::string> > ();
      (yyval.pair_vector)->push_back(*(yysemantic_stack_[(1) - (1)].pair));
      delete (yysemantic_stack_[(1) - (1)].pair);
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 1157 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].pair_vector)->push_back(*(yysemantic_stack_[(2) - (2)].pair));
      delete (yysemantic_stack_[(2) - (2)].pair);
      (yyval.pair_vector) = (yysemantic_stack_[(2) - (1)].pair_vector);
    }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1166 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *s = static_cast<StringLiteral *>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.pair) = new std::pair<std::string, std::string>((yysemantic_stack_[(3) - (1)].strval), s->get_strval());
      delete s;
    }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1174 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1175 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1176 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1177 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1178 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1179 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1180 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1181 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1182 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1183 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1220 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1232 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		}
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1237 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		}
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1248 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_element_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1254 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_function_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1266 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OptionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
								SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
		}
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1279 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (3)].node));
		}
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1290 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		}
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1295 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		}
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1307 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		}
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1312 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		}
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1323 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::inherit_ns);
		}
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1329 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::no_inherit_ns);
		}
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1335 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::inherit_ns);
		}
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1341 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::no_inherit_ns);
		}
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1360 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)));
		}
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1371 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		}
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1382 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		}
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1389 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)),
								NULL);
		}
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 1396 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		}
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 1403 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
		}
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 1416 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = new URILiteralList(LOC ((yyloc)));
			uri_list_p->push_back(SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		}
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1422 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1437 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1441 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		}
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1451 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)), false,
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1458 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1466 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)), false,
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
		}
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1473 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1486 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1493 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->type = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1499 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1506 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(1) - (1)].node));
      d->ext = false;
      (yyval.node) = d;
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1512 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), NULL);
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1516 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1523 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1534 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(), NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1539 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
                               dynamic_cast<SequenceType *> ((yysemantic_stack_[(3) - (3)].node)));
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1548 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1557 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (3)].varnametype)));
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       NULL, true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
		}
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1564 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(6) - (3)].varnametype)));
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       (yysemantic_stack_[(6) - (6)].expr), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
		}
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1574 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1582 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1590 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1598 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1606 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<CollPropertyList*>((yysemantic_stack_[(4) - (2)].node)), 0, 0);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1612 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1620 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1628 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1639 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CollPropertyList* l = new CollPropertyList(LOC((yyloc)));
      l->addProperty(dynamic_cast<CollProperty*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1645 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<CollPropertyList*>((yysemantic_stack_[(2) - (1)].node))->addProperty(static_cast<CollProperty*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1653 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollProperty(LOC((yyloc)), StaticContextConsts::const_);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1657 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollProperty(LOC((yyloc)), StaticContextConsts::append_only);
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1661 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollProperty(LOC((yyloc)), StaticContextConsts::queue);
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1665 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollProperty(LOC((yyloc)), StaticContextConsts::mutable_coll);
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1669 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollProperty(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1673 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollProperty(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1682 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1686 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1694 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                         (yysemantic_stack_[(7) - (5)].expr),
                         dynamic_cast<IndexKeyList*>((yysemantic_stack_[(7) - (7)].node)),
                         new IndexPropertyList(LOC((yyloc))));
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1702 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(8) - (4)].expr)),
                         (yysemantic_stack_[(8) - (6)].expr),
                         dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                         dynamic_cast<IndexPropertyList*>((yysemantic_stack_[(8) - (2)].node)));
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1714 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      IndexPropertyList* l = new IndexPropertyList(LOC((yyloc)));
      l->addProperty(dynamic_cast<IndexProperty*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1720 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexPropertyList*>((yysemantic_stack_[(2) - (1)].node))->addProperty(static_cast<IndexProperty*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1729 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexProperty(LOC((yyloc)), StaticContextConsts::idx_ordered);
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1733 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexProperty(LOC((yyloc)), StaticContextConsts::idx_unordered);
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1737 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexProperty(LOC((yyloc)), StaticContextConsts::idx_unique);
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1741 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexProperty(LOC((yyloc)), StaticContextConsts::idx_non_unique);
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1745 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexProperty(LOC((yyloc)), StaticContextConsts::idx_automatic);
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1749 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexProperty(LOC((yyloc)), StaticContextConsts::idx_manual);
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1757 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1763 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1772 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)),
                            NULL);
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1779 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(4) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (3)].node)),
                            dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1791 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 134:

/* Line 678 of lalr1.cc  */
#line 1803 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                            (yysemantic_stack_[(14) - (2)].intval) & IntegrityConstraintDecl::IC_OPTION_UNCHECKED,
                            (yysemantic_stack_[(14) - (2)].intval) & IntegrityConstraintDecl::IC_OPTION_ASYNCH,
                                    static_cast<QName*>((yysemantic_stack_[(14) - (5)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (8)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1815 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 136:

/* Line 678 of lalr1.cc  */
#line 1827 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 137:

/* Line 678 of lalr1.cc  */
#line 1840 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICForeignKey(LOC((yyloc)),
                            (yysemantic_stack_[(23) - (2)].intval) & IntegrityConstraintDecl::IC_OPTION_UNCHECKED,
                            (yysemantic_stack_[(23) - (2)].intval) & IntegrityConstraintDecl::IC_OPTION_ASYNCH,
                            static_cast<QName*>((yysemantic_stack_[(23) - (5)].expr)),
                            static_cast<QName*>((yysemantic_stack_[(23) - (10)].expr)),
                            static_cast<QName*>((yysemantic_stack_[(23) - (13)].expr)),
                            (yysemantic_stack_[(23) - (15)].expr),
                            static_cast<QName*>((yysemantic_stack_[(23) - (18)].expr)),
                            static_cast<QName*>((yysemantic_stack_[(23) - (21)].expr)),
                            (yysemantic_stack_[(23) - (23)].expr)); 
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1861 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.intval) = (yysemantic_stack_[(2) - (1)].intval) | (yysemantic_stack_[(2) - (2)].intval); }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1864 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.intval) = (yysemantic_stack_[(2) - (1)].intval) | (yysemantic_stack_[(2) - (2)].intval); }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1867 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.intval) = IntegrityConstraintDecl::IC_OPTION_CHECKED; // checked
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1872 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.intval) = IntegrityConstraintDecl::IC_OPTION_CHECKED; // checked
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1876 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.intval) = IntegrityConstraintDecl::IC_OPTION_UNCHECKED;  // unchecked
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1882 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.intval) = IntegrityConstraintDecl::IC_OPTION_SYNCH; // synchronous
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1887 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.intval) = IntegrityConstraintDecl::IC_OPTION_SYNCH; // synchronous
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.intval) = IntegrityConstraintDecl::IC_OPTION_ASYNCH;  // asynchronous
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1902 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		}
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1907 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		}
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1919 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL);
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1923 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1927 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL, dynamic_cast<SequenceType *> ((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1931 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType *> ((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1938 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1945 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 154:

/* Line 678 of lalr1.cc  */
#line 1971 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (1)].node));
      std::auto_ptr<VFO_DeclList> vfo2(dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (2)].node)));
      if ((yysemantic_stack_[(3) - (1)].node) == NULL)
        vfo = new VFO_DeclList (LOC ((yyloc)));
      vfo->push_back (*(vfo2.get()));
      (yyval.node) = vfo;
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1980 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL;
    }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1987 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (1)].node));
      vfo->push_back ((yysemantic_stack_[(3) - (3)].node));
      (yyval.node) = vfo;
    }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 1993 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = new VFO_DeclList (LOC ((yyloc)));
      vfo->push_back ((yysemantic_stack_[(2) - (2)].node));
      (yyval.node) = vfo;
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 2002 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 159:

/* Line 678 of lalr1.cc  */
#line 2012 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 160:

/* Line 678 of lalr1.cc  */
#line 2025 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr (LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr))->get_qname(), (yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (3)].expr);
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 2033 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr (LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 2040 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 163:

/* Line 678 of lalr1.cc  */
#line 2054 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2058 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::CONTINUE);
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 2065 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<FunctionDecl *>((yysemantic_stack_[(2) - (2)].node))->setComment(SYMTAB((yysemantic_stack_[(2) - (1)].sval)));
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 2070 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
      d->deterministic = false;
      (yyval.node) = d;
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 2077 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<FunctionDecl *>((yysemantic_stack_[(3) - (3)].node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 2085 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 2089 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 2093 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(2) - (2)].node));
      d->type = (d->type == ParseConstants::fn_extern)
        ? ParseConstants::fn_extern_update
        : ParseConstants::fn_update;
      (yyval.node) = d;
    }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 2101 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 2108 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								(yysemantic_stack_[(4) - (4)].expr),
								ParseConstants::fn_read);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 2117 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								NULL,
								ParseConstants::fn_extern);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 2129 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								(yysemantic_stack_[(4) - (4)].expr),
								ParseConstants::fn_sequential);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 2138 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								NULL,
								ParseConstants::fn_extern_sequential);
    }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 2151 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = new ParamList(LOC ((yyloc)));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)));
			}
			(yyval.node) = plist_p;
		}
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 2159 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 2173 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(),
								NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
		}
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2180 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
      delete (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2193 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2201 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 2212 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QueryBody(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
		}
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 2227 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 2231 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<BlockBody> blk(dynamic_cast<BlockBody *>((yysemantic_stack_[(2) - (2)].expr)));

      BlockBody* blk2 = new BlockBody(LOC((yyloc)));

      blk2->add((yysemantic_stack_[(2) - (1)].expr));

      for (int i = 0; i < blk->size(); ++i)
        blk2->add((*blk)[i]);

      (yyval.expr) = blk2;
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 2247 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody (LOC ((yyloc)));
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 2251 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = dynamic_cast<BlockBody *>((yysemantic_stack_[(3) - (1)].expr));
      blk->add((yysemantic_stack_[(3) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 2260 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 2264 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 206:

/* Line 678 of lalr1.cc  */
#line 2309 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 207:

/* Line 678 of lalr1.cc  */
#line 2322 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 2329 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 2333 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 2341 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 2345 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 2349 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_only_end;
    }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 2356 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), dynamic_cast<WindowVars *> ((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr), (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 2360 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr), (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 2367 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(5) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window,
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(5) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (4)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 2375 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window,
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 2386 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause (LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 2405 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = new FLWORClauseList (LOC ((yyloc)));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 2411 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = dynamic_cast<FLWORClauseList *> ((yysemantic_stack_[(2) - (1)].node));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 2420 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = NULL;
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 2424 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_ofor;
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 2434 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForClause(LOC ((yyloc)),
                         dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL);
		}
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 2445 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		}
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 2451 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vardecl_list_p) {
				vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 2465 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (1)].expr);
		}
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 2473 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 2482 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 236:

/* Line 678 of lalr1.cc  */
#line 2492 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 237:

/* Line 678 of lalr1.cc  */
#line 2503 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 2512 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 239:

/* Line 678 of lalr1.cc  */
#line 2522 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 240:

/* Line 678 of lalr1.cc  */
#line 2532 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 241:

/* Line 678 of lalr1.cc  */
#line 2548 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
		}
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 2561 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
		}
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 2573 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)));

		}
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2585 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		}
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 2591 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2603 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		}
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 2609 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2623 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
								NULL,
								NULL,
								(yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (1)].expr);
		}
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2632 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2642 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2651 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (1)].expr);
		}
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 2664 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr))->get_qname(),
								NULL, (yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (2)].expr);
		}
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2671 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (2)].expr);
		}
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 2683 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(), "", "");
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 2688 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_curr (static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 2697 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), dynamic_cast<PositionalVar *> ((yysemantic_stack_[(1) - (1)].node)), "", "", "");
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 2701 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_posvar (dynamic_cast<PositionalVar *> ((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2710 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr))->get_qname(), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr))->get_qname());
      delete (yysemantic_stack_[(6) - (3)].expr);
      delete (yysemantic_stack_[(6) - (6)].expr);
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2716 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", "", static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2721 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname(), "");
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2729 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::string name = static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr))->get_qname();
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           name, NULL, NULL,
                           new VarRef (LOC ((yyloc)), name),
                           VarGetsDecl::eval_var);
      delete (yysemantic_stack_[(1) - (1)].expr);

    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2745 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2753 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2760 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = new GroupSpecList(LOC((yyloc)));
      gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl_p;
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      if (gsl_p) {
        gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      }
      (yyval.node) = gsl_p;
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2777 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(),
                 NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2784 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
                 dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2794 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2804 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2809 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)),
								true);
		}
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2821 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		}
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2827 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node));
			if (osl_p) {
				osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2841 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		}
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
                         (yysemantic_stack_[(2) - (1)].expr),
                         dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 2859 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
                               NULL,
                               NULL);
		}
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2866 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               NULL,
                               dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
                               NULL);
		}
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               NULL,
                               NULL,
                               dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2880 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                               dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                               NULL);
		}
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2887 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                               NULL,
                               dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2894 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               NULL,
                               dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                               dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2901 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                               dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                               dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2914 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		}
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2918 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		}
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2928 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC((yyloc)), StaticContextConsts::empty_greatest);
		}
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2932 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC((yyloc)), StaticContextConsts::empty_least);
		}
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2942 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		}
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2953 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 2960 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 2973 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;

		}
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 2980 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 2992 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
								(yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (1)].expr);
		}
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 2999 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 3013 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
								(yysemantic_stack_[(8) - (8)].expr));
		}
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 3020 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(10) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
								static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr))->get_qname(),
								(yysemantic_stack_[(10) - (10)].expr));
      delete (yysemantic_stack_[(10) - (8)].expr);
		}
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 3035 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		}
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 3041 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 3053 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 3059 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr))->get_qname(),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
      delete (yysemantic_stack_[(7) - (3)].expr);
		}
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 3073 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
		}
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3084 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3088 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3099 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3103 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3122 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3126 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3134 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      /*  ::=  "is" | "<<" | ">>" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3142 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3150 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3157 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { /* this call is needed */  driver.lexer->interpretAsLessThan(); }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3158 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3166 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_le),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3174 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3182 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3196 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3200 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		}
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3207 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3220 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3224 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3235 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3239 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3243 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3253 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3257 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3261 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3265 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3269 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3279 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3283 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3288 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3299 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3303 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3307 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3317 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3321 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3333 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3337 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3349 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3353 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3365 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3369 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3381 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3385 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3397 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		}
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3401 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		}
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3405 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3409 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3421 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3425 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3429 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3439 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		}
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3443 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		}
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3447 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		}
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3451 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		}
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3455 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		}
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3459 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		}
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3469 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		}
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3473 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		}
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3477 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		}
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3487 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3491 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3495 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3499 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                            dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(),
                            (yysemantic_stack_[(6) - (5)].expr));
    }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3511 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		}
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3517 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3529 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		}
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3535 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node));
			if (pragma_list_p) {
				pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3549 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));

		}
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3555 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval))),
								"");
    }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3597 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		}
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3601 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3605 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3609 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (rpe == NULL ?
             (yysemantic_stack_[(1) - (1)].expr) :
             new PathExpr(LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3621 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3631 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 377:

/* Line 678 of lalr1.cc  */
#line 3642 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3647 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3657 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3661 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3671 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		}
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3677 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3683 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		}
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3689 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3701 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		}
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3707 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3718 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		}
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3722 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		}
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3726 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		}
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3730 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		}
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3734 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		}
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3738 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		}
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3742 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		}
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3752 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node), false);
		}
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3756 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		}
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseStep(LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node));
		}
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3770 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC((yyloc)), rev_p, NULL);
		}
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3781 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		}
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3785 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		}
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3789 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		}
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3793 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		}
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3797 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		}
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3812 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3816 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3826 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3830 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3840 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        "",
                        ParseConstants::wild_all);
		}
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        ParseConstants::wild_elem);
		}
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3854 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        ParseConstants::wild_prefix);
		}
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3867 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3871 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
                          (yysemantic_stack_[(2) - (1)].expr),
                          dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3883 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		}
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3889 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node));
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3903 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3914 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3918 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3922 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3926 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3930 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3934 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3938 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3942 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3952 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 3956 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 3966 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval));
      delete yylval.decval;
		}
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 3971 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival));
      delete yylval.ival;
		}
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 3976 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval));
      delete yylval.dval;
		}
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 3987 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new VarRef(LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname());
      delete (yysemantic_stack_[(2) - (2)].expr);
		}
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 3998 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		}
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 4002 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 4013 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		}
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 4023 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 4034 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 4090 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)),
								NULL);
		}
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 4096 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 4108 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = new ArgList(LOC ((yyloc)));
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		}
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 4114 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4126 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4130 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4140 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4144 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4148 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4158 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
								NULL,
								NULL,
								NULL);
		}
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4166 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
								NULL,
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)),
								NULL);
		}
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4174 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(8) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr)),
								NULL,
								NULL);
		}
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4182 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
								NULL,
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node)));
		}
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4190 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
								NULL);
		}
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4198 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(10) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)),
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node)));
		}
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4213 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		}
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4219 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4231 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		}
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4237 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4250 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
		}
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4267 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		}
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4272 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		}
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4283 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		}
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4287 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4294 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		}
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4300 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		}
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4306 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4314 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4328 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		}
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4332 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4339 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		}
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4345 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		}
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4351 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4359 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4373 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4378 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4389 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4394 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4405 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		}
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4410 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4415 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		}
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4421 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		}
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4433 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4439 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		}
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4444 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		}
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4449 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4460 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4465 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4480 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4485 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		}
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4502 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CDataSection(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		}
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4517 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4521 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4525 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4529 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4533 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4537 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4547 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4558 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
								NULL);
		}
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4564 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4570 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4575 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4597 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (2)].expr),
								NULL);
		}
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4603 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4609 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4614 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4625 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4635 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4645 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		}
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4651 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4657 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4662 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4673 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		}
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4679 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		}
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4691 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
		}
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4702 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		}
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4708 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4714 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		}
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4751 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		}
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4756 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		}
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4761 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		}
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4772 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4776 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4780 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		}
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4790 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4801 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4805 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4809 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4813 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4817 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4821 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4825 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4829 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4833 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4843 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		}
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4853 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		}
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4857 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4862 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4873 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TextTest(LOC ((yyloc)));
		}
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4883 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		}
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4893 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		}
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4897 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		}
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4901 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		}
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4911 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		}
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4917 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
								NULL);
		}
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4923 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		}
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4929 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		}
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4935 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		}
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4947 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
		}
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4958 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           NULL,
                           NULL,
                           true);
		}
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4965 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                           NULL,
                           true);
		}
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4972 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           false);
		}
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4979 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           true);
		}
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4986 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL,
									true);
		}
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4993 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									false);
		}
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 5000 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									true);
		}
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 5013 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)));
		}
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 5034 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 5041 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)),
								true);
		}
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 5061 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 5101 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::strict_validation);
		}
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 5105 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::lax_validation);
    }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 5109 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::skip_validation);
    }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 5118 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 5124 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 5130 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 5136 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 5142 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 5149 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 5155 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 5161 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 5167 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 5173 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5185 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5190 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5200 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5206 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5218 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5244 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5255 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       CopyVarList* lList = new CopyVarList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
		}
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5261 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
       VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
       lList->push_back(lBinding);
       (yyval.expr) = lList;
		}
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5274 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (1)].expr);
    }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5290 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5297 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5303 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* aCatchListExpr = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if (aCatchListExpr) {
        aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)));
      }
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5314 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(3) - (2)].name_test_list),
                          (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5321 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(7) - (2)].name_test_list),
                          static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr))->get_qname(),
                          (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (5)].expr);
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5331 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 584:

/* Line 678 of lalr1.cc  */
#line 5342 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 585:

/* Line 678 of lalr1.cc  */
#line 5358 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CatchExpr::NameTestList *name_test_list = new CatchExpr::NameTestList;
      name_test_list->push_back (static_cast<NameTest *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.name_test_list) = name_test_list;
    }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5364 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CatchExpr::NameTestList *name_test_list =
        static_cast<CatchExpr::NameTestList *> ((yysemantic_stack_[(3) - (1)].name_test_list));
      name_test_list->push_back (static_cast<NameTest *> ((yysemantic_stack_[(3) - (3)].node)));
      (yyval.name_test_list) = name_test_list;
    }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5384 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 590:

/* Line 678 of lalr1.cc  */
#line 5402 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5406 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5412 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("xquery"); }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5413 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty"); }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5414 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("attribute"); }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5415 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("comment"); }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5416 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document-node"); }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5417 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("element"); }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5418 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("item"); }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5419 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("if"); }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5420 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("node"); }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5421 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("processing-instruction"); }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5422 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-attribute"); }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5423 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-element"); }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5424 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("text"); }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5425 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("typeswitch"); }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5426 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty-sequence"); }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5427 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("boundary-space"); }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5428 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ft-option"); }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5429 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("base-uri"); }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5430 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lax"); }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5431 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strict"); }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5432 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("idiv"); }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5433 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document"); }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5434 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("not"); }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5435 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sensitive"); }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5436 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insensitive"); }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5437 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("diacritics"); }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5438 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("without"); }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5439 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stemming"); }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5440 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("thesaurus"); }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5441 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stop"); }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5442 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("wildcards"); }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5443 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("entire"); }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5444 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("content"); }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5445 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("word"); }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5446 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("start"); }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5447 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("end"); }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5448 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("most"); }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5449 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("skip"); }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5450 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy"); }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5451 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("value"); }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5452 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eq"); }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5453 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ne"); }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5454 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lt"); }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5455 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("le"); }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5456 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("gt"); }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5457 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ge"); }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5458 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("at"); }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5459 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("context"); }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5460 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("variable"); }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5461 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("return"); }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5462 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("for"); }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5463 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("outer"); }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5464 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sliding"); }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5465 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("tumbling"); }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5466 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("previous"); }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5467 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("next"); }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5468 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("only"); }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5469 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("when"); }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5470 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("count"); }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5471 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("in"); }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5472 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("let"); }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5473 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("where"); }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5474 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("by"); }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5475 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("group"); }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5476 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("order"); }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5477 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stable"); }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5478 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ascending"); }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5479 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("descending"); }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5480 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("greatest"); }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5481 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("least"); }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5482 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("collation"); }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5483 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("some"); }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5484 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("every"); }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5485 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("satisfies"); }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5486 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("case"); }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5487 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("as"); }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5488 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("then"); }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5489 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("else"); }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5490 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("or"); }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5491 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("and"); }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5492 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("instance"); }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5493 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("of"); }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5494 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("castable"); }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5495 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("to"); }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5496 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("div"); }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5497 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("mod"); }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5498 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("union"); }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5499 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("intersect"); }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5500 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("except"); }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5501 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("validate"); }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5502 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("cast"); }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5503 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("treat"); }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5504 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("is"); }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5505 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("preserve"); }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5506 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strip"); }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5507 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("namespace"); }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5508 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("external"); }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5509 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("encoding"); }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5510 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-preserve"); }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5511 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("inherit"); }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5512 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-inherit"); }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5513 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("declare"); }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5514 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("construction"); }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5515 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordering"); }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5516 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("default"); }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5517 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy-namespaces"); }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5518 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("option"); }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5519 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("version"); }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5520 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("import"); }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 5521 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema"); }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5522 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("module"); }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 5523 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("function"); }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 5524 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("score"); }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 5525 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ftcontains"); }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 5526 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("weight"); }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 5527 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("window"); }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 5528 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("distance"); }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 5529 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("occurs"); }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 5530 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("times"); }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 5531 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("same"); }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 5532 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("different"); }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 5533 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lowercase"); }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 5534 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("uppercase"); }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 5535 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("relationship"); }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 5536 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("levels"); }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 5537 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("language"); }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 5538 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("any"); }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 5539 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("all"); }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 5540 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("phrase"); }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 5541 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exactly"); }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 5542 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("from"); }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 5543 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("words"); }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 5544 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentences"); }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 5545 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentence"); }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 5546 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("paragraph"); }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 5547 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("replace"); }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 5548 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("modify"); }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 5549 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("first"); }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 5550 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insert"); }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 5551 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("before"); }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 5552 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("after"); }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 5553 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("revalidation"); }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 5554 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("with"); }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 5555 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nodes"); }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 5556 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("rename"); }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 5557 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("last"); }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 5558 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("delete"); }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 5559 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("into"); }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 5560 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("simple"); }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 5561 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sequential"); }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 5562 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("updating"); }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 5563 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("deterministic"); }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 5564 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nondeterministic"); }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 5565 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordered"); }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 5566 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unordered"); }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 5567 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("returning"); }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 5568 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("block"); }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 5569 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exit"); }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 5570 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("loop"); }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 5571 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("while"); }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 5572 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("break"); }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 5573 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("continue"); }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 5574 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("try"); }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 5575 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("catch"); }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 5576 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eval"); }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 5577 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("using"); }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 5578 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("set"); }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 5579 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("index"); }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 5580 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unique"); }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 5581 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("non"); }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 5582 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("on"); }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 5583 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("manual"); }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 5584 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("automatic"); }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 5585 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("decimal-format"); }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 5586 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("decimal-separator"); }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 5587 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("grouping-separator"); }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 5588 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("infinity"); }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 5589 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("minus-sign"); }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 5590 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("NaN"); }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 5591 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("percent"); }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 5592 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("per-mille"); }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 5593 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("zero-digit"); }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 5594 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("digit"); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 5595 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("pattern-separator"); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 5596 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("collection"); }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 5597 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("const"); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 5598 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("append-only"); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 5599 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("queue"); }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 5600 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("mutable"); }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 5601 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("read-only"); }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 5602 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("checked"); }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 5603 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unchecked"); }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 5604 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("asynchronous"); }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 5605 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("synchronous"); }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 5606 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("integrity"); }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 5607 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("constraint"); }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 5608 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("check"); }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 5609 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("key"); }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 5610 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("foreach"); }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 5611 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("type"); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 5612 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("foreign"); }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 5613 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("keys"); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 5625 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)),
                          (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 5631 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 5648 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(1) - (1)].node)), NULL, NULL);
		}
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 5652 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(2) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(2) - (2)].node)), NULL);
		}
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 5656 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(3) - (1)].node)), NULL, static_cast<RangeExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		}
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 5660 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(4) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(4) - (2)].node)), static_cast<RangeExpr *> ((yysemantic_stack_[(4) - (4)].expr)));
		}
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 5670 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 5673 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 5676 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 5679 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 5688 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 5691 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 5700 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 5703 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 5712 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 5715 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 5724 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 5727 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 5736 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 5739 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 5742 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 5751 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 5754 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 5763 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), static_cast<StringLiteral *> ((yysemantic_stack_[(1) - (1)].expr)), NULL);
		}
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 5767 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 5777 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 5780 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 5783 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 5786 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 5789 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 5798 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 5807 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 5811 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 5815 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 5819 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 5823 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 5827 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 5831 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 5841 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 5844 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 5847 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 5850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 5859 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 5862 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 5865 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 5868 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 5877 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 5880 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 5889 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 5892 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 5895 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 5898 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 5901 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 5904 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 5907 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 5916 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 5919 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 5928 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 5931 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 5934 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 5937 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 5946 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 5949 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 5952 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 5955 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 5958 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 5967 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 5970 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 5979 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 5982 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 5991 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 5994 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 6003 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 6006 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 6015 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 6024 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 6027 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 6036 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6039 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6042 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6051 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6054 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6057 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6060 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6063 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 6072 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 6076 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 6080 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 6084 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 6094 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 6103 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWindow (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (2)].expr)), static_cast<FTUnit *> ((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 6113 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 6122 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 6125 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 6134 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 6137 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 6140 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 6149 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 6152 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 6161 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTIgnoreOption (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		}
    break;



/* Line 678 of lalr1.cc  */
#line 10281 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1271;
  const short int
  xquery_parser::yypact_[] =
  {
      1488, -1271, -1271, -1271, -1271,   891,    15,   170,   -16,  8688,
      32,   124,   245, -1271, -1271, -1271, -1271, -1271, -1271,   241,
     110,  7554, -1271,   298, -1271, -1271, -1271, -1271,   377,   405,
   -1271,   285,    76,   483, -1271, -1271, -1271, -1271, -1271, -1271,
   -1271, -1271, -1271,   407,   411, -1271, -1271, -1271, -1271, -1271,
   -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271,
   -1271, -1271, -1271, -1271, -1271, -1271,  8969, -1271,  6980, -1271,
   -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271,
   -1271, -1271, 10655, -1271, -1271, -1271, -1271, -1271, -1271, -1271,
   -1271,   461, -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271,
   -1271, -1271, -1271,  1778, 10655, -1271, -1271, -1271, -1271, -1271,
   -1271,   441, -1271, -1271, -1271, -1271,  8124, -1271,  8407, -1271,
   -1271, -1271, -1271, -1271, 10655, -1271, -1271,  6691, -1271, -1271,
   -1271, -1271, -1271, -1271,   451, -1271, -1271, -1271, -1271, -1271,
   -1271, -1271, -1271,    20,   429, -1271, -1271, -1271, -1271, -1271,
   -1271, -1271, -1271,   322,   464,   396, -1271,   432,   334, -1271,
   -1271, -1271, -1271, -1271, -1271,   556, -1271, -1271,   508,   446,
     437, -1271,   444,   531,   537, -1271,   570, -1271, -1271, -1271,
   -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271,
   -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271,
   -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271,
   -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271,
   -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271,
   -1271, -1271, -1271, -1271, -1271, -1271, -1271,  4379,   681, -1271,
    4668, -1271, -1271,   113,  4957,   505,   507, -1271, -1271, -1271,
   -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271,
   -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271,
   -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271,   -20, -1271,
   -1271, -1271, -1271,   237, 10655, -1271, -1271, -1271, -1271, -1271,
     532,   603, -1271,  1095,   438,   188,   149,   167,   372, -1271,
     624,   506,   600,   602,  5246, -1271, -1271, -1271,    -8, -1271,
   -1271,  6691, -1271,   278, -1271,   565,  6980, -1271,   565,  6980,
   -1271, -1271, -1271, -1271,   565, -1271, -1271, -1271, -1271, -1271,
   -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271,
   -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271,
   -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271,
   -1271, -1271, -1271,   564, -1271, -1271, 10655,   676,   678,   534,
     534,   676, 10655,   300,   -41,   694,   109,   329, 10655,   574,
     606,   321,  8124,   336,   342,   395,    14, 10655, -1271, -1271,
   -1271, -1271, -1271,   439, 10655, -1271, -1271, -1271, -1271, -1271,
   -1271,   287, -1271,   171, -1271,   427,    69,   130, -1271, -1271,
    8124, 10655,  4957,   577,   579,  4957, -1271, -1271, -1271, -1271,
   -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271,
   -1271, -1271, -1271, -1271, -1271, -1271, -1271,  4957,  9250, -1271,
   -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271,
   -1271, -1271, -1271, -1271, -1271,   580,  4957,  4957,   548,  4957,
     549,  4957,    97,   122, -1271,  4957,  7839,   583, -1271, 10655,
   10655, 10655,  4957,   458,   459, -1271,   618,   621, 10655,    28,
    4957,  9531,   591,   587,   595,   596,   597,   598, -1271, -1271,
   -1271, 10655, -1271,   569,   720,  4957,    37, -1271,   734,   575,
   -1271,  4957,   551, -1271,   731,  4957,  4957,   584,  4957,  4957,
    4957,  4957,   535, 10655, -1271, -1271,  4957, -1271, -1271,  4957,
    4957, 10655, -1271, -1271, -1271, -1271,   700,   110, -1271, -1271,
     113,   735,  4957, -1271,  4957,   604,   405,    76,   483,   651,
     607,   609,  4957,  4957, -1271, -1271, -1271, -1271, -1271, -1271,
   -1271,   666, -1271,   -33,  5535,  5535,  5535, -1271,  5535,  5535,
   -1271,  5535, -1271,  5535, -1271, -1271, -1271, -1271, -1271, -1271,
   -1271,  5535,  5535,    10,  5535,  5535,  5535,  5535,  5535,  5535,
    5535,  5535,  5535,  5535,  5535,   553,   689,   690,   691, -1271,
   -1271, -1271,  2067, -1271, -1271,  6691,  6691,  4957,   565, -1271,
   -1271,   565, -1271,   565,  2356,   633, -1271, 10655, -1271, -1271,
   -1271, -1271,   759, -1271, -1271, -1271, -1271, -1271, -1271,   682,
     683, -1271, -1271,   626,   313, 10655,   462,   634,   635,   626,
     694,   669,   665, -1271, -1271, -1271,   267,    67,   343,   768,
   -1271, -1271,   223, -1271, -1271, -1271, -1271, -1271, -1271, -1271,
   -1271,   -30, -1271,   503, -1271, -1271, 10655, -1271, -1271, -1271,
   10655, -1271,   498, -1271, -1271,   670,   649, -1271,   627,  4957,
    4957,   623,   629, -1271,    19,    31,  2645,   630,   636, -1271,
     637, -1271,   631,  8124,   705,   777,  8124,   694,   722,   639,
     638, -1271,   645,  2934,     0, -1271,   158,   680,   715, -1271,
     -32,   659, -1271, -1271, 10655,   -22, -1271,   657,   587,   407,
   -1271,   658,   660,   664, -1271,    40,    42,  3223,     5, -1271,
   10655,   720, -1271,   -45,   667, -1271, -1271, -1271, -1271,   668,
   -1271,    57, -1271, -1271, -1271,   142,   181,   751,   612,   628,
     -23, -1271,   709,  5824, -1271,   671,   672,    66, -1271, -1271,
     674, -1271,   540, -1271, -1271,   -19,   684, 10655,  4957,   737,
   -1271, -1271,   738, 10093,   740,  4957,   741,   -75,   719,   -25,
     603, -1271, -1271, -1271, -1271, -1271,  5535, -1271, -1271, -1271,
    4957,    10,   412, -1271,   576,   816,   608,   610, -1271, -1271,
     599,    95,   149,   149,    -3,   167,   167,   167,   167,   372,
     372, -1271, -1271, 10093, 10093, 10655, 10655, -1271,   687, -1271,
   -1271,   688, -1271, -1271, -1271,    48,    -5,   324,   633, -1271,
     163,   256, -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271,
   -1271, -1271,   626, -1271,   742, 10374,   733,  4957, -1271, -1271,
   -1271,   780,   736,  4957,   694,   694,   626, -1271,   520,   694,
   -1271, -1271,   601, -1271, -1271,   611,    38, -1271, -1271, -1271,
   -1271, -1271, -1271,   613, -1271, -1271,    36,   361,   781,  6402,
     -14,   593, 10655,   694,  4957, -1271,   697,   698,   790,   744,
   10655, -1271, 10655, -1271, -1271,   712, -1271, -1271, -1271,   701,
     766,   694,   743,   767,   803,   694,   753, -1271, -1271, -1271,
     721,   786,  4957,  4957,   761,  4957,   788,  4957,   769,   -72,
   -1271,   238,   653, -1271, -1271,   355,   -22, -1271, -1271, -1271,
     758, 10655, -1271, 10655, -1271, -1271,   739,  4957,   876, -1271,
      -6, -1271,    56, -1271, -1271,   885, -1271,   392,  4957,  4957,
    4957,   409,  4957,  4957,  4957,  4957,  4957,  4957,   796,  4957,
    4957,   606,   -17,   745,   508,   675,   765,   805,   735,   842,
   -1271,  4957, -1271,   402,   817, -1271, 10655,   819, -1271, 10655,
     774,   775, -1271,   264, -1271, -1271, -1271, 10655, -1271, 10655,
    4957,   785,  4957,  4957,   -69,   787, -1271,   750,   749, -1271,
     685, -1271,   -71, -1271,   337,   -39,   686,    10,   337,  5535,
    5535,   945, -1271, -1271, -1271, -1271, -1271, -1271, -1271,    10,
     795,   -39, -1271,   662,   888, -1271, -1271, -1271, -1271, -1271,
     802, -1271, -1271, -1271,  4957, -1271, 10655,   852,    51, -1271,
   -1271,  4957, -1271,   344, -1271, -1271, -1271, -1271, -1271,   919,
     465, -1271, -1271, -1271,  4957, -1271, -1271, -1271, -1271, -1271,
   -1271,   679,    35,   921, -1271,   317, -1271, -1271,   595,   596,
     597,   411,   598,   464, -1271,   728,   732,    36,   791,    36,
     866,  6402,   247,   784,   792, -1271, -1271,  9812,   442, -1271,
    3512,   778,   794,   822,   797,   799, -1271,  4957,   694,   860,
   -1271, -1271, -1271,   694,   860,  3801, -1271, 10655, -1271, -1271,
    4957, -1271, 10655, -1271,  4957,  4957,   833,  4957,   830, -1271,
     857,   861,  4957, 10655,   590,   925, -1271, -1271, -1271,  4090,
     818,   823, -1271, -1271, -1271,   858, -1271,   119, -1271, -1271,
     986, -1271, -1271,  4957, 10655, -1271, -1271,   159, -1271, -1271,
   -1271,   820,   779,   782, -1271, -1271, -1271,   783,   789, -1271,
   -1271, -1271, -1271, -1271,   771, 10655,   826, -1271,   870, -1271,
     606, -1271, -1271, -1271,  7269,   675, -1271,  4957, 10655,   817,
   -1271,   694, -1271,   539, -1271,   229,   905, -1271,  4957,   909,
     737, -1271,   834,   835, -1271, -1271, -1271, -1271, -1271, -1271,
   -1271,  4957, -1271, -1271,  4957,   872,  4957, -1271, -1271,  5535,
   -1271, -1271, -1271, -1271, -1271,    47,  5535,  5535,   271, -1271,
     608, -1271, -1271,  -127,  5535, -1271, -1271,   610,    10,   747,
   -1271, -1271, -1271, -1271,   780, 10093,   903,   928,   843, -1271,
   -1271, -1271, -1271, -1271,    -4,   996,   998,    -4,    -7,    74,
     164, -1271, -1271, -1271,  6402, -1271,    36,   862,  -129,   725,
   -1271, -1271, 10655,   846,     3, -1271, -1271,   850, -1271, -1271,
   -1271, -1271, -1271,   907,   936,   694,   860, -1271,   853, -1271,
   -1271, -1271, -1271, -1271,  4957, -1271,  4957, 10655, 10655, -1271,
     375, -1271,  4957, -1271,   854, -1271, -1271,   876, 10655,   183,
   -1271,   855,   876, 10655, -1271, -1271,  4957,  4957,  4957,  4957,
    4957, -1271,  4957,  4957, -1271, -1271,   202, -1271,   859, -1271,
   -1271, -1271, -1271,   905, -1271, -1271, -1271,   694, -1271, -1271,
   -1271, -1271, -1271, -1271,  4957, -1271,   167,  5535,  5535,   167,
     353, -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271,
   -1271, -1271, 10093, -1271,    35,    35,    -4, -1271, -1271, -1271,
      22,    -4,  1009,   800,   944, -1271,   944, -1271,   935, -1271,
     949, -1271,  6402,   926, 10655,   798,   952,  4957, 10655,  4957,
   -1271,  4957,   694, -1271, -1271, -1271, -1271,   980, -1271, -1271,
   -1271, -1271,   -15,   876, 10655, -1271,   856,   876, -1271, -1271,
   -1271, -1271, -1271, -1271, -1271,   933,  7269, -1271, -1271, -1271,
   -1271, -1271,   167,   167,  5535, -1271, -1271, -1271, -1271, -1271,
   -1271,   -39, -1271,   178, -1271,   187,  6402, 10655,   935, 10655,
     -70,   770, 10093, -1271,   875, -1271, -1271,   860,   940,   281,
     180, -1271,   867,   876, -1271,   869, 10655, -1271,   167,   801,
     944, -1271, -1271, -1271,   402,   831, 10655,   832, 10655,   884,
    4957, 10655, -1271, -1271,   977,   326, -1271, -1271, -1271, -1271,
     892,   417, -1271, -1271, -1271,   879, -1271,   204, -1271, -1271,
   -1271,   793,   772,   957,   865,  4957, -1271, -1271, -1271, -1271,
   -1271, -1271, -1271, -1271, -1271,   961,   931,    36,  6113, 10655,
     964, -1271, 10655, -1271,   804,   807, -1271,   806, 10655,   207,
    4957,  6402,  4957,   808,   965,   931, -1271, -1271, -1271,  6402,
   10655, -1271,   889,   911,   812,   931, 10655, -1271,   877,   982,
   10655,   809,  6402, -1271
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   408,   409,   590,   555,   693,   702,   681,   605,   597,
     613,   604,   595,   703,   742,   741,   743,   744,   740,   599,
     700,   601,   628,   663,   657,   698,   625,   701,   758,   652,
     694,   756,   642,   643,   644,   645,   646,   647,   648,   649,
     650,   695,   609,   603,   596,   697,   672,   602,   607,   765,
     766,   767,   768,   769,   770,   771,   772,   773,   774,   775,
     399,   402,   671,   667,   658,   638,   594,   389,     0,   666,
     674,   682,   387,   662,   425,   639,   640,   696,   388,   391,
     659,   676,     0,   431,   397,   427,   669,   593,   660,   661,
     689,   664,   680,   688,   393,   392,   612,   651,   691,   426,
     679,   684,   598,     0,     0,   346,   677,   687,   692,   690,
     670,   745,   656,   654,   655,   398,     0,   345,     0,   401,
     400,   685,   641,   665,     0,   390,   375,     0,   407,   686,
     668,   675,   683,   678,   746,   632,   637,   636,   635,   634,
     633,   606,   653,     0,   592,   699,   626,   732,   731,   733,
     611,   610,   629,   738,   600,   730,   735,   736,   727,   631,
     673,   729,   739,   737,   728,   630,   734,   747,   748,   749,
     752,   750,   753,   751,   754,   755,   757,   719,   718,   615,
     608,   617,   616,   712,   708,   623,   627,   624,   721,   722,
     705,   614,   717,   716,   713,   709,   726,   720,   715,   711,
     704,   725,   724,   710,   714,   706,   707,   618,   619,   621,
     723,   620,   622,   776,   777,   778,   779,   780,   781,   760,
     761,   759,   763,   764,   762,   782,   783,   784,   785,   786,
     787,   788,   789,   790,   791,   792,   793,     0,     0,     2,
       0,     4,     6,    12,     0,     0,     0,    18,    20,    34,
      22,    23,    24,    50,    25,    29,    30,    54,    55,    56,
      51,    52,    58,    59,    27,    26,    31,    32,    33,    53,
     205,   204,   201,   202,   203,    28,    11,   182,   183,   187,
     189,   220,   226,     0,     0,   218,   219,   190,   191,   192,
     193,   302,   304,   306,   316,   319,   321,   324,   329,   332,
     335,   337,   339,   341,     0,   343,   349,   351,     0,   367,
     350,   371,   374,   376,   379,   381,     0,   386,   383,     0,
     394,   404,   406,   380,   410,   415,   423,   416,   417,   418,
     421,   422,   419,   420,   438,   440,   441,   442,   439,   487,
     488,   489,   490,   491,   492,   403,   529,   521,   528,   527,
     526,   523,   525,   522,   524,   424,    57,   194,   195,   197,
     196,   198,   199,   405,   591,   200,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   115,   116,     0,     0,     0,   111,   112,
     113,   114,   125,     0,     0,   128,   127,   141,   142,   145,
     144,     0,   109,     0,   121,     0,   143,   140,   165,   168,
       0,     0,     0,     0,     0,     0,   693,   702,   681,   605,
     597,   613,   604,   595,   599,   700,   601,   663,   758,   652,
     756,   642,   643,   603,   596,   594,   664,     0,     0,   745,
     746,   592,   738,   600,   730,   736,   727,   630,   748,   749,
     752,   753,   751,   754,   757,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   588,     0,     0,     0,   589,     0,
       0,     0,     0,     0,     0,   228,     0,     0,     0,     0,
       0,     0,     0,   597,   604,   595,   601,   594,   395,   405,
     428,     0,   429,     0,   454,     0,     0,   370,     0,     0,
     373,     0,     0,   483,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   155,   152,     0,   163,   164,     0,
       0,     0,     3,     1,     5,     7,   140,     0,    13,    10,
      15,    16,     0,   185,   184,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   206,   225,   221,   227,   222,   224,
     223,   230,   231,     0,     0,     0,     0,   360,     0,     0,
     358,     0,   311,     0,   359,   352,   357,   356,   355,   354,
     353,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   348,
     347,   344,     0,   368,   372,     0,     0,     0,   382,   412,
     385,   384,   396,   411,     0,     0,   170,     0,   171,   167,
     166,   169,     0,   146,   147,    67,    68,   587,    76,     0,
       0,    61,    62,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   556,   557,   558,     0,     0,     0,     0,
     832,   833,     0,    66,   825,   826,   827,   828,   829,   830,
     831,   101,   126,     0,   115,   116,     0,   110,   123,   124,
       0,   122,     0,   138,   139,     0,     0,   553,     0,     0,
       0,     0,     0,   545,     0,     0,     0,     0,     0,   534,
       0,   535,     0,     0,    85,     0,     0,     0,    77,     0,
       0,   536,     0,     0,     0,   291,     0,     0,   243,   244,
       0,     0,   208,   209,     0,     0,   229,     0,     0,     0,
     531,     0,     0,     0,   539,     0,     0,     0,     0,   430,
     455,   454,   451,     0,     0,   485,   484,   369,   544,     0,
     482,     0,   569,   570,   530,     0,     0,     0,     0,     0,
       0,   575,     0,     0,   161,     0,     0,     0,   246,   263,
       0,    19,   140,    21,   188,     0,     0,     0,     0,     0,
     207,   264,     0,     0,     0,     0,     0,     0,     0,     0,
     303,   305,   309,   315,   314,   313,     0,   310,   307,   308,
       0,     0,     0,   817,   317,   796,   804,   806,   808,   810,
     812,   815,   323,   322,   320,   326,   327,   328,   325,   330,
     331,   334,   333,     0,     0,     0,     0,   365,     0,   377,
     378,     0,   413,   434,   436,     0,     0,     0,     0,    65,
       0,     0,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    36,    37,     0,     0,    93,     0,    89,    91,
      92,    96,    99,     0,     0,     0,    35,    75,     0,     0,
     834,   835,     0,   836,   840,     0,     0,   869,   838,   839,
     868,   837,   841,     0,   848,   870,     0,     0,   102,     0,
     105,     0,     0,     0,     0,   361,     0,     0,     0,     0,
       0,   549,     0,   546,   494,     0,   493,   502,   503,     0,
       0,     0,     0,     0,    78,     0,     0,   538,   537,   504,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     795,     0,     0,   210,   211,     0,   216,   552,   532,   533,
       0,     0,   542,     0,   540,   498,     0,     0,   454,   452,
       0,   443,     0,   432,   433,     0,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   693,     0,     0,     0,     0,     0,     0,    17,     0,
     186,     0,   217,   275,   271,   273,     0,   265,   266,     0,
     598,   606,   510,   511,   517,   518,   520,     0,   233,     0,
       0,     0,     0,     0,     0,     0,   312,     0,     0,   811,
       0,   318,     0,   824,     0,     0,     0,     0,     0,     0,
       0,   797,   801,   819,   800,   823,   821,   820,   822,     0,
       0,     0,   813,   876,   874,   878,   816,   336,   338,   340,
     508,   342,   366,   414,     0,   435,     0,   148,     0,   176,
     173,     0,   172,     0,    73,    74,    71,    72,    38,     0,
       0,    94,    95,    97,     0,    98,    63,    64,    69,    70,
      60,     0,     0,     0,   843,     0,   842,   859,     0,     0,
       0,     0,     0,     0,   103,     0,     0,     0,     0,     0,
     106,     0,     0,     0,     0,   363,   362,     0,     0,   297,
       0,     0,     0,   553,     0,     0,   495,     0,     0,    87,
      81,    84,    83,     0,    79,     0,   505,     0,   289,   293,
       0,   160,     0,   248,     0,     0,     0,     0,     0,   212,
       0,     0,     0,     0,   257,     0,   254,   259,   215,     0,
       0,     0,   499,   290,   455,     0,   444,     0,   478,   475,
       0,   479,   480,     0,     0,   481,   474,     0,   449,   477,
     476,     0,     0,     0,   562,   563,   559,     0,     0,   567,
     568,   564,   573,   571,     0,     0,     0,   577,   158,   157,
       0,   154,   153,   162,     0,   578,   579,     0,     0,   272,
     284,     0,   285,     0,   276,   277,   278,   279,     0,   268,
       0,   232,     0,     0,   514,   516,   515,   512,   241,   242,
     235,     0,   237,   234,     0,     0,     0,   818,   814,     0,
     871,   872,   892,   891,   887,     0,     0,     0,     0,   873,
     805,   886,   798,     0,     0,   803,   802,   807,     0,     0,
     877,   875,   509,   437,   178,     0,     0,   149,     0,   175,
     174,    39,    90,   100,   857,     0,     0,   855,   851,     0,
       0,   118,   117,   104,     0,   107,     0,     0,     0,     0,
      14,   364,     0,     0,     0,   298,   496,     0,   550,   551,
     554,   547,   548,     0,    86,     0,    80,   506,     0,   292,
     294,   245,   250,   249,     0,   252,     0,     0,     0,   214,
     255,   258,     0,   500,     0,   543,   541,   454,     0,     0,
     486,     0,   454,     0,   450,     9,     0,     0,     0,     0,
       0,   576,     0,     0,   156,   585,     0,   580,     0,   247,
     288,   286,   287,   280,   281,   282,   274,     0,   269,   267,
     519,   513,   239,   236,     0,   238,   893,     0,     0,   879,
       0,   890,   889,   888,   883,   884,   799,   809,   885,   179,
     150,   177,     0,   181,     0,     0,   858,   860,   862,   864,
       0,   856,     0,     0,     0,   846,     0,   844,   119,   129,
       0,   108,     0,     0,     0,     0,     0,     0,     0,     0,
     497,     0,     0,    82,   507,   251,   253,   262,   261,   256,
     213,   501,     0,   454,     0,   180,     0,   454,   560,   561,
     565,   566,   572,   574,   159,     0,     0,   581,   794,   283,
     270,   240,   881,   880,     0,   151,   867,   866,   861,   865,
     863,   852,   853,     0,   849,     0,     0,     0,   120,     0,
       0,     0,     0,   299,     0,   295,   301,    88,     0,   464,
     458,   453,     0,   454,   445,     0,     0,   586,   882,     0,
       0,   847,   845,   130,   131,     0,     0,     0,     0,     0,
       0,     0,   472,   466,     0,   465,   467,   473,   470,   460,
       0,   459,   461,   471,   447,     0,   446,     0,   854,   850,
     132,     0,     0,     0,     0,     0,   296,   260,   457,   468,
     469,   456,   462,   463,   448,     0,     0,     0,     0,     0,
       0,   300,     0,   582,     0,   760,   133,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   136,   134,   135,     0,
       0,   583,     0,     0,     0,     0,     0,   584,     0,     0,
       0,     0,     0,   137
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1271, -1271,   868, -1271,   863,   871, -1271,   847, -1271,   566,
     568,  -516, -1271,   466,  -301, -1271, -1271, -1271, -1271, -1271,
   -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271,  -882,
   -1271, -1271, -1271, -1271,    54,   272,   729, -1271, -1271, -1271,
     711,   240, -1271, -1271,   710,  -248,  -300, -1271, -1271,   708,
     713, -1271,   299, -1271,  -880, -1271, -1271,   -42, -1271, -1271,
   -1271, -1271, -1271,   283,   -53, -1271, -1271,  -106, -1271, -1270,
     878,   -89, -1271,   589,  -422, -1271, -1271, -1271, -1271,   205,
   -1271, -1271,   841, -1271, -1271, -1271, -1271, -1271,   157,  -526,
    -671, -1271, -1271, -1271,    25, -1271, -1271,  -152,    16,   -36,
   -1271, -1271, -1271,   -51, -1271, -1271,   172,   -44,  -309, -1271,
     -38, -1124, -1271,   647,    39, -1271, -1271,    61, -1271, -1271,
     586,   588, -1271,  -524,  -966,   571,    85,  -570,    80,    86,
   -1271, -1271, -1271, -1271, -1271,   837, -1271, -1271, -1271, -1271,
   -1271,   836,  -867, -1271,  -104, -1271, -1271, -1271, -1271, -1271,
   -1271, -1271,   -43, -1136, -1271, -1271,   102,    -2, -1271,  -562,
   -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271, -1271,  -906,
   -1271,    18, -1271,   421,  -720, -1271, -1271, -1271, -1271, -1271,
    -313,  -306, -1094,  -954, -1271, -1271, -1271, -1271, -1271, -1271,
   -1271, -1271, -1271, -1271,  -803,  -678,  -787, -1271,   315,  -786,
    -758, -1271, -1271, -1271, -1271, -1271, -1271, -1271,   673,   677,
    -473,   269,   114, -1271, -1271, -1271, -1271, -1271, -1271, -1271,
      -1, -1271, -1271,    12, -1271,  -371,   -95,    -9, -1271, -1271,
     376, -1271, -1271,   161,   151,   -57,   380, -1271, -1271,   162,
   -1271,  -754, -1271, -1271, -1271, -1271,  -192,  -850, -1271,   -54,
    -673, -1271,  -743, -1271, -1271, -1271, -1271,  -987, -1271, -1271,
   -1271, -1271,   -48,   186, -1271
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   832,   833,   834,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,  1089,
     687,   263,   264,   838,   839,   840,  1158,   265,   266,   401,
     402,   868,   267,   403,   404,  1358,  1359,   268,   405,   406,
     407,   269,   817,   270,   515,   743,   952,  1159,   271,   272,
     273,   274,   275,   408,   409,   608,  1028,  1029,  1135,  1032,
     276,   277,   534,   278,   279,   280,   544,   476,   915,   916,
     281,   545,   282,   547,   283,   284,   285,   551,   552,  1114,
     768,   286,   698,   747,   699,   705,  1115,  1116,  1117,   748,
     548,   549,   967,   968,  1318,   550,   964,   965,  1174,  1175,
    1176,  1177,   287,   694,   695,   288,  1078,  1079,   289,   290,
     291,   292,   776,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   571,   572,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   323,   598,   599,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   815,   333,   334,
     335,  1137,   721,   722,   723,  1431,  1460,  1461,  1454,  1455,
    1462,  1456,  1138,  1139,   336,   337,  1140,   338,   339,   340,
     341,   342,   343,   344,  1019,   769,   972,  1187,   973,   974,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     666,  1082,   355,   356,   357,   358,   359,   360,   361,   740,
     741,   362,  1165,  1166,  1306,  1090,   467,   363,   364,   365,
     784,  1001,   785,   786,   787,   788,   789,   790,   791,  1002,
    1003,   643,   644,   645,   646,   647,  1413,  1414,   648,  1346,
    1237,  1350,  1347,   649,   650,  1005,  1016,  1208,  1006,  1007,
    1012,  1008,  1334,  1204,   991
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int xquery_parser::yytable_ninf_ = -141;
  const short int
  xquery_parser::yytable_[] =
  {
       455,   930,  1068,  1021,   618,   975,  1056,   795,   796,   797,
     798,   783,   468,  1094,   493,   753,  1017,  1018,   904,  1020,
    1020,   496,   909,   500,  1219,   488,  1136,   767,  1305,   908,
       4,  1004,   772,  1212,   773,   774,  1397,   775,   912,   777,
    1446,   502,  1409,  1294,   725,   975,   975,   778,   779,  1205,
     701,  1314,  1315,   763,   763,   764,   866,   482,   708,   489,
    1105,   980,   581,   764,  1128,  1129,   708,  1194,  1058,  1059,
    1429,   582,  1069,   490,  1163,   931,   948,   975,  1060,   532,
     532,  1205,  1160,   732,   733,  1363,   735,   736,   737,   738,
    1327,   684,   688,   709,   744,   494,   981,   745,   985,   901,
     907,   709,  1061,   765,   901,  1026,   636,   468,  1064,   498,
     754,   983,    74,  1368,  1126,   499,   615,   617,   880,   956,
     760,   761,  1344,  1235,    85,  1062,  1053,  1128,  1129,   415,
     882,  1331,   473,   474,   592,  1200,   462,  1332,   526,   921,
     932,   923,   617,  1054,   574,  1333,  1364,  1024,    99,   616,
    1226,  1130,   780,  1230,   527,   781,  1430,   118,   463,   533,
     960,   575,  1161,  1043,   410,   957,  1328,  1128,  1129,  1131,
    1027,  1132,   852,  1354,   456,  1201,   902,  1369,   935,  1127,
    1236,   927,   814,  1055,   913,  1345,   475,   766,  1128,  1399,
     766,  1128,  1129,   766,   881,  1294,   867,  1410,  1133,  1458,
     726,   949,   104,   710,  1247,  1240,   883,   594,  1125,  1206,
    1207,  1266,   867,   124,  1130,   922,  1493,   924,   116,   783,
     783,  1136,   503,  1025,   914,  1447,  1227,   685,   937,   766,
     766,  1136,  1131,  1108,  1132,  1511,   936,   766,  1106,  1134,
     637,  1206,  1207,   984,   763,  1517,   683,  1216,  1336,  1355,
    1063,  1353,   986,  1352,  1130,   638,   411,   143,   577,   847,
    1437,  1133,   782,  1356,   619,   104,   457,   941,   639,   458,
     640,   686,  1131,   600,  1132,   553,   602,  1440,  1130,   620,
     641,   116,   535,   642,   578,  1452,  1440,   632,   536,  1128,
    1253,   537,   538,  1131,   903,  1132,  1131,   579,  1132,   539,
    1034,  1133,  1288,  1485,  1459,   104,  1504,   489,   853,  1243,
     489,  1245,   412,  1195,   606,   665,   894,  1035,   611,   975,
     143,   116,  1133,   668,   763,  1133,   671,  1171,   658,   104,
    1452,   580,  1013,  1014,  1128,   574,   963,   854,   855,  1357,
     856,   857,  1293,   978,  1031,   116,  1173,  1395,   672,   938,
     939,   627,   575,  1441,  1015,   628,   581,   605,   399,   400,
     143,   659,  1442,   612,   940,   582,  1384,   677,   678,   623,
     680,   692,   682,   468,  1107,   576,   689,  1360,   651,  1486,
     413,   414,  1505,  1136,   143,   653,   461,   459,   942,   943,
     460,   713,   629,  1036,  1131,   540,  1132,   541,  1184,   835,
    1396,   468,   667,   944,  1453,  1053,   724,  1081,   469,  1084,
    1037,   542,   729,  1110,  1111,  1042,  1112,   397,   398,   630,
     601,  1045,  1239,  1133,  1439,  1128,   603,   472,  1185,   675,
    1213,   746,     4,  1110,  1111,   783,  1458,   543,  1340,  1131,
     836,  1132,   753,   764,   654,   837,  1186,   783,  1120,  1479,
    1121,  1030,   392,   393,   660,   395,   396,   468,   595,   596,
     696,   697,   700,   764,   861,  1113,  1031,   975,  1133,   707,
     613,  1229,   716,  1046,  1047,  1457,  1463,   655,  1050,   631,
    1098,  1099,   696,  1101,   614,  1103,   514,   470,  1361,  1170,
    1427,   809,   810,   862,   863,  1360,   864,   865,   583,   621,
    1171,  1457,  1073,   808,   742,  1123,   850,  1463,   811,   851,
    1172,   584,   749,   622,    74,   471,  1144,  1145,  1146,  1173,
    1149,  1150,  1151,  1152,  1153,  1154,    85,  1156,  1157,  1331,
    1131,  1038,  1132,  1248,  1077,  1332,   505,   477,   506,   963,
    1404,  1482,   581,  1333,  1249,  1038,  1339,  1254,   511,  1360,
      99,   582,   478,   512,   780,  1405,   479,   781,  1190,  1133,
    1192,  1193,   656,   388,   389,   390,   391,  1382,   366,   367,
     368,   491,  1386,   371,   366,   367,   368,   369,   370,   371,
     876,   877,   858,   495,   975,   859,   372,   885,   890,   842,
    1469,   893,   836,   501,   843,  1202,   812,   837,   818,   812,
    1203,   812,  1223,  1408,   900,   633,   634,   635,  1408,   507,
     508,   378,   509,  1142,  1444,  1143,   841,  -123,  -123,  -123,
    -123,  -123,  1233,  -124,  -124,  -124,  -124,  -124,   926,  1326,
    1147,  1020,  1148,   504,  1507,  1449,  1329,  1330,  1048,  1049,
    1065,  1066,  1512,   379,   380,   959,   510,   870,  1110,  1111,
     514,   871,   609,   610,   953,  1523,   783,  1311,  1312,   792,
     793,   799,   800,  1432,   975,  1263,   513,  1435,   517,   801,
     802,  1406,  1407,   516,   468,   518,   519,   468,  1270,   520,
     521,   523,  1272,  1273,   530,  1275,   531,   555,   554,   573,
    1279,   987,   585,   587,   586,   911,   588,   383,   822,   823,
     824,   825,   826,   827,   828,   829,   830,   831,   597,   604,
     366,   928,   607,  1465,   617,   624,   625,  1264,   662,   669,
     652,   670,   676,   679,   681,   693,   702,   703,   704,  1494,
     384,   706,   438,   717,   366,   367,   368,   369,   370,   371,
     458,   460,   466,   481,   719,  1308,   372,   720,   962,   727,
     728,   731,   373,   730,   976,   739,   963,  1402,  1403,   734,
     752,   757,   756,   374,   375,   762,   758,   376,   759,  1322,
     377,   378,  1323,   803,  1325,   804,   805,   806,   816,   819,
     386,   820,   821,   844,   845,  1074,   848,   849,   860,   869,
     872,   874,   873,   891,   976,   976,   976,   976,   878,   875,
    1310,   879,   886,   379,   380,   381,   889,   892,   887,   888,
     895,   896,   905,   897,   906,   387,   388,   389,   390,   391,
     898,   392,   393,   394,   395,   396,   976,   397,   398,   399,
     400,   910,   917,   918,  1438,   919,   920,   945,   946,   933,
     934,   950,   947,   961,   955,   990,   954,   966,   969,   382,
     977,   979,  1375,   958,  1376,   982,  1011,   383,  1009,  1022,
    1380,  1023,  1010,  1072,  1039,   837,   763,  1067,  1044,  1075,
    1076,  1083,  1051,  1083,  1388,  1389,  1390,  1391,  1392,  1071,
    1393,  1394,  1077,  1052,  1086,  1057,  1080,  1087,  1088,  1092,
     384,  1093,  1091,  1096,  1373,  1095,  1097,  1100,  1102,  1109,
    1119,  1104,  1401,  1124,   992,  1141,  1155,  1167,   636,   385,
    1164,  1122,   667,   629,   667,  1168,  1178,  1162,  1180,  1182,
    1183,  1191,  1197,  1196,  1198,   366,   367,   368,   369,   370,
     371,  1218,  1199,  1209,  1220,  1221,  1222,   372,  1225,     4,
     386,  1238,  1228,   373,  1241,  1423,  1400,  1425,  1242,  1426,
    1244,  1234,  1246,  1258,   374,   375,  1260,  1179,   376,  1265,
     553,   377,   378,  1250,  1251,  1274,  1276,  1277,  1188,  1259,
    1189,  1278,  1261,   993,  1262,   387,   388,   389,   390,   391,
    1287,   392,   393,   394,   395,   396,  1282,   397,   398,   399,
     400,  1257,  1290,  1285,   379,   380,   381,  1300,  1286,  1295,
    1302,  1296,  1303,  1171,  1297,  1298,  1268,  1317,  1324,  1320,
    1321,  1299,  1338,  1026,  1342,  1343,  1348,  1224,  1349,  1365,
    1367,  1362,  1370,  1371,  1372,  1374,  1381,  1385,  1476,  1411,
    1284,  1398,  1053,   992,  1416,  1417,  1419,   636,  1422,  1428,
     382,  1434,   637,  1436,  1291,  1448,  1473,  1421,   383,  1450,
    1451,  1471,  1464,  1491,  1466,  1412,  1468,   638,  1475,   994,
     995,   996,  1478,  1481,  1484,  1488,  1496,  1489,   976,   997,
     639,  1492,   640,  1031,  1498,  1510,  1514,   998,  1506,  1490,
    1508,   384,   641,   999,  1000,   642,  1515,  1516,   696,  1487,
     528,  1519,  1520,   700,  1232,   846,   750,  1500,   751,  1502,
     385,  1501,   993,   524,  1280,   522,  1509,  1522,  1041,   626,
    1070,   525,   657,   661,  1418,   664,  1443,  1033,  1304,   663,
    1341,  1118,   529,   755,   546,  1292,  1181,  1271,  1379,  1319,
    1281,   386,  1309,  1169,  1316,  1470,  1269,  1313,   718,  1255,
     770,   591,   929,   771,   593,  1289,   742,   794,  1483,  1480,
    1040,  1085,   711,  1231,  1301,   489,   712,   988,  1210,   749,
    1217,  1337,   989,  1215,  1415,  1335,   387,   388,   389,   390,
     391,   637,   392,   393,   394,   395,   396,  1307,   397,   398,
     399,   400,  -140,  1351,  1211,     0,   638,     0,   994,   995,
     996,     0,     0,     0,     0,     0,     0,     0,     0,   639,
       0,   640,     0,     0,     0,     0,   998,     0,     0,     0,
       0,   641,  1214,  1000,   642,     0,   976,   556,     0,     0,
       0,     0,     0,     0,     0,   557,   558,     0,   559,     0,
       0,     0,     0,     0,     0,   560,     0,     0,     0,   561,
       0,   562,     0,  1366,     0,     0,   563,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   564,     0,     0,     0,     0,     0,  1377,  1378,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1383,
       0,     0,     0,     0,  1387,     0,   565,   566,   567,   568,
     569,   570,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   976,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1420,     0,     0,     0,  1424,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1433,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   489,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   976,     0,
    1445,     0,     0,   976,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1467,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1472,     0,  1474,
       0,     0,  1477,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1497,     0,     0,  1499,     0,     0,     0,     0,     0,  1503,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,  1513,     0,     0,     0,     2,     3,  1518,     4,     0,
       0,  1521,     0,     5,     6,     0,     7,     8,     9,    10,
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
       0,   144,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,   416,   417,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,   425,
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
       0,     0,   122,   492,   123,   124,   125,     0,   126,   127,
     128,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   441,   145,     0,   146,   147,   148,   149,   150,   151,
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
       0,     0,   416,   417,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,   425,    21,
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
       0,   117,   118,     0,     0,   119,   120,   121,     0,   807,
       0,   122,     0,   123,   124,   125,     0,   126,   127,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     441,   145,     0,   146,   147,   148,   149,   150,   151,   152,
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
       0,   416,   417,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,   425,    21,    22,
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
     122,   813,   123,   124,   125,     0,   126,   127,   128,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   441,
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
     416,   417,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,   425,    21,    22,    23,
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
     118,     0,     0,   119,   120,   121,     0,   884,     0,   122,
       0,   123,   124,   125,     0,   126,   127,   128,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,   143,     0,   441,   145,
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
       0,     2,     3,     0,     4,     0,     0,     0,     0,   416,
     417,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,   425,    21,    22,    23,    24,
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
       0,     0,   119,   120,   121,     0,   899,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   441,   145,     0,
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
       2,     3,     0,     4,     0,     0,     0,     0,   416,   417,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,   425,    21,    22,    23,    24,    25,
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
       0,   119,   120,   121,     0,   925,     0,   122,     0,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   441,   145,     0,   146,
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
       3,     0,     4,     0,     0,     0,     0,   416,   417,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,   425,    21,    22,    23,    24,    25,    26,
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
     119,   120,   121,     0,  1256,     0,   122,     0,   123,   124,
     125,     0,   126,   127,   128,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   441,   145,     0,   146,   147,
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
       0,     4,     0,     0,     0,     0,   416,   417,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,   425,    21,    22,    23,    24,    25,    26,    27,
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
     120,   121,     0,  1267,     0,   122,     0,   123,   124,   125,
       0,   126,   127,   128,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   441,   145,     0,   146,   147,   148,
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
       4,     0,     0,     0,     0,   416,   417,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,   425,    21,    22,    23,    24,    25,    26,    27,     0,
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
     121,     0,  1283,     0,   122,     0,   123,   124,   125,     0,
     126,   127,   128,     0,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,   143,     0,   441,   145,     0,   146,   147,   148,   149,
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
       0,     0,     0,     0,     5,     6,     0,     7,     8,     9,
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
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,     0,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,     1,     0,
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
       0,   441,   145,     0,   146,   147,   148,   149,   150,   151,
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
       0,     0,   416,   417,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,   425,    21,
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
     441,   145,     0,   146,   147,   148,   149,   150,   151,   152,
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
       0,   416,   417,     0,     7,   419,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,   424,   425,    21,    22,
     427,    24,    25,    26,    27,     0,   428,   429,    30,   430,
     431,   432,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,    72,    73,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   436,    92,    93,    94,    95,     0,     0,     0,     0,
       0,    96,    97,    98,    99,   100,   101,   102,     0,     0,
       0,   103,   104,   589,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   112,   113,   114,   115,   116,     0,
     590,   118,     0,     0,   119,   120,   121,     0,     0,     0,
     122,     0,   123,   124,   125,     0,   126,   127,   128,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   441,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   442,
     154,   444,   156,   445,   446,   159,   160,   161,   162,   163,
     164,   447,   166,   167,   448,   449,   450,   171,   451,   452,
     453,   175,   454,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
     416,   417,     0,     7,   419,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,   424,   425,    21,    22,   427,
      24,    25,    26,    27,     0,   428,   429,    30,   430,   431,
     432,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,     0,    72,    73,     0,     0,     0,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,     0,    85,
       0,    86,    87,    88,    89,     0,    90,     0,     0,     0,
     436,    92,    93,    94,    95,     0,     0,     0,     0,     0,
      96,    97,    98,    99,   100,   101,   102,     0,     0,     0,
     103,   104,   105,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   111,   112,   113,   114,   115,   116,     0,   117,
     118,     0,     0,   119,   120,   121,     0,     0,     0,   122,
       0,   123,   124,   125,     0,   126,   127,   128,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,   143,     0,   441,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   442,   154,
     444,   156,   445,   446,   159,   160,   161,   162,   163,   164,
     447,   166,   167,   448,   449,   450,   171,   451,   452,   453,
     175,   454,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,     0,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,   951,
     417,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,   425,    21,    22,    23,    24,
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
     140,     0,     0,   141,   142,   143,     0,   441,   145,     0,
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
       2,     3,     0,     4,     0,     0,     0,     0,   416,   417,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,   425,    21,    22,    23,    24,    25,
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
       0,     0,   141,   142,   143,     0,   441,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,  1495,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,   416,   417,     0,
     418,   419,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,   424,   425,    21,    22,   427,    24,    25,    26,
      27,     0,   428,   429,    30,   430,   431,   432,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,     0,    72,
      73,     0,     0,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,    85,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   436,    92,    93,
      94,    95,     0,     0,     0,     0,     0,    96,    97,    98,
      99,   100,   101,   102,     0,     0,     0,   103,   104,     0,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   111,
     112,   113,   114,   115,   116,     0,     0,     0,     0,     0,
     119,   120,   121,     0,     0,     0,   122,     0,   123,   124,
     125,     0,   126,   127,   128,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   441,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   442,   154,   444,   156,   445,
     446,   159,   160,   161,   162,   163,   164,   447,   166,   167,
     448,   449,   450,   171,   451,   452,   453,   175,   454,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,   416,   417,     0,   418,
     419,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,   424,   425,    21,    22,   427,    24,    25,    26,    27,
       0,   428,   429,    30,   430,   431,   432,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,     0,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,     0,    72,    73,
       0,     0,     0,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,     0,    85,     0,    86,    87,    88,
      89,     0,    90,     0,     0,     0,   436,    92,    93,    94,
      95,     0,     0,     0,     0,     0,    96,    97,    98,    99,
     100,   101,   102,     0,     0,     0,   103,   104,     0,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   111,   112,
     113,   114,   115,   116,     0,     0,     0,     0,     0,   119,
     120,   121,     0,     0,     0,   122,     0,   123,   124,   125,
       0,     0,     0,   128,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   441,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   442,   154,   444,   156,   445,   446,
     159,   160,   161,   162,   163,   164,   447,   166,   167,   448,
     449,   450,   171,   451,   452,   453,   175,   454,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       0,     0,     0,     0,     0,   416,   417,     0,   418,   419,
     483,   421,   484,   485,    13,    14,    15,    16,    17,    18,
     424,   425,   486,    22,   427,    24,    25,    26,    27,     0,
     428,   429,    30,   430,   431,   432,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    62,     0,    63,    64,    65,   487,
       0,     0,    69,    70,    71,     0,     0,     0,    73,     0,
       0,     0,     0,    75,    76,    77,     0,     0,    80,    81,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,   436,    92,    93,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,     0,   100,
     101,   102,     0,     0,     0,     0,     0,     0,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   439,   112,   113,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,     0,     0,     0,   122,     0,   123,   124,     0,     0,
       0,     0,   128,     0,   129,     0,   130,   131,   132,   133,
     440,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,     0,     0,   441,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   442,   154,   444,   156,   445,   446,   159,
     160,   161,   162,   163,   164,   447,   166,   167,   448,   449,
     450,   171,   451,   452,   453,   175,   454,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     0,
       0,     0,     0,     0,   416,   417,     0,   418,   419,   420,
     421,   422,   423,    13,    14,    15,    16,    17,    18,   424,
     425,   426,    22,   427,    24,    25,    26,    27,     0,   428,
     429,    30,   430,   431,   432,    34,    35,    36,    37,    38,
      39,    40,    41,    42,   433,   434,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,     0,     0,    62,     0,    63,    64,    65,   435,     0,
       0,    69,    70,    71,     0,     0,     0,    73,     0,     0,
       0,     0,    75,    76,    77,     0,     0,    80,    81,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,     0,
      90,     0,     0,     0,   436,    92,    93,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,     0,   100,   101,
     102,     0,     0,     0,     0,     0,     0,   106,   107,     0,
       0,     0,     0,   108,   109,   110,   439,   112,   113,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
       0,     0,     0,   122,     0,   123,     0,     0,     0,     0,
       0,   128,     0,   129,     0,   130,   131,   132,   133,   440,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
       0,     0,   441,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   442,   443,   444,   156,   445,   446,   159,   160,
     161,   162,   163,   164,   447,   166,   167,   448,   449,   450,
     171,   451,   452,   453,   175,   454,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,     0,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   464,     0,
       0,     0,     3,     0,     0,     0,     0,     0,     0,   416,
     417,     0,   418,   419,   420,   421,   422,   423,    13,    14,
      15,    16,    17,    18,   424,   425,   426,    22,   427,    24,
      25,    26,    27,     0,   428,   429,    30,   430,   431,   432,
      34,    35,    36,    37,    38,    39,    40,    41,    42,   433,
     434,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    62,     0,
      63,    64,    65,   435,     0,     0,    69,    70,    71,     0,
       0,     0,    73,     0,     0,     0,     0,    75,    76,    77,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,   436,
      92,    93,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,     0,   100,   101,   102,   465,     0,     0,   466,
       0,     0,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   439,   112,   113,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,   122,     0,
     123,     0,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   440,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,     0,     0,   441,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   442,   443,   444,
     156,   445,   446,   159,   160,   161,   162,   163,   164,   447,
     166,   167,   448,   449,   450,   171,   451,   452,   453,   175,
     454,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   464,     0,     0,     0,     3,     0,   690,
       0,     0,     0,     0,   416,   417,     0,   418,   419,   420,
     421,   422,   423,    13,    14,    15,    16,    17,    18,   424,
     425,   426,    22,   427,    24,    25,    26,    27,     0,   428,
     429,    30,   430,   431,   432,    34,    35,    36,    37,    38,
      39,    40,    41,    42,   433,   434,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,     0,     0,    62,     0,    63,    64,    65,   435,     0,
       0,    69,    70,    71,     0,     0,     0,    73,     0,     0,
       0,     0,    75,    76,    77,     0,     0,    80,    81,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,     0,
      90,     0,     0,     0,   436,    92,    93,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,     0,   100,   101,
     102,     0,     0,     0,     0,     0,     0,   106,   107,     0,
       0,     0,     0,   108,   109,   110,   439,   112,   113,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
       0,     0,     0,   122,   691,   123,     0,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   440,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
       0,     0,   441,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   442,   443,   444,   156,   445,   446,   159,   160,
     161,   162,   163,   164,   447,   166,   167,   448,   449,   450,
     171,   451,   452,   453,   175,   454,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,     0,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   464,     0,
       0,     0,     3,     0,     0,     0,     0,     0,     0,   416,
     417,     0,   418,   419,   420,   421,   422,   423,    13,    14,
      15,    16,    17,    18,   424,   425,   426,    22,   427,    24,
      25,    26,    27,     0,   428,   429,    30,   430,   431,   432,
      34,    35,    36,    37,    38,    39,    40,    41,    42,   433,
     434,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    62,     0,
      63,    64,    65,   435,     0,     0,    69,    70,    71,     0,
       0,     0,    73,     0,     0,     0,     0,    75,    76,    77,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,   436,
      92,    93,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,     0,   100,   101,   102,     0,     0,     0,     0,
       0,     0,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   439,   112,   113,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,   122,     0,
     123,     0,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   440,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,     0,     0,   441,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   442,   443,   444,
     156,   445,   446,   159,   160,   161,   162,   163,   164,   447,
     166,   167,   448,   449,   450,   171,   451,   452,   453,   175,
     454,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   497,     0,     3,     0,     0,     0,     0,
       0,     0,   416,   417,     0,   418,   419,   420,   421,   422,
     423,    13,    14,    15,    16,    17,    18,   424,   425,   426,
      22,   427,    24,    25,    26,    27,     0,   428,   429,    30,
     430,   431,   432,    34,    35,    36,    37,    38,    39,    40,
      41,    42,   433,   434,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,     0,
       0,    62,     0,    63,    64,    65,   435,     0,     0,    69,
      70,    71,     0,     0,     0,    73,     0,     0,     0,     0,
      75,    76,    77,     0,     0,    80,    81,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,     0,    90,     0,
       0,     0,   436,    92,    93,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,     0,   100,   101,   102,     0,
       0,     0,     0,     0,     0,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   439,   112,   113,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,     0,
       0,   122,     0,   123,     0,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   440,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,     0,     0,
     441,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     442,   443,   444,   156,   445,   446,   159,   160,   161,   162,
     163,   164,   447,   166,   167,   448,   449,   450,   171,   451,
     452,   453,   175,   454,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,     3,     0,     0,     0,
       0,     0,     0,   416,   417,     0,   418,   419,   420,   421,
     422,   423,    13,    14,    15,    16,    17,    18,   424,   425,
     426,    22,   427,    24,    25,    26,    27,     0,   428,   429,
      30,   430,   431,   432,    34,    35,    36,    37,    38,    39,
      40,    41,    42,   433,   434,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
       0,     0,    62,     0,    63,    64,    65,   435,     0,     0,
      69,    70,    71,     0,     0,     0,    73,     0,     0,     0,
       0,    75,    76,    77,     0,     0,    80,    81,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,   436,    92,    93,     0,     0,     0,     0,
       0,     0,     0,    96,    97,    98,     0,   100,   101,   102,
     437,     0,     0,   438,     0,     0,   106,   107,     0,     0,
       0,     0,   108,   109,   110,   439,   112,   113,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   121,     0,
       0,     0,   122,     0,   123,     0,     0,     0,     0,     0,
       0,     0,   129,     0,   130,   131,   132,   133,   440,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,     0,
       0,   441,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   442,   443,   444,   156,   445,   446,   159,   160,   161,
     162,   163,   164,   447,   166,   167,   448,   449,   450,   171,
     451,   452,   453,   175,   454,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     3,     0,     0,
       0,     0,     0,     0,   416,   417,     0,   418,   419,   420,
     421,   422,   423,    13,    14,    15,    16,    17,    18,   424,
     425,   426,    22,   427,    24,    25,    26,    27,     0,   428,
     429,    30,   430,   431,   432,    34,    35,    36,    37,    38,
      39,    40,    41,    42,   433,   434,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,     0,     0,    62,     0,    63,    64,    65,   435,     0,
       0,    69,    70,    71,     0,     0,     0,    73,     0,     0,
       0,     0,    75,    76,    77,     0,     0,    80,    81,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,     0,
      90,     0,     0,     0,   436,    92,    93,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,     0,   100,   101,
     102,   480,     0,     0,   481,     0,     0,   106,   107,     0,
       0,     0,     0,   108,   109,   110,   439,   112,   113,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
       0,     0,     0,   122,     0,   123,     0,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   440,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
       0,     0,   441,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   442,   443,   444,   156,   445,   446,   159,   160,
     161,   162,   163,   164,   447,   166,   167,   448,   449,   450,
     171,   451,   452,   453,   175,   454,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,     0,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,     3,     0,
       0,     0,     0,     0,     0,   416,   417,     0,   418,   419,
     420,   421,   422,   423,    13,    14,    15,    16,    17,    18,
     424,   425,   426,    22,   427,    24,    25,    26,    27,     0,
     428,   429,    30,   430,   431,   432,    34,    35,    36,    37,
      38,    39,    40,    41,    42,   433,   434,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    62,     0,    63,    64,    65,   435,
       0,     0,    69,    70,    71,     0,     0,     0,    73,     0,
       0,     0,     0,    75,    76,    77,     0,     0,    80,    81,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,   436,    92,    93,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,     0,   100,
     101,   102,     0,     0,     0,     0,     0,     0,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   439,   112,   113,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,     0,     0,     0,   122,   673,   123,     0,     0,     0,
       0,     0,   674,     0,   129,     0,   130,   131,   132,   133,
     440,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,     0,     0,   441,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   442,   443,   444,   156,   445,   446,   159,
     160,   161,   162,   163,   164,   447,   166,   167,   448,   449,
     450,   171,   451,   452,   453,   175,   454,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     3,
       0,     0,     0,     0,     0,     0,   416,   417,     0,   418,
     419,   420,   421,   422,   423,    13,    14,    15,    16,    17,
      18,   424,   425,   426,    22,   427,    24,    25,    26,    27,
       0,   428,   429,    30,   430,   431,   432,    34,    35,    36,
      37,    38,    39,    40,    41,    42,   433,   434,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,     0,    62,     0,    63,    64,    65,
     435,     0,     0,    69,    70,    71,     0,     0,     0,    73,
       0,     0,     0,     0,    75,    76,    77,     0,     0,    80,
      81,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,     0,    90,     0,     0,     0,   436,    92,    93,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    98,     0,
     100,   101,   102,     0,     0,     0,     0,     0,     0,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   439,   112,
     113,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,     0,     0,     0,   122,   714,   123,     0,     0,
       0,     0,     0,   715,     0,   129,     0,   130,   131,   132,
     133,   440,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,     0,     0,   441,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   442,   443,   444,   156,   445,   446,
     159,   160,   161,   162,   163,   164,   447,   166,   167,   448,
     449,   450,   171,   451,   452,   453,   175,   454,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
       3,     0,     0,     0,     0,     0,     0,   416,   417,     0,
     418,   419,   483,   421,   484,   485,    13,    14,    15,    16,
      17,    18,   424,   425,   486,    22,   427,    24,    25,    26,
      27,     0,   428,   429,    30,   430,   431,   432,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     0,     0,    62,     0,    63,    64,
      65,   487,     0,     0,    69,    70,    71,     0,     0,     0,
      73,     0,     0,     0,     0,    75,    76,    77,     0,     0,
      80,    81,  1252,     0,     0,     0,     0,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   436,    92,    93,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
       0,   100,   101,   970,     0,     0,     0,     0,     0,     0,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   439,
     112,   113,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,     0,     0,     0,   122,     0,   123,   124,
       0,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   440,   135,   136,   137,   138,   139,   140,     0,
       0,   971,   142,     0,     0,   441,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   442,   154,   444,   156,   445,
     446,   159,   160,   161,   162,   163,   164,   447,   166,   167,
     448,   449,   450,   171,   451,   452,   453,   175,   454,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,     3,     0,     0,     0,     0,     0,     0,   416,   417,
       0,   418,   419,   483,   421,   484,   485,    13,    14,    15,
      16,    17,    18,   424,   425,   486,    22,   427,    24,    25,
      26,    27,     0,   428,   429,    30,   430,   431,   432,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,     0,     0,    62,     0,    63,
      64,    65,   487,     0,     0,    69,    70,    71,     0,     0,
       0,    73,     0,     0,     0,     0,    75,    76,    77,     0,
       0,    80,    81,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,   436,    92,
      93,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      98,     0,   100,   101,   970,     0,     0,     0,     0,     0,
       0,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     439,   112,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   121,     0,     0,     0,   122,     0,   123,
     124,     0,     0,     0,     0,     0,     0,   129,     0,   130,
     131,   132,   133,   440,   135,   136,   137,   138,   139,   140,
       0,     0,   971,   142,     0,     0,   441,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   442,   154,   444,   156,
     445,   446,   159,   160,   161,   162,   163,   164,   447,   166,
     167,   448,   449,   450,   171,   451,   452,   453,   175,   454,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,     3,     0,     0,     0,     0,     0,     0,   416,
     417,     0,   418,   419,   483,   421,   484,   485,    13,    14,
      15,    16,    17,    18,   424,   425,   486,    22,   427,    24,
      25,    26,    27,     0,   428,   429,    30,   430,   431,   432,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    62,     0,
      63,    64,    65,   487,     0,     0,    69,    70,    71,     0,
       0,     0,    73,     0,     0,     0,     0,    75,    76,    77,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,   436,
      92,    93,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,     0,   100,   101,   970,     0,     0,     0,     0,
       0,     0,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   439,   112,   113,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,   122,     0,
     123,   124,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   440,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,     0,     0,   441,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   442,   154,   444,
     156,   445,   446,   159,   160,   161,   162,   163,   164,   447,
     166,   167,   448,   449,   450,   171,   451,   452,   453,   175,
     454,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     3,     0,     0,     0,     0,     0,     0,
     416,   417,     0,   418,   419,   420,   421,   422,   423,    13,
      14,    15,    16,    17,    18,   424,   425,   426,    22,   427,
      24,    25,    26,    27,     0,   428,   429,    30,   430,   431,
     432,    34,    35,    36,    37,    38,    39,    40,    41,    42,
     433,   434,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,     0,     0,    62,
       0,    63,    64,    65,   435,     0,     0,    69,    70,    71,
       0,     0,     0,    73,     0,     0,     0,     0,    75,    76,
      77,     0,     0,    80,    81,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,     0,    90,     0,     0,     0,
     436,    92,    93,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,     0,   100,   101,   102,     0,     0,     0,
       0,     0,     0,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   439,   112,   113,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,     0,     0,     0,   122,
       0,   123,     0,     0,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   440,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,     0,     0,   441,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   442,   443,
     444,   156,   445,   446,   159,   160,   161,   162,   163,   164,
     447,   166,   167,   448,   449,   450,   171,   451,   452,   453,
     175,   454,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,     0,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         9,   721,   869,   806,   375,   763,   856,   577,   578,   579,
     580,   573,    21,   895,   103,   531,   803,   804,   696,   805,
     806,   116,   700,   127,  1011,    68,   932,   553,  1164,   700,
      20,   785,   556,   999,   558,   559,  1306,   561,    60,   563,
     110,    21,    20,  1137,     7,   803,   804,   571,   572,    88,
     472,  1175,  1176,    86,    86,    88,    86,    66,    30,    68,
     132,   136,   189,    88,     8,     9,    30,   136,    32,    33,
      85,   198,    86,    82,   954,   120,    99,   835,    42,    99,
      99,    88,    99,   505,   506,   214,   508,   509,   510,   511,
      43,   462,   463,    65,   516,   104,   767,   519,   769,    99,
     132,    65,    66,   136,    99,   110,    92,   116,   866,   118,
     532,   136,   102,   110,   120,   124,   157,    20,    99,    53,
     542,   543,   126,    88,   114,    89,    88,     8,     9,   145,
      99,   258,    56,    57,   142,   206,    26,   264,    25,    99,
     185,    99,    20,   105,   147,   272,   275,    99,   138,   190,
      99,    95,   142,  1033,    41,   145,   171,   165,    48,   179,
     179,   164,   179,   841,   149,    99,   119,     8,     9,   113,
     175,   115,   105,    99,   142,   246,   176,   174,   121,   185,
     145,   176,   604,   145,   206,   189,   110,   262,     8,  1313,
     262,     8,     9,   262,   175,  1289,   226,   175,   142,    19,
     163,   224,   146,   175,  1071,  1055,   175,   311,   928,   248,
     249,  1093,   226,   177,    95,   175,  1486,   175,   162,   781,
     782,  1127,   202,   175,   246,   295,   175,   105,    86,   262,
     262,  1137,   113,   911,   115,  1505,   179,   262,   909,   183,
     226,   248,   249,   769,    86,  1515,   149,  1001,  1214,   175,
     214,  1238,   776,   260,    95,   241,    86,   201,   109,   630,
    1396,   142,   252,    99,   155,   146,   142,    86,   254,   145,
     256,   149,   113,   316,   115,   284,   319,    99,    95,   170,
     266,   162,    45,   269,   135,     4,    99,   382,    51,     8,
    1077,    54,    55,   113,   136,   115,   113,   148,   115,    62,
     137,   142,   183,    99,   124,   146,    99,   316,   241,  1067,
     319,  1069,   142,   984,   367,   410,   687,   154,   371,  1077,
     201,   162,   142,   412,    86,   142,   415,    98,   157,   146,
       4,   182,   237,   238,     8,   147,   758,   270,   271,   175,
     273,   274,   183,   765,   142,   162,   117,   145,   437,   207,
     208,    30,   164,   175,   259,    34,   189,   366,   289,   290,
     201,   190,   175,   372,   222,   198,   183,   456,   457,   378,
     459,   466,   461,   382,   136,   187,   465,  1244,   387,   175,
     210,   211,   175,  1289,   201,   394,   145,   142,   207,   208,
     145,   480,    71,   137,   113,   158,   115,   160,   134,    86,
     198,   410,   411,   222,   123,    88,   495,   880,   110,   882,
     154,   174,   501,    58,    59,   837,    61,   287,   288,    98,
     318,   843,   105,   142,  1411,     8,   324,   142,   164,   438,
    1000,   520,    20,    58,    59,   997,    19,   200,  1225,   113,
     127,   115,   958,    88,   157,   132,   182,  1009,   921,   123,
     923,   127,   281,   282,   283,   284,   285,   466,   180,   181,
     469,   470,   471,    88,   241,   110,   142,  1225,   142,   478,
     170,   127,   481,   844,   845,  1429,  1430,   190,   849,   158,
     902,   903,   491,   905,   184,   907,   142,   110,  1246,    87,
    1372,   595,   596,   270,   271,  1362,   273,   274,   126,   170,
      98,  1455,   873,   592,   513,   927,   239,  1461,   597,   242,
     108,   139,   521,   184,   102,   110,   938,   939,   940,   117,
     942,   943,   944,   945,   946,   947,   114,   949,   950,   258,
     113,   832,   115,   286,    92,   264,   214,    54,   216,   961,
     187,   124,   189,   272,   297,   846,  1224,   105,   214,  1416,
     138,   198,   145,   219,   142,  1342,   145,   145,   980,   142,
     982,   983,   275,   276,   277,   278,   279,  1287,    34,    35,
      36,   110,  1292,    39,    34,    35,    36,    37,    38,    39,
     669,   670,   239,   142,  1342,   242,    46,   676,   683,   127,
    1440,   686,   127,   142,   132,   258,   598,   132,   607,   601,
     263,   603,  1024,  1346,   693,   210,   211,   212,  1351,   145,
     214,    71,   216,   221,  1417,   223,   625,   281,   282,   283,
     284,   285,  1044,   281,   282,   283,   284,   285,   717,  1199,
     221,  1417,   223,   204,  1501,  1422,  1206,  1207,   118,   119,
     279,   280,  1509,   103,   104,   105,   214,   656,    58,    59,
     142,   660,   369,   370,   743,  1522,  1218,   118,   119,   574,
     575,   581,   582,  1383,  1422,  1087,   110,  1387,   231,   583,
     584,  1344,  1345,   227,   683,   231,   145,   686,  1100,   142,
     110,     0,  1104,  1105,   179,  1107,   179,    84,   156,   251,
    1112,   780,    68,    93,   188,   704,    94,   157,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,   143,   145,
      34,   720,    34,  1433,    20,   141,   110,  1088,   291,   142,
     281,   142,   142,   175,   175,   142,   268,   268,   110,  1487,
     190,   110,   145,   142,    34,    35,    36,    37,    38,    39,
     145,   145,   145,   145,   175,  1167,    46,    27,   757,    15,
     175,    20,    52,   202,   763,   220,  1178,  1327,  1328,   175,
      25,   110,   158,    63,    64,    99,   159,    67,   159,  1191,
      70,    71,  1194,   220,  1196,    86,    86,    86,   145,    20,
     240,    99,    99,   149,   149,   874,   117,   122,    20,   286,
     292,   142,   122,    88,   803,   804,   805,   806,   175,   172,
    1171,   172,   172,   103,   104,   105,   175,    30,   172,   172,
      88,   172,   132,   175,    99,   275,   276,   277,   278,   279,
     175,   281,   282,   283,   284,   285,   835,   287,   288,   289,
     290,   172,   175,   175,  1404,   175,   172,    86,   226,   172,
     172,   132,   214,   159,   172,   269,   175,   110,   110,   149,
     110,   110,  1274,   179,  1276,   136,   257,   157,   250,   172,
    1282,   173,   252,   872,   122,   132,    86,    86,   132,   172,
     172,   880,   271,   882,  1296,  1297,  1298,  1299,  1300,   286,
    1302,  1303,    92,   272,   172,   272,   142,   186,   122,   122,
     190,    88,   149,   172,  1265,   142,   110,   136,   110,   246,
     142,   132,  1324,    27,    88,    20,   110,   142,    92,   209,
     235,   172,   921,    71,   923,   110,    99,   172,    99,   145,
     145,   136,   172,   136,   175,    34,    35,    36,    37,    38,
      39,   136,   247,   247,   272,    47,   134,    46,    86,    20,
     240,    20,  1031,    52,   216,  1367,  1317,  1369,   216,  1371,
     159,   272,    86,   175,    63,    64,   134,   966,    67,    99,
     969,    70,    71,   179,   172,   132,   136,   110,   977,   175,
     979,   110,   175,   157,   175,   275,   276,   277,   278,   279,
     122,   281,   282,   283,   284,   285,    61,   287,   288,   289,
     290,  1080,     6,   175,   103,   104,   105,   226,   175,   179,
     174,   222,   132,    98,   222,   222,  1095,    98,   136,   175,
     175,   222,   265,   110,    86,   172,    20,  1026,    20,   294,
     174,   159,   172,   116,    88,   172,   172,   172,  1450,    20,
    1119,   172,    88,    88,    99,    86,   110,    92,    86,    59,
     149,   185,   226,   110,  1133,   275,   214,   249,   157,   174,
     110,   220,   185,  1475,   185,   255,   255,   241,   174,   243,
     244,   245,    85,   171,   185,   293,  1488,   110,  1077,   253,
     254,   110,   256,   142,   110,   110,   187,   261,  1500,   214,
    1502,   190,   266,   267,   268,   269,   175,   275,  1097,   296,
     243,   214,   110,  1102,  1040,   629,   530,   293,   530,   293,
     209,   294,   157,   240,  1113,   237,   298,   298,   836,   380,
     870,   240,   401,   403,  1362,   407,  1416,   818,  1160,   406,
    1226,   916,   244,   534,   283,  1134,   969,  1102,  1280,  1180,
    1114,   240,  1168,   961,  1178,  1444,  1097,  1175,   491,  1078,
     554,   304,   721,   555,   308,  1127,  1155,   576,  1461,  1455,
     835,   882,   479,  1039,  1155,  1164,   479,   781,   997,  1168,
    1009,  1218,   782,  1001,  1356,  1213,   275,   276,   277,   278,
     279,   226,   281,   282,   283,   284,   285,  1165,   287,   288,
     289,   290,   291,  1237,   998,    -1,   241,    -1,   243,   244,
     245,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,
      -1,   256,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,
      -1,   266,   267,   268,   269,    -1,  1225,   122,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,    -1,   133,    -1,
      -1,    -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,   144,
      -1,   146,    -1,  1252,    -1,    -1,   151,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   167,    -1,    -1,    -1,    -1,    -1,  1277,  1278,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1288,
      -1,    -1,    -1,    -1,  1293,    -1,   191,   192,   193,   194,
     195,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1342,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1364,    -1,    -1,    -1,  1368,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1384,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1396,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1417,    -1,
    1419,    -1,    -1,  1422,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1436,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1446,    -1,  1448,
      -1,    -1,  1451,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1489,    -1,    -1,  1492,    -1,    -1,    -1,    -1,    -1,  1498,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,
      -1,  1510,    -1,    -1,    -1,    17,    18,  1516,    20,    -1,
      -1,  1520,    -1,    25,    26,    -1,    28,    29,    30,    31,
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
     242,   243,   244,   245,   246,   247,   248,   249,    -1,   251,
     252,    -1,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,    10,    -1,
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
     164,   165,    -1,    -1,   168,   169,   170,    -1,    -1,    -1,
     174,   175,   176,   177,   178,    -1,   180,   181,   182,    -1,
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
     164,   165,    -1,    -1,   168,   169,   170,    -1,    -1,    -1,
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
     138,   139,   140,   141,    -1,    -1,    -1,   145,   146,    -1,
     148,   149,    -1,    -1,    -1,    -1,   154,   155,   156,   157,
     158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,    -1,
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
     139,   140,   141,    -1,    -1,    -1,   145,   146,    -1,   148,
     149,    -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,
     159,   160,   161,   162,    -1,    -1,    -1,    -1,    -1,   168,
     169,   170,    -1,    -1,    -1,   174,    -1,   176,   177,   178,
      -1,    -1,    -1,   182,    -1,   184,    -1,   186,   187,   188,
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
      -1,    -1,   182,    -1,   184,    -1,   186,   187,   188,   189,
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
     290,   291,   292,   293,   294,   295,   296,   297,   298,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    -1,    -1,    84,    -1,    86,    87,    88,    89,    -1,
      -1,    92,    93,    94,    -1,    -1,    -1,    98,    -1,    -1,
      -1,    -1,   103,   104,   105,    -1,    -1,   108,   109,    -1,
      -1,    -1,    -1,    -1,    -1,   116,   117,   118,   119,    -1,
     121,    -1,    -1,    -1,   125,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   135,   136,   137,    -1,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,    -1,
      -1,    -1,    -1,   154,   155,   156,   157,   158,   159,   160,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,
      -1,    -1,    -1,   174,    -1,   176,    -1,    -1,    -1,    -1,
      -1,   182,    -1,   184,    -1,   186,   187,   188,   189,   190,
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
     291,   292,   293,   294,   295,   296,   297,   298,    14,    -1,
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
     136,   137,    -1,   139,   140,   141,   142,    -1,    -1,   145,
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
     296,   297,   298,    14,    -1,    -1,    -1,    18,    -1,    20,
      -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    -1,    -1,    84,    -1,    86,    87,    88,    89,    -1,
      -1,    92,    93,    94,    -1,    -1,    -1,    98,    -1,    -1,
      -1,    -1,   103,   104,   105,    -1,    -1,   108,   109,    -1,
      -1,    -1,    -1,    -1,    -1,   116,   117,   118,   119,    -1,
     121,    -1,    -1,    -1,   125,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   135,   136,   137,    -1,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,    -1,
      -1,    -1,    -1,   154,   155,   156,   157,   158,   159,   160,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,
      -1,    -1,    -1,   174,   175,   176,    -1,    -1,    -1,    -1,
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
     291,   292,   293,   294,   295,   296,   297,   298,    14,    -1,
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
     246,   247,   248,   249,    -1,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,    16,    -1,    18,    -1,    -1,    -1,    -1,
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
      -1,    -1,   103,   104,   105,    -1,    -1,   108,   109,    -1,
      -1,    -1,    -1,    -1,    -1,   116,   117,   118,   119,    -1,
     121,    -1,    -1,    -1,   125,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   135,   136,   137,    -1,   139,   140,
     141,   142,    -1,    -1,   145,    -1,    -1,   148,   149,    -1,
      -1,    -1,    -1,   154,   155,   156,   157,   158,   159,   160,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,
      -1,    -1,    -1,   174,    -1,   176,    -1,    -1,    -1,    -1,
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
     170,    -1,    -1,    -1,   174,   175,   176,    -1,    -1,    -1,
      -1,    -1,   182,    -1,   184,    -1,   186,   187,   188,   189,
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
      -1,   170,    -1,    -1,    -1,   174,   175,   176,    -1,    -1,
      -1,    -1,    -1,   182,    -1,   184,    -1,   186,   187,   188,
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
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    -1,    -1,    84,    -1,    86,
      87,    88,    89,    -1,    -1,    92,    93,    94,    -1,    -1,
      -1,    98,    -1,    -1,    -1,    -1,   103,   104,   105,    -1,
      -1,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,   116,
     117,   118,   119,    -1,   121,    -1,    -1,    -1,   125,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,   136,
     137,    -1,   139,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,   148,   149,    -1,    -1,    -1,    -1,   154,   155,   156,
     157,   158,   159,   160,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   170,    -1,    -1,    -1,   174,    -1,   176,
     177,    -1,    -1,    -1,    -1,    -1,    -1,   184,    -1,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      -1,    -1,   199,   200,    -1,    -1,   203,   204,    -1,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,   251,   252,    -1,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,
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
     176,   177,    -1,    -1,    -1,    -1,    -1,    -1,   184,    -1,
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
     135,   136,   137,    -1,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,    -1,    -1,    -1,    -1,   154,
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
     295,   296,   297,   298
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
     340,   341,   342,   345,   346,   351,   352,   356,   361,   365,
     367,   372,   373,   374,   375,   376,   384,   385,   387,   388,
     389,   394,   396,   398,   399,   400,   405,   426,   429,   432,
     433,   434,   435,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   482,   483,   484,   498,   499,   501,   502,
     503,   504,   505,   506,   507,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   526,   527,   528,   529,   530,
     531,   532,   535,   541,   542,   543,    34,    35,    36,    37,
      38,    39,    46,    52,    63,    64,    67,    70,    71,   103,
     104,   105,   149,   157,   190,   209,   240,   275,   276,   277,
     278,   279,   281,   282,   283,   284,   285,   287,   288,   289,
     290,   353,   354,   357,   358,   362,   363,   364,   377,   378,
     149,    86,   142,   210,   211,   145,    25,    26,    28,    29,
      30,    31,    32,    33,    40,    41,    42,    44,    50,    51,
      53,    54,    55,    65,    66,    89,   125,   142,   145,   157,
     190,   203,   213,   214,   215,   217,   218,   225,   228,   229,
     230,   232,   233,   234,   236,   541,   142,   142,   145,   142,
     145,   145,    26,    48,    14,   142,   145,   540,   541,   110,
     110,   110,   142,    56,    57,   110,   391,    54,   145,   145,
     142,   145,   541,    30,    32,    33,    42,    89,   466,   541,
     541,   110,   175,   385,   541,   142,   540,    16,   541,   541,
     458,   142,    21,   202,   204,   214,   216,   145,   214,   216,
     214,   214,   219,   110,   142,   368,   227,   231,   231,   145,
     142,   110,   316,     0,   318,   319,    25,    41,   321,   384,
     179,   179,    99,   179,   386,    45,    51,    54,    55,    62,
     158,   160,   174,   200,   390,   395,   396,   397,   414,   415,
     419,   401,   402,   541,   156,    84,   122,   130,   131,   133,
     140,   144,   146,   151,   167,   191,   192,   193,   194,   195,
     196,   450,   451,   251,   147,   164,   187,   109,   135,   148,
     182,   189,   198,   126,   139,    68,   188,    93,    94,   147,
     164,   449,   142,   455,   458,   180,   181,   143,   470,   471,
     466,   470,   466,   470,   145,   541,   378,    34,   379,   377,
     377,   378,   541,   170,   184,   157,   190,    20,   539,   155,
     170,   170,   184,   541,   141,   110,   350,    30,    34,    71,
      98,   158,   540,   210,   211,   212,    92,   226,   241,   254,
     256,   266,   269,   555,   556,   557,   558,   559,   562,   567,
     568,   541,   281,   541,   157,   190,   275,   354,   157,   190,
     283,   358,   291,   364,   363,   540,   524,   541,   385,   142,
     142,   385,   385,   175,   182,   541,   142,   385,   385,   175,
     385,   175,   385,   149,   539,   105,   149,   344,   539,   385,
      20,   175,   540,   142,   427,   428,   541,   541,   406,   408,
     541,   388,   268,   268,   110,   409,   110,   541,    30,    65,
     175,   522,   523,   385,   175,   182,   541,   142,   427,   175,
      27,   486,   487,   488,   385,     7,   163,    15,   175,   385,
     202,    20,   388,   388,   175,   388,   388,   388,   388,   220,
     533,   534,   541,   369,   388,   388,   385,   407,   413,   541,
     323,   324,    25,   325,   388,   387,   158,   110,   159,   159,
     388,   388,    99,    86,    88,   136,   262,   403,   404,   509,
     434,   435,   437,   437,   437,   437,   436,   437,   437,   437,
     142,   145,   252,   473,   544,   546,   547,   548,   549,   550,
     551,   552,   440,   440,   439,   441,   441,   441,   441,   442,
     442,   443,   443,   220,    86,    86,    86,   172,   385,   458,
     458,   385,   471,   175,   388,   481,   145,   366,   541,    20,
      99,    99,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,   327,   328,   329,    86,   127,   132,   347,   348,
     349,   541,   127,   132,   149,   149,   327,   539,   117,   122,
     239,   242,   105,   241,   270,   271,   273,   274,   239,   242,
      20,   241,   270,   271,   273,   274,    86,   226,   355,   286,
     541,   541,   292,   122,   142,   172,   385,   385,   175,   172,
      99,   175,    99,   175,   172,   385,   172,   172,   172,   175,
     540,    88,    30,   540,   539,    88,   172,   175,   175,   172,
     385,    99,   176,   136,   509,   132,    99,   132,   404,   509,
     172,   541,    60,   206,   246,   392,   393,   175,   175,   175,
     172,    99,   175,    99,   175,   172,   385,   176,   541,   487,
     488,   120,   185,   172,   172,   121,   179,    86,   207,   208,
     222,    86,   207,   208,   222,    86,   226,   214,    99,   224,
     132,    25,   370,   385,   175,   172,    53,    99,   179,   105,
     179,   159,   541,   388,   420,   421,   110,   416,   417,   110,
     141,   199,   510,   512,   513,   514,   541,   110,   388,   110,
     136,   404,   136,   136,   403,   404,   437,   385,   544,   550,
     269,   578,    88,   157,   243,   244,   245,   253,   261,   267,
     268,   545,   553,   554,   555,   569,   572,   573,   575,   250,
     252,   257,   574,   237,   238,   259,   570,   510,   510,   508,
     513,   508,   172,   173,    99,   175,   110,   175,   380,   381,
     127,   142,   383,   366,   137,   154,   137,   154,   328,   122,
     512,   349,   388,   509,   132,   388,   539,   539,   118,   119,
     539,   271,   272,    88,   105,   145,   561,   272,    32,    33,
      42,    66,    89,   214,   514,   279,   280,    86,   456,    86,
     355,   286,   541,   539,   385,   172,   172,    92,   430,   431,
     142,   524,   525,   541,   524,   525,   172,   186,   122,   343,
     539,   149,   122,    88,   343,   142,   172,   110,   388,   388,
     136,   388,   110,   388,   132,   132,   404,   136,   509,   246,
      58,    59,    61,   110,   403,   410,   411,   412,   393,   142,
     524,   524,   172,   388,    27,   488,   120,   185,     8,     9,
      95,   113,   115,   142,   183,   382,   483,   485,   496,   497,
     500,    20,   221,   223,   388,   388,   388,   221,   223,   388,
     388,   388,   388,   388,   388,   110,   388,   388,   350,   371,
      99,   179,   172,   368,   235,   536,   537,   142,   110,   420,
      87,    98,   108,   117,   422,   423,   424,   425,    99,   541,
      99,   402,   145,   145,   134,   164,   182,   511,   541,   541,
     388,   136,   388,   388,   136,   404,   136,   172,   175,   247,
     206,   246,   258,   263,   577,    88,   248,   249,   571,   247,
     547,   577,   438,   441,   267,   553,   555,   548,   136,   571,
     272,    47,   134,   388,   541,    86,    99,   175,   385,   127,
     368,   526,   348,   388,   272,    88,   145,   564,    20,   105,
     561,   216,   216,   514,   159,   514,    86,   456,   286,   297,
     179,   172,   110,   510,   105,   431,   172,   385,   175,   175,
     134,   175,   175,   388,   539,    99,   343,   172,   385,   428,
     388,   408,   388,   388,   132,   388,   136,   110,   110,   388,
     541,   412,    61,   172,   385,   175,   175,   122,   183,   485,
       6,   385,   541,   183,   496,   179,   222,   222,   222,   222,
     226,   534,   174,   132,   371,   467,   538,   537,   388,   413,
     539,   118,   119,   424,   425,   425,   421,    98,   418,   417,
     175,   175,   388,   388,   136,   388,   441,    43,   119,   441,
     441,   258,   264,   272,   576,   576,   438,   549,   265,   509,
     510,   381,    86,   172,   126,   189,   563,   566,    20,    20,
     565,   563,   260,   571,    99,   175,    99,   175,   359,   360,
     456,   514,   159,   214,   275,   294,   541,   174,   110,   174,
     172,   116,    88,   539,   172,   388,   388,   541,   541,   411,
     388,   172,   488,   541,   183,   172,   488,   541,   388,   388,
     388,   388,   388,   388,   388,   145,   198,   383,   172,   425,
     539,   388,   441,   441,   187,   510,   564,   564,   566,    20,
     175,    20,   255,   560,   561,   560,    99,    86,   359,   110,
     541,   249,    86,   388,   541,   388,   388,   343,    59,    85,
     171,   489,   488,   541,   185,   488,   110,   467,   441,   571,
      99,   175,   175,   360,   508,   541,   110,   295,   275,   510,
     174,   110,     4,   123,   492,   493,   495,   497,    19,   124,
     490,   491,   494,   497,   185,   488,   185,   541,   255,   561,
     422,   220,   541,   214,   541,   174,   388,   541,    85,   123,
     495,   171,   124,   494,   185,    99,   175,   296,   293,   110,
     214,   388,   110,   383,   514,   281,   388,   541,   110,   541,
     293,   294,   293,   541,    99,   175,   388,   456,   388,   298,
     110,   383,   456,   541,   187,   175,   275,   383,   541,   214,
     110,   541,   298,   456
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
     356,   357,   357,   358,   358,   358,   358,   358,   358,   359,
     359,   360,   360,   361,   361,   361,   361,   361,   362,   362,
     363,   363,   363,   364,   364,   364,   365,   365,   366,   366,
     366,   366,   367,   368,   369,   369,   370,   370,   371,   371,
     372,   373,   374,   375,   375,   376,   376,   376,   377,   377,
     377,   377,   378,   378,   379,   379,   380,   380,   381,   381,
     382,   383,   384,   385,   385,   386,   386,   387,   387,   388,
     388,   388,   388,   388,   388,   388,   388,   388,   388,   388,
     388,   388,   388,   388,   388,   388,   389,   390,   391,   391,
     392,   392,   392,   393,   393,   394,   394,   395,   396,   396,
     396,   397,   397,   397,   397,   397,   398,   398,   399,   399,
     400,   401,   401,   402,   402,   402,   402,   402,   402,   402,
     402,   403,   404,   405,   406,   406,   407,   407,   408,   408,
     408,   408,   409,   409,   410,   410,   410,   411,   411,   411,
     412,   412,   412,   413,   414,   415,   416,   416,   417,   417,
     418,   419,   419,   420,   420,   421,   421,   422,   422,   422,
     422,   422,   422,   422,   423,   423,   424,   424,   425,   426,
     426,   427,   427,   428,   428,   429,   429,   430,   430,   431,
     431,   432,   433,   433,   434,   434,   435,   435,   435,   435,
     435,   436,   435,   435,   435,   435,   437,   437,   437,   438,
     438,   439,   439,   439,   440,   440,   440,   440,   440,   441,
     441,   441,   442,   442,   442,   443,   443,   444,   444,   445,
     445,   446,   446,   447,   447,   448,   448,   448,   448,   449,
     449,   449,   450,   450,   450,   450,   450,   450,   451,   451,
     451,   452,   452,   452,   452,   453,   453,   454,   454,   455,
     455,   456,   456,   456,   456,   457,   458,   458,   458,   459,
     459,   460,   460,   460,   460,   461,   461,   462,   462,   462,
     462,   462,   462,   462,   463,   463,   464,   464,   465,   465,
     465,   465,   465,   466,   466,   467,   467,   468,   468,   468,
     469,   469,   470,   470,   471,   472,   472,   472,   472,   472,
     472,   472,   472,   473,   473,   474,   474,   474,   475,   476,
     476,   477,   478,   479,   480,   480,   481,   481,   482,   482,
     483,   483,   483,   484,   484,   484,   484,   484,   484,   485,
     485,   486,   486,   487,   488,   488,   489,   489,   490,   490,
     491,   491,   491,   491,   492,   492,   493,   493,   493,   493,
     494,   494,   495,   495,   496,   496,   496,   496,   497,   497,
     497,   497,   498,   498,   499,   499,   500,   501,   501,   501,
     501,   501,   501,   502,   503,   503,   503,   503,   504,   504,
     504,   504,   505,   506,   507,   507,   507,   507,   508,   508,
     509,   510,   510,   510,   511,   511,   511,   512,   512,   512,
     513,   514,   514,   514,   514,   514,   514,   514,   514,   514,
     515,   516,   516,   516,   517,   518,   519,   519,   519,   520,
     520,   520,   520,   520,   521,   522,   522,   522,   522,   522,
     522,   522,   523,   524,   525,   526,   527,   527,   527,   528,
     528,   528,   528,   528,   528,   528,   528,   528,   528,   529,
     529,   530,   530,   531,   532,   533,   533,   534,   535,   536,
     536,   537,   537,   537,   537,   538,   538,   539,   540,   540,
     541,   541,   542,   542,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   542,   543,   543,   544,   544,   544,   544,
     545,   545,   545,   545,   546,   546,   547,   547,   548,   548,
     549,   549,   550,   550,   550,   551,   551,   552,   552,   553,
     553,   553,   553,   553,   554,   555,   555,   555,   555,   555,
     555,   555,   556,   556,   556,   556,   557,   557,   557,   557,
     558,   558,   559,   559,   559,   559,   559,   559,   559,   560,
     560,   561,   561,   561,   561,   562,   562,   562,   562,   562,
     563,   563,   564,   564,   565,   565,   566,   566,   567,   568,
     568,   569,   569,   569,   570,   570,   570,   570,   570,   571,
     571,   571,   571,   572,   573,   574,   575,   575,   576,   576,
     576,   577,   577,   578
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
       2,     1,     1,     1,     1,     1,     1,     3,     3,     7,
       8,     1,     2,     1,     1,     1,     2,     1,     1,     1,
       3,     3,     4,    12,    14,    14,    14,    23,     2,     2,
       0,     1,     1,     0,     1,     1,     3,     3,     2,     3,
       4,     5,     2,     4,     3,     0,     3,     2,     1,     3,
       5,     3,     5,     2,     2,     2,     3,     3,     1,     2,
       2,     2,     4,     4,     4,     4,     1,     3,     2,     3,
       3,     3,     1,     1,     2,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       1,     1,     2,     4,     3,     5,     4,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       2,     1,     4,     3,     4,     4,     5,     4,     5,     5,
       6,     3,     3,     3,     1,     4,     1,     4,     3,     4,
       4,     5,     4,     5,     1,     2,     3,     1,     2,     1,
       6,     3,     3,     1,     2,     3,     1,     3,     2,     3,
       2,     3,     4,     1,     3,     1,     2,     1,     1,     1,
       2,     2,     2,     3,     1,     1,     2,     2,     2,     5,
       5,     1,     4,     3,     4,     8,    10,     1,     2,     4,
       7,     8,     1,     3,     1,     3,     1,     3,     3,     3,
       3,     0,     4,     3,     3,     3,     1,     3,     4,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     4,     1,     4,     1,
       4,     1,     4,     1,     2,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     5,     5,     6,     3,     4,     1,     2,     3,
       2,     1,     2,     2,     1,     1,     1,     3,     3,     1,
       1,     1,     2,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       3,     1,     4,     4,     3,     4,     1,     3,     1,     1,
       1,     1,     1,     4,     5,     8,     9,     9,    10,     1,
       2,     1,     2,     6,     0,     1,     3,     3,     0,     1,
       1,     1,     2,     2,     0,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     3,     3,     2,     1,     1,     1,
       1,     1,     1,     4,     4,     5,     6,     7,     4,     5,
       6,     7,     4,     4,     4,     5,     6,     7,     1,     2,
       2,     1,     2,     3,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     4,     4,     3,     3,     3,     4,     4,     3,
       4,     6,     4,     6,     3,     3,     4,     6,     6,     4,
       6,     6,     4,     1,     2,     1,     3,     3,     3,     5,
       7,     7,     5,     5,     5,     7,     7,     5,     5,     3,
       3,     5,     7,     5,     7,     1,     4,     3,     5,     1,
       2,     3,     7,    10,    13,     1,     3,     1,     1,     1,
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
       1,     1,     1,     1,     7,     4,     1,     2,     3,     4,
       1,     1,     2,     2,     1,     3,     1,     3,     1,     4,
       1,     2,     1,     2,     3,     1,     2,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     3,     3,     5,     7,     5,     7,     2,     1,
       3,     2,     4,     4,     6,     4,     5,     4,     5,     3,
       1,     2,     2,     3,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     2,     1,     2,     1,     2,
       3,     3,     4,     3,     3,     3,     2,     2,     1,     1,
       1,     1,     1,     3
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
  "IndexPropertyList", "IndexProperty", "IndexKeyList", "IndexKeySpec",
  "IntegrityConstraintDecl", "IntgCnstOptions", "IntgCnstUnchecked",
  "IntgCnstAsynch", "ConstructionDecl", "FunctionSig", "BlockExpr",
  "Block", "BlockDecls", "BlockVarDeclList", "BlockVarDecl", "AssignExpr",
  "ExitExpr", "WhileExpr", "FlowCtlStatement", "FunctionDecl",
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
     321,   384,    -1,   384,    -1,   320,    -1,   320,   321,    -1,
      26,   149,   540,   122,   539,   179,    -1,   322,   179,    -1,
     323,   179,    -1,   322,   179,   323,   179,    -1,   324,    -1,
     322,   179,   324,    -1,   325,    -1,   323,   179,   325,    -1,
     330,    -1,   331,    -1,   332,    -1,   334,    -1,   351,    -1,
     346,    -1,   376,    -1,   335,    -1,   336,    -1,   352,    -1,
     356,    -1,   361,    -1,   326,    -1,    25,   105,    71,   327,
      -1,    25,    71,   541,   327,    -1,   328,    -1,   327,   328,
      -1,   329,   122,   526,    -1,    72,    -1,    73,    -1,    74,
      -1,    75,    -1,    76,    -1,    77,    -1,    78,    -1,    79,
      -1,    80,    -1,    81,    -1,   333,    -1,   340,    -1,   341,
      -1,   365,    -1,   337,    -1,   338,    -1,   339,    -1,   527,
      -1,   342,    -1,   345,    -1,    25,   149,   540,   122,   539,
      -1,    25,    70,   170,    -1,    25,    70,   184,    -1,    25,
     105,    30,   149,   539,    -1,    25,   105,    34,   149,   539,
      -1,    25,    46,   541,    20,    -1,    25,   240,   555,    -1,
      25,    63,   157,    -1,    25,    63,   190,    -1,    25,   105,
     158,   117,   118,    -1,    25,   105,   158,   117,   119,    -1,
      25,    67,   170,    99,   137,    -1,    25,    67,   170,    99,
     154,    -1,    25,    67,   155,    99,   137,    -1,    25,    67,
     155,    99,   154,    -1,    25,   105,    98,   539,    -1,    25,
      64,   539,    -1,    41,    48,   539,    -1,    41,    48,   344,
     539,    -1,    41,    48,   539,    88,   343,    -1,    41,    48,
     344,   539,    88,   343,    -1,   539,    -1,   343,    99,   539,
      -1,   149,   540,   122,    -1,   105,    30,   149,    -1,    41,
      26,   539,    -1,    41,    26,   149,   540,   122,   539,    -1,
      41,    26,   539,    88,   343,    -1,    41,    26,   149,   540,
     122,   539,    88,   343,    -1,    25,   103,   141,   347,    -1,
      86,   512,   348,    -1,   348,    -1,   349,    -1,   127,    -1,
     127,   349,    -1,   132,   388,    -1,   110,   541,    -1,   110,
     541,   509,    -1,    25,   104,   350,   132,   388,    -1,    25,
     104,   350,   127,    -1,    25,   104,   350,   127,   132,   388,
      -1,    25,   275,   541,    -1,    25,   275,   541,   355,    -1,
      25,   275,   541,    86,   514,    -1,    25,   275,   541,   355,
      86,   514,    -1,    25,   353,   275,   541,    -1,    25,   353,
     275,   541,   355,    -1,    25,   353,   275,   541,    86,   514,
      -1,    25,   353,   275,   541,   355,    86,   514,    -1,   354,
      -1,   353,   354,    -1,   276,    -1,   277,    -1,   278,    -1,
     279,    -1,   157,    -1,   190,    -1,   226,   280,   216,    -1,
     226,   279,   216,    -1,    25,   283,   541,   286,   456,   159,
     359,    -1,    25,   357,   283,   541,   286,   456,   159,   359,
      -1,   358,    -1,   357,   358,    -1,   157,    -1,   190,    -1,
     281,    -1,   282,   281,    -1,   285,    -1,   284,    -1,   360,
      -1,   359,    99,   360,    -1,   456,    86,   508,    -1,   456,
      86,   508,   422,    -1,    25,   362,   291,   292,   541,   286,
     275,   541,   110,   541,   293,   388,    -1,    25,   362,   291,
     292,   541,   286,   275,   541,   110,   541,   293,   281,   294,
     456,    -1,    25,   362,   291,   292,   541,   286,   275,   541,
     295,   214,   110,   541,   293,   388,    -1,    25,   362,   291,
     292,   541,   286,   214,   110,   541,   220,   296,   514,   293,
     388,    -1,    25,   362,   291,   292,   541,   297,   294,   249,
     275,   541,   214,   110,   541,   298,   456,   187,   275,   541,
     214,   110,   541,   298,   456,    -1,   363,   364,    -1,   364,
     363,    -1,    -1,   287,    -1,   288,    -1,    -1,   290,    -1,
     289,    -1,    25,    52,   170,    -1,    25,    52,   184,    -1,
     145,   175,    -1,   145,   380,   175,    -1,   145,   175,    86,
     510,    -1,   145,   380,   175,    86,   510,    -1,   228,   368,
      -1,   142,   369,   385,   172,    -1,   369,   370,   179,    -1,
      -1,   370,    99,   371,    -1,    25,   371,    -1,   350,    -1,
     350,   132,   388,    -1,    50,   110,   541,   132,   388,    -1,
     229,   227,   388,    -1,   233,   145,   388,   175,   368,    -1,
     230,   231,    -1,   232,   231,    -1,    25,   377,    -1,    25,
      38,   377,    -1,    25,    37,   377,    -1,   378,    -1,    39,
     378,    -1,    35,   378,    -1,    36,   379,    -1,    34,   541,
     366,   383,    -1,    34,   541,   366,   127,    -1,    34,   541,
     366,   368,    -1,    34,   541,   366,   127,    -1,   381,    -1,
     380,    99,   381,    -1,   110,   541,    -1,   110,   541,   509,
      -1,   142,   385,   172,    -1,   142,   385,   172,    -1,   385,
      -1,   387,    -1,   387,   386,    -1,   179,    -1,   386,   387,
     179,    -1,   388,    -1,   387,    99,   388,    -1,   389,    -1,
     426,    -1,   429,    -1,   432,    -1,   433,    -1,   528,    -1,
     529,    -1,   531,    -1,   530,    -1,   532,    -1,   535,    -1,
     543,    -1,   373,    -1,   374,    -1,   375,    -1,   372,    -1,
     367,    -1,   398,   390,    -1,   174,   388,    -1,    56,   268,
      -1,    57,   268,    -1,   206,    -1,   246,    -1,    60,   246,
      -1,   392,   410,    61,   388,    -1,   392,    61,   388,    -1,
      54,   391,   409,   393,   393,    -1,    54,   391,   409,   393,
      -1,    62,   110,   541,    -1,   400,    -1,   405,    -1,   394,
      -1,   396,    -1,   414,    -1,   419,    -1,   415,    -1,   395,
      -1,   396,    -1,   398,   397,    -1,    54,   110,    -1,    55,
      54,   110,    -1,   399,   401,    -1,   402,    -1,   401,    99,
     110,   402,    -1,   541,   136,   388,    -1,   541,   509,   136,
     388,    -1,   541,   403,   136,   388,    -1,   541,   509,   403,
     136,   388,    -1,   541,   404,   136,   388,    -1,   541,   509,
     404,   136,   388,    -1,   541,   403,   404,   136,   388,    -1,
     541,   509,   403,   404,   136,   388,    -1,    88,   110,   541,
      -1,   262,   110,   541,    -1,    51,   110,   406,    -1,   408,
      -1,   406,    99,   110,   408,    -1,   413,    -1,   407,    99,
     110,   413,    -1,   541,   132,   388,    -1,   541,   509,   132,
     388,    -1,   541,   404,   132,   388,    -1,   541,   509,   404,
     132,   388,    -1,   110,   541,   136,   388,    -1,   110,   541,
     509,   136,   388,    -1,   411,    -1,   110,   541,    -1,   110,
     541,   411,    -1,   403,    -1,   403,   412,    -1,   412,    -1,
      58,   110,   541,    59,   110,   541,    -1,    59,   110,   541,
      -1,    58,   110,   541,    -1,   541,    -1,   200,   388,    -1,
     160,   159,   416,    -1,   417,    -1,   416,    99,   417,    -1,
     110,   541,    -1,   110,   541,   418,    -1,    98,   539,    -1,
     158,   159,   420,    -1,    45,   158,   159,   420,    -1,   421,
      -1,   420,    99,   421,    -1,   388,    -1,   388,   422,    -1,
     423,    -1,   424,    -1,   425,    -1,   423,   424,    -1,   423,
     425,    -1,   424,   425,    -1,   423,   424,   425,    -1,    87,
      -1,   108,    -1,   117,   118,    -1,   117,   119,    -1,    98,
     539,    -1,    44,   110,   427,   176,   388,    -1,   125,   110,
     427,   176,   388,    -1,   428,    -1,   427,    99,   110,   428,
      -1,   541,   136,   388,    -1,   541,   509,   136,   388,    -1,
      29,   145,   385,   175,   430,   105,   174,   388,    -1,    29,
     145,   385,   175,   430,   105,   110,   541,   174,   388,    -1,
     431,    -1,   430,   431,    -1,    92,   510,   174,   388,    -1,
      92,   110,   541,    86,   510,   174,   388,    -1,    40,   145,
     385,   175,   186,   388,   116,   388,    -1,   434,    -1,   433,
     156,   434,    -1,   435,    -1,   434,    84,   435,    -1,   437,
      -1,   437,   450,   437,    -1,   437,   451,   437,    -1,   437,
     122,   437,    -1,   437,   151,   437,    -1,    -1,   437,   146,
     436,   437,    -1,   437,   144,   437,    -1,   437,   133,   437,
      -1,   437,   131,   437,    -1,   438,    -1,   438,   251,   544,
      -1,   438,   251,   544,   578,    -1,   439,    -1,   439,   187,
     439,    -1,   440,    -1,   439,   164,   440,    -1,   439,   147,
     440,    -1,   441,    -1,   440,   182,   441,    -1,   440,   109,
     441,    -1,   440,   135,   441,    -1,   440,   148,   441,    -1,
     442,    -1,   441,   189,   442,    -1,   441,   198,   442,    -1,
     443,    -1,   442,   139,   443,    -1,   442,   126,   443,    -1,
     444,    -1,   444,    68,   220,   510,    -1,   445,    -1,   445,
     188,    86,   510,    -1,   446,    -1,   446,    93,    86,   508,
      -1,   447,    -1,   447,    94,    86,   508,    -1,   449,    -1,
     448,   449,    -1,   164,    -1,   147,    -1,   448,   164,    -1,
     448,   147,    -1,   452,    -1,   456,    -1,   453,    -1,   191,
      -1,   196,    -1,   195,    -1,   194,    -1,   193,    -1,   192,
      -1,   140,    -1,   167,    -1,   130,    -1,    28,   142,   385,
     172,    -1,    28,   211,   142,   385,   172,    -1,    28,   210,
     142,   385,   172,    -1,    28,    86,   524,   142,   385,   172,
      -1,   454,   142,   172,    -1,   454,   142,   385,   172,    -1,
     455,    -1,   454,   455,    -1,   165,   541,    15,    -1,   165,
      16,    -1,   457,    -1,   457,   458,    -1,   181,   458,    -1,
     458,    -1,   180,    -1,   459,    -1,   459,   180,   458,    -1,
     459,   181,   458,    -1,   460,    -1,   469,    -1,   461,    -1,
     461,   470,    -1,   464,    -1,   464,   470,    -1,   462,   466,
      -1,   463,    -1,    97,    -1,   106,    -1,    90,    -1,   178,
      -1,   107,    -1,   129,    -1,   128,    -1,   466,    -1,    91,
     466,    -1,   465,   466,    -1,   112,    -1,   161,    -1,    82,
      -1,   169,    -1,   168,    -1,    83,    -1,   514,    -1,   467,
      -1,   541,    -1,   468,    -1,   182,    -1,    10,    -1,    17,
      -1,   472,    -1,   472,   470,    -1,   471,    -1,   470,   471,
      -1,   143,   385,   173,    -1,   473,    -1,   475,    -1,   476,
      -1,   477,    -1,   480,    -1,   482,    -1,   478,    -1,   479,
      -1,   474,    -1,   526,    -1,   102,    -1,   138,    -1,   114,
      -1,   110,   541,    -1,   145,   175,    -1,   145,   385,   175,
      -1,   111,    -1,   157,   142,   385,   172,    -1,   190,   142,
     385,   172,    -1,   541,   145,   175,    -1,   541,   145,   481,
     175,    -1,   388,    -1,   481,    99,   388,    -1,   483,    -1,
     501,    -1,   484,    -1,   498,    -1,   499,    -1,   146,   541,
     488,   120,    -1,   146,   541,   486,   488,   120,    -1,   146,
     541,   488,   185,   183,   541,   488,   185,    -1,   146,   541,
     488,   185,   485,   183,   541,   488,   185,    -1,   146,   541,
     486,   488,   185,   183,   541,   488,   185,    -1,   146,   541,
     486,   488,   185,   485,   183,   541,   488,   185,    -1,   496,
      -1,   485,   496,    -1,   487,    -1,   486,   487,    -1,    27,
     541,   488,   122,   488,   489,    -1,    -1,    27,    -1,   171,
     490,   171,    -1,    85,   492,    85,    -1,    -1,   491,    -1,
     124,    -1,   494,    -1,   491,   124,    -1,   491,   494,    -1,
      -1,   493,    -1,   123,    -1,   495,    -1,   493,   123,    -1,
     493,   495,    -1,    19,    -1,   497,    -1,     4,    -1,   497,
      -1,   483,    -1,     9,    -1,   500,    -1,   497,    -1,     8,
      -1,   113,    -1,   115,    -1,   382,    -1,   201,    21,   202,
      -1,   201,   202,    -1,   162,   540,   163,    -1,   162,   540,
       7,    -1,    95,     6,    -1,   502,    -1,   503,    -1,   504,
      -1,   505,    -1,   506,    -1,   507,    -1,    31,   142,   385,
     172,    -1,    30,   541,   142,   172,    -1,    30,   541,   142,
     385,   172,    -1,    30,   142,   385,   172,   142,   172,    -1,
      30,   142,   385,   172,   142,   385,   172,    -1,    89,   541,
     142,   172,    -1,    89,   541,   142,   385,   172,    -1,    89,
     142,   385,   172,   142,   172,    -1,    89,   142,   385,   172,
     142,   385,   172,    -1,    32,   142,   385,   172,    -1,    33,
     142,   385,   172,    -1,    42,   540,   142,   172,    -1,    42,
     540,   142,   385,   172,    -1,    42,   142,   385,   172,   142,
     172,    -1,    42,   142,   385,   172,   142,   385,   172,    -1,
     513,    -1,   513,   134,    -1,    86,   510,    -1,   512,    -1,
     512,   511,    -1,   199,   145,   175,    -1,   134,    -1,   182,
      -1,   164,    -1,   513,    -1,   514,    -1,   141,   145,   175,
      -1,   541,    -1,   516,    -1,   522,    -1,   520,    -1,   523,
      -1,   521,    -1,   519,    -1,   518,    -1,   517,    -1,   515,
      -1,   214,   145,   175,    -1,    66,   145,   175,    -1,    66,
     145,   522,   175,    -1,    66,   145,   523,   175,    -1,    32,
     145,   175,    -1,    33,   145,   175,    -1,    42,   145,   175,
      -1,    42,   145,   540,   175,    -1,    42,   145,    20,   175,
      -1,    89,   145,   175,    -1,    89,   145,   541,   175,    -1,
      89,   145,   541,    99,   524,   175,    -1,    89,   145,   182,
     175,    -1,    89,   145,   182,    99,   524,   175,    -1,   177,
     541,   175,    -1,    30,   145,   175,    -1,    30,   145,   541,
     175,    -1,    30,   145,   541,    99,   524,   175,    -1,    30,
     145,   541,    99,   525,   175,    -1,    30,   145,   182,   175,
      -1,    30,   145,   182,    99,   524,   175,    -1,    30,   145,
     182,    99,   525,   175,    -1,    65,   145,   541,   175,    -1,
     541,    -1,   541,   134,    -1,    20,    -1,    25,   209,   210,
      -1,    25,   209,   211,    -1,    25,   209,   212,    -1,   215,
     214,   388,   222,   388,    -1,   215,   214,   388,    86,   221,
     222,   388,    -1,   215,   214,   388,    86,   223,   222,   388,
      -1,   215,   214,   388,   207,   388,    -1,   215,   214,   388,
     208,   388,    -1,   215,   216,   388,   222,   388,    -1,   215,
     216,   388,    86,   221,   222,   388,    -1,   215,   216,   388,
      86,   223,   222,   388,    -1,   215,   216,   388,   207,   388,
      -1,   215,   216,   388,   208,   388,    -1,   213,   214,   388,
      -1,   213,   216,   388,    -1,   218,   214,   388,   226,   388,
      -1,   218,   219,   220,   214,   388,   226,   388,    -1,   217,
     214,   388,    86,   388,    -1,   225,   110,   533,   224,   388,
     174,   388,    -1,   534,    -1,   533,    99,   110,   534,    -1,
     541,   132,   388,    -1,   234,   142,   385,   172,   536,    -1,
     537,    -1,   536,   537,    -1,   235,   538,   383,    -1,   235,
     538,   145,   110,   541,   175,   383,    -1,   235,   538,   145,
     110,   541,    99,   110,   541,   175,   383,    -1,   235,   538,
     145,   110,   541,    99,   110,   541,    99,   110,   541,   175,
     383,    -1,   467,    -1,   538,   198,   467,    -1,    20,    -1,
      14,    -1,   541,    -1,    18,    -1,   542,    -1,   203,    -1,
     117,    -1,    89,    -1,    33,    -1,    66,    -1,    30,    -1,
     141,    -1,    40,    -1,   214,    -1,    42,    -1,    69,    -1,
      65,    -1,    32,    -1,    29,    -1,   199,    -1,    70,    -1,
     240,    -1,    64,    -1,   211,    -1,   210,    -1,   135,    -1,
      31,    -1,   252,    -1,   239,    -1,   242,    -1,   241,    -1,
     269,    -1,   270,    -1,   273,    -1,   271,    -1,   274,    -1,
     245,    -1,   247,    -1,    47,    -1,   206,    -1,   246,    -1,
      43,    -1,   212,    -1,   225,    -1,   219,    -1,   191,    -1,
     196,    -1,   195,    -1,   194,    -1,   193,    -1,   192,    -1,
      88,    -1,   103,    -1,   104,    -1,   174,    -1,    54,    -1,
      55,    -1,    56,    -1,    57,    -1,    58,    -1,    59,    -1,
      60,    -1,    61,    -1,    62,    -1,   136,    -1,    51,    -1,
     200,    -1,   159,    -1,   160,    -1,   158,    -1,    45,    -1,
      87,    -1,   108,    -1,   118,    -1,   119,    -1,    98,    -1,
      44,    -1,   125,    -1,   176,    -1,    92,    -1,    86,    -1,
     186,    -1,   116,    -1,   156,    -1,    84,    -1,    68,    -1,
     220,    -1,    93,    -1,   187,    -1,   109,    -1,   148,    -1,
     189,    -1,   139,    -1,   126,    -1,    28,    -1,    94,    -1,
     188,    -1,   140,    -1,   170,    -1,   184,    -1,   149,    -1,
     127,    -1,   121,    -1,   155,    -1,   137,    -1,   154,    -1,
      25,    -1,    52,    -1,    63,    -1,   105,    -1,    67,    -1,
      46,    -1,   204,    -1,    41,    -1,    48,    -1,    26,    -1,
      34,    -1,   262,    -1,   251,    -1,   267,    -1,   268,    -1,
     244,    -1,   257,    -1,   265,    -1,   261,    -1,   243,    -1,
     256,    -1,   266,    -1,   260,    -1,   255,    -1,   254,    -1,
     238,    -1,   237,    -1,   259,    -1,   248,    -1,   249,    -1,
     272,    -1,   264,    -1,   263,    -1,   258,    -1,   218,    -1,
     224,    -1,   221,    -1,   215,    -1,   208,    -1,   207,    -1,
     209,    -1,   226,    -1,   216,    -1,   217,    -1,   223,    -1,
     213,    -1,   222,    -1,    39,    -1,    36,    -1,    35,    -1,
      37,    -1,    38,    -1,   157,    -1,   190,    -1,   227,    -1,
     228,    -1,   229,    -1,   231,    -1,   233,    -1,   230,    -1,
     232,    -1,   234,    -1,   235,    -1,    53,    -1,   236,    -1,
      50,    -1,   283,    -1,   281,    -1,   282,    -1,   286,    -1,
     284,    -1,   285,    -1,    71,    -1,    72,    -1,    73,    -1,
      74,    -1,    75,    -1,    76,    -1,    77,    -1,    78,    -1,
      79,    -1,    80,    -1,    81,    -1,   275,    -1,   276,    -1,
     277,    -1,   278,    -1,   279,    -1,   280,    -1,   287,    -1,
     288,    -1,   289,    -1,   290,    -1,   291,    -1,   292,    -1,
     293,    -1,   294,    -1,   295,    -1,   296,    -1,   297,    -1,
     298,    -1,   236,   110,   407,    53,   142,   388,   172,    -1,
      53,   142,   388,   172,    -1,   546,    -1,   546,   545,    -1,
     546,   267,   438,    -1,   546,   545,   267,   438,    -1,   555,
      -1,   553,    -1,   545,   555,    -1,   545,   553,    -1,   547,
      -1,   546,   253,   547,    -1,   548,    -1,   547,   250,   548,
      -1,   549,    -1,   548,   252,   136,   549,    -1,   550,    -1,
     252,   550,    -1,   551,    -1,   551,   574,    -1,   145,   544,
     175,    -1,   552,    -1,   552,   570,    -1,   473,    -1,   142,
     385,   172,    -1,   554,    -1,   573,    -1,   572,    -1,   575,
      -1,   569,    -1,   157,    -1,   556,    -1,   557,    -1,   558,
      -1,   559,    -1,   562,    -1,   567,    -1,   568,    -1,   256,
      -1,   266,    -1,    92,   239,    -1,    92,   242,    -1,   226,
     241,    -1,   269,   241,    -1,   241,   239,    -1,   241,   242,
      -1,   226,   270,    -1,   269,   270,    -1,   226,   273,   561,
      -1,   226,   273,   105,    -1,   226,   273,   145,   561,   175,
      -1,   226,   273,   145,   561,    99,   560,   175,    -1,   226,
     273,   145,   105,   175,    -1,   226,   273,   145,   105,    99,
     560,   175,    -1,   269,   273,    -1,   561,    -1,   560,    99,
     561,    -1,    88,    20,    -1,    88,    20,   260,    20,    -1,
      88,    20,   571,   255,    -1,    88,    20,   260,    20,   571,
     255,    -1,   226,   271,   272,   564,    -1,   226,   271,   272,
     564,   563,    -1,   226,   105,   271,   272,    -1,   226,   105,
     271,   272,   563,    -1,   269,   271,   272,    -1,   566,    -1,
     563,   566,    -1,    88,    20,    -1,   145,   565,   175,    -1,
      20,    -1,   565,    20,    -1,   189,   564,    -1,   126,   564,
      -1,   254,    20,    -1,   226,   274,    -1,   269,   274,    -1,
      88,   206,    -1,    88,   246,    -1,   245,   247,    -1,   238,
      -1,   238,    47,    -1,   237,    -1,   237,   272,    -1,   259,
      -1,   248,   441,    -1,    88,   119,   441,    -1,    88,    43,
     441,    -1,   249,   441,   187,   441,    -1,   244,   571,   576,
      -1,   268,   441,   576,    -1,   257,   571,   265,    -1,   261,
     577,    -1,   243,   577,    -1,   272,    -1,   264,    -1,   258,
      -1,   263,    -1,   258,    -1,   269,   247,   441,    -1
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
     401,   404,   406,   408,   410,   412,   414,   416,   420,   424,
     432,   441,   443,   446,   448,   450,   452,   455,   457,   459,
     461,   465,   469,   474,   487,   502,   517,   532,   556,   559,
     562,   563,   565,   567,   568,   570,   572,   576,   580,   583,
     587,   592,   598,   601,   606,   610,   611,   615,   618,   620,
     624,   630,   634,   640,   643,   646,   649,   653,   657,   659,
     662,   665,   668,   673,   678,   683,   688,   690,   694,   697,
     701,   705,   709,   711,   713,   716,   718,   722,   724,   728,
     730,   732,   734,   736,   738,   740,   742,   744,   746,   748,
     750,   752,   754,   756,   758,   760,   762,   765,   768,   771,
     774,   776,   778,   781,   786,   790,   796,   801,   805,   807,
     809,   811,   813,   815,   817,   819,   821,   823,   826,   829,
     833,   836,   838,   843,   847,   852,   857,   863,   868,   874,
     880,   887,   891,   895,   899,   901,   906,   908,   913,   917,
     922,   927,   933,   938,   944,   946,   949,   953,   955,   958,
     960,   967,   971,   975,   977,   980,   984,   986,   990,   993,
     997,  1000,  1004,  1009,  1011,  1015,  1017,  1020,  1022,  1024,
    1026,  1029,  1032,  1035,  1039,  1041,  1043,  1046,  1049,  1052,
    1058,  1064,  1066,  1071,  1075,  1080,  1089,  1100,  1102,  1105,
    1110,  1118,  1127,  1129,  1133,  1135,  1139,  1141,  1145,  1149,
    1153,  1157,  1158,  1163,  1167,  1171,  1175,  1177,  1181,  1186,
    1188,  1192,  1194,  1198,  1202,  1204,  1208,  1212,  1216,  1220,
    1222,  1226,  1230,  1232,  1236,  1240,  1242,  1247,  1249,  1254,
    1256,  1261,  1263,  1268,  1270,  1273,  1275,  1277,  1280,  1283,
    1285,  1287,  1289,  1291,  1293,  1295,  1297,  1299,  1301,  1303,
    1305,  1307,  1312,  1318,  1324,  1331,  1335,  1340,  1342,  1345,
    1349,  1352,  1354,  1357,  1360,  1362,  1364,  1366,  1370,  1374,
    1376,  1378,  1380,  1383,  1385,  1388,  1391,  1393,  1395,  1397,
    1399,  1401,  1403,  1405,  1407,  1409,  1412,  1415,  1417,  1419,
    1421,  1423,  1425,  1427,  1429,  1431,  1433,  1435,  1437,  1439,
    1441,  1443,  1446,  1448,  1451,  1455,  1457,  1459,  1461,  1463,
    1465,  1467,  1469,  1471,  1473,  1475,  1477,  1479,  1481,  1484,
    1487,  1491,  1493,  1498,  1503,  1507,  1512,  1514,  1518,  1520,
    1522,  1524,  1526,  1528,  1533,  1539,  1548,  1558,  1568,  1579,
    1581,  1584,  1586,  1589,  1596,  1597,  1599,  1603,  1607,  1608,
    1610,  1612,  1614,  1617,  1620,  1621,  1623,  1625,  1627,  1630,
    1633,  1635,  1637,  1639,  1641,  1643,  1645,  1647,  1649,  1651,
    1653,  1655,  1657,  1661,  1664,  1668,  1672,  1675,  1677,  1679,
    1681,  1683,  1685,  1687,  1692,  1697,  1703,  1710,  1718,  1723,
    1729,  1736,  1744,  1749,  1754,  1759,  1765,  1772,  1780,  1782,
    1785,  1788,  1790,  1793,  1797,  1799,  1801,  1803,  1805,  1807,
    1811,  1813,  1815,  1817,  1819,  1821,  1823,  1825,  1827,  1829,
    1831,  1835,  1839,  1844,  1849,  1853,  1857,  1861,  1866,  1871,
    1875,  1880,  1887,  1892,  1899,  1903,  1907,  1912,  1919,  1926,
    1931,  1938,  1945,  1950,  1952,  1955,  1957,  1961,  1965,  1969,
    1975,  1983,  1991,  1997,  2003,  2009,  2017,  2025,  2031,  2037,
    2041,  2045,  2051,  2059,  2065,  2073,  2075,  2080,  2084,  2090,
    2092,  2095,  2099,  2107,  2118,  2132,  2134,  2138,  2140,  2142,
    2144,  2146,  2148,  2150,  2152,  2154,  2156,  2158,  2160,  2162,
    2164,  2166,  2168,  2170,  2172,  2174,  2176,  2178,  2180,  2182,
    2184,  2186,  2188,  2190,  2192,  2194,  2196,  2198,  2200,  2202,
    2204,  2206,  2208,  2210,  2212,  2214,  2216,  2218,  2220,  2222,
    2224,  2226,  2228,  2230,  2232,  2234,  2236,  2238,  2240,  2242,
    2244,  2246,  2248,  2250,  2252,  2254,  2256,  2258,  2260,  2262,
    2264,  2266,  2268,  2270,  2272,  2274,  2276,  2278,  2280,  2282,
    2284,  2286,  2288,  2290,  2292,  2294,  2296,  2298,  2300,  2302,
    2304,  2306,  2308,  2310,  2312,  2314,  2316,  2318,  2320,  2322,
    2324,  2326,  2328,  2330,  2332,  2334,  2336,  2338,  2340,  2342,
    2344,  2346,  2348,  2350,  2352,  2354,  2356,  2358,  2360,  2362,
    2364,  2366,  2368,  2370,  2372,  2374,  2376,  2378,  2380,  2382,
    2384,  2386,  2388,  2390,  2392,  2394,  2396,  2398,  2400,  2402,
    2404,  2406,  2408,  2410,  2412,  2414,  2416,  2418,  2420,  2422,
    2424,  2426,  2428,  2430,  2432,  2434,  2436,  2438,  2440,  2442,
    2444,  2446,  2448,  2450,  2452,  2454,  2456,  2458,  2460,  2462,
    2464,  2466,  2468,  2470,  2472,  2474,  2476,  2478,  2480,  2482,
    2484,  2486,  2488,  2490,  2492,  2494,  2496,  2498,  2500,  2502,
    2504,  2506,  2508,  2510,  2512,  2514,  2516,  2518,  2520,  2522,
    2524,  2526,  2528,  2530,  2532,  2534,  2536,  2538,  2540,  2542,
    2544,  2546,  2548,  2550,  2552,  2560,  2565,  2567,  2570,  2574,
    2579,  2581,  2583,  2586,  2589,  2591,  2595,  2597,  2601,  2603,
    2608,  2610,  2613,  2615,  2618,  2622,  2624,  2627,  2629,  2633,
    2635,  2637,  2639,  2641,  2643,  2645,  2647,  2649,  2651,  2653,
    2655,  2657,  2659,  2661,  2663,  2666,  2669,  2672,  2675,  2678,
    2681,  2684,  2687,  2691,  2695,  2701,  2709,  2715,  2723,  2726,
    2728,  2732,  2735,  2740,  2745,  2752,  2757,  2763,  2768,  2774,
    2778,  2780,  2783,  2786,  2790,  2792,  2795,  2798,  2801,  2804,
    2807,  2810,  2813,  2816,  2819,  2821,  2824,  2826,  2829,  2831,
    2834,  2838,  2842,  2847,  2851,  2855,  2859,  2862,  2865,  2867,
    2869,  2871,  2873,  2875
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   940,   940,   941,   951,   956,   962,   967,   979,   984,
     994,  1001,  1013,  1019,  1031,  1044,  1048,  1052,  1064,  1070,
    1084,  1090,  1104,  1105,  1106,  1107,  1113,  1114,  1115,  1116,
    1119,  1122,  1125,  1128,  1130,  1136,  1141,  1150,  1156,  1165,
    1174,  1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,
    1190,  1191,  1192,  1193,  1194,  1195,  1196,  1199,  1206,  1207,
    1219,  1231,  1236,  1247,  1253,  1265,  1278,  1289,  1294,  1306,
    1311,  1322,  1328,  1334,  1340,  1359,  1370,  1381,  1388,  1395,
    1402,  1415,  1421,  1436,  1440,  1450,  1457,  1465,  1472,  1485,
    1492,  1498,  1505,  1511,  1515,  1522,  1533,  1538,  1547,  1556,
    1563,  1573,  1581,  1589,  1597,  1605,  1611,  1619,  1627,  1638,
    1644,  1652,  1656,  1660,  1664,  1668,  1672,  1681,  1685,  1693,
    1701,  1713,  1719,  1728,  1732,  1736,  1740,  1744,  1748,  1756,
    1762,  1771,  1778,  1789,  1801,  1813,  1825,  1837,  1860,  1863,
    1867,  1871,  1875,  1882,  1886,  1890,  1901,  1906,  1918,  1922,
    1926,  1930,  1937,  1944,  1970,  1980,  1986,  1992,  2001,  2011,
    2024,  2032,  2039,  2053,  2057,  2064,  2069,  2076,  2084,  2088,
    2092,  2100,  2107,  2116,  2128,  2137,  2150,  2158,  2172,  2179,
    2192,  2200,  2211,  2226,  2230,  2246,  2250,  2259,  2263,  2280,
    2281,  2282,  2283,  2284,  2287,  2288,  2289,  2290,  2291,  2293,
    2294,  2297,  2298,  2299,  2300,  2301,  2308,  2321,  2328,  2332,
    2340,  2344,  2348,  2355,  2359,  2366,  2374,  2385,  2395,  2396,
    2397,  2401,  2401,  2401,  2401,  2401,  2404,  2410,  2419,  2423,
    2433,  2444,  2450,  2464,  2472,  2481,  2491,  2502,  2511,  2521,
    2531,  2547,  2560,  2572,  2584,  2590,  2602,  2608,  2622,  2631,
    2641,  2650,  2663,  2670,  2681,  2682,  2687,  2696,  2700,  2705,
    2709,  2715,  2720,  2728,  2744,  2752,  2759,  2765,  2776,  2783,
    2793,  2803,  2808,  2820,  2826,  2840,  2846,  2858,  2865,  2872,
    2879,  2886,  2893,  2900,  2913,  2917,  2927,  2931,  2941,  2952,
    2959,  2972,  2979,  2991,  2998,  3012,  3019,  3034,  3040,  3052,
    3058,  3072,  3083,  3087,  3098,  3102,  3121,  3125,  3133,  3141,
    3149,  3157,  3157,  3165,  3173,  3181,  3195,  3199,  3206,  3219,
    3223,  3234,  3238,  3242,  3252,  3256,  3260,  3264,  3268,  3278,
    3282,  3287,  3298,  3302,  3306,  3316,  3320,  3332,  3336,  3348,
    3352,  3364,  3368,  3380,  3384,  3396,  3400,  3404,  3408,  3420,
    3424,  3428,  3438,  3442,  3446,  3450,  3454,  3458,  3468,  3472,
    3476,  3486,  3490,  3494,  3498,  3510,  3516,  3528,  3534,  3548,
    3555,  3596,  3600,  3604,  3608,  3620,  3630,  3641,  3646,  3656,
    3660,  3670,  3676,  3682,  3688,  3700,  3706,  3717,  3721,  3725,
    3729,  3733,  3737,  3741,  3751,  3755,  3765,  3769,  3780,  3784,
    3788,  3792,  3796,  3811,  3815,  3825,  3829,  3839,  3846,  3853,
    3866,  3870,  3882,  3888,  3902,  3913,  3917,  3921,  3925,  3929,
    3933,  3937,  3941,  3951,  3955,  3965,  3970,  3975,  3986,  3997,
    4001,  4012,  4022,  4033,  4089,  4095,  4107,  4113,  4125,  4129,
    4139,  4143,  4147,  4157,  4165,  4173,  4181,  4189,  4197,  4212,
    4218,  4230,  4236,  4249,  4258,  4260,  4266,  4271,  4283,  4286,
    4293,  4299,  4305,  4313,  4328,  4331,  4338,  4344,  4350,  4358,
    4372,  4377,  4388,  4393,  4404,  4409,  4414,  4420,  4432,  4438,
    4443,  4448,  4459,  4464,  4479,  4484,  4501,  4516,  4520,  4524,
    4528,  4532,  4536,  4546,  4557,  4563,  4569,  4574,  4596,  4602,
    4608,  4613,  4624,  4634,  4644,  4650,  4656,  4661,  4672,  4678,
    4690,  4701,  4707,  4713,  4750,  4755,  4760,  4771,  4775,  4779,
    4789,  4800,  4804,  4808,  4812,  4816,  4820,  4824,  4828,  4832,
    4842,  4852,  4856,  4861,  4872,  4882,  4892,  4896,  4900,  4910,
    4916,  4922,  4928,  4934,  4946,  4957,  4964,  4971,  4978,  4985,
    4992,  4999,  5012,  5033,  5040,  5060,  5100,  5104,  5108,  5117,
    5123,  5129,  5135,  5141,  5148,  5154,  5160,  5166,  5172,  5184,
    5189,  5199,  5205,  5217,  5243,  5254,  5260,  5273,  5289,  5296,
    5302,  5313,  5320,  5330,  5341,  5357,  5363,  5373,  5382,  5383,
    5401,  5405,  5412,  5413,  5414,  5415,  5416,  5417,  5418,  5419,
    5420,  5421,  5422,  5423,  5424,  5425,  5426,  5427,  5428,  5429,
    5430,  5431,  5432,  5433,  5434,  5435,  5436,  5437,  5438,  5439,
    5440,  5441,  5442,  5443,  5444,  5445,  5446,  5447,  5448,  5449,
    5450,  5451,  5452,  5453,  5454,  5455,  5456,  5457,  5458,  5459,
    5460,  5461,  5462,  5463,  5464,  5465,  5466,  5467,  5468,  5469,
    5470,  5471,  5472,  5473,  5474,  5475,  5476,  5477,  5478,  5479,
    5480,  5481,  5482,  5483,  5484,  5485,  5486,  5487,  5488,  5489,
    5490,  5491,  5492,  5493,  5494,  5495,  5496,  5497,  5498,  5499,
    5500,  5501,  5502,  5503,  5504,  5505,  5506,  5507,  5508,  5509,
    5510,  5511,  5512,  5513,  5514,  5515,  5516,  5517,  5518,  5519,
    5520,  5521,  5522,  5523,  5524,  5525,  5526,  5527,  5528,  5529,
    5530,  5531,  5532,  5533,  5534,  5535,  5536,  5537,  5538,  5539,
    5540,  5541,  5542,  5543,  5544,  5545,  5546,  5547,  5548,  5549,
    5550,  5551,  5552,  5553,  5554,  5555,  5556,  5557,  5558,  5559,
    5560,  5561,  5562,  5563,  5564,  5565,  5566,  5567,  5568,  5569,
    5570,  5571,  5572,  5573,  5574,  5575,  5576,  5577,  5578,  5579,
    5580,  5581,  5582,  5583,  5584,  5585,  5586,  5587,  5588,  5589,
    5590,  5591,  5592,  5593,  5594,  5595,  5596,  5597,  5598,  5599,
    5600,  5601,  5602,  5603,  5604,  5605,  5606,  5607,  5608,  5609,
    5610,  5611,  5612,  5613,  5624,  5630,  5647,  5651,  5655,  5659,
    5669,  5672,  5675,  5678,  5687,  5690,  5699,  5702,  5711,  5714,
    5723,  5726,  5735,  5738,  5741,  5750,  5753,  5762,  5766,  5776,
    5779,  5782,  5785,  5788,  5797,  5806,  5810,  5814,  5818,  5822,
    5826,  5830,  5840,  5843,  5846,  5849,  5858,  5861,  5864,  5867,
    5876,  5879,  5888,  5891,  5894,  5897,  5900,  5903,  5906,  5915,
    5918,  5927,  5930,  5933,  5936,  5945,  5948,  5951,  5954,  5957,
    5966,  5969,  5978,  5981,  5990,  5993,  6002,  6005,  6014,  6023,
    6026,  6035,  6038,  6041,  6050,  6053,  6056,  6059,  6062,  6071,
    6075,  6079,  6083,  6093,  6102,  6112,  6121,  6124,  6133,  6136,
    6139,  6148,  6151,  6160
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
  const int xquery_parser::yylast_ = 10953;
  const int xquery_parser::yynnts_ = 265;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 523;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 314;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 568;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 14236 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6168 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"


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

