
/* A Bison parser, made by GNU Bison 2.4.  */

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
#line 45 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"


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
#line 872 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"

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
#line 756 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 268 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 114: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 755 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 277 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 138: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 754 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 286 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 298: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 295 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 299: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 304 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 300: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 313 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 301: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 322 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 302: /* "Prolog" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 331 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 303: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 340 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 304: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 349 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 305: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 358 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 306: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 367 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 307: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 376 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 308: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 768 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->pair_vector); };

/* Line 480 of lalr1.cc  */
#line 385 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 309: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 768 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->pair); };

/* Line 480 of lalr1.cc  */
#line 394 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 311: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 403 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 312: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 412 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 313: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 421 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 314: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 430 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 315: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 439 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 316: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 448 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 457 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 466 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 475 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 484 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 493 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 502 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 511 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 520 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 529 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 538 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 547 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 556 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 565 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 768 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 574 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 583 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 592 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "IndexDecl2" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 601 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "IndexDecl3" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 610 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "IndexDeclSuffix" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 619 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 628 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 637 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "IndexKeySpec1" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 646 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 655 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 768 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 664 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 673 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "Block" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 682 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "BlockDecls" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 691 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "BlockVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 700 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "BlockVarDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 709 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "AssignExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 718 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "ExitExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 727 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "WhileExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 736 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 745 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 754 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 763 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "FunctionDecl3" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 772 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "FunctionDecl4" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 781 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 790 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 799 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "EnclosedExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 808 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 817 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 826 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 835 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "ApplyExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 844 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "ConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 853 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 862 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 871 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 880 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 889 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 898 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 907 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 916 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 925 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 934 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 943 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 952 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 961 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 970 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 979 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "EvalVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 988 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 997 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1006 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1015 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1024 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1033 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "EvalVarDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1042 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1051 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1060 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1069 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1078 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1087 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1096 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1105 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1114 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1123 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1132 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1141 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1150 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1159 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1168 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1177 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1186 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1195 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1204 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1213 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1222 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1231 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1240 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1249 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1258 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1267 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1276 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1285 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1294 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1303 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1312 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1321 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1330 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1339 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1348 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1357 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1366 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1375 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1384 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1393 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "PragmaList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1402 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1411 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1420 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1429 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1438 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1447 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1456 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1465 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1474 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1483 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1492 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1501 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1510 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1519 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1528 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1537 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1546 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1555 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1564 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1573 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1582 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1591 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1600 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1609 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1618 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1627 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1636 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1645 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1654 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1663 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1672 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1681 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1690 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1699 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "Opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1708 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1717 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "Opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1726 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1735 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1744 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1753 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1762 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1771 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1780 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1789 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1798 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1807 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1816 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1825 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1834 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1843 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1852 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1861 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1870 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1879 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1888 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1897 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1906 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1915 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1924 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1933 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1942 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1951 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1960 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1969 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1978 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1987 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1996 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2005 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2014 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2023 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2032 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2041 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2050 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2059 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2068 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2077 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2086 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2095 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2104 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2113 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2122 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 768 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2131 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2140 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "EvalExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2149 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
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
#line 94 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename);
}

/* Line 553 of lalr1.cc  */
#line 2234 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"

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
#line 890 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 900 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		}
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 905 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<MainModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr ((yyval.node));
		}
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 911 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
       driver.set_expr ((yyval.node));
		}
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 916 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
       driver.set_expr ((yyval.node));
		}
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 928 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)), encoding);
		}
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 933 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 943 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)));
		}
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 950 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)),
                NULL);
		}
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 962 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC ((yyloc)),
                             static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)),
                             NULL);
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 968 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LibraryModule(LOC ((yyloc)),
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 980 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), 
								SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
      dynamic_cast<ModuleDecl *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
		}
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 993 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)),
								NULL);
		}
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 999 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								NULL,
								static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		}
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1005 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
								static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1017 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = new SIND_DeclList(LOC ((yyloc)));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		}
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1023 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1037 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = new VFO_DeclList(LOC ((yyloc)));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		}
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1043 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (vfoList_p) {
				vfoList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 1083 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].pair_vector));
      delete (yysemantic_stack_[(4) - (4)].pair_vector);
    }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 1088 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr))->get_qname(), (yysemantic_stack_[(4) - (4)].pair_vector)); 
      delete (yysemantic_stack_[(4) - (3)].expr);
      delete (yysemantic_stack_[(4) - (4)].pair_vector);
    }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 1097 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { 
      (yyval.pair_vector) = new std::vector<std::pair<std::string, std::string> > ();
      (yyval.pair_vector)->push_back(*(yysemantic_stack_[(1) - (1)].pair));
      delete (yysemantic_stack_[(1) - (1)].pair);
    }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 1103 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].pair_vector)->push_back(*(yysemantic_stack_[(2) - (2)].pair));
      delete (yysemantic_stack_[(2) - (2)].pair);
      (yyval.pair_vector) = (yysemantic_stack_[(2) - (1)].pair_vector);
    }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 1112 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *s = static_cast<StringLiteral *>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.pair) = new std::pair<std::string, std::string>((yysemantic_stack_[(3) - (1)].strval), s->get_strval());
      delete s;
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 1120 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1121 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1122 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1123 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1124 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1125 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1126 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1127 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1128 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1129 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 1166 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 1178 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		}
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1183 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		}
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1194 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_element_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1200 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_function_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1212 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OptionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
								SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
		}
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1225 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (3)].node));
		}
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1236 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		}
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1241 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		}
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1253 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		}
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1258 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		}
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1269 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::inherit_ns);
		}
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1275 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::no_inherit_ns);
		}
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1281 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::inherit_ns);
		}
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1287 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::no_inherit_ns);
		}
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1306 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)));
		}
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1317 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		}
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1328 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		}
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1335 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)),
								NULL);
		}
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1342 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		}
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1349 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
		}
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 1362 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = new URILiteralList(LOC ((yyloc)));
			uri_list_p->push_back(SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		}
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 1368 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node));
			if (uri_list_p) {
				uri_list_p->push_back(SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 1383 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1387 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		}
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1397 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1404 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
								SYMTAB ((yysemantic_stack_[(6) - (6)].sval)),
								NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
		}
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1412 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
		}
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1419 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(8) - (4)].sval)),
								SYMTAB ((yysemantic_stack_[(8) - (6)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
		}
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1432 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1439 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->type = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1445 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1452 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(1) - (1)].node));
      d->ext = false;
      (yyval.node) = d;
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1458 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), NULL);
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1462 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1469 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1480 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(), NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1485 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
                               dynamic_cast<SequenceType *> ((yysemantic_stack_[(3) - (3)].node)));
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1494 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(5) - (3)].varnametype)));
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								nt->name,
								nt->type,
								(yysemantic_stack_[(5) - (5)].expr));
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
		}
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1503 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (3)].varnametype)));
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       NULL, true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
		}
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1510 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(6) - (3)].varnametype)));
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       (yysemantic_stack_[(6) - (6)].expr), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
		}
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1521 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1525 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexDecl*>((yysemantic_stack_[(3) - (3)].node))->setUnique();
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1533 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1537 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1541 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexDecl*>((yysemantic_stack_[(2) - (2)].node))->setOrdered();
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1549 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1553 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1557 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexDecl*>((yysemantic_stack_[(2) - (2)].node))->setAutomatic();
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1565 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(7) - (2)].expr)),
                         (yysemantic_stack_[(7) - (4)].expr),
                         dynamic_cast<IndexKeyList*>((yysemantic_stack_[(7) - (6)].node)));
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 1575 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* l = new IndexKeyList(LOC((yyloc)));
      l->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 1581 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1589 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1593 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (1)].node))->setCollation(SYMTAB((yysemantic_stack_[(3) - (3)].sval)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1601 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL);
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1605 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1615 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		}
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1620 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		}
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1632 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1636 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1640 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL, dynamic_cast<SequenceType *> ((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1644 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType *> ((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1651 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1658 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 122:

/* Line 678 of lalr1.cc  */
#line 1677 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (1)].node));
      std::auto_ptr<VFO_DeclList> vfo2(dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (2)].node)));
      if ((yysemantic_stack_[(3) - (1)].node) == NULL)
        vfo = new VFO_DeclList (LOC ((yyloc)));
      vfo->push_back (*(vfo2.get()));
      (yyval.node) = vfo;
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1686 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL;
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1693 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (1)].node));
      vfo->push_back ((yysemantic_stack_[(3) - (3)].node));
      (yyval.node) = vfo;
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1699 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = new VFO_DeclList (LOC ((yyloc)));
      vfo->push_back ((yysemantic_stack_[(2) - (2)].node));
      (yyval.node) = vfo;
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1708 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 127:

/* Line 678 of lalr1.cc  */
#line 1718 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 128:

/* Line 678 of lalr1.cc  */
#line 1731 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr (LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr))->get_qname(), (yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (3)].expr);
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1739 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr (LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1746 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *b = dynamic_cast<BlockBody *> ((yysemantic_stack_[(5) - (5)].expr));
      if (b == NULL) {
        b = new BlockBody ((yysemantic_stack_[(5) - (5)].expr)->get_location ()); 
        b->add ((yysemantic_stack_[(5) - (5)].expr));
      }
      (yyval.expr) = new WhileExpr (LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), b);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1758 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1762 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::CONTINUE);
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1769 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { 
      dynamic_cast<FunctionDecl *>((yysemantic_stack_[(2) - (2)].node))->setComment(SYMTAB((yysemantic_stack_[(2) - (1)].sval)));
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1774 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
      d->deterministic = false;
      (yyval.node) = d;
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1781 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<FunctionDecl *>((yysemantic_stack_[(3) - (3)].node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1789 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1793 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1797 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(2) - (2)].node));
      d->type = (d->type == ParseConstants::fn_extern)
        ? ParseConstants::fn_extern_update
        : ParseConstants::fn_update;
      (yyval.node) = d;
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1805 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1812 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								(yysemantic_stack_[(4) - (4)].expr),
								ParseConstants::fn_read);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1821 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								NULL,
								ParseConstants::fn_extern);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1833 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								(yysemantic_stack_[(4) - (4)].expr),
								ParseConstants::fn_sequential);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1842 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								NULL,
								ParseConstants::fn_extern_sequential);
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1855 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = new ParamList(LOC ((yyloc)));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)));
			}
			(yyval.node) = plist_p;
		}
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1863 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1877 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(),
								NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
		}
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1884 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
      delete (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1897 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1905 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1916 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QueryBody(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
		}
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1927 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1931 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<BlockBody> blk(dynamic_cast<BlockBody *> ((yysemantic_stack_[(2) - (2)].expr)));
      BlockBody  *blk2 = new BlockBody (LOC ((yyloc)));
      (yyval.expr) = blk2;
      blk2->add ((yysemantic_stack_[(2) - (1)].expr));
      for (int i = 0; i < blk->size (); i++)
        blk2->add ((*blk) [i]);
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1943 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody (LOC ((yyloc)));
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1947 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = dynamic_cast<BlockBody *> ((yysemantic_stack_[(3) - (1)].expr));
      blk->add ((yysemantic_stack_[(3) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1956 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1960 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 174:

/* Line 678 of lalr1.cc  */
#line 2004 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      ReturnExpr* lReturnExpr = dynamic_cast<ReturnExpr*>((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = new FLWORExpr (LOC ((yyloc)), dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node)), lReturnExpr->get_return_val(), lReturnExpr->get_location(), driver.theCompilerCB->m_config.force_gflwor);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 2013 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 2020 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 2024 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 2032 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2036 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2040 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_only_end;
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2047 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), dynamic_cast<WindowVars *> ((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr), (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 2051 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr), (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 2058 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(5) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window,
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(5) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (4)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 2066 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window,
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 2077 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause (LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 2096 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = new FLWORClauseList (LOC ((yyloc)));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 2102 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = dynamic_cast<FLWORClauseList *> ((yysemantic_stack_[(2) - (1)].node));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 2111 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = NULL;
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 2115 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_ofor;
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 2125 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForClause(LOC ((yyloc)),
                         dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL);
		}
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 2136 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		}
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 2142 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vardecl_list_p) {
				vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2156 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (1)].expr);
		}
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 2164 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 2173 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 204:

/* Line 678 of lalr1.cc  */
#line 2183 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 205:

/* Line 678 of lalr1.cc  */
#line 2194 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 2203 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 207:

/* Line 678 of lalr1.cc  */
#line 2213 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 208:

/* Line 678 of lalr1.cc  */
#line 2223 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 209:

/* Line 678 of lalr1.cc  */
#line 2239 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
		}
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 2252 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
		}
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 2264 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)));
			
		}
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 2276 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		}
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 2282 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 2294 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		}
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 2300 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 2314 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
								NULL,
								NULL,
								(yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (1)].expr);
		}
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 2323 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 2333 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 2342 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (1)].expr);
		}
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 2355 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr))->get_qname(),
								NULL, (yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (2)].expr);
		}
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 2362 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (2)].expr);
		}
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 2374 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(), "", "");
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 2379 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_curr (static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 2388 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), dynamic_cast<PositionalVar *> ((yysemantic_stack_[(1) - (1)].node)), "", "", "");
    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 2392 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_posvar (dynamic_cast<PositionalVar *> ((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 2401 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr))->get_qname(), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr))->get_qname());
      delete (yysemantic_stack_[(6) - (3)].expr);
      delete (yysemantic_stack_[(6) - (6)].expr);
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 2407 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", "", static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 2412 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname(), "");
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 2420 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::string name = static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr))->get_qname();
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           name, NULL, NULL,
                           new VarRef (LOC ((yyloc)), name),
                           VarGetsDecl::eval_var);
      delete (yysemantic_stack_[(1) - (1)].expr);
                           
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 2436 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 2444 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 2451 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = new GroupSpecList(LOC((yyloc)));
      gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl_p;
    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 2457 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      if (gsl_p) {
        gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      }
      (yyval.node) = gsl_p;
    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 2468 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(),
                 NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 2475 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), 
                 static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(), 
                 dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node))); 
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 2485 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 2495 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 2500 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)),
								true);
		}
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 2512 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		}
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 2518 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node));
			if (osl_p) {
				osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 2532 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		}
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2538 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<OrderModifier*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 2550 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL,
								NULL);
		}
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2557 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		}
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 2564 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2571 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
								NULL);
		}
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2578 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2585 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2592 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 2605 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		}
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2609 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		}
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 2619 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		}
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 2624 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		}
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 2635 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		}
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 2646 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 2653 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2666 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;
				
		}
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2673 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2685 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
								(yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (1)].expr);
		}
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2692 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2706 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
								(yysemantic_stack_[(8) - (8)].expr));
		}
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2713 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(10) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
								static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr))->get_qname(),
								(yysemantic_stack_[(10) - (10)].expr));
      delete (yysemantic_stack_[(10) - (8)].expr);
		}
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2728 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		}
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2734 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2746 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2752 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr))->get_qname(),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
      delete (yysemantic_stack_[(7) - (3)].expr);
		}
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2766 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
		}
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2777 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2781 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2792 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2796 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2815 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2819 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2827 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      /*  ::=  "is" | "<<" | ">>" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 2835 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2843 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2850 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { /* this call is needed */  driver.lexer->interpretAsLessThan(); }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2851 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2859 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_le),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2867 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2875 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2889 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2893 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		}
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2900 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2913 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2917 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2928 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 2932 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 2936 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 2946 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 2950 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 2954 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 2958 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 2962 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 2972 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 2976 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 2981 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 2992 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 2996 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3000 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3010 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3014 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3026 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3030 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3042 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3046 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3058 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3062 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3074 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3078 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3090 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		}
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3094 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		}
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3098 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3102 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3114 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3118 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3122 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3132 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		}
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3136 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		}
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3140 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		}
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3144 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		}
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3148 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		}
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3152 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		}
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3162 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		}
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3166 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		}
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3170 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		}
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3180 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3184 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3188 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3192 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                            dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(),
                            (yysemantic_stack_[(6) - (5)].expr));
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3204 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		}
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3210 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3222 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		}
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3228 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node));
			if (pragma_list_p) {
				pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3242 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));

		}
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3248 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval))),
								"");      
    }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3290 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		}
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3294 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3298 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3302 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (rpe == NULL ?
             (yysemantic_stack_[(1) - (1)].expr) :
             new PathExpr(LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3314 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3324 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 345:

/* Line 678 of lalr1.cc  */
#line 3335 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3340 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3350 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3354 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3364 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		}
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3370 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3376 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		}
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3382 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3394 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		}
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3400 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3411 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		}
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3415 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		}
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3419 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		}
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3423 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		}
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3427 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		}
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3431 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		}
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3435 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		}
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3445 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node), false);
		}
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3449 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		}
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3459 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseStep(LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node));
		}
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3463 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC((yyloc)), rev_p, NULL);
		}
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3474 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		}
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3478 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		}
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3482 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		}
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3486 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		}
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3490 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		}
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3505 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3509 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3519 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3523 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3533 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        "",
                        ParseConstants::wild_all);
		}
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3540 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        ParseConstants::wild_elem);
		}
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3547 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        ParseConstants::wild_prefix);
		}
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3560 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3564 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
                          (yysemantic_stack_[(2) - (1)].expr),
                          dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3576 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		}
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3582 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node));
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3596 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3607 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3611 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3615 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3619 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3623 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3627 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3631 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3635 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3645 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3649 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3659 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval));
      delete yylval.decval;
		}
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3664 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival));
      delete yylval.ival;
		}
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3669 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval));
      delete yylval.dval;
		}
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3680 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new VarRef(LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname());
      delete (yysemantic_stack_[(2) - (2)].expr);
		}
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3691 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		}
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3695 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3706 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		}
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3716 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3727 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3783 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)),
								NULL);
		}
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3789 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3801 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = new ArgList(LOC ((yyloc))); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		}
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3807 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3819 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3823 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3833 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3837 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3841 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3851 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
								NULL,
								NULL,
								NULL);
		}
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3859 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
								NULL,
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)), 
								NULL);
		}
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3867 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(8) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr)),
								NULL,
								NULL);
		}
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3875 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
								NULL,
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node)));
		}
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3883 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
								NULL);
		}
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3891 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(10) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)), 
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node)));
		}
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3906 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		}
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3912 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3924 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		}
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3930 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3943 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
		}
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 3960 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		}
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 3965 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		}
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 3976 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		}
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 3980 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 3987 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		}
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 3993 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		}
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 3999 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 4007 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 4021 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		}
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 4025 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 4032 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		}
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 4038 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		}
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 4044 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 4052 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4066 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4071 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4082 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4087 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4098 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		}
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4103 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4108 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		}
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4114 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		}
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4126 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4132 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		}
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4137 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		}
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4142 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4153 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4158 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4173 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4178 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		}
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4195 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CDataSection(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		}
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4210 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4214 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4218 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4222 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4226 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4230 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4240 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4251 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
								NULL);
		}
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4257 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4263 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4268 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4290 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (2)].expr),
								NULL);
		}
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4296 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4302 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4307 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4318 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4328 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4338 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		}
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4344 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4350 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4355 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4366 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		}
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4372 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		}
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4384 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
		}
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4395 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		}
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4401 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4407 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		}
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4444 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		}
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4449 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		}
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4454 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		}
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4465 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4469 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4473 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		}
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4483 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4494 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4498 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4502 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4506 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4510 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4514 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4518 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4522 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4526 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4536 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		}
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4546 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		}
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4550 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4555 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4566 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TextTest(LOC ((yyloc)));
		}
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4576 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		}
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4586 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		}
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4590 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		}
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4594 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		}
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4604 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		}
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4610 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
								NULL);
		}
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4616 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		}
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4622 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		}
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4628 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		}
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4640 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
		}
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4651 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           NULL,
                           NULL,
                           true);
		}
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4658 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                           NULL,
                           true);
		}
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4665 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           false);
		}
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4672 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           true);
		}
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4679 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL,
									true);
		}
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4686 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									false);
		}
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4693 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									true);
		}
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4706 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)));
		}
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4727 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4734 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)),
								true);
		}
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4754 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4794 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::strict_validation);
		}
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4798 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::lax_validation);
    }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4802 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::skip_validation);
    }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4811 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4817 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4823 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4829 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4835 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4842 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4848 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4854 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4860 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4866 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4878 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4883 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4893 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4899 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4911 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4937 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4948 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       CopyVarList* lList = new CopyVarList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
		}
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4954 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
       VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
       lList->push_back(lBinding);
       (yyval.expr) = lList;
		}
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4967 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(), (yysemantic_stack_[(3) - (3)].expr));  
       delete (yysemantic_stack_[(3) - (1)].expr);
    }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4982 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4989 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4995 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* aCatchListExpr = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if (aCatchListExpr) {
        aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)));
      }
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 5006 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(3) - (2)].name_test_list),
                          (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 5013 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(7) - (2)].name_test_list),
                          static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr))->get_qname(),
                          (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (5)].expr);
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 5023 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 552:

/* Line 678 of lalr1.cc  */
#line 5034 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 553:

/* Line 678 of lalr1.cc  */
#line 5050 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CatchExpr::NameTestList *name_test_list = new CatchExpr::NameTestList;
      name_test_list->push_back (static_cast<NameTest *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.name_test_list) = name_test_list;
    }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 5056 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      CatchExpr::NameTestList *name_test_list =
        static_cast<CatchExpr::NameTestList *> ((yysemantic_stack_[(3) - (1)].name_test_list));
      name_test_list->push_back (static_cast<NameTest *> ((yysemantic_stack_[(3) - (3)].node)));
      (yyval.name_test_list) = name_test_list;
    }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 5076 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
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

  case 558:

/* Line 678 of lalr1.cc  */
#line 5094 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { 
      (yyval.expr) = new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval))); 
    }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 5098 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { 
      (yyval.expr) = new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval))); 
    }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 5104 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("xquery"); }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 5105 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty"); }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 5106 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("attribute"); }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 5107 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("comment"); }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 5108 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document-node"); }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 5109 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("element"); }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 5110 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("item"); }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 5111 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("if"); }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 5112 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("node"); }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5113 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("processing-instruction"); }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5114 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-attribute"); }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5115 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-element"); }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5116 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("text"); }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5117 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("typeswitch"); }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5118 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty-sequence"); }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5119 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("boundary-space"); }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5120 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ft-option"); }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5121 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("base-uri"); }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5122 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lax"); }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5123 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strict"); }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5124 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("idiv"); }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5125 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document"); }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5126 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("not"); }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5127 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sensitive"); }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5128 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insensitive"); }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5129 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("diacritics"); }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5130 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("without"); }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5131 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stemming"); }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5132 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("thesaurus"); }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5133 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stop"); }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5134 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("wildcards"); }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5135 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("entire"); }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5136 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("content"); }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5137 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("word"); }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5138 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("start"); }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5139 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("end"); }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5140 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("most"); }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5141 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("skip"); }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5142 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy"); }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5143 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("value"); }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5144 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eq"); }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5145 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ne"); }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5146 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lt"); }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5147 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("le"); }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5148 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("gt"); }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5149 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ge"); }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5150 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("at"); }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5151 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("context"); }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5152 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("variable"); }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5153 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("return"); }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5154 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("for"); }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5155 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("outer"); }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5156 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sliding"); }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5157 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("tumbling"); }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5158 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("previous"); }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5159 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("next"); }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5160 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("only"); }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5161 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("when"); }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5162 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("count"); }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5163 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("in"); }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5164 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("let"); }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5165 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("where"); }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5166 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("by"); }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5167 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("group"); }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5168 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("order"); }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5169 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stable"); }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5170 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ascending"); }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5171 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("descending"); }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5172 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("greatest"); }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5173 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("least"); }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5174 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("collation"); }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5175 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("some"); }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5176 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("every"); }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5177 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("satisfies"); }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5178 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("case"); }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5179 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("as"); }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5180 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("then"); }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5181 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("else"); }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5182 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("or"); }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5183 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("and"); }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5184 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("instance"); }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5185 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("of"); }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5186 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("castable"); }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5187 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("to"); }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5188 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("div"); }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5189 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("mod"); }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5190 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("union"); }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5191 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("intersect"); }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5192 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("except"); }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5193 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("validate"); }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5194 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("cast"); }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5195 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("treat"); }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5196 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("is"); }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5197 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("preserve"); }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5198 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strip"); }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5199 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("namespace"); }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5200 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("external"); }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5201 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("encoding"); }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5202 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-preserve"); }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5203 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("inherit"); }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5204 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-inherit"); }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5205 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("declare"); }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5206 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("construction"); }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5207 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordering"); }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5208 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("default"); }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5209 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy-namespaces"); }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5210 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("option"); }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5211 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("version"); }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5212 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("import"); }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5213 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema"); }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5214 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("module"); }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5215 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("function"); }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5216 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("score"); }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5217 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ftcontains"); }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5218 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("weight"); }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5219 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("window"); }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5220 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("distance"); }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5221 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("occurs"); }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5222 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("times"); }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5223 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("same"); }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5224 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("different"); }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5225 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lowercase"); }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5226 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("uppercase"); }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5227 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("relationship"); }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5228 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("levels"); }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5229 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("language"); }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5230 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("any"); }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5231 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("all"); }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5232 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("phrase"); }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5233 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exactly"); }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5234 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("from"); }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5235 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("words"); }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5236 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentences"); }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5237 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentence"); }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5238 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("paragraph"); }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5239 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("replace"); }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5240 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("modify"); }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5241 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("first"); }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5242 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insert"); }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5243 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("before"); }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5244 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("after"); }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 5245 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("revalidation"); }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5246 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("with"); }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 5247 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nodes"); }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 5248 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("rename"); }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 5249 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("last"); }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 5250 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("delete"); }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 5251 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("into"); }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 5252 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("simple"); }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 5253 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sequential"); }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 5254 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("updating"); }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 5255 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("deterministic"); }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 5256 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nondeterministic"); }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 5257 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordered"); }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 5258 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unordered"); }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 5259 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("returning"); }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 5260 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("block"); }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 5261 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exit"); }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 5262 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("loop"); }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 5263 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("while"); }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 5264 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("break"); }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 5265 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("continue"); }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 5266 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("try"); }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 5267 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("catch"); }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 5268 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eval"); }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 5269 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("using"); }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 5270 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("set"); }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 5271 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("index"); }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 5272 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unique"); }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 5273 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("on"); }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 5274 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("manual"); }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 5275 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("automatic"); }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 5276 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("decimal-format"); }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 5277 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("decimal-separator"); }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 5278 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("grouping-separator"); }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 5279 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("infinity"); }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 5280 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("minus-sign"); }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 5281 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("NaN"); }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 5282 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("percent"); }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 5283 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("per-mille"); }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 5284 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("zero-digit"); }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 5285 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("digit"); }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 5286 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("pattern-separator"); }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 5298 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)),
                          (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 5304 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 5321 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(1) - (1)].node)), NULL, NULL);
		}
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 5325 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(2) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(2) - (2)].node)), NULL);
		}
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 5329 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(3) - (1)].node)), NULL, static_cast<RangeExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		}
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 5333 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(4) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(4) - (2)].node)), static_cast<RangeExpr *> ((yysemantic_stack_[(4) - (4)].expr)));
		}
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 5343 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 5346 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 5349 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 5352 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 5361 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 5364 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 5373 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 5376 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 5385 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 5388 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 5397 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 5400 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 5409 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 5412 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 5415 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 5424 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 5427 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 5436 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), static_cast<StringLiteral *> ((yysemantic_stack_[(1) - (1)].expr)), NULL);
		}
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 5440 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 5450 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 5453 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 5456 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 5459 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 5462 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 5471 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 5480 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 5484 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 5488 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 5492 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 5496 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 5500 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 5504 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 5514 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 5517 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 5520 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 5523 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 5532 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 5535 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 5538 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 5541 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 5550 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 5553 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 5562 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 5565 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 5568 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 5571 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 5574 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 5577 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 5580 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 5589 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 5592 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 5601 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 5604 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 5607 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 5610 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 5619 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 5622 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 5625 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 5628 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 5631 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 5640 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 5643 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 5652 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 5655 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 5664 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 5667 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 5676 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 5679 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 5688 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 5697 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 5700 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 5709 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 5712 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 5715 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 5724 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 5727 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 5730 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 5733 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 5736 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 5745 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 5749 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 5753 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 5757 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 5767 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 5776 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWindow (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (2)].expr)), static_cast<FTUnit *> ((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 5786 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 5795 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 5798 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 5807 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 5810 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 5813 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 5822 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 5825 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 5834 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTIgnoreOption (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		}
    break;



/* Line 678 of lalr1.cc  */
#line 9767 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1157;
  const short int
  xquery_parser::yypact_[] =
  {
      1372, -1157, -1157, -1157, -1157,   123,   -26,    56,    84,  7557,
     111,   423,   430, -1157, -1157, -1157, -1157, -1157, -1157,   142,
     298,  6499, -1157,   212, -1157, -1157, -1157, -1157,   279,   326,
   -1157,   275,   294,   390, -1157, -1157, -1157, -1157, -1157, -1157,
   -1157, -1157, -1157,   310,   336, -1157, -1157, -1157, -1157, -1157,
   -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157,
   -1157, -1157, -1157, -1157, -1157, -1157,  7819, -1157,  5963, -1157,
   -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157,
   -1157, -1157,  9391, -1157, -1157, -1157, -1157, -1157, -1157, -1157,
   -1157,   400, -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157,
   -1157, -1157, -1157,  1643,  9391, -1157, -1157, -1157, -1157, -1157,
   -1157,   396, -1157, -1157, -1157, -1157,  7031, -1157,  7295, -1157,
   -1157, -1157, -1157, -1157,  9391, -1157, -1157,  5693, -1157, -1157,
   -1157, -1157, -1157, -1157,   429, -1157, -1157, -1157, -1157, -1157,
   -1157, -1157, -1157,    12,   378, -1157, -1157, -1157, -1157, -1157,
   -1157, -1157, -1157,   307,   450,   394, -1157,   398,   191, -1157,
   -1157, -1157, -1157, -1157, -1157,   518, -1157, -1157,   488,   406,
     411, -1157,   420,   514,   521, -1157,   559, -1157, -1157, -1157,
   -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157,
   -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157,
   -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157,
   -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157,  4073,   671,
   -1157,  4343, -1157, -1157,   270,  4613,   507,   522, -1157, -1157,
   -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157,
   -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157,
   -1157, -1157, -1157, -1157, -1157, -1157, -1157,   -35, -1157, -1157,
   -1157, -1157,   283,  9391, -1157, -1157, -1157, -1157, -1157,   541,
     593, -1157,   545,   449,   321,   247,   331,   -34, -1157,   634,
     515,   611,   612,  4883, -1157, -1157, -1157,    98, -1157, -1157,
    5693, -1157,   457, -1157,   564,  5963, -1157,   564,  5963, -1157,
   -1157, -1157, -1157,   564, -1157, -1157, -1157, -1157, -1157, -1157,
   -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157,
   -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157,
   -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157,
   -1157, -1157,   563, -1157, -1157,  9391,   675,   676,   551,   551,
     675,  9391,   -99,   -58,   693,   324,   -86,  9391,   573,   605,
      80,  7031,   339,   339,   408,   -10,   197,  9391,   440,   440,
   -1157, -1157, -1157, -1157, -1157,  7031,  9391,  4613,   577,   578,
    4613, -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157,
   -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157,
   -1157, -1157,  4613,  8081, -1157, -1157, -1157, -1157, -1157, -1157,
   -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157,
     579,  4613,  4613,   548,  4613,   560,  4613,    58,   128, -1157,
    4613,  6765,   600, -1157,  9391,  9391,  9391,  4613,   476,   477,
   -1157,   633,   636,  9391,    59,  4613,  8343,   606,   602,   604,
     613,   614,   615, -1157, -1157, -1157,  9391, -1157,   581,   730,
    4613,    28, -1157,   747,   590, -1157,  4613,   562, -1157,   746,
    4613,  4613,   592,  4613,  4613,  4613,  4613,   549,  9391, -1157,
   -1157,  4613, -1157, -1157,  4613,  4613,  9391, -1157, -1157, -1157,
   -1157,   123,   298, -1157, -1157,   270,   743,  4613, -1157,  4613,
     617,   326,   294,   390,   660,   625,   626,  4613,  4613, -1157,
   -1157, -1157, -1157, -1157, -1157, -1157,   672, -1157,   -49,  5153,
    5153,  5153, -1157,  5153,  5153, -1157,  5153, -1157,  5153, -1157,
   -1157, -1157, -1157, -1157, -1157, -1157,  5153,  5153,    26,  5153,
    5153,  5153,  5153,  5153,  5153,  5153,  5153,  5153,  5153,  5153,
     552,   687,   690,   700, -1157, -1157, -1157,  1913, -1157, -1157,
    5693,  5693,  4613,   564, -1157, -1157,   564, -1157,   564,  2183,
     642, -1157,  9391, -1157, -1157, -1157, -1157,   769, -1157, -1157,
   -1157, -1157, -1157, -1157,   695,   696, -1157, -1157,   653,    18,
    9391,   382,   643,   647,   653,   693,   680,   677, -1157, -1157,
   -1157, -1157, -1157,   349,   -71,   350,   780, -1157, -1157,   222,
   -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157,   523,
   -1157, -1157,   679,   665, -1157,   637,  4613,  4613,   635,   639,
   -1157,    -8,    -3,  2453,   640,   641, -1157,   644, -1157,   645,
    7031,   720,   784,  7031,   693,   727,   646,   648, -1157,   650,
    2723,     7, -1157,   257,   685,   722, -1157,   -39,   654, -1157,
   -1157,  9391,   -24, -1157,   652,   602,   310, -1157,   655,   656,
     657, -1157,    85,   121,  2993,    19, -1157,  9391,   730, -1157,
     -59,   661, -1157, -1157, -1157, -1157,   662, -1157,   -13, -1157,
   -1157, -1157,   162,   164,   733,   609,   618,     1, -1157,   704,
    5423, -1157,   663,   667,   361, -1157, -1157,   649, -1157,    31,
   -1157, -1157,   -27,   678,  9391,  4613,   732, -1157, -1157,   734,
    8867,   735,  4613,   736,   -85,   707,   -50,   593, -1157, -1157,
   -1157, -1157, -1157,  5153, -1157, -1157, -1157,  4613,    26,   278,
   -1157,   571,   537,   597,   596, -1157, -1157,   595,  -126,   247,
     247,   167,   331,   331,   331,   331,   -34,   -34, -1157, -1157,
    8867,  8867,  9391,  9391, -1157,   681, -1157, -1157,   682, -1157,
   -1157, -1157,   144,   -29,   312,   642, -1157,   193,   284, -1157,
   -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157,   653,
   -1157,   728,  9129,   724,  4613, -1157, -1157, -1157,   768,   726,
    4613,   693,   693,   653, -1157,   527,   693, -1157, -1157,   588,
   -1157, -1157,   594,   325, -1157, -1157, -1157, -1157, -1157, -1157,
     598, -1157, -1157,  4613,   693,  4613, -1157,   688,   689,   770,
     725,  9391, -1157,  9391, -1157, -1157,   692, -1157, -1157, -1157,
     683,   754,   693,   719,   757,   792,   693,   740, -1157, -1157,
   -1157,   711,   774,  4613,  4613,   749,  4613,   776,  4613,   755,
     -88, -1157,   288,   651, -1157, -1157,   496,   -24, -1157, -1157,
   -1157,   748,  9391, -1157,  9391, -1157, -1157,   716,  4613,   862,
   -1157,   177, -1157,    34, -1157, -1157,   871, -1157,   244,  4613,
    4613,  4613,   401,  4613,  4613,  4613,  4613,  4613,  4613,   782,
    4613,  4613,   605,   -23,   723,   488,   659,   756,   786,   743,
     829, -1157,  4613, -1157,   466,   802, -1157,  9391,   803, -1157,
    9391,   758,   759, -1157,   251, -1157, -1157, -1157,  9391, -1157,
    9391,  4613,   771,  4613,  4613,   -83,   773, -1157,   738,   731,
   -1157,   658, -1157,  -143, -1157,   303,     9,   666,    26,   303,
    5153,  5153,    49, -1157, -1157, -1157, -1157, -1157, -1157, -1157,
      26,   778,     9, -1157,   669,   865, -1157, -1157, -1157, -1157,
   -1157,   781, -1157, -1157, -1157,  4613, -1157,  9391,   831,   166,
   -1157, -1157,  4613, -1157,   371, -1157, -1157, -1157, -1157, -1157,
     898,   475, -1157, -1157, -1157,  4613, -1157, -1157, -1157, -1157,
   -1157, -1157,   670,   159,   900, -1157,   354, -1157, -1157,   763,
     744,   752, -1157, -1157,  8605,   353, -1157,  3263,   750,   751,
     793,   753,   760, -1157,  4613,   693,   830, -1157, -1157, -1157,
     693,   830,  3533, -1157,  9391, -1157, -1157,  4613, -1157,  9391,
   -1157,  4613,  4613,   798,  4613,   796, -1157,   824,   827,  4613,
    9391,   589,   878, -1157, -1157, -1157,  3803,   772,   775, -1157,
   -1157, -1157,   821, -1157,   369, -1157, -1157,   938, -1157, -1157,
    4613,  9391, -1157, -1157,   481, -1157, -1157, -1157,   766,   729,
     737, -1157, -1157, -1157,   739,   741, -1157, -1157, -1157, -1157,
   -1157,   745,  9391,   779, -1157,   814, -1157,   605, -1157, -1157,
   -1157,  6233,   659, -1157,  4613,  9391,   802, -1157,   693, -1157,
     531, -1157,    -4,   850, -1157,  4613,   851,   732, -1157,   777,
     783, -1157, -1157, -1157, -1157, -1157, -1157, -1157,  4613, -1157,
   -1157,  4613,   818,  4613, -1157, -1157,  5153, -1157, -1157, -1157,
   -1157, -1157,   238,  5153,  5153,   233, -1157,   597, -1157, -1157,
     208,  5153, -1157, -1157,   596,    26,   691, -1157, -1157, -1157,
   -1157,   768,  8867,   847,   874,   790, -1157, -1157, -1157, -1157,
   -1157,   -64,   944,   945,   -64,    13,   185,   189,   822, -1157,
   -1157,  9391,   799,   108, -1157, -1157,   794, -1157, -1157, -1157,
   -1157, -1157,   854,   884,   693,   830, -1157,   804, -1157, -1157,
   -1157, -1157, -1157,  4613, -1157,  4613,  9391,  9391, -1157,   428,
   -1157,  4613, -1157,   805, -1157, -1157,   862,  9391,   498, -1157,
     806,   862,  9391, -1157, -1157,  4613,  4613,  4613,  4613,  4613,
   -1157,  4613,  4613, -1157, -1157,   290, -1157,   807, -1157, -1157,
   -1157, -1157,   850, -1157, -1157, -1157,   693, -1157, -1157, -1157,
   -1157, -1157, -1157,  4613, -1157,   331,  5153,  5153,   331,   380,
   -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157,
   -1157,  8867, -1157,   159,   159,   -64, -1157, -1157, -1157,    30,
     -64,   954,   742,   887, -1157,   887, -1157,  4613,   201,   894,
    4613,  9391,  4613, -1157,  4613,   693, -1157, -1157, -1157, -1157,
     922, -1157, -1157, -1157, -1157,   -33,   862,  9391, -1157,   797,
     862, -1157, -1157, -1157, -1157, -1157, -1157, -1157,   873,  6233,
   -1157, -1157, -1157, -1157, -1157,   331,   331,  5153, -1157, -1157,
   -1157, -1157, -1157, -1157,     9, -1157,   213, -1157,   228, -1157,
     886,   768,  4613, -1157,  8867, -1157,   811, -1157, -1157,   830,
     876,    50,   266, -1157,   808,   862, -1157,   809,  9391, -1157,
     331,   761,   887, -1157, -1157,   693, -1157, -1157,   813,  4613,
    9391, -1157, -1157,   904,   260, -1157, -1157, -1157, -1157,   819,
     388, -1157, -1157, -1157,   810, -1157,   234, -1157, -1157, -1157,
    4613, -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157,
     881,   856, -1157,  9391, -1157,   236,   882,   856,  9391, -1157,
     825,   856, -1157
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   376,   377,   558,   523,   661,   670,   649,   573,   565,
     581,   572,   563,   671,   710,   709,   711,   712,   708,   567,
     668,   569,   596,   631,   625,   666,   593,   669,   726,   620,
     662,   724,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   663,   577,   571,   564,   665,   640,   570,   575,   732,
     733,   734,   735,   736,   737,   738,   739,   740,   741,   742,
     367,   370,   639,   635,   626,   606,   562,   357,     0,   634,
     642,   650,   355,   630,   393,   607,   608,   664,   356,   359,
     627,   644,     0,   399,   365,   395,   637,   561,   628,   629,
     657,   632,   648,   656,   361,   360,   580,   619,   659,   394,
     647,   652,   566,     0,     0,   314,   645,   655,   660,   658,
     638,   713,   624,   622,   623,   366,     0,   313,     0,   369,
     368,   653,   609,   633,     0,   358,   343,     0,   375,   654,
     636,   643,   651,   646,   714,   600,   605,   604,   603,   602,
     601,   574,   621,     0,   560,   667,   594,   700,   699,   701,
     579,   578,   597,   706,   568,   698,   703,   704,   695,   599,
     641,   697,   707,   705,   696,   598,   702,   715,   716,   717,
     720,   718,   721,   719,   722,   723,   725,   687,   686,   583,
     576,   585,   584,   680,   676,   591,   595,   592,   689,   690,
     673,   582,   685,   684,   681,   677,   694,   688,   683,   679,
     672,   693,   692,   678,   682,   674,   675,   586,   587,   589,
     691,   588,   590,   728,   727,   730,   731,   729,     0,     0,
       2,     0,     4,     6,    12,     0,     0,     0,    18,    20,
      32,    22,    23,    24,    48,    25,    29,    30,    52,    53,
      54,    49,    50,    56,    57,    27,    26,    31,    51,   173,
     172,   169,   170,   171,    28,    11,   150,   151,   155,   157,
     188,   194,     0,     0,   186,   187,   158,   159,   160,   161,
     270,   272,   274,   284,   287,   289,   292,   297,   300,   303,
     305,   307,   309,     0,   311,   317,   319,     0,   335,   318,
     339,   342,   344,   347,   349,     0,   354,   351,     0,   362,
     372,   374,   348,   378,   383,   391,   384,   385,   386,   389,
     390,   387,   388,   406,   408,   409,   410,   407,   455,   456,
     457,   458,   459,   460,   371,   497,   489,   496,   495,   494,
     491,   493,   490,   492,   392,    55,   162,   163,   165,   164,
     166,   167,   373,   559,   168,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      99,   101,   104,   133,   136,     0,     0,     0,     0,     0,
       0,   661,   670,   649,   573,   565,   581,   572,   563,   567,
     668,   569,   631,   726,   620,   724,   610,   611,   571,   564,
     562,   632,     0,     0,   713,   714,   560,   706,   568,   698,
     704,   695,   598,   716,   717,   720,   721,   719,   722,   725,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   556,
       0,     0,     0,   557,     0,     0,     0,     0,     0,     0,
     196,     0,     0,     0,     0,     0,     0,     0,   565,   572,
     563,   569,   562,   363,   373,   396,     0,   397,     0,   422,
       0,     0,   338,     0,     0,   341,     0,     0,   451,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   123,
     120,     0,   131,   132,     0,     0,     0,     3,     1,     5,
       7,     0,     0,    13,    10,    15,    16,     0,   153,   152,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   174,
     193,   189,   195,   190,   192,   191,   198,   199,     0,     0,
       0,     0,   328,     0,     0,   326,     0,   279,     0,   327,
     320,   325,   324,   323,   322,   321,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   316,   315,   312,     0,   336,   340,
       0,     0,     0,   350,   380,   353,   352,   364,   379,     0,
       0,   138,     0,   139,   135,   134,   137,     0,   114,   115,
      65,    66,   555,    74,     0,     0,    59,    60,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   103,   102,
     524,   525,   526,     0,     0,     0,     0,   781,   782,     0,
      64,   774,   775,   776,   777,   778,   779,   780,   100,     0,
     105,   106,     0,     0,   521,     0,     0,     0,     0,     0,
     513,     0,     0,     0,     0,     0,   502,     0,   503,     0,
       0,    83,     0,     0,     0,    75,     0,     0,   504,     0,
       0,     0,   259,     0,     0,   211,   212,     0,     0,   176,
     177,     0,     0,   197,     0,     0,     0,   499,     0,     0,
       0,   507,     0,     0,     0,     0,   398,   423,   422,   419,
       0,     0,   453,   452,   337,   512,     0,   450,     0,   537,
     538,   498,     0,     0,     0,     0,     0,     0,   543,     0,
       0,   129,     0,     0,     0,   214,   231,     0,    19,     0,
      21,   156,     0,     0,     0,     0,     0,   175,   232,     0,
       0,     0,     0,     0,     0,     0,     0,   271,   273,   277,
     283,   282,   281,     0,   278,   275,   276,     0,     0,     0,
     766,   285,   745,   753,   755,   757,   759,   761,   764,   291,
     290,   288,   294,   295,   296,   293,   298,   299,   302,   301,
       0,     0,     0,     0,   333,     0,   345,   346,     0,   381,
     402,   404,     0,     0,     0,     0,    63,     0,     0,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    34,
      35,     0,     0,    91,     0,    87,    89,    90,    94,    97,
       0,     0,     0,    33,    73,     0,     0,   783,   784,     0,
     785,   789,     0,     0,   818,   787,   788,   817,   786,   790,
       0,   797,   819,     0,     0,     0,   329,     0,     0,     0,
       0,     0,   517,     0,   514,   462,     0,   461,   470,   471,
       0,     0,     0,     0,     0,    76,     0,     0,   506,   505,
     472,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   744,     0,     0,   178,   179,     0,   184,   520,   500,
     501,     0,     0,   510,     0,   508,   466,     0,     0,   422,
     420,     0,   411,     0,   400,   401,     0,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   661,     0,     0,     0,     0,     0,     0,    17,
       0,   154,     0,   185,   243,   239,   241,     0,   233,   234,
       0,   566,   574,   478,   479,   485,   486,   488,     0,   201,
       0,     0,     0,     0,     0,     0,     0,   280,     0,     0,
     760,     0,   286,     0,   773,     0,     0,     0,     0,     0,
       0,     0,   746,   750,   768,   749,   772,   770,   769,   771,
       0,     0,     0,   762,   825,   823,   827,   765,   304,   306,
     308,   476,   310,   334,   382,     0,   403,     0,   116,     0,
     144,   141,     0,   140,     0,    71,    72,    69,    70,    36,
       0,     0,    92,    93,    95,     0,    96,    61,    62,    67,
      68,    58,     0,     0,     0,   792,     0,   791,   808,     0,
       0,     0,   331,   330,     0,     0,   265,     0,     0,     0,
     521,     0,     0,   463,     0,     0,    85,    79,    82,    81,
       0,    77,     0,   473,     0,   257,   261,     0,   128,     0,
     216,     0,     0,     0,     0,     0,   180,     0,     0,     0,
       0,   225,     0,   222,   227,   183,     0,     0,     0,   467,
     258,   423,     0,   412,     0,   446,   443,     0,   447,   448,
       0,     0,   449,   442,     0,   417,   445,   444,     0,     0,
       0,   530,   531,   527,     0,     0,   535,   536,   532,   541,
     539,     0,     0,     0,   545,   126,   125,     0,   122,   121,
     130,     0,   546,   547,     0,     0,   240,   252,     0,   253,
       0,   244,   245,   246,   247,     0,   236,     0,   200,     0,
       0,   482,   484,   483,   480,   209,   210,   203,     0,   205,
     202,     0,     0,     0,   767,   763,     0,   820,   821,   841,
     840,   836,     0,     0,     0,     0,   822,   754,   835,   747,
       0,     0,   752,   751,   756,     0,     0,   826,   824,   477,
     405,   146,     0,     0,   117,     0,   143,   142,    37,    88,
      98,   806,     0,     0,   804,   800,     0,     0,     0,    14,
     332,     0,     0,     0,   266,   464,     0,   518,   519,   522,
     515,   516,     0,    84,     0,    78,   474,     0,   260,   262,
     213,   218,   217,     0,   220,     0,     0,     0,   182,   223,
     226,     0,   468,     0,   511,   509,   422,     0,     0,   454,
       0,   422,     0,   418,     9,     0,     0,     0,     0,     0,
     544,     0,     0,   124,   553,     0,   548,     0,   215,   256,
     254,   255,   248,   249,   250,   242,     0,   237,   235,   487,
     481,   207,   204,     0,   206,   842,     0,     0,   828,     0,
     839,   838,   837,   832,   833,   748,   758,   834,   147,   118,
     145,     0,   149,     0,     0,   807,   809,   811,   813,     0,
     805,     0,     0,     0,   795,     0,   793,     0,     0,     0,
       0,     0,     0,   465,     0,     0,    80,   475,   219,   221,
     230,   229,   224,   181,   469,     0,   422,     0,   148,     0,
     422,   528,   529,   533,   534,   540,   542,   127,     0,     0,
     549,   743,   251,   238,   208,   830,   829,     0,   119,   816,
     815,   810,   814,   812,   801,   802,     0,   798,     0,   108,
     110,   112,     0,   107,     0,   267,     0,   263,   269,    86,
       0,   432,   426,   421,     0,   422,   413,     0,     0,   554,
     831,     0,     0,   796,   794,     0,   113,   109,     0,     0,
       0,   440,   434,     0,   433,   435,   441,   438,   428,     0,
     427,   429,   439,   415,     0,   414,     0,   803,   799,   111,
       0,   264,   228,   425,   436,   437,   424,   430,   431,   416,
       0,     0,   268,     0,   550,     0,     0,     0,     0,   551,
       0,     0,   552
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1157, -1157,   785, -1157,   787,   788, -1157,   789, -1157,   501,
     504,  -481, -1157,   407,  -463, -1157, -1157, -1157, -1157, -1157,
   -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157,  -833,
   -1157, -1157, -1157, -1157,    11,   211,   664, -1157, -1157,   668,
     291,   287, -1157,  -336, -1157, -1157,   232, -1157,  -845, -1157,
   -1157,   -87, -1157, -1157, -1157, -1157, -1157,   309,     3, -1157,
   -1157,  -152, -1157, -1156,   795,  -101, -1157,   519,  -354, -1157,
   -1157, -1157, -1157,   147, -1157, -1157,   762, -1157, -1157, -1157,
   -1157, -1157,    97,  -487,  -636, -1157, -1157, -1157,   -20, -1157,
   -1157,  -188,   -25,   -78, -1157, -1157, -1157,   -95, -1157, -1157,
     116,   -84, -1157, -1157,   -80, -1057, -1157,   582,    -5, -1157,
   -1157,    20, -1157, -1157,   520,   513, -1157,  -496,  -921,   499,
     122,  -539,   119,   125, -1157, -1157, -1157, -1157, -1157,   764,
   -1157, -1157, -1157, -1157, -1157,   765, -1157, -1157,  -109, -1157,
   -1157, -1157, -1157, -1157, -1157, -1157,   -46, -1078, -1157, -1157,
     225,    35, -1157,  -529, -1157, -1157, -1157, -1157, -1157, -1157,
   -1157, -1157, -1157,  -863, -1157,   -22, -1157,   359,  -671, -1157,
   -1157, -1157, -1157, -1157,  -337,  -330, -1029,  -818, -1157, -1157,
   -1157, -1157, -1157, -1157, -1157, -1157, -1157, -1157,   282,  -643,
    -744, -1157,   254,   -70,  -712, -1157, -1157, -1157, -1157, -1157,
   -1157, -1157,   607,   610,  -355,   215,    60, -1157, -1157, -1157,
   -1157, -1157, -1157, -1157,   -43, -1157, -1157,   -47, -1157,  -353,
     -92,    -9, -1157, -1157,   315, -1157, -1157,   109,    96,   -97,
     320, -1157, -1157,   112, -1157,  -716, -1157, -1157, -1157, -1157,
    -225,  -802, -1157,  -113,  -594, -1157,  -666, -1157, -1157, -1157,
   -1157,  -943, -1157, -1157, -1157, -1157,   -82,   114, -1157
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   789,   790,   791,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,  1026,
     644,   244,   245,   795,   796,   797,  1095,   246,   247,   370,
     371,   372,  1288,  1339,  1340,   248,   774,   249,   480,   700,
     903,  1096,   250,   251,   252,   253,   254,   373,   374,   573,
     979,   980,  1072,   983,   255,   256,   499,   257,   258,   259,
     509,   441,   866,   867,   260,   510,   261,   512,   262,   263,
     264,   516,   517,  1051,   725,   265,   655,   704,   656,   662,
    1052,  1053,  1054,   705,   513,   514,   918,   919,  1247,   515,
     915,   916,  1111,  1112,  1113,  1114,   266,   651,   652,   267,
    1015,  1016,   268,   269,   270,   271,   733,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     536,   537,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     563,   564,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   772,   312,   313,   314,  1074,   678,   679,   680,  1353,
    1379,  1380,  1373,  1374,  1381,  1375,  1075,  1076,   315,   316,
    1077,   317,   318,   319,   320,   321,   322,   323,   970,   726,
     923,  1124,   924,   925,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   623,  1019,   334,   335,   336,   337,
     338,   339,   340,   697,   698,   341,  1102,  1103,  1235,  1027,
     432,   342,   343,   344,   741,   952,   742,   743,   744,   745,
     746,   747,   748,   953,   954,   610,   611,   612,   613,   614,
    1336,  1337,   615,  1275,  1174,  1279,  1276,   616,   617,   956,
     967,  1145,   957,   958,   963,   959,  1263,  1141,   942
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       420,   583,   458,   752,   753,   754,   755,   881,   926,   740,
     855,  1007,   433,  1031,   860,   710,   968,   969,   465,  1156,
    1073,   859,   453,  1234,   461,   729,   955,   730,   731,  1149,
     732,   724,   734,   467,   809,   682,   863,   720,   721,   721,
     735,   736,  1065,  1066,  1042,  1223,     4,   720,   926,   926,
    1332,   931,  1351,  1131,  1371,  1243,  1244,   447,  1065,   454,
    1100,   882,  1273,  1137,   497,   345,   346,   347,   348,   349,
     350,   578,   497,   455,   641,   645,  1097,   351,   582,  1320,
     926,   977,   603,   658,   586,   579,   934,   722,   932,   665,
     936,   831,   548,   858,  1108,   459,   833,  1142,   587,   580,
     899,  1142,   357,  1138,   792,   549,   852,   433,   886,   463,
     592,   964,   965,  1110,   593,   464,   689,   690,   852,   692,
     693,   694,   695,   375,   666,  1274,   883,   701,    74,  1067,
     702,   703,   581,   966,   358,   359,   910,   943,  1352,  1167,
      85,   603,   376,   711,   498,   793,   978,  1068,   582,  1069,
     794,   594,   911,   717,   718,   994,  1098,   345,   346,   347,
     348,   349,   350,  1068,    99,  1069,   887,   832,   737,   351,
     810,   738,   834,  1372,   723,   352,  1070,   723,   595,   723,
     104,   559,   864,   853,   872,  1322,   353,   354,   362,  1223,
     355,   683,  1070,   356,   357,   878,   116,  1195,   377,   811,
     812,  1073,   813,   814,  1177,  1333,   944,   640,  1062,   740,
     740,  1073,   723,   723,   468,   771,   604,  1071,  1291,  1045,
     874,   363,   865,   723,  1043,   900,   358,   359,   360,   380,
    1265,   605,  1282,   642,   667,   143,  1153,   937,   596,   935,
     557,  1359,   804,   975,   606,  1404,   607,  1172,   888,   565,
     892,  1409,   567,   421,   518,  1412,   608,  1143,  1144,   609,
     873,  1143,  1144,   118,  1371,  1163,   378,   379,  1065,   597,
    1182,   365,   361,  1281,  1065,   604,   625,   643,   739,   628,
     362,  1256,  1292,   622,  1283,  1377,   454,   426,  1285,   454,
     605,   845,   945,   946,   947,   491,   875,  1063,     4,  1132,
    1342,   629,   926,   606,  1173,   607,   366,   367,   368,   369,
     949,   492,  1362,   363,   539,   608,  1151,   951,   609,   976,
     634,   635,   434,   637,   427,   639,   989,  1362,   500,   646,
     985,   540,   364,  1400,   501,  1406,   570,   502,   503,   649,
     989,  1164,   577,   720,   670,   504,   428,   986,   588,   571,
     438,   439,   433,   576,   362,  1073,   542,  1257,   619,   681,
    1284,   914,  1064,   365,  1286,   686,   433,   624,   929,   889,
     890,   893,   894,  1068,   720,  1069,  1343,  1065,  1066,  1068,
      74,  1069,   543,  1394,   891,  1121,   895,   363,  1363,   435,
    1378,  1361,    85,   854,   632,   544,  1065,   546,   366,   367,
     368,   369,  1070,  1364,   440,   476,   547,  1377,  1070,  1401,
     477,  1407,  1150,  1004,   907,  1122,    99,   437,  1269,   740,
     737,   987,   433,   738,  1044,   653,   654,   657,   710,   545,
    1005,   740,   982,  1123,   664,  1318,   436,   673,   988,   981,
     993,   505,  1004,   506,   442,  1014,   996,   653,   997,   998,
     926,   766,   767,  1001,   982,   443,   765,   507,  1183,  1176,
     908,   768,  1349,   818,  1067,  1079,  1260,  1080,   539,   699,
    1006,  1010,  1261,   367,   368,   369,  1018,   706,  1021,   584,
    1262,   444,  1068,   508,  1069,   540,  1047,  1048,  1319,  1065,
    1066,  1260,   819,   820,   585,   821,   822,  1261,  1166,  1035,
    1036,  1068,  1038,  1069,  1040,  1262,  1065,  1066,   541,   799,
     456,  1070,  1397,   479,   800,   104,   721,  1057,  1268,  1058,
     546,   470,   566,   471,  1060,   827,   828,  1328,   568,   547,
    1070,   116,   836,  1376,  1382,  1081,  1082,  1083,   460,  1086,
    1087,  1088,  1089,  1090,  1091,  1305,  1093,  1094,   841,   851,
    1309,   844,  1217,  1107,  1047,  1048,  1376,  1049,   914,   926,
    1388,  1139,  1382,   775,  1108,   422,  1140,  1327,   423,   546,
     143,   466,   424,   877,  1109,   425,  1067,  1127,   547,  1129,
    1130,   798,   469,  1110,   721,   345,   346,   347,   807,   815,
     350,   808,   816,  1067,  1068,   472,  1069,  1255,   769,   904,
    1368,   769,   793,   769,  1258,  1259,  1050,   794,   473,  1331,
     474,  1068,   475,  1069,  1331,   367,   368,   369,   600,   601,
     602,  1160,  1084,  1070,  1085,   943,   740,   104,   478,   603,
     479,   433,   926,   481,   433,  1354,   938,   560,   561,  1357,
    1070,  1170,   482,   116,   104,   999,  1000,  1047,  1048,  1240,
    1241,   483,   862,   598,   599,   620,   621,   574,   575,   484,
     116,   749,   750,   485,  1222,   756,   757,   521,   879,   486,
    1192,   488,  1193,   758,   759,   522,   523,   520,   524,  1329,
    1330,  1307,   143,  1199,  1384,   525,   495,  1201,  1202,   526,
    1204,   527,   971,   971,   944,  1208,   528,   519,  1366,   143,
     538,   496,   550,   551,   552,   913,   553,   562,   569,   345,
     572,   927,   529,   582,   589,   590,   367,  1325,  1326,   626,
     627,   633,  1009,   636,  1011,   779,   780,   781,   782,   783,
     784,   785,   786,   787,   788,   638,   530,   531,   532,   533,
     534,   535,   650,   661,   659,   660,   663,   403,   674,   423,
    1237,   927,   927,   927,   927,  1239,   676,   677,   425,   431,
     446,   914,   684,   604,   687,   685,   688,   691,   709,   696,
     714,   719,   760,   761,  1251,   713,   762,  1252,   605,  1254,
     945,   946,   947,   927,   715,   716,   763,   773,  1360,   776,
     948,   606,   801,   607,   777,   778,   802,   805,   949,   806,
     817,   824,   823,   608,   950,   951,   609,   825,   842,   826,
     829,   830,   837,   838,   843,   846,   839,   856,   847,   896,
     840,   857,  1020,   848,  1020,   849,   861,   868,   909,   871,
     869,   870,   898,   884,   885,   897,   901,   912,   905,   906,
     941,  1296,   917,   933,   920,   928,   930,   960,   961,  1298,
     990,  1299,   962,   973,   720,   974,   794,  1303,   995,  1002,
    1012,  1013,  1014,   624,  1023,   624,  1003,  1017,  1028,  1024,
    1008,  1311,  1312,  1313,  1314,  1315,  1025,  1316,  1317,  1029,
    1030,  1165,  1032,  1033,  1034,  1037,  1039,  1041,  1059,  1061,
    1056,  1078,  1092,  1323,  1101,  1099,  1105,  1046,  1104,  1324,
     594,  1115,  1117,  1119,  1120,  1136,  1135,  1128,  1116,  1133,
    1134,   518,  1158,  1146,  1155,  1159,  1186,  1162,     4,  1125,
    1175,  1126,  1178,  1179,  1180,  1187,  1188,  1189,  1190,  1194,
    1203,  1197,  1205,  1341,  1206,  1191,  1345,  1207,  1347,  1211,
    1348,  1157,  1171,  1216,  1219,  1224,  1232,  1214,  1108,  1246,
    1215,  1225,  1249,  1231,  1253,  1213,  1267,   977,  1250,  1226,
    1271,  1227,  1272,  1228,  1277,  1278,  1293,  1287,  1161,  1220,
    1294,  1229,  1295,  1290,  1334,  1004,  1297,  1304,  1308,  1321,
    1344,  1350,  1356,  1358,  1365,  1369,  1370,  1390,  1341,  1393,
    1396,  1403,  1408,  1383,  1385,  1399,   707,  1335,   982,   708,
    1411,   803,  1169,   487,   992,   927,  1367,   984,   489,   490,
    1233,  1270,  1389,   493,  1055,  1391,  1387,  1118,   712,  1200,
     494,  1302,  1248,   591,   511,   653,  1210,  1238,  1106,  1198,
     657,  1245,  1242,   728,   618,  1184,  1402,   880,   675,   727,
     751,  1209,  1218,  1398,  1395,   972,   991,   556,  1022,  1230,
    1168,   668,   558,   939,   669,  1236,  1154,  1147,  1266,   940,
    1338,  1280,  1221,  1148,  1152,     0,     0,     0,  1264,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   699,     0,     0,     0,     0,     0,     0,
       0,     0,   454,     0,     0,     0,   706,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   927,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1289,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1300,  1301,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1306,     0,
       0,     0,     0,  1310,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   927,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1346,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1355,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     454,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   927,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1386,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1392,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,  1405,     0,     0,     5,     6,  1410,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
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
     119,   120,   121,     0,     0,     0,   122,     0,   123,   124,
     125,     0,   126,   127,   128,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   144,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,   381,   382,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,   390,    21,    22,    23,    24,    25,
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
       0,   119,   120,   121,     0,     0,     0,   122,   457,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   406,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,   381,   382,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,   390,    21,    22,    23,    24,    25,
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
       0,   119,   120,   121,     0,   764,     0,   122,     0,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   406,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,   381,   382,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,   390,    21,    22,    23,    24,    25,
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
       0,   119,   120,   121,     0,     0,     0,   122,   770,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   406,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,   381,   382,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,   390,    21,    22,    23,    24,    25,
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
       0,   119,   120,   121,     0,   835,     0,   122,     0,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   406,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,   381,   382,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,   390,    21,    22,    23,    24,    25,
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
       0,   119,   120,   121,     0,   850,     0,   122,     0,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   406,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,   381,   382,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,   390,    21,    22,    23,    24,    25,
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
       0,   119,   120,   121,     0,   876,     0,   122,     0,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   406,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,   381,   382,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,   390,    21,    22,    23,    24,    25,
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
       0,   119,   120,   121,     0,  1185,     0,   122,     0,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   406,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,   381,   382,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,   390,    21,    22,    23,    24,    25,
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
       0,   119,   120,   121,     0,  1196,     0,   122,     0,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   406,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,   381,   382,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,   390,    21,    22,    23,    24,    25,
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
       0,   119,   120,   121,     0,  1212,     0,   122,     0,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   406,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,     5,     6,
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
     215,   216,   217,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,     5,     6,
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
       0,     0,   141,   142,   143,     0,   406,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,   381,   382,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,   390,    21,    22,    23,    24,    25,
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
       0,     0,   141,   142,   143,     0,   406,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,   381,   382,
       0,     7,   384,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,   389,   390,    21,    22,   392,    24,    25,
      26,    27,     0,   393,   394,    30,   395,   396,   397,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,     0,
      72,    73,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,    85,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,   401,    92,
      93,    94,    95,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,     0,     0,     0,   103,   104,
     554,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     0,   555,   118,     0,
       0,   119,   120,   121,     0,     0,     0,   122,     0,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   406,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   407,   154,   409,   156,
     410,   411,   159,   160,   161,   162,   163,   164,   412,   166,
     167,   413,   414,   415,   171,   416,   417,   418,   175,   419,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,   381,   382,
       0,     7,   384,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,   389,   390,    21,    22,   392,    24,    25,
      26,    27,     0,   393,   394,    30,   395,   396,   397,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,     0,
      72,    73,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,    85,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,   401,    92,
      93,    94,    95,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,     0,     0,     0,   103,   104,
     105,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     0,   117,   118,     0,
       0,   119,   120,   121,     0,     0,     0,   122,     0,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   406,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   407,   154,   409,   156,
     410,   411,   159,   160,   161,   162,   163,   164,   412,   166,
     167,   413,   414,   415,   171,   416,   417,   418,   175,   419,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,   902,   382,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,   390,    21,    22,    23,    24,    25,
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
       0,     0,   141,   142,   143,     0,   406,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,   381,   382,
       0,   383,   384,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,   389,   390,    21,    22,   392,    24,    25,
      26,    27,     0,   393,   394,    30,   395,   396,   397,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,     0,
      72,    73,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,    85,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,   401,    92,
      93,    94,    95,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,     0,     0,     0,   103,   104,
       0,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     0,     0,     0,     0,
       0,   119,   120,   121,     0,     0,     0,   122,     0,   123,
     124,   125,     0,     0,     0,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   406,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   407,   154,   409,   156,
     410,   411,   159,   160,   161,   162,   163,   164,   412,   166,
     167,   413,   414,   415,   171,   416,   417,   418,   175,   419,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     0,     0,     0,     0,     0,   381,   382,
       0,   383,   384,   448,   386,   449,   450,    13,    14,    15,
      16,    17,    18,   389,   390,   451,    22,   392,    24,    25,
      26,    27,     0,   393,   394,    30,   395,   396,   397,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,     0,     0,    62,     0,    63,
      64,    65,   452,     0,     0,    69,    70,    71,     0,     0,
       0,    73,     0,     0,     0,     0,    75,    76,    77,     0,
       0,    80,    81,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,   401,    92,
      93,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      98,     0,   100,   101,   102,     0,     0,     0,     0,     0,
       0,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     404,   112,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   121,     0,     0,     0,   122,     0,   123,
     124,     0,     0,     0,     0,   128,     0,   129,     0,   130,
     131,   132,   133,   405,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,     0,     0,   406,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   407,   154,   409,   156,
     410,   411,   159,   160,   161,   162,   163,   164,   412,   166,
     167,   413,   414,   415,   171,   416,   417,   418,   175,   419,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     0,     0,     0,     0,     0,   381,   382,
       0,   383,   384,   385,   386,   387,   388,    13,    14,    15,
      16,    17,    18,   389,   390,   391,    22,   392,    24,    25,
      26,    27,     0,   393,   394,    30,   395,   396,   397,    34,
      35,    36,    37,    38,    39,    40,    41,    42,   398,   399,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,     0,     0,    62,     0,    63,
      64,    65,   400,     0,     0,    69,    70,    71,     0,     0,
       0,    73,     0,     0,     0,     0,    75,    76,    77,     0,
       0,    80,    81,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,   401,    92,
      93,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      98,     0,   100,   101,   102,     0,     0,     0,     0,     0,
       0,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     404,   112,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   121,     0,     0,     0,   122,     0,   123,
       0,     0,     0,     0,     0,   128,     0,   129,     0,   130,
     131,   132,   133,   405,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,     0,     0,   406,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   407,   408,   409,   156,
     410,   411,   159,   160,   161,   162,   163,   164,   412,   166,
     167,   413,   414,   415,   171,   416,   417,   418,   175,   419,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   429,     0,     0,     0,     3,     0,     0,
       0,     0,     0,     0,   381,   382,     0,   383,   384,   385,
     386,   387,   388,    13,    14,    15,    16,    17,    18,   389,
     390,   391,    22,   392,    24,    25,    26,    27,     0,   393,
     394,    30,   395,   396,   397,    34,    35,    36,    37,    38,
      39,    40,    41,    42,   398,   399,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,     0,     0,    62,     0,    63,    64,    65,   400,     0,
       0,    69,    70,    71,     0,     0,     0,    73,     0,     0,
       0,     0,    75,    76,    77,     0,     0,    80,    81,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,     0,
      90,     0,     0,     0,   401,    92,    93,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,     0,   100,   101,
     102,   430,     0,     0,   431,     0,     0,   106,   107,     0,
       0,     0,     0,   108,   109,   110,   404,   112,   113,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
       0,     0,     0,   122,     0,   123,     0,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   405,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
       0,     0,   406,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   407,   408,   409,   156,   410,   411,   159,   160,
     161,   162,   163,   164,   412,   166,   167,   413,   414,   415,
     171,   416,   417,   418,   175,   419,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,     0,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   429,
       0,     0,     0,     3,     0,   647,     0,     0,     0,     0,
     381,   382,     0,   383,   384,   385,   386,   387,   388,    13,
      14,    15,    16,    17,    18,   389,   390,   391,    22,   392,
      24,    25,    26,    27,     0,   393,   394,    30,   395,   396,
     397,    34,    35,    36,    37,    38,    39,    40,    41,    42,
     398,   399,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,     0,     0,    62,
       0,    63,    64,    65,   400,     0,     0,    69,    70,    71,
       0,     0,     0,    73,     0,     0,     0,     0,    75,    76,
      77,     0,     0,    80,    81,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,     0,    90,     0,     0,     0,
     401,    92,    93,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,     0,   100,   101,   102,     0,     0,     0,
       0,     0,     0,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   404,   112,   113,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,     0,     0,     0,   122,
     648,   123,     0,     0,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   405,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,     0,     0,   406,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   407,   408,
     409,   156,   410,   411,   159,   160,   161,   162,   163,   164,
     412,   166,   167,   413,   414,   415,   171,   416,   417,   418,
     175,   419,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,     0,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   429,     0,     0,     0,     3,
       0,     0,     0,     0,     0,     0,   381,   382,     0,   383,
     384,   385,   386,   387,   388,    13,    14,    15,    16,    17,
      18,   389,   390,   391,    22,   392,    24,    25,    26,    27,
       0,   393,   394,    30,   395,   396,   397,    34,    35,    36,
      37,    38,    39,    40,    41,    42,   398,   399,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,     0,    62,     0,    63,    64,    65,
     400,     0,     0,    69,    70,    71,     0,     0,     0,    73,
       0,     0,     0,     0,    75,    76,    77,     0,     0,    80,
      81,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,     0,    90,     0,     0,     0,   401,    92,    93,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    98,     0,
     100,   101,   102,     0,     0,     0,     0,     0,     0,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   404,   112,
     113,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,     0,     0,     0,   122,     0,   123,     0,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   405,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,     0,     0,   406,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   407,   408,   409,   156,   410,   411,
     159,   160,   161,   162,   163,   164,   412,   166,   167,   413,
     414,   415,   171,   416,   417,   418,   175,   419,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   462,     0,     3,     0,     0,     0,     0,     0,     0,
     381,   382,     0,   383,   384,   385,   386,   387,   388,    13,
      14,    15,    16,    17,    18,   389,   390,   391,    22,   392,
      24,    25,    26,    27,     0,   393,   394,    30,   395,   396,
     397,    34,    35,    36,    37,    38,    39,    40,    41,    42,
     398,   399,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,     0,     0,    62,
       0,    63,    64,    65,   400,     0,     0,    69,    70,    71,
       0,     0,     0,    73,     0,     0,     0,     0,    75,    76,
      77,     0,     0,    80,    81,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,     0,    90,     0,     0,     0,
     401,    92,    93,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,     0,   100,   101,   102,     0,     0,     0,
       0,     0,     0,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   404,   112,   113,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,     0,     0,     0,   122,
       0,   123,     0,     0,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   405,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,     0,     0,   406,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   407,   408,
     409,   156,   410,   411,   159,   160,   161,   162,   163,   164,
     412,   166,   167,   413,   414,   415,   171,   416,   417,   418,
     175,   419,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,     0,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,     3,     0,     0,     0,     0,
       0,     0,   381,   382,     0,   383,   384,   385,   386,   387,
     388,    13,    14,    15,    16,    17,    18,   389,   390,   391,
      22,   392,    24,    25,    26,    27,     0,   393,   394,    30,
     395,   396,   397,    34,    35,    36,    37,    38,    39,    40,
      41,    42,   398,   399,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,     0,
       0,    62,     0,    63,    64,    65,   400,     0,     0,    69,
      70,    71,     0,     0,     0,    73,     0,     0,     0,     0,
      75,    76,    77,     0,     0,    80,    81,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,     0,    90,     0,
       0,     0,   401,    92,    93,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,     0,   100,   101,   102,   402,
       0,     0,   403,     0,     0,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   404,   112,   113,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,     0,
       0,   122,     0,   123,     0,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   405,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,     0,     0,
     406,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     407,   408,   409,   156,   410,   411,   159,   160,   161,   162,
     163,   164,   412,   166,   167,   413,   414,   415,   171,   416,
     417,   418,   175,   419,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,     3,     0,     0,
       0,     0,     0,     0,   381,   382,     0,   383,   384,   385,
     386,   387,   388,    13,    14,    15,    16,    17,    18,   389,
     390,   391,    22,   392,    24,    25,    26,    27,     0,   393,
     394,    30,   395,   396,   397,    34,    35,    36,    37,    38,
      39,    40,    41,    42,   398,   399,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,     0,     0,    62,     0,    63,    64,    65,   400,     0,
       0,    69,    70,    71,     0,     0,     0,    73,     0,     0,
       0,     0,    75,    76,    77,     0,     0,    80,    81,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,     0,
      90,     0,     0,     0,   401,    92,    93,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,     0,   100,   101,
     102,   445,     0,     0,   446,     0,     0,   106,   107,     0,
       0,     0,     0,   108,   109,   110,   404,   112,   113,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
       0,     0,     0,   122,     0,   123,     0,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   405,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
       0,     0,   406,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   407,   408,   409,   156,   410,   411,   159,   160,
     161,   162,   163,   164,   412,   166,   167,   413,   414,   415,
     171,   416,   417,   418,   175,   419,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,     0,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,     3,
       0,     0,     0,     0,     0,     0,   381,   382,     0,   383,
     384,   385,   386,   387,   388,    13,    14,    15,    16,    17,
      18,   389,   390,   391,    22,   392,    24,    25,    26,    27,
       0,   393,   394,    30,   395,   396,   397,    34,    35,    36,
      37,    38,    39,    40,    41,    42,   398,   399,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,     0,    62,     0,    63,    64,    65,
     400,     0,     0,    69,    70,    71,     0,     0,     0,    73,
       0,     0,     0,     0,    75,    76,    77,     0,     0,    80,
      81,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,     0,    90,     0,     0,     0,   401,    92,    93,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    98,     0,
     100,   101,   102,     0,     0,     0,     0,     0,     0,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   404,   112,
     113,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,     0,     0,     0,   122,   630,   123,     0,     0,
       0,     0,     0,   631,     0,   129,     0,   130,   131,   132,
     133,   405,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,     0,     0,   406,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   407,   408,   409,   156,   410,   411,
     159,   160,   161,   162,   163,   164,   412,   166,   167,   413,
     414,   415,   171,   416,   417,   418,   175,   419,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,     3,     0,     0,     0,     0,     0,     0,   381,   382,
       0,   383,   384,   385,   386,   387,   388,    13,    14,    15,
      16,    17,    18,   389,   390,   391,    22,   392,    24,    25,
      26,    27,     0,   393,   394,    30,   395,   396,   397,    34,
      35,    36,    37,    38,    39,    40,    41,    42,   398,   399,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,     0,     0,    62,     0,    63,
      64,    65,   400,     0,     0,    69,    70,    71,     0,     0,
       0,    73,     0,     0,     0,     0,    75,    76,    77,     0,
       0,    80,    81,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,   401,    92,
      93,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      98,     0,   100,   101,   102,     0,     0,     0,     0,     0,
       0,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     404,   112,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   121,     0,     0,     0,   122,   671,   123,
       0,     0,     0,     0,     0,   672,     0,   129,     0,   130,
     131,   132,   133,   405,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,     0,     0,   406,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   407,   408,   409,   156,
     410,   411,   159,   160,   161,   162,   163,   164,   412,   166,
     167,   413,   414,   415,   171,   416,   417,   418,   175,   419,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,     3,     0,     0,     0,     0,     0,     0,
     381,   382,     0,   383,   384,   448,   386,   449,   450,    13,
      14,    15,    16,    17,    18,   389,   390,   451,    22,   392,
      24,    25,    26,    27,     0,   393,   394,    30,   395,   396,
     397,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,     0,     0,    62,
       0,    63,    64,    65,   452,     0,     0,    69,    70,    71,
       0,     0,     0,    73,     0,     0,     0,     0,    75,    76,
      77,     0,     0,    80,    81,  1181,     0,     0,     0,     0,
       0,    86,    87,    88,    89,     0,    90,     0,     0,     0,
     401,    92,    93,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,     0,   100,   101,   921,     0,     0,     0,
       0,     0,     0,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   404,   112,   113,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,     0,     0,     0,   122,
       0,   123,   124,     0,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   405,   135,   136,   137,   138,
     139,   140,     0,     0,   922,   142,     0,     0,   406,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   407,   154,
     409,   156,   410,   411,   159,   160,   161,   162,   163,   164,
     412,   166,   167,   413,   414,   415,   171,   416,   417,   418,
     175,   419,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,     0,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,     3,     0,     0,     0,     0,
       0,     0,   381,   382,     0,   383,   384,   448,   386,   449,
     450,    13,    14,    15,    16,    17,    18,   389,   390,   451,
      22,   392,    24,    25,    26,    27,     0,   393,   394,    30,
     395,   396,   397,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,     0,
       0,    62,     0,    63,    64,    65,   452,     0,     0,    69,
      70,    71,     0,     0,     0,    73,     0,     0,     0,     0,
      75,    76,    77,     0,     0,    80,    81,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,     0,    90,     0,
       0,     0,   401,    92,    93,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,     0,   100,   101,   921,     0,
       0,     0,     0,     0,     0,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   404,   112,   113,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,     0,
       0,   122,     0,   123,   124,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   405,   135,   136,
     137,   138,   139,   140,     0,     0,   922,   142,     0,     0,
     406,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     407,   154,   409,   156,   410,   411,   159,   160,   161,   162,
     163,   164,   412,   166,   167,   413,   414,   415,   171,   416,
     417,   418,   175,   419,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,     3,     0,     0,
       0,     0,     0,     0,   381,   382,     0,   383,   384,   448,
     386,   449,   450,    13,    14,    15,    16,    17,    18,   389,
     390,   451,    22,   392,    24,    25,    26,    27,     0,   393,
     394,    30,   395,   396,   397,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,     0,     0,    62,     0,    63,    64,    65,   452,     0,
       0,    69,    70,    71,     0,     0,     0,    73,     0,     0,
       0,     0,    75,    76,    77,     0,     0,    80,    81,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,     0,
      90,     0,     0,     0,   401,    92,    93,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,     0,   100,   101,
     921,     0,     0,     0,     0,     0,     0,   106,   107,     0,
       0,     0,     0,   108,   109,   110,   404,   112,   113,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
       0,     0,     0,   122,     0,   123,   124,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   405,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
       0,     0,   406,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   407,   154,   409,   156,   410,   411,   159,   160,
     161,   162,   163,   164,   412,   166,   167,   413,   414,   415,
     171,   416,   417,   418,   175,   419,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,     0,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,     3,
       0,     0,     0,     0,     0,     0,   381,   382,     0,   383,
     384,   385,   386,   387,   388,    13,    14,    15,    16,    17,
      18,   389,   390,   391,    22,   392,    24,    25,    26,    27,
       0,   393,   394,    30,   395,   396,   397,    34,    35,    36,
      37,    38,    39,    40,    41,    42,   398,   399,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,     0,    62,     0,    63,    64,    65,
     400,     0,     0,    69,    70,    71,     0,     0,     0,    73,
       0,     0,     0,     0,    75,    76,    77,     0,     0,    80,
      81,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,     0,    90,     0,     0,     0,   401,    92,    93,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    98,     0,
     100,   101,   102,     0,     0,     0,     0,     0,     0,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   404,   112,
     113,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,     0,     0,     0,   122,     0,   123,     0,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   405,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,     0,     0,   406,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   407,   408,   409,   156,   410,   411,
     159,   160,   161,   162,   163,   164,   412,   166,   167,   413,
     414,   415,   171,   416,   417,   418,   175,   419,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         9,   354,   103,   542,   543,   544,   545,   678,   720,   538,
     653,   813,    21,   846,   657,   496,   760,   761,   127,   962,
     883,   657,    68,  1101,   116,   521,   742,   523,   524,   950,
     526,   518,   528,    21,   105,     7,    60,    86,    88,    88,
     536,   537,     8,     9,   132,  1074,    20,    86,   760,   761,
      20,   136,    85,   136,     4,  1112,  1113,    66,     8,    68,
     905,   120,   126,   206,    99,    34,    35,    36,    37,    38,
      39,   170,    99,    82,   427,   428,    99,    46,    20,  1235,
     792,   110,    92,   437,   170,   184,   136,   136,   724,    30,
     726,    99,   126,   132,    98,   104,    99,    88,   184,   157,
      99,    88,    71,   246,    86,   139,    99,   116,   121,   118,
      30,   237,   238,   117,    34,   124,   470,   471,    99,   473,
     474,   475,   476,   149,    65,   189,   185,   481,   102,    95,
     484,   485,   190,   259,   103,   104,   105,    88,   171,   984,
     114,    92,    86,   497,   179,   127,   175,   113,    20,   115,
     132,    71,   179,   507,   508,   798,   179,    34,    35,    36,
      37,    38,    39,   113,   138,   115,   179,   175,   142,    46,
     241,   145,   175,   123,   262,    52,   142,   262,    98,   262,
     146,   290,   206,   176,    99,  1242,    63,    64,   157,  1218,
      67,   163,   142,    70,    71,   176,   162,  1030,   142,   270,
     271,  1064,   273,   274,  1006,   175,   157,   149,   879,   738,
     739,  1074,   262,   262,   202,   569,   226,   183,   110,   862,
      99,   190,   246,   262,   860,   224,   103,   104,   105,   145,
    1151,   241,  1175,   105,   175,   201,   952,   733,   158,   726,
     142,  1319,   595,    99,   254,  1401,   256,    88,    86,   295,
      86,  1407,   298,   142,   263,  1411,   266,   248,   249,   269,
     175,   248,   249,   165,     4,    99,   210,   211,     8,   361,
    1014,   240,   149,   260,     8,   226,   377,   149,   252,   380,
     157,    43,   174,   375,    99,    19,   295,   145,    99,   298,
     241,   644,   243,   244,   245,    25,   175,   120,    20,   935,
      99,   402,  1014,   254,   145,   256,   275,   276,   277,   278,
     261,    41,    99,   190,   147,   266,   267,   268,   269,   175,
     421,   422,   110,   424,    26,   426,   789,    99,    45,   430,
     137,   164,   209,    99,    51,    99,   345,    54,    55,   431,
     803,   175,   351,    86,   445,    62,    48,   154,   357,   346,
      56,    57,   361,   350,   157,  1218,   109,   119,   367,   460,
     175,   715,   185,   240,   175,   466,   375,   376,   722,   207,
     208,   207,   208,   113,    86,   115,   175,     8,     9,   113,
     102,   115,   135,   123,   222,   134,   222,   190,   175,   110,
     124,  1334,   114,   136,   403,   148,     8,   189,   275,   276,
     277,   278,   142,   175,   110,   214,   198,    19,   142,   175,
     219,   175,   951,    88,    53,   164,   138,   142,  1162,   948,
     142,   137,   431,   145,   136,   434,   435,   436,   909,   182,
     105,   960,   142,   182,   443,   145,   110,   446,   154,   127,
     794,   158,    88,   160,    54,    92,   800,   456,   801,   802,
    1162,   560,   561,   806,   142,   145,   557,   174,   105,   105,
      99,   562,  1295,   241,    95,   221,   258,   223,   147,   478,
     145,   824,   264,   276,   277,   278,   831,   486,   833,   155,
     272,   145,   113,   200,   115,   164,    58,    59,   198,     8,
       9,   258,   270,   271,   170,   273,   274,   264,   127,   853,
     854,   113,   856,   115,   858,   272,     8,     9,   187,   127,
     110,   142,   124,   142,   132,   146,    88,   872,  1161,   874,
     189,   214,   297,   216,   878,   626,   627,  1271,   303,   198,
     142,   162,   633,  1351,  1352,   889,   890,   891,   142,   893,
     894,   895,   896,   897,   898,  1216,   900,   901,   640,   650,
    1221,   643,   183,    87,    58,    59,  1374,    61,   912,  1271,
    1362,   258,  1380,   572,    98,   142,   263,   187,   145,   189,
     201,   142,   142,   674,   108,   145,    95,   931,   198,   933,
     934,   590,   204,   117,    88,    34,    35,    36,   239,   239,
      39,   242,   242,    95,   113,   145,   115,  1136,   563,   700,
    1344,   566,   127,   568,  1143,  1144,   110,   132,   214,  1275,
     216,   113,   214,   115,  1280,   276,   277,   278,   210,   211,
     212,   975,   221,   142,   223,    88,  1155,   146,   110,    92,
     142,   640,  1344,   227,   643,  1306,   737,   180,   181,  1310,
     142,   995,   231,   162,   146,   118,   119,    58,    59,   118,
     119,   231,   661,   362,   363,   368,   369,   348,   349,   145,
     162,   539,   540,   142,   183,   546,   547,   122,   677,   110,
    1024,     0,  1025,   548,   549,   130,   131,    84,   133,  1273,
    1274,   183,   201,  1037,  1355,   140,   179,  1041,  1042,   144,
    1044,   146,   762,   763,   157,  1049,   151,   156,  1341,   201,
     251,   179,    68,   188,    93,   714,    94,   143,   145,    34,
      34,   720,   167,    20,   141,   110,   276,  1256,  1257,   142,
     142,   142,   823,   175,   825,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,   175,   191,   192,   193,   194,
     195,   196,   142,   110,   268,   268,   110,   145,   142,   145,
    1104,   760,   761,   762,   763,  1108,   175,    27,   145,   145,
     145,  1115,    15,   226,   202,   175,    20,   175,    25,   220,
     110,    99,   220,    86,  1128,   158,    86,  1131,   241,  1133,
     243,   244,   245,   792,   159,   159,    86,   145,  1327,    20,
     253,   254,   149,   256,    99,    99,   149,   117,   261,   122,
      20,   122,   279,   266,   267,   268,   269,   142,    88,   172,
     175,   172,   172,   172,    30,    88,   172,   132,   172,    86,
     175,    99,   831,   175,   833,   175,   172,   175,   179,   172,
     175,   175,   214,   172,   172,   226,   132,   159,   175,   172,
     269,  1194,   110,   136,   110,   110,   110,   250,   252,  1203,
     122,  1205,   257,   172,    86,   173,   132,  1211,   132,   271,
     172,   172,    92,   872,   172,   874,   272,   142,   149,   186,
     272,  1225,  1226,  1227,  1228,  1229,   122,  1231,  1232,   122,
      88,   982,   142,   172,   110,   136,   110,   132,   172,    27,
     142,    20,   110,  1246,   235,   172,   110,   246,   142,  1253,
      71,    99,    99,   145,   145,   247,   175,   136,   917,   136,
     172,   920,    47,   247,   136,   134,  1017,    86,    20,   928,
      20,   930,   159,   179,   172,   175,   175,   134,   175,    99,
     132,  1032,   136,  1287,   110,   175,  1290,   110,  1292,    61,
    1294,   272,   272,   122,     6,   179,   132,   175,    98,    98,
     175,   222,   175,   174,   136,  1056,   265,   110,   175,   222,
      86,   222,   172,   222,    20,    20,   172,   145,   977,  1070,
     116,   226,    88,   174,    20,    88,   172,   172,   172,   172,
      86,    59,   185,   110,    98,   174,   110,   174,  1342,    85,
     171,   110,   110,   185,   185,   185,   495,   255,   142,   495,
     175,   594,   991,   218,   793,  1014,  1342,   775,   221,   221,
    1097,  1163,  1365,   224,   867,  1369,   255,   920,   499,  1039,
     225,  1209,  1117,   359,   262,  1034,  1051,  1105,   912,  1034,
    1039,  1115,  1112,   520,   366,  1015,  1390,   678,   456,   519,
     541,  1050,  1064,  1380,  1374,   763,   792,   283,   833,  1092,
     990,   444,   287,   738,   444,  1102,   960,   948,  1155,   739,
    1285,  1174,  1071,   949,   952,    -1,    -1,    -1,  1150,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1092,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1101,    -1,    -1,    -1,  1105,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1162,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1206,  1207,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1217,    -1,
      -1,    -1,    -1,  1222,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1271,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1291,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1307,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1319,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1344,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1358,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1370,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    20,    -1,  1403,    -1,    -1,    25,    26,  1408,
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
     278,   279,   280,    10,    -1,    -1,    -1,    -1,    -1,    -1,
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
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,    10,    -1,    -1,    -1,    -1,    -1,    -1,
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
     277,   278,   279,    10,    -1,    -1,    -1,    -1,    -1,    -1,
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
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,    10,    -1,    -1,    -1,    -1,    -1,    -1,
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
     277,   278,   279,    10,    -1,    -1,    -1,    -1,    -1,    -1,
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
     277,   278,   279,    10,    -1,    -1,    -1,    -1,    -1,    -1,
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
     277,   278,   279,    10,    -1,    -1,    -1,    -1,    -1,    -1,
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
     277,   278,   279,    10,    -1,    -1,    -1,    -1,    -1,    -1,
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
     277,   278,   279,    10,    -1,    -1,    -1,    -1,    -1,    -1,
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
     277,   278,   279,    10,    -1,    -1,    -1,    -1,    -1,    -1,
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
     277,   278,   279,    10,    -1,    -1,    -1,    -1,    -1,    -1,
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
     277,   278,   279,    10,    -1,    -1,    -1,    -1,    -1,    -1,
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
     277,   278,   279,    10,    -1,    -1,    -1,    -1,    -1,    -1,
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
     277,   278,   279,    10,    -1,    -1,    -1,    -1,    -1,    -1,
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
     277,   278,   279,    10,    -1,    -1,    -1,    -1,    -1,    -1,
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
     277,   278,   279,    10,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,   148,   149,    -1,    -1,    -1,    -1,   154,   155,   156,
     157,   158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,
      -1,   168,   169,   170,    -1,    -1,    -1,   174,    -1,   176,
     177,   178,    -1,    -1,    -1,   182,    -1,   184,    -1,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      -1,    -1,   199,   200,   201,    -1,   203,   204,    -1,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,   251,   252,    -1,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
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
     177,    -1,    -1,    -1,    -1,   182,    -1,   184,    -1,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      -1,    -1,   199,   200,    -1,    -1,   203,   204,    -1,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,   251,   252,    -1,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
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
      -1,    -1,    -1,    -1,    -1,   182,    -1,   184,    -1,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      -1,    -1,   199,   200,    -1,    -1,   203,   204,    -1,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,   251,   252,    -1,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,    14,    -1,    -1,    -1,    18,    -1,    -1,
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
     271,   272,   273,   274,   275,   276,   277,   278,   279,    14,
      -1,    -1,    -1,    18,    -1,    20,    -1,    -1,    -1,    -1,
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
     175,   176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   184,
      -1,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,    -1,    -1,   199,   200,    -1,    -1,   203,   204,
      -1,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    14,    -1,    -1,    -1,    18,
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
     279,    16,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,
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
     275,   276,   277,   278,   279,    18,    -1,    -1,    -1,    -1,
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
     273,   274,   275,   276,   277,   278,   279,    18,    -1,    -1,
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
     271,   272,   273,   274,   275,   276,   277,   278,   279,    18,
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
     279,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
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
      -1,    -1,    -1,   170,    -1,    -1,    -1,   174,   175,   176,
      -1,    -1,    -1,    -1,    -1,   182,    -1,   184,    -1,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
      -1,    -1,   199,   200,    -1,    -1,   203,   204,    -1,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,    -1,   251,   252,    -1,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      25,    26,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    -1,    -1,    84,
      -1,    86,    87,    88,    89,    -1,    -1,    92,    93,    94,
      -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,   103,   104,
     105,    -1,    -1,   108,   109,   110,    -1,    -1,    -1,    -1,
      -1,   116,   117,   118,   119,    -1,   121,    -1,    -1,    -1,
     125,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     135,   136,   137,    -1,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,    -1,    -1,    -1,    -1,   154,
     155,   156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,   174,
      -1,   176,   177,    -1,    -1,    -1,    -1,    -1,    -1,   184,
      -1,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,    -1,    -1,   199,   200,    -1,    -1,   203,   204,
      -1,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    18,    -1,    -1,    -1,    -1,
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
     273,   274,   275,   276,   277,   278,   279,    18,    -1,    -1,
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
     271,   272,   273,   274,   275,   276,   277,   278,   279,    18,
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
     279
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
     272,   273,   274,   275,   276,   277,   278,   279,   280,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   326,   327,   332,   333,   340,   342,
     347,   348,   349,   350,   351,   359,   360,   362,   363,   364,
     369,   371,   373,   374,   375,   380,   401,   404,   407,   408,
     409,   410,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   457,   458,   459,   473,   474,   476,   477,   478,
     479,   480,   481,   482,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   501,   502,   503,   504,   505,   506,
     507,   510,   516,   517,   518,    34,    35,    36,    37,    38,
      39,    46,    52,    63,    64,    67,    70,    71,   103,   104,
     105,   149,   157,   190,   209,   240,   275,   276,   277,   278,
     334,   335,   336,   352,   353,   149,    86,   142,   210,   211,
     145,    25,    26,    28,    29,    30,    31,    32,    33,    40,
      41,    42,    44,    50,    51,    53,    54,    55,    65,    66,
      89,   125,   142,   145,   157,   190,   203,   213,   214,   215,
     217,   218,   225,   228,   229,   230,   232,   233,   234,   236,
     516,   142,   142,   145,   142,   145,   145,    26,    48,    14,
     142,   145,   515,   516,   110,   110,   110,   142,    56,    57,
     110,   366,    54,   145,   145,   142,   145,   516,    30,    32,
      33,    42,    89,   441,   516,   516,   110,   175,   360,   516,
     142,   515,    16,   516,   516,   433,   142,    21,   202,   204,
     214,   216,   145,   214,   216,   214,   214,   219,   110,   142,
     343,   227,   231,   231,   145,   142,   110,   297,     0,   299,
     300,    25,    41,   302,   359,   179,   179,    99,   179,   361,
      45,    51,    54,    55,    62,   158,   160,   174,   200,   365,
     370,   371,   372,   389,   390,   394,   376,   377,   516,   156,
      84,   122,   130,   131,   133,   140,   144,   146,   151,   167,
     191,   192,   193,   194,   195,   196,   425,   426,   251,   147,
     164,   187,   109,   135,   148,   182,   189,   198,   126,   139,
      68,   188,    93,    94,   147,   164,   424,   142,   430,   433,
     180,   181,   143,   445,   446,   441,   445,   441,   445,   145,
     516,   353,    34,   354,   352,   352,   353,   516,   170,   184,
     157,   190,    20,   514,   155,   170,   170,   184,   516,   141,
     110,   331,    30,    34,    71,    98,   158,   515,   335,   335,
     210,   211,   212,    92,   226,   241,   254,   256,   266,   269,
     530,   531,   532,   533,   534,   537,   542,   543,   334,   516,
     336,   336,   515,   499,   516,   360,   142,   142,   360,   360,
     175,   182,   516,   142,   360,   360,   175,   360,   175,   360,
     149,   514,   105,   149,   325,   514,   360,    20,   175,   515,
     142,   402,   403,   516,   516,   381,   383,   516,   363,   268,
     268,   110,   384,   110,   516,    30,    65,   175,   497,   498,
     360,   175,   182,   516,   142,   402,   175,    27,   461,   462,
     463,   360,     7,   163,    15,   175,   360,   202,    20,   363,
     363,   175,   363,   363,   363,   363,   220,   508,   509,   516,
     344,   363,   363,   363,   382,   388,   516,   304,   305,    25,
     306,   363,   362,   158,   110,   159,   159,   363,   363,    99,
      86,    88,   136,   262,   378,   379,   484,   409,   410,   412,
     412,   412,   412,   411,   412,   412,   412,   142,   145,   252,
     448,   519,   521,   522,   523,   524,   525,   526,   527,   415,
     415,   414,   416,   416,   416,   416,   417,   417,   418,   418,
     220,    86,    86,    86,   172,   360,   433,   433,   360,   446,
     175,   363,   456,   145,   341,   516,    20,    99,    99,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,   308,
     309,   310,    86,   127,   132,   328,   329,   330,   516,   127,
     132,   149,   149,   308,   514,   117,   122,   239,   242,   105,
     241,   270,   271,   273,   274,   239,   242,    20,   241,   270,
     271,   273,   274,   279,   122,   142,   172,   360,   360,   175,
     172,    99,   175,    99,   175,   172,   360,   172,   172,   172,
     175,   515,    88,    30,   515,   514,    88,   172,   175,   175,
     172,   360,    99,   176,   136,   484,   132,    99,   132,   379,
     484,   172,   516,    60,   206,   246,   367,   368,   175,   175,
     175,   172,    99,   175,    99,   175,   172,   360,   176,   516,
     462,   463,   120,   185,   172,   172,   121,   179,    86,   207,
     208,   222,    86,   207,   208,   222,    86,   226,   214,    99,
     224,   132,    25,   345,   360,   175,   172,    53,    99,   179,
     105,   179,   159,   516,   363,   395,   396,   110,   391,   392,
     110,   141,   199,   485,   487,   488,   489,   516,   110,   363,
     110,   136,   379,   136,   136,   378,   379,   412,   360,   519,
     525,   269,   553,    88,   157,   243,   244,   245,   253,   261,
     267,   268,   520,   528,   529,   530,   544,   547,   548,   550,
     250,   252,   257,   549,   237,   238,   259,   545,   485,   485,
     483,   488,   483,   172,   173,    99,   175,   110,   175,   355,
     356,   127,   142,   358,   341,   137,   154,   137,   154,   309,
     122,   487,   330,   363,   484,   132,   363,   514,   514,   118,
     119,   514,   271,   272,    88,   105,   145,   536,   272,   360,
     514,   360,   172,   172,    92,   405,   406,   142,   499,   500,
     516,   499,   500,   172,   186,   122,   324,   514,   149,   122,
      88,   324,   142,   172,   110,   363,   363,   136,   363,   110,
     363,   132,   132,   379,   136,   484,   246,    58,    59,    61,
     110,   378,   385,   386,   387,   368,   142,   499,   499,   172,
     363,    27,   463,   120,   185,     8,     9,    95,   113,   115,
     142,   183,   357,   458,   460,   471,   472,   475,    20,   221,
     223,   363,   363,   363,   221,   223,   363,   363,   363,   363,
     363,   363,   110,   363,   363,   331,   346,    99,   179,   172,
     343,   235,   511,   512,   142,   110,   395,    87,    98,   108,
     117,   397,   398,   399,   400,    99,   516,    99,   377,   145,
     145,   134,   164,   182,   486,   516,   516,   363,   136,   363,
     363,   136,   379,   136,   172,   175,   247,   206,   246,   258,
     263,   552,    88,   248,   249,   546,   247,   522,   552,   413,
     416,   267,   528,   530,   523,   136,   546,   272,    47,   134,
     363,   516,    86,    99,   175,   360,   127,   343,   501,   329,
     363,   272,    88,   145,   539,    20,   105,   536,   159,   179,
     172,   110,   485,   105,   406,   172,   360,   175,   175,   134,
     175,   175,   363,   514,    99,   324,   172,   360,   403,   363,
     383,   363,   363,   132,   363,   136,   110,   110,   363,   516,
     387,    61,   172,   360,   175,   175,   122,   183,   460,     6,
     360,   516,   183,   471,   179,   222,   222,   222,   222,   226,
     509,   174,   132,   346,   442,   513,   512,   363,   388,   514,
     118,   119,   399,   400,   400,   396,    98,   393,   392,   175,
     175,   363,   363,   136,   363,   416,    43,   119,   416,   416,
     258,   264,   272,   551,   551,   413,   524,   265,   484,   485,
     356,    86,   172,   126,   189,   538,   541,    20,    20,   540,
     538,   260,   546,    99,   175,    99,   175,   145,   337,   516,
     174,   110,   174,   172,   116,    88,   514,   172,   363,   363,
     516,   516,   386,   363,   172,   463,   516,   183,   172,   463,
     516,   363,   363,   363,   363,   363,   363,   363,   145,   198,
     358,   172,   400,   514,   363,   416,   416,   187,   485,   539,
     539,   541,    20,   175,    20,   255,   535,   536,   535,   338,
     339,   363,    99,   175,    86,   363,   516,   363,   363,   324,
      59,    85,   171,   464,   463,   516,   185,   463,   110,   442,
     416,   546,    99,   175,   175,    98,   484,   338,   485,   174,
     110,     4,   123,   467,   468,   470,   472,    19,   124,   465,
     466,   469,   472,   185,   463,   185,   516,   255,   536,   514,
     174,   363,   516,    85,   123,   470,   171,   124,   469,   185,
      99,   175,   363,   110,   358,   516,    99,   175,   110,   358,
     516,   175,   358
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
     545,   546,   547,   548,   549
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   295,   296,   296,   297,   297,   297,   297,   298,   298,
     299,   299,   300,   300,   301,   302,   302,   302,   303,   303,
     304,   304,   305,   305,   305,   305,   306,   306,   306,   306,
     306,   306,   306,   307,   307,   308,   308,   309,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   311,   311,
     311,   311,   311,   311,   311,   311,   312,   312,   313,   314,
     314,   315,   315,   316,   317,   318,   318,   319,   319,   320,
     320,   320,   320,   321,   322,   323,   323,   323,   323,   324,
     324,   325,   325,   326,   326,   326,   326,   327,   328,   328,
     329,   329,   329,   330,   331,   331,   332,   332,   332,   333,
     333,   334,   334,   334,   335,   335,   335,   336,   337,   337,
     338,   338,   339,   339,   340,   340,   341,   341,   341,   341,
     342,   343,   344,   344,   345,   345,   346,   346,   347,   348,
     349,   350,   350,   351,   351,   351,   352,   352,   352,   352,
     353,   353,   354,   354,   355,   355,   356,   356,   357,   358,
     359,   360,   360,   361,   361,   362,   362,   363,   363,   363,
     363,   363,   363,   363,   363,   363,   363,   363,   363,   363,
     363,   363,   363,   363,   364,   365,   366,   366,   367,   367,
     367,   368,   368,   369,   369,   370,   371,   371,   371,   372,
     372,   372,   372,   372,   373,   373,   374,   374,   375,   376,
     376,   377,   377,   377,   377,   377,   377,   377,   377,   378,
     379,   380,   381,   381,   382,   382,   383,   383,   383,   383,
     384,   384,   385,   385,   385,   386,   386,   386,   387,   387,
     387,   388,   389,   390,   391,   391,   392,   392,   393,   394,
     394,   395,   395,   396,   396,   397,   397,   397,   397,   397,
     397,   397,   398,   398,   399,   399,   400,   401,   401,   402,
     402,   403,   403,   404,   404,   405,   405,   406,   406,   407,
     408,   408,   409,   409,   410,   410,   410,   410,   410,   411,
     410,   410,   410,   410,   412,   412,   412,   413,   413,   414,
     414,   414,   415,   415,   415,   415,   415,   416,   416,   416,
     417,   417,   417,   418,   418,   419,   419,   420,   420,   421,
     421,   422,   422,   423,   423,   423,   423,   424,   424,   424,
     425,   425,   425,   425,   425,   425,   426,   426,   426,   427,
     427,   427,   427,   428,   428,   429,   429,   430,   430,   431,
     431,   431,   431,   432,   433,   433,   433,   434,   434,   435,
     435,   435,   435,   436,   436,   437,   437,   437,   437,   437,
     437,   437,   438,   438,   439,   439,   440,   440,   440,   440,
     440,   441,   441,   442,   442,   443,   443,   443,   444,   444,
     445,   445,   446,   447,   447,   447,   447,   447,   447,   447,
     447,   448,   448,   449,   449,   449,   450,   451,   451,   452,
     453,   454,   455,   455,   456,   456,   457,   457,   458,   458,
     458,   459,   459,   459,   459,   459,   459,   460,   460,   461,
     461,   462,   463,   463,   464,   464,   465,   465,   466,   466,
     466,   466,   467,   467,   468,   468,   468,   468,   469,   469,
     470,   470,   471,   471,   471,   471,   472,   472,   472,   472,
     473,   473,   474,   474,   475,   476,   476,   476,   476,   476,
     476,   477,   478,   478,   478,   478,   479,   479,   479,   479,
     480,   481,   482,   482,   482,   482,   483,   483,   484,   485,
     485,   485,   486,   486,   486,   487,   487,   487,   488,   489,
     489,   489,   489,   489,   489,   489,   489,   489,   490,   491,
     491,   491,   492,   493,   494,   494,   494,   495,   495,   495,
     495,   495,   496,   497,   497,   497,   497,   497,   497,   497,
     498,   499,   500,   501,   502,   502,   502,   503,   503,   503,
     503,   503,   503,   503,   503,   503,   503,   504,   504,   505,
     505,   506,   507,   508,   508,   509,   510,   511,   511,   512,
     512,   512,   512,   513,   513,   514,   515,   515,   516,   516,
     517,   517,   517,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   517,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   517,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   517,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   517,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   517,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   517,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   517,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   517,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   517,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   517,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   517,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   517,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   517,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   517,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   517,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   517,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   517,   517,   517,   517,   517,   517,   517,   517,
     517,   517,   517,   518,   518,   519,   519,   519,   519,   520,
     520,   520,   520,   521,   521,   522,   522,   523,   523,   524,
     524,   525,   525,   525,   526,   526,   527,   527,   528,   528,
     528,   528,   528,   529,   530,   530,   530,   530,   530,   530,
     530,   531,   531,   531,   531,   532,   532,   532,   532,   533,
     533,   534,   534,   534,   534,   534,   534,   534,   535,   535,
     536,   536,   536,   536,   537,   537,   537,   537,   537,   538,
     538,   539,   539,   540,   540,   541,   541,   542,   543,   543,
     544,   544,   544,   545,   545,   545,   545,   545,   546,   546,
     546,   546,   547,   548,   549,   550,   550,   551,   551,   551,
     552,   552,   553
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  xquery_parser::yyr2_[] =
  {
         0,     2,     1,     2,     1,     2,     1,     2,     4,     6,
       2,     1,     1,     2,     6,     2,     2,     4,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     3,
       3,     5,     5,     4,     3,     3,     3,     5,     5,     5,
       5,     5,     5,     4,     3,     3,     4,     5,     6,     1,
       3,     3,     3,     3,     6,     5,     8,     4,     3,     1,
       1,     1,     2,     2,     2,     3,     5,     4,     6,     2,
       3,     1,     2,     2,     1,     2,     2,     7,     2,     3,
       1,     3,     1,     2,     3,     3,     2,     3,     4,     5,
       2,     4,     3,     0,     3,     2,     1,     3,     5,     3,
       5,     2,     2,     2,     3,     3,     1,     2,     2,     2,
       4,     4,     4,     4,     1,     3,     2,     3,     3,     3,
       1,     1,     2,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     1,     1,
       2,     4,     3,     5,     4,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     3,     2,     1,
       4,     3,     4,     4,     5,     4,     5,     5,     6,     3,
       3,     3,     1,     4,     1,     4,     3,     4,     4,     5,
       4,     5,     1,     2,     3,     1,     2,     1,     6,     3,
       3,     1,     2,     3,     1,     3,     2,     3,     2,     3,
       4,     1,     3,     1,     2,     1,     1,     1,     2,     2,
       2,     3,     1,     1,     2,     2,     2,     5,     5,     1,
       4,     3,     4,     8,    10,     1,     2,     4,     7,     8,
       1,     3,     1,     3,     1,     3,     3,     3,     3,     0,
       4,     3,     3,     3,     1,     3,     4,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     4,     1,     4,     1,     4,     1,
       4,     1,     2,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       5,     5,     6,     3,     4,     1,     2,     3,     2,     1,
       2,     2,     1,     1,     1,     3,     3,     1,     1,     1,
       2,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     3,     1,
       4,     4,     3,     4,     1,     3,     1,     1,     1,     1,
       1,     4,     5,     8,     9,     9,    10,     1,     2,     1,
       2,     6,     0,     1,     3,     3,     0,     1,     1,     1,
       2,     2,     0,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     3,     3,     2,     1,     1,     1,     1,     1,
       1,     4,     4,     5,     6,     7,     4,     5,     6,     7,
       4,     4,     4,     5,     6,     7,     1,     2,     2,     1,
       2,     3,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       4,     4,     3,     3,     3,     4,     4,     3,     4,     6,
       4,     6,     3,     3,     4,     6,     6,     4,     6,     6,
       4,     1,     2,     1,     3,     3,     3,     5,     7,     7,
       5,     5,     5,     7,     7,     5,     5,     3,     3,     5,
       7,     5,     7,     1,     4,     3,     5,     1,     2,     3,
       7,    10,    13,     1,     3,     1,     1,     1,     1,     1,
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
       1,     1,     1,     7,     4,     1,     2,     3,     4,     1,
       1,     2,     2,     1,     3,     1,     3,     1,     4,     1,
       2,     1,     2,     3,     1,     2,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     3,     3,     5,     7,     5,     7,     2,     1,     3,
       2,     4,     4,     6,     4,     5,     4,     5,     3,     1,
       2,     2,     3,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     2,     1,     2,     1,     2,     3,
       3,     4,     3,     3,     3,     2,     2,     1,     1,     1,
       1,     1,     3
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
  "\"'words'\"", "\"'thesaurus'\"", "\"'wildcards'\"", "\"'unique'\"",
  "\"'index'\"", "\"'manual'\"", "\"'automatic'\"", "\"'on'\"",
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
  "CtxItemDecl4", "VarNameAndType", "VarDecl", "IndexDecl", "IndexDecl2",
  "IndexDecl3", "IndexDeclSuffix", "IndexKeyList", "IndexKeySpec",
  "IndexKeySpec1", "ConstructionDecl", "FunctionSig", "BlockExpr", "Block",
  "BlockDecls", "BlockVarDeclList", "BlockVarDecl", "AssignExpr",
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
       296,     0,    -1,   297,    -1,   280,   297,    -1,   299,    -1,
     298,   299,    -1,   300,    -1,   298,   300,    -1,   203,   204,
      20,   179,    -1,   203,   204,    20,   121,    20,   179,    -1,
     302,   359,    -1,   359,    -1,   301,    -1,   301,   302,    -1,
      26,   149,   515,   122,   514,   179,    -1,   303,   179,    -1,
     304,   179,    -1,   303,   179,   304,   179,    -1,   305,    -1,
     303,   179,   305,    -1,   306,    -1,   304,   179,   306,    -1,
     311,    -1,   312,    -1,   313,    -1,   315,    -1,   332,    -1,
     327,    -1,   351,    -1,   316,    -1,   317,    -1,   333,    -1,
     307,    -1,    25,   105,    71,   308,    -1,    25,    71,   516,
     308,    -1,   309,    -1,   308,   309,    -1,   310,   122,   501,
      -1,    72,    -1,    73,    -1,    74,    -1,    75,    -1,    76,
      -1,    77,    -1,    78,    -1,    79,    -1,    80,    -1,    81,
      -1,   314,    -1,   321,    -1,   322,    -1,   340,    -1,   318,
      -1,   319,    -1,   320,    -1,   502,    -1,   323,    -1,   326,
      -1,    25,   149,   515,   122,   514,    -1,    25,    70,   170,
      -1,    25,    70,   184,    -1,    25,   105,    30,   149,   514,
      -1,    25,   105,    34,   149,   514,    -1,    25,    46,   516,
      20,    -1,    25,   240,   530,    -1,    25,    63,   157,    -1,
      25,    63,   190,    -1,    25,   105,   158,   117,   118,    -1,
      25,   105,   158,   117,   119,    -1,    25,    67,   170,    99,
     137,    -1,    25,    67,   170,    99,   154,    -1,    25,    67,
     155,    99,   137,    -1,    25,    67,   155,    99,   154,    -1,
      25,   105,    98,   514,    -1,    25,    64,   514,    -1,    41,
      48,   514,    -1,    41,    48,   325,   514,    -1,    41,    48,
     514,    88,   324,    -1,    41,    48,   325,   514,    88,   324,
      -1,   514,    -1,   324,    99,   514,    -1,   149,   515,   122,
      -1,   105,    30,   149,    -1,    41,    26,   514,    -1,    41,
      26,   149,   515,   122,   514,    -1,    41,    26,   514,    88,
     324,    -1,    41,    26,   149,   515,   122,   514,    88,   324,
      -1,    25,   103,   141,   328,    -1,    86,   487,   329,    -1,
     329,    -1,   330,    -1,   127,    -1,   127,   330,    -1,   132,
     363,    -1,   110,   516,    -1,   110,   516,   484,    -1,    25,
     104,   331,   132,   363,    -1,    25,   104,   331,   127,    -1,
      25,   104,   331,   127,   132,   363,    -1,    25,   334,    -1,
      25,   275,   334,    -1,   335,    -1,   190,   335,    -1,   157,
     335,    -1,   336,    -1,   277,   336,    -1,   278,   336,    -1,
     276,   516,   279,   360,   159,   337,   175,    -1,   145,   338,
      -1,   337,    99,   338,    -1,   339,    -1,   339,    98,   514,
      -1,   363,    -1,   363,   484,    -1,    25,    52,   170,    -1,
      25,    52,   184,    -1,   145,   175,    -1,   145,   355,   175,
      -1,   145,   175,    86,   485,    -1,   145,   355,   175,    86,
     485,    -1,   228,   343,    -1,   142,   344,   360,   172,    -1,
     344,   345,   179,    -1,    -1,   345,    99,   346,    -1,    25,
     346,    -1,   331,    -1,   331,   132,   363,    -1,    50,   110,
     516,   132,   363,    -1,   229,   227,   363,    -1,   233,   145,
     363,   175,   343,    -1,   230,   231,    -1,   232,   231,    -1,
      25,   352,    -1,    25,    38,   352,    -1,    25,    37,   352,
      -1,   353,    -1,    39,   353,    -1,    35,   353,    -1,    36,
     354,    -1,    34,   516,   341,   358,    -1,    34,   516,   341,
     127,    -1,    34,   516,   341,   343,    -1,    34,   516,   341,
     127,    -1,   356,    -1,   355,    99,   356,    -1,   110,   516,
      -1,   110,   516,   484,    -1,   142,   360,   172,    -1,   142,
     360,   172,    -1,   360,    -1,   362,    -1,   362,   361,    -1,
     179,    -1,   361,   362,   179,    -1,   363,    -1,   362,    99,
     363,    -1,   364,    -1,   401,    -1,   404,    -1,   407,    -1,
     408,    -1,   503,    -1,   504,    -1,   506,    -1,   505,    -1,
     507,    -1,   510,    -1,   518,    -1,   348,    -1,   349,    -1,
     350,    -1,   347,    -1,   342,    -1,   373,   365,    -1,   174,
     363,    -1,    56,   268,    -1,    57,   268,    -1,   206,    -1,
     246,    -1,    60,   246,    -1,   367,   385,    61,   363,    -1,
     367,    61,   363,    -1,    54,   366,   384,   368,   368,    -1,
      54,   366,   384,   368,    -1,    62,   110,   516,    -1,   375,
      -1,   380,    -1,   369,    -1,   371,    -1,   389,    -1,   394,
      -1,   390,    -1,   370,    -1,   371,    -1,   373,   372,    -1,
      54,   110,    -1,    55,    54,   110,    -1,   374,   376,    -1,
     377,    -1,   376,    99,   110,   377,    -1,   516,   136,   363,
      -1,   516,   484,   136,   363,    -1,   516,   378,   136,   363,
      -1,   516,   484,   378,   136,   363,    -1,   516,   379,   136,
     363,    -1,   516,   484,   379,   136,   363,    -1,   516,   378,
     379,   136,   363,    -1,   516,   484,   378,   379,   136,   363,
      -1,    88,   110,   516,    -1,   262,   110,   516,    -1,    51,
     110,   381,    -1,   383,    -1,   381,    99,   110,   383,    -1,
     388,    -1,   382,    99,   110,   388,    -1,   516,   132,   363,
      -1,   516,   484,   132,   363,    -1,   516,   379,   132,   363,
      -1,   516,   484,   379,   132,   363,    -1,   110,   516,   136,
     363,    -1,   110,   516,   484,   136,   363,    -1,   386,    -1,
     110,   516,    -1,   110,   516,   386,    -1,   378,    -1,   378,
     387,    -1,   387,    -1,    58,   110,   516,    59,   110,   516,
      -1,    59,   110,   516,    -1,    58,   110,   516,    -1,   516,
      -1,   200,   363,    -1,   160,   159,   391,    -1,   392,    -1,
     391,    99,   392,    -1,   110,   516,    -1,   110,   516,   393,
      -1,    98,   514,    -1,   158,   159,   395,    -1,    45,   158,
     159,   395,    -1,   396,    -1,   395,    99,   396,    -1,   363,
      -1,   363,   397,    -1,   398,    -1,   399,    -1,   400,    -1,
     398,   399,    -1,   398,   400,    -1,   399,   400,    -1,   398,
     399,   400,    -1,    87,    -1,   108,    -1,   117,   118,    -1,
     117,   119,    -1,    98,   514,    -1,    44,   110,   402,   176,
     363,    -1,   125,   110,   402,   176,   363,    -1,   403,    -1,
     402,    99,   110,   403,    -1,   516,   136,   363,    -1,   516,
     484,   136,   363,    -1,    29,   145,   360,   175,   405,   105,
     174,   363,    -1,    29,   145,   360,   175,   405,   105,   110,
     516,   174,   363,    -1,   406,    -1,   405,   406,    -1,    92,
     485,   174,   363,    -1,    92,   110,   516,    86,   485,   174,
     363,    -1,    40,   145,   360,   175,   186,   363,   116,   363,
      -1,   409,    -1,   408,   156,   409,    -1,   410,    -1,   409,
      84,   410,    -1,   412,    -1,   412,   425,   412,    -1,   412,
     426,   412,    -1,   412,   122,   412,    -1,   412,   151,   412,
      -1,    -1,   412,   146,   411,   412,    -1,   412,   144,   412,
      -1,   412,   133,   412,    -1,   412,   131,   412,    -1,   413,
      -1,   413,   251,   519,    -1,   413,   251,   519,   553,    -1,
     414,    -1,   414,   187,   414,    -1,   415,    -1,   414,   164,
     415,    -1,   414,   147,   415,    -1,   416,    -1,   415,   182,
     416,    -1,   415,   109,   416,    -1,   415,   135,   416,    -1,
     415,   148,   416,    -1,   417,    -1,   416,   189,   417,    -1,
     416,   198,   417,    -1,   418,    -1,   417,   139,   418,    -1,
     417,   126,   418,    -1,   419,    -1,   419,    68,   220,   485,
      -1,   420,    -1,   420,   188,    86,   485,    -1,   421,    -1,
     421,    93,    86,   483,    -1,   422,    -1,   422,    94,    86,
     483,    -1,   424,    -1,   423,   424,    -1,   164,    -1,   147,
      -1,   423,   164,    -1,   423,   147,    -1,   427,    -1,   431,
      -1,   428,    -1,   191,    -1,   196,    -1,   195,    -1,   194,
      -1,   193,    -1,   192,    -1,   140,    -1,   167,    -1,   130,
      -1,    28,   142,   360,   172,    -1,    28,   211,   142,   360,
     172,    -1,    28,   210,   142,   360,   172,    -1,    28,    86,
     499,   142,   360,   172,    -1,   429,   142,   172,    -1,   429,
     142,   360,   172,    -1,   430,    -1,   429,   430,    -1,   165,
     516,    15,    -1,   165,    16,    -1,   432,    -1,   432,   433,
      -1,   181,   433,    -1,   433,    -1,   180,    -1,   434,    -1,
     434,   180,   433,    -1,   434,   181,   433,    -1,   435,    -1,
     444,    -1,   436,    -1,   436,   445,    -1,   439,    -1,   439,
     445,    -1,   437,   441,    -1,   438,    -1,    97,    -1,   106,
      -1,    90,    -1,   178,    -1,   107,    -1,   129,    -1,   128,
      -1,   441,    -1,    91,   441,    -1,   440,   441,    -1,   112,
      -1,   161,    -1,    82,    -1,   169,    -1,   168,    -1,    83,
      -1,   489,    -1,   442,    -1,   516,    -1,   443,    -1,   182,
      -1,    10,    -1,    17,    -1,   447,    -1,   447,   445,    -1,
     446,    -1,   445,   446,    -1,   143,   360,   173,    -1,   448,
      -1,   450,    -1,   451,    -1,   452,    -1,   455,    -1,   457,
      -1,   453,    -1,   454,    -1,   449,    -1,   501,    -1,   102,
      -1,   138,    -1,   114,    -1,   110,   516,    -1,   145,   175,
      -1,   145,   360,   175,    -1,   111,    -1,   157,   142,   360,
     172,    -1,   190,   142,   360,   172,    -1,   516,   145,   175,
      -1,   516,   145,   456,   175,    -1,   363,    -1,   456,    99,
     363,    -1,   458,    -1,   476,    -1,   459,    -1,   473,    -1,
     474,    -1,   146,   516,   463,   120,    -1,   146,   516,   461,
     463,   120,    -1,   146,   516,   463,   185,   183,   516,   463,
     185,    -1,   146,   516,   463,   185,   460,   183,   516,   463,
     185,    -1,   146,   516,   461,   463,   185,   183,   516,   463,
     185,    -1,   146,   516,   461,   463,   185,   460,   183,   516,
     463,   185,    -1,   471,    -1,   460,   471,    -1,   462,    -1,
     461,   462,    -1,    27,   516,   463,   122,   463,   464,    -1,
      -1,    27,    -1,   171,   465,   171,    -1,    85,   467,    85,
      -1,    -1,   466,    -1,   124,    -1,   469,    -1,   466,   124,
      -1,   466,   469,    -1,    -1,   468,    -1,   123,    -1,   470,
      -1,   468,   123,    -1,   468,   470,    -1,    19,    -1,   472,
      -1,     4,    -1,   472,    -1,   458,    -1,     9,    -1,   475,
      -1,   472,    -1,     8,    -1,   113,    -1,   115,    -1,   357,
      -1,   201,    21,   202,    -1,   201,   202,    -1,   162,   515,
     163,    -1,   162,   515,     7,    -1,    95,     6,    -1,   477,
      -1,   478,    -1,   479,    -1,   480,    -1,   481,    -1,   482,
      -1,    31,   142,   360,   172,    -1,    30,   516,   142,   172,
      -1,    30,   516,   142,   360,   172,    -1,    30,   142,   360,
     172,   142,   172,    -1,    30,   142,   360,   172,   142,   360,
     172,    -1,    89,   516,   142,   172,    -1,    89,   516,   142,
     360,   172,    -1,    89,   142,   360,   172,   142,   172,    -1,
      89,   142,   360,   172,   142,   360,   172,    -1,    32,   142,
     360,   172,    -1,    33,   142,   360,   172,    -1,    42,   515,
     142,   172,    -1,    42,   515,   142,   360,   172,    -1,    42,
     142,   360,   172,   142,   172,    -1,    42,   142,   360,   172,
     142,   360,   172,    -1,   488,    -1,   488,   134,    -1,    86,
     485,    -1,   487,    -1,   487,   486,    -1,   199,   145,   175,
      -1,   134,    -1,   182,    -1,   164,    -1,   488,    -1,   489,
      -1,   141,   145,   175,    -1,   516,    -1,   491,    -1,   497,
      -1,   495,    -1,   498,    -1,   496,    -1,   494,    -1,   493,
      -1,   492,    -1,   490,    -1,   214,   145,   175,    -1,    66,
     145,   175,    -1,    66,   145,   497,   175,    -1,    66,   145,
     498,   175,    -1,    32,   145,   175,    -1,    33,   145,   175,
      -1,    42,   145,   175,    -1,    42,   145,   515,   175,    -1,
      42,   145,    20,   175,    -1,    89,   145,   175,    -1,    89,
     145,   516,   175,    -1,    89,   145,   516,    99,   499,   175,
      -1,    89,   145,   182,   175,    -1,    89,   145,   182,    99,
     499,   175,    -1,   177,   516,   175,    -1,    30,   145,   175,
      -1,    30,   145,   516,   175,    -1,    30,   145,   516,    99,
     499,   175,    -1,    30,   145,   516,    99,   500,   175,    -1,
      30,   145,   182,   175,    -1,    30,   145,   182,    99,   499,
     175,    -1,    30,   145,   182,    99,   500,   175,    -1,    65,
     145,   516,   175,    -1,   516,    -1,   516,   134,    -1,    20,
      -1,    25,   209,   210,    -1,    25,   209,   211,    -1,    25,
     209,   212,    -1,   215,   214,   363,   222,   363,    -1,   215,
     214,   363,    86,   221,   222,   363,    -1,   215,   214,   363,
      86,   223,   222,   363,    -1,   215,   214,   363,   207,   363,
      -1,   215,   214,   363,   208,   363,    -1,   215,   216,   363,
     222,   363,    -1,   215,   216,   363,    86,   221,   222,   363,
      -1,   215,   216,   363,    86,   223,   222,   363,    -1,   215,
     216,   363,   207,   363,    -1,   215,   216,   363,   208,   363,
      -1,   213,   214,   363,    -1,   213,   216,   363,    -1,   218,
     214,   363,   226,   363,    -1,   218,   219,   220,   214,   363,
     226,   363,    -1,   217,   214,   363,    86,   363,    -1,   225,
     110,   508,   224,   363,   174,   363,    -1,   509,    -1,   508,
      99,   110,   509,    -1,   516,   132,   363,    -1,   234,   142,
     363,   172,   511,    -1,   512,    -1,   511,   512,    -1,   235,
     513,   358,    -1,   235,   513,   145,   110,   516,   175,   358,
      -1,   235,   513,   145,   110,   516,    99,   110,   516,   175,
     358,    -1,   235,   513,   145,   110,   516,    99,   110,   516,
      99,   110,   516,   175,   358,    -1,   442,    -1,   513,   198,
     442,    -1,    20,    -1,    14,    -1,   516,    -1,    18,    -1,
     517,    -1,   203,    -1,   117,    -1,    89,    -1,    33,    -1,
      66,    -1,    30,    -1,   141,    -1,    40,    -1,   214,    -1,
      42,    -1,    69,    -1,    65,    -1,    32,    -1,    29,    -1,
     199,    -1,    70,    -1,   240,    -1,    64,    -1,   211,    -1,
     210,    -1,   135,    -1,    31,    -1,   252,    -1,   239,    -1,
     242,    -1,   241,    -1,   269,    -1,   270,    -1,   273,    -1,
     271,    -1,   274,    -1,   245,    -1,   247,    -1,    47,    -1,
     206,    -1,   246,    -1,    43,    -1,   212,    -1,   225,    -1,
     219,    -1,   191,    -1,   196,    -1,   195,    -1,   194,    -1,
     193,    -1,   192,    -1,    88,    -1,   103,    -1,   104,    -1,
     174,    -1,    54,    -1,    55,    -1,    56,    -1,    57,    -1,
      58,    -1,    59,    -1,    60,    -1,    61,    -1,    62,    -1,
     136,    -1,    51,    -1,   200,    -1,   159,    -1,   160,    -1,
     158,    -1,    45,    -1,    87,    -1,   108,    -1,   118,    -1,
     119,    -1,    98,    -1,    44,    -1,   125,    -1,   176,    -1,
      92,    -1,    86,    -1,   186,    -1,   116,    -1,   156,    -1,
      84,    -1,    68,    -1,   220,    -1,    93,    -1,   187,    -1,
     109,    -1,   148,    -1,   189,    -1,   139,    -1,   126,    -1,
      28,    -1,    94,    -1,   188,    -1,   140,    -1,   170,    -1,
     184,    -1,   149,    -1,   127,    -1,   121,    -1,   155,    -1,
     137,    -1,   154,    -1,    25,    -1,    52,    -1,    63,    -1,
     105,    -1,    67,    -1,    46,    -1,   204,    -1,    41,    -1,
      48,    -1,    26,    -1,    34,    -1,   262,    -1,   251,    -1,
     267,    -1,   268,    -1,   244,    -1,   257,    -1,   265,    -1,
     261,    -1,   243,    -1,   256,    -1,   266,    -1,   260,    -1,
     255,    -1,   254,    -1,   238,    -1,   237,    -1,   259,    -1,
     248,    -1,   249,    -1,   272,    -1,   264,    -1,   263,    -1,
     258,    -1,   218,    -1,   224,    -1,   221,    -1,   215,    -1,
     208,    -1,   207,    -1,   209,    -1,   226,    -1,   216,    -1,
     217,    -1,   223,    -1,   213,    -1,   222,    -1,    39,    -1,
      36,    -1,    35,    -1,    37,    -1,    38,    -1,   157,    -1,
     190,    -1,   227,    -1,   228,    -1,   229,    -1,   231,    -1,
     233,    -1,   230,    -1,   232,    -1,   234,    -1,   235,    -1,
      53,    -1,   236,    -1,    50,    -1,   276,    -1,   275,    -1,
     279,    -1,   277,    -1,   278,    -1,    71,    -1,    72,    -1,
      73,    -1,    74,    -1,    75,    -1,    76,    -1,    77,    -1,
      78,    -1,    79,    -1,    80,    -1,    81,    -1,   236,   110,
     382,    53,   142,   363,   172,    -1,    53,   142,   363,   172,
      -1,   521,    -1,   521,   520,    -1,   521,   267,   413,    -1,
     521,   520,   267,   413,    -1,   530,    -1,   528,    -1,   520,
     530,    -1,   520,   528,    -1,   522,    -1,   521,   253,   522,
      -1,   523,    -1,   522,   250,   523,    -1,   524,    -1,   523,
     252,   136,   524,    -1,   525,    -1,   252,   525,    -1,   526,
      -1,   526,   549,    -1,   145,   519,   175,    -1,   527,    -1,
     527,   545,    -1,   448,    -1,   142,   360,   172,    -1,   529,
      -1,   548,    -1,   547,    -1,   550,    -1,   544,    -1,   157,
      -1,   531,    -1,   532,    -1,   533,    -1,   534,    -1,   537,
      -1,   542,    -1,   543,    -1,   256,    -1,   266,    -1,    92,
     239,    -1,    92,   242,    -1,   226,   241,    -1,   269,   241,
      -1,   241,   239,    -1,   241,   242,    -1,   226,   270,    -1,
     269,   270,    -1,   226,   273,   536,    -1,   226,   273,   105,
      -1,   226,   273,   145,   536,   175,    -1,   226,   273,   145,
     536,    99,   535,   175,    -1,   226,   273,   145,   105,   175,
      -1,   226,   273,   145,   105,    99,   535,   175,    -1,   269,
     273,    -1,   536,    -1,   535,    99,   536,    -1,    88,    20,
      -1,    88,    20,   260,    20,    -1,    88,    20,   546,   255,
      -1,    88,    20,   260,    20,   546,   255,    -1,   226,   271,
     272,   539,    -1,   226,   271,   272,   539,   538,    -1,   226,
     105,   271,   272,    -1,   226,   105,   271,   272,   538,    -1,
     269,   271,   272,    -1,   541,    -1,   538,   541,    -1,    88,
      20,    -1,   145,   540,   175,    -1,    20,    -1,   540,    20,
      -1,   189,   539,    -1,   126,   539,    -1,   254,    20,    -1,
     226,   274,    -1,   269,   274,    -1,    88,   206,    -1,    88,
     246,    -1,   245,   247,    -1,   238,    -1,   238,    47,    -1,
     237,    -1,   237,   272,    -1,   259,    -1,   248,   416,    -1,
      88,   119,   416,    -1,    88,    43,   416,    -1,   249,   416,
     187,   416,    -1,   244,   546,   551,    -1,   268,   416,   551,
      -1,   257,   546,   265,    -1,   261,   552,    -1,   243,   552,
      -1,   272,    -1,   264,    -1,   258,    -1,   263,    -1,   258,
      -1,   269,   247,   416,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  xquery_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    10,    13,    15,    18,    23,
      30,    33,    35,    37,    40,    47,    50,    53,    58,    60,
      64,    66,    70,    72,    74,    76,    78,    80,    82,    84,
      86,    88,    90,    92,    97,   102,   104,   107,   111,   113,
     115,   117,   119,   121,   123,   125,   127,   129,   131,   133,
     135,   137,   139,   141,   143,   145,   147,   149,   151,   157,
     161,   165,   171,   177,   182,   186,   190,   194,   200,   206,
     212,   218,   224,   230,   235,   239,   243,   248,   254,   261,
     263,   267,   271,   275,   279,   286,   292,   301,   306,   310,
     312,   314,   316,   319,   322,   325,   329,   335,   340,   347,
     350,   354,   356,   359,   362,   364,   367,   370,   378,   381,
     385,   387,   391,   393,   396,   400,   404,   407,   411,   416,
     422,   425,   430,   434,   435,   439,   442,   444,   448,   454,
     458,   464,   467,   470,   473,   477,   481,   483,   486,   489,
     492,   497,   502,   507,   512,   514,   518,   521,   525,   529,
     533,   535,   537,   540,   542,   546,   548,   552,   554,   556,
     558,   560,   562,   564,   566,   568,   570,   572,   574,   576,
     578,   580,   582,   584,   586,   589,   592,   595,   598,   600,
     602,   605,   610,   614,   620,   625,   629,   631,   633,   635,
     637,   639,   641,   643,   645,   647,   650,   653,   657,   660,
     662,   667,   671,   676,   681,   687,   692,   698,   704,   711,
     715,   719,   723,   725,   730,   732,   737,   741,   746,   751,
     757,   762,   768,   770,   773,   777,   779,   782,   784,   791,
     795,   799,   801,   804,   808,   810,   814,   817,   821,   824,
     828,   833,   835,   839,   841,   844,   846,   848,   850,   853,
     856,   859,   863,   865,   867,   870,   873,   876,   882,   888,
     890,   895,   899,   904,   913,   924,   926,   929,   934,   942,
     951,   953,   957,   959,   963,   965,   969,   973,   977,   981,
     982,   987,   991,   995,   999,  1001,  1005,  1010,  1012,  1016,
    1018,  1022,  1026,  1028,  1032,  1036,  1040,  1044,  1046,  1050,
    1054,  1056,  1060,  1064,  1066,  1071,  1073,  1078,  1080,  1085,
    1087,  1092,  1094,  1097,  1099,  1101,  1104,  1107,  1109,  1111,
    1113,  1115,  1117,  1119,  1121,  1123,  1125,  1127,  1129,  1131,
    1136,  1142,  1148,  1155,  1159,  1164,  1166,  1169,  1173,  1176,
    1178,  1181,  1184,  1186,  1188,  1190,  1194,  1198,  1200,  1202,
    1204,  1207,  1209,  1212,  1215,  1217,  1219,  1221,  1223,  1225,
    1227,  1229,  1231,  1233,  1236,  1239,  1241,  1243,  1245,  1247,
    1249,  1251,  1253,  1255,  1257,  1259,  1261,  1263,  1265,  1267,
    1270,  1272,  1275,  1279,  1281,  1283,  1285,  1287,  1289,  1291,
    1293,  1295,  1297,  1299,  1301,  1303,  1305,  1308,  1311,  1315,
    1317,  1322,  1327,  1331,  1336,  1338,  1342,  1344,  1346,  1348,
    1350,  1352,  1357,  1363,  1372,  1382,  1392,  1403,  1405,  1408,
    1410,  1413,  1420,  1421,  1423,  1427,  1431,  1432,  1434,  1436,
    1438,  1441,  1444,  1445,  1447,  1449,  1451,  1454,  1457,  1459,
    1461,  1463,  1465,  1467,  1469,  1471,  1473,  1475,  1477,  1479,
    1481,  1485,  1488,  1492,  1496,  1499,  1501,  1503,  1505,  1507,
    1509,  1511,  1516,  1521,  1527,  1534,  1542,  1547,  1553,  1560,
    1568,  1573,  1578,  1583,  1589,  1596,  1604,  1606,  1609,  1612,
    1614,  1617,  1621,  1623,  1625,  1627,  1629,  1631,  1635,  1637,
    1639,  1641,  1643,  1645,  1647,  1649,  1651,  1653,  1655,  1659,
    1663,  1668,  1673,  1677,  1681,  1685,  1690,  1695,  1699,  1704,
    1711,  1716,  1723,  1727,  1731,  1736,  1743,  1750,  1755,  1762,
    1769,  1774,  1776,  1779,  1781,  1785,  1789,  1793,  1799,  1807,
    1815,  1821,  1827,  1833,  1841,  1849,  1855,  1861,  1865,  1869,
    1875,  1883,  1889,  1897,  1899,  1904,  1908,  1914,  1916,  1919,
    1923,  1931,  1942,  1956,  1958,  1962,  1964,  1966,  1968,  1970,
    1972,  1974,  1976,  1978,  1980,  1982,  1984,  1986,  1988,  1990,
    1992,  1994,  1996,  1998,  2000,  2002,  2004,  2006,  2008,  2010,
    2012,  2014,  2016,  2018,  2020,  2022,  2024,  2026,  2028,  2030,
    2032,  2034,  2036,  2038,  2040,  2042,  2044,  2046,  2048,  2050,
    2052,  2054,  2056,  2058,  2060,  2062,  2064,  2066,  2068,  2070,
    2072,  2074,  2076,  2078,  2080,  2082,  2084,  2086,  2088,  2090,
    2092,  2094,  2096,  2098,  2100,  2102,  2104,  2106,  2108,  2110,
    2112,  2114,  2116,  2118,  2120,  2122,  2124,  2126,  2128,  2130,
    2132,  2134,  2136,  2138,  2140,  2142,  2144,  2146,  2148,  2150,
    2152,  2154,  2156,  2158,  2160,  2162,  2164,  2166,  2168,  2170,
    2172,  2174,  2176,  2178,  2180,  2182,  2184,  2186,  2188,  2190,
    2192,  2194,  2196,  2198,  2200,  2202,  2204,  2206,  2208,  2210,
    2212,  2214,  2216,  2218,  2220,  2222,  2224,  2226,  2228,  2230,
    2232,  2234,  2236,  2238,  2240,  2242,  2244,  2246,  2248,  2250,
    2252,  2254,  2256,  2258,  2260,  2262,  2264,  2266,  2268,  2270,
    2272,  2274,  2276,  2278,  2280,  2282,  2284,  2286,  2288,  2290,
    2292,  2294,  2296,  2298,  2300,  2302,  2304,  2306,  2308,  2310,
    2312,  2314,  2316,  2318,  2320,  2322,  2324,  2326,  2328,  2330,
    2332,  2334,  2336,  2338,  2346,  2351,  2353,  2356,  2360,  2365,
    2367,  2369,  2372,  2375,  2377,  2381,  2383,  2387,  2389,  2394,
    2396,  2399,  2401,  2404,  2408,  2410,  2413,  2415,  2419,  2421,
    2423,  2425,  2427,  2429,  2431,  2433,  2435,  2437,  2439,  2441,
    2443,  2445,  2447,  2449,  2452,  2455,  2458,  2461,  2464,  2467,
    2470,  2473,  2477,  2481,  2487,  2495,  2501,  2509,  2512,  2514,
    2518,  2521,  2526,  2531,  2538,  2543,  2549,  2554,  2560,  2564,
    2566,  2569,  2572,  2576,  2578,  2581,  2584,  2587,  2590,  2593,
    2596,  2599,  2602,  2605,  2607,  2610,  2612,  2615,  2617,  2620,
    2624,  2628,  2633,  2637,  2641,  2645,  2648,  2651,  2653,  2655,
    2657,  2659,  2661
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   888,   888,   889,   899,   904,   910,   915,   927,   932,
     942,   949,   961,   967,   979,   992,   998,  1004,  1016,  1022,
    1036,  1042,  1056,  1057,  1058,  1059,  1065,  1066,  1067,  1068,
    1071,  1074,  1076,  1082,  1087,  1096,  1102,  1111,  1120,  1121,
    1122,  1123,  1124,  1125,  1126,  1127,  1128,  1129,  1136,  1137,
    1138,  1139,  1140,  1141,  1142,  1145,  1152,  1153,  1165,  1177,
    1182,  1193,  1199,  1211,  1224,  1235,  1240,  1252,  1257,  1268,
    1274,  1280,  1286,  1305,  1316,  1327,  1334,  1341,  1348,  1361,
    1367,  1382,  1386,  1396,  1403,  1411,  1418,  1431,  1438,  1444,
    1451,  1457,  1461,  1468,  1479,  1484,  1493,  1502,  1509,  1520,
    1524,  1532,  1536,  1540,  1548,  1552,  1556,  1564,  1574,  1580,
    1588,  1592,  1600,  1604,  1614,  1619,  1631,  1635,  1639,  1643,
    1650,  1657,  1676,  1686,  1692,  1698,  1707,  1717,  1730,  1738,
    1745,  1757,  1761,  1768,  1773,  1780,  1788,  1792,  1796,  1804,
    1811,  1820,  1832,  1841,  1854,  1862,  1876,  1883,  1896,  1904,
    1915,  1926,  1930,  1942,  1946,  1955,  1959,  1975,  1976,  1977,
    1978,  1979,  1982,  1983,  1984,  1985,  1986,  1988,  1989,  1992,
    1993,  1994,  1995,  1996,  2003,  2012,  2019,  2023,  2031,  2035,
    2039,  2046,  2050,  2057,  2065,  2076,  2086,  2087,  2088,  2092,
    2092,  2092,  2092,  2092,  2095,  2101,  2110,  2114,  2124,  2135,
    2141,  2155,  2163,  2172,  2182,  2193,  2202,  2212,  2222,  2238,
    2251,  2263,  2275,  2281,  2293,  2299,  2313,  2322,  2332,  2341,
    2354,  2361,  2372,  2373,  2378,  2387,  2391,  2396,  2400,  2406,
    2411,  2419,  2435,  2443,  2450,  2456,  2467,  2474,  2484,  2494,
    2499,  2511,  2517,  2531,  2537,  2549,  2556,  2563,  2570,  2577,
    2584,  2591,  2604,  2608,  2618,  2623,  2634,  2645,  2652,  2665,
    2672,  2684,  2691,  2705,  2712,  2727,  2733,  2745,  2751,  2765,
    2776,  2780,  2791,  2795,  2814,  2818,  2826,  2834,  2842,  2850,
    2850,  2858,  2866,  2874,  2888,  2892,  2899,  2912,  2916,  2927,
    2931,  2935,  2945,  2949,  2953,  2957,  2961,  2971,  2975,  2980,
    2991,  2995,  2999,  3009,  3013,  3025,  3029,  3041,  3045,  3057,
    3061,  3073,  3077,  3089,  3093,  3097,  3101,  3113,  3117,  3121,
    3131,  3135,  3139,  3143,  3147,  3151,  3161,  3165,  3169,  3179,
    3183,  3187,  3191,  3203,  3209,  3221,  3227,  3241,  3248,  3289,
    3293,  3297,  3301,  3313,  3323,  3334,  3339,  3349,  3353,  3363,
    3369,  3375,  3381,  3393,  3399,  3410,  3414,  3418,  3422,  3426,
    3430,  3434,  3444,  3448,  3458,  3462,  3473,  3477,  3481,  3485,
    3489,  3504,  3508,  3518,  3522,  3532,  3539,  3546,  3559,  3563,
    3575,  3581,  3595,  3606,  3610,  3614,  3618,  3622,  3626,  3630,
    3634,  3644,  3648,  3658,  3663,  3668,  3679,  3690,  3694,  3705,
    3715,  3726,  3782,  3788,  3800,  3806,  3818,  3822,  3832,  3836,
    3840,  3850,  3858,  3866,  3874,  3882,  3890,  3905,  3911,  3923,
    3929,  3942,  3951,  3953,  3959,  3964,  3976,  3979,  3986,  3992,
    3998,  4006,  4021,  4024,  4031,  4037,  4043,  4051,  4065,  4070,
    4081,  4086,  4097,  4102,  4107,  4113,  4125,  4131,  4136,  4141,
    4152,  4157,  4172,  4177,  4194,  4209,  4213,  4217,  4221,  4225,
    4229,  4239,  4250,  4256,  4262,  4267,  4289,  4295,  4301,  4306,
    4317,  4327,  4337,  4343,  4349,  4354,  4365,  4371,  4383,  4394,
    4400,  4406,  4443,  4448,  4453,  4464,  4468,  4472,  4482,  4493,
    4497,  4501,  4505,  4509,  4513,  4517,  4521,  4525,  4535,  4545,
    4549,  4554,  4565,  4575,  4585,  4589,  4593,  4603,  4609,  4615,
    4621,  4627,  4639,  4650,  4657,  4664,  4671,  4678,  4685,  4692,
    4705,  4726,  4733,  4753,  4793,  4797,  4801,  4810,  4816,  4822,
    4828,  4834,  4841,  4847,  4853,  4859,  4865,  4877,  4882,  4892,
    4898,  4910,  4936,  4947,  4953,  4966,  4981,  4988,  4994,  5005,
    5012,  5022,  5033,  5049,  5055,  5065,  5074,  5075,  5093,  5097,
    5104,  5105,  5106,  5107,  5108,  5109,  5110,  5111,  5112,  5113,
    5114,  5115,  5116,  5117,  5118,  5119,  5120,  5121,  5122,  5123,
    5124,  5125,  5126,  5127,  5128,  5129,  5130,  5131,  5132,  5133,
    5134,  5135,  5136,  5137,  5138,  5139,  5140,  5141,  5142,  5143,
    5144,  5145,  5146,  5147,  5148,  5149,  5150,  5151,  5152,  5153,
    5154,  5155,  5156,  5157,  5158,  5159,  5160,  5161,  5162,  5163,
    5164,  5165,  5166,  5167,  5168,  5169,  5170,  5171,  5172,  5173,
    5174,  5175,  5176,  5177,  5178,  5179,  5180,  5181,  5182,  5183,
    5184,  5185,  5186,  5187,  5188,  5189,  5190,  5191,  5192,  5193,
    5194,  5195,  5196,  5197,  5198,  5199,  5200,  5201,  5202,  5203,
    5204,  5205,  5206,  5207,  5208,  5209,  5210,  5211,  5212,  5213,
    5214,  5215,  5216,  5217,  5218,  5219,  5220,  5221,  5222,  5223,
    5224,  5225,  5226,  5227,  5228,  5229,  5230,  5231,  5232,  5233,
    5234,  5235,  5236,  5237,  5238,  5239,  5240,  5241,  5242,  5243,
    5244,  5245,  5246,  5247,  5248,  5249,  5250,  5251,  5252,  5253,
    5254,  5255,  5256,  5257,  5258,  5259,  5260,  5261,  5262,  5263,
    5264,  5265,  5266,  5267,  5268,  5269,  5270,  5271,  5272,  5273,
    5274,  5275,  5276,  5277,  5278,  5279,  5280,  5281,  5282,  5283,
    5284,  5285,  5286,  5297,  5303,  5320,  5324,  5328,  5332,  5342,
    5345,  5348,  5351,  5360,  5363,  5372,  5375,  5384,  5387,  5396,
    5399,  5408,  5411,  5414,  5423,  5426,  5435,  5439,  5449,  5452,
    5455,  5458,  5461,  5470,  5479,  5483,  5487,  5491,  5495,  5499,
    5503,  5513,  5516,  5519,  5522,  5531,  5534,  5537,  5540,  5549,
    5552,  5561,  5564,  5567,  5570,  5573,  5576,  5579,  5588,  5591,
    5600,  5603,  5606,  5609,  5618,  5621,  5624,  5627,  5630,  5639,
    5642,  5651,  5654,  5663,  5666,  5675,  5678,  5687,  5696,  5699,
    5708,  5711,  5714,  5723,  5726,  5729,  5732,  5735,  5744,  5748,
    5752,  5756,  5766,  5775,  5785,  5794,  5797,  5806,  5809,  5812,
    5821,  5824,  5833
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 9670;
  const int xquery_parser::yynnts_ = 259;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 488;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 295;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 549;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 13379 "/home/markos/zorba/zorba/build-gdb/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 5841 "/home/markos/zorba/zorba/src/compiler/parser/xquery_parser.y"


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

