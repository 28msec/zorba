
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
#line 45 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"


#define TEST_TEST_TEST

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
#line 77 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 872 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_driver.h"
#include "compiler/parser/xquery_scanner.h"
#undef yylex
#define yylex driver.lexer->lex


/* Line 317 of lalr1.cc  */
#line 94 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"

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
#line 163 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
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
        case 110: /* "\"'DECIMAL'\"" */

/* Line 480 of lalr1.cc  */
#line 756 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 270 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 122: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 755 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 279 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 146: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 754 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 288 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 302: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 297 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 303: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 306 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 304: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 315 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 305: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 324 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 306: /* "Prolog" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 333 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 307: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 342 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 308: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 351 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 309: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 360 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 310: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 369 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 311: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 378 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 312: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 768 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->pair_vector); };

/* Line 480 of lalr1.cc  */
#line 387 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 313: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 768 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->pair); };

/* Line 480 of lalr1.cc  */
#line 396 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 315: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 405 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 316: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 414 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 317: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 423 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 318: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 432 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 319: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 441 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 320: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 450 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 322: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 459 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 323: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 468 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 324: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 477 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 325: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 486 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 326: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 495 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 327: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 504 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 328: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 513 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 329: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 522 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 330: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 531 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 331: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 540 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 332: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 549 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 333: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 558 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 334: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 567 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 768 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 576 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 585 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 594 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "IndexDecl2" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 603 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "IndexDecl3" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 612 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "IndexDeclSuffix" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 621 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "IndexField" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 630 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "IndexField1" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 639 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "IndexFieldList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 648 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 657 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 768 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 666 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 675 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "Block" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 684 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "BlockDecls" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 693 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "BlockVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 702 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "BlockVarDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 711 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "AssignExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 720 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "ExitExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 729 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "WhileExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 738 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 747 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "IndexStatement" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 756 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 765 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 774 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "FunctionDecl3" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 783 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "FunctionDecl4" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 792 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 801 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 810 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "EnclosedExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 819 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 828 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 837 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 846 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "ApplyExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 855 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "ConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 864 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 873 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 882 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 891 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 900 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 909 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 918 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 927 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 936 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 945 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 954 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 963 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 972 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 981 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 990 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "EvalVarDeclList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 999 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1008 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1017 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1026 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1035 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1044 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "EvalVarDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1053 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1062 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1071 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1080 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1089 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1098 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1107 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1116 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1125 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1134 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1143 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1152 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1161 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1170 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1179 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1188 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1197 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1206 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1215 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1224 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1233 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1242 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1251 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1260 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1269 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1278 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1287 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1296 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1305 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1314 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1323 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1332 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1341 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1350 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1359 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1368 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1377 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1386 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1395 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1404 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "PragmaList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1413 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1422 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1431 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1440 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1449 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1458 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1467 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1476 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1485 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1494 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1503 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1512 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1521 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1530 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1539 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1548 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1557 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1566 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1575 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1584 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1593 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1602 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1611 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1620 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1629 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1638 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1647 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1656 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1665 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1674 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1683 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1692 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1701 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1710 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "Opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1719 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1728 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "Opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1737 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1746 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1755 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1764 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1773 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1782 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1791 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1800 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1809 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1818 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1827 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1836 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1845 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1854 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1863 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 1872 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1881 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1890 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1899 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1908 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1917 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1926 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1935 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1944 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1953 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1962 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1971 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1980 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1989 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 1998 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2007 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2016 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2025 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->node) != NULL) { RCHelper::addReference ((yyvaluep->node)); RCHelper::removeReference ((yyvaluep->node)); } };

/* Line 480 of lalr1.cc  */
#line 2034 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2043 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2052 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2061 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2070 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2079 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2088 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2097 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2106 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2115 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2124 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2133 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 768 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2142 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "EvalExpr" */

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
	{ if ((yyvaluep->expr) != NULL) { RCHelper::addReference ((yyvaluep->expr)); RCHelper::removeReference ((yyvaluep->expr)); } };

/* Line 480 of lalr1.cc  */
#line 2151 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
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
#line 96 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
{
  yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename);
}

/* Line 553 of lalr1.cc  */
#line 2236 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"

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
#line 890 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 900 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
			driver.set_expr ((yyval.node));
		}
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 905 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<MainModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
			driver.set_expr ((yyval.node));
		}
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 911 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
       driver.set_expr ((yyval.node));
		}
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 916 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       dynamic_cast<LibraryModule *> ((yysemantic_stack_[(2) - (2)].node))->set_version_decl (static_cast<VersionDecl *> ((yysemantic_stack_[(2) - (1)].node)));
       (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
       driver.set_expr ((yyval.node));
		}
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 928 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       std::string encoding = "utf-8";
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)), encoding);
		}
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 933 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new VersionDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 943 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(2) - (2)].expr)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (1)].node)));
		}
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 950 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new MainModule(LOC ((yyloc)),
								static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)),
                NULL);
		}
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 962 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LibraryModule(LOC ((yyloc)),
								static_cast<ModuleDecl*>((yysemantic_stack_[(2) - (1)].node)),
								static_cast<Prolog*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 974 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), 
								SYMTAB ((yysemantic_stack_[(6) - (5)].sval)));
		}
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 986 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(2) - (1)].node)),
								NULL);
		}
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 992 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								NULL,
								static_cast<VFO_DeclList*>((yysemantic_stack_[(2) - (1)].node)));
		}
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 998 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Prolog(LOC ((yyloc)),
								static_cast<SIND_DeclList*>((yysemantic_stack_[(4) - (1)].node)),
								static_cast<VFO_DeclList*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1010 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = new SIND_DeclList(LOC ((yyloc)));
			sindList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = sindList_p;
		}
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1016 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			SIND_DeclList* sindList_p = static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (sindList_p) {
				sindList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1030 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = new VFO_DeclList(LOC ((yyloc)));
			vfoList_p->push_back((yysemantic_stack_[(1) - (1)].node));
			(yyval.node) = vfoList_p;
		}
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1036 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			VFO_DeclList* vfoList_p = dynamic_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node));
			if (vfoList_p) {
				vfoList_p->push_back((yysemantic_stack_[(3) - (3)].node));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 32:

/* Line 678 of lalr1.cc  */
#line 1076 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].pair_vector));
      delete (yysemantic_stack_[(4) - (4)].pair_vector);
    }
    break;

  case 33:

/* Line 678 of lalr1.cc  */
#line 1081 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), (yysemantic_stack_[(4) - (4)].pair_vector)); 
      delete (yysemantic_stack_[(4) - (4)].pair_vector);
    }
    break;

  case 34:

/* Line 678 of lalr1.cc  */
#line 1089 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { 
      (yyval.pair_vector) = new std::vector<std::pair<std::string, std::string> > ();
      (yyval.pair_vector)->push_back(*(yysemantic_stack_[(1) - (1)].pair));
      delete (yysemantic_stack_[(1) - (1)].pair);
    }
    break;

  case 35:

/* Line 678 of lalr1.cc  */
#line 1095 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].pair_vector)->push_back(*(yysemantic_stack_[(2) - (2)].pair));
      delete (yysemantic_stack_[(2) - (2)].pair);
      (yyval.pair_vector) = (yysemantic_stack_[(2) - (1)].pair_vector);
    }
    break;

  case 36:

/* Line 678 of lalr1.cc  */
#line 1104 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *s = static_cast<StringLiteral *>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.pair) = new std::pair<std::string, std::string>((yysemantic_stack_[(3) - (1)].strval), s->get_strval());
      delete s;
    }
    break;

  case 37:

/* Line 678 of lalr1.cc  */
#line 1112 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 38:

/* Line 678 of lalr1.cc  */
#line 1113 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 39:

/* Line 678 of lalr1.cc  */
#line 1114 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1115 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1116 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1117 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1118 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1119 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1120 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1121 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1158 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NamespaceDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 1170 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_space);
		}
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 1175 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BoundarySpaceDecl(LOC ((yyloc)),
								StaticContextConsts::strip_space);
		}
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1186 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_element_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1192 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultNamespaceDecl(LOC ((yyloc)),
								ParseConstants::ns_function_default,
								SYMTAB ((yysemantic_stack_[(5) - (5)].sval)));
		}
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1204 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OptionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (3)].sval))),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)));
		}
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1217 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTOptionDecl(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (3)].node));
		}
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1228 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::ordered);
		}
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1233 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderingModeDecl(LOC ((yyloc)),
								StaticContextConsts::unordered);
		}
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1245 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		}
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1250 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new EmptyOrderDecl(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		}
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1261 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::inherit_ns);
		}
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1267 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::preserve_ns,
								StaticContextConsts::no_inherit_ns);
		}
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1273 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::inherit_ns);
		}
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1279 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CopyNamespacesDecl(LOC ((yyloc)),
								StaticContextConsts::no_preserve_ns,
								StaticContextConsts::no_inherit_ns);
		}
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1298 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DefaultCollationDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)));
		}
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1309 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new BaseURIDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		}
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1320 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		}
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1327 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(4) - (4)].sval)),
								NULL);
		}
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1334 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								NULL,
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		}
    break;

  case 77:

/* Line 678 of lalr1.cc  */
#line 1341 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaImport(LOC ((yyloc)),
								dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
								SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
		}
    break;

  case 78:

/* Line 678 of lalr1.cc  */
#line 1354 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = new URILiteralList(LOC ((yyloc)));
			uri_list_p->push_back(SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
			(yyval.node) = uri_list_p;
		}
    break;

  case 79:

/* Line 678 of lalr1.cc  */
#line 1360 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			URILiteralList* uri_list_p = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node));
			if (uri_list_p) {
				uri_list_p->push_back(SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 80:

/* Line 678 of lalr1.cc  */
#line 1375 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 81:

/* Line 678 of lalr1.cc  */
#line 1379 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaPrefix(LOC ((yyloc)), true);
		}
    break;

  case 82:

/* Line 678 of lalr1.cc  */
#line 1389 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)),
								NULL);
		}
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1395 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(6) - (4)].sval)),
								SYMTAB ((yysemantic_stack_[(6) - (6)].sval)),
								NULL);
		}
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1402 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (3)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
		}
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1408 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ModuleImport(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(8) - (4)].sval)),
								SYMTAB ((yysemantic_stack_[(8) - (6)].sval)),
								dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));
		}
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1420 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1427 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->type = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1433 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1440 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl *d = dynamic_cast<CtxItemDecl *> ((yysemantic_stack_[(1) - (1)].node));
      d->ext = false;
      (yyval.node) = d;
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1446 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), NULL);
    }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1450 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1457 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl (LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1468 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (SYMTAB ((yysemantic_stack_[(2) - (2)].sval)), NULL);
    }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1472 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType (SYMTAB ((yysemantic_stack_[(3) - (2)].sval)),
                               dynamic_cast<SequenceType *> ((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1480 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(5) - (3)].varnametype);
			(yyval.node) = new VarDecl(LOC ((yyloc)),
								nt->name,
								nt->type,
								(yysemantic_stack_[(5) - (5)].expr));
      delete nt;
		}
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1489 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(4) - (3)].varnametype);
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       NULL, true);
      delete nt;
		}
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1496 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      VarNameAndType *nt = dynamic_cast<VarNameAndType *> (yysemantic_stack_[(6) - (3)].varnametype);
			(yyval.node) = new VarDecl(LOC ((yyloc)), nt->name, nt->type,
                       (yysemantic_stack_[(6) - (6)].expr), true);
      delete nt;
		}
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1506 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "hash"; }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1508 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "btree"; }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1515 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      IndexDecl *d = dynamic_cast<IndexDecl *> ((yysemantic_stack_[(2) - (2)].node));
      d->create = false;
      (yyval.node) = d;
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1523 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1527 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexDecl *> ((yysemantic_stack_[(2) - (2)].node))->uniq = true;
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1535 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1539 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexDecl *> ((yysemantic_stack_[(2) - (2)].node))->method = (yysemantic_stack_[(2) - (1)].strval);
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1547 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexDecl (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(7) - (2)].sval)), (yysemantic_stack_[(7) - (4)].expr), "",
                          dynamic_cast<IndexFieldList *> ((yysemantic_stack_[(7) - (6)].node)));
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1555 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1559 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexField *> ((yysemantic_stack_[(3) - (1)].node))->coll = SYMTAB ((yysemantic_stack_[(3) - (3)].sval));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 1567 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexField (LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL);
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 1571 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexField (LOC ((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<SequenceType *> ((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1578 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      IndexFieldList *l = new IndexFieldList (LOC ((yyloc)));
      l->fields.push_back (dynamic_cast<IndexField *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
      
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1585 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexFieldList *> ((yysemantic_stack_[(3) - (1)].node))->fields.push_back (dynamic_cast<IndexField *> ((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1595 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_preserve);
		}
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1600 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ConstructionDecl(LOC ((yyloc)),
								StaticContextConsts::cons_strip);
		}
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1612 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL);
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1616 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1620 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (NULL, dynamic_cast<SequenceType *> ((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1624 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig (dynamic_cast<ParamList *> ((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType *> ((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1631 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1638 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
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

  case 120:

/* Line 678 of lalr1.cc  */
#line 1657 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (1)].node));
      VFO_DeclList *vfo2 = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (2)].node));
      if ((yysemantic_stack_[(3) - (1)].node) == NULL)
        vfo = new VFO_DeclList (LOC ((yyloc)));
      vfo->push_back (*vfo2);
      (yyval.node) = vfo;
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1666 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL;
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1673 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = dynamic_cast<VFO_DeclList *> ((yysemantic_stack_[(3) - (1)].node));
      vfo->push_back ((yysemantic_stack_[(3) - (3)].node));
      (yyval.node) = vfo;
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1679 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vfo = new VFO_DeclList (LOC ((yyloc)));
      vfo->push_back ((yysemantic_stack_[(2) - (2)].node));
      (yyval.node) = vfo;
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1688 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
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

  case 125:

/* Line 678 of lalr1.cc  */
#line 1699 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
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

  case 126:

/* Line 678 of lalr1.cc  */
#line 1712 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(5) - (3)].sval)), (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1719 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr (LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1726 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *b = dynamic_cast<BlockBody *> ((yysemantic_stack_[(5) - (5)].expr));
      if (b == NULL) {
        b = new BlockBody ((yysemantic_stack_[(5) - (5)].expr)->get_location ()); 
        b->add ((yysemantic_stack_[(5) - (5)].expr));
      }
      (yyval.expr) = new WhileExpr (LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), b);
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1738 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1742 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement (LOC ((yyloc)), FlowCtlStatement::CONTINUE);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1749 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IndexStatement (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), IndexStatement::create_stmt);
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1753 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IndexStatement (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), IndexStatement::drop_stmt);
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1757 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IndexStatement (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), IndexStatement::build_stmt);
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1764 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1768 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(3) - (3)].node));
      d->deterministic = false;
      (yyval.node) = d;
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1774 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1781 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1785 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1789 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl *d = dynamic_cast<FunctionDecl *> ((yysemantic_stack_[(2) - (2)].node));
      d->type = (d->type == ParseConstants::fn_extern)
        ? ParseConstants::fn_extern_update
        : ParseConstants::fn_update;
      (yyval.node) = d;
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1797 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1804 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								(yysemantic_stack_[(4) - (4)].expr),
								ParseConstants::fn_read);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1813 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								NULL,
								ParseConstants::fn_extern);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1825 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FunctionDecl(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
                &* (yysemantic_stack_[(4) - (3)].fnsig)->param, &* (yysemantic_stack_[(4) - (3)].fnsig)->ret,
								(yysemantic_stack_[(4) - (4)].expr),
								ParseConstants::fn_sequential);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1839 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
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
#line 1847 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
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
#line 1861 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(2) - (2)].sval)),
								NULL);
		}
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1867 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Param(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1879 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new EnclosedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 1887 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 1898 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QueryBody(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
		}
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 1909 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 1913 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = dynamic_cast<BlockBody *> ((yysemantic_stack_[(2) - (2)].expr)),
        *blk2 = new BlockBody (LOC ((yyloc)));
      blk2->add ((yysemantic_stack_[(2) - (1)].expr));
      for (int i = 0; i < blk->size (); i++)
        blk2->add ((*blk) [i]);
      (yyval.expr) = blk2;
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 1925 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody (LOC ((yyloc)));
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 1929 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      BlockBody *blk = dynamic_cast<BlockBody *> ((yysemantic_stack_[(3) - (1)].expr));
      blk->add ((yysemantic_stack_[(3) - (2)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 1938 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 1942 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
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

  case 175:

/* Line 678 of lalr1.cc  */
#line 1989 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      ReturnExpr* lReturnExpr = dynamic_cast<ReturnExpr*>((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = new FLWORExpr (LOC ((yyloc)), dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node)), lReturnExpr->get_return_val(), lReturnExpr->get_location(), driver.theCompilerCB->m_config.force_gflwor);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 176:

/* Line 678 of lalr1.cc  */
#line 1998 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 177:

/* Line 678 of lalr1.cc  */
#line 2005 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 178:

/* Line 678 of lalr1.cc  */
#line 2009 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2017 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2021 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2025 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_only_end;
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 2032 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), dynamic_cast<WindowVars *> ((yysemantic_stack_[(4) - (2)].node)), (yysemantic_stack_[(4) - (4)].expr), (yysemantic_stack_[(4) - (1)].strval) == parser::the_start, (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 2036 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (3)].expr), (yysemantic_stack_[(3) - (1)].strval) == parser::the_start, (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 2043 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(5) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window,
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(5) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (4)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 2051 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling) ? WindowClause::tumbling_window : WindowClause::sliding_window,
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 2062 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause (LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 2080 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = new FLWORClauseList (LOC ((yyloc)));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = l;
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 2086 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *l = dynamic_cast<FLWORClauseList *> ((yysemantic_stack_[(2) - (1)].node));
      l->push_back (dynamic_cast<FLWORClause *> ((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = l;
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 2095 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = NULL;
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 2099 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_ofor;
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 2109 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForClause(LOC ((yyloc)),
                         dynamic_cast<VarInDeclList*>((yysemantic_stack_[(2) - (2)].node)), (yysemantic_stack_[(2) - (1)].strval) != NULL);
		}
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 2120 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = new VarInDeclList(LOC ((yyloc)));
			vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vardecl_list_p;
		}
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2126 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			VarInDeclList* vardecl_list_p = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vardecl_list_p) {
				vardecl_list_p->push_back(dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 2140 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (1)].sval)),
								NULL,NULL,NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 2147 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								NULL,NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 2155 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 2164 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
								NULL,
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 2174 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								NULL,NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 2182 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 2191 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (1)].sval)),
								NULL,
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 2200 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(6) - (1)].sval)),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (2)].node)),
								dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
								(yysemantic_stack_[(6) - (6)].expr));
		}
    break;

  case 210:

/* Line 678 of lalr1.cc  */
#line 2215 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PositionalVar(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		}
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 2227 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new FTScoreVar(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		}
    break;

  case 212:

/* Line 678 of lalr1.cc  */
#line 2238 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new LetClause(LOC ((yyloc)),
								dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (3)].node)));
			
		}
    break;

  case 213:

/* Line 678 of lalr1.cc  */
#line 2250 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		}
    break;

  case 214:

/* Line 678 of lalr1.cc  */
#line 2256 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(4) - (1)].node));
			if (vgdl_p) {
				vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(4) - (4)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 215:

/* Line 678 of lalr1.cc  */
#line 2268 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			VarGetsDeclList* vgdl_p = new VarGetsDeclList(LOC ((yyloc)));
			vgdl_p->push_back(dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = vgdl_p;
		}
    break;

  case 216:

/* Line 678 of lalr1.cc  */
#line 2274 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
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
#line 2288 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (1)].sval)),
								NULL,
								NULL,
								(yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 218:

/* Line 678 of lalr1.cc  */
#line 2296 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								NULL,
								(yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 219:

/* Line 678 of lalr1.cc  */
#line 2305 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								NULL,
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 220:

/* Line 678 of lalr1.cc  */
#line 2313 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new VarGetsDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (1)].sval)),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
								dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 221:

/* Line 678 of lalr1.cc  */
#line 2325 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (2)].sval)),
								NULL, (yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 222:

/* Line 678 of lalr1.cc  */
#line 2331 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WindowVarDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (2)].sval)),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 224:

/* Line 678 of lalr1.cc  */
#line 2342 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, SYMTAB ((yysemantic_stack_[(2) - (2)].sval)), "", "");
    }
    break;

  case 225:

/* Line 678 of lalr1.cc  */
#line 2346 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_curr (SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 2354 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), dynamic_cast<PositionalVar *> ((yysemantic_stack_[(1) - (1)].node)), "", "", "");
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 2358 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *> ((yyval.node))->set_posvar (dynamic_cast<PositionalVar *> ((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 2367 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", SYMTAB ((yysemantic_stack_[(6) - (3)].sval)), SYMTAB ((yysemantic_stack_[(6) - (6)].sval)));
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 2371 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", "", SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 2375 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars (LOC ((yyloc)), NULL, "", SYMTAB ((yysemantic_stack_[(3) - (3)].sval)), "");
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 2382 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      std::string name = SYMTAB ((yysemantic_stack_[(1) - (1)].sval));
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           name, NULL, NULL,
                           new VarRef (LOC ((yyloc)), name),
                           VarGetsDecl::eval_var);
                           
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 2397 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new WhereClause(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 2405 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 2412 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = new GroupSpecList(LOC((yyloc)));
      gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl_p;
    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 2418 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl_p = dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      if (gsl_p) {
        gsl_p->push_back(dynamic_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      }
      (yyval.node) = gsl_p;
    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 2429 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                 SYMTAB ((yysemantic_stack_[(2) - (2)].sval)),
                 NULL);
    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 2435 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), 
                 SYMTAB ((yysemantic_stack_[(3) - (2)].sval)), 
                 dynamic_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node))); 
    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 2444 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
    }
    break;

  case 240:

/* Line 678 of lalr1.cc  */
#line 2454 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 2459 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderByClause(LOC ((yyloc)),
								dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)),
								true);
		}
    break;

  case 242:

/* Line 678 of lalr1.cc  */
#line 2471 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = new OrderSpecList(LOC ((yyloc)));
			osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = osl_p;
		}
    break;

  case 243:

/* Line 678 of lalr1.cc  */
#line 2477 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			OrderSpecList* osl_p = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node));
			if (osl_p) {
				osl_p->push_back(dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2491 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr),
								NULL);
		}
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 2497 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderSpec(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].expr),
								dynamic_cast<OrderModifier*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2509 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL,
								NULL);
		}
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 2516 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		}
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2523 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2530 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
								NULL);
		}
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2537 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
								NULL,
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2544 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								NULL,
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 2551 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderModifier(LOC ((yyloc)),
								dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
								dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
								dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2564 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_ascending);
		}
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 2568 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderDirSpec(LOC ((yyloc)), ParseConstants::dir_descending);
		}
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 2578 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_greatest);
		}
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 2583 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderEmptySpec(LOC ((yyloc)),
								StaticContextConsts::empty_least);
		}
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 2594 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OrderCollationSpec(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		}
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 2605 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_some,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2612 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new QuantifiedExpr(LOC ((yyloc)),
								ParseConstants::quant_every,
								dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
								(yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2625 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = new QVarInDeclList(LOC ((yyloc)));
			qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qvid_list_p;
				
		}
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2632 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			QVarInDeclList* qvid_list_p = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
            qvid_list_p->push_back(dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)));
			(yyval.node) = (yysemantic_stack_[(4) - (1)].node);
		}
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2644 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (1)].sval)),
								(yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2650 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QVarInDecl(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (1)].sval)),
								dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2663 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
								(yysemantic_stack_[(8) - (8)].expr));
		}
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2670 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
								(yysemantic_stack_[(10) - (3)].expr),
								dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
								SYMTAB ((yysemantic_stack_[(10) - (8)].sval)),
								(yysemantic_stack_[(10) - (10)].expr));
		}
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2684 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = cc_list_p;
		}
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2690 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
			cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2702 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
								(yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2708 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CaseClause(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(7) - (3)].sval)),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
								(yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2721 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IfExpr(LOC ((yyloc)),
								(yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
		}
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2732 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2736 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2747 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2751 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AndExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2770 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2774 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			/*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 2782 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      /*  ::=  "is" | "<<" | ">>" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2790 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			/* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
			(yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
								new GeneralComp(LOC ((yyloc)), ParseConstants::op_eq),
								(yysemantic_stack_[(3) - (1)].expr),
								(yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2798 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ne),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2805 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { /* this call is needed */  driver.lexer->interpretAsLessThan(); }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2806 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_lt),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2814 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_le),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2822 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_gt),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2830 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      /* ::=  "=" | "!=" | "<" | "<=" | ">" | ">=" */
      (yyval.expr) = new ComparisonExpr(LOC ((yyloc)),
                new GeneralComp(LOC ((yyloc)), ParseConstants::op_ge),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2844 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2848 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(3) - (3)].node)),
								NULL);
		}
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2855 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FTContainsExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node)),
								dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2868 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2872 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RangeExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 2883 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 2887 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 2891 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AdditiveExpr(LOC ((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 2901 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 2905 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 2909 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 2913 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 2917 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new MultiplicativeExpr(LOC ((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 2927 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 2931 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 2936 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnionExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 2947 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 2951 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 2955 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new IntersectExceptExpr(LOC ((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 2965 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 2969 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new InstanceofExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 2981 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 2985 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new TreatExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 2997 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3001 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastableExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3013 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3017 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CastExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (1)].expr),
								dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node)));
		}
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3029 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3033 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnaryExpr(LOC ((yyloc)),
								dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3045 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), true);
		}
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3049 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SignList(LOC ((yyloc)), false);
		}
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3053 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3057 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			SignList* slist_p = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node));
			if (slist_p) slist_p->negate();
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3069 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3073 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3077 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3087 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_eq);
		}
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3091 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ne);
		}
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3095 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_lt);
		}
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3099 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_le);
		}
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3103 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_gt);
		}
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3107 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ValueComp(LOC ((yyloc)), ParseConstants::op_val_ge);
		}
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3117 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_is);
		}
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3121 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_precedes);
		}
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3125 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NodeComp(LOC ((yyloc)), ParseConstants::op_follows);
		}
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3135 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3139 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3143 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3147 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ValidateExpr(LOC ((yyloc)),
                            dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(),
                            (yysemantic_stack_[(6) - (5)].expr));
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3159 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)),
								NULL);
		}
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3165 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ExtensionExpr(LOC ((yyloc)),
								dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3177 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = new PragmaList(LOC ((yyloc)));
			pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = pragma_list_p;
		}
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3183 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			PragmaList* pragma_list_p = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node));
			if (pragma_list_p) {
				pragma_list_p->push_back(dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3197 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(3) - (2)].sval))),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));

		}
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3203 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Pragma(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(2) - (2)].sval))),
								"");      
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3245 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
		}
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3249 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slash, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3253 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new PathExpr(LOC ((yyloc)), ParseConstants::path_leading_slashslash, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3257 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       RelativePathExpr *rpe = dynamic_cast<RelativePathExpr *>((yysemantic_stack_[(1) - (1)].expr));
       (yyval.expr) = (rpe == NULL ?
             (yysemantic_stack_[(1) - (1)].expr) :
             new PathExpr(LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3269 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3279 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
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

  case 346:

/* Line 678 of lalr1.cc  */
#line 3290 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3295 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3305 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3309 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3319 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		}
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3325 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3331 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)),
								NULL);
		}
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3337 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new AxisStep(LOC ((yyloc)),
								dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
								dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3349 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)),
								(yysemantic_stack_[(2) - (2)].node));
		}
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3355 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardStep(LOC ((yyloc)),
								dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3366 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_child);
		}
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3370 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant);
		}
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3374 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_attribute);
		}
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3378 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_self);
		}
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3382 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_descendant_or_self);
		}
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3386 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following_sibling);
		}
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3390 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ForwardAxis(LOC ((yyloc)), ParseConstants::axis_following);
		}
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3400 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(1) - (1)].node), false);
		}
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3404 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AbbrevForwardStep(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].node), true);
		}
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3414 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseStep(LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node));
		}
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3418 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			ReverseAxis* rev_p = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
			(yyval.node) = new ReverseStep(LOC((yyloc)), rev_p, NULL);
		}
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3429 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_parent);
		}
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3433 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor);
		}
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3437 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding_sibling);
		}
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3441 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_preceding);
		}
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3445 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ReverseAxis(LOC ((yyloc)), ParseConstants::axis_ancestor_or_self);
		}
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3460 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3464 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3474 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval))));
		}
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3478 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new NameTest(LOC ((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)));
		}
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3488 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        "",
                        ParseConstants::wild_all);
		}
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3495 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        "",
                        ParseConstants::wild_elem);
		}
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3502 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new Wildcard(LOC ((yyloc)),
                        "",
                        SYMTAB ((yysemantic_stack_[(1) - (1)].sval)),
                        ParseConstants::wild_prefix);
		}
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3515 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3519 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FilterExpr(LOC ((yyloc)),
                          (yysemantic_stack_[(2) - (1)].expr),
                          dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3531 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = new PredicateList(LOC ((yyloc)));
			pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = pred_list_p;
		}
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3537 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			PredicateList* pred_list_p = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node));
			if (pred_list_p) {
				pred_list_p->push_back(dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3551 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
		}
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3562 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3566 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3570 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3574 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3578 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3582 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3586 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3590 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3600 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3604 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3614 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval));
      delete yylval.decval;
		}
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3619 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival));
      delete yylval.ival;
		}
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3624 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = NumericLiteral::new_literal(LOC ((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval));
      delete yylval.dval;
		}
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3635 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new VarRef(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		}
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3645 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)), NULL);
		}
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3649 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ParenthesizedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3660 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new ContextItemExpr(LOC ((yyloc)));
		}
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3670 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new OrderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3681 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new UnorderedExpr(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3737 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(3) - (1)].sval))),
								NULL);
		}
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3743 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new FunctionCall(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (1)].sval))),
								dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3755 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = new ArgList(LOC ((yyloc))); 
			a_list_p->push_back((yysemantic_stack_[(1) - (1)].expr));
			(yyval.node) = a_list_p;
		}
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3761 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			ArgList* a_list_p = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node));
			if (a_list_p) a_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
			(yyval.node) = (yysemantic_stack_[(3) - (1)].node);
		}
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3773 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3787 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3791 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3795 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3805 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
								NULL,
								NULL,
								NULL);
		}
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3813 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(5) - (2)].sval))),
								NULL,
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)), 
								NULL);
		}
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3821 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(8) - (2)].sval))),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(8) - (6)].sval))),
								NULL,
								NULL);
		}
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3829 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(9) - (2)].sval))),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(9) - (7)].sval))),
								NULL,
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node)));
		}
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3837 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(9) - (2)].sval))),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(9) - (7)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
								NULL);
		}
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3845 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(10) - (2)].sval))),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(10) - (8)].sval))),
								dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)), 
								dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node)));
		}
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3860 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = new DirElemContentList(LOC ((yyloc)));
			elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)));
			(yyval.node) = elem_content_list_p;
		}
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3866 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			DirElemContentList* elem_content_list_p = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (elem_content_list_p) elem_content_list_p->push_back(dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)));
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3878 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = new DirAttributeList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		}
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3884 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			DirAttributeList* at_list_p = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3897 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttr(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(6) - (2)].sval))),
								dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
		}
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 3914 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		}
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 3919 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DirAttributeValue(LOC ((yyloc)),
								dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
		}
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 3930 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrContentList(LOC ((yyloc)));
		}
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 3934 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 3941 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			(yyval.node) = qo_list_p;
		}
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 3947 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = new QuoteAttrContentList(LOC ((yyloc)));
			qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = qo_list_p;
		}
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 3953 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(new QuoteAttrValueContent(LOC ((yyloc)),std::string("\"")));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 3961 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			QuoteAttrContentList* qo_list_p = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (qo_list_p) {
				qo_list_p->push_back(dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 3975 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrContentList(LOC ((yyloc)));
		}
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 3979 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 3986 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			(yyval.node) = at_list_p;
		}
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 3992 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = new AposAttrContentList(LOC ((yyloc)));
			at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)));
			(yyval.node) = at_list_p;
		}
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 3998 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(new AposAttrValueContent(LOC ((yyloc)),"'"));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4006 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			AposAttrContentList* at_list_p = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
			if (at_list_p) {
				at_list_p->push_back(dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)));
			}
			(yyval.node) = (yysemantic_stack_[(2) - (1)].node);
		}
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4020 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4025 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new QuoteAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4036 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4041 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AposAttrValueContent(LOC ((yyloc)),
								dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4052 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].expr));
		}
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4057 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4062 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cdata_h);
		}
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4068 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
			(yyval.expr) = new DirElemContent(LOC ((yyloc)),
								cont_h);
		}
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4080 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
                ParseConstants::cont_charref,
								SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4086 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_lbrace);
		}
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4091 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								ParseConstants::cont_escape_rbrace);
		}
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4096 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CommonContent(LOC ((yyloc)),
								dynamic_cast<EnclosedExpr*>((yysemantic_stack_[(1) - (1)].expr)));
		}
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4107 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirCommentConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4112 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor(LOC ((yyloc)), "");
    }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4127 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)));
		}
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4132 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new DirPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(3) - (2)].sval)),
								SYMTAB ((yysemantic_stack_[(3) - (3)].sval)));
		}
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4149 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CDataSection(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(2) - (2)].sval)));
		}
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4164 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4168 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4172 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4176 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4180 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4184 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
		}
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4194 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompDocConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4205 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
								NULL);
		}
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4211 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(5) - (2)].sval))),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4217 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4222 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompElemConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4244 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (2)].sval))),
								NULL);
		}
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4250 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(5) - (2)].sval))),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4256 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4261 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompAttrConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4272 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompTextConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4282 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompCommentConstructor(LOC ((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
		}
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4292 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(4) - (2)].sval)),
								NULL);
		}
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4298 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								SYMTAB ((yysemantic_stack_[(5) - (2)].sval)),
								(yysemantic_stack_[(5) - (4)].expr));
		}
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4304 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(6) - (3)].expr), NULL);
		}
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4309 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new CompPIConstructor(LOC ((yyloc)),
								(yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
		}
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4320 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)),
								false);
		}
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4326 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SingleType(LOC ((yyloc)),
								dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)),
								true);
		}
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4338 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(2) - (2)].node);
		}
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4349 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(1) - (1)].node),
								NULL);
		}
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4355 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)),
								(yysemantic_stack_[(2) - (1)].node),
								dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
		}
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4361 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SequenceType(LOC ((yyloc)), NULL, NULL);
		}
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4398 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_optionally);
		}
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4403 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_zero_or_more);
		}
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4408 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new OccurrenceIndicator(LOC ((yyloc)),
								ParseConstants::occurs_one_or_more);
		}
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4419 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4423 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4427 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ItemType(LOC ((yyloc)),true);
		}
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4437 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AtomicType(LOC ((yyloc)),
								new QName(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(1) - (1)].sval))));
		}
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4448 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4452 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4456 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4460 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4464 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4468 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4472 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4476 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4480 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4490 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AnyKindTest(LOC ((yyloc)));
		}
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4500 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)));
		}
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4504 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4509 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new DocumentTest(LOC ((yyloc)),
								dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
		}
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4520 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TextTest(LOC ((yyloc)));
		}
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4530 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new CommentTest(LOC ((yyloc)));
		}
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4540 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), "");
		}
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4544 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		}
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4548 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new PITest(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval)));
		}
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4558 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		}
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4564 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (3)].sval))),
								NULL);
		}
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4570 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(6) - (3)].sval))),
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		}
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4576 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								NULL);
		}
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4582 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new AttributeTest(LOC ((yyloc)),
								NULL,
								dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)));
		}
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4594 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaAttributeTest(LOC ((yyloc)),
								new QName(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (2)].sval))));
		}
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4605 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           NULL,
                           NULL,
                           true);
		}
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4612 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(4) - (3)].sval))),
                           NULL,
                           true);
		}
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4619 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)),SYMTAB ((yysemantic_stack_[(6) - (3)].sval))),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           false);
		}
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4626 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
                           new QName(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(6) - (3)].sval))),
                           dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                           true);
		}
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4633 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									NULL,
									true);
		}
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4640 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									false);
		}
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4647 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new ElementTest(LOC ((yyloc)),
									NULL,
									dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
									true);
		}
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4660 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new SchemaElementTest(LOC ((yyloc)),
									new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(4) - (3)].sval))));
		}
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4681 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(1) - (1)].sval))));
		}
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4688 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = new TypeName(LOC ((yyloc)),
								new QName(LOC ((yyloc)),SYMTAB ((yysemantic_stack_[(2) - (1)].sval))),
								true);
		}
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4708 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.expr) = new StringLiteral(LOC ((yyloc)), SYMTAB ((yysemantic_stack_[(1) - (1)].sval)));
		}
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4748 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::strict_validation);
		}
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4752 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::lax_validation);
    }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4756 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new RevalidationDecl (LOC ((yyloc)), StaticContextConsts::skip_validation);
    }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4765 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4771 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4777 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4783 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4789 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4796 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4802 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4808 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4814 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4820 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new InsertExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4832 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4837 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4847 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4853 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new ReplaceExpr(
                  LOC ((yyloc)),
                  store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4865 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new RenameExpr(
                  LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
		}
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4891 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr(LOC((yyloc)), lList, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr));
		}
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4902 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       CopyVarList* lList = new CopyVarList(LOC((yyloc)));
       lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = lList;
		}
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4908 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
       VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
       lList->push_back(lBinding);
       (yyval.expr) = lList;
		}
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4921 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), SYMTAB ((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (3)].expr));  
    }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4935 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new TryExpr(LOC ((yyloc)),
								       (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4942 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       CatchListExpr* aCatchListExpr = new CatchListExpr(LOC ((yyloc)));
       aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)));
       (yyval.expr) = aCatchListExpr;
    }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4948 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* aCatchListExpr = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if (aCatchListExpr) {
        aCatchListExpr->push_back(static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)));
      }
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4959 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(3) - (2)].name_test_list),
                          (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4966 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(7) - (2)].name_test_list),
                          SYMTAB ((yysemantic_stack_[(7) - (5)].sval)),
                          (yysemantic_stack_[(7) - (7)].expr));
       delete (yysemantic_stack_[(7) - (2)].name_test_list);
    }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4975 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(10) - (2)].name_test_list),
                          SYMTAB ((yysemantic_stack_[(10) - (5)].sval)),
                          SYMTAB ((yysemantic_stack_[(10) - (8)].sval)),
                          (yysemantic_stack_[(10) - (10)].expr));
       delete (yysemantic_stack_[(10) - (2)].name_test_list);
    }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4984 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC ((yyloc)),
                          *(yysemantic_stack_[(13) - (2)].name_test_list),
                          SYMTAB ((yysemantic_stack_[(13) - (5)].sval)),
                          SYMTAB ((yysemantic_stack_[(13) - (8)].sval)),
                          SYMTAB ((yysemantic_stack_[(13) - (11)].sval)),
                          (yysemantic_stack_[(13) - (13)].expr));
       delete (yysemantic_stack_[(13) - (2)].name_test_list);
    }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4997 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      CatchExpr::NameTestList *name_test_list = new CatchExpr::NameTestList;
      name_test_list->push_back (static_cast<NameTest *> ((yysemantic_stack_[(1) - (1)].node)));
      (yyval.name_test_list) = name_test_list;
    }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 5003 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      CatchExpr::NameTestList *name_test_list =
        static_cast<CatchExpr::NameTestList *> ((yysemantic_stack_[(3) - (1)].name_test_list));
      name_test_list->push_back (static_cast<NameTest *> ((yysemantic_stack_[(3) - (3)].node)));
      (yyval.name_test_list) = name_test_list;
    }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 5015 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = (yysemantic_stack_[(1) - (1)].sval); }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 5020 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      std::string tmp = SYMTAB ((yysemantic_stack_[(1) - (1)].sval));
      if (tmp.find (':') != std::string::npos) {
        error((yylocation_stack_[(1) - (1)]), "A NCName is expected, found a QName");
        YYERROR;
      }
      (yyval.sval) = (yysemantic_stack_[(1) - (1)].sval);
    }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 5036 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = (yysemantic_stack_[(1) - (1)].sval); }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 5039 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("xquery"); }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 5040 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty"); }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 5041 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("attribute"); }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 5042 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("comment"); }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 5043 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document-node"); }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 5044 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("element"); }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 5045 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("item"); }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5046 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("if"); }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5047 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("node"); }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5048 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("processing-instruction"); }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5049 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-attribute"); }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5050 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema-element"); }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5051 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("text"); }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5052 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("typeswitch"); }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5053 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("empty-sequence"); }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5054 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("boundary-space"); }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5055 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ft-option"); }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5056 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("base-uri"); }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5057 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lax"); }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5058 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strict"); }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5059 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("idiv"); }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5060 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("document"); }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5061 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("not"); }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5062 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sensitive"); }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5063 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insensitive"); }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5064 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("diacritics"); }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5065 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("without"); }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5066 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stemming"); }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5067 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("thesaurus"); }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5068 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stop"); }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5069 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("wildcards"); }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5070 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("entire"); }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5071 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("content"); }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5072 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("word"); }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5073 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("start"); }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5074 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("end"); }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5075 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("most"); }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5076 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("skip"); }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5077 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy"); }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5078 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("value"); }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5079 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eq"); }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5080 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ne"); }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5081 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lt"); }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5082 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("le"); }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5083 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("gt"); }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5084 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ge"); }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5085 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("at"); }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5086 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("context"); }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5087 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("variable"); }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5088 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("return"); }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5089 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("for"); }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5090 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("outer"); }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5091 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sliding"); }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5092 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("tumbling"); }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5093 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("previous"); }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5094 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("next"); }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5095 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("only"); }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5096 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("when"); }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5097 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("count"); }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5098 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("in"); }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5099 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("let"); }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5100 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("where"); }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5101 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("by"); }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5102 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("group"); }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5103 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("order"); }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5104 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("stable"); }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5105 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ascending"); }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5106 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("descending"); }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5107 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("greatest"); }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5108 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("least"); }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5109 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("collation"); }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5110 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("some"); }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5111 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("every"); }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5112 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("satisfies"); }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5113 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("case"); }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5114 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("as"); }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5115 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("then"); }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5116 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("else"); }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5117 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("or"); }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5118 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("and"); }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5119 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("instance"); }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5120 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("of"); }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5121 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("castable"); }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5122 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("to"); }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5123 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("div"); }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5124 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("mod"); }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5125 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("union"); }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5126 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("intersect"); }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5127 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("except"); }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5128 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("validate"); }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5129 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("cast"); }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5130 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("treat"); }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5131 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("is"); }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5132 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("preserve"); }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5133 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("strip"); }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5134 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("namespace"); }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5135 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("external"); }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5136 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("encoding"); }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5137 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-preserve"); }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5138 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("inherit"); }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5139 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("no-inherit"); }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5140 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("declare"); }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5141 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("construction"); }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5142 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordering"); }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5143 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("default"); }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5144 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("copy-namespaces"); }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5145 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("option"); }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5146 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("version"); }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5147 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("import"); }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5148 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("schema"); }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5149 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("module"); }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5150 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("function"); }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5151 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("score"); }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5152 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ftcontains"); }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5153 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("weight"); }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5154 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("window"); }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5155 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("distance"); }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5156 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("occurs"); }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5157 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("times"); }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5158 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("same"); }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5159 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("different"); }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5160 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("lowercase"); }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5161 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("uppercase"); }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5162 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("relationship"); }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5163 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("levels"); }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5164 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("language"); }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5165 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("any"); }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5166 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("all"); }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5167 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("phrase"); }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5168 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exactly"); }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5169 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("from"); }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5170 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("words"); }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5171 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentences"); }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5172 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sentence"); }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5173 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("paragraph"); }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5174 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("replace"); }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5175 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("modify"); }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5176 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("first"); }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5177 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("insert"); }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 5178 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("before"); }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5179 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("after"); }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 5180 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("revalidation"); }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 5181 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("with"); }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 5182 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nodes"); }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 5183 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("rename"); }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 5184 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("last"); }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 5185 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("delete"); }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 5186 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("into"); }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 5187 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("simple"); }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 5188 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("sequential"); }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 5189 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("updating"); }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 5190 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("deterministic"); }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 5191 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("nondeterministic"); }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 5192 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("ordered"); }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 5193 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unordered"); }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 5194 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("block"); }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 5195 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("exit"); }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 5196 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("loop"); }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 5197 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("while"); }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 5198 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("break"); }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 5199 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("continue"); }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 5200 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("try"); }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 5201 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("catch"); }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 5202 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("eval"); }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 5203 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("using"); }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 5204 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("set"); }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 5205 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("index"); }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 5206 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("create"); }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 5207 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("build"); }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 5208 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("unique"); }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 5209 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("on"); }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 5210 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("hash"); }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 5211 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("btree"); }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 5212 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("drop"); }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 5213 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("decimal-format"); }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 5214 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("decimal-separator"); }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 5215 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("grouping-separator"); }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 5216 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("infinity"); }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 5217 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("minus-sign"); }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 5218 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("NaN"); }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 5219 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("percent"); }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 5220 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("per-mille"); }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 5221 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("zero-digit"); }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 5222 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("digit"); }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 5223 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    { (yyval.sval) = SYMTAB_PUT ("pattern-separator"); }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 5235 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new EvalExpr (LOC ((yyloc)),
                          dynamic_cast<VarGetsDeclList *> ((yysemantic_stack_[(7) - (3)].node)),
                          (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 5241 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new EvalExpr (LOC ((yyloc)), new VarGetsDeclList (LOC ((yyloc))), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 5258 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(1) - (1)].node)), NULL, NULL);
		}
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 5262 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(2) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(2) - (2)].node)), NULL);
		}
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 5266 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(3) - (1)].node)), NULL, static_cast<RangeExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		}
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 5270 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTSelection (LOC ((yyloc)), static_cast<FTOr *> ((yysemantic_stack_[(4) - (1)].node)), static_cast<FTMatchOptionProximityList *> ((yysemantic_stack_[(4) - (2)].node)), static_cast<RangeExpr *> ((yysemantic_stack_[(4) - (4)].expr)));
		}
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 5280 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 5283 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 5286 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 5289 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 5298 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 5301 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 5310 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 5313 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 5322 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 5325 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 5334 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 5337 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 5346 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 5349 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 5352 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 5361 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 5364 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 5373 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), static_cast<StringLiteral *> ((yysemantic_stack_[(1) - (1)].expr)), NULL);
		}
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 5377 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWordsValue (LOC ((yyloc)), NULL, (yysemantic_stack_[(3) - (2)].expr));
		}
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 5387 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 5390 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 5393 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 5396 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 5399 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 5408 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 5417 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 5421 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 5425 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 5429 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 5433 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 5437 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 5441 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
			(yyval.node) = (yysemantic_stack_[(1) - (1)].node);
		}
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 5451 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 5454 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 5457 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 5460 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 5469 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 5472 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 5475 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 5478 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 5487 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 5490 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 5499 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 5502 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 5505 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 5508 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 5511 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 5514 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 5517 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 5526 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 5529 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 5538 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 5541 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 5544 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 5547 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 5556 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 5559 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 5562 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 5565 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 5568 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 5577 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 5580 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 5589 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 5592 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 5601 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 5604 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 5613 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 5616 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 5625 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 5634 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 5637 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 5646 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 5649 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 5652 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 5661 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 5664 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 5667 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 5670 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 5673 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 5682 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::exactly, (yysemantic_stack_[(2) - (2)].expr));
		}
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 5686 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_least, (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 5690 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::at_most, (yysemantic_stack_[(3) - (3)].expr));
		}
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 5694 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
       (yyval.node) = new FTRange (LOC ((yyloc)), FTRange::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
		}
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 5704 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 5713 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTWindow (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (2)].expr)), static_cast<FTUnit *> ((yysemantic_stack_[(3) - (3)].node)));
		}
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 5723 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 5732 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 5735 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 5744 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 5747 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 5750 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 5759 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 5762 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
		}
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 5771 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTIgnoreOption (LOC ((yyloc)), static_cast<UnionExpr *> ((yysemantic_stack_[(3) - (3)].expr)));
		}
    break;



/* Line 678 of lalr1.cc  */
#line 9717 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"
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
      1376, -1203, -1203, -1203, -1203,   -55,  -147,   239, -1203,   362,
      56,   -27,   111,  6843,   277,   364,   441,    -7, -1203, -1203,
   -1203, -1203, -1203, -1203,   266,    73, -1203,   568,   313, -1203,
     333, -1203, -1203, -1203,   363,   397, -1203,   387,   345,   506,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,   422,
     431, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,
   -1203, -1203,  7109, -1203,  6035, -1203, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,  8705, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203,   488, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,  1651,
    8705, -1203, -1203, -1203, -1203, -1203, -1203,   463, -1203, -1203,
   -1203, -1203,   603, -1203,  6577, -1203, -1203, -1203, -1203, -1203,
    8705, -1203, -1203,  5761, -1203, -1203, -1203, -1203, -1203, -1203,
     473, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,    21,
     415, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,   -97,
     478,   227, -1203,   413,   375, -1203, -1203, -1203, -1203, -1203,
   -1203,   538, -1203,   508, -1203,   549, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,
   -1203, -1203,   398,   404,   417, -1203, -1203, -1203, -1203, -1203,
    4117,   693, -1203,  4391, -1203, -1203,   116,  4665,   513,   514,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,
     -41, -1203, -1203, -1203, -1203,   286,  8705, -1203, -1203, -1203,
   -1203, -1203,   531,   610, -1203,   544,   453,   233,   258,    92,
     351, -1203,   630,   515,   608,   612,  4939, -1203, -1203, -1203,
     265, -1203, -1203,  5761, -1203,   103, -1203,   566,  6035, -1203,
     566,  6035, -1203, -1203, -1203, -1203,   566, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203,   565, -1203, -1203, -1203, -1203,
    4665, -1203, -1203,  4665,  8705,  4665,   571,   572,  4665, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203,  4665,  7375, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,
   -1203,   573,  4665,  4665,   541,  4665,   542,  8705,   685,   686,
     600,   600,   685,  8705,    84,   269,   708,   -31,   319,  8705,
     580,   624,   316,  8971,   336,    48,   370,   708, -1203, -1203,
     470, -1203, -1203, -1203, -1203, -1203,  4665, -1203,  4665,    80,
     601,    37,    36,  8705,  8971,  8705,  8705,  4665,   480,   484,
   -1203,   634,   636,  8705,    16,  4665,  7641,   605,   607,   609,
     611,   613,   614, -1203, -1203, -1203,  8705, -1203,   578,   736,
    4665,    51, -1203,   750,   585, -1203,  4665,   560, -1203,   751,
    4665,  4665,   589,  4665,  4665,  4665,  4665,   545,  8705,  4665,
    8705,   708,   708,   708, -1203, -1203, -1203, -1203,    -7,   568,
   -1203, -1203,   116,   734,  4665, -1203,  4665,   616,   397,   345,
     506,   657,   617,   618,  4665,  4665, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203,   669, -1203,   -45,  5213,  5213,  5213, -1203,
    5213,  5213, -1203,  5213, -1203,  5213, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203,  5213,  5213,    12,  5213,  5213,  5213,  5213,
    5213,  5213,  5213,  5213,  5213,  5213,  5213,   550,   683,   689,
     692, -1203, -1203, -1203,  1925, -1203, -1203,  5761,  5761,  4665,
     566, -1203, -1203,   566, -1203,   566,  2199,  5487, -1203,   604,
     638, -1203,   615,  4665,  4665,   606,   619, -1203,     0,     5,
    2473,   620,   622, -1203,   623, -1203,   637, -1203,  8705, -1203,
   -1203, -1203, -1203,   771, -1203, -1203, -1203, -1203, -1203, -1203,
     687,   690, -1203, -1203,   652,   324,  8705,   469,   647,   648,
     652,   708,   681,   678, -1203, -1203, -1203, -1203, -1203,    96,
     170,   405,   789, -1203, -1203,   229, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203,   527, -1203,   628,   632,   631,
   -1203,   633,  2747,  8971,   717,   779,  8971,   708,   721,     2,
   -1203,    30,   688,   679,   713, -1203,   -39,   641, -1203, -1203,
    8705,   -35, -1203,   639,   607,   422, -1203,   640,   642,   644,
   -1203,    22,    57,  3021,    19, -1203,  8705,   736, -1203,   -12,
     649, -1203, -1203, -1203, -1203,   650, -1203,   -11, -1203, -1203,
   -1203,    79,   167,   733,   594,   621,   -57, -1203,   691,   653,
      54, -1203, -1203, -1203, -1203, -1203,   645, -1203,    40, -1203,
   -1203,   -19,   667,  8705,  4665,   718, -1203, -1203,   719,  8173,
     720,  4665,   722,   -34,   695,   -36,   610, -1203, -1203, -1203,
   -1203, -1203,  5213, -1203, -1203, -1203,  4665,    12,   218, -1203,
     574,   274,   584,   592, -1203, -1203,   588,   235,   258,   258,
     178,    92,    92,    92,    92,   351,   351, -1203, -1203,  8173,
    8173,  8705,  8705, -1203,   662, -1203, -1203,   666, -1203, -1203,
   -1203,   104,   624,    14,   668,   -55,  4665, -1203,   670,   671,
     749,   702,  8705, -1203,  8705, -1203, -1203,   673, -1203, -1203,
   -1203,    -5,   228,   637, -1203,   214,   246, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203,   652, -1203,   724,
    8439,   715,  4665, -1203, -1203, -1203,   762,   723,  4665,   708,
     708,   652, -1203,   537,   708, -1203, -1203,   586, -1203, -1203,
     587,   283, -1203, -1203, -1203, -1203, -1203, -1203,   591, -1203,
   -1203,  4665,   663,   709, -1203, -1203, -1203,   682,   731,   708,
     710,   735,   770,   708,   752,  4665,  4665,   729,   708,  4665,
     757,  4665,   728,   -63, -1203,   162,   629, -1203, -1203,   483,
     -35, -1203, -1203, -1203,   730,  8705, -1203,  8705, -1203, -1203,
     698,  4665,   852, -1203,    35, -1203,   146, -1203, -1203,   861,
   -1203,   317,  4665,  4665,  4665,   424,  4665,  4665,  4665,  4665,
    4665,  4665,   764,  4665,  4665,   651,   738,   765,   734,   805,
   -1203,  4665, -1203,   407,   778, -1203,  8705,   782, -1203,  8705,
     737,   743, -1203,   257, -1203, -1203, -1203,  8705, -1203,  8705,
    4665,   742,  4665,  4665,   -30,   754, -1203,   725,   716, -1203,
     654, -1203,   236, -1203,   356,   -53,   655,    12,   356,  5213,
    5213,   392, -1203, -1203, -1203, -1203, -1203, -1203, -1203,    12,
     756,   -53, -1203,   635,   846, -1203, -1203, -1203, -1203, -1203,
     767, -1203, -1203, -1203,  4665, -1203,   766, -1203,   624, -1203,
   -1203, -1203,   727, -1203, -1203,  7907,   438, -1203,  3295,   732,
     739,   768,   740,   744, -1203,  8705,   810,   128, -1203, -1203,
    4665, -1203,   -55, -1203, -1203, -1203, -1203, -1203,   891,   490,
   -1203, -1203, -1203,  4665, -1203, -1203, -1203, -1203, -1203, -1203,
     646,    24,   892, -1203,   383, -1203, -1203,   747,  4665,  3569,
   -1203,   708,   811, -1203, -1203, -1203,   708,   811,  8705, -1203,
   -1203,  4665,   741, -1203,  8705, -1203,  4665,  4665,   781,  4665,
     785, -1203,   807,   812,  4665,  8705,   599,   862, -1203, -1203,
   -1203,  3843,   755,   758, -1203, -1203, -1203,   803, -1203,   176,
   -1203, -1203,   929, -1203, -1203,  4665,  8705, -1203, -1203,   181,
   -1203, -1203, -1203,   753,   707,   712, -1203, -1203, -1203,   714,
     726, -1203, -1203, -1203, -1203, -1203,   705,  8705,   761, -1203,
    6309,   651, -1203,  4665,  8705,   778, -1203,   708, -1203,   543,
   -1203,    32,   839, -1203,  4665,   840,   718, -1203,   769,   772,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203,  4665, -1203, -1203,
    4665,   804,  4665, -1203, -1203,  5213, -1203, -1203, -1203, -1203,
   -1203,    53,  5213,  5213,   349, -1203,   584, -1203, -1203,   207,
    5213, -1203, -1203,   592,    12,   684, -1203, -1203, -1203, -1203,
    4665, -1203, -1203,  8705,   776,   141, -1203, -1203,   773, -1203,
   -1203, -1203, -1203, -1203,   762,  8173,   829,   855,   774, -1203,
   -1203, -1203, -1203,   132,   931,   940,   132,    -3,   129,   134,
     813,   841, -1203,   783,   868,   708,   811, -1203, -1203, -1203,
   -1203, -1203, -1203,  4665, -1203,  4665,  8705,  8705, -1203,   443,
   -1203,  4665, -1203,   787, -1203, -1203,   852,  8705,   211, -1203,
     788,   852,  8705, -1203, -1203,  4665,  4665,  4665,  4665,  4665,
   -1203,  4665, -1203,   160, -1203,   790, -1203, -1203, -1203, -1203,
     839, -1203, -1203, -1203,   708, -1203, -1203, -1203, -1203, -1203,
   -1203,  4665, -1203,    92,  5213,  5213,    92,   386, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203,   875,  4665,  8705,
    4665, -1203, -1203, -1203, -1203,  8173, -1203,    24,    24,   132,
   -1203, -1203, -1203,    42,   132,   951,   745,   876, -1203,   876,
   -1203,  4665,   161,  4665, -1203,   708, -1203, -1203, -1203,   906,
   -1203, -1203, -1203, -1203,   -20,   852,  8705, -1203,   784,   852,
   -1203, -1203, -1203, -1203, -1203, -1203,   856,  6309, -1203, -1203,
   -1203, -1203, -1203,    92,    92,  5213,  8173, -1203,   793, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203,   -53, -1203,   171, -1203,
     179, -1203,   870,   762,  4665, -1203, -1203,   811,   860,   339,
     450, -1203,   786,   852, -1203,   791,  8705, -1203,    92,   798,
    4665,   746,   876, -1203, -1203,   708, -1203, -1203,  8705, -1203,
   -1203,   888,   403, -1203, -1203, -1203, -1203,   806,   457, -1203,
   -1203, -1203,   794, -1203,   186,  4665, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,   865,   836,
   -1203,  8705, -1203,   201,   871,   836,  8705, -1203,   808,   836,
   -1203
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
         0,   377,   378,   560,   524,   717,   718,   721,   719,   722,
     720,   651,   575,   567,   583,   574,   565,   663,   673,   712,
     711,   713,   714,   710,   569,   571,   598,   670,   633,   627,
     672,   668,   595,   671,   727,   622,   664,   725,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   665,   579,   573,
     566,   667,   642,   572,   577,   736,   737,   738,   739,   740,
     741,   742,   743,   744,   745,   746,   368,   371,   641,   637,
     628,   608,   564,   358,     0,   636,   644,   652,   356,   632,
     394,   609,   610,   666,   357,   360,   629,   646,     0,   400,
     366,   396,   639,   563,   630,   631,   659,   634,   650,   658,
     362,   361,   582,   621,   661,   395,   649,   654,   568,     0,
       0,   315,   647,   657,   662,   660,   640,   715,   626,   624,
     625,   367,     0,   314,     0,   370,   369,   655,   611,   635,
       0,   359,   344,     0,   376,   656,   638,   645,   653,   648,
     716,   602,   607,   606,   605,   604,   603,   576,   623,     0,
     562,   669,   596,   702,   701,   703,   581,   580,   599,   708,
     570,   700,   705,   706,   697,   601,   643,   699,   709,   707,
     698,   600,   704,   723,   724,   726,   689,   688,   585,   578,
     587,   586,   682,   678,   593,   597,   594,   691,   692,   675,
     584,   687,   686,   683,   679,   696,   690,   685,   681,   674,
     695,   694,   680,   684,   676,   677,   588,   589,   591,   693,
     590,   592,   729,   730,   735,   731,   728,   733,   734,   732,
       0,     0,     2,     0,     4,     6,     0,     0,     0,     0,
      17,    19,    31,    21,    22,    23,    47,    24,    28,    29,
      51,    52,    53,    48,    49,    55,    56,    26,    25,    30,
      50,   173,   172,   169,   170,   171,   174,    27,    11,   150,
     151,   155,   157,   189,   195,     0,     0,   187,   188,   158,
     159,   160,   161,   271,   273,   275,   285,   288,   290,   293,
     298,   301,   304,   306,   308,   310,     0,   312,   318,   320,
       0,   336,   319,   340,   343,   345,   348,   350,     0,   355,
     352,     0,   363,   373,   375,   349,   379,   384,   392,   385,
     386,   387,   390,   391,   388,   389,   407,   409,   410,   411,
     408,   456,   457,   458,   459,   460,   461,   372,   498,   490,
     497,   496,   495,   492,   494,   491,   493,   393,    54,   162,
     163,   165,   164,   166,   167,   374,   561,   168,   121,   118,
       0,   129,   130,     0,     0,     0,     0,     0,     0,   717,
     718,   721,   722,   720,   651,   575,   567,   583,   574,   565,
     663,   569,   571,   670,   633,   672,   727,   622,   725,   612,
     613,   573,   566,   564,   634,     0,     0,   715,   716,   562,
     708,   570,   700,   706,   697,   600,   723,   726,   729,   730,
     735,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    98,    99,
       0,   100,   101,   103,   134,   137,     0,   559,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     197,     0,     0,     0,     0,     0,     0,     0,   567,   574,
     565,   571,   564,   364,   374,   397,     0,   398,     0,   423,
       0,     0,   339,     0,     0,   342,     0,     0,   452,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     3,     1,     5,     7,     0,     0,
      12,    10,    14,    15,     0,   153,   152,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   175,   194,   190,   196,
     191,   193,   192,   199,   200,     0,     0,     0,     0,   329,
       0,     0,   327,     0,   280,     0,   328,   321,   326,   325,
     324,   323,   322,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   317,   316,   313,     0,   337,   341,     0,     0,     0,
     351,   381,   354,   353,   365,   380,     0,     0,   127,     0,
       0,   522,     0,     0,     0,     0,     0,   514,     0,     0,
       0,     0,     0,   503,     0,   504,     0,   139,     0,   140,
     136,   135,   138,     0,   112,   113,    64,    65,   556,    73,
       0,     0,    58,    59,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   557,   558,   525,   526,   527,     0,
       0,     0,     0,   785,   786,     0,    63,   778,   779,   780,
     781,   782,   783,   784,   102,     0,   104,     0,     0,     0,
     505,     0,     0,     0,    82,     0,     0,     0,    74,     0,
     260,     0,     0,     0,   212,   213,     0,     0,   177,   178,
       0,     0,   198,     0,     0,     0,   500,     0,     0,     0,
     508,     0,     0,     0,     0,   399,   424,   423,   420,     0,
       0,   454,   453,   338,   513,     0,   451,     0,   538,   539,
     499,     0,     0,     0,     0,     0,     0,   544,     0,     0,
       0,   215,   232,   131,   133,   132,     0,    18,     0,    20,
     156,     0,     0,     0,     0,     0,   176,   233,     0,     0,
       0,     0,     0,     0,     0,     0,   272,   274,   278,   284,
     283,   282,     0,   279,   276,   277,     0,     0,     0,   770,
     286,   749,   757,   759,   761,   763,   765,   768,   292,   291,
     289,   295,   296,   297,   294,   299,   300,   303,   302,     0,
       0,     0,     0,   334,     0,   346,   347,     0,   382,   403,
     405,     0,   663,     0,     0,     0,     0,   330,     0,     0,
       0,     0,     0,   518,     0,   515,   463,     0,   462,   471,
     472,     0,     0,     0,    62,     0,     0,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    33,    34,     0,
       0,    90,     0,    86,    88,    89,    93,    96,     0,     0,
       0,    32,    72,     0,     0,   787,   788,     0,   789,   793,
       0,     0,   822,   791,   792,   821,   790,   794,     0,   801,
     823,     0,     0,     0,   507,   506,   473,     0,     0,     0,
       0,     0,    75,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   748,     0,     0,   179,   180,     0,
     185,   521,   501,   502,     0,     0,   511,     0,   509,   467,
       0,     0,   423,   421,     0,   412,     0,   401,   402,     0,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,     0,
     154,     0,   186,   244,   240,   242,     0,   234,   235,     0,
     568,   576,   479,   480,   486,   487,   489,     0,   202,     0,
       0,     0,     0,     0,     0,     0,   281,     0,     0,   764,
       0,   287,     0,   777,     0,     0,     0,     0,     0,     0,
       0,   750,   754,   772,   753,   776,   774,   773,   775,     0,
       0,     0,   766,   829,   827,   831,   769,   305,   307,   309,
     477,   311,   335,   383,     0,   404,   124,   123,     0,   120,
     119,   128,     0,   332,   331,     0,     0,   266,     0,     0,
       0,   522,     0,     0,   464,     0,   114,     0,   144,   142,
       0,   141,     0,    70,    71,    68,    69,    35,     0,     0,
      91,    92,    94,     0,    95,    60,    61,    66,    67,    57,
       0,     0,     0,   796,     0,   795,   812,     0,     0,     0,
     474,     0,    84,    78,    81,    80,     0,    76,     0,   258,
     262,     0,     0,   126,     0,   217,     0,     0,     0,     0,
       0,   181,     0,     0,     0,     0,   226,     0,   223,   228,
     184,     0,     0,     0,   468,   259,   424,     0,   413,     0,
     447,   444,     0,   448,   449,     0,     0,   450,   443,     0,
     418,   446,   445,     0,     0,     0,   531,   532,   528,     0,
       0,   536,   537,   533,   542,   540,     0,     0,     0,   546,
       0,   547,   548,     0,     0,   241,   253,     0,   254,     0,
     245,   246,   247,   248,     0,   237,     0,   201,     0,     0,
     483,   485,   484,   481,   210,   211,   204,     0,   206,   203,
       0,     0,     0,   771,   767,     0,   824,   825,   845,   844,
     840,     0,     0,     0,     0,   826,   758,   839,   751,     0,
       0,   756,   755,   760,     0,     0,   830,   828,   478,   406,
       0,   122,   333,     0,     0,     0,   267,   465,     0,   519,
     520,   523,   516,   517,   146,     0,     0,   115,     0,   143,
      36,    87,    97,   810,     0,     0,   808,   804,     0,     0,
       0,     0,   475,     0,    83,     0,    77,   261,   263,    13,
     214,   219,   218,     0,   221,     0,     0,     0,   183,   224,
     227,     0,   469,     0,   512,   510,   423,     0,     0,   455,
       0,   423,     0,   419,     9,     0,     0,     0,     0,     0,
     545,     0,   554,     0,   549,     0,   216,   257,   255,   256,
     249,   250,   251,   243,     0,   238,   236,   488,   482,   208,
     205,     0,   207,   846,     0,     0,   832,     0,   843,   842,
     841,   836,   837,   752,   762,   838,   125,     0,     0,     0,
       0,   466,   147,   116,   145,     0,   149,     0,     0,   811,
     813,   815,   817,     0,   809,     0,     0,     0,   799,     0,
     797,     0,     0,     0,   476,     0,    79,   220,   222,   231,
     230,   225,   182,   470,     0,   423,     0,   148,     0,   423,
     529,   530,   534,   535,   541,   543,     0,     0,   550,   747,
     252,   239,   209,   834,   833,     0,     0,   268,     0,   264,
     117,   820,   819,   814,   818,   816,   805,   806,     0,   802,
       0,   110,   106,   108,     0,   105,   270,    85,     0,   433,
     427,   422,     0,   423,   414,     0,     0,   555,   835,     0,
       0,     0,     0,   800,   798,     0,   109,   111,     0,   441,
     435,     0,   434,   436,   442,   439,   429,     0,   428,   430,
     440,   416,     0,   415,     0,     0,   265,   807,   803,   107,
     229,   426,   437,   438,   425,   431,   432,   417,     0,     0,
     269,     0,   551,     0,     0,     0,     0,   552,     0,     0,
     553
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1203, -1203,   775, -1203,   777,   780, -1203,   792, -1203,   486,
     492,  -495, -1203,   376,  -428, -1203, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,  -859,
   -1203, -1203, -1203, -1203,   -29,   177,   576, -1203, -1203, -1203,
   -1203,   579,   569,  -350, -1203, -1203, -1203,   203, -1203,  -760,
   -1203, -1203,    23, -1203, -1203, -1203, -1203, -1203, -1203,   261,
     164, -1203, -1203,  -178, -1203, -1202,   795,   -78, -1203,   503,
    -344, -1203, -1203, -1203, -1203,   133, -1203, -1203,   759, -1203,
   -1203, -1203, -1203, -1203,    83,  -485,  -643, -1203, -1203, -1203,
     -40, -1203, -1203,  -204,   -49,   -98, -1203, -1203, -1203,  -107,
   -1203, -1203,    99,  -103, -1203, -1203,   -96, -1052, -1203,   557,
     -21, -1203, -1203,    33, -1203, -1203,   502,   504, -1203,  -400,
    -905,   482,   140,  -534,   122,   125, -1203, -1203, -1203, -1203,
   -1203,   748, -1203, -1203, -1203, -1203, -1203,   760, -1203, -1203,
    -111, -1203, -1203, -1203, -1203, -1203, -1203, -1203,   -50, -1084,
   -1203, -1203,   187,    20, -1203,  -532, -1203, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203, -1203,  -875, -1203,   -47, -1203,   346,
    -686, -1203, -1203, -1203, -1203, -1203,  -352,  -345, -1026,  -772,
   -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203, -1203,
     267,  -654,  -750, -1203,   220,   -83,  -724, -1203, -1203, -1203,
   -1203, -1203, -1203, -1203,   590,   593,  -718,   244,    25, -1203,
   -1203, -1203, -1203, -1203, -1203, -1203,   -65, -1203, -1203,   -66,
   -1203,  -413,  -414,   -15,   -13,  -396, -1203,   299, -1203, -1203,
      91,    85,  -115,   305, -1203, -1203,    94, -1203,  -707, -1203,
   -1203, -1203, -1203,  -243,  -839, -1203,  -139,  -597, -1203,  -650,
   -1203, -1203, -1203, -1203,  -960, -1203, -1203, -1203, -1203,  -101,
     101, -1203
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   817,   818,   819,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,  1042,
     657,   246,   247,   823,   824,   825,   986,   248,   430,   249,
     431,   432,   433,  1351,  1352,  1302,   250,   802,   251,   349,
     577,   783,   987,   252,   253,   254,   255,   256,   257,   434,
     435,   599,  1007,  1008,  1087,  1011,   258,   259,   506,   260,
     261,   262,   516,   451,   879,   880,   263,   517,   264,   519,
     265,   266,   267,   523,   524,  1066,   734,   268,   664,   710,
     665,   671,  1067,  1068,  1069,   711,   520,   521,   927,   928,
    1255,   522,   924,   925,  1120,  1121,  1122,  1123,   269,   659,
     660,   270,   996,   997,   271,   272,   273,   274,   742,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   543,   544,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   570,   571,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   781,   315,   316,   317,  1089,   687,   688,
     689,  1361,  1387,  1388,  1381,  1382,  1389,  1383,  1090,  1091,
     318,   319,  1092,   320,   321,   322,   323,   324,   325,   326,
     979,   735,   932,  1133,   933,   934,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   580,  1000,   337,   338,
     339,   340,   341,   342,   343,   706,   707,   344,  1111,  1112,
    1243,  1043,   623,   624,   345,   346,   347,   750,   961,   751,
     752,   753,   754,   755,   756,   757,   962,   963,   636,   637,
     638,   639,   640,  1348,  1349,   641,  1289,  1196,  1293,  1290,
     642,   643,   965,   976,  1154,   966,   967,   972,   968,  1271,
    1150,   951
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       401,   894,  1035,   609,  1047,   935,   578,   867,   719,   579,
     440,  1165,   873,   749,   645,   761,   762,   763,   764,   977,
     978,  1088,   475,   872,   463,   991,  1242,   625,   654,   658,
     662,   468,     4,   876,   407,   408,   409,   410,   411,   412,
     733,  1328,   477,  1151,   964,   935,   935,   413,   625,   729,
     912,   730,   674,   414,  1158,   729,   608,   608,   691,   457,
     730,   464,  1344,  1233,   415,   416,   504,   354,   417,  1251,
    1252,   418,   419,  1359,   999,   465,  1002,  1057,   713,   714,
     715,   407,   408,   409,   410,   411,   412,   350,   504,   675,
     941,   437,   945,  1151,   413,   348,   935,   469,   437,   731,
     649,   871,  1264,   667,   420,   421,   422,   792,   943,   864,
     940,   473,   794,  1005,  1140,   916,   895,   474,   899,   419,
    1194,   988,    80,   355,   729,   480,   864,   481,   738,   885,
     739,   740,   610,   741,    91,   743,   698,   699,  1117,   701,
     702,   703,   704,   744,   745,   709,   505,   611,   629,   655,
     423,   420,   421,   919,  1080,  1081,   498,  1119,   105,  1360,
     720,   917,   746,  1078,   887,   747,   499,  1072,   920,  1073,
     726,   727,  1022,   901,   866,   913,   900,  1195,  1006,   877,
    1265,   896,   566,   793,  1080,  1081,   865,  1206,   795,  1080,
    1081,   356,   357,   656,   653,  1199,  1152,  1153,  1330,   676,
     732,   989,  1233,   891,  1088,   886,  1077,  1412,   832,   353,
     424,   984,   878,  1417,  1088,   749,   749,  1420,   732,  1080,
    1081,  1060,   692,   438,   732,  1345,   439,   732,  1079,   732,
    1058,   478,   780,   732,   425,  1186,  1297,  1296,     4,   858,
     888,  1299,   861,  1367,   862,  1174,  1152,  1153,   572,  1082,
     944,   574,  1189,   525,  1162,  1273,   729,   625,  1295,  1279,
     625,   905,   604,   650,   358,   748,  1287,  1083,  1354,  1084,
     351,   935,   426,   427,   428,   429,   605,   582,  1372,  1082,
     585,   425,   630,   837,  1082,   464,  1372,   985,   464,   553,
     631,   567,   568,  1408,   902,   903,  1085,  1083,   554,  1084,
     110,  1141,  1083,   632,  1084,   633,  1059,   586,  1414,   904,
    1010,  1187,  1298,  1326,  1082,   634,   122,  1300,   635,   426,
     427,   428,   429,  1280,   591,   592,  1085,   594,    80,  1288,
     110,  1085,  1083,   546,  1084,   110,   835,  1086,   507,   836,
      91,   581,   946,  1379,  1355,   508,   122,  1080,   509,   510,
     547,   122,   618,  1088,  1373,   149,   511,   619,   647,  1013,
     648,  1085,  1374,  1009,   105,   110,  1327,  1227,   746,  1409,
     952,   747,  1232,   589,   629,   549,  1014,   679,  1010,  1032,
     923,   122,   906,   907,  1415,   149,  1371,   938,   546,  1017,
     149,  1015,   690,   352,   596,   620,  1033,   908,   695,  1130,
     603,   550,  1316,  1017,   553,   547,   614,  1379,  1016,   448,
     449,  1080,   838,   554,   551,   564,  1025,  1026,   820,   436,
     149,  1029,   621,   719,   651,   749,  1159,   402,   548,  1131,
     661,   443,   663,   666,   606,  1283,  1034,   749,   124,   953,
     673,   839,   840,   682,   841,   842,  1357,  1132,   552,   483,
    1146,   484,   512,   661,   513,  1052,   775,   776,  1080,   821,
    1083,   935,  1084,   450,   822,  1080,  1268,   607,   514,  1385,
    1380,   846,  1269,   973,   974,   708,  1385,   712,  1021,  1032,
    1270,   445,   622,  1147,  1024,   555,   774,   573,   952,  1085,
     444,   777,   629,   575,   515,   975,  1198,   612,   556,   784,
     847,   848,  1116,   849,   850,   788,   789,  1037,   630,  1062,
    1063,   613,   797,  1117,   403,   446,   631,   404,   954,   955,
     956,  1049,  1050,  1118,  1083,  1053,  1084,  1055,   957,   632,
    1282,   633,  1119,  1398,  1402,  1340,   958,   447,   995,   730,
    1314,   634,   959,   960,   635,  1318,  1094,  1075,  1095,  1062,
    1063,  1175,  1064,  1085,   626,   627,   628,   953,  1096,  1097,
    1098,   935,  1101,  1102,  1103,  1104,  1105,  1106,   452,  1108,
    1109,  1083,   597,  1084,   857,   453,   602,   923,  1083,   730,
    1084,  1335,  1386,   553,   454,   803,  1369,  1384,  1390,  1405,
     778,   405,   554,   778,   406,   778,  1136,   486,  1138,  1139,
    1085,  1065,   487,   826,   827,   890,   466,  1085,  1268,   828,
    1384,  1263,   935,   470,  1269,  1148,  1390,   471,  1266,  1267,
    1149,   441,  1270,   476,   442,   821,   630,   479,  1204,  1362,
     822,   482,   749,  1365,   631,   485,   954,   955,   956,  1343,
    1169,   407,   408,   409,  1343,   843,   412,   632,   844,   633,
     427,   428,   429,  1099,   958,  1100,   488,   875,   489,   634,
    1160,   960,   635,  1027,  1028,  1062,  1063,   490,   947,  1248,
    1249,   600,   601,   892,   528,   765,   766,  1392,   491,  1192,
     767,   768,   529,   530,   492,   531,   758,   759,   980,   980,
    1341,  1342,   532,   495,  1201,   526,   533,   493,   534,  1376,
     502,   503,   527,   535,  1247,   545,   557,  1208,   992,   559,
     922,   558,  1211,  1212,   560,  1214,   936,   569,   576,   536,
    1218,   583,   584,   590,   593,   595,   407,   598,   608,   615,
    1333,  1334,   807,   808,   809,   810,   811,   812,   813,   814,
     815,   816,   616,   537,   538,   539,   540,   541,   542,   668,
     427,   652,   670,   669,   672,   683,   936,   936,   936,   936,
     386,   685,   404,   686,   406,   693,   439,   456,   694,  1245,
     696,   697,   700,   705,   718,   723,   728,   770,   769,  1001,
     923,  1001,   722,   771,   724,   725,   772,   785,   786,   790,
     801,   804,  1306,  1259,   805,   787,  1260,   806,  1262,   791,
     798,  1368,   799,   800,   829,   830,   833,   936,   834,   845,
     851,   852,   853,   859,   854,   860,   855,   863,   868,   869,
     870,   874,   881,   882,   884,   883,  1276,   909,   910,   897,
     898,   914,   918,   915,   921,   969,   926,   929,   937,   942,
     939,  1331,   982,   911,   950,   970,   971,   983,   990,   995,
     993,   994,   998,  1004,  1018,   822,   729,  1038,  1030,  1039,
    1031,  1041,  1040,  1023,  1036,  1045,  1046,  1044,  1056,  1307,
    1048,  1308,   581,  1051,   581,  1054,  1061,  1312,  1074,  1076,
    1071,  1093,  1107,  1114,   620,  1124,  1137,  1110,  1113,  1126,
    1128,  1320,  1321,  1322,  1323,  1324,  1129,  1325,  1142,  1144,
    1164,  1167,  1145,  1155,  1185,  1143,  1170,  1172,  1166,  1168,
    1181,     4,  1197,  1125,  1200,  1179,   525,  1332,  1205,  1193,
    1178,  1213,  1180,  1182,  1134,  1216,  1135,  1183,  1209,  1215,
    1217,  1221,  1188,  1226,  1337,  1229,  1339,  1235,  1224,  1239,
    1234,  1225,  1236,  1241,  1237,  1117,  1254,  1005,  1261,  1285,
    1275,  1291,  1257,  1281,  1286,  1258,  1238,  1353,  1278,  1356,
    1292,  1203,  1399,  1304,  1305,  1303,  1301,  1313,  1317,  1336,
    1329,  1346,  1032,  1358,  1366,  1370,  1375,  1364,  1378,  1391,
    1395,  1401,   936,  1411,  1393,  1404,  1010,  1407,   716,  1416,
    1191,  1419,  1184,  1223,   717,   494,   831,   617,  1020,   646,
     496,  1347,  1397,   497,  1377,   644,  1012,  1230,  1284,   721,
    1353,  1171,  1127,  1070,  1210,  1311,  1246,  1220,   500,  1256,
    1115,  1253,   501,   684,   518,  1250,  1396,  1207,   736,  1176,
     760,   737,  1228,   893,   563,   661,  1406,  1403,  1003,   981,
    1019,   666,  1240,  1190,   677,  1244,   948,   678,  1156,  1274,
     565,  1410,  1219,   949,  1163,  1161,  1350,  1294,  1272,  1157,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1231,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   708,     0,     0,   464,     0,     0,
       0,   712,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1277,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   936,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1309,  1310,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1315,     0,     0,     0,     0,  1319,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1338,     0,     0,     0,
       0,     0,   936,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1363,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   464,     0,     0,     0,     0,     0,
       0,     0,     0,   936,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1394,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1400,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     0,     0,
       0,     0,     0,     2,     3,     0,     4,     0,  1413,     0,
       0,     0,     0,  1418,     5,     6,     7,     8,     9,    10,
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
       0,     4,     0,     0,     0,     0,     0,     0,     0,     5,
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
       0,     0,     0,   128,   467,   129,   130,   131,     0,   132,
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
       0,   125,   126,   127,     0,   773,     0,   128,     0,   129,
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
       0,     0,     0,     0,     0,     0,     0,     5,     6,     7,
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
       0,   128,   779,   129,   130,   131,     0,   132,   133,   134,
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
       2,     3,     0,     4,     0,     0,     0,     0,     0,     0,
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
     126,   127,     0,   796,     0,   128,     0,   129,   130,   131,
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
     124,     0,     0,   125,   126,   127,     0,   856,     0,   128,
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
       0,     4,     0,     0,     0,     0,     0,     0,     0,     5,
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
       0,   889,     0,   128,     0,   129,   130,   131,     0,   132,
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
       0,   125,   126,   127,     0,  1177,     0,   128,     0,   129,
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
       0,     0,     0,     0,     0,     0,     0,     5,     6,     7,
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
       0,   123,   124,     0,     0,   125,   126,   127,     0,  1202,
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
       2,     3,     0,     4,     0,     0,     0,     0,     0,     0,
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
     126,   127,     0,  1222,     0,   128,     0,   129,   130,   131,
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
       0,     4,     0,     0,     0,     0,     0,     0,     0,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,     0,    34,
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
       0,   125,   126,   127,     0,     0,     0,   128,     0,   129,
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
       0,     0,     0,     0,     0,     0,     0,   359,   360,   361,
       8,   362,   363,    11,   365,    13,    14,    15,    16,   370,
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
       0,     0,   109,   110,   561,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
       0,   562,   124,     0,     0,   125,   126,   127,     0,     0,
       0,   128,     0,   129,   130,   131,     0,   132,   133,   134,
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
       2,     3,     0,     4,     0,     0,     0,     0,     0,     0,
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
     106,   107,   108,     0,     0,     0,   109,   110,   111,   112,
     113,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,     0,   123,   124,     0,     0,   125,
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
       0,     0,     0,     0,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,   782,    18,    19,
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
       0,     4,     0,     0,     0,     0,     0,     0,     0,   359,
     360,   361,     8,   362,   363,   364,   365,    13,    14,    15,
      16,   370,    18,    19,    20,    21,    22,    23,   371,    25,
      26,   373,   374,    29,   375,    31,    32,    33,     0,   376,
     377,    36,   378,   379,   380,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
      74,    75,    76,    77,     0,     0,    78,    79,     0,     0,
       0,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,     0,    91,     0,    92,    93,    94,    95,     0,
      96,     0,     0,     0,   384,    98,    99,   100,   101,     0,
       0,     0,     0,     0,   102,   103,   104,   105,   106,   107,
     108,     0,     0,     0,   109,   110,     0,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   117,   118,   119,   120,
     121,   122,     0,     0,     0,     0,     0,   125,   126,   127,
       0,     0,     0,   128,     0,   129,   130,   131,     0,     0,
       0,   134,     0,   135,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
     149,     0,   389,   151,     0,   152,   153,   154,   155,   156,
     157,   158,   390,   160,   392,   162,   393,   394,   165,   166,
     167,   168,   169,   170,   395,   172,   396,   174,   397,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,     0,   189,   190,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   398,   399,   400,
     215,   216,   217,   218,   219,     1,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   359,   360,   361,     8,   362,   363,   364,
     365,   458,   367,   459,   460,   370,    18,    19,    20,    21,
      22,    23,   371,   461,    26,   373,   374,    29,   375,    31,
      32,    33,     0,   376,   377,    36,   378,   379,   380,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,     0,     0,    68,     0,    69,
      70,    71,   462,     0,     0,    75,    76,    77,     0,     0,
       0,    79,     0,     0,     0,     0,    81,    82,    83,     0,
       0,    86,    87,     0,     0,     0,     0,     0,     0,    92,
      93,    94,    95,     0,    96,     0,     0,     0,   384,    98,
      99,     0,     0,     0,     0,     0,     0,     0,   102,   103,
     104,     0,   106,   107,   108,     0,     0,     0,     0,     0,
       0,   112,   113,     0,     0,     0,     0,   114,   115,   116,
     387,   118,   119,   120,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   127,     0,     0,     0,   128,     0,   129,
     130,     0,     0,     0,     0,   134,     0,   135,     0,   136,
     137,   138,   139,   388,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,     0,     0,   389,   151,     0,   152,
     153,   154,   155,   156,   157,   158,   390,   160,   392,   162,
     393,   394,   165,   166,   167,   168,   169,   170,   395,   172,
     396,   174,   397,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,     0,   189,   190,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   398,   399,   400,   215,   216,   217,   218,   219,     1,
       0,     0,     0,     0,     0,     0,     2,     3,     0,     0,
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
       0,   128,     0,   129,     0,     0,     0,     0,     0,   134,
       0,   135,     0,   136,   137,   138,   139,   388,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,     0,     0,
     389,   151,     0,   152,   153,   154,   155,   156,   157,   158,
     390,   391,   392,   162,   393,   394,   165,   166,   167,   168,
     169,   170,   395,   172,   396,   174,   397,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,   189,   190,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   398,   399,   400,   215,   216,
     217,   218,   219,   472,     0,     3,     0,     0,     0,     0,
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
     219,     3,     0,     0,     0,     0,     0,     0,     0,     0,
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
     106,   107,   108,   385,     0,     0,   386,     0,     0,   112,
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
       0,     0,   102,   103,   104,     0,   106,   107,   108,   455,
       0,     0,   456,     0,     0,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   387,   118,   119,   120,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   127,     0,     0,
       0,   128,     0,   129,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,   127,     0,     0,     0,   128,   587,   129,
       0,     0,     0,     0,     0,   588,     0,   135,     0,   136,
     137,   138,   139,   388,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,     0,     0,   389,   151,     0,   152,
     153,   154,   155,   156,   157,   158,   390,   391,   392,   162,
     393,   394,   165,   166,   167,   168,   169,   170,   395,   172,
     396,   174,   397,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,     0,   189,   190,     0,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   398,   399,   400,   215,   216,   217,   218,   219,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   359,
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
     108,     0,     0,     0,     0,     0,     0,   112,   113,     0,
       0,     0,     0,   114,   115,   116,   387,   118,   119,   120,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   127,
       0,     0,     0,   128,   680,   129,     0,     0,     0,     0,
       0,   681,     0,   135,     0,   136,   137,   138,   139,   388,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
       0,     0,   389,   151,     0,   152,   153,   154,   155,   156,
     157,   158,   390,   391,   392,   162,   393,   394,   165,   166,
     167,   168,   169,   170,   395,   172,   396,   174,   397,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,     0,   189,   190,     0,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   398,   399,   400,
     215,   216,   217,   218,   219,     3,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   359,   360,   361,     8,   362,
     363,   364,   365,   458,   367,   459,   460,   370,    18,    19,
      20,    21,    22,    23,   371,   461,    26,   373,   374,    29,
     375,    31,    32,    33,     0,   376,   377,    36,   378,   379,
     380,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,     0,     0,    68,
       0,    69,    70,    71,   462,     0,     0,    75,    76,    77,
       0,     0,     0,    79,     0,     0,     0,     0,    81,    82,
      83,     0,     0,    86,    87,  1173,     0,     0,     0,     0,
       0,    92,    93,    94,    95,     0,    96,     0,     0,     0,
     384,    98,    99,     0,     0,     0,     0,     0,     0,     0,
     102,   103,   104,     0,   106,   107,   930,     0,     0,     0,
       0,     0,     0,   112,   113,     0,     0,     0,     0,   114,
     115,   116,   387,   118,   119,   120,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   127,     0,     0,     0,   128,
       0,   129,   130,     0,     0,     0,     0,     0,     0,   135,
       0,   136,   137,   138,   139,   388,   141,   142,   143,   144,
     145,   146,     0,     0,   931,   148,     0,     0,   389,   151,
       0,   152,   153,   154,   155,   156,   157,   158,   390,   160,
     392,   162,   393,   394,   165,   166,   167,   168,   169,   170,
     395,   172,   396,   174,   397,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,     0,   189,
     190,     0,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   398,   399,   400,   215,   216,   217,   218,
     219,     3,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   359,   360,   361,     8,   362,   363,   364,   365,   458,
     367,   459,   460,   370,    18,    19,    20,    21,    22,    23,
     371,   461,    26,   373,   374,    29,   375,    31,    32,    33,
       0,   376,   377,    36,   378,   379,   380,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,     0,     0,    68,     0,    69,    70,    71,
     462,     0,     0,    75,    76,    77,     0,     0,     0,    79,
       0,     0,     0,     0,    81,    82,    83,     0,     0,    86,
      87,     0,     0,     0,     0,     0,     0,    92,    93,    94,
      95,     0,    96,     0,     0,     0,   384,    98,    99,     0,
       0,     0,     0,     0,     0,     0,   102,   103,   104,     0,
     106,   107,   930,     0,     0,     0,     0,     0,     0,   112,
     113,     0,     0,     0,     0,   114,   115,   116,   387,   118,
     119,   120,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   127,     0,     0,     0,   128,     0,   129,   130,     0,
       0,     0,     0,     0,     0,   135,     0,   136,   137,   138,
     139,   388,   141,   142,   143,   144,   145,   146,     0,     0,
     931,   148,     0,     0,   389,   151,     0,   152,   153,   154,
     155,   156,   157,   158,   390,   160,   392,   162,   393,   394,
     165,   166,   167,   168,   169,   170,   395,   172,   396,   174,
     397,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,     0,   189,   190,     0,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   398,
     399,   400,   215,   216,   217,   218,   219,     3,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   359,   360,   361,
       8,   362,   363,   364,   365,   458,   367,   459,   460,   370,
      18,    19,    20,    21,    22,    23,   371,   461,    26,   373,
     374,    29,   375,    31,    32,    33,     0,   376,   377,    36,
     378,   379,   380,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,     0,
       0,    68,     0,    69,    70,    71,   462,     0,     0,    75,
      76,    77,     0,     0,     0,    79,     0,     0,     0,     0,
      81,    82,    83,     0,     0,    86,    87,     0,     0,     0,
       0,     0,     0,    92,    93,    94,    95,     0,    96,     0,
       0,     0,   384,    98,    99,     0,     0,     0,     0,     0,
       0,     0,   102,   103,   104,     0,   106,   107,   930,     0,
       0,     0,     0,     0,     0,   112,   113,     0,     0,     0,
       0,   114,   115,   116,   387,   118,   119,   120,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   127,     0,     0,
       0,   128,     0,   129,   130,     0,     0,     0,     0,     0,
       0,   135,     0,   136,   137,   138,   139,   388,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,     0,     0,
     389,   151,     0,   152,   153,   154,   155,   156,   157,   158,
     390,   160,   392,   162,   393,   394,   165,   166,   167,   168,
     169,   170,   395,   172,   396,   174,   397,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
       0,   189,   190,     0,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   398,   399,   400,   215,   216,
     217,   218,   219,     3,     0,     0,     0,     0,     0,     0,
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
     211,   398,   399,   400,   215,   216,   217,   218,   219,   437,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   359,
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
     108,     0,     0,     0,     0,     0,     0,   112,   113,     0,
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
     215,   216,   217,   218,   219
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
        13,   687,   841,   416,   863,   729,   350,   661,   503,   353,
      25,   971,   666,   545,   427,   549,   550,   551,   552,   769,
     770,   896,   133,   666,    74,   785,  1110,   423,   441,   442,
     444,   109,    20,    68,    41,    42,    43,    44,    45,    46,
     525,  1243,    21,    96,   751,   769,   770,    54,   444,    94,
     107,    96,    36,    60,   959,    94,    20,    20,     7,    72,
      96,    74,    20,  1089,    71,    72,   107,    94,    75,  1121,
    1122,    78,    79,    93,   792,    88,   794,   140,   491,   492,
     493,    41,    42,    43,    44,    45,    46,   234,   107,    73,
     733,    18,   735,    96,    54,   150,   820,   110,    18,   144,
      20,   140,    49,   447,   111,   112,   113,   107,   144,   107,
     144,   124,   107,   118,   144,    61,   128,   130,   129,    79,
      96,   107,   110,   150,    94,   222,   107,   224,   528,   107,
     530,   531,   163,   533,   122,   535,   480,   481,   106,   483,
     484,   485,   486,   543,   544,   489,   187,   178,   100,   113,
     157,   111,   112,   113,     8,     9,    40,   125,   146,   179,
     504,   107,   150,   128,   107,   153,    50,   885,   187,   887,
     514,   515,   826,    94,   144,   232,   187,   153,   183,   214,
     127,   193,   293,   183,     8,     9,   184,  1046,   183,     8,
       9,   218,   219,   157,   157,  1034,   249,   250,  1250,   183,
     263,   187,  1228,   184,  1079,   183,   892,  1409,   621,   153,
     217,   107,   247,  1415,  1089,   747,   748,  1419,   263,     8,
       9,   875,   171,   150,   263,   183,   153,   263,   193,   263,
     873,   210,   576,   263,   241,   107,   107,  1197,    20,   653,
     183,   107,   656,  1327,   657,   995,   249,   250,   298,   103,
     735,   301,  1012,   266,   961,  1160,    94,   653,   261,   118,
     656,    94,   178,   183,   153,   253,   134,   121,   107,   123,
      31,   995,   279,   280,   281,   282,   192,   355,   107,   103,
     358,   241,   234,   113,   103,   298,   107,   183,   301,   197,
     242,   188,   189,   107,   215,   216,   150,   121,   206,   123,
     154,   944,   121,   255,   123,   257,   144,   385,   107,   230,
     150,   183,   183,   153,   103,   267,   170,   183,   270,   279,
     280,   281,   282,   182,   402,   403,   150,   405,   110,   197,
     154,   150,   121,   155,   123,   154,   240,   191,    52,   243,
     122,   354,   742,     4,   183,    59,   170,     8,    62,    63,
     172,   170,    36,  1228,   183,   209,    70,    41,   436,   145,
     438,   150,   183,   135,   146,   154,   206,   191,   150,   183,
      96,   153,   191,   386,   100,   117,   162,   455,   150,    96,
     724,   170,   215,   216,   183,   209,  1346,   731,   155,   817,
     209,   145,   470,    31,   407,    79,   113,   230,   476,   142,
     413,   143,   191,   831,   197,   172,   419,     4,   162,    64,
      65,     8,   242,   206,   156,   150,   829,   830,    94,   153,
     209,   834,   106,   918,   439,   957,   960,   150,   195,   172,
     443,   118,   445,   446,   165,  1185,   153,   969,   173,   165,
     453,   271,   272,   456,   274,   275,  1305,   190,   190,   222,
     214,   224,   166,   466,   168,   868,   567,   568,     8,   135,
     121,  1185,   123,   118,   140,     8,   259,   198,   182,    19,
     131,   242,   265,   238,   239,   488,    19,   490,   822,    96,
     273,   118,   166,   247,   828,   134,   564,   300,    96,   150,
     157,   569,   100,   306,   208,   260,   113,   178,   147,   577,
     271,   272,    95,   274,   275,   583,   584,   851,   234,    66,
      67,   192,   590,   106,   150,   118,   242,   153,   244,   245,
     246,   865,   866,   116,   121,   869,   123,   871,   254,   255,
    1184,   257,   125,  1372,   131,  1285,   262,   150,   100,    96,
    1226,   267,   268,   269,   270,  1231,   229,   891,   231,    66,
      67,   113,    69,   150,   218,   219,   220,   165,   902,   903,
     904,  1285,   906,   907,   908,   909,   910,   911,    62,   913,
     914,   121,   408,   123,   652,   153,   412,   921,   121,    96,
     123,   195,   132,   197,   153,   598,  1336,  1359,  1360,   132,
     570,   150,   206,   573,   153,   575,   940,   222,   942,   943,
     150,   118,   227,   616,   135,   683,   118,   150,   259,   140,
    1382,  1145,  1336,   150,   265,   259,  1388,    14,  1152,  1153,
     264,    53,   273,   150,    56,   135,   234,   212,  1041,  1315,
     140,   153,  1164,  1319,   242,   222,   244,   245,   246,  1289,
     984,    41,    42,    43,  1294,   240,    46,   255,   243,   257,
     280,   281,   282,   229,   262,   231,   118,   670,   150,   267,
     268,   269,   270,   126,   127,    66,    67,   118,   746,   126,
     127,   410,   411,   686,   130,   553,   554,  1363,   280,  1023,
     555,   556,   138,   139,   280,   141,   546,   547,   771,   772,
    1287,  1288,   148,     0,  1038,   164,   152,   280,   154,  1353,
     187,   187,    92,   159,  1117,   252,    76,  1051,   786,   101,
     723,   196,  1056,  1057,   102,  1059,   729,   151,   153,   175,
    1064,   150,   150,   150,   183,   183,    41,    41,    20,   149,
    1264,  1265,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,   118,   199,   200,   201,   202,   203,   204,   269,
     280,   150,   118,   269,   118,   150,   769,   770,   771,   772,
     153,   183,   153,    27,   153,    15,   153,   153,   183,  1113,
     210,    20,   183,   228,    40,   118,   107,    94,   228,   792,
    1124,   794,   166,    94,   167,   167,    94,   183,   150,   183,
     153,    20,  1205,  1137,   107,   180,  1140,   107,  1142,   180,
     180,  1335,   180,   180,   157,   157,   125,   820,   130,    20,
     283,   183,   180,    96,   183,    36,   183,    96,   130,   140,
     107,   180,   183,   183,   180,   183,  1170,    94,   234,   180,
     180,   140,   187,   180,   167,   251,   118,   118,   118,   144,
     118,  1254,   180,   222,   270,   253,   258,   181,   180,   100,
     180,   180,   150,   180,   130,   140,    94,   194,   272,   150,
     273,   130,   180,   140,   273,   130,    96,   157,   140,  1213,
     118,  1215,   885,   144,   887,   118,   247,  1221,   180,    27,
     150,    20,   118,   118,    79,   107,   144,   236,   150,   107,
     153,  1235,  1236,  1237,  1238,  1239,   153,  1241,   144,   183,
     144,    55,   248,   248,    94,   180,   140,   180,   273,   142,
     142,    20,    20,   926,   167,   183,   929,  1261,   107,   273,
     998,   140,   183,   183,   937,   118,   939,   183,   187,   144,
     118,    69,  1010,   130,  1278,     6,  1280,   230,   183,   234,
     187,   183,   230,   182,   230,   106,   106,   118,   144,    94,
     266,    20,   183,   180,   180,   183,   230,  1301,   182,  1303,
      20,  1039,  1375,   180,    96,   124,   153,   180,   180,    94,
     180,    20,    96,    67,   118,   182,   106,   193,   118,   193,
     182,    93,   995,   118,   193,   179,   150,   193,   502,   118,
    1019,   183,  1005,  1071,   502,   220,   620,   421,   821,   430,
     223,   256,   256,   223,  1354,   426,   803,  1085,  1186,   506,
    1354,   988,   929,   880,  1054,  1219,  1114,  1066,   226,  1126,
     921,  1124,   227,   466,   265,  1121,  1370,  1048,   526,   996,
     548,   527,  1079,   687,   286,  1048,  1388,  1382,   794,   772,
     820,  1054,  1107,  1018,   454,  1111,   747,   454,   957,  1164,
     290,  1395,  1065,   748,   969,   961,  1299,  1196,  1159,   958,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1086,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1107,    -1,    -1,  1110,    -1,    -1,
      -1,  1114,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1173,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1216,  1217,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1227,    -1,    -1,    -1,    -1,  1232,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1279,    -1,    -1,    -1,
      -1,    -1,  1285,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1316,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1327,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1336,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1366,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1378,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,    -1,  1411,    -1,
      -1,    -1,    -1,  1416,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    -1,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    -1,
      -1,   105,   106,    -1,    -1,    -1,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,    -1,   122,    -1,
     124,   125,   126,   127,    -1,   129,    -1,    -1,    -1,   133,
     134,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,   143,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,   153,
     154,   155,   156,   157,    -1,    -1,    -1,    -1,   162,   163,
     164,   165,   166,   167,   168,   169,   170,    -1,   172,   173,
      -1,    -1,   176,   177,   178,    -1,    -1,    -1,   182,    -1,
     184,   185,   186,    -1,   188,   189,   190,    -1,   192,    -1,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,    -1,    -1,   207,   208,   209,    -1,   211,   212,    -1,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,    -1,   252,   253,
      -1,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,
      -1,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,   122,    -1,   124,   125,   126,   127,    -1,
     129,    -1,    -1,    -1,   133,   134,   135,   136,   137,    -1,
      -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,   153,   154,   155,   156,   157,    -1,
      -1,    -1,    -1,   162,   163,   164,   165,   166,   167,   168,
     169,   170,    -1,   172,   173,    -1,    -1,   176,   177,   178,
      -1,    -1,    -1,   182,   183,   184,   185,   186,    -1,   188,
     189,   190,    -1,   192,    -1,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,    -1,    -1,   207,   208,
     209,    -1,   211,   212,    -1,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,    -1,   252,   253,    -1,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    98,    99,   100,   101,   102,    -1,    -1,
     105,   106,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    -1,   122,    -1,   124,
     125,   126,   127,    -1,   129,    -1,    -1,    -1,   133,   134,
     135,   136,   137,    -1,    -1,    -1,    -1,    -1,   143,   144,
     145,   146,   147,   148,   149,    -1,    -1,    -1,   153,   154,
     155,   156,   157,    -1,    -1,    -1,    -1,   162,   163,   164,
     165,   166,   167,   168,   169,   170,    -1,   172,   173,    -1,
      -1,   176,   177,   178,    -1,   180,    -1,   182,    -1,   184,
     185,   186,    -1,   188,   189,   190,    -1,   192,    -1,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
      -1,    -1,   207,   208,   209,    -1,   211,   212,    -1,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,    -1,   252,   253,    -1,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      -1,   122,    -1,   124,   125,   126,   127,    -1,   129,    -1,
      -1,    -1,   133,   134,   135,   136,   137,    -1,    -1,    -1,
      -1,    -1,   143,   144,   145,   146,   147,   148,   149,    -1,
      -1,    -1,   153,   154,   155,   156,   157,    -1,    -1,    -1,
      -1,   162,   163,   164,   165,   166,   167,   168,   169,   170,
      -1,   172,   173,    -1,    -1,   176,   177,   178,    -1,    -1,
      -1,   182,   183,   184,   185,   186,    -1,   188,   189,   190,
      -1,   192,    -1,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,    -1,    -1,   207,   208,   209,    -1,
     211,   212,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      -1,   252,   253,    -1,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    98,    99,   100,   101,   102,    -1,    -1,   105,   106,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,    -1,   122,    -1,   124,   125,   126,
     127,    -1,   129,    -1,    -1,    -1,   133,   134,   135,   136,
     137,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,   153,   154,   155,   156,
     157,    -1,    -1,    -1,    -1,   162,   163,   164,   165,   166,
     167,   168,   169,   170,    -1,   172,   173,    -1,    -1,   176,
     177,   178,    -1,   180,    -1,   182,    -1,   184,   185,   186,
      -1,   188,   189,   190,    -1,   192,    -1,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,    -1,    -1,
     207,   208,   209,    -1,   211,   212,    -1,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,   252,   253,    -1,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    -1,   122,
      -1,   124,   125,   126,   127,    -1,   129,    -1,    -1,    -1,
     133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,
     143,   144,   145,   146,   147,   148,   149,    -1,    -1,    -1,
     153,   154,   155,   156,   157,    -1,    -1,    -1,    -1,   162,
     163,   164,   165,   166,   167,   168,   169,   170,    -1,   172,
     173,    -1,    -1,   176,   177,   178,    -1,   180,    -1,   182,
      -1,   184,   185,   186,    -1,   188,   189,   190,    -1,   192,
      -1,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,    -1,    -1,   207,   208,   209,    -1,   211,   212,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,    -1,   252,
     253,    -1,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,
      -1,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,   122,    -1,   124,   125,   126,   127,    -1,
     129,    -1,    -1,    -1,   133,   134,   135,   136,   137,    -1,
      -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,   153,   154,   155,   156,   157,    -1,
      -1,    -1,    -1,   162,   163,   164,   165,   166,   167,   168,
     169,   170,    -1,   172,   173,    -1,    -1,   176,   177,   178,
      -1,   180,    -1,   182,    -1,   184,   185,   186,    -1,   188,
     189,   190,    -1,   192,    -1,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,    -1,    -1,   207,   208,
     209,    -1,   211,   212,    -1,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,    -1,   252,   253,    -1,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    98,    99,   100,   101,   102,    -1,    -1,
     105,   106,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    -1,   122,    -1,   124,
     125,   126,   127,    -1,   129,    -1,    -1,    -1,   133,   134,
     135,   136,   137,    -1,    -1,    -1,    -1,    -1,   143,   144,
     145,   146,   147,   148,   149,    -1,    -1,    -1,   153,   154,
     155,   156,   157,    -1,    -1,    -1,    -1,   162,   163,   164,
     165,   166,   167,   168,   169,   170,    -1,   172,   173,    -1,
      -1,   176,   177,   178,    -1,   180,    -1,   182,    -1,   184,
     185,   186,    -1,   188,   189,   190,    -1,   192,    -1,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
      -1,    -1,   207,   208,   209,    -1,   211,   212,    -1,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,    -1,   252,   253,    -1,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      -1,   122,    -1,   124,   125,   126,   127,    -1,   129,    -1,
      -1,    -1,   133,   134,   135,   136,   137,    -1,    -1,    -1,
      -1,    -1,   143,   144,   145,   146,   147,   148,   149,    -1,
      -1,    -1,   153,   154,   155,   156,   157,    -1,    -1,    -1,
      -1,   162,   163,   164,   165,   166,   167,   168,   169,   170,
      -1,   172,   173,    -1,    -1,   176,   177,   178,    -1,   180,
      -1,   182,    -1,   184,   185,   186,    -1,   188,   189,   190,
      -1,   192,    -1,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,    -1,    -1,   207,   208,   209,    -1,
     211,   212,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      -1,   252,   253,    -1,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    98,    99,   100,   101,   102,    -1,    -1,   105,   106,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,    -1,   122,    -1,   124,   125,   126,
     127,    -1,   129,    -1,    -1,    -1,   133,   134,   135,   136,
     137,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,   153,   154,   155,   156,
     157,    -1,    -1,    -1,    -1,   162,   163,   164,   165,   166,
     167,   168,   169,   170,    -1,   172,   173,    -1,    -1,   176,
     177,   178,    -1,   180,    -1,   182,    -1,   184,   185,   186,
      -1,   188,   189,   190,    -1,   192,    -1,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,    -1,    -1,
     207,   208,   209,    -1,   211,   212,    -1,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,   252,   253,    -1,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    -1,   122,
      -1,   124,   125,   126,   127,    -1,   129,    -1,    -1,    -1,
     133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,
     143,   144,   145,   146,   147,   148,   149,    -1,    -1,    -1,
     153,   154,   155,   156,   157,    -1,    -1,    -1,    -1,   162,
     163,   164,   165,   166,   167,   168,   169,   170,    -1,   172,
     173,    -1,    -1,   176,   177,   178,    -1,    -1,    -1,   182,
      -1,   184,   185,   186,    -1,   188,   189,   190,    -1,   192,
      -1,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,    -1,    -1,   207,   208,   209,    -1,   211,   212,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,    -1,   252,
     253,    -1,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,
      -1,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,   122,    -1,   124,   125,   126,   127,    -1,
     129,    -1,    -1,    -1,   133,   134,   135,   136,   137,    -1,
      -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,   153,   154,   155,   156,   157,    -1,
      -1,    -1,    -1,   162,   163,   164,   165,   166,   167,   168,
     169,   170,    -1,   172,   173,    -1,    -1,   176,   177,   178,
      -1,    -1,    -1,   182,    -1,   184,   185,   186,    -1,   188,
     189,   190,    -1,   192,    -1,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,    -1,    -1,   207,   208,
     209,    -1,   211,   212,    -1,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,    -1,   252,   253,    -1,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    98,    99,   100,   101,   102,    -1,    -1,
     105,   106,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    -1,   122,    -1,   124,
     125,   126,   127,    -1,   129,    -1,    -1,    -1,   133,   134,
     135,   136,   137,    -1,    -1,    -1,    -1,    -1,   143,   144,
     145,   146,   147,   148,   149,    -1,    -1,    -1,   153,   154,
     155,   156,   157,    -1,    -1,    -1,    -1,   162,   163,   164,
     165,   166,   167,   168,   169,   170,    -1,   172,   173,    -1,
      -1,   176,   177,   178,    -1,    -1,    -1,   182,    -1,   184,
     185,   186,    -1,   188,   189,   190,    -1,   192,    -1,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
      -1,    -1,   207,   208,   209,    -1,   211,   212,    -1,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,    -1,   252,   253,    -1,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      -1,   122,    -1,   124,   125,   126,   127,    -1,   129,    -1,
      -1,    -1,   133,   134,   135,   136,   137,    -1,    -1,    -1,
      -1,    -1,   143,   144,   145,   146,   147,   148,   149,    -1,
      -1,    -1,   153,   154,   155,   156,   157,    -1,    -1,    -1,
      -1,   162,   163,   164,   165,   166,   167,   168,   169,   170,
      -1,   172,   173,    -1,    -1,   176,   177,   178,    -1,    -1,
      -1,   182,    -1,   184,   185,   186,    -1,   188,   189,   190,
      -1,   192,    -1,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,    -1,    -1,   207,   208,   209,    -1,
     211,   212,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      -1,   252,   253,    -1,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    98,    99,   100,   101,   102,    -1,    -1,   105,   106,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,    -1,   122,    -1,   124,   125,   126,
     127,    -1,   129,    -1,    -1,    -1,   133,   134,   135,   136,
     137,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,   153,   154,   155,   156,
     157,    -1,    -1,    -1,    -1,   162,   163,   164,   165,   166,
     167,   168,   169,   170,    -1,   172,   173,    -1,    -1,   176,
     177,   178,    -1,    -1,    -1,   182,    -1,   184,   185,   186,
      -1,   188,   189,   190,    -1,   192,    -1,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,    -1,    -1,
     207,   208,   209,    -1,   211,   212,    -1,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,   252,   253,    -1,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    -1,   122,
      -1,   124,   125,   126,   127,    -1,   129,    -1,    -1,    -1,
     133,   134,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,
     143,   144,   145,   146,   147,   148,   149,    -1,    -1,    -1,
     153,   154,   155,   156,   157,    -1,    -1,    -1,    -1,   162,
     163,   164,   165,   166,   167,   168,   169,   170,    -1,   172,
     173,    -1,    -1,   176,   177,   178,    -1,    -1,    -1,   182,
      -1,   184,   185,   186,    -1,   188,   189,   190,    -1,   192,
      -1,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,    -1,    -1,   207,   208,   209,    -1,   211,   212,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,    -1,   252,
     253,    -1,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    98,
      99,   100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,
      -1,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,   122,    -1,   124,   125,   126,   127,    -1,
     129,    -1,    -1,    -1,   133,   134,   135,   136,   137,    -1,
      -1,    -1,    -1,    -1,   143,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,   153,   154,    -1,   156,   157,    -1,
      -1,    -1,    -1,   162,   163,   164,   165,   166,   167,   168,
     169,   170,    -1,    -1,    -1,    -1,    -1,   176,   177,   178,
      -1,    -1,    -1,   182,    -1,   184,   185,   186,    -1,    -1,
      -1,   190,    -1,   192,    -1,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,    -1,    -1,   207,   208,
     209,    -1,   211,   212,    -1,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,    -1,   252,   253,    -1,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,    -1,    92,    -1,    94,
      95,    96,    97,    -1,    -1,   100,   101,   102,    -1,    -1,
      -1,   106,    -1,    -1,    -1,    -1,   111,   112,   113,    -1,
      -1,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,   124,
     125,   126,   127,    -1,   129,    -1,    -1,    -1,   133,   134,
     135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,
     145,    -1,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,   162,   163,   164,
     165,   166,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   178,    -1,    -1,    -1,   182,    -1,   184,
     185,    -1,    -1,    -1,    -1,   190,    -1,   192,    -1,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
      -1,    -1,   207,   208,    -1,    -1,   211,   212,    -1,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,    -1,   252,   253,    -1,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    -1,
      -1,    92,    -1,    94,    95,    96,    97,    -1,    -1,   100,
     101,   102,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,
     111,   112,   113,    -1,    -1,   116,   117,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   125,   126,   127,    -1,   129,    -1,
      -1,    -1,   133,   134,   135,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   143,   144,   145,    -1,   147,   148,   149,    -1,
      -1,    -1,    -1,    -1,    -1,   156,   157,    -1,    -1,    -1,
      -1,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,    -1,    -1,
      -1,   182,    -1,   184,    -1,    -1,    -1,    -1,    -1,   190,
      -1,   192,    -1,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,    -1,    -1,   207,   208,    -1,    -1,
     211,   212,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      -1,   252,   253,    -1,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,    16,    -1,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    92,
      -1,    94,    95,    96,    97,    -1,    -1,   100,   101,   102,
      -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,   111,   112,
     113,    -1,    -1,   116,   117,    -1,    -1,    -1,    -1,    -1,
      -1,   124,   125,   126,   127,    -1,   129,    -1,    -1,    -1,
     133,   134,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     143,   144,   145,    -1,   147,   148,   149,    -1,    -1,    -1,
      -1,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,   162,
     163,   164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,   182,
      -1,   184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,
      -1,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,    -1,    -1,   207,   208,    -1,    -1,   211,   212,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,    -1,   252,
     253,    -1,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    -1,    -1,    92,    -1,    94,    95,    96,
      97,    -1,    -1,   100,   101,   102,    -1,    -1,    -1,   106,
      -1,    -1,    -1,    -1,   111,   112,   113,    -1,    -1,   116,
     117,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,
     127,    -1,   129,    -1,    -1,    -1,   133,   134,   135,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,    -1,
     147,   148,   149,   150,    -1,    -1,   153,    -1,    -1,   156,
     157,    -1,    -1,    -1,    -1,   162,   163,   164,   165,   166,
     167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   178,    -1,    -1,    -1,   182,    -1,   184,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   192,    -1,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,    -1,    -1,
     207,   208,    -1,    -1,   211,   212,    -1,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,   252,   253,    -1,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    -1,
      -1,    92,    -1,    94,    95,    96,    97,    -1,    -1,   100,
     101,   102,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,
     111,   112,   113,    -1,    -1,   116,   117,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   125,   126,   127,    -1,   129,    -1,
      -1,    -1,   133,   134,   135,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   143,   144,   145,    -1,   147,   148,   149,   150,
      -1,    -1,   153,    -1,    -1,   156,   157,    -1,    -1,    -1,
      -1,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,    -1,    -1,
      -1,   182,    -1,   184,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   192,    -1,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,    -1,    -1,   207,   208,    -1,    -1,
     211,   212,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      -1,   252,   253,    -1,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,    -1,    92,    -1,    94,
      95,    96,    97,    -1,    -1,   100,   101,   102,    -1,    -1,
      -1,   106,    -1,    -1,    -1,    -1,   111,   112,   113,    -1,
      -1,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,   124,
     125,   126,   127,    -1,   129,    -1,    -1,    -1,   133,   134,
     135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,
     145,    -1,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,   162,   163,   164,
     165,   166,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   178,    -1,    -1,    -1,   182,   183,   184,
      -1,    -1,    -1,    -1,    -1,   190,    -1,   192,    -1,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
      -1,    -1,   207,   208,    -1,    -1,   211,   212,    -1,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,    -1,   252,   253,    -1,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    -1,    -1,    92,    -1,    94,    95,    96,    97,    -1,
      -1,   100,   101,   102,    -1,    -1,    -1,   106,    -1,    -1,
      -1,    -1,   111,   112,   113,    -1,    -1,   116,   117,    -1,
      -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,    -1,
     129,    -1,    -1,    -1,   133,   134,   135,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   143,   144,   145,    -1,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,   156,   157,    -1,
      -1,    -1,    -1,   162,   163,   164,   165,   166,   167,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,
      -1,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,    -1,
      -1,   190,    -1,   192,    -1,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,    -1,    -1,   207,   208,
      -1,    -1,   211,   212,    -1,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,    -1,   252,   253,    -1,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    92,
      -1,    94,    95,    96,    97,    -1,    -1,   100,   101,   102,
      -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,   111,   112,
     113,    -1,    -1,   116,   117,   118,    -1,    -1,    -1,    -1,
      -1,   124,   125,   126,   127,    -1,   129,    -1,    -1,    -1,
     133,   134,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     143,   144,   145,    -1,   147,   148,   149,    -1,    -1,    -1,
      -1,    -1,    -1,   156,   157,    -1,    -1,    -1,    -1,   162,
     163,   164,   165,   166,   167,   168,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,   182,
      -1,   184,   185,    -1,    -1,    -1,    -1,    -1,    -1,   192,
      -1,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,    -1,    -1,   207,   208,    -1,    -1,   211,   212,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,    -1,   252,
     253,    -1,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    -1,    -1,    92,    -1,    94,    95,    96,
      97,    -1,    -1,   100,   101,   102,    -1,    -1,    -1,   106,
      -1,    -1,    -1,    -1,   111,   112,   113,    -1,    -1,   116,
     117,    -1,    -1,    -1,    -1,    -1,    -1,   124,   125,   126,
     127,    -1,   129,    -1,    -1,    -1,   133,   134,   135,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,    -1,
     147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,
     157,    -1,    -1,    -1,    -1,   162,   163,   164,   165,   166,
     167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   178,    -1,    -1,    -1,   182,    -1,   184,   185,    -1,
      -1,    -1,    -1,    -1,    -1,   192,    -1,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,    -1,    -1,
     207,   208,    -1,    -1,   211,   212,    -1,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,    -1,   252,   253,    -1,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    -1,
      -1,    92,    -1,    94,    95,    96,    97,    -1,    -1,   100,
     101,   102,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,
     111,   112,   113,    -1,    -1,   116,   117,    -1,    -1,    -1,
      -1,    -1,    -1,   124,   125,   126,   127,    -1,   129,    -1,
      -1,    -1,   133,   134,   135,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   143,   144,   145,    -1,   147,   148,   149,    -1,
      -1,    -1,    -1,    -1,    -1,   156,   157,    -1,    -1,    -1,
      -1,   162,   163,   164,   165,   166,   167,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,    -1,    -1,
      -1,   182,    -1,   184,   185,    -1,    -1,    -1,    -1,    -1,
      -1,   192,    -1,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,    -1,    -1,   207,   208,    -1,    -1,
     211,   212,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
      -1,   252,   253,    -1,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,    -1,    92,    -1,    94,
      95,    96,    97,    -1,    -1,   100,   101,   102,    -1,    -1,
      -1,   106,    -1,    -1,    -1,    -1,   111,   112,   113,    -1,
      -1,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,   124,
     125,   126,   127,    -1,   129,    -1,    -1,    -1,   133,   134,
     135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,
     145,    -1,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,
      -1,   156,   157,    -1,    -1,    -1,    -1,   162,   163,   164,
     165,   166,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   178,    -1,    -1,    -1,   182,    -1,   184,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,    -1,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
      -1,    -1,   207,   208,    -1,    -1,   211,   212,    -1,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,    -1,   252,   253,    -1,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    18,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    -1,    -1,    92,    -1,    94,    95,    96,    97,    -1,
      -1,   100,   101,   102,    -1,    -1,    -1,   106,    -1,    -1,
      -1,    -1,   111,   112,   113,    -1,    -1,   116,   117,    -1,
      -1,    -1,    -1,    -1,    -1,   124,   125,   126,   127,    -1,
     129,    -1,    -1,    -1,   133,   134,   135,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   143,   144,   145,    -1,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,   156,   157,    -1,
      -1,    -1,    -1,   162,   163,   164,   165,   166,   167,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,
      -1,    -1,    -1,   182,    -1,   184,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   192,    -1,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,    -1,    -1,   207,   208,
      -1,    -1,   211,   212,    -1,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,    -1,   252,   253,    -1,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,    10,    17,    18,    20,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   105,   106,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   122,   124,   125,   126,   127,   129,   133,   134,   135,
     136,   137,   143,   144,   145,   146,   147,   148,   149,   153,
     154,   155,   156,   157,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   172,   173,   176,   177,   178,   182,   184,
     185,   186,   188,   189,   190,   192,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   207,   208,   209,
     211,   212,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   252,
     253,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   330,   331,   336,   338,
     345,   347,   352,   353,   354,   355,   356,   357,   365,   366,
     368,   369,   370,   375,   377,   379,   380,   381,   386,   407,
     410,   413,   414,   415,   416,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   463,   464,   465,   479,   480,
     482,   483,   484,   485,   486,   487,   488,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   507,   508,   509,
     510,   511,   512,   513,   516,   523,   524,   525,   150,   348,
     234,    31,    31,   153,    94,   150,   218,   219,   153,    28,
      29,    30,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    47,    48,    50,    51,    53,    58,    59,    61,    62,
      63,    73,    74,    97,   133,   150,   153,   165,   198,   211,
     221,   222,   223,   225,   226,   233,   235,   237,   276,   277,
     278,   523,   150,   150,   153,   150,   153,    41,    42,    43,
      44,    45,    46,    54,    60,    71,    72,    75,    78,    79,
     111,   112,   113,   157,   217,   241,   279,   280,   281,   282,
     337,   339,   340,   341,   358,   359,   153,    18,   150,   153,
     522,    53,    56,   118,   157,   118,   118,   150,    64,    65,
     118,   372,    62,   153,   153,   150,   153,   523,    36,    38,
      39,    48,    97,   447,   523,   523,   118,   183,   366,   523,
     150,    14,    16,   523,   523,   439,   150,    21,   210,   212,
     222,   224,   153,   222,   224,   222,   222,   227,   118,   150,
     118,   280,   280,   280,   301,     0,   303,   304,    40,    50,
     306,   365,   187,   187,   107,   187,   367,    52,    59,    62,
      63,    70,   166,   168,   182,   208,   371,   376,   377,   378,
     395,   396,   400,   382,   383,   523,   164,    92,   130,   138,
     139,   141,   148,   152,   154,   159,   175,   199,   200,   201,
     202,   203,   204,   431,   432,   252,   155,   172,   195,   117,
     143,   156,   190,   197,   206,   134,   147,    76,   196,   101,
     102,   155,   172,   430,   150,   436,   439,   188,   189,   151,
     451,   452,   447,   451,   447,   451,   153,   349,   369,   369,
     505,   523,   366,   150,   150,   366,   366,   183,   190,   523,
     150,   366,   366,   183,   366,   183,   523,   359,    41,   360,
     358,   358,   359,   523,   178,   192,   165,   198,    20,   520,
     163,   178,   178,   192,   523,   149,   118,   335,    36,    41,
      79,   106,   166,   521,   522,   524,   218,   219,   220,   100,
     234,   242,   255,   257,   267,   270,   537,   538,   539,   540,
     541,   544,   549,   550,   340,   520,   341,   366,   366,    20,
     183,   522,   150,   157,   520,   113,   157,   329,   520,   408,
     409,   523,   521,   523,   387,   389,   523,   369,   269,   269,
     118,   390,   118,   523,    36,    73,   183,   503,   504,   366,
     183,   190,   523,   150,   408,   183,    27,   467,   468,   469,
     366,     7,   171,    15,   183,   366,   210,    20,   369,   369,
     183,   369,   369,   369,   369,   228,   514,   515,   523,   369,
     388,   394,   523,   520,   520,   520,   308,   309,    40,   310,
     369,   368,   166,   118,   167,   167,   369,   369,   107,    94,
      96,   144,   263,   384,   385,   490,   415,   416,   418,   418,
     418,   418,   417,   418,   418,   418,   150,   153,   253,   454,
     526,   528,   529,   530,   531,   532,   533,   534,   421,   421,
     420,   422,   422,   422,   422,   423,   423,   424,   424,   228,
      94,    94,    94,   180,   366,   439,   439,   366,   452,   183,
     369,   462,    40,   350,   366,   183,   150,   180,   366,   366,
     183,   180,   107,   183,   107,   183,   180,   366,   180,   180,
     180,   153,   346,   523,    20,   107,   107,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,   312,   313,   314,
      94,   135,   140,   332,   333,   334,   523,   135,   140,   157,
     157,   312,   520,   125,   130,   240,   243,   113,   242,   271,
     272,   274,   275,   240,   243,    20,   242,   271,   272,   274,
     275,   283,   183,   180,   183,   183,   180,   366,   521,    96,
      36,   521,   520,    96,   107,   184,   144,   490,   130,   140,
     107,   140,   385,   490,   180,   523,    68,   214,   247,   373,
     374,   183,   183,   183,   180,   107,   183,   107,   183,   180,
     366,   184,   523,   468,   469,   128,   193,   180,   180,   129,
     187,    94,   215,   216,   230,    94,   215,   216,   230,    94,
     234,   222,   107,   232,   140,   180,    61,   107,   187,   113,
     187,   167,   523,   369,   401,   402,   118,   397,   398,   118,
     149,   207,   491,   493,   494,   495,   523,   118,   369,   118,
     144,   385,   144,   144,   384,   385,   418,   366,   526,   532,
     270,   560,    96,   165,   244,   245,   246,   254,   262,   268,
     269,   527,   535,   536,   537,   551,   554,   555,   557,   251,
     253,   258,   556,   238,   239,   260,   552,   491,   491,   489,
     494,   489,   180,   181,   107,   183,   335,   351,   107,   187,
     180,   348,   366,   180,   180,   100,   411,   412,   150,   505,
     506,   523,   505,   506,   180,   118,   183,   361,   362,   135,
     150,   364,   346,   145,   162,   145,   162,   313,   130,   493,
     334,   369,   490,   140,   369,   520,   520,   126,   127,   520,
     272,   273,    96,   113,   153,   543,   273,   369,   194,   150,
     180,   130,   328,   520,   157,   130,    96,   328,   118,   369,
     369,   144,   520,   369,   118,   369,   140,   140,   385,   144,
     490,   247,    66,    67,    69,   118,   384,   391,   392,   393,
     374,   150,   505,   505,   180,   369,    27,   469,   128,   193,
       8,     9,   103,   121,   123,   150,   191,   363,   464,   466,
     477,   478,   481,    20,   229,   231,   369,   369,   369,   229,
     231,   369,   369,   369,   369,   369,   369,   118,   369,   369,
     236,   517,   518,   150,   118,   401,    95,   106,   116,   125,
     403,   404,   405,   406,   107,   523,   107,   383,   153,   153,
     142,   172,   190,   492,   523,   523,   369,   144,   369,   369,
     144,   385,   144,   180,   183,   248,   214,   247,   259,   264,
     559,    96,   249,   250,   553,   248,   529,   559,   419,   422,
     268,   535,   537,   530,   144,   553,   273,    55,   142,   369,
     140,   351,   180,   118,   491,   113,   412,   180,   366,   183,
     183,   142,   183,   183,   523,    94,   107,   183,   366,   348,
     507,   333,   369,   273,    96,   153,   546,    20,   113,   543,
     167,   369,   180,   366,   520,   107,   328,   409,   369,   187,
     389,   369,   369,   140,   369,   144,   118,   118,   369,   523,
     393,    69,   180,   366,   183,   183,   130,   191,   466,     6,
     366,   523,   191,   477,   187,   230,   230,   230,   230,   234,
     515,   182,   448,   519,   518,   369,   394,   520,   126,   127,
     405,   406,   406,   402,   106,   399,   398,   183,   183,   369,
     369,   144,   369,   422,    49,   127,   422,   422,   259,   265,
     273,   558,   558,   419,   531,   266,   369,   523,   182,   118,
     182,   180,   490,   491,   362,    94,   180,   134,   197,   545,
     548,    20,    20,   547,   545,   261,   553,   107,   183,   107,
     183,   153,   344,   124,   180,    96,   520,   369,   369,   523,
     523,   392,   369,   180,   469,   523,   191,   180,   469,   523,
     369,   369,   369,   369,   369,   369,   153,   206,   364,   180,
     406,   520,   369,   422,   422,   195,    94,   369,   523,   369,
     491,   546,   546,   548,    20,   183,    20,   256,   542,   543,
     542,   342,   343,   369,   107,   183,   369,   328,    67,    93,
     179,   470,   469,   523,   193,   469,   118,   448,   422,   491,
     182,   553,   107,   183,   183,   106,   490,   342,   118,     4,
     131,   473,   474,   476,   478,    19,   132,   471,   472,   475,
     478,   193,   469,   193,   523,   182,   369,   256,   543,   520,
     523,    93,   131,   476,   179,   132,   475,   193,   107,   183,
     369,   118,   364,   523,   107,   183,   118,   364,   523,   183,
     364
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
     545,   546,   547,   548,   549,   550,   551,   552,   553
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   299,   300,   300,   301,   301,   301,   301,   302,   302,
     303,   303,   304,   305,   306,   306,   306,   307,   307,   308,
     308,   309,   309,   309,   309,   310,   310,   310,   310,   310,
     310,   310,   311,   311,   312,   312,   313,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   315,   315,   315,
     315,   315,   315,   315,   315,   316,   316,   317,   318,   318,
     319,   319,   320,   321,   322,   322,   323,   323,   324,   324,
     324,   324,   325,   326,   327,   327,   327,   327,   328,   328,
     329,   329,   330,   330,   330,   330,   331,   332,   332,   333,
     333,   333,   334,   335,   335,   336,   336,   336,   337,   337,
     338,   339,   339,   340,   340,   341,   342,   342,   343,   343,
     344,   344,   345,   345,   346,   346,   346,   346,   347,   348,
     349,   349,   350,   350,   351,   351,   352,   353,   354,   355,
     355,   356,   356,   356,   357,   357,   357,   358,   358,   358,
     358,   359,   359,   360,   361,   361,   362,   362,   363,   364,
     365,   366,   366,   367,   367,   368,   368,   369,   369,   369,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   369,
     369,   369,   369,   369,   369,   370,   371,   372,   372,   373,
     373,   373,   374,   374,   375,   375,   376,   377,   377,   377,
     378,   378,   378,   378,   378,   379,   379,   380,   380,   381,
     382,   382,   383,   383,   383,   383,   383,   383,   383,   383,
     384,   385,   386,   387,   387,   388,   388,   389,   389,   389,
     389,   390,   390,   391,   391,   391,   392,   392,   392,   393,
     393,   393,   394,   395,   396,   397,   397,   398,   398,   399,
     400,   400,   401,   401,   402,   402,   403,   403,   403,   403,
     403,   403,   403,   404,   404,   405,   405,   406,   407,   407,
     408,   408,   409,   409,   410,   410,   411,   411,   412,   412,
     413,   414,   414,   415,   415,   416,   416,   416,   416,   416,
     417,   416,   416,   416,   416,   418,   418,   418,   419,   419,
     420,   420,   420,   421,   421,   421,   421,   421,   422,   422,
     422,   423,   423,   423,   424,   424,   425,   425,   426,   426,
     427,   427,   428,   428,   429,   429,   429,   429,   430,   430,
     430,   431,   431,   431,   431,   431,   431,   432,   432,   432,
     433,   433,   433,   433,   434,   434,   435,   435,   436,   436,
     437,   437,   437,   437,   438,   439,   439,   439,   440,   440,
     441,   441,   441,   441,   442,   442,   443,   443,   443,   443,
     443,   443,   443,   444,   444,   445,   445,   446,   446,   446,
     446,   446,   447,   447,   448,   448,   449,   449,   449,   450,
     450,   451,   451,   452,   453,   453,   453,   453,   453,   453,
     453,   453,   454,   454,   455,   455,   455,   456,   457,   457,
     458,   459,   460,   461,   461,   462,   462,   463,   463,   464,
     464,   464,   465,   465,   465,   465,   465,   465,   466,   466,
     467,   467,   468,   469,   469,   470,   470,   471,   471,   472,
     472,   472,   472,   473,   473,   474,   474,   474,   474,   475,
     475,   476,   476,   477,   477,   477,   477,   478,   478,   478,
     478,   479,   479,   480,   480,   481,   482,   482,   482,   482,
     482,   482,   483,   484,   484,   484,   484,   485,   485,   485,
     485,   486,   487,   488,   488,   488,   488,   489,   489,   490,
     491,   491,   491,   492,   492,   492,   493,   493,   493,   494,
     495,   495,   495,   495,   495,   495,   495,   495,   495,   496,
     497,   497,   497,   498,   499,   500,   500,   500,   501,   501,
     501,   501,   501,   502,   503,   503,   503,   503,   503,   503,
     503,   504,   505,   506,   507,   508,   508,   508,   509,   509,
     509,   509,   509,   509,   509,   509,   509,   509,   510,   510,
     511,   511,   512,   513,   514,   514,   515,   516,   517,   517,
     518,   518,   518,   518,   519,   519,   520,   521,   521,   522,
     523,   523,   524,   524,   524,   524,   524,   524,   524,   524,
     524,   524,   524,   524,   524,   524,   524,   524,   524,   524,
     524,   524,   524,   524,   524,   524,   524,   524,   524,   524,
     524,   524,   524,   524,   524,   524,   524,   524,   524,   524,
     524,   524,   524,   524,   524,   524,   524,   524,   524,   524,
     524,   524,   524,   524,   524,   524,   524,   524,   524,   524,
     524,   524,   524,   524,   524,   524,   524,   524,   524,   524,
     524,   524,   524,   524,   524,   524,   524,   524,   524,   524,
     524,   524,   524,   524,   524,   524,   524,   524,   524,   524,
     524,   524,   524,   524,   524,   524,   524,   524,   524,   524,
     524,   524,   524,   524,   524,   524,   524,   524,   524,   524,
     524,   524,   524,   524,   524,   524,   524,   524,   524,   524,
     524,   524,   524,   524,   524,   524,   524,   524,   524,   524,
     524,   524,   524,   524,   524,   524,   524,   524,   524,   524,
     524,   524,   524,   524,   524,   524,   524,   524,   524,   524,
     524,   524,   524,   524,   524,   524,   524,   524,   524,   524,
     524,   524,   524,   524,   524,   524,   524,   524,   524,   524,
     524,   524,   524,   524,   524,   524,   524,   524,   524,   524,
     524,   524,   524,   524,   524,   524,   524,   525,   525,   526,
     526,   526,   526,   527,   527,   527,   527,   528,   528,   529,
     529,   530,   530,   531,   531,   532,   532,   532,   533,   533,
     534,   534,   535,   535,   535,   535,   535,   536,   537,   537,
     537,   537,   537,   537,   537,   538,   538,   538,   538,   539,
     539,   539,   539,   540,   540,   541,   541,   541,   541,   541,
     541,   541,   542,   542,   543,   543,   543,   543,   544,   544,
     544,   544,   544,   545,   545,   546,   546,   547,   547,   548,
     548,   549,   550,   550,   551,   551,   551,   552,   552,   552,
     552,   552,   553,   553,   553,   553,   554,   555,   556,   557,
     557,   558,   558,   558,   559,   559,   560
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  xquery_parser::yyr2_[] =
  {
         0,     2,     1,     2,     1,     2,     1,     2,     4,     6,
       2,     1,     2,     6,     2,     2,     4,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     1,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     3,     3,
       5,     5,     4,     3,     3,     3,     5,     5,     5,     5,
       5,     5,     4,     3,     3,     4,     5,     6,     1,     3,
       3,     3,     3,     6,     5,     8,     4,     3,     1,     1,
       1,     2,     2,     2,     3,     5,     4,     6,     1,     1,
       2,     1,     2,     1,     2,     7,     1,     3,     1,     2,
       2,     3,     3,     3,     2,     3,     4,     5,     2,     4,
       3,     0,     3,     2,     1,     3,     5,     3,     5,     2,
       2,     3,     3,     3,     2,     3,     3,     1,     2,     2,
       2,     4,     4,     4,     1,     3,     2,     3,     3,     3,
       1,     1,     2,     1,     3,     1,     3,     1,     1,     1,
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
  "\"'pi target'\"", "\"'pragma literal'\"", "\"'QName #)'\"",
  "\"'*:QName'\"", "\"'QName_sval'\"", "\"'quote attribute content'\"",
  "\"'STRING'\"", "\"'XML comment'\"", "\"'QName'\"", "\"'URI'\"",
  "\"'NCName'\"", "\"'NCName(non keyword)'\"", "\"'KEYWORD'\"",
  "\"<blank>\"", "\"'block'\"", "\"'exit'\"", "\"'break'\"", "\"'loop'\"",
  "\"'continue'\"", "\"'while'\"", "\"'validate'\"", "\"'typeswitch'\"",
  "\"'element'\"", "\"'document'\"", "\"'text'\"", "\"'comment'\"",
  "\"'declare'\"", "\"'function'\"", "\"'updating'\"", "\"'sequential'\"",
  "\"'deterministic'\"", "\"'nondeterministic'\"", "\"'simple'\"",
  "\"'if'\"", "\"'processing-instruction'\"", "\"'most'\"", "\"'import'\"",
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
  "URI_LITERAL", "NCNAME", "NCNAME_NOKW", "QNAME", "KEYWORD", "EvalExpr",
  "FTSelection", "FTMatchOptionProximityList", "FTOr", "FTAnd",
  "FTMildnot", "FTUnaryNot", "FTWordsSelection", "FTWords", "FTWordsValue",
  "FTProximity", "FTOrderedIndicator", "FTMatchOption", "FTCaseOption",
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
       300,     0,    -1,   301,    -1,   284,   301,    -1,   303,    -1,
     302,   303,    -1,   304,    -1,   302,   304,    -1,   211,   212,
      20,   187,    -1,   211,   212,    20,   129,    20,   187,    -1,
     306,   365,    -1,   365,    -1,   305,   306,    -1,    53,   157,
     521,   130,   520,   187,    -1,   307,   187,    -1,   308,   187,
      -1,   307,   187,   308,   187,    -1,   309,    -1,   307,   187,
     309,    -1,   310,    -1,   308,   187,   310,    -1,   315,    -1,
     316,    -1,   317,    -1,   319,    -1,   336,    -1,   331,    -1,
     357,    -1,   320,    -1,   321,    -1,   338,    -1,   311,    -1,
      40,   113,    79,   312,    -1,    40,    79,   523,   312,    -1,
     313,    -1,   312,   313,    -1,   314,   130,   507,    -1,    80,
      -1,    81,    -1,    82,    -1,    83,    -1,    84,    -1,    85,
      -1,    86,    -1,    87,    -1,    88,    -1,    89,    -1,   318,
      -1,   325,    -1,   326,    -1,   345,    -1,   322,    -1,   323,
      -1,   324,    -1,   508,    -1,   327,    -1,   330,    -1,    40,
     157,   521,   130,   520,    -1,    40,    78,   178,    -1,    40,
      78,   192,    -1,    40,   113,    36,   157,   520,    -1,    40,
     113,    41,   157,   520,    -1,    40,    54,   523,    20,    -1,
      40,   241,   537,    -1,    40,    71,   165,    -1,    40,    71,
     198,    -1,    40,   113,   166,   125,   126,    -1,    40,   113,
     166,   125,   127,    -1,    40,    75,   178,   107,   145,    -1,
      40,    75,   178,   107,   162,    -1,    40,    75,   163,   107,
     145,    -1,    40,    75,   163,   107,   162,    -1,    40,   113,
     106,   520,    -1,    40,    72,   520,    -1,    50,    56,   520,
      -1,    50,    56,   329,   520,    -1,    50,    56,   520,    96,
     328,    -1,    50,    56,   329,   520,    96,   328,    -1,   520,
      -1,   328,   107,   520,    -1,   157,   521,   130,    -1,   113,
      36,   157,    -1,    50,    53,   520,    -1,    50,    53,   157,
     521,   130,   520,    -1,    50,    53,   520,    96,   328,    -1,
      50,    53,   157,   521,   130,   520,    96,   328,    -1,    40,
     111,   149,   332,    -1,    94,   493,   333,    -1,   333,    -1,
     334,    -1,   135,    -1,   135,   334,    -1,   140,   369,    -1,
     118,   523,    -1,   118,   523,   490,    -1,    40,   112,   335,
     140,   369,    -1,    40,   112,   335,   135,    -1,    40,   112,
     335,   135,   140,   369,    -1,   281,    -1,   282,    -1,    40,
     339,    -1,   340,    -1,   279,   340,    -1,   341,    -1,   337,
     341,    -1,   280,   520,   283,   369,   167,   344,   183,    -1,
     343,    -1,   343,   106,   520,    -1,   369,    -1,   369,   490,
      -1,   153,   342,    -1,   344,   107,   342,    -1,    40,    60,
     178,    -1,    40,    60,   192,    -1,   153,   183,    -1,   153,
     361,   183,    -1,   153,   183,    94,   491,    -1,   153,   361,
     183,    94,   491,    -1,    28,   348,    -1,   150,   349,   366,
     180,    -1,   349,   350,   187,    -1,    -1,   350,   107,   351,
      -1,    40,   351,    -1,   335,    -1,   335,   140,   369,    -1,
      58,   118,   523,   140,   369,    -1,    29,   234,   369,    -1,
      33,   153,   369,   183,   348,    -1,    30,    31,    -1,    32,
      31,    -1,   276,   280,   520,    -1,   278,   280,   520,    -1,
     277,   280,   520,    -1,    40,   358,    -1,    40,    45,   358,
      -1,    40,    44,   358,    -1,   359,    -1,    46,   359,    -1,
      42,   359,    -1,    43,   360,    -1,    41,   523,   346,   364,
      -1,    41,   523,   346,   135,    -1,    41,   523,   346,   348,
      -1,   362,    -1,   361,   107,   362,    -1,   118,   523,    -1,
     118,   523,   490,    -1,   150,   366,   180,    -1,   150,   366,
     180,    -1,   366,    -1,   368,    -1,   368,   367,    -1,   187,
      -1,   367,   368,   187,    -1,   369,    -1,   368,   107,   369,
      -1,   370,    -1,   407,    -1,   410,    -1,   413,    -1,   414,
      -1,   509,    -1,   510,    -1,   512,    -1,   511,    -1,   513,
      -1,   516,    -1,   525,    -1,   353,    -1,   354,    -1,   355,
      -1,   352,    -1,   347,    -1,   356,    -1,   379,   371,    -1,
     182,   369,    -1,    64,   269,    -1,    65,   269,    -1,   214,
      -1,   247,    -1,    68,   247,    -1,   373,   391,    69,   369,
      -1,   373,    69,   369,    -1,    62,   372,   390,   374,   374,
      -1,    62,   372,   390,   374,    -1,    70,   118,   523,    -1,
     381,    -1,   386,    -1,   375,    -1,   377,    -1,   395,    -1,
     400,    -1,   396,    -1,   376,    -1,   377,    -1,   379,   378,
      -1,    62,   118,    -1,    63,    62,   118,    -1,   380,   382,
      -1,   383,    -1,   382,   107,   118,   383,    -1,   523,   144,
     369,    -1,   523,   490,   144,   369,    -1,   523,   384,   144,
     369,    -1,   523,   490,   384,   144,   369,    -1,   523,   385,
     144,   369,    -1,   523,   490,   385,   144,   369,    -1,   523,
     384,   385,   144,   369,    -1,   523,   490,   384,   385,   144,
     369,    -1,    96,   118,   523,    -1,   263,   118,   523,    -1,
      59,   118,   387,    -1,   389,    -1,   387,   107,   118,   389,
      -1,   394,    -1,   388,   107,   118,   394,    -1,   523,   140,
     369,    -1,   523,   490,   140,   369,    -1,   523,   385,   140,
     369,    -1,   523,   490,   385,   140,   369,    -1,   118,   523,
     144,   369,    -1,   118,   523,   490,   144,   369,    -1,   392,
      -1,   118,   523,    -1,   118,   523,   392,    -1,   384,    -1,
     384,   393,    -1,   393,    -1,    66,   118,   523,    67,   118,
     523,    -1,    67,   118,   523,    -1,    66,   118,   523,    -1,
     523,    -1,   208,   369,    -1,   168,   167,   397,    -1,   398,
      -1,   397,   107,   398,    -1,   118,   523,    -1,   118,   523,
     399,    -1,   106,   520,    -1,   166,   167,   401,    -1,    52,
     166,   167,   401,    -1,   402,    -1,   401,   107,   402,    -1,
     369,    -1,   369,   403,    -1,   404,    -1,   405,    -1,   406,
      -1,   404,   405,    -1,   404,   406,    -1,   405,   406,    -1,
     404,   405,   406,    -1,    95,    -1,   116,    -1,   125,   126,
      -1,   125,   127,    -1,   106,   520,    -1,    51,   118,   408,
     184,   369,    -1,   133,   118,   408,   184,   369,    -1,   409,
      -1,   408,   107,   118,   409,    -1,   523,   144,   369,    -1,
     523,   490,   144,   369,    -1,    35,   153,   366,   183,   411,
     113,   182,   369,    -1,    35,   153,   366,   183,   411,   113,
     118,   523,   182,   369,    -1,   412,    -1,   411,   412,    -1,
     100,   491,   182,   369,    -1,   100,   118,   523,    94,   491,
     182,   369,    -1,    47,   153,   366,   183,   194,   369,   124,
     369,    -1,   415,    -1,   414,   164,   415,    -1,   416,    -1,
     415,    92,   416,    -1,   418,    -1,   418,   431,   418,    -1,
     418,   432,   418,    -1,   418,   130,   418,    -1,   418,   159,
     418,    -1,    -1,   418,   154,   417,   418,    -1,   418,   152,
     418,    -1,   418,   141,   418,    -1,   418,   139,   418,    -1,
     419,    -1,   419,   252,   526,    -1,   419,   252,   526,   560,
      -1,   420,    -1,   420,   195,   420,    -1,   421,    -1,   420,
     172,   421,    -1,   420,   155,   421,    -1,   422,    -1,   421,
     190,   422,    -1,   421,   117,   422,    -1,   421,   143,   422,
      -1,   421,   156,   422,    -1,   423,    -1,   422,   197,   423,
      -1,   422,   206,   423,    -1,   424,    -1,   423,   147,   424,
      -1,   423,   134,   424,    -1,   425,    -1,   425,    76,   228,
     491,    -1,   426,    -1,   426,   196,    94,   491,    -1,   427,
      -1,   427,   101,    94,   489,    -1,   428,    -1,   428,   102,
      94,   489,    -1,   430,    -1,   429,   430,    -1,   172,    -1,
     155,    -1,   429,   172,    -1,   429,   155,    -1,   433,    -1,
     437,    -1,   434,    -1,   199,    -1,   204,    -1,   203,    -1,
     202,    -1,   201,    -1,   200,    -1,   148,    -1,   175,    -1,
     138,    -1,    34,   150,   366,   180,    -1,    34,   219,   150,
     366,   180,    -1,    34,   218,   150,   366,   180,    -1,    34,
      94,   505,   150,   366,   180,    -1,   435,   150,   180,    -1,
     435,   150,   366,   180,    -1,   436,    -1,   435,   436,    -1,
     173,   523,    15,    -1,   173,    16,    -1,   438,    -1,   438,
     439,    -1,   189,   439,    -1,   439,    -1,   188,    -1,   440,
      -1,   440,   188,   439,    -1,   440,   189,   439,    -1,   441,
      -1,   450,    -1,   442,    -1,   442,   451,    -1,   445,    -1,
     445,   451,    -1,   443,   447,    -1,   444,    -1,   105,    -1,
     114,    -1,    98,    -1,   186,    -1,   115,    -1,   137,    -1,
     136,    -1,   447,    -1,    99,   447,    -1,   446,   447,    -1,
     120,    -1,   169,    -1,    90,    -1,   177,    -1,   176,    -1,
      91,    -1,   495,    -1,   448,    -1,   523,    -1,   449,    -1,
     190,    -1,    10,    -1,    17,    -1,   453,    -1,   453,   451,
      -1,   452,    -1,   451,   452,    -1,   151,   366,   181,    -1,
     454,    -1,   456,    -1,   457,    -1,   458,    -1,   461,    -1,
     463,    -1,   459,    -1,   460,    -1,   455,    -1,   507,    -1,
     110,    -1,   146,    -1,   122,    -1,   118,   523,    -1,   153,
     183,    -1,   153,   366,   183,    -1,   119,    -1,   165,   150,
     366,   180,    -1,   198,   150,   366,   180,    -1,   523,   153,
     183,    -1,   523,   153,   462,   183,    -1,   369,    -1,   462,
     107,   369,    -1,   464,    -1,   482,    -1,   465,    -1,   479,
      -1,   480,    -1,   154,   523,   469,   128,    -1,   154,   523,
     467,   469,   128,    -1,   154,   523,   469,   193,   191,   523,
     469,   193,    -1,   154,   523,   469,   193,   466,   191,   523,
     469,   193,    -1,   154,   523,   467,   469,   193,   191,   523,
     469,   193,    -1,   154,   523,   467,   469,   193,   466,   191,
     523,   469,   193,    -1,   477,    -1,   466,   477,    -1,   468,
      -1,   467,   468,    -1,    27,   523,   469,   130,   469,   470,
      -1,    -1,    27,    -1,   179,   471,   179,    -1,    93,   473,
      93,    -1,    -1,   472,    -1,   132,    -1,   475,    -1,   472,
     132,    -1,   472,   475,    -1,    -1,   474,    -1,   131,    -1,
     476,    -1,   474,   131,    -1,   474,   476,    -1,    19,    -1,
     478,    -1,     4,    -1,   478,    -1,   464,    -1,     9,    -1,
     481,    -1,   478,    -1,     8,    -1,   121,    -1,   123,    -1,
     363,    -1,   209,    21,   210,    -1,   209,   210,    -1,   170,
      14,   171,    -1,   170,    14,     7,    -1,   103,     6,    -1,
     483,    -1,   484,    -1,   485,    -1,   486,    -1,   487,    -1,
     488,    -1,    37,   150,   366,   180,    -1,    36,   523,   150,
     180,    -1,    36,   523,   150,   366,   180,    -1,    36,   150,
     366,   180,   150,   180,    -1,    36,   150,   366,   180,   150,
     366,   180,    -1,    97,   523,   150,   180,    -1,    97,   523,
     150,   366,   180,    -1,    97,   150,   366,   180,   150,   180,
      -1,    97,   150,   366,   180,   150,   366,   180,    -1,    38,
     150,   366,   180,    -1,    39,   150,   366,   180,    -1,    48,
     522,   150,   180,    -1,    48,   522,   150,   366,   180,    -1,
      48,   150,   366,   180,   150,   180,    -1,    48,   150,   366,
     180,   150,   366,   180,    -1,   494,    -1,   494,   142,    -1,
      94,   491,    -1,   493,    -1,   493,   492,    -1,   207,   153,
     183,    -1,   142,    -1,   190,    -1,   172,    -1,   494,    -1,
     495,    -1,   149,   153,   183,    -1,   523,    -1,   497,    -1,
     503,    -1,   501,    -1,   504,    -1,   502,    -1,   500,    -1,
     499,    -1,   498,    -1,   496,    -1,   222,   153,   183,    -1,
      74,   153,   183,    -1,    74,   153,   503,   183,    -1,    74,
     153,   504,   183,    -1,    38,   153,   183,    -1,    39,   153,
     183,    -1,    48,   153,   183,    -1,    48,   153,   522,   183,
      -1,    48,   153,    20,   183,    -1,    97,   153,   183,    -1,
      97,   153,   523,   183,    -1,    97,   153,   523,   107,   505,
     183,    -1,    97,   153,   190,   183,    -1,    97,   153,   190,
     107,   505,   183,    -1,   185,   523,   183,    -1,    36,   153,
     183,    -1,    36,   153,   523,   183,    -1,    36,   153,   523,
     107,   505,   183,    -1,    36,   153,   523,   107,   506,   183,
      -1,    36,   153,   190,   183,    -1,    36,   153,   190,   107,
     505,   183,    -1,    36,   153,   190,   107,   506,   183,    -1,
      73,   153,   523,   183,    -1,   523,    -1,   523,   142,    -1,
      20,    -1,    40,   217,   218,    -1,    40,   217,   219,    -1,
      40,   217,   220,    -1,   223,   222,   369,   230,   369,    -1,
     223,   222,   369,    94,   229,   230,   369,    -1,   223,   222,
     369,    94,   231,   230,   369,    -1,   223,   222,   369,   215,
     369,    -1,   223,   222,   369,   216,   369,    -1,   223,   224,
     369,   230,   369,    -1,   223,   224,   369,    94,   229,   230,
     369,    -1,   223,   224,   369,    94,   231,   230,   369,    -1,
     223,   224,   369,   215,   369,    -1,   223,   224,   369,   216,
     369,    -1,   221,   222,   369,    -1,   221,   224,   369,    -1,
     226,   222,   369,   234,   369,    -1,   226,   227,   228,   222,
     369,   234,   369,    -1,   225,   222,   369,    94,   369,    -1,
     233,   118,   514,   232,   369,   182,   369,    -1,   515,    -1,
     514,   107,   118,   515,    -1,   523,   140,   369,    -1,   235,
     150,   369,   180,   517,    -1,   518,    -1,   517,   518,    -1,
     236,   519,   364,    -1,   236,   519,   153,   118,   523,   183,
     364,    -1,   236,   519,   153,   118,   523,   107,   118,   523,
     183,   364,    -1,   236,   519,   153,   118,   523,   107,   118,
     523,   107,   118,   523,   183,   364,    -1,   448,    -1,   519,
     206,   448,    -1,    20,    -1,   522,    -1,   524,    -1,    18,
      -1,    18,    -1,   524,    -1,   211,    -1,   125,    -1,    97,
      -1,    39,    -1,    74,    -1,    36,    -1,   149,    -1,    47,
      -1,   222,    -1,    48,    -1,    77,    -1,    73,    -1,    38,
      -1,    35,    -1,   207,    -1,    78,    -1,   241,    -1,    72,
      -1,   219,    -1,   218,    -1,   143,    -1,    37,    -1,   253,
      -1,   240,    -1,   243,    -1,   242,    -1,   270,    -1,   271,
      -1,   274,    -1,   272,    -1,   275,    -1,   246,    -1,   248,
      -1,    55,    -1,   214,    -1,   247,    -1,    49,    -1,   220,
      -1,   233,    -1,   227,    -1,   199,    -1,   204,    -1,   203,
      -1,   202,    -1,   201,    -1,   200,    -1,    96,    -1,   111,
      -1,   112,    -1,   182,    -1,    62,    -1,    63,    -1,    64,
      -1,    65,    -1,    66,    -1,    67,    -1,    68,    -1,    69,
      -1,    70,    -1,   144,    -1,    59,    -1,   208,    -1,   167,
      -1,   168,    -1,   166,    -1,    52,    -1,    95,    -1,   116,
      -1,   126,    -1,   127,    -1,   106,    -1,    51,    -1,   133,
      -1,   184,    -1,   100,    -1,    94,    -1,   194,    -1,   124,
      -1,   164,    -1,    92,    -1,    76,    -1,   228,    -1,   101,
      -1,   195,    -1,   117,    -1,   156,    -1,   197,    -1,   147,
      -1,   134,    -1,    34,    -1,   102,    -1,   196,    -1,   148,
      -1,   178,    -1,   192,    -1,   157,    -1,   135,    -1,   129,
      -1,   163,    -1,   145,    -1,   162,    -1,    40,    -1,    60,
      -1,    71,    -1,   113,    -1,    75,    -1,    54,    -1,   212,
      -1,    50,    -1,    56,    -1,    53,    -1,    41,    -1,   263,
      -1,   252,    -1,   268,    -1,   269,    -1,   245,    -1,   258,
      -1,   266,    -1,   262,    -1,   244,    -1,   257,    -1,   267,
      -1,   261,    -1,   256,    -1,   255,    -1,   239,    -1,   238,
      -1,   260,    -1,   249,    -1,   250,    -1,   273,    -1,   265,
      -1,   264,    -1,   259,    -1,   226,    -1,   232,    -1,   229,
      -1,   223,    -1,   216,    -1,   215,    -1,   217,    -1,   234,
      -1,   224,    -1,   225,    -1,   231,    -1,   221,    -1,   230,
      -1,    46,    -1,    43,    -1,    42,    -1,    44,    -1,    45,
      -1,   165,    -1,   198,    -1,    28,    -1,    29,    -1,    31,
      -1,    33,    -1,    30,    -1,    32,    -1,   235,    -1,   236,
      -1,    61,    -1,   237,    -1,    58,    -1,   280,    -1,   276,
      -1,   277,    -1,   279,    -1,   283,    -1,   281,    -1,   282,
      -1,   278,    -1,    79,    -1,    80,    -1,    81,    -1,    82,
      -1,    83,    -1,    84,    -1,    85,    -1,    86,    -1,    87,
      -1,    88,    -1,    89,    -1,   237,   118,   388,    61,   150,
     369,   180,    -1,    61,   150,   369,   180,    -1,   528,    -1,
     528,   527,    -1,   528,   268,   419,    -1,   528,   527,   268,
     419,    -1,   537,    -1,   535,    -1,   527,   537,    -1,   527,
     535,    -1,   529,    -1,   528,   254,   529,    -1,   530,    -1,
     529,   251,   530,    -1,   531,    -1,   530,   253,   144,   531,
      -1,   532,    -1,   253,   532,    -1,   533,    -1,   533,   556,
      -1,   153,   526,   183,    -1,   534,    -1,   534,   552,    -1,
     454,    -1,   150,   366,   180,    -1,   536,    -1,   555,    -1,
     554,    -1,   557,    -1,   551,    -1,   165,    -1,   538,    -1,
     539,    -1,   540,    -1,   541,    -1,   544,    -1,   549,    -1,
     550,    -1,   257,    -1,   267,    -1,   100,   240,    -1,   100,
     243,    -1,   234,   242,    -1,   270,   242,    -1,   242,   240,
      -1,   242,   243,    -1,   234,   271,    -1,   270,   271,    -1,
     234,   274,   543,    -1,   234,   274,   113,    -1,   234,   274,
     153,   543,   183,    -1,   234,   274,   153,   543,   107,   542,
     183,    -1,   234,   274,   153,   113,   183,    -1,   234,   274,
     153,   113,   107,   542,   183,    -1,   270,   274,    -1,   543,
      -1,   542,   107,   543,    -1,    96,    20,    -1,    96,    20,
     261,    20,    -1,    96,    20,   553,   256,    -1,    96,    20,
     261,    20,   553,   256,    -1,   234,   272,   273,   546,    -1,
     234,   272,   273,   546,   545,    -1,   234,   113,   272,   273,
      -1,   234,   113,   272,   273,   545,    -1,   270,   272,   273,
      -1,   548,    -1,   545,   548,    -1,    96,    20,    -1,   153,
     547,   183,    -1,    20,    -1,   547,    20,    -1,   197,   546,
      -1,   134,   546,    -1,   255,    20,    -1,   234,   275,    -1,
     270,   275,    -1,    96,   214,    -1,    96,   247,    -1,   246,
     248,    -1,   239,    -1,   239,    55,    -1,   238,    -1,   238,
     273,    -1,   260,    -1,   249,   422,    -1,    96,   127,   422,
      -1,    96,    49,   422,    -1,   250,   422,   195,   422,    -1,
     245,   553,   558,    -1,   269,   422,   558,    -1,   258,   553,
     266,    -1,   262,   559,    -1,   244,   559,    -1,   273,    -1,
     265,    -1,   259,    -1,   264,    -1,   259,    -1,   270,   248,
     422,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  xquery_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    10,    13,    15,    18,    23,
      30,    33,    35,    38,    45,    48,    51,    56,    58,    62,
      64,    68,    70,    72,    74,    76,    78,    80,    82,    84,
      86,    88,    90,    95,   100,   102,   105,   109,   111,   113,
     115,   117,   119,   121,   123,   125,   127,   129,   131,   133,
     135,   137,   139,   141,   143,   145,   147,   149,   155,   159,
     163,   169,   175,   180,   184,   188,   192,   198,   204,   210,
     216,   222,   228,   233,   237,   241,   246,   252,   259,   261,
     265,   269,   273,   277,   284,   290,   299,   304,   308,   310,
     312,   314,   317,   320,   323,   327,   333,   338,   345,   347,
     349,   352,   354,   357,   359,   362,   370,   372,   376,   378,
     381,   384,   388,   392,   396,   399,   403,   408,   414,   417,
     422,   426,   427,   431,   434,   436,   440,   446,   450,   456,
     459,   462,   466,   470,   474,   477,   481,   485,   487,   490,
     493,   496,   501,   506,   511,   513,   517,   520,   524,   528,
     532,   534,   536,   539,   541,   545,   547,   551,   553,   555,
     557,   559,   561,   563,   565,   567,   569,   571,   573,   575,
     577,   579,   581,   583,   585,   587,   590,   593,   596,   599,
     601,   603,   606,   611,   615,   621,   626,   630,   632,   634,
     636,   638,   640,   642,   644,   646,   648,   651,   654,   658,
     661,   663,   668,   672,   677,   682,   688,   693,   699,   705,
     712,   716,   720,   724,   726,   731,   733,   738,   742,   747,
     752,   758,   763,   769,   771,   774,   778,   780,   783,   785,
     792,   796,   800,   802,   805,   809,   811,   815,   818,   822,
     825,   829,   834,   836,   840,   842,   845,   847,   849,   851,
     854,   857,   860,   864,   866,   868,   871,   874,   877,   883,
     889,   891,   896,   900,   905,   914,   925,   927,   930,   935,
     943,   952,   954,   958,   960,   964,   966,   970,   974,   978,
     982,   983,   988,   992,   996,  1000,  1002,  1006,  1011,  1013,
    1017,  1019,  1023,  1027,  1029,  1033,  1037,  1041,  1045,  1047,
    1051,  1055,  1057,  1061,  1065,  1067,  1072,  1074,  1079,  1081,
    1086,  1088,  1093,  1095,  1098,  1100,  1102,  1105,  1108,  1110,
    1112,  1114,  1116,  1118,  1120,  1122,  1124,  1126,  1128,  1130,
    1132,  1137,  1143,  1149,  1156,  1160,  1165,  1167,  1170,  1174,
    1177,  1179,  1182,  1185,  1187,  1189,  1191,  1195,  1199,  1201,
    1203,  1205,  1208,  1210,  1213,  1216,  1218,  1220,  1222,  1224,
    1226,  1228,  1230,  1232,  1234,  1237,  1240,  1242,  1244,  1246,
    1248,  1250,  1252,  1254,  1256,  1258,  1260,  1262,  1264,  1266,
    1268,  1271,  1273,  1276,  1280,  1282,  1284,  1286,  1288,  1290,
    1292,  1294,  1296,  1298,  1300,  1302,  1304,  1306,  1309,  1312,
    1316,  1318,  1323,  1328,  1332,  1337,  1339,  1343,  1345,  1347,
    1349,  1351,  1353,  1358,  1364,  1373,  1383,  1393,  1404,  1406,
    1409,  1411,  1414,  1421,  1422,  1424,  1428,  1432,  1433,  1435,
    1437,  1439,  1442,  1445,  1446,  1448,  1450,  1452,  1455,  1458,
    1460,  1462,  1464,  1466,  1468,  1470,  1472,  1474,  1476,  1478,
    1480,  1482,  1486,  1489,  1493,  1497,  1500,  1502,  1504,  1506,
    1508,  1510,  1512,  1517,  1522,  1528,  1535,  1543,  1548,  1554,
    1561,  1569,  1574,  1579,  1584,  1590,  1597,  1605,  1607,  1610,
    1613,  1615,  1618,  1622,  1624,  1626,  1628,  1630,  1632,  1636,
    1638,  1640,  1642,  1644,  1646,  1648,  1650,  1652,  1654,  1656,
    1660,  1664,  1669,  1674,  1678,  1682,  1686,  1691,  1696,  1700,
    1705,  1712,  1717,  1724,  1728,  1732,  1737,  1744,  1751,  1756,
    1763,  1770,  1775,  1777,  1780,  1782,  1786,  1790,  1794,  1800,
    1808,  1816,  1822,  1828,  1834,  1842,  1850,  1856,  1862,  1866,
    1870,  1876,  1884,  1890,  1898,  1900,  1905,  1909,  1915,  1917,
    1920,  1924,  1932,  1943,  1957,  1959,  1963,  1965,  1967,  1969,
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
         0,   888,   888,   889,   899,   904,   910,   915,   927,   932,
     942,   949,   961,   973,   985,   991,   997,  1009,  1015,  1029,
    1035,  1049,  1050,  1051,  1052,  1058,  1059,  1060,  1061,  1064,
    1067,  1069,  1075,  1080,  1088,  1094,  1103,  1112,  1113,  1114,
    1115,  1116,  1117,  1118,  1119,  1120,  1121,  1128,  1129,  1130,
    1131,  1132,  1133,  1134,  1137,  1144,  1145,  1157,  1169,  1174,
    1185,  1191,  1203,  1216,  1227,  1232,  1244,  1249,  1260,  1266,
    1272,  1278,  1297,  1308,  1319,  1326,  1333,  1340,  1353,  1359,
    1374,  1378,  1388,  1394,  1401,  1407,  1419,  1426,  1432,  1439,
    1445,  1449,  1456,  1467,  1471,  1479,  1488,  1495,  1505,  1507,
    1514,  1522,  1526,  1534,  1538,  1546,  1554,  1558,  1566,  1570,
    1577,  1584,  1594,  1599,  1611,  1615,  1619,  1623,  1630,  1637,
    1656,  1666,  1672,  1678,  1687,  1698,  1711,  1718,  1725,  1737,
    1741,  1748,  1752,  1756,  1763,  1767,  1773,  1780,  1784,  1788,
    1796,  1803,  1812,  1824,  1838,  1846,  1860,  1866,  1878,  1886,
    1897,  1908,  1912,  1924,  1928,  1937,  1941,  1957,  1958,  1959,
    1960,  1961,  1964,  1965,  1966,  1967,  1968,  1970,  1971,  1974,
    1975,  1976,  1977,  1978,  1981,  1988,  1997,  2004,  2008,  2016,
    2020,  2024,  2031,  2035,  2042,  2050,  2061,  2070,  2071,  2072,
    2076,  2076,  2076,  2076,  2076,  2079,  2085,  2094,  2098,  2108,
    2119,  2125,  2139,  2146,  2154,  2163,  2173,  2181,  2190,  2199,
    2214,  2226,  2237,  2249,  2255,  2267,  2273,  2287,  2295,  2304,
    2312,  2324,  2330,  2340,  2341,  2345,  2353,  2357,  2362,  2366,
    2370,  2374,  2381,  2396,  2404,  2411,  2417,  2428,  2434,  2443,
    2453,  2458,  2470,  2476,  2490,  2496,  2508,  2515,  2522,  2529,
    2536,  2543,  2550,  2563,  2567,  2577,  2582,  2593,  2604,  2611,
    2624,  2631,  2643,  2649,  2662,  2669,  2683,  2689,  2701,  2707,
    2720,  2731,  2735,  2746,  2750,  2769,  2773,  2781,  2789,  2797,
    2805,  2805,  2813,  2821,  2829,  2843,  2847,  2854,  2867,  2871,
    2882,  2886,  2890,  2900,  2904,  2908,  2912,  2916,  2926,  2930,
    2935,  2946,  2950,  2954,  2964,  2968,  2980,  2984,  2996,  3000,
    3012,  3016,  3028,  3032,  3044,  3048,  3052,  3056,  3068,  3072,
    3076,  3086,  3090,  3094,  3098,  3102,  3106,  3116,  3120,  3124,
    3134,  3138,  3142,  3146,  3158,  3164,  3176,  3182,  3196,  3203,
    3244,  3248,  3252,  3256,  3268,  3278,  3289,  3294,  3304,  3308,
    3318,  3324,  3330,  3336,  3348,  3354,  3365,  3369,  3373,  3377,
    3381,  3385,  3389,  3399,  3403,  3413,  3417,  3428,  3432,  3436,
    3440,  3444,  3459,  3463,  3473,  3477,  3487,  3494,  3501,  3514,
    3518,  3530,  3536,  3550,  3561,  3565,  3569,  3573,  3577,  3581,
    3585,  3589,  3599,  3603,  3613,  3618,  3623,  3634,  3644,  3648,
    3659,  3669,  3680,  3736,  3742,  3754,  3760,  3772,  3776,  3786,
    3790,  3794,  3804,  3812,  3820,  3828,  3836,  3844,  3859,  3865,
    3877,  3883,  3896,  3905,  3907,  3913,  3918,  3930,  3933,  3940,
    3946,  3952,  3960,  3975,  3978,  3985,  3991,  3997,  4005,  4019,
    4024,  4035,  4040,  4051,  4056,  4061,  4067,  4079,  4085,  4090,
    4095,  4106,  4111,  4126,  4131,  4148,  4163,  4167,  4171,  4175,
    4179,  4183,  4193,  4204,  4210,  4216,  4221,  4243,  4249,  4255,
    4260,  4271,  4281,  4291,  4297,  4303,  4308,  4319,  4325,  4337,
    4348,  4354,  4360,  4397,  4402,  4407,  4418,  4422,  4426,  4436,
    4447,  4451,  4455,  4459,  4463,  4467,  4471,  4475,  4479,  4489,
    4499,  4503,  4508,  4519,  4529,  4539,  4543,  4547,  4557,  4563,
    4569,  4575,  4581,  4593,  4604,  4611,  4618,  4625,  4632,  4639,
    4646,  4659,  4680,  4687,  4707,  4747,  4751,  4755,  4764,  4770,
    4776,  4782,  4788,  4795,  4801,  4807,  4813,  4819,  4831,  4836,
    4846,  4852,  4864,  4890,  4901,  4907,  4920,  4934,  4941,  4947,
    4958,  4965,  4974,  4983,  4996,  5002,  5012,  5015,  5015,  5019,
    5036,  5036,  5039,  5040,  5041,  5042,  5043,  5044,  5045,  5046,
    5047,  5048,  5049,  5050,  5051,  5052,  5053,  5054,  5055,  5056,
    5057,  5058,  5059,  5060,  5061,  5062,  5063,  5064,  5065,  5066,
    5067,  5068,  5069,  5070,  5071,  5072,  5073,  5074,  5075,  5076,
    5077,  5078,  5079,  5080,  5081,  5082,  5083,  5084,  5085,  5086,
    5087,  5088,  5089,  5090,  5091,  5092,  5093,  5094,  5095,  5096,
    5097,  5098,  5099,  5100,  5101,  5102,  5103,  5104,  5105,  5106,
    5107,  5108,  5109,  5110,  5111,  5112,  5113,  5114,  5115,  5116,
    5117,  5118,  5119,  5120,  5121,  5122,  5123,  5124,  5125,  5126,
    5127,  5128,  5129,  5130,  5131,  5132,  5133,  5134,  5135,  5136,
    5137,  5138,  5139,  5140,  5141,  5142,  5143,  5144,  5145,  5146,
    5147,  5148,  5149,  5150,  5151,  5152,  5153,  5154,  5155,  5156,
    5157,  5158,  5159,  5160,  5161,  5162,  5163,  5164,  5165,  5166,
    5167,  5168,  5169,  5170,  5171,  5172,  5173,  5174,  5175,  5176,
    5177,  5178,  5179,  5180,  5181,  5182,  5183,  5184,  5185,  5186,
    5187,  5188,  5189,  5190,  5191,  5192,  5193,  5194,  5195,  5196,
    5197,  5198,  5199,  5200,  5201,  5202,  5203,  5204,  5205,  5206,
    5207,  5208,  5209,  5210,  5211,  5212,  5213,  5214,  5215,  5216,
    5217,  5218,  5219,  5220,  5221,  5222,  5223,  5234,  5240,  5257,
    5261,  5265,  5269,  5279,  5282,  5285,  5288,  5297,  5300,  5309,
    5312,  5321,  5324,  5333,  5336,  5345,  5348,  5351,  5360,  5363,
    5372,  5376,  5386,  5389,  5392,  5395,  5398,  5407,  5416,  5420,
    5424,  5428,  5432,  5436,  5440,  5450,  5453,  5456,  5459,  5468,
    5471,  5474,  5477,  5486,  5489,  5498,  5501,  5504,  5507,  5510,
    5513,  5516,  5525,  5528,  5537,  5540,  5543,  5546,  5555,  5558,
    5561,  5564,  5567,  5576,  5579,  5588,  5591,  5600,  5603,  5612,
    5615,  5624,  5633,  5636,  5645,  5648,  5651,  5660,  5663,  5666,
    5669,  5672,  5681,  5685,  5689,  5693,  5703,  5712,  5722,  5731,
    5734,  5743,  5746,  5749,  5758,  5761,  5770
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
     295,   296,   297,   298
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 9254;
  const int xquery_parser::yynnts_ = 262;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 495;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 299;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 553;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 13252 "/home/colea/work/xquery_temp/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 5778 "/home/colea/work/xquery_temp/src/compiler/parser/xquery_parser.y"


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

