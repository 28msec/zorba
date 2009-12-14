
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
#line 925 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"

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
#line 809 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 268 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 114: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 808 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 277 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 138: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 807 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 286 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 317: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 295 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 304 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 313 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 322 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "Prolog" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 331 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 340 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 349 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 358 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 367 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 376 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 821 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->pair_vector); };

/* Line 480 of lalr1.cc  */
#line 385 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 821 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->pair); };

/* Line 480 of lalr1.cc  */
#line 394 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 403 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 412 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 421 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 430 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 439 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 448 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 457 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 466 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 475 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 484 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 493 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 502 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 511 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 520 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 529 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 538 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 547 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 556 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 565 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 821 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 574 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 583 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 592 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "CollPropertyList" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 601 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "CollProperty" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 610 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "NodeModifier" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 619 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 628 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "IndexProperties" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 637 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "IndexProperties2" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 646 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "IndexProperties3" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 655 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 664 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 673 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 682 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 691 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 821 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 700 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 709 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "Block" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 718 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "BlockDecls" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 727 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "BlockVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 736 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "BlockVarDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 745 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "AssignExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 754 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "ExitExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 763 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "WhileExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 772 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 781 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 790 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 799 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "FunctionDecl3" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 808 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "FunctionDecl4" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 826 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 835 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "EnclosedExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 844 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 853 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 862 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 871 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "ApplyExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 880 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "ConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 889 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 898 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 907 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 916 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 925 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 934 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 943 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 952 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 961 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 970 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 979 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 988 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 997 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1006 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1015 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "EvalVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1024 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1033 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1042 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1051 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1060 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1069 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "EvalVarDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1078 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1087 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1096 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1105 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1114 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1123 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1132 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1141 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1150 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1159 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1168 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1177 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1186 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1195 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1204 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1213 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1222 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1231 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1240 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1249 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1258 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1267 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1276 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1285 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1294 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1303 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1312 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1321 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1330 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1339 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1348 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1357 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1366 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1375 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1384 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1393 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1402 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1411 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1420 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1429 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "PragmaList" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1438 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1447 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1456 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1465 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1474 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1483 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1492 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1501 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1510 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1519 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1528 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1537 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1546 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1555 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1564 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1573 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1582 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1591 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1600 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1609 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1618 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1627 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1636 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1645 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1654 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1663 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1672 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1681 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1690 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1699 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1708 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1717 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1726 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1735 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "Opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1744 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1753 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "Opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1762 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1771 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1780 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1789 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1798 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1807 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1816 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1825 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1834 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1843 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1852 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1861 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1870 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1879 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1888 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1897 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1906 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1915 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1924 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1933 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1942 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1951 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1960 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1969 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1978 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1987 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1996 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2005 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2014 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2023 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2032 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2041 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2050 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 817 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2059 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2068 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2077 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2086 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2095 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2104 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2113 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2122 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2131 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2140 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2149 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2158 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 821 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2167 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2176 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "EvalExpr" */

/* Line 480 of lalr1.cc  */
#line 819 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2185 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
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
#line 2270 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"

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
#line 943 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 953 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		}
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 958 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<MainModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr ((yyval.node));
		}
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 964 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
       driver.set_expr ((yyval.node));
		}
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 969 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
       driver.set_expr ((yyval.node));
		}
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 981 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)), encoding);
		}
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 986 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 996 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)));
		}
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 1003 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)),
                NULL);
		}
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1015 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC ((yyloc)),
                             static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)),
                             NULL);
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1021 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LibraryModule(LOC ((yyloc)),
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1033 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(6) - (3)].sval)),
								SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
      dynamic_cast<ModuleDecl *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
		}
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1046 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)), NULL);
		}
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1050 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		}
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1054 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC((yyloc)),
                      static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
                      static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1066 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = new SIND_DeclList(LOC ((yyloc)));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		}
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1072 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1086 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = new VFO_DeclList(LOC ((yyloc)));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		}
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1092 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1138 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].pair_vector));
      delete (yysemantic_stack_[(4) - (4)].pair_vector);
    }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 1143 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr))->get_qname(), (yysemantic_stack_[(4) - (4)].pair_vector));
      delete (yysemantic_stack_[(4) - (3)].expr);
      delete (yysemantic_stack_[(4) - (4)].pair_vector);
    }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 1152 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.pair_vector) = new std::vector<std::pair<std::string, std::string> > ();
      (yyval.pair_vector)->push_back(*(yysemantic_stack_[(1) - (1)].pair));
      delete (yysemantic_stack_[(1) - (1)].pair);
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 1158 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].pair_vector)->push_back(*(yysemantic_stack_[(2) - (2)].pair));
      delete (yysemantic_stack_[(2) - (2)].pair);
      (yyval.pair_vector) = (yysemantic_stack_[(2) - (1)].pair_vector);
    }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1167 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *s = static_cast<StringLiteral *>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.pair) = new std::pair<std::string, std::string>((yysemantic_stack_[(3) - (1)].strval), s->get_strval());
      delete s;
    }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1175 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1176 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1177 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1178 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1179 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1180 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1181 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1182 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1183 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1184 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1221 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1233 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		}
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1238 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		}
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1249 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_element_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1255 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_function_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1267 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OptionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
								SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
		}
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1280 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (3)].node));
		}
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1291 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		}
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1296 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		}
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1308 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		}
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1313 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		}
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1324 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::inherit_ns);
		}
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1330 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::no_inherit_ns);
		}
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1336 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::inherit_ns);
		}
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1342 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::no_inherit_ns);
		}
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1361 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)));
		}
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1372 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		}
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1383 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		}
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1390 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)),
								NULL);
		}
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 1397 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		}
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 1404 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
		}
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 1417 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = new URILiteralList(LOC ((yyloc)));
			uri_list_p->push_back(SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		}
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1423 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1438 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1442 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		}
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1452 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)), false,
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1459 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1467 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)), false,
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
		}
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1474 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1487 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1494 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->type = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1500 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1507 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(1) - (1)].node));
      d->ext = false;
      (yyval.node) = d;
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1513 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), NULL);
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1517 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1524 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1535 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(), NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1540 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
                               dynamic_cast<SequenceType *> ((yysemantic_stack_[(3) - (3)].node)));
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1549 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1558 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (3)].varnametype)));
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       NULL, true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
		}
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1565 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(6) - (3)].varnametype)));
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       (yysemantic_stack_[(6) - (6)].expr), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
		}
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1575 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1583 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1591 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1599 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1607 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<CollPropertyList*>((yysemantic_stack_[(4) - (2)].node)), 0, 0);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1613 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1621 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1629 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1640 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      CollPropertyList* l = new CollPropertyList(LOC((yyloc)));
      l->addProperty(dynamic_cast<CollProperty*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1646 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<CollPropertyList*>((yysemantic_stack_[(2) - (1)].node))->addProperty(static_cast<CollProperty*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1654 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollProperty(LOC((yyloc)), StaticContextConsts::const_);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1658 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollProperty(LOC((yyloc)), StaticContextConsts::append_only);
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1662 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollProperty(LOC((yyloc)), StaticContextConsts::queue);
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1666 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollProperty(LOC((yyloc)), StaticContextConsts::mutable_coll);
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1670 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollProperty(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1674 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollProperty(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1683 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::read_only);
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1687 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NodeModifier(LOC((yyloc)), StaticContextConsts::mutable_node);
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1695 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1707 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1712 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      IndexProperties* p = dynamic_cast<IndexProperties*>((yysemantic_stack_[(2) - (2)].node));
      p->setUnique();
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1719 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1726 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1731 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      IndexProperties* p = dynamic_cast<IndexProperties*>((yysemantic_stack_[(2) - (2)].node));
      p->setOrdered();
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1738 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1744 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      // default properties: non-unique, non-ordered, manual
      (yyval.node) = new IndexProperties(LOC((yyloc)), false, false, false);
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1749 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexProperties(LOC((yyloc)), false, false, false);
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1754 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexProperties(LOC((yyloc)), false, false, true);
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1762 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* l = new IndexKeyList(LOC((yyloc)));
      l->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1768 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1777 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1782 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1789 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1796 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1808 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1820 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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

  case 137:

/* Line 678 of lalr1.cc  */
#line 1832 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1844 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1857 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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

  case 140:

/* Line 678 of lalr1.cc  */
#line 1878 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.intval) = (yysemantic_stack_[(2) - (1)].intval) | (yysemantic_stack_[(2) - (2)].intval); }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1881 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.intval) = (yysemantic_stack_[(2) - (1)].intval) | (yysemantic_stack_[(2) - (2)].intval); }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1884 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.intval) = IntegrityConstraintDecl::IC_OPTION_CHECKED; // checked
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1889 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.intval) = IntegrityConstraintDecl::IC_OPTION_CHECKED; // checked
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1893 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.intval) = IntegrityConstraintDecl::IC_OPTION_UNCHECKED;  // unchecked
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1899 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.intval) = IntegrityConstraintDecl::IC_OPTION_SYNCH; // synchronous
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1904 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.intval) = IntegrityConstraintDecl::IC_OPTION_SYNCH; // synchronous
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1908 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.intval) = IntegrityConstraintDecl::IC_OPTION_ASYNCH;  // asynchronous
    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1919 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		}
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1924 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		}
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1936 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL);
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1940 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1944 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL, dynamic_cast<SequenceType *> ((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1948 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType *> ((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1955 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1962 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1988 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 1997 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL;
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 2004 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (1)].node));
      vfo->push_back ((yysemantic_stack_[(3) - (3)].node));
      (yyval.node) = vfo;
    }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 2010 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = new VFO_DeclList (LOC ((yyloc)));
      vfo->push_back ((yysemantic_stack_[(2) - (2)].node));
      (yyval.node) = vfo;
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 2019 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2029 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2042 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr (LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr))->get_qname(), (yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (3)].expr);
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 2050 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr (LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2057 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2071 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 2075 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::CONTINUE);
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 2082 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<FunctionDecl *>((yysemantic_stack_[(2) - (2)].node))->setComment(SYMTAB((yysemantic_stack_[(2) - (1)].sval)));
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 2087 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
      d->deterministic = false;
      (yyval.node) = d;
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 2094 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<FunctionDecl *>((yysemantic_stack_[(3) - (3)].node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 2102 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 171:

/* Line 678 of lalr1.cc  */
#line 2106 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 172:

/* Line 678 of lalr1.cc  */
#line 2110 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2118 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 174:

/* Line 678 of lalr1.cc  */
#line 2125 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2134 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2146 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2155 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2168 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2176 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2190 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(),
								NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
		}
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2197 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
      delete (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 2210 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 2218 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 2229 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QueryBody(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
		}
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 2244 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 2248 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2264 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody (LOC ((yyloc)));
    }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 2268 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = dynamic_cast<BlockBody *>((yysemantic_stack_[(3) - (1)].expr));
      blk->add((yysemantic_stack_[(3) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 2277 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 2281 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2326 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2339 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 2346 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 2350 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 2358 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 2362 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 2366 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_only_end;
    }
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 2373 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), dynamic_cast<WindowVars *> ((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr), (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 2377 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr), (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 2384 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2392 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window,
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 2403 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause (LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 2422 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = new FLWORClauseList (LOC ((yyloc)));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 2428 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = dynamic_cast<FLWORClauseList *> ((yysemantic_stack_[(2) - (1)].node));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 2437 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = NULL;
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 2441 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_ofor;
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 2451 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForClause(LOC ((yyloc)),
                         dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL);
		}
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 2462 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		}
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 2468 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2482 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2490 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2499 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2509 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2520 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2529 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2539 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2549 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2565 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
		}
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2578 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
		}
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 2590 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)));

		}
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2602 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		}
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 2608 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2620 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		}
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2626 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2640 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2649 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2659 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2668 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2681 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr))->get_qname(),
								NULL, (yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (2)].expr);
		}
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 2688 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2700 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(), "", "");
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 2705 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_curr (static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2714 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), dynamic_cast<PositionalVar *> ((yysemantic_stack_[(1) - (1)].node)), "", "", "");
    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2718 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_posvar (dynamic_cast<PositionalVar *> ((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2727 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr))->get_qname(), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr))->get_qname());
      delete (yysemantic_stack_[(6) - (3)].expr);
      delete (yysemantic_stack_[(6) - (6)].expr);
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2733 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", "", static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2738 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname(), "");
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2746 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2762 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2770 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2777 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = new GroupSpecList(LOC((yyloc)));
      gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl_p;
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2783 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2794 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(),
                 NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2801 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
                 dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2811 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2821 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2826 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)),
								true);
		}
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2838 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		}
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2844 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 2858 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		}
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2864 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
                         (yysemantic_stack_[(2) - (1)].expr),
                         dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2876 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
                               NULL,
                               NULL);
		}
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2883 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               NULL,
                               dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
                               NULL);
		}
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2890 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               NULL,
                               NULL,
                               dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2897 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                               dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                               NULL);
		}
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2904 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                               NULL,
                               dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2911 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               NULL,
                               dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                               dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2918 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifierPN(LOC((yyloc)),
                               dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                               dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                               dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2931 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		}
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2935 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		}
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2945 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC((yyloc)), StaticContextConsts::empty_greatest);
		}
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2949 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC((yyloc)), StaticContextConsts::empty_least);
		}
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 2959 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		}
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 2970 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 2977 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 2990 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;

		}
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 2997 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 3009 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
								(yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (1)].expr);
		}
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 3016 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3030 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
								(yysemantic_stack_[(8) - (8)].expr));
		}
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 3037 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3052 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		}
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 3058 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 3070 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3076 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3090 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
		}
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3101 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3105 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3116 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3120 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3139 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3143 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3151 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3159 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3167 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3174 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { /* this call is needed */  driver.lexer->interpretAsLessThan(); }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3175 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3183 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3191 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3199 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3213 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3217 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		}
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3224 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3237 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3241 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3252 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3256 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3260 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3270 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3274 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3278 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3282 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3286 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3296 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3300 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3305 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3316 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3320 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3324 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3334 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3338 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3350 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3354 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3366 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3370 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3382 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3386 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3398 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3402 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3414 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		}
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3418 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		}
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3422 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3426 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3438 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3442 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3446 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3456 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		}
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3460 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		}
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3464 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		}
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3468 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		}
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3472 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		}
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3476 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		}
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3486 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		}
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3490 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		}
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3494 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		}
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3504 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3508 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3512 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3516 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                            dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(),
                            (yysemantic_stack_[(6) - (5)].expr));
    }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3528 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		}
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3534 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3546 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		}
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3552 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3566 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));

		}
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3572 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval))),
								"");
    }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3614 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		}
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3618 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3622 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3626 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (rpe == NULL ?
             (yysemantic_stack_[(1) - (1)].expr) :
             new PathExpr(LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3638 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3648 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3659 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3664 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3674 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3678 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3688 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		}
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3694 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3700 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		}
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3706 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3718 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		}
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3724 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3735 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		}
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3739 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		}
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3743 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		}
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3747 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		}
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3751 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		}
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3755 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		}
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3759 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		}
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3769 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node), false);
		}
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3773 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		}
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3783 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseStep(LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node));
		}
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3787 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC((yyloc)), rev_p, NULL);
		}
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3798 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		}
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3802 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		}
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3806 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		}
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3810 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		}
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3814 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		}
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3829 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3833 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3843 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3847 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3857 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        "",
                        ParseConstants::wild_all);
		}
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3864 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        ParseConstants::wild_elem);
		}
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3871 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        ParseConstants::wild_prefix);
		}
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3884 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3888 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
                          (yysemantic_stack_[(2) - (1)].expr),
                          dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3900 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		}
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3906 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 3920 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3931 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3935 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3939 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3943 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3947 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3951 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3955 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 3959 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 3969 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 3973 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 3983 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval));
      delete yylval.decval;
		}
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 3988 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival));
      delete yylval.ival;
		}
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 3993 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval));
      delete yylval.dval;
		}
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 4004 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new VarRef(LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname());
      delete (yysemantic_stack_[(2) - (2)].expr);
		}
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 4015 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		}
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 4019 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 4030 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		}
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 4040 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 4051 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 4107 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)),
								NULL);
		}
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 4113 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4125 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = new ArgList(LOC ((yyloc)));
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		}
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4131 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4143 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4147 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4157 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4161 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4165 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4175 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4183 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4191 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4199 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4207 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4215 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4230 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		}
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4236 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4248 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		}
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4254 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4267 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
		}
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4284 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		}
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4289 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		}
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4300 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		}
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4304 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4311 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		}
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4317 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		}
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4323 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4331 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4345 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		}
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4349 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4356 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		}
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4362 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		}
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4368 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4376 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 4390 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4395 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4406 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4411 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4422 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		}
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4427 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4432 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		}
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4438 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		}
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4450 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4456 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		}
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4461 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		}
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4466 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4477 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4482 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4497 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4502 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		}
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4519 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CDataSection(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		}
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4534 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4538 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4542 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4546 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4550 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4554 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4564 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4575 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
								NULL);
		}
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4581 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4587 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4592 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4614 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (2)].expr),
								NULL);
		}
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4620 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4626 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4631 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4642 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4652 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4662 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		}
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4668 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4674 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4679 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4690 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		}
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4696 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		}
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4708 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
		}
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4719 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		}
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4725 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4731 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		}
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4768 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		}
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4773 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		}
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4778 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		}
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4789 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4793 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4797 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		}
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4807 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4818 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4822 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4826 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4830 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4834 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4838 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4842 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4846 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4850 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4860 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		}
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4870 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		}
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4874 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4879 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4890 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TextTest(LOC ((yyloc)));
		}
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4900 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		}
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4910 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		}
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4914 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		}
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4918 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		}
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4928 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		}
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4934 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
								NULL);
		}
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4940 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		}
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4946 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		}
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4952 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		}
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4964 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
		}
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4975 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           NULL,
                           NULL,
                           true);
		}
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4982 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                           NULL,
                           true);
		}
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4989 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           false);
		}
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4996 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           true);
		}
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 5003 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL,
									true);
		}
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 5010 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									false);
		}
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 5017 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									true);
		}
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 5030 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)));
		}
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 5051 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 5058 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)),
								true);
		}
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 5078 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 5118 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::strict_validation);
		}
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 5122 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::lax_validation);
    }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 5126 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::skip_validation);
    }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 5135 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 5141 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 5147 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 5153 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 5159 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 5166 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 5172 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 5178 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5184 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5190 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5202 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5207 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5217 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5223 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5235 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5261 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5272 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       CopyVarList* lList = new CopyVarList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
		}
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5278 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
       VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
       lList->push_back(lBinding);
       (yyval.expr) = lList;
		}
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5291 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (1)].expr);
    }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5307 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5314 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5320 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5331 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(3) - (2)].name_test_list),
                          (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5338 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5348 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5359 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5375 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      CatchExpr::NameTestList *name_test_list = new CatchExpr::NameTestList;
      name_test_list->push_back (static_cast<NameTest *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.name_test_list) = name_test_list;
    }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5381 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      CatchExpr::NameTestList *name_test_list =
        static_cast<CatchExpr::NameTestList *> ((yysemantic_stack_[(3) - (1)].name_test_list));
      name_test_list->push_back (static_cast<NameTest *> ((yysemantic_stack_[(3) - (3)].node)));
      (yyval.name_test_list) = name_test_list;
    }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5401 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
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
#line 5419 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5423 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5429 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("xquery"); }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5430 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty"); }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5431 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("attribute"); }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5432 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("comment"); }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5433 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document-node"); }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5434 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("element"); }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5435 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("item"); }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5436 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("if"); }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5437 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("node"); }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5438 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("processing-instruction"); }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5439 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-attribute"); }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5440 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-element"); }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5441 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("text"); }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5442 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("typeswitch"); }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5443 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty-sequence"); }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5444 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("boundary-space"); }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5445 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ft-option"); }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5446 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("base-uri"); }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5447 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lax"); }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5448 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strict"); }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5449 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("idiv"); }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5450 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document"); }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5451 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("not"); }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5452 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sensitive"); }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5453 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insensitive"); }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5454 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("diacritics"); }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5455 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("without"); }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5456 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stemming"); }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5457 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("thesaurus"); }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5458 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stop"); }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5459 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("wildcards"); }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5460 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("entire"); }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5461 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("content"); }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5462 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("word"); }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5463 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("start"); }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5464 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("end"); }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5465 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("most"); }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5466 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("skip"); }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5467 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy"); }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5468 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("value"); }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5469 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eq"); }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5470 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ne"); }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5471 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lt"); }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5472 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("le"); }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5473 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("gt"); }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5474 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ge"); }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5475 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("at"); }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5476 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("context"); }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5477 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("variable"); }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5478 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("return"); }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5479 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("for"); }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5480 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("outer"); }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5481 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sliding"); }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5482 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("tumbling"); }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5483 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("previous"); }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5484 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("next"); }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5485 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("only"); }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5486 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("when"); }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5487 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("count"); }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5488 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("in"); }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5489 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("let"); }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5490 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("where"); }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5491 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("by"); }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5492 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("group"); }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5493 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("order"); }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5494 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stable"); }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5495 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ascending"); }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5496 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("descending"); }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5497 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("greatest"); }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5498 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("least"); }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5499 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("collation"); }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5500 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("some"); }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5501 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("every"); }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5502 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("satisfies"); }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5503 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("case"); }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5504 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("as"); }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5505 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("then"); }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5506 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("else"); }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5507 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("or"); }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5508 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("and"); }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5509 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("instance"); }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5510 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("of"); }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5511 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("castable"); }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5512 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("to"); }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5513 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("div"); }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5514 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("mod"); }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5515 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("union"); }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5516 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("intersect"); }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5517 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("except"); }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5518 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("validate"); }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5519 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("cast"); }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5520 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("treat"); }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5521 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("is"); }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5522 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("preserve"); }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5523 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strip"); }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5524 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("namespace"); }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5525 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("external"); }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5526 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("encoding"); }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5527 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-preserve"); }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5528 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("inherit"); }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5529 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-inherit"); }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5530 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("declare"); }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5531 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("construction"); }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5532 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordering"); }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5533 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("default"); }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5534 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy-namespaces"); }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5535 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("option"); }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 5536 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("version"); }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5537 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("import"); }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 5538 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema"); }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 5539 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("module"); }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 5540 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("function"); }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 5541 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("score"); }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 5542 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ftcontains"); }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 5543 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("weight"); }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 5544 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("window"); }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 5545 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("distance"); }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 5546 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("occurs"); }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 5547 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("times"); }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 5548 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("same"); }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 5549 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("different"); }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 5550 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lowercase"); }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 5551 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("uppercase"); }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 5552 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("relationship"); }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 5553 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("levels"); }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 5554 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("language"); }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 5555 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("any"); }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 5556 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("all"); }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 5557 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("phrase"); }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 5558 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exactly"); }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 5559 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("from"); }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 5560 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("words"); }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 5561 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentences"); }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 5562 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentence"); }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 5563 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("paragraph"); }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 5564 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("replace"); }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 5565 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("modify"); }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 5566 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("first"); }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 5567 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insert"); }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 5568 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("before"); }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 5569 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("after"); }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 5570 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("revalidation"); }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 5571 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("with"); }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 5572 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nodes"); }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 5573 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("rename"); }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 5574 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("last"); }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 5575 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("delete"); }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 5576 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("into"); }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 5577 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("simple"); }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 5578 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sequential"); }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 5579 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("updating"); }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 5580 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("deterministic"); }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 5581 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nondeterministic"); }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 5582 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordered"); }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 5583 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unordered"); }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 5584 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("returning"); }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 5585 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("block"); }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 5586 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exit"); }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 5587 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("loop"); }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 5588 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("while"); }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 5589 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("break"); }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 5590 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("continue"); }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 5591 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("try"); }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 5592 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("catch"); }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 5593 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eval"); }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 5594 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("using"); }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 5595 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("set"); }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 5596 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("index"); }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 5597 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unique"); }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 5598 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("non"); }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 5599 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("on"); }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 5600 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("manual"); }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 5601 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("automatic"); }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 5602 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("decimal-format"); }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 5603 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("decimal-separator"); }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 5604 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("grouping-separator"); }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 5605 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("infinity"); }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 5606 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("minus-sign"); }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 5607 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("NaN"); }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 5608 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("percent"); }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 5609 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("per-mille"); }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 5610 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("zero-digit"); }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 5611 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("digit"); }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 5612 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("pattern-separator"); }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 5613 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("collection"); }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 5614 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("const"); }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 5615 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("append-only"); }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 5616 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("queue"); }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 5617 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("mutable"); }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 5618 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("read-only"); }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 5619 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("checked"); }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 5620 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unchecked"); }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 5621 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("asynchronous"); }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 5622 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("synchronous"); }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 5623 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("integrity"); }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 5624 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("constraint"); }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 5625 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("check"); }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 5626 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("key"); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 5627 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("foreach"); }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 5628 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("type"); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 5629 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("foreign"); }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 5630 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("keys"); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 5642 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)),
                          (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 5648 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 5665 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(1) - (1)].node)), NULL, NULL);
		}
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 5669 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(2) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(2) - (2)].node)), NULL);
		}
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 5673 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(3) - (1)].node)), NULL, static_cast<RangeExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		}
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 5677 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(4) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(4) - (2)].node)), static_cast<RangeExpr *> ((yysemantic_stack_[(4) - (4)].expr)));
		}
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 5687 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 5690 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 5693 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 5696 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 5705 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 5708 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 5717 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 5720 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 5729 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 5732 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 5741 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 5744 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 5753 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 5756 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 5759 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 5768 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 5771 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 5780 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), static_cast<StringLiteral *> ((yysemantic_stack_[(1) - (1)].expr)), NULL);
		}
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 5784 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 5794 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 5797 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 5800 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 5803 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 5806 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 5815 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 5824 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 5828 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 5832 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 5836 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 5840 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 5844 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 5848 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 5858 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 5861 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 5864 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 5867 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 5876 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 5879 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 5882 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 5885 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 5894 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 5897 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 5906 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 5909 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 5912 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 5915 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 5918 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 5921 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 5924 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 5933 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 5936 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 5945 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 5948 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 5951 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 5954 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 5963 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 5966 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 5969 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 5972 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 5975 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 5984 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 5987 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 5996 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 5999 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 6008 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 6011 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 6020 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 6023 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 6032 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 6041 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6044 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6053 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6056 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6059 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6068 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6071 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6074 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 6077 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 6080 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 6089 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 6093 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 6097 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 6101 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 6111 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 6120 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWindow (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (2)].expr)), static_cast<FTUnit *> ((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 6130 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 6139 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 6142 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 6151 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 6154 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 6157 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 6166 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6169 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6178 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTIgnoreOption (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		}
    break;



/* Line 678 of lalr1.cc  */
#line 10309 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1303;
  const short int
  xquery_parser::yypact_[] =
  {
      1484, -1303, -1303, -1303, -1303,   903,    73,   205,   108,  8684,
     -24,   498,   503, -1303, -1303, -1303, -1303, -1303, -1303,   216,
     282,  7550, -1303,   279, -1303, -1303, -1303, -1303,   315,   336,
   -1303,   237,   283,   446, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303,   341,   389, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303,  8965, -1303,  6976, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, 10651, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303,   461, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303,  1774, 10651, -1303, -1303, -1303, -1303, -1303,
   -1303,   404, -1303, -1303, -1303, -1303,  8120, -1303,  8403, -1303,
   -1303, -1303, -1303, -1303, 10651, -1303, -1303,  6687, -1303, -1303,
   -1303, -1303, -1303, -1303,   438, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303,    22,   385, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303,   347,   477,   436, -1303,   430,   124, -1303,
   -1303, -1303, -1303, -1303, -1303,   552, -1303, -1303,   526,   453,
     458, -1303,   468,   546,   566, -1303,   612, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303,  4375,   734, -1303,
    4664, -1303, -1303,    83,  4953,   558,   559, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,   -34, -1303,
   -1303, -1303, -1303,   207, 10651, -1303, -1303, -1303, -1303, -1303,
     583,   656, -1303,   411,   493,   300,   218,   350,   326, -1303,
     677,   560,   657,   655,  5242, -1303, -1303, -1303,    13, -1303,
   -1303,  6687, -1303,   431, -1303,   608,  6976, -1303,   608,  6976,
   -1303, -1303, -1303, -1303,   608, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303,   607, -1303, -1303, 10651,   719,   720,   548,
     548,   719, 10651,   132,    -4,   735,   266,   273, 10651,   615,
     647,   260,  8120, -1303, -1303,   460,     1, 10651, -1303, -1303,
   -1303, -1303, 10651, -1303, -1303, -1303, -1303,   127, -1303,   467,
     343,   370, -1303, -1303,  8120, 10651,  4953,   617,   619,  4953,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303,  4953,  9246, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,   620,
    4953,  4953,   589,  4953,   591,  4953,    41,    42, -1303,  4953,
    7835,   625, -1303, 10651, 10651, 10651,  4953,   500,   501, -1303,
     660,   661, 10651,    34,  4953,  9527,   631,   635,   640,   642,
     643,   644, -1303, -1303, -1303, 10651, -1303,   616,   763,  4953,
      31, -1303,   777,   618, -1303,  4953,   592, -1303,   775,  4953,
    4953,   621,  4953,  4953,  4953,  4953,   577, 10651, -1303, -1303,
    4953, -1303, -1303,  4953,  4953, 10651, -1303, -1303, -1303, -1303,
     999,   282, -1303, -1303,    83,   773,  4953, -1303,  4953,   641,
     336,   283,   446,   690,   646,   648,  4953,  4953, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303,   702, -1303,   -33,  5531,  5531,
    5531, -1303,  5531,  5531, -1303,  5531, -1303,  5531, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303,  5531,  5531,    -2,  5531,  5531,
    5531,  5531,  5531,  5531,  5531,  5531,  5531,  5531,  5531,   582,
     717,   722,   723, -1303, -1303, -1303,  2063, -1303, -1303,  6687,
    6687,  4953,   608, -1303, -1303,   608, -1303,   608,  2352,   665,
   -1303, 10651, -1303, -1303, -1303, -1303,   786, -1303, -1303, -1303,
   -1303, -1303, -1303,   713,   715, -1303, -1303,   652,   285, 10651,
     463,   666,   667,   652,   735,   701,   697, -1303, -1303, -1303,
     407,     8,   412,   800, -1303, -1303,   254, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303,   -16,   535, 10651, -1303,   530,
   -1303, -1303,   703,   681, -1303,   654,  4953,  4953,   649,   658,
   -1303,   -31,   -25,  2641,   659,   662, -1303,   664, -1303,   653,
    8120,   739,   799,  8120,   735,   744,   669,   663, -1303,   671,
    2930,   -45, -1303,    -1,   705,   748, -1303,   -30,   678, -1303,
   -1303, 10651,   -29, -1303,   676,   635,   341, -1303,   679,   680,
     684, -1303,   -18,    65,  3219,   -39, -1303, 10651,   763, -1303,
       2,   686, -1303, -1303, -1303, -1303,   688, -1303,   -54, -1303,
   -1303, -1303,   -38,    81,   747,   626,   639,     7, -1303,   729,
    5820, -1303,   692,   698,    63, -1303, -1303,   693, -1303,   740,
   -1303, -1303,   -27,   712, 10651,  4953,   764, -1303, -1303,   765,
   10089,   766,  4953,   767,   -70,   737,   -17,   656, -1303, -1303,
   -1303, -1303, -1303,  5531, -1303, -1303, -1303,  4953,    -2,   299,
   -1303,   609,   332,   629,   630, -1303, -1303,   623,   224,   218,
     218,     4,   350,   350,   350,   350,   326,   326, -1303, -1303,
   10089, 10089, 10651, 10651, -1303,   709, -1303, -1303,   710, -1303,
   -1303, -1303,   129,   150,   363,   665, -1303,   169,   196, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,   652,
   -1303,   762, 10370,   753,  4953, -1303, -1303, -1303,   801,   754,
    4953,   735,   735,   652, -1303,   547,   735, -1303, -1303,   622,
   -1303, -1303,   624,   227, -1303, -1303, -1303, -1303, -1303, -1303,
     627, -1303, -1303,   141,   405,   802,  4953,    37, 10651,   735,
    4953, -1303,   730,   731,   797,   749, 10651, -1303, 10651, -1303,
   -1303,   732, -1303, -1303, -1303,   706,   772,   735,   752,   783,
     818,   735,   768, -1303, -1303, -1303,   736,   803,  4953,  4953,
     771,  4953,   804,  4953,   779,   -74, -1303,     5,   670, -1303,
   -1303,   471,   -29, -1303, -1303, -1303,   770, 10651, -1303, 10651,
   -1303, -1303,   743,  4953,   882, -1303,   185, -1303,    19, -1303,
   -1303,   897, -1303,   176,  4953,  4953,  4953,   432,  4953,  4953,
    4953,  4953,  4953,  4953,   808,  4953,  4953,   647,    -7,   750,
     526,   685,   781,   809,   773,   850, -1303,  4953, -1303,   522,
     826, -1303, 10651,   827, -1303, 10651,   782,   784, -1303,   306,
   -1303, -1303, -1303, 10651, -1303, 10651,  4953,   792,  4953,  4953,
      -6,   796, -1303,   776,   759, -1303,   689, -1303,  -129, -1303,
     365,   -48,   704,    -2,   365,  5531,  5531,   434, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303,    -2,   814,   -48, -1303,   672,
     898, -1303, -1303, -1303, -1303, -1303,   819, -1303, -1303, -1303,
    4953, -1303, 10651,   866,   134, -1303, -1303,  4953, -1303,   369,
   -1303, -1303, -1303, -1303, -1303,   937,   499, -1303, -1303, -1303,
    4953, -1303, -1303, -1303, -1303, -1303, -1303,   687,   183,   938,
   -1303,   435, -1303, -1303,   640,   642,   643,   389,   644,   477,
   -1303, -1303, -1303,   141,   805,   141,   874,   252,   789,   790,
   -1303, -1303,  9808,   399, -1303,  3508,   788,   794,   831,   806,
     810, -1303,  4953,   735,   862, -1303, -1303, -1303,   735,   862,
    3797, -1303, 10651, -1303, -1303,  4953, -1303, 10651, -1303,  4953,
    4953,   839,  4953,   836, -1303,   865,   867,  4953, 10651,   628,
     915, -1303, -1303, -1303,  4086,   811,   812, -1303, -1303, -1303,
     856, -1303,    33, -1303, -1303,   973, -1303, -1303,  4953, 10651,
   -1303, -1303,    43, -1303, -1303, -1303,   813,   761,   769, -1303,
   -1303, -1303,   778,   780, -1303, -1303, -1303, -1303, -1303,   758,
   10651,   815, -1303,   858, -1303,   647, -1303, -1303, -1303,  7265,
     685, -1303,  4953, 10651,   826, -1303,   735, -1303,   575, -1303,
     243,   890, -1303,  4953,   895,   764, -1303,   820,   822, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303,  4953, -1303, -1303,  4953,
     863,  4953, -1303, -1303,  5531, -1303, -1303, -1303, -1303, -1303,
      47,  5531,  5531,   296, -1303,   629, -1303, -1303,   122,  5531,
   -1303, -1303,   630,    -2,   733, -1303, -1303, -1303, -1303,   801,
   10089,   884,   918,   829, -1303, -1303, -1303, -1303, -1303,   175,
     985,   989,   175,   -52,   160,   181, -1303,   868, -1303,   141,
    -136,   716, -1303, -1303, 10651,   837,   -41, -1303, -1303,   840,
   -1303, -1303, -1303, -1303, -1303,   904,   926,   735,   862, -1303,
     849, -1303, -1303, -1303, -1303, -1303,  4953, -1303,  4953, 10651,
   10651, -1303,   390, -1303,  4953, -1303,   852, -1303, -1303,   882,
   10651,   151, -1303,   854,   882, 10651, -1303, -1303,  4953,  4953,
    4953,  4953,  4953, -1303,  4953,  4953, -1303, -1303,   179, -1303,
     859, -1303, -1303, -1303, -1303,   890, -1303, -1303, -1303,   735,
   -1303, -1303, -1303, -1303, -1303, -1303,  4953, -1303,   350,  5531,
    5531,   350,   358, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, 10089, -1303,   183,   183,   175, -1303,
   -1303, -1303,    29,   175,  1002,   785,   944, -1303,   944, -1303,
    4953,   184, -1303,   929, 10651,   793,   955,  4953, 10651,  4953,
   -1303,  4953,   735, -1303, -1303, -1303, -1303,   984, -1303, -1303,
   -1303, -1303,   -22,   882, 10651, -1303,   861,   882, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303,   939,  7265, -1303, -1303, -1303,
   -1303, -1303,   350,   350,  5531, -1303, -1303, -1303, -1303, -1303,
   -1303,   -48, -1303,   187, -1303,   193, -1303,   510,  4953,    64,
   10651,   -76,   816, 10089, -1303,   873, -1303, -1303,   862,   940,
     172,   318, -1303,   870,   882, -1303,   871, 10651, -1303,   350,
     817,   944, -1303, -1303, -1303,   522, -1303,   420,   420,   106,
     795, -1303, -1303, -1303, -1303, -1303,   828, 10651,   843, 10651,
     887,  4953, 10651, -1303, -1303,   979,   269, -1303, -1303, -1303,
   -1303,   894,   379, -1303, -1303, -1303,   886, -1303,   200, -1303,
   -1303, -1303, -1303, -1303, -1303,   106,   791,   774,   948,   860,
    4953, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
     965,   935, -1303,   141,  6109, 10651,   969, -1303, 10651, -1303,
     807,   787, -1303,   821, 10651,   201,  4953,  6398,  4953,   798,
     974,   935, -1303, -1303, -1303,  6398, 10651, -1303,   899,   910,
     823,   935, 10651, -1303,   876,   978, 10651,   824,  6398, -1303
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
       0,     0,   138,   136,   137,     0,     0,   585,     0,     0,
       0,     0,     0,   586,     0,     0,     0,     0,     0,   139
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1303, -1303,   855, -1303,   869,   875, -1303,   851, -1303,   571,
     581,  -509, -1303,   476,  -374, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,  -867,
   -1303, -1303, -1303, -1303,    75,   284,   726, -1303, -1303, -1303,
     711,   256, -1303, -1303, -1302,  -731, -1303,  -287, -1303, -1303,
     718,   721, -1303,   311, -1303,  -893, -1303, -1303,   -28, -1303,
   -1303, -1303, -1303, -1303,   337,   270, -1303, -1303,   -93, -1303,
   -1263,   879,   -21, -1303,   596,  -416, -1303, -1303, -1303, -1303,
     223, -1303, -1303,   844, -1303, -1303, -1303, -1303, -1303,   165,
    -521,  -658, -1303, -1303, -1303,    39, -1303, -1303,  -134,    30,
     -23, -1303, -1303, -1303,   -32, -1303, -1303,   188,   -26, -1296,
   -1303,   -19, -1085, -1303,   651,    50, -1303, -1303,    71, -1303,
   -1303,   590,   593, -1303,  -520,  -963,   569,   142,  -567,   137,
     138, -1303, -1303, -1303, -1303, -1303,   841, -1303, -1303, -1303,
   -1303, -1303,   838, -1047, -1303,  -108, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303,   -51, -1129, -1303, -1303,   248,    24, -1303,
    -556, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303, -1303,
    -897, -1303,    35, -1303,   441,  -700, -1303, -1303, -1303, -1303,
   -1303,  -302,  -295, -1078,  -909, -1303, -1303, -1303, -1303, -1303,
   -1303, -1303, -1303, -1303, -1303,   359,  -674,  -788, -1303,   331,
     -75,  -711, -1303, -1303, -1303, -1303, -1303, -1303, -1303,   682,
     691,  -440,   286,   133, -1303, -1303, -1303, -1303, -1303, -1303,
   -1303,    17, -1303, -1303,     9, -1303,  -352,  -106,    -9, -1303,
   -1303,   392, -1303, -1303,   178,   167,   -40,   396, -1303, -1303,
     180, -1303,  -748, -1303, -1303, -1303, -1303,  -172,  -842, -1303,
     -53,  -607, -1303,  -699, -1303, -1303, -1303, -1303,  -982, -1303,
   -1303, -1303, -1303,   -15,   186, -1303
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
       449,  1042,  1003,  1004,   782,   783,   784,   785,   916,   890,
     490,   770,   462,   895,  1079,  1204,   740,   482,     4,   494,
    1287,  1121,  1197,   612,   990,  1377,   754,  1113,  1114,   894,
     759,   898,   760,   761,  1437,   762,  1190,   764,   712,   961,
    1190,  1113,  1114,   496,  1276,   765,   766,  1148,   923,  1389,
     688,  1113,  1114,   750,   887,   751,   750,   476,  1090,   483,
     887,   611,   611,  1410,   695,   526,   966,   921,   866,  1348,
     853,   751,   526,   484,   868,  1296,  1297,  1185,  1343,   961,
     961,   907,   487,   719,   720,   750,   722,   723,   724,   725,
    1309,   750,  1145,   630,   731,   488,   967,   732,   971,   696,
      74,  1424,   893,   752,   671,   675,   934,   462,   520,   492,
     741,   961,    85,   839,  1115,   493,   942,  1186,   450,   969,
     747,   748,   917,  1055,   521,   922,  1215,  1464,  1115,  1461,
    1179,   888,  1116,  1349,  1117,   889,    99,   913,  1115,  1344,
     767,  1092,  1050,   768,   867,   527,  1116,   672,  1117,  1411,
     869,   568,   946,   609,  1029,   586,  1116,   908,  1117,  1113,
    1114,  1118,   943,  1482,   909,   104,  1310,   927,   569,   924,
     925,   695,  1146,  1044,  1045,  1118,  1443,   899,   118,   104,
    1113,   116,   801,  1046,   926,  1118,   610,   918,   753,   104,
     670,   673,   753,  1276,   713,   116,  1191,  1192,   854,  1225,
    1191,  1192,  1119,   588,  1390,   116,   696,  1047,  1334,   697,
    1379,  1248,   770,   770,  1110,  1121,  1270,   900,  1489,  1438,
     143,  1427,   404,  1093,   497,  1121,  1275,   631,  1010,   753,
    1048,   935,   753,  1211,   143,   970,  1318,  1091,  1507,  1201,
     910,  1335,   632,   972,   143,   753,  1115,  1418,  1513,   840,
     769,   854,   529,   409,  1428,   633,   753,   634,   530,  1336,
    1012,   531,   532,  1427,  1116,   594,  1117,   635,   596,   533,
     636,  1220,   834,  1443,  1235,   547,   626,  1113,   841,   842,
    1338,   843,   844,  1398,   383,  1116,  1421,  1117,   928,   929,
     621,   405,  1421,  1118,   622,  1444,  1428,   104,   652,  1480,
    1500,  1326,   607,   930,  1011,  1111,  1020,   483,   456,  1212,
     483,   575,  1180,   116,  1118,  1039,   608,   384,   124,     4,
     576,  1017,   880,  1021,  1375,  1013,  1113,   571,  1221,   949,
     457,   623,  1040,  1022,  1364,  1337,   964,  1449,   505,   467,
     468,  1156,  1226,   506,  1228,  1429,  1430,   406,  1431,  1432,
    1023,   961,   143,   572,   679,  1049,  1339,   599,   624,  1399,
    1158,   455,  1422,   606,  1327,   534,   573,   535,  1423,   617,
    1112,   822,  1041,   462,  1121,  1481,  1501,  1376,   645,   466,
    1313,   536,  1116,   646,  1117,   655,  1314,  1113,   658,   463,
    1431,  1432,  1474,   469,  1315,   462,   654,  1127,  1449,  1128,
     574,    74,   647,   388,   389,   390,   391,   537,  1028,  1420,
     659,  1118,   823,    85,  1031,   407,   408,   824,   625,  1198,
     978,   613,  1322,   662,   630,   464,  1066,   770,  1069,   664,
     665,  1116,   667,  1117,   669,   740,   614,    99,   676,   770,
    1169,   767,  1450,   615,   768,  1024,   465,   568,  1095,  1096,
    1503,   462,   577,   700,   683,   684,   687,   616,  1508,  1024,
    1118,   999,  1000,   694,   569,   578,   703,  1105,   711,  1106,
    1170,  1519,  1083,  1084,   716,  1086,   683,  1088,   751,  1032,
    1033,   796,   797,  1001,  1036,  1408,   472,   570,  1171,   979,
    1016,  1062,  1116,   733,  1117,   848,  1214,  1108,   729,   961,
     471,  1448,  1454,  1477,  1236,  1017,   736,  1058,  1129,  1130,
    1131,   508,  1134,  1135,  1136,  1137,  1138,  1139,  1342,  1141,
    1142,  1118,   978,  1039,   849,   850,   630,   851,   852,  1095,
    1096,   949,  1097,   550,   473,  1321,  1385,  1448,  1230,   575,
    1224,   551,   552,  1454,   553,  1384,   489,   575,   576,  1231,
    1175,   554,  1177,  1178,  1313,   555,   576,   556,   631,   751,
    1314,   499,   557,   500,   876,   795,   595,   879,  1315,  1362,
     798,   485,   597,   632,  1366,   980,   981,   982,   558,  1460,
     495,  1098,   366,   367,   368,   983,   633,   371,   634,   498,
     829,   979,   805,   984,  1208,   830,   750,  1155,   635,   985,
     986,   636,   559,   560,   561,   562,   563,   564,  1156,  1155,
     828,   589,   590,   961,  1218,  1440,   799,  1308,  1157,   799,
    1156,   799,   501,  1187,  1311,  1312,   823,  1158,  1188,  1388,
    1157,   824,   395,   396,  1388,   862,   863,   600,   857,  1158,
     451,   605,   871,   452,   504,   453,   837,   770,   454,   838,
     502,   845,   503,  1132,   846,  1133,  1245,   393,   394,   886,
     631,   462,   507,  1413,   462,  1034,  1035,  1416,   508,  1252,
     627,   628,   629,  1254,  1255,   632,  1257,   980,   981,   982,
     510,  1261,   897,   912,  1051,  1052,  1095,  1096,   633,   511,
     634,   513,   961,  1293,  1294,   984,  1462,  1463,   914,   512,
     635,  1199,   986,   636,  1431,  1432,   603,   604,   514,   939,
     779,   780,   786,   787,  1456,   788,   789,  1006,  1006,  1386,
    1387,  1246,   515,  1425,   809,   810,   811,   812,   813,   814,
     815,   816,   817,   818,   517,   948,  1290,   524,   525,   548,
     549,   962,  1382,  1383,   567,   579,   973,   949,   580,   582,
     581,   591,   598,   366,   601,   611,   618,   619,   649,   656,
    1304,   657,   663,  1305,   666,  1307,   668,   680,   689,   690,
     691,   693,  1490,   704,   366,   367,   368,   369,   370,   371,
     432,   962,   962,   962,   962,   452,   372,   454,   460,   475,
     707,   706,   714,   715,   717,   718,   721,   726,   739,   743,
     744,   749,   790,   791,  1292,   745,   806,   746,   792,   793,
     803,   378,   807,   962,   808,   831,   832,  1419,   835,   836,
     847,   856,   858,   860,   864,   859,   861,   877,   875,   878,
     865,   872,   881,   931,   873,  1054,   874,   891,   883,  1059,
    1355,   882,  1356,   379,   380,   945,   884,   892,  1360,  1057,
     896,   903,   932,   933,   904,   905,   906,  1068,   919,  1068,
     920,   936,  1368,  1369,  1370,  1371,  1372,   940,  1373,  1374,
     941,   947,   944,   968,   952,   955,   963,   965,   976,   995,
     997,  1008,   996,  1009,  1025,   824,  1030,   750,  1053,  1062,
    1381,  1065,  1072,  1037,  1073,  1353,  1038,   383,   654,  1043,
     654,  1076,  1060,  1061,  1071,  1077,  1078,  1085,  1081,  1109,
    1080,  1089,  1104,  1082,  1087,  1107,  1094,  1126,  1140,  1153,
    1149,   623,  1147,  1152,  1397,  1163,  1165,  1167,  1176,  1168,
     384,  1404,  1181,  1406,  1183,  1407,  1184,   366,   367,   368,
     369,   370,   371,  1164,  1205,  1206,   547,  1380,  1182,   372,
    1203,  1194,  1210,  1207,  1173,   373,  1174,     4,  1223,  1219,
    1229,  1247,  1233,  1240,  1227,  1242,   374,   375,  1232,  1241,
     376,  1256,  1258,   377,   378,  1259,  1264,  1260,  1269,  1272,
     386,  1243,  1397,  1278,  1282,  1244,  1267,  1268,  1156,  1284,
    1285,  1279,  1277,  1299,  1012,  1302,  1213,  1303,  1320,  1306,
    1280,  1325,  1281,  1209,  1324,  1330,   379,   380,   381,  1331,
    1345,  1347,  1350,  1340,  1352,   387,   388,   389,   390,   391,
    1351,  1354,  1391,   392,  1361,  1471,  1365,   393,   394,   395,
     396,  1378,  1039,   366,   367,   368,   369,   370,   371,  1400,
    1392,  1403,  1402,  1409,  1239,   372,  1415,  1441,  1466,  1417,
    1442,   373,   382,   962,  1487,  1455,  1457,  1468,  1485,  1250,
     383,  1470,   374,   375,  1473,  1476,   376,  1484,  1492,   377,
     378,  1479,  1459,   683,  1486,  1488,  1465,  1017,   687,  1494,
    1502,  1497,  1504,  1266,  1506,  1511,  1510,  1483,  1516,  1262,
    1515,  1439,   516,   384,   522,   737,  1505,  1273,  1512,   833,
    1496,  1217,   379,   380,   381,   738,   620,  1027,   648,   518,
    1274,  1426,   385,  1056,  1498,   519,  1019,  1286,  1323,   651,
    1166,   650,  1518,   523,   742,  1103,  1253,   540,  1359,  1263,
    1291,   729,  1251,  1301,  1237,  1154,   705,  1298,   757,   781,
     483,  1295,   758,   386,   736,   585,   587,  1271,   382,   915,
    1478,  1475,  1007,  1026,  1070,   698,   383,  1283,  1216,  1289,
     974,  1195,  1202,  1319,   699,   975,  1395,  1200,     0,  1333,
    1196,     0,     0,     0,     0,     0,     0,     0,   387,   388,
     389,   390,   391,  1317,     0,     0,   392,     0,     0,   384,
     393,   394,   395,   396,  -142,     0,     0,     0,     0,     0,
       0,   962,     0,     0,     0,     0,     0,     0,   385,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1346,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   386,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1357,  1358,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1363,     0,     0,     0,     0,  1367,     0,     0,     0,
       0,     0,     0,     0,   387,   388,   389,   390,   391,     0,
       0,     0,   392,     0,     0,     0,   393,   394,   395,   396,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   962,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1401,     0,     0,     0,  1405,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1414,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   483,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1436,     0,     0,   962,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1458,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1467,     0,
    1469,     0,     0,  1472,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1493,     0,     0,  1495,
       0,     0,     0,     0,     0,  1499,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     0,  1509,     0,     0,
       0,     2,     3,  1514,     4,     0,     0,  1517,     0,     5,
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
       0,     0,   122,     0,   123,   124,   125,     0,   126,   127,
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
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,   410,   411,     0,   412,   413,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,   418,   419,    21,
      22,   421,    24,    25,    26,    27,     0,   422,   423,    30,
     424,   425,   426,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,     0,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,     0,    72,    73,     0,     0,     0,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
       0,    85,     0,    86,    87,    88,    89,     0,    90,     0,
       0,     0,   430,    92,    93,    94,    95,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,   103,   104,     0,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,     0,     0,     0,     0,   119,   120,   121,     0,     0,
       0,   122,     0,   123,   124,   125,     0,     0,     0,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
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
       0,   410,   411,     0,   412,   413,   477,   415,   478,   479,
      13,    14,    15,    16,    17,    18,   418,   419,   480,    22,
     421,    24,    25,    26,    27,     0,   422,   423,    30,   424,
     425,   426,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   481,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   430,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   102,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   433,   112,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,   124,     0,     0,     0,     0,   128,     0,
     129,     0,   130,   131,   132,   133,   434,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   435,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   436,
     154,   438,   156,   439,   440,   159,   160,   161,   162,   163,
     164,   441,   166,   167,   442,   443,   444,   171,   445,   446,
     447,   175,   448,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     0,     0,     0,     0,     0,
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
      96,    97,    98,     0,   100,   101,   102,     0,     0,     0,
       0,     0,     0,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   433,   112,   113,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,     0,     0,     0,   122,
       0,   123,     0,     0,     0,     0,     0,   128,     0,   129,
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
     233,   234,   235,   236,   458,     0,     0,     0,     3,     0,
       0,     0,     0,     0,     0,   410,   411,     0,   412,   413,
     414,   415,   416,   417,    13,    14,    15,    16,    17,    18,
     418,   419,   420,    22,   421,    24,    25,    26,    27,     0,
     422,   423,    30,   424,   425,   426,    34,    35,    36,    37,
      38,    39,    40,    41,    42,   427,   428,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    62,     0,    63,    64,    65,   429,
       0,     0,    69,    70,    71,     0,     0,     0,    73,     0,
       0,     0,     0,    75,    76,    77,     0,     0,    80,    81,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,   430,    92,    93,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,     0,   100,
     101,   102,   459,     0,     0,   460,     0,     0,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   433,   112,   113,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,     0,     0,     0,   122,     0,   123,     0,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     434,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,     0,     0,   435,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   436,   437,   438,   156,   439,   440,   159,
     160,   161,   162,   163,   164,   441,   166,   167,   442,   443,
     444,   171,   445,   446,   447,   175,   448,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   458,
       0,     0,     0,     3,     0,   677,     0,     0,     0,     0,
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
      96,    97,    98,     0,   100,   101,   102,     0,     0,     0,
       0,     0,     0,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   433,   112,   113,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,     0,     0,     0,   122,
     678,   123,     0,     0,     0,     0,     0,     0,     0,   129,
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
     233,   234,   235,   236,   458,     0,     0,     0,     3,     0,
       0,     0,     0,     0,     0,   410,   411,     0,   412,   413,
     414,   415,   416,   417,    13,    14,    15,    16,    17,    18,
     418,   419,   420,    22,   421,    24,    25,    26,    27,     0,
     422,   423,    30,   424,   425,   426,    34,    35,    36,    37,
      38,    39,    40,    41,    42,   427,   428,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    62,     0,    63,    64,    65,   429,
       0,     0,    69,    70,    71,     0,     0,     0,    73,     0,
       0,     0,     0,    75,    76,    77,     0,     0,    80,    81,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,   430,    92,    93,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,     0,   100,
     101,   102,     0,     0,     0,     0,     0,     0,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   433,   112,   113,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,     0,     0,     0,   122,     0,   123,     0,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     434,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,     0,     0,   435,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   436,   437,   438,   156,   439,   440,   159,
     160,   161,   162,   163,   164,   441,   166,   167,   442,   443,
     444,   171,   445,   446,   447,   175,   448,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   491,
       0,     3,     0,     0,     0,     0,     0,     0,   410,   411,
       0,   412,   413,   414,   415,   416,   417,    13,    14,    15,
      16,    17,    18,   418,   419,   420,    22,   421,    24,    25,
      26,    27,     0,   422,   423,    30,   424,   425,   426,    34,
      35,    36,    37,    38,    39,    40,    41,    42,   427,   428,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,     0,     0,    62,     0,    63,
      64,    65,   429,     0,     0,    69,    70,    71,     0,     0,
       0,    73,     0,     0,     0,     0,    75,    76,    77,     0,
       0,    80,    81,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,   430,    92,
      93,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      98,     0,   100,   101,   102,     0,     0,     0,     0,     0,
       0,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     433,   112,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   121,     0,     0,     0,   122,     0,   123,
       0,     0,     0,     0,     0,     0,     0,   129,     0,   130,
     131,   132,   133,   434,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,     0,     0,   435,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   436,   437,   438,   156,
     439,   440,   159,   160,   161,   162,   163,   164,   441,   166,
     167,   442,   443,   444,   171,   445,   446,   447,   175,   448,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,     3,     0,     0,     0,     0,     0,     0,   410,
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
      97,    98,     0,   100,   101,   102,   431,     0,     0,   432,
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
      96,    97,    98,     0,   100,   101,   102,   474,     0,     0,
     475,     0,     0,   106,   107,     0,     0,     0,     0,   108,
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
       0,    96,    97,    98,     0,   100,   101,   102,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   433,   112,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,   660,   123,     0,     0,     0,     0,     0,   661,     0,
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
       0,   122,   701,   123,     0,     0,     0,     0,     0,   702,
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
       0,     0,     0,   410,   411,     0,   412,   413,   477,   415,
     478,   479,    13,    14,    15,    16,    17,    18,   418,   419,
     480,    22,   421,    24,    25,    26,    27,     0,   422,   423,
      30,   424,   425,   426,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
       0,     0,    62,     0,    63,    64,    65,   481,     0,     0,
      69,    70,    71,     0,     0,     0,    73,     0,     0,     0,
       0,    75,    76,    77,     0,     0,    80,    81,  1234,     0,
       0,     0,     0,     0,    86,    87,    88,    89,     0,    90,
       0,     0,     0,   430,    92,    93,     0,     0,     0,     0,
       0,     0,     0,    96,    97,    98,     0,   100,   101,   956,
       0,     0,     0,     0,     0,     0,   106,   107,     0,     0,
       0,     0,   108,   109,   110,   433,   112,   113,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   121,     0,
       0,     0,   122,     0,   123,   124,     0,     0,     0,     0,
       0,     0,   129,     0,   130,   131,   132,   133,   434,   135,
     136,   137,   138,   139,   140,     0,     0,   957,   142,     0,
       0,   435,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   436,   154,   438,   156,   439,   440,   159,   160,   161,
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
       0,     0,    75,    76,    77,     0,     0,    80,    81,     0,
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
     434,   135,   136,   137,   138,   139,   140,     0,     0,   141,
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
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         9,   843,   790,   791,   571,   572,   573,   574,   708,   683,
     116,   567,    21,   687,   881,   997,   525,    68,    20,   127,
    1149,   918,   985,   375,   772,  1288,   547,     8,     9,   687,
     550,    60,   552,   553,   110,   555,    88,   557,     7,   750,
      88,     8,     9,    21,  1122,   565,   566,   940,    86,    20,
     466,     8,     9,    86,    99,    88,    86,    66,   132,    68,
      99,    20,    20,    85,    30,    99,   136,   121,    99,   110,
      86,    88,    99,    82,    99,  1160,  1161,   206,   214,   790,
     791,    99,   103,   499,   500,    86,   502,   503,   504,   505,
      43,    86,    99,    92,   510,   104,   754,   513,   756,    65,
     102,  1397,   132,   136,   456,   457,    99,   116,    25,   118,
     526,   822,   114,   105,    95,   124,    53,   246,   142,   136,
     536,   537,   120,    86,    41,   179,  1019,  1429,    95,  1425,
     136,   176,   113,   174,   115,   136,   138,   176,    95,   275,
     142,   136,   853,   145,   175,   179,   113,   105,   115,   171,
     175,   147,   179,   157,   828,   142,   113,   175,   115,     8,
       9,   142,    99,  1465,    99,   146,   119,    86,   164,   207,
     208,    30,   179,    32,    33,   142,     4,   206,   165,   146,
       8,   162,   598,    42,   222,   142,   190,   185,   262,   146,
     149,   149,   262,  1271,   163,   162,   248,   249,   214,  1041,
     248,   249,   183,   311,   175,   162,    65,    66,   260,   175,
    1295,  1078,   768,   769,   914,  1112,   183,   246,  1481,   295,
     201,   157,   149,   897,   202,  1122,   183,   226,    99,   262,
      89,   224,   262,    99,   201,   756,  1199,   895,  1501,   987,
     175,  1223,   241,   763,   201,   262,    95,  1376,  1511,   241,
     252,   214,    45,   145,   190,   254,   262,   256,    51,    99,
     110,    54,    55,   157,   113,   316,   115,   266,   319,    62,
     269,    88,   624,     4,  1062,   284,   382,     8,   270,   271,
      99,   273,   274,    99,   157,   113,    99,   115,   207,   208,
      30,    86,    99,   142,    34,   123,   190,   146,   404,    99,
      99,   126,   170,   222,   175,   120,   137,   316,    26,   175,
     319,   189,   970,   162,   142,    88,   184,   190,   177,    20,
     198,   142,   674,   154,   145,   175,     8,   109,   145,   745,
      48,    71,   105,   137,   183,   175,   752,    19,   214,    56,
      57,    98,  1053,   219,  1055,   281,   282,   142,   284,   285,
     154,  1062,   201,   135,   460,   214,   175,   366,    98,   175,
     117,   145,   175,   372,   189,   158,   148,   160,   175,   378,
     185,    86,   145,   382,  1271,   175,   175,   198,   387,   142,
     258,   174,   113,   392,   115,   406,   264,     8,   409,   110,
     284,   285,   123,   110,   272,   404,   405,   221,    19,   223,
     182,   102,   275,   276,   277,   278,   279,   200,   824,  1391,
     431,   142,   127,   114,   830,   210,   211,   132,   158,   986,
      88,   155,  1210,   432,    92,   110,   866,   983,   868,   450,
     451,   113,   453,   115,   455,   944,   170,   138,   459,   995,
     134,   142,   124,   170,   145,   819,   110,   147,    58,    59,
    1497,   460,   126,   474,   463,   464,   465,   184,  1505,   833,
     142,   237,   238,   472,   164,   139,   475,   907,   489,   909,
     164,  1518,   888,   889,   495,   891,   485,   893,    88,   831,
     832,   589,   590,   259,   836,  1352,   145,   187,   182,   157,
     127,    92,   113,   514,   115,   241,   127,   913,   507,  1210,
      54,  1410,  1411,   124,   105,   142,   515,   859,   924,   925,
     926,   142,   928,   929,   930,   931,   932,   933,  1229,   935,
     936,   142,    88,    88,   270,   271,    92,   273,   274,    58,
      59,   947,    61,   122,   145,  1209,  1324,  1446,   286,   189,
     105,   130,   131,  1452,   133,   187,   142,   189,   198,   297,
     966,   140,   968,   969,   258,   144,   198,   146,   226,    88,
     264,   214,   151,   216,   670,   586,   318,   673,   272,  1269,
     591,   110,   324,   241,  1274,   243,   244,   245,   167,  1421,
     142,   110,    34,    35,    36,   253,   254,    39,   256,   204,
     127,   157,   601,   261,  1010,   132,    86,    87,   266,   267,
     268,   269,   191,   192,   193,   194,   195,   196,    98,    87,
     619,   180,   181,  1324,  1030,  1403,   592,  1184,   108,   595,
      98,   597,   145,   258,  1191,  1192,   127,   117,   263,  1328,
     108,   132,   289,   290,  1333,   656,   657,   367,   647,   117,
     142,   371,   663,   145,   214,   142,   239,  1203,   145,   242,
     214,   239,   216,   221,   242,   223,  1072,   287,   288,   680,
     226,   670,   110,  1363,   673,   118,   119,  1367,   142,  1085,
     210,   211,   212,  1089,  1090,   241,  1092,   243,   244,   245,
     227,  1097,   691,   704,   279,   280,    58,    59,   254,   231,
     256,   145,  1403,   118,   119,   261,  1427,  1428,   707,   231,
     266,   267,   268,   269,   284,   285,   369,   370,   142,   730,
     568,   569,   575,   576,  1414,   577,   578,   792,   793,  1326,
    1327,  1073,   110,  1397,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,     0,   744,  1152,   179,   179,   156,
      84,   750,  1309,  1310,   251,    68,   767,  1163,   188,    94,
      93,   143,   145,    34,    34,    20,   141,   110,   291,   142,
    1176,   142,   142,  1179,   175,  1181,   175,   142,   268,   268,
     110,   110,  1483,   142,    34,    35,    36,    37,    38,    39,
     145,   790,   791,   792,   793,   145,    46,   145,   145,   145,
      27,   175,    15,   175,   202,    20,   175,   220,    25,   158,
     110,    99,   220,    86,  1156,   159,    20,   159,    86,    86,
     145,    71,    99,   822,    99,   149,   149,  1384,   117,   122,
      20,   286,   292,   142,   175,   122,   172,    88,   175,    30,
     172,   172,    88,    86,   172,   856,   172,   132,   175,   860,
    1256,   172,  1258,   103,   104,   105,   175,    99,  1264,   858,
     172,   175,   226,   214,   175,   175,   172,   866,   172,   868,
     172,   132,  1278,  1279,  1280,  1281,  1282,   175,  1284,  1285,
     172,   159,   179,   136,   110,   110,   110,   110,   269,   250,
     257,   172,   252,   173,   122,   132,   132,    86,    86,    92,
    1306,   142,   186,   271,   122,  1247,   272,   157,   907,   272,
     909,   149,   172,   172,   172,   122,    88,   136,   172,    27,
     142,   132,   142,   110,   110,   172,   246,    20,   110,   110,
     235,    71,   172,   142,  1340,    99,    99,   145,   136,   145,
     190,  1347,   136,  1349,   175,  1351,   247,    34,    35,    36,
      37,    38,    39,   952,   272,    47,   955,  1299,   172,    46,
     136,   247,    86,   134,   963,    52,   965,    20,    20,   272,
      86,    99,   172,   175,   159,   134,    63,    64,   179,   175,
      67,   132,   136,    70,    71,   110,    61,   110,   122,     6,
     240,   175,  1398,   222,   226,   175,   175,   175,    98,   174,
     132,   222,   179,    98,   110,   175,  1017,   175,   265,   136,
     222,   172,   222,  1012,    86,    20,   103,   104,   105,    20,
     294,   174,   172,   145,    88,   275,   276,   277,   278,   279,
     116,   172,    20,   283,   172,  1441,   172,   287,   288,   289,
     290,   172,    88,    34,    35,    36,    37,    38,    39,   110,
     255,    86,   249,    59,  1065,    46,   185,   174,   220,   110,
     110,    52,   149,  1062,  1470,   185,   185,   214,   110,  1080,
     157,   174,    63,    64,    85,   171,    67,   293,  1484,    70,
      71,   185,   255,  1082,   214,   110,   281,   142,  1087,   110,
    1496,   294,  1498,  1104,   110,   175,   187,   296,   110,  1098,
     214,   275,   237,   190,   243,   524,   298,  1118,   275,   623,
     293,  1026,   103,   104,   105,   524,   380,   823,   397,   240,
    1119,  1398,   209,   857,   293,   240,   805,  1145,  1211,   401,
     955,   400,   298,   244,   528,   902,  1087,   283,  1262,  1099,
    1153,  1140,  1082,  1165,  1063,   947,   485,  1163,   548,   570,
    1149,  1160,   549,   240,  1153,   304,   308,  1112,   149,   708,
    1452,  1446,   793,   822,   868,   473,   157,  1140,  1025,  1150,
     768,   983,   995,  1203,   473,   769,  1338,   987,    -1,  1222,
     984,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,   276,
     277,   278,   279,  1198,    -1,    -1,   283,    -1,    -1,   190,
     287,   288,   289,   290,   291,    -1,    -1,    -1,    -1,    -1,
      -1,  1210,    -1,    -1,    -1,    -1,    -1,    -1,   209,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1234,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   240,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1259,  1260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1270,    -1,    -1,    -1,    -1,  1275,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   275,   276,   277,   278,   279,    -1,
      -1,    -1,   283,    -1,    -1,    -1,   287,   288,   289,   290,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1324,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1344,    -1,    -1,    -1,  1348,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1364,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1376,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1400,    -1,    -1,  1403,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1417,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1437,    -1,
    1439,    -1,    -1,  1442,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1485,    -1,    -1,  1488,
      -1,    -1,    -1,    -1,    -1,  1494,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    10,    -1,    -1,  1506,    -1,    -1,
      -1,    17,    18,  1512,    20,    -1,    -1,  1516,    -1,    25,
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
      -1,    -1,   145,   146,    -1,   148,   149,    -1,    -1,    -1,
      -1,   154,   155,   156,   157,   158,   159,   160,   161,   162,
      -1,    -1,    -1,    -1,    -1,   168,   169,   170,    -1,    -1,
      -1,   174,    -1,   176,   177,   178,    -1,    -1,    -1,   182,
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
     174,    -1,   176,   177,    -1,    -1,    -1,    -1,   182,    -1,
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
     294,   295,   296,   297,   298,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,   176,    -1,    -1,    -1,    -1,    -1,   182,    -1,   184,
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
     295,   296,   297,   298,    14,    -1,    -1,    -1,    18,    -1,
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
     290,   291,   292,   293,   294,   295,   296,   297,   298,    14,
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
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,    14,    -1,    -1,    -1,    18,    -1,
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
     290,   291,   292,   293,   294,   295,   296,   297,   298,    16,
      -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
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
      -1,   103,   104,   105,    -1,    -1,   108,   109,   110,    -1,
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
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298
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
      99,   175,   389,   457,   389,   298,   110,   384,   457,   542,
     187,   175,   275,   384,   542,   214,   110,   542,   298,   457
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
       3,     1,     2,     2,     3,    12,    14,    14,    14,    23,
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
     542,   286,   275,   542,   110,   542,   293,   281,   294,   457,
      -1,    25,   363,   291,   292,   542,   286,   275,   542,   295,
     214,   110,   542,   293,   389,    -1,    25,   363,   291,   292,
     542,   286,   214,   110,   542,   220,   296,   515,   293,   389,
      -1,    25,   363,   291,   292,   542,   297,   294,   249,   275,
     542,   214,   110,   542,   298,   457,   187,   275,   542,   214,
     110,   542,   298,   457,    -1,   364,   365,    -1,   365,   364,
      -1,    -1,   287,    -1,   288,    -1,    -1,   290,    -1,   289,
      -1,    25,    52,   170,    -1,    25,    52,   184,    -1,   145,
     175,    -1,   145,   381,   175,    -1,   145,   175,    86,   511,
      -1,   145,   381,   175,    86,   511,    -1,   228,   369,    -1,
     142,   370,   386,   172,    -1,   370,   371,   179,    -1,    -1,
     371,    99,   372,    -1,    25,   372,    -1,   350,    -1,   350,
     132,   389,    -1,    50,   110,   542,   132,   389,    -1,   229,
     227,   389,    -1,   233,   145,   389,   175,   369,    -1,   230,
     231,    -1,   232,   231,    -1,    25,   378,    -1,    25,    38,
     378,    -1,    25,    37,   378,    -1,   379,    -1,    39,   379,
      -1,    35,   379,    -1,    36,   380,    -1,    34,   542,   367,
     384,    -1,    34,   542,   367,   127,    -1,    34,   542,   367,
     369,    -1,    34,   542,   367,   127,    -1,   382,    -1,   381,
      99,   382,    -1,   110,   542,    -1,   110,   542,   510,    -1,
     142,   386,   172,    -1,   142,   386,   172,    -1,   386,    -1,
     388,    -1,   388,   387,    -1,   179,    -1,   387,   388,   179,
      -1,   389,    -1,   388,    99,   389,    -1,   390,    -1,   427,
      -1,   430,    -1,   433,    -1,   434,    -1,   529,    -1,   530,
      -1,   532,    -1,   531,    -1,   533,    -1,   536,    -1,   544,
      -1,   374,    -1,   375,    -1,   376,    -1,   373,    -1,   368,
      -1,   399,   391,    -1,   174,   389,    -1,    56,   268,    -1,
      57,   268,    -1,   206,    -1,   246,    -1,    60,   246,    -1,
     393,   411,    61,   389,    -1,   393,    61,   389,    -1,    54,
     392,   410,   394,   394,    -1,    54,   392,   410,   394,    -1,
      62,   110,   542,    -1,   401,    -1,   406,    -1,   395,    -1,
     397,    -1,   415,    -1,   420,    -1,   416,    -1,   396,    -1,
     397,    -1,   399,   398,    -1,    54,   110,    -1,    55,    54,
     110,    -1,   400,   402,    -1,   403,    -1,   402,    99,   110,
     403,    -1,   542,   136,   389,    -1,   542,   510,   136,   389,
      -1,   542,   404,   136,   389,    -1,   542,   510,   404,   136,
     389,    -1,   542,   405,   136,   389,    -1,   542,   510,   405,
     136,   389,    -1,   542,   404,   405,   136,   389,    -1,   542,
     510,   404,   405,   136,   389,    -1,    88,   110,   542,    -1,
     262,   110,   542,    -1,    51,   110,   407,    -1,   409,    -1,
     407,    99,   110,   409,    -1,   414,    -1,   408,    99,   110,
     414,    -1,   542,   132,   389,    -1,   542,   510,   132,   389,
      -1,   542,   405,   132,   389,    -1,   542,   510,   405,   132,
     389,    -1,   110,   542,   136,   389,    -1,   110,   542,   510,
     136,   389,    -1,   412,    -1,   110,   542,    -1,   110,   542,
     412,    -1,   404,    -1,   404,   413,    -1,   413,    -1,    58,
     110,   542,    59,   110,   542,    -1,    59,   110,   542,    -1,
      58,   110,   542,    -1,   542,    -1,   200,   389,    -1,   160,
     159,   417,    -1,   418,    -1,   417,    99,   418,    -1,   110,
     542,    -1,   110,   542,   419,    -1,    98,   540,    -1,   158,
     159,   421,    -1,    45,   158,   159,   421,    -1,   422,    -1,
     421,    99,   422,    -1,   389,    -1,   389,   423,    -1,   424,
      -1,   425,    -1,   426,    -1,   424,   425,    -1,   424,   426,
      -1,   425,   426,    -1,   424,   425,   426,    -1,    87,    -1,
     108,    -1,   117,   118,    -1,   117,   119,    -1,    98,   540,
      -1,    44,   110,   428,   176,   389,    -1,   125,   110,   428,
     176,   389,    -1,   429,    -1,   428,    99,   110,   429,    -1,
     542,   136,   389,    -1,   542,   510,   136,   389,    -1,    29,
     145,   386,   175,   431,   105,   174,   389,    -1,    29,   145,
     386,   175,   431,   105,   110,   542,   174,   389,    -1,   432,
      -1,   431,   432,    -1,    92,   511,   174,   389,    -1,    92,
     110,   542,    86,   511,   174,   389,    -1,    40,   145,   386,
     175,   186,   389,   116,   389,    -1,   435,    -1,   434,   156,
     435,    -1,   436,    -1,   435,    84,   436,    -1,   438,    -1,
     438,   451,   438,    -1,   438,   452,   438,    -1,   438,   122,
     438,    -1,   438,   151,   438,    -1,    -1,   438,   146,   437,
     438,    -1,   438,   144,   438,    -1,   438,   133,   438,    -1,
     438,   131,   438,    -1,   439,    -1,   439,   251,   545,    -1,
     439,   251,   545,   579,    -1,   440,    -1,   440,   187,   440,
      -1,   441,    -1,   440,   164,   441,    -1,   440,   147,   441,
      -1,   442,    -1,   441,   182,   442,    -1,   441,   109,   442,
      -1,   441,   135,   442,    -1,   441,   148,   442,    -1,   443,
      -1,   442,   189,   443,    -1,   442,   198,   443,    -1,   444,
      -1,   443,   139,   444,    -1,   443,   126,   444,    -1,   445,
      -1,   445,    68,   220,   511,    -1,   446,    -1,   446,   188,
      86,   511,    -1,   447,    -1,   447,    93,    86,   509,    -1,
     448,    -1,   448,    94,    86,   509,    -1,   450,    -1,   449,
     450,    -1,   164,    -1,   147,    -1,   449,   164,    -1,   449,
     147,    -1,   453,    -1,   457,    -1,   454,    -1,   191,    -1,
     196,    -1,   195,    -1,   194,    -1,   193,    -1,   192,    -1,
     140,    -1,   167,    -1,   130,    -1,    28,   142,   386,   172,
      -1,    28,   211,   142,   386,   172,    -1,    28,   210,   142,
     386,   172,    -1,    28,    86,   525,   142,   386,   172,    -1,
     455,   142,   172,    -1,   455,   142,   386,   172,    -1,   456,
      -1,   455,   456,    -1,   165,   542,    15,    -1,   165,    16,
      -1,   458,    -1,   458,   459,    -1,   181,   459,    -1,   459,
      -1,   180,    -1,   460,    -1,   460,   180,   459,    -1,   460,
     181,   459,    -1,   461,    -1,   470,    -1,   462,    -1,   462,
     471,    -1,   465,    -1,   465,   471,    -1,   463,   467,    -1,
     464,    -1,    97,    -1,   106,    -1,    90,    -1,   178,    -1,
     107,    -1,   129,    -1,   128,    -1,   467,    -1,    91,   467,
      -1,   466,   467,    -1,   112,    -1,   161,    -1,    82,    -1,
     169,    -1,   168,    -1,    83,    -1,   515,    -1,   468,    -1,
     542,    -1,   469,    -1,   182,    -1,    10,    -1,    17,    -1,
     473,    -1,   473,   471,    -1,   472,    -1,   471,   472,    -1,
     143,   386,   173,    -1,   474,    -1,   476,    -1,   477,    -1,
     478,    -1,   481,    -1,   483,    -1,   479,    -1,   480,    -1,
     475,    -1,   527,    -1,   102,    -1,   138,    -1,   114,    -1,
     110,   542,    -1,   145,   175,    -1,   145,   386,   175,    -1,
     111,    -1,   157,   142,   386,   172,    -1,   190,   142,   386,
     172,    -1,   542,   145,   175,    -1,   542,   145,   482,   175,
      -1,   389,    -1,   482,    99,   389,    -1,   484,    -1,   502,
      -1,   485,    -1,   499,    -1,   500,    -1,   146,   542,   489,
     120,    -1,   146,   542,   487,   489,   120,    -1,   146,   542,
     489,   185,   183,   542,   489,   185,    -1,   146,   542,   489,
     185,   486,   183,   542,   489,   185,    -1,   146,   542,   487,
     489,   185,   183,   542,   489,   185,    -1,   146,   542,   487,
     489,   185,   486,   183,   542,   489,   185,    -1,   497,    -1,
     486,   497,    -1,   488,    -1,   487,   488,    -1,    27,   542,
     489,   122,   489,   490,    -1,    -1,    27,    -1,   171,   491,
     171,    -1,    85,   493,    85,    -1,    -1,   492,    -1,   124,
      -1,   495,    -1,   492,   124,    -1,   492,   495,    -1,    -1,
     494,    -1,   123,    -1,   496,    -1,   494,   123,    -1,   494,
     496,    -1,    19,    -1,   498,    -1,     4,    -1,   498,    -1,
     484,    -1,     9,    -1,   501,    -1,   498,    -1,     8,    -1,
     113,    -1,   115,    -1,   383,    -1,   201,    21,   202,    -1,
     201,   202,    -1,   162,   541,   163,    -1,   162,   541,     7,
      -1,    95,     6,    -1,   503,    -1,   504,    -1,   505,    -1,
     506,    -1,   507,    -1,   508,    -1,    31,   142,   386,   172,
      -1,    30,   542,   142,   172,    -1,    30,   542,   142,   386,
     172,    -1,    30,   142,   386,   172,   142,   172,    -1,    30,
     142,   386,   172,   142,   386,   172,    -1,    89,   542,   142,
     172,    -1,    89,   542,   142,   386,   172,    -1,    89,   142,
     386,   172,   142,   172,    -1,    89,   142,   386,   172,   142,
     386,   172,    -1,    32,   142,   386,   172,    -1,    33,   142,
     386,   172,    -1,    42,   541,   142,   172,    -1,    42,   541,
     142,   386,   172,    -1,    42,   142,   386,   172,   142,   172,
      -1,    42,   142,   386,   172,   142,   386,   172,    -1,   514,
      -1,   514,   134,    -1,    86,   511,    -1,   513,    -1,   513,
     512,    -1,   199,   145,   175,    -1,   134,    -1,   182,    -1,
     164,    -1,   514,    -1,   515,    -1,   141,   145,   175,    -1,
     542,    -1,   517,    -1,   523,    -1,   521,    -1,   524,    -1,
     522,    -1,   520,    -1,   519,    -1,   518,    -1,   516,    -1,
     214,   145,   175,    -1,    66,   145,   175,    -1,    66,   145,
     523,   175,    -1,    66,   145,   524,   175,    -1,    32,   145,
     175,    -1,    33,   145,   175,    -1,    42,   145,   175,    -1,
      42,   145,   541,   175,    -1,    42,   145,    20,   175,    -1,
      89,   145,   175,    -1,    89,   145,   542,   175,    -1,    89,
     145,   542,    99,   525,   175,    -1,    89,   145,   182,   175,
      -1,    89,   145,   182,    99,   525,   175,    -1,   177,   542,
     175,    -1,    30,   145,   175,    -1,    30,   145,   542,   175,
      -1,    30,   145,   542,    99,   525,   175,    -1,    30,   145,
     542,    99,   526,   175,    -1,    30,   145,   182,   175,    -1,
      30,   145,   182,    99,   525,   175,    -1,    30,   145,   182,
      99,   526,   175,    -1,    65,   145,   542,   175,    -1,   542,
      -1,   542,   134,    -1,    20,    -1,    25,   209,   210,    -1,
      25,   209,   211,    -1,    25,   209,   212,    -1,   215,   214,
     389,   222,   389,    -1,   215,   214,   389,    86,   221,   222,
     389,    -1,   215,   214,   389,    86,   223,   222,   389,    -1,
     215,   214,   389,   207,   389,    -1,   215,   214,   389,   208,
     389,    -1,   215,   216,   389,   222,   389,    -1,   215,   216,
     389,    86,   221,   222,   389,    -1,   215,   216,   389,    86,
     223,   222,   389,    -1,   215,   216,   389,   207,   389,    -1,
     215,   216,   389,   208,   389,    -1,   213,   214,   389,    -1,
     213,   216,   389,    -1,   218,   214,   389,   226,   389,    -1,
     218,   219,   220,   214,   389,   226,   389,    -1,   217,   214,
     389,    86,   389,    -1,   225,   110,   534,   224,   389,   174,
     389,    -1,   535,    -1,   534,    99,   110,   535,    -1,   542,
     132,   389,    -1,   234,   142,   386,   172,   537,    -1,   538,
      -1,   537,   538,    -1,   235,   539,   384,    -1,   235,   539,
     145,   110,   542,   175,   384,    -1,   235,   539,   145,   110,
     542,    99,   110,   542,   175,   384,    -1,   235,   539,   145,
     110,   542,    99,   110,   542,    99,   110,   542,   175,   384,
      -1,   468,    -1,   539,   198,   468,    -1,    20,    -1,    14,
      -1,   542,    -1,    18,    -1,   543,    -1,   203,    -1,   117,
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
      -1,   283,    -1,   281,    -1,   282,    -1,   286,    -1,   284,
      -1,   285,    -1,    71,    -1,    72,    -1,    73,    -1,    74,
      -1,    75,    -1,    76,    -1,    77,    -1,    78,    -1,    79,
      -1,    80,    -1,    81,    -1,   275,    -1,   276,    -1,   277,
      -1,   278,    -1,   279,    -1,   280,    -1,   287,    -1,   288,
      -1,   289,    -1,   290,    -1,   291,    -1,   292,    -1,   293,
      -1,   294,    -1,   295,    -1,   296,    -1,   297,    -1,   298,
      -1,   236,   110,   408,    53,   142,   389,   172,    -1,    53,
     142,   389,   172,    -1,   547,    -1,   547,   546,    -1,   547,
     267,   439,    -1,   547,   546,   267,   439,    -1,   556,    -1,
     554,    -1,   546,   556,    -1,   546,   554,    -1,   548,    -1,
     547,   253,   548,    -1,   549,    -1,   548,   250,   549,    -1,
     550,    -1,   549,   252,   136,   550,    -1,   551,    -1,   252,
     551,    -1,   552,    -1,   552,   575,    -1,   145,   545,   175,
      -1,   553,    -1,   553,   571,    -1,   474,    -1,   142,   386,
     172,    -1,   555,    -1,   574,    -1,   573,    -1,   576,    -1,
     570,    -1,   157,    -1,   557,    -1,   558,    -1,   559,    -1,
     560,    -1,   563,    -1,   568,    -1,   569,    -1,   256,    -1,
     266,    -1,    92,   239,    -1,    92,   242,    -1,   226,   241,
      -1,   269,   241,    -1,   241,   239,    -1,   241,   242,    -1,
     226,   270,    -1,   269,   270,    -1,   226,   273,   562,    -1,
     226,   273,   105,    -1,   226,   273,   145,   562,   175,    -1,
     226,   273,   145,   562,    99,   561,   175,    -1,   226,   273,
     145,   105,   175,    -1,   226,   273,   145,   105,    99,   561,
     175,    -1,   269,   273,    -1,   562,    -1,   561,    99,   562,
      -1,    88,    20,    -1,    88,    20,   260,    20,    -1,    88,
      20,   572,   255,    -1,    88,    20,   260,    20,   572,   255,
      -1,   226,   271,   272,   565,    -1,   226,   271,   272,   565,
     564,    -1,   226,   105,   271,   272,    -1,   226,   105,   271,
     272,   564,    -1,   269,   271,   272,    -1,   567,    -1,   564,
     567,    -1,    88,    20,    -1,   145,   566,   175,    -1,    20,
      -1,   566,    20,    -1,   189,   565,    -1,   126,   565,    -1,
     254,    20,    -1,   226,   274,    -1,   269,   274,    -1,    88,
     206,    -1,    88,   246,    -1,   245,   247,    -1,   238,    -1,
     238,    47,    -1,   237,    -1,   237,   272,    -1,   259,    -1,
     248,   442,    -1,    88,   119,   442,    -1,    88,    43,   442,
      -1,   249,   442,   187,   442,    -1,   244,   572,   577,    -1,
     268,   442,   577,    -1,   257,   572,   265,    -1,   261,   578,
      -1,   243,   578,    -1,   272,    -1,   264,    -1,   258,    -1,
     263,    -1,   258,    -1,   269,   247,   442,    -1
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
     457,   461,   463,   466,   469,   473,   486,   501,   516,   531,
     555,   558,   561,   562,   564,   566,   567,   569,   571,   575,
     579,   582,   586,   591,   597,   600,   605,   609,   610,   614,
     617,   619,   623,   629,   633,   639,   642,   645,   648,   652,
     656,   658,   661,   664,   667,   672,   677,   682,   687,   689,
     693,   696,   700,   704,   708,   710,   712,   715,   717,   721,
     723,   727,   729,   731,   733,   735,   737,   739,   741,   743,
     745,   747,   749,   751,   753,   755,   757,   759,   761,   764,
     767,   770,   773,   775,   777,   780,   785,   789,   795,   800,
     804,   806,   808,   810,   812,   814,   816,   818,   820,   822,
     825,   828,   832,   835,   837,   842,   846,   851,   856,   862,
     867,   873,   879,   886,   890,   894,   898,   900,   905,   907,
     912,   916,   921,   926,   932,   937,   943,   945,   948,   952,
     954,   957,   959,   966,   970,   974,   976,   979,   983,   985,
     989,   992,   996,   999,  1003,  1008,  1010,  1014,  1016,  1019,
    1021,  1023,  1025,  1028,  1031,  1034,  1038,  1040,  1042,  1045,
    1048,  1051,  1057,  1063,  1065,  1070,  1074,  1079,  1088,  1099,
    1101,  1104,  1109,  1117,  1126,  1128,  1132,  1134,  1138,  1140,
    1144,  1148,  1152,  1156,  1157,  1162,  1166,  1170,  1174,  1176,
    1180,  1185,  1187,  1191,  1193,  1197,  1201,  1203,  1207,  1211,
    1215,  1219,  1221,  1225,  1229,  1231,  1235,  1239,  1241,  1246,
    1248,  1253,  1255,  1260,  1262,  1267,  1269,  1272,  1274,  1276,
    1279,  1282,  1284,  1286,  1288,  1290,  1292,  1294,  1296,  1298,
    1300,  1302,  1304,  1306,  1311,  1317,  1323,  1330,  1334,  1339,
    1341,  1344,  1348,  1351,  1353,  1356,  1359,  1361,  1363,  1365,
    1369,  1373,  1375,  1377,  1379,  1382,  1384,  1387,  1390,  1392,
    1394,  1396,  1398,  1400,  1402,  1404,  1406,  1408,  1411,  1414,
    1416,  1418,  1420,  1422,  1424,  1426,  1428,  1430,  1432,  1434,
    1436,  1438,  1440,  1442,  1445,  1447,  1450,  1454,  1456,  1458,
    1460,  1462,  1464,  1466,  1468,  1470,  1472,  1474,  1476,  1478,
    1480,  1483,  1486,  1490,  1492,  1497,  1502,  1506,  1511,  1513,
    1517,  1519,  1521,  1523,  1525,  1527,  1532,  1538,  1547,  1557,
    1567,  1578,  1580,  1583,  1585,  1588,  1595,  1596,  1598,  1602,
    1606,  1607,  1609,  1611,  1613,  1616,  1619,  1620,  1622,  1624,
    1626,  1629,  1632,  1634,  1636,  1638,  1640,  1642,  1644,  1646,
    1648,  1650,  1652,  1654,  1656,  1660,  1663,  1667,  1671,  1674,
    1676,  1678,  1680,  1682,  1684,  1686,  1691,  1696,  1702,  1709,
    1717,  1722,  1728,  1735,  1743,  1748,  1753,  1758,  1764,  1771,
    1779,  1781,  1784,  1787,  1789,  1792,  1796,  1798,  1800,  1802,
    1804,  1806,  1810,  1812,  1814,  1816,  1818,  1820,  1822,  1824,
    1826,  1828,  1830,  1834,  1838,  1843,  1848,  1852,  1856,  1860,
    1865,  1870,  1874,  1879,  1886,  1891,  1898,  1902,  1906,  1911,
    1918,  1925,  1930,  1937,  1944,  1949,  1951,  1954,  1956,  1960,
    1964,  1968,  1974,  1982,  1990,  1996,  2002,  2008,  2016,  2024,
    2030,  2036,  2040,  2044,  2050,  2058,  2064,  2072,  2074,  2079,
    2083,  2089,  2091,  2094,  2098,  2106,  2117,  2131,  2133,  2137,
    2139,  2141,  2143,  2145,  2147,  2149,  2151,  2153,  2155,  2157,
    2159,  2161,  2163,  2165,  2167,  2169,  2171,  2173,  2175,  2177,
    2179,  2181,  2183,  2185,  2187,  2189,  2191,  2193,  2195,  2197,
    2199,  2201,  2203,  2205,  2207,  2209,  2211,  2213,  2215,  2217,
    2219,  2221,  2223,  2225,  2227,  2229,  2231,  2233,  2235,  2237,
    2239,  2241,  2243,  2245,  2247,  2249,  2251,  2253,  2255,  2257,
    2259,  2261,  2263,  2265,  2267,  2269,  2271,  2273,  2275,  2277,
    2279,  2281,  2283,  2285,  2287,  2289,  2291,  2293,  2295,  2297,
    2299,  2301,  2303,  2305,  2307,  2309,  2311,  2313,  2315,  2317,
    2319,  2321,  2323,  2325,  2327,  2329,  2331,  2333,  2335,  2337,
    2339,  2341,  2343,  2345,  2347,  2349,  2351,  2353,  2355,  2357,
    2359,  2361,  2363,  2365,  2367,  2369,  2371,  2373,  2375,  2377,
    2379,  2381,  2383,  2385,  2387,  2389,  2391,  2393,  2395,  2397,
    2399,  2401,  2403,  2405,  2407,  2409,  2411,  2413,  2415,  2417,
    2419,  2421,  2423,  2425,  2427,  2429,  2431,  2433,  2435,  2437,
    2439,  2441,  2443,  2445,  2447,  2449,  2451,  2453,  2455,  2457,
    2459,  2461,  2463,  2465,  2467,  2469,  2471,  2473,  2475,  2477,
    2479,  2481,  2483,  2485,  2487,  2489,  2491,  2493,  2495,  2497,
    2499,  2501,  2503,  2505,  2507,  2509,  2511,  2513,  2515,  2517,
    2519,  2521,  2523,  2525,  2527,  2529,  2531,  2533,  2535,  2537,
    2539,  2541,  2543,  2545,  2547,  2549,  2551,  2559,  2564,  2566,
    2569,  2573,  2578,  2580,  2582,  2585,  2588,  2590,  2594,  2596,
    2600,  2602,  2607,  2609,  2612,  2614,  2617,  2621,  2623,  2626,
    2628,  2632,  2634,  2636,  2638,  2640,  2642,  2644,  2646,  2648,
    2650,  2652,  2654,  2656,  2658,  2660,  2662,  2665,  2668,  2671,
    2674,  2677,  2680,  2683,  2686,  2690,  2694,  2700,  2708,  2714,
    2722,  2725,  2727,  2731,  2734,  2739,  2744,  2751,  2756,  2762,
    2767,  2773,  2777,  2779,  2782,  2785,  2789,  2791,  2794,  2797,
    2800,  2803,  2806,  2809,  2812,  2815,  2818,  2820,  2823,  2825,
    2828,  2830,  2833,  2837,  2841,  2846,  2850,  2854,  2858,  2861,
    2864,  2866,  2868,  2870,  2872,  2874
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
  const int xquery_parser::yylast_ = 10949;
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
#line 14260 "/home/fx/dev/zorba/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6185 "/home/fx/dev/zorba/src/compiler/parser/xquery_parser.y"


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

