
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
#line 59 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"


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
#line 75 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 924 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_driver.h"
#include "compiler/parser/xquery_scanner.h"
#undef yylex
#define yylex driver.lexer->lex


/* Line 317 of lalr1.cc  */
#line 92 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"

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
#line 161 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
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
#line 808 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 268 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 114: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 277 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 138: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 806 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 286 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 312: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 295 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 313: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 304 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 314: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 313 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 315: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 322 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 316: /* "Prolog" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 331 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 317: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 340 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 349 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 358 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 367 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 376 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 820 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->pair_vector); };

/* Line 480 of lalr1.cc  */
#line 385 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 820 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->pair); };

/* Line 480 of lalr1.cc  */
#line 394 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 403 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 412 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 421 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 430 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 439 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 448 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 457 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 466 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 475 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 484 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 493 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 502 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 511 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 520 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 529 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 538 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 547 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 556 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 565 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 820 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 574 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 583 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 592 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "CollPropertyList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 601 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "CollProperty" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 610 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "NodeModifier" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 619 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 628 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "IndexPropertyList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 637 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "IndexProperty" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 646 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 655 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 664 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 673 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 682 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 820 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 691 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 700 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "Block" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 709 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "BlockDecls" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 718 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "BlockVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 727 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "BlockVarDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 736 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "AssignExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 745 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "ExitExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 754 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "WhileExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 763 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 772 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 781 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 790 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "FunctionDecl3" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 799 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "FunctionDecl4" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 808 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 826 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "EnclosedExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 835 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 844 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 853 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 862 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "ApplyExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 871 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "ConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 880 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 889 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 898 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 907 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 916 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 925 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 934 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 943 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 952 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 961 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 970 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 979 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 988 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 997 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1006 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "EvalVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1015 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1024 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1033 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1042 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1051 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1060 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "EvalVarDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1069 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1078 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1087 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1096 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1105 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1114 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1123 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1132 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1141 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1150 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1159 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1168 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1177 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1186 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1195 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1204 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1213 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1222 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1231 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1240 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1249 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1258 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1267 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1276 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1285 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1294 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1303 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1312 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1321 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1330 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1339 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1348 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1357 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1366 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1375 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1384 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1393 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1402 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1411 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1420 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "PragmaList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1429 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1438 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1447 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1456 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1465 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1474 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1483 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1492 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1501 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1510 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1519 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1528 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1537 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1546 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1555 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1564 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1573 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1582 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1591 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1600 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1609 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1618 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1627 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1636 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1645 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1654 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1663 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1672 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1681 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1690 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1699 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1708 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1717 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1726 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "Opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1735 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1744 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "Opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1753 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1762 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1771 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1780 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1789 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1798 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1807 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1816 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1825 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1834 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1843 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1852 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1861 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1870 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1879 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1888 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1897 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1906 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1915 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1924 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1933 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1942 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1951 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1960 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1969 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1978 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1987 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1996 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2005 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2014 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2023 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2032 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2041 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2050 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2059 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2068 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2077 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2086 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2095 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2104 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2113 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2122 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2131 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2140 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2149 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 820 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2158 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2167 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "EvalExpr" */

/* Line 480 of lalr1.cc  */
#line 818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2176 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
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
#line 108 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename);
}

/* Line 553 of lalr1.cc  */
#line 2261 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"

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
#line 942 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 952 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		}
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 957 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<MainModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr ((yyval.node));
		}
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 963 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
       driver.set_expr ((yyval.node));
		}
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 968 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
       driver.set_expr ((yyval.node));
		}
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 980 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)), encoding);
		}
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 985 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 995 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)));
		}
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 1002 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)),
                NULL);
		}
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1014 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC ((yyloc)),
                             static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)),
                             NULL);
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1020 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LibraryModule(LOC ((yyloc)),
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1032 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(6) - (3)].sval)),
								SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
      dynamic_cast<ModuleDecl *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
		}
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1045 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)), NULL);
		}
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1049 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		}
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1053 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC((yyloc)),
                      static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
                      static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1065 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = new SIND_DeclList(LOC ((yyloc)));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		}
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1071 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1085 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = new VFO_DeclList(LOC ((yyloc)));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		}
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1091 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1137 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].pair_vector));
      delete (yysemantic_stack_[(4) - (4)].pair_vector);
    }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 1142 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr))->get_qname(), (yysemantic_stack_[(4) - (4)].pair_vector));
      delete (yysemantic_stack_[(4) - (3)].expr);
      delete (yysemantic_stack_[(4) - (4)].pair_vector);
    }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 1151 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.pair_vector) = new std::vector<std::pair<std::string, std::string> > ();
      (yyval.pair_vector)->push_back(*(yysemantic_stack_[(1) - (1)].pair));
      delete (yysemantic_stack_[(1) - (1)].pair);
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 1157 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].pair_vector)->push_back(*(yysemantic_stack_[(2) - (2)].pair));
      delete (yysemantic_stack_[(2) - (2)].pair);
      (yyval.pair_vector) = (yysemantic_stack_[(2) - (1)].pair_vector);
    }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1166 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *s = static_cast<StringLiteral *>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.pair) = new std::pair<std::string, std::string>((yysemantic_stack_[(3) - (1)].strval), s->get_strval());
      delete s;
    }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1174 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1175 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1176 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1177 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1178 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1179 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1180 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1181 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1182 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1183 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1220 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1232 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		}
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1237 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		}
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1248 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_element_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1254 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_function_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1266 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OptionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
								SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
		}
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1279 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (3)].node));
		}
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1290 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		}
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1295 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		}
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1307 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		}
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1312 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		}
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1323 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::inherit_ns);
		}
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1329 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::no_inherit_ns);
		}
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1335 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::inherit_ns);
		}
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1341 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::no_inherit_ns);
		}
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1360 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)));
		}
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1371 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		}
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1382 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		}
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1389 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)),
								NULL);
		}
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 1396 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		}
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 1403 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
		}
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 1416 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = new URILiteralList(LOC ((yyloc)));
			uri_list_p->push_back(SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		}
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1422 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1437 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1441 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		}
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1451 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)), false,
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1458 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1466 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)), false,
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
		}
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1473 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1486 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1493 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->type = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1499 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1506 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(1) - (1)].node));
      d->ext = false;
      (yyval.node) = d;
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1512 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), NULL);
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1516 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1523 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1534 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(), NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1539 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
                               dynamic_cast<SequenceType *> ((yysemantic_stack_[(3) - (3)].node)));
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1548 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1557 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (3)].varnametype)));
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       NULL, true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
		}
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1564 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(6) - (3)].varnametype)));
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       (yysemantic_stack_[(6) - (6)].expr), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
		}
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1574 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1582 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1590 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1598 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1606 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<CollPropertyList*>((yysemantic_stack_[(4) - (2)].node)), 0, 0);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1612 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1620 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1628 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1639 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      CollPropertyList* l = new CollPropertyList(LOC((yyloc)));
      l->addProperty(dynamic_cast<CollProperty*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1645 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<CollPropertyList*>((yysemantic_stack_[(2) - (1)].node))->addProperty(static_cast<CollProperty*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1653 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollProperty(LOC((yyloc)), StaticContextConsts::const_);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1657 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollProperty(LOC((yyloc)), StaticContextConsts::append_only);
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1661 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollProperty(LOC((yyloc)), StaticContextConsts::queue);
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1665 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollProperty(LOC((yyloc)), StaticContextConsts::mutable_coll);
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1669 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollProperty(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1673 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollProperty(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1682 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1686 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1694 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1702 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1714 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      IndexPropertyList* l = new IndexPropertyList(LOC((yyloc)));
      l->addProperty(dynamic_cast<IndexProperty*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1720 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexPropertyList*>((yysemantic_stack_[(2) - (1)].node))->addProperty(static_cast<IndexProperty*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1729 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexProperty(LOC((yyloc)), StaticContextConsts::idx_ordered);
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1733 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexProperty(LOC((yyloc)), StaticContextConsts::idx_unordered);
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1737 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexProperty(LOC((yyloc)), StaticContextConsts::idx_unique);
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1741 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexProperty(LOC((yyloc)), StaticContextConsts::idx_non_unique);
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1745 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexProperty(LOC((yyloc)), StaticContextConsts::idx_automatic);
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1749 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexProperty(LOC((yyloc)), StaticContextConsts::idx_manual);
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1757 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1763 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1772 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)),
                            NULL);
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1779 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(4) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (3)].node)),
                            dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1791 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1801 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(13) - (9)].expr)),
                                    (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1811 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                    (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1832 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1850 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		}
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1855 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		}
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1867 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL);
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1871 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1875 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL, dynamic_cast<SequenceType *> ((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1879 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType *> ((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1886 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1893 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1919 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1928 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL;
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1935 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (1)].node));
      vfo->push_back ((yysemantic_stack_[(3) - (3)].node));
      (yyval.node) = vfo;
    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1941 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = new VFO_DeclList (LOC ((yyloc)));
      vfo->push_back ((yysemantic_stack_[(2) - (2)].node));
      (yyval.node) = vfo;
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1950 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1960 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1973 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr (LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr))->get_qname(), (yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (3)].expr);
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1981 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr (LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1988 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2002 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 2006 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::CONTINUE);
    }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 2013 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<FunctionDecl *>((yysemantic_stack_[(2) - (2)].node))->setComment(SYMTAB((yysemantic_stack_[(2) - (1)].sval)));
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 2018 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
      d->deterministic = false;
      (yyval.node) = d;
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 2025 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<FunctionDecl *>((yysemantic_stack_[(3) - (3)].node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 2033 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 2037 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 2041 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2049 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 2056 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2065 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2077 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								(yysemantic_stack_[(4) - (4)].expr),
								ParseConstants::fn_sequential);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 2086 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								NULL,
								ParseConstants::fn_extern_sequential);
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 2099 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = new ParamList(LOC ((yyloc)));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)));
			}
			(yyval.node) = plist_p;
		}
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 2107 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 2121 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(),
								NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
		}
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 2128 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
      delete (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 2141 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 2149 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 173:

/* Line 678 of lalr1.cc  */
#line 2160 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QueryBody(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
		}
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 2175 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 175:

/* Line 678 of lalr1.cc  */
#line 2179 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<BlockBody> blk(dynamic_cast<BlockBody *>((yysemantic_stack_[(2) - (2)].expr)));

      BlockBody* blk2 = new BlockBody(LOC((yyloc)));

      blk2->add((yysemantic_stack_[(2) - (1)].expr));

      for (int i = 0; i < blk->size(); ++i)
        blk2->add((*blk)[i]);

      (yyval.expr) = blk2;
    }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 2195 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody (LOC ((yyloc)));
    }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 2199 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = dynamic_cast<BlockBody *>((yysemantic_stack_[(3) - (1)].expr));
      blk->add((yysemantic_stack_[(3) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 2208 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2212 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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

  case 197:

/* Line 678 of lalr1.cc  */
#line 2257 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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

  case 198:

/* Line 678 of lalr1.cc  */
#line 2270 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 2277 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 2281 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2289 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 2293 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 2297 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_only_end;
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 2304 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), dynamic_cast<WindowVars *> ((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr), (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 2308 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr), (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 2315 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(5) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window,
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(5) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (4)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 2323 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window,
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 2334 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause (LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 2353 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = new FLWORClauseList (LOC ((yyloc)));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    }
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 2359 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = dynamic_cast<FLWORClauseList *> ((yysemantic_stack_[(2) - (1)].node));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 2368 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = NULL;
    }
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 2372 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_ofor;
    }
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 2382 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForClause(LOC ((yyloc)),
                         dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL);
		}
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 2393 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		}
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 2399 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vardecl_list_p) {
				vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 2413 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (1)].expr);
		}
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 2421 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 2430 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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

  case 227:

/* Line 678 of lalr1.cc  */
#line 2440 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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

  case 228:

/* Line 678 of lalr1.cc  */
#line 2451 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 2460 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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

  case 230:

/* Line 678 of lalr1.cc  */
#line 2470 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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

  case 231:

/* Line 678 of lalr1.cc  */
#line 2480 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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

  case 232:

/* Line 678 of lalr1.cc  */
#line 2496 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
		}
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 2509 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
		}
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 2521 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)));

		}
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 2533 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		}
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 2539 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2551 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		}
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 2557 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2571 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
								NULL,
								NULL,
								(yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (1)].expr);
		}
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 2580 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 2590 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 2599 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (1)].expr);
		}
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 2612 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr))->get_qname(),
								NULL, (yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (2)].expr);
		}
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2619 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (2)].expr);
		}
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2631 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(), "", "");
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 2636 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_curr (static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2645 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), dynamic_cast<PositionalVar *> ((yysemantic_stack_[(1) - (1)].node)), "", "", "");
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2649 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_posvar (dynamic_cast<PositionalVar *> ((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2658 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr))->get_qname(), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr))->get_qname());
      delete (yysemantic_stack_[(6) - (3)].expr);
      delete (yysemantic_stack_[(6) - (6)].expr);
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 2664 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", "", static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2669 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname(), "");
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 2677 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::string name = static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr))->get_qname();
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           name, NULL, NULL,
                           new VarRef (LOC ((yyloc)), name),
                           VarGetsDecl::eval_var);
      delete (yysemantic_stack_[(1) - (1)].expr);

    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 2693 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 2701 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 2708 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = new GroupSpecList(LOC((yyloc)));
      gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl_p;
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 2714 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      if (gsl_p) {
        gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      }
      (yyval.node) = gsl_p;
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2725 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(),
                 NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2732 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
                 dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2742 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2752 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2757 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)),
								true);
		}
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2769 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		}
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2775 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node));
			if (osl_p) {
				osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2789 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		}
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2795 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
                         (yysemantic_stack_[(2) - (1)].expr),
                         dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2807 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
                               NULL,
                               NULL);
		}
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2814 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               NULL,
                               dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
                               NULL);
		}
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2821 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               NULL,
                               NULL,
                               dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2828 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                               dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                               NULL);
		}
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2835 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                               NULL,
                               dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2842 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               NULL,
                               dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                               dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2849 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                               dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                               dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2862 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		}
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2866 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		}
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 2876 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC((yyloc)), StaticContextConsts::empty_greatest);
		}
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2880 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC((yyloc)), StaticContextConsts::empty_least);
		}
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2890 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		}
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2901 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2908 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2921 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;

		}
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2928 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2940 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
								(yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (1)].expr);
		}
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2947 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2961 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
								(yysemantic_stack_[(8) - (8)].expr));
		}
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2968 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(10) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
								static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr))->get_qname(),
								(yysemantic_stack_[(10) - (10)].expr));
      delete (yysemantic_stack_[(10) - (8)].expr);
		}
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2983 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		}
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2989 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 3001 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 3007 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr))->get_qname(),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
      delete (yysemantic_stack_[(7) - (3)].expr);
		}
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 3021 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
		}
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 3032 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 3036 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 3047 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 3051 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 3070 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 3074 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 3082 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      /*  ::=  "is" | "<<" | ">>" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 3090 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 3098 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3105 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { /* this call is needed */  driver.lexer->interpretAsLessThan(); }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3106 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3114 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_le),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3122 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3130 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3144 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3148 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		}
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3155 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3168 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3172 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3183 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3187 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3191 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3201 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3205 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3209 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3213 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3217 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3227 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3231 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3236 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3247 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3251 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3255 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3265 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3269 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3281 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3285 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3297 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3301 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3313 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3317 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3329 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3333 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3345 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		}
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3349 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		}
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3353 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3357 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3369 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3373 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3377 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3387 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		}
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3391 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		}
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3395 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		}
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3399 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		}
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3403 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		}
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3407 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		}
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3417 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		}
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3421 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		}
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3425 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		}
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3435 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3439 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3443 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3447 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                            dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(),
                            (yysemantic_stack_[(6) - (5)].expr));
    }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3459 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		}
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3465 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3477 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		}
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3483 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node));
			if (pragma_list_p) {
				pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3497 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));

		}
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3503 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval))),
								"");
    }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3545 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		}
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3549 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3553 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3557 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (rpe == NULL ?
             (yysemantic_stack_[(1) - (1)].expr) :
             new PathExpr(LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3569 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3579 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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

  case 368:

/* Line 678 of lalr1.cc  */
#line 3590 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3595 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3605 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3609 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3619 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		}
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3625 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3631 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		}
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3637 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3649 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		}
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3655 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3666 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		}
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3670 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		}
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3674 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		}
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3678 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		}
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3682 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		}
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3686 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		}
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3690 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		}
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3700 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node), false);
		}
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3704 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		}
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3714 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseStep(LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node));
		}
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3718 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC((yyloc)), rev_p, NULL);
		}
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3729 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		}
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3733 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		}
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3737 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		}
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3741 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		}
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3745 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		}
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3760 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3764 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3774 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3778 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3788 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        "",
                        ParseConstants::wild_all);
		}
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3795 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        ParseConstants::wild_elem);
		}
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3802 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        ParseConstants::wild_prefix);
		}
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3815 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
                          (yysemantic_stack_[(2) - (1)].expr),
                          dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3831 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		}
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3837 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node));
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3851 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3862 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3866 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3870 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3874 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3878 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3882 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3886 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3890 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3900 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3904 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3914 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval));
      delete yylval.decval;
		}
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3919 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival));
      delete yylval.ival;
		}
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3924 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval));
      delete yylval.dval;
		}
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3935 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new VarRef(LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname());
      delete (yysemantic_stack_[(2) - (2)].expr);
		}
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3946 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		}
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3950 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3961 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		}
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3971 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 3982 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 4038 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)),
								NULL);
		}
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 4044 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 4056 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = new ArgList(LOC ((yyloc)));
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		}
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 4062 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 4074 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 4078 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 4088 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 4092 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 4096 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 4106 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
								NULL,
								NULL,
								NULL);
		}
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 4114 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
								NULL,
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)),
								NULL);
		}
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 4122 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(8) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr)),
								NULL,
								NULL);
		}
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 4130 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
								NULL,
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node)));
		}
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4138 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
								NULL);
		}
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4146 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(10) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)),
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node)));
		}
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4161 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		}
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4167 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4179 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		}
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4185 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4198 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
		}
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4215 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		}
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4220 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		}
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4231 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		}
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4235 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4242 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		}
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4248 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		}
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4254 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4262 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4276 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		}
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4280 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4287 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		}
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4293 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		}
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4299 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4307 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4321 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4326 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4337 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4342 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4353 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		}
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4358 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4363 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		}
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4369 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		}
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4381 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4387 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		}
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4392 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		}
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4397 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4408 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4413 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4428 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4433 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		}
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4450 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CDataSection(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		}
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4465 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4469 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4473 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4477 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4481 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4485 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4495 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4506 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
								NULL);
		}
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4512 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4518 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4523 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4545 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (2)].expr),
								NULL);
		}
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4551 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4557 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4562 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4573 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4583 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4593 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		}
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4599 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4605 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4610 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4621 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		}
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4627 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		}
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4639 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
		}
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4650 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		}
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4656 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4662 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		}
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4699 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		}
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4704 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		}
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4709 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		}
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4720 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4724 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4728 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		}
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4738 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4749 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4753 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4757 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4761 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4765 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4769 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4773 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4777 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4781 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4791 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		}
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4801 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		}
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4805 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4810 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4821 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TextTest(LOC ((yyloc)));
		}
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4831 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		}
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4841 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		}
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4845 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		}
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4849 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		}
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4859 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		}
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4865 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
								NULL);
		}
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4871 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		}
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4877 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		}
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4883 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		}
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4895 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
		}
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4906 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           NULL,
                           NULL,
                           true);
		}
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4913 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                           NULL,
                           true);
		}
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4920 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           false);
		}
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4927 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           true);
		}
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4934 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL,
									true);
		}
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4941 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									false);
		}
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4948 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									true);
		}
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4961 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)));
		}
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4982 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4989 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)),
								true);
		}
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 5009 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 5049 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::strict_validation);
		}
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 5053 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::lax_validation);
    }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 5057 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::skip_validation);
    }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 5066 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 5072 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 5078 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 5084 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 5090 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 5097 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 5103 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 5109 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 5115 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 5121 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 5133 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 5138 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 5148 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 5154 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 5166 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 5192 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 5203 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       CopyVarList* lList = new CopyVarList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
		}
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 5209 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
       VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
       lList->push_back(lBinding);
       (yyval.expr) = lList;
		}
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 5222 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (1)].expr);
    }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5238 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5245 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5251 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* aCatchListExpr = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if (aCatchListExpr) {
        aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)));
      }
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5262 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(3) - (2)].name_test_list),
                          (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5269 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(7) - (2)].name_test_list),
                          static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr))->get_qname(),
                          (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (5)].expr);
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5279 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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

  case 575:

/* Line 678 of lalr1.cc  */
#line 5290 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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

  case 576:

/* Line 678 of lalr1.cc  */
#line 5306 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      CatchExpr::NameTestList *name_test_list = new CatchExpr::NameTestList;
      name_test_list->push_back (static_cast<NameTest *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.name_test_list) = name_test_list;
    }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5312 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      CatchExpr::NameTestList *name_test_list =
        static_cast<CatchExpr::NameTestList *> ((yysemantic_stack_[(3) - (1)].name_test_list));
      name_test_list->push_back (static_cast<NameTest *> ((yysemantic_stack_[(3) - (3)].node)));
      (yyval.name_test_list) = name_test_list;
    }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5332 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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

  case 581:

/* Line 678 of lalr1.cc  */
#line 5350 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5354 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5360 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("xquery"); }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5361 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty"); }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5362 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("attribute"); }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5363 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("comment"); }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5364 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document-node"); }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5365 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("element"); }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5366 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("item"); }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5367 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("if"); }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5368 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("node"); }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5369 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("processing-instruction"); }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5370 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-attribute"); }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5371 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-element"); }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5372 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("text"); }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5373 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("typeswitch"); }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5374 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty-sequence"); }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5375 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("boundary-space"); }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5376 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ft-option"); }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5377 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("base-uri"); }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5378 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lax"); }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5379 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strict"); }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5380 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("idiv"); }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5381 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document"); }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5382 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("not"); }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5383 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sensitive"); }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5384 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insensitive"); }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5385 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("diacritics"); }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5386 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("without"); }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5387 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stemming"); }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5388 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("thesaurus"); }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5389 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stop"); }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5390 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("wildcards"); }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5391 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("entire"); }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5392 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("content"); }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5393 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("word"); }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5394 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("start"); }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5395 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("end"); }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5396 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("most"); }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5397 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("skip"); }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5398 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy"); }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5399 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("value"); }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5400 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eq"); }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5401 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ne"); }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5402 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lt"); }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5403 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("le"); }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5404 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("gt"); }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5405 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ge"); }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5406 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("at"); }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5407 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("context"); }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5408 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("variable"); }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5409 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("return"); }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5410 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("for"); }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5411 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("outer"); }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5412 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sliding"); }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5413 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("tumbling"); }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5414 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("previous"); }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5415 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("next"); }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5416 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("only"); }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5417 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("when"); }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5418 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("count"); }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5419 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("in"); }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5420 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("let"); }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5421 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("where"); }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5422 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("by"); }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5423 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("group"); }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5424 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("order"); }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5425 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stable"); }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5426 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ascending"); }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5427 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("descending"); }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5428 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("greatest"); }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5429 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("least"); }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5430 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("collation"); }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5431 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("some"); }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5432 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("every"); }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5433 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("satisfies"); }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5434 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("case"); }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5435 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("as"); }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5436 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("then"); }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5437 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("else"); }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5438 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("or"); }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5439 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("and"); }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5440 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("instance"); }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5441 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("of"); }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5442 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("castable"); }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5443 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("to"); }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5444 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("div"); }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5445 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("mod"); }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5446 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("union"); }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5447 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("intersect"); }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5448 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("except"); }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5449 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("validate"); }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5450 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("cast"); }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5451 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("treat"); }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5452 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("is"); }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5453 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("preserve"); }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5454 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strip"); }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5455 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("namespace"); }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5456 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("external"); }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5457 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("encoding"); }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5458 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-preserve"); }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5459 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("inherit"); }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5460 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-inherit"); }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5461 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("declare"); }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5462 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("construction"); }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5463 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordering"); }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5464 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("default"); }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5465 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy-namespaces"); }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5466 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("option"); }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5467 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("version"); }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5468 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("import"); }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5469 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema"); }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5470 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("module"); }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5471 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("function"); }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5472 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("score"); }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5473 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ftcontains"); }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5474 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("weight"); }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5475 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("window"); }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5476 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("distance"); }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5477 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("occurs"); }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 5478 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("times"); }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5479 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("same"); }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 5480 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("different"); }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 5481 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lowercase"); }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 5482 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("uppercase"); }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 5483 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("relationship"); }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 5484 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("levels"); }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 5485 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("language"); }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 5486 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("any"); }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 5487 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("all"); }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 5488 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("phrase"); }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 5489 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exactly"); }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 5490 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("from"); }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 5491 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("words"); }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 5492 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentences"); }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 5493 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentence"); }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 5494 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("paragraph"); }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 5495 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("replace"); }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 5496 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("modify"); }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 5497 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("first"); }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 5498 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insert"); }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 5499 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("before"); }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 5500 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("after"); }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 5501 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("revalidation"); }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 5502 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("with"); }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 5503 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nodes"); }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 5504 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("rename"); }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 5505 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("last"); }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 5506 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("delete"); }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 5507 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("into"); }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 5508 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("simple"); }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 5509 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sequential"); }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 5510 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("updating"); }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 5511 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("deterministic"); }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 5512 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nondeterministic"); }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 5513 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordered"); }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 5514 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unordered"); }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 5515 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("returning"); }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 5516 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("block"); }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 5517 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exit"); }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 5518 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("loop"); }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 5519 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("while"); }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 5520 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("break"); }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 5521 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("continue"); }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 5522 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("try"); }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 5523 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("catch"); }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 5524 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eval"); }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 5525 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("using"); }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 5526 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("set"); }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 5527 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("index"); }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 5528 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unique"); }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 5529 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("non"); }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 5530 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("on"); }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 5531 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("manual"); }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 5532 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("automatic"); }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 5533 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("decimal-format"); }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 5534 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("decimal-separator"); }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 5535 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("grouping-separator"); }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 5536 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("infinity"); }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 5537 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("minus-sign"); }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 5538 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("NaN"); }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 5539 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("percent"); }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 5540 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("per-mille"); }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 5541 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("zero-digit"); }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 5542 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("digit"); }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 5543 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("pattern-separator"); }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 5544 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("collection"); }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 5545 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("const"); }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 5546 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("append-only"); }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 5547 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("queue"); }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 5548 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("mutable"); }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 5549 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("read-only"); }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 5554 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("integrity"); }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 5555 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("constraint"); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 5556 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("check"); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 5557 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("key"); }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 5558 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("foreach"); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 5560 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("foreign"); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 5561 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("keys"); }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 5573 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)),
                          (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 5579 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 5596 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(1) - (1)].node)), NULL, NULL);
		}
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 5600 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(2) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(2) - (2)].node)), NULL);
		}
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 5604 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(3) - (1)].node)), NULL, static_cast<RangeExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		}
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 5608 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(4) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(4) - (2)].node)), static_cast<RangeExpr *> ((yysemantic_stack_[(4) - (4)].expr)));
		}
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 5618 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 5621 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 5624 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 5627 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 5636 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 5639 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 5648 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 5651 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 5660 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 5663 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 5672 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 5675 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 5684 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 5687 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 5690 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 5699 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 5702 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 5711 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), static_cast<StringLiteral *> ((yysemantic_stack_[(1) - (1)].expr)), NULL);
		}
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 5715 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 5725 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 5728 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 5731 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 5734 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 5737 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 5746 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 5755 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 5759 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 5763 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 5767 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 5771 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 5775 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 5779 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 5789 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 5792 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 5795 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 5798 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 5807 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 5810 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 5813 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 5816 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 5825 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 5828 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 5837 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 5840 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 5843 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 5846 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 5849 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 5852 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 5855 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 5864 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 5867 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 5876 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 5879 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 5882 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 5885 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 5894 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 5897 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 5900 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 5903 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 5906 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 5915 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 5918 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 5927 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 5930 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 5939 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 5942 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 5951 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 5954 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 5963 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 5972 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 5975 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 5984 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 5987 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 5990 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 5999 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 6002 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 6005 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 6008 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 6011 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 6020 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 6024 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 6028 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 6032 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 6042 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 6051 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWindow (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (2)].expr)), static_cast<FTUnit *> ((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 6061 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6070 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6073 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6082 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6085 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6088 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6097 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6100 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 6109 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTIgnoreOption (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		}
    break;



/* Line 678 of lalr1.cc  */
#line 10155 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1255;
  const short int
  xquery_parser::yypact_[] =
  {
      1465, -1255, -1255, -1255, -1255,   653,    27,    57,   -10,  8540,
      84,   240,   397, -1255, -1255, -1255, -1255, -1255, -1255,    92,
     368,  7426, -1255,   153, -1255, -1255, -1255, -1255,   233,   260,
   -1255,   149,   355,   308, -1255, -1255, -1255, -1255, -1255, -1255,
   -1255, -1255, -1255,   342,   353, -1255, -1255, -1255, -1255, -1255,
   -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255,
   -1255, -1255, -1255, -1255, -1255, -1255,  8816, -1255,  6862, -1255,
   -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255,
   -1255, -1255, 10472, -1255, -1255, -1255, -1255, -1255, -1255, -1255,
   -1255,   356, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255,
   -1255, -1255, -1255,  1750, 10472, -1255, -1255, -1255, -1255, -1255,
   -1255,   381, -1255, -1255, -1255, -1255,  7986, -1255,  8264, -1255,
   -1255, -1255, -1255, -1255, 10472, -1255, -1255,  6578, -1255, -1255,
   -1255, -1255, -1255, -1255,   390, -1255, -1255, -1255, -1255, -1255,
   -1255, -1255, -1255,    11,   334, -1255, -1255, -1255, -1255, -1255,
   -1255, -1255, -1255,   401,   421,   449, -1255,   343,   276, -1255,
   -1255, -1255, -1255, -1255, -1255,   463, -1255, -1255,   440,   367,
     380, -1255,   399,   491,   502, -1255,   542, -1255, -1255, -1255,
   -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255,
   -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255,
   -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255,
   -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255,
   -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255,
   -1255, -1255,  4306,   659, -1255,  4590, -1255, -1255,   122,  4874,
     483,   487, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255,
   -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255,
   -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255,
   -1255, -1255, -1255,   -22, -1255, -1255, -1255, -1255,   393, 10472,
   -1255, -1255, -1255, -1255, -1255,   514,   597, -1255,   823,   435,
     383,   278,   199,   181, -1255,   636,   518,   619,   628,  5158,
   -1255, -1255, -1255,   168, -1255, -1255,  6578, -1255,   248, -1255,
     583,  6862, -1255,   583,  6862, -1255, -1255, -1255, -1255,   583,
   -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255,
   -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255,
   -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255,
   -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255,   580, -1255,
   -1255, 10472,   693,   694,   584,   584,   693, 10472,   324,   -21,
     709,   145,   374, 10472,   590,   622,    90,  7986,   373,   412,
     439,   151, 10472, -1255, -1255, -1255, -1255, -1255,   452, 10472,
   -1255, -1255,   448,   313, -1255,   244, -1255, -1255, -1255,  7986,
   10472,  4874,   595,   596,  4874, -1255, -1255, -1255, -1255, -1255,
   -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255,
   -1255, -1255, -1255, -1255, -1255, -1255,  4874,  9092, -1255, -1255,
   -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255,
   -1255, -1255, -1255, -1255,   600,  4874,  4874,   564,  4874,   568,
    4874,    48,    81, -1255,  4874,  7706,   602, -1255, 10472, 10472,
   10472,  4874,   477,   478, -1255,   637,   638, 10472,    26,  4874,
    9368,   607,   605,   609,   610,   614,   615, -1255, -1255, -1255,
   10472, -1255,   586,   735,  4874,    37, -1255,   748,   593, -1255,
    4874,   563, -1255,   750,  4874,  4874,   598,  4874,  4874,  4874,
    4874,   551, 10472, -1255, -1255,  4874, -1255, -1255,  4874,  4874,
   10472, -1255, -1255, -1255, -1255,   653,   368, -1255, -1255,   122,
     747,  4874, -1255,  4874,   616,   260,   355,   308,   665,   618,
     620,  4874,  4874, -1255, -1255, -1255, -1255, -1255, -1255, -1255,
     679, -1255,   -17,  5442,  5442,  5442, -1255,  5442,  5442, -1255,
    5442, -1255,  5442, -1255, -1255, -1255, -1255, -1255, -1255, -1255,
    5442,  5442,     8,  5442,  5442,  5442,  5442,  5442,  5442,  5442,
    5442,  5442,  5442,  5442,   560,   699,   700,   701, -1255, -1255,
   -1255,  2034, -1255, -1255,  6578,  6578,  4874,   583, -1255, -1255,
     583, -1255,   583,  2318,   643, -1255, 10472, -1255, -1255, -1255,
   -1255,   769, -1255, -1255, -1255, -1255, -1255, -1255,   691,   698,
   -1255, -1255,   757,   335, 10472,   433,   649,   651,   757,   709,
     675,   683, -1255, -1255, -1255,   341,    23,   359,   781, -1255,
   -1255,   333, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255,
     -33, -1255,   521, 10472, -1255, -1255, 10472, -1255, -1255, -1255,
   10472, -1255,   686,   667, -1255,   640,  4874,  4874,   639,   648,
   -1255,     6,    19,  2602,   650,   652, -1255,   654, -1255,   646,
    7986,   727,   793,  7986,   709,   737,   655,   664, -1255,   666,
    2886,   -24, -1255,    28,   708,   743, -1255,   -38,   672, -1255,
   -1255, 10472,   -19, -1255,   670,   605,   342, -1255,   671,   673,
     678, -1255,    76,    80,  3170,     9, -1255, 10472,   735, -1255,
     -44,   680, -1255, -1255, -1255, -1255,   681, -1255,    -8, -1255,
   -1255, -1255,    82,   134,   765,   630,   645,    -2, -1255,   722,
    5726, -1255,   682,   689,    78, -1255, -1255,   684, -1255,    -1,
   -1255, -1255,   -12,   705, 10472,  4874,   755, -1255, -1255,   756,
    9920,   764,  4874,   767,   -72,   731,   -37,   597, -1255, -1255,
   -1255, -1255, -1255,  5442, -1255, -1255, -1255,  4874,     8,   234,
   -1255,   611,   550,   629,   626, -1255, -1255,   624,   226,   278,
     278,     2,   199,   199,   199,   199,   181,   181, -1255, -1255,
    9920,  9920, 10472, 10472, -1255,   710, -1255, -1255,   711, -1255,
   -1255, -1255,   137,    16,   192,   643, -1255,   302,   351, -1255,
   -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255,   757,
   -1255,   766, 10196,   759,  4874, -1255, -1255, -1255,   803,   760,
    4874,   709,   709,   757, -1255,   508,   709, -1255, -1255,   623,
   -1255, -1255,   632,   239, -1255, -1255, -1255, -1255, -1255, -1255,
     633, -1255, -1255,   140,   360,   809,  6294,  -154,   -28,   621,
     709,  4874, -1255,   728,   730,   814,   770, 10472, -1255, 10472,
   -1255, -1255,   741, -1255, -1255, -1255,   729,   792,   709,   768,
     794,   830,   709,   777, -1255, -1255, -1255,   749,   810,  4874,
    4874,   786,  4874,   815,  4874,   795,   -67, -1255,    73,   687,
   -1255, -1255,   476,   -19, -1255, -1255, -1255,   782, 10472, -1255,
   10472, -1255, -1255,   754,  4874,   919, -1255,   -34, -1255,   146,
   -1255, -1255,   928, -1255,   446,  4874,  4874,  4874,   453,  4874,
    4874,  4874,  4874,  4874,  4874,   839,  4874,  4874,   622,     1,
     778,   440,   716,   816,   842,   747,   888, -1255,  4874, -1255,
     461,   861, -1255, 10472,   862, -1255, 10472,   817,   819, -1255,
     318, -1255, -1255, -1255, 10472, -1255, 10472,  4874,   829,  4874,
    4874,   -70,   832, -1255,   798,   791, -1255,   724, -1255,   -81,
   -1255,   321,   -14,   725,     8,   321,  5442,  5442,   642, -1255,
   -1255, -1255, -1255, -1255, -1255, -1255,     8,   840,   -14, -1255,
     703,   930, -1255, -1255, -1255, -1255, -1255,   844, -1255, -1255,
   -1255,  4874, -1255, 10472,   893,   188, -1255, -1255,  4874, -1255,
     219, -1255, -1255, -1255, -1255, -1255,   960,   470, -1255, -1255,
   -1255,  4874, -1255, -1255, -1255, -1255, -1255, -1255,   712,    51,
     961, -1255,   436, -1255, -1255,   609,   610,   614,   353,   615,
     421, -1255,   771,   773,   140,   824,   707,   695,   140,   900,
    6294,   812,   820, -1255, -1255,  9644,   301, -1255,  3454,   818,
     821,   860,   822,   825, -1255,  4874,   709,   896, -1255, -1255,
   -1255,   709,   896,  3738, -1255, 10472, -1255, -1255,  4874, -1255,
   10472, -1255,  4874,  4874,   866,  4874,   863, -1255,   891,   892,
    4874, 10472,   625,   942, -1255, -1255, -1255,  4022,   831,   833,
   -1255, -1255, -1255,   883, -1255,   203, -1255, -1255,  1001, -1255,
   -1255,  4874, 10472, -1255, -1255,   330, -1255, -1255, -1255,   834,
     787,   788, -1255, -1255, -1255,   789,   800, -1255, -1255, -1255,
   -1255, -1255,   797, 10472,   846, -1255,   895, -1255,   622, -1255,
   -1255, -1255,  7146,   716, -1255,  4874, 10472,   861, -1255,   709,
   -1255,   582, -1255,    31,   926, -1255,  4874,   927,   755, -1255,
     853,   854, -1255, -1255, -1255, -1255, -1255, -1255, -1255,  4874,
   -1255, -1255,  4874,   894,  4874, -1255, -1255,  5442, -1255, -1255,
   -1255, -1255, -1255,   252,  5442,  5442,   350, -1255,   629, -1255,
   -1255,    68,  5442, -1255, -1255,   626,     8,   772, -1255, -1255,
   -1255, -1255,   803,  9920,   921,   946,   864, -1255, -1255, -1255,
   -1255, -1255,    -5,  1013,  1014,    -5,   -45,   200,   223, -1255,
   -1255, -1255,  6294, 10472,   790, -1255,   140,   876, -1255, -1255,
   10472,   867,   -32, -1255, -1255,   868, -1255, -1255, -1255, -1255,
   -1255,   922,   955,   709,   896, -1255,   872, -1255, -1255, -1255,
   -1255, -1255,  4874, -1255,  4874, 10472, 10472, -1255,    86, -1255,
    4874, -1255,   874, -1255, -1255,   919, 10472,   394, -1255,   875,
     919, 10472, -1255, -1255,  4874,  4874,  4874,  4874,  4874, -1255,
    4874,  4874, -1255, -1255,   -15, -1255,   877, -1255, -1255, -1255,
   -1255,   926, -1255, -1255, -1255,   709, -1255, -1255, -1255, -1255,
   -1255, -1255,  4874, -1255,   199,  5442,  5442,   199,   423, -1255,
   -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255,
    9920, -1255,    51,    51,    -5, -1255, -1255, -1255,    35,    -5,
    1028,   796,   962, -1255,   962, -1255,   953, -1255,   967,   -68,
     779, -1255,  6294,   969,  4874, 10472,  4874, -1255,  4874,   709,
   -1255, -1255, -1255, -1255,   998, -1255, -1255, -1255, -1255,   -13,
     919, 10472, -1255,   873,   919, -1255, -1255, -1255, -1255, -1255,
   -1255, -1255,   949,  7146, -1255, -1255, -1255, -1255, -1255,   199,
     199,  5442, -1255, -1255, -1255, -1255, -1255, -1255,   -14, -1255,
     224, -1255,   261,  6294, 10472, 10472,   847, 10472,   953,  9920,
   -1255,   886, -1255, -1255,   896,   952,   129,   254, -1255,   878,
     919, -1255,   879, 10472, -1255,   199,   811,   962, -1255, -1255,
   -1255,   461,   780,   957,   856,   897,  4874, 10472, -1255, -1255,
     983,   317, -1255, -1255, -1255, -1255,   901,   295, -1255, -1255,
   -1255,   889, -1255,   267, -1255, -1255, -1255,  6010, 10472,   963,
    4874, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255,
     965,   935,   799, -1255,   801, 10472, -1255, 10472, -1255,  6294,
    4874,   785,   282, -1255, -1255,  6294,   970,   935,   898, 10472,
   -1255,   804,   907, 10472,   935,   869, -1255,   974, 10472,   802,
    6294, -1255
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   399,   400,   581,   546,   684,   693,   672,   596,   588,
     604,   595,   586,   694,   733,   732,   734,   735,   731,   590,
     691,   592,   619,   654,   648,   689,   616,   692,   749,   643,
     685,   747,   633,   634,   635,   636,   637,   638,   639,   640,
     641,   686,   600,   594,   587,   688,   663,   593,   598,   756,
     757,   758,   759,   760,   761,   762,   763,   764,   765,   766,
     390,   393,   662,   658,   649,   629,   585,   380,     0,   657,
     665,   673,   378,   653,   416,   630,   631,   687,   379,   382,
     650,   667,     0,   422,   388,   418,   660,   584,   651,   652,
     680,   655,   671,   679,   384,   383,   603,   642,   682,   417,
     670,   675,   589,     0,     0,   337,   668,   678,   683,   681,
     661,   736,   647,   645,   646,   389,     0,   336,     0,   392,
     391,   676,   632,   656,     0,   381,   366,     0,   398,   677,
     659,   666,   674,   669,   737,   623,   628,   627,   626,   625,
     624,   597,   644,     0,   583,   690,   617,   723,   722,   724,
     602,   601,   620,   729,   591,   721,   726,   727,   718,   622,
     664,   720,   730,   728,   719,   621,   725,   738,   739,   740,
     743,   741,   744,   742,   745,   746,   748,   710,   709,   606,
     599,   608,   607,   703,   699,   614,   618,   615,   712,   713,
     696,   605,   708,   707,   704,   700,   717,   711,   706,   702,
     695,   716,   715,   701,   705,   697,   698,   609,   610,   612,
     714,   611,   613,   767,   768,   769,   770,   771,   772,   751,
     752,   750,   754,   755,   753,   773,   774,   775,   776,   777,
     778,   779,     0,     0,     2,     0,     4,     6,    12,     0,
       0,     0,    18,    20,    34,    22,    23,    24,    50,    25,
      29,    30,    54,    55,    56,    51,    52,    58,    59,    27,
      26,    31,    32,    33,    53,   196,   195,   192,   193,   194,
      28,    11,   173,   174,   178,   180,   211,   217,     0,     0,
     209,   210,   181,   182,   183,   184,   293,   295,   297,   307,
     310,   312,   315,   320,   323,   326,   328,   330,   332,     0,
     334,   340,   342,     0,   358,   341,   362,   365,   367,   370,
     372,     0,   377,   374,     0,   385,   395,   397,   371,   401,
     406,   414,   407,   408,   409,   412,   413,   410,   411,   429,
     431,   432,   433,   430,   478,   479,   480,   481,   482,   483,
     394,   520,   512,   519,   518,   517,   514,   516,   513,   515,
     415,    57,   185,   186,   188,   187,   189,   190,   396,   582,
     191,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   115,   116,
       0,     0,     0,   111,   112,   113,   114,   125,     0,     0,
     128,   127,     0,     0,   109,     0,   121,   156,   159,     0,
       0,     0,     0,     0,     0,   684,   693,   672,   596,   588,
     604,   595,   586,   590,   691,   592,   654,   749,   643,   747,
     633,   634,   594,   587,   585,   655,     0,     0,   736,   737,
     583,   729,   591,   721,   727,   718,   621,   739,   740,   743,
     744,   742,   745,   748,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   579,     0,     0,     0,   580,     0,     0,
       0,     0,     0,     0,   219,     0,     0,     0,     0,     0,
       0,     0,   588,   595,   586,   592,   585,   386,   396,   419,
       0,   420,     0,   445,     0,     0,   361,     0,     0,   364,
       0,     0,   474,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   146,   143,     0,   154,   155,     0,     0,
       0,     3,     1,     5,     7,     0,     0,    13,    10,    15,
      16,     0,   176,   175,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   197,   216,   212,   218,   213,   215,   214,
     221,   222,     0,     0,     0,     0,   351,     0,     0,   349,
       0,   302,     0,   350,   343,   348,   347,   346,   345,   344,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   339,   338,
     335,     0,   359,   363,     0,     0,     0,   373,   403,   376,
     375,   387,   402,     0,     0,   161,     0,   162,   158,   157,
     160,     0,   137,   138,    67,    68,   578,    76,     0,     0,
      61,    62,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   547,   548,   549,     0,     0,     0,     0,   818,
     819,     0,    66,   811,   812,   813,   814,   815,   816,   817,
     101,   126,     0,     0,   115,   116,     0,   110,   123,   124,
       0,   122,     0,     0,   544,     0,     0,     0,     0,     0,
     536,     0,     0,     0,     0,     0,   525,     0,   526,     0,
       0,    85,     0,     0,     0,    77,     0,     0,   527,     0,
       0,     0,   282,     0,     0,   234,   235,     0,     0,   199,
     200,     0,     0,   220,     0,     0,     0,   522,     0,     0,
       0,   530,     0,     0,     0,     0,   421,   446,   445,   442,
       0,     0,   476,   475,   360,   535,     0,   473,     0,   560,
     561,   521,     0,     0,     0,     0,     0,     0,   566,     0,
       0,   152,     0,     0,     0,   237,   254,     0,    19,     0,
      21,   179,     0,     0,     0,     0,     0,   198,   255,     0,
       0,     0,     0,     0,     0,     0,     0,   294,   296,   300,
     306,   305,   304,     0,   301,   298,   299,     0,     0,     0,
     803,   308,   782,   790,   792,   794,   796,   798,   801,   314,
     313,   311,   317,   318,   319,   316,   321,   322,   325,   324,
       0,     0,     0,     0,   356,     0,   368,   369,     0,   404,
     425,   427,     0,     0,     0,     0,    65,     0,     0,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    36,
      37,     0,     0,    93,     0,    89,    91,    92,    96,    99,
       0,     0,     0,    35,    75,     0,     0,   820,   821,     0,
     822,   826,     0,     0,   855,   824,   825,   854,   823,   827,
       0,   834,   856,     0,     0,   102,     0,     0,   105,     0,
       0,     0,   352,     0,     0,     0,     0,     0,   540,     0,
     537,   485,     0,   484,   493,   494,     0,     0,     0,     0,
       0,    78,     0,     0,   529,   528,   495,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   781,     0,     0,
     201,   202,     0,   207,   543,   523,   524,     0,     0,   533,
       0,   531,   489,     0,     0,   445,   443,     0,   434,     0,
     423,   424,     0,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   684,     0,
       0,     0,     0,     0,     0,    17,     0,   177,     0,   208,
     266,   262,   264,     0,   256,   257,     0,   589,   597,   501,
     502,   508,   509,   511,     0,   224,     0,     0,     0,     0,
       0,     0,     0,   303,     0,     0,   797,     0,   309,     0,
     810,     0,     0,     0,     0,     0,     0,     0,   783,   787,
     805,   786,   809,   807,   806,   808,     0,     0,     0,   799,
     862,   860,   864,   802,   327,   329,   331,   499,   333,   357,
     405,     0,   426,     0,   139,     0,   167,   164,     0,   163,
       0,    73,    74,    71,    72,    38,     0,     0,    94,    95,
      97,     0,    98,    63,    64,    69,    70,    60,     0,     0,
       0,   829,     0,   828,   845,     0,     0,     0,     0,     0,
       0,   103,     0,     0,     0,     0,     0,     0,     0,   106,
       0,     0,     0,   354,   353,     0,     0,   288,     0,     0,
       0,   544,     0,     0,   486,     0,     0,    87,    81,    84,
      83,     0,    79,     0,   496,     0,   280,   284,     0,   151,
       0,   239,     0,     0,     0,     0,     0,   203,     0,     0,
       0,     0,   248,     0,   245,   250,   206,     0,     0,     0,
     490,   281,   446,     0,   435,     0,   469,   466,     0,   470,
     471,     0,     0,   472,   465,     0,   440,   468,   467,     0,
       0,     0,   553,   554,   550,     0,     0,   558,   559,   555,
     564,   562,     0,     0,     0,   568,   149,   148,     0,   145,
     144,   153,     0,   569,   570,     0,     0,   263,   275,     0,
     276,     0,   267,   268,   269,   270,     0,   259,     0,   223,
       0,     0,   505,   507,   506,   503,   232,   233,   226,     0,
     228,   225,     0,     0,     0,   804,   800,     0,   857,   858,
     878,   877,   873,     0,     0,     0,     0,   859,   791,   872,
     784,     0,     0,   789,   788,   793,     0,     0,   863,   861,
     500,   428,   169,     0,     0,   140,     0,   166,   165,    39,
      90,   100,   843,     0,     0,   841,   837,     0,     0,   118,
     117,   104,     0,     0,     0,   107,     0,     0,    14,   355,
       0,     0,     0,   289,   487,     0,   541,   542,   545,   538,
     539,     0,    86,     0,    80,   497,     0,   283,   285,   236,
     241,   240,     0,   243,     0,     0,     0,   205,   246,   249,
       0,   491,     0,   534,   532,   445,     0,     0,   477,     0,
     445,     0,   441,     9,     0,     0,     0,     0,     0,   567,
       0,     0,   147,   576,     0,   571,     0,   238,   279,   277,
     278,   271,   272,   273,   265,     0,   260,   258,   510,   504,
     230,   227,     0,   229,   879,     0,     0,   865,     0,   876,
     875,   874,   869,   870,   785,   795,   871,   170,   141,   168,
       0,   172,     0,     0,   844,   846,   848,   850,     0,   842,
       0,     0,     0,   832,     0,   830,   119,   129,     0,     0,
       0,   108,     0,     0,     0,     0,     0,   488,     0,     0,
      82,   498,   242,   244,   253,   252,   247,   204,   492,     0,
     445,     0,   171,     0,   445,   551,   552,   556,   557,   563,
     565,   150,     0,     0,   572,   780,   274,   261,   231,   867,
     866,     0,   142,   853,   852,   847,   851,   849,   838,   839,
       0,   835,     0,     0,     0,     0,     0,     0,   120,     0,
     290,     0,   286,   292,    88,     0,   455,   449,   444,     0,
     445,   436,     0,     0,   577,   868,     0,     0,   833,   831,
     130,   131,     0,     0,     0,     0,     0,     0,   463,   457,
       0,   456,   458,   464,   461,   451,     0,   450,   452,   462,
     438,     0,   437,     0,   840,   836,   132,     0,     0,     0,
       0,   287,   251,   448,   459,   460,   447,   453,   454,   439,
       0,     0,   751,   133,     0,     0,   291,     0,   573,     0,
       0,     0,     0,   134,   135,     0,     0,     0,     0,     0,
     574,     0,     0,     0,     0,     0,   575,     0,     0,     0,
       0,   136
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1255, -1255,   855, -1255,   851,   858, -1255,   850, -1255,   572,
     575,  -504, -1255,   479,  -270, -1255, -1255, -1255, -1255, -1255,
   -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255,  -863,
   -1255, -1255, -1255, -1255,    69,   275,   726, -1255, -1255, -1255,
     706,   242, -1255, -1255,   713,  -250,  -300, -1255, -1255,   299,
   -1255,  -860, -1255, -1255,   -43, -1255, -1255, -1255, -1255, -1255,
     338,    65, -1255, -1255,  -108, -1255, -1254,   870,   -95, -1255,
     587,  -415, -1255, -1255, -1255, -1255,   204, -1255, -1255,   836,
   -1255, -1255, -1255, -1255, -1255,   155,  -503,  -658, -1255, -1255,
   -1255,    22, -1255, -1255,  -153,    14,   -39, -1255, -1255, -1255,
     -50, -1255, -1255,   171,   -46,  -310, -1255,   -41, -1052, -1255,
     644,    38, -1255, -1255,    59, -1255, -1255,   585,   588, -1255,
    -498,  -956,   561,   147,  -563,   138,   142, -1255, -1255, -1255,
   -1255, -1255,   828, -1255, -1255, -1255, -1255, -1255,   826,  -832,
   -1255,  -104, -1255, -1255, -1255, -1255, -1255, -1255, -1255,   -42,
   -1125, -1255, -1255,  -179,    56, -1255,  -561, -1255, -1255, -1255,
   -1255, -1255, -1255, -1255, -1255, -1255,  -894, -1255,    15, -1255,
     425,  -699, -1255, -1255, -1255, -1255, -1255,  -316,  -306, -1058,
    -963, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255, -1255,
   -1255,  -791,  -666,  -780, -1255,   314,  -779,  -730, -1255, -1255,
   -1255, -1255, -1255, -1255, -1255,   669,   674,  -365,   269,   113,
   -1255, -1255, -1255, -1255, -1255, -1255, -1255,    -3, -1255, -1255,
      -7, -1255,  -363,   -98,    -9, -1255, -1255,   376, -1255, -1255,
     157,   152,   -61,   382, -1255, -1255,   161, -1255,  -741, -1255,
   -1255, -1255, -1255,  -194,  -828, -1255,   -73,  -614, -1255,  -706,
   -1255, -1255, -1255, -1255,  -976, -1255, -1255, -1255, -1255,   -48,
     169, -1255
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   819,   820,   821,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,  1077,
     674,   258,   259,   825,   826,   827,  1146,   260,   261,   393,
     394,   855,   262,   395,   396,  1346,  1347,   263,   264,   804,
     265,   504,   730,   939,  1147,   266,   267,   268,   269,   270,
     397,   398,   597,  1015,  1016,  1123,  1019,   271,   272,   523,
     273,   274,   275,   533,   465,   902,   903,   276,   534,   277,
     536,   278,   279,   280,   540,   541,  1102,   755,   281,   685,
     734,   686,   692,  1103,  1104,  1105,   735,   537,   538,   954,
     955,  1306,   539,   951,   952,  1162,  1163,  1164,  1165,   282,
     681,   682,   283,  1066,  1067,   284,   285,   286,   287,   763,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   560,   561,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   587,   588,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   802,   328,   329,   330,  1125,   708,
     709,   710,  1418,  1446,  1447,  1440,  1441,  1448,  1442,  1126,
    1127,   331,   332,  1128,   333,   334,   335,   336,   337,   338,
     339,  1006,   756,   959,  1175,   960,   961,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   653,  1070,   350,
     351,   352,   353,   354,   355,   356,   727,   728,   357,  1153,
    1154,  1294,  1078,   456,   358,   359,   360,   771,   988,   772,
     773,   774,   775,   776,   777,   778,   989,   990,   632,   633,
     634,   635,   636,  1400,  1401,   637,  1334,  1225,  1338,  1335,
     638,   639,   992,  1003,  1196,   993,   994,   999,   995,  1322,
    1192,   978
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -125;
  const short int
  xquery_parser::yytable_[] =
  {
       444,   770,  1008,   782,   783,   784,   785,   607,   482,   917,
    1004,  1005,   457,  1007,  1007,  1043,   740,   891,   485,  1082,
     962,   896,  1207,   489,  1055,  1124,   477,  1293,     4,   895,
    1200,   991,   491,   361,   362,   363,   364,   365,   366,   754,
    1384,   899,  1405,  1193,   712,   367,   688,   759,   750,   760,
     761,   751,   762,   853,   764,  1396,   695,   471,  1058,   478,
     962,   962,   765,   766,   967,  1093,  1182,  1282,   606,   750,
     373,   751,  1416,   479,  1193,   888,   918,   521,  1355,   719,
     720,  1151,   722,   723,   724,   725,  1114,   521,   671,   675,
     731,   696,   962,   732,   894,   483,   968,   935,   972,   970,
    1148,   606,   374,   375,   946,   867,   741,   457,   888,   487,
      74,  1302,  1303,   922,   750,   488,   747,   748,   869,   752,
     616,  1332,    85,  1051,   617,  1188,  1013,  1018,   839,  1159,
    1382,   943,  1056,  1438,   590,   404,   604,  1116,  1057,  1223,
     592,   919,  1356,   400,  1098,  1099,    99,   515,  1161,   563,
     767,  1115,   889,   768,  1116,  1117,   378,   522,  1417,   750,
    1218,   618,  1030,   516,   890,  1189,   564,   947,   924,   605,
     695,   923,  1045,  1046,   751,   908,   399,   944,   801,   910,
    1149,   868,  1047,  1383,  1333,   914,   672,   900,   619,   379,
     753,  1014,   753,   854,   870,   753,  1224,   670,   854,   401,
     713,   697,   583,  1194,  1195,   696,  1048,   770,   770,  1095,
    1397,  1116,  1117,   492,  1228,  1340,  1113,  1478,  1254,  1282,
     928,  1124,   936,  1406,   753,   753,   445,   901,  1237,  1049,
     673,  1124,  1096,  1490,  1194,  1195,  1011,   450,  1094,   381,
    1496,  1118,  1119,   625,  1120,   753,  1324,  1204,   620,  1386,
    1341,   909,  1439,   971,     4,   911,   834,   570,  1424,  1119,
     769,  1120,  1116,   458,   840,   973,   571,   402,   403,   589,
     542,  1121,   591,  1444,   382,   383,   384,   385,   386,   621,
     387,   388,   389,   390,   391,  1241,   392,  1214,  1121,   925,
     926,   461,   104,   841,   842,  1315,   843,   844,  1118,  1342,
     608,   652,   478,  1116,   927,   478,   655,   572,   116,   658,
     581,   881,  1012,  1183,  1444,   609,  1119,   124,  1120,  1017,
     573,  1438,  1344,  1427,  1231,  1116,  1319,  1040,  1235,  1122,
     950,   659,  1320,   118,  1018,   962,    74,   965,  1116,  1117,
    1321,   929,   930,   459,  1041,  1121,  1217,   143,    85,   104,
     664,   665,   594,   667,  1050,   669,   931,   679,   601,   676,
    1427,   503,   466,  1215,   612,   116,  1470,  1119,   457,  1120,
     460,  1316,    99,   640,   700,  1343,   767,   626,  1445,   768,
     642,  1486,   446,  1124,  1042,   447,  1276,   566,   570,   711,
     457,   654,   627,  1065,   451,   716,  1121,   571,  1345,  1428,
    1348,   648,  1116,  1117,   143,   628,  1242,   629,  1119,  1029,
    1120,   462,   463,   567,   733,  1032,   452,   630,   662,  1467,
     631,   822,  1426,   770,  1201,  1118,   568,   595,   584,   585,
    1119,   600,  1120,  1328,   649,   770,  1429,  1121,   524,  1021,
    1464,   740,  1471,  1119,   525,  1120,   457,   526,   527,   683,
     684,   687,  1172,  1443,  1449,   528,  1022,  1487,   694,  1121,
     569,   703,   823,  1000,  1001,   464,   480,   824,  1033,  1034,
     644,   683,  1121,  1037,  1086,  1087,   104,  1089,  1443,  1091,
     796,   797,  1173,   962,  1449,  1002,   795,   467,  1023,  1118,
     500,   798,   116,   729,   602,   501,  1414,  1061,   468,  1111,
    1174,   736,  1069,   645,  1072,  1024,  1351,  1119,   603,  1120,
    1132,  1133,  1134,  1281,  1137,  1138,  1139,  1140,  1141,  1142,
    1348,  1144,  1145,   484,  1040,   387,   388,   650,   390,   391,
     563,   143,   490,   950,  1098,  1099,  1121,  1100,   493,   448,
     104,  1227,   449,  1108,   610,  1109,  1327,   564,  1158,  1025,
    1392,   529,  1178,   530,  1180,  1181,   116,   499,   611,  1159,
     829,   863,   864,  1025,   751,   830,   496,   531,   872,  1160,
     565,  1348,   877,   502,   848,   880,  1369,  1371,  1161,  1190,
     837,  1373,   503,   838,  1191,   887,  1101,   805,   646,   383,
     384,   385,   386,   532,   505,   143,  1211,   823,   845,  1455,
     962,   846,   824,   849,   850,   828,   851,   852,  1319,   913,
    1391,   506,   570,  1431,  1320,   494,  1221,   495,   361,   362,
     363,   571,  1321,   366,  1314,  1007,  1035,  1036,  1395,  1435,
     507,  1317,  1318,  1395,   857,   940,   508,   858,   979,  1052,
    1053,   859,   625,   799,   509,   770,   799,  1483,   799,   622,
     623,   624,   510,  1488,  -123,  -123,  -123,  -123,  -123,   512,
    1251,   457,   519,   497,   457,   498,   520,  1130,  1501,  1131,
     543,  1419,   974,  1258,  1135,  1422,  1136,  1260,  1261,   962,
    1263,   544,   898,  1098,  1099,  1267,   562,   361,   362,   363,
     364,   365,   366,  -124,  -124,  -124,  -124,  -124,   915,   367,
    1299,  1300,   598,   599,   574,   368,   575,   980,   786,   787,
     779,   780,   576,  1252,   788,   789,   369,   370,  1393,  1394,
     371,  1451,   577,   372,   373,   593,   586,   361,   596,   606,
     979,   613,   614,   641,   625,   949,   643,   656,   657,   666,
    1296,   963,   663,   668,   680,   689,   690,   691,   693,   704,
     427,   950,  1389,  1390,   447,   449,   374,   375,   376,   455,
     470,   706,   707,   714,  1310,   717,  1062,  1311,   715,  1313,
     718,   726,   739,   721,   743,   744,   626,   745,   749,   746,
     790,   963,   963,   963,   963,   791,   792,   793,   803,   806,
     807,   627,   835,   981,   982,   983,  1298,   808,   831,   980,
     832,   847,   377,   984,   628,   836,   629,   856,   860,   861,
     378,   985,   862,   963,   865,   878,   630,   986,   987,   631,
     866,   876,   873,   879,   874,   882,   875,   883,  1425,   809,
     810,   811,   812,   813,   814,   815,   816,   817,   818,   884,
     892,   885,   893,   379,   897,   904,   905,  1362,   906,  1363,
     907,   932,   920,   921,   937,  1367,   933,   941,  1071,   934,
    1071,   942,   380,   945,   948,   953,   956,   969,   626,  1375,
    1376,  1377,  1378,  1379,   964,  1380,  1381,   966,   997,   996,
     977,   998,  1009,   627,  1010,   981,   982,   983,  1026,   750,
    1360,   824,  1031,   381,  1038,  1054,   628,  1388,   629,   654,
    1063,   654,  1064,   985,  1039,  1044,  1065,  1060,   630,  1202,
     987,   631,  1068,  1074,  1076,  1075,  1080,  1079,  1081,  1083,
    1085,  1084,  1088,  1216,  1107,  1090,  1110,  1092,   382,   383,
     384,   385,   386,  1097,   387,   388,   389,   390,   391,  1410,
     392,  1412,  1387,  1413,  1167,   545,  1112,   542,  1129,  1143,
    1150,  1152,  1156,   546,   547,  1176,   548,  1177,  1155,   618,
    1166,  1168,  1170,   549,  1171,  1179,  1186,   550,  1184,   551,
    1185,  1187,  1197,  1245,   552,  1208,  1206,  1209,  1210,  1213,
       4,  1226,  1233,  1232,  1222,  1234,  1236,  1229,  1256,  1230,
     553,  1238,  1239,  1246,  1248,  1253,  1247,  1249,  1262,  1264,
    1250,  1265,  1266,  1270,  1212,  1275,  1273,  1278,  1274,  1284,
    1285,  1286,  1272,  1283,   554,   555,   556,   557,   558,   559,
    1290,  1461,  1287,  1288,  1159,  1305,  1279,  1291,  1308,  1309,
    1312,  1013,  1330,  1336,  1337,  1352,  1331,  1326,  1358,  1350,
    1357,  1354,  1473,  1359,  1361,  1476,  1368,  1372,  1398,  1385,
    1040,  1399,  1403,  1404,  1407,  1409,   963,  1415,  1421,  1423,
    1436,  1433,  1437,  1450,  1452,  1484,  1454,  1458,  1463,  1457,
    1459,  1460,  1466,  1475,  1469,  1477,   683,  1018,  1485,  1493,
    1489,   687,  1494,  1497,  1498,  1491,   513,   511,   517,  1479,
    1480,   737,  1268,   514,   738,  1500,  1220,   833,  1028,   647,
    1059,   615,  1408,  1430,  1020,  1292,  1329,  1106,   651,   518,
     742,  1169,  1259,  1280,   535,  1366,  1269,  1297,  1307,  1157,
    1304,  1456,  1301,  1257,   705,  1243,   781,   580,   757,   582,
    1277,  1468,   758,   916,   729,  1465,  1027,   698,  1073,  1219,
    1289,  1198,   699,   478,   975,  1325,  1295,   736,  1205,  1203,
    1402,   976,  1339,  1323,  1199,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   963,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1349,     0,     0,     0,     0,     0,
       0,  1353,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1364,  1365,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1370,     0,     0,
       0,     0,  1374,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   963,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1411,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1420,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   478,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   963,  1432,     0,  1434,     0,
     963,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1453,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1462,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1474,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1481,     0,  1482,     0,
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
    1492,     0,     2,     3,  1495,     4,     0,     0,     0,  1499,
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
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,   405,   406,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,   414,    21,    22,    23,    24,    25,    26,    27,     0,
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
     121,     0,     0,     0,   122,   481,   123,   124,   125,     0,
     126,   127,   128,     0,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,   143,     0,   430,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,   405,
     406,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,   414,    21,    22,    23,    24,
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
       0,     0,   119,   120,   121,     0,   794,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   430,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,   405,   406,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,   414,
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
       0,     0,   122,   800,   123,   124,   125,     0,   126,   127,
     128,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   430,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,   405,   406,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,   414,    21,    22,    23,    24,    25,    26,
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
     119,   120,   121,     0,   871,     0,   122,     0,   123,   124,
     125,     0,   126,   127,   128,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   430,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
       0,   405,   406,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,   414,    21,    22,
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
     117,   118,     0,     0,   119,   120,   121,     0,   886,     0,
     122,     0,   123,   124,   125,     0,   126,   127,   128,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   430,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,   405,   406,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,   414,    21,    22,    23,    24,    25,    26,    27,     0,
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
     121,     0,   912,     0,   122,     0,   123,   124,   125,     0,
     126,   127,   128,     0,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,   143,     0,   430,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,   405,
     406,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,   414,    21,    22,    23,    24,
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
       0,     0,   119,   120,   121,     0,  1244,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   430,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,   405,   406,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,   414,
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
    1255,     0,   122,     0,   123,   124,   125,     0,   126,   127,
     128,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   430,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,   405,   406,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,   414,    21,    22,    23,    24,    25,    26,
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
     119,   120,   121,     0,  1271,     0,   122,     0,   123,   124,
     125,     0,   126,   127,   128,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   430,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
       0,     5,     6,     0,     7,     8,     9,    10,    11,    12,
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
     142,   143,     0,   430,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,   405,
     406,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,   414,    21,    22,    23,    24,
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
     140,     0,     0,   141,   142,   143,     0,   430,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,   405,   406,     0,     7,   408,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,   413,   414,
      21,    22,   416,    24,    25,    26,    27,     0,   417,   418,
      30,   419,   420,   421,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,     0,    72,    73,     0,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,     0,    85,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,   425,    92,    93,    94,    95,     0,     0,
       0,     0,     0,    96,    97,    98,    99,   100,   101,   102,
       0,     0,     0,   103,   104,   578,   106,   107,     0,     0,
       0,     0,   108,   109,   110,   111,   112,   113,   114,   115,
     116,     0,   579,   118,     0,     0,   119,   120,   121,     0,
       0,     0,   122,     0,   123,   124,   125,     0,   126,   127,
     128,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   430,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   431,   154,   433,   156,   434,   435,   159,   160,   161,
     162,   163,   164,   436,   166,   167,   437,   438,   439,   171,
     440,   441,   442,   175,   443,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,   405,   406,     0,
       7,   408,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,   413,   414,    21,    22,   416,    24,    25,    26,
      27,     0,   417,   418,    30,   419,   420,   421,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     0,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,     0,    72,
      73,     0,     0,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     0,    85,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   425,    92,    93,
      94,    95,     0,     0,     0,     0,     0,    96,    97,    98,
      99,   100,   101,   102,     0,     0,     0,   103,   104,   105,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   111,
     112,   113,   114,   115,   116,     0,   117,   118,     0,     0,
     119,   120,   121,     0,     0,     0,   122,     0,   123,   124,
     125,     0,   126,   127,   128,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   430,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   431,   154,   433,   156,   434,
     435,   159,   160,   161,   162,   163,   164,   436,   166,   167,
     437,   438,   439,   171,   440,   441,   442,   175,   443,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
       0,   938,   406,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,   414,    21,    22,
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
     138,   139,   140,     0,     0,   141,   142,   143,     0,   430,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,   405,   406,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,   414,    21,    22,    23,    24,    25,    26,    27,     0,
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
     142,   143,     0,   430,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,  1472,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,   405,
     406,     0,   407,   408,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,   413,   414,    21,    22,   416,    24,
      25,    26,    27,     0,   417,   418,    30,   419,   420,   421,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
       0,    72,    73,     0,     0,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     0,    85,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,   425,
      92,    93,    94,    95,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,   103,
     104,     0,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     0,     0,     0,
       0,     0,   119,   120,   121,     0,     0,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   430,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   431,   154,   433,
     156,   434,   435,   159,   160,   161,   162,   163,   164,   436,
     166,   167,   437,   438,   439,   171,   440,   441,   442,   175,
     443,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,   405,   406,     0,   407,   408,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,   413,   414,
      21,    22,   416,    24,    25,    26,    27,     0,   417,   418,
      30,   419,   420,   421,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,     0,    72,    73,     0,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,     0,    85,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,   425,    92,    93,    94,    95,     0,     0,
       0,     0,     0,    96,    97,    98,    99,   100,   101,   102,
       0,     0,     0,   103,   104,     0,   106,   107,     0,     0,
       0,     0,   108,   109,   110,   111,   112,   113,   114,   115,
     116,     0,     0,     0,     0,     0,   119,   120,   121,     0,
       0,     0,   122,     0,   123,   124,   125,     0,     0,     0,
     128,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   430,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   431,   154,   433,   156,   434,   435,   159,   160,   161,
     162,   163,   164,   436,   166,   167,   437,   438,   439,   171,
     440,   441,   442,   175,   443,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     0,     0,     0,     0,     0,   405,   406,     0,
     407,   408,   472,   410,   473,   474,    13,    14,    15,    16,
      17,    18,   413,   414,   475,    22,   416,    24,    25,    26,
      27,     0,   417,   418,    30,   419,   420,   421,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     0,     0,    62,     0,    63,    64,
      65,   476,     0,     0,    69,    70,    71,     0,     0,     0,
      73,     0,     0,     0,     0,    75,    76,    77,     0,     0,
      80,    81,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   425,    92,    93,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
       0,   100,   101,   102,     0,     0,     0,     0,     0,     0,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   428,
     112,   113,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,     0,     0,     0,   122,     0,   123,   124,
       0,     0,     0,     0,   128,     0,   129,     0,   130,   131,
     132,   133,   429,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,     0,     0,   430,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   431,   154,   433,   156,   434,
     435,   159,   160,   161,   162,   163,   164,   436,   166,   167,
     437,   438,   439,   171,   440,   441,   442,   175,   443,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     0,     0,     0,     0,
       0,   405,   406,     0,   407,   408,   409,   410,   411,   412,
      13,    14,    15,    16,    17,    18,   413,   414,   415,    22,
     416,    24,    25,    26,    27,     0,   417,   418,    30,   419,
     420,   421,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   422,   423,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   424,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   425,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   102,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   428,   112,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,     0,     0,     0,     0,     0,   128,     0,
     129,     0,   130,   131,   132,   133,   429,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   430,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   431,
     432,   433,   156,   434,   435,   159,   160,   161,   162,   163,
     164,   436,   166,   167,   437,   438,   439,   171,   440,   441,
     442,   175,   443,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     453,     0,     0,     0,     3,     0,     0,     0,     0,     0,
       0,   405,   406,     0,   407,   408,   409,   410,   411,   412,
      13,    14,    15,    16,    17,    18,   413,   414,   415,    22,
     416,    24,    25,    26,    27,     0,   417,   418,    30,   419,
     420,   421,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   422,   423,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   424,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   425,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   102,   454,     0,
       0,   455,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   428,   112,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,     0,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   429,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   430,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   431,
     432,   433,   156,   434,   435,   159,   160,   161,   162,   163,
     164,   436,   166,   167,   437,   438,   439,   171,   440,   441,
     442,   175,   443,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     453,     0,     0,     0,     3,     0,   677,     0,     0,     0,
       0,   405,   406,     0,   407,   408,   409,   410,   411,   412,
      13,    14,    15,    16,    17,    18,   413,   414,   415,    22,
     416,    24,    25,    26,    27,     0,   417,   418,    30,   419,
     420,   421,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   422,   423,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   424,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   425,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   102,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   428,   112,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,   678,   123,     0,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   429,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   430,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   431,
     432,   433,   156,   434,   435,   159,   160,   161,   162,   163,
     164,   436,   166,   167,   437,   438,   439,   171,   440,   441,
     442,   175,   443,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     453,     0,     0,     0,     3,     0,     0,     0,     0,     0,
       0,   405,   406,     0,   407,   408,   409,   410,   411,   412,
      13,    14,    15,    16,    17,    18,   413,   414,   415,    22,
     416,    24,    25,    26,    27,     0,   417,   418,    30,   419,
     420,   421,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   422,   423,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   424,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   425,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   102,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   428,   112,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,     0,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   429,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   430,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   431,
     432,   433,   156,   434,   435,   159,   160,   161,   162,   163,
     164,   436,   166,   167,   437,   438,   439,   171,   440,   441,
     442,   175,   443,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     486,     0,     3,     0,     0,     0,     0,     0,     0,   405,
     406,     0,   407,   408,   409,   410,   411,   412,    13,    14,
      15,    16,    17,    18,   413,   414,   415,    22,   416,    24,
      25,    26,    27,     0,   417,   418,    30,   419,   420,   421,
      34,    35,    36,    37,    38,    39,    40,    41,    42,   422,
     423,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    62,     0,
      63,    64,    65,   424,     0,     0,    69,    70,    71,     0,
       0,     0,    73,     0,     0,     0,     0,    75,    76,    77,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,   425,
      92,    93,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,     0,   100,   101,   102,     0,     0,     0,     0,
       0,     0,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   428,   112,   113,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,   122,     0,
     123,     0,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   429,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,     0,     0,   430,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   431,   432,   433,
     156,   434,   435,   159,   160,   161,   162,   163,   164,   436,
     166,   167,   437,   438,   439,   171,   440,   441,   442,   175,
     443,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,     3,     0,
       0,     0,     0,     0,     0,   405,   406,     0,   407,   408,
     409,   410,   411,   412,    13,    14,    15,    16,    17,    18,
     413,   414,   415,    22,   416,    24,    25,    26,    27,     0,
     417,   418,    30,   419,   420,   421,    34,    35,    36,    37,
      38,    39,    40,    41,    42,   422,   423,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    62,     0,    63,    64,    65,   424,
       0,     0,    69,    70,    71,     0,     0,     0,    73,     0,
       0,     0,     0,    75,    76,    77,     0,     0,    80,    81,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,   425,    92,    93,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,     0,   100,
     101,   102,   426,     0,     0,   427,     0,     0,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   428,   112,   113,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,     0,     0,     0,   122,     0,   123,     0,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     429,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,     0,     0,   430,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   431,   432,   433,   156,   434,   435,   159,
     160,   161,   162,   163,   164,   436,   166,   167,   437,   438,
     439,   171,   440,   441,   442,   175,   443,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,     3,     0,     0,     0,     0,     0,
       0,   405,   406,     0,   407,   408,   409,   410,   411,   412,
      13,    14,    15,    16,    17,    18,   413,   414,   415,    22,
     416,    24,    25,    26,    27,     0,   417,   418,    30,   419,
     420,   421,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   422,   423,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   424,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   425,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   102,   469,     0,
       0,   470,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   428,   112,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,     0,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   429,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   430,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   431,
     432,   433,   156,   434,   435,   159,   160,   161,   162,   163,
     164,   436,   166,   167,   437,   438,   439,   171,   440,   441,
     442,   175,   443,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
       3,     0,     0,     0,     0,     0,     0,   405,   406,     0,
     407,   408,   409,   410,   411,   412,    13,    14,    15,    16,
      17,    18,   413,   414,   415,    22,   416,    24,    25,    26,
      27,     0,   417,   418,    30,   419,   420,   421,    34,    35,
      36,    37,    38,    39,    40,    41,    42,   422,   423,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     0,     0,    62,     0,    63,    64,
      65,   424,     0,     0,    69,    70,    71,     0,     0,     0,
      73,     0,     0,     0,     0,    75,    76,    77,     0,     0,
      80,    81,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   425,    92,    93,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
       0,   100,   101,   102,     0,     0,     0,     0,     0,     0,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   428,
     112,   113,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,     0,     0,     0,   122,   660,   123,     0,
       0,     0,     0,     0,   661,     0,   129,     0,   130,   131,
     132,   133,   429,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,     0,     0,   430,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   431,   432,   433,   156,   434,
     435,   159,   160,   161,   162,   163,   164,   436,   166,   167,
     437,   438,   439,   171,   440,   441,   442,   175,   443,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,     3,     0,     0,     0,
       0,     0,     0,   405,   406,     0,   407,   408,   409,   410,
     411,   412,    13,    14,    15,    16,    17,    18,   413,   414,
     415,    22,   416,    24,    25,    26,    27,     0,   417,   418,
      30,   419,   420,   421,    34,    35,    36,    37,    38,    39,
      40,    41,    42,   422,   423,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
       0,     0,    62,     0,    63,    64,    65,   424,     0,     0,
      69,    70,    71,     0,     0,     0,    73,     0,     0,     0,
       0,    75,    76,    77,     0,     0,    80,    81,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,   425,    92,    93,     0,     0,     0,     0,
       0,     0,     0,    96,    97,    98,     0,   100,   101,   102,
       0,     0,     0,     0,     0,     0,   106,   107,     0,     0,
       0,     0,   108,   109,   110,   428,   112,   113,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   121,     0,
       0,     0,   122,   701,   123,     0,     0,     0,     0,     0,
     702,     0,   129,     0,   130,   131,   132,   133,   429,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,     0,
       0,   430,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   431,   432,   433,   156,   434,   435,   159,   160,   161,
     162,   163,   164,   436,   166,   167,   437,   438,   439,   171,
     440,   441,   442,   175,   443,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,     3,     0,     0,     0,     0,     0,     0,   405,
     406,     0,   407,   408,   472,   410,   473,   474,    13,    14,
      15,    16,    17,    18,   413,   414,   475,    22,   416,    24,
      25,    26,    27,     0,   417,   418,    30,   419,   420,   421,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    62,     0,
      63,    64,    65,   476,     0,     0,    69,    70,    71,     0,
       0,     0,    73,     0,     0,     0,     0,    75,    76,    77,
       0,     0,    80,    81,  1240,     0,     0,     0,     0,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,   425,
      92,    93,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,     0,   100,   101,   957,     0,     0,     0,     0,
       0,     0,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   428,   112,   113,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,   122,     0,
     123,   124,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   429,   135,   136,   137,   138,   139,
     140,     0,     0,   958,   142,     0,     0,   430,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   431,   154,   433,
     156,   434,   435,   159,   160,   161,   162,   163,   164,   436,
     166,   167,   437,   438,   439,   171,   440,   441,   442,   175,
     443,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,     3,     0,
       0,     0,     0,     0,     0,   405,   406,     0,   407,   408,
     472,   410,   473,   474,    13,    14,    15,    16,    17,    18,
     413,   414,   475,    22,   416,    24,    25,    26,    27,     0,
     417,   418,    30,   419,   420,   421,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    62,     0,    63,    64,    65,   476,
       0,     0,    69,    70,    71,     0,     0,     0,    73,     0,
       0,     0,     0,    75,    76,    77,     0,     0,    80,    81,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,   425,    92,    93,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,     0,   100,
     101,   957,     0,     0,     0,     0,     0,     0,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   428,   112,   113,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,     0,     0,     0,   122,     0,   123,   124,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     429,   135,   136,   137,   138,   139,   140,     0,     0,   958,
     142,     0,     0,   430,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   431,   154,   433,   156,   434,   435,   159,
     160,   161,   162,   163,   164,   436,   166,   167,   437,   438,
     439,   171,   440,   441,   442,   175,   443,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,     3,     0,     0,     0,     0,     0,
       0,   405,   406,     0,   407,   408,   472,   410,   473,   474,
      13,    14,    15,    16,    17,    18,   413,   414,   475,    22,
     416,    24,    25,    26,    27,     0,   417,   418,    30,   419,
     420,   421,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   476,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   425,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   957,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   428,   112,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,   124,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   429,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   430,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   431,
     154,   433,   156,   434,   435,   159,   160,   161,   162,   163,
     164,   436,   166,   167,   437,   438,   439,   171,   440,   441,
     442,   175,   443,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
       3,     0,     0,     0,     0,     0,     0,   405,   406,     0,
     407,   408,   409,   410,   411,   412,    13,    14,    15,    16,
      17,    18,   413,   414,   415,    22,   416,    24,    25,    26,
      27,     0,   417,   418,    30,   419,   420,   421,    34,    35,
      36,    37,    38,    39,    40,    41,    42,   422,   423,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     0,     0,    62,     0,    63,    64,
      65,   424,     0,     0,    69,    70,    71,     0,     0,     0,
      73,     0,     0,     0,     0,    75,    76,    77,     0,     0,
      80,    81,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   425,    92,    93,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
       0,   100,   101,   102,     0,     0,     0,     0,     0,     0,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   428,
     112,   113,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,     0,     0,     0,   122,     0,   123,     0,
       0,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   429,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,     0,     0,   430,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   431,   432,   433,   156,   434,
     435,   159,   160,   161,   162,   163,   164,   436,   166,   167,
     437,   438,   439,   171,   440,   441,   442,   175,   443,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         9,   562,   793,   566,   567,   568,   569,   370,   103,   708,
     790,   791,    21,   792,   793,   843,   520,   683,   116,   882,
     750,   687,   998,   127,   856,   919,    68,  1152,    20,   687,
     986,   772,    21,    34,    35,    36,    37,    38,    39,   542,
    1294,    60,   110,    88,     7,    46,   461,   545,    86,   547,
     548,    88,   550,    86,   552,    20,    30,    66,    86,    68,
     790,   791,   560,   561,   136,   132,   136,  1125,    20,    86,
      71,    88,    85,    82,    88,    99,   120,    99,   110,   494,
     495,   941,   497,   498,   499,   500,   120,    99,   451,   452,
     505,    65,   822,   508,   132,   104,   754,    99,   756,   136,
      99,    20,   103,   104,   105,    99,   521,   116,    99,   118,
     102,  1163,  1164,   121,    86,   124,   531,   532,    99,   136,
      30,   126,   114,   853,    34,   206,   110,   142,   105,    98,
     145,    53,   286,     4,   313,   145,   157,     8,   292,    88,
     319,   185,   174,    86,    58,    59,   138,    25,   117,   147,
     142,   185,   176,   145,     8,     9,   157,   179,   171,    86,
    1020,    71,   828,    41,   136,   246,   164,   179,    86,   190,
      30,   179,    32,    33,    88,    99,   149,    99,   593,    99,
     179,   175,    42,   198,   189,   176,   105,   206,    98,   190,
     262,   175,   262,   226,   175,   262,   145,   149,   226,   142,
     163,   175,   306,   248,   249,    65,    66,   768,   769,   136,
     175,     8,     9,   202,  1042,   260,   915,  1471,  1081,  1277,
      86,  1115,   224,   291,   262,   262,   142,   246,  1060,    89,
     149,  1125,   898,  1487,   248,   249,    99,   145,   896,   240,
    1494,    95,   113,    92,   115,   262,  1202,   988,   158,  1301,
    1226,   175,   123,   756,    20,   175,   619,   189,  1383,   113,
     252,   115,     8,   110,   241,   763,   198,   210,   211,   311,
     279,   142,   314,    19,   275,   276,   277,   278,   279,   377,
     281,   282,   283,   284,   285,  1065,   287,    99,   142,   207,
     208,   142,   146,   270,   271,    43,   273,   274,    95,    99,
     155,   399,   311,     8,   222,   314,   401,   126,   162,   404,
     142,   674,   175,   971,    19,   170,   113,   177,   115,   127,
     139,     4,    99,    99,  1054,     8,   258,    88,  1058,   183,
     745,   426,   264,   165,   142,  1065,   102,   752,     8,     9,
     272,   207,   208,   110,   105,   142,   127,   201,   114,   146,
     445,   446,   361,   448,   214,   450,   222,   455,   367,   454,
      99,   142,    54,   175,   373,   162,    99,   113,   377,   115,
     110,   119,   138,   382,   469,   175,   142,   226,   124,   145,
     389,    99,   142,  1277,   145,   145,   183,   109,   189,   484,
     399,   400,   241,    92,    26,   490,   142,   198,   175,   175,
    1232,   157,     8,     9,   201,   254,   105,   256,   113,   824,
     115,    56,    57,   135,   509,   830,    48,   266,   427,   124,
     269,    86,  1398,   984,   987,    95,   148,   362,   180,   181,
     113,   366,   115,  1213,   190,   996,   175,   142,    45,   137,
     123,   945,   175,   113,    51,   115,   455,    54,    55,   458,
     459,   460,   134,  1416,  1417,    62,   154,   175,   467,   142,
     182,   470,   127,   237,   238,   110,   110,   132,   831,   832,
     157,   480,   142,   836,   889,   890,   146,   892,  1441,   894,
     584,   585,   164,  1213,  1447,   259,   581,   145,   137,    95,
     214,   586,   162,   502,   170,   219,  1359,   860,   145,   914,
     182,   510,   867,   190,   869,   154,  1236,   113,   184,   115,
     925,   926,   927,   183,   929,   930,   931,   932,   933,   934,
    1352,   936,   937,   142,    88,   281,   282,   283,   284,   285,
     147,   201,   142,   948,    58,    59,   142,    61,   204,   142,
     146,   105,   145,   908,   170,   910,  1212,   164,    87,   819,
    1330,   158,   967,   160,   969,   970,   162,   214,   184,    98,
     127,   656,   657,   833,    88,   132,   145,   174,   663,   108,
     187,  1403,   670,   110,   241,   673,  1275,   183,   117,   258,
     239,  1280,   142,   242,   263,   680,   110,   596,   275,   276,
     277,   278,   279,   200,   227,   201,  1011,   127,   239,  1427,
    1330,   242,   132,   270,   271,   614,   273,   274,   258,   704,
     187,   231,   189,  1404,   264,   214,  1031,   216,    34,    35,
      36,   198,   272,    39,  1187,  1404,   118,   119,  1334,  1409,
     231,  1194,  1195,  1339,   643,   730,   145,   646,    88,   279,
     280,   650,    92,   587,   142,  1206,   590,  1479,   592,   210,
     211,   212,   110,  1485,   281,   282,   283,   284,   285,     0,
    1075,   670,   179,   214,   673,   216,   179,   221,  1500,   223,
     156,  1370,   767,  1088,   221,  1374,   223,  1092,  1093,  1409,
    1095,    84,   691,    58,    59,  1100,   251,    34,    35,    36,
      37,    38,    39,   281,   282,   283,   284,   285,   707,    46,
     118,   119,   364,   365,    68,    52,   188,   157,   570,   571,
     563,   564,    93,  1076,   572,   573,    63,    64,  1332,  1333,
      67,  1420,    94,    70,    71,   145,   143,    34,    34,    20,
      88,   141,   110,   281,    92,   744,   288,   142,   142,   175,
    1155,   750,   142,   175,   142,   268,   268,   110,   110,   142,
     145,  1166,  1315,  1316,   145,   145,   103,   104,   105,   145,
     145,   175,    27,    15,  1179,   202,   861,  1182,   175,  1184,
      20,   220,    25,   175,   158,   110,   226,   159,    99,   159,
     220,   790,   791,   792,   793,    86,    86,    86,   145,    20,
      99,   241,   117,   243,   244,   245,  1159,    99,   149,   157,
     149,    20,   149,   253,   254,   122,   256,   286,   122,   142,
     157,   261,   172,   822,   175,    88,   266,   267,   268,   269,
     172,   175,   172,    30,   172,    88,   172,   172,  1391,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,   175,
     132,   175,    99,   190,   172,   175,   175,  1262,   175,  1264,
     172,    86,   172,   172,   132,  1270,   226,   175,   867,   214,
     869,   172,   209,   179,   159,   110,   110,   136,   226,  1284,
    1285,  1286,  1287,  1288,   110,  1290,  1291,   110,   252,   250,
     269,   257,   172,   241,   173,   243,   244,   245,   122,    86,
    1253,   132,   132,   240,   271,    86,   254,  1312,   256,   908,
     172,   910,   172,   261,   272,   272,    92,   286,   266,   267,
     268,   269,   142,   172,   122,   186,   122,   149,    88,   142,
     110,   172,   136,  1018,   142,   110,   172,   132,   275,   276,
     277,   278,   279,   246,   281,   282,   283,   284,   285,  1354,
     287,  1356,  1305,  1358,   953,   122,    27,   956,    20,   110,
     172,   235,   110,   130,   131,   964,   133,   966,   142,    71,
      99,    99,   145,   140,   145,   136,   175,   144,   136,   146,
     172,   247,   247,  1068,   151,   272,   136,    47,   134,    86,
      20,    20,   275,   159,   272,   290,    86,   216,  1083,   216,
     167,   179,   172,   175,   134,    99,   175,   175,   132,   136,
     175,   110,   110,    61,  1013,   122,   175,     6,   175,   222,
     222,   222,  1107,   179,   191,   192,   193,   194,   195,   196,
     174,  1436,   222,   226,    98,    98,  1121,   132,   175,   175,
     136,   110,    86,    20,    20,   159,   172,   265,   116,   249,
     172,   174,  1457,    88,   172,  1460,   172,   172,    20,   172,
      88,   255,    99,    86,   275,    86,  1065,    59,   185,   110,
     174,   214,   110,   185,   185,  1480,   255,   110,    85,   289,
     214,   174,   171,   110,   185,   110,  1085,   142,   293,   275,
     110,  1090,   175,   214,   110,   187,   235,   232,   238,   290,
     289,   519,  1101,   235,   519,   293,  1027,   618,   823,   393,
     858,   375,  1352,  1403,   805,  1148,  1214,   903,   395,   239,
     523,   956,  1090,  1122,   278,  1268,  1102,  1156,  1168,   948,
    1166,  1431,  1163,  1085,   480,  1066,   565,   299,   543,   303,
    1115,  1447,   544,   708,  1143,  1441,   822,   468,   869,  1026,
    1143,   984,   468,  1152,   768,  1206,  1153,  1156,   996,   988,
    1344,   769,  1225,  1201,   985,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1213,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1233,    -1,    -1,    -1,    -1,    -1,
      -1,  1240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1265,  1266,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1276,    -1,    -1,
      -1,    -1,  1281,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1330,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1355,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1371,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1383,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1404,  1405,    -1,  1407,    -1,
    1409,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1423,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1437,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1458,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1475,    -1,  1477,    -1,
      -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,
    1489,    -1,    17,    18,  1493,    20,    -1,    -1,    -1,  1498,
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
     170,    -1,    -1,    -1,   174,   175,   176,   177,   178,    -1,
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
     290,   291,   292,   293,    10,    -1,    -1,    -1,    -1,    -1,
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
     286,   287,   288,   289,   290,   291,   292,   293,    10,    -1,
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
     292,   293,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
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
     288,   289,   290,   291,   292,   293,    10,    -1,    -1,    -1,
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
     290,   291,   292,   293,    10,    -1,    -1,    -1,    -1,    -1,
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
     286,   287,   288,   289,   290,   291,   292,   293,    10,    -1,
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
     292,   293,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
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
     288,   289,   290,   291,   292,   293,    10,    -1,    -1,    -1,
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
     290,   291,   292,   293,    10,    -1,    -1,    -1,    -1,    -1,
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
     286,   287,   288,   289,   290,   291,   292,   293,    10,    -1,
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
     292,   293,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
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
     288,   289,   290,   291,   292,   293,    10,    -1,    -1,    -1,
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
     290,   291,   292,   293,    10,    -1,    -1,    -1,    -1,    -1,
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
     286,   287,   288,   289,   290,   291,   292,   293,    10,    -1,
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
     292,   293,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
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
      -1,    -1,   170,    -1,    -1,    -1,   174,    -1,   176,   177,
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
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,    10,    -1,    -1,    -1,
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
     244,   245,   246,   247,   248,   249,    -1,   251,   252,    -1,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
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
     286,   287,   288,   289,   290,   291,   292,   293,    18,    -1,
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
     290,   291,   292,   293,    18,    -1,    -1,    -1,    -1,    -1,
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
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,    18,    -1,    -1,    -1,
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
     292,   293,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      26,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    -1,    -1,    84,    -1,
      86,    87,    88,    89,    -1,    -1,    92,    93,    94,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,   103,   104,   105,
      -1,    -1,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,
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
     286,   287,   288,   289,   290,   291,   292,   293,    18,    -1,
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
     290,   291,   292,   293,    18,    -1,    -1,    -1,    -1,    -1,
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
     244,   245,   246,   247,   248,   249,    -1,   251,   252,    -1,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
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
     288,   289,   290,   291,   292,   293
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
     292,   293,   294,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   340,   341,
     346,   347,   351,   356,   357,   359,   364,   365,   366,   367,
     368,   376,   377,   379,   380,   381,   386,   388,   390,   391,
     392,   397,   418,   421,   424,   425,   426,   427,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   474,   475,
     476,   490,   491,   493,   494,   495,   496,   497,   498,   499,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     518,   519,   520,   521,   522,   523,   524,   527,   533,   534,
     535,    34,    35,    36,    37,    38,    39,    46,    52,    63,
      64,    67,    70,    71,   103,   104,   105,   149,   157,   190,
     209,   240,   275,   276,   277,   278,   279,   281,   282,   283,
     284,   285,   287,   348,   349,   352,   353,   369,   370,   149,
      86,   142,   210,   211,   145,    25,    26,    28,    29,    30,
      31,    32,    33,    40,    41,    42,    44,    50,    51,    53,
      54,    55,    65,    66,    89,   125,   142,   145,   157,   190,
     203,   213,   214,   215,   217,   218,   225,   228,   229,   230,
     232,   233,   234,   236,   533,   142,   142,   145,   142,   145,
     145,    26,    48,    14,   142,   145,   532,   533,   110,   110,
     110,   142,    56,    57,   110,   383,    54,   145,   145,   142,
     145,   533,    30,    32,    33,    42,    89,   458,   533,   533,
     110,   175,   377,   533,   142,   532,    16,   533,   533,   450,
     142,    21,   202,   204,   214,   216,   145,   214,   216,   214,
     214,   219,   110,   142,   360,   227,   231,   231,   145,   142,
     110,   311,     0,   313,   314,    25,    41,   316,   376,   179,
     179,    99,   179,   378,    45,    51,    54,    55,    62,   158,
     160,   174,   200,   382,   387,   388,   389,   406,   407,   411,
     393,   394,   533,   156,    84,   122,   130,   131,   133,   140,
     144,   146,   151,   167,   191,   192,   193,   194,   195,   196,
     442,   443,   251,   147,   164,   187,   109,   135,   148,   182,
     189,   198,   126,   139,    68,   188,    93,    94,   147,   164,
     441,   142,   447,   450,   180,   181,   143,   462,   463,   458,
     462,   458,   462,   145,   533,   370,    34,   371,   369,   369,
     370,   533,   170,   184,   157,   190,    20,   531,   155,   170,
     170,   184,   533,   141,   110,   345,    30,    34,    71,    98,
     158,   532,   210,   211,   212,    92,   226,   241,   254,   256,
     266,   269,   547,   548,   549,   550,   551,   554,   559,   560,
     533,   281,   533,   288,   157,   190,   275,   349,   157,   190,
     283,   353,   532,   516,   533,   377,   142,   142,   377,   377,
     175,   182,   533,   142,   377,   377,   175,   377,   175,   377,
     149,   531,   105,   149,   339,   531,   377,    20,   175,   532,
     142,   419,   420,   533,   533,   398,   400,   533,   380,   268,
     268,   110,   401,   110,   533,    30,    65,   175,   514,   515,
     377,   175,   182,   533,   142,   419,   175,    27,   478,   479,
     480,   377,     7,   163,    15,   175,   377,   202,    20,   380,
     380,   175,   380,   380,   380,   380,   220,   525,   526,   533,
     361,   380,   380,   377,   399,   405,   533,   318,   319,    25,
     320,   380,   379,   158,   110,   159,   159,   380,   380,    99,
      86,    88,   136,   262,   395,   396,   501,   426,   427,   429,
     429,   429,   429,   428,   429,   429,   429,   142,   145,   252,
     465,   536,   538,   539,   540,   541,   542,   543,   544,   432,
     432,   431,   433,   433,   433,   433,   434,   434,   435,   435,
     220,    86,    86,    86,   172,   377,   450,   450,   377,   463,
     175,   380,   473,   145,   358,   533,    20,    99,    99,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,   322,
     323,   324,    86,   127,   132,   342,   343,   344,   533,   127,
     132,   149,   149,   322,   531,   117,   122,   239,   242,   105,
     241,   270,   271,   273,   274,   239,   242,    20,   241,   270,
     271,   273,   274,    86,   226,   350,   286,   533,   533,   533,
     122,   142,   172,   377,   377,   175,   172,    99,   175,    99,
     175,   172,   377,   172,   172,   172,   175,   532,    88,    30,
     532,   531,    88,   172,   175,   175,   172,   377,    99,   176,
     136,   501,   132,    99,   132,   396,   501,   172,   533,    60,
     206,   246,   384,   385,   175,   175,   175,   172,    99,   175,
      99,   175,   172,   377,   176,   533,   479,   480,   120,   185,
     172,   172,   121,   179,    86,   207,   208,   222,    86,   207,
     208,   222,    86,   226,   214,    99,   224,   132,    25,   362,
     377,   175,   172,    53,    99,   179,   105,   179,   159,   533,
     380,   412,   413,   110,   408,   409,   110,   141,   199,   502,
     504,   505,   506,   533,   110,   380,   110,   136,   396,   136,
     136,   395,   396,   429,   377,   536,   542,   269,   570,    88,
     157,   243,   244,   245,   253,   261,   267,   268,   537,   545,
     546,   547,   561,   564,   565,   567,   250,   252,   257,   566,
     237,   238,   259,   562,   502,   502,   500,   505,   500,   172,
     173,    99,   175,   110,   175,   372,   373,   127,   142,   375,
     358,   137,   154,   137,   154,   323,   122,   504,   344,   380,
     501,   132,   380,   531,   531,   118,   119,   531,   271,   272,
      88,   105,   145,   553,   272,    32,    33,    42,    66,    89,
     214,   506,   279,   280,    86,   448,   286,   292,    86,   350,
     286,   531,   377,   172,   172,    92,   422,   423,   142,   516,
     517,   533,   516,   517,   172,   186,   122,   338,   531,   149,
     122,    88,   338,   142,   172,   110,   380,   380,   136,   380,
     110,   380,   132,   132,   396,   136,   501,   246,    58,    59,
      61,   110,   395,   402,   403,   404,   385,   142,   516,   516,
     172,   380,    27,   480,   120,   185,     8,     9,    95,   113,
     115,   142,   183,   374,   475,   477,   488,   489,   492,    20,
     221,   223,   380,   380,   380,   221,   223,   380,   380,   380,
     380,   380,   380,   110,   380,   380,   345,   363,    99,   179,
     172,   360,   235,   528,   529,   142,   110,   412,    87,    98,
     108,   117,   414,   415,   416,   417,    99,   533,    99,   394,
     145,   145,   134,   164,   182,   503,   533,   533,   380,   136,
     380,   380,   136,   396,   136,   172,   175,   247,   206,   246,
     258,   263,   569,    88,   248,   249,   563,   247,   539,   569,
     430,   433,   267,   545,   547,   540,   136,   563,   272,    47,
     134,   380,   533,    86,    99,   175,   377,   127,   360,   518,
     343,   380,   272,    88,   145,   556,    20,   105,   553,   216,
     216,   506,   159,   275,   290,   506,    86,   448,   179,   172,
     110,   502,   105,   423,   172,   377,   175,   175,   134,   175,
     175,   380,   531,    99,   338,   172,   377,   420,   380,   400,
     380,   380,   132,   380,   136,   110,   110,   380,   533,   404,
      61,   172,   377,   175,   175,   122,   183,   477,     6,   377,
     533,   183,   488,   179,   222,   222,   222,   222,   226,   526,
     174,   132,   363,   459,   530,   529,   380,   405,   531,   118,
     119,   416,   417,   417,   413,    98,   410,   409,   175,   175,
     380,   380,   136,   380,   433,    43,   119,   433,   433,   258,
     264,   272,   568,   568,   430,   541,   265,   501,   502,   373,
      86,   172,   126,   189,   555,   558,    20,    20,   557,   555,
     260,   563,    99,   175,    99,   175,   354,   355,   448,   533,
     249,   506,   159,   533,   174,   110,   174,   172,   116,    88,
     531,   172,   380,   380,   533,   533,   403,   380,   172,   480,
     533,   183,   172,   480,   533,   380,   380,   380,   380,   380,
     380,   380,   145,   198,   375,   172,   417,   531,   380,   433,
     433,   187,   502,   556,   556,   558,    20,   175,    20,   255,
     552,   553,   552,    99,    86,   110,   291,   275,   354,    86,
     380,   533,   380,   380,   338,    59,    85,   171,   481,   480,
     533,   185,   480,   110,   459,   433,   563,    99,   175,   175,
     355,   500,   533,   214,   533,   502,   174,   110,     4,   123,
     484,   485,   487,   489,    19,   124,   482,   483,   486,   489,
     185,   480,   185,   533,   255,   553,   414,   289,   110,   214,
     174,   380,   533,    85,   123,   487,   171,   124,   486,   185,
      99,   175,   281,   380,   533,   110,   380,   110,   375,   290,
     289,   533,   533,   448,   380,   293,    99,   175,   448,   110,
     375,   187,   533,   275,   175,   533,   375,   214,   110,   533,
     293,   448
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
     555,   556,   557,   558,   559,   560,   561,   562,   563
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   309,   310,   310,   311,   311,   311,   311,   312,   312,
     313,   313,   314,   314,   315,   316,   316,   316,   317,   317,
     318,   318,   319,   319,   319,   319,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   321,   321,   322,   322,   323,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     325,   325,   325,   325,   325,   325,   325,   325,   326,   326,
     327,   328,   328,   329,   329,   330,   331,   332,   332,   333,
     333,   334,   334,   334,   334,   335,   336,   337,   337,   337,
     337,   338,   338,   339,   339,   340,   340,   340,   340,   341,
     342,   342,   343,   343,   343,   344,   345,   345,   346,   346,
     346,   347,   347,   347,   347,   347,   347,   347,   347,   348,
     348,   349,   349,   349,   349,   349,   349,   350,   350,   351,
     351,   352,   352,   353,   353,   353,   353,   353,   353,   354,
     354,   355,   355,   356,   356,   356,   356,   357,   357,   358,
     358,   358,   358,   359,   360,   361,   361,   362,   362,   363,
     363,   364,   365,   366,   367,   367,   368,   368,   368,   369,
     369,   369,   369,   370,   370,   371,   371,   372,   372,   373,
     373,   374,   375,   376,   377,   377,   378,   378,   379,   379,
     380,   380,   380,   380,   380,   380,   380,   380,   380,   380,
     380,   380,   380,   380,   380,   380,   380,   381,   382,   383,
     383,   384,   384,   384,   385,   385,   386,   386,   387,   388,
     388,   388,   389,   389,   389,   389,   389,   390,   390,   391,
     391,   392,   393,   393,   394,   394,   394,   394,   394,   394,
     394,   394,   395,   396,   397,   398,   398,   399,   399,   400,
     400,   400,   400,   401,   401,   402,   402,   402,   403,   403,
     403,   404,   404,   404,   405,   406,   407,   408,   408,   409,
     409,   410,   411,   411,   412,   412,   413,   413,   414,   414,
     414,   414,   414,   414,   414,   415,   415,   416,   416,   417,
     418,   418,   419,   419,   420,   420,   421,   421,   422,   422,
     423,   423,   424,   425,   425,   426,   426,   427,   427,   427,
     427,   427,   428,   427,   427,   427,   427,   429,   429,   429,
     430,   430,   431,   431,   431,   432,   432,   432,   432,   432,
     433,   433,   433,   434,   434,   434,   435,   435,   436,   436,
     437,   437,   438,   438,   439,   439,   440,   440,   440,   440,
     441,   441,   441,   442,   442,   442,   442,   442,   442,   443,
     443,   443,   444,   444,   444,   444,   445,   445,   446,   446,
     447,   447,   448,   448,   448,   448,   449,   450,   450,   450,
     451,   451,   452,   452,   452,   452,   453,   453,   454,   454,
     454,   454,   454,   454,   454,   455,   455,   456,   456,   457,
     457,   457,   457,   457,   458,   458,   459,   459,   460,   460,
     460,   461,   461,   462,   462,   463,   464,   464,   464,   464,
     464,   464,   464,   464,   465,   465,   466,   466,   466,   467,
     468,   468,   469,   470,   471,   472,   472,   473,   473,   474,
     474,   475,   475,   475,   476,   476,   476,   476,   476,   476,
     477,   477,   478,   478,   479,   480,   480,   481,   481,   482,
     482,   483,   483,   483,   483,   484,   484,   485,   485,   485,
     485,   486,   486,   487,   487,   488,   488,   488,   488,   489,
     489,   489,   489,   490,   490,   491,   491,   492,   493,   493,
     493,   493,   493,   493,   494,   495,   495,   495,   495,   496,
     496,   496,   496,   497,   498,   499,   499,   499,   499,   500,
     500,   501,   502,   502,   502,   503,   503,   503,   504,   504,
     504,   505,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   507,   508,   508,   508,   509,   510,   511,   511,   511,
     512,   512,   512,   512,   512,   513,   514,   514,   514,   514,
     514,   514,   514,   515,   516,   517,   518,   519,   519,   519,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     521,   521,   522,   522,   523,   524,   525,   525,   526,   527,
     528,   528,   529,   529,   529,   529,   530,   530,   531,   532,
     532,   533,   533,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     535,   535,   536,   536,   536,   536,   537,   537,   537,   537,
     538,   538,   539,   539,   540,   540,   541,   541,   542,   542,
     542,   543,   543,   544,   544,   545,   545,   545,   545,   545,
     546,   547,   547,   547,   547,   547,   547,   547,   548,   548,
     548,   548,   549,   549,   549,   549,   550,   550,   551,   551,
     551,   551,   551,   551,   551,   552,   552,   553,   553,   553,
     553,   554,   554,   554,   554,   554,   555,   555,   556,   556,
     557,   557,   558,   558,   559,   560,   560,   561,   561,   561,
     562,   562,   562,   562,   562,   563,   563,   563,   563,   564,
     565,   566,   567,   567,   568,   568,   568,   569,   569,   570
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
       3,     3,     4,    11,    13,    13,    22,     3,     3,     2,
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
       7,     4,     1,     2,     3,     4,     1,     1,     2,     2,
       1,     3,     1,     3,     1,     4,     1,     2,     1,     2,
       3,     1,     2,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     3,     3,
       5,     7,     5,     7,     2,     1,     3,     2,     4,     4,
       6,     4,     5,     4,     5,     3,     1,     2,     2,     3,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     2,     1,     2,     1,     2,     3,     3,     4,     3,
       3,     3,     2,     2,     1,     1,     1,     1,     1,     3
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
  "\"'manual'\"", "\"'automatic'\"", "\"'on'\"", "\"'integrity'\"",
  "\"'constraint'\"", "\"'check'\"", "\"'key'\"", "\"'foreach'\"",
  "\"'foreign'\"", "\"'keys'\"", "\"'BOM_UTF8'\"", "FTCONTAINS_REDUCE",
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
  "VarNameAndType", "VarDecl", "CollectionDecl", "CollPropertyList",
  "CollProperty", "NodeModifier", "IndexDecl", "IndexPropertyList",
  "IndexProperty", "IndexKeyList", "IndexKeySpec",
  "IntegrityConstraintDecl", "ConstructionDecl", "FunctionSig",
  "BlockExpr", "Block", "BlockDecls", "BlockVarDeclList", "BlockVarDecl",
  "AssignExpr", "ExitExpr", "WhileExpr", "FlowCtlStatement",
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
       310,     0,    -1,   311,    -1,   294,   311,    -1,   313,    -1,
     312,   313,    -1,   314,    -1,   312,   314,    -1,   203,   204,
      20,   179,    -1,   203,   204,    20,   121,    20,   179,    -1,
     316,   376,    -1,   376,    -1,   315,    -1,   315,   316,    -1,
      26,   149,   532,   122,   531,   179,    -1,   317,   179,    -1,
     318,   179,    -1,   317,   179,   318,   179,    -1,   319,    -1,
     317,   179,   319,    -1,   320,    -1,   318,   179,   320,    -1,
     325,    -1,   326,    -1,   327,    -1,   329,    -1,   346,    -1,
     341,    -1,   368,    -1,   330,    -1,   331,    -1,   347,    -1,
     351,    -1,   356,    -1,   321,    -1,    25,   105,    71,   322,
      -1,    25,    71,   533,   322,    -1,   323,    -1,   322,   323,
      -1,   324,   122,   518,    -1,    72,    -1,    73,    -1,    74,
      -1,    75,    -1,    76,    -1,    77,    -1,    78,    -1,    79,
      -1,    80,    -1,    81,    -1,   328,    -1,   335,    -1,   336,
      -1,   357,    -1,   332,    -1,   333,    -1,   334,    -1,   519,
      -1,   337,    -1,   340,    -1,    25,   149,   532,   122,   531,
      -1,    25,    70,   170,    -1,    25,    70,   184,    -1,    25,
     105,    30,   149,   531,    -1,    25,   105,    34,   149,   531,
      -1,    25,    46,   533,    20,    -1,    25,   240,   547,    -1,
      25,    63,   157,    -1,    25,    63,   190,    -1,    25,   105,
     158,   117,   118,    -1,    25,   105,   158,   117,   119,    -1,
      25,    67,   170,    99,   137,    -1,    25,    67,   170,    99,
     154,    -1,    25,    67,   155,    99,   137,    -1,    25,    67,
     155,    99,   154,    -1,    25,   105,    98,   531,    -1,    25,
      64,   531,    -1,    41,    48,   531,    -1,    41,    48,   339,
     531,    -1,    41,    48,   531,    88,   338,    -1,    41,    48,
     339,   531,    88,   338,    -1,   531,    -1,   338,    99,   531,
      -1,   149,   532,   122,    -1,   105,    30,   149,    -1,    41,
      26,   531,    -1,    41,    26,   149,   532,   122,   531,    -1,
      41,    26,   531,    88,   338,    -1,    41,    26,   149,   532,
     122,   531,    88,   338,    -1,    25,   103,   141,   342,    -1,
      86,   504,   343,    -1,   343,    -1,   344,    -1,   127,    -1,
     127,   344,    -1,   132,   380,    -1,   110,   533,    -1,   110,
     533,   501,    -1,    25,   104,   345,   132,   380,    -1,    25,
     104,   345,   127,    -1,    25,   104,   345,   127,   132,   380,
      -1,    25,   275,   533,    -1,    25,   275,   533,   350,    -1,
      25,   275,   533,    86,   506,    -1,    25,   275,   533,   350,
      86,   506,    -1,    25,   348,   275,   533,    -1,    25,   348,
     275,   533,   350,    -1,    25,   348,   275,   533,    86,   506,
      -1,    25,   348,   275,   533,   350,    86,   506,    -1,   349,
      -1,   348,   349,    -1,   276,    -1,   277,    -1,   278,    -1,
     279,    -1,   157,    -1,   190,    -1,   226,   280,   216,    -1,
     226,   279,   216,    -1,    25,   283,   533,   286,   448,   159,
     354,    -1,    25,   352,   283,   533,   286,   448,   159,   354,
      -1,   353,    -1,   352,   353,    -1,   157,    -1,   190,    -1,
     281,    -1,   282,   281,    -1,   285,    -1,   284,    -1,   355,
      -1,   354,    99,   355,    -1,   448,    86,   500,    -1,   448,
      86,   500,   414,    -1,    25,   287,   288,   533,   286,   275,
     533,   110,   533,   289,   380,    -1,    25,   287,   288,   533,
     286,   275,   533,   110,   533,   289,   281,   290,   448,    -1,
      25,   287,   288,   533,   286,   275,   533,   291,   214,   110,
     533,   289,   380,    -1,    25,   287,   288,   533,   292,   290,
     249,   275,   533,   214,   110,   533,   293,   448,   187,   275,
     533,   214,   110,   533,   293,   448,    -1,    25,    52,   170,
      -1,    25,    52,   184,    -1,   145,   175,    -1,   145,   372,
     175,    -1,   145,   175,    86,   502,    -1,   145,   372,   175,
      86,   502,    -1,   228,   360,    -1,   142,   361,   377,   172,
      -1,   361,   362,   179,    -1,    -1,   362,    99,   363,    -1,
      25,   363,    -1,   345,    -1,   345,   132,   380,    -1,    50,
     110,   533,   132,   380,    -1,   229,   227,   380,    -1,   233,
     145,   380,   175,   360,    -1,   230,   231,    -1,   232,   231,
      -1,    25,   369,    -1,    25,    38,   369,    -1,    25,    37,
     369,    -1,   370,    -1,    39,   370,    -1,    35,   370,    -1,
      36,   371,    -1,    34,   533,   358,   375,    -1,    34,   533,
     358,   127,    -1,    34,   533,   358,   360,    -1,    34,   533,
     358,   127,    -1,   373,    -1,   372,    99,   373,    -1,   110,
     533,    -1,   110,   533,   501,    -1,   142,   377,   172,    -1,
     142,   377,   172,    -1,   377,    -1,   379,    -1,   379,   378,
      -1,   179,    -1,   378,   379,   179,    -1,   380,    -1,   379,
      99,   380,    -1,   381,    -1,   418,    -1,   421,    -1,   424,
      -1,   425,    -1,   520,    -1,   521,    -1,   523,    -1,   522,
      -1,   524,    -1,   527,    -1,   535,    -1,   365,    -1,   366,
      -1,   367,    -1,   364,    -1,   359,    -1,   390,   382,    -1,
     174,   380,    -1,    56,   268,    -1,    57,   268,    -1,   206,
      -1,   246,    -1,    60,   246,    -1,   384,   402,    61,   380,
      -1,   384,    61,   380,    -1,    54,   383,   401,   385,   385,
      -1,    54,   383,   401,   385,    -1,    62,   110,   533,    -1,
     392,    -1,   397,    -1,   386,    -1,   388,    -1,   406,    -1,
     411,    -1,   407,    -1,   387,    -1,   388,    -1,   390,   389,
      -1,    54,   110,    -1,    55,    54,   110,    -1,   391,   393,
      -1,   394,    -1,   393,    99,   110,   394,    -1,   533,   136,
     380,    -1,   533,   501,   136,   380,    -1,   533,   395,   136,
     380,    -1,   533,   501,   395,   136,   380,    -1,   533,   396,
     136,   380,    -1,   533,   501,   396,   136,   380,    -1,   533,
     395,   396,   136,   380,    -1,   533,   501,   395,   396,   136,
     380,    -1,    88,   110,   533,    -1,   262,   110,   533,    -1,
      51,   110,   398,    -1,   400,    -1,   398,    99,   110,   400,
      -1,   405,    -1,   399,    99,   110,   405,    -1,   533,   132,
     380,    -1,   533,   501,   132,   380,    -1,   533,   396,   132,
     380,    -1,   533,   501,   396,   132,   380,    -1,   110,   533,
     136,   380,    -1,   110,   533,   501,   136,   380,    -1,   403,
      -1,   110,   533,    -1,   110,   533,   403,    -1,   395,    -1,
     395,   404,    -1,   404,    -1,    58,   110,   533,    59,   110,
     533,    -1,    59,   110,   533,    -1,    58,   110,   533,    -1,
     533,    -1,   200,   380,    -1,   160,   159,   408,    -1,   409,
      -1,   408,    99,   409,    -1,   110,   533,    -1,   110,   533,
     410,    -1,    98,   531,    -1,   158,   159,   412,    -1,    45,
     158,   159,   412,    -1,   413,    -1,   412,    99,   413,    -1,
     380,    -1,   380,   414,    -1,   415,    -1,   416,    -1,   417,
      -1,   415,   416,    -1,   415,   417,    -1,   416,   417,    -1,
     415,   416,   417,    -1,    87,    -1,   108,    -1,   117,   118,
      -1,   117,   119,    -1,    98,   531,    -1,    44,   110,   419,
     176,   380,    -1,   125,   110,   419,   176,   380,    -1,   420,
      -1,   419,    99,   110,   420,    -1,   533,   136,   380,    -1,
     533,   501,   136,   380,    -1,    29,   145,   377,   175,   422,
     105,   174,   380,    -1,    29,   145,   377,   175,   422,   105,
     110,   533,   174,   380,    -1,   423,    -1,   422,   423,    -1,
      92,   502,   174,   380,    -1,    92,   110,   533,    86,   502,
     174,   380,    -1,    40,   145,   377,   175,   186,   380,   116,
     380,    -1,   426,    -1,   425,   156,   426,    -1,   427,    -1,
     426,    84,   427,    -1,   429,    -1,   429,   442,   429,    -1,
     429,   443,   429,    -1,   429,   122,   429,    -1,   429,   151,
     429,    -1,    -1,   429,   146,   428,   429,    -1,   429,   144,
     429,    -1,   429,   133,   429,    -1,   429,   131,   429,    -1,
     430,    -1,   430,   251,   536,    -1,   430,   251,   536,   570,
      -1,   431,    -1,   431,   187,   431,    -1,   432,    -1,   431,
     164,   432,    -1,   431,   147,   432,    -1,   433,    -1,   432,
     182,   433,    -1,   432,   109,   433,    -1,   432,   135,   433,
      -1,   432,   148,   433,    -1,   434,    -1,   433,   189,   434,
      -1,   433,   198,   434,    -1,   435,    -1,   434,   139,   435,
      -1,   434,   126,   435,    -1,   436,    -1,   436,    68,   220,
     502,    -1,   437,    -1,   437,   188,    86,   502,    -1,   438,
      -1,   438,    93,    86,   500,    -1,   439,    -1,   439,    94,
      86,   500,    -1,   441,    -1,   440,   441,    -1,   164,    -1,
     147,    -1,   440,   164,    -1,   440,   147,    -1,   444,    -1,
     448,    -1,   445,    -1,   191,    -1,   196,    -1,   195,    -1,
     194,    -1,   193,    -1,   192,    -1,   140,    -1,   167,    -1,
     130,    -1,    28,   142,   377,   172,    -1,    28,   211,   142,
     377,   172,    -1,    28,   210,   142,   377,   172,    -1,    28,
      86,   516,   142,   377,   172,    -1,   446,   142,   172,    -1,
     446,   142,   377,   172,    -1,   447,    -1,   446,   447,    -1,
     165,   533,    15,    -1,   165,    16,    -1,   449,    -1,   449,
     450,    -1,   181,   450,    -1,   450,    -1,   180,    -1,   451,
      -1,   451,   180,   450,    -1,   451,   181,   450,    -1,   452,
      -1,   461,    -1,   453,    -1,   453,   462,    -1,   456,    -1,
     456,   462,    -1,   454,   458,    -1,   455,    -1,    97,    -1,
     106,    -1,    90,    -1,   178,    -1,   107,    -1,   129,    -1,
     128,    -1,   458,    -1,    91,   458,    -1,   457,   458,    -1,
     112,    -1,   161,    -1,    82,    -1,   169,    -1,   168,    -1,
      83,    -1,   506,    -1,   459,    -1,   533,    -1,   460,    -1,
     182,    -1,    10,    -1,    17,    -1,   464,    -1,   464,   462,
      -1,   463,    -1,   462,   463,    -1,   143,   377,   173,    -1,
     465,    -1,   467,    -1,   468,    -1,   469,    -1,   472,    -1,
     474,    -1,   470,    -1,   471,    -1,   466,    -1,   518,    -1,
     102,    -1,   138,    -1,   114,    -1,   110,   533,    -1,   145,
     175,    -1,   145,   377,   175,    -1,   111,    -1,   157,   142,
     377,   172,    -1,   190,   142,   377,   172,    -1,   533,   145,
     175,    -1,   533,   145,   473,   175,    -1,   380,    -1,   473,
      99,   380,    -1,   475,    -1,   493,    -1,   476,    -1,   490,
      -1,   491,    -1,   146,   533,   480,   120,    -1,   146,   533,
     478,   480,   120,    -1,   146,   533,   480,   185,   183,   533,
     480,   185,    -1,   146,   533,   480,   185,   477,   183,   533,
     480,   185,    -1,   146,   533,   478,   480,   185,   183,   533,
     480,   185,    -1,   146,   533,   478,   480,   185,   477,   183,
     533,   480,   185,    -1,   488,    -1,   477,   488,    -1,   479,
      -1,   478,   479,    -1,    27,   533,   480,   122,   480,   481,
      -1,    -1,    27,    -1,   171,   482,   171,    -1,    85,   484,
      85,    -1,    -1,   483,    -1,   124,    -1,   486,    -1,   483,
     124,    -1,   483,   486,    -1,    -1,   485,    -1,   123,    -1,
     487,    -1,   485,   123,    -1,   485,   487,    -1,    19,    -1,
     489,    -1,     4,    -1,   489,    -1,   475,    -1,     9,    -1,
     492,    -1,   489,    -1,     8,    -1,   113,    -1,   115,    -1,
     374,    -1,   201,    21,   202,    -1,   201,   202,    -1,   162,
     532,   163,    -1,   162,   532,     7,    -1,    95,     6,    -1,
     494,    -1,   495,    -1,   496,    -1,   497,    -1,   498,    -1,
     499,    -1,    31,   142,   377,   172,    -1,    30,   533,   142,
     172,    -1,    30,   533,   142,   377,   172,    -1,    30,   142,
     377,   172,   142,   172,    -1,    30,   142,   377,   172,   142,
     377,   172,    -1,    89,   533,   142,   172,    -1,    89,   533,
     142,   377,   172,    -1,    89,   142,   377,   172,   142,   172,
      -1,    89,   142,   377,   172,   142,   377,   172,    -1,    32,
     142,   377,   172,    -1,    33,   142,   377,   172,    -1,    42,
     532,   142,   172,    -1,    42,   532,   142,   377,   172,    -1,
      42,   142,   377,   172,   142,   172,    -1,    42,   142,   377,
     172,   142,   377,   172,    -1,   505,    -1,   505,   134,    -1,
      86,   502,    -1,   504,    -1,   504,   503,    -1,   199,   145,
     175,    -1,   134,    -1,   182,    -1,   164,    -1,   505,    -1,
     506,    -1,   141,   145,   175,    -1,   533,    -1,   508,    -1,
     514,    -1,   512,    -1,   515,    -1,   513,    -1,   511,    -1,
     510,    -1,   509,    -1,   507,    -1,   214,   145,   175,    -1,
      66,   145,   175,    -1,    66,   145,   514,   175,    -1,    66,
     145,   515,   175,    -1,    32,   145,   175,    -1,    33,   145,
     175,    -1,    42,   145,   175,    -1,    42,   145,   532,   175,
      -1,    42,   145,    20,   175,    -1,    89,   145,   175,    -1,
      89,   145,   533,   175,    -1,    89,   145,   533,    99,   516,
     175,    -1,    89,   145,   182,   175,    -1,    89,   145,   182,
      99,   516,   175,    -1,   177,   533,   175,    -1,    30,   145,
     175,    -1,    30,   145,   533,   175,    -1,    30,   145,   533,
      99,   516,   175,    -1,    30,   145,   533,    99,   517,   175,
      -1,    30,   145,   182,   175,    -1,    30,   145,   182,    99,
     516,   175,    -1,    30,   145,   182,    99,   517,   175,    -1,
      65,   145,   533,   175,    -1,   533,    -1,   533,   134,    -1,
      20,    -1,    25,   209,   210,    -1,    25,   209,   211,    -1,
      25,   209,   212,    -1,   215,   214,   380,   222,   380,    -1,
     215,   214,   380,    86,   221,   222,   380,    -1,   215,   214,
     380,    86,   223,   222,   380,    -1,   215,   214,   380,   207,
     380,    -1,   215,   214,   380,   208,   380,    -1,   215,   216,
     380,   222,   380,    -1,   215,   216,   380,    86,   221,   222,
     380,    -1,   215,   216,   380,    86,   223,   222,   380,    -1,
     215,   216,   380,   207,   380,    -1,   215,   216,   380,   208,
     380,    -1,   213,   214,   380,    -1,   213,   216,   380,    -1,
     218,   214,   380,   226,   380,    -1,   218,   219,   220,   214,
     380,   226,   380,    -1,   217,   214,   380,    86,   380,    -1,
     225,   110,   525,   224,   380,   174,   380,    -1,   526,    -1,
     525,    99,   110,   526,    -1,   533,   132,   380,    -1,   234,
     142,   377,   172,   528,    -1,   529,    -1,   528,   529,    -1,
     235,   530,   375,    -1,   235,   530,   145,   110,   533,   175,
     375,    -1,   235,   530,   145,   110,   533,    99,   110,   533,
     175,   375,    -1,   235,   530,   145,   110,   533,    99,   110,
     533,    99,   110,   533,   175,   375,    -1,   459,    -1,   530,
     198,   459,    -1,    20,    -1,    14,    -1,   533,    -1,    18,
      -1,   534,    -1,   203,    -1,   117,    -1,    89,    -1,    33,
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
      -1,   291,    -1,   292,    -1,   293,    -1,   236,   110,   399,
      53,   142,   380,   172,    -1,    53,   142,   380,   172,    -1,
     538,    -1,   538,   537,    -1,   538,   267,   430,    -1,   538,
     537,   267,   430,    -1,   547,    -1,   545,    -1,   537,   547,
      -1,   537,   545,    -1,   539,    -1,   538,   253,   539,    -1,
     540,    -1,   539,   250,   540,    -1,   541,    -1,   540,   252,
     136,   541,    -1,   542,    -1,   252,   542,    -1,   543,    -1,
     543,   566,    -1,   145,   536,   175,    -1,   544,    -1,   544,
     562,    -1,   465,    -1,   142,   377,   172,    -1,   546,    -1,
     565,    -1,   564,    -1,   567,    -1,   561,    -1,   157,    -1,
     548,    -1,   549,    -1,   550,    -1,   551,    -1,   554,    -1,
     559,    -1,   560,    -1,   256,    -1,   266,    -1,    92,   239,
      -1,    92,   242,    -1,   226,   241,    -1,   269,   241,    -1,
     241,   239,    -1,   241,   242,    -1,   226,   270,    -1,   269,
     270,    -1,   226,   273,   553,    -1,   226,   273,   105,    -1,
     226,   273,   145,   553,   175,    -1,   226,   273,   145,   553,
      99,   552,   175,    -1,   226,   273,   145,   105,   175,    -1,
     226,   273,   145,   105,    99,   552,   175,    -1,   269,   273,
      -1,   553,    -1,   552,    99,   553,    -1,    88,    20,    -1,
      88,    20,   260,    20,    -1,    88,    20,   563,   255,    -1,
      88,    20,   260,    20,   563,   255,    -1,   226,   271,   272,
     556,    -1,   226,   271,   272,   556,   555,    -1,   226,   105,
     271,   272,    -1,   226,   105,   271,   272,   555,    -1,   269,
     271,   272,    -1,   558,    -1,   555,   558,    -1,    88,    20,
      -1,   145,   557,   175,    -1,    20,    -1,   557,    20,    -1,
     189,   556,    -1,   126,   556,    -1,   254,    20,    -1,   226,
     274,    -1,   269,   274,    -1,    88,   206,    -1,    88,   246,
      -1,   245,   247,    -1,   238,    -1,   238,    47,    -1,   237,
      -1,   237,   272,    -1,   259,    -1,   248,   433,    -1,    88,
     119,   433,    -1,    88,    43,   433,    -1,   249,   433,   187,
     433,    -1,   244,   563,   568,    -1,   268,   433,   568,    -1,
     257,   563,   265,    -1,   261,   569,    -1,   243,   569,    -1,
     272,    -1,   264,    -1,   258,    -1,   263,    -1,   258,    -1,
     269,   247,   433,    -1
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
     461,   465,   469,   474,   486,   500,   514,   537,   541,   545,
     548,   552,   557,   563,   566,   571,   575,   576,   580,   583,
     585,   589,   595,   599,   605,   608,   611,   614,   618,   622,
     624,   627,   630,   633,   638,   643,   648,   653,   655,   659,
     662,   666,   670,   674,   676,   678,   681,   683,   687,   689,
     693,   695,   697,   699,   701,   703,   705,   707,   709,   711,
     713,   715,   717,   719,   721,   723,   725,   727,   730,   733,
     736,   739,   741,   743,   746,   751,   755,   761,   766,   770,
     772,   774,   776,   778,   780,   782,   784,   786,   788,   791,
     794,   798,   801,   803,   808,   812,   817,   822,   828,   833,
     839,   845,   852,   856,   860,   864,   866,   871,   873,   878,
     882,   887,   892,   898,   903,   909,   911,   914,   918,   920,
     923,   925,   932,   936,   940,   942,   945,   949,   951,   955,
     958,   962,   965,   969,   974,   976,   980,   982,   985,   987,
     989,   991,   994,   997,  1000,  1004,  1006,  1008,  1011,  1014,
    1017,  1023,  1029,  1031,  1036,  1040,  1045,  1054,  1065,  1067,
    1070,  1075,  1083,  1092,  1094,  1098,  1100,  1104,  1106,  1110,
    1114,  1118,  1122,  1123,  1128,  1132,  1136,  1140,  1142,  1146,
    1151,  1153,  1157,  1159,  1163,  1167,  1169,  1173,  1177,  1181,
    1185,  1187,  1191,  1195,  1197,  1201,  1205,  1207,  1212,  1214,
    1219,  1221,  1226,  1228,  1233,  1235,  1238,  1240,  1242,  1245,
    1248,  1250,  1252,  1254,  1256,  1258,  1260,  1262,  1264,  1266,
    1268,  1270,  1272,  1277,  1283,  1289,  1296,  1300,  1305,  1307,
    1310,  1314,  1317,  1319,  1322,  1325,  1327,  1329,  1331,  1335,
    1339,  1341,  1343,  1345,  1348,  1350,  1353,  1356,  1358,  1360,
    1362,  1364,  1366,  1368,  1370,  1372,  1374,  1377,  1380,  1382,
    1384,  1386,  1388,  1390,  1392,  1394,  1396,  1398,  1400,  1402,
    1404,  1406,  1408,  1411,  1413,  1416,  1420,  1422,  1424,  1426,
    1428,  1430,  1432,  1434,  1436,  1438,  1440,  1442,  1444,  1446,
    1449,  1452,  1456,  1458,  1463,  1468,  1472,  1477,  1479,  1483,
    1485,  1487,  1489,  1491,  1493,  1498,  1504,  1513,  1523,  1533,
    1544,  1546,  1549,  1551,  1554,  1561,  1562,  1564,  1568,  1572,
    1573,  1575,  1577,  1579,  1582,  1585,  1586,  1588,  1590,  1592,
    1595,  1598,  1600,  1602,  1604,  1606,  1608,  1610,  1612,  1614,
    1616,  1618,  1620,  1622,  1626,  1629,  1633,  1637,  1640,  1642,
    1644,  1646,  1648,  1650,  1652,  1657,  1662,  1668,  1675,  1683,
    1688,  1694,  1701,  1709,  1714,  1719,  1724,  1730,  1737,  1745,
    1747,  1750,  1753,  1755,  1758,  1762,  1764,  1766,  1768,  1770,
    1772,  1776,  1778,  1780,  1782,  1784,  1786,  1788,  1790,  1792,
    1794,  1796,  1800,  1804,  1809,  1814,  1818,  1822,  1826,  1831,
    1836,  1840,  1845,  1852,  1857,  1864,  1868,  1872,  1877,  1884,
    1891,  1896,  1903,  1910,  1915,  1917,  1920,  1922,  1926,  1930,
    1934,  1940,  1948,  1956,  1962,  1968,  1974,  1982,  1990,  1996,
    2002,  2006,  2010,  2016,  2024,  2030,  2038,  2040,  2045,  2049,
    2055,  2057,  2060,  2064,  2072,  2083,  2097,  2099,  2103,  2105,
    2107,  2109,  2111,  2113,  2115,  2117,  2119,  2121,  2123,  2125,
    2127,  2129,  2131,  2133,  2135,  2137,  2139,  2141,  2143,  2145,
    2147,  2149,  2151,  2153,  2155,  2157,  2159,  2161,  2163,  2165,
    2167,  2169,  2171,  2173,  2175,  2177,  2179,  2181,  2183,  2185,
    2187,  2189,  2191,  2193,  2195,  2197,  2199,  2201,  2203,  2205,
    2207,  2209,  2211,  2213,  2215,  2217,  2219,  2221,  2223,  2225,
    2227,  2229,  2231,  2233,  2235,  2237,  2239,  2241,  2243,  2245,
    2247,  2249,  2251,  2253,  2255,  2257,  2259,  2261,  2263,  2265,
    2267,  2269,  2271,  2273,  2275,  2277,  2279,  2281,  2283,  2285,
    2287,  2289,  2291,  2293,  2295,  2297,  2299,  2301,  2303,  2305,
    2307,  2309,  2311,  2313,  2315,  2317,  2319,  2321,  2323,  2325,
    2327,  2329,  2331,  2333,  2335,  2337,  2339,  2341,  2343,  2345,
    2347,  2349,  2351,  2353,  2355,  2357,  2359,  2361,  2363,  2365,
    2367,  2369,  2371,  2373,  2375,  2377,  2379,  2381,  2383,  2385,
    2387,  2389,  2391,  2393,  2395,  2397,  2399,  2401,  2403,  2405,
    2407,  2409,  2411,  2413,  2415,  2417,  2419,  2421,  2423,  2425,
    2427,  2429,  2431,  2433,  2435,  2437,  2439,  2441,  2443,  2445,
    2447,  2449,  2451,  2453,  2455,  2457,  2459,  2461,  2463,  2465,
    2467,  2469,  2471,  2473,  2475,  2477,  2479,  2481,  2483,  2485,
    2487,  2489,  2491,  2493,  2495,  2497,  2499,  2501,  2503,  2505,
    2507,  2515,  2520,  2522,  2525,  2529,  2534,  2536,  2538,  2541,
    2544,  2546,  2550,  2552,  2556,  2558,  2563,  2565,  2568,  2570,
    2573,  2577,  2579,  2582,  2584,  2588,  2590,  2592,  2594,  2596,
    2598,  2600,  2602,  2604,  2606,  2608,  2610,  2612,  2614,  2616,
    2618,  2621,  2624,  2627,  2630,  2633,  2636,  2639,  2642,  2646,
    2650,  2656,  2664,  2670,  2678,  2681,  2683,  2687,  2690,  2695,
    2700,  2707,  2712,  2718,  2723,  2729,  2733,  2735,  2738,  2741,
    2745,  2747,  2750,  2753,  2756,  2759,  2762,  2765,  2768,  2771,
    2774,  2776,  2779,  2781,  2784,  2786,  2789,  2793,  2797,  2802,
    2806,  2810,  2814,  2817,  2820,  2822,  2824,  2826,  2828,  2830
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
    1762,  1771,  1778,  1789,  1799,  1809,  1829,  1849,  1854,  1866,
    1870,  1874,  1878,  1885,  1892,  1918,  1928,  1934,  1940,  1949,
    1959,  1972,  1980,  1987,  2001,  2005,  2012,  2017,  2024,  2032,
    2036,  2040,  2048,  2055,  2064,  2076,  2085,  2098,  2106,  2120,
    2127,  2140,  2148,  2159,  2174,  2178,  2194,  2198,  2207,  2211,
    2228,  2229,  2230,  2231,  2232,  2235,  2236,  2237,  2238,  2239,
    2241,  2242,  2245,  2246,  2247,  2248,  2249,  2256,  2269,  2276,
    2280,  2288,  2292,  2296,  2303,  2307,  2314,  2322,  2333,  2343,
    2344,  2345,  2349,  2349,  2349,  2349,  2349,  2352,  2358,  2367,
    2371,  2381,  2392,  2398,  2412,  2420,  2429,  2439,  2450,  2459,
    2469,  2479,  2495,  2508,  2520,  2532,  2538,  2550,  2556,  2570,
    2579,  2589,  2598,  2611,  2618,  2629,  2630,  2635,  2644,  2648,
    2653,  2657,  2663,  2668,  2676,  2692,  2700,  2707,  2713,  2724,
    2731,  2741,  2751,  2756,  2768,  2774,  2788,  2794,  2806,  2813,
    2820,  2827,  2834,  2841,  2848,  2861,  2865,  2875,  2879,  2889,
    2900,  2907,  2920,  2927,  2939,  2946,  2960,  2967,  2982,  2988,
    3000,  3006,  3020,  3031,  3035,  3046,  3050,  3069,  3073,  3081,
    3089,  3097,  3105,  3105,  3113,  3121,  3129,  3143,  3147,  3154,
    3167,  3171,  3182,  3186,  3190,  3200,  3204,  3208,  3212,  3216,
    3226,  3230,  3235,  3246,  3250,  3254,  3264,  3268,  3280,  3284,
    3296,  3300,  3312,  3316,  3328,  3332,  3344,  3348,  3352,  3356,
    3368,  3372,  3376,  3386,  3390,  3394,  3398,  3402,  3406,  3416,
    3420,  3424,  3434,  3438,  3442,  3446,  3458,  3464,  3476,  3482,
    3496,  3503,  3544,  3548,  3552,  3556,  3568,  3578,  3589,  3594,
    3604,  3608,  3618,  3624,  3630,  3636,  3648,  3654,  3665,  3669,
    3673,  3677,  3681,  3685,  3689,  3699,  3703,  3713,  3717,  3728,
    3732,  3736,  3740,  3744,  3759,  3763,  3773,  3777,  3787,  3794,
    3801,  3814,  3818,  3830,  3836,  3850,  3861,  3865,  3869,  3873,
    3877,  3881,  3885,  3889,  3899,  3903,  3913,  3918,  3923,  3934,
    3945,  3949,  3960,  3970,  3981,  4037,  4043,  4055,  4061,  4073,
    4077,  4087,  4091,  4095,  4105,  4113,  4121,  4129,  4137,  4145,
    4160,  4166,  4178,  4184,  4197,  4206,  4208,  4214,  4219,  4231,
    4234,  4241,  4247,  4253,  4261,  4276,  4279,  4286,  4292,  4298,
    4306,  4320,  4325,  4336,  4341,  4352,  4357,  4362,  4368,  4380,
    4386,  4391,  4396,  4407,  4412,  4427,  4432,  4449,  4464,  4468,
    4472,  4476,  4480,  4484,  4494,  4505,  4511,  4517,  4522,  4544,
    4550,  4556,  4561,  4572,  4582,  4592,  4598,  4604,  4609,  4620,
    4626,  4638,  4649,  4655,  4661,  4698,  4703,  4708,  4719,  4723,
    4727,  4737,  4748,  4752,  4756,  4760,  4764,  4768,  4772,  4776,
    4780,  4790,  4800,  4804,  4809,  4820,  4830,  4840,  4844,  4848,
    4858,  4864,  4870,  4876,  4882,  4894,  4905,  4912,  4919,  4926,
    4933,  4940,  4947,  4960,  4981,  4988,  5008,  5048,  5052,  5056,
    5065,  5071,  5077,  5083,  5089,  5096,  5102,  5108,  5114,  5120,
    5132,  5137,  5147,  5153,  5165,  5191,  5202,  5208,  5221,  5237,
    5244,  5250,  5261,  5268,  5278,  5289,  5305,  5311,  5321,  5330,
    5331,  5349,  5353,  5360,  5361,  5362,  5363,  5364,  5365,  5366,
    5367,  5368,  5369,  5370,  5371,  5372,  5373,  5374,  5375,  5376,
    5377,  5378,  5379,  5380,  5381,  5382,  5383,  5384,  5385,  5386,
    5387,  5388,  5389,  5390,  5391,  5392,  5393,  5394,  5395,  5396,
    5397,  5398,  5399,  5400,  5401,  5402,  5403,  5404,  5405,  5406,
    5407,  5408,  5409,  5410,  5411,  5412,  5413,  5414,  5415,  5416,
    5417,  5418,  5419,  5420,  5421,  5422,  5423,  5424,  5425,  5426,
    5427,  5428,  5429,  5430,  5431,  5432,  5433,  5434,  5435,  5436,
    5437,  5438,  5439,  5440,  5441,  5442,  5443,  5444,  5445,  5446,
    5447,  5448,  5449,  5450,  5451,  5452,  5453,  5454,  5455,  5456,
    5457,  5458,  5459,  5460,  5461,  5462,  5463,  5464,  5465,  5466,
    5467,  5468,  5469,  5470,  5471,  5472,  5473,  5474,  5475,  5476,
    5477,  5478,  5479,  5480,  5481,  5482,  5483,  5484,  5485,  5486,
    5487,  5488,  5489,  5490,  5491,  5492,  5493,  5494,  5495,  5496,
    5497,  5498,  5499,  5500,  5501,  5502,  5503,  5504,  5505,  5506,
    5507,  5508,  5509,  5510,  5511,  5512,  5513,  5514,  5515,  5516,
    5517,  5518,  5519,  5520,  5521,  5522,  5523,  5524,  5525,  5526,
    5527,  5528,  5529,  5530,  5531,  5532,  5533,  5534,  5535,  5536,
    5537,  5538,  5539,  5540,  5541,  5542,  5543,  5544,  5545,  5546,
    5547,  5548,  5549,  5554,  5555,  5556,  5557,  5558,  5560,  5561,
    5572,  5578,  5595,  5599,  5603,  5607,  5617,  5620,  5623,  5626,
    5635,  5638,  5647,  5650,  5659,  5662,  5671,  5674,  5683,  5686,
    5689,  5698,  5701,  5710,  5714,  5724,  5727,  5730,  5733,  5736,
    5745,  5754,  5758,  5762,  5766,  5770,  5774,  5778,  5788,  5791,
    5794,  5797,  5806,  5809,  5812,  5815,  5824,  5827,  5836,  5839,
    5842,  5845,  5848,  5851,  5854,  5863,  5866,  5875,  5878,  5881,
    5884,  5893,  5896,  5899,  5902,  5905,  5914,  5917,  5926,  5929,
    5938,  5941,  5950,  5953,  5962,  5971,  5974,  5983,  5986,  5989,
    5998,  6001,  6004,  6007,  6010,  6019,  6023,  6027,  6031,  6041,
    6050,  6060,  6069,  6072,  6081,  6084,  6087,  6096,  6099,  6108
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
     305,   306,   307,   308
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 10765;
  const int xquery_parser::yynnts_ = 262;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 512;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 309;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 563;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 14051 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6116 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"


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

