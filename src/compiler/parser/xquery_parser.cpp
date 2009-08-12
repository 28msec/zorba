
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
#line 45 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"


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
#line 75 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 877 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_driver.h"
#include "compiler/parser/xquery_scanner.h"
#undef yylex
#define yylex driver.lexer->lex


/* Line 317 of lalr1.cc  */
#line 92 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"

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
#line 161 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
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
#line 761 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 268 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 114: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 760 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 277 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 138: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 759 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 286 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 301: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 295 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 302: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 304 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 303: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 313 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 304: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 322 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 305: /* "Prolog" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 331 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 306: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 340 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 307: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 349 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 308: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 358 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 309: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 367 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 310: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 376 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 311: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 773 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->pair_vector); };

/* Line 480 of lalr1.cc  */
#line 385 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 312: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 773 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->pair); };

/* Line 480 of lalr1.cc  */
#line 394 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 314: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 403 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 315: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 412 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 316: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 421 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 317: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 430 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 439 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 448 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 457 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 466 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 475 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 484 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 493 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 502 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 511 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 520 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 529 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 538 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 547 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 556 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 565 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 773 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 574 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 583 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 592 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "IndexDecl2" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 601 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "IndexDecl3" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 610 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "IndexDeclSuffix" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 619 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "IndexField" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 628 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "IndexField1" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 637 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "IndexFieldList" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 646 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 655 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 773 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 664 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 673 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "Block" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 682 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "BlockDecls" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 691 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "BlockVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 700 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "BlockVarDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 709 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "AssignExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 718 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "ExitExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 727 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "WhileExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 736 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 745 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "IndexStatement" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 754 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 772 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "FunctionDecl3" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 781 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "FunctionDecl4" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 790 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 799 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 808 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "EnclosedExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 817 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 826 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 835 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 844 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "ApplyExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 853 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "ConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 862 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 871 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 880 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 889 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 898 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 907 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 916 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 925 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 934 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 943 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 952 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 961 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 970 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 979 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 988 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "EvalVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 997 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1006 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1015 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1024 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1033 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1042 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "EvalVarDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1051 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1060 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1069 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1078 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1087 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1096 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1105 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1114 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1123 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1132 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1141 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1150 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1159 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1168 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1177 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1186 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1195 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1204 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1213 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1222 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1231 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1240 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1249 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1258 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1267 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1276 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1285 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1294 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1303 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1312 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1321 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1330 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1339 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1348 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1357 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1366 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1375 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1384 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1393 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1402 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "PragmaList" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1411 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1420 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1429 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1438 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1447 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1456 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1465 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1474 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1483 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1492 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1501 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1510 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1519 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1528 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1537 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1546 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1555 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1564 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1573 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1582 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1591 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1600 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1609 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1618 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1627 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1636 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1645 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1654 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1663 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1672 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1681 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1690 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1699 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1708 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "Opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1717 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1726 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "Opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1735 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1744 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1753 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1762 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1771 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1780 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1789 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1798 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1807 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1816 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1825 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1834 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1843 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1852 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1861 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1870 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1879 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1888 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1897 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1906 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1915 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1924 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1933 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1942 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1951 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1960 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1969 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1978 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1987 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1996 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2005 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2014 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2023 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2032 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2041 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2050 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2059 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2068 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2077 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2086 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2095 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2104 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2113 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2122 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2131 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 773 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2140 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2149 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "EvalExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2158 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
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
#line 94 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename);
}

/* Line 553 of lalr1.cc  */
#line 2243 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"

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
#line 895 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 905 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		}
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 910 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<MainModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr ((yyval.node));
		}
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 916 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
       driver.set_expr ((yyval.node));
		}
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 921 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
       driver.set_expr ((yyval.node));
		}
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 933 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)), encoding);
		}
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 938 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 948 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)));
		}
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 955 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)),
                NULL);
		}
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 967 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC ((yyloc)),
                             static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)),
                             NULL);
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 973 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LibraryModule(LOC ((yyloc)),
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 985 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), 
								SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
      dynamic_cast<ModuleDecl *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
		}
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 998 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)),
								NULL);
		}
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1004 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								NULL,
								static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		}
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1010 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
								static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1022 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = new SIND_DeclList(LOC ((yyloc)));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		}
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1028 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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
#line 1042 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = new VFO_DeclList(LOC ((yyloc)));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		}
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1048 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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
#line 1088 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].pair_vector));
      delete (yysemantic_stack_[(4) - (4)].pair_vector);
    }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 1093 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr))->get_qname(), (yysemantic_stack_[(4) - (4)].pair_vector)); 
      delete (yysemantic_stack_[(4) - (3)].expr);
      delete (yysemantic_stack_[(4) - (4)].pair_vector);
    }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 1102 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { 
      (yyval.pair_vector) = new std::vector<std::pair<std::string, std::string> > ();
      (yyval.pair_vector)->push_back(*(yysemantic_stack_[(1) - (1)].pair));
      delete (yysemantic_stack_[(1) - (1)].pair);
    }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 1108 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].pair_vector)->push_back(*(yysemantic_stack_[(2) - (2)].pair));
      delete (yysemantic_stack_[(2) - (2)].pair);
      (yyval.pair_vector) = (yysemantic_stack_[(2) - (1)].pair_vector);
    }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 1117 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *s = static_cast<StringLiteral *>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.pair) = new std::pair<std::string, std::string>((yysemantic_stack_[(3) - (1)].strval), s->get_strval());
      delete s;
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 1125 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1126 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1127 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1128 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1129 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1130 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1131 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1132 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1133 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1134 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 1171 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 1183 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		}
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1188 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		}
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1199 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_element_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1205 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_function_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1217 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OptionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
								SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
		}
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1230 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (3)].node));
		}
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1241 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		}
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1246 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		}
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1258 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		}
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1263 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		}
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1274 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::inherit_ns);
		}
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1280 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::no_inherit_ns);
		}
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1286 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::inherit_ns);
		}
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1292 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::no_inherit_ns);
		}
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1311 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)));
		}
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1322 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		}
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1333 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		}
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1340 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)),
								NULL);
		}
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1347 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		}
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1354 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
		}
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 1367 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = new URILiteralList(LOC ((yyloc)));
			uri_list_p->push_back(SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		}
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 1373 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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
#line 1388 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1392 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		}
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1402 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1409 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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
#line 1417 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
		}
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1424 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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
#line 1437 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1444 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->type = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1450 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1457 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(1) - (1)].node));
      d->ext = false;
      (yyval.node) = d;
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1463 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), NULL);
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1467 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1474 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1485 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(), NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1490 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
                               dynamic_cast<SequenceType *> ((yysemantic_stack_[(3) - (3)].node)));
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1499 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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
#line 1508 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (3)].varnametype)));
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       NULL, true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
		}
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1515 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(6) - (3)].varnametype)));
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       (yysemantic_stack_[(6) - (6)].expr), true);
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
		}
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1525 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "hash"; }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1527 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "btree"; }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1534 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      IndexDecl *d = dynamic_cast<IndexDecl *> ((yysemantic_stack_[(2) - (2)].node));
      d->create = false;
      (yyval.node) = d;
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1542 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1546 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexDecl *> ((yysemantic_stack_[(2) - (2)].node))->uniq = true;
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1554 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1558 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexDecl *> ((yysemantic_stack_[(2) - (2)].node))->method = (yysemantic_stack_[(2) - (1)].strval);
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1566 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(7) - (2)].sval)), (yysemantic_stack_[(7) - (4)].expr), "",
                          dynamic_cast<IndexFieldList *> ((yysemantic_stack_[(7) - (6)].node)));
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1574 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 1578 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexField *> ((yysemantic_stack_[(3) - (1)].node))->coll = SYMTAB ((yysemantic_stack_[(3) - (3)].sval));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 1586 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexField (LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL);
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1590 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexField (LOC ((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<SequenceType *> ((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1597 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      IndexFieldList *l = new IndexFieldList (LOC ((yyloc)));
      l->fields.push_back (dynamic_cast<IndexField *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
      
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1604 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexFieldList *> ((yysemantic_stack_[(3) - (1)].node))->fields.push_back (dynamic_cast<IndexField *> ((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1614 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		}
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1619 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		}
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1631 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1635 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1639 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL, dynamic_cast<SequenceType *> ((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1643 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType *> ((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1650 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1657 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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

  case 121:

/* Line 678 of lalr1.cc  */
#line 1676 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (1)].node));
      std::auto_ptr<VFO_DeclList> vfo2(dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (2)].node)));
      if ((yysemantic_stack_[(3) - (1)].node) == NULL)
        vfo = new VFO_DeclList (LOC ((yyloc)));
      vfo->push_back (*(vfo2.get()));
      (yyval.node) = vfo;
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1685 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL;
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1692 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (1)].node));
      vfo->push_back ((yysemantic_stack_[(3) - (3)].node));
      (yyval.node) = vfo;
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1698 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = new VFO_DeclList (LOC ((yyloc)));
      vfo->push_back ((yysemantic_stack_[(2) - (2)].node));
      (yyval.node) = vfo;
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1707 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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

  case 126:

/* Line 678 of lalr1.cc  */
#line 1717 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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

  case 127:

/* Line 678 of lalr1.cc  */
#line 1730 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr (LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr))->get_qname(), (yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (3)].expr);
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1738 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr (LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1745 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *b = dynamic_cast<BlockBody *> ((yysemantic_stack_[(5) - (5)].expr));
      if (b == NULL) {
        b = new BlockBody ((yysemantic_stack_[(5) - (5)].expr)->get_location ()); 
        b->add ((yysemantic_stack_[(5) - (5)].expr));
      }
      (yyval.expr) = new WhileExpr (LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), b);
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1757 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1761 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::CONTINUE);
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1768 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IndexStatement (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), IndexStatement::create_stmt);
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1772 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IndexStatement (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), IndexStatement::drop_stmt);
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1776 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IndexStatement (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), IndexStatement::build_stmt);
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1783 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { 
      dynamic_cast<FunctionDecl *>((yysemantic_stack_[(2) - (2)].node))->setComment(SYMTAB((yysemantic_stack_[(2) - (1)].sval)));
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1788 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
      d->deterministic = false;
      (yyval.node) = d;
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1795 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<FunctionDecl *>((yysemantic_stack_[(3) - (3)].node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1803 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1807 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1811 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(2) - (2)].node));
      d->type = (d->type == ParseConstants::fn_extern)
        ? ParseConstants::fn_extern_update
        : ParseConstants::fn_update;
      (yyval.node) = d;
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1819 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1826 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								(yysemantic_stack_[(4) - (4)].expr),
								ParseConstants::fn_read);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1835 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								NULL,
								ParseConstants::fn_extern);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1847 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								(yysemantic_stack_[(4) - (4)].expr),
								ParseConstants::fn_sequential);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1856 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								NULL,
								ParseConstants::fn_extern_sequential);
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1869 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = new ParamList(LOC ((yyloc)));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)));
			}
			(yyval.node) = plist_p;
		}
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1877 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1891 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(),
								NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
		}
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1898 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
      delete (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1911 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1919 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1930 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QueryBody(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
		}
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1941 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1945 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<BlockBody> blk(dynamic_cast<BlockBody *> ((yysemantic_stack_[(2) - (2)].expr)));
      BlockBody  *blk2 = new BlockBody (LOC ((yyloc)));
      (yyval.expr) = blk2;
      blk2->add ((yysemantic_stack_[(2) - (1)].expr));
      for (int i = 0; i < blk->size (); i++)
        blk2->add ((*blk) [i]);
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1957 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody (LOC ((yyloc)));
    }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1961 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = dynamic_cast<BlockBody *> ((yysemantic_stack_[(3) - (1)].expr));
      blk->add ((yysemantic_stack_[(3) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 1970 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 1974 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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

  case 177:

/* Line 678 of lalr1.cc  */
#line 2021 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      ReturnExpr* lReturnExpr = dynamic_cast<ReturnExpr*>((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = new FLWORExpr (LOC ((yyloc)), dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node)), lReturnExpr->get_return_val(), lReturnExpr->get_location(), driver.theCompilerCB->m_config.force_gflwor);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 2030 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2037 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2041 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2049 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 2053 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 2057 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_only_end;
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 2064 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), dynamic_cast<WindowVars *> ((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr), (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 2068 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr), (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 2075 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(5) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window,
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(5) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (4)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 2083 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window,
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 2094 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause (LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 2113 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = new FLWORClauseList (LOC ((yyloc)));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 2119 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = dynamic_cast<FLWORClauseList *> ((yysemantic_stack_[(2) - (1)].node));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 2128 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = NULL;
    }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 2132 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_ofor;
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2142 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForClause(LOC ((yyloc)),
                         dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL);
		}
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 2153 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		}
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 2159 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vardecl_list_p) {
				vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 2173 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (1)].expr);
		}
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 2181 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 2190 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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

  case 207:

/* Line 678 of lalr1.cc  */
#line 2200 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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

  case 208:

/* Line 678 of lalr1.cc  */
#line 2211 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 2220 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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

  case 210:

/* Line 678 of lalr1.cc  */
#line 2230 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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

  case 211:

/* Line 678 of lalr1.cc  */
#line 2240 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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

  case 212:

/* Line 678 of lalr1.cc  */
#line 2256 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
		}
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 2269 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
		}
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 2281 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)));
			
		}
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 2293 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		}
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 2299 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 2311 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		}
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 2317 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 2331 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
								NULL,
								NULL,
								(yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (1)].expr);
		}
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 2340 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 2350 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 2359 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (1)].expr);
		}
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 2372 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr))->get_qname(),
								NULL, (yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (2)].expr);
		}
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 2379 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (2)].expr);
		}
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 2391 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(), "", "");
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 2396 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_curr (static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 2405 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), dynamic_cast<PositionalVar *> ((yysemantic_stack_[(1) - (1)].node)), "", "", "");
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 2409 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_posvar (dynamic_cast<PositionalVar *> ((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 2418 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr))->get_qname(), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr))->get_qname());
      delete (yysemantic_stack_[(6) - (3)].expr);
      delete (yysemantic_stack_[(6) - (6)].expr);
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 2424 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", "", static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 2429 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname(), "");
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 2437 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      std::string name = static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr))->get_qname();
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           name, NULL, NULL,
                           new VarRef (LOC ((yyloc)), name),
                           VarGetsDecl::eval_var);
      delete (yysemantic_stack_[(1) - (1)].expr);
                           
    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 2453 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 2461 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 2468 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = new GroupSpecList(LOC((yyloc)));
      gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl_p;
    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 2474 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      if (gsl_p) {
        gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      }
      (yyval.node) = gsl_p;
    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 2485 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(),
                 NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 2492 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), 
                 static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(), 
                 dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node))); 
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 2502 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
    }
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 2512 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 2517 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)),
								true);
		}
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2529 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		}
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 2535 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node));
			if (osl_p) {
				osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2549 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		}
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 2555 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<OrderModifier*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2567 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL,
								NULL);
		}
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2574 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		}
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2581 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2588 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
								NULL);
		}
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 2595 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2602 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 2609 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 2622 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		}
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 2626 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		}
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 2636 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		}
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 2641 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		}
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2652 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		}
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2663 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2670 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2683 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;
				
		}
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2690 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2702 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
								(yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (1)].expr);
		}
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2709 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2723 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
								(yysemantic_stack_[(8) - (8)].expr));
		}
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2730 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(10) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
								static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr))->get_qname(),
								(yysemantic_stack_[(10) - (10)].expr));
      delete (yysemantic_stack_[(10) - (8)].expr);
		}
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2745 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		}
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2751 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr))->get_qname(),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
      delete (yysemantic_stack_[(7) - (3)].expr);
		}
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2783 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
		}
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2794 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2798 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2809 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2813 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 2832 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2836 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2844 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      /*  ::=  "is" | "<<" | ">>" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2852 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2860 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2867 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { /* this call is needed */  driver.lexer->interpretAsLessThan(); }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2868 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2876 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_le),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2884 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2892 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2906 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2910 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		}
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2917 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 2930 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 2934 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 2945 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 2949 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 2953 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 2963 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 2967 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 2971 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 2975 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 2979 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 2989 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 2993 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 2998 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3009 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3013 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3017 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3027 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3031 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3043 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3047 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3059 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3063 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3075 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3079 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3091 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3095 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3107 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		}
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3111 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		}
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3115 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3119 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3131 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3135 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3139 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3149 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		}
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3153 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		}
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3157 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		}
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3161 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		}
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3165 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		}
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3169 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		}
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3179 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		}
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3183 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		}
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3187 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		}
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3197 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3201 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3205 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3209 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                            dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(),
                            (yysemantic_stack_[(6) - (5)].expr));
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3221 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		}
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3227 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3239 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		}
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3245 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node));
			if (pragma_list_p) {
				pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3259 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));

		}
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3265 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval))),
								"");      
    }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3307 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		}
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3311 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3315 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3319 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (rpe == NULL ?
             (yysemantic_stack_[(1) - (1)].expr) :
             new PathExpr(LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3331 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3341 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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

  case 348:

/* Line 678 of lalr1.cc  */
#line 3352 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3357 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3367 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3371 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3381 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		}
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3387 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3393 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		}
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3399 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3411 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		}
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3417 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3428 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		}
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3432 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		}
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3436 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		}
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3440 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		}
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3444 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		}
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3448 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		}
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3452 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		}
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3462 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node), false);
		}
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3466 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		}
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3476 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseStep(LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node));
		}
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3480 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC((yyloc)), rev_p, NULL);
		}
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3491 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		}
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3495 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		}
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3499 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		}
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3503 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		}
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3507 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		}
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3522 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3526 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3536 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3540 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3550 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        "",
                        ParseConstants::wild_all);
		}
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3557 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        ParseConstants::wild_elem);
		}
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3564 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        ParseConstants::wild_prefix);
		}
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3577 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3581 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
                          (yysemantic_stack_[(2) - (1)].expr),
                          dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3593 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		}
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3599 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node));
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3613 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3624 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3628 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3632 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3636 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3640 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3644 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3648 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3652 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3662 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3666 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3676 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval));
      delete yylval.decval;
		}
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3681 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival));
      delete yylval.ival;
		}
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3686 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval));
      delete yylval.dval;
		}
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3697 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new VarRef(LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname());
      delete (yysemantic_stack_[(2) - (2)].expr);
		}
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3708 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		}
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3712 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3723 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		}
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3733 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3744 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3800 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)),
								NULL);
		}
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3806 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3818 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = new ArgList(LOC ((yyloc))); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		}
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3824 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3836 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3840 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3850 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3854 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3858 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3868 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
								NULL,
								NULL,
								NULL);
		}
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3876 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
								NULL,
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)), 
								NULL);
		}
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3884 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(8) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr)),
								NULL,
								NULL);
		}
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3892 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
								NULL,
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node)));
		}
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3900 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
								NULL);
		}
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3908 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(10) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)), 
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node)));
		}
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3923 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		}
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3929 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3941 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		}
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3947 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 3960 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
		}
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 3977 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		}
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 3982 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		}
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 3993 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		}
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 3997 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 4004 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		}
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 4010 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		}
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 4016 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 4024 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 4038 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		}
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 4042 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 4049 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		}
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4055 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		}
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4061 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4069 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4083 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4088 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4099 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4104 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4115 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		}
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4120 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4125 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		}
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4131 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		}
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4143 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4149 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		}
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4154 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		}
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4159 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4170 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4175 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4190 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4195 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		}
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4212 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CDataSection(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		}
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4227 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4231 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4235 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4239 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4243 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4247 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4257 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4268 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
								NULL);
		}
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4274 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4280 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4285 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4307 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (2)].expr),
								NULL);
		}
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4313 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4319 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4324 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4335 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4345 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4355 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		}
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4361 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4367 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4372 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4383 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		}
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4389 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		}
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4401 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
		}
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4412 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		}
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4418 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4424 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		}
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4461 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		}
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4466 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		}
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4471 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		}
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4482 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4486 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4490 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		}
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4500 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4511 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4515 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4519 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4523 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4527 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4531 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4535 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4539 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4543 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4553 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		}
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4563 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		}
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4567 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4572 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4583 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TextTest(LOC ((yyloc)));
		}
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4593 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		}
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4603 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		}
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4607 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		}
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4611 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		}
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4621 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		}
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4627 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
								NULL);
		}
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4633 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		}
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4639 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		}
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4645 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		}
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4657 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
		}
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4668 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           NULL,
                           NULL,
                           true);
		}
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4675 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                           NULL,
                           true);
		}
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4682 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           false);
		}
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4689 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           true);
		}
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4696 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL,
									true);
		}
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4703 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									false);
		}
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4710 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									true);
		}
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4723 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)));
		}
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4744 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4751 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)),
								true);
		}
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4811 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::strict_validation);
		}
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4815 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::lax_validation);
    }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4819 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::skip_validation);
    }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4828 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4834 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4840 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4846 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4852 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4859 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4865 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4871 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4877 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4883 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4895 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4900 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4910 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4916 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4928 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4954 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4965 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       CopyVarList* lList = new CopyVarList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
		}
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4971 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
       VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
       lList->push_back(lBinding);
       (yyval.expr) = lList;
		}
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4984 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(), (yysemantic_stack_[(3) - (3)].expr));  
       delete (yysemantic_stack_[(3) - (1)].expr);
    }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4999 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 5006 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 5012 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* aCatchListExpr = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if (aCatchListExpr) {
        aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)));
      }
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 5023 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(3) - (2)].name_test_list),
                          (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 5030 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(7) - (2)].name_test_list),
                          static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr))->get_qname(),
                          (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (5)].expr);
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 5040 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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

  case 555:

/* Line 678 of lalr1.cc  */
#line 5051 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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

  case 556:

/* Line 678 of lalr1.cc  */
#line 5067 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      CatchExpr::NameTestList *name_test_list = new CatchExpr::NameTestList;
      name_test_list->push_back (static_cast<NameTest *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.name_test_list) = name_test_list;
    }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 5073 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      CatchExpr::NameTestList *name_test_list =
        static_cast<CatchExpr::NameTestList *> ((yysemantic_stack_[(3) - (1)].name_test_list));
      name_test_list->push_back (static_cast<NameTest *> ((yysemantic_stack_[(3) - (3)].node)));
      (yyval.name_test_list) = name_test_list;
    }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 5093 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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

  case 561:

/* Line 678 of lalr1.cc  */
#line 5111 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { 
      (yyval.expr) = new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval))); 
    }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 5115 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { 
      (yyval.expr) = new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval))); 
    }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 5121 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("xquery"); }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 5122 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty"); }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 5123 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("attribute"); }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 5124 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("comment"); }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 5125 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document-node"); }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 5126 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("element"); }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5127 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("item"); }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5128 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("if"); }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5129 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("node"); }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5130 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("processing-instruction"); }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5131 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-attribute"); }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5132 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-element"); }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5133 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("text"); }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5134 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("typeswitch"); }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5135 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty-sequence"); }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5136 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("boundary-space"); }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5137 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ft-option"); }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5138 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("base-uri"); }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5139 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lax"); }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5140 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strict"); }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5141 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("idiv"); }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5142 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document"); }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5143 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("not"); }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5144 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sensitive"); }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5145 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insensitive"); }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5146 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("diacritics"); }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5147 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("without"); }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5148 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stemming"); }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5149 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("thesaurus"); }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5150 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stop"); }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5151 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("wildcards"); }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5152 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("entire"); }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5153 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("content"); }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5154 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("word"); }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5155 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("start"); }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5156 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("end"); }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5157 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("most"); }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5158 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("skip"); }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5159 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy"); }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5160 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("value"); }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5161 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eq"); }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5162 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ne"); }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5163 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lt"); }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5164 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("le"); }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5165 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("gt"); }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5166 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ge"); }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5167 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("at"); }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5168 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("context"); }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5169 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("variable"); }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5170 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("return"); }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5171 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("for"); }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5172 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("outer"); }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5173 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sliding"); }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5174 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("tumbling"); }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5175 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("previous"); }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5176 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("next"); }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5177 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("only"); }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5178 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("when"); }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5179 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("count"); }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5180 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("in"); }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5181 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("let"); }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5182 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("where"); }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5183 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("by"); }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5184 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("group"); }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5185 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("order"); }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5186 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stable"); }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5187 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ascending"); }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5188 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("descending"); }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5189 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("greatest"); }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5190 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("least"); }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5191 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("collation"); }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5192 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("some"); }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5193 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("every"); }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5194 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("satisfies"); }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5195 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("case"); }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5196 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("as"); }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5197 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("then"); }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5198 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("else"); }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5199 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("or"); }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5200 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("and"); }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5201 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("instance"); }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5202 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("of"); }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5203 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("castable"); }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5204 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("to"); }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5205 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("div"); }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5206 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("mod"); }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5207 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("union"); }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5208 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("intersect"); }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5209 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("except"); }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5210 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("validate"); }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5211 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("cast"); }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5212 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("treat"); }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5213 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("is"); }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5214 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("preserve"); }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5215 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strip"); }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5216 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("namespace"); }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5217 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("external"); }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5218 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("encoding"); }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5219 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-preserve"); }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5220 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("inherit"); }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5221 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-inherit"); }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5222 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("declare"); }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5223 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("construction"); }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5224 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordering"); }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5225 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("default"); }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5226 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy-namespaces"); }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5227 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("option"); }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5228 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("version"); }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5229 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("import"); }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5230 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema"); }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5231 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("module"); }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5232 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("function"); }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5233 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("score"); }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5234 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ftcontains"); }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5235 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("weight"); }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5236 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("window"); }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5237 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("distance"); }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5238 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("occurs"); }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5239 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("times"); }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5240 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("same"); }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5241 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("different"); }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5242 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lowercase"); }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5243 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("uppercase"); }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5244 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("relationship"); }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5245 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("levels"); }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5246 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("language"); }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5247 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("any"); }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5248 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("all"); }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5249 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("phrase"); }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5250 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exactly"); }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5251 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("from"); }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5252 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("words"); }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5253 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentences"); }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5254 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentence"); }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5255 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("paragraph"); }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5256 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("replace"); }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5257 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("modify"); }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5258 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("first"); }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 5259 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insert"); }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5260 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("before"); }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 5261 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("after"); }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 5262 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("revalidation"); }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 5263 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("with"); }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 5264 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nodes"); }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 5265 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("rename"); }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 5266 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("last"); }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 5267 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("delete"); }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 5268 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("into"); }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 5269 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("simple"); }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 5270 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sequential"); }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 5271 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("updating"); }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 5272 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("deterministic"); }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 5273 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nondeterministic"); }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 5274 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordered"); }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 5275 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unordered"); }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 5276 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("returning"); }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 5277 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("block"); }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 5278 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exit"); }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 5279 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("loop"); }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 5280 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("while"); }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 5281 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("break"); }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 5282 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("continue"); }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 5283 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("try"); }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 5284 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("catch"); }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 5285 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eval"); }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 5286 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("using"); }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 5287 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("set"); }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 5288 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("index"); }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 5289 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("create"); }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 5290 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("build"); }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 5291 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unique"); }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 5292 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("on"); }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 5293 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("hash"); }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 5294 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("btree"); }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 5295 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("drop"); }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 5296 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("decimal-format"); }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 5297 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("decimal-separator"); }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 5298 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("grouping-separator"); }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 5299 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("infinity"); }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 5300 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("minus-sign"); }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 5301 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("NaN"); }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 5302 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("percent"); }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 5303 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("per-mille"); }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 5304 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("zero-digit"); }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 5305 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("digit"); }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 5306 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("pattern-separator"); }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 5318 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)),
                          (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 5324 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 5341 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(1) - (1)].node)), NULL, NULL);
		}
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 5345 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(2) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(2) - (2)].node)), NULL);
		}
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 5349 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(3) - (1)].node)), NULL, static_cast<RangeExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		}
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 5353 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(4) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(4) - (2)].node)), static_cast<RangeExpr *> ((yysemantic_stack_[(4) - (4)].expr)));
		}
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 5363 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 5366 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 5369 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 5372 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 5381 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 5384 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 5393 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 5396 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 5405 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 5408 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 5417 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 5420 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 5429 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 5432 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 5435 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 5444 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 5447 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 5456 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), static_cast<StringLiteral *> ((yysemantic_stack_[(1) - (1)].expr)), NULL);
		}
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 5460 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 5470 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 5473 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 5476 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 5479 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 5482 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 5491 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 5500 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 5504 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 5508 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 5512 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 5516 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 5520 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 5524 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 5534 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 5537 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 5540 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 5543 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 5552 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 5555 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 5558 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 5561 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 5570 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 5573 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 5582 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 5585 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 5588 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 5591 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 5594 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 5597 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 5600 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 5609 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 5612 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 5621 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 5624 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 5627 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 5630 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 5639 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 5642 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 5645 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 5648 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 5651 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 5660 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 5663 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 5672 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 5675 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 5684 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 5687 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 5696 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 5699 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 5708 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 5717 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 5720 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 5729 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 5732 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 5735 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 5744 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 5747 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 5750 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 5753 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 5756 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 5765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 5769 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 5773 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 5777 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 5787 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 5796 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWindow (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (2)].expr)), static_cast<FTUnit *> ((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 5806 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 5815 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 5818 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 5827 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 5830 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 5833 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 5842 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 5845 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 5854 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTIgnoreOption (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		}
    break;



/* Line 678 of lalr1.cc  */
#line 9811 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1203;
  const short int
  xquery_parser::yypact_[] =
  {
      1381, -1203, -1203, -1203, -1203,   672,   -75,    28,    -1,  7635,
      75,   466,   470, -1203, -1203, -1203, -1203, -1203, -1203,   107,
     387,  6565, -1203,   154, -1203, -1203, -1203, -1203,   179,   214,
   -1203,   213,   282,   321, -1203, -1203, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203,   253,   273, -1203, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203,  7900, -1203,  6023, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,
   -1203, -1203,  9490, -1203, -1203, -1203, -1203, -1203, -1203, -1203,
   -1203,   345, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203,  1655,  9490, -1203, -1203, -1203, -1203, -1203,
   -1203,   357, -1203, -1203, -1203, -1203,  7103, -1203,  7370, -1203,
   -1203, -1203, -1203, -1203,  9490, -1203, -1203,  5750, -1203, -1203,
   -1203, -1203, -1203, -1203,   364, -1203, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203,     7,   331, -1203, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203,   340,   398,   354, -1203,   344,   104, -1203,
   -1203, -1203, -1203, -1203, -1203,   440, -1203, -1203,   436,   359,
     368, -1203,   403,   450,   497, -1203,   540, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203,   390,   391,   392, -1203, -1203, -1203, -1203,
   -1203,  4112,   673, -1203,  4385, -1203, -1203,   355,  4658,   493,
     498, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,
   -1203,   -36, -1203, -1203, -1203, -1203,   327,  9490, -1203, -1203,
   -1203, -1203, -1203,   520,   594, -1203,   607,   429,   339,   239,
     197,   351, -1203,   611,   494,   590,   591,  4931, -1203, -1203,
   -1203,   203, -1203, -1203,  5750, -1203,   426, -1203,   543,  6023,
   -1203,   543,  6023, -1203, -1203, -1203, -1203,   543, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203,   539, -1203, -1203,  9490,
     653,   655,   541,   541,   653,  9490,   -58,   -12,   670,   115,
     246,  9490,   550,   586,   370,  7103,   411,    93,   348,   670,
   -1203, -1203,   418, -1203, -1203, -1203, -1203, -1203,  7103,  9490,
    4658,   557,   559,  4658, -1203, -1203, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203,  4658,  8165, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203,   560,  4658,  4658,   528,
    4658,   529,  4658,    44,    34, -1203,  4658,  6834,   563, -1203,
    9490,  9490,  9490,  4658,   444,   445, -1203,   605,   606,  9490,
      14,  4658,  8430,   575,   574,   576,   580,   581,   582, -1203,
   -1203, -1203,  9490, -1203,   553,   703,  4658,    27, -1203,   716,
     569, -1203,  4658,   530, -1203,   714,  4658,  4658,   570,  4658,
    4658,  4658,  4658,   521,  9490, -1203, -1203,  4658, -1203, -1203,
    4658,  4658,  9490,   670,   670,   670, -1203, -1203, -1203, -1203,
     672,   387, -1203, -1203,   355,   721,  4658, -1203,  4658,   592,
     214,   282,   321,   638,   593,   595,  4658,  4658, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203,   650, -1203,   -33,  5204,  5204,
    5204, -1203,  5204,  5204, -1203,  5204, -1203,  5204, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203,  5204,  5204,    11,  5204,  5204,
    5204,  5204,  5204,  5204,  5204,  5204,  5204,  5204,  5204,   536,
     671,   679,   681, -1203, -1203, -1203,  1928, -1203, -1203,  5750,
    5750,  4658,   543, -1203, -1203,   543, -1203,   543,  2201,   614,
   -1203,  9490, -1203, -1203, -1203, -1203,   748, -1203, -1203, -1203,
   -1203, -1203, -1203,   674,   682, -1203, -1203,   587,   278,  9490,
     317,   620,   621,   587,   670,   654,   656, -1203, -1203, -1203,
     377,    25,   378,   752, -1203, -1203,   330, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203,   501, -1203,   658,   643,
   -1203,   615,  4658,  4658,   613,   617, -1203,   -28,    -8,  2474,
     618,   619, -1203,   622, -1203,   629,  7103,   698,   765,  7103,
     670,   708,   625,   630, -1203,   631,  2747,   -39, -1203,   222,
     675,   709, -1203,   -57,   637, -1203, -1203,  9490,   -30, -1203,
     635,   574,   253, -1203,   636,   639,   640, -1203,     2,    12,
    3020,    -3, -1203,  9490,   703, -1203,   -23,   641, -1203, -1203,
   -1203, -1203,   644, -1203,   -16, -1203, -1203, -1203,   -47,   -43,
     729,   596,   603,   -17, -1203,   686,  5477, -1203,   645,   647,
     238, -1203, -1203, -1203, -1203, -1203,   646, -1203,    31, -1203,
   -1203,   -27,   664,  9490,  4658,   717, -1203, -1203,   718,  8960,
     719,  4658,   720,   -52,   688,   -38,   594, -1203, -1203, -1203,
   -1203, -1203,  5204, -1203, -1203, -1203,  4658,    11,   374, -1203,
     565,   228,   585,   584, -1203, -1203,   583,   254,   239,   239,
      72,   197,   197,   197,   197,   351,   351, -1203, -1203,  8960,
    8960,  9490,  9490, -1203,   660, -1203, -1203,   665, -1203, -1203,
   -1203,    73,   167,   325,   614, -1203,   292,   356, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,   587, -1203,
     704,  9225,   705,  4658, -1203, -1203, -1203,   753,   710,  4658,
     670,   670,   587, -1203,   495,   670, -1203, -1203,   572, -1203,
   -1203,   573,     1, -1203, -1203, -1203, -1203, -1203, -1203,   577,
   -1203, -1203,  4658,   670,  4658, -1203,   669,   676,   754,   702,
    9490, -1203,  9490, -1203, -1203,   680, -1203, -1203, -1203,   661,
     731,   670,   706,   735,   763,   670,   722, -1203, -1203, -1203,
     687,   750,  4658,  4658,   725,  4658,   755,  4658,   726,   -74,
   -1203,   227,   623, -1203, -1203,   478,   -30, -1203, -1203, -1203,
     724,  9490, -1203,  9490, -1203, -1203,   691,  4658,   840, -1203,
     136, -1203,    79, -1203, -1203,   848, -1203,   412,  4658,  4658,
    4658,   415,  4658,  4658,  4658,  4658,  4658,  4658,   760,  4658,
    4658,   586,   -13,   699,   436,   649,   733,   775,   721,   802,
   -1203,  4658, -1203,   413,   787, -1203,  9490,   788, -1203,  9490,
     743,   744, -1203,   274, -1203, -1203, -1203,  9490, -1203,  9490,
    4658,   756,  4658,  4658,   -32,   757, -1203,   723,   728, -1203,
     651, -1203,   -89, -1203,   311,    -5,   652,    11,   311,  5204,
    5204,   158, -1203, -1203, -1203, -1203, -1203, -1203, -1203,    11,
     758,    -5, -1203,   624,   844, -1203, -1203, -1203, -1203, -1203,
     766, -1203, -1203, -1203,  4658, -1203,  9490,   811,   150, -1203,
   -1203,  4658, -1203,   375, -1203, -1203, -1203, -1203, -1203,   881,
     460, -1203, -1203, -1203,  4658, -1203, -1203, -1203, -1203, -1203,
   -1203,   633,    50,   886, -1203,   410, -1203, -1203,   749,   730,
     738, -1203, -1203,  8695,   428, -1203,  3293,   732,   736,   779,
     739,   740, -1203,  4658,   670,   817, -1203, -1203, -1203,   670,
     817,  3566, -1203,  9490, -1203, -1203,  4658, -1203,  9490, -1203,
    4658,  4658,   786,  4658,   783, -1203,   812,   813,  4658,  9490,
     566,   860, -1203, -1203, -1203,  3839,   751,   759, -1203, -1203,
   -1203,   805, -1203,    85, -1203, -1203,   918, -1203, -1203,  4658,
    9490, -1203, -1203,    91, -1203, -1203, -1203,   767,   707,   711,
   -1203, -1203, -1203,   713,   715, -1203, -1203, -1203, -1203, -1203,
     734,  9490,   762, -1203,   799, -1203,   586, -1203, -1203, -1203,
    6296,   649, -1203,  4658,  9490,   787, -1203,   670, -1203,   513,
   -1203,    10,   834, -1203,  4658,   841,   717, -1203,   769,   772,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203,  4658, -1203, -1203,
    4658,   806,  4658, -1203, -1203,  5204, -1203, -1203, -1203, -1203,
   -1203,     9,  5204,  5204,   309, -1203,   585, -1203, -1203,   178,
    5204, -1203, -1203,   584,    11,   683, -1203, -1203, -1203, -1203,
     753,  8960,   839,   868,   784, -1203, -1203, -1203, -1203, -1203,
     114,   935,   937,   114,   -37,   161,   166,   814, -1203, -1203,
    9490,   789,   -54, -1203, -1203,   790, -1203, -1203, -1203, -1203,
   -1203,   842,   873,   670,   817, -1203,   793, -1203, -1203, -1203,
   -1203, -1203,  4658, -1203,  4658,  9490,  9490, -1203,   420, -1203,
    4658, -1203,   794, -1203, -1203,   840,  9490,   160, -1203,   795,
     840,  9490, -1203, -1203,  4658,  4658,  4658,  4658,  4658, -1203,
    4658,  4658, -1203, -1203,   209, -1203,   796, -1203, -1203, -1203,
   -1203,   834, -1203, -1203, -1203,   670, -1203, -1203, -1203, -1203,
   -1203, -1203,  4658, -1203,   197,  5204,  5204,   197,   336, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,
    8960, -1203,    50,    50,   114, -1203, -1203, -1203,    21,   114,
     949,   727,   882, -1203,   882, -1203,  4658,   185,   885,  4658,
    9490,  4658, -1203,  4658,   670, -1203, -1203, -1203, -1203,   913,
   -1203, -1203, -1203, -1203,   -40,   840,  9490, -1203,   791,   840,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203,   863,  6296, -1203,
   -1203, -1203, -1203, -1203,   197,   197,  5204, -1203, -1203, -1203,
   -1203, -1203, -1203,    -5, -1203,   208, -1203,   215, -1203,   876,
     753,  4658, -1203,  8960, -1203,   801, -1203, -1203,   817,   869,
     146,   163, -1203,   798,   840, -1203,   800,  9490, -1203,   197,
     737,   882, -1203, -1203,   670, -1203, -1203,   807,  4658,  9490,
   -1203, -1203,   895,   324, -1203, -1203, -1203, -1203,   815,   264,
   -1203, -1203, -1203,   803, -1203,   218, -1203, -1203, -1203,  4658,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,   874,
     845, -1203,  9490, -1203,   234,   879,   845,  9490, -1203,   816,
     845, -1203
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   379,   380,   561,   526,   664,   673,   652,   576,   568,
     584,   575,   566,   674,   713,   712,   714,   715,   711,   570,
     671,   572,   599,   634,   628,   669,   596,   672,   729,   623,
     665,   727,   613,   614,   615,   616,   617,   618,   619,   620,
     621,   666,   580,   574,   567,   668,   643,   573,   578,   738,
     739,   740,   741,   742,   743,   744,   745,   746,   747,   748,
     370,   373,   642,   638,   629,   609,   565,   360,     0,   637,
     645,   653,   358,   633,   396,   610,   611,   667,   359,   362,
     630,   647,     0,   402,   368,   398,   640,   564,   631,   632,
     660,   635,   651,   659,   364,   363,   583,   622,   662,   397,
     650,   655,   569,     0,     0,   317,   648,   658,   663,   661,
     641,   716,   627,   625,   626,   369,     0,   316,     0,   372,
     371,   656,   612,   636,     0,   361,   346,     0,   378,   657,
     639,   646,   654,   649,   717,   603,   608,   607,   606,   605,
     604,   577,   624,     0,   563,   670,   597,   703,   702,   704,
     582,   581,   600,   709,   571,   701,   706,   707,   698,   602,
     644,   700,   710,   708,   699,   601,   705,   718,   719,   720,
     723,   721,   724,   722,   725,   726,   728,   690,   689,   586,
     579,   588,   587,   683,   679,   594,   598,   595,   692,   693,
     676,   585,   688,   687,   684,   680,   697,   691,   686,   682,
     675,   696,   695,   681,   685,   677,   678,   589,   590,   592,
     694,   591,   593,   731,   732,   737,   733,   730,   735,   736,
     734,     0,     0,     2,     0,     4,     6,    12,     0,     0,
       0,    18,    20,    32,    22,    23,    24,    48,    25,    29,
      30,    52,    53,    54,    49,    50,    56,    57,    27,    26,
      31,    51,   175,   174,   171,   172,   173,   176,    28,    11,
     152,   153,   157,   159,   191,   197,     0,     0,   189,   190,
     160,   161,   162,   163,   273,   275,   277,   287,   290,   292,
     295,   300,   303,   306,   308,   310,   312,     0,   314,   320,
     322,     0,   338,   321,   342,   345,   347,   350,   352,     0,
     357,   354,     0,   365,   375,   377,   351,   381,   386,   394,
     387,   388,   389,   392,   393,   390,   391,   409,   411,   412,
     413,   410,   458,   459,   460,   461,   462,   463,   374,   500,
     492,   499,   498,   497,   494,   496,   493,   495,   395,    55,
     164,   165,   167,   166,   168,   169,   376,   562,   170,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      99,   100,     0,   101,   102,   104,   135,   138,     0,     0,
       0,     0,     0,     0,   664,   673,   652,   576,   568,   584,
     575,   566,   570,   671,   572,   634,   729,   623,   727,   613,
     614,   574,   567,   565,   635,     0,     0,   716,   717,   563,
     709,   571,   701,   707,   698,   601,   719,   720,   723,   724,
     722,   725,   728,   731,   732,   737,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   559,     0,     0,     0,   560,
       0,     0,     0,     0,     0,     0,   199,     0,     0,     0,
       0,     0,     0,     0,   568,   575,   566,   572,   565,   366,
     376,   399,     0,   400,     0,   425,     0,     0,   341,     0,
       0,   344,     0,     0,   454,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   122,   119,     0,   130,   131,
       0,     0,     0,     0,     0,     0,     3,     1,     5,     7,
       0,     0,    13,    10,    15,    16,     0,   155,   154,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   177,   196,
     192,   198,   193,   195,   194,   201,   202,     0,     0,     0,
       0,   331,     0,     0,   329,     0,   282,     0,   330,   323,
     328,   327,   326,   325,   324,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   319,   318,   315,     0,   339,   343,     0,
       0,     0,   353,   383,   356,   355,   367,   382,     0,     0,
     140,     0,   141,   137,   136,   139,     0,   113,   114,    65,
      66,   558,    74,     0,     0,    59,    60,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   527,   528,   529,
       0,     0,     0,     0,   787,   788,     0,    64,   780,   781,
     782,   783,   784,   785,   786,   103,     0,   105,     0,     0,
     524,     0,     0,     0,     0,     0,   516,     0,     0,     0,
       0,     0,   505,     0,   506,     0,     0,    83,     0,     0,
       0,    75,     0,     0,   507,     0,     0,     0,   262,     0,
       0,   214,   215,     0,     0,   179,   180,     0,     0,   200,
       0,     0,     0,   502,     0,     0,     0,   510,     0,     0,
       0,     0,   401,   426,   425,   422,     0,     0,   456,   455,
     340,   515,     0,   453,     0,   540,   541,   501,     0,     0,
       0,     0,     0,     0,   546,     0,     0,   128,     0,     0,
       0,   217,   234,   132,   134,   133,     0,    19,     0,    21,
     158,     0,     0,     0,     0,     0,   178,   235,     0,     0,
       0,     0,     0,     0,     0,     0,   274,   276,   280,   286,
     285,   284,     0,   281,   278,   279,     0,     0,     0,   772,
     288,   751,   759,   761,   763,   765,   767,   770,   294,   293,
     291,   297,   298,   299,   296,   301,   302,   305,   304,     0,
       0,     0,     0,   336,     0,   348,   349,     0,   384,   405,
     407,     0,     0,     0,     0,    63,     0,     0,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    34,    35,
       0,     0,    91,     0,    87,    89,    90,    94,    97,     0,
       0,     0,    33,    73,     0,     0,   789,   790,     0,   791,
     795,     0,     0,   824,   793,   794,   823,   792,   796,     0,
     803,   825,     0,     0,     0,   332,     0,     0,     0,     0,
       0,   520,     0,   517,   465,     0,   464,   473,   474,     0,
       0,     0,     0,     0,    76,     0,     0,   509,   508,   475,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     750,     0,     0,   181,   182,     0,   187,   523,   503,   504,
       0,     0,   513,     0,   511,   469,     0,     0,   425,   423,
       0,   414,     0,   403,   404,     0,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   664,     0,     0,     0,     0,     0,     0,    17,     0,
     156,     0,   188,   246,   242,   244,     0,   236,   237,     0,
     569,   577,   481,   482,   488,   489,   491,     0,   204,     0,
       0,     0,     0,     0,     0,     0,   283,     0,     0,   766,
       0,   289,     0,   779,     0,     0,     0,     0,     0,     0,
       0,   752,   756,   774,   755,   778,   776,   775,   777,     0,
       0,     0,   768,   831,   829,   833,   771,   307,   309,   311,
     479,   313,   337,   385,     0,   406,     0,   115,     0,   146,
     143,     0,   142,     0,    71,    72,    69,    70,    36,     0,
       0,    92,    93,    95,     0,    96,    61,    62,    67,    68,
      58,     0,     0,     0,   798,     0,   797,   814,     0,     0,
       0,   334,   333,     0,     0,   268,     0,     0,     0,   524,
       0,     0,   466,     0,     0,    85,    79,    82,    81,     0,
      77,     0,   476,     0,   260,   264,     0,   127,     0,   219,
       0,     0,     0,     0,     0,   183,     0,     0,     0,     0,
     228,     0,   225,   230,   186,     0,     0,     0,   470,   261,
     426,     0,   415,     0,   449,   446,     0,   450,   451,     0,
       0,   452,   445,     0,   420,   448,   447,     0,     0,     0,
     533,   534,   530,     0,     0,   538,   539,   535,   544,   542,
       0,     0,     0,   548,   125,   124,     0,   121,   120,   129,
       0,   549,   550,     0,     0,   243,   255,     0,   256,     0,
     247,   248,   249,   250,     0,   239,     0,   203,     0,     0,
     485,   487,   486,   483,   212,   213,   206,     0,   208,   205,
       0,     0,     0,   773,   769,     0,   826,   827,   847,   846,
     842,     0,     0,     0,     0,   828,   760,   841,   753,     0,
       0,   758,   757,   762,     0,     0,   832,   830,   480,   408,
     148,     0,     0,   116,     0,   145,   144,    37,    88,    98,
     812,     0,     0,   810,   806,     0,     0,     0,    14,   335,
       0,     0,     0,   269,   467,     0,   521,   522,   525,   518,
     519,     0,    84,     0,    78,   477,     0,   263,   265,   216,
     221,   220,     0,   223,     0,     0,     0,   185,   226,   229,
       0,   471,     0,   514,   512,   425,     0,     0,   457,     0,
     425,     0,   421,     9,     0,     0,     0,     0,     0,   547,
       0,     0,   123,   556,     0,   551,     0,   218,   259,   257,
     258,   251,   252,   253,   245,     0,   240,   238,   490,   484,
     210,   207,     0,   209,   848,     0,     0,   834,     0,   845,
     844,   843,   838,   839,   754,   764,   840,   149,   117,   147,
       0,   151,     0,     0,   813,   815,   817,   819,     0,   811,
       0,     0,     0,   801,     0,   799,     0,     0,     0,     0,
       0,     0,   468,     0,     0,    80,   478,   222,   224,   233,
     232,   227,   184,   472,     0,   425,     0,   150,     0,   425,
     531,   532,   536,   537,   543,   545,   126,     0,     0,   552,
     749,   254,   241,   211,   836,   835,     0,   118,   822,   821,
     816,   820,   818,   807,   808,     0,   804,     0,   111,   107,
     109,     0,   106,     0,   270,     0,   266,   272,    86,     0,
     435,   429,   424,     0,   425,   416,     0,     0,   557,   837,
       0,     0,   802,   800,     0,   110,   112,     0,     0,     0,
     443,   437,     0,   436,   438,   444,   441,   431,     0,   430,
     432,   442,   418,     0,   417,     0,   809,   805,   108,     0,
     267,   231,   428,   439,   440,   427,   433,   434,   419,     0,
       0,   271,     0,   553,     0,     0,     0,     0,   554,     0,
       0,   555
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1203, -1203,   773, -1203,   771,   774, -1203,   770, -1203,   486,
     492,  -484, -1203,   396,  -468, -1203, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,  -840,
   -1203, -1203, -1203, -1203,     0,   199,   642, -1203, -1203, -1203,
   -1203,   634,   632,  -348, -1203, -1203, -1203,   223, -1203,  -838,
   -1203, -1203,  -100, -1203, -1203, -1203, -1203, -1203, -1203,   289,
     168, -1203, -1203,  -164, -1203, -1202,   781,  -101, -1203,   502,
    -358, -1203, -1203, -1203, -1203,   135, -1203, -1203,   746, -1203,
   -1203, -1203, -1203, -1203,    84,  -501,  -643, -1203, -1203, -1203,
     -31, -1203, -1203,  -203,   -44,   -96, -1203, -1203, -1203,  -107,
   -1203, -1203,   101,   -99, -1203, -1203,   -98, -1060, -1203,   562,
     -15, -1203, -1203,     3, -1203, -1203,   503,   500, -1203,  -497,
    -932,   476,    95,  -543,    92,    94, -1203, -1203, -1203, -1203,
   -1203,   745, -1203, -1203, -1203, -1203, -1203,   742, -1203, -1203,
    -110, -1203, -1203, -1203, -1203, -1203, -1203, -1203,   -45, -1086,
   -1203, -1203,  -191,    19, -1203,  -546, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203,  -870, -1203,   -35, -1203,   346,
    -666, -1203, -1203, -1203, -1203, -1203,  -354,  -347, -1046,  -800,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,
     265,  -656,  -756, -1203,   241,  -117,  -723, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203,   597,   598,  -420,   198,    45, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203,   -56, -1203, -1203,   -68,
   -1203,  -353,   -84,    -9, -1203, -1203,   299, -1203, -1203,    96,
      80,  -113,   304, -1203, -1203,    97, -1203,  -726, -1203, -1203,
   -1203, -1203,  -240,  -818, -1203,  -128,  -626, -1203,  -691, -1203,
   -1203, -1203, -1203,  -952, -1203, -1203, -1203, -1203,  -103,    99,
   -1203
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   798,   799,   800,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,  1035,
     650,   247,   248,   804,   805,   806,  1104,   249,   372,   250,
     373,   374,   375,  1348,  1349,  1297,   251,   783,   252,   486,
     706,   912,  1105,   253,   254,   255,   256,   257,   258,   376,
     377,   582,   988,   989,  1081,   992,   259,   260,   508,   261,
     262,   263,   518,   447,   875,   876,   264,   519,   265,   521,
     266,   267,   268,   525,   526,  1060,   734,   269,   661,   710,
     662,   668,  1061,  1062,  1063,   711,   522,   523,   927,   928,
    1256,   524,   924,   925,  1120,  1121,  1122,  1123,   270,   657,
     658,   271,  1024,  1025,   272,   273,   274,   275,   742,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   545,   546,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   572,   573,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   781,   316,   317,   318,  1083,   684,   685,
     686,  1362,  1388,  1389,  1382,  1383,  1390,  1384,  1084,  1085,
     319,   320,  1086,   321,   322,   323,   324,   325,   326,   327,
     979,   735,   932,  1133,   933,   934,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   629,  1028,   338,   339,
     340,   341,   342,   343,   344,   703,   704,   345,  1111,  1112,
    1244,  1036,   438,   346,   347,   348,   750,   961,   751,   752,
     753,   754,   755,   756,   757,   962,   963,   617,   618,   619,
     620,   621,  1345,  1346,   622,  1284,  1183,  1288,  1285,   623,
     624,   965,   976,  1154,   966,   967,   972,   968,  1272,  1150,
     951
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       426,   749,   464,   864,  1016,   592,   935,   869,   761,   762,
     763,   764,   439,   977,   978,  1040,   626,   471,   890,  1165,
     868,   719,  1082,   459,  1243,   964,   733,  1158,   473,   729,
     872,     4,   467,   738,   688,   739,   740,  1232,   741,   897,
     743,  1341,  1329,   901,   671,  1360,   935,   935,   744,   745,
     730,  1151,  1265,   729,   591,   730,  1300,   453,  1051,   460,
     861,  1252,  1253,   506,   591,   349,   350,   351,   352,   353,
     354,   840,   506,   461,   378,   867,  1109,   355,   935,   672,
     647,   651,   908,  1151,   940,   664,  1106,  1074,  1075,  1013,
     941,   842,   945,  1074,  1075,   465,   861,   891,   943,  1074,
    1075,   881,   361,   731,  1140,   895,  1014,   439,  1117,   469,
     575,   883,   587,    74,   379,   470,   577,  1146,   695,   696,
    1301,   698,   699,   700,   701,    85,   588,  1119,  1266,   707,
     818,  1361,   708,   709,   362,   363,   919,   862,  1181,   648,
     713,   714,   715,   507,   383,   589,  1015,   841,   720,    99,
    1380,  1003,   920,   746,  1074,  1176,   747,  1147,   726,   727,
     898,   899,   892,   896,   902,   903,  1107,   843,  1074,  1075,
     380,  1074,   984,   887,  1076,   900,   873,   882,   590,   904,
    1076,  1232,  1386,   649,   568,   610,  1076,   884,   732,   673,
     689,  1331,  1077,   646,  1078,  1182,  1342,  1186,  1077,  1204,
    1078,   749,   749,  1082,  1077,   732,  1078,   909,  1413,   474,
     732,  1152,  1153,  1082,  1418,  1054,   874,   427,  1421,   548,
     780,  1079,  1071,  1290,   732,   104,  1052,  1079,  1274,   732,
     732,   104,  1291,  1079,   944,  1162,   549,   104,   381,   382,
    1282,   116,  1368,  1152,  1153,   946,   952,   116,   985,  1172,
     610,   813,   432,   116,   574,  1076,  1072,   576,   527,  1077,
    1292,  1078,  1080,   748,   440,  1294,   819,  1191,  1226,  1381,
     593,   367,  1074,  1077,  1231,  1078,  1077,   986,  1078,   631,
     143,   606,   634,  1386,  1351,   594,   143,  1387,  1079,   441,
     460,   916,   143,   460,   628,   820,   821,   854,   822,   823,
     935,  1141,  1079,  1283,   635,  1079,   104,  1371,   729,   368,
     369,   370,   371,   729,  1371,   953,   952,  1409,   482,   611,
     610,  1073,   116,   483,   442,  1173,   640,   641,  1380,   643,
     998,   645,  1074,  1415,   612,   652,  1293,   917,   444,   445,
     579,  1295,   987,  1316,   998,   566,   586,   613,   551,   614,
     676,   991,   597,   655,  1327,   443,   439,  1082,   863,   615,
    1352,   143,   616,  1053,   801,   687,   923,   555,   118,   439,
     630,   692,   509,   938,   552,   448,   556,  1077,   510,  1078,
     500,   511,   512,  1372,   611,   953,   555,   553,  1406,   513,
    1373,  1370,   446,  1410,     4,   556,   501,   638,   449,   612,
     601,   954,   955,   956,   602,   802,  1079,  1328,  1130,  1416,
     803,   749,   613,   433,   614,  1278,   595,  1159,   450,   958,
    1027,   554,  1030,   749,   615,  1160,   960,   616,   439,   994,
     596,   659,   660,   663,   719,   434,  1269,  1077,  1131,  1078,
     670,   603,  1270,   679,   808,  1002,   995,  1403,   935,   809,
    1271,  1005,   990,   659,   611,   462,  1132,  1006,  1007,   775,
     776,  1066,  1010,  1067,  1358,   774,  1079,   991,   604,   612,
     777,   954,   955,   956,  1018,   705,    74,   557,  1056,  1057,
    1019,   957,   613,   712,   614,   514,   548,   515,    85,   958,
     558,   973,   974,   996,   615,   959,   960,   616,  1013,   466,
    1116,   516,  1175,   549,  1044,  1045,   472,  1047,   730,  1049,
     997,  1117,    99,   975,  1277,  1185,   746,   485,   580,   747,
    1023,  1118,   585,  1336,  1337,   555,   550,   517,   605,  1069,
    1119,   836,   837,  1192,   556,   475,  1056,  1057,   845,  1058,
    1090,  1091,  1092,   478,  1095,  1096,  1097,  1098,  1099,  1100,
     484,  1102,  1103,  1397,   476,   860,   477,   935,   481,  1314,
    1385,  1391,   850,   923,  1318,   853,   730,  1269,   479,  1148,
     480,   827,   784,  1270,  1149,   349,   350,   351,   485,   886,
     354,  1271,  1136,  1385,  1138,  1139,   487,   802,  1059,  1391,
     807,   778,   803,  1340,   778,   490,   778,  1377,  1340,   488,
     828,   829,  1264,   830,   831,   913,   569,   570,   428,  1267,
    1268,   429,   430,  1008,  1009,   431,   816,   824,   749,   817,
     825,   607,   608,   609,  1056,  1057,  1169,   369,   370,   371,
     935,  1249,  1250,  1088,   489,  1089,  1093,   439,  1094,   491,
     439,   583,   584,   758,   759,   947,  1179,   765,   766,  1363,
     492,   767,   768,  1366,   980,   980,  1338,  1339,   871,   788,
     789,   790,   791,   792,   793,   794,   795,   796,   797,   493,
     494,   495,   504,   497,   888,  1201,   528,   505,   529,   559,
     547,  1202,   560,   561,   578,   562,   571,   349,  1208,   581,
     591,   598,  1210,  1211,  1375,  1213,   599,   369,  1393,   632,
    1217,   633,   639,   642,   644,   656,   349,   350,   351,   352,
     353,   354,   665,   666,   922,   667,   669,   680,   355,   406,
     936,   429,  1334,  1335,   356,   431,   437,   452,   682,   530,
     683,   690,   693,  1020,   694,   357,   358,   531,   532,   359,
     533,   702,   360,   361,   691,   697,   718,   534,   723,   728,
     722,   535,   724,   536,   725,  1246,   769,   770,   537,   782,
     936,   936,   936,   936,  1248,   771,   923,   772,   785,   810,
     811,   814,   826,   786,   538,   362,   363,   364,   815,  1260,
     833,   787,  1261,   832,  1263,   834,   851,   835,   838,   839,
     846,   847,   936,  1369,   848,   852,   855,   856,   539,   540,
     541,   542,   543,   544,   849,   857,   858,   865,   866,   870,
     877,   878,   880,   893,   879,   905,   894,   907,   910,   915,
     914,   365,   906,   921,   942,   918,   999,   926,   929,   937,
     939,  1029,   982,  1029,   950,   969,   970,   803,   983,   729,
     971,  1021,  1004,  1011,  1026,  1012,  1023,  1033,  1022,  1017,
    1305,  1039,  1032,  1034,  1307,  1037,  1308,  1038,  1050,  1042,
    1043,  1046,  1312,  1068,  1041,  1048,  1065,  1070,  1087,  1055,
    1101,  1108,   630,   603,   630,  1113,  1320,  1321,  1322,  1323,
    1324,   366,  1325,  1326,  1110,  1114,  1124,  1126,  1128,  1129,
    1174,  1167,  1137,  1142,  1164,  1143,  1166,  1171,  1145,  1155,
    1168,     4,  1332,  1144,  1333,  1180,  1184,  1196,  1187,  1188,
    1189,  1197,   367,  1198,  1199,  1200,  1203,  1125,  1212,  1214,
     527,  1220,  1215,  1216,  1228,  1195,  1223,  1225,  1134,  1234,
    1135,  1241,  1117,  1235,  1224,  1236,  1240,  1237,  1350,  1255,
    1206,  1354,  1262,  1356,  1258,  1357,  1233,  1259,  1276,   986,
     368,   369,   370,   371,  1280,  1286,  1281,  1287,  1303,  1296,
    1238,  1304,  1302,  1299,  1222,  1306,  1313,  1317,  1330,  1343,
    1013,  1353,  1359,  1367,  1374,  1378,  1365,  1170,  1229,  1379,
    1402,  1399,  1344,  1392,  1412,  1394,  1405,   991,  1408,  1417,
     716,  1420,  1396,  1350,   496,   498,   717,   502,   499,   812,
    1178,  1001,   625,  1376,   627,   600,  1242,   993,  1279,   503,
     721,  1064,   520,  1127,   936,  1311,  1219,  1209,  1247,  1257,
    1400,  1398,  1115,  1251,   681,  1254,   760,  1193,  1207,   737,
     889,   736,   565,   567,   659,  1407,  1404,   981,  1227,   663,
    1031,  1411,  1000,  1245,  1177,  1239,   948,   674,   675,  1163,
    1218,  1275,   949,  1156,  1347,  1289,  1273,  1157,  1161,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1230,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   705,     0,     0,     0,     0,     0,     0,     0,
       0,   460,     0,     0,     0,   712,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   936,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1298,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1309,  1310,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1315,     0,     0,
       0,     0,  1319,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   936,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1355,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1364,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   460,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   936,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1395,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1401,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,  1414,     0,     0,     5,     6,  1419,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
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
     141,   142,   143,     0,   144,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
     384,   385,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,   393,    21,    22,    23,
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
     463,   123,   124,   125,     0,   126,   127,   128,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,   143,     0,   409,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,     0,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,   384,   385,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,   393,
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
     773,     0,   122,     0,   123,   124,   125,     0,   126,   127,
     128,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   409,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,   384,   385,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,   393,    21,    22,    23,    24,    25,    26,    27,
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
     120,   121,     0,     0,     0,   122,   779,   123,   124,   125,
       0,   126,   127,   128,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   409,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,   384,
     385,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,   393,    21,    22,    23,    24,
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
       0,     0,   119,   120,   121,     0,   844,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   409,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,   384,   385,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,   393,    21,
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
       0,   117,   118,     0,     0,   119,   120,   121,     0,   859,
       0,   122,     0,   123,   124,   125,     0,   126,   127,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     409,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,   384,   385,     0,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,   393,    21,    22,    23,    24,    25,    26,    27,     0,
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
     142,   143,     0,   409,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,   384,   385,
       0,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,   393,    21,    22,    23,    24,    25,
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
       0,   119,   120,   121,     0,  1194,     0,   122,     0,   123,
     124,   125,     0,   126,   127,   128,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   409,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,     0,     0,
       0,   384,   385,     0,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,   393,    21,    22,
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
     117,   118,     0,     0,   119,   120,   121,     0,  1205,     0,
     122,     0,   123,   124,   125,     0,   126,   127,   128,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   409,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,   384,   385,     0,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
     393,    21,    22,    23,    24,    25,    26,    27,     0,    28,
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
       0,  1221,     0,   122,     0,   123,   124,   125,     0,   126,
     127,   128,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   409,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,     0,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     4,     0,     0,     0,     0,     5,     6,     0,
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
     216,   217,   218,   219,   220,     1,     0,     0,     0,     0,
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
     139,   140,     0,     0,   141,   142,   143,     0,   409,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,     0,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,     1,     0,
       0,     0,     0,     0,     0,     2,     3,     0,     4,     0,
       0,     0,     0,   384,   385,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,   393,
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
       0,   409,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,   384,   385,     0,     7,
     387,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,   392,   393,    21,    22,   395,    24,    25,    26,    27,
       0,   396,   397,    30,   398,   399,   400,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,     0,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,     0,    72,    73,
       0,     0,     0,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,     0,    85,     0,    86,    87,    88,
      89,     0,    90,     0,     0,     0,   404,    92,    93,    94,
      95,     0,     0,     0,     0,     0,    96,    97,    98,    99,
     100,   101,   102,     0,     0,     0,   103,   104,   563,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   111,   112,
     113,   114,   115,   116,     0,   564,   118,     0,     0,   119,
     120,   121,     0,     0,     0,   122,     0,   123,   124,   125,
       0,   126,   127,   128,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   409,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   410,   154,   412,   156,   413,   414,
     159,   160,   161,   162,   163,   164,   415,   166,   167,   416,
     417,   418,   171,   419,   420,   421,   175,   422,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   423,   424,   425,   216,
     217,   218,   219,   220,     1,     0,     0,     0,     0,     0,
       0,     2,     3,     0,     4,     0,     0,     0,     0,   384,
     385,     0,     7,   387,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,   392,   393,    21,    22,   395,    24,
      25,    26,    27,     0,   396,   397,    30,   398,   399,   400,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,     0,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
       0,    72,    73,     0,     0,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,     0,    85,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,   404,
      92,    93,    94,    95,     0,     0,     0,     0,     0,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,   103,
     104,   105,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     0,   117,   118,
       0,     0,   119,   120,   121,     0,     0,     0,   122,     0,
     123,   124,   125,     0,   126,   127,   128,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   409,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   410,   154,   412,
     156,   413,   414,   159,   160,   161,   162,   163,   164,   415,
     166,   167,   416,   417,   418,   171,   419,   420,   421,   175,
     422,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   423,
     424,   425,   216,   217,   218,   219,   220,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,   911,   385,     0,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,   393,    21,
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
     409,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,   384,   385,     0,   386,   387,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
     392,   393,    21,    22,   395,    24,    25,    26,    27,     0,
     396,   397,    30,   398,   399,   400,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,     0,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,     0,    72,    73,     0,
       0,     0,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,     0,    85,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,   404,    92,    93,    94,    95,
       0,     0,     0,     0,     0,    96,    97,    98,    99,   100,
     101,   102,     0,     0,     0,   103,   104,     0,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   111,   112,   113,
     114,   115,   116,     0,     0,     0,     0,     0,   119,   120,
     121,     0,     0,     0,   122,     0,   123,   124,   125,     0,
       0,     0,   128,     0,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,   143,     0,   409,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   410,   154,   412,   156,   413,   414,   159,
     160,   161,   162,   163,   164,   415,   166,   167,   416,   417,
     418,   171,   419,   420,   421,   175,   422,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   423,   424,   425,   216,   217,
     218,   219,   220,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     0,     0,     0,     0,     0,   384,   385,
       0,   386,   387,   454,   389,   455,   456,    13,    14,    15,
      16,    17,    18,   392,   393,   457,    22,   395,    24,    25,
      26,    27,     0,   396,   397,    30,   398,   399,   400,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,     0,     0,    62,     0,    63,
      64,    65,   458,     0,     0,    69,    70,    71,     0,     0,
       0,    73,     0,     0,     0,     0,    75,    76,    77,     0,
       0,    80,    81,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,   404,    92,
      93,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      98,     0,   100,   101,   102,     0,     0,     0,     0,     0,
       0,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     407,   112,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   121,     0,     0,     0,   122,     0,   123,
     124,     0,     0,     0,     0,   128,     0,   129,     0,   130,
     131,   132,   133,   408,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,     0,     0,   409,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   410,   154,   412,   156,
     413,   414,   159,   160,   161,   162,   163,   164,   415,   166,
     167,   416,   417,   418,   171,   419,   420,   421,   175,   422,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   423,   424,
     425,   216,   217,   218,   219,   220,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     0,     0,     0,     0,
       0,   384,   385,     0,   386,   387,   388,   389,   390,   391,
      13,    14,    15,    16,    17,    18,   392,   393,   394,    22,
     395,    24,    25,    26,    27,     0,   396,   397,    30,   398,
     399,   400,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   401,   402,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   403,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   404,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   102,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   407,   112,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,     0,     0,     0,     0,     0,   128,     0,
     129,     0,   130,   131,   132,   133,   408,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   409,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   410,
     411,   412,   156,   413,   414,   159,   160,   161,   162,   163,
     164,   415,   166,   167,   416,   417,   418,   171,   419,   420,
     421,   175,   422,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   423,   424,   425,   216,   217,   218,   219,   220,   435,
       0,     0,     0,     3,     0,     0,     0,     0,     0,     0,
     384,   385,     0,   386,   387,   388,   389,   390,   391,    13,
      14,    15,    16,    17,    18,   392,   393,   394,    22,   395,
      24,    25,    26,    27,     0,   396,   397,    30,   398,   399,
     400,    34,    35,    36,    37,    38,    39,    40,    41,    42,
     401,   402,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,     0,     0,    62,
       0,    63,    64,    65,   403,     0,     0,    69,    70,    71,
       0,     0,     0,    73,     0,     0,     0,     0,    75,    76,
      77,     0,     0,    80,    81,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,     0,    90,     0,     0,     0,
     404,    92,    93,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,     0,   100,   101,   102,   436,     0,     0,
     437,     0,     0,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   407,   112,   113,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,     0,     0,     0,   122,
       0,   123,     0,     0,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   408,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,     0,     0,   409,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   410,   411,
     412,   156,   413,   414,   159,   160,   161,   162,   163,   164,
     415,   166,   167,   416,   417,   418,   171,   419,   420,   421,
     175,   422,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,     0,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     423,   424,   425,   216,   217,   218,   219,   220,   435,     0,
       0,     0,     3,     0,   653,     0,     0,     0,     0,   384,
     385,     0,   386,   387,   388,   389,   390,   391,    13,    14,
      15,    16,    17,    18,   392,   393,   394,    22,   395,    24,
      25,    26,    27,     0,   396,   397,    30,   398,   399,   400,
      34,    35,    36,    37,    38,    39,    40,    41,    42,   401,
     402,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    62,     0,
      63,    64,    65,   403,     0,     0,    69,    70,    71,     0,
       0,     0,    73,     0,     0,     0,     0,    75,    76,    77,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,     0,    90,     0,     0,     0,   404,
      92,    93,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,     0,   100,   101,   102,     0,     0,     0,     0,
       0,     0,   106,   107,     0,     0,     0,     0,   108,   109,
     110,   407,   112,   113,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,   122,   654,
     123,     0,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   408,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,     0,     0,   409,   145,     0,
     146,   147,   148,   149,   150,   151,   152,   410,   411,   412,
     156,   413,   414,   159,   160,   161,   162,   163,   164,   415,
     166,   167,   416,   417,   418,   171,   419,   420,   421,   175,
     422,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,     0,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   423,
     424,   425,   216,   217,   218,   219,   220,   435,     0,     0,
       0,     3,     0,     0,     0,     0,     0,     0,   384,   385,
       0,   386,   387,   388,   389,   390,   391,    13,    14,    15,
      16,    17,    18,   392,   393,   394,    22,   395,    24,    25,
      26,    27,     0,   396,   397,    30,   398,   399,   400,    34,
      35,    36,    37,    38,    39,    40,    41,    42,   401,   402,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,     0,     0,    62,     0,    63,
      64,    65,   403,     0,     0,    69,    70,    71,     0,     0,
       0,    73,     0,     0,     0,     0,    75,    76,    77,     0,
       0,    80,    81,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,     0,    90,     0,     0,     0,   404,    92,
      93,     0,     0,     0,     0,     0,     0,     0,    96,    97,
      98,     0,   100,   101,   102,     0,     0,     0,     0,     0,
       0,   106,   107,     0,     0,     0,     0,   108,   109,   110,
     407,   112,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   121,     0,     0,     0,   122,     0,   123,
       0,     0,     0,     0,     0,     0,     0,   129,     0,   130,
     131,   132,   133,   408,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,     0,     0,   409,   145,     0,   146,
     147,   148,   149,   150,   151,   152,   410,   411,   412,   156,
     413,   414,   159,   160,   161,   162,   163,   164,   415,   166,
     167,   416,   417,   418,   171,   419,   420,   421,   175,   422,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   423,   424,
     425,   216,   217,   218,   219,   220,   468,     0,     3,     0,
       0,     0,     0,     0,     0,   384,   385,     0,   386,   387,
     388,   389,   390,   391,    13,    14,    15,    16,    17,    18,
     392,   393,   394,    22,   395,    24,    25,    26,    27,     0,
     396,   397,    30,   398,   399,   400,    34,    35,    36,    37,
      38,    39,    40,    41,    42,   401,   402,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    62,     0,    63,    64,    65,   403,
       0,     0,    69,    70,    71,     0,     0,     0,    73,     0,
       0,     0,     0,    75,    76,    77,     0,     0,    80,    81,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,   404,    92,    93,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,     0,   100,
     101,   102,     0,     0,     0,     0,     0,     0,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   407,   112,   113,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,     0,     0,     0,   122,     0,   123,     0,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     408,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,     0,     0,   409,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   410,   411,   412,   156,   413,   414,   159,
     160,   161,   162,   163,   164,   415,   166,   167,   416,   417,
     418,   171,   419,   420,   421,   175,   422,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   423,   424,   425,   216,   217,
     218,   219,   220,     3,     0,     0,     0,     0,     0,     0,
     384,   385,     0,   386,   387,   388,   389,   390,   391,    13,
      14,    15,    16,    17,    18,   392,   393,   394,    22,   395,
      24,    25,    26,    27,     0,   396,   397,    30,   398,   399,
     400,    34,    35,    36,    37,    38,    39,    40,    41,    42,
     401,   402,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,     0,     0,    62,
       0,    63,    64,    65,   403,     0,     0,    69,    70,    71,
       0,     0,     0,    73,     0,     0,     0,     0,    75,    76,
      77,     0,     0,    80,    81,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,     0,    90,     0,     0,     0,
     404,    92,    93,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,     0,   100,   101,   102,   405,     0,     0,
     406,     0,     0,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   407,   112,   113,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,     0,     0,     0,   122,
       0,   123,     0,     0,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   408,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,     0,     0,   409,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   410,   411,
     412,   156,   413,   414,   159,   160,   161,   162,   163,   164,
     415,   166,   167,   416,   417,   418,   171,   419,   420,   421,
     175,   422,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,     0,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     423,   424,   425,   216,   217,   218,   219,   220,     3,     0,
       0,     0,     0,     0,     0,   384,   385,     0,   386,   387,
     388,   389,   390,   391,    13,    14,    15,    16,    17,    18,
     392,   393,   394,    22,   395,    24,    25,    26,    27,     0,
     396,   397,    30,   398,   399,   400,    34,    35,    36,    37,
      38,    39,    40,    41,    42,   401,   402,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    62,     0,    63,    64,    65,   403,
       0,     0,    69,    70,    71,     0,     0,     0,    73,     0,
       0,     0,     0,    75,    76,    77,     0,     0,    80,    81,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,   404,    92,    93,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,     0,   100,
     101,   102,   451,     0,     0,   452,     0,     0,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   407,   112,   113,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,     0,     0,     0,   122,     0,   123,     0,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     408,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,     0,     0,   409,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   410,   411,   412,   156,   413,   414,   159,
     160,   161,   162,   163,   164,   415,   166,   167,   416,   417,
     418,   171,   419,   420,   421,   175,   422,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   423,   424,   425,   216,   217,
     218,   219,   220,     3,     0,     0,     0,     0,     0,     0,
     384,   385,     0,   386,   387,   388,   389,   390,   391,    13,
      14,    15,    16,    17,    18,   392,   393,   394,    22,   395,
      24,    25,    26,    27,     0,   396,   397,    30,   398,   399,
     400,    34,    35,    36,    37,    38,    39,    40,    41,    42,
     401,   402,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,     0,     0,    62,
       0,    63,    64,    65,   403,     0,     0,    69,    70,    71,
       0,     0,     0,    73,     0,     0,     0,     0,    75,    76,
      77,     0,     0,    80,    81,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,     0,    90,     0,     0,     0,
     404,    92,    93,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,     0,   100,   101,   102,     0,     0,     0,
       0,     0,     0,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   407,   112,   113,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,     0,     0,     0,   122,
     636,   123,     0,     0,     0,     0,     0,   637,     0,   129,
       0,   130,   131,   132,   133,   408,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,     0,     0,   409,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   410,   411,
     412,   156,   413,   414,   159,   160,   161,   162,   163,   164,
     415,   166,   167,   416,   417,   418,   171,   419,   420,   421,
     175,   422,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,     0,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     423,   424,   425,   216,   217,   218,   219,   220,     3,     0,
       0,     0,     0,     0,     0,   384,   385,     0,   386,   387,
     388,   389,   390,   391,    13,    14,    15,    16,    17,    18,
     392,   393,   394,    22,   395,    24,    25,    26,    27,     0,
     396,   397,    30,   398,   399,   400,    34,    35,    36,    37,
      38,    39,    40,    41,    42,   401,   402,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    62,     0,    63,    64,    65,   403,
       0,     0,    69,    70,    71,     0,     0,     0,    73,     0,
       0,     0,     0,    75,    76,    77,     0,     0,    80,    81,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,   404,    92,    93,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,     0,   100,
     101,   102,     0,     0,     0,     0,     0,     0,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   407,   112,   113,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,     0,     0,     0,   122,   677,   123,     0,     0,     0,
       0,     0,   678,     0,   129,     0,   130,   131,   132,   133,
     408,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,     0,     0,   409,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   410,   411,   412,   156,   413,   414,   159,
     160,   161,   162,   163,   164,   415,   166,   167,   416,   417,
     418,   171,   419,   420,   421,   175,   422,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   423,   424,   425,   216,   217,
     218,   219,   220,     3,     0,     0,     0,     0,     0,     0,
     384,   385,     0,   386,   387,   454,   389,   455,   456,    13,
      14,    15,    16,    17,    18,   392,   393,   457,    22,   395,
      24,    25,    26,    27,     0,   396,   397,    30,   398,   399,
     400,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,     0,     0,    62,
       0,    63,    64,    65,   458,     0,     0,    69,    70,    71,
       0,     0,     0,    73,     0,     0,     0,     0,    75,    76,
      77,     0,     0,    80,    81,  1190,     0,     0,     0,     0,
       0,    86,    87,    88,    89,     0,    90,     0,     0,     0,
     404,    92,    93,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,     0,   100,   101,   930,     0,     0,     0,
       0,     0,     0,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   407,   112,   113,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,     0,     0,     0,   122,
       0,   123,   124,     0,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   408,   135,   136,   137,   138,
     139,   140,     0,     0,   931,   142,     0,     0,   409,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   410,   154,
     412,   156,   413,   414,   159,   160,   161,   162,   163,   164,
     415,   166,   167,   416,   417,   418,   171,   419,   420,   421,
     175,   422,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,     0,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     423,   424,   425,   216,   217,   218,   219,   220,     3,     0,
       0,     0,     0,     0,     0,   384,   385,     0,   386,   387,
     454,   389,   455,   456,    13,    14,    15,    16,    17,    18,
     392,   393,   457,    22,   395,    24,    25,    26,    27,     0,
     396,   397,    30,   398,   399,   400,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    62,     0,    63,    64,    65,   458,
       0,     0,    69,    70,    71,     0,     0,     0,    73,     0,
       0,     0,     0,    75,    76,    77,     0,     0,    80,    81,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,   404,    92,    93,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,     0,   100,
     101,   930,     0,     0,     0,     0,     0,     0,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   407,   112,   113,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,     0,     0,     0,   122,     0,   123,   124,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     408,   135,   136,   137,   138,   139,   140,     0,     0,   931,
     142,     0,     0,   409,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   410,   154,   412,   156,   413,   414,   159,
     160,   161,   162,   163,   164,   415,   166,   167,   416,   417,
     418,   171,   419,   420,   421,   175,   422,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   423,   424,   425,   216,   217,
     218,   219,   220,     3,     0,     0,     0,     0,     0,     0,
     384,   385,     0,   386,   387,   454,   389,   455,   456,    13,
      14,    15,    16,    17,    18,   392,   393,   457,    22,   395,
      24,    25,    26,    27,     0,   396,   397,    30,   398,   399,
     400,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,     0,     0,    62,
       0,    63,    64,    65,   458,     0,     0,    69,    70,    71,
       0,     0,     0,    73,     0,     0,     0,     0,    75,    76,
      77,     0,     0,    80,    81,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,     0,    90,     0,     0,     0,
     404,    92,    93,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,     0,   100,   101,   930,     0,     0,     0,
       0,     0,     0,   106,   107,     0,     0,     0,     0,   108,
     109,   110,   407,   112,   113,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   121,     0,     0,     0,   122,
       0,   123,   124,     0,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   408,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,     0,     0,   409,   145,
       0,   146,   147,   148,   149,   150,   151,   152,   410,   154,
     412,   156,   413,   414,   159,   160,   161,   162,   163,   164,
     415,   166,   167,   416,   417,   418,   171,   419,   420,   421,
     175,   422,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,     0,   190,   191,     0,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     423,   424,   425,   216,   217,   218,   219,   220,     3,     0,
       0,     0,     0,     0,     0,   384,   385,     0,   386,   387,
     388,   389,   390,   391,    13,    14,    15,    16,    17,    18,
     392,   393,   394,    22,   395,    24,    25,    26,    27,     0,
     396,   397,    30,   398,   399,   400,    34,    35,    36,    37,
      38,    39,    40,    41,    42,   401,   402,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    62,     0,    63,    64,    65,   403,
       0,     0,    69,    70,    71,     0,     0,     0,    73,     0,
       0,     0,     0,    75,    76,    77,     0,     0,    80,    81,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
       0,    90,     0,     0,     0,   404,    92,    93,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,     0,   100,
     101,   102,     0,     0,     0,     0,     0,     0,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   407,   112,   113,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,     0,     0,     0,   122,     0,   123,     0,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     408,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,     0,     0,   409,   145,     0,   146,   147,   148,   149,
     150,   151,   152,   410,   411,   412,   156,   413,   414,   159,
     160,   161,   162,   163,   164,   415,   166,   167,   416,   417,
     418,   171,   419,   420,   421,   175,   422,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,     0,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   423,   424,   425,   216,   217,
     218,   219,   220
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         9,   547,   103,   659,   822,   358,   729,   663,   551,   552,
     553,   554,    21,   769,   770,   855,   369,   127,   684,   971,
     663,   505,   892,    68,  1110,   751,   527,   959,    21,    86,
      60,    20,   116,   530,     7,   532,   533,  1083,   535,    86,
     537,    20,  1244,    86,    30,    85,   769,   770,   545,   546,
      88,    88,    43,    86,    20,    88,   110,    66,   132,    68,
      99,  1121,  1122,    99,    20,    34,    35,    36,    37,    38,
      39,    99,    99,    82,   149,   132,   914,    46,   801,    65,
     433,   434,    99,    88,   136,   443,    99,     8,     9,    88,
     733,    99,   735,     8,     9,   104,    99,   120,   136,     8,
       9,    99,    71,   136,   136,   121,   105,   116,    98,   118,
     301,    99,   170,   102,    86,   124,   307,   206,   476,   477,
     174,   479,   480,   481,   482,   114,   184,   117,   119,   487,
     105,   171,   490,   491,   103,   104,   105,   176,    88,   105,
     493,   494,   495,   179,   145,   157,   145,   175,   506,   138,
       4,   807,   179,   142,     8,   993,   145,   246,   516,   517,
     207,   208,   185,   179,   207,   208,   179,   175,     8,     9,
     142,     8,    99,   176,    95,   222,   206,   175,   190,   222,
      95,  1227,    19,   149,   294,    92,    95,   175,   262,   175,
     163,  1251,   113,   149,   115,   145,   175,  1015,   113,  1039,
     115,   747,   748,  1073,   113,   262,   115,   224,  1410,   202,
     262,   248,   249,  1083,  1416,   871,   246,   142,  1420,   147,
     578,   142,   888,   260,   262,   146,   869,   142,  1160,   262,
     262,   146,  1184,   142,   735,   961,   164,   146,   210,   211,
     126,   162,  1328,   248,   249,   742,    88,   162,   175,    99,
      92,   604,   145,   162,   299,    95,   120,   302,   267,   113,
      99,   115,   183,   252,   110,    99,   241,  1023,   183,   123,
     155,   240,     8,   113,   183,   115,   113,   110,   115,   380,
     201,   365,   383,    19,    99,   170,   201,   124,   142,   110,
     299,    53,   201,   302,   378,   270,   271,   650,   273,   274,
    1023,   944,   142,   189,   405,   142,   146,    99,    86,   278,
     279,   280,   281,    86,    99,   157,    88,    99,   214,   226,
      92,   185,   162,   219,   110,   175,   427,   428,     4,   430,
     798,   432,     8,    99,   241,   436,   175,    99,    56,    57,
     349,   175,   175,   183,   812,   142,   355,   254,   109,   256,
     451,   142,   361,   437,   145,   142,   365,  1227,   136,   266,
     175,   201,   269,   136,    86,   466,   724,   189,   165,   378,
     379,   472,    45,   731,   135,    54,   198,   113,    51,   115,
      25,    54,    55,   175,   226,   157,   189,   148,   124,    62,
     175,  1343,   110,   175,    20,   198,    41,   406,   145,   241,
      30,   243,   244,   245,    34,   127,   142,   198,   134,   175,
     132,   957,   254,    26,   256,  1171,   170,   960,   145,   261,
     840,   182,   842,   969,   266,   267,   268,   269,   437,   137,
     184,   440,   441,   442,   918,    48,   258,   113,   164,   115,
     449,    71,   264,   452,   127,   803,   154,   123,  1171,   132,
     272,   809,   127,   462,   226,   110,   182,   810,   811,   569,
     570,   881,   815,   883,  1304,   566,   142,   142,    98,   241,
     571,   243,   244,   245,   832,   484,   102,   126,    58,    59,
     833,   253,   254,   492,   256,   158,   147,   160,   114,   261,
     139,   237,   238,   137,   266,   267,   268,   269,    88,   142,
      87,   174,   127,   164,   862,   863,   142,   865,    88,   867,
     154,    98,   138,   259,  1170,   105,   142,   142,   350,   145,
      92,   108,   354,   187,  1280,   189,   187,   200,   158,   887,
     117,   632,   633,   105,   198,   204,    58,    59,   639,    61,
     898,   899,   900,   145,   902,   903,   904,   905,   906,   907,
     110,   909,   910,  1371,   214,   656,   216,  1280,   214,  1225,
    1360,  1361,   646,   921,  1230,   649,    88,   258,   214,   258,
     216,   241,   581,   264,   263,    34,    35,    36,   142,   680,
      39,   272,   940,  1383,   942,   943,   227,   127,   110,  1389,
     599,   572,   132,  1284,   575,   145,   577,  1353,  1289,   231,
     270,   271,  1145,   273,   274,   706,   180,   181,   142,  1152,
    1153,   145,   142,   118,   119,   145,   239,   239,  1164,   242,
     242,   210,   211,   212,    58,    59,   984,   279,   280,   281,
    1353,   118,   119,   221,   231,   223,   221,   646,   223,   142,
     649,   352,   353,   548,   549,   746,  1004,   555,   556,  1315,
     110,   557,   558,  1319,   771,   772,  1282,  1283,   667,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,   279,
     279,   279,   179,     0,   683,  1033,   156,   179,    84,    68,
     251,  1034,   188,    93,   145,    94,   143,    34,  1046,    34,
      20,   141,  1050,  1051,  1350,  1053,   110,   279,  1364,   142,
    1058,   142,   142,   175,   175,   142,    34,    35,    36,    37,
      38,    39,   268,   268,   723,   110,   110,   142,    46,   145,
     729,   145,  1265,  1266,    52,   145,   145,   145,   175,   122,
      27,    15,   202,   834,    20,    63,    64,   130,   131,    67,
     133,   220,    70,    71,   175,   175,    25,   140,   110,    99,
     158,   144,   159,   146,   159,  1113,   220,    86,   151,   145,
     769,   770,   771,   772,  1117,    86,  1124,    86,    20,   149,
     149,   117,    20,    99,   167,   103,   104,   105,   122,  1137,
     122,    99,  1140,   282,  1142,   142,    88,   172,   175,   172,
     172,   172,   801,  1336,   172,    30,    88,   172,   191,   192,
     193,   194,   195,   196,   175,   175,   175,   132,    99,   172,
     175,   175,   172,   172,   175,    86,   172,   214,   132,   172,
     175,   149,   226,   159,   136,   179,   122,   110,   110,   110,
     110,   840,   172,   842,   269,   250,   252,   132,   173,    86,
     257,   172,   132,   271,   142,   272,    92,   186,   172,   272,
    1203,    88,   172,   122,  1212,   149,  1214,   122,   132,   172,
     110,   136,  1220,   172,   142,   110,   142,    27,    20,   246,
     110,   172,   881,    71,   883,   142,  1234,  1235,  1236,  1237,
    1238,   209,  1240,  1241,   235,   110,    99,    99,   145,   145,
     991,    47,   136,   136,   136,   172,   272,    86,   247,   247,
     134,    20,  1255,   175,  1262,   272,    20,   175,   159,   179,
     172,   175,   240,   134,   175,   175,    99,   926,   132,   136,
     929,    61,   110,   110,     6,  1026,   175,   122,   937,   222,
     939,   132,    98,   222,   175,   222,   174,   222,  1296,    98,
    1041,  1299,   136,  1301,   175,  1303,   179,   175,   265,   110,
     278,   279,   280,   281,    86,    20,   172,    20,   116,   145,
     226,    88,   172,   174,  1065,   172,   172,   172,   172,    20,
      88,    86,    59,   110,    98,   174,   185,   986,  1079,   110,
      85,   174,   255,   185,   110,   185,   171,   142,   185,   110,
     504,   175,   255,  1351,   221,   224,   504,   227,   224,   603,
    1000,   802,   368,  1351,   372,   363,  1106,   784,  1172,   228,
     508,   876,   266,   929,  1023,  1218,  1060,  1048,  1114,  1126,
    1378,  1374,   921,  1121,   462,  1124,   550,  1024,  1043,   529,
     684,   528,   287,   291,  1043,  1389,  1383,   772,  1073,  1048,
     842,  1399,   801,  1111,   999,  1101,   747,   450,   450,   969,
    1059,  1164,   748,   957,  1294,  1183,  1159,   958,   961,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1080,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1110,    -1,    -1,    -1,  1114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1215,  1216,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1226,    -1,    -1,
      -1,    -1,  1231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1280,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1316,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1328,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1353,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1367,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1379,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,  1412,    -1,    -1,    25,    26,  1417,    28,
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
     279,   280,   281,   282,   283,    10,    -1,    -1,    -1,    -1,
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
     175,   176,   177,   178,    -1,   180,   181,   182,    -1,   184,
      -1,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,    -1,    -1,   199,   200,   201,    -1,   203,   204,
      -1,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    10,    -1,
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
     282,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
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
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,    10,    -1,    -1,    -1,    -1,    -1,
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
     276,   277,   278,   279,   280,   281,   282,    10,    -1,    -1,
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
     280,   281,   282,    10,    -1,    -1,    -1,    -1,    -1,    -1,
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
     277,   278,   279,   280,   281,   282,    10,    -1,    -1,    -1,
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
     274,   275,   276,   277,   278,   279,   280,   281,   282,    10,
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
     281,   282,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
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
     278,   279,   280,   281,   282,    10,    -1,    -1,    -1,    -1,
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
     275,   276,   277,   278,   279,   280,   281,   282,    10,    -1,
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
     282,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
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
     279,   280,   281,   282,    10,    -1,    -1,    -1,    -1,    -1,
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
     276,   277,   278,   279,   280,   281,   282,    10,    -1,    -1,
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
     140,   141,    -1,    -1,    -1,   145,   146,    -1,   148,   149,
      -1,    -1,    -1,    -1,   154,   155,   156,   157,   158,   159,
     160,   161,   162,    -1,    -1,    -1,    -1,    -1,   168,   169,
     170,    -1,    -1,    -1,   174,    -1,   176,   177,   178,    -1,
      -1,    -1,   182,    -1,   184,    -1,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,    -1,   199,
     200,   201,    -1,   203,   204,    -1,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,   251,   252,    -1,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,    10,    -1,    -1,    -1,    -1,    -1,    -1,
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
     277,   278,   279,   280,   281,   282,    10,    -1,    -1,    -1,
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
     274,   275,   276,   277,   278,   279,   280,   281,   282,    14,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,
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
     275,   276,   277,   278,   279,   280,   281,   282,    14,    -1,
      -1,    -1,    18,    -1,    20,    -1,    -1,    -1,    -1,    25,
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
     276,   277,   278,   279,   280,   281,   282,    14,    -1,    -1,
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
     277,   278,   279,   280,   281,   282,    16,    -1,    18,    -1,
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
     280,   281,   282,    18,    -1,    -1,    -1,    -1,    -1,    -1,
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
     275,   276,   277,   278,   279,   280,   281,   282,    18,    -1,
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
     280,   281,   282,    18,    -1,    -1,    -1,    -1,    -1,    -1,
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
     175,   176,    -1,    -1,    -1,    -1,    -1,   182,    -1,   184,
      -1,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,    -1,    -1,   199,   200,    -1,    -1,   203,   204,
      -1,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,    -1,   251,   252,    -1,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    18,    -1,
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
     280,   281,   282,    18,    -1,    -1,    -1,    -1,    -1,    -1,
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
     275,   276,   277,   278,   279,   280,   281,   282,    18,    -1,
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
     280,   281,   282,    18,    -1,    -1,    -1,    -1,    -1,    -1,
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
     275,   276,   277,   278,   279,   280,   281,   282,    18,    -1,
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
     280,   281,   282
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
     282,   283,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   329,   330,   335,
     337,   344,   346,   351,   352,   353,   354,   355,   356,   364,
     365,   367,   368,   369,   374,   376,   378,   379,   380,   385,
     406,   409,   412,   413,   414,   415,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   462,   463,   464,   478,
     479,   481,   482,   483,   484,   485,   486,   487,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   506,   507,
     508,   509,   510,   511,   512,   515,   521,   522,   523,    34,
      35,    36,    37,    38,    39,    46,    52,    63,    64,    67,
      70,    71,   103,   104,   105,   149,   209,   240,   278,   279,
     280,   281,   336,   338,   339,   340,   357,   358,   149,    86,
     142,   210,   211,   145,    25,    26,    28,    29,    30,    31,
      32,    33,    40,    41,    42,    44,    50,    51,    53,    54,
      55,    65,    66,    89,   125,   142,   145,   157,   190,   203,
     213,   214,   215,   217,   218,   225,   228,   229,   230,   232,
     233,   234,   236,   275,   276,   277,   521,   142,   142,   145,
     142,   145,   145,    26,    48,    14,   142,   145,   520,   521,
     110,   110,   110,   142,    56,    57,   110,   371,    54,   145,
     145,   142,   145,   521,    30,    32,    33,    42,    89,   446,
     521,   521,   110,   175,   365,   521,   142,   520,    16,   521,
     521,   438,   142,    21,   202,   204,   214,   216,   145,   214,
     216,   214,   214,   219,   110,   142,   347,   227,   231,   231,
     145,   142,   110,   279,   279,   279,   300,     0,   302,   303,
      25,    41,   305,   364,   179,   179,    99,   179,   366,    45,
      51,    54,    55,    62,   158,   160,   174,   200,   370,   375,
     376,   377,   394,   395,   399,   381,   382,   521,   156,    84,
     122,   130,   131,   133,   140,   144,   146,   151,   167,   191,
     192,   193,   194,   195,   196,   430,   431,   251,   147,   164,
     187,   109,   135,   148,   182,   189,   198,   126,   139,    68,
     188,    93,    94,   147,   164,   429,   142,   435,   438,   180,
     181,   143,   450,   451,   446,   450,   446,   450,   145,   521,
     358,    34,   359,   357,   357,   358,   521,   170,   184,   157,
     190,    20,   519,   155,   170,   170,   184,   521,   141,   110,
     334,    30,    34,    71,    98,   158,   520,   210,   211,   212,
      92,   226,   241,   254,   256,   266,   269,   535,   536,   537,
     538,   539,   542,   547,   548,   339,   519,   340,   520,   504,
     521,   365,   142,   142,   365,   365,   175,   182,   521,   142,
     365,   365,   175,   365,   175,   365,   149,   519,   105,   149,
     328,   519,   365,    20,   175,   520,   142,   407,   408,   521,
     521,   386,   388,   521,   368,   268,   268,   110,   389,   110,
     521,    30,    65,   175,   502,   503,   365,   175,   182,   521,
     142,   407,   175,    27,   466,   467,   468,   365,     7,   163,
      15,   175,   365,   202,    20,   368,   368,   175,   368,   368,
     368,   368,   220,   513,   514,   521,   348,   368,   368,   368,
     387,   393,   521,   519,   519,   519,   307,   308,    25,   309,
     368,   367,   158,   110,   159,   159,   368,   368,    99,    86,
      88,   136,   262,   383,   384,   489,   414,   415,   417,   417,
     417,   417,   416,   417,   417,   417,   142,   145,   252,   453,
     524,   526,   527,   528,   529,   530,   531,   532,   420,   420,
     419,   421,   421,   421,   421,   422,   422,   423,   423,   220,
      86,    86,    86,   172,   365,   438,   438,   365,   451,   175,
     368,   461,   145,   345,   521,    20,    99,    99,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,   311,   312,
     313,    86,   127,   132,   331,   332,   333,   521,   127,   132,
     149,   149,   311,   519,   117,   122,   239,   242,   105,   241,
     270,   271,   273,   274,   239,   242,    20,   241,   270,   271,
     273,   274,   282,   122,   142,   172,   365,   365,   175,   172,
      99,   175,    99,   175,   172,   365,   172,   172,   172,   175,
     520,    88,    30,   520,   519,    88,   172,   175,   175,   172,
     365,    99,   176,   136,   489,   132,    99,   132,   384,   489,
     172,   521,    60,   206,   246,   372,   373,   175,   175,   175,
     172,    99,   175,    99,   175,   172,   365,   176,   521,   467,
     468,   120,   185,   172,   172,   121,   179,    86,   207,   208,
     222,    86,   207,   208,   222,    86,   226,   214,    99,   224,
     132,    25,   349,   365,   175,   172,    53,    99,   179,   105,
     179,   159,   521,   368,   400,   401,   110,   396,   397,   110,
     141,   199,   490,   492,   493,   494,   521,   110,   368,   110,
     136,   384,   136,   136,   383,   384,   417,   365,   524,   530,
     269,   558,    88,   157,   243,   244,   245,   253,   261,   267,
     268,   525,   533,   534,   535,   549,   552,   553,   555,   250,
     252,   257,   554,   237,   238,   259,   550,   490,   490,   488,
     493,   488,   172,   173,    99,   175,   110,   175,   360,   361,
     127,   142,   363,   345,   137,   154,   137,   154,   312,   122,
     492,   333,   368,   489,   132,   368,   519,   519,   118,   119,
     519,   271,   272,    88,   105,   145,   541,   272,   368,   519,
     365,   172,   172,    92,   410,   411,   142,   504,   505,   521,
     504,   505,   172,   186,   122,   327,   519,   149,   122,    88,
     327,   142,   172,   110,   368,   368,   136,   368,   110,   368,
     132,   132,   384,   136,   489,   246,    58,    59,    61,   110,
     383,   390,   391,   392,   373,   142,   504,   504,   172,   368,
      27,   468,   120,   185,     8,     9,    95,   113,   115,   142,
     183,   362,   463,   465,   476,   477,   480,    20,   221,   223,
     368,   368,   368,   221,   223,   368,   368,   368,   368,   368,
     368,   110,   368,   368,   334,   350,    99,   179,   172,   347,
     235,   516,   517,   142,   110,   400,    87,    98,   108,   117,
     402,   403,   404,   405,    99,   521,    99,   382,   145,   145,
     134,   164,   182,   491,   521,   521,   368,   136,   368,   368,
     136,   384,   136,   172,   175,   247,   206,   246,   258,   263,
     557,    88,   248,   249,   551,   247,   527,   557,   418,   421,
     267,   533,   535,   528,   136,   551,   272,    47,   134,   368,
     521,    86,    99,   175,   365,   127,   347,   506,   332,   368,
     272,    88,   145,   544,    20,   105,   541,   159,   179,   172,
     110,   490,   105,   411,   172,   365,   175,   175,   134,   175,
     175,   368,   519,    99,   327,   172,   365,   408,   368,   388,
     368,   368,   132,   368,   136,   110,   110,   368,   521,   392,
      61,   172,   365,   175,   175,   122,   183,   465,     6,   365,
     521,   183,   476,   179,   222,   222,   222,   222,   226,   514,
     174,   132,   350,   447,   518,   517,   368,   393,   519,   118,
     119,   404,   405,   405,   401,    98,   398,   397,   175,   175,
     368,   368,   136,   368,   421,    43,   119,   421,   421,   258,
     264,   272,   556,   556,   418,   529,   265,   489,   490,   361,
      86,   172,   126,   189,   543,   546,    20,    20,   545,   543,
     260,   551,    99,   175,    99,   175,   145,   343,   521,   174,
     110,   174,   172,   116,    88,   519,   172,   368,   368,   521,
     521,   391,   368,   172,   468,   521,   183,   172,   468,   521,
     368,   368,   368,   368,   368,   368,   368,   145,   198,   363,
     172,   405,   519,   368,   421,   421,   187,   490,   544,   544,
     546,    20,   175,    20,   255,   540,   541,   540,   341,   342,
     368,    99,   175,    86,   368,   521,   368,   368,   327,    59,
      85,   171,   469,   468,   521,   185,   468,   110,   447,   421,
     551,    99,   175,   175,    98,   489,   341,   490,   174,   110,
       4,   123,   472,   473,   475,   477,    19,   124,   470,   471,
     474,   477,   185,   468,   185,   521,   255,   541,   519,   174,
     368,   521,    85,   123,   475,   171,   124,   474,   185,    99,
     175,   368,   110,   363,   521,    99,   175,   110,   363,   521,
     175,   363
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
     545,   546,   547,   548,   549,   550,   551,   552
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   298,   299,   299,   300,   300,   300,   300,   301,   301,
     302,   302,   303,   303,   304,   305,   305,   305,   306,   306,
     307,   307,   308,   308,   308,   308,   309,   309,   309,   309,
     309,   309,   309,   310,   310,   311,   311,   312,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   314,   314,
     314,   314,   314,   314,   314,   314,   315,   315,   316,   317,
     317,   318,   318,   319,   320,   321,   321,   322,   322,   323,
     323,   323,   323,   324,   325,   326,   326,   326,   326,   327,
     327,   328,   328,   329,   329,   329,   329,   330,   331,   331,
     332,   332,   332,   333,   334,   334,   335,   335,   335,   336,
     336,   337,   338,   338,   339,   339,   340,   341,   341,   342,
     342,   343,   343,   344,   344,   345,   345,   345,   345,   346,
     347,   348,   348,   349,   349,   350,   350,   351,   352,   353,
     354,   354,   355,   355,   355,   356,   356,   356,   357,   357,
     357,   357,   358,   358,   359,   359,   360,   360,   361,   361,
     362,   363,   364,   365,   365,   366,   366,   367,   367,   368,
     368,   368,   368,   368,   368,   368,   368,   368,   368,   368,
     368,   368,   368,   368,   368,   368,   368,   369,   370,   371,
     371,   372,   372,   372,   373,   373,   374,   374,   375,   376,
     376,   376,   377,   377,   377,   377,   377,   378,   378,   379,
     379,   380,   381,   381,   382,   382,   382,   382,   382,   382,
     382,   382,   383,   384,   385,   386,   386,   387,   387,   388,
     388,   388,   388,   389,   389,   390,   390,   390,   391,   391,
     391,   392,   392,   392,   393,   394,   395,   396,   396,   397,
     397,   398,   399,   399,   400,   400,   401,   401,   402,   402,
     402,   402,   402,   402,   402,   403,   403,   404,   404,   405,
     406,   406,   407,   407,   408,   408,   409,   409,   410,   410,
     411,   411,   412,   413,   413,   414,   414,   415,   415,   415,
     415,   415,   416,   415,   415,   415,   415,   417,   417,   417,
     418,   418,   419,   419,   419,   420,   420,   420,   420,   420,
     421,   421,   421,   422,   422,   422,   423,   423,   424,   424,
     425,   425,   426,   426,   427,   427,   428,   428,   428,   428,
     429,   429,   429,   430,   430,   430,   430,   430,   430,   431,
     431,   431,   432,   432,   432,   432,   433,   433,   434,   434,
     435,   435,   436,   436,   436,   436,   437,   438,   438,   438,
     439,   439,   440,   440,   440,   440,   441,   441,   442,   442,
     442,   442,   442,   442,   442,   443,   443,   444,   444,   445,
     445,   445,   445,   445,   446,   446,   447,   447,   448,   448,
     448,   449,   449,   450,   450,   451,   452,   452,   452,   452,
     452,   452,   452,   452,   453,   453,   454,   454,   454,   455,
     456,   456,   457,   458,   459,   460,   460,   461,   461,   462,
     462,   463,   463,   463,   464,   464,   464,   464,   464,   464,
     465,   465,   466,   466,   467,   468,   468,   469,   469,   470,
     470,   471,   471,   471,   471,   472,   472,   473,   473,   473,
     473,   474,   474,   475,   475,   476,   476,   476,   476,   477,
     477,   477,   477,   478,   478,   479,   479,   480,   481,   481,
     481,   481,   481,   481,   482,   483,   483,   483,   483,   484,
     484,   484,   484,   485,   486,   487,   487,   487,   487,   488,
     488,   489,   490,   490,   490,   491,   491,   491,   492,   492,
     492,   493,   494,   494,   494,   494,   494,   494,   494,   494,
     494,   495,   496,   496,   496,   497,   498,   499,   499,   499,
     500,   500,   500,   500,   500,   501,   502,   502,   502,   502,
     502,   502,   502,   503,   504,   505,   506,   507,   507,   507,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     509,   509,   510,   510,   511,   512,   513,   513,   514,   515,
     516,   516,   517,   517,   517,   517,   518,   518,   519,   520,
     520,   521,   521,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   523,
     523,   524,   524,   524,   524,   525,   525,   525,   525,   526,
     526,   527,   527,   528,   528,   529,   529,   530,   530,   530,
     531,   531,   532,   532,   533,   533,   533,   533,   533,   534,
     535,   535,   535,   535,   535,   535,   535,   536,   536,   536,
     536,   537,   537,   537,   537,   538,   538,   539,   539,   539,
     539,   539,   539,   539,   540,   540,   541,   541,   541,   541,
     542,   542,   542,   542,   542,   543,   543,   544,   544,   545,
     545,   546,   546,   547,   548,   548,   549,   549,   549,   550,
     550,   550,   550,   550,   551,   551,   551,   551,   552,   553,
     554,   555,   555,   556,   556,   556,   557,   557,   558
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
       1,     1,     2,     2,     2,     3,     5,     4,     6,     1,
       1,     2,     1,     2,     1,     2,     7,     1,     3,     1,
       2,     2,     3,     3,     3,     2,     3,     4,     5,     2,
       4,     3,     0,     3,     2,     1,     3,     5,     3,     5,
       2,     2,     3,     3,     3,     2,     3,     3,     1,     2,
       2,     2,     4,     4,     4,     4,     1,     3,     2,     3,
       3,     3,     1,     1,     2,     1,     3,     1,     3,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     7,
       4,     1,     2,     3,     4,     1,     1,     2,     2,     1,
       3,     1,     3,     1,     4,     1,     2,     1,     2,     3,
       1,     2,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     3,     3,     5,
       7,     5,     7,     2,     1,     3,     2,     4,     4,     6,
       4,     5,     4,     5,     3,     1,     2,     2,     3,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       2,     1,     2,     1,     2,     3,     3,     4,     3,     3,
       3,     2,     2,     1,     1,     1,     1,     1,     3
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
  "\"'words'\"", "\"'thesaurus'\"", "\"'wildcards'\"", "\"'create'\"",
  "\"'build'\"", "\"'drop'\"", "\"'unique'\"", "\"'index'\"", "\"'hash'\"",
  "\"'btree'\"", "\"'on'\"", "\"'BOM_UTF8'\"", "FTCONTAINS_REDUCE",
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
  "VarNameAndType", "VarDecl", "IndexingMethod", "IndexDecl", "IndexDecl2",
  "IndexDecl3", "IndexDeclSuffix", "IndexField", "IndexField1",
  "IndexFieldList", "ConstructionDecl", "FunctionSig", "BlockExpr",
  "Block", "BlockDecls", "BlockVarDeclList", "BlockVarDecl", "AssignExpr",
  "ExitExpr", "WhileExpr", "FlowCtlStatement", "IndexStatement",
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
       299,     0,    -1,   300,    -1,   283,   300,    -1,   302,    -1,
     301,   302,    -1,   303,    -1,   301,   303,    -1,   203,   204,
      20,   179,    -1,   203,   204,    20,   121,    20,   179,    -1,
     305,   364,    -1,   364,    -1,   304,    -1,   304,   305,    -1,
      26,   149,   520,   122,   519,   179,    -1,   306,   179,    -1,
     307,   179,    -1,   306,   179,   307,   179,    -1,   308,    -1,
     306,   179,   308,    -1,   309,    -1,   307,   179,   309,    -1,
     314,    -1,   315,    -1,   316,    -1,   318,    -1,   335,    -1,
     330,    -1,   356,    -1,   319,    -1,   320,    -1,   337,    -1,
     310,    -1,    25,   105,    71,   311,    -1,    25,    71,   521,
     311,    -1,   312,    -1,   311,   312,    -1,   313,   122,   506,
      -1,    72,    -1,    73,    -1,    74,    -1,    75,    -1,    76,
      -1,    77,    -1,    78,    -1,    79,    -1,    80,    -1,    81,
      -1,   317,    -1,   324,    -1,   325,    -1,   344,    -1,   321,
      -1,   322,    -1,   323,    -1,   507,    -1,   326,    -1,   329,
      -1,    25,   149,   520,   122,   519,    -1,    25,    70,   170,
      -1,    25,    70,   184,    -1,    25,   105,    30,   149,   519,
      -1,    25,   105,    34,   149,   519,    -1,    25,    46,   521,
      20,    -1,    25,   240,   535,    -1,    25,    63,   157,    -1,
      25,    63,   190,    -1,    25,   105,   158,   117,   118,    -1,
      25,   105,   158,   117,   119,    -1,    25,    67,   170,    99,
     137,    -1,    25,    67,   170,    99,   154,    -1,    25,    67,
     155,    99,   137,    -1,    25,    67,   155,    99,   154,    -1,
      25,   105,    98,   519,    -1,    25,    64,   519,    -1,    41,
      48,   519,    -1,    41,    48,   328,   519,    -1,    41,    48,
     519,    88,   327,    -1,    41,    48,   328,   519,    88,   327,
      -1,   519,    -1,   327,    99,   519,    -1,   149,   520,   122,
      -1,   105,    30,   149,    -1,    41,    26,   519,    -1,    41,
      26,   149,   520,   122,   519,    -1,    41,    26,   519,    88,
     327,    -1,    41,    26,   149,   520,   122,   519,    88,   327,
      -1,    25,   103,   141,   331,    -1,    86,   492,   332,    -1,
     332,    -1,   333,    -1,   127,    -1,   127,   333,    -1,   132,
     368,    -1,   110,   521,    -1,   110,   521,   489,    -1,    25,
     104,   334,   132,   368,    -1,    25,   104,   334,   127,    -1,
      25,   104,   334,   127,   132,   368,    -1,   280,    -1,   281,
      -1,    25,   338,    -1,   339,    -1,   278,   339,    -1,   340,
      -1,   336,   340,    -1,   279,   519,   282,   368,   159,   343,
     175,    -1,   342,    -1,   342,    98,   519,    -1,   368,    -1,
     368,   489,    -1,   145,   341,    -1,   343,    99,   341,    -1,
      25,    52,   170,    -1,    25,    52,   184,    -1,   145,   175,
      -1,   145,   360,   175,    -1,   145,   175,    86,   490,    -1,
     145,   360,   175,    86,   490,    -1,   228,   347,    -1,   142,
     348,   365,   172,    -1,   348,   349,   179,    -1,    -1,   349,
      99,   350,    -1,    25,   350,    -1,   334,    -1,   334,   132,
     368,    -1,    50,   110,   521,   132,   368,    -1,   229,   227,
     368,    -1,   233,   145,   368,   175,   347,    -1,   230,   231,
      -1,   232,   231,    -1,   275,   279,   519,    -1,   277,   279,
     519,    -1,   276,   279,   519,    -1,    25,   357,    -1,    25,
      38,   357,    -1,    25,    37,   357,    -1,   358,    -1,    39,
     358,    -1,    35,   358,    -1,    36,   359,    -1,    34,   521,
     345,   363,    -1,    34,   521,   345,   127,    -1,    34,   521,
     345,   347,    -1,    34,   521,   345,   127,    -1,   361,    -1,
     360,    99,   361,    -1,   110,   521,    -1,   110,   521,   489,
      -1,   142,   365,   172,    -1,   142,   365,   172,    -1,   365,
      -1,   367,    -1,   367,   366,    -1,   179,    -1,   366,   367,
     179,    -1,   368,    -1,   367,    99,   368,    -1,   369,    -1,
     406,    -1,   409,    -1,   412,    -1,   413,    -1,   508,    -1,
     509,    -1,   511,    -1,   510,    -1,   512,    -1,   515,    -1,
     523,    -1,   352,    -1,   353,    -1,   354,    -1,   351,    -1,
     346,    -1,   355,    -1,   378,   370,    -1,   174,   368,    -1,
      56,   268,    -1,    57,   268,    -1,   206,    -1,   246,    -1,
      60,   246,    -1,   372,   390,    61,   368,    -1,   372,    61,
     368,    -1,    54,   371,   389,   373,   373,    -1,    54,   371,
     389,   373,    -1,    62,   110,   521,    -1,   380,    -1,   385,
      -1,   374,    -1,   376,    -1,   394,    -1,   399,    -1,   395,
      -1,   375,    -1,   376,    -1,   378,   377,    -1,    54,   110,
      -1,    55,    54,   110,    -1,   379,   381,    -1,   382,    -1,
     381,    99,   110,   382,    -1,   521,   136,   368,    -1,   521,
     489,   136,   368,    -1,   521,   383,   136,   368,    -1,   521,
     489,   383,   136,   368,    -1,   521,   384,   136,   368,    -1,
     521,   489,   384,   136,   368,    -1,   521,   383,   384,   136,
     368,    -1,   521,   489,   383,   384,   136,   368,    -1,    88,
     110,   521,    -1,   262,   110,   521,    -1,    51,   110,   386,
      -1,   388,    -1,   386,    99,   110,   388,    -1,   393,    -1,
     387,    99,   110,   393,    -1,   521,   132,   368,    -1,   521,
     489,   132,   368,    -1,   521,   384,   132,   368,    -1,   521,
     489,   384,   132,   368,    -1,   110,   521,   136,   368,    -1,
     110,   521,   489,   136,   368,    -1,   391,    -1,   110,   521,
      -1,   110,   521,   391,    -1,   383,    -1,   383,   392,    -1,
     392,    -1,    58,   110,   521,    59,   110,   521,    -1,    59,
     110,   521,    -1,    58,   110,   521,    -1,   521,    -1,   200,
     368,    -1,   160,   159,   396,    -1,   397,    -1,   396,    99,
     397,    -1,   110,   521,    -1,   110,   521,   398,    -1,    98,
     519,    -1,   158,   159,   400,    -1,    45,   158,   159,   400,
      -1,   401,    -1,   400,    99,   401,    -1,   368,    -1,   368,
     402,    -1,   403,    -1,   404,    -1,   405,    -1,   403,   404,
      -1,   403,   405,    -1,   404,   405,    -1,   403,   404,   405,
      -1,    87,    -1,   108,    -1,   117,   118,    -1,   117,   119,
      -1,    98,   519,    -1,    44,   110,   407,   176,   368,    -1,
     125,   110,   407,   176,   368,    -1,   408,    -1,   407,    99,
     110,   408,    -1,   521,   136,   368,    -1,   521,   489,   136,
     368,    -1,    29,   145,   365,   175,   410,   105,   174,   368,
      -1,    29,   145,   365,   175,   410,   105,   110,   521,   174,
     368,    -1,   411,    -1,   410,   411,    -1,    92,   490,   174,
     368,    -1,    92,   110,   521,    86,   490,   174,   368,    -1,
      40,   145,   365,   175,   186,   368,   116,   368,    -1,   414,
      -1,   413,   156,   414,    -1,   415,    -1,   414,    84,   415,
      -1,   417,    -1,   417,   430,   417,    -1,   417,   431,   417,
      -1,   417,   122,   417,    -1,   417,   151,   417,    -1,    -1,
     417,   146,   416,   417,    -1,   417,   144,   417,    -1,   417,
     133,   417,    -1,   417,   131,   417,    -1,   418,    -1,   418,
     251,   524,    -1,   418,   251,   524,   558,    -1,   419,    -1,
     419,   187,   419,    -1,   420,    -1,   419,   164,   420,    -1,
     419,   147,   420,    -1,   421,    -1,   420,   182,   421,    -1,
     420,   109,   421,    -1,   420,   135,   421,    -1,   420,   148,
     421,    -1,   422,    -1,   421,   189,   422,    -1,   421,   198,
     422,    -1,   423,    -1,   422,   139,   423,    -1,   422,   126,
     423,    -1,   424,    -1,   424,    68,   220,   490,    -1,   425,
      -1,   425,   188,    86,   490,    -1,   426,    -1,   426,    93,
      86,   488,    -1,   427,    -1,   427,    94,    86,   488,    -1,
     429,    -1,   428,   429,    -1,   164,    -1,   147,    -1,   428,
     164,    -1,   428,   147,    -1,   432,    -1,   436,    -1,   433,
      -1,   191,    -1,   196,    -1,   195,    -1,   194,    -1,   193,
      -1,   192,    -1,   140,    -1,   167,    -1,   130,    -1,    28,
     142,   365,   172,    -1,    28,   211,   142,   365,   172,    -1,
      28,   210,   142,   365,   172,    -1,    28,    86,   504,   142,
     365,   172,    -1,   434,   142,   172,    -1,   434,   142,   365,
     172,    -1,   435,    -1,   434,   435,    -1,   165,   521,    15,
      -1,   165,    16,    -1,   437,    -1,   437,   438,    -1,   181,
     438,    -1,   438,    -1,   180,    -1,   439,    -1,   439,   180,
     438,    -1,   439,   181,   438,    -1,   440,    -1,   449,    -1,
     441,    -1,   441,   450,    -1,   444,    -1,   444,   450,    -1,
     442,   446,    -1,   443,    -1,    97,    -1,   106,    -1,    90,
      -1,   178,    -1,   107,    -1,   129,    -1,   128,    -1,   446,
      -1,    91,   446,    -1,   445,   446,    -1,   112,    -1,   161,
      -1,    82,    -1,   169,    -1,   168,    -1,    83,    -1,   494,
      -1,   447,    -1,   521,    -1,   448,    -1,   182,    -1,    10,
      -1,    17,    -1,   452,    -1,   452,   450,    -1,   451,    -1,
     450,   451,    -1,   143,   365,   173,    -1,   453,    -1,   455,
      -1,   456,    -1,   457,    -1,   460,    -1,   462,    -1,   458,
      -1,   459,    -1,   454,    -1,   506,    -1,   102,    -1,   138,
      -1,   114,    -1,   110,   521,    -1,   145,   175,    -1,   145,
     365,   175,    -1,   111,    -1,   157,   142,   365,   172,    -1,
     190,   142,   365,   172,    -1,   521,   145,   175,    -1,   521,
     145,   461,   175,    -1,   368,    -1,   461,    99,   368,    -1,
     463,    -1,   481,    -1,   464,    -1,   478,    -1,   479,    -1,
     146,   521,   468,   120,    -1,   146,   521,   466,   468,   120,
      -1,   146,   521,   468,   185,   183,   521,   468,   185,    -1,
     146,   521,   468,   185,   465,   183,   521,   468,   185,    -1,
     146,   521,   466,   468,   185,   183,   521,   468,   185,    -1,
     146,   521,   466,   468,   185,   465,   183,   521,   468,   185,
      -1,   476,    -1,   465,   476,    -1,   467,    -1,   466,   467,
      -1,    27,   521,   468,   122,   468,   469,    -1,    -1,    27,
      -1,   171,   470,   171,    -1,    85,   472,    85,    -1,    -1,
     471,    -1,   124,    -1,   474,    -1,   471,   124,    -1,   471,
     474,    -1,    -1,   473,    -1,   123,    -1,   475,    -1,   473,
     123,    -1,   473,   475,    -1,    19,    -1,   477,    -1,     4,
      -1,   477,    -1,   463,    -1,     9,    -1,   480,    -1,   477,
      -1,     8,    -1,   113,    -1,   115,    -1,   362,    -1,   201,
      21,   202,    -1,   201,   202,    -1,   162,   520,   163,    -1,
     162,   520,     7,    -1,    95,     6,    -1,   482,    -1,   483,
      -1,   484,    -1,   485,    -1,   486,    -1,   487,    -1,    31,
     142,   365,   172,    -1,    30,   521,   142,   172,    -1,    30,
     521,   142,   365,   172,    -1,    30,   142,   365,   172,   142,
     172,    -1,    30,   142,   365,   172,   142,   365,   172,    -1,
      89,   521,   142,   172,    -1,    89,   521,   142,   365,   172,
      -1,    89,   142,   365,   172,   142,   172,    -1,    89,   142,
     365,   172,   142,   365,   172,    -1,    32,   142,   365,   172,
      -1,    33,   142,   365,   172,    -1,    42,   520,   142,   172,
      -1,    42,   520,   142,   365,   172,    -1,    42,   142,   365,
     172,   142,   172,    -1,    42,   142,   365,   172,   142,   365,
     172,    -1,   493,    -1,   493,   134,    -1,    86,   490,    -1,
     492,    -1,   492,   491,    -1,   199,   145,   175,    -1,   134,
      -1,   182,    -1,   164,    -1,   493,    -1,   494,    -1,   141,
     145,   175,    -1,   521,    -1,   496,    -1,   502,    -1,   500,
      -1,   503,    -1,   501,    -1,   499,    -1,   498,    -1,   497,
      -1,   495,    -1,   214,   145,   175,    -1,    66,   145,   175,
      -1,    66,   145,   502,   175,    -1,    66,   145,   503,   175,
      -1,    32,   145,   175,    -1,    33,   145,   175,    -1,    42,
     145,   175,    -1,    42,   145,   520,   175,    -1,    42,   145,
      20,   175,    -1,    89,   145,   175,    -1,    89,   145,   521,
     175,    -1,    89,   145,   521,    99,   504,   175,    -1,    89,
     145,   182,   175,    -1,    89,   145,   182,    99,   504,   175,
      -1,   177,   521,   175,    -1,    30,   145,   175,    -1,    30,
     145,   521,   175,    -1,    30,   145,   521,    99,   504,   175,
      -1,    30,   145,   521,    99,   505,   175,    -1,    30,   145,
     182,   175,    -1,    30,   145,   182,    99,   504,   175,    -1,
      30,   145,   182,    99,   505,   175,    -1,    65,   145,   521,
     175,    -1,   521,    -1,   521,   134,    -1,    20,    -1,    25,
     209,   210,    -1,    25,   209,   211,    -1,    25,   209,   212,
      -1,   215,   214,   368,   222,   368,    -1,   215,   214,   368,
      86,   221,   222,   368,    -1,   215,   214,   368,    86,   223,
     222,   368,    -1,   215,   214,   368,   207,   368,    -1,   215,
     214,   368,   208,   368,    -1,   215,   216,   368,   222,   368,
      -1,   215,   216,   368,    86,   221,   222,   368,    -1,   215,
     216,   368,    86,   223,   222,   368,    -1,   215,   216,   368,
     207,   368,    -1,   215,   216,   368,   208,   368,    -1,   213,
     214,   368,    -1,   213,   216,   368,    -1,   218,   214,   368,
     226,   368,    -1,   218,   219,   220,   214,   368,   226,   368,
      -1,   217,   214,   368,    86,   368,    -1,   225,   110,   513,
     224,   368,   174,   368,    -1,   514,    -1,   513,    99,   110,
     514,    -1,   521,   132,   368,    -1,   234,   142,   368,   172,
     516,    -1,   517,    -1,   516,   517,    -1,   235,   518,   363,
      -1,   235,   518,   145,   110,   521,   175,   363,    -1,   235,
     518,   145,   110,   521,    99,   110,   521,   175,   363,    -1,
     235,   518,   145,   110,   521,    99,   110,   521,    99,   110,
     521,   175,   363,    -1,   447,    -1,   518,   198,   447,    -1,
      20,    -1,    14,    -1,   521,    -1,    18,    -1,   522,    -1,
     203,    -1,   117,    -1,    89,    -1,    33,    -1,    66,    -1,
      30,    -1,   141,    -1,    40,    -1,   214,    -1,    42,    -1,
      69,    -1,    65,    -1,    32,    -1,    29,    -1,   199,    -1,
      70,    -1,   240,    -1,    64,    -1,   211,    -1,   210,    -1,
     135,    -1,    31,    -1,   252,    -1,   239,    -1,   242,    -1,
     241,    -1,   269,    -1,   270,    -1,   273,    -1,   271,    -1,
     274,    -1,   245,    -1,   247,    -1,    47,    -1,   206,    -1,
     246,    -1,    43,    -1,   212,    -1,   225,    -1,   219,    -1,
     191,    -1,   196,    -1,   195,    -1,   194,    -1,   193,    -1,
     192,    -1,    88,    -1,   103,    -1,   104,    -1,   174,    -1,
      54,    -1,    55,    -1,    56,    -1,    57,    -1,    58,    -1,
      59,    -1,    60,    -1,    61,    -1,    62,    -1,   136,    -1,
      51,    -1,   200,    -1,   159,    -1,   160,    -1,   158,    -1,
      45,    -1,    87,    -1,   108,    -1,   118,    -1,   119,    -1,
      98,    -1,    44,    -1,   125,    -1,   176,    -1,    92,    -1,
      86,    -1,   186,    -1,   116,    -1,   156,    -1,    84,    -1,
      68,    -1,   220,    -1,    93,    -1,   187,    -1,   109,    -1,
     148,    -1,   189,    -1,   139,    -1,   126,    -1,    28,    -1,
      94,    -1,   188,    -1,   140,    -1,   170,    -1,   184,    -1,
     149,    -1,   127,    -1,   121,    -1,   155,    -1,   137,    -1,
     154,    -1,    25,    -1,    52,    -1,    63,    -1,   105,    -1,
      67,    -1,    46,    -1,   204,    -1,    41,    -1,    48,    -1,
      26,    -1,    34,    -1,   262,    -1,   251,    -1,   267,    -1,
     268,    -1,   244,    -1,   257,    -1,   265,    -1,   261,    -1,
     243,    -1,   256,    -1,   266,    -1,   260,    -1,   255,    -1,
     254,    -1,   238,    -1,   237,    -1,   259,    -1,   248,    -1,
     249,    -1,   272,    -1,   264,    -1,   263,    -1,   258,    -1,
     218,    -1,   224,    -1,   221,    -1,   215,    -1,   208,    -1,
     207,    -1,   209,    -1,   226,    -1,   216,    -1,   217,    -1,
     223,    -1,   213,    -1,   222,    -1,    39,    -1,    36,    -1,
      35,    -1,    37,    -1,    38,    -1,   157,    -1,   190,    -1,
     227,    -1,   228,    -1,   229,    -1,   231,    -1,   233,    -1,
     230,    -1,   232,    -1,   234,    -1,   235,    -1,    53,    -1,
     236,    -1,    50,    -1,   279,    -1,   275,    -1,   276,    -1,
     278,    -1,   282,    -1,   280,    -1,   281,    -1,   277,    -1,
      71,    -1,    72,    -1,    73,    -1,    74,    -1,    75,    -1,
      76,    -1,    77,    -1,    78,    -1,    79,    -1,    80,    -1,
      81,    -1,   236,   110,   387,    53,   142,   368,   172,    -1,
      53,   142,   368,   172,    -1,   526,    -1,   526,   525,    -1,
     526,   267,   418,    -1,   526,   525,   267,   418,    -1,   535,
      -1,   533,    -1,   525,   535,    -1,   525,   533,    -1,   527,
      -1,   526,   253,   527,    -1,   528,    -1,   527,   250,   528,
      -1,   529,    -1,   528,   252,   136,   529,    -1,   530,    -1,
     252,   530,    -1,   531,    -1,   531,   554,    -1,   145,   524,
     175,    -1,   532,    -1,   532,   550,    -1,   453,    -1,   142,
     365,   172,    -1,   534,    -1,   553,    -1,   552,    -1,   555,
      -1,   549,    -1,   157,    -1,   536,    -1,   537,    -1,   538,
      -1,   539,    -1,   542,    -1,   547,    -1,   548,    -1,   256,
      -1,   266,    -1,    92,   239,    -1,    92,   242,    -1,   226,
     241,    -1,   269,   241,    -1,   241,   239,    -1,   241,   242,
      -1,   226,   270,    -1,   269,   270,    -1,   226,   273,   541,
      -1,   226,   273,   105,    -1,   226,   273,   145,   541,   175,
      -1,   226,   273,   145,   541,    99,   540,   175,    -1,   226,
     273,   145,   105,   175,    -1,   226,   273,   145,   105,    99,
     540,   175,    -1,   269,   273,    -1,   541,    -1,   540,    99,
     541,    -1,    88,    20,    -1,    88,    20,   260,    20,    -1,
      88,    20,   551,   255,    -1,    88,    20,   260,    20,   551,
     255,    -1,   226,   271,   272,   544,    -1,   226,   271,   272,
     544,   543,    -1,   226,   105,   271,   272,    -1,   226,   105,
     271,   272,   543,    -1,   269,   271,   272,    -1,   546,    -1,
     543,   546,    -1,    88,    20,    -1,   145,   545,   175,    -1,
      20,    -1,   545,    20,    -1,   189,   544,    -1,   126,   544,
      -1,   254,    20,    -1,   226,   274,    -1,   269,   274,    -1,
      88,   206,    -1,    88,   246,    -1,   245,   247,    -1,   238,
      -1,   238,    47,    -1,   237,    -1,   237,   272,    -1,   259,
      -1,   248,   421,    -1,    88,   119,   421,    -1,    88,    43,
     421,    -1,   249,   421,   187,   421,    -1,   244,   551,   556,
      -1,   268,   421,   556,    -1,   257,   551,   265,    -1,   261,
     557,    -1,   243,   557,    -1,   272,    -1,   264,    -1,   258,
      -1,   263,    -1,   258,    -1,   269,   247,   421,    -1
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
     349,   351,   354,   356,   359,   361,   364,   372,   374,   378,
     380,   383,   386,   390,   394,   398,   401,   405,   410,   416,
     419,   424,   428,   429,   433,   436,   438,   442,   448,   452,
     458,   461,   464,   468,   472,   476,   479,   483,   487,   489,
     492,   495,   498,   503,   508,   513,   518,   520,   524,   527,
     531,   535,   539,   541,   543,   546,   548,   552,   554,   558,
     560,   562,   564,   566,   568,   570,   572,   574,   576,   578,
     580,   582,   584,   586,   588,   590,   592,   594,   597,   600,
     603,   606,   608,   610,   613,   618,   622,   628,   633,   637,
     639,   641,   643,   645,   647,   649,   651,   653,   655,   658,
     661,   665,   668,   670,   675,   679,   684,   689,   695,   700,
     706,   712,   719,   723,   727,   731,   733,   738,   740,   745,
     749,   754,   759,   765,   770,   776,   778,   781,   785,   787,
     790,   792,   799,   803,   807,   809,   812,   816,   818,   822,
     825,   829,   832,   836,   841,   843,   847,   849,   852,   854,
     856,   858,   861,   864,   867,   871,   873,   875,   878,   881,
     884,   890,   896,   898,   903,   907,   912,   921,   932,   934,
     937,   942,   950,   959,   961,   965,   967,   971,   973,   977,
     981,   985,   989,   990,   995,   999,  1003,  1007,  1009,  1013,
    1018,  1020,  1024,  1026,  1030,  1034,  1036,  1040,  1044,  1048,
    1052,  1054,  1058,  1062,  1064,  1068,  1072,  1074,  1079,  1081,
    1086,  1088,  1093,  1095,  1100,  1102,  1105,  1107,  1109,  1112,
    1115,  1117,  1119,  1121,  1123,  1125,  1127,  1129,  1131,  1133,
    1135,  1137,  1139,  1144,  1150,  1156,  1163,  1167,  1172,  1174,
    1177,  1181,  1184,  1186,  1189,  1192,  1194,  1196,  1198,  1202,
    1206,  1208,  1210,  1212,  1215,  1217,  1220,  1223,  1225,  1227,
    1229,  1231,  1233,  1235,  1237,  1239,  1241,  1244,  1247,  1249,
    1251,  1253,  1255,  1257,  1259,  1261,  1263,  1265,  1267,  1269,
    1271,  1273,  1275,  1278,  1280,  1283,  1287,  1289,  1291,  1293,
    1295,  1297,  1299,  1301,  1303,  1305,  1307,  1309,  1311,  1313,
    1316,  1319,  1323,  1325,  1330,  1335,  1339,  1344,  1346,  1350,
    1352,  1354,  1356,  1358,  1360,  1365,  1371,  1380,  1390,  1400,
    1411,  1413,  1416,  1418,  1421,  1428,  1429,  1431,  1435,  1439,
    1440,  1442,  1444,  1446,  1449,  1452,  1453,  1455,  1457,  1459,
    1462,  1465,  1467,  1469,  1471,  1473,  1475,  1477,  1479,  1481,
    1483,  1485,  1487,  1489,  1493,  1496,  1500,  1504,  1507,  1509,
    1511,  1513,  1515,  1517,  1519,  1524,  1529,  1535,  1542,  1550,
    1555,  1561,  1568,  1576,  1581,  1586,  1591,  1597,  1604,  1612,
    1614,  1617,  1620,  1622,  1625,  1629,  1631,  1633,  1635,  1637,
    1639,  1643,  1645,  1647,  1649,  1651,  1653,  1655,  1657,  1659,
    1661,  1663,  1667,  1671,  1676,  1681,  1685,  1689,  1693,  1698,
    1703,  1707,  1712,  1719,  1724,  1731,  1735,  1739,  1744,  1751,
    1758,  1763,  1770,  1777,  1782,  1784,  1787,  1789,  1793,  1797,
    1801,  1807,  1815,  1823,  1829,  1835,  1841,  1849,  1857,  1863,
    1869,  1873,  1877,  1883,  1891,  1897,  1905,  1907,  1912,  1916,
    1922,  1924,  1927,  1931,  1939,  1950,  1964,  1966,  1970,  1972,
    1974,  1976,  1978,  1980,  1982,  1984,  1986,  1988,  1990,  1992,
    1994,  1996,  1998,  2000,  2002,  2004,  2006,  2008,  2010,  2012,
    2014,  2016,  2018,  2020,  2022,  2024,  2026,  2028,  2030,  2032,
    2034,  2036,  2038,  2040,  2042,  2044,  2046,  2048,  2050,  2052,
    2054,  2056,  2058,  2060,  2062,  2064,  2066,  2068,  2070,  2072,
    2074,  2076,  2078,  2080,  2082,  2084,  2086,  2088,  2090,  2092,
    2094,  2096,  2098,  2100,  2102,  2104,  2106,  2108,  2110,  2112,
    2114,  2116,  2118,  2120,  2122,  2124,  2126,  2128,  2130,  2132,
    2134,  2136,  2138,  2140,  2142,  2144,  2146,  2148,  2150,  2152,
    2154,  2156,  2158,  2160,  2162,  2164,  2166,  2168,  2170,  2172,
    2174,  2176,  2178,  2180,  2182,  2184,  2186,  2188,  2190,  2192,
    2194,  2196,  2198,  2200,  2202,  2204,  2206,  2208,  2210,  2212,
    2214,  2216,  2218,  2220,  2222,  2224,  2226,  2228,  2230,  2232,
    2234,  2236,  2238,  2240,  2242,  2244,  2246,  2248,  2250,  2252,
    2254,  2256,  2258,  2260,  2262,  2264,  2266,  2268,  2270,  2272,
    2274,  2276,  2278,  2280,  2282,  2284,  2286,  2288,  2290,  2292,
    2294,  2296,  2298,  2300,  2302,  2304,  2306,  2308,  2310,  2312,
    2314,  2316,  2318,  2320,  2322,  2324,  2326,  2328,  2330,  2332,
    2334,  2336,  2338,  2340,  2342,  2344,  2346,  2348,  2350,  2352,
    2360,  2365,  2367,  2370,  2374,  2379,  2381,  2383,  2386,  2389,
    2391,  2395,  2397,  2401,  2403,  2408,  2410,  2413,  2415,  2418,
    2422,  2424,  2427,  2429,  2433,  2435,  2437,  2439,  2441,  2443,
    2445,  2447,  2449,  2451,  2453,  2455,  2457,  2459,  2461,  2463,
    2466,  2469,  2472,  2475,  2478,  2481,  2484,  2487,  2491,  2495,
    2501,  2509,  2515,  2523,  2526,  2528,  2532,  2535,  2540,  2545,
    2552,  2557,  2563,  2568,  2574,  2578,  2580,  2583,  2586,  2590,
    2592,  2595,  2598,  2601,  2604,  2607,  2610,  2613,  2616,  2619,
    2621,  2624,  2626,  2629,  2631,  2634,  2638,  2642,  2647,  2651,
    2655,  2659,  2662,  2665,  2667,  2669,  2671,  2673,  2675
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   893,   893,   894,   904,   909,   915,   920,   932,   937,
     947,   954,   966,   972,   984,   997,  1003,  1009,  1021,  1027,
    1041,  1047,  1061,  1062,  1063,  1064,  1070,  1071,  1072,  1073,
    1076,  1079,  1081,  1087,  1092,  1101,  1107,  1116,  1125,  1126,
    1127,  1128,  1129,  1130,  1131,  1132,  1133,  1134,  1141,  1142,
    1143,  1144,  1145,  1146,  1147,  1150,  1157,  1158,  1170,  1182,
    1187,  1198,  1204,  1216,  1229,  1240,  1245,  1257,  1262,  1273,
    1279,  1285,  1291,  1310,  1321,  1332,  1339,  1346,  1353,  1366,
    1372,  1387,  1391,  1401,  1408,  1416,  1423,  1436,  1443,  1449,
    1456,  1462,  1466,  1473,  1484,  1489,  1498,  1507,  1514,  1524,
    1526,  1533,  1541,  1545,  1553,  1557,  1565,  1573,  1577,  1585,
    1589,  1596,  1603,  1613,  1618,  1630,  1634,  1638,  1642,  1649,
    1656,  1675,  1685,  1691,  1697,  1706,  1716,  1729,  1737,  1744,
    1756,  1760,  1767,  1771,  1775,  1782,  1787,  1794,  1802,  1806,
    1810,  1818,  1825,  1834,  1846,  1855,  1868,  1876,  1890,  1897,
    1910,  1918,  1929,  1940,  1944,  1956,  1960,  1969,  1973,  1989,
    1990,  1991,  1992,  1993,  1996,  1997,  1998,  1999,  2000,  2002,
    2003,  2006,  2007,  2008,  2009,  2010,  2013,  2020,  2029,  2036,
    2040,  2048,  2052,  2056,  2063,  2067,  2074,  2082,  2093,  2103,
    2104,  2105,  2109,  2109,  2109,  2109,  2109,  2112,  2118,  2127,
    2131,  2141,  2152,  2158,  2172,  2180,  2189,  2199,  2210,  2219,
    2229,  2239,  2255,  2268,  2280,  2292,  2298,  2310,  2316,  2330,
    2339,  2349,  2358,  2371,  2378,  2389,  2390,  2395,  2404,  2408,
    2413,  2417,  2423,  2428,  2436,  2452,  2460,  2467,  2473,  2484,
    2491,  2501,  2511,  2516,  2528,  2534,  2548,  2554,  2566,  2573,
    2580,  2587,  2594,  2601,  2608,  2621,  2625,  2635,  2640,  2651,
    2662,  2669,  2682,  2689,  2701,  2708,  2722,  2729,  2744,  2750,
    2762,  2768,  2782,  2793,  2797,  2808,  2812,  2831,  2835,  2843,
    2851,  2859,  2867,  2867,  2875,  2883,  2891,  2905,  2909,  2916,
    2929,  2933,  2944,  2948,  2952,  2962,  2966,  2970,  2974,  2978,
    2988,  2992,  2997,  3008,  3012,  3016,  3026,  3030,  3042,  3046,
    3058,  3062,  3074,  3078,  3090,  3094,  3106,  3110,  3114,  3118,
    3130,  3134,  3138,  3148,  3152,  3156,  3160,  3164,  3168,  3178,
    3182,  3186,  3196,  3200,  3204,  3208,  3220,  3226,  3238,  3244,
    3258,  3265,  3306,  3310,  3314,  3318,  3330,  3340,  3351,  3356,
    3366,  3370,  3380,  3386,  3392,  3398,  3410,  3416,  3427,  3431,
    3435,  3439,  3443,  3447,  3451,  3461,  3465,  3475,  3479,  3490,
    3494,  3498,  3502,  3506,  3521,  3525,  3535,  3539,  3549,  3556,
    3563,  3576,  3580,  3592,  3598,  3612,  3623,  3627,  3631,  3635,
    3639,  3643,  3647,  3651,  3661,  3665,  3675,  3680,  3685,  3696,
    3707,  3711,  3722,  3732,  3743,  3799,  3805,  3817,  3823,  3835,
    3839,  3849,  3853,  3857,  3867,  3875,  3883,  3891,  3899,  3907,
    3922,  3928,  3940,  3946,  3959,  3968,  3970,  3976,  3981,  3993,
    3996,  4003,  4009,  4015,  4023,  4038,  4041,  4048,  4054,  4060,
    4068,  4082,  4087,  4098,  4103,  4114,  4119,  4124,  4130,  4142,
    4148,  4153,  4158,  4169,  4174,  4189,  4194,  4211,  4226,  4230,
    4234,  4238,  4242,  4246,  4256,  4267,  4273,  4279,  4284,  4306,
    4312,  4318,  4323,  4334,  4344,  4354,  4360,  4366,  4371,  4382,
    4388,  4400,  4411,  4417,  4423,  4460,  4465,  4470,  4481,  4485,
    4489,  4499,  4510,  4514,  4518,  4522,  4526,  4530,  4534,  4538,
    4542,  4552,  4562,  4566,  4571,  4582,  4592,  4602,  4606,  4610,
    4620,  4626,  4632,  4638,  4644,  4656,  4667,  4674,  4681,  4688,
    4695,  4702,  4709,  4722,  4743,  4750,  4770,  4810,  4814,  4818,
    4827,  4833,  4839,  4845,  4851,  4858,  4864,  4870,  4876,  4882,
    4894,  4899,  4909,  4915,  4927,  4953,  4964,  4970,  4983,  4998,
    5005,  5011,  5022,  5029,  5039,  5050,  5066,  5072,  5082,  5091,
    5092,  5110,  5114,  5121,  5122,  5123,  5124,  5125,  5126,  5127,
    5128,  5129,  5130,  5131,  5132,  5133,  5134,  5135,  5136,  5137,
    5138,  5139,  5140,  5141,  5142,  5143,  5144,  5145,  5146,  5147,
    5148,  5149,  5150,  5151,  5152,  5153,  5154,  5155,  5156,  5157,
    5158,  5159,  5160,  5161,  5162,  5163,  5164,  5165,  5166,  5167,
    5168,  5169,  5170,  5171,  5172,  5173,  5174,  5175,  5176,  5177,
    5178,  5179,  5180,  5181,  5182,  5183,  5184,  5185,  5186,  5187,
    5188,  5189,  5190,  5191,  5192,  5193,  5194,  5195,  5196,  5197,
    5198,  5199,  5200,  5201,  5202,  5203,  5204,  5205,  5206,  5207,
    5208,  5209,  5210,  5211,  5212,  5213,  5214,  5215,  5216,  5217,
    5218,  5219,  5220,  5221,  5222,  5223,  5224,  5225,  5226,  5227,
    5228,  5229,  5230,  5231,  5232,  5233,  5234,  5235,  5236,  5237,
    5238,  5239,  5240,  5241,  5242,  5243,  5244,  5245,  5246,  5247,
    5248,  5249,  5250,  5251,  5252,  5253,  5254,  5255,  5256,  5257,
    5258,  5259,  5260,  5261,  5262,  5263,  5264,  5265,  5266,  5267,
    5268,  5269,  5270,  5271,  5272,  5273,  5274,  5275,  5276,  5277,
    5278,  5279,  5280,  5281,  5282,  5283,  5284,  5285,  5286,  5287,
    5288,  5289,  5290,  5291,  5292,  5293,  5294,  5295,  5296,  5297,
    5298,  5299,  5300,  5301,  5302,  5303,  5304,  5305,  5306,  5317,
    5323,  5340,  5344,  5348,  5352,  5362,  5365,  5368,  5371,  5380,
    5383,  5392,  5395,  5404,  5407,  5416,  5419,  5428,  5431,  5434,
    5443,  5446,  5455,  5459,  5469,  5472,  5475,  5478,  5481,  5490,
    5499,  5503,  5507,  5511,  5515,  5519,  5523,  5533,  5536,  5539,
    5542,  5551,  5554,  5557,  5560,  5569,  5572,  5581,  5584,  5587,
    5590,  5593,  5596,  5599,  5608,  5611,  5620,  5623,  5626,  5629,
    5638,  5641,  5644,  5647,  5650,  5659,  5662,  5671,  5674,  5683,
    5686,  5695,  5698,  5707,  5716,  5719,  5728,  5731,  5734,  5743,
    5746,  5749,  5752,  5755,  5764,  5768,  5772,  5776,  5786,  5795,
    5805,  5814,  5817,  5826,  5829,  5832,  5841,  5844,  5853
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
     295,   296,   297
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 9772;
  const int xquery_parser::yynnts_ = 261;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 497;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 298;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 552;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 13451 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 5861 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"


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

