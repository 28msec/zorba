
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
#line 871 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"

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
        case 108: /* "\"'DECIMAL'\"" */

/* Line 480 of lalr1.cc  */
#line 755 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 268 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 120: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 754 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 277 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 144: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 753 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 286 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 300: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 295 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 301: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 304 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 302: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 313 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 303: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 322 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 304: /* "Prolog" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 331 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 305: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 340 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 306: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 349 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 307: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 358 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 308: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 367 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 309: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 376 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 310: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 767 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->pair_vector); };

/* Line 480 of lalr1.cc  */
#line 385 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 311: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 767 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->pair); };

/* Line 480 of lalr1.cc  */
#line 394 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 313: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 403 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 314: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 412 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 315: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 421 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 316: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 430 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 317: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 439 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 448 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 457 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 466 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 475 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 484 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 493 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 502 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 511 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 520 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 529 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 538 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 547 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 556 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 565 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 767 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 574 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 583 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 592 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "IndexDecl2" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 601 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "IndexDecl3" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 610 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "IndexDeclSuffix" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 619 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "IndexField" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 628 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "IndexField1" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 637 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "IndexFieldList" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 646 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 655 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 767 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 664 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 673 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "Block" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 682 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "BlockDecls" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 691 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "BlockVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 700 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "BlockVarDecl" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 709 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "AssignExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 718 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "ExitExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 727 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "WhileExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 736 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 745 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "IndexStatement" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 754 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 772 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "FunctionDecl3" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 781 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "FunctionDecl4" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 790 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 799 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 808 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "EnclosedExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 817 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 826 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 835 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 844 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "ApplyExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 853 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "ConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 862 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 871 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 880 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 889 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 898 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 907 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 916 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 925 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 934 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 943 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 952 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 961 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 970 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 979 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 988 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "EvalVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 997 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1006 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1015 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1024 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1033 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1042 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "EvalVarDecl" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1051 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1060 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1069 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1078 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1087 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1096 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1105 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1114 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1123 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1132 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1141 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1150 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1159 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1168 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1177 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1186 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1195 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1204 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1213 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1222 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1231 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1240 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1249 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1258 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1267 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1276 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1285 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1294 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1303 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1312 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1321 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1330 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1339 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1348 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1357 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1366 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1375 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1384 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1393 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1402 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "PragmaList" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1411 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1420 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1429 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1438 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1447 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1456 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1465 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1474 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1483 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1492 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1501 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1510 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1519 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1528 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1537 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1546 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1555 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1564 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1573 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1582 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1591 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1600 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1609 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1618 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1627 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1636 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1645 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1654 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1663 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1672 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1681 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1690 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1699 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1708 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "Opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1717 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1726 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "Opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1735 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1744 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1753 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1762 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1771 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1780 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1789 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1798 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1807 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1816 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1825 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1834 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1843 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1852 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1861 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1870 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1879 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1888 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1897 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1906 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1915 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1924 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1933 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1942 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1951 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1960 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1969 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1978 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1987 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1996 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2005 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2014 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2023 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 763 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2032 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2041 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2050 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2059 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2068 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2077 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2086 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2095 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2104 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2113 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2122 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2131 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 767 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2140 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2149 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "EvalExpr" */

/* Line 480 of lalr1.cc  */
#line 765 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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
#line 889 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 899 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		}
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 904 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<MainModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr ((yyval.node));
		}
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 910 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
       driver.set_expr ((yyval.node));
		}
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 915 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
       driver.set_expr ((yyval.node));
		}
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 927 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)), encoding);
		}
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 932 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 942 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)));
		}
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 949 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)),
                NULL);
		}
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 961 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC ((yyloc)),
                             static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)),
                             NULL);
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 967 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LibraryModule(LOC ((yyloc)),
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 979 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), 
								SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
		}
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 991 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)),
								NULL);
		}
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 997 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								NULL,
								static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		}
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1003 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
								static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1015 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = new SIND_DeclList(LOC ((yyloc)));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		}
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1021 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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
#line 1035 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = new VFO_DeclList(LOC ((yyloc)));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		}
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1041 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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
#line 1081 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].pair_vector));
      delete (yysemantic_stack_[(4) - (4)].pair_vector);
    }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 1086 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr))->get_qname(), (yysemantic_stack_[(4) - (4)].pair_vector)); 
      delete (yysemantic_stack_[(4) - (3)].expr);
      delete (yysemantic_stack_[(4) - (4)].pair_vector);
    }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 1095 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { 
      (yyval.pair_vector) = new std::vector<std::pair<std::string, std::string> > ();
      (yyval.pair_vector)->push_back(*(yysemantic_stack_[(1) - (1)].pair));
      delete (yysemantic_stack_[(1) - (1)].pair);
    }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 1101 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].pair_vector)->push_back(*(yysemantic_stack_[(2) - (2)].pair));
      delete (yysemantic_stack_[(2) - (2)].pair);
      (yyval.pair_vector) = (yysemantic_stack_[(2) - (1)].pair_vector);
    }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 1110 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *s = static_cast<StringLiteral *>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.pair) = new std::pair<std::string, std::string>((yysemantic_stack_[(3) - (1)].strval), s->get_strval());
      delete s;
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 1118 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1119 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1120 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1121 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1122 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1123 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1124 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1125 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1126 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1127 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 1164 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NamespaceDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 1176 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		}
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1181 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		}
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1192 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_element_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1198 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_function_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1210 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OptionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
								SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
		}
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1223 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (3)].node));
		}
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1234 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		}
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1239 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		}
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1251 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		}
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1256 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		}
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1267 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::inherit_ns);
		}
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1273 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::no_inherit_ns);
		}
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1279 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::inherit_ns);
		}
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1285 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::no_inherit_ns);
		}
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1304 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)));
		}
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1315 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		}
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1326 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		}
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1333 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)),
								NULL);
		}
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1340 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		}
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1347 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
		}
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 1360 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = new URILiteralList(LOC ((yyloc)));
			uri_list_p->push_back(SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		}
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 1366 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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
#line 1381 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1385 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		}
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1395 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		}
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1401 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
								SYMTAB ((yysemantic_stack_[(6) - (6)].sval)),
								NULL);
		}
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1408 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		}
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1414 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(8) - (4)].sval)),
								SYMTAB ((yysemantic_stack_[(8) - (6)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
		}
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1426 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1433 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->type = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1439 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1446 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(1) - (1)].node));
      d->ext = false;
      (yyval.node) = d;
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1452 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), NULL);
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1456 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1463 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1474 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(), NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1479 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
                               dynamic_cast<SequenceType *> ((yysemantic_stack_[(3) - (3)].node)));
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1488 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(5) - (3)].varnametype);
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								nt->name,
								nt->type,
								(yysemantic_stack_[(5) - (5)].expr));
      delete nt;
		}
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1497 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(4) - (3)].varnametype);
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       NULL, true);
      delete nt;
		}
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1504 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(6) - (3)].varnametype);
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       (yysemantic_stack_[(6) - (6)].expr), true);
      delete nt;
		}
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1514 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "hash"; }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1516 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "btree"; }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1523 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      IndexDecl *d = dynamic_cast<IndexDecl *> ((yysemantic_stack_[(2) - (2)].node));
      d->create = false;
      (yyval.node) = d;
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1531 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1535 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexDecl *> ((yysemantic_stack_[(2) - (2)].node))->uniq = true;
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1543 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1547 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexDecl *> ((yysemantic_stack_[(2) - (2)].node))->method = (yysemantic_stack_[(2) - (1)].strval);
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1555 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(7) - (2)].sval)), (yysemantic_stack_[(7) - (4)].expr), "",
                          dynamic_cast<IndexFieldList *> ((yysemantic_stack_[(7) - (6)].node)));
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1563 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 1567 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexField *> ((yysemantic_stack_[(3) - (1)].node))->coll = SYMTAB ((yysemantic_stack_[(3) - (3)].sval));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 1575 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexField (LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL);
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1579 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexField (LOC ((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<SequenceType *> ((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1586 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      IndexFieldList *l = new IndexFieldList (LOC ((yyloc)));
      l->fields.push_back (dynamic_cast<IndexField *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
      
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1593 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexFieldList *> ((yysemantic_stack_[(3) - (1)].node))->fields.push_back (dynamic_cast<IndexField *> ((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1603 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		}
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1608 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		}
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1620 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1624 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1628 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL, dynamic_cast<SequenceType *> ((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1632 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType *> ((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1639 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1646 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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
#line 1665 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (1)].node));
      VFO_DeclList *vfo2 = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (2)].node));
      if ((yysemantic_stack_[(3) - (1)].node) == NULL)
        vfo = new VFO_DeclList (LOC ((yyloc)));
      vfo->push_back (*vfo2);
      (yyval.node) = vfo;
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1674 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL;
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1681 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (1)].node));
      vfo->push_back ((yysemantic_stack_[(3) - (3)].node));
      (yyval.node) = vfo;
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1687 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = new VFO_DeclList (LOC ((yyloc)));
      vfo->push_back ((yysemantic_stack_[(2) - (2)].node));
      (yyval.node) = vfo;
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1696 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(1) - (1)].varnametype);
      VarDecl *vd = new VarDecl(LOC ((yyloc)),
                       nt->name,
                       nt->type,
                       NULL);
      vd->set_global (false);
			(yyval.node) = vd;
      delete nt;
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1707 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(3) - (1)].varnametype);
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
#line 1720 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr (LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr))->get_qname(), (yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (3)].expr);
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1728 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr (LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1735 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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
#line 1747 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1751 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::CONTINUE);
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1758 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IndexStatement (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), IndexStatement::create_stmt);
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1762 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IndexStatement (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), IndexStatement::drop_stmt);
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1766 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IndexStatement (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), IndexStatement::build_stmt);
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1773 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1777 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->deterministic = false;
      (yyval.node) = d;
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1783 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1790 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1794 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1798 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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
#line 1806 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1813 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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
#line 1822 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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
#line 1834 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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
#line 1848 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = new ParamList(LOC ((yyloc)));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)));
			}
			(yyval.node) = plist_p;
		}
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1856 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			ParamList* plist_p = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node));
			if (plist_p) {
				plist_p->push_back(dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1870 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(),
								NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
		}
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1877 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
      delete (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1890 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1898 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1909 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QueryBody(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
		}
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1920 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1924 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = dynamic_cast<BlockBody *> ((yysemantic_stack_[(2) - (2)].expr)),
        *blk2 = new BlockBody (LOC ((yyloc)));
      blk2->add ((yysemantic_stack_[(2) - (1)].expr));
      for (int i = 0; i < blk->size (); i++)
        blk2->add ((*blk) [i]);
      (yyval.expr) = blk2;
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1936 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody (LOC ((yyloc)));
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1940 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = dynamic_cast<BlockBody *> ((yysemantic_stack_[(3) - (1)].expr));
      blk->add ((yysemantic_stack_[(3) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1949 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 1953 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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

  case 176:

/* Line 678 of lalr1.cc  */
#line 2000 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      ReturnExpr* lReturnExpr = dynamic_cast<ReturnExpr*>((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = new FLWORExpr (LOC ((yyloc)), dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node)), lReturnExpr->get_return_val(), lReturnExpr->get_location(), driver.theCompilerCB->m_config.force_gflwor);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 2009 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 2016 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2020 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2028 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2032 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 2036 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_only_end;
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 2043 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), dynamic_cast<WindowVars *> ((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr), (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 2047 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr), (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 2054 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(5) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window,
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(5) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (4)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 2062 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window,
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 2073 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause (LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 2092 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = new FLWORClauseList (LOC ((yyloc)));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 2098 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = dynamic_cast<FLWORClauseList *> ((yysemantic_stack_[(2) - (1)].node));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 2107 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = NULL;
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 2111 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_ofor;
    }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 2121 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForClause(LOC ((yyloc)),
                         dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL);
		}
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2132 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		}
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 2138 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vardecl_list_p) {
				vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 2152 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (1)].expr);
		}
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 2160 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 2169 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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

  case 206:

/* Line 678 of lalr1.cc  */
#line 2179 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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

  case 207:

/* Line 678 of lalr1.cc  */
#line 2190 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 2199 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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

  case 209:

/* Line 678 of lalr1.cc  */
#line 2209 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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

  case 210:

/* Line 678 of lalr1.cc  */
#line 2219 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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

  case 211:

/* Line 678 of lalr1.cc  */
#line 2235 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
		}
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 2248 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
		}
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 2260 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)));
			
		}
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 2272 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		}
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 2278 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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
#line 2290 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		}
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 2296 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 2310 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
								NULL,
								NULL,
								(yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (1)].expr);
		}
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 2319 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 2329 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 2338 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (1)].expr);
		}
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 2351 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr))->get_qname(),
								NULL, (yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (2)].expr);
		}
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 2358 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (2)].expr);
		}
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 2370 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(), "", "");
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 2375 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_curr (static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 2384 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), dynamic_cast<PositionalVar *> ((yysemantic_stack_[(1) - (1)].node)), "", "", "");
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 2388 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_posvar (dynamic_cast<PositionalVar *> ((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 2397 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr))->get_qname(), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr))->get_qname());
      delete (yysemantic_stack_[(6) - (3)].expr);
      delete (yysemantic_stack_[(6) - (6)].expr);
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 2403 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", "", static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 2408 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname(), "");
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 2416 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      std::string name = static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr))->get_qname();
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           name, NULL, NULL,
                           new VarRef (LOC ((yyloc)), name),
                           VarGetsDecl::eval_var);
      delete (yysemantic_stack_[(1) - (1)].expr);
                           
    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 2432 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 2440 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 2447 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = new GroupSpecList(LOC((yyloc)));
      gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl_p;
    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 2453 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      if (gsl_p) {
        gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      }
      (yyval.node) = gsl_p;
    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 2464 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(),
                 NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 2471 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), 
                 static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(), 
                 dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node))); 
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 2481 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 2491 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 2496 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)),
								true);
		}
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 2508 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		}
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2514 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node));
			if (osl_p) {
				osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 2528 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		}
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2534 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<OrderModifier*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 2546 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL,
								NULL);
		}
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2553 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		}
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2560 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2567 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
								NULL);
		}
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2574 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 2581 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2588 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 2601 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		}
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 2605 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		}
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 2615 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		}
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 2620 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		}
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 2631 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		}
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2642 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2649 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2662 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;
				
		}
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2669 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2681 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
								(yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (1)].expr);
		}
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2688 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (1)].expr);
		}
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2702 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
								(yysemantic_stack_[(8) - (8)].expr));
		}
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2709 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(10) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
								SYMTAB ((yysemantic_stack_[(10) - (8)].expr)),
								(yysemantic_stack_[(10) - (10)].expr));
		}
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2723 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		}
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2729 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2741 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2747 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr))->get_qname(),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
      delete (yysemantic_stack_[(7) - (3)].expr);
		}
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2761 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
		}
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2772 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2776 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2787 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2791 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2810 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 2814 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2822 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      /*  ::=  "is" | "<<" | ">>" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2830 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2838 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2845 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { /* this call is needed */  driver.lexer->interpretAsLessThan(); }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2846 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2854 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_le),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2862 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2870 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2884 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2888 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		}
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2895 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2908 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 2912 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 2923 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 2927 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 2931 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 2941 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 2945 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 2949 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 2953 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 2957 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 2967 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 2971 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 2976 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 2987 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 2991 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 2995 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3005 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3009 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3021 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3025 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3037 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3041 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3053 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3057 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3069 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3073 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3085 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		}
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3089 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		}
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3093 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3097 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3109 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3113 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3117 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3127 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		}
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3131 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		}
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3135 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		}
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3139 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		}
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3143 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		}
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3147 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		}
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3157 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		}
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3161 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		}
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3165 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		}
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3175 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3179 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3183 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3187 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                            dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(),
                            (yysemantic_stack_[(6) - (5)].expr));
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3199 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		}
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3205 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3217 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		}
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3223 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node));
			if (pragma_list_p) {
				pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3237 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));

		}
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3243 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval))),
								"");      
    }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3285 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		}
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3289 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3293 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3297 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (rpe == NULL ?
             (yysemantic_stack_[(1) - (1)].expr) :
             new PathExpr(LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3309 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3319 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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

  case 347:

/* Line 678 of lalr1.cc  */
#line 3330 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3335 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3345 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3349 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3359 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		}
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3365 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3371 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		}
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3377 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3389 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		}
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3395 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3406 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		}
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3410 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		}
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3414 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		}
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3418 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		}
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3422 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		}
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3426 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		}
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3430 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		}
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3440 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node), false);
		}
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3444 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		}
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3454 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseStep(LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node));
		}
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3458 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC((yyloc)), rev_p, NULL);
		}
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3469 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		}
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3473 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		}
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3477 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		}
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3481 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		}
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3485 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		}
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3500 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3504 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3514 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3518 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3528 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        "",
                        ParseConstants::wild_all);
		}
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3535 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        ParseConstants::wild_elem);
		}
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3542 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        ParseConstants::wild_prefix);
		}
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3555 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3559 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
                          (yysemantic_stack_[(2) - (1)].expr),
                          dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3571 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		}
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3577 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node));
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3591 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3602 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3606 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3610 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3614 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3618 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3622 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3626 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3630 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3640 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3644 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3654 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval));
      delete yylval.decval;
		}
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3659 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival));
      delete yylval.ival;
		}
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3664 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval));
      delete yylval.dval;
		}
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3675 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new VarRef(LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname());
      delete (yysemantic_stack_[(2) - (2)].expr);
		}
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3686 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		}
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3690 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3701 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		}
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3711 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3722 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3778 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)),
								NULL);
		}
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3784 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3796 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = new ArgList(LOC ((yyloc))); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		}
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3802 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3814 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3818 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3828 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3832 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3836 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3846 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
								NULL,
								NULL,
								NULL);
		}
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3854 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
								NULL,
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)), 
								NULL);
		}
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3862 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(8) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr)),
								NULL,
								NULL);
		}
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3870 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
								NULL,
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node)));
		}
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3878 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
								NULL);
		}
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3886 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(10) - (2)].expr)),
								static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)), 
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node)));
		}
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3901 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		}
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3907 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3919 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		}
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3925 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3938 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
		}
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 3955 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		}
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 3960 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		}
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 3971 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		}
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 3975 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 3982 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		}
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 3988 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		}
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 3994 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 4002 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 4016 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		}
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 4020 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 4027 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		}
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 4033 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		}
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4039 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4047 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4061 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4066 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4077 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4082 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4093 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		}
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4098 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4103 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		}
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4109 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		}
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4121 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4127 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		}
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4132 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		}
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4137 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4148 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4153 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4168 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4173 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		}
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4190 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CDataSection(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		}
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4205 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4209 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4213 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4217 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4221 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4225 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4235 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4246 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
								NULL);
		}
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4252 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4258 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4263 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4285 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (2)].expr),
								NULL);
		}
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4291 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4297 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4302 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4313 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4323 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4333 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		}
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4339 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4345 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4350 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4361 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		}
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4367 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		}
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4379 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
		}
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4390 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		}
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4396 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4402 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		}
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4439 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		}
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4444 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		}
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4449 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		}
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4460 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4464 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4468 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		}
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4478 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4489 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4493 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4497 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4501 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4505 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4509 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4513 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4517 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4521 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4531 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		}
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4541 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		}
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4545 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4550 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4561 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TextTest(LOC ((yyloc)));
		}
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4571 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		}
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4581 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		}
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4585 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		}
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4589 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		}
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4599 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		}
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4605 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
								NULL);
		}
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4611 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		}
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4617 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		}
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4623 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		}
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4635 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
		}
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4646 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           NULL,
                           NULL,
                           true);
		}
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4653 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                           NULL,
                           true);
		}
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4660 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           false);
		}
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4667 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           true);
		}
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4674 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL,
									true);
		}
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4681 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									false);
		}
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4688 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									true);
		}
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4701 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)));
		}
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4722 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4729 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)),
								true);
		}
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4749 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4789 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::strict_validation);
		}
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4793 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::lax_validation);
    }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4797 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::skip_validation);
    }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4806 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4812 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4818 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4824 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4830 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4837 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4843 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4849 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4855 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4861 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4873 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4878 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4888 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4894 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4906 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4932 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4943 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       CopyVarList* lList = new CopyVarList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
		}
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4949 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
       VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
       lList->push_back(lBinding);
       (yyval.expr) = lList;
		}
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4962 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(), (yysemantic_stack_[(3) - (3)].expr));  
       delete (yysemantic_stack_[(3) - (1)].expr);
    }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4977 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4984 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4990 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* aCatchListExpr = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if (aCatchListExpr) {
        aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)));
      }
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 5001 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(3) - (2)].name_test_list),
                          (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 5008 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(7) - (2)].name_test_list),
                          static_cast<QName*>((yysemantic_stack_[(7) - (5)].expr))->get_qname(),
                          (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (5)].expr);
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 5018 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
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

  case 554:

/* Line 678 of lalr1.cc  */
#line 5029 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(13) - (2)].name_test_list),
                          static_cast<QName*>((yysemantic_stack_[(13) - (5)].expr))->get_qname(),
                          static_cast<QName*>((yysemantic_stack_[(13) - (8)].expr))->get_qname(),
                          static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr))->get_qname(),
                          (yysemantic_stack_[(13) - (13)].expr));
       delete (yysemantic_stack_[(13) - (5)].expr);
       delete (yysemantic_stack_[(13) - (8)].expr);
       delete (yysemantic_stack_[(13) - (2)].name_test_list);
    }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 5044 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      CatchExpr::NameTestList *name_test_list = new CatchExpr::NameTestList;
      name_test_list->push_back (static_cast<NameTest *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.name_test_list) = name_test_list;
    }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 5050 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      CatchExpr::NameTestList *name_test_list =
        static_cast<CatchExpr::NameTestList *> ((yysemantic_stack_[(3) - (1)].name_test_list));
      name_test_list->push_back (static_cast<NameTest *> ((yysemantic_stack_[(3) - (3)].node)));
      (yyval.name_test_list) = name_test_list;
    }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 5070 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      std::string tmp = static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr))->get_qname();
      if (tmp.find (':') != std::string::npos) {
        error((yylocation_stack_[(1) - (1)]), "A NCName is expected, found a QName");
        YYERROR;
      }
      (yyval.sval) = SYMTAB_PUT(tmp.c_str());
    }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 5087 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { 
      (yyval.expr) = new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval))); 
    }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 5091 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { 
      (yyval.expr) = new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval))); 
    }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 5097 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("xquery"); }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 5098 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty"); }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 5099 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("attribute"); }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 5100 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("comment"); }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 5101 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document-node"); }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 5102 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("element"); }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 5103 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("item"); }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5104 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("if"); }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5105 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("node"); }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5106 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("processing-instruction"); }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5107 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-attribute"); }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5108 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-element"); }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5109 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("text"); }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5110 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("typeswitch"); }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5111 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty-sequence"); }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5112 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("boundary-space"); }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5113 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ft-option"); }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5114 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("base-uri"); }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5115 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lax"); }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5116 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strict"); }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5117 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("idiv"); }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5118 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document"); }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5119 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("not"); }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5120 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sensitive"); }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5121 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insensitive"); }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5122 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("diacritics"); }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5123 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("without"); }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5124 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stemming"); }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5125 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("thesaurus"); }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5126 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stop"); }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5127 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("wildcards"); }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5128 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("entire"); }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5129 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("content"); }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5130 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("word"); }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5131 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("start"); }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5132 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("end"); }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5133 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("most"); }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5134 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("skip"); }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5135 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy"); }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5136 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("value"); }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5137 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eq"); }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5138 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ne"); }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5139 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lt"); }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5140 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("le"); }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5141 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("gt"); }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5142 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ge"); }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5143 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("at"); }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5144 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("context"); }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5145 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("variable"); }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5146 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("return"); }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5147 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("for"); }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5148 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("outer"); }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5149 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sliding"); }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5150 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("tumbling"); }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5151 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("previous"); }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5152 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("next"); }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5153 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("only"); }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5154 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("when"); }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5155 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("count"); }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5156 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("in"); }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5157 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("let"); }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5158 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("where"); }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5159 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("by"); }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5160 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("group"); }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5161 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("order"); }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5162 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stable"); }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5163 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ascending"); }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5164 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("descending"); }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5165 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("greatest"); }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5166 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("least"); }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5167 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("collation"); }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5168 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("some"); }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5169 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("every"); }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5170 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("satisfies"); }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5171 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("case"); }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5172 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("as"); }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5173 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("then"); }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5174 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("else"); }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5175 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("or"); }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5176 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("and"); }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5177 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("instance"); }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5178 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("of"); }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5179 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("castable"); }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5180 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("to"); }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5181 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("div"); }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5182 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("mod"); }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5183 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("union"); }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5184 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("intersect"); }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5185 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("except"); }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5186 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("validate"); }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5187 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("cast"); }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5188 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("treat"); }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5189 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("is"); }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5190 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("preserve"); }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5191 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strip"); }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5192 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("namespace"); }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5193 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("external"); }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5194 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("encoding"); }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5195 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-preserve"); }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5196 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("inherit"); }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5197 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-inherit"); }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5198 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("declare"); }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5199 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("construction"); }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5200 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordering"); }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5201 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("default"); }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5202 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy-namespaces"); }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5203 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("option"); }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5204 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("version"); }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5205 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("import"); }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5206 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema"); }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5207 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("module"); }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5208 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("function"); }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5209 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("score"); }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5210 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ftcontains"); }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5211 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("weight"); }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5212 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("window"); }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5213 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("distance"); }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5214 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("occurs"); }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5215 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("times"); }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5216 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("same"); }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5217 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("different"); }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5218 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lowercase"); }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5219 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("uppercase"); }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5220 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("relationship"); }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5221 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("levels"); }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5222 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("language"); }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5223 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("any"); }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5224 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("all"); }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5225 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("phrase"); }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5226 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exactly"); }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5227 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("from"); }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5228 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("words"); }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5229 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentences"); }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5230 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentence"); }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5231 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("paragraph"); }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5232 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("replace"); }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5233 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("modify"); }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5234 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("first"); }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5235 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insert"); }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 5236 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("before"); }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5237 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("after"); }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 5238 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("revalidation"); }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 5239 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("with"); }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 5240 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nodes"); }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 5241 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("rename"); }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 5242 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("last"); }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 5243 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("delete"); }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 5244 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("into"); }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 5245 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("simple"); }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 5246 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sequential"); }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 5247 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("updating"); }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 5248 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("deterministic"); }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 5249 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nondeterministic"); }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 5250 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordered"); }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 5251 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unordered"); }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 5252 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("block"); }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 5253 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exit"); }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 5254 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("loop"); }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 5255 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("while"); }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 5256 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("break"); }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 5257 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("continue"); }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 5258 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("try"); }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 5259 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("catch"); }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 5260 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eval"); }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 5261 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("using"); }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 5262 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("set"); }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 5263 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("index"); }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 5264 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("create"); }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 5265 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("build"); }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 5266 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unique"); }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 5267 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("on"); }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 5268 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("hash"); }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 5269 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("btree"); }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 5270 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("drop"); }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 5271 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("decimal-format"); }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 5272 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("decimal-separator"); }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 5273 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("grouping-separator"); }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 5274 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("infinity"); }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 5275 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("minus-sign"); }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 5276 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("NaN"); }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 5277 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("percent"); }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 5278 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("per-mille"); }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 5279 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("zero-digit"); }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 5280 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("digit"); }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 5281 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("pattern-separator"); }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 5293 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)),
                          (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 5299 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 5316 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(1) - (1)].node)), NULL, NULL);
		}
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 5320 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(2) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(2) - (2)].node)), NULL);
		}
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 5324 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(3) - (1)].node)), NULL, static_cast<RangeExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		}
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 5328 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(4) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(4) - (2)].node)), static_cast<RangeExpr *> ((yysemantic_stack_[(4) - (4)].expr)));
		}
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 5338 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 5341 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 5344 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 5347 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 5356 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 5359 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 5368 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 5371 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 5380 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 5383 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 5392 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 5395 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 5404 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 5407 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 5410 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 5419 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 5422 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 5431 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), static_cast<StringLiteral *> ((yysemantic_stack_[(1) - (1)].expr)), NULL);
		}
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 5435 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 5445 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 5448 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 5451 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 5454 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 5457 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 5466 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 5475 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 5479 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 5483 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 5487 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 5491 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 5495 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 5499 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 5509 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 5512 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 5515 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 5518 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 5527 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 5530 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 5533 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 5536 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 5545 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 5548 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 5557 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 5560 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 5563 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 5566 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 5569 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 5572 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 5575 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 5584 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 5587 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 5596 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 5599 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 5602 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 5605 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 5614 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 5617 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 5620 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 5623 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 5626 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 5635 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 5638 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 5647 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 5650 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 5659 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 5662 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 5671 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 5674 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 5683 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 5692 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 5695 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 5704 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 5707 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 5710 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 5719 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 5722 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 5725 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 5728 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 5731 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 5740 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 5744 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 5748 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 5752 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 5762 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 5771 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWindow (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (2)].expr)), static_cast<FTUnit *> ((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 5781 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 5790 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 5793 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 5802 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 5805 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 5808 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 5817 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 5820 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 5829 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTIgnoreOption (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		}
    break;



/* Line 678 of lalr1.cc  */
#line 9781 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1187;
  const short int
  xquery_parser::yypact_[] =
  {
      1378, -1187, -1187, -1187, -1187,     4,    29,   153, -1187,   196,
     126,   142,   147,  7609,   186,   387,   403,    26, -1187, -1187,
   -1187, -1187, -1187, -1187,   268,  6543, -1187,   529,   370, -1187,
     341, -1187, -1187, -1187,   404,   411, -1187,   357,   304,   490,
   -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187,   407,
     431, -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187,
   -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187,
   -1187, -1187,  7873, -1187,  6003, -1187, -1187, -1187, -1187, -1187,
   -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187,  9457, -1187,
   -1187, -1187, -1187, -1187, -1187, -1187, -1187,   446, -1187, -1187,
   -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187,  1651,
    9457, -1187, -1187, -1187, -1187, -1187, -1187,   447, -1187, -1187,
   -1187, -1187,  7079, -1187,  7345, -1187, -1187, -1187, -1187, -1187,
    9457, -1187, -1187,  5731, -1187, -1187, -1187, -1187, -1187, -1187,
     450, -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187,    12,
     399, -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187,   369,
     464,   385, -1187,   401,   255, -1187, -1187, -1187, -1187, -1187,
   -1187,   508, -1187,   471, -1187,   510, -1187, -1187, -1187, -1187,
   -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187,
   -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187,
   -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187,
   -1187, -1187,   351,   360,   362, -1187, -1187, -1187, -1187, -1187,
    4099,   644, -1187,  4371, -1187, -1187,   353,  4643,   462,   486,
   -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187,
   -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187,
   -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187,
     -34, -1187, -1187, -1187, -1187,   292,  9457, -1187, -1187, -1187,
   -1187, -1187,   511,   584, -1187,   636,   426,   254,   327,   -74,
     332, -1187,   601,   483,   582,   594,  4915, -1187, -1187, -1187,
     238, -1187, -1187,  5731, -1187,   425, -1187,   547,  6003, -1187,
     547,  6003, -1187, -1187, -1187, -1187,   547, -1187, -1187, -1187,
   -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187,
   -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187,
   -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187,
   -1187, -1187, -1187, -1187, -1187,   546, -1187, -1187, -1187, -1187,
    4643, -1187, -1187,  4643,  9457,  4643,   550,   551,  4643, -1187,
   -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187,
   -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187,
   -1187, -1187, -1187, -1187, -1187,  4643,  8137, -1187, -1187, -1187,
   -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187,
   -1187,   552,  4643,  4643,   520,  4643,   521,  9457,   664,   666,
     503,   503,   664,  9457,   164,   -63,   686,   -60,   171,  9457,
     560,   595,   389,  7079,   -93,    80,   323,   686, -1187, -1187,
     432, -1187, -1187, -1187, -1187, -1187,  4643, -1187,  4643,  6811,
     564, -1187,    66,    21,  9457,  7079,  9457,  9457,  4643,   451,
     453, -1187,   606,   607,  9457,     5,  4643,  8401,   569,   573,
     574,   576,   577,   580, -1187, -1187, -1187,  9457, -1187,   554,
     707,  4643,    40, -1187,   718,   558, -1187,  4643,   532, -1187,
     721,  4643,  4643,   561,  4643,  4643,  4643,  4643,   517,  9457,
    4643,  9457,   686,   686,   686, -1187, -1187, -1187, -1187,    26,
     529, -1187, -1187,   353,   706,  4643, -1187,  4643,   581,   411,
     304,   490,   630,   583,   585,  4643,  4643, -1187, -1187, -1187,
   -1187, -1187, -1187, -1187,   646, -1187,   -37,  5187,  5187,  5187,
   -1187,  5187,  5187, -1187,  5187, -1187,  5187, -1187, -1187, -1187,
   -1187, -1187, -1187, -1187,  5187,  5187,     6,  5187,  5187,  5187,
    5187,  5187,  5187,  5187,  5187,  5187,  5187,  5187,   526,   661,
     671,   673, -1187, -1187, -1187,  1923, -1187, -1187,  5731,  5731,
    4643,   547, -1187, -1187,   547, -1187,   547,  2195,  5459, -1187,
     586,   618, -1187,   590,  4643,  4643,   588,   593, -1187,   -43,
     -20,  2467,   596,   598, -1187,   599, -1187,   628, -1187,  9457,
   -1187, -1187, -1187, -1187,   763, -1187, -1187, -1187, -1187, -1187,
   -1187,   679,   680, -1187, -1187,   605,    -4,  9457,   376,   632,
     634,   605,   686,   667,   663, -1187, -1187, -1187,   343,   -75,
     352,   775, -1187, -1187,   260, -1187, -1187, -1187, -1187, -1187,
   -1187, -1187, -1187, -1187,   515, -1187,   617,   623,   621, -1187,
     622,  2739,  7079,   710,   771,  7079,   686,   713,   -41, -1187,
     176,   682,   670,   708, -1187,   -47,   633, -1187, -1187,  9457,
     -22, -1187,   631,   573,   407, -1187,   635,   637,   639, -1187,
       7,   150,  3011,    -7, -1187,  9457,   707, -1187,    -6,   641,
   -1187, -1187, -1187, -1187,   642, -1187,   -14, -1187, -1187, -1187,
      97,   101,   722,   589,   602,   -53, -1187,   677,   645,    63,
   -1187, -1187, -1187, -1187, -1187,   640, -1187,   160, -1187, -1187,
     -26,   659,  9457,  4643,   712, -1187, -1187,   714,  8929,   715,
    4643,   716,   -82,   684,   -48,   584, -1187, -1187, -1187, -1187,
   -1187,  5187, -1187, -1187, -1187,  4643,     6,   236, -1187,   571,
     393,   591,   578, -1187, -1187,   587,    23,   327,   327,   297,
     -74,   -74,   -74,   -74,   332,   332, -1187, -1187,  8929,  8929,
    9457,  9457, -1187,   668, -1187, -1187,   665, -1187, -1187, -1187,
     190,   595,   -18,   669,     4,  4643, -1187,   672,   674,   744,
     697,  9457, -1187,  9457, -1187, -1187,   675, -1187, -1187, -1187,
     181,   139,   628, -1187,   107,   270, -1187, -1187, -1187, -1187,
   -1187, -1187, -1187, -1187, -1187, -1187,   605, -1187,   720,  9193,
     711,  4643, -1187, -1187, -1187,   759,   717,  4643,   686,   686,
     605, -1187,   489,   686, -1187, -1187,   592, -1187, -1187,   597,
     301, -1187, -1187, -1187, -1187, -1187, -1187,   603, -1187, -1187,
    4643,   662,   709, -1187, -1187, -1187,   678,   730,   686,   704,
     732,   767,   686,   747,  4643,  4643,   723,   686,  4643,   748,
    4643,   728,   -89, -1187,   276,   624, -1187, -1187,   395,   -22,
   -1187, -1187, -1187,   719,  9457, -1187,  9457, -1187, -1187,   698,
    4643,   850, -1187,   187, -1187,   110, -1187, -1187,   857, -1187,
     346,  4643,  4643,  4643,   379,  4643,  4643,  4643,  4643,  4643,
    4643,   764,  4643,  4643,   647,   731,   766,   706,   806, -1187,
    4643, -1187,   378,   779, -1187,  9457,   780, -1187,  9457,   735,
     736, -1187,   215, -1187, -1187, -1187,  9457, -1187,  9457,  4643,
     746,  4643,  4643,   -70,   749, -1187,   724,   725, -1187,   643,
   -1187,   -81, -1187,   208,   -31,   651,     6,   208,  5187,  5187,
     494, -1187, -1187, -1187, -1187, -1187, -1187, -1187,     6,   757,
     -31, -1187,   619,   847, -1187, -1187, -1187, -1187, -1187,   761,
   -1187, -1187, -1187,  4643, -1187,   765, -1187,   595, -1187, -1187,
   -1187,   726, -1187, -1187,  8665,    17, -1187,  3283,   727,   729,
     769,   733,   738, -1187,  9457,   813,   195, -1187, -1187,  4643,
   -1187,     4, -1187, -1187, -1187, -1187, -1187,   887,   439, -1187,
   -1187, -1187,  4643, -1187, -1187, -1187, -1187, -1187, -1187,   649,
      -5,   891, -1187,    16, -1187, -1187,   751,  4643,  3555, -1187,
     686,   808, -1187, -1187, -1187,   686,   808,  9457, -1187, -1187,
    4643,   737, -1187,  9457, -1187,  4643,  4643,   783,  4643,   782,
   -1187,   801,   810,  4643,  9457,   567,   860, -1187, -1187, -1187,
    3827,   752,   753, -1187, -1187, -1187,   800, -1187,   175, -1187,
   -1187,   923, -1187, -1187,  4643,  9457, -1187, -1187,   342, -1187,
   -1187, -1187,   745,   739,   740, -1187, -1187, -1187,   741,   742,
   -1187, -1187, -1187, -1187, -1187,   700,  9457,   756, -1187,  6275,
     647, -1187,  4643,  9457,   779, -1187,   686, -1187,   525, -1187,
     325,   834, -1187,  4643,   835,   712, -1187,   760,   768, -1187,
   -1187, -1187, -1187, -1187, -1187, -1187,  4643, -1187, -1187,  4643,
     798,  4643, -1187, -1187,  5187, -1187, -1187, -1187, -1187, -1187,
      30,  5187,  5187,   250, -1187,   591, -1187, -1187,   112,  5187,
   -1187, -1187,   578,     6,   681, -1187, -1187, -1187, -1187,  4643,
   -1187, -1187,  9457,   762,   -33, -1187, -1187,   770, -1187, -1187,
   -1187, -1187, -1187,   759,  8929,   828,   854,   772, -1187, -1187,
   -1187, -1187,   -39,   927,   931,   -39,   -21,   216,   217,   802,
     830, -1187,   776,   861,   686,   808, -1187, -1187, -1187, -1187,
   -1187, -1187,  4643, -1187,  4643,  9457,  9457, -1187,   409, -1187,
    4643, -1187,   778, -1187, -1187,   850,  9457,   475, -1187,   781,
     850,  9457, -1187, -1187,  4643,  4643,  4643,  4643,  4643, -1187,
    4643, -1187,   245, -1187,   785, -1187, -1187, -1187, -1187,   834,
   -1187, -1187, -1187,   686, -1187, -1187, -1187, -1187, -1187, -1187,
    4643, -1187,   -74,  5187,  5187,   -74,   302, -1187, -1187, -1187,
   -1187, -1187, -1187, -1187, -1187, -1187,   865,  4643,  9457,  4643,
   -1187, -1187, -1187, -1187,  8929, -1187,    -5,    -5,   -39, -1187,
   -1187, -1187,    38,   -39,   941,   734,   870, -1187,   870, -1187,
    4643,   221,  4643, -1187,   686, -1187, -1187, -1187,   900, -1187,
   -1187, -1187, -1187,   -17,   850,  9457, -1187,   784,   850, -1187,
   -1187, -1187, -1187, -1187, -1187,   855,  6275, -1187, -1187, -1187,
   -1187, -1187,   -74,   -74,  5187,  8929, -1187,   786, -1187, -1187,
   -1187, -1187, -1187, -1187, -1187,   -31, -1187,   223, -1187,   227,
   -1187,   869,   759,  4643, -1187, -1187,   808,   858,   145,   161,
   -1187,   787,   850, -1187,   788,  9457, -1187,   -74,   796,  4643,
     743,   870, -1187, -1187,   686, -1187, -1187,  9457, -1187, -1187,
     886,   154, -1187, -1187, -1187, -1187,   803,   244, -1187, -1187,
   -1187,   791, -1187,   233,  4643, -1187, -1187, -1187, -1187, -1187,
   -1187, -1187, -1187, -1187, -1187, -1187, -1187,   867,   836, -1187,
    9457, -1187,   241,   871,   836,  9457, -1187,   804,   836, -1187
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   378,   379,   560,   525,   717,   718,   721,   719,   722,
     720,   651,   575,   567,   583,   574,   565,   663,   673,   712,
     711,   713,   714,   710,   569,   571,   598,   670,   633,   627,
     672,   668,   595,   671,   727,   622,   664,   725,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   665,   579,   573,
     566,   667,   642,   572,   577,   736,   737,   738,   739,   740,
     741,   742,   743,   744,   745,   746,   369,   372,   641,   637,
     628,   608,   564,   359,     0,   636,   644,   652,   357,   632,
     395,   609,   610,   666,   358,   361,   629,   646,     0,   401,
     367,   397,   639,   563,   630,   631,   659,   634,   650,   658,
     363,   362,   582,   621,   661,   396,   649,   654,   568,     0,
       0,   316,   647,   657,   662,   660,   640,   715,   626,   624,
     625,   368,     0,   315,     0,   371,   370,   655,   611,   635,
       0,   360,   345,     0,   377,   656,   638,   645,   653,   648,
     716,   602,   607,   606,   605,   604,   603,   576,   623,     0,
     562,   669,   596,   702,   701,   703,   581,   580,   599,   708,
     570,   700,   705,   706,   697,   601,   643,   699,   709,   707,
     698,   600,   704,   723,   724,   726,   689,   688,   585,   578,
     587,   586,   682,   678,   593,   597,   594,   691,   692,   675,
     584,   687,   686,   683,   679,   696,   690,   685,   681,   674,
     695,   694,   680,   684,   676,   677,   588,   589,   591,   693,
     590,   592,   729,   730,   735,   731,   728,   733,   734,   732,
       0,     0,     2,     0,     4,     6,    12,     0,     0,     0,
      18,    20,    32,    22,    23,    24,    48,    25,    29,    30,
      52,    53,    54,    49,    50,    56,    57,    27,    26,    31,
      51,   174,   173,   170,   171,   172,   175,    28,    11,   151,
     152,   156,   158,   190,   196,     0,     0,   188,   189,   159,
     160,   161,   162,   272,   274,   276,   286,   289,   291,   294,
     299,   302,   305,   307,   309,   311,     0,   313,   319,   321,
       0,   337,   320,   341,   344,   346,   349,   351,     0,   356,
     353,     0,   364,   374,   376,   350,   380,   385,   393,   386,
     387,   388,   391,   392,   389,   390,   408,   410,   411,   412,
     409,   457,   458,   459,   460,   461,   462,   373,   499,   491,
     498,   497,   496,   493,   495,   492,   494,   394,    55,   163,
     164,   166,   165,   167,   168,   375,   561,   169,   122,   119,
       0,   130,   131,     0,     0,     0,     0,     0,     0,   717,
     718,   721,   722,   720,   651,   575,   567,   583,   574,   565,
     663,   569,   571,   670,   633,   672,   727,   622,   725,   612,
     613,   573,   566,   564,   634,     0,     0,   715,   716,   562,
     708,   570,   700,   706,   697,   600,   723,   726,   729,   730,
     735,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    99,   100,
       0,   101,   102,   104,   135,   138,     0,   558,     0,     0,
       0,   559,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   198,     0,     0,     0,     0,     0,     0,     0,   567,
     574,   565,   571,   564,   365,   375,   398,     0,   399,     0,
     424,     0,     0,   340,     0,     0,   343,     0,     0,   453,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     3,     1,     5,     7,     0,
       0,    13,    10,    15,    16,     0,   154,   153,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   176,   195,   191,
     197,   192,   194,   193,   200,   201,     0,     0,     0,     0,
     330,     0,     0,   328,     0,   281,     0,   329,   322,   327,
     326,   325,   324,   323,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   318,   317,   314,     0,   338,   342,     0,     0,
       0,   352,   382,   355,   354,   366,   381,     0,     0,   128,
       0,     0,   523,     0,     0,     0,     0,     0,   515,     0,
       0,     0,     0,     0,   504,     0,   505,     0,   140,     0,
     141,   137,   136,   139,     0,   113,   114,    65,    66,   557,
      74,     0,     0,    59,    60,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   526,   527,   528,     0,     0,
       0,     0,   785,   786,     0,    64,   778,   779,   780,   781,
     782,   783,   784,   103,     0,   105,     0,     0,     0,   506,
       0,     0,     0,    83,     0,     0,     0,    75,     0,   261,
       0,     0,     0,   213,   214,     0,     0,   178,   179,     0,
       0,   199,     0,     0,     0,   501,     0,     0,     0,   509,
       0,     0,     0,     0,   400,   425,   424,   421,     0,     0,
     455,   454,   339,   514,     0,   452,     0,   539,   540,   500,
       0,     0,     0,     0,     0,     0,   545,     0,     0,     0,
     216,   233,   132,   134,   133,     0,    19,     0,    21,   157,
       0,     0,     0,     0,     0,   177,   234,     0,     0,     0,
       0,     0,     0,     0,     0,   273,   275,   279,   285,   284,
     283,     0,   280,   277,   278,     0,     0,     0,   770,   287,
     749,   757,   759,   761,   763,   765,   768,   293,   292,   290,
     296,   297,   298,   295,   300,   301,   304,   303,     0,     0,
       0,     0,   335,     0,   347,   348,     0,   383,   404,   406,
       0,   663,     0,     0,     0,     0,   331,     0,     0,     0,
       0,     0,   519,     0,   516,   464,     0,   463,   472,   473,
       0,     0,     0,    63,     0,     0,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    34,    35,     0,     0,
      91,     0,    87,    89,    90,    94,    97,     0,     0,     0,
      33,    73,     0,     0,   787,   788,     0,   789,   793,     0,
       0,   822,   791,   792,   821,   790,   794,     0,   801,   823,
       0,     0,     0,   508,   507,   474,     0,     0,     0,     0,
       0,    76,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   748,     0,     0,   180,   181,     0,   186,
     522,   502,   503,     0,     0,   512,     0,   510,   468,     0,
       0,   424,   422,     0,   413,     0,   402,   403,     0,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    17,     0,   155,
       0,   187,   245,   241,   243,     0,   235,   236,     0,   568,
     576,   480,   481,   487,   488,   490,     0,   203,     0,     0,
       0,     0,     0,     0,     0,   282,     0,     0,   764,     0,
     288,     0,   777,     0,     0,     0,     0,     0,     0,     0,
     750,   754,   772,   753,   776,   774,   773,   775,     0,     0,
       0,   766,   829,   827,   831,   769,   306,   308,   310,   478,
     312,   336,   384,     0,   405,   125,   124,     0,   121,   120,
     129,     0,   333,   332,     0,     0,   267,     0,     0,     0,
     523,     0,     0,   465,     0,   115,     0,   145,   143,     0,
     142,     0,    71,    72,    69,    70,    36,     0,     0,    92,
      93,    95,     0,    96,    61,    62,    67,    68,    58,     0,
       0,     0,   796,     0,   795,   812,     0,     0,     0,   475,
       0,    85,    79,    82,    81,     0,    77,     0,   259,   263,
       0,     0,   127,     0,   218,     0,     0,     0,     0,     0,
     182,     0,     0,     0,     0,   227,     0,   224,   229,   185,
       0,     0,     0,   469,   260,   425,     0,   414,     0,   448,
     445,     0,   449,   450,     0,     0,   451,   444,     0,   419,
     447,   446,     0,     0,     0,   532,   533,   529,     0,     0,
     537,   538,   534,   543,   541,     0,     0,     0,   547,     0,
     548,   549,     0,     0,   242,   254,     0,   255,     0,   246,
     247,   248,   249,     0,   238,     0,   202,     0,     0,   484,
     486,   485,   482,   211,   212,   205,     0,   207,   204,     0,
       0,     0,   771,   767,     0,   824,   825,   845,   844,   840,
       0,     0,     0,     0,   826,   758,   839,   751,     0,     0,
     756,   755,   760,     0,     0,   830,   828,   479,   407,     0,
     123,   334,     0,     0,     0,   268,   466,     0,   520,   521,
     524,   517,   518,   147,     0,     0,   116,     0,   144,    37,
      88,    98,   810,     0,     0,   808,   804,     0,     0,     0,
       0,   476,     0,    84,     0,    78,   262,   264,    14,   215,
     220,   219,     0,   222,     0,     0,     0,   184,   225,   228,
       0,   470,     0,   513,   511,   424,     0,     0,   456,     0,
     424,     0,   420,     9,     0,     0,     0,     0,     0,   546,
       0,   555,     0,   550,     0,   217,   258,   256,   257,   250,
     251,   252,   244,     0,   239,   237,   489,   483,   209,   206,
       0,   208,   846,     0,     0,   832,     0,   843,   842,   841,
     836,   837,   752,   762,   838,   126,     0,     0,     0,     0,
     467,   148,   117,   146,     0,   150,     0,     0,   811,   813,
     815,   817,     0,   809,     0,     0,     0,   799,     0,   797,
       0,     0,     0,   477,     0,    80,   221,   223,   232,   231,
     226,   183,   471,     0,   424,     0,   149,     0,   424,   530,
     531,   535,   536,   542,   544,     0,     0,   551,   747,   253,
     240,   210,   834,   833,     0,     0,   269,     0,   265,   118,
     820,   819,   814,   818,   816,   805,   806,     0,   802,     0,
     111,   107,   109,     0,   106,   271,    86,     0,   434,   428,
     423,     0,   424,   415,     0,     0,   556,   835,     0,     0,
       0,     0,   800,   798,     0,   110,   112,     0,   442,   436,
       0,   435,   437,   443,   440,   430,     0,   429,   431,   441,
     417,     0,   416,     0,     0,   266,   807,   803,   108,   230,
     427,   438,   439,   426,   432,   433,   418,     0,     0,   270,
       0,   552,     0,     0,     0,     0,   553,     0,     0,   554
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1187, -1187,   773, -1187,   777,   789, -1187,   790, -1187,   487,
     491,  -482, -1187,   365,  -328, -1187, -1187, -1187, -1187, -1187,
   -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187,  -853,
   -1187, -1187, -1187, -1187,   -29,   172,   575, -1187, -1187, -1187,
   -1187,   572,   565,  -354, -1187, -1187, -1187,   199, -1187,  -757,
   -1187, -1187,    15, -1187, -1187, -1187, -1187, -1187, -1187,   252,
      45, -1187, -1187,  -182, -1187, -1186,   792,   -66, -1187,   498,
    -342, -1187, -1187, -1187, -1187,   127, -1187, -1187,   750, -1187,
   -1187, -1187, -1187, -1187,    79,  -492,  -642, -1187, -1187, -1187,
     -45, -1187, -1187,  -209,   -55,  -100, -1187, -1187, -1187,  -111,
   -1187, -1187,   102,  -106, -1187, -1187,   -99, -1013, -1187,   553,
     -24, -1187, -1187,    31, -1187, -1187,   497,   500, -1187,  -494,
    -926,   476,   104,  -534,   100,   109, -1187, -1187, -1187, -1187,
   -1187,   755, -1187, -1187, -1187, -1187, -1187,   754, -1187, -1187,
    -123, -1187, -1187, -1187, -1187, -1187, -1187, -1187,   -50, -1081,
   -1187, -1187,   -57,   -19, -1187,  -541, -1187, -1187, -1187, -1187,
   -1187, -1187, -1187, -1187, -1187,  -870, -1187,   -49, -1187,   344,
    -684, -1187, -1187, -1187, -1187, -1187,  -356,  -349, -1040,  -842,
   -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187, -1187,
     262,  -659,  -748, -1187,   218,  -103,  -715, -1187, -1187, -1187,
   -1187, -1187, -1187, -1187,   600,   604,  -507,   242,    19, -1187,
   -1187, -1187, -1187, -1187, -1187, -1187,   -68, -1187, -1187,   -71,
   -1187,  -412,  -115,   -13, -1187, -1187,   296, -1187, -1187,    87,
      77,  -117,   300, -1187, -1187,    88, -1187,  -721, -1187, -1187,
   -1187, -1187,  -249,  -837, -1187,  -145,  -617, -1187,  -714, -1187,
   -1187, -1187, -1187,  -956, -1187, -1187, -1187, -1187,  -105,    99,
   -1187
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   816,   817,   818,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,  1041,
     656,   246,   247,   822,   823,   824,   985,   248,   430,   249,
     431,   432,   433,  1350,  1351,  1301,   250,   801,   251,   349,
     578,   782,   986,   252,   253,   254,   255,   256,   257,   434,
     435,   600,  1006,  1007,  1086,  1010,   258,   259,   507,   260,
     261,   262,   517,   452,   878,   879,   263,   518,   264,   520,
     265,   266,   267,   524,   525,  1065,   733,   268,   663,   709,
     664,   670,  1066,  1067,  1068,   710,   521,   522,   926,   927,
    1254,   523,   923,   924,  1119,  1120,  1121,  1122,   269,   658,
     659,   270,   995,   996,   271,   272,   273,   274,   741,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   544,   545,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   571,   572,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   780,   315,   316,   317,  1088,   686,   687,
     688,  1360,  1386,  1387,  1380,  1381,  1388,  1382,  1089,  1090,
     318,   319,  1091,   320,   321,   322,   323,   324,   325,   326,
     978,   734,   931,  1132,   932,   933,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   581,   999,   337,   338,
     339,   340,   341,   342,   343,   705,   706,   344,  1110,  1111,
    1242,  1042,   440,   345,   346,   347,   749,   960,   750,   751,
     752,   753,   754,   755,   756,   961,   962,   635,   636,   637,
     638,   639,  1347,  1348,   640,  1288,  1195,  1292,  1289,   641,
     642,   964,   975,  1153,   965,   966,   971,   967,  1270,  1149,
     950
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       401,   866,   893,  1034,   610,   748,   872,   472,   579,  1046,
     476,   580,   441,   934,  1164,   644,   760,   761,   762,   763,
     976,   977,   718,   871,   464,  1087,     4,   990,  1241,   963,
     653,   657,  1157,   478,   732,   737,   836,   738,   739,   673,
     740,   609,   742,   469,   875,   728,   729,   690,  1232,  1056,
     743,   744,   911,   934,   934,   728,  1327,   729,  1343,   458,
     939,   465,   791,  1150,   863,   407,   408,   409,   410,   411,
     412,   505,  1139,  1150,  1358,   466,   674,  1263,   413,   505,
     712,   713,   714,  1278,   414,   793,   609,   987,   819,  1193,
     940,   870,   944,  1286,   942,   415,   416,   470,   863,   417,
     607,   611,   418,   419,   934,   730,   666,  1250,  1251,   441,
    1031,   474,   884,   898,    80,   994,   612,   475,  1079,  1080,
     894,   554,   915,   625,   626,   627,    91,  1197,  1174,   820,
     555,  1145,   654,   608,   821,   420,   421,   422,   792,   697,
     698,   864,   700,   701,   702,   703,  1194,  1279,   708,  1378,
     105,   506,   348,  1079,   745,  1264,  1287,   746,  1378,   919,
    1359,   794,  1079,   719,  1146,   837,  1021,   988,   916,  1079,
     567,   899,   731,   725,   726,   890,   655,   912,   628,   731,
    1384,   423,   351,  1079,  1080,   895,   675,  1232,   885,   900,
     876,   731,  1205,   904,   838,   839,  1198,   840,   841,   407,
     408,   409,   410,   411,   412,   748,   748,  1076,  1087,   691,
     831,  1081,   413,   731,   731,  1059,  1151,  1152,  1087,  1344,
     479,   652,  1411,   877,   731,   352,  1151,  1152,  1416,  1082,
    1057,  1083,  1419,  1272,   354,   779,  1329,   419,  1294,  1161,
    1295,   424,   943,   574,   861,  1366,  1173,   945,   573,   576,
    1012,   575,  1079,   526,  1188,   886,     4,   747,  1084,   972,
     973,   350,   110,  1384,  1082,   425,  1083,  1013,   728,   420,
     421,   918,  1008,  1082,  1379,  1083,  1081,   353,   122,   934,
    1082,   974,  1083,  1401,   998,   465,  1001,  1009,   465,   583,
     355,  1385,   586,  1084,  1082,   983,  1083,  1004,   358,  1085,
    1185,  1140,  1084,   426,   427,   428,   429,   554,   624,  1084,
     901,   902,   629,  1077,   905,   906,   555,   149,   865,   587,
     630,  1296,  1298,  1084,   650,   903,  1353,   110,  1371,   907,
     661,   887,  1371,   631,   402,   632,   592,   593,  1407,   595,
     605,   582,   508,   122,    80,   633,  1413,   613,   634,   509,
    1079,  1080,   510,   511,   606,  1129,    91,  1087,   356,   357,
     512,   614,  1005,  1082,  1226,  1083,   449,   450,   728,  1267,
     646,   984,   647,   590,  1404,  1268,  1186,  1071,  1078,  1072,
     105,   922,   149,  1269,   745,  1130,   565,   746,   937,  1370,
     678,   499,  1084,  1009,   597,  1031,  1325,  1297,  1299,   425,
     604,   500,  1354,  1131,  1372,   689,   615,   547,  1373,   124,
     441,   694,  1032,  1014,  1408,   748,  1024,  1025,  1058,   436,
     451,  1028,  1414,   619,   548,  1158,   441,   748,   620,  1116,
    1015,   660,   441,   662,   665,   718,  1282,   426,   427,   428,
     429,   672,   550,  1081,   681,   774,   775,   549,  1118,  1326,
     547,  1356,  1033,   598,   660,  1051,   513,   603,   514,  1061,
    1062,  1082,  1063,  1083,   556,  1147,   621,   548,   551,   934,
    1148,  1115,   515,  1061,  1062,   487,   707,   557,   711,  1020,
     488,   552,  1116,  1079,  1080,  1023,   444,   951,  1016,   729,
    1084,   628,  1117,   622,   110,  1334,   445,   554,   516,   773,
     845,  1118,  1016,   729,   776,   448,   555,  1267,  1036,   826,
     122,  1064,   783,  1268,   827,   553,  1383,  1389,   787,   788,
     446,  1269,  1048,  1049,  1281,   796,  1052,   447,  1054,   846,
     847,  1231,   848,   849,  1397,   403,  1339,   857,   404,  1383,
     860,  1313,   407,   408,   409,  1389,  1317,   412,  1074,   149,
     453,   405,   777,   623,   406,   777,   952,   777,   454,  1095,
    1096,  1097,   467,  1100,  1101,  1102,  1103,  1104,  1105,   934,
    1107,  1108,   820,  1093,  1342,  1094,  1081,   821,   922,  1342,
     442,   834,   455,   443,   835,   856,   802,  1368,   951,   481,
     842,   482,   628,   843,  1082,   471,  1083,  1135,   477,  1137,
    1138,   427,   428,   429,   825,   484,  1098,   485,  1099,   480,
    1262,   568,   569,  1026,  1027,   483,   889,  1265,  1266,   490,
     934,   486,   748,  1084,   489,   629,   491,   110,  1203,   492,
    1361,  1061,  1062,   630,  1364,   953,   954,   955,   493,   441,
     494,  1168,   441,   122,   496,   956,   631,   503,   632,  1247,
    1248,   757,   758,   957,   764,   765,   874,   952,   633,   958,
     959,   634,   601,   602,  1315,   766,   767,   979,   979,  1340,
    1341,   504,   891,   527,   528,   558,   546,   559,  1391,   946,
    1191,   560,   149,   806,   807,   808,   809,   810,   811,   812,
     813,   814,   815,  1375,   561,  1200,   570,   577,   584,   585,
     591,   594,   596,   407,  1246,   599,   609,   616,  1207,   921,
     427,   617,   651,  1210,  1211,   935,  1213,   682,   667,   991,
     668,  1217,   669,   671,   386,   404,   629,   406,   439,  1332,
    1333,   457,   685,   692,   630,   684,   953,   954,   955,   693,
     695,   696,   699,   704,   717,   721,   722,   631,   723,   632,
     724,   727,   768,   769,   957,   935,   935,   935,   935,   633,
    1159,   959,   634,   770,   529,   771,   785,   784,   786,   789,
    1244,   790,   530,   531,   797,   532,   798,   799,  1000,   800,
    1000,   922,   533,   803,   804,   805,   534,   828,   535,   829,
     832,   833,  1305,   536,  1258,   844,   850,  1259,   851,  1261,
    1367,   852,   853,   854,   858,   859,   935,   862,   868,   537,
     867,   873,   880,   869,   908,   913,   881,   883,   882,   896,
     897,   909,   910,   914,   920,   917,   941,  1275,   925,   969,
     928,   936,   938,   538,   539,   540,   541,   542,   543,   949,
     968,  1330,   994,   970,   982,   997,   981,   989,  1017,   821,
     992,   728,   993,  1003,  1037,  1022,  1039,  1038,  1040,  1043,
    1044,  1045,  1029,  1047,  1053,  1050,  1055,  1070,  1030,  1060,
    1306,   582,  1307,   582,  1035,  1075,  1073,  1092,  1311,  1112,
    1106,  1109,  1113,   621,  1123,  1125,  1127,  1128,  1136,  1144,
    1165,  1141,  1319,  1320,  1321,  1322,  1323,  1154,  1324,  1163,
    1166,  1167,  1142,  1169,  1171,  1184,  1143,     4,  1178,  1180,
    1179,  1196,  1124,  1204,  1181,   526,  1199,  1215,  1331,  1182,
    1192,  1212,  1208,  1133,  1214,  1134,  1216,  1220,  1225,  1228,
    1233,  1177,  1238,  1223,  1224,  1336,  1240,  1338,  1116,  1253,
    1260,  1256,  1277,  1187,  1004,  1274,  1284,  1290,  1280,  1257,
    1285,  1291,  1302,  1300,  1303,  1304,  1312,  1335,  1352,  1316,
    1355,  1345,  1398,  1328,  1031,  1357,  1369,  1234,  1235,  1236,
    1237,  1365,  1202,  1374,  1377,  1363,  1394,  1400,  1390,  1392,
    1403,   935,  1406,  1410,  1009,  1418,   830,  1415,  1346,  1190,
     715,  1183,  1019,   495,   716,   645,   618,  1396,   643,  1376,
     497,  1011,  1170,  1283,  1222,   720,  1069,  1126,  1209,  1310,
    1219,  1352,   498,  1245,  1255,   519,   501,  1252,  1229,   502,
     683,  1249,  1114,  1206,   735,   759,  1175,  1395,   736,  1227,
     892,  1405,  1402,   980,   660,  1002,  1189,  1018,  1239,  1243,
     665,   564,   947,  1155,   566,  1162,  1273,   948,  1160,  1349,
    1293,  1218,  1409,  1271,     0,   676,  1156,     0,     0,   677,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1230,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   707,     0,     0,   465,     0,     0,     0,
     711,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1276,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   935,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1308,  1309,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1314,     0,     0,     0,     0,  1318,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1337,     0,     0,     0,     0,
       0,   935,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1362,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   465,     0,     0,     0,     0,     0,     0,
       0,     0,   935,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1393,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1399,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,     0,     0,     0,     0,     2,     3,  1412,     4,     0,
       0,     0,  1417,     0,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,     0,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,    74,    75,    76,    77,     0,
       0,    78,    79,     0,     0,     0,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,     0,    91,     0,
      92,    93,    94,    95,     0,    96,     0,     0,     0,    97,
      98,    99,   100,   101,     0,     0,     0,     0,     0,   102,
     103,   104,   105,   106,   107,   108,     0,     0,     0,   109,
     110,   111,   112,   113,     0,     0,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,   124,
       0,     0,   125,   126,   127,     0,     0,     0,   128,     0,
     129,   130,   131,     0,   132,   133,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   150,   151,     0,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,     0,   189,   190,
       0,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,   370,
      18,    19,    20,    21,    22,    23,    24,    25,    26,   373,
      28,    29,   375,    31,    32,    33,     0,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,    74,    75,
      76,    77,     0,     0,    78,    79,     0,     0,     0,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
       0,    91,     0,    92,    93,    94,    95,     0,    96,     0,
       0,     0,    97,    98,    99,   100,   101,     0,     0,     0,
       0,     0,   102,   103,   104,   105,   106,   107,   108,     0,
       0,     0,   109,   110,   111,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
       0,   123,   124,     0,     0,   125,   126,   127,     0,     0,
       0,   128,   468,   129,   130,   131,     0,   132,   133,   134,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,   149,     0,
     389,   151,     0,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,   189,   190,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,     0,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,   370,    18,    19,    20,    21,    22,    23,    24,    25,
      26,   373,    28,    29,   375,    31,    32,    33,     0,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
      74,    75,    76,    77,     0,     0,    78,    79,     0,     0,
       0,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,     0,    91,     0,    92,    93,    94,    95,     0,
      96,     0,     0,     0,    97,    98,    99,   100,   101,     0,
       0,     0,     0,     0,   102,   103,   104,   105,   106,   107,
     108,     0,     0,     0,   109,   110,   111,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,     0,   123,   124,     0,     0,   125,   126,   127,
       0,   772,     0,   128,     0,   129,   130,   131,     0,   132,
     133,   134,     0,   135,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
     149,     0,   389,   151,     0,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,     0,   189,   190,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
       0,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,   370,    18,    19,    20,    21,    22,    23,
      24,    25,    26,   373,    28,    29,   375,    31,    32,    33,
       0,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,    74,    75,    76,    77,     0,     0,    78,    79,
       0,     0,     0,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,     0,    91,     0,    92,    93,    94,
      95,     0,    96,     0,     0,     0,    97,    98,    99,   100,
     101,     0,     0,     0,     0,     0,   102,   103,   104,   105,
     106,   107,   108,     0,     0,     0,   109,   110,   111,   112,
     113,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,     0,   123,   124,     0,     0,   125,
     126,   127,     0,     0,     0,   128,   778,   129,   130,   131,
       0,   132,   133,   134,     0,   135,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,   149,     0,   389,   151,     0,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     0,   189,   190,     0,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,   370,    18,    19,    20,    21,
      22,    23,    24,    25,    26,   373,    28,    29,   375,    31,
      32,    33,     0,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,    74,    75,    76,    77,     0,     0,
      78,    79,     0,     0,     0,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,     0,    91,     0,    92,
      93,    94,    95,     0,    96,     0,     0,     0,    97,    98,
      99,   100,   101,     0,     0,     0,     0,     0,   102,   103,
     104,   105,   106,   107,   108,     0,     0,     0,   109,   110,
     111,   112,   113,     0,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,     0,   123,   124,     0,
       0,   125,   126,   127,     0,   795,     0,   128,     0,   129,
     130,   131,     0,   132,   133,   134,     0,   135,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,   149,     0,   389,   151,     0,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,     0,   189,   190,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,   370,    18,    19,
      20,    21,    22,    23,    24,    25,    26,   373,    28,    29,
     375,    31,    32,    33,     0,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    77,
       0,     0,    78,    79,     0,     0,     0,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,     0,    91,
       0,    92,    93,    94,    95,     0,    96,     0,     0,     0,
      97,    98,    99,   100,   101,     0,     0,     0,     0,     0,
     102,   103,   104,   105,   106,   107,   108,     0,     0,     0,
     109,   110,   111,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,   122,     0,   123,
     124,     0,     0,   125,   126,   127,     0,   855,     0,   128,
       0,   129,   130,   131,     0,   132,   133,   134,     0,   135,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,   149,     0,   389,   151,
       0,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     0,   189,
     190,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,   370,
      18,    19,    20,    21,    22,    23,    24,    25,    26,   373,
      28,    29,   375,    31,    32,    33,     0,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,    74,    75,
      76,    77,     0,     0,    78,    79,     0,     0,     0,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
       0,    91,     0,    92,    93,    94,    95,     0,    96,     0,
       0,     0,    97,    98,    99,   100,   101,     0,     0,     0,
       0,     0,   102,   103,   104,   105,   106,   107,   108,     0,
       0,     0,   109,   110,   111,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
       0,   123,   124,     0,     0,   125,   126,   127,     0,   888,
       0,   128,     0,   129,   130,   131,     0,   132,   133,   134,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,   149,     0,
     389,   151,     0,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,   189,   190,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,     0,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,   370,    18,    19,    20,    21,    22,    23,    24,    25,
      26,   373,    28,    29,   375,    31,    32,    33,     0,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
      74,    75,    76,    77,     0,     0,    78,    79,     0,     0,
       0,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,     0,    91,     0,    92,    93,    94,    95,     0,
      96,     0,     0,     0,    97,    98,    99,   100,   101,     0,
       0,     0,     0,     0,   102,   103,   104,   105,   106,   107,
     108,     0,     0,     0,   109,   110,   111,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,     0,   123,   124,     0,     0,   125,   126,   127,
       0,  1176,     0,   128,     0,   129,   130,   131,     0,   132,
     133,   134,     0,   135,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
     149,     0,   389,   151,     0,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,     0,   189,   190,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
       0,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,   370,    18,    19,    20,    21,    22,    23,
      24,    25,    26,   373,    28,    29,   375,    31,    32,    33,
       0,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,    74,    75,    76,    77,     0,     0,    78,    79,
       0,     0,     0,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,     0,    91,     0,    92,    93,    94,
      95,     0,    96,     0,     0,     0,    97,    98,    99,   100,
     101,     0,     0,     0,     0,     0,   102,   103,   104,   105,
     106,   107,   108,     0,     0,     0,   109,   110,   111,   112,
     113,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,     0,   123,   124,     0,     0,   125,
     126,   127,     0,  1201,     0,   128,     0,   129,   130,   131,
       0,   132,   133,   134,     0,   135,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,   149,     0,   389,   151,     0,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     0,   189,   190,     0,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,     0,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,   370,    18,    19,    20,    21,
      22,    23,    24,    25,    26,   373,    28,    29,   375,    31,
      32,    33,     0,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,    74,    75,    76,    77,     0,     0,
      78,    79,     0,     0,     0,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,     0,    91,     0,    92,
      93,    94,    95,     0,    96,     0,     0,     0,    97,    98,
      99,   100,   101,     0,     0,     0,     0,     0,   102,   103,
     104,   105,   106,   107,   108,     0,     0,     0,   109,   110,
     111,   112,   113,     0,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,     0,   123,   124,     0,
       0,   125,   126,   127,     0,  1221,     0,   128,     0,   129,
     130,   131,     0,   132,   133,   134,     0,   135,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,   149,     0,   389,   151,     0,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,     0,   189,   190,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,     0,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    77,
       0,     0,    78,    79,     0,     0,     0,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,     0,    91,
       0,    92,    93,    94,    95,     0,    96,     0,     0,     0,
      97,    98,    99,   100,   101,     0,     0,     0,     0,     0,
     102,   103,   104,   105,   106,   107,   108,     0,     0,     0,
     109,   110,   111,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,   122,     0,   123,
     124,     0,     0,   125,   126,   127,     0,     0,     0,   128,
       0,   129,   130,   131,     0,   132,   133,   134,     0,   135,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,   149,     0,   150,   151,
       0,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     0,   189,
     190,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,     0,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,     0,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,    74,    75,
      76,    77,     0,     0,    78,    79,     0,     0,     0,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
       0,    91,     0,    92,    93,    94,    95,     0,    96,     0,
       0,     0,    97,    98,    99,   100,   101,     0,     0,     0,
       0,     0,   102,   103,   104,   105,   106,   107,   108,     0,
       0,     0,   109,   110,   111,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
       0,   123,   124,     0,     0,   125,   126,   127,     0,     0,
       0,   128,     0,   129,   130,   131,     0,   132,   133,   134,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,   149,     0,
     389,   151,     0,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,   189,   190,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     4,     0,     0,     0,     0,     0,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,   370,    18,    19,    20,    21,    22,    23,    24,    25,
      26,   373,    28,    29,   375,    31,    32,    33,     0,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
      74,    75,    76,    77,     0,     0,    78,    79,     0,     0,
       0,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,     0,    91,     0,    92,    93,    94,    95,     0,
      96,     0,     0,     0,    97,    98,    99,   100,   101,     0,
       0,     0,     0,     0,   102,   103,   104,   105,   106,   107,
     108,     0,     0,     0,   109,   110,   111,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,     0,   123,   124,     0,     0,   125,   126,   127,
       0,     0,     0,   128,     0,   129,   130,   131,     0,   132,
     133,   134,     0,   135,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
     149,     0,   389,   151,     0,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,     0,   189,   190,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     4,     0,     0,     0,     0,
       0,   359,   360,   361,     8,   362,   363,    11,   365,    13,
      14,    15,    16,   370,    18,    19,    20,    21,    22,    23,
     371,    25,    26,   373,   374,    29,   375,    31,    32,    33,
       0,   376,   377,    36,   378,   379,   380,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,    74,    75,    76,    77,     0,     0,    78,    79,
       0,     0,     0,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,     0,    91,     0,    92,    93,    94,
      95,     0,    96,     0,     0,     0,   384,    98,    99,   100,
     101,     0,     0,     0,     0,     0,   102,   103,   104,   105,
     106,   107,   108,     0,     0,     0,   109,   110,   562,   112,
     113,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,     0,   563,   124,     0,     0,   125,
     126,   127,     0,     0,     0,   128,     0,   129,   130,   131,
       0,   132,   133,   134,     0,   135,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,   149,     0,   389,   151,     0,   152,   153,   154,
     155,   156,   157,   158,   390,   160,   392,   162,   393,   394,
     165,   166,   167,   168,   169,   170,   395,   172,   396,   174,
     397,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     0,   189,   190,     0,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   398,
     399,   400,   215,   216,   217,   218,   219,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,     0,   359,   360,   361,     8,   362,   363,    11,
     365,    13,    14,    15,    16,   370,    18,    19,    20,    21,
      22,    23,   371,    25,    26,   373,   374,    29,   375,    31,
      32,    33,     0,   376,   377,    36,   378,   379,   380,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,    74,    75,    76,    77,     0,     0,
      78,    79,     0,     0,     0,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,     0,    91,     0,    92,
      93,    94,    95,     0,    96,     0,     0,     0,   384,    98,
      99,   100,   101,     0,     0,     0,     0,     0,   102,   103,
     104,   105,   106,   107,   108,     0,     0,     0,   109,   110,
     111,   112,   113,     0,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,     0,   123,   124,     0,
       0,   125,   126,   127,     0,     0,     0,   128,     0,   129,
     130,   131,     0,   132,   133,   134,     0,   135,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,   149,     0,   389,   151,     0,   152,
     153,   154,   155,   156,   157,   158,   390,   160,   392,   162,
     393,   394,   165,   166,   167,   168,   169,   170,   395,   172,
     396,   174,   397,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,     0,   189,   190,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   398,   399,   400,   215,   216,   217,   218,   219,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     4,
       0,     0,     0,     0,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,   781,    18,    19,
      20,    21,    22,    23,    24,    25,    26,   373,    28,    29,
     375,    31,    32,    33,     0,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    77,
       0,     0,    78,    79,     0,     0,     0,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,     0,    91,
       0,    92,    93,    94,    95,     0,    96,     0,     0,     0,
      97,    98,    99,   100,   101,     0,     0,     0,     0,     0,
     102,   103,   104,   105,   106,   107,   108,     0,     0,     0,
     109,   110,   111,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   117,   118,   119,   120,   121,   122,     0,   123,
     124,     0,     0,   125,   126,   127,     0,     0,     0,   128,
       0,   129,   130,   131,     0,   132,   133,   134,     0,   135,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,   149,     0,   389,   151,
       0,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     0,   189,
     190,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,     0,   359,   360,   361,
       8,   362,   363,   364,   365,    13,    14,    15,    16,   370,
      18,    19,    20,    21,    22,    23,   371,    25,    26,   373,
     374,    29,   375,    31,    32,    33,     0,   376,   377,    36,
     378,   379,   380,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,    74,    75,
      76,    77,     0,     0,    78,    79,     0,     0,     0,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
       0,    91,     0,    92,    93,    94,    95,     0,    96,     0,
       0,     0,   384,    98,    99,   100,   101,     0,     0,     0,
       0,     0,   102,   103,   104,   105,   106,   107,   108,     0,
       0,     0,   109,   110,     0,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
       0,     0,     0,     0,     0,   125,   126,   127,     0,     0,
       0,   128,     0,   129,   130,   131,     0,     0,     0,   134,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,   149,     0,
     389,   151,     0,   152,   153,   154,   155,   156,   157,   158,
     390,   160,   392,   162,   393,   394,   165,   166,   167,   168,
     169,   170,   395,   172,   396,   174,   397,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,   189,   190,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   398,   399,   400,   215,   216,
     217,   218,   219,     1,     0,     0,     0,     0,     0,     0,
       2,     3,     0,     0,     0,     0,     0,     0,     0,   359,
     360,   361,     8,   362,   363,   364,   365,   459,   367,   460,
     461,   370,    18,    19,    20,    21,    22,    23,   371,   462,
      26,   373,   374,    29,   375,    31,    32,    33,     0,   376,
     377,    36,   378,   379,   380,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,     0,     0,    68,     0,    69,    70,    71,   463,     0,
       0,    75,    76,    77,     0,     0,     0,    79,     0,     0,
       0,     0,    81,    82,    83,     0,     0,    86,    87,     0,
       0,     0,     0,     0,     0,    92,    93,    94,    95,     0,
      96,     0,     0,     0,   384,    98,    99,     0,     0,     0,
       0,     0,     0,     0,   102,   103,   104,     0,   106,   107,
     108,     0,     0,     0,     0,     0,     0,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   387,   118,   119,   120,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   127,
       0,     0,     0,   128,     0,   129,   130,     0,     0,     0,
       0,   134,     0,   135,     0,   136,   137,   138,   139,   388,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
       0,     0,   389,   151,     0,   152,   153,   154,   155,   156,
     157,   158,   390,   160,   392,   162,   393,   394,   165,   166,
     167,   168,   169,   170,   395,   172,   396,   174,   397,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,     0,   189,   190,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   398,   399,   400,
     215,   216,   217,   218,   219,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     0,     0,     0,     0,     0,
       0,   359,   360,   361,     8,   362,   363,   364,   365,   366,
     367,   368,   369,   370,    18,    19,    20,    21,    22,    23,
     371,   372,    26,   373,   374,    29,   375,    31,    32,    33,
       0,   376,   377,    36,   378,   379,   380,    40,    41,    42,
      43,    44,    45,    46,    47,    48,   381,   382,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,     0,     0,    68,     0,    69,    70,    71,
     383,     0,     0,    75,    76,    77,     0,     0,     0,    79,
       0,     0,     0,     0,    81,    82,    83,     0,     0,    86,
      87,     0,     0,     0,     0,     0,     0,    92,    93,    94,
      95,     0,    96,     0,     0,     0,   384,    98,    99,     0,
       0,     0,     0,     0,     0,     0,   102,   103,   104,     0,
     106,   107,   108,     0,     0,     0,     0,     0,     0,   112,
     113,     0,     0,     0,     0,   114,   115,   116,   387,   118,
     119,   120,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   127,     0,     0,     0,   128,     0,   129,     0,     0,
       0,     0,     0,   134,     0,   135,     0,   136,   137,   138,
     139,   388,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,     0,     0,   389,   151,     0,   152,   153,   154,
     155,   156,   157,   158,   390,   391,   392,   162,   393,   394,
     165,   166,   167,   168,   169,   170,   395,   172,   396,   174,
     397,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     0,   189,   190,     0,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   398,
     399,   400,   215,   216,   217,   218,   219,   437,     0,     0,
       0,     3,     0,     0,     0,     0,     0,     0,     0,   359,
     360,   361,     8,   362,   363,   364,   365,   366,   367,   368,
     369,   370,    18,    19,    20,    21,    22,    23,   371,   372,
      26,   373,   374,    29,   375,    31,    32,    33,     0,   376,
     377,    36,   378,   379,   380,    40,    41,    42,    43,    44,
      45,    46,    47,    48,   381,   382,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,     0,     0,    68,     0,    69,    70,    71,   383,     0,
       0,    75,    76,    77,     0,     0,     0,    79,     0,     0,
       0,     0,    81,    82,    83,     0,     0,    86,    87,     0,
       0,     0,     0,     0,     0,    92,    93,    94,    95,     0,
      96,     0,     0,     0,   384,    98,    99,     0,     0,     0,
       0,     0,     0,     0,   102,   103,   104,     0,   106,   107,
     108,   438,     0,     0,   439,     0,     0,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   387,   118,   119,   120,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   127,
       0,     0,     0,   128,     0,   129,     0,     0,     0,     0,
       0,     0,     0,   135,     0,   136,   137,   138,   139,   388,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
       0,     0,   389,   151,     0,   152,   153,   154,   155,   156,
     157,   158,   390,   391,   392,   162,   393,   394,   165,   166,
     167,   168,   169,   170,   395,   172,   396,   174,   397,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,     0,   189,   190,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   398,   399,   400,
     215,   216,   217,   218,   219,   437,     0,     0,     0,     3,
       0,   648,     0,     0,     0,     0,     0,   359,   360,   361,
       8,   362,   363,   364,   365,   366,   367,   368,   369,   370,
      18,    19,    20,    21,    22,    23,   371,   372,    26,   373,
     374,    29,   375,    31,    32,    33,     0,   376,   377,    36,
     378,   379,   380,    40,    41,    42,    43,    44,    45,    46,
      47,    48,   381,   382,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,     0,
       0,    68,     0,    69,    70,    71,   383,     0,     0,    75,
      76,    77,     0,     0,     0,    79,     0,     0,     0,     0,
      81,    82,    83,     0,     0,    86,    87,     0,     0,     0,
       0,     0,     0,    92,    93,    94,    95,     0,    96,     0,
       0,     0,   384,    98,    99,     0,     0,     0,     0,     0,
       0,     0,   102,   103,   104,     0,   106,   107,   108,     0,
       0,     0,     0,     0,     0,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   387,   118,   119,   120,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   127,     0,     0,
       0,   128,   649,   129,     0,     0,     0,     0,     0,     0,
       0,   135,     0,   136,   137,   138,   139,   388,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,     0,     0,
     389,   151,     0,   152,   153,   154,   155,   156,   157,   158,
     390,   391,   392,   162,   393,   394,   165,   166,   167,   168,
     169,   170,   395,   172,   396,   174,   397,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,   189,   190,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   398,   399,   400,   215,   216,
     217,   218,   219,   437,     0,     0,     0,     3,     0,     0,
       0,     0,     0,     0,     0,   359,   360,   361,     8,   362,
     363,   364,   365,   366,   367,   368,   369,   370,    18,    19,
      20,    21,    22,    23,   371,   372,    26,   373,   374,    29,
     375,    31,    32,    33,     0,   376,   377,    36,   378,   379,
     380,    40,    41,    42,    43,    44,    45,    46,    47,    48,
     381,   382,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,     0,     0,    68,
       0,    69,    70,    71,   383,     0,     0,    75,    76,    77,
       0,     0,     0,    79,     0,     0,     0,     0,    81,    82,
      83,     0,     0,    86,    87,     0,     0,     0,     0,     0,
       0,    92,    93,    94,    95,     0,    96,     0,     0,     0,
     384,    98,    99,     0,     0,     0,     0,     0,     0,     0,
     102,   103,   104,     0,   106,   107,   108,     0,     0,     0,
       0,     0,     0,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   387,   118,   119,   120,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   127,     0,     0,     0,   128,
       0,   129,     0,     0,     0,     0,     0,     0,     0,   135,
       0,   136,   137,   138,   139,   388,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,     0,     0,   389,   151,
       0,   152,   153,   154,   155,   156,   157,   158,   390,   391,
     392,   162,   393,   394,   165,   166,   167,   168,   169,   170,
     395,   172,   396,   174,   397,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     0,   189,
     190,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   398,   399,   400,   215,   216,   217,   218,
     219,   473,     0,     3,     0,     0,     0,     0,     0,     0,
       0,   359,   360,   361,     8,   362,   363,   364,   365,   366,
     367,   368,   369,   370,    18,    19,    20,    21,    22,    23,
     371,   372,    26,   373,   374,    29,   375,    31,    32,    33,
       0,   376,   377,    36,   378,   379,   380,    40,    41,    42,
      43,    44,    45,    46,    47,    48,   381,   382,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,     0,     0,    68,     0,    69,    70,    71,
     383,     0,     0,    75,    76,    77,     0,     0,     0,    79,
       0,     0,     0,     0,    81,    82,    83,     0,     0,    86,
      87,     0,     0,     0,     0,     0,     0,    92,    93,    94,
      95,     0,    96,     0,     0,     0,   384,    98,    99,     0,
       0,     0,     0,     0,     0,     0,   102,   103,   104,     0,
     106,   107,   108,     0,     0,     0,     0,     0,     0,   112,
     113,     0,     0,     0,     0,   114,   115,   116,   387,   118,
     119,   120,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   127,     0,     0,     0,   128,     0,   129,     0,     0,
       0,     0,     0,     0,     0,   135,     0,   136,   137,   138,
     139,   388,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,     0,     0,   389,   151,     0,   152,   153,   154,
     155,   156,   157,   158,   390,   391,   392,   162,   393,   394,
     165,   166,   167,   168,   169,   170,   395,   172,   396,   174,
     397,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     0,   189,   190,     0,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   398,
     399,   400,   215,   216,   217,   218,   219,     3,     0,     0,
       0,     0,     0,     0,     0,   359,   360,   361,     8,   362,
     363,   364,   365,   366,   367,   368,   369,   370,    18,    19,
      20,    21,    22,    23,   371,   372,    26,   373,   374,    29,
     375,    31,    32,    33,     0,   376,   377,    36,   378,   379,
     380,    40,    41,    42,    43,    44,    45,    46,    47,    48,
     381,   382,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,     0,     0,    68,
       0,    69,    70,    71,   383,     0,     0,    75,    76,    77,
       0,     0,     0,    79,     0,     0,     0,     0,    81,    82,
      83,     0,     0,    86,    87,     0,     0,     0,     0,     0,
       0,    92,    93,    94,    95,     0,    96,     0,     0,     0,
     384,    98,    99,     0,     0,     0,     0,     0,     0,     0,
     102,   103,   104,     0,   106,   107,   108,   385,     0,     0,
     386,     0,     0,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   387,   118,   119,   120,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   127,     0,     0,     0,   128,
       0,   129,     0,     0,     0,     0,     0,     0,     0,   135,
       0,   136,   137,   138,   139,   388,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,     0,     0,   389,   151,
       0,   152,   153,   154,   155,   156,   157,   158,   390,   391,
     392,   162,   393,   394,   165,   166,   167,   168,   169,   170,
     395,   172,   396,   174,   397,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     0,   189,
     190,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   398,   399,   400,   215,   216,   217,   218,
     219,     3,     0,     0,     0,     0,     0,     0,     0,   359,
     360,   361,     8,   362,   363,   364,   365,   366,   367,   368,
     369,   370,    18,    19,    20,    21,    22,    23,   371,   372,
      26,   373,   374,    29,   375,    31,    32,    33,     0,   376,
     377,    36,   378,   379,   380,    40,    41,    42,    43,    44,
      45,    46,    47,    48,   381,   382,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,     0,     0,    68,     0,    69,    70,    71,   383,     0,
       0,    75,    76,    77,     0,     0,     0,    79,     0,     0,
       0,     0,    81,    82,    83,     0,     0,    86,    87,     0,
       0,     0,     0,     0,     0,    92,    93,    94,    95,     0,
      96,     0,     0,     0,   384,    98,    99,     0,     0,     0,
       0,     0,     0,     0,   102,   103,   104,     0,   106,   107,
     108,   456,     0,     0,   457,     0,     0,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   387,   118,   119,   120,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   127,
       0,     0,     0,   128,     0,   129,     0,     0,     0,     0,
       0,     0,     0,   135,     0,   136,   137,   138,   139,   388,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
       0,     0,   389,   151,     0,   152,   153,   154,   155,   156,
     157,   158,   390,   391,   392,   162,   393,   394,   165,   166,
     167,   168,   169,   170,   395,   172,   396,   174,   397,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,     0,   189,   190,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   398,   399,   400,
     215,   216,   217,   218,   219,     3,     0,     0,     0,     0,
       0,     0,     0,   359,   360,   361,     8,   362,   363,   364,
     365,   366,   367,   368,   369,   370,    18,    19,    20,    21,
      22,    23,   371,   372,    26,   373,   374,    29,   375,    31,
      32,    33,     0,   376,   377,    36,   378,   379,   380,    40,
      41,    42,    43,    44,    45,    46,    47,    48,   381,   382,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,     0,     0,    68,     0,    69,
      70,    71,   383,     0,     0,    75,    76,    77,     0,     0,
       0,    79,     0,     0,     0,     0,    81,    82,    83,     0,
       0,    86,    87,     0,     0,     0,     0,     0,     0,    92,
      93,    94,    95,     0,    96,     0,     0,     0,   384,    98,
      99,     0,     0,     0,     0,     0,     0,     0,   102,   103,
     104,     0,   106,   107,   108,     0,     0,     0,     0,     0,
       0,   112,   113,     0,     0,     0,     0,   114,   115,   116,
     387,   118,   119,   120,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   127,     0,     0,     0,   128,   588,   129,
       0,     0,     0,     0,     0,   589,     0,   135,     0,   136,
     137,   138,   139,   388,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,     0,     0,   389,   151,     0,   152,
     153,   154,   155,   156,   157,   158,   390,   391,   392,   162,
     393,   394,   165,   166,   167,   168,   169,   170,   395,   172,
     396,   174,   397,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,     0,   189,   190,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   398,   399,   400,   215,   216,   217,   218,   219,     3,
       0,     0,     0,     0,     0,     0,     0,   359,   360,   361,
       8,   362,   363,   364,   365,   366,   367,   368,   369,   370,
      18,    19,    20,    21,    22,    23,   371,   372,    26,   373,
     374,    29,   375,    31,    32,    33,     0,   376,   377,    36,
     378,   379,   380,    40,    41,    42,    43,    44,    45,    46,
      47,    48,   381,   382,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,     0,
       0,    68,     0,    69,    70,    71,   383,     0,     0,    75,
      76,    77,     0,     0,     0,    79,     0,     0,     0,     0,
      81,    82,    83,     0,     0,    86,    87,     0,     0,     0,
       0,     0,     0,    92,    93,    94,    95,     0,    96,     0,
       0,     0,   384,    98,    99,     0,     0,     0,     0,     0,
       0,     0,   102,   103,   104,     0,   106,   107,   108,     0,
       0,     0,     0,     0,     0,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   387,   118,   119,   120,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   127,     0,     0,
       0,   128,   679,   129,     0,     0,     0,     0,     0,   680,
       0,   135,     0,   136,   137,   138,   139,   388,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,     0,     0,
     389,   151,     0,   152,   153,   154,   155,   156,   157,   158,
     390,   391,   392,   162,   393,   394,   165,   166,   167,   168,
     169,   170,   395,   172,   396,   174,   397,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,   189,   190,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   398,   399,   400,   215,   216,
     217,   218,   219,     3,     0,     0,     0,     0,     0,     0,
       0,   359,   360,   361,     8,   362,   363,   364,   365,   459,
     367,   460,   461,   370,    18,    19,    20,    21,    22,    23,
     371,   462,    26,   373,   374,    29,   375,    31,    32,    33,
       0,   376,   377,    36,   378,   379,   380,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,     0,     0,    68,     0,    69,    70,    71,
     463,     0,     0,    75,    76,    77,     0,     0,     0,    79,
       0,     0,     0,     0,    81,    82,    83,     0,     0,    86,
      87,  1172,     0,     0,     0,     0,     0,    92,    93,    94,
      95,     0,    96,     0,     0,     0,   384,    98,    99,     0,
       0,     0,     0,     0,     0,     0,   102,   103,   104,     0,
     106,   107,   929,     0,     0,     0,     0,     0,     0,   112,
     113,     0,     0,     0,     0,   114,   115,   116,   387,   118,
     119,   120,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   127,     0,     0,     0,   128,     0,   129,   130,     0,
       0,     0,     0,     0,     0,   135,     0,   136,   137,   138,
     139,   388,   141,   142,   143,   144,   145,   146,     0,     0,
     930,   148,     0,     0,   389,   151,     0,   152,   153,   154,
     155,   156,   157,   158,   390,   160,   392,   162,   393,   394,
     165,   166,   167,   168,   169,   170,   395,   172,   396,   174,
     397,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     0,   189,   190,     0,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   398,
     399,   400,   215,   216,   217,   218,   219,     3,     0,     0,
       0,     0,     0,     0,     0,   359,   360,   361,     8,   362,
     363,   364,   365,   459,   367,   460,   461,   370,    18,    19,
      20,    21,    22,    23,   371,   462,    26,   373,   374,    29,
     375,    31,    32,    33,     0,   376,   377,    36,   378,   379,
     380,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,     0,     0,    68,
       0,    69,    70,    71,   463,     0,     0,    75,    76,    77,
       0,     0,     0,    79,     0,     0,     0,     0,    81,    82,
      83,     0,     0,    86,    87,     0,     0,     0,     0,     0,
       0,    92,    93,    94,    95,     0,    96,     0,     0,     0,
     384,    98,    99,     0,     0,     0,     0,     0,     0,     0,
     102,   103,   104,     0,   106,   107,   929,     0,     0,     0,
       0,     0,     0,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   387,   118,   119,   120,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   127,     0,     0,     0,   128,
       0,   129,   130,     0,     0,     0,     0,     0,     0,   135,
       0,   136,   137,   138,   139,   388,   141,   142,   143,   144,
     145,   146,     0,     0,   930,   148,     0,     0,   389,   151,
       0,   152,   153,   154,   155,   156,   157,   158,   390,   160,
     392,   162,   393,   394,   165,   166,   167,   168,   169,   170,
     395,   172,   396,   174,   397,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     0,   189,
     190,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   398,   399,   400,   215,   216,   217,   218,
     219,     3,     0,     0,     0,     0,     0,     0,     0,   359,
     360,   361,     8,   362,   363,   364,   365,   459,   367,   460,
     461,   370,    18,    19,    20,    21,    22,    23,   371,   462,
      26,   373,   374,    29,   375,    31,    32,    33,     0,   376,
     377,    36,   378,   379,   380,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,     0,     0,    68,     0,    69,    70,    71,   463,     0,
       0,    75,    76,    77,     0,     0,     0,    79,     0,     0,
       0,     0,    81,    82,    83,     0,     0,    86,    87,     0,
       0,     0,     0,     0,     0,    92,    93,    94,    95,     0,
      96,     0,     0,     0,   384,    98,    99,     0,     0,     0,
       0,     0,     0,     0,   102,   103,   104,     0,   106,   107,
     929,     0,     0,     0,     0,     0,     0,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   387,   118,   119,   120,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   127,
       0,     0,     0,   128,     0,   129,   130,     0,     0,     0,
       0,     0,     0,   135,     0,   136,   137,   138,   139,   388,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
       0,     0,   389,   151,     0,   152,   153,   154,   155,   156,
     157,   158,   390,   160,   392,   162,   393,   394,   165,   166,
     167,   168,   169,   170,   395,   172,   396,   174,   397,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,     0,   189,   190,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   398,   399,   400,
     215,   216,   217,   218,   219,     3,     0,     0,     0,     0,
       0,     0,     0,   359,   360,   361,     8,   362,   363,   364,
     365,   366,   367,   368,   369,   370,    18,    19,    20,    21,
      22,    23,   371,   372,    26,   373,   374,    29,   375,    31,
      32,    33,     0,   376,   377,    36,   378,   379,   380,    40,
      41,    42,    43,    44,    45,    46,    47,    48,   381,   382,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,     0,     0,    68,     0,    69,
      70,    71,   383,     0,     0,    75,    76,    77,     0,     0,
       0,    79,     0,     0,     0,     0,    81,    82,    83,     0,
       0,    86,    87,     0,     0,     0,     0,     0,     0,    92,
      93,    94,    95,     0,    96,     0,     0,     0,   384,    98,
      99,     0,     0,     0,     0,     0,     0,     0,   102,   103,
     104,     0,   106,   107,   108,     0,     0,     0,     0,     0,
       0,   112,   113,     0,     0,     0,     0,   114,   115,   116,
     387,   118,   119,   120,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   127,     0,     0,     0,   128,     0,   129,
       0,     0,     0,     0,     0,     0,     0,   135,     0,   136,
     137,   138,   139,   388,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,     0,     0,   389,   151,     0,   152,
     153,   154,   155,   156,   157,   158,   390,   391,   392,   162,
     393,   394,   165,   166,   167,   168,   169,   170,   395,   172,
     396,   174,   397,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,     0,   189,   190,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   398,   399,   400,   215,   216,   217,   218,   219
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        13,   660,   686,   840,   416,   546,   665,   122,   350,   862,
     133,   353,    25,   728,   970,   427,   550,   551,   552,   553,
     768,   769,   504,   665,    74,   895,    20,   784,  1109,   750,
     442,   443,   958,    21,   526,   529,   111,   531,   532,    34,
     534,    20,   536,   109,    66,    92,    94,     7,  1088,   138,
     544,   545,   105,   768,   769,    92,  1242,    94,    20,    72,
     142,    74,   105,    94,   105,    39,    40,    41,    42,    43,
      44,   105,   142,    94,    91,    88,    71,    47,    52,   105,
     492,   493,   494,   116,    58,   105,    20,   105,    92,    94,
     732,   138,   734,   132,   142,    69,    70,   110,   105,    73,
     163,   161,    76,    77,   819,   142,   448,  1120,  1121,   122,
      94,   124,   105,   127,   108,    98,   176,   130,     8,     9,
     126,   195,    59,   216,   217,   218,   120,   111,   111,   133,
     204,   212,   111,   196,   138,   109,   110,   111,   181,   481,
     482,   182,   484,   485,   486,   487,   151,   180,   490,     4,
     144,   185,   148,     8,   148,   125,   195,   151,     4,   185,
     177,   181,     8,   505,   245,   240,   825,   185,   105,     8,
     293,   185,   261,   515,   516,   182,   155,   230,    98,   261,
      19,   155,    29,     8,     9,   191,   181,  1227,   181,    92,
     212,   261,  1045,    92,   269,   270,  1033,   272,   273,    39,
      40,    41,    42,    43,    44,   746,   747,   891,  1078,   169,
     622,   101,    52,   261,   261,   874,   247,   248,  1088,   181,
     208,   155,  1408,   245,   261,    29,   247,   248,  1414,   119,
     872,   121,  1418,  1159,    92,   577,  1249,    77,   259,   960,
    1196,   215,   734,   300,   656,  1326,   994,   741,   298,   306,
     143,   301,     8,   266,  1011,   105,    20,   251,   148,   236,
     237,   232,   152,    19,   119,   239,   121,   160,    92,   109,
     110,   111,   133,   119,   129,   121,   101,   151,   168,   994,
     119,   258,   121,   129,   791,   298,   793,   148,   301,   355,
     148,   130,   358,   148,   119,   105,   121,   116,   151,   189,
     105,   943,   148,   277,   278,   279,   280,   195,   423,   148,
     213,   214,   232,   126,   213,   214,   204,   207,   142,   385,
     240,   105,   105,   148,   439,   228,   105,   152,   105,   228,
     445,   181,   105,   253,   148,   255,   402,   403,   105,   405,
     176,   354,    50,   168,   108,   265,   105,   176,   268,    57,
       8,     9,    60,    61,   190,   140,   120,  1227,   216,   217,
      68,   190,   181,   119,   189,   121,    62,    63,    92,   257,
     436,   181,   438,   386,   130,   263,   181,   884,   191,   886,
     144,   723,   207,   271,   148,   170,   148,   151,   730,  1345,
     456,    38,   148,   148,   407,    94,   151,   181,   181,   239,
     413,    48,   181,   188,   181,   471,   419,   153,   181,   171,
     423,   477,   111,   143,   181,   956,   828,   829,   142,   151,
     116,   833,   181,    34,   170,   959,   439,   968,    39,   104,
     160,   444,   445,   446,   447,   917,  1184,   277,   278,   279,
     280,   454,   115,   101,   457,   568,   569,   193,   123,   204,
     153,  1304,   151,   408,   467,   867,   164,   412,   166,    64,
      65,   119,    67,   121,   132,   257,    77,   170,   141,  1184,
     262,    93,   180,    64,    65,   220,   489,   145,   491,   821,
     225,   154,   104,     8,     9,   827,   116,    94,   816,    94,
     148,    98,   114,   104,   152,   193,   155,   195,   206,   565,
     240,   123,   830,    94,   570,   148,   204,   257,   850,   133,
     168,   116,   578,   263,   138,   188,  1358,  1359,   584,   585,
     116,   271,   864,   865,  1183,   591,   868,   116,   870,   269,
     270,   189,   272,   273,  1371,   148,  1284,   652,   151,  1381,
     655,  1225,    39,    40,    41,  1387,  1230,    44,   890,   207,
      60,   148,   571,   164,   151,   574,   163,   576,   151,   901,
     902,   903,   116,   905,   906,   907,   908,   909,   910,  1284,
     912,   913,   133,   227,  1288,   229,   101,   138,   920,  1293,
      51,   238,   151,    54,   241,   651,   599,  1335,    94,   220,
     238,   222,    98,   241,   119,   148,   121,   939,   148,   941,
     942,   278,   279,   280,   617,   220,   227,   222,   229,   210,
    1144,   186,   187,   124,   125,   151,   682,  1151,  1152,   148,
    1335,   220,  1163,   148,   116,   232,   116,   152,  1040,   278,
    1314,    64,    65,   240,  1318,   242,   243,   244,   278,   652,
     278,   983,   655,   168,     0,   252,   253,   185,   255,   124,
     125,   547,   548,   260,   554,   555,   669,   163,   265,   266,
     267,   268,   410,   411,   189,   556,   557,   770,   771,  1286,
    1287,   185,   685,   162,    90,    74,   250,   194,  1362,   745,
    1022,    99,   207,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,  1352,   100,  1037,   149,   151,   148,   148,
     148,   181,   181,    39,  1116,    39,    20,   147,  1050,   722,
     278,   116,   148,  1055,  1056,   728,  1058,   148,   267,   785,
     267,  1063,   116,   116,   151,   151,   232,   151,   151,  1263,
    1264,   151,    25,    15,   240,   181,   242,   243,   244,   181,
     208,    20,   181,   226,    38,   164,   116,   253,   165,   255,
     165,   105,   226,    92,   260,   768,   769,   770,   771,   265,
     266,   267,   268,    92,   128,    92,   148,   181,   178,   181,
    1112,   178,   136,   137,   178,   139,   178,   178,   791,   151,
     793,  1123,   146,    20,   105,   105,   150,   155,   152,   155,
     123,   128,  1204,   157,  1136,    20,   281,  1139,   181,  1141,
    1334,   178,   181,   181,    94,    34,   819,    94,   138,   173,
     128,   178,   181,   105,    92,   138,   181,   178,   181,   178,
     178,   232,   220,   178,   165,   185,   142,  1169,   116,   251,
     116,   116,   116,   197,   198,   199,   200,   201,   202,   268,
     249,  1253,    98,   256,   179,   148,   178,   178,   128,   138,
     178,    92,   178,   178,   192,   138,   178,   148,   128,   155,
     128,    94,   270,   116,   116,   142,   138,   148,   271,   245,
    1212,   884,  1214,   886,   271,    25,   178,    20,  1220,   148,
     116,   234,   116,    77,   105,   105,   151,   151,   142,   246,
     271,   142,  1234,  1235,  1236,  1237,  1238,   246,  1240,   142,
      53,   140,   178,   138,   178,    92,   181,    20,   181,   140,
     181,    20,   925,   105,   181,   928,   165,   116,  1260,   181,
     271,   138,   185,   936,   142,   938,   116,    67,   128,     6,
     185,   997,   232,   181,   181,  1277,   180,  1279,   104,   104,
     142,   181,   180,  1009,   116,   264,    92,    20,   178,   181,
     178,    20,   122,   151,   178,    94,   178,    92,  1300,   178,
    1302,    20,  1374,   178,    94,    65,   180,   228,   228,   228,
     228,   116,  1038,   104,   116,   191,   180,    91,   191,   191,
     177,   994,   191,   116,   148,   181,   621,   116,   254,  1018,
     503,  1004,   820,   220,   503,   430,   421,   254,   426,  1353,
     223,   802,   987,  1185,  1070,   507,   879,   928,  1053,  1218,
    1065,  1353,   223,  1113,  1125,   265,   226,  1123,  1084,   227,
     467,  1120,   920,  1047,   527,   549,   995,  1369,   528,  1078,
     686,  1387,  1381,   771,  1047,   793,  1017,   819,  1106,  1110,
    1053,   286,   746,   956,   290,   968,  1163,   747,   960,  1298,
    1195,  1064,  1394,  1158,    -1,   455,   957,    -1,    -1,   455,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1085,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1106,    -1,    -1,  1109,    -1,    -1,    -1,
    1113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1172,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1215,  1216,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1226,    -1,    -1,    -1,    -1,  1231,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1278,    -1,    -1,    -1,    -1,
      -1,  1284,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1315,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1326,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1335,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1365,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1377,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,  1410,    20,    -1,
      -1,    -1,  1415,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    -1,
      92,    93,    94,    95,    96,    97,    98,    99,   100,    -1,
      -1,   103,   104,    -1,    -1,    -1,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,    -1,   120,    -1,
     122,   123,   124,   125,    -1,   127,    -1,    -1,    -1,   131,
     132,   133,   134,   135,    -1,    -1,    -1,    -1,    -1,   141,
     142,   143,   144,   145,   146,   147,    -1,    -1,    -1,   151,
     152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,   161,
     162,   163,   164,   165,   166,   167,   168,    -1,   170,   171,
      -1,    -1,   174,   175,   176,    -1,    -1,    -1,   180,    -1,
     182,   183,   184,    -1,   186,   187,   188,    -1,   190,    -1,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,    -1,    -1,   205,   206,   207,    -1,   209,   210,    -1,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,    -1,   250,   251,
      -1,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
      -1,   120,    -1,   122,   123,   124,   125,    -1,   127,    -1,
      -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,    -1,
      -1,    -1,   141,   142,   143,   144,   145,   146,   147,    -1,
      -1,    -1,   151,   152,   153,   154,   155,    -1,    -1,    -1,
      -1,   160,   161,   162,   163,   164,   165,   166,   167,   168,
      -1,   170,   171,    -1,    -1,   174,   175,   176,    -1,    -1,
      -1,   180,   181,   182,   183,   184,    -1,   186,   187,   188,
      -1,   190,    -1,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,    -1,    -1,   205,   206,   207,    -1,
     209,   210,    -1,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
      -1,   250,   251,    -1,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    92,    93,    94,    95,    96,
      97,    98,    99,   100,    -1,    -1,   103,   104,    -1,    -1,
      -1,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,    -1,   120,    -1,   122,   123,   124,   125,    -1,
     127,    -1,    -1,    -1,   131,   132,   133,   134,   135,    -1,
      -1,    -1,    -1,    -1,   141,   142,   143,   144,   145,   146,
     147,    -1,    -1,    -1,   151,   152,   153,   154,   155,    -1,
      -1,    -1,    -1,   160,   161,   162,   163,   164,   165,   166,
     167,   168,    -1,   170,   171,    -1,    -1,   174,   175,   176,
      -1,   178,    -1,   180,    -1,   182,   183,   184,    -1,   186,
     187,   188,    -1,   190,    -1,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,    -1,    -1,   205,   206,
     207,    -1,   209,   210,    -1,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,    -1,   250,   251,    -1,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    -1,    -1,   103,   104,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,    -1,   120,    -1,   122,   123,   124,
     125,    -1,   127,    -1,    -1,    -1,   131,   132,   133,   134,
     135,    -1,    -1,    -1,    -1,    -1,   141,   142,   143,   144,
     145,   146,   147,    -1,    -1,    -1,   151,   152,   153,   154,
     155,    -1,    -1,    -1,    -1,   160,   161,   162,   163,   164,
     165,   166,   167,   168,    -1,   170,   171,    -1,    -1,   174,
     175,   176,    -1,    -1,    -1,   180,   181,   182,   183,   184,
      -1,   186,   187,   188,    -1,   190,    -1,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,    -1,    -1,
     205,   206,   207,    -1,   209,   210,    -1,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,   250,   251,    -1,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    -1,    -1,
     103,   104,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,    -1,   120,    -1,   122,
     123,   124,   125,    -1,   127,    -1,    -1,    -1,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,    -1,   141,   142,
     143,   144,   145,   146,   147,    -1,    -1,    -1,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,   170,   171,    -1,
      -1,   174,   175,   176,    -1,   178,    -1,   180,    -1,   182,
     183,   184,    -1,   186,   187,   188,    -1,   190,    -1,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
      -1,    -1,   205,   206,   207,    -1,   209,   210,    -1,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,    -1,   250,   251,    -1,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      -1,    92,    93,    94,    95,    96,    97,    98,    99,   100,
      -1,    -1,   103,   104,    -1,    -1,    -1,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,    -1,   120,
      -1,   122,   123,   124,   125,    -1,   127,    -1,    -1,    -1,
     131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,    -1,
     141,   142,   143,   144,   145,   146,   147,    -1,    -1,    -1,
     151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,   170,
     171,    -1,    -1,   174,   175,   176,    -1,   178,    -1,   180,
      -1,   182,   183,   184,    -1,   186,   187,   188,    -1,   190,
      -1,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,    -1,    -1,   205,   206,   207,    -1,   209,   210,
      -1,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,    -1,   250,
     251,    -1,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
      -1,   120,    -1,   122,   123,   124,   125,    -1,   127,    -1,
      -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,    -1,
      -1,    -1,   141,   142,   143,   144,   145,   146,   147,    -1,
      -1,    -1,   151,   152,   153,   154,   155,    -1,    -1,    -1,
      -1,   160,   161,   162,   163,   164,   165,   166,   167,   168,
      -1,   170,   171,    -1,    -1,   174,   175,   176,    -1,   178,
      -1,   180,    -1,   182,   183,   184,    -1,   186,   187,   188,
      -1,   190,    -1,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,    -1,    -1,   205,   206,   207,    -1,
     209,   210,    -1,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
      -1,   250,   251,    -1,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    92,    93,    94,    95,    96,
      97,    98,    99,   100,    -1,    -1,   103,   104,    -1,    -1,
      -1,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,    -1,   120,    -1,   122,   123,   124,   125,    -1,
     127,    -1,    -1,    -1,   131,   132,   133,   134,   135,    -1,
      -1,    -1,    -1,    -1,   141,   142,   143,   144,   145,   146,
     147,    -1,    -1,    -1,   151,   152,   153,   154,   155,    -1,
      -1,    -1,    -1,   160,   161,   162,   163,   164,   165,   166,
     167,   168,    -1,   170,   171,    -1,    -1,   174,   175,   176,
      -1,   178,    -1,   180,    -1,   182,   183,   184,    -1,   186,
     187,   188,    -1,   190,    -1,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,    -1,    -1,   205,   206,
     207,    -1,   209,   210,    -1,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,    -1,   250,   251,    -1,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    -1,    -1,   103,   104,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,    -1,   120,    -1,   122,   123,   124,
     125,    -1,   127,    -1,    -1,    -1,   131,   132,   133,   134,
     135,    -1,    -1,    -1,    -1,    -1,   141,   142,   143,   144,
     145,   146,   147,    -1,    -1,    -1,   151,   152,   153,   154,
     155,    -1,    -1,    -1,    -1,   160,   161,   162,   163,   164,
     165,   166,   167,   168,    -1,   170,   171,    -1,    -1,   174,
     175,   176,    -1,   178,    -1,   180,    -1,   182,   183,   184,
      -1,   186,   187,   188,    -1,   190,    -1,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,    -1,    -1,
     205,   206,   207,    -1,   209,   210,    -1,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,   250,   251,    -1,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    -1,    -1,
     103,   104,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,    -1,   120,    -1,   122,
     123,   124,   125,    -1,   127,    -1,    -1,    -1,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,    -1,   141,   142,
     143,   144,   145,   146,   147,    -1,    -1,    -1,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,   170,   171,    -1,
      -1,   174,   175,   176,    -1,   178,    -1,   180,    -1,   182,
     183,   184,    -1,   186,   187,   188,    -1,   190,    -1,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
      -1,    -1,   205,   206,   207,    -1,   209,   210,    -1,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,    -1,   250,   251,    -1,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      -1,    92,    93,    94,    95,    96,    97,    98,    99,   100,
      -1,    -1,   103,   104,    -1,    -1,    -1,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,    -1,   120,
      -1,   122,   123,   124,   125,    -1,   127,    -1,    -1,    -1,
     131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,    -1,
     141,   142,   143,   144,   145,   146,   147,    -1,    -1,    -1,
     151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,   170,
     171,    -1,    -1,   174,   175,   176,    -1,    -1,    -1,   180,
      -1,   182,   183,   184,    -1,   186,   187,   188,    -1,   190,
      -1,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,    -1,    -1,   205,   206,   207,    -1,   209,   210,
      -1,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,    -1,   250,
     251,    -1,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
      -1,   120,    -1,   122,   123,   124,   125,    -1,   127,    -1,
      -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,    -1,
      -1,    -1,   141,   142,   143,   144,   145,   146,   147,    -1,
      -1,    -1,   151,   152,   153,   154,   155,    -1,    -1,    -1,
      -1,   160,   161,   162,   163,   164,   165,   166,   167,   168,
      -1,   170,   171,    -1,    -1,   174,   175,   176,    -1,    -1,
      -1,   180,    -1,   182,   183,   184,    -1,   186,   187,   188,
      -1,   190,    -1,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,    -1,    -1,   205,   206,   207,    -1,
     209,   210,    -1,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
      -1,   250,   251,    -1,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    92,    93,    94,    95,    96,
      97,    98,    99,   100,    -1,    -1,   103,   104,    -1,    -1,
      -1,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,    -1,   120,    -1,   122,   123,   124,   125,    -1,
     127,    -1,    -1,    -1,   131,   132,   133,   134,   135,    -1,
      -1,    -1,    -1,    -1,   141,   142,   143,   144,   145,   146,
     147,    -1,    -1,    -1,   151,   152,   153,   154,   155,    -1,
      -1,    -1,    -1,   160,   161,   162,   163,   164,   165,   166,
     167,   168,    -1,   170,   171,    -1,    -1,   174,   175,   176,
      -1,    -1,    -1,   180,    -1,   182,   183,   184,    -1,   186,
     187,   188,    -1,   190,    -1,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,    -1,    -1,   205,   206,
     207,    -1,   209,   210,    -1,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,    -1,   250,   251,    -1,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    -1,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    -1,    -1,   103,   104,
      -1,    -1,    -1,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,    -1,   120,    -1,   122,   123,   124,
     125,    -1,   127,    -1,    -1,    -1,   131,   132,   133,   134,
     135,    -1,    -1,    -1,    -1,    -1,   141,   142,   143,   144,
     145,   146,   147,    -1,    -1,    -1,   151,   152,   153,   154,
     155,    -1,    -1,    -1,    -1,   160,   161,   162,   163,   164,
     165,   166,   167,   168,    -1,   170,   171,    -1,    -1,   174,
     175,   176,    -1,    -1,    -1,   180,    -1,   182,   183,   184,
      -1,   186,   187,   188,    -1,   190,    -1,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,    -1,    -1,
     205,   206,   207,    -1,   209,   210,    -1,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,   250,   251,    -1,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    -1,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    -1,    -1,
     103,   104,    -1,    -1,    -1,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,    -1,   120,    -1,   122,
     123,   124,   125,    -1,   127,    -1,    -1,    -1,   131,   132,
     133,   134,   135,    -1,    -1,    -1,    -1,    -1,   141,   142,
     143,   144,   145,   146,   147,    -1,    -1,    -1,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,   160,   161,   162,
     163,   164,   165,   166,   167,   168,    -1,   170,   171,    -1,
      -1,   174,   175,   176,    -1,    -1,    -1,   180,    -1,   182,
     183,   184,    -1,   186,   187,   188,    -1,   190,    -1,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
      -1,    -1,   205,   206,   207,    -1,   209,   210,    -1,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,    -1,   250,   251,    -1,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      -1,    92,    93,    94,    95,    96,    97,    98,    99,   100,
      -1,    -1,   103,   104,    -1,    -1,    -1,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,    -1,   120,
      -1,   122,   123,   124,   125,    -1,   127,    -1,    -1,    -1,
     131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,    -1,
     141,   142,   143,   144,   145,   146,   147,    -1,    -1,    -1,
     151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,   164,   165,   166,   167,   168,    -1,   170,
     171,    -1,    -1,   174,   175,   176,    -1,    -1,    -1,   180,
      -1,   182,   183,   184,    -1,   186,   187,   188,    -1,   190,
      -1,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,    -1,    -1,   205,   206,   207,    -1,   209,   210,
      -1,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,    -1,   250,
     251,    -1,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,   100,    -1,    -1,   103,   104,    -1,    -1,    -1,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
      -1,   120,    -1,   122,   123,   124,   125,    -1,   127,    -1,
      -1,    -1,   131,   132,   133,   134,   135,    -1,    -1,    -1,
      -1,    -1,   141,   142,   143,   144,   145,   146,   147,    -1,
      -1,    -1,   151,   152,    -1,   154,   155,    -1,    -1,    -1,
      -1,   160,   161,   162,   163,   164,   165,   166,   167,   168,
      -1,    -1,    -1,    -1,    -1,   174,   175,   176,    -1,    -1,
      -1,   180,    -1,   182,   183,   184,    -1,    -1,    -1,   188,
      -1,   190,    -1,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,    -1,    -1,   205,   206,   207,    -1,
     209,   210,    -1,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
      -1,   250,   251,    -1,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    -1,    -1,    90,    -1,    92,    93,    94,    95,    -1,
      -1,    98,    99,   100,    -1,    -1,    -1,   104,    -1,    -1,
      -1,    -1,   109,   110,   111,    -1,    -1,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,   122,   123,   124,   125,    -1,
     127,    -1,    -1,    -1,   131,   132,   133,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   141,   142,   143,    -1,   145,   146,
     147,    -1,    -1,    -1,    -1,    -1,    -1,   154,   155,    -1,
      -1,    -1,    -1,   160,   161,   162,   163,   164,   165,   166,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,
      -1,    -1,    -1,   180,    -1,   182,   183,    -1,    -1,    -1,
      -1,   188,    -1,   190,    -1,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,    -1,    -1,   205,   206,
      -1,    -1,   209,   210,    -1,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,    -1,   250,   251,    -1,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    -1,    -1,    90,    -1,    92,    93,    94,
      95,    -1,    -1,    98,    99,   100,    -1,    -1,    -1,   104,
      -1,    -1,    -1,    -1,   109,   110,   111,    -1,    -1,   114,
     115,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,   124,
     125,    -1,   127,    -1,    -1,    -1,   131,   132,   133,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   141,   142,   143,    -1,
     145,   146,   147,    -1,    -1,    -1,    -1,    -1,    -1,   154,
     155,    -1,    -1,    -1,    -1,   160,   161,   162,   163,   164,
     165,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   176,    -1,    -1,    -1,   180,    -1,   182,    -1,    -1,
      -1,    -1,    -1,   188,    -1,   190,    -1,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,    -1,    -1,
     205,   206,    -1,    -1,   209,   210,    -1,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,   250,   251,    -1,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    14,    -1,    -1,
      -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    -1,    -1,    90,    -1,    92,    93,    94,    95,    -1,
      -1,    98,    99,   100,    -1,    -1,    -1,   104,    -1,    -1,
      -1,    -1,   109,   110,   111,    -1,    -1,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,   122,   123,   124,   125,    -1,
     127,    -1,    -1,    -1,   131,   132,   133,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   141,   142,   143,    -1,   145,   146,
     147,   148,    -1,    -1,   151,    -1,    -1,   154,   155,    -1,
      -1,    -1,    -1,   160,   161,   162,   163,   164,   165,   166,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,
      -1,    -1,    -1,   180,    -1,   182,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   190,    -1,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,    -1,    -1,   205,   206,
      -1,    -1,   209,   210,    -1,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,    -1,   250,   251,    -1,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,    14,    -1,    -1,    -1,    18,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    -1,
      -1,    90,    -1,    92,    93,    94,    95,    -1,    -1,    98,
      99,   100,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,
     109,   110,   111,    -1,    -1,   114,   115,    -1,    -1,    -1,
      -1,    -1,    -1,   122,   123,   124,   125,    -1,   127,    -1,
      -1,    -1,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   141,   142,   143,    -1,   145,   146,   147,    -1,
      -1,    -1,    -1,    -1,    -1,   154,   155,    -1,    -1,    -1,
      -1,   160,   161,   162,   163,   164,   165,   166,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   190,    -1,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,    -1,    -1,   205,   206,    -1,    -1,
     209,   210,    -1,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
      -1,   250,   251,    -1,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,    14,    -1,    -1,    -1,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,    -1,    90,
      -1,    92,    93,    94,    95,    -1,    -1,    98,    99,   100,
      -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,   109,   110,
     111,    -1,    -1,   114,   115,    -1,    -1,    -1,    -1,    -1,
      -1,   122,   123,   124,   125,    -1,   127,    -1,    -1,    -1,
     131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     141,   142,   143,    -1,   145,   146,   147,    -1,    -1,    -1,
      -1,    -1,    -1,   154,   155,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   176,    -1,    -1,    -1,   180,
      -1,   182,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,
      -1,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,    -1,    -1,   205,   206,    -1,    -1,   209,   210,
      -1,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,    -1,   250,
     251,    -1,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,    16,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    -1,    -1,    90,    -1,    92,    93,    94,
      95,    -1,    -1,    98,    99,   100,    -1,    -1,    -1,   104,
      -1,    -1,    -1,    -1,   109,   110,   111,    -1,    -1,   114,
     115,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,   124,
     125,    -1,   127,    -1,    -1,    -1,   131,   132,   133,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   141,   142,   143,    -1,
     145,   146,   147,    -1,    -1,    -1,    -1,    -1,    -1,   154,
     155,    -1,    -1,    -1,    -1,   160,   161,   162,   163,   164,
     165,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   176,    -1,    -1,    -1,   180,    -1,   182,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   190,    -1,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,    -1,    -1,
     205,   206,    -1,    -1,   209,   210,    -1,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,   250,   251,    -1,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,    -1,    90,
      -1,    92,    93,    94,    95,    -1,    -1,    98,    99,   100,
      -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,   109,   110,
     111,    -1,    -1,   114,   115,    -1,    -1,    -1,    -1,    -1,
      -1,   122,   123,   124,   125,    -1,   127,    -1,    -1,    -1,
     131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     141,   142,   143,    -1,   145,   146,   147,   148,    -1,    -1,
     151,    -1,    -1,   154,   155,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   176,    -1,    -1,    -1,   180,
      -1,   182,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,
      -1,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,    -1,    -1,   205,   206,    -1,    -1,   209,   210,
      -1,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,    -1,   250,
     251,    -1,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    -1,    -1,    90,    -1,    92,    93,    94,    95,    -1,
      -1,    98,    99,   100,    -1,    -1,    -1,   104,    -1,    -1,
      -1,    -1,   109,   110,   111,    -1,    -1,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,   122,   123,   124,   125,    -1,
     127,    -1,    -1,    -1,   131,   132,   133,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   141,   142,   143,    -1,   145,   146,
     147,   148,    -1,    -1,   151,    -1,    -1,   154,   155,    -1,
      -1,    -1,    -1,   160,   161,   162,   163,   164,   165,   166,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,
      -1,    -1,    -1,   180,    -1,   182,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   190,    -1,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,    -1,    -1,   205,   206,
      -1,    -1,   209,   210,    -1,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,    -1,   250,   251,    -1,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    -1,    -1,    90,    -1,    92,
      93,    94,    95,    -1,    -1,    98,    99,   100,    -1,    -1,
      -1,   104,    -1,    -1,    -1,    -1,   109,   110,   111,    -1,
      -1,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,
     123,   124,   125,    -1,   127,    -1,    -1,    -1,   131,   132,
     133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,   142,
     143,    -1,   145,   146,   147,    -1,    -1,    -1,    -1,    -1,
      -1,   154,   155,    -1,    -1,    -1,    -1,   160,   161,   162,
     163,   164,   165,   166,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   176,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,    -1,    -1,   188,    -1,   190,    -1,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
      -1,    -1,   205,   206,    -1,    -1,   209,   210,    -1,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,    -1,   250,   251,    -1,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    -1,
      -1,    90,    -1,    92,    93,    94,    95,    -1,    -1,    98,
      99,   100,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,
     109,   110,   111,    -1,    -1,   114,   115,    -1,    -1,    -1,
      -1,    -1,    -1,   122,   123,   124,   125,    -1,   127,    -1,
      -1,    -1,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   141,   142,   143,    -1,   145,   146,   147,    -1,
      -1,    -1,    -1,    -1,    -1,   154,   155,    -1,    -1,    -1,
      -1,   160,   161,   162,   163,   164,   165,   166,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,    -1,    -1,   188,
      -1,   190,    -1,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,    -1,    -1,   205,   206,    -1,    -1,
     209,   210,    -1,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
      -1,   250,   251,    -1,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    -1,    -1,    90,    -1,    92,    93,    94,
      95,    -1,    -1,    98,    99,   100,    -1,    -1,    -1,   104,
      -1,    -1,    -1,    -1,   109,   110,   111,    -1,    -1,   114,
     115,   116,    -1,    -1,    -1,    -1,    -1,   122,   123,   124,
     125,    -1,   127,    -1,    -1,    -1,   131,   132,   133,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   141,   142,   143,    -1,
     145,   146,   147,    -1,    -1,    -1,    -1,    -1,    -1,   154,
     155,    -1,    -1,    -1,    -1,   160,   161,   162,   163,   164,
     165,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   176,    -1,    -1,    -1,   180,    -1,   182,   183,    -1,
      -1,    -1,    -1,    -1,    -1,   190,    -1,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,    -1,    -1,
     205,   206,    -1,    -1,   209,   210,    -1,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,   250,   251,    -1,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    -1,    -1,    90,
      -1,    92,    93,    94,    95,    -1,    -1,    98,    99,   100,
      -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,   109,   110,
     111,    -1,    -1,   114,   115,    -1,    -1,    -1,    -1,    -1,
      -1,   122,   123,   124,   125,    -1,   127,    -1,    -1,    -1,
     131,   132,   133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     141,   142,   143,    -1,   145,   146,   147,    -1,    -1,    -1,
      -1,    -1,    -1,   154,   155,    -1,    -1,    -1,    -1,   160,
     161,   162,   163,   164,   165,   166,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   176,    -1,    -1,    -1,   180,
      -1,   182,   183,    -1,    -1,    -1,    -1,    -1,    -1,   190,
      -1,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,    -1,    -1,   205,   206,    -1,    -1,   209,   210,
      -1,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,    -1,   250,
     251,    -1,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    -1,    -1,    90,    -1,    92,    93,    94,    95,    -1,
      -1,    98,    99,   100,    -1,    -1,    -1,   104,    -1,    -1,
      -1,    -1,   109,   110,   111,    -1,    -1,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,   122,   123,   124,   125,    -1,
     127,    -1,    -1,    -1,   131,   132,   133,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   141,   142,   143,    -1,   145,   146,
     147,    -1,    -1,    -1,    -1,    -1,    -1,   154,   155,    -1,
      -1,    -1,    -1,   160,   161,   162,   163,   164,   165,   166,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,
      -1,    -1,    -1,   180,    -1,   182,   183,    -1,    -1,    -1,
      -1,    -1,    -1,   190,    -1,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,    -1,    -1,   205,   206,
      -1,    -1,   209,   210,    -1,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,    -1,   250,   251,    -1,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    -1,    -1,    90,    -1,    92,
      93,    94,    95,    -1,    -1,    98,    99,   100,    -1,    -1,
      -1,   104,    -1,    -1,    -1,    -1,   109,   110,   111,    -1,
      -1,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,
     123,   124,   125,    -1,   127,    -1,    -1,    -1,   131,   132,
     133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,   142,
     143,    -1,   145,   146,   147,    -1,    -1,    -1,    -1,    -1,
      -1,   154,   155,    -1,    -1,    -1,    -1,   160,   161,   162,
     163,   164,   165,   166,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   176,    -1,    -1,    -1,   180,    -1,   182,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
      -1,    -1,   205,   206,    -1,    -1,   209,   210,    -1,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,    -1,   250,   251,    -1,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,    10,    17,    18,    20,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   103,   104,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   120,   122,   123,   124,   125,   127,   131,   132,   133,
     134,   135,   141,   142,   143,   144,   145,   146,   147,   151,
     152,   153,   154,   155,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   170,   171,   174,   175,   176,   180,   182,
     183,   184,   186,   187,   188,   190,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   205,   206,   207,
     209,   210,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   250,
     251,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   328,   329,   334,   336,
     343,   345,   350,   351,   352,   353,   354,   355,   363,   364,
     366,   367,   368,   373,   375,   377,   378,   379,   384,   405,
     408,   411,   412,   413,   414,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   461,   462,   463,   477,   478,
     480,   481,   482,   483,   484,   485,   486,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   505,   506,   507,
     508,   509,   510,   511,   514,   520,   521,   522,   148,   346,
     232,    29,    29,   151,    92,   148,   216,   217,   151,    26,
      27,    28,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    45,    46,    48,    49,    51,    56,    57,    59,    60,
      61,    71,    72,    95,   131,   148,   151,   163,   196,   209,
     219,   220,   221,   223,   224,   231,   233,   235,   274,   275,
     276,   520,   148,   148,   151,   148,   151,    39,    40,    41,
      42,    43,    44,    52,    58,    69,    70,    73,    76,    77,
     109,   110,   111,   155,   215,   239,   277,   278,   279,   280,
     335,   337,   338,   339,   356,   357,   151,    14,   148,   151,
     519,   520,    51,    54,   116,   155,   116,   116,   148,    62,
      63,   116,   370,    60,   151,   151,   148,   151,   520,    34,
      36,    37,    46,    95,   445,   520,   520,   116,   181,   364,
     520,   148,   519,    16,   520,   520,   437,   148,    21,   208,
     210,   220,   222,   151,   220,   222,   220,   220,   225,   116,
     148,   116,   278,   278,   278,   299,     0,   301,   302,    38,
      48,   304,   363,   185,   185,   105,   185,   365,    50,    57,
      60,    61,    68,   164,   166,   180,   206,   369,   374,   375,
     376,   393,   394,   398,   380,   381,   520,   162,    90,   128,
     136,   137,   139,   146,   150,   152,   157,   173,   197,   198,
     199,   200,   201,   202,   429,   430,   250,   153,   170,   193,
     115,   141,   154,   188,   195,   204,   132,   145,    74,   194,
      99,   100,   153,   170,   428,   148,   434,   437,   186,   187,
     149,   449,   450,   445,   449,   445,   449,   151,   347,   367,
     367,   503,   520,   364,   148,   148,   364,   364,   181,   188,
     520,   148,   364,   364,   181,   364,   181,   520,   357,    39,
     358,   356,   356,   357,   520,   176,   190,   163,   196,    20,
     518,   161,   176,   176,   190,   520,   147,   116,   333,    34,
      39,    77,   104,   164,   519,   216,   217,   218,    98,   232,
     240,   253,   255,   265,   268,   534,   535,   536,   537,   538,
     541,   546,   547,   338,   518,   339,   364,   364,    20,   181,
     519,   148,   155,   518,   111,   155,   327,   518,   406,   407,
     520,   519,   520,   385,   387,   520,   367,   267,   267,   116,
     388,   116,   520,    34,    71,   181,   501,   502,   364,   181,
     188,   520,   148,   406,   181,    25,   465,   466,   467,   364,
       7,   169,    15,   181,   364,   208,    20,   367,   367,   181,
     367,   367,   367,   367,   226,   512,   513,   520,   367,   386,
     392,   520,   518,   518,   518,   306,   307,    38,   308,   367,
     366,   164,   116,   165,   165,   367,   367,   105,    92,    94,
     142,   261,   382,   383,   488,   413,   414,   416,   416,   416,
     416,   415,   416,   416,   416,   148,   151,   251,   452,   523,
     525,   526,   527,   528,   529,   530,   531,   419,   419,   418,
     420,   420,   420,   420,   421,   421,   422,   422,   226,    92,
      92,    92,   178,   364,   437,   437,   364,   450,   181,   367,
     460,    38,   348,   364,   181,   148,   178,   364,   364,   181,
     178,   105,   181,   105,   181,   178,   364,   178,   178,   178,
     151,   344,   520,    20,   105,   105,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,   310,   311,   312,    92,
     133,   138,   330,   331,   332,   520,   133,   138,   155,   155,
     310,   518,   123,   128,   238,   241,   111,   240,   269,   270,
     272,   273,   238,   241,    20,   240,   269,   270,   272,   273,
     281,   181,   178,   181,   181,   178,   364,   519,    94,    34,
     519,   518,    94,   105,   182,   142,   488,   128,   138,   105,
     138,   383,   488,   178,   520,    66,   212,   245,   371,   372,
     181,   181,   181,   178,   105,   181,   105,   181,   178,   364,
     182,   520,   466,   467,   126,   191,   178,   178,   127,   185,
      92,   213,   214,   228,    92,   213,   214,   228,    92,   232,
     220,   105,   230,   138,   178,    59,   105,   185,   111,   185,
     165,   520,   367,   399,   400,   116,   395,   396,   116,   147,
     205,   489,   491,   492,   493,   520,   116,   367,   116,   142,
     383,   142,   142,   382,   383,   416,   364,   523,   529,   268,
     557,    94,   163,   242,   243,   244,   252,   260,   266,   267,
     524,   532,   533,   534,   548,   551,   552,   554,   249,   251,
     256,   553,   236,   237,   258,   549,   489,   489,   487,   492,
     487,   178,   179,   105,   181,   333,   349,   105,   185,   178,
     346,   364,   178,   178,    98,   409,   410,   148,   503,   504,
     520,   503,   504,   178,   116,   181,   359,   360,   133,   148,
     362,   344,   143,   160,   143,   160,   311,   128,   491,   332,
     367,   488,   138,   367,   518,   518,   124,   125,   518,   270,
     271,    94,   111,   151,   540,   271,   367,   192,   148,   178,
     128,   326,   518,   155,   128,    94,   326,   116,   367,   367,
     142,   518,   367,   116,   367,   138,   138,   383,   142,   488,
     245,    64,    65,    67,   116,   382,   389,   390,   391,   372,
     148,   503,   503,   178,   367,    25,   467,   126,   191,     8,
       9,   101,   119,   121,   148,   189,   361,   462,   464,   475,
     476,   479,    20,   227,   229,   367,   367,   367,   227,   229,
     367,   367,   367,   367,   367,   367,   116,   367,   367,   234,
     515,   516,   148,   116,   399,    93,   104,   114,   123,   401,
     402,   403,   404,   105,   520,   105,   381,   151,   151,   140,
     170,   188,   490,   520,   520,   367,   142,   367,   367,   142,
     383,   142,   178,   181,   246,   212,   245,   257,   262,   556,
      94,   247,   248,   550,   246,   526,   556,   417,   420,   266,
     532,   534,   527,   142,   550,   271,    53,   140,   367,   138,
     349,   178,   116,   489,   111,   410,   178,   364,   181,   181,
     140,   181,   181,   520,    92,   105,   181,   364,   346,   505,
     331,   367,   271,    94,   151,   543,    20,   111,   540,   165,
     367,   178,   364,   518,   105,   326,   407,   367,   185,   387,
     367,   367,   138,   367,   142,   116,   116,   367,   520,   391,
      67,   178,   364,   181,   181,   128,   189,   464,     6,   364,
     520,   189,   475,   185,   228,   228,   228,   228,   232,   513,
     180,   446,   517,   516,   367,   392,   518,   124,   125,   403,
     404,   404,   400,   104,   397,   396,   181,   181,   367,   367,
     142,   367,   420,    47,   125,   420,   420,   257,   263,   271,
     555,   555,   417,   528,   264,   367,   520,   180,   116,   180,
     178,   488,   489,   360,    92,   178,   132,   195,   542,   545,
      20,    20,   544,   542,   259,   550,   105,   181,   105,   181,
     151,   342,   122,   178,    94,   518,   367,   367,   520,   520,
     390,   367,   178,   467,   520,   189,   178,   467,   520,   367,
     367,   367,   367,   367,   367,   151,   204,   362,   178,   404,
     518,   367,   420,   420,   193,    92,   367,   520,   367,   489,
     543,   543,   545,    20,   181,    20,   254,   539,   540,   539,
     340,   341,   367,   105,   181,   367,   326,    65,    91,   177,
     468,   467,   520,   191,   467,   116,   446,   420,   489,   180,
     550,   105,   181,   181,   104,   488,   340,   116,     4,   129,
     471,   472,   474,   476,    19,   130,   469,   470,   473,   476,
     191,   467,   191,   520,   180,   367,   254,   540,   518,   520,
      91,   129,   474,   177,   130,   473,   191,   105,   181,   367,
     116,   362,   520,   105,   181,   116,   362,   520,   181,   362
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
     545,   546,   547,   548,   549,   550,   551
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   297,   298,   298,   299,   299,   299,   299,   300,   300,
     301,   301,   302,   302,   303,   304,   304,   304,   305,   305,
     306,   306,   307,   307,   307,   307,   308,   308,   308,   308,
     308,   308,   308,   309,   309,   310,   310,   311,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   313,   313,
     313,   313,   313,   313,   313,   313,   314,   314,   315,   316,
     316,   317,   317,   318,   319,   320,   320,   321,   321,   322,
     322,   322,   322,   323,   324,   325,   325,   325,   325,   326,
     326,   327,   327,   328,   328,   328,   328,   329,   330,   330,
     331,   331,   331,   332,   333,   333,   334,   334,   334,   335,
     335,   336,   337,   337,   338,   338,   339,   340,   340,   341,
     341,   342,   342,   343,   343,   344,   344,   344,   344,   345,
     346,   347,   347,   348,   348,   349,   349,   350,   351,   352,
     353,   353,   354,   354,   354,   355,   355,   355,   356,   356,
     356,   356,   357,   357,   358,   359,   359,   360,   360,   361,
     362,   363,   364,   364,   365,   365,   366,   366,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   368,   369,   370,   370,
     371,   371,   371,   372,   372,   373,   373,   374,   375,   375,
     375,   376,   376,   376,   376,   376,   377,   377,   378,   378,
     379,   380,   380,   381,   381,   381,   381,   381,   381,   381,
     381,   382,   383,   384,   385,   385,   386,   386,   387,   387,
     387,   387,   388,   388,   389,   389,   389,   390,   390,   390,
     391,   391,   391,   392,   393,   394,   395,   395,   396,   396,
     397,   398,   398,   399,   399,   400,   400,   401,   401,   401,
     401,   401,   401,   401,   402,   402,   403,   403,   404,   405,
     405,   406,   406,   407,   407,   408,   408,   409,   409,   410,
     410,   411,   412,   412,   413,   413,   414,   414,   414,   414,
     414,   415,   414,   414,   414,   414,   416,   416,   416,   417,
     417,   418,   418,   418,   419,   419,   419,   419,   419,   420,
     420,   420,   421,   421,   421,   422,   422,   423,   423,   424,
     424,   425,   425,   426,   426,   427,   427,   427,   427,   428,
     428,   428,   429,   429,   429,   429,   429,   429,   430,   430,
     430,   431,   431,   431,   431,   432,   432,   433,   433,   434,
     434,   435,   435,   435,   435,   436,   437,   437,   437,   438,
     438,   439,   439,   439,   439,   440,   440,   441,   441,   441,
     441,   441,   441,   441,   442,   442,   443,   443,   444,   444,
     444,   444,   444,   445,   445,   446,   446,   447,   447,   447,
     448,   448,   449,   449,   450,   451,   451,   451,   451,   451,
     451,   451,   451,   452,   452,   453,   453,   453,   454,   455,
     455,   456,   457,   458,   459,   459,   460,   460,   461,   461,
     462,   462,   462,   463,   463,   463,   463,   463,   463,   464,
     464,   465,   465,   466,   467,   467,   468,   468,   469,   469,
     470,   470,   470,   470,   471,   471,   472,   472,   472,   472,
     473,   473,   474,   474,   475,   475,   475,   475,   476,   476,
     476,   476,   477,   477,   478,   478,   479,   480,   480,   480,
     480,   480,   480,   481,   482,   482,   482,   482,   483,   483,
     483,   483,   484,   485,   486,   486,   486,   486,   487,   487,
     488,   489,   489,   489,   490,   490,   490,   491,   491,   491,
     492,   493,   493,   493,   493,   493,   493,   493,   493,   493,
     494,   495,   495,   495,   496,   497,   498,   498,   498,   499,
     499,   499,   499,   499,   500,   501,   501,   501,   501,   501,
     501,   501,   502,   503,   504,   505,   506,   506,   506,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   507,   508,
     508,   509,   509,   510,   511,   512,   512,   513,   514,   515,
     515,   516,   516,   516,   516,   517,   517,   518,   519,   519,
     520,   520,   521,   521,   521,   521,   521,   521,   521,   521,
     521,   521,   521,   521,   521,   521,   521,   521,   521,   521,
     521,   521,   521,   521,   521,   521,   521,   521,   521,   521,
     521,   521,   521,   521,   521,   521,   521,   521,   521,   521,
     521,   521,   521,   521,   521,   521,   521,   521,   521,   521,
     521,   521,   521,   521,   521,   521,   521,   521,   521,   521,
     521,   521,   521,   521,   521,   521,   521,   521,   521,   521,
     521,   521,   521,   521,   521,   521,   521,   521,   521,   521,
     521,   521,   521,   521,   521,   521,   521,   521,   521,   521,
     521,   521,   521,   521,   521,   521,   521,   521,   521,   521,
     521,   521,   521,   521,   521,   521,   521,   521,   521,   521,
     521,   521,   521,   521,   521,   521,   521,   521,   521,   521,
     521,   521,   521,   521,   521,   521,   521,   521,   521,   521,
     521,   521,   521,   521,   521,   521,   521,   521,   521,   521,
     521,   521,   521,   521,   521,   521,   521,   521,   521,   521,
     521,   521,   521,   521,   521,   521,   521,   521,   521,   521,
     521,   521,   521,   521,   521,   521,   521,   521,   521,   521,
     521,   521,   521,   521,   521,   521,   521,   521,   521,   521,
     521,   521,   521,   521,   521,   521,   521,   522,   522,   523,
     523,   523,   523,   524,   524,   524,   524,   525,   525,   526,
     526,   527,   527,   528,   528,   529,   529,   529,   530,   530,
     531,   531,   532,   532,   532,   532,   532,   533,   534,   534,
     534,   534,   534,   534,   534,   535,   535,   535,   535,   536,
     536,   536,   536,   537,   537,   538,   538,   538,   538,   538,
     538,   538,   539,   539,   540,   540,   540,   540,   541,   541,
     541,   541,   541,   542,   542,   543,   543,   544,   544,   545,
     545,   546,   547,   547,   548,   548,   548,   549,   549,   549,
     549,   549,   550,   550,   550,   550,   551,   552,   553,   554,
     554,   555,   555,   555,   556,   556,   557
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
       2,     2,     4,     4,     4,     1,     3,     2,     3,     3,
       3,     1,     1,     2,     1,     3,     1,     3,     1,     1,
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
  "\"'KEYWORD'\"", "\"<blank>\"", "\"'block'\"", "\"'exit'\"",
  "\"'break'\"", "\"'loop'\"", "\"'continue'\"", "\"'while'\"",
  "\"'validate'\"", "\"'typeswitch'\"", "\"'element'\"", "\"'document'\"",
  "\"'text'\"", "\"'comment'\"", "\"'declare'\"", "\"'function'\"",
  "\"'updating'\"", "\"'sequential'\"", "\"'deterministic'\"",
  "\"'nondeterministic'\"", "\"'simple'\"", "\"'if'\"",
  "\"'processing-instruction'\"", "\"'most'\"", "\"'import'\"",
  "\"'some'\"", "\"'stable'\"", "\"'module'\"", "\"'option'\"",
  "\"'word'\"", "\"'schema'\"", "\"'space'\"", "\"'set'\"", "\"'let'\"",
  "\"'construction'\"", "\"'eval'\"", "\"'for'\"", "\"'outer'\"",
  "\"'sliding'\"", "\"'tumbling'\"", "\"'previous'\"", "\"'next'\"",
  "\"'only'\"", "\"'when'\"", "\"'count'\"", "\"'ordering'\"",
  "\"'base-uri'\"", "\"'schema-element'\"", "\"'document-node'\"",
  "\"'copy-namespaces'\"", "\"'instance'\"", "\"'schema-attribute'\"",
  "\"'boundary-space'\"", "\"'decimal-format'\"",
  "\"'decimal-separator'\"", "\"'grouping-separator'\"", "\"'infinity'\"",
  "\"'minus-sign'\"", "\"'NaN'\"", "\"'percent'\"", "\"'per-mille'\"",
  "\"'zero-digit'\"", "\"'digit'\"", "\"'pattern-separator'\"",
  "\"'ancestor::'\"", "\"'ancestor-or-self::'\"", "\"'and'\"", "\"'''\"",
  "\"'as'\"", "\"'ascending'\"", "\"'at'\"", "\"'attribute'\"",
  "\"'attribute::'\"", "\"'@'\"", "\"'case'\"", "\"'castable'\"",
  "\"'cast'\"", "\"'CDATA[['\"", "\"']]'\"", "\"'child::'\"",
  "\"'collation'\"", "\"','\"", "\"'(:'\"", "\"':)'\"", "\"'DECIMAL'\"",
  "\"'context'\"", "\"'variable'\"", "\"'default'\"", "\"'descendant::'\"",
  "\"'descendant-or-self::'\"", "\"'descending'\"", "\"'div'\"", "\"'$'\"",
  "\"'.'\"", "\"'..'\"", "\"'{{'\"", "\"'DOUBLE'\"", "\"'<double {>'\"",
  "\"'else'\"", "\"'empty'\"", "\"'greatest'\"", "\"'least'\"", "\"'/>'\"",
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
  "\"'copy'\"", "\"'with'\"", "\"'try'\"", "\"'catch'\"", "\"'using'\"",
  "\"'all'\"", "\"'any'\"", "\"'casesensitive'\"", "\"'ft-option'\"",
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
       298,     0,    -1,   299,    -1,   282,   299,    -1,   301,    -1,
     300,   301,    -1,   302,    -1,   300,   302,    -1,   209,   210,
      20,   185,    -1,   209,   210,    20,   127,    20,   185,    -1,
     304,   363,    -1,   363,    -1,   303,    -1,   303,   304,    -1,
      51,   155,   519,   128,   518,   185,    -1,   305,   185,    -1,
     306,   185,    -1,   305,   185,   306,   185,    -1,   307,    -1,
     305,   185,   307,    -1,   308,    -1,   306,   185,   308,    -1,
     313,    -1,   314,    -1,   315,    -1,   317,    -1,   334,    -1,
     329,    -1,   355,    -1,   318,    -1,   319,    -1,   336,    -1,
     309,    -1,    38,   111,    77,   310,    -1,    38,    77,   520,
     310,    -1,   311,    -1,   310,   311,    -1,   312,   128,   505,
      -1,    78,    -1,    79,    -1,    80,    -1,    81,    -1,    82,
      -1,    83,    -1,    84,    -1,    85,    -1,    86,    -1,    87,
      -1,   316,    -1,   323,    -1,   324,    -1,   343,    -1,   320,
      -1,   321,    -1,   322,    -1,   506,    -1,   325,    -1,   328,
      -1,    38,   155,   519,   128,   518,    -1,    38,    76,   176,
      -1,    38,    76,   190,    -1,    38,   111,    34,   155,   518,
      -1,    38,   111,    39,   155,   518,    -1,    38,    52,   520,
      20,    -1,    38,   239,   534,    -1,    38,    69,   163,    -1,
      38,    69,   196,    -1,    38,   111,   164,   123,   124,    -1,
      38,   111,   164,   123,   125,    -1,    38,    73,   176,   105,
     143,    -1,    38,    73,   176,   105,   160,    -1,    38,    73,
     161,   105,   143,    -1,    38,    73,   161,   105,   160,    -1,
      38,   111,   104,   518,    -1,    38,    70,   518,    -1,    48,
      54,   518,    -1,    48,    54,   327,   518,    -1,    48,    54,
     518,    94,   326,    -1,    48,    54,   327,   518,    94,   326,
      -1,   518,    -1,   326,   105,   518,    -1,   155,   519,   128,
      -1,   111,    34,   155,    -1,    48,    51,   518,    -1,    48,
      51,   155,   519,   128,   518,    -1,    48,    51,   518,    94,
     326,    -1,    48,    51,   155,   519,   128,   518,    94,   326,
      -1,    38,   109,   147,   330,    -1,    92,   491,   331,    -1,
     331,    -1,   332,    -1,   133,    -1,   133,   332,    -1,   138,
     367,    -1,   116,   520,    -1,   116,   520,   488,    -1,    38,
     110,   333,   138,   367,    -1,    38,   110,   333,   133,    -1,
      38,   110,   333,   133,   138,   367,    -1,   279,    -1,   280,
      -1,    38,   337,    -1,   338,    -1,   277,   338,    -1,   339,
      -1,   335,   339,    -1,   278,   518,   281,   367,   165,   342,
     181,    -1,   341,    -1,   341,   104,   518,    -1,   367,    -1,
     367,   488,    -1,   151,   340,    -1,   342,   105,   340,    -1,
      38,    58,   176,    -1,    38,    58,   190,    -1,   151,   181,
      -1,   151,   359,   181,    -1,   151,   181,    92,   489,    -1,
     151,   359,   181,    92,   489,    -1,    26,   346,    -1,   148,
     347,   364,   178,    -1,   347,   348,   185,    -1,    -1,   348,
     105,   349,    -1,    38,   349,    -1,   333,    -1,   333,   138,
     367,    -1,    56,   116,   520,   138,   367,    -1,    27,   232,
     367,    -1,    31,   151,   367,   181,   346,    -1,    28,    29,
      -1,    30,    29,    -1,   274,   278,   518,    -1,   276,   278,
     518,    -1,   275,   278,   518,    -1,    38,   356,    -1,    38,
      43,   356,    -1,    38,    42,   356,    -1,   357,    -1,    44,
     357,    -1,    40,   357,    -1,    41,   358,    -1,    39,   520,
     344,   362,    -1,    39,   520,   344,   133,    -1,    39,   520,
     344,   346,    -1,   360,    -1,   359,   105,   360,    -1,   116,
     520,    -1,   116,   520,   488,    -1,   148,   364,   178,    -1,
     148,   364,   178,    -1,   364,    -1,   366,    -1,   366,   365,
      -1,   185,    -1,   365,   366,   185,    -1,   367,    -1,   366,
     105,   367,    -1,   368,    -1,   405,    -1,   408,    -1,   411,
      -1,   412,    -1,   507,    -1,   508,    -1,   510,    -1,   509,
      -1,   511,    -1,   514,    -1,   522,    -1,   351,    -1,   352,
      -1,   353,    -1,   350,    -1,   345,    -1,   354,    -1,   377,
     369,    -1,   180,   367,    -1,    62,   267,    -1,    63,   267,
      -1,   212,    -1,   245,    -1,    66,   245,    -1,   371,   389,
      67,   367,    -1,   371,    67,   367,    -1,    60,   370,   388,
     372,   372,    -1,    60,   370,   388,   372,    -1,    68,   116,
     520,    -1,   379,    -1,   384,    -1,   373,    -1,   375,    -1,
     393,    -1,   398,    -1,   394,    -1,   374,    -1,   375,    -1,
     377,   376,    -1,    60,   116,    -1,    61,    60,   116,    -1,
     378,   380,    -1,   381,    -1,   380,   105,   116,   381,    -1,
     520,   142,   367,    -1,   520,   488,   142,   367,    -1,   520,
     382,   142,   367,    -1,   520,   488,   382,   142,   367,    -1,
     520,   383,   142,   367,    -1,   520,   488,   383,   142,   367,
      -1,   520,   382,   383,   142,   367,    -1,   520,   488,   382,
     383,   142,   367,    -1,    94,   116,   520,    -1,   261,   116,
     520,    -1,    57,   116,   385,    -1,   387,    -1,   385,   105,
     116,   387,    -1,   392,    -1,   386,   105,   116,   392,    -1,
     520,   138,   367,    -1,   520,   488,   138,   367,    -1,   520,
     383,   138,   367,    -1,   520,   488,   383,   138,   367,    -1,
     116,   520,   142,   367,    -1,   116,   520,   488,   142,   367,
      -1,   390,    -1,   116,   520,    -1,   116,   520,   390,    -1,
     382,    -1,   382,   391,    -1,   391,    -1,    64,   116,   520,
      65,   116,   520,    -1,    65,   116,   520,    -1,    64,   116,
     520,    -1,   520,    -1,   206,   367,    -1,   166,   165,   395,
      -1,   396,    -1,   395,   105,   396,    -1,   116,   520,    -1,
     116,   520,   397,    -1,   104,   518,    -1,   164,   165,   399,
      -1,    50,   164,   165,   399,    -1,   400,    -1,   399,   105,
     400,    -1,   367,    -1,   367,   401,    -1,   402,    -1,   403,
      -1,   404,    -1,   402,   403,    -1,   402,   404,    -1,   403,
     404,    -1,   402,   403,   404,    -1,    93,    -1,   114,    -1,
     123,   124,    -1,   123,   125,    -1,   104,   518,    -1,    49,
     116,   406,   182,   367,    -1,   131,   116,   406,   182,   367,
      -1,   407,    -1,   406,   105,   116,   407,    -1,   520,   142,
     367,    -1,   520,   488,   142,   367,    -1,    33,   151,   364,
     181,   409,   111,   180,   367,    -1,    33,   151,   364,   181,
     409,   111,   116,   520,   180,   367,    -1,   410,    -1,   409,
     410,    -1,    98,   489,   180,   367,    -1,    98,   116,   520,
      92,   489,   180,   367,    -1,    45,   151,   364,   181,   192,
     367,   122,   367,    -1,   413,    -1,   412,   162,   413,    -1,
     414,    -1,   413,    90,   414,    -1,   416,    -1,   416,   429,
     416,    -1,   416,   430,   416,    -1,   416,   128,   416,    -1,
     416,   157,   416,    -1,    -1,   416,   152,   415,   416,    -1,
     416,   150,   416,    -1,   416,   139,   416,    -1,   416,   137,
     416,    -1,   417,    -1,   417,   250,   523,    -1,   417,   250,
     523,   557,    -1,   418,    -1,   418,   193,   418,    -1,   419,
      -1,   418,   170,   419,    -1,   418,   153,   419,    -1,   420,
      -1,   419,   188,   420,    -1,   419,   115,   420,    -1,   419,
     141,   420,    -1,   419,   154,   420,    -1,   421,    -1,   420,
     195,   421,    -1,   420,   204,   421,    -1,   422,    -1,   421,
     145,   422,    -1,   421,   132,   422,    -1,   423,    -1,   423,
      74,   226,   489,    -1,   424,    -1,   424,   194,    92,   489,
      -1,   425,    -1,   425,    99,    92,   487,    -1,   426,    -1,
     426,   100,    92,   487,    -1,   428,    -1,   427,   428,    -1,
     170,    -1,   153,    -1,   427,   170,    -1,   427,   153,    -1,
     431,    -1,   435,    -1,   432,    -1,   197,    -1,   202,    -1,
     201,    -1,   200,    -1,   199,    -1,   198,    -1,   146,    -1,
     173,    -1,   136,    -1,    32,   148,   364,   178,    -1,    32,
     217,   148,   364,   178,    -1,    32,   216,   148,   364,   178,
      -1,    32,    92,   503,   148,   364,   178,    -1,   433,   148,
     178,    -1,   433,   148,   364,   178,    -1,   434,    -1,   433,
     434,    -1,   171,   520,    15,    -1,   171,    16,    -1,   436,
      -1,   436,   437,    -1,   187,   437,    -1,   437,    -1,   186,
      -1,   438,    -1,   438,   186,   437,    -1,   438,   187,   437,
      -1,   439,    -1,   448,    -1,   440,    -1,   440,   449,    -1,
     443,    -1,   443,   449,    -1,   441,   445,    -1,   442,    -1,
     103,    -1,   112,    -1,    96,    -1,   184,    -1,   113,    -1,
     135,    -1,   134,    -1,   445,    -1,    97,   445,    -1,   444,
     445,    -1,   118,    -1,   167,    -1,    88,    -1,   175,    -1,
     174,    -1,    89,    -1,   493,    -1,   446,    -1,   520,    -1,
     447,    -1,   188,    -1,    10,    -1,    17,    -1,   451,    -1,
     451,   449,    -1,   450,    -1,   449,   450,    -1,   149,   364,
     179,    -1,   452,    -1,   454,    -1,   455,    -1,   456,    -1,
     459,    -1,   461,    -1,   457,    -1,   458,    -1,   453,    -1,
     505,    -1,   108,    -1,   144,    -1,   120,    -1,   116,   520,
      -1,   151,   181,    -1,   151,   364,   181,    -1,   117,    -1,
     163,   148,   364,   178,    -1,   196,   148,   364,   178,    -1,
     520,   151,   181,    -1,   520,   151,   460,   181,    -1,   367,
      -1,   460,   105,   367,    -1,   462,    -1,   480,    -1,   463,
      -1,   477,    -1,   478,    -1,   152,   520,   467,   126,    -1,
     152,   520,   465,   467,   126,    -1,   152,   520,   467,   191,
     189,   520,   467,   191,    -1,   152,   520,   467,   191,   464,
     189,   520,   467,   191,    -1,   152,   520,   465,   467,   191,
     189,   520,   467,   191,    -1,   152,   520,   465,   467,   191,
     464,   189,   520,   467,   191,    -1,   475,    -1,   464,   475,
      -1,   466,    -1,   465,   466,    -1,    25,   520,   467,   128,
     467,   468,    -1,    -1,    25,    -1,   177,   469,   177,    -1,
      91,   471,    91,    -1,    -1,   470,    -1,   130,    -1,   473,
      -1,   470,   130,    -1,   470,   473,    -1,    -1,   472,    -1,
     129,    -1,   474,    -1,   472,   129,    -1,   472,   474,    -1,
      19,    -1,   476,    -1,     4,    -1,   476,    -1,   462,    -1,
       9,    -1,   479,    -1,   476,    -1,     8,    -1,   119,    -1,
     121,    -1,   361,    -1,   207,    21,   208,    -1,   207,   208,
      -1,   168,   519,   169,    -1,   168,   519,     7,    -1,   101,
       6,    -1,   481,    -1,   482,    -1,   483,    -1,   484,    -1,
     485,    -1,   486,    -1,    35,   148,   364,   178,    -1,    34,
     520,   148,   178,    -1,    34,   520,   148,   364,   178,    -1,
      34,   148,   364,   178,   148,   178,    -1,    34,   148,   364,
     178,   148,   364,   178,    -1,    95,   520,   148,   178,    -1,
      95,   520,   148,   364,   178,    -1,    95,   148,   364,   178,
     148,   178,    -1,    95,   148,   364,   178,   148,   364,   178,
      -1,    36,   148,   364,   178,    -1,    37,   148,   364,   178,
      -1,    46,   519,   148,   178,    -1,    46,   519,   148,   364,
     178,    -1,    46,   148,   364,   178,   148,   178,    -1,    46,
     148,   364,   178,   148,   364,   178,    -1,   492,    -1,   492,
     140,    -1,    92,   489,    -1,   491,    -1,   491,   490,    -1,
     205,   151,   181,    -1,   140,    -1,   188,    -1,   170,    -1,
     492,    -1,   493,    -1,   147,   151,   181,    -1,   520,    -1,
     495,    -1,   501,    -1,   499,    -1,   502,    -1,   500,    -1,
     498,    -1,   497,    -1,   496,    -1,   494,    -1,   220,   151,
     181,    -1,    72,   151,   181,    -1,    72,   151,   501,   181,
      -1,    72,   151,   502,   181,    -1,    36,   151,   181,    -1,
      37,   151,   181,    -1,    46,   151,   181,    -1,    46,   151,
     519,   181,    -1,    46,   151,    20,   181,    -1,    95,   151,
     181,    -1,    95,   151,   520,   181,    -1,    95,   151,   520,
     105,   503,   181,    -1,    95,   151,   188,   181,    -1,    95,
     151,   188,   105,   503,   181,    -1,   183,   520,   181,    -1,
      34,   151,   181,    -1,    34,   151,   520,   181,    -1,    34,
     151,   520,   105,   503,   181,    -1,    34,   151,   520,   105,
     504,   181,    -1,    34,   151,   188,   181,    -1,    34,   151,
     188,   105,   503,   181,    -1,    34,   151,   188,   105,   504,
     181,    -1,    71,   151,   520,   181,    -1,   520,    -1,   520,
     140,    -1,    20,    -1,    38,   215,   216,    -1,    38,   215,
     217,    -1,    38,   215,   218,    -1,   221,   220,   367,   228,
     367,    -1,   221,   220,   367,    92,   227,   228,   367,    -1,
     221,   220,   367,    92,   229,   228,   367,    -1,   221,   220,
     367,   213,   367,    -1,   221,   220,   367,   214,   367,    -1,
     221,   222,   367,   228,   367,    -1,   221,   222,   367,    92,
     227,   228,   367,    -1,   221,   222,   367,    92,   229,   228,
     367,    -1,   221,   222,   367,   213,   367,    -1,   221,   222,
     367,   214,   367,    -1,   219,   220,   367,    -1,   219,   222,
     367,    -1,   224,   220,   367,   232,   367,    -1,   224,   225,
     226,   220,   367,   232,   367,    -1,   223,   220,   367,    92,
     367,    -1,   231,   116,   512,   230,   367,   180,   367,    -1,
     513,    -1,   512,   105,   116,   513,    -1,   520,   138,   367,
      -1,   233,   148,   367,   178,   515,    -1,   516,    -1,   515,
     516,    -1,   234,   517,   362,    -1,   234,   517,   151,   116,
     520,   181,   362,    -1,   234,   517,   151,   116,   520,   105,
     116,   520,   181,   362,    -1,   234,   517,   151,   116,   520,
     105,   116,   520,   105,   116,   520,   181,   362,    -1,   446,
      -1,   517,   204,   446,    -1,    20,    -1,    14,    -1,   520,
      -1,    18,    -1,   521,    -1,   209,    -1,   123,    -1,    95,
      -1,    37,    -1,    72,    -1,    34,    -1,   147,    -1,    45,
      -1,   220,    -1,    46,    -1,    75,    -1,    71,    -1,    36,
      -1,    33,    -1,   205,    -1,    76,    -1,   239,    -1,    70,
      -1,   217,    -1,   216,    -1,   141,    -1,    35,    -1,   251,
      -1,   238,    -1,   241,    -1,   240,    -1,   268,    -1,   269,
      -1,   272,    -1,   270,    -1,   273,    -1,   244,    -1,   246,
      -1,    53,    -1,   212,    -1,   245,    -1,    47,    -1,   218,
      -1,   231,    -1,   225,    -1,   197,    -1,   202,    -1,   201,
      -1,   200,    -1,   199,    -1,   198,    -1,    94,    -1,   109,
      -1,   110,    -1,   180,    -1,    60,    -1,    61,    -1,    62,
      -1,    63,    -1,    64,    -1,    65,    -1,    66,    -1,    67,
      -1,    68,    -1,   142,    -1,    57,    -1,   206,    -1,   165,
      -1,   166,    -1,   164,    -1,    50,    -1,    93,    -1,   114,
      -1,   124,    -1,   125,    -1,   104,    -1,    49,    -1,   131,
      -1,   182,    -1,    98,    -1,    92,    -1,   192,    -1,   122,
      -1,   162,    -1,    90,    -1,    74,    -1,   226,    -1,    99,
      -1,   193,    -1,   115,    -1,   154,    -1,   195,    -1,   145,
      -1,   132,    -1,    32,    -1,   100,    -1,   194,    -1,   146,
      -1,   176,    -1,   190,    -1,   155,    -1,   133,    -1,   127,
      -1,   161,    -1,   143,    -1,   160,    -1,    38,    -1,    58,
      -1,    69,    -1,   111,    -1,    73,    -1,    52,    -1,   210,
      -1,    48,    -1,    54,    -1,    51,    -1,    39,    -1,   261,
      -1,   250,    -1,   266,    -1,   267,    -1,   243,    -1,   256,
      -1,   264,    -1,   260,    -1,   242,    -1,   255,    -1,   265,
      -1,   259,    -1,   254,    -1,   253,    -1,   237,    -1,   236,
      -1,   258,    -1,   247,    -1,   248,    -1,   271,    -1,   263,
      -1,   262,    -1,   257,    -1,   224,    -1,   230,    -1,   227,
      -1,   221,    -1,   214,    -1,   213,    -1,   215,    -1,   232,
      -1,   222,    -1,   223,    -1,   229,    -1,   219,    -1,   228,
      -1,    44,    -1,    41,    -1,    40,    -1,    42,    -1,    43,
      -1,   163,    -1,   196,    -1,    26,    -1,    27,    -1,    29,
      -1,    31,    -1,    28,    -1,    30,    -1,   233,    -1,   234,
      -1,    59,    -1,   235,    -1,    56,    -1,   278,    -1,   274,
      -1,   275,    -1,   277,    -1,   281,    -1,   279,    -1,   280,
      -1,   276,    -1,    77,    -1,    78,    -1,    79,    -1,    80,
      -1,    81,    -1,    82,    -1,    83,    -1,    84,    -1,    85,
      -1,    86,    -1,    87,    -1,   235,   116,   386,    59,   148,
     367,   178,    -1,    59,   148,   367,   178,    -1,   525,    -1,
     525,   524,    -1,   525,   266,   417,    -1,   525,   524,   266,
     417,    -1,   534,    -1,   532,    -1,   524,   534,    -1,   524,
     532,    -1,   526,    -1,   525,   252,   526,    -1,   527,    -1,
     526,   249,   527,    -1,   528,    -1,   527,   251,   142,   528,
      -1,   529,    -1,   251,   529,    -1,   530,    -1,   530,   553,
      -1,   151,   523,   181,    -1,   531,    -1,   531,   549,    -1,
     452,    -1,   148,   364,   178,    -1,   533,    -1,   552,    -1,
     551,    -1,   554,    -1,   548,    -1,   163,    -1,   535,    -1,
     536,    -1,   537,    -1,   538,    -1,   541,    -1,   546,    -1,
     547,    -1,   255,    -1,   265,    -1,    98,   238,    -1,    98,
     241,    -1,   232,   240,    -1,   268,   240,    -1,   240,   238,
      -1,   240,   241,    -1,   232,   269,    -1,   268,   269,    -1,
     232,   272,   540,    -1,   232,   272,   111,    -1,   232,   272,
     151,   540,   181,    -1,   232,   272,   151,   540,   105,   539,
     181,    -1,   232,   272,   151,   111,   181,    -1,   232,   272,
     151,   111,   105,   539,   181,    -1,   268,   272,    -1,   540,
      -1,   539,   105,   540,    -1,    94,    20,    -1,    94,    20,
     259,    20,    -1,    94,    20,   550,   254,    -1,    94,    20,
     259,    20,   550,   254,    -1,   232,   270,   271,   543,    -1,
     232,   270,   271,   543,   542,    -1,   232,   111,   270,   271,
      -1,   232,   111,   270,   271,   542,    -1,   268,   270,   271,
      -1,   545,    -1,   542,   545,    -1,    94,    20,    -1,   151,
     544,   181,    -1,    20,    -1,   544,    20,    -1,   195,   543,
      -1,   132,   543,    -1,   253,    20,    -1,   232,   273,    -1,
     268,   273,    -1,    94,   212,    -1,    94,   245,    -1,   244,
     246,    -1,   237,    -1,   237,    53,    -1,   236,    -1,   236,
     271,    -1,   258,    -1,   247,   420,    -1,    94,   125,   420,
      -1,    94,    47,   420,    -1,   248,   420,   193,   420,    -1,
     243,   550,   555,    -1,   267,   420,   555,    -1,   256,   550,
     264,    -1,   260,   556,    -1,   242,   556,    -1,   271,    -1,
     263,    -1,   257,    -1,   262,    -1,   257,    -1,   268,   246,
     420,    -1
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
     492,   495,   498,   503,   508,   513,   515,   519,   522,   526,
     530,   534,   536,   538,   541,   543,   547,   549,   553,   555,
     557,   559,   561,   563,   565,   567,   569,   571,   573,   575,
     577,   579,   581,   583,   585,   587,   589,   592,   595,   598,
     601,   603,   605,   608,   613,   617,   623,   628,   632,   634,
     636,   638,   640,   642,   644,   646,   648,   650,   653,   656,
     660,   663,   665,   670,   674,   679,   684,   690,   695,   701,
     707,   714,   718,   722,   726,   728,   733,   735,   740,   744,
     749,   754,   760,   765,   771,   773,   776,   780,   782,   785,
     787,   794,   798,   802,   804,   807,   811,   813,   817,   820,
     824,   827,   831,   836,   838,   842,   844,   847,   849,   851,
     853,   856,   859,   862,   866,   868,   870,   873,   876,   879,
     885,   891,   893,   898,   902,   907,   916,   927,   929,   932,
     937,   945,   954,   956,   960,   962,   966,   968,   972,   976,
     980,   984,   985,   990,   994,   998,  1002,  1004,  1008,  1013,
    1015,  1019,  1021,  1025,  1029,  1031,  1035,  1039,  1043,  1047,
    1049,  1053,  1057,  1059,  1063,  1067,  1069,  1074,  1076,  1081,
    1083,  1088,  1090,  1095,  1097,  1100,  1102,  1104,  1107,  1110,
    1112,  1114,  1116,  1118,  1120,  1122,  1124,  1126,  1128,  1130,
    1132,  1134,  1139,  1145,  1151,  1158,  1162,  1167,  1169,  1172,
    1176,  1179,  1181,  1184,  1187,  1189,  1191,  1193,  1197,  1201,
    1203,  1205,  1207,  1210,  1212,  1215,  1218,  1220,  1222,  1224,
    1226,  1228,  1230,  1232,  1234,  1236,  1239,  1242,  1244,  1246,
    1248,  1250,  1252,  1254,  1256,  1258,  1260,  1262,  1264,  1266,
    1268,  1270,  1273,  1275,  1278,  1282,  1284,  1286,  1288,  1290,
    1292,  1294,  1296,  1298,  1300,  1302,  1304,  1306,  1308,  1311,
    1314,  1318,  1320,  1325,  1330,  1334,  1339,  1341,  1345,  1347,
    1349,  1351,  1353,  1355,  1360,  1366,  1375,  1385,  1395,  1406,
    1408,  1411,  1413,  1416,  1423,  1424,  1426,  1430,  1434,  1435,
    1437,  1439,  1441,  1444,  1447,  1448,  1450,  1452,  1454,  1457,
    1460,  1462,  1464,  1466,  1468,  1470,  1472,  1474,  1476,  1478,
    1480,  1482,  1484,  1488,  1491,  1495,  1499,  1502,  1504,  1506,
    1508,  1510,  1512,  1514,  1519,  1524,  1530,  1537,  1545,  1550,
    1556,  1563,  1571,  1576,  1581,  1586,  1592,  1599,  1607,  1609,
    1612,  1615,  1617,  1620,  1624,  1626,  1628,  1630,  1632,  1634,
    1638,  1640,  1642,  1644,  1646,  1648,  1650,  1652,  1654,  1656,
    1658,  1662,  1666,  1671,  1676,  1680,  1684,  1688,  1693,  1698,
    1702,  1707,  1714,  1719,  1726,  1730,  1734,  1739,  1746,  1753,
    1758,  1765,  1772,  1777,  1779,  1782,  1784,  1788,  1792,  1796,
    1802,  1810,  1818,  1824,  1830,  1836,  1844,  1852,  1858,  1864,
    1868,  1872,  1878,  1886,  1892,  1900,  1902,  1907,  1911,  1917,
    1919,  1922,  1926,  1934,  1945,  1959,  1961,  1965,  1967,  1969,
    1971,  1973,  1975,  1977,  1979,  1981,  1983,  1985,  1987,  1989,
    1991,  1993,  1995,  1997,  1999,  2001,  2003,  2005,  2007,  2009,
    2011,  2013,  2015,  2017,  2019,  2021,  2023,  2025,  2027,  2029,
    2031,  2033,  2035,  2037,  2039,  2041,  2043,  2045,  2047,  2049,
    2051,  2053,  2055,  2057,  2059,  2061,  2063,  2065,  2067,  2069,
    2071,  2073,  2075,  2077,  2079,  2081,  2083,  2085,  2087,  2089,
    2091,  2093,  2095,  2097,  2099,  2101,  2103,  2105,  2107,  2109,
    2111,  2113,  2115,  2117,  2119,  2121,  2123,  2125,  2127,  2129,
    2131,  2133,  2135,  2137,  2139,  2141,  2143,  2145,  2147,  2149,
    2151,  2153,  2155,  2157,  2159,  2161,  2163,  2165,  2167,  2169,
    2171,  2173,  2175,  2177,  2179,  2181,  2183,  2185,  2187,  2189,
    2191,  2193,  2195,  2197,  2199,  2201,  2203,  2205,  2207,  2209,
    2211,  2213,  2215,  2217,  2219,  2221,  2223,  2225,  2227,  2229,
    2231,  2233,  2235,  2237,  2239,  2241,  2243,  2245,  2247,  2249,
    2251,  2253,  2255,  2257,  2259,  2261,  2263,  2265,  2267,  2269,
    2271,  2273,  2275,  2277,  2279,  2281,  2283,  2285,  2287,  2289,
    2291,  2293,  2295,  2297,  2299,  2301,  2303,  2305,  2307,  2309,
    2311,  2313,  2315,  2317,  2319,  2321,  2323,  2325,  2327,  2329,
    2331,  2333,  2335,  2337,  2339,  2341,  2343,  2345,  2353,  2358,
    2360,  2363,  2367,  2372,  2374,  2376,  2379,  2382,  2384,  2388,
    2390,  2394,  2396,  2401,  2403,  2406,  2408,  2411,  2415,  2417,
    2420,  2422,  2426,  2428,  2430,  2432,  2434,  2436,  2438,  2440,
    2442,  2444,  2446,  2448,  2450,  2452,  2454,  2456,  2459,  2462,
    2465,  2468,  2471,  2474,  2477,  2480,  2484,  2488,  2494,  2502,
    2508,  2516,  2519,  2521,  2525,  2528,  2533,  2538,  2545,  2550,
    2556,  2561,  2567,  2571,  2573,  2576,  2579,  2583,  2585,  2588,
    2591,  2594,  2597,  2600,  2603,  2606,  2609,  2612,  2614,  2617,
    2619,  2622,  2624,  2627,  2631,  2635,  2640,  2644,  2648,  2652,
    2655,  2658,  2660,  2662,  2664,  2666,  2668
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,   887,   887,   888,   898,   903,   909,   914,   926,   931,
     941,   948,   960,   966,   978,   990,   996,  1002,  1014,  1020,
    1034,  1040,  1054,  1055,  1056,  1057,  1063,  1064,  1065,  1066,
    1069,  1072,  1074,  1080,  1085,  1094,  1100,  1109,  1118,  1119,
    1120,  1121,  1122,  1123,  1124,  1125,  1126,  1127,  1134,  1135,
    1136,  1137,  1138,  1139,  1140,  1143,  1150,  1151,  1163,  1175,
    1180,  1191,  1197,  1209,  1222,  1233,  1238,  1250,  1255,  1266,
    1272,  1278,  1284,  1303,  1314,  1325,  1332,  1339,  1346,  1359,
    1365,  1380,  1384,  1394,  1400,  1407,  1413,  1425,  1432,  1438,
    1445,  1451,  1455,  1462,  1473,  1478,  1487,  1496,  1503,  1513,
    1515,  1522,  1530,  1534,  1542,  1546,  1554,  1562,  1566,  1574,
    1578,  1585,  1592,  1602,  1607,  1619,  1623,  1627,  1631,  1638,
    1645,  1664,  1674,  1680,  1686,  1695,  1706,  1719,  1727,  1734,
    1746,  1750,  1757,  1761,  1765,  1772,  1776,  1782,  1789,  1793,
    1797,  1805,  1812,  1821,  1833,  1847,  1855,  1869,  1876,  1889,
    1897,  1908,  1919,  1923,  1935,  1939,  1948,  1952,  1968,  1969,
    1970,  1971,  1972,  1975,  1976,  1977,  1978,  1979,  1981,  1982,
    1985,  1986,  1987,  1988,  1989,  1992,  1999,  2008,  2015,  2019,
    2027,  2031,  2035,  2042,  2046,  2053,  2061,  2072,  2082,  2083,
    2084,  2088,  2088,  2088,  2088,  2088,  2091,  2097,  2106,  2110,
    2120,  2131,  2137,  2151,  2159,  2168,  2178,  2189,  2198,  2208,
    2218,  2234,  2247,  2259,  2271,  2277,  2289,  2295,  2309,  2318,
    2328,  2337,  2350,  2357,  2368,  2369,  2374,  2383,  2387,  2392,
    2396,  2402,  2407,  2415,  2431,  2439,  2446,  2452,  2463,  2470,
    2480,  2490,  2495,  2507,  2513,  2527,  2533,  2545,  2552,  2559,
    2566,  2573,  2580,  2587,  2600,  2604,  2614,  2619,  2630,  2641,
    2648,  2661,  2668,  2680,  2687,  2701,  2708,  2722,  2728,  2740,
    2746,  2760,  2771,  2775,  2786,  2790,  2809,  2813,  2821,  2829,
    2837,  2845,  2845,  2853,  2861,  2869,  2883,  2887,  2894,  2907,
    2911,  2922,  2926,  2930,  2940,  2944,  2948,  2952,  2956,  2966,
    2970,  2975,  2986,  2990,  2994,  3004,  3008,  3020,  3024,  3036,
    3040,  3052,  3056,  3068,  3072,  3084,  3088,  3092,  3096,  3108,
    3112,  3116,  3126,  3130,  3134,  3138,  3142,  3146,  3156,  3160,
    3164,  3174,  3178,  3182,  3186,  3198,  3204,  3216,  3222,  3236,
    3243,  3284,  3288,  3292,  3296,  3308,  3318,  3329,  3334,  3344,
    3348,  3358,  3364,  3370,  3376,  3388,  3394,  3405,  3409,  3413,
    3417,  3421,  3425,  3429,  3439,  3443,  3453,  3457,  3468,  3472,
    3476,  3480,  3484,  3499,  3503,  3513,  3517,  3527,  3534,  3541,
    3554,  3558,  3570,  3576,  3590,  3601,  3605,  3609,  3613,  3617,
    3621,  3625,  3629,  3639,  3643,  3653,  3658,  3663,  3674,  3685,
    3689,  3700,  3710,  3721,  3777,  3783,  3795,  3801,  3813,  3817,
    3827,  3831,  3835,  3845,  3853,  3861,  3869,  3877,  3885,  3900,
    3906,  3918,  3924,  3937,  3946,  3948,  3954,  3959,  3971,  3974,
    3981,  3987,  3993,  4001,  4016,  4019,  4026,  4032,  4038,  4046,
    4060,  4065,  4076,  4081,  4092,  4097,  4102,  4108,  4120,  4126,
    4131,  4136,  4147,  4152,  4167,  4172,  4189,  4204,  4208,  4212,
    4216,  4220,  4224,  4234,  4245,  4251,  4257,  4262,  4284,  4290,
    4296,  4301,  4312,  4322,  4332,  4338,  4344,  4349,  4360,  4366,
    4378,  4389,  4395,  4401,  4438,  4443,  4448,  4459,  4463,  4467,
    4477,  4488,  4492,  4496,  4500,  4504,  4508,  4512,  4516,  4520,
    4530,  4540,  4544,  4549,  4560,  4570,  4580,  4584,  4588,  4598,
    4604,  4610,  4616,  4622,  4634,  4645,  4652,  4659,  4666,  4673,
    4680,  4687,  4700,  4721,  4728,  4748,  4788,  4792,  4796,  4805,
    4811,  4817,  4823,  4829,  4836,  4842,  4848,  4854,  4860,  4872,
    4877,  4887,  4893,  4905,  4931,  4942,  4948,  4961,  4976,  4983,
    4989,  5000,  5007,  5017,  5028,  5043,  5049,  5059,  5068,  5069,
    5086,  5090,  5097,  5098,  5099,  5100,  5101,  5102,  5103,  5104,
    5105,  5106,  5107,  5108,  5109,  5110,  5111,  5112,  5113,  5114,
    5115,  5116,  5117,  5118,  5119,  5120,  5121,  5122,  5123,  5124,
    5125,  5126,  5127,  5128,  5129,  5130,  5131,  5132,  5133,  5134,
    5135,  5136,  5137,  5138,  5139,  5140,  5141,  5142,  5143,  5144,
    5145,  5146,  5147,  5148,  5149,  5150,  5151,  5152,  5153,  5154,
    5155,  5156,  5157,  5158,  5159,  5160,  5161,  5162,  5163,  5164,
    5165,  5166,  5167,  5168,  5169,  5170,  5171,  5172,  5173,  5174,
    5175,  5176,  5177,  5178,  5179,  5180,  5181,  5182,  5183,  5184,
    5185,  5186,  5187,  5188,  5189,  5190,  5191,  5192,  5193,  5194,
    5195,  5196,  5197,  5198,  5199,  5200,  5201,  5202,  5203,  5204,
    5205,  5206,  5207,  5208,  5209,  5210,  5211,  5212,  5213,  5214,
    5215,  5216,  5217,  5218,  5219,  5220,  5221,  5222,  5223,  5224,
    5225,  5226,  5227,  5228,  5229,  5230,  5231,  5232,  5233,  5234,
    5235,  5236,  5237,  5238,  5239,  5240,  5241,  5242,  5243,  5244,
    5245,  5246,  5247,  5248,  5249,  5250,  5251,  5252,  5253,  5254,
    5255,  5256,  5257,  5258,  5259,  5260,  5261,  5262,  5263,  5264,
    5265,  5266,  5267,  5268,  5269,  5270,  5271,  5272,  5273,  5274,
    5275,  5276,  5277,  5278,  5279,  5280,  5281,  5292,  5298,  5315,
    5319,  5323,  5327,  5337,  5340,  5343,  5346,  5355,  5358,  5367,
    5370,  5379,  5382,  5391,  5394,  5403,  5406,  5409,  5418,  5421,
    5430,  5434,  5444,  5447,  5450,  5453,  5456,  5465,  5474,  5478,
    5482,  5486,  5490,  5494,  5498,  5508,  5511,  5514,  5517,  5526,
    5529,  5532,  5535,  5544,  5547,  5556,  5559,  5562,  5565,  5568,
    5571,  5574,  5583,  5586,  5595,  5598,  5601,  5604,  5613,  5616,
    5619,  5622,  5625,  5634,  5637,  5646,  5649,  5658,  5661,  5670,
    5673,  5682,  5691,  5694,  5703,  5706,  5709,  5718,  5721,  5724,
    5727,  5730,  5739,  5743,  5747,  5751,  5761,  5770,  5780,  5789,
    5792,  5801,  5804,  5807,  5816,  5819,  5828
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
     295,   296
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 9738;
  const int xquery_parser::yynnts_ = 261;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 496;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 297;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 551;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 13409 "/Users/mbrantner/projects/zorba/vanilla/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 5836 "/Users/mbrantner/projects/zorba/vanilla/src/compiler/parser/xquery_parser.y"


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

