
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
#line 45 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"


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
#line 75 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 877 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_driver.h"
#include "compiler/parser/xquery_scanner.h"
#undef yylex
#define yylex driver.lexer->lex


/* Line 317 of lalr1.cc  */
#line 92 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"

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
#line 161 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
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
#line 761 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 268 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 114: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 760 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 277 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 138: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 759 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 286 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 301: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 295 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 302: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 304 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 303: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 313 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 304: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 322 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 305: /* "Prolog" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 331 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 306: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 340 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 307: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 349 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 308: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 358 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 309: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 367 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 310: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 376 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 311: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 773 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->pair_vector); };

/* Line 480 of lalr1.cc  */
#line 385 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 312: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 773 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->pair); };

/* Line 480 of lalr1.cc  */
#line 394 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 314: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 403 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 315: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 412 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 316: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 421 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 317: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 430 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 439 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 448 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 321: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 457 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 466 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 475 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 484 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 493 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 502 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 511 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 520 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 529 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 538 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 547 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 556 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 565 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 773 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 574 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 583 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 592 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "IndexDecl2" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 601 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "IndexDecl3" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 610 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "IndexDeclSuffix" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 619 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "IndexField" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 628 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "IndexField1" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 637 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "IndexFieldList" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 646 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 655 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 773 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 664 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 673 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "Block" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 682 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "BlockDecls" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 691 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "BlockVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 700 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "BlockVarDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 709 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "AssignExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 718 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "ExitExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 727 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "WhileExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 736 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 745 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "IndexStatement" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 754 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 763 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 772 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "FunctionDecl3" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 781 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "FunctionDecl4" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 790 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 799 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 808 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "EnclosedExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 817 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 826 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 835 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 844 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "ApplyExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 853 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "ConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 862 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 871 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 880 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 889 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 898 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 916 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 952 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 961 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 970 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 979 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 988 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "EvalVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 997 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1006 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1015 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1024 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1033 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1042 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "EvalVarDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1051 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1060 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1069 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1078 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1087 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1096 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1105 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1114 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1123 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1132 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1141 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1150 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1159 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1168 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1177 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1186 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1195 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1204 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1213 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1222 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1231 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1240 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1249 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1258 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1267 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1276 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1285 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1294 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1303 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1312 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1321 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1330 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1339 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1348 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1357 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1366 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1375 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1384 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1393 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1402 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "PragmaList" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1411 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1420 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1429 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1438 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1447 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1456 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1465 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1474 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1483 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1492 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1501 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1510 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1519 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1528 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1537 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1546 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1555 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1564 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1573 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1582 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1591 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1600 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1609 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1618 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1627 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1636 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1645 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1654 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1663 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1672 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1681 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1690 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1699 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1708 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "Opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1717 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1726 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "Opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1735 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1744 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1753 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1762 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1771 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1780 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1789 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1798 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1807 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1816 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1825 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1834 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1843 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1852 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1861 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1870 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1879 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1888 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1897 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1906 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1915 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1924 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1933 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1942 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1951 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1960 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1969 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1978 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1987 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1996 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2005 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2014 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2023 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 769 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2032 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2041 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2050 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2059 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2068 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2077 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2086 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2095 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2104 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2113 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2122 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2131 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 773 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2140 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2149 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "EvalExpr" */

/* Line 480 of lalr1.cc  */
#line 771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2158 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
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
#line 94 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename);
}

/* Line 553 of lalr1.cc  */
#line 2243 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"

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
#line 895 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 905 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		}
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 910 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<MainModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr ((yyval.node));
		}
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 916 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
       driver.set_expr ((yyval.node));
		}
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 921 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
       driver.set_expr ((yyval.node));
		}
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 933 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)), encoding);
		}
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 938 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 948 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)));
		}
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 955 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)),
                NULL);
		}
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 967 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC ((yyloc)),
                             static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)),
                             NULL);
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 973 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LibraryModule(LOC ((yyloc)),
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 985 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), 
								SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
      dynamic_cast<ModuleDecl *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
		}
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 998 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)),
								NULL);
		}
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1004 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								NULL,
								static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		}
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1010 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
								static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1022 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = new SIND_DeclList(LOC ((yyloc)));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		}
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1028 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 1042 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = new VFO_DeclList(LOC ((yyloc)));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		}
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1048 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 1088 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].pair_vector));
      delete (yysemantic_stack_[(4) - (4)].pair_vector);
    }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 1093 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr))->get_qname(), (yysemantic_stack_[(4) - (4)].pair_vector)); 
      delete (yysemantic_stack_[(4) - (3)].expr);
      delete (yysemantic_stack_[(4) - (4)].pair_vector);
    }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 1102 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { 
      (yyval.pair_vector) = new std::vector<std::pair<std::string, std::string> > ();
      (yyval.pair_vector)->push_back(*(yysemantic_stack_[(1) - (1)].pair));
      delete (yysemantic_stack_[(1) - (1)].pair);
    }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 1108 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].pair_vector)->push_back(*(yysemantic_stack_[(2) - (2)].pair));
      delete (yysemantic_stack_[(2) - (2)].pair);
      (yyval.pair_vector) = (yysemantic_stack_[(2) - (1)].pair_vector);
    }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 1117 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *s = static_cast<StringLiteral *>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.pair) = new std::pair<std::string, std::string>((yysemantic_stack_[(3) - (1)].strval), s->get_strval());
      delete s;
    }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 1125 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1126 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1127 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1128 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1129 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1130 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1131 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1132 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1133 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1134 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 1171 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 1183 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		}
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1188 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		}
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1199 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_element_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1205 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_function_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1217 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OptionDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
								SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
		}
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1230 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (3)].node));
		}
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1241 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		}
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1246 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		}
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1258 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		}
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1263 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		}
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1274 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::inherit_ns);
		}
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1280 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::no_inherit_ns);
		}
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1286 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::inherit_ns);
		}
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1292 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::no_inherit_ns);
		}
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1311 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)));
		}
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1322 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		}
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1333 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		}
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1340 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)),
								NULL);
		}
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1347 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		}
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1354 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
		}
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 1367 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = new URILiteralList(LOC ((yyloc)));
			uri_list_p->push_back(SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		}
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 1373 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 1388 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1392 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		}
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1402 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1409 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 1417 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
		}
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1424 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 1437 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1444 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->type = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1450 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1457 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(1) - (1)].node));
      d->ext = false;
      (yyval.node) = d;
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1463 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), NULL);
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1467 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1474 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1485 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(), NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1490 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
                               dynamic_cast<SequenceType *> ((yysemantic_stack_[(3) - (3)].node)));
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1499 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(5) - (3)].varnametype);
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								nt->name,
								nt->type,
								(yysemantic_stack_[(5) - (5)].expr));
      delete nt;
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
		}
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1509 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(4) - (3)].varnametype);
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       NULL, true);
      delete nt;
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
		}
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1517 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(6) - (3)].varnametype);
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       (yysemantic_stack_[(6) - (6)].expr), true);
      delete nt;
      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
		}
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1528 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "hash"; }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1530 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "btree"; }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1537 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      IndexDecl *d = dynamic_cast<IndexDecl *> ((yysemantic_stack_[(2) - (2)].node));
      d->create = false;
      (yyval.node) = d;
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1545 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1549 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexDecl *> ((yysemantic_stack_[(2) - (2)].node))->uniq = true;
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1557 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1561 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexDecl *> ((yysemantic_stack_[(2) - (2)].node))->method = (yysemantic_stack_[(2) - (1)].strval);
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1569 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(7) - (2)].sval)), (yysemantic_stack_[(7) - (4)].expr), "",
                          dynamic_cast<IndexFieldList *> ((yysemantic_stack_[(7) - (6)].node)));
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1577 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 1581 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexField *> ((yysemantic_stack_[(3) - (1)].node))->coll = SYMTAB ((yysemantic_stack_[(3) - (3)].sval));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 1589 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexField (LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL);
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1593 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexField (LOC ((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<SequenceType *> ((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1600 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      IndexFieldList *l = new IndexFieldList (LOC ((yyloc)));
      l->fields.push_back (dynamic_cast<IndexField *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
      
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1607 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexFieldList *> ((yysemantic_stack_[(3) - (1)].node))->fields.push_back (dynamic_cast<IndexField *> ((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1617 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		}
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1622 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		}
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1634 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1638 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1642 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL, dynamic_cast<SequenceType *> ((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1646 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType *> ((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1653 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1660 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 1679 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 1688 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL;
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1695 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (1)].node));
      vfo->push_back ((yysemantic_stack_[(3) - (3)].node));
      (yyval.node) = vfo;
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1701 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = new VFO_DeclList (LOC ((yyloc)));
      vfo->push_back ((yysemantic_stack_[(2) - (2)].node));
      (yyval.node) = vfo;
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1710 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 1721 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 1734 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr (LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr))->get_qname(), (yysemantic_stack_[(5) - (5)].expr));
      delete (yysemantic_stack_[(5) - (3)].expr);
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1742 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr (LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1749 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 1761 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1765 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::CONTINUE);
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1772 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IndexStatement (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), IndexStatement::create_stmt);
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1776 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IndexStatement (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), IndexStatement::drop_stmt);
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1780 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IndexStatement (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), IndexStatement::build_stmt);
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1787 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { 
      dynamic_cast<FunctionDecl *>((yysemantic_stack_[(2) - (2)].node))->setComment(SYMTAB((yysemantic_stack_[(2) - (1)].sval)));
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1792 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
      d->deterministic = false;
      (yyval.node) = d;
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1799 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<FunctionDecl *>((yysemantic_stack_[(3) - (3)].node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1807 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1811 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1815 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 1823 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1830 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 1839 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 1851 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 1865 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 1873 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 1887 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(),
								NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
		}
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1894 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
      delete (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1907 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1915 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1926 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QueryBody(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
		}
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1937 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1941 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 1953 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody (LOC ((yyloc)));
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1957 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = dynamic_cast<BlockBody *> ((yysemantic_stack_[(3) - (1)].expr));
      blk->add ((yysemantic_stack_[(3) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1966 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 1970 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 2017 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      ReturnExpr* lReturnExpr = dynamic_cast<ReturnExpr*>((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = new FLWORExpr (LOC ((yyloc)), dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node)), lReturnExpr->get_return_val(), lReturnExpr->get_location(), driver.theCompilerCB->m_config.force_gflwor);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 2026 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 2033 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2037 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2045 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2049 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 2053 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_only_end;
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 2060 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), dynamic_cast<WindowVars *> ((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr), (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 2064 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr), (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 2071 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 2079 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window,
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 2090 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause (LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 2109 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = new FLWORClauseList (LOC ((yyloc)));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 2115 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = dynamic_cast<FLWORClauseList *> ((yysemantic_stack_[(2) - (1)].node));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 2124 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = NULL;
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 2128 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_ofor;
    }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 2138 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForClause(LOC ((yyloc)),
                         dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL);
		}
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2149 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		}
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 2155 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 2169 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 2177 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 2186 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 2196 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 2207 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 2216 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 2226 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 2236 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 2252 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
		}
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 2265 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
		}
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 2277 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)));
			
		}
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 2289 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		}
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 2295 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 2307 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		}
    break;

  case 217:

/* Line 678 of lalr1.cc  */
#line 2313 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 2327 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 2336 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 2346 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 2355 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 2368 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr))->get_qname(),
								NULL, (yysemantic_stack_[(4) - (4)].expr));
      delete (yysemantic_stack_[(4) - (2)].expr);
		}
    break;

  case 223:

/* Line 678 of lalr1.cc  */
#line 2375 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 2387 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(), "", "");
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 2392 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_curr (static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 2401 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), dynamic_cast<PositionalVar *> ((yysemantic_stack_[(1) - (1)].node)), "", "", "");
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 2405 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_posvar (dynamic_cast<PositionalVar *> ((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 2414 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr))->get_qname(), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr))->get_qname());
      delete (yysemantic_stack_[(6) - (3)].expr);
      delete (yysemantic_stack_[(6) - (6)].expr);
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 2420 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", "", static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname());
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 2425 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr))->get_qname(), "");
      delete (yysemantic_stack_[(3) - (3)].expr);
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 2433 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 2449 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 2457 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 2464 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = new GroupSpecList(LOC((yyloc)));
      gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl_p;
    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 2470 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 2481 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname(),
                 NULL);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 2488 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), 
                 static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr))->get_qname(), 
                 dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node))); 
      delete (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 2498 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 2508 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 2513 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)),
								true);
		}
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 2525 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		}
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2531 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 2545 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		}
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2551 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<OrderModifier*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 2563 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL,
								NULL);
		}
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2570 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		}
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2577 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2584 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
								NULL);
		}
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2591 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 2598 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2605 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 2618 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		}
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 2622 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		}
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 2632 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		}
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 2637 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		}
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 2648 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		}
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2659 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2666 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2679 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;
				
		}
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2686 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2698 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(),
								(yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (1)].expr);
		}
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2705 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 2719 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
								(yysemantic_stack_[(8) - (8)].expr));
		}
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2726 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(10) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
								static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr))->get_qname(),
								(yysemantic_stack_[(10) - (10)].expr));
		}
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2740 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		}
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2746 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2758 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2764 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 2778 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
		}
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2789 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2793 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2804 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2808 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2827 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 2831 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 2839 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 2847 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 2855 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 2862 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { /* this call is needed */  driver.lexer->interpretAsLessThan(); }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2863 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 2871 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 2879 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 2887 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 2901 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2905 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		}
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2912 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2925 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 2929 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 2940 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 2944 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 2948 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 2958 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 2962 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 2966 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 2970 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 2974 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 2984 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 2988 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 2993 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3004 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3008 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3012 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3022 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3026 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3038 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3042 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3054 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3058 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3070 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3074 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3086 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3090 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3102 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		}
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3106 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		}
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3110 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3114 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3126 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3130 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3134 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3144 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		}
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3148 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		}
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3152 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		}
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3156 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		}
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3160 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		}
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3164 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		}
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3174 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		}
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3178 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		}
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3182 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		}
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3192 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3196 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3200 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3204 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                            dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(),
                            (yysemantic_stack_[(6) - (5)].expr));
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3216 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		}
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3222 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3234 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		}
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3240 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 3254 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));

		}
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3260 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval))),
								"");      
    }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3302 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		}
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3306 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3310 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3314 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
       RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (rpe == NULL ?
             (yysemantic_stack_[(1) - (1)].expr) :
             new PathExpr(LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3326 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3336 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 3347 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3352 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3362 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3366 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3376 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		}
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3382 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3388 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		}
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3394 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3406 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		}
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3412 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3423 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		}
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3427 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		}
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3431 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		}
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3435 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		}
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3439 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		}
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3443 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		}
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3447 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		}
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3457 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node), false);
		}
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3461 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		}
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3471 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseStep(LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node));
		}
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3475 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC((yyloc)), rev_p, NULL);
		}
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3486 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		}
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3490 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		}
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3494 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		}
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3498 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		}
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3502 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		}
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3517 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3521 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3531 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3535 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3545 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        "",
                        ParseConstants::wild_all);
		}
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3552 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        ParseConstants::wild_elem);
		}
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3559 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        ParseConstants::wild_prefix);
		}
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3572 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3576 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
                          (yysemantic_stack_[(2) - (1)].expr),
                          dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3588 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		}
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3594 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 3608 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3619 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3623 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3627 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3631 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3635 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3639 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3643 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3647 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3657 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3661 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3671 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval));
      delete yylval.decval;
		}
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3676 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival));
      delete yylval.ival;
		}
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3681 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval));
      delete yylval.dval;
		}
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3692 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new VarRef(LOC ((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr))->get_qname());
      delete (yysemantic_stack_[(2) - (2)].expr);
		}
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3703 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		}
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3707 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3718 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		}
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3728 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3739 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3795 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)),
								NULL);
		}
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3801 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3813 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = new ArgList(LOC ((yyloc))); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		}
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3819 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3831 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3835 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3845 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3849 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3853 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3863 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 3871 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 3879 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 3887 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 3895 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 3903 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 3918 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		}
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3924 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3936 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		}
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3942 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 3955 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
		}
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 3972 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		}
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 3977 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		}
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 3988 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		}
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 3992 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 3999 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		}
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 4005 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		}
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 4011 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 4019 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 4033 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		}
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 4037 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 4044 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		}
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 4050 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		}
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4056 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 4064 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 4078 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4083 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4094 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4099 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4110 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		}
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4115 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4120 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		}
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4126 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		}
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4138 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4144 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		}
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4149 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		}
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4154 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4165 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4170 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4185 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4190 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		}
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4207 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CDataSection(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		}
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4222 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4226 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4230 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4234 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4238 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4242 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4252 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4263 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
								NULL);
		}
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4269 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4275 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4280 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4302 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (2)].expr),
								NULL);
		}
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4308 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(5) - (2)].expr),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4314 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4319 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4330 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4340 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4350 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		}
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4356 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4362 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4367 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4378 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		}
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4384 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		}
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4396 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
		}
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4407 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		}
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4413 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4419 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		}
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4456 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		}
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4461 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		}
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4466 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		}
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4477 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4481 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4485 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		}
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4495 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4506 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4510 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4514 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4518 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4522 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4526 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4530 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4534 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4538 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4548 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		}
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4558 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		}
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4562 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4567 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4578 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TextTest(LOC ((yyloc)));
		}
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4588 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		}
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4598 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		}
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4602 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		}
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4606 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		}
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4616 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		}
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4622 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
								NULL);
		}
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4628 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		}
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4634 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		}
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4640 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		}
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4652 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
		}
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4663 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           NULL,
                           NULL,
                           true);
		}
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4670 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                           NULL,
                           true);
		}
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4677 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           false);
		}
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4684 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           true);
		}
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4691 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL,
									true);
		}
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4698 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									false);
		}
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4705 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									true);
		}
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4718 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)));
		}
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4739 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4746 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)),
								true);
		}
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4766 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4806 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::strict_validation);
		}
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4810 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::lax_validation);
    }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4814 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::skip_validation);
    }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4823 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4829 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4835 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4841 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4847 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4854 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4860 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4866 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4872 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4878 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4890 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4895 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4905 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4911 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4923 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4949 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4960 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
       CopyVarList* lList = new CopyVarList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
		}
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4966 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
       CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
       VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
       lList->push_back(lBinding);
       (yyval.expr) = lList;
		}
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4979 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr))->get_qname(), (yysemantic_stack_[(3) - (3)].expr));  
       delete (yysemantic_stack_[(3) - (1)].expr);
    }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4994 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 5001 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 5007 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 5018 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(3) - (2)].name_test_list),
                          (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 5025 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 5035 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 5046 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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

  case 555:

/* Line 678 of lalr1.cc  */
#line 5062 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      CatchExpr::NameTestList *name_test_list = new CatchExpr::NameTestList;
      name_test_list->push_back (static_cast<NameTest *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.name_test_list) = name_test_list;
    }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 5068 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      CatchExpr::NameTestList *name_test_list =
        static_cast<CatchExpr::NameTestList *> ((yysemantic_stack_[(3) - (1)].name_test_list));
      name_test_list->push_back (static_cast<NameTest *> ((yysemantic_stack_[(3) - (3)].node)));
      (yyval.name_test_list) = name_test_list;
    }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 5088 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
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
#line 5105 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { 
      (yyval.expr) = new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval))); 
    }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 5109 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { 
      (yyval.expr) = new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval))); 
    }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 5115 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("xquery"); }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 5116 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty"); }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 5117 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("attribute"); }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 5118 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("comment"); }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 5119 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document-node"); }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 5120 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("element"); }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 5121 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("item"); }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5122 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("if"); }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5123 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("node"); }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5124 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("processing-instruction"); }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5125 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-attribute"); }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5126 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-element"); }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5127 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("text"); }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5128 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("typeswitch"); }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5129 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty-sequence"); }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5130 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("boundary-space"); }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5131 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ft-option"); }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5132 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("base-uri"); }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5133 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lax"); }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5134 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strict"); }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5135 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("idiv"); }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5136 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document"); }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5137 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("not"); }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5138 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sensitive"); }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5139 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insensitive"); }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5140 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("diacritics"); }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5141 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("without"); }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5142 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stemming"); }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5143 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("thesaurus"); }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5144 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stop"); }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5145 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("wildcards"); }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5146 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("entire"); }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5147 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("content"); }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5148 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("word"); }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5149 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("start"); }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5150 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("end"); }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5151 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("most"); }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5152 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("skip"); }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5153 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy"); }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5154 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("value"); }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5155 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eq"); }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5156 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ne"); }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5157 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lt"); }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5158 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("le"); }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5159 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("gt"); }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5160 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ge"); }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5161 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("at"); }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5162 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("context"); }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5163 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("variable"); }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5164 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("return"); }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5165 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("for"); }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5166 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("outer"); }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5167 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sliding"); }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5168 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("tumbling"); }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5169 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("previous"); }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5170 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("next"); }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5171 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("only"); }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5172 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("when"); }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5173 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("count"); }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5174 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("in"); }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5175 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("let"); }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5176 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("where"); }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5177 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("by"); }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5178 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("group"); }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5179 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("order"); }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5180 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stable"); }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5181 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ascending"); }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5182 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("descending"); }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5183 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("greatest"); }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5184 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("least"); }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5185 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("collation"); }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5186 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("some"); }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5187 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("every"); }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5188 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("satisfies"); }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5189 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("case"); }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5190 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("as"); }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5191 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("then"); }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5192 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("else"); }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5193 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("or"); }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5194 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("and"); }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5195 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("instance"); }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5196 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("of"); }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5197 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("castable"); }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5198 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("to"); }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5199 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("div"); }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5200 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("mod"); }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5201 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("union"); }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5202 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("intersect"); }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5203 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("except"); }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5204 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("validate"); }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5205 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("cast"); }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5206 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("treat"); }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5207 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("is"); }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5208 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("preserve"); }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5209 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strip"); }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5210 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("namespace"); }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5211 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("external"); }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5212 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("encoding"); }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5213 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-preserve"); }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5214 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("inherit"); }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5215 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-inherit"); }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5216 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("declare"); }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5217 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("construction"); }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5218 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordering"); }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5219 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("default"); }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5220 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy-namespaces"); }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5221 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("option"); }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5222 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("version"); }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5223 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("import"); }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5224 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema"); }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5225 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("module"); }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5226 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("function"); }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5227 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("score"); }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5228 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ftcontains"); }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5229 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("weight"); }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5230 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("window"); }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5231 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("distance"); }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5232 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("occurs"); }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5233 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("times"); }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5234 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("same"); }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5235 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("different"); }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5236 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lowercase"); }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5237 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("uppercase"); }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5238 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("relationship"); }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5239 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("levels"); }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5240 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("language"); }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5241 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("any"); }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5242 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("all"); }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5243 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("phrase"); }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5244 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exactly"); }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5245 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("from"); }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5246 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("words"); }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5247 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentences"); }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5248 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentence"); }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5249 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("paragraph"); }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5250 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("replace"); }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5251 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("modify"); }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5252 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("first"); }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5253 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insert"); }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 5254 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("before"); }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5255 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("after"); }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 5256 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("revalidation"); }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 5257 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("with"); }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 5258 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nodes"); }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 5259 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("rename"); }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 5260 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("last"); }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 5261 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("delete"); }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 5262 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("into"); }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 5263 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("simple"); }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 5264 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sequential"); }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 5265 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("updating"); }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 5266 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("deterministic"); }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 5267 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nondeterministic"); }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 5268 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordered"); }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 5269 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unordered"); }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 5270 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("returning"); }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 5271 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("block"); }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 5272 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exit"); }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 5273 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("loop"); }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 5274 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("while"); }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 5275 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("break"); }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 5276 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("continue"); }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 5277 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("try"); }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 5278 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("catch"); }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 5279 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eval"); }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 5280 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("using"); }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 5281 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("set"); }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 5282 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("index"); }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 5283 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("create"); }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 5284 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("build"); }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 5285 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unique"); }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 5286 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("on"); }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 5287 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("hash"); }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 5288 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("btree"); }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 5289 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("drop"); }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 5290 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("decimal-format"); }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 5291 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("decimal-separator"); }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 5292 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("grouping-separator"); }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 5293 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("infinity"); }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 5294 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("minus-sign"); }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 5295 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("NaN"); }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 5296 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("percent"); }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 5297 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("per-mille"); }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 5298 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("zero-digit"); }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 5299 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("digit"); }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 5300 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("pattern-separator"); }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 5312 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)),
                          (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 5318 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 5335 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(1) - (1)].node)), NULL, NULL);
		}
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 5339 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(2) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(2) - (2)].node)), NULL);
		}
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 5343 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(3) - (1)].node)), NULL, static_cast<RangeExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		}
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 5347 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(4) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(4) - (2)].node)), static_cast<RangeExpr *> ((yysemantic_stack_[(4) - (4)].expr)));
		}
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 5357 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 5360 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 5363 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 5366 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 5375 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 5378 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 5387 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 5390 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 5399 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 5402 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 5411 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 5414 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 5423 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 5426 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 5429 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 5438 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 5441 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 5450 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), static_cast<StringLiteral *> ((yysemantic_stack_[(1) - (1)].expr)), NULL);
		}
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 5454 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 5464 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 5467 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 5470 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 5473 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 5476 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 5485 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 5494 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 5498 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 5502 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 5506 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 5510 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 5514 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 5518 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 5528 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 5531 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 5534 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 5537 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 5546 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 5549 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 5552 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 5555 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 5564 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 5567 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 5576 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 5579 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 5582 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 5585 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 5588 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 5591 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 5594 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 5603 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 5606 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 5615 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 5618 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 5621 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 5624 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 5633 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 5636 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 5639 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 5642 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 5645 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 5654 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 5657 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 5666 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 5669 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 5678 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 5681 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 5690 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 5693 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 5702 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 5711 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 5714 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 5723 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 5726 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 5729 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 5738 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 5741 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 5744 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 5747 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 5750 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 5759 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 5763 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 5767 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 5771 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 5781 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 5790 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWindow (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (2)].expr)), static_cast<FTUnit *> ((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 5800 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 5809 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 5812 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 5821 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 5824 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 5827 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 5836 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 5839 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 5848 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTIgnoreOption (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		}
    break;



/* Line 678 of lalr1.cc  */
#line 9800 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1198;
  const short int
  xquery_parser::yypact_[] =
  {
      1457, -1198, -1198, -1198, -1198,    33,   -86,   168,   -34,  7711,
     -20,   319,   416, -1198, -1198, -1198, -1198, -1198, -1198,   -16,
     355,  6641, -1198,   171, -1198, -1198, -1198, -1198,   232,   239,
   -1198,   265,    49,   387, -1198, -1198, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198,   228,   244, -1198, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198,  7976, -1198,  6099, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,
   -1198, -1198,  9566, -1198, -1198, -1198, -1198, -1198, -1198, -1198,
   -1198,   362, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198,  1731,  9566, -1198, -1198, -1198, -1198, -1198,
   -1198,   374, -1198, -1198, -1198, -1198,  7179, -1198,  7446, -1198,
   -1198, -1198, -1198, -1198,  9566, -1198, -1198,  5826, -1198, -1198,
   -1198, -1198, -1198, -1198,   381, -1198, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198,    15,   309, -1198, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198,   209,   415,   335, -1198,   390,   325, -1198,
   -1198, -1198, -1198, -1198, -1198,   514, -1198, -1198,   484,   409,
     412, -1198,   417,   510,   515, -1198,   546, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198,   380,   382,   383, -1198, -1198, -1198, -1198,
   -1198,  4188,   663, -1198,  4461, -1198, -1198,   283,  4734,   486,
     487, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,
   -1198,   -49, -1198, -1198, -1198, -1198,   109,  9566, -1198, -1198,
   -1198, -1198, -1198,   520,   583, -1198,   477,   431,   200,   300,
     345,   371, -1198,   615,   496,   592,   593,  5007, -1198, -1198,
   -1198,   111, -1198, -1198,  5826, -1198,    69, -1198,   543,  6099,
   -1198,   543,  6099, -1198, -1198, -1198, -1198,   543, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198,   544, -1198, -1198,  9566,
     657,   658,   501,   501,   657,  9566,   267,   -44,   674,   243,
     334,  9566,   555,   587,    52,  7179,   402,   -30,   353,   674,
   -1198, -1198,   419, -1198, -1198, -1198, -1198, -1198,  7179,  9566,
    4734,   562,   563,  4734, -1198, -1198, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198,  4734,  8241, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198,   564,  4734,  4734,   524,
    4734,   532,  4734,    55,    34, -1198,  4734,  6910,   566, -1198,
    9566,  9566,  9566,  4734,   441,   442, -1198,   601,   602,  9566,
      18,  4734,  8506,   571,   570,   572,   573,   574,   576, -1198,
   -1198, -1198,  9566, -1198,   541,   695,  4734,    40, -1198,   708,
     549, -1198,  4734,   523, -1198,   706,  4734,  4734,   552,  4734,
    4734,  4734,  4734,   509,  9566, -1198, -1198,  4734, -1198, -1198,
    4734,  4734,  9566,   674,   674,   674, -1198, -1198, -1198, -1198,
      33,   355, -1198, -1198,   283,   703,  4734, -1198,  4734,   577,
     239,    49,   387,   622,   575,   578,  4734,  4734, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198,   637, -1198,   -37,  5280,  5280,
    5280, -1198,  5280,  5280, -1198,  5280, -1198,  5280, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198,  5280,  5280,    10,  5280,  5280,
    5280,  5280,  5280,  5280,  5280,  5280,  5280,  5280,  5280,   518,
     653,   654,   655, -1198, -1198, -1198,  2004, -1198, -1198,  5826,
    5826,  4734,   543, -1198, -1198,   543, -1198,   543,  2277,   597,
   -1198,  9566, -1198, -1198, -1198, -1198,   723, -1198, -1198, -1198,
   -1198, -1198, -1198,   645,   646, -1198, -1198,   508,   315,  9566,
     418,   598,   599,   508,   674,   629,   627, -1198, -1198, -1198,
     336,   -41,   367,   730, -1198, -1198,   254, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198,   469, -1198,   630,   611,
   -1198,   582,  4734,  4734,   580,   584, -1198,     2,     3,  2550,
     585,   586, -1198,   594, -1198,   590,  7179,   671,   737,  7179,
     674,   680,   600,   595, -1198,   596,  2823,    -8, -1198,   -26,
     641,   670, -1198,   -43,   603, -1198, -1198,  9566,   -25, -1198,
     604,   570,   228, -1198,   605,   606,   610, -1198,    45,    68,
    3096,    -6, -1198,  9566,   695, -1198,     6,   612, -1198, -1198,
   -1198, -1198,   613, -1198,   -23, -1198, -1198, -1198,   -33,    79,
     688,   550,   569,    36, -1198,   656,  5553, -1198,   614,   618,
     330, -1198, -1198, -1198, -1198, -1198,   607, -1198,    82, -1198,
   -1198,   -22,   619,  9566,  4734,   667, -1198, -1198,   677,  9036,
     681,  4734,   683,   -28,   659,   -48,   583, -1198, -1198, -1198,
   -1198, -1198,  5280, -1198, -1198, -1198,  4734,    10,   203, -1198,
     525,   233,   547,   548, -1198, -1198,   539,   274,   300,   300,
     -15,   345,   345,   345,   345,   371,   371, -1198, -1198,  9036,
    9036,  9566,  9566, -1198,   626, -1198, -1198,   631, -1198, -1198,
   -1198,   102,     4,   365,   597, -1198,   201,   280, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,   508, -1198,
     684,  9301,   673,  4734, -1198, -1198, -1198,   713,   675,  4734,
     674,   674,   508, -1198,   452,   674, -1198, -1198,   531, -1198,
   -1198,   536,   187, -1198, -1198, -1198, -1198, -1198, -1198,   537,
   -1198, -1198,  4734,   674,  4734, -1198,   639,   640,   711,   672,
    9566, -1198,  9566, -1198, -1198,   643, -1198, -1198, -1198,   632,
     691,   674,   676,   694,   731,   674,   678, -1198, -1198, -1198,
     649,   712,  4734,  4734,   687,  4734,   714,  4734,   696,   -74,
   -1198,   257,   581, -1198, -1198,   361,   -25, -1198, -1198, -1198,
     690,  9566, -1198,  9566, -1198, -1198,   662,  4734,   799, -1198,
     182, -1198,    30, -1198, -1198,   809, -1198,   373,  4734,  4734,
    4734,   399,  4734,  4734,  4734,  4734,  4734,  4734,   720,  4734,
    4734,   587,   -21,   664,   484,   608,   693,   727,   703,   767,
   -1198,  4734, -1198,   398,   740, -1198,  9566,   741, -1198,  9566,
     697,   699, -1198,   302, -1198, -1198, -1198,  9566, -1198,  9566,
    4734,   705,  4734,  4734,    -3,   709, -1198,   679,   682, -1198,
     609, -1198,  -119, -1198,   289,   -51,   616,    10,   289,  5280,
    5280,   434, -1198, -1198, -1198, -1198, -1198, -1198, -1198,    10,
     710,   -51, -1198,   588,   800, -1198, -1198, -1198, -1198, -1198,
     716, -1198, -1198, -1198,  4734, -1198,  9566,   762,   164, -1198,
   -1198,  4734, -1198,   484, -1198, -1198, -1198, -1198, -1198,   832,
     432, -1198, -1198, -1198,  4734, -1198, -1198, -1198, -1198, -1198,
   -1198,   589,   -14,   833, -1198,   400, -1198, -1198,   700,   685,
     686, -1198, -1198,  8771,   368, -1198,  3369,   692,   698,   721,
     701,   702, -1198,  4734,   674,   755, -1198, -1198, -1198,   674,
     755,  3642, -1198,  9566, -1198, -1198,  4734, -1198,  9566, -1198,
    4734,  4734,   733,  4734,   726, -1198,   756,   758,  4734,  9566,
     557,   808, -1198, -1198, -1198,  3915,   704,   707, -1198, -1198,
   -1198,   748, -1198,   153, -1198, -1198,   865, -1198, -1198,  4734,
    9566, -1198, -1198,   238, -1198, -1198, -1198,   715,   661,   665,
   -1198, -1198, -1198,   666,   669, -1198, -1198, -1198, -1198, -1198,
     652,  9566,   718, -1198,   743, -1198,   587, -1198, -1198, -1198,
    6372,   608, -1198,  4734,  9566,   740, -1198,   674, -1198,   511,
   -1198,   167,   782, -1198,  4734,   783,   667, -1198,   722,   724,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198,  4734, -1198, -1198,
    4734,   749,  4734, -1198, -1198,  5280, -1198, -1198, -1198, -1198,
   -1198,    47,  5280,  5280,   245, -1198,   547, -1198, -1198,   130,
    5280, -1198, -1198,   548,    10,   621, -1198, -1198, -1198, -1198,
     713,  9036,   774,   807,   728, -1198, -1198, -1198, -1198,   148,
     876,   878,   148,    -4,   197,   207,   757, -1198, -1198,  9566,
     729,   184, -1198, -1198,   732, -1198, -1198, -1198, -1198, -1198,
     789,   818,   674,   755, -1198,   735, -1198, -1198, -1198, -1198,
   -1198,  4734, -1198,  4734,  9566,  9566, -1198,   410, -1198,  4734,
   -1198,   736, -1198, -1198,   799,  9566,   262, -1198,   738,   799,
    9566, -1198, -1198,  4734,  4734,  4734,  4734,  4734, -1198,  4734,
    4734, -1198, -1198,   269, -1198,   739, -1198, -1198, -1198, -1198,
     782, -1198, -1198, -1198,   674, -1198, -1198, -1198, -1198, -1198,
   -1198,  4734, -1198,   345,  5280,  5280,   345,   332, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,  9036,
   -1198,   -14,   -14,   148, -1198, -1198, -1198,    32,   148,   889,
     660,   824, -1198,   824, -1198,  4734,   217,   827,  4734,  9566,
    4734, -1198,  4734,   674, -1198, -1198, -1198, -1198,   855, -1198,
   -1198, -1198, -1198,   -24,   799,  9566, -1198,   734,   799, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198,   806,  6372, -1198, -1198,
   -1198, -1198, -1198,   345,   345,  5280, -1198, -1198, -1198, -1198,
   -1198, -1198,   -51, -1198,   221, -1198,   224, -1198,   823,   713,
    4734, -1198,  9036, -1198,   750, -1198, -1198,   755,   812,   165,
     176, -1198,   742,   799, -1198,   744,  9566, -1198,   345,   668,
     824, -1198, -1198,   674, -1198, -1198,   752,  4734,  9566, -1198,
   -1198,   846,   253, -1198, -1198, -1198, -1198,   761,   366, -1198,
   -1198, -1198,   751, -1198,   231, -1198, -1198, -1198,  4734, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,   825,   791,
   -1198,  9566, -1198,   235,   828,   791,  9566, -1198,   759,   791,
   -1198
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   378,   379,   560,   525,   663,   672,   651,   575,   567,
     583,   574,   565,   673,   712,   711,   713,   714,   710,   569,
     670,   571,   598,   633,   627,   668,   595,   671,   728,   622,
     664,   726,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   665,   579,   573,   566,   667,   642,   572,   577,   737,
     738,   739,   740,   741,   742,   743,   744,   745,   746,   747,
     369,   372,   641,   637,   628,   608,   564,   359,     0,   636,
     644,   652,   357,   632,   395,   609,   610,   666,   358,   361,
     629,   646,     0,   401,   367,   397,   639,   563,   630,   631,
     659,   634,   650,   658,   363,   362,   582,   621,   661,   396,
     649,   654,   568,     0,     0,   316,   647,   657,   662,   660,
     640,   715,   626,   624,   625,   368,     0,   315,     0,   371,
     370,   655,   611,   635,     0,   360,   345,     0,   377,   656,
     638,   645,   653,   648,   716,   602,   607,   606,   605,   604,
     603,   576,   623,     0,   562,   669,   596,   702,   701,   703,
     581,   580,   599,   708,   570,   700,   705,   706,   697,   601,
     643,   699,   709,   707,   698,   600,   704,   717,   718,   719,
     722,   720,   723,   721,   724,   725,   727,   689,   688,   585,
     578,   587,   586,   682,   678,   593,   597,   594,   691,   692,
     675,   584,   687,   686,   683,   679,   696,   690,   685,   681,
     674,   695,   694,   680,   684,   676,   677,   588,   589,   591,
     693,   590,   592,   730,   731,   736,   732,   729,   734,   735,
     733,     0,     0,     2,     0,     4,     6,    12,     0,     0,
       0,    18,    20,    32,    22,    23,    24,    48,    25,    29,
      30,    52,    53,    54,    49,    50,    56,    57,    27,    26,
      31,    51,   174,   173,   170,   171,   172,   175,    28,    11,
     151,   152,   156,   158,   190,   196,     0,     0,   188,   189,
     159,   160,   161,   162,   272,   274,   276,   286,   289,   291,
     294,   299,   302,   305,   307,   309,   311,     0,   313,   319,
     321,     0,   337,   320,   341,   344,   346,   349,   351,     0,
     356,   353,     0,   364,   374,   376,   350,   380,   385,   393,
     386,   387,   388,   391,   392,   389,   390,   408,   410,   411,
     412,   409,   457,   458,   459,   460,   461,   462,   373,   499,
     491,   498,   497,   496,   493,   495,   492,   494,   394,    55,
     163,   164,   166,   165,   167,   168,   375,   561,   169,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      99,   100,     0,   101,   102,   104,   135,   138,     0,     0,
       0,     0,     0,     0,   663,   672,   651,   575,   567,   583,
     574,   565,   569,   670,   571,   633,   728,   622,   726,   612,
     613,   573,   566,   564,   634,     0,     0,   715,   716,   562,
     708,   570,   700,   706,   697,   600,   718,   719,   722,   723,
     721,   724,   727,   730,   731,   736,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   558,     0,     0,     0,   559,
       0,     0,     0,     0,     0,     0,   198,     0,     0,     0,
       0,     0,     0,     0,   567,   574,   565,   571,   564,   365,
     375,   398,     0,   399,     0,   424,     0,     0,   340,     0,
       0,   343,     0,     0,   453,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   122,   119,     0,   130,   131,
       0,     0,     0,     0,     0,     0,     3,     1,     5,     7,
       0,     0,    13,    10,    15,    16,     0,   154,   153,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   176,   195,
     191,   197,   192,   194,   193,   200,   201,     0,     0,     0,
       0,   330,     0,     0,   328,     0,   281,     0,   329,   322,
     327,   326,   325,   324,   323,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   318,   317,   314,     0,   338,   342,     0,
       0,     0,   352,   382,   355,   354,   366,   381,     0,     0,
     140,     0,   141,   137,   136,   139,     0,   113,   114,    65,
      66,   557,    74,     0,     0,    59,    60,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   526,   527,   528,
       0,     0,     0,     0,   786,   787,     0,    64,   779,   780,
     781,   782,   783,   784,   785,   103,     0,   105,     0,     0,
     523,     0,     0,     0,     0,     0,   515,     0,     0,     0,
       0,     0,   504,     0,   505,     0,     0,    83,     0,     0,
       0,    75,     0,     0,   506,     0,     0,     0,   261,     0,
       0,   213,   214,     0,     0,   178,   179,     0,     0,   199,
       0,     0,     0,   501,     0,     0,     0,   509,     0,     0,
       0,     0,   400,   425,   424,   421,     0,     0,   455,   454,
     339,   514,     0,   452,     0,   539,   540,   500,     0,     0,
       0,     0,     0,     0,   545,     0,     0,   128,     0,     0,
       0,   216,   233,   132,   134,   133,     0,    19,     0,    21,
     157,     0,     0,     0,     0,     0,   177,   234,     0,     0,
       0,     0,     0,     0,     0,     0,   273,   275,   279,   285,
     284,   283,     0,   280,   277,   278,     0,     0,     0,   771,
     287,   750,   758,   760,   762,   764,   766,   769,   293,   292,
     290,   296,   297,   298,   295,   300,   301,   304,   303,     0,
       0,     0,     0,   335,     0,   347,   348,     0,   383,   404,
     406,     0,     0,     0,     0,    63,     0,     0,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    34,    35,
       0,     0,    91,     0,    87,    89,    90,    94,    97,     0,
       0,     0,    33,    73,     0,     0,   788,   789,     0,   790,
     794,     0,     0,   823,   792,   793,   822,   791,   795,     0,
     802,   824,     0,     0,     0,   331,     0,     0,     0,     0,
       0,   519,     0,   516,   464,     0,   463,   472,   473,     0,
       0,     0,     0,     0,    76,     0,     0,   508,   507,   474,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     749,     0,     0,   180,   181,     0,   186,   522,   502,   503,
       0,     0,   512,     0,   510,   468,     0,     0,   424,   422,
       0,   413,     0,   402,   403,     0,     8,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   663,     0,     0,     0,     0,     0,     0,    17,     0,
     155,     0,   187,   245,   241,   243,     0,   235,   236,     0,
     568,   576,   480,   481,   487,   488,   490,     0,   203,     0,
       0,     0,     0,     0,     0,     0,   282,     0,     0,   765,
       0,   288,     0,   778,     0,     0,     0,     0,     0,     0,
       0,   751,   755,   773,   754,   777,   775,   774,   776,     0,
       0,     0,   767,   830,   828,   832,   770,   306,   308,   310,
     478,   312,   336,   384,     0,   405,     0,   115,     0,   145,
     143,     0,   142,     0,    71,    72,    69,    70,    36,     0,
       0,    92,    93,    95,     0,    96,    61,    62,    67,    68,
      58,     0,     0,     0,   797,     0,   796,   813,     0,     0,
       0,   333,   332,     0,     0,   267,     0,     0,     0,   523,
       0,     0,   465,     0,     0,    85,    79,    82,    81,     0,
      77,     0,   475,     0,   259,   263,     0,   127,     0,   218,
       0,     0,     0,     0,     0,   182,     0,     0,     0,     0,
     227,     0,   224,   229,   185,     0,     0,     0,   469,   260,
     425,     0,   414,     0,   448,   445,     0,   449,   450,     0,
       0,   451,   444,     0,   419,   447,   446,     0,     0,     0,
     532,   533,   529,     0,     0,   537,   538,   534,   543,   541,
       0,     0,     0,   547,   125,   124,     0,   121,   120,   129,
       0,   548,   549,     0,     0,   242,   254,     0,   255,     0,
     246,   247,   248,   249,     0,   238,     0,   202,     0,     0,
     484,   486,   485,   482,   211,   212,   205,     0,   207,   204,
       0,     0,     0,   772,   768,     0,   825,   826,   846,   845,
     841,     0,     0,     0,     0,   827,   759,   840,   752,     0,
       0,   757,   756,   761,     0,     0,   831,   829,   479,   407,
     147,     0,     0,   116,     0,   144,    37,    88,    98,   811,
       0,     0,   809,   805,     0,     0,     0,    14,   334,     0,
       0,     0,   268,   466,     0,   520,   521,   524,   517,   518,
       0,    84,     0,    78,   476,     0,   262,   264,   215,   220,
     219,     0,   222,     0,     0,     0,   184,   225,   228,     0,
     470,     0,   513,   511,   424,     0,     0,   456,     0,   424,
       0,   420,     9,     0,     0,     0,     0,     0,   546,     0,
       0,   123,   555,     0,   550,     0,   217,   258,   256,   257,
     250,   251,   252,   244,     0,   239,   237,   489,   483,   209,
     206,     0,   208,   847,     0,     0,   833,     0,   844,   843,
     842,   837,   838,   753,   763,   839,   148,   117,   146,     0,
     150,     0,     0,   812,   814,   816,   818,     0,   810,     0,
       0,     0,   800,     0,   798,     0,     0,     0,     0,     0,
       0,   467,     0,     0,    80,   477,   221,   223,   232,   231,
     226,   183,   471,     0,   424,     0,   149,     0,   424,   530,
     531,   535,   536,   542,   544,   126,     0,     0,   551,   748,
     253,   240,   210,   835,   834,     0,   118,   821,   820,   815,
     819,   817,   806,   807,     0,   803,     0,   111,   107,   109,
       0,   106,     0,   269,     0,   265,   271,    86,     0,   434,
     428,   423,     0,   424,   415,     0,     0,   556,   836,     0,
       0,   801,   799,     0,   110,   112,     0,     0,     0,   442,
     436,     0,   435,   437,   443,   440,   430,     0,   429,   431,
     441,   417,     0,   416,     0,   808,   804,   108,     0,   266,
     230,   427,   438,   439,   426,   432,   433,   418,     0,     0,
     270,     0,   552,     0,     0,     0,     0,   553,     0,     0,
     554
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1198, -1198,   725, -1198,   717,   719, -1198,   745, -1198,   433,
     435,  -491, -1198,   339,  -407, -1198, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,  -849,
   -1198, -1198, -1198, -1198,   -56,   143,   591, -1198, -1198, -1198,
   -1198,   579,   625,  -400, -1198, -1198, -1198,   172, -1198,  -859,
   -1198, -1198,  -154, -1198, -1198, -1198, -1198, -1198, -1198,   286,
     247, -1198, -1198,  -217, -1198, -1197,   746,  -101, -1198,   449,
      86, -1198, -1198, -1198, -1198,    83, -1198, -1198,   747, -1198,
   -1198, -1198, -1198, -1198,    29,  -495,  -641, -1198, -1198, -1198,
     -88, -1198, -1198,  -256,   -98,  -151, -1198, -1198, -1198,  -161,
   -1198, -1198,    46,  -158, -1198, -1198,  -153, -1056, -1198,   507,
     -73, -1198, -1198,   -53, -1198, -1198,   447,   450, -1198,  -504,
    -925,   426,    93,  -534,    91,    92, -1198, -1198, -1198, -1198,
   -1198,   753, -1198, -1198, -1198, -1198, -1198,   689, -1198, -1198,
    -114, -1198, -1198, -1198, -1198, -1198, -1198, -1198,   -47, -1086,
   -1198, -1198,   241,    23, -1198,  -539, -1198, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198, -1198,  -867, -1198,   -92, -1198,   298,
    -683, -1198, -1198, -1198, -1198, -1198,  -405,  -395, -1027,  -944,
   -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198, -1198,
     222,  -656,  -759, -1198,   198,  -120,  -725, -1198, -1198, -1198,
   -1198, -1198, -1198, -1198,   551,   553,  -390,   156,     1, -1198,
   -1198, -1198, -1198, -1198, -1198, -1198,   -99, -1198, -1198,  -107,
   -1198,  -353,   -93,    -9, -1198, -1198,   258, -1198, -1198,    51,
      37,  -155,   263, -1198, -1198,    54, -1198,  -724, -1198, -1198,
   -1198, -1198,  -283,  -813, -1198,  -170,  -628, -1198,  -714, -1198,
   -1198, -1198, -1198,  -956, -1198, -1198, -1198, -1198,  -143,    59,
   -1198
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   798,   799,   800,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,  1035,
     650,   247,   248,   804,   805,   806,  1104,   249,   372,   250,
     373,   374,   375,  1347,  1348,  1296,   251,   783,   252,   486,
     706,   912,  1105,   253,   254,   255,   256,   257,   258,   376,
     377,   582,   988,   989,  1081,   992,   259,   260,   508,   261,
     262,   263,   518,   447,   875,   876,   264,   519,   265,   521,
     266,   267,   268,   525,   526,  1060,   734,   269,   661,   710,
     662,   668,  1061,  1062,  1063,   711,   522,   523,   927,   928,
    1255,   524,   924,   925,  1120,  1121,  1122,  1123,   270,   657,
     658,   271,  1024,  1025,   272,   273,   274,   275,   742,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   545,   546,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   572,   573,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   781,   316,   317,   318,  1083,   684,   685,
     686,  1361,  1387,  1388,  1381,  1382,  1389,  1383,  1084,  1085,
     319,   320,  1086,   321,   322,   323,   324,   325,   326,   327,
     979,   735,   932,  1133,   933,   934,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   629,  1028,   338,   339,
     340,   341,   342,   343,   344,   703,   704,   345,  1111,  1112,
    1243,  1036,   438,   346,   347,   348,   750,   961,   751,   752,
     753,   754,   755,   756,   757,   962,   963,   617,   618,   619,
     620,   621,  1344,  1345,   622,  1283,  1182,  1287,  1284,   623,
     624,   965,   976,  1154,   966,   967,   972,   968,  1271,  1150,
     951
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       426,   890,   464,   864,   935,   592,  1040,   869,   749,  1016,
     977,   978,   439,   471,   719,  1165,   626,   761,   762,   763,
     764,   459,   868,   467,  1242,  1082,   738,   964,   739,   740,
       4,   741,   733,   743,  1158,   872,   473,  1151,  1074,  1075,
     730,   744,   745,   729,   935,   935,  1328,   688,   671,   729,
     506,   730,  1340,   897,   591,  1109,  1231,   453,  1051,   460,
     729,  1359,   610,   378,   818,  1251,  1252,   349,   350,   351,
     352,   353,   354,   461,  1180,   591,   935,   506,  1106,   355,
     647,   651,   601,   672,  1151,   356,   602,  1146,   943,   867,
    1264,   861,   941,   861,   945,   465,   357,   358,   895,   731,
     359,   840,   842,   360,   361,   444,   445,   439,   940,   469,
     863,   383,    74,   589,   986,   470,   349,   350,   351,   352,
     353,   354,   427,   603,    85,  1076,   891,  1147,   355,   432,
     507,  1181,   548,  1140,  1175,   908,   362,   363,   364,   648,
     713,   714,   715,  1077,   881,  1078,   590,  1360,    99,   549,
     604,  1003,   746,   361,   509,   747,   896,   920,  1107,   446,
     510,  1074,  1075,   511,   512,   901,  1265,   883,   862,  1379,
     887,   513,  1079,  1074,   898,   899,   104,   841,   843,   987,
     568,   873,   365,   649,  1074,   362,   363,   919,   732,   900,
    1203,   892,   116,   673,  1330,  1385,   611,  1152,  1153,  1231,
     819,   984,  1185,   689,   646,  1071,  1082,  1341,   749,   749,
     605,   612,  1412,  1080,   732,  1054,  1082,   474,  1417,   732,
     882,   874,  1420,     4,   613,   732,   614,  1290,  1052,   820,
     821,   143,   822,   823,   732,  1273,   615,  1162,   946,   616,
     944,  1367,   366,   884,  1152,  1153,  1074,  1075,  1076,   569,
     570,   813,   574,   566,   379,   576,  1289,  1379,   527,   732,
     909,  1074,   748,  1172,  1190,  1117,  1077,   514,  1078,   515,
    1074,  1075,   606,   367,  1281,  1013,   118,   985,  1077,   631,
    1078,   440,   634,   516,  1119,   628,   902,   903,  1380,  1077,
     460,  1078,  1014,   460,  1299,  1079,  1291,   854,   935,   104,
    1386,   904,  1072,  1141,   635,    74,  1293,  1079,   500,   517,
     380,   368,   369,   370,   371,   116,  1350,    85,  1079,   555,
    1370,   952,   367,  1370,   501,   610,   640,   641,   556,   643,
    1408,   645,  1015,  1076,  1414,   652,  1225,  1282,   994,  1173,
     579,    99,   441,   729,   655,   746,   586,   548,   747,   442,
     676,  1077,   597,  1078,   143,   995,   439,  1076,  1300,  1082,
     368,   369,   370,   371,   549,   687,  1077,  1073,  1078,   439,
     630,   692,  1292,   449,  1074,  1077,  1402,  1078,   381,   382,
    1079,   433,  1294,   916,   104,  1385,  1369,   550,  1268,   450,
     953,   998,  1351,  1053,  1269,  1079,  1371,   638,   593,  1372,
     116,   801,  1270,   434,  1079,   998,  1409,   443,   104,   551,
    1415,   991,  1277,   594,  1326,  1384,  1390,   996,   749,  1056,
    1057,  1230,  1058,   476,   116,   477,  1159,   719,   439,   917,
     749,   659,   660,   663,   997,   552,  1130,   587,  1384,   143,
     670,   448,   802,   679,  1390,  1315,   935,   803,   553,   730,
    1027,   588,  1030,   659,  1357,   775,   776,  1006,  1007,   611,
    1023,   428,  1010,   143,   429,   774,  1131,  1327,  1056,  1057,
     777,  1059,   462,  1191,   612,   705,   954,   955,   956,  1077,
    1019,  1078,   554,   712,  1132,  1116,   957,   613,  1013,   614,
    1405,  1066,   990,  1067,   958,   827,  1117,   557,   730,   615,
     959,   960,   616,  1268,   595,  1184,  1118,   991,  1079,  1269,
     558,   973,   974,   475,  1276,  1119,   466,  1270,   596,  1335,
    1336,   555,   952,   472,   828,   829,   610,   830,   831,   664,
     556,   836,   837,   975,   555,   349,   350,   351,   845,   482,
     354,  1313,   575,   556,   483,   808,  1317,  1148,   577,   479,
     809,   480,  1149,   850,   935,   860,   853,  1396,   430,   802,
     478,   431,   695,   696,   803,   698,   699,   700,   701,  1339,
    1008,  1009,   784,   707,  1339,   816,   708,   709,   817,   886,
     788,   789,   790,   791,   792,   793,   794,   795,   796,   797,
     807,   953,   720,  1376,  1088,   778,  1089,   580,   778,   530,
     778,   585,   726,   727,   481,   913,   824,   531,   532,   825,
     533,  1263,   607,   608,   609,  1056,  1057,   534,  1266,  1267,
    1093,   535,  1094,   536,   484,   749,   485,   935,   537,  1248,
    1249,  1362,   369,   370,   371,  1365,   487,   439,   583,   584,
     439,   758,   759,   488,   538,   947,   765,   766,   489,   767,
     768,   980,   980,  1337,  1338,   490,   492,   491,   871,   493,
     611,   494,   495,   497,   780,   504,   505,   529,   539,   540,
     541,   542,   543,   544,   888,   612,   528,   954,   955,   956,
    1392,  1201,   547,   559,   560,   561,   571,   562,   613,   578,
     614,   349,   581,  1374,   591,   958,   598,   599,   369,   642,
     615,  1160,   960,   616,   632,   633,   639,   644,   656,   665,
     666,   667,   669,   680,   922,   406,   682,   429,   431,   437,
     936,   452,   683,   690,   691,   693,   694,   697,   718,   702,
    1333,  1334,   723,  1020,   724,   722,   728,   725,   769,   770,
     771,   772,   782,   785,   786,   787,   814,   810,   811,   815,
     826,   832,   833,   834,   835,   838,   839,   846,   847,   851,
     936,   936,   936,   936,  1247,   849,   848,   852,   855,   866,
     857,   858,   856,   865,   905,   870,   906,   926,   921,   877,
     878,   879,   880,   907,   893,   894,   918,   929,   910,   914,
     915,   937,   936,   939,   950,   942,   971,   969,   982,   729,
     970,  1368,  1011,  1023,   983,   803,   999,  1004,  1012,  1017,
     923,  1021,  1022,  1034,  1026,  1032,  1038,   938,  1033,  1039,
    1041,  1042,  1043,  1046,  1048,  1037,  1070,  1055,  1050,  1087,
    1101,  1029,  1065,  1029,  1068,  1113,  1108,  1114,   603,  1124,
    1126,  1137,  1128,  1110,  1129,  1142,  1164,  1167,  1171,  1304,
    1168,  1143,     4,  1183,  1202,  1197,  1145,  1144,  1188,  1186,
    1166,  1179,  1213,  1155,  1187,  1211,  1214,  1195,  1215,  1219,
    1224,  1227,   630,  1196,   630,  1240,  1198,  1199,  1237,  1222,
    1117,  1254,  1223,  1233,   986,  1261,  1275,  1234,  1235,  1002,
    1174,  1236,  1239,  1279,  1232,  1005,  1285,  1257,  1286,  1258,
    1280,  1331,  1295,  1298,  1301,  1302,  1303,  1305,  1312,  1342,
    1316,  1329,  1013,  1352,  1358,  1343,  1366,  1125,  1018,  1364,
     527,  1373,  1378,  1395,  1377,  1194,  1398,  1391,  1134,  1393,
    1135,  1401,  1404,   991,  1419,  1411,  1407,   716,  1416,   717,
    1205,   498,   812,   499,  1177,  1001,   496,   625,  1044,  1045,
    1375,  1047,  1241,  1049,   600,  1278,   993,   721,  1127,  1064,
    1208,  1310,  1218,  1246,  1221,  1256,  1253,  1115,  1250,   681,
    1206,  1192,   502,  1069,   503,   736,   760,  1170,  1228,   737,
     567,  1226,   889,  1406,  1090,  1091,  1092,  1403,  1095,  1096,
    1097,  1098,  1099,  1100,   981,  1102,  1103,   627,  1031,  1000,
    1176,   674,  1238,   675,  1244,   948,  1163,   923,  1156,  1274,
    1346,   949,  1288,   520,   936,  1161,  1272,  1157,     0,     0,
    1397,     0,     0,     0,     0,     0,  1136,     0,  1138,  1139,
       0,     0,     0,     0,   659,     0,     0,     0,     0,   663,
     565,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1217,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1169,  1229,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1178,     0,   705,     0,     0,     0,     0,     0,     0,     0,
       0,   460,     0,     0,     0,   712,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1200,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1207,     0,     0,     0,  1209,  1210,     0,  1212,
       0,     0,     0,     0,  1216,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   936,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1297,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1245,
       0,     0,     0,     0,     0,  1308,  1309,     0,     0,     0,
     923,     0,     0,     0,     0,     0,  1314,     0,     0,     0,
       0,  1318,     0,  1259,     0,     0,  1260,     0,  1262,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     936,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1354,     0,     0,     0,     0,     0,     0,  1306,     0,  1307,
       0,     0,     0,     0,     0,  1311,  1363,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   460,  1319,
    1320,  1321,  1322,  1323,     0,  1324,  1325,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   936,     0,     0,     0,  1332,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1394,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1400,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1349,     0,     0,  1353,     0,  1355,     0,  1356,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1413,     0,     0,     0,     0,  1418,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1349,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1399,     0,     0,     0,     1,     0,     0,
       0,     0,     0,     0,     2,     3,     0,     4,     0,     0,
       0,     0,     5,     6,  1410,     7,     8,     9,    10,    11,
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
     221,     1,     0,     0,     0,     0,     0,     0,     2,     3,
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
     120,   121,     0,     0,     0,   122,   463,   123,   124,   125,
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
       0,     0,   119,   120,   121,     0,   773,     0,   122,     0,
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
       0,   117,   118,     0,     0,   119,   120,   121,     0,     0,
       0,   122,   779,   123,   124,   125,     0,   126,   127,   128,
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
     121,     0,   844,     0,   122,     0,   123,   124,   125,     0,
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
       0,   119,   120,   121,     0,   859,     0,   122,     0,   123,
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
     117,   118,     0,     0,   119,   120,   121,     0,   885,     0,
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
       0,  1193,     0,   122,     0,   123,   124,   125,     0,   126,
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
       3,     0,     4,     0,     0,     0,     0,   384,   385,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,   393,    21,    22,    23,    24,    25,    26,
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
     119,   120,   121,     0,  1204,     0,   122,     0,   123,   124,
     125,     0,   126,   127,   128,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   409,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,     1,     0,     0,     0,     0,
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
     118,     0,     0,   119,   120,   121,     0,  1220,     0,   122,
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
       0,   144,   145,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,     0,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,     1,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     4,     0,     0,     0,     0,     5,     6,     0,     7,
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
       0,     0,   119,   120,   121,     0,     0,     0,   122,     0,
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
       0,     0,   384,   385,     0,     7,   387,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,   392,   393,    21,
      22,   395,    24,    25,    26,    27,     0,   396,   397,    30,
     398,   399,   400,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,     0,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,     0,    72,    73,     0,     0,     0,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
       0,    85,     0,    86,    87,    88,    89,     0,    90,     0,
       0,     0,   404,    92,    93,    94,    95,     0,     0,     0,
       0,     0,    96,    97,    98,    99,   100,   101,   102,     0,
       0,     0,   103,   104,   563,   106,   107,     0,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   116,
       0,   564,   118,     0,     0,   119,   120,   121,     0,     0,
       0,   122,     0,   123,   124,   125,     0,   126,   127,   128,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     409,   145,     0,   146,   147,   148,   149,   150,   151,   152,
     410,   154,   412,   156,   413,   414,   159,   160,   161,   162,
     163,   164,   415,   166,   167,   416,   417,   418,   171,   419,
     420,   421,   175,   422,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
       0,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   423,   424,   425,   216,   217,   218,   219,   220,
       1,     0,     0,     0,     0,     0,     0,     2,     3,     0,
       4,     0,     0,     0,     0,   384,   385,     0,     7,   387,
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
     101,   102,     0,     0,     0,   103,   104,   105,   106,   107,
       0,     0,     0,     0,   108,   109,   110,   111,   112,   113,
     114,   115,   116,     0,   117,   118,     0,     0,   119,   120,
     121,     0,     0,     0,   122,     0,   123,   124,   125,     0,
     126,   127,   128,     0,   129,     0,   130,   131,   132,   133,
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
       2,     3,     0,     4,     0,     0,     0,     0,   911,   385,
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
       0,   119,   120,   121,     0,     0,     0,   122,     0,   123,
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
       0,   384,   385,     0,   386,   387,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,   392,   393,    21,    22,
     395,    24,    25,    26,    27,     0,   396,   397,    30,   398,
     399,   400,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,    72,    73,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,     0,
      85,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   404,    92,    93,    94,    95,     0,     0,     0,     0,
       0,    96,    97,    98,    99,   100,   101,   102,     0,     0,
       0,   103,   104,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   111,   112,   113,   114,   115,   116,     0,
       0,     0,     0,     0,   119,   120,   121,     0,     0,     0,
     122,     0,   123,   124,   125,     0,     0,     0,   128,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   409,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   410,
     154,   412,   156,   413,   414,   159,   160,   161,   162,   163,
     164,   415,   166,   167,   416,   417,   418,   171,   419,   420,
     421,   175,   422,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   423,   424,   425,   216,   217,   218,   219,   220,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     0,
       0,     0,     0,     0,   384,   385,     0,   386,   387,   454,
     389,   455,   456,    13,    14,    15,    16,    17,    18,   392,
     393,   457,    22,   395,    24,    25,    26,    27,     0,   396,
     397,    30,   398,   399,   400,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,     0,     0,    62,     0,    63,    64,    65,   458,     0,
       0,    69,    70,    71,     0,     0,     0,    73,     0,     0,
       0,     0,    75,    76,    77,     0,     0,    80,    81,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,     0,
      90,     0,     0,     0,   404,    92,    93,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,     0,   100,   101,
     102,     0,     0,     0,     0,     0,     0,   106,   107,     0,
       0,     0,     0,   108,   109,   110,   407,   112,   113,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
       0,     0,     0,   122,     0,   123,   124,     0,     0,     0,
       0,   128,     0,   129,     0,   130,   131,   132,   133,   408,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
       0,     0,   409,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   410,   154,   412,   156,   413,   414,   159,   160,
     161,   162,   163,   164,   415,   166,   167,   416,   417,   418,
     171,   419,   420,   421,   175,   422,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,     0,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   423,   424,   425,   216,   217,   218,
     219,   220,     1,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     0,     0,     0,     0,     0,   384,   385,     0,
     386,   387,   388,   389,   390,   391,    13,    14,    15,    16,
      17,    18,   392,   393,   394,    22,   395,    24,    25,    26,
      27,     0,   396,   397,    30,   398,   399,   400,    34,    35,
      36,    37,    38,    39,    40,    41,    42,   401,   402,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,     0,     0,    62,     0,    63,    64,
      65,   403,     0,     0,    69,    70,    71,     0,     0,     0,
      73,     0,     0,     0,     0,    75,    76,    77,     0,     0,
      80,    81,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,     0,    90,     0,     0,     0,   404,    92,    93,
       0,     0,     0,     0,     0,     0,     0,    96,    97,    98,
       0,   100,   101,   102,     0,     0,     0,     0,     0,     0,
     106,   107,     0,     0,     0,     0,   108,   109,   110,   407,
     112,   113,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,     0,     0,     0,   122,     0,   123,     0,
       0,     0,     0,     0,   128,     0,   129,     0,   130,   131,
     132,   133,   408,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,     0,     0,   409,   145,     0,   146,   147,
     148,   149,   150,   151,   152,   410,   411,   412,   156,   413,
     414,   159,   160,   161,   162,   163,   164,   415,   166,   167,
     416,   417,   418,   171,   419,   420,   421,   175,   422,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   423,   424,   425,
     216,   217,   218,   219,   220,   435,     0,     0,     0,     3,
       0,     0,     0,     0,     0,     0,   384,   385,     0,   386,
     387,   388,   389,   390,   391,    13,    14,    15,    16,    17,
      18,   392,   393,   394,    22,   395,    24,    25,    26,    27,
       0,   396,   397,    30,   398,   399,   400,    34,    35,    36,
      37,    38,    39,    40,    41,    42,   401,   402,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,     0,    62,     0,    63,    64,    65,
     403,     0,     0,    69,    70,    71,     0,     0,     0,    73,
       0,     0,     0,     0,    75,    76,    77,     0,     0,    80,
      81,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,     0,    90,     0,     0,     0,   404,    92,    93,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    98,     0,
     100,   101,   102,   436,     0,     0,   437,     0,     0,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   407,   112,
     113,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,     0,     0,     0,   122,     0,   123,     0,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   408,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,     0,     0,   409,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   410,   411,   412,   156,   413,   414,
     159,   160,   161,   162,   163,   164,   415,   166,   167,   416,
     417,   418,   171,   419,   420,   421,   175,   422,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   423,   424,   425,   216,
     217,   218,   219,   220,   435,     0,     0,     0,     3,     0,
     653,     0,     0,     0,     0,   384,   385,     0,   386,   387,
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
     121,     0,     0,     0,   122,   654,   123,     0,     0,     0,
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
     218,   219,   220,   435,     0,     0,     0,     3,     0,     0,
       0,     0,     0,     0,   384,   385,     0,   386,   387,   388,
     389,   390,   391,    13,    14,    15,    16,    17,    18,   392,
     393,   394,    22,   395,    24,    25,    26,    27,     0,   396,
     397,    30,   398,   399,   400,    34,    35,    36,    37,    38,
      39,    40,    41,    42,   401,   402,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,     0,     0,    62,     0,    63,    64,    65,   403,     0,
       0,    69,    70,    71,     0,     0,     0,    73,     0,     0,
       0,     0,    75,    76,    77,     0,     0,    80,    81,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,     0,
      90,     0,     0,     0,   404,    92,    93,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,     0,   100,   101,
     102,     0,     0,     0,     0,     0,     0,   106,   107,     0,
       0,     0,     0,   108,   109,   110,   407,   112,   113,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
       0,     0,     0,   122,     0,   123,     0,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   408,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
       0,     0,   409,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   410,   411,   412,   156,   413,   414,   159,   160,
     161,   162,   163,   164,   415,   166,   167,   416,   417,   418,
     171,   419,   420,   421,   175,   422,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,     0,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   423,   424,   425,   216,   217,   218,
     219,   220,   468,     0,     3,     0,     0,     0,     0,     0,
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
     122,     0,   123,     0,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   408,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   409,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   410,
     411,   412,   156,   413,   414,   159,   160,   161,   162,   163,
     164,   415,   166,   167,   416,   417,   418,   171,   419,   420,
     421,   175,   422,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   423,   424,   425,   216,   217,   218,   219,   220,     3,
       0,     0,     0,     0,     0,     0,   384,   385,     0,   386,
     387,   388,   389,   390,   391,    13,    14,    15,    16,    17,
      18,   392,   393,   394,    22,   395,    24,    25,    26,    27,
       0,   396,   397,    30,   398,   399,   400,    34,    35,    36,
      37,    38,    39,    40,    41,    42,   401,   402,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,     0,    62,     0,    63,    64,    65,
     403,     0,     0,    69,    70,    71,     0,     0,     0,    73,
       0,     0,     0,     0,    75,    76,    77,     0,     0,    80,
      81,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,     0,    90,     0,     0,     0,   404,    92,    93,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    98,     0,
     100,   101,   102,   405,     0,     0,   406,     0,     0,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   407,   112,
     113,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,     0,     0,     0,   122,     0,   123,     0,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   408,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,     0,     0,   409,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   410,   411,   412,   156,   413,   414,
     159,   160,   161,   162,   163,   164,   415,   166,   167,   416,
     417,   418,   171,   419,   420,   421,   175,   422,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   423,   424,   425,   216,
     217,   218,   219,   220,     3,     0,     0,     0,     0,     0,
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
       0,    96,    97,    98,     0,   100,   101,   102,   451,     0,
       0,   452,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   407,   112,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,     0,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   408,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   409,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   410,
     411,   412,   156,   413,   414,   159,   160,   161,   162,   163,
     164,   415,   166,   167,   416,   417,   418,   171,   419,   420,
     421,   175,   422,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   423,   424,   425,   216,   217,   218,   219,   220,     3,
       0,     0,     0,     0,     0,     0,   384,   385,     0,   386,
     387,   388,   389,   390,   391,    13,    14,    15,    16,    17,
      18,   392,   393,   394,    22,   395,    24,    25,    26,    27,
       0,   396,   397,    30,   398,   399,   400,    34,    35,    36,
      37,    38,    39,    40,    41,    42,   401,   402,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,     0,    62,     0,    63,    64,    65,
     403,     0,     0,    69,    70,    71,     0,     0,     0,    73,
       0,     0,     0,     0,    75,    76,    77,     0,     0,    80,
      81,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,     0,    90,     0,     0,     0,   404,    92,    93,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    98,     0,
     100,   101,   102,     0,     0,     0,     0,     0,     0,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   407,   112,
     113,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,     0,     0,     0,   122,   636,   123,     0,     0,
       0,     0,     0,   637,     0,   129,     0,   130,   131,   132,
     133,   408,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,     0,     0,   409,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   410,   411,   412,   156,   413,   414,
     159,   160,   161,   162,   163,   164,   415,   166,   167,   416,
     417,   418,   171,   419,   420,   421,   175,   422,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   423,   424,   425,   216,
     217,   218,   219,   220,     3,     0,     0,     0,     0,     0,
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
     122,   677,   123,     0,     0,     0,     0,     0,   678,     0,
     129,     0,   130,   131,   132,   133,   408,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   409,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   410,
     411,   412,   156,   413,   414,   159,   160,   161,   162,   163,
     164,   415,   166,   167,   416,   417,   418,   171,   419,   420,
     421,   175,   422,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   423,   424,   425,   216,   217,   218,   219,   220,     3,
       0,     0,     0,     0,     0,     0,   384,   385,     0,   386,
     387,   454,   389,   455,   456,    13,    14,    15,    16,    17,
      18,   392,   393,   457,    22,   395,    24,    25,    26,    27,
       0,   396,   397,    30,   398,   399,   400,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,     0,    62,     0,    63,    64,    65,
     458,     0,     0,    69,    70,    71,     0,     0,     0,    73,
       0,     0,     0,     0,    75,    76,    77,     0,     0,    80,
      81,  1189,     0,     0,     0,     0,     0,    86,    87,    88,
      89,     0,    90,     0,     0,     0,   404,    92,    93,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    98,     0,
     100,   101,   930,     0,     0,     0,     0,     0,     0,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   407,   112,
     113,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,     0,     0,     0,   122,     0,   123,   124,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   408,   135,   136,   137,   138,   139,   140,     0,     0,
     931,   142,     0,     0,   409,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   410,   154,   412,   156,   413,   414,
     159,   160,   161,   162,   163,   164,   415,   166,   167,   416,
     417,   418,   171,   419,   420,   421,   175,   422,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   423,   424,   425,   216,
     217,   218,   219,   220,     3,     0,     0,     0,     0,     0,
       0,   384,   385,     0,   386,   387,   454,   389,   455,   456,
      13,    14,    15,    16,    17,    18,   392,   393,   457,    22,
     395,    24,    25,    26,    27,     0,   396,   397,    30,   398,
     399,   400,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      62,     0,    63,    64,    65,   458,     0,     0,    69,    70,
      71,     0,     0,     0,    73,     0,     0,     0,     0,    75,
      76,    77,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,    90,     0,     0,
       0,   404,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,   100,   101,   930,     0,     0,
       0,     0,     0,     0,   106,   107,     0,     0,     0,     0,
     108,   109,   110,   407,   112,   113,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     122,     0,   123,   124,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   408,   135,   136,   137,
     138,   139,   140,     0,     0,   931,   142,     0,     0,   409,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   410,
     154,   412,   156,   413,   414,   159,   160,   161,   162,   163,
     164,   415,   166,   167,   416,   417,   418,   171,   419,   420,
     421,   175,   422,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   423,   424,   425,   216,   217,   218,   219,   220,     3,
       0,     0,     0,     0,     0,     0,   384,   385,     0,   386,
     387,   454,   389,   455,   456,    13,    14,    15,    16,    17,
      18,   392,   393,   457,    22,   395,    24,    25,    26,    27,
       0,   396,   397,    30,   398,   399,   400,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,     0,    62,     0,    63,    64,    65,
     458,     0,     0,    69,    70,    71,     0,     0,     0,    73,
       0,     0,     0,     0,    75,    76,    77,     0,     0,    80,
      81,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,     0,    90,     0,     0,     0,   404,    92,    93,     0,
       0,     0,     0,     0,     0,     0,    96,    97,    98,     0,
     100,   101,   930,     0,     0,     0,     0,     0,     0,   106,
     107,     0,     0,     0,     0,   108,   109,   110,   407,   112,
     113,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,     0,     0,     0,   122,     0,   123,   124,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   408,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,     0,     0,   409,   145,     0,   146,   147,   148,
     149,   150,   151,   152,   410,   154,   412,   156,   413,   414,
     159,   160,   161,   162,   163,   164,   415,   166,   167,   416,
     417,   418,   171,   419,   420,   421,   175,   422,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,     0,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   423,   424,   425,   216,
     217,   218,   219,   220,     3,     0,     0,     0,     0,     0,
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
     122,     0,   123,     0,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   408,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   409,
     145,     0,   146,   147,   148,   149,   150,   151,   152,   410,
     411,   412,   156,   413,   414,   159,   160,   161,   162,   163,
     164,   415,   166,   167,   416,   417,   418,   171,   419,   420,
     421,   175,   422,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,     0,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   423,   424,   425,   216,   217,   218,   219,   220
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         9,   684,   103,   659,   729,   358,   855,   663,   547,   822,
     769,   770,    21,   127,   505,   971,   369,   551,   552,   553,
     554,    68,   663,   116,  1110,   892,   530,   751,   532,   533,
      20,   535,   527,   537,   959,    60,    21,    88,     8,     9,
      88,   545,   546,    86,   769,   770,  1243,     7,    30,    86,
      99,    88,    20,    86,    20,   914,  1083,    66,   132,    68,
      86,    85,    92,   149,   105,  1121,  1122,    34,    35,    36,
      37,    38,    39,    82,    88,    20,   801,    99,    99,    46,
     433,   434,    30,    65,    88,    52,    34,   206,   136,   132,
      43,    99,   733,    99,   735,   104,    63,    64,   121,   136,
      67,    99,    99,    70,    71,    56,    57,   116,   136,   118,
     136,   145,   102,   157,   110,   124,    34,    35,    36,    37,
      38,    39,   142,    71,   114,    95,   120,   246,    46,   145,
     179,   145,   147,   136,   993,    99,   103,   104,   105,   105,
     493,   494,   495,   113,    99,   115,   190,   171,   138,   164,
      98,   807,   142,    71,    45,   145,   179,   179,   179,   110,
      51,     8,     9,    54,    55,    86,   119,    99,   176,     4,
     176,    62,   142,     8,   207,   208,   146,   175,   175,   175,
     294,   206,   149,   149,     8,   103,   104,   105,   262,   222,
    1039,   185,   162,   175,  1250,    19,   226,   248,   249,  1226,
     241,    99,  1015,   163,   149,   888,  1073,   175,   747,   748,
     158,   241,  1409,   183,   262,   871,  1083,   202,  1415,   262,
     175,   246,  1419,    20,   254,   262,   256,  1183,   869,   270,
     271,   201,   273,   274,   262,  1160,   266,   961,   742,   269,
     735,  1327,   209,   175,   248,   249,     8,     9,    95,   180,
     181,   604,   299,   142,    86,   302,   260,     4,   267,   262,
     224,     8,   252,    99,  1023,    98,   113,   158,   115,   160,
       8,     9,   365,   240,   126,    88,   165,   175,   113,   380,
     115,   110,   383,   174,   117,   378,   207,   208,   123,   113,
     299,   115,   105,   302,   110,   142,    99,   650,  1023,   146,
     124,   222,   120,   944,   405,   102,    99,   142,    25,   200,
     142,   278,   279,   280,   281,   162,    99,   114,   142,   189,
      99,    88,   240,    99,    41,    92,   427,   428,   198,   430,
      99,   432,   145,    95,    99,   436,   183,   189,   137,   175,
     349,   138,   110,    86,   437,   142,   355,   147,   145,   110,
     451,   113,   361,   115,   201,   154,   365,    95,   174,  1226,
     278,   279,   280,   281,   164,   466,   113,   185,   115,   378,
     379,   472,   175,   145,     8,   113,   123,   115,   210,   211,
     142,    26,   175,    53,   146,    19,  1342,   187,   258,   145,
     157,   798,   175,   136,   264,   142,   175,   406,   155,   175,
     162,    86,   272,    48,   142,   812,   175,   142,   146,   109,
     175,   142,  1171,   170,   145,  1359,  1360,   137,   957,    58,
      59,   183,    61,   214,   162,   216,   960,   918,   437,    99,
     969,   440,   441,   442,   154,   135,   134,   170,  1382,   201,
     449,    54,   127,   452,  1388,   183,  1171,   132,   148,    88,
     840,   184,   842,   462,  1303,   569,   570,   810,   811,   226,
      92,   142,   815,   201,   145,   566,   164,   198,    58,    59,
     571,   110,   110,   105,   241,   484,   243,   244,   245,   113,
     833,   115,   182,   492,   182,    87,   253,   254,    88,   256,
     124,   881,   127,   883,   261,   241,    98,   126,    88,   266,
     267,   268,   269,   258,   170,   105,   108,   142,   142,   264,
     139,   237,   238,   204,  1170,   117,   142,   272,   184,   187,
    1279,   189,    88,   142,   270,   271,    92,   273,   274,   443,
     198,   632,   633,   259,   189,    34,    35,    36,   639,   214,
      39,  1224,   301,   198,   219,   127,  1229,   258,   307,   214,
     132,   216,   263,   646,  1279,   656,   649,  1370,   142,   127,
     145,   145,   476,   477,   132,   479,   480,   481,   482,  1283,
     118,   119,   581,   487,  1288,   239,   490,   491,   242,   680,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
     599,   157,   506,  1352,   221,   572,   223,   350,   575,   122,
     577,   354,   516,   517,   214,   706,   239,   130,   131,   242,
     133,  1145,   210,   211,   212,    58,    59,   140,  1152,  1153,
     221,   144,   223,   146,   110,  1164,   142,  1352,   151,   118,
     119,  1314,   279,   280,   281,  1318,   227,   646,   352,   353,
     649,   548,   549,   231,   167,   746,   555,   556,   231,   557,
     558,   771,   772,  1281,  1282,   145,   110,   142,   667,   279,
     226,   279,   279,     0,   578,   179,   179,    84,   191,   192,
     193,   194,   195,   196,   683,   241,   156,   243,   244,   245,
    1363,  1034,   251,    68,   188,    93,   143,    94,   254,   145,
     256,    34,    34,  1349,    20,   261,   141,   110,   279,   175,
     266,   267,   268,   269,   142,   142,   142,   175,   142,   268,
     268,   110,   110,   142,   723,   145,   175,   145,   145,   145,
     729,   145,    27,    15,   175,   202,    20,   175,    25,   220,
    1264,  1265,   110,   834,   159,   158,    99,   159,   220,    86,
      86,    86,   145,    20,    99,    99,   117,   149,   149,   122,
      20,   282,   122,   142,   172,   175,   172,   172,   172,    88,
     769,   770,   771,   772,  1117,   175,   172,    30,    88,    99,
     175,   175,   172,   132,    86,   172,   226,   110,   159,   175,
     175,   175,   172,   214,   172,   172,   179,   110,   132,   175,
     172,   110,   801,   110,   269,   136,   257,   250,   172,    86,
     252,  1335,   271,    92,   173,   132,   122,   132,   272,   272,
     724,   172,   172,   122,   142,   172,   122,   731,   186,    88,
     142,   172,   110,   136,   110,   149,    27,   246,   132,    20,
     110,   840,   142,   842,   172,   142,   172,   110,    71,    99,
      99,   136,   145,   235,   145,   136,   136,    47,    86,  1202,
     134,   172,    20,    20,    99,   134,   247,   175,   172,   159,
     272,   272,   136,   247,   179,   132,   110,   175,   110,    61,
     122,     6,   881,   175,   883,   132,   175,   175,   226,   175,
      98,    98,   175,   222,   110,   136,   265,   222,   222,   803,
     991,   222,   174,    86,   179,   809,    20,   175,    20,   175,
     172,  1254,   145,   174,   172,   116,    88,   172,   172,    20,
     172,   172,    88,    86,    59,   255,   110,   926,   832,   185,
     929,    98,   110,   255,   174,  1026,   174,   185,   937,   185,
     939,    85,   171,   142,   175,   110,   185,   504,   110,   504,
    1041,   224,   603,   224,  1000,   802,   221,   368,   862,   863,
    1350,   865,  1106,   867,   363,  1172,   784,   508,   929,   876,
    1048,  1217,  1060,  1114,  1065,  1126,  1124,   921,  1121,   462,
    1043,  1024,   227,   887,   228,   528,   550,   986,  1079,   529,
     291,  1073,   684,  1388,   898,   899,   900,  1382,   902,   903,
     904,   905,   906,   907,   772,   909,   910,   372,   842,   801,
     999,   450,  1101,   450,  1111,   747,   969,   921,   957,  1164,
    1293,   748,  1182,   266,  1023,   961,  1159,   958,    -1,    -1,
    1373,    -1,    -1,    -1,    -1,    -1,   940,    -1,   942,   943,
      -1,    -1,    -1,    -1,  1043,    -1,    -1,    -1,    -1,  1048,
     287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1059,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     984,  1080,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1004,    -1,  1101,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1110,    -1,    -1,    -1,  1114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1033,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1046,    -1,    -1,    -1,  1050,  1051,    -1,  1053,
      -1,    -1,    -1,    -1,  1058,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1189,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1113,
      -1,    -1,    -1,    -1,    -1,  1214,  1215,    -1,    -1,    -1,
    1124,    -1,    -1,    -1,    -1,    -1,  1225,    -1,    -1,    -1,
      -1,  1230,    -1,  1137,    -1,    -1,  1140,    -1,  1142,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1279,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1299,    -1,    -1,    -1,    -1,    -1,    -1,  1211,    -1,  1213,
      -1,    -1,    -1,    -1,    -1,  1219,  1315,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1327,  1233,
    1234,  1235,  1236,  1237,    -1,  1239,  1240,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1352,    -1,    -1,    -1,  1261,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1366,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1378,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1295,    -1,    -1,  1298,    -1,  1300,    -1,  1302,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1411,    -1,    -1,    -1,    -1,  1416,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1350,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1377,    -1,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    25,    26,  1398,    28,    29,    30,    31,    32,
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
     283,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
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
      -1,   164,   165,    -1,    -1,   168,   169,   170,    -1,    -1,
      -1,   174,   175,   176,   177,   178,    -1,   180,   181,   182,
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
     274,   275,   276,   277,   278,   279,   280,   281,   282,    10,
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
      -1,    -1,    -1,   174,    -1,   176,   177,    -1,    -1,    -1,
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
     281,   282,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,
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
     278,   279,   280,   281,   282,    14,    -1,    -1,    -1,    18,
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
     279,   280,   281,   282,    14,    -1,    -1,    -1,    18,    -1,
      20,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,    29,
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
     280,   281,   282,    14,    -1,    -1,    -1,    18,    -1,    -1,
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
     281,   282,    16,    -1,    18,    -1,    -1,    -1,    -1,    -1,
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
     274,   275,   276,   277,   278,   279,   280,   281,   282,    18,
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
     279,   280,   281,   282,    18,    -1,    -1,    -1,    -1,    -1,
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
     274,   275,   276,   277,   278,   279,   280,   281,   282,    18,
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
     279,   280,   281,   282,    18,    -1,    -1,    -1,    -1,    -1,
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
     274,   275,   276,   277,   278,   279,   280,   281,   282,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    -1,    -1,    84,    -1,    86,    87,    88,
      89,    -1,    -1,    92,    93,    94,    -1,    -1,    -1,    98,
      -1,    -1,    -1,    -1,   103,   104,   105,    -1,    -1,   108,
     109,   110,    -1,    -1,    -1,    -1,    -1,   116,   117,   118,
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
     279,   280,   281,   282,    18,    -1,    -1,    -1,    -1,    -1,
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
     274,   275,   276,   277,   278,   279,   280,   281,   282,    18,
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
     279,   280,   281,   282,    18,    -1,    -1,    -1,    -1,    -1,
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
     274,   275,   276,   277,   278,   279,   280,   281,   282
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
     521,    86,    99,   175,   365,   347,   506,   332,   368,   272,
      88,   145,   544,    20,   105,   541,   159,   179,   172,   110,
     490,   105,   411,   172,   365,   175,   175,   134,   175,   175,
     368,   519,    99,   327,   172,   365,   408,   368,   388,   368,
     368,   132,   368,   136,   110,   110,   368,   521,   392,    61,
     172,   365,   175,   175,   122,   183,   465,     6,   365,   521,
     183,   476,   179,   222,   222,   222,   222,   226,   514,   174,
     132,   350,   447,   518,   517,   368,   393,   519,   118,   119,
     404,   405,   405,   401,    98,   398,   397,   175,   175,   368,
     368,   136,   368,   421,    43,   119,   421,   421,   258,   264,
     272,   556,   556,   418,   529,   265,   489,   490,   361,    86,
     172,   126,   189,   543,   546,    20,    20,   545,   543,   260,
     551,    99,   175,    99,   175,   145,   343,   521,   174,   110,
     174,   172,   116,    88,   519,   172,   368,   368,   521,   521,
     391,   368,   172,   468,   521,   183,   172,   468,   521,   368,
     368,   368,   368,   368,   368,   368,   145,   198,   363,   172,
     405,   519,   368,   421,   421,   187,   490,   544,   544,   546,
      20,   175,    20,   255,   540,   541,   540,   341,   342,   368,
      99,   175,    86,   368,   521,   368,   368,   327,    59,    85,
     171,   469,   468,   521,   185,   468,   110,   447,   421,   551,
      99,   175,   175,    98,   489,   341,   490,   174,   110,     4,
     123,   472,   473,   475,   477,    19,   124,   470,   471,   474,
     477,   185,   468,   185,   521,   255,   541,   519,   174,   368,
     521,    85,   123,   475,   171,   124,   474,   185,    99,   175,
     368,   110,   363,   521,    99,   175,   110,   363,   521,   175,
     363
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
     357,   357,   358,   358,   359,   360,   360,   361,   361,   362,
     363,   364,   365,   365,   366,   366,   367,   367,   368,   368,
     368,   368,   368,   368,   368,   368,   368,   368,   368,   368,
     368,   368,   368,   368,   368,   368,   369,   370,   371,   371,
     372,   372,   372,   373,   373,   374,   374,   375,   376,   376,
     376,   377,   377,   377,   377,   377,   378,   378,   379,   379,
     380,   381,   381,   382,   382,   382,   382,   382,   382,   382,
     382,   383,   384,   385,   386,   386,   387,   387,   388,   388,
     388,   388,   389,   389,   390,   390,   390,   391,   391,   391,
     392,   392,   392,   393,   394,   395,   396,   396,   397,   397,
     398,   399,   399,   400,   400,   401,   401,   402,   402,   402,
     402,   402,   402,   402,   403,   403,   404,   404,   405,   406,
     406,   407,   407,   408,   408,   409,   409,   410,   410,   411,
     411,   412,   413,   413,   414,   414,   415,   415,   415,   415,
     415,   416,   415,   415,   415,   415,   417,   417,   417,   418,
     418,   419,   419,   419,   420,   420,   420,   420,   420,   421,
     421,   421,   422,   422,   422,   423,   423,   424,   424,   425,
     425,   426,   426,   427,   427,   428,   428,   428,   428,   429,
     429,   429,   430,   430,   430,   430,   430,   430,   431,   431,
     431,   432,   432,   432,   432,   433,   433,   434,   434,   435,
     435,   436,   436,   436,   436,   437,   438,   438,   438,   439,
     439,   440,   440,   440,   440,   441,   441,   442,   442,   442,
     442,   442,   442,   442,   443,   443,   444,   444,   445,   445,
     445,   445,   445,   446,   446,   447,   447,   448,   448,   448,
     449,   449,   450,   450,   451,   452,   452,   452,   452,   452,
     452,   452,   452,   453,   453,   454,   454,   454,   455,   456,
     456,   457,   458,   459,   460,   460,   461,   461,   462,   462,
     463,   463,   463,   464,   464,   464,   464,   464,   464,   465,
     465,   466,   466,   467,   468,   468,   469,   469,   470,   470,
     471,   471,   471,   471,   472,   472,   473,   473,   473,   473,
     474,   474,   475,   475,   476,   476,   476,   476,   477,   477,
     477,   477,   478,   478,   479,   479,   480,   481,   481,   481,
     481,   481,   481,   482,   483,   483,   483,   483,   484,   484,
     484,   484,   485,   486,   487,   487,   487,   487,   488,   488,
     489,   490,   490,   490,   491,   491,   491,   492,   492,   492,
     493,   494,   494,   494,   494,   494,   494,   494,   494,   494,
     495,   496,   496,   496,   497,   498,   499,   499,   499,   500,
     500,   500,   500,   500,   501,   502,   502,   502,   502,   502,
     502,   502,   503,   504,   505,   506,   507,   507,   507,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   509,
     509,   510,   510,   511,   512,   513,   513,   514,   515,   516,
     516,   517,   517,   517,   517,   518,   518,   519,   520,   520,
     521,   521,   522,   522,   522,   522,   522,   522,   522,   522,
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
     522,   522,   522,   522,   522,   522,   522,   522,   523,   523,
     524,   524,   524,   524,   525,   525,   525,   525,   526,   526,
     527,   527,   528,   528,   529,   529,   530,   530,   530,   531,
     531,   532,   532,   533,   533,   533,   533,   533,   534,   535,
     535,   535,   535,   535,   535,   535,   536,   536,   536,   536,
     537,   537,   537,   537,   538,   538,   539,   539,   539,   539,
     539,   539,   539,   540,   540,   541,   541,   541,   541,   542,
     542,   542,   542,   542,   543,   543,   544,   544,   545,   545,
     546,   546,   547,   548,   548,   549,   549,   549,   550,   550,
     550,   550,   550,   551,   551,   551,   551,   552,   553,   554,
     555,   555,   556,   556,   556,   557,   557,   558
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
       1,     1,     1,     1,     1,     1,     1,     1,     7,     4,
       1,     2,     3,     4,     1,     1,     2,     2,     1,     3,
       1,     3,     1,     4,     1,     2,     1,     2,     3,     1,
       2,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     3,     3,     5,     7,
       5,     7,     2,     1,     3,     2,     4,     4,     6,     4,
       5,     4,     5,     3,     1,     2,     2,     3,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     2,
       1,     2,     1,     2,     3,     3,     4,     3,     3,     3,
       2,     2,     1,     1,     1,     1,     1,     3
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
     345,   347,    -1,   361,    -1,   360,    99,   361,    -1,   110,
     521,    -1,   110,   521,   489,    -1,   142,   365,   172,    -1,
     142,   365,   172,    -1,   365,    -1,   367,    -1,   367,   366,
      -1,   179,    -1,   366,   367,   179,    -1,   368,    -1,   367,
      99,   368,    -1,   369,    -1,   406,    -1,   409,    -1,   412,
      -1,   413,    -1,   508,    -1,   509,    -1,   511,    -1,   510,
      -1,   512,    -1,   515,    -1,   523,    -1,   352,    -1,   353,
      -1,   354,    -1,   351,    -1,   346,    -1,   355,    -1,   378,
     370,    -1,   174,   368,    -1,    56,   268,    -1,    57,   268,
      -1,   206,    -1,   246,    -1,    60,   246,    -1,   372,   390,
      61,   368,    -1,   372,    61,   368,    -1,    54,   371,   389,
     373,   373,    -1,    54,   371,   389,   373,    -1,    62,   110,
     521,    -1,   380,    -1,   385,    -1,   374,    -1,   376,    -1,
     394,    -1,   399,    -1,   395,    -1,   375,    -1,   376,    -1,
     378,   377,    -1,    54,   110,    -1,    55,    54,   110,    -1,
     379,   381,    -1,   382,    -1,   381,    99,   110,   382,    -1,
     521,   136,   368,    -1,   521,   489,   136,   368,    -1,   521,
     383,   136,   368,    -1,   521,   489,   383,   136,   368,    -1,
     521,   384,   136,   368,    -1,   521,   489,   384,   136,   368,
      -1,   521,   383,   384,   136,   368,    -1,   521,   489,   383,
     384,   136,   368,    -1,    88,   110,   521,    -1,   262,   110,
     521,    -1,    51,   110,   386,    -1,   388,    -1,   386,    99,
     110,   388,    -1,   393,    -1,   387,    99,   110,   393,    -1,
     521,   132,   368,    -1,   521,   489,   132,   368,    -1,   521,
     384,   132,   368,    -1,   521,   489,   384,   132,   368,    -1,
     110,   521,   136,   368,    -1,   110,   521,   489,   136,   368,
      -1,   391,    -1,   110,   521,    -1,   110,   521,   391,    -1,
     383,    -1,   383,   392,    -1,   392,    -1,    58,   110,   521,
      59,   110,   521,    -1,    59,   110,   521,    -1,    58,   110,
     521,    -1,   521,    -1,   200,   368,    -1,   160,   159,   396,
      -1,   397,    -1,   396,    99,   397,    -1,   110,   521,    -1,
     110,   521,   398,    -1,    98,   519,    -1,   158,   159,   400,
      -1,    45,   158,   159,   400,    -1,   401,    -1,   400,    99,
     401,    -1,   368,    -1,   368,   402,    -1,   403,    -1,   404,
      -1,   405,    -1,   403,   404,    -1,   403,   405,    -1,   404,
     405,    -1,   403,   404,   405,    -1,    87,    -1,   108,    -1,
     117,   118,    -1,   117,   119,    -1,    98,   519,    -1,    44,
     110,   407,   176,   368,    -1,   125,   110,   407,   176,   368,
      -1,   408,    -1,   407,    99,   110,   408,    -1,   521,   136,
     368,    -1,   521,   489,   136,   368,    -1,    29,   145,   365,
     175,   410,   105,   174,   368,    -1,    29,   145,   365,   175,
     410,   105,   110,   521,   174,   368,    -1,   411,    -1,   410,
     411,    -1,    92,   490,   174,   368,    -1,    92,   110,   521,
      86,   490,   174,   368,    -1,    40,   145,   365,   175,   186,
     368,   116,   368,    -1,   414,    -1,   413,   156,   414,    -1,
     415,    -1,   414,    84,   415,    -1,   417,    -1,   417,   430,
     417,    -1,   417,   431,   417,    -1,   417,   122,   417,    -1,
     417,   151,   417,    -1,    -1,   417,   146,   416,   417,    -1,
     417,   144,   417,    -1,   417,   133,   417,    -1,   417,   131,
     417,    -1,   418,    -1,   418,   251,   524,    -1,   418,   251,
     524,   558,    -1,   419,    -1,   419,   187,   419,    -1,   420,
      -1,   419,   164,   420,    -1,   419,   147,   420,    -1,   421,
      -1,   420,   182,   421,    -1,   420,   109,   421,    -1,   420,
     135,   421,    -1,   420,   148,   421,    -1,   422,    -1,   421,
     189,   422,    -1,   421,   198,   422,    -1,   423,    -1,   422,
     139,   423,    -1,   422,   126,   423,    -1,   424,    -1,   424,
      68,   220,   490,    -1,   425,    -1,   425,   188,    86,   490,
      -1,   426,    -1,   426,    93,    86,   488,    -1,   427,    -1,
     427,    94,    86,   488,    -1,   429,    -1,   428,   429,    -1,
     164,    -1,   147,    -1,   428,   164,    -1,   428,   147,    -1,
     432,    -1,   436,    -1,   433,    -1,   191,    -1,   196,    -1,
     195,    -1,   194,    -1,   193,    -1,   192,    -1,   140,    -1,
     167,    -1,   130,    -1,    28,   142,   365,   172,    -1,    28,
     211,   142,   365,   172,    -1,    28,   210,   142,   365,   172,
      -1,    28,    86,   504,   142,   365,   172,    -1,   434,   142,
     172,    -1,   434,   142,   365,   172,    -1,   435,    -1,   434,
     435,    -1,   165,   521,    15,    -1,   165,    16,    -1,   437,
      -1,   437,   438,    -1,   181,   438,    -1,   438,    -1,   180,
      -1,   439,    -1,   439,   180,   438,    -1,   439,   181,   438,
      -1,   440,    -1,   449,    -1,   441,    -1,   441,   450,    -1,
     444,    -1,   444,   450,    -1,   442,   446,    -1,   443,    -1,
      97,    -1,   106,    -1,    90,    -1,   178,    -1,   107,    -1,
     129,    -1,   128,    -1,   446,    -1,    91,   446,    -1,   445,
     446,    -1,   112,    -1,   161,    -1,    82,    -1,   169,    -1,
     168,    -1,    83,    -1,   494,    -1,   447,    -1,   521,    -1,
     448,    -1,   182,    -1,    10,    -1,    17,    -1,   452,    -1,
     452,   450,    -1,   451,    -1,   450,   451,    -1,   143,   365,
     173,    -1,   453,    -1,   455,    -1,   456,    -1,   457,    -1,
     460,    -1,   462,    -1,   458,    -1,   459,    -1,   454,    -1,
     506,    -1,   102,    -1,   138,    -1,   114,    -1,   110,   521,
      -1,   145,   175,    -1,   145,   365,   175,    -1,   111,    -1,
     157,   142,   365,   172,    -1,   190,   142,   365,   172,    -1,
     521,   145,   175,    -1,   521,   145,   461,   175,    -1,   368,
      -1,   461,    99,   368,    -1,   463,    -1,   481,    -1,   464,
      -1,   478,    -1,   479,    -1,   146,   521,   468,   120,    -1,
     146,   521,   466,   468,   120,    -1,   146,   521,   468,   185,
     183,   521,   468,   185,    -1,   146,   521,   468,   185,   465,
     183,   521,   468,   185,    -1,   146,   521,   466,   468,   185,
     183,   521,   468,   185,    -1,   146,   521,   466,   468,   185,
     465,   183,   521,   468,   185,    -1,   476,    -1,   465,   476,
      -1,   467,    -1,   466,   467,    -1,    27,   521,   468,   122,
     468,   469,    -1,    -1,    27,    -1,   171,   470,   171,    -1,
      85,   472,    85,    -1,    -1,   471,    -1,   124,    -1,   474,
      -1,   471,   124,    -1,   471,   474,    -1,    -1,   473,    -1,
     123,    -1,   475,    -1,   473,   123,    -1,   473,   475,    -1,
      19,    -1,   477,    -1,     4,    -1,   477,    -1,   463,    -1,
       9,    -1,   480,    -1,   477,    -1,     8,    -1,   113,    -1,
     115,    -1,   362,    -1,   201,    21,   202,    -1,   201,   202,
      -1,   162,   520,   163,    -1,   162,   520,     7,    -1,    95,
       6,    -1,   482,    -1,   483,    -1,   484,    -1,   485,    -1,
     486,    -1,   487,    -1,    31,   142,   365,   172,    -1,    30,
     521,   142,   172,    -1,    30,   521,   142,   365,   172,    -1,
      30,   142,   365,   172,   142,   172,    -1,    30,   142,   365,
     172,   142,   365,   172,    -1,    89,   521,   142,   172,    -1,
      89,   521,   142,   365,   172,    -1,    89,   142,   365,   172,
     142,   172,    -1,    89,   142,   365,   172,   142,   365,   172,
      -1,    32,   142,   365,   172,    -1,    33,   142,   365,   172,
      -1,    42,   520,   142,   172,    -1,    42,   520,   142,   365,
     172,    -1,    42,   142,   365,   172,   142,   172,    -1,    42,
     142,   365,   172,   142,   365,   172,    -1,   493,    -1,   493,
     134,    -1,    86,   490,    -1,   492,    -1,   492,   491,    -1,
     199,   145,   175,    -1,   134,    -1,   182,    -1,   164,    -1,
     493,    -1,   494,    -1,   141,   145,   175,    -1,   521,    -1,
     496,    -1,   502,    -1,   500,    -1,   503,    -1,   501,    -1,
     499,    -1,   498,    -1,   497,    -1,   495,    -1,   214,   145,
     175,    -1,    66,   145,   175,    -1,    66,   145,   502,   175,
      -1,    66,   145,   503,   175,    -1,    32,   145,   175,    -1,
      33,   145,   175,    -1,    42,   145,   175,    -1,    42,   145,
     520,   175,    -1,    42,   145,    20,   175,    -1,    89,   145,
     175,    -1,    89,   145,   521,   175,    -1,    89,   145,   521,
      99,   504,   175,    -1,    89,   145,   182,   175,    -1,    89,
     145,   182,    99,   504,   175,    -1,   177,   521,   175,    -1,
      30,   145,   175,    -1,    30,   145,   521,   175,    -1,    30,
     145,   521,    99,   504,   175,    -1,    30,   145,   521,    99,
     505,   175,    -1,    30,   145,   182,   175,    -1,    30,   145,
     182,    99,   504,   175,    -1,    30,   145,   182,    99,   505,
     175,    -1,    65,   145,   521,   175,    -1,   521,    -1,   521,
     134,    -1,    20,    -1,    25,   209,   210,    -1,    25,   209,
     211,    -1,    25,   209,   212,    -1,   215,   214,   368,   222,
     368,    -1,   215,   214,   368,    86,   221,   222,   368,    -1,
     215,   214,   368,    86,   223,   222,   368,    -1,   215,   214,
     368,   207,   368,    -1,   215,   214,   368,   208,   368,    -1,
     215,   216,   368,   222,   368,    -1,   215,   216,   368,    86,
     221,   222,   368,    -1,   215,   216,   368,    86,   223,   222,
     368,    -1,   215,   216,   368,   207,   368,    -1,   215,   216,
     368,   208,   368,    -1,   213,   214,   368,    -1,   213,   216,
     368,    -1,   218,   214,   368,   226,   368,    -1,   218,   219,
     220,   214,   368,   226,   368,    -1,   217,   214,   368,    86,
     368,    -1,   225,   110,   513,   224,   368,   174,   368,    -1,
     514,    -1,   513,    99,   110,   514,    -1,   521,   132,   368,
      -1,   234,   142,   368,   172,   516,    -1,   517,    -1,   516,
     517,    -1,   235,   518,   363,    -1,   235,   518,   145,   110,
     521,   175,   363,    -1,   235,   518,   145,   110,   521,    99,
     110,   521,   175,   363,    -1,   235,   518,   145,   110,   521,
      99,   110,   521,    99,   110,   521,   175,   363,    -1,   447,
      -1,   518,   198,   447,    -1,    20,    -1,    14,    -1,   521,
      -1,    18,    -1,   522,    -1,   203,    -1,   117,    -1,    89,
      -1,    33,    -1,    66,    -1,    30,    -1,   141,    -1,    40,
      -1,   214,    -1,    42,    -1,    69,    -1,    65,    -1,    32,
      -1,    29,    -1,   199,    -1,    70,    -1,   240,    -1,    64,
      -1,   211,    -1,   210,    -1,   135,    -1,    31,    -1,   252,
      -1,   239,    -1,   242,    -1,   241,    -1,   269,    -1,   270,
      -1,   273,    -1,   271,    -1,   274,    -1,   245,    -1,   247,
      -1,    47,    -1,   206,    -1,   246,    -1,    43,    -1,   212,
      -1,   225,    -1,   219,    -1,   191,    -1,   196,    -1,   195,
      -1,   194,    -1,   193,    -1,   192,    -1,    88,    -1,   103,
      -1,   104,    -1,   174,    -1,    54,    -1,    55,    -1,    56,
      -1,    57,    -1,    58,    -1,    59,    -1,    60,    -1,    61,
      -1,    62,    -1,   136,    -1,    51,    -1,   200,    -1,   159,
      -1,   160,    -1,   158,    -1,    45,    -1,    87,    -1,   108,
      -1,   118,    -1,   119,    -1,    98,    -1,    44,    -1,   125,
      -1,   176,    -1,    92,    -1,    86,    -1,   186,    -1,   116,
      -1,   156,    -1,    84,    -1,    68,    -1,   220,    -1,    93,
      -1,   187,    -1,   109,    -1,   148,    -1,   189,    -1,   139,
      -1,   126,    -1,    28,    -1,    94,    -1,   188,    -1,   140,
      -1,   170,    -1,   184,    -1,   149,    -1,   127,    -1,   121,
      -1,   155,    -1,   137,    -1,   154,    -1,    25,    -1,    52,
      -1,    63,    -1,   105,    -1,    67,    -1,    46,    -1,   204,
      -1,    41,    -1,    48,    -1,    26,    -1,    34,    -1,   262,
      -1,   251,    -1,   267,    -1,   268,    -1,   244,    -1,   257,
      -1,   265,    -1,   261,    -1,   243,    -1,   256,    -1,   266,
      -1,   260,    -1,   255,    -1,   254,    -1,   238,    -1,   237,
      -1,   259,    -1,   248,    -1,   249,    -1,   272,    -1,   264,
      -1,   263,    -1,   258,    -1,   218,    -1,   224,    -1,   221,
      -1,   215,    -1,   208,    -1,   207,    -1,   209,    -1,   226,
      -1,   216,    -1,   217,    -1,   223,    -1,   213,    -1,   222,
      -1,    39,    -1,    36,    -1,    35,    -1,    37,    -1,    38,
      -1,   157,    -1,   190,    -1,   227,    -1,   228,    -1,   229,
      -1,   231,    -1,   233,    -1,   230,    -1,   232,    -1,   234,
      -1,   235,    -1,    53,    -1,   236,    -1,    50,    -1,   279,
      -1,   275,    -1,   276,    -1,   278,    -1,   282,    -1,   280,
      -1,   281,    -1,   277,    -1,    71,    -1,    72,    -1,    73,
      -1,    74,    -1,    75,    -1,    76,    -1,    77,    -1,    78,
      -1,    79,    -1,    80,    -1,    81,    -1,   236,   110,   387,
      53,   142,   368,   172,    -1,    53,   142,   368,   172,    -1,
     526,    -1,   526,   525,    -1,   526,   267,   418,    -1,   526,
     525,   267,   418,    -1,   535,    -1,   533,    -1,   525,   535,
      -1,   525,   533,    -1,   527,    -1,   526,   253,   527,    -1,
     528,    -1,   527,   250,   528,    -1,   529,    -1,   528,   252,
     136,   529,    -1,   530,    -1,   252,   530,    -1,   531,    -1,
     531,   554,    -1,   145,   524,   175,    -1,   532,    -1,   532,
     550,    -1,   453,    -1,   142,   365,   172,    -1,   534,    -1,
     553,    -1,   552,    -1,   555,    -1,   549,    -1,   157,    -1,
     536,    -1,   537,    -1,   538,    -1,   539,    -1,   542,    -1,
     547,    -1,   548,    -1,   256,    -1,   266,    -1,    92,   239,
      -1,    92,   242,    -1,   226,   241,    -1,   269,   241,    -1,
     241,   239,    -1,   241,   242,    -1,   226,   270,    -1,   269,
     270,    -1,   226,   273,   541,    -1,   226,   273,   105,    -1,
     226,   273,   145,   541,   175,    -1,   226,   273,   145,   541,
      99,   540,   175,    -1,   226,   273,   145,   105,   175,    -1,
     226,   273,   145,   105,    99,   540,   175,    -1,   269,   273,
      -1,   541,    -1,   540,    99,   541,    -1,    88,    20,    -1,
      88,    20,   260,    20,    -1,    88,    20,   551,   255,    -1,
      88,    20,   260,    20,   551,   255,    -1,   226,   271,   272,
     544,    -1,   226,   271,   272,   544,   543,    -1,   226,   105,
     271,   272,    -1,   226,   105,   271,   272,   543,    -1,   269,
     271,   272,    -1,   546,    -1,   543,   546,    -1,    88,    20,
      -1,   145,   545,   175,    -1,    20,    -1,   545,    20,    -1,
     189,   544,    -1,   126,   544,    -1,   254,    20,    -1,   226,
     274,    -1,   269,   274,    -1,    88,   206,    -1,    88,   246,
      -1,   245,   247,    -1,   238,    -1,   238,    47,    -1,   237,
      -1,   237,   272,    -1,   259,    -1,   248,   421,    -1,    88,
     119,   421,    -1,    88,    43,   421,    -1,   249,   421,   187,
     421,    -1,   244,   551,   556,    -1,   268,   421,   556,    -1,
     257,   551,   265,    -1,   261,   557,    -1,   243,   557,    -1,
     272,    -1,   264,    -1,   258,    -1,   263,    -1,   258,    -1,
     269,   247,   421,    -1
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
    2331,  2333,  2335,  2337,  2339,  2341,  2343,  2345,  2347,  2355,
    2360,  2362,  2365,  2369,  2374,  2376,  2378,  2381,  2384,  2386,
    2390,  2392,  2396,  2398,  2403,  2405,  2408,  2410,  2413,  2417,
    2419,  2422,  2424,  2428,  2430,  2432,  2434,  2436,  2438,  2440,
    2442,  2444,  2446,  2448,  2450,  2452,  2454,  2456,  2458,  2461,
    2464,  2467,  2470,  2473,  2476,  2479,  2482,  2486,  2490,  2496,
    2504,  2510,  2518,  2521,  2523,  2527,  2530,  2535,  2540,  2547,
    2552,  2558,  2563,  2569,  2573,  2575,  2578,  2581,  2585,  2587,
    2590,  2593,  2596,  2599,  2602,  2605,  2608,  2611,  2614,  2616,
    2619,  2621,  2624,  2626,  2629,  2633,  2637,  2642,  2646,  2650,
    2654,  2657,  2660,  2662,  2664,  2666,  2668,  2670
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
    1456,  1462,  1466,  1473,  1484,  1489,  1498,  1508,  1516,  1527,
    1529,  1536,  1544,  1548,  1556,  1560,  1568,  1576,  1580,  1588,
    1592,  1599,  1606,  1616,  1621,  1633,  1637,  1641,  1645,  1652,
    1659,  1678,  1688,  1694,  1700,  1709,  1720,  1733,  1741,  1748,
    1760,  1764,  1771,  1775,  1779,  1786,  1791,  1798,  1806,  1810,
    1814,  1822,  1829,  1838,  1850,  1864,  1872,  1886,  1893,  1906,
    1914,  1925,  1936,  1940,  1952,  1956,  1965,  1969,  1985,  1986,
    1987,  1988,  1989,  1992,  1993,  1994,  1995,  1996,  1998,  1999,
    2002,  2003,  2004,  2005,  2006,  2009,  2016,  2025,  2032,  2036,
    2044,  2048,  2052,  2059,  2063,  2070,  2078,  2089,  2099,  2100,
    2101,  2105,  2105,  2105,  2105,  2105,  2108,  2114,  2123,  2127,
    2137,  2148,  2154,  2168,  2176,  2185,  2195,  2206,  2215,  2225,
    2235,  2251,  2264,  2276,  2288,  2294,  2306,  2312,  2326,  2335,
    2345,  2354,  2367,  2374,  2385,  2386,  2391,  2400,  2404,  2409,
    2413,  2419,  2424,  2432,  2448,  2456,  2463,  2469,  2480,  2487,
    2497,  2507,  2512,  2524,  2530,  2544,  2550,  2562,  2569,  2576,
    2583,  2590,  2597,  2604,  2617,  2621,  2631,  2636,  2647,  2658,
    2665,  2678,  2685,  2697,  2704,  2718,  2725,  2739,  2745,  2757,
    2763,  2777,  2788,  2792,  2803,  2807,  2826,  2830,  2838,  2846,
    2854,  2862,  2862,  2870,  2878,  2886,  2900,  2904,  2911,  2924,
    2928,  2939,  2943,  2947,  2957,  2961,  2965,  2969,  2973,  2983,
    2987,  2992,  3003,  3007,  3011,  3021,  3025,  3037,  3041,  3053,
    3057,  3069,  3073,  3085,  3089,  3101,  3105,  3109,  3113,  3125,
    3129,  3133,  3143,  3147,  3151,  3155,  3159,  3163,  3173,  3177,
    3181,  3191,  3195,  3199,  3203,  3215,  3221,  3233,  3239,  3253,
    3260,  3301,  3305,  3309,  3313,  3325,  3335,  3346,  3351,  3361,
    3365,  3375,  3381,  3387,  3393,  3405,  3411,  3422,  3426,  3430,
    3434,  3438,  3442,  3446,  3456,  3460,  3470,  3474,  3485,  3489,
    3493,  3497,  3501,  3516,  3520,  3530,  3534,  3544,  3551,  3558,
    3571,  3575,  3587,  3593,  3607,  3618,  3622,  3626,  3630,  3634,
    3638,  3642,  3646,  3656,  3660,  3670,  3675,  3680,  3691,  3702,
    3706,  3717,  3727,  3738,  3794,  3800,  3812,  3818,  3830,  3834,
    3844,  3848,  3852,  3862,  3870,  3878,  3886,  3894,  3902,  3917,
    3923,  3935,  3941,  3954,  3963,  3965,  3971,  3976,  3988,  3991,
    3998,  4004,  4010,  4018,  4033,  4036,  4043,  4049,  4055,  4063,
    4077,  4082,  4093,  4098,  4109,  4114,  4119,  4125,  4137,  4143,
    4148,  4153,  4164,  4169,  4184,  4189,  4206,  4221,  4225,  4229,
    4233,  4237,  4241,  4251,  4262,  4268,  4274,  4279,  4301,  4307,
    4313,  4318,  4329,  4339,  4349,  4355,  4361,  4366,  4377,  4383,
    4395,  4406,  4412,  4418,  4455,  4460,  4465,  4476,  4480,  4484,
    4494,  4505,  4509,  4513,  4517,  4521,  4525,  4529,  4533,  4537,
    4547,  4557,  4561,  4566,  4577,  4587,  4597,  4601,  4605,  4615,
    4621,  4627,  4633,  4639,  4651,  4662,  4669,  4676,  4683,  4690,
    4697,  4704,  4717,  4738,  4745,  4765,  4805,  4809,  4813,  4822,
    4828,  4834,  4840,  4846,  4853,  4859,  4865,  4871,  4877,  4889,
    4894,  4904,  4910,  4922,  4948,  4959,  4965,  4978,  4993,  5000,
    5006,  5017,  5024,  5034,  5045,  5061,  5067,  5077,  5086,  5087,
    5104,  5108,  5115,  5116,  5117,  5118,  5119,  5120,  5121,  5122,
    5123,  5124,  5125,  5126,  5127,  5128,  5129,  5130,  5131,  5132,
    5133,  5134,  5135,  5136,  5137,  5138,  5139,  5140,  5141,  5142,
    5143,  5144,  5145,  5146,  5147,  5148,  5149,  5150,  5151,  5152,
    5153,  5154,  5155,  5156,  5157,  5158,  5159,  5160,  5161,  5162,
    5163,  5164,  5165,  5166,  5167,  5168,  5169,  5170,  5171,  5172,
    5173,  5174,  5175,  5176,  5177,  5178,  5179,  5180,  5181,  5182,
    5183,  5184,  5185,  5186,  5187,  5188,  5189,  5190,  5191,  5192,
    5193,  5194,  5195,  5196,  5197,  5198,  5199,  5200,  5201,  5202,
    5203,  5204,  5205,  5206,  5207,  5208,  5209,  5210,  5211,  5212,
    5213,  5214,  5215,  5216,  5217,  5218,  5219,  5220,  5221,  5222,
    5223,  5224,  5225,  5226,  5227,  5228,  5229,  5230,  5231,  5232,
    5233,  5234,  5235,  5236,  5237,  5238,  5239,  5240,  5241,  5242,
    5243,  5244,  5245,  5246,  5247,  5248,  5249,  5250,  5251,  5252,
    5253,  5254,  5255,  5256,  5257,  5258,  5259,  5260,  5261,  5262,
    5263,  5264,  5265,  5266,  5267,  5268,  5269,  5270,  5271,  5272,
    5273,  5274,  5275,  5276,  5277,  5278,  5279,  5280,  5281,  5282,
    5283,  5284,  5285,  5286,  5287,  5288,  5289,  5290,  5291,  5292,
    5293,  5294,  5295,  5296,  5297,  5298,  5299,  5300,  5311,  5317,
    5334,  5338,  5342,  5346,  5356,  5359,  5362,  5365,  5374,  5377,
    5386,  5389,  5398,  5401,  5410,  5413,  5422,  5425,  5428,  5437,
    5440,  5449,  5453,  5463,  5466,  5469,  5472,  5475,  5484,  5493,
    5497,  5501,  5505,  5509,  5513,  5517,  5527,  5530,  5533,  5536,
    5545,  5548,  5551,  5554,  5563,  5566,  5575,  5578,  5581,  5584,
    5587,  5590,  5593,  5602,  5605,  5614,  5617,  5620,  5623,  5632,
    5635,  5638,  5641,  5644,  5653,  5656,  5665,  5668,  5677,  5680,
    5689,  5692,  5701,  5710,  5713,  5722,  5725,  5728,  5737,  5740,
    5743,  5746,  5749,  5758,  5762,  5766,  5770,  5780,  5789,  5799,
    5808,  5811,  5820,  5823,  5826,  5835,  5838,  5847
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
  const int xquery_parser::yylast_ = 9848;
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
#line 13454 "/home/colea/work/xquery_temp2/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 5855 "/home/colea/work/xquery_temp2/src/compiler/parser/xquery_parser.y"


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

