
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
#line 59 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"


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
#line 75 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 917 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_driver.h"
#include "compiler/parser/xquery_scanner.h"
#undef yylex
#define yylex driver.lexer->lex


/* Line 317 of lalr1.cc  */
#line 92 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"

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
#line 161 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
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
#line 801 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 268 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 114: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 800 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 277 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 138: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 799 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 286 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 315: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 295 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 316: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 304 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 317: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 313 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 322 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "Prolog" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 331 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 340 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 349 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 358 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 367 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 376 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 813 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->pair_vector); };

/* Line 480 of lalr1.cc  */
#line 385 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 813 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->pair); };

/* Line 480 of lalr1.cc  */
#line 394 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 403 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 412 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 421 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 430 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 439 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 448 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 457 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 466 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 475 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 484 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 493 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 502 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 511 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 520 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 529 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 538 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 547 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 556 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 565 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 813 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 574 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 583 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "DeclPropertyList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 592 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "DeclProperty" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 601 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 610 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "NodeModifier" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 619 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 628 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 637 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 646 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 655 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 664 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 813 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 673 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 682 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "Block" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 691 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "BlockDecls" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 700 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "BlockVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 709 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "BlockVarDecl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 718 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "AssignExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 727 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "ExitExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 736 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "WhileExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 745 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 754 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 763 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 772 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "FunctionDecl3" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 781 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "FunctionDecl4" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 790 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 799 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 808 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "EnclosedExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 826 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 835 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 844 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "ApplyExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 853 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "ConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 862 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 871 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 880 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 889 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 898 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 907 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 916 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 925 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 934 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 943 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 952 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 961 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 970 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 979 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 988 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "EvalVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 997 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1006 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1015 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1024 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1033 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1042 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "EvalVarDecl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1051 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1060 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1069 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1078 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1087 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1096 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1105 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1114 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1123 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1132 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1141 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1150 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1159 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1168 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1177 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1186 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1195 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1204 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1213 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1222 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1231 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1240 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1249 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1258 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1267 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1276 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1285 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1294 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1303 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1312 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1321 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1330 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1339 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1348 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1357 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1366 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1375 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1384 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1393 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1402 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "PragmaList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1411 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1420 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1429 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1438 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1447 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1456 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1465 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1474 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1483 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1492 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1501 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1510 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1519 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1528 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1537 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1546 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1555 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1564 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1573 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1582 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1591 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1600 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1609 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1618 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1627 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1636 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1645 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1654 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1663 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1672 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1681 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1690 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1699 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1708 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "Opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1717 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1726 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "Opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1735 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1744 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1753 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1762 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1771 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1780 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1789 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1798 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1807 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1816 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1825 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1834 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1843 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1852 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1861 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1870 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1879 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1888 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1897 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1906 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1915 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1924 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1933 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1942 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1951 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1960 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1969 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1978 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1987 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1996 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2005 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2014 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2023 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2032 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2041 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2050 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2059 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2068 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2077 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2086 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2095 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2104 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2113 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2122 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2131 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 813 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2140 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2149 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "EvalExpr" */

/* Line 480 of lalr1.cc  */
#line 811 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2158 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
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
#line 108 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename);
}

/* Line 553 of lalr1.cc  */
#line 2243 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"

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
#line 935 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 945 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		}
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 950 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<MainModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr ((yyval.node));
		}
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 956 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
       driver.set_expr ((yyval.node));
		}
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 961 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
       driver.set_expr ((yyval.node));
		}
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 973 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)), encoding);
		}
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 978 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 988 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)));
		}
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 995 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)),
                NULL);
		}
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1007 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC ((yyloc)),
                             static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)),
                             NULL);
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1013 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LibraryModule(LOC ((yyloc)),
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1025 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(6) - (3)].sval)),
								SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
      dynamic_cast<ModuleDecl *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
		}
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1038 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)), NULL);
		}
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1042 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		}
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1046 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC((yyloc)),
                      static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
                      static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1058 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = new SIND_DeclList(LOC ((yyloc)));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		}
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1064 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
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
#line 1078 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = new VFO_DeclList(LOC ((yyloc)));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		}
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1084 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
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
#line 1130 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].pair_vector));
      delete (yysemantic_stack_[(4) - (4)].pair_vector);
    }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 1135 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr))->get_qname(), (yysemantic_stack_[(4) - (4)].pair_vector));
      delete (yysemantic_stack_[(4) - (3)].expr);
      delete (yysemantic_stack_[(4) - (4)].pair_vector);
    }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 1144 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.pair_vector) = new std::vector<std::pair<std::string, std::string> > ();
      (yyval.pair_vector)->push_back(*(yysemantic_stack_[(1) - (1)].pair));
      delete (yysemantic_stack_[(1) - (1)].pair);
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 1150 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].pair_vector)->push_back(*(yysemantic_stack_[(2) - (2)].pair));
      delete (yysemantic_stack_[(2) - (2)].pair);
      (yyval.pair_vector) = (yysemantic_stack_[(2) - (1)].pair_vector);
    }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1159 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *s = static_cast<StringLiteral *>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.pair) = new std::pair<std::string, std::string>((yysemantic_stack_[(3) - (1)].strval), s->get_strval());
      delete s;
    }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1167 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1168 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1169 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1170 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1171 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1172 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1173 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1174 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1175 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1176 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1213 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1225 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		}
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1230 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		}
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1241 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_element_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1247 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_function_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1259 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OptionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
								SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
		}
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1272 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (3)].node));
		}
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1283 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		}
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1288 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		}
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1300 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		}
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1305 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		}
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1316 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::inherit_ns);
		}
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1322 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::no_inherit_ns);
		}
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1328 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::inherit_ns);
		}
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1334 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::no_inherit_ns);
		}
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1353 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)));
		}
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1364 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		}
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1375 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		}
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1382 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)),
								NULL);
		}
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 1389 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		}
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 1396 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
		}
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 1409 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = new URILiteralList(LOC ((yyloc)));
			uri_list_p->push_back(SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		}
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1415 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
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
#line 1430 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1434 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		}
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1444 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)), false,
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1451 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
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
#line 1459 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)), false,
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
		}
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1466 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
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
#line 1479 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1486 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->type = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1492 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1499 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(1) - (1)].node));
      d->ext = false;
      (yyval.node) = d;
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1505 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), NULL);
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1509 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1516 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1527 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(), NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1532 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
                               dynamic_cast<SequenceType *> ((yysemantic_stack_[(3) - (3)].node)));
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1541 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
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
#line 1550 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (3)].varnametype)));
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       NULL, true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
		}
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1557 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(6) - (3)].varnametype)));
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       (yysemantic_stack_[(6) - (6)].expr), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
		}
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1567 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      DeclPropertyList* l = new DeclPropertyList(LOC((yyloc)));
      l->addProperty(dynamic_cast<DeclProperty*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1573 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(2) - (1)].node))->addProperty(static_cast<DeclProperty*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1582 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DeclProperty(LOC((yyloc)), StaticContextConsts::decl_const);
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1586 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DeclProperty(LOC((yyloc)), StaticContextConsts::decl_append_only);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1590 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DeclProperty(LOC((yyloc)), StaticContextConsts::decl_queue);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1594 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DeclProperty(LOC((yyloc)), StaticContextConsts::decl_mutable);
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1598 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DeclProperty(LOC((yyloc)), StaticContextConsts::decl_ordered);
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 1602 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DeclProperty(LOC((yyloc)), StaticContextConsts::decl_unordered);
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 1606 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DeclProperty(LOC((yyloc)), StaticContextConsts::decl_value_equality);
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1610 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DeclProperty(LOC((yyloc)), StaticContextConsts::decl_value_range);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1614 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DeclProperty(LOC((yyloc)), StaticContextConsts::decl_unique);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1618 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DeclProperty(LOC((yyloc)), StaticContextConsts::decl_non_unique);
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1622 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DeclProperty(LOC((yyloc)), StaticContextConsts::decl_automatic);
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1626 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DeclProperty(LOC((yyloc)), StaticContextConsts::decl_manual);
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1634 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                               0, 
                               0, 
                               0);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1642 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                               0, 
                               static_cast<NodeModifier*>((yysemantic_stack_[(4) - (4)].node)), 
                               0);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1650 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                               0, 
                               0, 
                               static_cast<parsenode*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1658 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                               0, 
                               static_cast<NodeModifier*>((yysemantic_stack_[(6) - (6)].node)), 
                               (yysemantic_stack_[(6) - (5)].node));
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1666 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<DeclPropertyList*>((yysemantic_stack_[(4) - (2)].node)), 0, 0);
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1672 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
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
#line 1680 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<DeclPropertyList*>((yysemantic_stack_[(6) - (2)].node)), 
                               0, 
                               static_cast<parsenode*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1688 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(7) - (4)].expr)),
                               static_cast<DeclPropertyList*>((yysemantic_stack_[(7) - (2)].node)), 
                               static_cast<NodeModifier*>((yysemantic_stack_[(7) - (7)].node)), 
                               (yysemantic_stack_[(7) - (6)].node));
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1700 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1704 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1712 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                         (yysemantic_stack_[(8) - (6)].expr),
                         dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                         new DeclPropertyList(LOC((yyloc))));
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1720 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(9) - (4)].expr)),
                         (yysemantic_stack_[(9) - (7)].expr),
                         dynamic_cast<IndexKeyList*>((yysemantic_stack_[(9) - (9)].node)),
                         dynamic_cast<DeclPropertyList*>((yysemantic_stack_[(9) - (2)].node)));
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1732 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1738 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1747 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SingleType*>((yysemantic_stack_[(3) - (3)].node)),
                            NULL);
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1754 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(4) - (1)].expr),
                            dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (3)].node)),
                            dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1766 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1776 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(13) - (9)].expr)),
                                    (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1786 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                    (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1797 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
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

  case 135:

/* Line 678 of lalr1.cc  */
#line 1814 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		}
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1819 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		}
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1831 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL);
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1835 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1839 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL, dynamic_cast<SequenceType *> ((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1843 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType *> ((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1850 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1857 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
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

  case 143:

/* Line 678 of lalr1.cc  */
#line 1883 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (1)].node));
      std::auto_ptr<VFO_DeclList> vfo2(dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (2)].node)));
      if ((yysemantic_stack_[(3) - (1)].node) == NULL)
        vfo = new VFO_DeclList (LOC ((yyloc)));
      vfo->push_back (*(vfo2.get()));
      (yyval.node) = vfo;
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1892 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL;
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1899 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (1)].node));
      vfo->push_back ((yysemantic_stack_[(3) - (3)].node));
      (yyval.node) = vfo;
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1905 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = new VFO_DeclList (LOC ((yyloc)));
      vfo->push_back ((yysemantic_stack_[(2) - (2)].node));
      (yyval.node) = vfo;
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1914 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
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

  case 148:

/* Line 678 of lalr1.cc  */
#line 1924 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
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

  case 149:

/* Line 678 of lalr1.cc  */
#line 1937 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr (LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr))->get_qname(), (yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (3)].expr);
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1945 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr (LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1952 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
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

  case 152:

/* Line 678 of lalr1.cc  */
#line 1966 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1970 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::CONTINUE);
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1977 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<FunctionDecl *>((yysemantic_stack_[(2) - (2)].node))->setComment(SYMTAB((yysemantic_stack_[(2) - (1)].sval)));
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1982 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
      d->deterministic = false;
      (yyval.node) = d;
    }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1989 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<FunctionDecl *>((yysemantic_stack_[(3) - (3)].node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 1997 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 2001 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 2005 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(2) - (2)].node));
      d->type = (d->type == ParseConstants::fn_extern)
        ? ParseConstants::fn_extern_update
        : ParseConstants::fn_update;
      (yyval.node) = d;
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 2013 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 2020 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								(yysemantic_stack_[(4) - (4)].expr),
								ParseConstants::fn_read);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 2029 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								NULL,
								ParseConstants::fn_extern);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 2041 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								(yysemantic_stack_[(4) - (4)].expr),
								ParseConstants::fn_sequential);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2050 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								NULL,
								ParseConstants::fn_extern_sequential);
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 2063 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = new ParamList(LOC ((yyloc)));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)));
			}
			(yyval.node) = plist_p;
		}
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 2071 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 2085 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(),
								NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
		}
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 2092 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
      delete (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 2105 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 2113 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 2124 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QueryBody(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
		}
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 2139 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 2143 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<BlockBody> blk(dynamic_cast<BlockBody *>((yysemantic_stack_[(2) - (2)].expr)));

      BlockBody* blk2 = new BlockBody(LOC((yyloc)));

      blk2->add((yysemantic_stack_[(2) - (1)].expr));

      for (int i = 0; i < blk->size(); ++i)
        blk2->add((*blk)[i]);

      (yyval.expr) = blk2;
    }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 2159 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody (LOC ((yyloc)));
    }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 2163 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = dynamic_cast<BlockBody *>((yysemantic_stack_[(3) - (1)].expr));
      blk->add((yysemantic_stack_[(3) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 2172 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 2176 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
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

  case 195:

/* Line 678 of lalr1.cc  */
#line 2221 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
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

  case 196:

/* Line 678 of lalr1.cc  */
#line 2234 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 2241 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 2245 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 2253 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 2257 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2261 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_only_end;
    }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 2268 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), dynamic_cast<WindowVars *> ((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr), (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 2272 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr), (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 2279 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(5) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window,
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(5) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (4)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 2287 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window,
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 2298 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause (LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 2317 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = new FLWORClauseList (LOC ((yyloc)));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 2323 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = dynamic_cast<FLWORClauseList *> ((yysemantic_stack_[(2) - (1)].node));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
    }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 2332 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = NULL;
    }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 2336 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_ofor;
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 2346 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForClause(LOC ((yyloc)),
                         dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL);
		}
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 2357 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		}
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 2363 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vardecl_list_p) {
				vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 2377 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (1)].expr);
		}
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 2385 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 2394 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
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

  case 225:

/* Line 678 of lalr1.cc  */
#line 2404 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
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

  case 226:

/* Line 678 of lalr1.cc  */
#line 2415 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 2424 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
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

  case 228:

/* Line 678 of lalr1.cc  */
#line 2434 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
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

  case 229:

/* Line 678 of lalr1.cc  */
#line 2444 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
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

  case 230:

/* Line 678 of lalr1.cc  */
#line 2460 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
		}
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 2473 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
		}
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 2485 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)));

		}
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 2497 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		}
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 2503 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 2515 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		}
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 2521 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 2535 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
								NULL,
								NULL,
								(yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (1)].expr);
		}
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 2544 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 2554 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 2563 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (1)].expr);
		}
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 2576 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr))->get_qname(),
								NULL, (yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (2)].expr);
		}
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 2583 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (2)].expr);
		}
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2595 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(), "", "");
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 2600 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_curr (static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2609 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), dynamic_cast<PositionalVar *> ((yysemantic_stack_[(1) - (1)].node)), "", "", "");
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 2613 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_posvar (dynamic_cast<PositionalVar *> ((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2622 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr))->get_qname(), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr))->get_qname());
      delete (yysemantic_stack_[(6) - (3)].expr);
      delete (yysemantic_stack_[(6) - (6)].expr);
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2628 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", "", static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2633 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname(), "");
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 2641 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      std::string name = static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr))->get_qname();
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           name, NULL, NULL,
                           new VarRef (LOC ((yyloc)), name),
                           VarGetsDecl::eval_var);
      delete (yysemantic_stack_[(1) - (1)].expr);

    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2657 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 2665 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 2672 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = new GroupSpecList(LOC((yyloc)));
      gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl_p;
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 2678 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      if (gsl_p) {
        gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      }
      (yyval.node) = gsl_p;
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 2689 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(),
                 NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 2696 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
                 dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2706 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2716 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2721 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)),
								true);
		}
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2733 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		}
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2739 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node));
			if (osl_p) {
				osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2753 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		}
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2759 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
                         (yysemantic_stack_[(2) - (1)].expr),
                         dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2771 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
                               NULL,
                               NULL);
		}
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2778 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               NULL,
                               dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
                               NULL);
		}
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2785 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               NULL,
                               NULL,
                               dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2792 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                               dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                               NULL);
		}
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2799 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                               NULL,
                               dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2806 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               NULL,
                               dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                               dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2813 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                               dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                               dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2826 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		}
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2830 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		}
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2840 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC((yyloc)), StaticContextConsts::empty_greatest);
		}
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2844 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC((yyloc)), StaticContextConsts::empty_least);
		}
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 2854 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		}
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2865 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2872 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2885 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;

		}
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2892 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2904 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
								(yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (1)].expr);
		}
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2911 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2925 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
								(yysemantic_stack_[(8) - (8)].expr));
		}
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2932 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(10) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
								static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr))->get_qname(),
								(yysemantic_stack_[(10) - (10)].expr));
      delete (yysemantic_stack_[(10) - (8)].expr);
		}
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2947 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		}
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2953 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2965 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2971 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr))->get_qname(),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
      delete (yysemantic_stack_[(7) - (3)].expr);
		}
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 2985 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
		}
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 2996 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 3000 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 3011 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 3015 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 3034 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 3038 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 3046 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      /*  ::=  "is" | "<<" | ">>" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 3054 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 3062 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 3069 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { /* this call is needed */  driver.lexer->interpretAsLessThan(); }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 3070 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3078 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_le),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3086 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3094 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3108 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3112 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		}
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3119 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3132 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3136 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3147 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3151 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3155 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3165 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3169 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3173 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3177 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3181 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3191 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3195 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3200 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3211 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3215 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3219 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3229 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3233 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3245 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3249 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3261 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3265 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3277 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3281 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3293 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3297 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3309 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		}
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3313 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		}
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3317 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3321 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3333 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3337 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3341 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3351 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		}
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3355 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		}
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3359 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		}
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3363 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		}
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3367 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		}
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3371 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		}
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3381 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		}
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3385 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		}
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3389 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		}
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3399 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3403 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3407 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3411 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                            dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(),
                            (yysemantic_stack_[(6) - (5)].expr));
    }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3423 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		}
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3429 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3441 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		}
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3447 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node));
			if (pragma_list_p) {
				pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3461 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));

		}
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3467 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval))),
								"");
    }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3509 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		}
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3513 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3517 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3521 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
       RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (rpe == NULL ?
             (yysemantic_stack_[(1) - (1)].expr) :
             new PathExpr(LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3533 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3543 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
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

  case 366:

/* Line 678 of lalr1.cc  */
#line 3554 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3559 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3569 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3573 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3583 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		}
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3589 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3595 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		}
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3601 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3613 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		}
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3619 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3630 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		}
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3634 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		}
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3638 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		}
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3642 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		}
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3646 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		}
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3650 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		}
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3654 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		}
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3664 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node), false);
		}
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3668 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		}
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3678 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseStep(LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node));
		}
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3682 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC((yyloc)), rev_p, NULL);
		}
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3693 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		}
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3697 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		}
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3701 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		}
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3705 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		}
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3709 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		}
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3724 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3728 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3738 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3742 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3752 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        "",
                        ParseConstants::wild_all);
		}
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3759 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        ParseConstants::wild_elem);
		}
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3766 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        ParseConstants::wild_prefix);
		}
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3779 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3783 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
                          (yysemantic_stack_[(2) - (1)].expr),
                          dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3795 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		}
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3801 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node));
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3815 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3826 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3830 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3834 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3838 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3842 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3846 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3850 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3854 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3864 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3868 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3878 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval));
      delete yylval.decval;
		}
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3883 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival));
      delete yylval.ival;
		}
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3888 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval));
      delete yylval.dval;
		}
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3899 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new VarRef(LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname());
      delete (yysemantic_stack_[(2) - (2)].expr);
		}
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3910 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		}
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3914 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3925 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		}
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3935 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3946 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 4002 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)),
								NULL);
		}
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 4008 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 4020 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = new ArgList(LOC ((yyloc)));
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		}
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 4026 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 4038 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 4042 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 4052 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 4056 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 4060 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 4070 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
								NULL,
								NULL,
								NULL);
		}
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 4078 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
								NULL,
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)),
								NULL);
		}
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 4086 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(8) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr)),
								NULL,
								NULL);
		}
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 4094 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
								NULL,
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node)));
		}
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 4102 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
								NULL);
		}
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 4110 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(10) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)),
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node)));
		}
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4125 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		}
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4131 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4143 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		}
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4149 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4162 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
		}
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4179 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		}
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4184 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		}
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4195 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		}
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4199 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4206 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		}
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4212 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		}
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4218 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4226 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4240 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		}
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4244 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4251 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		}
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4257 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		}
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4263 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4271 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4285 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4290 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4301 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4306 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4317 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		}
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4322 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4327 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		}
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4333 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		}
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4345 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4351 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		}
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4356 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		}
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4361 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4372 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4377 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4392 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4397 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		}
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4414 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CDataSection(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		}
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4429 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4433 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4437 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4441 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4445 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4449 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4459 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4470 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
								NULL);
		}
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4476 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4482 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4487 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4509 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (2)].expr),
								NULL);
		}
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4515 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4521 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4526 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4537 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4547 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4557 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		}
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4563 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4569 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4574 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4585 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		}
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4591 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		}
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4603 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
		}
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4614 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		}
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4620 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4626 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		}
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4663 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		}
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4668 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		}
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4673 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		}
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4684 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4688 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4692 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		}
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4702 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4713 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4717 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4721 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4725 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4729 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4733 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4737 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4741 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4745 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4755 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		}
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4765 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		}
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4769 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4774 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4785 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TextTest(LOC ((yyloc)));
		}
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4795 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		}
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4805 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		}
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		}
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4813 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		}
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4823 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		}
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4829 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
								NULL);
		}
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4835 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		}
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4841 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		}
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4847 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		}
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4859 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
		}
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4870 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           NULL,
                           NULL,
                           true);
		}
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4877 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                           NULL,
                           true);
		}
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4884 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           false);
		}
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4891 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           true);
		}
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4898 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL,
									true);
		}
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4905 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									false);
		}
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4912 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									true);
		}
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4925 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)));
		}
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4946 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4953 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)),
								true);
		}
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4973 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 5013 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::strict_validation);
		}
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 5017 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::lax_validation);
    }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 5021 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::skip_validation);
    }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 5030 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 5036 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 5042 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 5048 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 5054 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 5061 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 5067 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 5073 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 5079 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 5085 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 5097 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 5102 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 5112 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 5118 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 5130 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 5156 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 5167 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
       CopyVarList* lList = new CopyVarList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
		}
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 5173 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
       CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
       VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
       lList->push_back(lBinding);
       (yyval.expr) = lList;
		}
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 5186 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (1)].expr);
    }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 5202 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 5209 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5215 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* aCatchListExpr = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if (aCatchListExpr) {
        aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)));
      }
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5226 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(3) - (2)].name_test_list),
                          (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5233 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(7) - (2)].name_test_list),
                          static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr))->get_qname(),
                          (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (5)].expr);
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5243 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
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

  case 573:

/* Line 678 of lalr1.cc  */
#line 5254 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
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

  case 574:

/* Line 678 of lalr1.cc  */
#line 5270 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      CatchExpr::NameTestList *name_test_list = new CatchExpr::NameTestList;
      name_test_list->push_back (static_cast<NameTest *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.name_test_list) = name_test_list;
    }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5276 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      CatchExpr::NameTestList *name_test_list =
        static_cast<CatchExpr::NameTestList *> ((yysemantic_stack_[(3) - (1)].name_test_list));
      name_test_list->push_back (static_cast<NameTest *> ((yysemantic_stack_[(3) - (3)].node)));
      (yyval.name_test_list) = name_test_list;
    }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5296 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
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

  case 579:

/* Line 678 of lalr1.cc  */
#line 5314 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5318 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5331 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)),
                          (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5337 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5344 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("xquery"); }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5345 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty"); }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5346 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("attribute"); }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5347 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("comment"); }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5348 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document-node"); }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5349 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("element"); }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5350 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("item"); }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5351 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("if"); }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5352 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("node"); }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5353 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("processing-instruction"); }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5354 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-attribute"); }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5355 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-element"); }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5356 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("text"); }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5357 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("typeswitch"); }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5358 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty-sequence"); }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5359 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("boundary-space"); }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5360 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ft-option"); }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5361 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("base-uri"); }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5362 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lax"); }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5363 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strict"); }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5364 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("idiv"); }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5365 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document"); }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5366 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("not"); }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5367 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sensitive"); }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5368 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insensitive"); }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5369 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("diacritics"); }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5370 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("without"); }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5371 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stemming"); }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5372 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("thesaurus"); }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5373 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stop"); }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5374 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("wildcards"); }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5375 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("entire"); }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5376 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("content"); }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5377 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("word"); }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5378 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("start"); }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5379 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("end"); }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5380 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("most"); }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5381 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("skip"); }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5382 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy"); }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5383 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("value"); }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5384 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eq"); }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5385 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ne"); }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5386 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lt"); }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5387 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("le"); }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5388 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("gt"); }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5389 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ge"); }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5390 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("at"); }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5391 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("context"); }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5392 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("variable"); }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5393 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("return"); }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5394 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("for"); }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5395 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("outer"); }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5396 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sliding"); }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5397 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("tumbling"); }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5398 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("previous"); }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5399 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("next"); }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5400 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("only"); }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5401 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("when"); }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5402 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("count"); }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5403 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("in"); }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5404 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("let"); }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5405 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("where"); }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5406 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("by"); }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5407 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("group"); }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5408 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("order"); }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5409 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stable"); }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5410 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ascending"); }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5411 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("descending"); }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5412 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("greatest"); }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5413 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("least"); }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5414 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("collation"); }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5415 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("some"); }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5416 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("every"); }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5417 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("satisfies"); }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5418 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("case"); }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5419 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("as"); }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5420 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("then"); }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5421 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("else"); }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5422 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("or"); }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5423 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("and"); }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5424 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("instance"); }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5425 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("of"); }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5426 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("castable"); }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5427 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("to"); }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5428 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("div"); }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5429 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("mod"); }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5430 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("union"); }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5431 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("intersect"); }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5432 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("except"); }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5433 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("validate"); }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5434 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("cast"); }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5435 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("treat"); }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5436 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("is"); }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5437 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("preserve"); }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5438 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strip"); }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5439 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("namespace"); }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5440 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("external"); }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5441 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("encoding"); }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5442 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-preserve"); }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5443 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("inherit"); }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5444 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-inherit"); }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5445 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("declare"); }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5446 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("construction"); }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5447 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordering"); }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5448 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("default"); }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5449 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy-namespaces"); }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5450 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("option"); }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5451 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("version"); }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5452 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("import"); }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5453 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema"); }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5454 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("module"); }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5455 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("function"); }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5456 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("score"); }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5457 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ftcontains"); }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5458 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("weight"); }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5459 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("window"); }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5460 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("distance"); }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5461 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("occurs"); }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 5462 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("times"); }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5463 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("same"); }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 5464 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("different"); }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 5465 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lowercase"); }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 5466 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("uppercase"); }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 5467 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("relationship"); }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 5468 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("levels"); }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 5469 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("language"); }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 5470 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("any"); }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 5471 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("all"); }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 5472 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("phrase"); }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 5473 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exactly"); }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 5474 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("from"); }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 5475 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("words"); }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 5476 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentences"); }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 5477 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentence"); }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 5478 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("paragraph"); }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 5479 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("replace"); }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 5480 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("modify"); }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 5481 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("first"); }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 5482 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insert"); }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 5483 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("before"); }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 5484 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("after"); }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 5485 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("revalidation"); }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 5486 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("with"); }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 5487 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nodes"); }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 5488 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("rename"); }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 5489 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("last"); }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 5490 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("delete"); }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 5491 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("into"); }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 5492 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("simple"); }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 5493 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sequential"); }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 5494 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("updating"); }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 5495 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("deterministic"); }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 5496 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nondeterministic"); }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 5497 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordered"); }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 5498 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unordered"); }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 5499 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("returning"); }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 5500 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("block"); }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 5501 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exit"); }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 5502 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("loop"); }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 5503 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("while"); }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 5504 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("break"); }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 5505 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("continue"); }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 5506 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("try"); }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 5507 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("catch"); }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 5508 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eval"); }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 5509 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("using"); }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 5510 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("set"); }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 5511 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("index"); }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 5512 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unique"); }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 5513 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("non"); }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 5514 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("on"); }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 5515 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("range"); }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 5516 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("equality"); }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 5517 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("manually"); }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 5518 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("automatically"); }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 5519 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("maintained"); }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 5520 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("decimal-format"); }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 5521 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("decimal-separator"); }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 5522 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("grouping-separator"); }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 5523 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("infinity"); }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 5524 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("minus-sign"); }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 5525 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("NaN"); }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 5526 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("percent"); }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 5527 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("per-mille"); }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 5528 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("zero-digit"); }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 5529 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("digit"); }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 5530 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("pattern-separator"); }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 5531 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("collection"); }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 5532 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("const"); }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 5533 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("append-only"); }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 5534 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("queue"); }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 5535 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("mutable"); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 5536 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("read-only"); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 5537 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("integrity"); }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 5538 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("constraint"); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 5539 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("check"); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 5540 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("key"); }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 5541 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("foreach"); }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 5542 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("foreign"); }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 5543 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("keys"); }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 5559 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(1) - (1)].node)), NULL, NULL);
		}
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 5563 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(2) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(2) - (2)].node)), NULL);
		}
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 5567 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(3) - (1)].node)), NULL, static_cast<RangeExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		}
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 5571 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(4) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(4) - (2)].node)), static_cast<RangeExpr *> ((yysemantic_stack_[(4) - (4)].expr)));
		}
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 5581 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 5584 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 5587 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 5590 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 5599 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 5602 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 5611 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 5614 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 5623 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 5626 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 5635 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 5638 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 5647 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 5650 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 5653 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 5662 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 5665 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 5674 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), static_cast<StringLiteral *> ((yysemantic_stack_[(1) - (1)].expr)), NULL);
		}
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 5678 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 5688 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 5691 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 5694 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 5697 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 5700 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 5709 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 5718 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 5722 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 5726 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 5730 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 5734 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 5738 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 5742 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 5752 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 5755 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 5758 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 5761 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 5770 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 5773 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 5776 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 5779 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 5788 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 5791 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 5800 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 5803 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 5806 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 5809 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 5812 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 5815 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 5818 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 5827 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 5830 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 5839 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 5842 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 5845 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 5848 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 5857 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 5860 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 5863 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 5866 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 5869 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 5878 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 5881 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 5890 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 5893 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 5902 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 5905 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 5914 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 5917 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 5926 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 5935 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 5938 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 5947 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 5950 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 5953 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 5962 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 5965 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 5968 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 5971 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 5974 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 5983 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 5987 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 5991 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 5995 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 6005 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 6014 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWindow (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (2)].expr)), static_cast<FTUnit *> ((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6024 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6033 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6036 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6045 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6048 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6051 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6060 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 6063 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 6072 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTIgnoreOption (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		}
    break;



/* Line 678 of lalr1.cc  */
#line 10137 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1238;
  const short int
  xquery_parser::yypact_[] =
  {
      1466, -1238, -1238, -1238, -1238,   689,    -5,   -24,    38,  8616,
      37,   442,   448, -1238, -1238, -1238, -1238, -1238, -1238,   154,
     108,  7490, -1238,   239, -1238, -1238, -1238, -1238,   268,   275,
   -1238,   299,   115,   355, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238,   339,   348, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238,  8895, -1238,  6920, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, 10569, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238,   424, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238,  1754, 10569, -1238, -1238, -1238, -1238, -1238,
   -1238,   446, -1238, -1238, -1238, -1238,  8056, -1238,  8337, -1238,
   -1238, -1238, -1238, -1238, 10569, -1238, -1238,  6633, -1238, -1238,
   -1238, -1238, -1238, -1238,   470, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238,    13,   337, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238,   399,   492,   400, -1238,   409,   193, -1238,
   -1238, -1238, -1238, -1238, -1238,   529, -1238, -1238,   501,   419,
     417, -1238,   422,   519,   524, -1238,   560, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238,  4337,   675, -1238,  4624, -1238,
   -1238,   408,  4911,   498,   502, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238,     2, -1238, -1238, -1238,
   -1238,   478, 10569, -1238, -1238, -1238, -1238, -1238,   526,   596,
   -1238,   682,   434,   321,   247,   -51,   304, -1238,   618,   499,
     600,   595,  5198, -1238, -1238, -1238,    -3, -1238, -1238,  6633,
   -1238,   143, -1238,   551,  6920, -1238,   551,  6920, -1238, -1238,
   -1238, -1238,   551, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238,   550, -1238, -1238, 10569,   662,   663,   528,   528,   662,
   10569,   189,   106,   678,   284,   305, 10569,   559,   592,    69,
    8056, -1238, -1238,   398,   212,   134, 10569, -1238, -1238, -1238,
   -1238, -1238,   425, 10569,   418,   421,   420,   610, -1238, -1238,
   -1238,  8056, 10569,  4911,   570,   575,  4911, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,  4911,  9174,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238,   576,  4911,  4911,   534,
    4911,   545,  4911,    51,    50, -1238,  4911,  7773,   579, -1238,
   10569, 10569, 10569,  4911,   454,   461, -1238,   620,   621, 10569,
      61,  4911,  9453,   590,   588,   593,   598,   601,   602, -1238,
   -1238, -1238, 10569, -1238,   565,   721,  4911,    39, -1238,   736,
     580, -1238,  4911,   552, -1238,   737,  4911,  4911,   594,  4911,
    4911,  4911,  4911,   548, 10569, -1238, -1238,  4911, -1238, -1238,
    4911,  4911, 10569, -1238, -1238, -1238, -1238,   689,   108, -1238,
   -1238,   408,   740,  4911, -1238,  4911,   613,   275,   115,   355,
     664,   614,   616,  4911,  4911, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238,   673, -1238,   -19,  5485,  5485,  5485, -1238,  5485,
    5485, -1238,  5485, -1238,  5485, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238,  5485,  5485,     8,  5485,  5485,  5485,  5485,  5485,
    5485,  5485,  5485,  5485,  5485,  5485,   556,   691,   693,   694,
   -1238, -1238, -1238,  2041, -1238, -1238,  6633,  6633,  4911,   551,
   -1238, -1238,   551, -1238,   551,  2328,   636, -1238, 10569, -1238,
   -1238, -1238, -1238,   767, -1238, -1238, -1238, -1238, -1238, -1238,
     690,   697, -1238, -1238,   837,   294, 10569,   416,   641,   648,
     837,   678,   681,   677, -1238, -1238, -1238, -1238, -1238,   361,
      27,   363,   781, -1238, -1238,   285, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238,   -21, -1238,   515, -1238, -1238, 10569,
   10569, 10569, -1238,   683,   661, -1238,   634,  4911,  4911,   633,
     637, -1238,    34,    58,  2615,   638,   644, -1238,   645, -1238,
     643,  8056,   731,   790,  8056,   678,   733,   652,   655, -1238,
     656,  2902,     9, -1238,    44,   695,   735, -1238,   -32,   665,
   -1238, -1238, 10569,   -11, -1238,   660,   588,   339, -1238,   666,
     668,   667, -1238,    94,   132,  3189,    21, -1238, 10569,   721,
   -1238,   172,   672, -1238, -1238, -1238, -1238,   679, -1238,   -31,
   -1238, -1238, -1238,   -18,    49,   750,   619,   639,    -6, -1238,
     715,  5772, -1238,   680,   684,    71, -1238, -1238,   688, -1238,
       1, -1238, -1238,    17,   698, 10569,  4911,   742, -1238, -1238,
     744, 10011,   748,  4911,   760,   -39,   724,   -22,   596, -1238,
   -1238, -1238, -1238, -1238,  5485, -1238, -1238, -1238,  4911,     8,
     377, -1238,   603,    85,   630,   631, -1238, -1238,   625,   -95,
     247,   247,     5,   -51,   -51,   -51,   -51,   304,   304, -1238,
   -1238, 10011, 10011, 10569, 10569, -1238,   699, -1238, -1238,   711,
   -1238, -1238, -1238,   165,   206,   350,   636, -1238,   237,   252,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
     837, -1238,   774, 10290,   765,  4911, -1238, -1238, -1238,   813,
     769,  4911,   678,   678,   837, -1238,   476,   678, -1238, -1238,
     632, -1238, -1238,   635,   313, -1238, -1238, -1238, -1238, -1238,
   -1238,   647, -1238, -1238,    95,   281, -1238,   704,   -20,   -12,
     617,   678,  4911, -1238,   734,   749,   830,   763, 10569, -1238,
   10569, -1238, -1238,   751, -1238, -1238, -1238,   738,   803,   678,
     777,   805,   840,   678,   789, -1238, -1238, -1238,   764,   827,
    4911,  4911,   802,  4911,   829,  4911,   808,   -74, -1238,   176,
     696, -1238, -1238,   466,   -11, -1238, -1238, -1238,   799, 10569,
   -1238, 10569, -1238, -1238,   771,  4911,   917, -1238,   201, -1238,
      36, -1238, -1238,   926, -1238,   396,  4911,  4911,  4911,   397,
    4911,  4911,  4911,  4911,  4911,  4911,   839,  4911,  4911,   592,
      22,   775,   501,   716,   810,   843,   740,   879, -1238,  4911,
   -1238,   380,   855, -1238, 10569,   856, -1238, 10569,   812,   814,
   -1238,   183, -1238, -1238, -1238, 10569, -1238, 10569,  4911,   824,
    4911,  4911,   -17,   825, -1238,   791,   787, -1238,   722, -1238,
     -70, -1238,   319,     0,   728,     8,   319,  5485,  5485,   447,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238,     8,   841,     0,
   -1238,   706,   929, -1238, -1238, -1238, -1238, -1238,   846, -1238,
   -1238, -1238,  4911, -1238, 10569,   895,   175, -1238, -1238,  4911,
   -1238,   360, -1238, -1238, -1238, -1238, -1238,   962,   451, -1238,
   -1238, -1238,  4911, -1238, -1238, -1238, -1238, -1238, -1238,   713,
      23,   963, -1238,   371, -1238, -1238,   593,   598,   601,   348,
     602,   492,   761,   770,   772,  6346,   714,   700,    95, -1238,
     776,   811,   819, -1238, -1238,  9732,   391, -1238,  3476,   820,
     821,   860,   822,   823, -1238,  4911,   678,   901, -1238, -1238,
   -1238,   678,   901,  3763, -1238, 10569, -1238, -1238,  4911, -1238,
   10569, -1238,  4911,  4911,   869,  4911,   866, -1238,   893,   894,
    4911, 10569,   567,   945, -1238, -1238, -1238,  4050,   832,   833,
   -1238, -1238, -1238,   887, -1238,   423, -1238, -1238,  1004, -1238,
   -1238,  4911, 10569, -1238, -1238,   624, -1238, -1238, -1238,   834,
     793,   794, -1238, -1238, -1238,   795,   796, -1238, -1238, -1238,
   -1238, -1238,   785, 10569,   838, -1238,   888, -1238,   592, -1238,
   -1238, -1238,  7207,   716, -1238,  4911, 10569,   855, -1238,   678,
   -1238,   509, -1238,   197,   921, -1238,  4911,   923,   742, -1238,
     847,   849, -1238, -1238, -1238, -1238, -1238, -1238, -1238,  4911,
   -1238, -1238,  4911,   889,  4911, -1238, -1238,  5485, -1238, -1238,
   -1238, -1238, -1238,   250,  5485,  5485,   273, -1238,   630, -1238,
   -1238,   147,  5485, -1238, -1238,   631,     8,   762, -1238, -1238,
   -1238, -1238,   813, 10011,   916,   942,   857, -1238, -1238, -1238,
   -1238, -1238,     3,  1010,  1011,     3,     6,   195,   204, -1238,
   -1238, -1238,   873, 10569,   784,   761,  6346, -1238, -1238, 10569,
     861,    65, -1238, -1238,   862, -1238, -1238, -1238, -1238, -1238,
     922,   952,   678,   901, -1238,   870, -1238, -1238, -1238, -1238,
   -1238,  4911, -1238,  4911, 10569, 10569, -1238,   376, -1238,  4911,
   -1238,   871, -1238, -1238,   917, 10569,   649, -1238,   872,   917,
   10569, -1238, -1238,  4911,  4911,  4911,  4911,  4911, -1238,  4911,
    4911, -1238, -1238,   300, -1238,   874, -1238, -1238, -1238, -1238,
     921, -1238, -1238, -1238,   678, -1238, -1238, -1238, -1238, -1238,
   -1238,  4911, -1238,   -51,  5485,  5485,   -51,   381, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, 10011,
   -1238,    23,    23,     3, -1238, -1238, -1238,    32,     3,  1021,
     792,   957, -1238,   957, -1238,  6346,   -77,   773, -1238,   890,
     964,  4911, 10569,  4911, -1238,  4911,   678, -1238, -1238, -1238,
   -1238,   992, -1238, -1238, -1238, -1238,    -8,   917, 10569, -1238,
     867,   917, -1238, -1238, -1238, -1238, -1238, -1238, -1238,   943,
    7207, -1238, -1238, -1238, -1238, -1238,   -51,   -51,  5485, -1238,
   -1238, -1238, -1238, -1238, -1238,     0, -1238,   219, -1238,   221,
     955, -1238,   969, 10569,   844, 10569,  6346, 10011, -1238,   883,
   -1238, -1238,   901,   949,   220,   146, -1238,   876,   917, -1238,
     877, 10569, -1238,   -51,   809,   957, -1238, -1238,  6346, 10569,
     778,   953,   851,   955,   892,  4911, 10569, -1238, -1238,   982,
     302, -1238, -1238, -1238, -1238,   897,   323, -1238, -1238, -1238,
     884, -1238,   238, -1238, -1238, -1238,   380,  6059, 10569,   961,
    4911, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,
     965,   930, -1238,   780, -1238,   782, 10569, -1238, 10569, -1238,
    6346,  4911,   783,   249, -1238, -1238,  6346,   967,   930,   891,
   10569, -1238,   807,   905, 10569,   930,   875, -1238,   973, 10569,
     788,  6346, -1238
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   397,   398,   579,   544,   684,   693,   672,   596,   588,
     604,   595,   586,   694,   733,   732,   734,   735,   731,   590,
     691,   592,   619,   654,   648,   689,   616,   692,   749,   643,
     685,   747,   633,   634,   635,   636,   637,   638,   639,   640,
     641,   686,   600,   594,   587,   688,   663,   593,   598,   759,
     760,   761,   762,   763,   764,   765,   766,   767,   768,   769,
     388,   391,   662,   658,   649,   629,   585,   378,     0,   657,
     665,   673,   376,   653,   414,   630,   631,   687,   377,   380,
     650,   667,     0,   420,   386,   416,   660,   584,   651,   652,
     680,   655,   671,   679,   382,   381,   603,   642,   682,   415,
     670,   675,   589,     0,     0,   335,   668,   678,   683,   681,
     661,   736,   647,   645,   646,   387,     0,   334,     0,   390,
     389,   676,   632,   656,     0,   379,   364,     0,   396,   677,
     659,   666,   674,   669,   737,   623,   628,   627,   626,   625,
     624,   597,   644,     0,   583,   690,   617,   723,   722,   724,
     602,   601,   620,   729,   591,   721,   726,   727,   718,   622,
     664,   720,   730,   728,   719,   621,   725,   738,   739,   740,
     743,   741,   744,   742,   745,   746,   748,   710,   709,   606,
     599,   608,   607,   703,   699,   614,   618,   615,   712,   713,
     696,   605,   708,   707,   704,   700,   717,   711,   706,   702,
     695,   716,   715,   701,   705,   697,   698,   609,   610,   612,
     714,   611,   613,   770,   771,   772,   773,   774,   775,   751,
     752,   750,   756,   757,   758,   753,   754,   755,   776,   777,
     778,   779,   780,   781,   782,     0,     0,     2,     0,     4,
       6,    12,     0,     0,     0,    18,    20,    34,    22,    23,
      24,    50,    25,    29,    30,    54,    55,    56,    51,    52,
      58,    59,    27,    26,    31,    32,    33,    53,   194,   193,
     190,   191,   192,    28,    11,   171,   172,   176,   178,   209,
     215,     0,     0,   207,   208,   179,   180,   181,   182,   291,
     293,   295,   305,   308,   310,   313,   318,   321,   324,   326,
     328,   330,     0,   332,   338,   340,     0,   356,   339,   360,
     363,   365,   368,   370,     0,   375,   372,     0,   383,   393,
     395,   369,   399,   404,   412,   405,   406,   407,   410,   411,
     408,   409,   427,   429,   430,   431,   428,   476,   477,   478,
     479,   480,   481,   392,   518,   510,   517,   516,   515,   512,
     514,   511,   513,   413,    57,   183,   184,   186,   185,   187,
     188,   394,   189,   580,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   107,   108,     0,     0,     0,     0,   103,   104,   105,
     106,   111,     0,     0,     0,     0,     0,     0,   101,   154,
     157,     0,     0,     0,     0,     0,     0,   684,   693,   672,
     596,   588,   604,   595,   586,   590,   691,   592,   654,   749,
     643,   747,   633,   634,   594,   587,   585,   655,     0,     0,
     736,   737,   583,   729,   591,   721,   727,   718,   621,   739,
     740,   743,   744,   742,   745,   748,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   577,     0,     0,     0,   578,
       0,     0,     0,     0,     0,     0,   217,     0,     0,     0,
       0,     0,     0,     0,   588,   595,   586,   592,   585,   384,
     394,   417,     0,   418,     0,   443,     0,     0,   359,     0,
       0,   362,     0,     0,   472,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   144,   141,     0,   152,   153,
       0,     0,     0,     3,     1,     5,     7,     0,     0,    13,
      10,    15,    16,     0,   174,   173,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   195,   214,   210,   216,   211,
     213,   212,   219,   220,     0,     0,     0,     0,   349,     0,
       0,   347,     0,   300,     0,   348,   341,   346,   345,   344,
     343,   342,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     337,   336,   333,     0,   357,   361,     0,     0,     0,   371,
     401,   374,   373,   385,   400,     0,     0,   159,     0,   160,
     156,   155,   158,     0,   135,   136,    67,    68,   576,    76,
       0,     0,    61,    62,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   545,   546,   547,   110,   109,     0,
       0,     0,     0,   819,   820,     0,    66,   812,   813,   814,
     815,   816,   817,   818,   115,   112,     0,   114,   113,     0,
       0,     0,   102,     0,     0,   542,     0,     0,     0,     0,
       0,   534,     0,     0,     0,     0,     0,   523,     0,   524,
       0,     0,    85,     0,     0,     0,    77,     0,     0,   525,
       0,     0,     0,   280,     0,     0,   232,   233,     0,     0,
     197,   198,     0,     0,   218,     0,     0,     0,   520,     0,
       0,     0,   528,     0,     0,     0,     0,   419,   444,   443,
     440,     0,     0,   474,   473,   358,   533,     0,   471,     0,
     558,   559,   519,     0,     0,     0,     0,     0,     0,   564,
       0,     0,   150,     0,     0,     0,   235,   252,     0,    19,
       0,    21,   177,     0,     0,     0,     0,     0,   196,   253,
       0,     0,     0,     0,     0,     0,     0,     0,   292,   294,
     298,   304,   303,   302,     0,   299,   296,   297,     0,     0,
       0,   804,   306,   783,   791,   793,   795,   797,   799,   802,
     312,   311,   309,   315,   316,   317,   314,   319,   320,   323,
     322,     0,     0,     0,     0,   354,     0,   366,   367,     0,
     402,   423,   425,     0,     0,     0,     0,    65,     0,     0,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      36,    37,     0,     0,    93,     0,    89,    91,    92,    96,
      99,     0,     0,     0,    35,    75,     0,     0,   821,   822,
       0,   823,   827,     0,     0,   856,   825,   826,   855,   824,
     828,     0,   835,   857,     0,     0,   116,     0,     0,   119,
       0,     0,     0,   350,     0,     0,     0,     0,     0,   538,
       0,   535,   483,     0,   482,   491,   492,     0,     0,     0,
       0,     0,    78,     0,     0,   527,   526,   493,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   582,     0,
       0,   199,   200,     0,   205,   541,   521,   522,     0,     0,
     531,     0,   529,   487,     0,     0,   443,   441,     0,   432,
       0,   421,   422,     0,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   684,
       0,     0,     0,     0,     0,     0,    17,     0,   175,     0,
     206,   264,   260,   262,     0,   254,   255,     0,   589,   597,
     499,   500,   506,   507,   509,     0,   222,     0,     0,     0,
       0,     0,     0,     0,   301,     0,     0,   798,     0,   307,
       0,   811,     0,     0,     0,     0,     0,     0,     0,   784,
     788,   806,   787,   810,   808,   807,   809,     0,     0,     0,
     800,   863,   861,   865,   803,   325,   327,   329,   497,   331,
     355,   403,     0,   424,     0,   137,     0,   165,   162,     0,
     161,     0,    73,    74,    71,    72,    38,     0,     0,    94,
      95,    97,     0,    98,    63,    64,    69,    70,    60,     0,
       0,     0,   830,     0,   829,   846,     0,     0,     0,     0,
       0,     0,   117,     0,     0,     0,     0,     0,     0,   120,
       0,     0,     0,   352,   351,     0,     0,   286,     0,     0,
       0,   542,     0,     0,   484,     0,     0,    87,    81,    84,
      83,     0,    79,     0,   494,     0,   278,   282,     0,   149,
       0,   237,     0,     0,     0,     0,     0,   201,     0,     0,
       0,     0,   246,     0,   243,   248,   204,     0,     0,     0,
     488,   279,   444,     0,   433,     0,   467,   464,     0,   468,
     469,     0,     0,   470,   463,     0,   438,   466,   465,     0,
       0,     0,   551,   552,   548,     0,     0,   556,   557,   553,
     562,   560,     0,     0,     0,   566,   147,   146,     0,   143,
     142,   151,     0,   567,   568,     0,     0,   261,   273,     0,
     274,     0,   265,   266,   267,   268,     0,   257,     0,   221,
       0,     0,   503,   505,   504,   501,   230,   231,   224,     0,
     226,   223,     0,     0,     0,   805,   801,     0,   858,   859,
     879,   878,   874,     0,     0,     0,     0,   860,   792,   873,
     785,     0,     0,   790,   789,   794,     0,     0,   864,   862,
     498,   426,   167,     0,     0,   138,     0,   164,   163,    39,
      90,   100,   844,     0,     0,   842,   838,     0,     0,   118,
     124,   123,     0,     0,     0,   121,     0,    14,   353,     0,
       0,     0,   287,   485,     0,   539,   540,   543,   536,   537,
       0,    86,     0,    80,   495,     0,   281,   283,   234,   239,
     238,     0,   241,     0,     0,     0,   203,   244,   247,     0,
     489,     0,   532,   530,   443,     0,     0,   475,     0,   443,
       0,   439,     9,     0,     0,     0,     0,     0,   565,     0,
       0,   145,   574,     0,   569,     0,   236,   277,   275,   276,
     269,   270,   271,   263,     0,   258,   256,   508,   502,   228,
     225,     0,   227,   880,     0,     0,   866,     0,   877,   876,
     875,   870,   871,   786,   796,   872,   168,   139,   166,     0,
     170,     0,     0,   845,   847,   849,   851,     0,   843,     0,
       0,     0,   833,     0,   831,     0,     0,     0,   122,     0,
       0,     0,     0,     0,   486,     0,     0,    82,   496,   240,
     242,   251,   250,   245,   202,   490,     0,   443,     0,   169,
       0,   443,   549,   550,   554,   555,   561,   563,   148,     0,
       0,   570,   581,   272,   259,   229,   868,   867,     0,   140,
     854,   853,   848,   852,   850,   839,   840,     0,   836,     0,
     125,   127,     0,     0,     0,     0,     0,     0,   288,     0,
     284,   290,    88,     0,   453,   447,   442,     0,   443,   434,
       0,     0,   575,   869,     0,     0,   834,   832,     0,     0,
       0,     0,     0,   126,     0,     0,     0,   461,   455,     0,
     454,   456,   462,   459,   449,     0,   448,   450,   460,   436,
       0,   435,     0,   841,   837,   128,   129,     0,     0,     0,
       0,   285,   249,   446,   457,   458,   445,   451,   452,   437,
       0,     0,   130,   751,   131,     0,     0,   289,     0,   571,
       0,     0,     0,     0,   132,   133,     0,     0,     0,     0,
       0,   572,     0,     0,     0,     0,     0,   573,     0,     0,
       0,     0,   134
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1238, -1238,   850, -1238,   848,   852, -1238,   853, -1238,   566,
     572,  -500, -1238,   468,  -290, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,  -870,
   -1238, -1238, -1238, -1238,    63,   271,   718, -1238, -1238,   701,
   -1238,  -836, -1238,  -309,  -329, -1238, -1238,   295, -1238,  -855,
   -1238, -1238,   -48, -1238, -1238, -1238, -1238, -1238,   267,  -224,
   -1238, -1238,  -112, -1238, -1237,   863,   -84, -1238,   578,  -421,
   -1238, -1238, -1238, -1238,   200, -1238, -1238,   826, -1238, -1238,
   -1238, -1238, -1238,   149,  -513,  -659, -1238, -1238, -1238,    18,
   -1238, -1238,  -158,    10,   -46, -1238, -1238, -1238,   -57, -1238,
   -1238,   166,   -52,  -340, -1238,   -45, -1079, -1238,   640,    35,
   -1238, -1238,    53, -1238, -1238,   581,   571, -1238,  -499,  -955,
     554,    90,  -565,    78,    86, -1238, -1238, -1238, -1238, -1238,
     828, -1238, -1238, -1238, -1238, -1238,   817, -1030, -1238,  -106,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238,   -27, -1128, -1238,
   -1238,   235,     7, -1238,  -557, -1238, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238, -1238,  -893, -1238,    12, -1238,   415,  -708,
   -1238, -1238, -1238, -1238, -1238,  -321,  -312, -1082,  -894, -1238,
   -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238, -1238,  -784,
    -670,  -776, -1238,   306,  -785,  -731, -1238, -1238, -1238, -1238,
   -1238, -1238, -1238,   669,   670,  -454,   261,   105, -1238, -1238,
   -1238, -1238, -1238, -1238, -1238,   -10, -1238, -1238,   -16, -1238,
    -371,   -99,    -9, -1238, -1238,   366, -1238, -1238,   151,   141,
     -65,   372, -1238, -1238,   155, -1238,  -743, -1238, -1238, -1238,
   -1238,  -198,  -833, -1238,   -79,  -663, -1238,  -752, -1238, -1238,
   -1238, -1238,  -973, -1238, -1238, -1238, -1238,   -53,   163, -1238
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   820,   821,   822,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,  1077,
     675,   261,   262,   826,   827,   828,  1146,   263,   397,   398,
     264,   856,   265,  1400,  1401,   266,   267,   805,   268,   506,
     731,   940,  1147,   269,   270,   271,   272,   273,   399,   400,
     599,  1016,  1017,  1123,  1020,   274,   275,   525,   276,   277,
     278,   535,   467,   903,   904,   279,   536,   280,   538,   281,
     282,   283,   542,   543,  1102,   756,   284,   686,   735,   687,
     693,  1103,  1104,  1105,   736,   539,   540,   955,   956,  1305,
     541,   952,   953,  1162,  1163,  1164,  1165,   285,   682,   683,
     286,  1066,  1067,   287,   288,   289,   290,   764,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   562,   563,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   589,   590,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   803,   331,   332,   333,  1125,   709,   710,   711,
    1416,  1445,  1446,  1439,  1440,  1447,  1441,  1126,  1127,   334,
     335,  1128,   336,   337,   338,   339,   340,   341,   342,  1007,
     757,   960,  1175,   961,   962,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   654,  1070,   353,   354,   355,
     356,   357,   358,   359,   728,   729,   360,  1153,  1154,  1293,
    1078,   458,   361,   362,   363,   772,   989,   773,   774,   775,
     776,   777,   778,   779,   990,   991,   636,   637,   638,   639,
     640,  1397,  1398,   641,  1333,  1225,  1337,  1334,   642,   643,
     993,  1004,  1196,   994,   995,  1000,   996,  1321,  1192,   979
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       446,   918,   609,   783,   784,   785,   786,   771,  1008,  1008,
    1009,  1044,   459,  1082,   892,  1005,  1006,   487,   897,   484,
     963,   491,   741,  1059,  1292,  1232,  1207,  1124,     4,   896,
     992,   755,  1200,  1403,   493,   364,   365,   366,   367,   368,
     369,   479,   689,  1281,  1116,  1117,   713,   370,   760,   900,
     761,   762,  1393,   763,   751,   765,  1381,   473,  1093,   480,
     963,   963,   402,   766,   767,   854,   752,   751,   925,   752,
     608,   608,   376,   481,  1058,   720,   721,  1414,   723,   724,
     725,   726,   672,   676,  1301,  1302,   732,  1151,  1193,   733,
     923,   696,   963,   936,  1193,   485,   969,   968,   973,   618,
     895,   523,   742,   619,   377,   378,   947,   459,   889,   489,
      74,  1223,   748,   749,   971,   490,   523,   753,   403,  1182,
     889,  1148,    85,  1052,   944,   696,   697,  1046,  1047,  1331,
     751,  1118,   840,   868,   453,   929,  1188,  1048,   572,   583,
     620,   597,  1001,  1002,   401,   602,    99,   573,   924,  1119,
     768,  1120,   565,   769,  1116,   673,   454,   870,   381,  1031,
     697,  1049,   118,  1415,  1003,  1443,  1218,   621,  1224,   566,
     945,   464,   465,   980,   802,  1352,  1189,   629,  1121,   447,
     891,   524,   104,   406,  1050,   890,   404,   405,   754,   926,
     927,   382,  1332,   909,  1281,   901,   948,   915,   116,   674,
     671,  1149,   714,   585,   928,   855,  1349,  1394,  1113,   869,
    1228,  1253,   771,   771,   855,   494,  1229,  1404,   937,  1122,
     384,  1383,  1124,   754,  1437,   466,   629,   622,  1116,  1096,
     754,   911,  1124,   871,  1479,   902,   698,   143,  1094,  1353,
     754,   385,   981,   754,   972,   754,  1204,  1323,  1194,  1195,
     835,  1491,  1422,  1340,  1194,  1195,   930,   931,  1497,  1119,
     770,  1120,   751,   606,  1012,   974,  1339,  1056,   841,   910,
    1444,   932,   124,   544,  1214,  1057,   386,   387,   388,   389,
     390,   623,   391,   392,   393,   394,   395,   591,  1121,  1240,
     593,   396,   919,  1314,  1341,  1159,   607,   842,   843,   452,
     844,   845,   653,  1343,   882,   480,  1437,   912,   480,  1051,
    1116,   630,  1095,  1183,  1161,  1402,  1014,  1172,  1425,   656,
    1425,  1114,   659,   586,   587,   951,   631,  1235,   982,   983,
     984,  1116,   966,  1119,   963,  1120,   572,  1470,   985,   632,
    1013,   633,  1443,  1438,   660,   573,   986,  1173,  1487,   460,
    1215,   634,   987,   988,   635,   596,   568,   920,   680,   604,
     630,   603,  1121,   665,   666,  1174,   668,   614,   670,  1315,
    1342,   459,   677,   605,  1022,   631,  1402,   644,   461,  1344,
     823,  1015,   569,  1124,   646,   462,  1115,   701,   632,  1024,
     633,  1023,   459,   655,  1426,   570,  1427,     4,  1402,  1348,
     634,  1041,   712,   635,  1030,  1318,  1025,   502,   717,   468,
    1033,  1319,   503,  1471,  1069,  1119,  1072,  1120,  1042,  1320,
     663,   824,  1424,  1201,  1488,  1464,   825,   734,   771,   571,
     574,  1116,  1117,   517,  1098,  1099,  1119,  1327,  1120,   610,
     771,   463,  1019,   575,  1121,  1379,   741,  1467,   459,   518,
    1484,   684,   685,   688,   611,  1108,  1489,  1109,  1043,  1041,
     695,  1034,  1035,   704,   752,  1121,  1038,  1158,   565,  1086,
    1087,  1502,  1089,   684,  1091,   612,  1227,  1018,  1159,    74,
     797,   798,   963,  1065,   469,   566,  1412,  1217,  1160,   613,
    1061,    85,  1019,   470,  1111,   730,  1241,  1161,  1380,   796,
     627,   628,   505,   737,   799,  1132,  1133,  1134,   567,  1137,
    1138,  1139,  1140,  1141,  1142,    99,  1144,  1145,  1118,   768,
    1442,  1448,   769,   526,  1098,  1099,   849,  1100,   951,   527,
    1026,  1318,   528,   529,   482,   980,  1119,  1319,  1120,   629,
     530,   495,  1326,   830,  1026,  1320,  1442,  1178,   831,  1180,
    1181,   592,  1448,  1389,   752,   850,   851,   594,   852,   853,
    1053,  1054,   364,   365,   366,  1121,  1366,   369,  1388,   104,
     572,  1370,   878,   864,   865,   881,  1101,  1190,   824,   573,
     873,  1392,  1191,   825,   448,   116,  1392,   449,   486,   806,
     450,  1211,  1454,   451,  1036,  1037,   800,   888,   963,   800,
     838,   800,   846,   839,   981,   847,  1275,   829,   624,   625,
     626,  1221,   492,   496,   499,   497,   500,  1130,  1135,  1131,
    1136,   914,  1313,   501,   143,  1098,  1099,  1298,  1299,  1316,
    1317,  1434,  1116,  1117,   600,   601,   531,   498,   532,   504,
     858,   859,   860,   505,  1008,  1456,   507,   941,   508,   771,
     787,   788,   533,   509,  1250,   780,   781,  1116,  1117,  1417,
     789,   790,   459,  1420,   510,   459,   511,  1257,  1390,  1391,
     512,  1259,  1260,   630,  1262,   514,   963,   521,   534,  1266,
     546,   522,   545,   899,   975,   564,   576,   577,   631,   579,
     982,   983,   984,   578,   588,   595,   364,   598,   608,   916,
     615,   632,   616,   633,   647,  1251,   645,   648,   986,   667,
    1450,   649,   657,   634,  1202,   988,   635,   658,   664,  1118,
     669,   681,   690,   364,   365,   366,   367,   368,   369,   691,
     692,   694,   705,   429,  1295,   370,   950,  1119,   449,  1120,
     707,   371,   964,   451,  1118,   951,   457,   472,   708,  1386,
    1387,   715,   372,   373,   718,   716,   374,   719,  1309,   375,
     376,  1310,  1119,  1312,  1120,   740,  1121,   381,   727,   722,
     104,   744,   750,   746,   745,   747,   791,   792,  1062,   793,
     794,   804,   964,   964,   964,   964,   116,   807,  1297,   808,
     832,  1121,   377,   378,   379,   104,   809,   833,   836,   837,
     382,   848,   857,   862,   547,   861,   863,  1280,   866,   867,
     874,   116,   548,   549,   964,   550,   875,   876,   877,   879,
     880,   883,   551,  1423,   884,   143,   552,   893,   553,   384,
     885,   886,  1368,   554,   894,   905,   933,   898,   380,   908,
    1359,   906,  1360,   907,   921,   934,   381,   938,  1364,   555,
     143,   922,   954,   935,   957,   942,   943,   949,   965,  1071,
     970,  1071,  1372,  1373,  1374,  1375,  1376,   946,  1377,  1378,
     967,  1010,   978,   556,   557,   558,   559,   560,   561,   382,
     997,  1357,   999,   998,  1011,   650,   387,   388,   389,   390,
    1385,   391,   392,   651,   394,   395,  1027,   825,   383,   751,
     655,  1032,   655,  1039,  1060,  1068,  1063,  1040,   384,   810,
     811,   812,   813,   814,   815,   816,   817,   818,   819,  1045,
    1055,  1064,  1065,  1074,  1075,  1076,  1079,  1080,  1081,   385,
    1408,  1083,  1410,  1384,  1411,  1216,  1084,  1085,  1088,  1090,
    1092,  1107,  1097,  1110,  1112,  1167,  1129,  1150,   544,  1143,
     620,  1152,  1155,  1156,  1166,  1168,  1176,  1170,  1177,  1171,
    1179,  1184,  1186,  1185,   386,   387,   388,   389,   390,  1187,
     391,   392,   393,   394,   395,  1197,  1209,  1206,  1208,   396,
    1210,  1213,     4,  1226,  1244,  1222,  1230,   855,  1231,  1233,
    1237,  1238,  1236,  1234,  1247,  1245,  1246,  1248,  1249,  1255,
    1252,  1261,  1263,  1264,  1265,  1212,  1269,  1272,  1273,  1274,
    1277,  1287,  1289,  1282,  1461,  1283,  1284,  1285,  1286,  1159,
    1290,  1304,  1307,  1271,  1308,  1311,  1014,  1325,  1329,  1330,
    1335,  1336,  1345,  1347,  1354,  1351,  1474,  1278,  1355,  1477,
    1356,  1395,  1358,  1365,  1369,  1041,  1382,  1396,  1405,  1406,
    1407,  1413,  1419,  1421,  1428,  1429,   964,  1435,  1431,  1436,
    1485,  1449,  1451,  1458,  1453,  1459,  1460,  1463,  1466,  1469,
    1457,  1476,  1019,  1480,  1481,  1478,   684,  1490,  1492,  1486,
    1495,   688,  1494,  1499,  1501,   513,   515,   738,   834,  1498,
     516,  1220,  1267,   739,   519,  1029,   617,  1433,   652,  1455,
    1291,  1021,  1328,   743,  1106,   520,  1169,   537,  1258,  1363,
    1296,  1306,  1268,  1279,  1303,  1157,  1472,   759,  1300,  1242,
    1256,   782,   706,   584,   917,  1468,   758,  1276,  1465,  1028,
     582,  1073,  1219,  1288,   730,   976,  1198,  1294,  1205,   699,
     700,  1324,   977,   480,  1203,  1399,  1338,   737,  1322,  1199,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   964,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1346,     0,     0,     0,     0,     0,
    1350,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1361,  1362,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1367,     0,     0,     0,
       0,  1371,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     964,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1409,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1418,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   480,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1430,     0,  1432,     0,   964,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1452,     0,     0,     0,     0,     0,     0,     0,
     964,     0,     0,     0,     0,     0,     0,  1462,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1475,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1482,     0,  1483,
       0,     0,     0,     0,     0,     0,     1,     0,     0,     0,
       0,  1493,     0,     2,     3,  1496,     4,     0,     0,     0,
    1500,     5,     6,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
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
     138,   139,   140,     0,     0,   141,   142,   143,     0,   144,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,     1,     0,     0,     0,     0,     0,
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
       0,     0,   119,   120,   121,     0,     0,     0,   122,   483,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   432,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,   407,   408,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,   416,    21,    22,    23,    24,    25,    26,    27,
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
     120,   121,     0,   795,     0,   122,     0,   123,   124,   125,
       0,   126,   127,   128,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   432,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,     0,   192,   193,   194,   195,   196,
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
       0,     0,   122,   801,   123,   124,   125,     0,   126,   127,
     128,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   432,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
     407,   408,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,   416,    21,    22,    23,
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
     118,     0,     0,   119,   120,   121,     0,   872,     0,   122,
       0,   123,   124,   125,     0,   126,   127,   128,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,   143,     0,   432,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,     0,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
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
     119,   120,   121,     0,   887,     0,   122,     0,   123,   124,
     125,     0,   126,   127,   128,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   432,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,   407,   408,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
     416,    21,    22,    23,    24,    25,    26,    27,     0,    28,
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
       0,   913,     0,   122,     0,   123,   124,   125,     0,   126,
     127,   128,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   432,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,     0,   192,   193,   194,   195,   196,   197,   198,
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
     117,   118,     0,     0,   119,   120,   121,     0,  1243,     0,
     122,     0,   123,   124,   125,     0,   126,   127,   128,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   432,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,   407,   408,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,   416,    21,    22,    23,    24,    25,
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
       0,   119,   120,   121,     0,  1254,     0,   122,     0,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   432,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
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
     121,     0,  1270,     0,   122,     0,   123,   124,   125,     0,
     126,   127,   128,     0,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,   143,     0,   432,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
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
     144,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,     1,     0,     0,     0,     0,     0,
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
     140,     0,     0,   141,   142,   143,     0,   432,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,   407,   408,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,   416,    21,    22,    23,    24,    25,    26,    27,
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
     120,   121,     0,     0,     0,   122,     0,   123,   124,   125,
       0,   126,   127,   128,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   432,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,   407,   408,     0,     7,   410,     9,    10,
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
       0,     0,     0,   103,   104,   580,   106,   107,     0,     0,
       0,     0,   108,   109,   110,   111,   112,   113,   114,   115,
     116,     0,   581,   118,     0,     0,   119,   120,   121,     0,
       0,     0,   122,     0,   123,   124,   125,     0,   126,   127,
     128,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   432,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   433,   154,   435,   156,   436,   437,   159,   160,   161,
     162,   163,   164,   438,   166,   167,   439,   440,   441,   171,
     442,   443,   444,   175,   445,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
     407,   408,     0,     7,   410,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,   415,   416,    21,    22,   418,
      24,    25,    26,    27,     0,   419,   420,    30,   421,   422,
     423,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,     0,    72,    73,     0,     0,     0,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,     0,    85,
       0,    86,    87,    88,    89,     0,    90,     0,     0,     0,
     427,    92,    93,    94,    95,     0,     0,     0,     0,     0,
      96,    97,    98,    99,   100,   101,   102,     0,     0,     0,
     103,   104,   105,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   111,   112,   113,   114,   115,   116,     0,   117,
     118,     0,     0,   119,   120,   121,     0,     0,     0,   122,
       0,   123,   124,   125,     0,   126,   127,   128,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,   143,     0,   432,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   433,   154,
     435,   156,   436,   437,   159,   160,   161,   162,   163,   164,
     438,   166,   167,   439,   440,   441,   171,   442,   443,   444,
     175,   445,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,     0,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,   939,   408,     0,
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
     119,   120,   121,     0,     0,     0,   122,     0,   123,   124,
     125,     0,   126,   127,   128,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   432,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,   407,   408,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
     416,    21,    22,    23,    24,    25,    26,    27,     0,    28,
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
     143,     0,   432,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,     0,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
    1473,   220,   221,   222,   223,   224,   225,   226,   227,   228,
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
     122,     0,   123,   124,   125,     0,   126,   127,   128,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   432,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   433,
     154,   435,   156,   436,   437,   159,   160,   161,   162,   163,
     164,   438,   166,   167,   439,   440,   441,   171,   442,   443,
     444,   175,   445,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,   407,   408,
       0,   409,   410,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,   415,   416,    21,    22,   418,    24,    25,
      26,    27,     0,   419,   420,    30,   421,   422,   423,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,     0,
      72,    73,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,    85,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,   427,    92,
      93,    94,    95,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,     0,     0,     0,   103,   104,
       0,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,   116,     0,     0,     0,     0,
       0,   119,   120,   121,     0,     0,     0,   122,     0,   123,
     124,   125,     0,     0,     0,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   432,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   433,   154,   435,   156,
     436,   437,   159,   160,   161,   162,   163,   164,   438,   166,
     167,   439,   440,   441,   171,   442,   443,   444,   175,   445,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       0,     0,     0,     0,     0,   407,   408,     0,   409,   410,
     474,   412,   475,   476,    13,    14,    15,    16,    17,    18,
     415,   416,   477,    22,   418,    24,    25,    26,    27,     0,
     419,   420,    30,   421,   422,   423,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    62,     0,    63,    64,    65,   478,
       0,     0,    69,    70,    71,     0,     0,     0,    73,     0,
       0,     0,     0,    75,    76,    77,     0,     0,    80,    81,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,   427,    92,    93,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,     0,   100,
     101,   102,     0,     0,     0,     0,     0,     0,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   430,   112,   113,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,     0,     0,     0,   122,     0,   123,   124,     0,     0,
       0,     0,   128,     0,   129,     0,   130,   131,   132,   133,
     431,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,     0,     0,   432,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   433,   154,   435,   156,   436,   437,   159,
     160,   161,   162,   163,   164,   438,   166,   167,   439,   440,
     441,   171,   442,   443,   444,   175,   445,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     0,     0,     0,
       0,     0,   407,   408,     0,   409,   410,   411,   412,   413,
     414,    13,    14,    15,    16,    17,    18,   415,   416,   417,
      22,   418,    24,    25,    26,    27,     0,   419,   420,    30,
     421,   422,   423,    34,    35,    36,    37,    38,    39,    40,
      41,    42,   424,   425,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,     0,
       0,    62,     0,    63,    64,    65,   426,     0,     0,    69,
      70,    71,     0,     0,     0,    73,     0,     0,     0,     0,
      75,    76,    77,     0,     0,    80,    81,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,     0,    90,     0,
       0,     0,   427,    92,    93,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,     0,   100,   101,   102,     0,
       0,     0,     0,     0,     0,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   430,   112,   113,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,     0,
       0,   122,     0,   123,     0,     0,     0,     0,     0,   128,
       0,   129,     0,   130,   131,   132,   133,   431,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,     0,     0,
     432,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     433,   434,   435,   156,   436,   437,   159,   160,   161,   162,
     163,   164,   438,   166,   167,   439,   440,   441,   171,   442,
     443,   444,   175,   445,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   455,     0,     0,     0,     3,     0,
       0,     0,     0,     0,     0,   407,   408,     0,   409,   410,
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
     101,   102,   456,     0,     0,   457,     0,     0,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   430,   112,   113,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,     0,     0,     0,   122,     0,   123,     0,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     431,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,     0,     0,   432,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   433,   434,   435,   156,   436,   437,   159,
     160,   161,   162,   163,   164,   438,   166,   167,   439,   440,
     441,   171,   442,   443,   444,   175,   445,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   455,     0,     0,
       0,     3,     0,   678,     0,     0,     0,     0,   407,   408,
       0,   409,   410,   411,   412,   413,   414,    13,    14,    15,
      16,    17,    18,   415,   416,   417,    22,   418,    24,    25,
      26,    27,     0,   419,   420,    30,   421,   422,   423,    34,
      35,    36,    37,    38,    39,    40,    41,    42,   424,   425,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,     0,     0,    62,     0,    63,
      64,    65,   426,     0,     0,    69,    70,    71,     0,     0,
       0,    73,     0,     0,     0,     0,    75,    76,    77,     0,
       0,    80,    81,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,   427,    92,
      93,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      98,     0,   100,   101,   102,     0,     0,     0,     0,     0,
       0,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     430,   112,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   121,     0,     0,     0,   122,   679,   123,
       0,     0,     0,     0,     0,     0,     0,   129,     0,   130,
     131,   132,   133,   431,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,     0,     0,   432,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   433,   434,   435,   156,
     436,   437,   159,   160,   161,   162,   163,   164,   438,   166,
     167,   439,   440,   441,   171,   442,   443,   444,   175,   445,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
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
       0,    96,    97,    98,     0,   100,   101,   102,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   430,   112,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,     0,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   431,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   432,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   433,
     434,   435,   156,   436,   437,   159,   160,   161,   162,   163,
     164,   438,   166,   167,   439,   440,   441,   171,   442,   443,
     444,   175,   445,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   488,     0,     3,     0,     0,     0,     0,
       0,     0,   407,   408,     0,   409,   410,   411,   412,   413,
     414,    13,    14,    15,    16,    17,    18,   415,   416,   417,
      22,   418,    24,    25,    26,    27,     0,   419,   420,    30,
     421,   422,   423,    34,    35,    36,    37,    38,    39,    40,
      41,    42,   424,   425,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,     0,
       0,    62,     0,    63,    64,    65,   426,     0,     0,    69,
      70,    71,     0,     0,     0,    73,     0,     0,     0,     0,
      75,    76,    77,     0,     0,    80,    81,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,     0,    90,     0,
       0,     0,   427,    92,    93,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,     0,   100,   101,   102,     0,
       0,     0,     0,     0,     0,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   430,   112,   113,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,     0,     0,
       0,   122,     0,   123,     0,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   431,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,     0,     0,
     432,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     433,   434,   435,   156,   436,   437,   159,   160,   161,   162,
     163,   164,   438,   166,   167,   439,   440,   441,   171,   442,
     443,   444,   175,   445,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
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
     108,   109,   110,   430,   112,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,     0,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   431,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   432,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   433,
     434,   435,   156,   436,   437,   159,   160,   161,   162,   163,
     164,   438,   166,   167,   439,   440,   441,   171,   442,   443,
     444,   175,   445,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,     3,     0,     0,     0,     0,     0,     0,
     407,   408,     0,   409,   410,   411,   412,   413,   414,    13,
      14,    15,    16,    17,    18,   415,   416,   417,    22,   418,
      24,    25,    26,    27,     0,   419,   420,    30,   421,   422,
     423,    34,    35,    36,    37,    38,    39,    40,    41,    42,
     424,   425,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,     0,     0,    62,
       0,    63,    64,    65,   426,     0,     0,    69,    70,    71,
       0,     0,     0,    73,     0,     0,     0,     0,    75,    76,
      77,     0,     0,    80,    81,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,     0,    90,     0,     0,     0,
     427,    92,    93,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,     0,   100,   101,   102,   471,     0,     0,
     472,     0,     0,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   430,   112,   113,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,     0,     0,     0,   122,
       0,   123,     0,     0,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   431,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,     0,     0,   432,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   433,   434,
     435,   156,   436,   437,   159,   160,   161,   162,   163,   164,
     438,   166,   167,   439,   440,   441,   171,   442,   443,   444,
     175,   445,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,     0,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,     3,     0,     0,     0,     0,     0,     0,   407,
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
     110,   430,   112,   113,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,   122,   661,
     123,     0,     0,     0,     0,     0,   662,     0,   129,     0,
     130,   131,   132,   133,   431,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,     0,     0,   432,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   433,   434,   435,
     156,   436,   437,   159,   160,   161,   162,   163,   164,   438,
     166,   167,   439,   440,   441,   171,   442,   443,   444,   175,
     445,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,     3,     0,     0,     0,     0,     0,     0,   407,   408,
       0,   409,   410,   411,   412,   413,   414,    13,    14,    15,
      16,    17,    18,   415,   416,   417,    22,   418,    24,    25,
      26,    27,     0,   419,   420,    30,   421,   422,   423,    34,
      35,    36,    37,    38,    39,    40,    41,    42,   424,   425,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,     0,     0,    62,     0,    63,
      64,    65,   426,     0,     0,    69,    70,    71,     0,     0,
       0,    73,     0,     0,     0,     0,    75,    76,    77,     0,
       0,    80,    81,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,   427,    92,
      93,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      98,     0,   100,   101,   102,     0,     0,     0,     0,     0,
       0,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     430,   112,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   121,     0,     0,     0,   122,   702,   123,
       0,     0,     0,     0,     0,   703,     0,   129,     0,   130,
     131,   132,   133,   431,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,     0,     0,   432,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   433,   434,   435,   156,
     436,   437,   159,   160,   161,   162,   163,   164,   438,   166,
     167,   439,   440,   441,   171,   442,   443,   444,   175,   445,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
       3,     0,     0,     0,     0,     0,     0,   407,   408,     0,
     409,   410,   474,   412,   475,   476,    13,    14,    15,    16,
      17,    18,   415,   416,   477,    22,   418,    24,    25,    26,
      27,     0,   419,   420,    30,   421,   422,   423,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     0,     0,    62,     0,    63,    64,
      65,   478,     0,     0,    69,    70,    71,     0,     0,     0,
      73,     0,     0,     0,     0,    75,    76,    77,     0,     0,
      80,    81,  1239,     0,     0,     0,     0,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   427,    92,    93,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
       0,   100,   101,   958,     0,     0,     0,     0,     0,     0,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   430,
     112,   113,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,     0,     0,     0,   122,     0,   123,   124,
       0,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   431,   135,   136,   137,   138,   139,   140,     0,
       0,   959,   142,     0,     0,   432,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   433,   154,   435,   156,   436,
     437,   159,   160,   161,   162,   163,   164,   438,   166,   167,
     439,   440,   441,   171,   442,   443,   444,   175,   445,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,     3,
       0,     0,     0,     0,     0,     0,   407,   408,     0,   409,
     410,   474,   412,   475,   476,    13,    14,    15,    16,    17,
      18,   415,   416,   477,    22,   418,    24,    25,    26,    27,
       0,   419,   420,    30,   421,   422,   423,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,     0,    62,     0,    63,    64,    65,
     478,     0,     0,    69,    70,    71,     0,     0,     0,    73,
       0,     0,     0,     0,    75,    76,    77,     0,     0,    80,
      81,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,     0,    90,     0,     0,     0,   427,    92,    93,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    98,     0,
     100,   101,   958,     0,     0,     0,     0,     0,     0,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   430,   112,
     113,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,     0,     0,     0,   122,     0,   123,   124,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   431,   135,   136,   137,   138,   139,   140,     0,     0,
     959,   142,     0,     0,   432,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   433,   154,   435,   156,   436,   437,
     159,   160,   161,   162,   163,   164,   438,   166,   167,   439,
     440,   441,   171,   442,   443,   444,   175,   445,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,     3,     0,
       0,     0,     0,     0,     0,   407,   408,     0,   409,   410,
     474,   412,   475,   476,    13,    14,    15,    16,    17,    18,
     415,   416,   477,    22,   418,    24,    25,    26,    27,     0,
     419,   420,    30,   421,   422,   423,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    62,     0,    63,    64,    65,   478,
       0,     0,    69,    70,    71,     0,     0,     0,    73,     0,
       0,     0,     0,    75,    76,    77,     0,     0,    80,    81,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,   427,    92,    93,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,     0,   100,
     101,   958,     0,     0,     0,     0,     0,     0,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   430,   112,   113,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,     0,     0,     0,   122,     0,   123,   124,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     431,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,     0,     0,   432,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   433,   154,   435,   156,   436,   437,   159,
     160,   161,   162,   163,   164,   438,   166,   167,   439,   440,
     441,   171,   442,   443,   444,   175,   445,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,     3,     0,     0,
       0,     0,     0,     0,   407,   408,     0,   409,   410,   411,
     412,   413,   414,    13,    14,    15,    16,    17,    18,   415,
     416,   417,    22,   418,    24,    25,    26,    27,     0,   419,
     420,    30,   421,   422,   423,    34,    35,    36,    37,    38,
      39,    40,    41,    42,   424,   425,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,     0,     0,    62,     0,    63,    64,    65,   426,     0,
       0,    69,    70,    71,     0,     0,     0,    73,     0,     0,
       0,     0,    75,    76,    77,     0,     0,    80,    81,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,     0,
      90,     0,     0,     0,   427,    92,    93,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,     0,   100,   101,
     102,     0,     0,     0,     0,     0,     0,   106,   107,     0,
       0,     0,     0,   108,   109,   110,   430,   112,   113,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
       0,     0,     0,   122,     0,   123,     0,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   431,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
       0,     0,   432,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   433,   434,   435,   156,   436,   437,   159,   160,
     161,   162,   163,   164,   438,   166,   167,   439,   440,   441,
     171,   442,   443,   444,   175,   445,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,     0,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         9,   709,   373,   568,   569,   570,   571,   564,   793,   794,
     794,   844,    21,   883,   684,   791,   792,   116,   688,   103,
     751,   127,   522,   859,  1152,  1055,   999,   920,    20,   688,
     773,   544,   987,   110,    21,    34,    35,    36,    37,    38,
      39,    68,   463,  1125,     8,     9,     7,    46,   547,    60,
     549,   550,    20,   552,    86,   554,  1293,    66,   132,    68,
     791,   792,    86,   562,   563,    86,    88,    86,    86,    88,
      20,    20,    71,    82,    86,   496,   497,    85,   499,   500,
     501,   502,   453,   454,  1163,  1164,   507,   942,    88,   510,
     121,    30,   823,    99,    88,   104,   755,   136,   757,    30,
     132,    99,   523,    34,   103,   104,   105,   116,    99,   118,
     102,    88,   533,   534,   136,   124,    99,   136,   142,   136,
      99,    99,   114,   854,    53,    30,    65,    32,    33,   126,
      86,    95,   105,    99,    26,    86,   206,    42,   189,   142,
      71,   365,   237,   238,   149,   369,   138,   198,   179,   113,
     142,   115,   147,   145,     8,   105,    48,    99,   157,   829,
      65,    66,   165,   171,   259,    19,  1021,    98,   145,   164,
      99,    56,    57,    88,   595,   110,   246,    92,   142,   142,
     136,   179,   146,   145,    89,   176,   210,   211,   262,   207,
     208,   190,   189,    99,  1276,   206,   179,   176,   162,   149,
     149,   179,   163,   309,   222,   226,  1236,   175,   916,   175,
    1043,  1081,   769,   770,   226,   202,  1052,   294,   224,   183,
     219,  1300,  1115,   262,     4,   110,    92,   158,     8,   899,
     262,    99,  1125,   175,  1471,   246,   175,   201,   897,   174,
     262,   240,   157,   262,   757,   262,   989,  1202,   248,   249,
     621,  1488,  1380,  1226,   248,   249,   207,   208,  1495,   113,
     252,   115,    86,   157,    99,   764,   260,   287,   241,   175,
     124,   222,   177,   282,    99,   295,   275,   276,   277,   278,
     279,   380,   281,   282,   283,   284,   285,   314,   142,  1065,
     317,   290,   120,    43,    99,    98,   190,   270,   271,   145,
     273,   274,   401,    99,   675,   314,     4,   175,   317,   214,
       8,   226,   136,   972,   117,  1345,   110,   134,    99,   403,
      99,   120,   406,   180,   181,   746,   241,  1058,   243,   244,
     245,     8,   753,   113,  1065,   115,   189,    99,   253,   254,
     175,   256,    19,   123,   428,   198,   261,   164,    99,   110,
     175,   266,   267,   268,   269,   364,   109,   185,   457,   170,
     226,   370,   142,   447,   448,   182,   450,   376,   452,   119,
     175,   380,   456,   184,   137,   241,  1406,   386,   110,   175,
      86,   175,   135,  1276,   393,   110,   185,   471,   254,   137,
     256,   154,   401,   402,   175,   148,   175,    20,  1428,  1235,
     266,    88,   486,   269,   825,   258,   154,   214,   492,    54,
     831,   264,   219,   175,   868,   113,   870,   115,   105,   272,
     429,   127,  1395,   988,   175,   123,   132,   511,   985,   182,
     126,     8,     9,    25,    58,    59,   113,  1213,   115,   155,
     997,   142,   142,   139,   142,   145,   946,   124,   457,    41,
    1480,   460,   461,   462,   170,   909,  1486,   911,   145,    88,
     469,   832,   833,   472,    88,   142,   837,    87,   147,   890,
     891,  1501,   893,   482,   895,   170,   105,   127,    98,   102,
     586,   587,  1213,    92,   145,   164,  1356,   127,   108,   184,
     861,   114,   142,   145,   915,   504,   105,   117,   198,   583,
     288,   289,   142,   512,   588,   926,   927,   928,   187,   930,
     931,   932,   933,   934,   935,   138,   937,   938,    95,   142,
    1414,  1415,   145,    45,    58,    59,   241,    61,   949,    51,
     820,   258,    54,    55,   110,    88,   113,   264,   115,    92,
      62,   204,  1212,   127,   834,   272,  1440,   968,   132,   970,
     971,   316,  1446,  1329,    88,   270,   271,   322,   273,   274,
     279,   280,    34,    35,    36,   142,  1274,    39,   187,   146,
     189,  1279,   671,   657,   658,   674,   110,   258,   127,   198,
     664,  1333,   263,   132,   142,   162,  1338,   145,   142,   598,
     142,  1012,  1425,   145,   118,   119,   589,   681,  1329,   592,
     239,   594,   239,   242,   157,   242,   183,   616,   210,   211,
     212,  1032,   142,   214,   214,   216,   216,   221,   221,   223,
     223,   705,  1187,   214,   201,    58,    59,   118,   119,  1194,
    1195,  1407,     8,     9,   367,   368,   158,   145,   160,   110,
     649,   650,   651,   142,  1429,  1429,   227,   731,   231,  1206,
     572,   573,   174,   231,  1075,   565,   566,     8,     9,  1367,
     574,   575,   671,  1371,   145,   674,   142,  1088,  1331,  1332,
     110,  1092,  1093,   226,  1095,     0,  1407,   179,   200,  1100,
      84,   179,   156,   692,   768,   251,    68,   188,   241,    94,
     243,   244,   245,    93,   143,   145,    34,    34,    20,   708,
     141,   254,   110,   256,   286,  1076,   281,   286,   261,   175,
    1418,   291,   142,   266,   267,   268,   269,   142,   142,    95,
     175,   142,   268,    34,    35,    36,    37,    38,    39,   268,
     110,   110,   142,   145,  1155,    46,   745,   113,   145,   115,
     175,    52,   751,   145,    95,  1166,   145,   145,    27,  1314,
    1315,    15,    63,    64,   202,   175,    67,    20,  1179,    70,
      71,  1182,   113,  1184,   115,    25,   142,   157,   220,   175,
     146,   158,    99,   159,   110,   159,   220,    86,   862,    86,
      86,   145,   791,   792,   793,   794,   162,    20,  1159,    99,
     149,   142,   103,   104,   105,   146,    99,   149,   117,   122,
     190,    20,   287,   142,   122,   122,   172,   183,   175,   172,
     172,   162,   130,   131,   823,   133,   172,   172,   175,    88,
      30,    88,   140,  1388,   172,   201,   144,   132,   146,   219,
     175,   175,   183,   151,    99,   175,    86,   172,   149,   172,
    1261,   175,  1263,   175,   172,   226,   157,   132,  1269,   167,
     201,   172,   110,   214,   110,   175,   172,   159,   110,   868,
     136,   870,  1283,  1284,  1285,  1286,  1287,   179,  1289,  1290,
     110,   172,   269,   191,   192,   193,   194,   195,   196,   190,
     250,  1252,   257,   252,   173,   275,   276,   277,   278,   279,
    1311,   281,   282,   283,   284,   285,   122,   132,   209,    86,
     909,   132,   911,   271,   287,   142,   172,   272,   219,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,   272,
     216,   172,    92,   172,   186,   122,   149,   122,    88,   240,
    1351,   142,  1353,  1304,  1355,  1019,   172,   110,   136,   110,
     132,   142,   246,   172,    27,   954,    20,   172,   957,   110,
      71,   235,   142,   110,    99,    99,   965,   145,   967,   145,
     136,   136,   175,   172,   275,   276,   277,   278,   279,   247,
     281,   282,   283,   284,   285,   247,    47,   136,   272,   290,
     134,    86,    20,    20,  1068,   272,   216,   226,   216,   275,
     179,   172,   216,   293,   134,   175,   175,   175,   175,  1083,
      99,   132,   136,   110,   110,  1014,    61,   175,   175,   122,
       6,   226,   174,   179,  1435,   222,   222,   222,   222,    98,
     132,    98,   175,  1107,   175,   136,   110,   265,    86,   172,
      20,    20,   159,   249,   172,   174,  1457,  1121,   116,  1460,
      88,    20,   172,   172,   172,    88,   172,   255,   275,   159,
      86,    59,   185,   110,    99,    86,  1065,   174,   214,   110,
    1481,   185,   185,   110,   255,   214,   174,    85,   171,   185,
     292,   110,   142,   293,   292,   110,  1085,   110,   187,   296,
     175,  1090,   275,   110,   296,   235,   238,   521,   620,   214,
     238,  1028,  1101,   521,   241,   824,   378,  1406,   397,  1428,
    1148,   806,  1214,   525,   904,   242,   957,   281,  1090,  1267,
    1156,  1168,  1102,  1122,  1166,   949,  1456,   546,  1163,  1066,
    1085,   567,   482,   306,   709,  1446,   545,  1115,  1440,   823,
     302,   870,  1027,  1143,  1143,   769,   985,  1153,   997,   470,
     470,  1206,   770,  1152,   989,  1343,  1225,  1156,  1201,   986,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1213,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1233,    -1,    -1,    -1,    -1,    -1,
    1239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1264,  1265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1275,    -1,    -1,    -1,
      -1,  1280,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1329,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1352,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1368,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1380,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1403,    -1,  1405,    -1,  1407,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1429,    -1,    -1,    -1,    -1,    -1,    -1,  1436,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1458,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1476,    -1,  1478,
      -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,
      -1,  1490,    -1,    17,    18,  1494,    20,    -1,    -1,    -1,
    1499,    25,    26,    -1,    28,    29,    30,    31,    32,    33,
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
     246,   247,   248,   249,    -1,   251,   252,    -1,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
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
     289,   290,   291,   292,   293,   294,   295,   296,    10,    -1,
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
     292,   293,   294,   295,   296,    10,    -1,    -1,    -1,    -1,
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
     295,   296,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
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
     288,   289,   290,   291,   292,   293,   294,   295,   296,    10,
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
     291,   292,   293,   294,   295,   296,    10,    -1,    -1,    -1,
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
     294,   295,   296,    10,    -1,    -1,    -1,    -1,    -1,    -1,
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
     290,   291,   292,   293,   294,   295,   296,    10,    -1,    -1,
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
     293,   294,   295,   296,    10,    -1,    -1,    -1,    -1,    -1,
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
     296,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
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
     289,   290,   291,   292,   293,   294,   295,   296,    10,    -1,
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
     292,   293,   294,   295,   296,    10,    -1,    -1,    -1,    -1,
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
     295,   296,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
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
     288,   289,   290,   291,   292,   293,   294,   295,   296,    10,
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
     291,   292,   293,   294,   295,   296,    10,    -1,    -1,    -1,
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
     294,   295,   296,    10,    -1,    -1,    -1,    -1,    -1,    -1,
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
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
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
     290,   291,   292,   293,   294,   295,   296,    10,    -1,    -1,
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
      -1,   174,    -1,   176,    -1,    -1,    -1,    -1,    -1,   182,
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
     293,   294,   295,   296,    14,    -1,    -1,    -1,    18,    -1,
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
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,    14,    -1,    -1,
      -1,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   184,    -1,   186,
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
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,    16,    -1,    18,    -1,    -1,    -1,    -1,
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
     293,   294,   295,   296,    18,    -1,    -1,    -1,    -1,    -1,
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
     294,   295,   296,    18,    -1,    -1,    -1,    -1,    -1,    -1,
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
     295,   296,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,
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
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
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
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
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
     288,   289,   290,   291,   292,   293,   294,   295,   296,    18,
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
     289,   290,   291,   292,   293,   294,   295,   296,    18,    -1,
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
     290,   291,   292,   293,   294,   295,   296,    18,    -1,    -1,
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
     291,   292,   293,   294,   295,   296
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
     292,   293,   294,   295,   296,   297,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   343,   344,   349,   352,   354,   357,   358,   360,   365,
     366,   367,   368,   369,   377,   378,   380,   381,   382,   387,
     389,   391,   392,   393,   398,   419,   422,   425,   426,   427,
     428,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   475,   476,   477,   491,   492,   494,   495,   496,   497,
     498,   499,   500,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   519,   520,   521,   522,   523,   524,   525,
     528,   534,   535,   536,    34,    35,    36,    37,    38,    39,
      46,    52,    63,    64,    67,    70,    71,   103,   104,   105,
     149,   157,   190,   209,   219,   240,   275,   276,   277,   278,
     279,   281,   282,   283,   284,   285,   290,   350,   351,   370,
     371,   149,    86,   142,   210,   211,   145,    25,    26,    28,
      29,    30,    31,    32,    33,    40,    41,    42,    44,    50,
      51,    53,    54,    55,    65,    66,    89,   125,   142,   145,
     157,   190,   203,   213,   214,   215,   217,   218,   225,   228,
     229,   230,   232,   233,   234,   236,   534,   142,   142,   145,
     142,   145,   145,    26,    48,    14,   142,   145,   533,   534,
     110,   110,   110,   142,    56,    57,   110,   384,    54,   145,
     145,   142,   145,   534,    30,    32,    33,    42,    89,   459,
     534,   534,   110,   175,   378,   534,   142,   533,    16,   534,
     534,   451,   142,    21,   202,   204,   214,   216,   145,   214,
     216,   214,   214,   219,   110,   142,   361,   227,   231,   231,
     145,   142,   110,   314,     0,   316,   317,    25,    41,   319,
     377,   179,   179,    99,   179,   379,    45,    51,    54,    55,
      62,   158,   160,   174,   200,   383,   388,   389,   390,   407,
     408,   412,   394,   395,   534,   156,    84,   122,   130,   131,
     133,   140,   144,   146,   151,   167,   191,   192,   193,   194,
     195,   196,   443,   444,   251,   147,   164,   187,   109,   135,
     148,   182,   189,   198,   126,   139,    68,   188,    93,    94,
     147,   164,   442,   142,   448,   451,   180,   181,   143,   463,
     464,   459,   463,   459,   463,   145,   534,   371,    34,   372,
     370,   370,   371,   534,   170,   184,   157,   190,    20,   532,
     155,   170,   170,   184,   534,   141,   110,   348,    30,    34,
      71,    98,   158,   533,   210,   211,   212,   288,   289,    92,
     226,   241,   254,   256,   266,   269,   548,   549,   550,   551,
     552,   555,   560,   561,   534,   281,   534,   286,   286,   291,
     275,   283,   351,   533,   517,   534,   378,   142,   142,   378,
     378,   175,   182,   534,   142,   378,   378,   175,   378,   175,
     378,   149,   532,   105,   149,   342,   532,   378,    20,   175,
     533,   142,   420,   421,   534,   534,   399,   401,   534,   381,
     268,   268,   110,   402,   110,   534,    30,    65,   175,   515,
     516,   378,   175,   182,   534,   142,   420,   175,    27,   479,
     480,   481,   378,     7,   163,    15,   175,   378,   202,    20,
     381,   381,   175,   381,   381,   381,   381,   220,   526,   527,
     534,   362,   381,   381,   378,   400,   406,   534,   321,   322,
      25,   323,   381,   380,   158,   110,   159,   159,   381,   381,
      99,    86,    88,   136,   262,   396,   397,   502,   427,   428,
     430,   430,   430,   430,   429,   430,   430,   430,   142,   145,
     252,   466,   537,   539,   540,   541,   542,   543,   544,   545,
     433,   433,   432,   434,   434,   434,   434,   435,   435,   436,
     436,   220,    86,    86,    86,   172,   378,   451,   451,   378,
     464,   175,   381,   474,   145,   359,   534,    20,    99,    99,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
     325,   326,   327,    86,   127,   132,   345,   346,   347,   534,
     127,   132,   149,   149,   325,   532,   117,   122,   239,   242,
     105,   241,   270,   271,   273,   274,   239,   242,    20,   241,
     270,   271,   273,   274,    86,   226,   353,   287,   534,   534,
     534,   122,   142,   172,   378,   378,   175,   172,    99,   175,
      99,   175,   172,   378,   172,   172,   172,   175,   533,    88,
      30,   533,   532,    88,   172,   175,   175,   172,   378,    99,
     176,   136,   502,   132,    99,   132,   397,   502,   172,   534,
      60,   206,   246,   385,   386,   175,   175,   175,   172,    99,
     175,    99,   175,   172,   378,   176,   534,   480,   481,   120,
     185,   172,   172,   121,   179,    86,   207,   208,   222,    86,
     207,   208,   222,    86,   226,   214,    99,   224,   132,    25,
     363,   378,   175,   172,    53,    99,   179,   105,   179,   159,
     534,   381,   413,   414,   110,   409,   410,   110,   141,   199,
     503,   505,   506,   507,   534,   110,   381,   110,   136,   397,
     136,   136,   396,   397,   430,   378,   537,   543,   269,   571,
      88,   157,   243,   244,   245,   253,   261,   267,   268,   538,
     546,   547,   548,   562,   565,   566,   568,   250,   252,   257,
     567,   237,   238,   259,   563,   503,   503,   501,   506,   501,
     172,   173,    99,   175,   110,   175,   373,   374,   127,   142,
     376,   359,   137,   154,   137,   154,   326,   122,   505,   347,
     381,   502,   132,   381,   532,   532,   118,   119,   532,   271,
     272,    88,   105,   145,   554,   272,    32,    33,    42,    66,
      89,   214,   507,   279,   280,   216,   287,   295,    86,   353,
     287,   532,   378,   172,   172,    92,   423,   424,   142,   517,
     518,   534,   517,   518,   172,   186,   122,   341,   532,   149,
     122,    88,   341,   142,   172,   110,   381,   381,   136,   381,
     110,   381,   132,   132,   397,   136,   502,   246,    58,    59,
      61,   110,   396,   403,   404,   405,   386,   142,   517,   517,
     172,   381,    27,   481,   120,   185,     8,     9,    95,   113,
     115,   142,   183,   375,   476,   478,   489,   490,   493,    20,
     221,   223,   381,   381,   381,   221,   223,   381,   381,   381,
     381,   381,   381,   110,   381,   381,   348,   364,    99,   179,
     172,   361,   235,   529,   530,   142,   110,   413,    87,    98,
     108,   117,   415,   416,   417,   418,    99,   534,    99,   395,
     145,   145,   134,   164,   182,   504,   534,   534,   381,   136,
     381,   381,   136,   397,   136,   172,   175,   247,   206,   246,
     258,   263,   570,    88,   248,   249,   564,   247,   540,   570,
     431,   434,   267,   546,   548,   541,   136,   564,   272,    47,
     134,   381,   534,    86,    99,   175,   378,   127,   361,   519,
     346,   381,   272,    88,   145,   557,    20,   105,   554,   353,
     216,   216,   449,   275,   293,   507,   216,   179,   172,   110,
     503,   105,   424,   172,   378,   175,   175,   134,   175,   175,
     381,   532,    99,   341,   172,   378,   421,   381,   401,   381,
     381,   132,   381,   136,   110,   110,   381,   534,   405,    61,
     172,   378,   175,   175,   122,   183,   478,     6,   378,   534,
     183,   489,   179,   222,   222,   222,   222,   226,   527,   174,
     132,   364,   460,   531,   530,   381,   406,   532,   118,   119,
     417,   418,   418,   414,    98,   411,   410,   175,   175,   381,
     381,   136,   381,   434,    43,   119,   434,   434,   258,   264,
     272,   569,   569,   431,   542,   265,   502,   503,   374,    86,
     172,   126,   189,   556,   559,    20,    20,   558,   556,   260,
     564,    99,   175,    99,   175,   159,   534,   249,   353,   449,
     534,   174,   110,   174,   172,   116,    88,   532,   172,   381,
     381,   534,   534,   404,   381,   172,   481,   534,   183,   172,
     481,   534,   381,   381,   381,   381,   381,   381,   381,   145,
     198,   376,   172,   418,   532,   381,   434,   434,   187,   503,
     557,   557,   559,    20,   175,    20,   255,   553,   554,   553,
     355,   356,   449,   110,   294,   275,   159,    86,   381,   534,
     381,   381,   341,    59,    85,   171,   482,   481,   534,   185,
     481,   110,   460,   434,   564,    99,   175,   175,    99,    86,
     534,   214,   534,   355,   503,   174,   110,     4,   123,   485,
     486,   488,   490,    19,   124,   483,   484,   487,   490,   185,
     481,   185,   534,   255,   554,   356,   501,   292,   110,   214,
     174,   381,   534,    85,   123,   488,   171,   124,   487,   185,
      99,   175,   415,   281,   381,   534,   110,   381,   110,   376,
     293,   292,   534,   534,   449,   381,   296,    99,   175,   449,
     110,   376,   187,   534,   275,   175,   534,   376,   214,   110,
     534,   296,   449
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
     565,   566
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   312,   313,   313,   314,   314,   314,   314,   315,   315,
     316,   316,   317,   317,   318,   319,   319,   319,   320,   320,
     321,   321,   322,   322,   322,   322,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   324,   324,   325,   325,   326,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     328,   328,   328,   328,   328,   328,   328,   328,   329,   329,
     330,   331,   331,   332,   332,   333,   334,   335,   335,   336,
     336,   337,   337,   337,   337,   338,   339,   340,   340,   340,
     340,   341,   341,   342,   342,   343,   343,   343,   343,   344,
     345,   345,   346,   346,   346,   347,   348,   348,   349,   349,
     349,   350,   350,   351,   351,   351,   351,   351,   351,   351,
     351,   351,   351,   351,   351,   352,   352,   352,   352,   352,
     352,   352,   352,   353,   353,   354,   354,   355,   355,   356,
     356,   357,   357,   357,   357,   358,   358,   359,   359,   359,
     359,   360,   361,   362,   362,   363,   363,   364,   364,   365,
     366,   367,   368,   368,   369,   369,   369,   370,   370,   370,
     370,   371,   371,   372,   372,   373,   373,   374,   374,   375,
     376,   377,   378,   378,   379,   379,   380,   380,   381,   381,
     381,   381,   381,   381,   381,   381,   381,   381,   381,   381,
     381,   381,   381,   381,   381,   382,   383,   384,   384,   385,
     385,   385,   386,   386,   387,   387,   388,   389,   389,   389,
     390,   390,   390,   390,   390,   391,   391,   392,   392,   393,
     394,   394,   395,   395,   395,   395,   395,   395,   395,   395,
     396,   397,   398,   399,   399,   400,   400,   401,   401,   401,
     401,   402,   402,   403,   403,   403,   404,   404,   404,   405,
     405,   405,   406,   407,   408,   409,   409,   410,   410,   411,
     412,   412,   413,   413,   414,   414,   415,   415,   415,   415,
     415,   415,   415,   416,   416,   417,   417,   418,   419,   419,
     420,   420,   421,   421,   422,   422,   423,   423,   424,   424,
     425,   426,   426,   427,   427,   428,   428,   428,   428,   428,
     429,   428,   428,   428,   428,   430,   430,   430,   431,   431,
     432,   432,   432,   433,   433,   433,   433,   433,   434,   434,
     434,   435,   435,   435,   436,   436,   437,   437,   438,   438,
     439,   439,   440,   440,   441,   441,   441,   441,   442,   442,
     442,   443,   443,   443,   443,   443,   443,   444,   444,   444,
     445,   445,   445,   445,   446,   446,   447,   447,   448,   448,
     449,   449,   449,   449,   450,   451,   451,   451,   452,   452,
     453,   453,   453,   453,   454,   454,   455,   455,   455,   455,
     455,   455,   455,   456,   456,   457,   457,   458,   458,   458,
     458,   458,   459,   459,   460,   460,   461,   461,   461,   462,
     462,   463,   463,   464,   465,   465,   465,   465,   465,   465,
     465,   465,   466,   466,   467,   467,   467,   468,   469,   469,
     470,   471,   472,   473,   473,   474,   474,   475,   475,   476,
     476,   476,   477,   477,   477,   477,   477,   477,   478,   478,
     479,   479,   480,   481,   481,   482,   482,   483,   483,   484,
     484,   484,   484,   485,   485,   486,   486,   486,   486,   487,
     487,   488,   488,   489,   489,   489,   489,   490,   490,   490,
     490,   491,   491,   492,   492,   493,   494,   494,   494,   494,
     494,   494,   495,   496,   496,   496,   496,   497,   497,   497,
     497,   498,   499,   500,   500,   500,   500,   501,   501,   502,
     503,   503,   503,   504,   504,   504,   505,   505,   505,   506,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   508,
     509,   509,   509,   510,   511,   512,   512,   512,   513,   513,
     513,   513,   513,   514,   515,   515,   515,   515,   515,   515,
     515,   516,   517,   518,   519,   520,   520,   520,   521,   521,
     521,   521,   521,   521,   521,   521,   521,   521,   522,   522,
     523,   523,   524,   525,   526,   526,   527,   528,   529,   529,
     530,   530,   530,   530,   531,   531,   532,   533,   533,   534,
     534,   535,   535,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   536,   536,   536,   536,   536,   536,   536,
     536,   536,   536,   537,   537,   537,   537,   538,   538,   538,
     538,   539,   539,   540,   540,   541,   541,   542,   542,   543,
     543,   543,   544,   544,   545,   545,   546,   546,   546,   546,
     546,   547,   548,   548,   548,   548,   548,   548,   548,   549,
     549,   549,   549,   550,   550,   550,   550,   551,   551,   552,
     552,   552,   552,   552,   552,   552,   553,   553,   554,   554,
     554,   554,   555,   555,   555,   555,   555,   556,   556,   557,
     557,   558,   558,   559,   559,   560,   561,   561,   562,   562,
     562,   563,   563,   563,   563,   563,   564,   564,   564,   564,
     565,   566,   567,   568,   568,   569,   569,   569,   570,   570,
     571
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
       5,     6,     7,     3,     3,     8,     9,     1,     3,     3,
       4,    11,    13,    13,    22,     3,     3,     2,     3,     4,
       5,     2,     4,     3,     0,     3,     2,     1,     3,     5,
       3,     5,     2,     2,     2,     3,     3,     1,     2,     2,
       2,     4,     4,     4,     4,     1,     3,     2,     3,     3,
       3,     1,     1,     2,     1,     3,     1,     3,     1,     1,
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
       3,     7,    10,    13,     1,     3,     1,     1,     1,     1,
       1,     7,     4,     1,     1,     1,     1,     1,     1,     1,
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
       1,     1,     1,     1,     2,     3,     4,     1,     1,     2,
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
  "\"'manually'\"", "\"'automatically'\"", "\"'maintained'\"", "\"'on'\"",
  "\"'range'\"", "\"'equality'\"", "\"'integrity'\"", "\"'constraint'\"",
  "\"'check'\"", "\"'key'\"", "\"'foreach'\"", "\"'foreign'\"",
  "\"'keys'\"", "\"'BOM_UTF8'\"", "FTCONTAINS_REDUCE", "RANGE_REDUCE",
  "ADDITIVE_REDUCE", "MULTIPLICATIVE_REDUCE", "UNION_REDUCE",
  "INTERSECT_EXCEPT_REDUCE", "QVARINDECLLIST_REDUCE", "COMMA_DOLLAR",
  "UNARY_PREC", "SEQUENCE_TYPE_REDUCE", "OCCURS_STAR", "OCCURS_PLUS",
  "OCCURS_HOOK", "STEP_REDUCE", "$accept", "Module", "ModuleWithoutBOM",
  "VersionDecl", "MainModule", "LibraryModule", "ModuleDecl", "Prolog",
  "SIND_DeclList", "VFO_DeclList", "SIND_Decl", "VFO_Decl",
  "DecimalFormatDecl", "DecimalFormatParamList", "DecimalFormatParam",
  "DecimalFormatParamName", "Setter", "Import", "NamespaceDecl",
  "BoundarySpaceDecl", "DefaultNamespaceDecl", "OptionDecl",
  "FTOptionDecl", "OrderingModeDecl", "EmptyOrderDecl",
  "CopyNamespacesDecl", "DefaultCollationDecl", "BaseURIDecl",
  "SchemaImport", "URILiteralList", "SchemaPrefix", "ModuleImport",
  "CtxItemDecl", "CtxItemDecl2", "CtxItemDecl3", "CtxItemDecl4",
  "VarNameAndType", "VarDecl", "DeclPropertyList", "DeclProperty",
  "CollectionDecl", "NodeModifier", "IndexDecl", "IndexKeyList",
  "IndexKeySpec", "IntegrityConstraintDecl", "ConstructionDecl",
  "FunctionSig", "BlockExpr", "Block", "BlockDecls", "BlockVarDeclList",
  "BlockVarDecl", "AssignExpr", "ExitExpr", "WhileExpr",
  "FlowCtlStatement", "FunctionDecl", "FunctionDecl2", "FunctionDecl3",
  "FunctionDecl4", "ParamList", "Param", "EnclosedExpr", "BracedExpr",
  "QueryBody", "Expr", "ApplyExpr", "ConcatExpr", "ExprSingle",
  "FLWORExpr", "ReturnExpr", "WindowType", "FLWORWinCondType",
  "FLWORWinCond", "WindowClause", "CountClause", "ForLetWinClause",
  "FLWORClause", "FLWORClauseList", "ForDollar", "ForClause",
  "VarInDeclList", "VarInDecl", "PositionalVar", "FTScoreVar", "LetClause",
  "VarGetsDeclList", "EvalVarDeclList", "VarGetsDecl", "WindowVarDecl",
  "WindowVars", "WindowVars3", "WindowVars2", "EvalVarDecl", "WhereClause",
  "GroupByClause", "GroupSpecList", "GroupSpec", "GroupCollationSpec",
  "OrderByClause", "OrderSpecList", "OrderSpec", "OrderModifier",
  "OrderDirSpec", "OrderEmptySpec", "OrderCollationSpec", "QuantifiedExpr",
  "QVarInDeclList", "QVarInDecl", "TypeswitchExpr", "CaseClauseList",
  "CaseClause", "IfExpr", "OrExpr", "AndExpr", "ComparisonExpr", "$@1",
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
       313,     0,    -1,   314,    -1,   297,   314,    -1,   316,    -1,
     315,   316,    -1,   317,    -1,   315,   317,    -1,   203,   204,
      20,   179,    -1,   203,   204,    20,   121,    20,   179,    -1,
     319,   377,    -1,   377,    -1,   318,    -1,   318,   319,    -1,
      26,   149,   533,   122,   532,   179,    -1,   320,   179,    -1,
     321,   179,    -1,   320,   179,   321,   179,    -1,   322,    -1,
     320,   179,   322,    -1,   323,    -1,   321,   179,   323,    -1,
     328,    -1,   329,    -1,   330,    -1,   332,    -1,   349,    -1,
     344,    -1,   369,    -1,   333,    -1,   334,    -1,   352,    -1,
     354,    -1,   357,    -1,   324,    -1,    25,   105,    71,   325,
      -1,    25,    71,   534,   325,    -1,   326,    -1,   325,   326,
      -1,   327,   122,   519,    -1,    72,    -1,    73,    -1,    74,
      -1,    75,    -1,    76,    -1,    77,    -1,    78,    -1,    79,
      -1,    80,    -1,    81,    -1,   331,    -1,   338,    -1,   339,
      -1,   358,    -1,   335,    -1,   336,    -1,   337,    -1,   520,
      -1,   340,    -1,   343,    -1,    25,   149,   533,   122,   532,
      -1,    25,    70,   170,    -1,    25,    70,   184,    -1,    25,
     105,    30,   149,   532,    -1,    25,   105,    34,   149,   532,
      -1,    25,    46,   534,    20,    -1,    25,   240,   548,    -1,
      25,    63,   157,    -1,    25,    63,   190,    -1,    25,   105,
     158,   117,   118,    -1,    25,   105,   158,   117,   119,    -1,
      25,    67,   170,    99,   137,    -1,    25,    67,   170,    99,
     154,    -1,    25,    67,   155,    99,   137,    -1,    25,    67,
     155,    99,   154,    -1,    25,   105,    98,   532,    -1,    25,
      64,   532,    -1,    41,    48,   532,    -1,    41,    48,   342,
     532,    -1,    41,    48,   532,    88,   341,    -1,    41,    48,
     342,   532,    88,   341,    -1,   532,    -1,   341,    99,   532,
      -1,   149,   533,   122,    -1,   105,    30,   149,    -1,    41,
      26,   532,    -1,    41,    26,   149,   533,   122,   532,    -1,
      41,    26,   532,    88,   341,    -1,    41,    26,   149,   533,
     122,   532,    88,   341,    -1,    25,   103,   141,   345,    -1,
      86,   505,   346,    -1,   346,    -1,   347,    -1,   127,    -1,
     127,   347,    -1,   132,   381,    -1,   110,   534,    -1,   110,
     534,   502,    -1,    25,   104,   348,   132,   381,    -1,    25,
     104,   348,   127,    -1,    25,   104,   348,   127,   132,   381,
      -1,   351,    -1,   350,   351,    -1,   276,    -1,   277,    -1,
     278,    -1,   279,    -1,   157,    -1,   190,    -1,   219,   289,
      -1,   219,   288,    -1,   281,    -1,   282,   281,    -1,   285,
     286,    -1,   284,   286,    -1,    25,   275,   534,    -1,    25,
     275,   534,   353,    -1,    25,   275,   534,    86,   507,    -1,
      25,   275,   534,    86,   507,   353,    -1,    25,   350,   275,
     534,    -1,    25,   350,   275,   534,   353,    -1,    25,   350,
     275,   534,    86,   507,    -1,    25,   350,   275,   534,    86,
     507,   353,    -1,   226,   280,   216,    -1,   226,   279,   216,
      -1,    25,   283,   534,   287,   216,   449,   159,   355,    -1,
      25,   350,   283,   534,   287,   216,   449,   159,   355,    -1,
     356,    -1,   355,    99,   356,    -1,   449,    86,   501,    -1,
     449,    86,   501,   415,    -1,    25,   290,   291,   534,   287,
     275,   534,   110,   534,   292,   381,    -1,    25,   290,   291,
     534,   287,   275,   534,   110,   534,   292,   281,   293,   449,
      -1,    25,   290,   291,   534,   287,   275,   534,   294,   214,
     110,   534,   292,   381,    -1,    25,   290,   291,   534,   295,
     293,   249,   275,   534,   214,   110,   534,   296,   449,   187,
     275,   534,   214,   110,   534,   296,   449,    -1,    25,    52,
     170,    -1,    25,    52,   184,    -1,   145,   175,    -1,   145,
     373,   175,    -1,   145,   175,    86,   503,    -1,   145,   373,
     175,    86,   503,    -1,   228,   361,    -1,   142,   362,   378,
     172,    -1,   362,   363,   179,    -1,    -1,   363,    99,   364,
      -1,    25,   364,    -1,   348,    -1,   348,   132,   381,    -1,
      50,   110,   534,   132,   381,    -1,   229,   227,   381,    -1,
     233,   145,   381,   175,   361,    -1,   230,   231,    -1,   232,
     231,    -1,    25,   370,    -1,    25,    38,   370,    -1,    25,
      37,   370,    -1,   371,    -1,    39,   371,    -1,    35,   371,
      -1,    36,   372,    -1,    34,   534,   359,   376,    -1,    34,
     534,   359,   127,    -1,    34,   534,   359,   361,    -1,    34,
     534,   359,   127,    -1,   374,    -1,   373,    99,   374,    -1,
     110,   534,    -1,   110,   534,   502,    -1,   142,   378,   172,
      -1,   142,   378,   172,    -1,   378,    -1,   380,    -1,   380,
     379,    -1,   179,    -1,   379,   380,   179,    -1,   381,    -1,
     380,    99,   381,    -1,   382,    -1,   419,    -1,   422,    -1,
     425,    -1,   426,    -1,   521,    -1,   522,    -1,   524,    -1,
     523,    -1,   525,    -1,   528,    -1,   535,    -1,   366,    -1,
     367,    -1,   368,    -1,   365,    -1,   360,    -1,   391,   383,
      -1,   174,   381,    -1,    56,   268,    -1,    57,   268,    -1,
     206,    -1,   246,    -1,    60,   246,    -1,   385,   403,    61,
     381,    -1,   385,    61,   381,    -1,    54,   384,   402,   386,
     386,    -1,    54,   384,   402,   386,    -1,    62,   110,   534,
      -1,   393,    -1,   398,    -1,   387,    -1,   389,    -1,   407,
      -1,   412,    -1,   408,    -1,   388,    -1,   389,    -1,   391,
     390,    -1,    54,   110,    -1,    55,    54,   110,    -1,   392,
     394,    -1,   395,    -1,   394,    99,   110,   395,    -1,   534,
     136,   381,    -1,   534,   502,   136,   381,    -1,   534,   396,
     136,   381,    -1,   534,   502,   396,   136,   381,    -1,   534,
     397,   136,   381,    -1,   534,   502,   397,   136,   381,    -1,
     534,   396,   397,   136,   381,    -1,   534,   502,   396,   397,
     136,   381,    -1,    88,   110,   534,    -1,   262,   110,   534,
      -1,    51,   110,   399,    -1,   401,    -1,   399,    99,   110,
     401,    -1,   406,    -1,   400,    99,   110,   406,    -1,   534,
     132,   381,    -1,   534,   502,   132,   381,    -1,   534,   397,
     132,   381,    -1,   534,   502,   397,   132,   381,    -1,   110,
     534,   136,   381,    -1,   110,   534,   502,   136,   381,    -1,
     404,    -1,   110,   534,    -1,   110,   534,   404,    -1,   396,
      -1,   396,   405,    -1,   405,    -1,    58,   110,   534,    59,
     110,   534,    -1,    59,   110,   534,    -1,    58,   110,   534,
      -1,   534,    -1,   200,   381,    -1,   160,   159,   409,    -1,
     410,    -1,   409,    99,   410,    -1,   110,   534,    -1,   110,
     534,   411,    -1,    98,   532,    -1,   158,   159,   413,    -1,
      45,   158,   159,   413,    -1,   414,    -1,   413,    99,   414,
      -1,   381,    -1,   381,   415,    -1,   416,    -1,   417,    -1,
     418,    -1,   416,   417,    -1,   416,   418,    -1,   417,   418,
      -1,   416,   417,   418,    -1,    87,    -1,   108,    -1,   117,
     118,    -1,   117,   119,    -1,    98,   532,    -1,    44,   110,
     420,   176,   381,    -1,   125,   110,   420,   176,   381,    -1,
     421,    -1,   420,    99,   110,   421,    -1,   534,   136,   381,
      -1,   534,   502,   136,   381,    -1,    29,   145,   378,   175,
     423,   105,   174,   381,    -1,    29,   145,   378,   175,   423,
     105,   110,   534,   174,   381,    -1,   424,    -1,   423,   424,
      -1,    92,   503,   174,   381,    -1,    92,   110,   534,    86,
     503,   174,   381,    -1,    40,   145,   378,   175,   186,   381,
     116,   381,    -1,   427,    -1,   426,   156,   427,    -1,   428,
      -1,   427,    84,   428,    -1,   430,    -1,   430,   443,   430,
      -1,   430,   444,   430,    -1,   430,   122,   430,    -1,   430,
     151,   430,    -1,    -1,   430,   146,   429,   430,    -1,   430,
     144,   430,    -1,   430,   133,   430,    -1,   430,   131,   430,
      -1,   431,    -1,   431,   251,   537,    -1,   431,   251,   537,
     571,    -1,   432,    -1,   432,   187,   432,    -1,   433,    -1,
     432,   164,   433,    -1,   432,   147,   433,    -1,   434,    -1,
     433,   182,   434,    -1,   433,   109,   434,    -1,   433,   135,
     434,    -1,   433,   148,   434,    -1,   435,    -1,   434,   189,
     435,    -1,   434,   198,   435,    -1,   436,    -1,   435,   139,
     436,    -1,   435,   126,   436,    -1,   437,    -1,   437,    68,
     220,   503,    -1,   438,    -1,   438,   188,    86,   503,    -1,
     439,    -1,   439,    93,    86,   501,    -1,   440,    -1,   440,
      94,    86,   501,    -1,   442,    -1,   441,   442,    -1,   164,
      -1,   147,    -1,   441,   164,    -1,   441,   147,    -1,   445,
      -1,   449,    -1,   446,    -1,   191,    -1,   196,    -1,   195,
      -1,   194,    -1,   193,    -1,   192,    -1,   140,    -1,   167,
      -1,   130,    -1,    28,   142,   378,   172,    -1,    28,   211,
     142,   378,   172,    -1,    28,   210,   142,   378,   172,    -1,
      28,    86,   517,   142,   378,   172,    -1,   447,   142,   172,
      -1,   447,   142,   378,   172,    -1,   448,    -1,   447,   448,
      -1,   165,   534,    15,    -1,   165,    16,    -1,   450,    -1,
     450,   451,    -1,   181,   451,    -1,   451,    -1,   180,    -1,
     452,    -1,   452,   180,   451,    -1,   452,   181,   451,    -1,
     453,    -1,   462,    -1,   454,    -1,   454,   463,    -1,   457,
      -1,   457,   463,    -1,   455,   459,    -1,   456,    -1,    97,
      -1,   106,    -1,    90,    -1,   178,    -1,   107,    -1,   129,
      -1,   128,    -1,   459,    -1,    91,   459,    -1,   458,   459,
      -1,   112,    -1,   161,    -1,    82,    -1,   169,    -1,   168,
      -1,    83,    -1,   507,    -1,   460,    -1,   534,    -1,   461,
      -1,   182,    -1,    10,    -1,    17,    -1,   465,    -1,   465,
     463,    -1,   464,    -1,   463,   464,    -1,   143,   378,   173,
      -1,   466,    -1,   468,    -1,   469,    -1,   470,    -1,   473,
      -1,   475,    -1,   471,    -1,   472,    -1,   467,    -1,   519,
      -1,   102,    -1,   138,    -1,   114,    -1,   110,   534,    -1,
     145,   175,    -1,   145,   378,   175,    -1,   111,    -1,   157,
     142,   378,   172,    -1,   190,   142,   378,   172,    -1,   534,
     145,   175,    -1,   534,   145,   474,   175,    -1,   381,    -1,
     474,    99,   381,    -1,   476,    -1,   494,    -1,   477,    -1,
     491,    -1,   492,    -1,   146,   534,   481,   120,    -1,   146,
     534,   479,   481,   120,    -1,   146,   534,   481,   185,   183,
     534,   481,   185,    -1,   146,   534,   481,   185,   478,   183,
     534,   481,   185,    -1,   146,   534,   479,   481,   185,   183,
     534,   481,   185,    -1,   146,   534,   479,   481,   185,   478,
     183,   534,   481,   185,    -1,   489,    -1,   478,   489,    -1,
     480,    -1,   479,   480,    -1,    27,   534,   481,   122,   481,
     482,    -1,    -1,    27,    -1,   171,   483,   171,    -1,    85,
     485,    85,    -1,    -1,   484,    -1,   124,    -1,   487,    -1,
     484,   124,    -1,   484,   487,    -1,    -1,   486,    -1,   123,
      -1,   488,    -1,   486,   123,    -1,   486,   488,    -1,    19,
      -1,   490,    -1,     4,    -1,   490,    -1,   476,    -1,     9,
      -1,   493,    -1,   490,    -1,     8,    -1,   113,    -1,   115,
      -1,   375,    -1,   201,    21,   202,    -1,   201,   202,    -1,
     162,   533,   163,    -1,   162,   533,     7,    -1,    95,     6,
      -1,   495,    -1,   496,    -1,   497,    -1,   498,    -1,   499,
      -1,   500,    -1,    31,   142,   378,   172,    -1,    30,   534,
     142,   172,    -1,    30,   534,   142,   378,   172,    -1,    30,
     142,   378,   172,   142,   172,    -1,    30,   142,   378,   172,
     142,   378,   172,    -1,    89,   534,   142,   172,    -1,    89,
     534,   142,   378,   172,    -1,    89,   142,   378,   172,   142,
     172,    -1,    89,   142,   378,   172,   142,   378,   172,    -1,
      32,   142,   378,   172,    -1,    33,   142,   378,   172,    -1,
      42,   533,   142,   172,    -1,    42,   533,   142,   378,   172,
      -1,    42,   142,   378,   172,   142,   172,    -1,    42,   142,
     378,   172,   142,   378,   172,    -1,   506,    -1,   506,   134,
      -1,    86,   503,    -1,   505,    -1,   505,   504,    -1,   199,
     145,   175,    -1,   134,    -1,   182,    -1,   164,    -1,   506,
      -1,   507,    -1,   141,   145,   175,    -1,   534,    -1,   509,
      -1,   515,    -1,   513,    -1,   516,    -1,   514,    -1,   512,
      -1,   511,    -1,   510,    -1,   508,    -1,   214,   145,   175,
      -1,    66,   145,   175,    -1,    66,   145,   515,   175,    -1,
      66,   145,   516,   175,    -1,    32,   145,   175,    -1,    33,
     145,   175,    -1,    42,   145,   175,    -1,    42,   145,   533,
     175,    -1,    42,   145,    20,   175,    -1,    89,   145,   175,
      -1,    89,   145,   534,   175,    -1,    89,   145,   534,    99,
     517,   175,    -1,    89,   145,   182,   175,    -1,    89,   145,
     182,    99,   517,   175,    -1,   177,   534,   175,    -1,    30,
     145,   175,    -1,    30,   145,   534,   175,    -1,    30,   145,
     534,    99,   517,   175,    -1,    30,   145,   534,    99,   518,
     175,    -1,    30,   145,   182,   175,    -1,    30,   145,   182,
      99,   517,   175,    -1,    30,   145,   182,    99,   518,   175,
      -1,    65,   145,   534,   175,    -1,   534,    -1,   534,   134,
      -1,    20,    -1,    25,   209,   210,    -1,    25,   209,   211,
      -1,    25,   209,   212,    -1,   215,   214,   381,   222,   381,
      -1,   215,   214,   381,    86,   221,   222,   381,    -1,   215,
     214,   381,    86,   223,   222,   381,    -1,   215,   214,   381,
     207,   381,    -1,   215,   214,   381,   208,   381,    -1,   215,
     216,   381,   222,   381,    -1,   215,   216,   381,    86,   221,
     222,   381,    -1,   215,   216,   381,    86,   223,   222,   381,
      -1,   215,   216,   381,   207,   381,    -1,   215,   216,   381,
     208,   381,    -1,   213,   214,   381,    -1,   213,   216,   381,
      -1,   218,   214,   381,   226,   381,    -1,   218,   219,   220,
     214,   381,   226,   381,    -1,   217,   214,   381,    86,   381,
      -1,   225,   110,   526,   224,   381,   174,   381,    -1,   527,
      -1,   526,    99,   110,   527,    -1,   534,   132,   381,    -1,
     234,   142,   378,   172,   529,    -1,   530,    -1,   529,   530,
      -1,   235,   531,   376,    -1,   235,   531,   145,   110,   534,
     175,   376,    -1,   235,   531,   145,   110,   534,    99,   110,
     534,   175,   376,    -1,   235,   531,   145,   110,   534,    99,
     110,   534,    99,   110,   534,   175,   376,    -1,   460,    -1,
     531,   198,   460,    -1,    20,    -1,    14,    -1,   534,    -1,
      18,    -1,   536,    -1,   236,   110,   400,    53,   142,   381,
     172,    -1,    53,   142,   381,   172,    -1,   203,    -1,   117,
      -1,    89,    -1,    33,    -1,    66,    -1,    30,    -1,   141,
      -1,    40,    -1,   214,    -1,    42,    -1,    69,    -1,    65,
      -1,    32,    -1,    29,    -1,   199,    -1,    70,    -1,   240,
      -1,    64,    -1,   211,    -1,   210,    -1,   135,    -1,    31,
      -1,   252,    -1,   239,    -1,   242,    -1,   241,    -1,   269,
      -1,   270,    -1,   273,    -1,   271,    -1,   274,    -1,   245,
      -1,   247,    -1,    47,    -1,   206,    -1,   246,    -1,    43,
      -1,   212,    -1,   225,    -1,   219,    -1,   191,    -1,   196,
      -1,   195,    -1,   194,    -1,   193,    -1,   192,    -1,    88,
      -1,   103,    -1,   104,    -1,   174,    -1,    54,    -1,    55,
      -1,    56,    -1,    57,    -1,    58,    -1,    59,    -1,    60,
      -1,    61,    -1,    62,    -1,   136,    -1,    51,    -1,   200,
      -1,   159,    -1,   160,    -1,   158,    -1,    45,    -1,    87,
      -1,   108,    -1,   118,    -1,   119,    -1,    98,    -1,    44,
      -1,   125,    -1,   176,    -1,    92,    -1,    86,    -1,   186,
      -1,   116,    -1,   156,    -1,    84,    -1,    68,    -1,   220,
      -1,    93,    -1,   187,    -1,   109,    -1,   148,    -1,   189,
      -1,   139,    -1,   126,    -1,    28,    -1,    94,    -1,   188,
      -1,   140,    -1,   170,    -1,   184,    -1,   149,    -1,   127,
      -1,   121,    -1,   155,    -1,   137,    -1,   154,    -1,    25,
      -1,    52,    -1,    63,    -1,   105,    -1,    67,    -1,    46,
      -1,   204,    -1,    41,    -1,    48,    -1,    26,    -1,    34,
      -1,   262,    -1,   251,    -1,   267,    -1,   268,    -1,   244,
      -1,   257,    -1,   265,    -1,   261,    -1,   243,    -1,   256,
      -1,   266,    -1,   260,    -1,   255,    -1,   254,    -1,   238,
      -1,   237,    -1,   259,    -1,   248,    -1,   249,    -1,   272,
      -1,   264,    -1,   263,    -1,   258,    -1,   218,    -1,   224,
      -1,   221,    -1,   215,    -1,   208,    -1,   207,    -1,   209,
      -1,   226,    -1,   216,    -1,   217,    -1,   223,    -1,   213,
      -1,   222,    -1,    39,    -1,    36,    -1,    35,    -1,    37,
      -1,    38,    -1,   157,    -1,   190,    -1,   227,    -1,   228,
      -1,   229,    -1,   231,    -1,   233,    -1,   230,    -1,   232,
      -1,   234,    -1,   235,    -1,    53,    -1,   236,    -1,    50,
      -1,   283,    -1,   281,    -1,   282,    -1,   287,    -1,   288,
      -1,   289,    -1,   284,    -1,   285,    -1,   286,    -1,    71,
      -1,    72,    -1,    73,    -1,    74,    -1,    75,    -1,    76,
      -1,    77,    -1,    78,    -1,    79,    -1,    80,    -1,    81,
      -1,   275,    -1,   276,    -1,   277,    -1,   278,    -1,   279,
      -1,   280,    -1,   290,    -1,   291,    -1,   292,    -1,   293,
      -1,   294,    -1,   295,    -1,   296,    -1,   539,    -1,   539,
     538,    -1,   539,   267,   431,    -1,   539,   538,   267,   431,
      -1,   548,    -1,   546,    -1,   538,   548,    -1,   538,   546,
      -1,   540,    -1,   539,   253,   540,    -1,   541,    -1,   540,
     250,   541,    -1,   542,    -1,   541,   252,   136,   542,    -1,
     543,    -1,   252,   543,    -1,   544,    -1,   544,   567,    -1,
     145,   537,   175,    -1,   545,    -1,   545,   563,    -1,   466,
      -1,   142,   378,   172,    -1,   547,    -1,   566,    -1,   565,
      -1,   568,    -1,   562,    -1,   157,    -1,   549,    -1,   550,
      -1,   551,    -1,   552,    -1,   555,    -1,   560,    -1,   561,
      -1,   256,    -1,   266,    -1,    92,   239,    -1,    92,   242,
      -1,   226,   241,    -1,   269,   241,    -1,   241,   239,    -1,
     241,   242,    -1,   226,   270,    -1,   269,   270,    -1,   226,
     273,   554,    -1,   226,   273,   105,    -1,   226,   273,   145,
     554,   175,    -1,   226,   273,   145,   554,    99,   553,   175,
      -1,   226,   273,   145,   105,   175,    -1,   226,   273,   145,
     105,    99,   553,   175,    -1,   269,   273,    -1,   554,    -1,
     553,    99,   554,    -1,    88,    20,    -1,    88,    20,   260,
      20,    -1,    88,    20,   564,   255,    -1,    88,    20,   260,
      20,   564,   255,    -1,   226,   271,   272,   557,    -1,   226,
     271,   272,   557,   556,    -1,   226,   105,   271,   272,    -1,
     226,   105,   271,   272,   556,    -1,   269,   271,   272,    -1,
     559,    -1,   556,   559,    -1,    88,    20,    -1,   145,   558,
     175,    -1,    20,    -1,   558,    20,    -1,   189,   557,    -1,
     126,   557,    -1,   254,    20,    -1,   226,   274,    -1,   269,
     274,    -1,    88,   206,    -1,    88,   246,    -1,   245,   247,
      -1,   238,    -1,   238,    47,    -1,   237,    -1,   237,   272,
      -1,   259,    -1,   248,   434,    -1,    88,   119,   434,    -1,
      88,    43,   434,    -1,   249,   434,   187,   434,    -1,   244,
     564,   569,    -1,   268,   434,   569,    -1,   257,   564,   265,
      -1,   261,   570,    -1,   243,   570,    -1,   272,    -1,   264,
      -1,   258,    -1,   263,    -1,   258,    -1,   269,   247,   434,
      -1
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
     412,   418,   425,   433,   437,   441,   450,   460,   462,   466,
     470,   475,   487,   501,   515,   538,   542,   546,   549,   553,
     558,   564,   567,   572,   576,   577,   581,   584,   586,   590,
     596,   600,   606,   609,   612,   615,   619,   623,   625,   628,
     631,   634,   639,   644,   649,   654,   656,   660,   663,   667,
     671,   675,   677,   679,   682,   684,   688,   690,   694,   696,
     698,   700,   702,   704,   706,   708,   710,   712,   714,   716,
     718,   720,   722,   724,   726,   728,   731,   734,   737,   740,
     742,   744,   747,   752,   756,   762,   767,   771,   773,   775,
     777,   779,   781,   783,   785,   787,   789,   792,   795,   799,
     802,   804,   809,   813,   818,   823,   829,   834,   840,   846,
     853,   857,   861,   865,   867,   872,   874,   879,   883,   888,
     893,   899,   904,   910,   912,   915,   919,   921,   924,   926,
     933,   937,   941,   943,   946,   950,   952,   956,   959,   963,
     966,   970,   975,   977,   981,   983,   986,   988,   990,   992,
     995,   998,  1001,  1005,  1007,  1009,  1012,  1015,  1018,  1024,
    1030,  1032,  1037,  1041,  1046,  1055,  1066,  1068,  1071,  1076,
    1084,  1093,  1095,  1099,  1101,  1105,  1107,  1111,  1115,  1119,
    1123,  1124,  1129,  1133,  1137,  1141,  1143,  1147,  1152,  1154,
    1158,  1160,  1164,  1168,  1170,  1174,  1178,  1182,  1186,  1188,
    1192,  1196,  1198,  1202,  1206,  1208,  1213,  1215,  1220,  1222,
    1227,  1229,  1234,  1236,  1239,  1241,  1243,  1246,  1249,  1251,
    1253,  1255,  1257,  1259,  1261,  1263,  1265,  1267,  1269,  1271,
    1273,  1278,  1284,  1290,  1297,  1301,  1306,  1308,  1311,  1315,
    1318,  1320,  1323,  1326,  1328,  1330,  1332,  1336,  1340,  1342,
    1344,  1346,  1349,  1351,  1354,  1357,  1359,  1361,  1363,  1365,
    1367,  1369,  1371,  1373,  1375,  1378,  1381,  1383,  1385,  1387,
    1389,  1391,  1393,  1395,  1397,  1399,  1401,  1403,  1405,  1407,
    1409,  1412,  1414,  1417,  1421,  1423,  1425,  1427,  1429,  1431,
    1433,  1435,  1437,  1439,  1441,  1443,  1445,  1447,  1450,  1453,
    1457,  1459,  1464,  1469,  1473,  1478,  1480,  1484,  1486,  1488,
    1490,  1492,  1494,  1499,  1505,  1514,  1524,  1534,  1545,  1547,
    1550,  1552,  1555,  1562,  1563,  1565,  1569,  1573,  1574,  1576,
    1578,  1580,  1583,  1586,  1587,  1589,  1591,  1593,  1596,  1599,
    1601,  1603,  1605,  1607,  1609,  1611,  1613,  1615,  1617,  1619,
    1621,  1623,  1627,  1630,  1634,  1638,  1641,  1643,  1645,  1647,
    1649,  1651,  1653,  1658,  1663,  1669,  1676,  1684,  1689,  1695,
    1702,  1710,  1715,  1720,  1725,  1731,  1738,  1746,  1748,  1751,
    1754,  1756,  1759,  1763,  1765,  1767,  1769,  1771,  1773,  1777,
    1779,  1781,  1783,  1785,  1787,  1789,  1791,  1793,  1795,  1797,
    1801,  1805,  1810,  1815,  1819,  1823,  1827,  1832,  1837,  1841,
    1846,  1853,  1858,  1865,  1869,  1873,  1878,  1885,  1892,  1897,
    1904,  1911,  1916,  1918,  1921,  1923,  1927,  1931,  1935,  1941,
    1949,  1957,  1963,  1969,  1975,  1983,  1991,  1997,  2003,  2007,
    2011,  2017,  2025,  2031,  2039,  2041,  2046,  2050,  2056,  2058,
    2061,  2065,  2073,  2084,  2098,  2100,  2104,  2106,  2108,  2110,
    2112,  2114,  2122,  2127,  2129,  2131,  2133,  2135,  2137,  2139,
    2141,  2143,  2145,  2147,  2149,  2151,  2153,  2155,  2157,  2159,
    2161,  2163,  2165,  2167,  2169,  2171,  2173,  2175,  2177,  2179,
    2181,  2183,  2185,  2187,  2189,  2191,  2193,  2195,  2197,  2199,
    2201,  2203,  2205,  2207,  2209,  2211,  2213,  2215,  2217,  2219,
    2221,  2223,  2225,  2227,  2229,  2231,  2233,  2235,  2237,  2239,
    2241,  2243,  2245,  2247,  2249,  2251,  2253,  2255,  2257,  2259,
    2261,  2263,  2265,  2267,  2269,  2271,  2273,  2275,  2277,  2279,
    2281,  2283,  2285,  2287,  2289,  2291,  2293,  2295,  2297,  2299,
    2301,  2303,  2305,  2307,  2309,  2311,  2313,  2315,  2317,  2319,
    2321,  2323,  2325,  2327,  2329,  2331,  2333,  2335,  2337,  2339,
    2341,  2343,  2345,  2347,  2349,  2351,  2353,  2355,  2357,  2359,
    2361,  2363,  2365,  2367,  2369,  2371,  2373,  2375,  2377,  2379,
    2381,  2383,  2385,  2387,  2389,  2391,  2393,  2395,  2397,  2399,
    2401,  2403,  2405,  2407,  2409,  2411,  2413,  2415,  2417,  2419,
    2421,  2423,  2425,  2427,  2429,  2431,  2433,  2435,  2437,  2439,
    2441,  2443,  2445,  2447,  2449,  2451,  2453,  2455,  2457,  2459,
    2461,  2463,  2465,  2467,  2469,  2471,  2473,  2475,  2477,  2479,
    2481,  2483,  2485,  2487,  2489,  2491,  2493,  2495,  2497,  2499,
    2501,  2503,  2505,  2507,  2509,  2511,  2513,  2515,  2517,  2519,
    2521,  2523,  2525,  2527,  2529,  2532,  2536,  2541,  2543,  2545,
    2548,  2551,  2553,  2557,  2559,  2563,  2565,  2570,  2572,  2575,
    2577,  2580,  2584,  2586,  2589,  2591,  2595,  2597,  2599,  2601,
    2603,  2605,  2607,  2609,  2611,  2613,  2615,  2617,  2619,  2621,
    2623,  2625,  2628,  2631,  2634,  2637,  2640,  2643,  2646,  2649,
    2653,  2657,  2663,  2671,  2677,  2685,  2688,  2690,  2694,  2697,
    2702,  2707,  2714,  2719,  2725,  2730,  2736,  2740,  2742,  2745,
    2748,  2752,  2754,  2757,  2760,  2763,  2766,  2769,  2772,  2775,
    2778,  2781,  2783,  2786,  2788,  2791,  2793,  2796,  2800,  2804,
    2809,  2813,  2817,  2821,  2824,  2827,  2829,  2831,  2833,  2835,
    2837
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   933,   933,   934,   944,   949,   955,   960,   972,   977,
     987,   994,  1006,  1012,  1024,  1037,  1041,  1045,  1057,  1063,
    1077,  1083,  1097,  1098,  1099,  1100,  1106,  1107,  1108,  1109,
    1112,  1115,  1118,  1121,  1123,  1129,  1134,  1143,  1149,  1158,
    1167,  1168,  1169,  1170,  1171,  1172,  1173,  1174,  1175,  1176,
    1183,  1184,  1185,  1186,  1187,  1188,  1189,  1192,  1199,  1200,
    1212,  1224,  1229,  1240,  1246,  1258,  1271,  1282,  1287,  1299,
    1304,  1315,  1321,  1327,  1333,  1352,  1363,  1374,  1381,  1388,
    1395,  1408,  1414,  1429,  1433,  1443,  1450,  1458,  1465,  1478,
    1485,  1491,  1498,  1504,  1508,  1515,  1526,  1531,  1540,  1549,
    1556,  1566,  1572,  1581,  1585,  1589,  1593,  1597,  1601,  1605,
    1609,  1613,  1617,  1621,  1625,  1633,  1641,  1649,  1657,  1665,
    1671,  1679,  1687,  1699,  1703,  1711,  1719,  1731,  1737,  1746,
    1753,  1764,  1774,  1784,  1794,  1813,  1818,  1830,  1834,  1838,
    1842,  1849,  1856,  1882,  1892,  1898,  1904,  1913,  1923,  1936,
    1944,  1951,  1965,  1969,  1976,  1981,  1988,  1996,  2000,  2004,
    2012,  2019,  2028,  2040,  2049,  2062,  2070,  2084,  2091,  2104,
    2112,  2123,  2138,  2142,  2158,  2162,  2171,  2175,  2192,  2193,
    2194,  2195,  2196,  2199,  2200,  2201,  2202,  2203,  2205,  2206,
    2209,  2210,  2211,  2212,  2213,  2220,  2233,  2240,  2244,  2252,
    2256,  2260,  2267,  2271,  2278,  2286,  2297,  2307,  2308,  2309,
    2313,  2313,  2313,  2313,  2313,  2316,  2322,  2331,  2335,  2345,
    2356,  2362,  2376,  2384,  2393,  2403,  2414,  2423,  2433,  2443,
    2459,  2472,  2484,  2496,  2502,  2514,  2520,  2534,  2543,  2553,
    2562,  2575,  2582,  2593,  2594,  2599,  2608,  2612,  2617,  2621,
    2627,  2632,  2640,  2656,  2664,  2671,  2677,  2688,  2695,  2705,
    2715,  2720,  2732,  2738,  2752,  2758,  2770,  2777,  2784,  2791,
    2798,  2805,  2812,  2825,  2829,  2839,  2843,  2853,  2864,  2871,
    2884,  2891,  2903,  2910,  2924,  2931,  2946,  2952,  2964,  2970,
    2984,  2995,  2999,  3010,  3014,  3033,  3037,  3045,  3053,  3061,
    3069,  3069,  3077,  3085,  3093,  3107,  3111,  3118,  3131,  3135,
    3146,  3150,  3154,  3164,  3168,  3172,  3176,  3180,  3190,  3194,
    3199,  3210,  3214,  3218,  3228,  3232,  3244,  3248,  3260,  3264,
    3276,  3280,  3292,  3296,  3308,  3312,  3316,  3320,  3332,  3336,
    3340,  3350,  3354,  3358,  3362,  3366,  3370,  3380,  3384,  3388,
    3398,  3402,  3406,  3410,  3422,  3428,  3440,  3446,  3460,  3467,
    3508,  3512,  3516,  3520,  3532,  3542,  3553,  3558,  3568,  3572,
    3582,  3588,  3594,  3600,  3612,  3618,  3629,  3633,  3637,  3641,
    3645,  3649,  3653,  3663,  3667,  3677,  3681,  3692,  3696,  3700,
    3704,  3708,  3723,  3727,  3737,  3741,  3751,  3758,  3765,  3778,
    3782,  3794,  3800,  3814,  3825,  3829,  3833,  3837,  3841,  3845,
    3849,  3853,  3863,  3867,  3877,  3882,  3887,  3898,  3909,  3913,
    3924,  3934,  3945,  4001,  4007,  4019,  4025,  4037,  4041,  4051,
    4055,  4059,  4069,  4077,  4085,  4093,  4101,  4109,  4124,  4130,
    4142,  4148,  4161,  4170,  4172,  4178,  4183,  4195,  4198,  4205,
    4211,  4217,  4225,  4240,  4243,  4250,  4256,  4262,  4270,  4284,
    4289,  4300,  4305,  4316,  4321,  4326,  4332,  4344,  4350,  4355,
    4360,  4371,  4376,  4391,  4396,  4413,  4428,  4432,  4436,  4440,
    4444,  4448,  4458,  4469,  4475,  4481,  4486,  4508,  4514,  4520,
    4525,  4536,  4546,  4556,  4562,  4568,  4573,  4584,  4590,  4602,
    4613,  4619,  4625,  4662,  4667,  4672,  4683,  4687,  4691,  4701,
    4712,  4716,  4720,  4724,  4728,  4732,  4736,  4740,  4744,  4754,
    4764,  4768,  4773,  4784,  4794,  4804,  4808,  4812,  4822,  4828,
    4834,  4840,  4846,  4858,  4869,  4876,  4883,  4890,  4897,  4904,
    4911,  4924,  4945,  4952,  4972,  5012,  5016,  5020,  5029,  5035,
    5041,  5047,  5053,  5060,  5066,  5072,  5078,  5084,  5096,  5101,
    5111,  5117,  5129,  5155,  5166,  5172,  5185,  5201,  5208,  5214,
    5225,  5232,  5242,  5253,  5269,  5275,  5285,  5294,  5295,  5313,
    5317,  5330,  5336,  5344,  5345,  5346,  5347,  5348,  5349,  5350,
    5351,  5352,  5353,  5354,  5355,  5356,  5357,  5358,  5359,  5360,
    5361,  5362,  5363,  5364,  5365,  5366,  5367,  5368,  5369,  5370,
    5371,  5372,  5373,  5374,  5375,  5376,  5377,  5378,  5379,  5380,
    5381,  5382,  5383,  5384,  5385,  5386,  5387,  5388,  5389,  5390,
    5391,  5392,  5393,  5394,  5395,  5396,  5397,  5398,  5399,  5400,
    5401,  5402,  5403,  5404,  5405,  5406,  5407,  5408,  5409,  5410,
    5411,  5412,  5413,  5414,  5415,  5416,  5417,  5418,  5419,  5420,
    5421,  5422,  5423,  5424,  5425,  5426,  5427,  5428,  5429,  5430,
    5431,  5432,  5433,  5434,  5435,  5436,  5437,  5438,  5439,  5440,
    5441,  5442,  5443,  5444,  5445,  5446,  5447,  5448,  5449,  5450,
    5451,  5452,  5453,  5454,  5455,  5456,  5457,  5458,  5459,  5460,
    5461,  5462,  5463,  5464,  5465,  5466,  5467,  5468,  5469,  5470,
    5471,  5472,  5473,  5474,  5475,  5476,  5477,  5478,  5479,  5480,
    5481,  5482,  5483,  5484,  5485,  5486,  5487,  5488,  5489,  5490,
    5491,  5492,  5493,  5494,  5495,  5496,  5497,  5498,  5499,  5500,
    5501,  5502,  5503,  5504,  5505,  5506,  5507,  5508,  5509,  5510,
    5511,  5512,  5513,  5514,  5515,  5516,  5517,  5518,  5519,  5520,
    5521,  5522,  5523,  5524,  5525,  5526,  5527,  5528,  5529,  5530,
    5531,  5532,  5533,  5534,  5535,  5536,  5537,  5538,  5539,  5540,
    5541,  5542,  5543,  5558,  5562,  5566,  5570,  5580,  5583,  5586,
    5589,  5598,  5601,  5610,  5613,  5622,  5625,  5634,  5637,  5646,
    5649,  5652,  5661,  5664,  5673,  5677,  5687,  5690,  5693,  5696,
    5699,  5708,  5717,  5721,  5725,  5729,  5733,  5737,  5741,  5751,
    5754,  5757,  5760,  5769,  5772,  5775,  5778,  5787,  5790,  5799,
    5802,  5805,  5808,  5811,  5814,  5817,  5826,  5829,  5838,  5841,
    5844,  5847,  5856,  5859,  5862,  5865,  5868,  5877,  5880,  5889,
    5892,  5901,  5904,  5913,  5916,  5925,  5934,  5937,  5946,  5949,
    5952,  5961,  5964,  5967,  5970,  5973,  5982,  5986,  5990,  5994,
    6004,  6013,  6023,  6032,  6035,  6044,  6047,  6050,  6059,  6062,
    6071
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
     305,   306,   307,   308,   309,   310,   311
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 10865;
  const int xquery_parser::yynnts_ = 260;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 514;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 312;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 566;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 14057 "/home/fx/dev/zorba2/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6079 "/home/fx/dev/zorba2/src/compiler/parser/xquery_parser.y"


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

