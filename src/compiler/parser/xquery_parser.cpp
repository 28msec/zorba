
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
#line 87 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"


#include "common/common.h"

#ifdef WIN32
#pragma warning(disable: 4786)
#endif

#include "compiler/parsetree/parsenodes.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/api/compilercb.h"
#include "store/api/update_consts.h"
#include "compiler/parser/xquery_driver.h"

#define SYMTAB( n ) driver.symtab.get( (off_t)n )
#define SYMTAB_PUT( s ) driver.symtab.put( s )
#define LOC( p ) driver.createQueryLoc( p )


namespace zorba
{
namespace parser
{
  extern const char *the_tumbling, *the_sliding, *the_start, *the_end, *the_only_end, *the_declare, *the_create;

}
}

#define YYDEBUG 1

using namespace std;
using namespace zorba;



/* Line 311 of lalr1.cc  */
#line 79 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 906 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 317 of lalr1.cc  */
#line 1022 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_scanner.h"

#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc  */
#line 109 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"

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
#line 178 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
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
#line 904 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 285 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 124: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 903 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 294 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 149: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 902 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 303 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 312 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 321 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 330 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 339 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 348 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 357 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 366 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 375 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 384 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 393 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 402 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 411 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 420 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 429 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 438 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 447 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 456 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 465 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 474 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 483 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 492 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 501 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 510 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 519 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 528 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 537 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 546 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 555 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 564 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 573 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 582 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 591 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 600 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 609 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 618 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 627 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 636 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 645 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 654 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 663 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 672 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 681 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 690 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 699 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 708 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 717 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 726 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 735 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 744 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 753 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 762 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 771 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 780 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 789 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 798 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 825 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 834 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 843 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 861 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 870 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 897 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 906 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 915 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 933 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 942 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 951 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 960 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 969 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 978 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 987 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 996 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1005 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1014 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1023 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1032 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1041 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1050 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1059 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1068 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1077 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1086 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1095 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1104 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1113 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1122 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1131 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1140 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1149 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1158 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1167 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1176 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1185 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1194 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1203 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1212 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1221 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1230 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1239 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1248 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1257 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1266 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1275 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1284 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1293 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1302 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1311 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1320 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1329 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1338 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1347 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1356 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1365 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1374 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1383 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1392 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1401 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1410 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1419 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1428 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1437 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1446 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1455 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1464 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1473 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1482 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1491 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1500 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1509 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1518 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1527 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1536 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1545 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1554 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1563 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1572 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1581 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1590 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1599 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1608 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1617 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1626 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1635 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1644 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1653 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1662 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1671 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1680 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1689 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1698 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1707 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1716 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1725 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1734 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1743 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1752 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1761 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1770 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1779 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1788 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1797 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1806 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1815 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1824 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1833 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1842 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1851 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1860 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1869 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1878 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1887 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1896 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1905 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1914 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1923 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1932 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1941 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1950 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1959 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1968 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1977 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1986 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1995 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2004 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2013 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2022 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2031 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2040 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2049 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2058 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2067 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2076 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2085 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2094 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2103 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2112 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2121 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2130 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2139 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2148 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2157 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2166 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2175 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2184 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2193 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2202 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2211 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2220 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2229 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2238 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2247 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2256 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2265 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2274 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2283 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2292 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2301 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2310 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2319 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2328 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2337 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2346 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2355 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2364 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2373 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2382 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2391 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2400 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2409 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2418 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2427 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2436 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2445 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2454 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2463 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2472 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2481 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2490 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2499 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2508 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2517 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2526 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 610: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2535 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 611: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2544 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 612: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2553 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 613: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2562 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 617: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2571 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2580 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 621: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2589 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 625: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2598 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 626: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2607 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 627: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2616 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 628: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2625 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 629: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2634 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 630: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2643 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 631: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2652 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 632: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2661 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 633: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2670 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 634: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2679 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 635: /* "JSONSimpleObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2688 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 636: /* "JSONAccumulatorObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2697 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 637: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2706 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 638: /* "JSONPairList" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2715 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 639: /* "JSONInsertExpr" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2724 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 640: /* "JSONAppendExpr" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2733 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 641: /* "JSONDeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2742 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 642: /* "JSONRenameExpr" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2751 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 643: /* "JSONReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2760 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 650: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2769 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 651: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2778 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
	break;
      case 652: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2787 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
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
#line 140 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 553 of lalr1.cc  */
#line 2872 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"

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
#line 1040 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 1044 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 1048 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 1059 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 1068 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 1074 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 1082 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 1088 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 1099 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1104 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1112 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1119 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1126 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1135 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1142 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1150 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1158 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1166 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1177 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 1182 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 1189 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 1196 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 1208 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 1218 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 1225 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 1232 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      // error
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1267 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1272 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1280 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1288 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1296 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1301 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1309 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1314 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1322 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1327 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1335 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1342 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 1349 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 1356 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 1371 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 1381 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1386 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1394 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1402 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1413 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1420 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1431 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1436 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1444 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1451 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1458 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1467 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(8) - (4)].sval)),
                            SYMTAB((yysemantic_stack_[(8) - (6)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1480 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1488 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1495 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1505 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1512 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1519 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1542 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1548 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1557 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1564 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1574 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1583 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1584 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1585 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1586 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1587 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1588 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1589 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1590 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1591 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1592 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1598 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1606 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1614 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1622 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1629 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1637 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1644 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1649 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 1657 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 1665 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (2)].varnametype)));

      (yyval.node) = new GlobalVarDecl(LOC((yyloc)),
                             nt->theName,
                             nt->theType,
                             (yysemantic_stack_[(4) - (4)].expr),
                             nt->get_annotations(),
                             false);  // not external

      static_cast<GlobalVarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1679 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (2)].varnametype)));

      (yyval.node) = new GlobalVarDecl(LOC((yyloc)),
                             nt->theName,
                             nt->theType,
                             NULL,   // no init expr
                             nt->get_annotations(),
                             true);  // external

      static_cast<GlobalVarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1693 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(5) - (2)].varnametype)));

      (yyval.node) = new GlobalVarDecl(LOC((yyloc)),
                             nt->theName,
                             nt->theType,
                             (yysemantic_stack_[(5) - (5)].expr),     // init expr
                             nt->get_annotations(),
                             true);  // external

      static_cast<GlobalVarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1710 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1715 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1723 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1731 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1742 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1747 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1756 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1761 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1768 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1773 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1783 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1788 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1797 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1803 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1816 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1821 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1829 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->theParams,
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->theReturnType,
                            (yysemantic_stack_[(4) - (4)].expr),      // body
                            false,   // not explicitly updating
                            false);  // not external
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 129:

/* Line 678 of lalr1.cc  */
#line 1840 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            (yysemantic_stack_[(4) - (3)].fnsig)->theParams.getp(),
                            (yysemantic_stack_[(4) - (3)].fnsig)->theReturnType.getp(),
                            NULL,   // no body
                            false,   // not explicitly updating
                            true);  // external
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 130:

/* Line 678 of lalr1.cc  */
#line 1855 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theParams.getp(),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theReturnType.getp(),
                            (yysemantic_stack_[(5) - (5)].expr),    // body
                            true,  // updating
                            false);// not external
      delete (yysemantic_stack_[(5) - (4)].fnsig);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1867 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theParams.getp(),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theReturnType.getp(),
                            NULL,  // no body
                            true,  // updating
                            true); // external
      delete (yysemantic_stack_[(5) - (4)].fnsig);
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1882 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1887 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1892 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1897 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1905 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1912 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1923 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1928 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1938 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL);
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1945 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1952 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0);
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1959 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1969 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1973 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1979 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1983 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));

    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1993 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                             (yysemantic_stack_[(8) - (6)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                             NULL);
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 2001 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(9) - (4)].expr)),
                             (yysemantic_stack_[(9) - (7)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(9) - (9)].node)),
                             static_cast<AnnotationListParsenode*>((yysemantic_stack_[(9) - (2)].node)));
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 2012 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 2018 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 2027 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 2032 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 2039 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 2046 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 2058 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 2068 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 2078 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 2089 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICForeignKey( LOC((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(22) - (4)].expr)),
                            static_cast<QName*>((yysemantic_stack_[(22) - (9)].expr)),
                            static_cast<QName*>((yysemantic_stack_[(22) - (12)].expr)),
                            (yysemantic_stack_[(22) - (14)].expr),
                            static_cast<QName*>((yysemantic_stack_[(22) - (17)].expr)),
                            static_cast<QName*>((yysemantic_stack_[(22) - (20)].expr)),
                            (yysemantic_stack_[(22) - (22)].expr));
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 2105 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      if ((yysemantic_stack_[(1) - (1)].expr) == NULL)
      {
        error((yylocation_stack_[(1) - (1)]), "syntax error, unexpected end of file, the query should not be empty");
        YYERROR;
      }

      if (dynamic_cast<BlockBody*>((yysemantic_stack_[(1) - (1)].expr)) != NULL)
      {
        BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(1) - (1)].expr));
        blk->setTopLevel(true);
      }

      (yyval.expr) = new QueryBody(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 2125 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 2129 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 2133 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2141 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 2145 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 2149 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 2157 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 2162 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 2174 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 2181 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 2210 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 2215 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 2223 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      if (dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (2)].expr)) == NULL)
      {
        BlockBody* blk = new BlockBody(LOC((yyloc)));
        blk->add((yysemantic_stack_[(3) - (2)].expr));
        (yyval.expr) = blk;
      }
      else
      {
        (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
      }
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 2240 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 2248 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 2256 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 2263 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 2270 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 2281 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)),
                                          NULL,  // no type
                                          NULL,  // no init expr
                                          NULL); // no annotations
      (yyval.node) = vd;
    }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 2290 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                                          dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)), // type
                                          NULL,  // no init expr
                                          NULL); // no annotations
      (yyval.node) = vd;
    }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 2299 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                          NULL,  // no type
                                          (yysemantic_stack_[(4) - (4)].expr),    // init expr
                                          NULL); // no annotations
      (yyval.node) = vd;
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 2308 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                          dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)), // type
                                          (yysemantic_stack_[(5) - (5)].expr),    // init expr
                                          NULL); // no annotations
      (yyval.node) = vd;
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 2321 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 2329 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 2337 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 2345 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* bb = dynamic_cast<BlockBody *>((yysemantic_stack_[(5) - (5)].expr));
      if (bb == NULL)
      {
        bb = new BlockBody((yysemantic_stack_[(5) - (5)].expr)->get_location());
        bb->add((yysemantic_stack_[(5) - (5)].expr));
      }

      (yyval.expr) = new WhileExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), bb);
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 2360 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 2365 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2373 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      ReturnExpr* re = dynamic_cast<ReturnExpr*>((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = new FLWORExpr(LOC((yyloc)),
                         dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node)),
                         re->get_return_val(),
                         re->get_location(),
                         driver.theCompilerCB->theConfig.force_gflwor);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 2387 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      exprnode* retExpr = (yysemantic_stack_[(2) - (2)].expr);

      if (dynamic_cast<VarDeclStmt*>(retExpr) != NULL)
      {
        BlockBody* blk = new BlockBody(LOC((yyloc)));
        blk->add(retExpr);
        retExpr = blk;
      }

      (yyval.expr) = new ReturnExpr(LOC((yyloc)), retExpr);
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 2404 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      exprnode* thenExpr = (yysemantic_stack_[(8) - (6)].expr);
      exprnode* elseExpr = (yysemantic_stack_[(8) - (8)].expr);

      if (dynamic_cast<VarDeclStmt*>(thenExpr) != NULL)
      {
        BlockBody* blk = new BlockBody(LOC((yyloc)));
        blk->add(thenExpr);
        thenExpr = blk;
      }

      if (dynamic_cast<VarDeclStmt*>(elseExpr) != NULL)
      {
        BlockBody* blk = new BlockBody(LOC((yyloc)));
        blk->add(elseExpr);
        elseExpr = blk;
      }

      (yyval.expr) = new IfExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), thenExpr, elseExpr);
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 2429 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 2437 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 2444 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 2455 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 2465 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 2470 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      Expr* expr = dynamic_cast<Expr*>((yysemantic_stack_[(3) - (1)].expr));
      if ( !expr )
      {
        expr = new Expr( LOC((yyloc)) );
        expr->push_back( (yysemantic_stack_[(3) - (1)].expr) );
      }
      expr->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.expr) = expr;
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 2515 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      ReturnExpr *re = dynamic_cast<ReturnExpr*>((yysemantic_stack_[(2) - (2)].expr));
      (yyval.expr) = new FLWORExpr(LOC((yyloc)),
                         dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node)),
                         re->get_return_val(),
                         re->get_location(),
                         driver.theCompilerCB->theConfig.force_gflwor);
      delete (yysemantic_stack_[(2) - (2)].expr);
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 2529 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 2537 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 2542 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 2550 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 2555 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 2560 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 2568 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)),
                            (yysemantic_stack_[(4) - (4)].expr),
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 2577 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            NULL,
                            (yysemantic_stack_[(3) - (3)].expr),
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 2589 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(5) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(5) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (4)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 2599 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 2612 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2636 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2643 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2653 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2659 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected QName \""
          + static_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node))->operator[](0)->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      YYERROR;
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 2667 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL; // to prevent the Bison warning
      error((yylocation_stack_[(2) - (2)]), ""); // the error message is already set in the driver's parseError member
      YYERROR;
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2677 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 2684 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 2692 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (3)]), "syntax error, unexpected QName \""
          + static_cast<VarInDecl*>((yysemantic_stack_[(3) - (3)].node))->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      YYERROR;
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 2703 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)),
                         NULL,
                         NULL,
                         NULL,
                         (yysemantic_stack_[(3) - (3)].expr),
                         false);
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 2713 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         NULL,
                         NULL,
                         NULL,
                         (yysemantic_stack_[(5) - (5)].expr),
                         true);
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 2723 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                         NULL,
                         NULL,
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 259:

/* Line 678 of lalr1.cc  */
#line 2733 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (2)].node)),
                         NULL,
                         NULL,
                         (yysemantic_stack_[(6) - (6)].expr),
                         true);
    }
    break;

  case 260:

/* Line 678 of lalr1.cc  */
#line 2743 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(4) - (2)].node)),
                         NULL,
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 261:

/* Line 678 of lalr1.cc  */
#line 2753 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (4)].node)),
                         NULL,
                         (yysemantic_stack_[(6) - (6)].expr),
                         true);
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2763 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (3)].node)),
                         NULL,
                         (yysemantic_stack_[(5) - (5)].expr),
                         false);
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2773 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(7) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(7) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(7) - (5)].node)),
                         NULL,
                         (yysemantic_stack_[(7) - (7)].expr),
                         true);
    }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2784 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2793 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (2)].node)),
                         NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         false);
    }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2803 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC ((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (1)].expr)),
                         NULL,
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(5) - (2)].node)),
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         false);
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2813 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC ((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (1)].expr)),
                         dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (2)].node)),
                         dynamic_cast<PositionalVar*>((yysemantic_stack_[(6) - (3)].node)),
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                         (yysemantic_stack_[(6) - (6)].expr),
                         false);
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2829 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2838 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2847 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2855 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2861 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2873 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2881 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2891 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2899 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 2911 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2917 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2930 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2934 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2942 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2946 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2955 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2959 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2963 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2973 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2981 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 2988 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 2994 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 3004 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 3008 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 3012 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         NULL);
    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 3020 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(6) - (3)].node)),
                         (yysemantic_stack_[(6) - (5)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 3028 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         NULL,
                         (yysemantic_stack_[(5) - (4)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 3036 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         NULL,
                         NULL,
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 3048 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 3056 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 3062 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 3072 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3078 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3088 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3092 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3102 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3108 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3114 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3120 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3129 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3138 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3147 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3160 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3164 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3172 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3178 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3188 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3196 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3205 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3218 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3225 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3237 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3241 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3253 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3260 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3266 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3275 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3282 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3288 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3299 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3306 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3312 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3321 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3330 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3337 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3348 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3355 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3367 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3373 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3385 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3391 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3402 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3408 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3419 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3425 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3436 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3445 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3449 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3458 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3462 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3470 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3474 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "eq" | "ne" | "lt" | "le" | "gt" | "ge" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3484 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3491 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3500 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3509 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3514 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3523 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3532 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3541 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3554 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3558 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3570 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3574 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3581 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3585 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3592 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3596 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3605 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3609 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3613 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3621 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3625 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3631 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3637 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3643 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3653 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3657 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3661 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3669 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3673 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3679 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3689 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3693 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3703 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3707 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3717 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3721 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3731 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3735 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3745 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3749 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3757 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3761 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3765 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3769 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3779 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3783 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3787 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3795 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3799 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3803 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3807 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3811 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3815 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3823 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3827 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3831 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3839 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3843 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3847 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3851 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3862 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3868 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3878 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3884 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3894 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3898 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3902 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3940 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3944 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3954 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3964 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3977 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 3986 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      AxisStep* as = dynamic_cast<AxisStep*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (as ?
            new RelativePathExpr(LOC((yyloc)),
                                 ParseConstants::st_slash,
                                 new ContextItemExpr( LOC((yyloc)), true ), (yysemantic_stack_[(1) - (1)].expr), true)
            :
            (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 3996 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 4000 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 4009 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 4013 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 4022 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 4028 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 4036 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 4042 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 4054 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 4060 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 4070 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 4074 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 4078 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4082 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4086 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4092 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4098 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4106 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4110 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4118 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4122 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4133 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4137 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4141 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4147 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4151 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4165 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4169 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4177 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4181 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4191 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4195 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4199 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4203 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4212 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4216 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4220 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4224 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4232 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4238 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4248 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4256 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4260 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4264 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4268 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4272 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4276 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4280 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4284 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4288 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4292 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4297 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4301 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4305 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4309 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4317 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4321 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4329 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4336 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4343 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4354 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4362 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4366 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4374 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4382 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4390 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4444 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4448 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4461 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4467 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4477 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4481 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4489 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4493 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4497 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4505 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemConstructor(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                NULL,
                NULL,
                NULL
            );
        }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4515 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemConstructor(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                NULL,
                dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)),
                NULL
            );
        }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4525 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            if (static_cast<QName*>((yysemantic_stack_[(8) - (2)].expr))->get_qname() != static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr))->get_qname())
            {
              error((yylocation_stack_[(8) - (1)]), "syntax error, end tag </" + static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr))->get_qname().str() + "> does not match start tag <"
                                                   + static_cast<QName*>((yysemantic_stack_[(8) - (2)].expr))->get_qname().str() + ">");
              YYERROR;
            }

            (yyval.expr) = new DirElemConstructor(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(8) - (2)].expr)),
                static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr)),
                NULL,
                NULL
            );
        }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4542 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            if (static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr))->get_qname() != static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr))->get_qname())
            {
              error((yylocation_stack_[(9) - (1)]), "syntax error, end tag </" + static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr))->get_qname().str() + "> does not match start tag <"
                                                   + static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr))->get_qname().str() + ">");
              YYERROR;
            }

            (yyval.expr) = new DirElemConstructor(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
                static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
                NULL,
                dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node))
            );
        }
    break;

  case 504:

/* Line 678 of lalr1.cc  */
#line 4559 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            if (static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr))->get_qname() != static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr))->get_qname())
            {
              error((yylocation_stack_[(9) - (1)]), "syntax error, end tag </" + static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr))->get_qname().str() + "> does not match start tag <"
                                                   + static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr))->get_qname().str() + ">");
              YYERROR;
            }

            (yyval.expr) = new DirElemConstructor(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
                static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
                dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
                NULL
            );
        }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4576 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            if (static_cast<QName*>((yysemantic_stack_[(10) - (2)].expr))->get_qname() != static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr))->get_qname())
            {
              error((yylocation_stack_[(10) - (1)]), "syntax error, end tag </" + static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr))->get_qname().str() + "> does not match start tag <"
                                                   + static_cast<QName*>((yysemantic_stack_[(10) - (2)].expr))->get_qname().str() + ">");
              YYERROR;
            }

            (yyval.expr) = new DirElemConstructor(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(10) - (2)].expr)),
                static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)),
                dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node))
            );
        }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4598 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4604 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4615 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4621 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4632 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4649 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4654 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4663 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4667 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4674 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4680 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4686 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4694 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4706 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4710 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4717 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4723 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4729 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4736 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4747 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4751 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4761 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4765 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4775 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4779 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4783 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4788 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4797 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4803 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4809 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4815 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4823 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4828 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4836 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4841 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4849 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4857 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4862 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4867 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4872 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4877 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4882 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4891 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4899 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4903 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4920 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4924 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 4932 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 4940 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 4948 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 4952 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 4960 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 4966 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 4976 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 4984 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 4988 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 4992 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 5027 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 5033 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 5039 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 5049 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5053 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5057 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5061 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5065 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5069 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5073 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5080 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5086 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5096 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5104 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5108 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5112 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5116 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5120 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5124 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5128 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5132 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5136 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5144 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5152 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5156 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5160 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5170 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5178 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5186 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5190 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5194 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5202 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5206 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5212 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5218 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5222 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5232 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5240 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5244 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5250 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5259 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5268 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5274 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5280 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5290 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5307 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5314 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5329 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5365 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5369 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5377 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5385 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5397 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5401 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5409 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5417 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5421 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5432 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5449 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5455 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5461 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5471 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5475 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5481 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5487 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5491 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5497 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5501 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5507 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5513 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5520 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5530 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5535 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5543 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5549 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5559 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5581 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5590 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5596 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5609 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5623 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5630 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5636 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5646 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5655 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5663 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5669 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5687 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5695 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5699 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5706 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5711 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5719 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5723 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5730 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5734 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5741 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5745 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5752 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5756 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5765 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5777 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5781 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5788 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5792 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5800 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5808 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5816 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5820 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5827 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5831 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5839 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5850 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5854 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5862 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5874 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5880 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5889 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5893 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5901 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5905 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5909 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5916 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5920 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5927 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5931 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5939 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5943 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5947 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5951 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5955 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5963 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5971 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5983 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5995 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5999 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 6003 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 6011 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 6017 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 6027 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 6031 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 6035 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 6039 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 6043 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 6047 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 6051 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 6055 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 6063 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 6067 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 6071 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 6075 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 6083 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 6089 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 6099 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 6109 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 6113 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 6121 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            FTThesaurusOption::thesaurus_id_list_t *til = NULL;
            if ( (yysemantic_stack_[(2) - (2)].node) ) {
                til = new FTThesaurusOption::thesaurus_id_list_t;
                til->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(2) - (2)].node)) );
            }
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), til, !til );
            delete til;
        }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 6131 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            FTThesaurusOption::thesaurus_id_list_t *til = (yysemantic_stack_[(5) - (4)].thesaurus_id_list);
            if ( (yysemantic_stack_[(5) - (3)].node) ) {
                if ( !til )
                    til = new FTThesaurusOption::thesaurus_id_list_t;
                til->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(5) - (3)].node)) );
            }
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), til, !(yysemantic_stack_[(5) - (3)].node) );
            delete til;
        }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 6142 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 6149 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 6153 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 6160 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 6164 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 6171 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 6176 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 6185 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 6194 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 6198 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 6205 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 6209 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 6217 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 6226 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 6233 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 6243 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 6247 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 6254 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 6260 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 6269 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 6273 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 6280 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 6285 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 6297 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 6305 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 6317 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 6325 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 6329 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 6337 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 6341 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 6345 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 6353 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 6361 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 6365 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 6369 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 6373 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 6381 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 6389 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 6401 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 6405 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 6413 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 6427 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 6431 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 6438 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 6443 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 6451 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 6456 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 6465 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 6473 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 6479 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 6489 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        static_cast<JSONPairList*>((yysemantic_stack_[(7) - (4)].node)),
                                        (yysemantic_stack_[(7) - (7)].expr));
        }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 6495 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(10) - (4)].expr), (yysemantic_stack_[(10) - (7)].expr), (yysemantic_stack_[(10) - (10)].expr));
        }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 6502 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(7) - (4)].expr), (yysemantic_stack_[(7) - (7)].expr));
        }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 6509 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          rchandle<DynamicFunctionInvocation> lDynamicFunctionInvocation = 
          dynamic_cast<DynamicFunctionInvocation*>((yysemantic_stack_[(3) - (3)].expr));

          if (lDynamicFunctionInvocation == NULL)
          {
            error((yylocation_stack_[(3) - (3)]), "An object invocation is expected. A filter was found instead.");
            YYERROR;
          }

          rchandle<exprnode> lPrimaryExpr =
          lDynamicFunctionInvocation->getPrimaryExpr().release();

          rchandle<ArgList> lArgList =
          lDynamicFunctionInvocation->getArgList().release();

          if (lArgList->size() != 1)
          {
            error((yylocation_stack_[(3) - (3)]), "An object invocation with exactly one argument is expected. Zero or more than one argument were found.");
            YYERROR;
          }

          rchandle<exprnode> lKey = (*lArgList)[0].release();
          (yyval.expr) = new JSONDeleteExpr(LOC((yyloc)), lPrimaryExpr.release(), lKey.release());
        }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 6538 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          rchandle<DynamicFunctionInvocation> lDynamicFunctionInvocation = 
          dynamic_cast<DynamicFunctionInvocation*>((yysemantic_stack_[(5) - (3)].expr));

          if(lDynamicFunctionInvocation == NULL) 
          {
            error((yylocation_stack_[(5) - (3)]), "An object invocation is expected. A filter was found instead.");
            YYERROR;
          }

          rchandle<exprnode> lPrimaryExpr =
          lDynamicFunctionInvocation->getPrimaryExpr().release();

          rchandle<ArgList> lArgList =
          lDynamicFunctionInvocation->getArgList().release();

          if (lArgList->size() != 1)
          {
            error((yylocation_stack_[(5) - (3)]), "An object invocation with exactly one argument is expected. Zero or more than one argument were found.");
            YYERROR;
          }

          rchandle<exprnode> lKey = (*lArgList)[0].release();
          (yyval.expr) = new JSONRenameExpr(LOC((yyloc)), lPrimaryExpr.release(), lKey.release(), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 6567 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          rchandle<DynamicFunctionInvocation> lDynamicFunctionInvocation = 
          dynamic_cast<DynamicFunctionInvocation*>((yysemantic_stack_[(7) - (5)].expr));

          if(lDynamicFunctionInvocation == NULL) 
          {
            error((yylocation_stack_[(7) - (3)]), "An object invocation is expected. A filter was found instead.");
            YYERROR;
          }

          rchandle<exprnode> lPrimaryExpr =
          lDynamicFunctionInvocation->getPrimaryExpr().release();

          rchandle<ArgList> lArgList =
          lDynamicFunctionInvocation->getArgList().release();

          if (lArgList->size() != 1)
          {
            error((yylocation_stack_[(7) - (3)]), "An object invocation with exactly one argument is expected. Zero or more than one argument were found.");
            YYERROR;
          }

          rchandle<exprnode> lKey = (*lArgList)[0].release();
          (yyval.expr) = new JSONReplaceExpr(LOC((yyloc)), lPrimaryExpr.release(), lKey.release(), (yysemantic_stack_[(7) - (7)].expr));
        }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 6596 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 6600 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 6604 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 6611 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 6618 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 6625 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 6642 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    {
          auto_ptr<QName> lQName( static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
          zstring const &tmp = lQName->get_qname();
          if ( tmp.find (':') != string::npos ) {
            error((yylocation_stack_[(1) - (1)]), "A NCName is expected, found a QName");
            YYERROR;
          }
          (yyval.sval) = SYMTAB_PUT(tmp.c_str());
        }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 6655 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 6656 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 6657 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 6658 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 6659 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 6660 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 6661 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 6662 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 6663 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 6664 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 6665 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 6666 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 6667 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 6668 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 6669 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 6674 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 6675 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 6676 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 6677 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 6678 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 6679 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 6680 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 6681 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 6682 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 6683 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 6684 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 6685 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 6686 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 6687 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 6688 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 6689 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 6690 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 6691 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 6692 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 6693 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 6694 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 6695 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 6696 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 6697 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 6698 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 6699 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 6700 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 6701 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 6702 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 6703 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 6704 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 6705 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 6706 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 6707 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 6708 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 6709 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 6710 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 6711 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 6712 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 6713 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 6714 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 6715 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 6716 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 6717 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 6718 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 6719 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 6720 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 6721 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 6722 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 6723 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 6724 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 6725 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 6726 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 6727 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 6728 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 6729 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 6730 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 6731 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 6732 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 6733 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 6734 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 6735 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 6736 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 6737 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 6738 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 6739 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 6740 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6741 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6742 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6743 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6744 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6745 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6746 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6747 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 6748 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 6749 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 6750 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 6751 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 6752 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 6753 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 6754 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 6755 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 6756 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 6757 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 6758 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 6759 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 6760 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 6761 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 6762 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6763 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6764 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 6765 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 6766 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 898:

/* Line 678 of lalr1.cc  */
#line 6767 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 899:

/* Line 678 of lalr1.cc  */
#line 6768 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 900:

/* Line 678 of lalr1.cc  */
#line 6769 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 901:

/* Line 678 of lalr1.cc  */
#line 6770 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 902:

/* Line 678 of lalr1.cc  */
#line 6771 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 903:

/* Line 678 of lalr1.cc  */
#line 6772 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 904:

/* Line 678 of lalr1.cc  */
#line 6773 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 905:

/* Line 678 of lalr1.cc  */
#line 6774 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 906:

/* Line 678 of lalr1.cc  */
#line 6775 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 907:

/* Line 678 of lalr1.cc  */
#line 6776 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 908:

/* Line 678 of lalr1.cc  */
#line 6777 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 909:

/* Line 678 of lalr1.cc  */
#line 6778 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 910:

/* Line 678 of lalr1.cc  */
#line 6779 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 911:

/* Line 678 of lalr1.cc  */
#line 6780 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 912:

/* Line 678 of lalr1.cc  */
#line 6781 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 913:

/* Line 678 of lalr1.cc  */
#line 6782 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 914:

/* Line 678 of lalr1.cc  */
#line 6783 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 915:

/* Line 678 of lalr1.cc  */
#line 6784 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 916:

/* Line 678 of lalr1.cc  */
#line 6785 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 917:

/* Line 678 of lalr1.cc  */
#line 6786 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 918:

/* Line 678 of lalr1.cc  */
#line 6787 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 919:

/* Line 678 of lalr1.cc  */
#line 6788 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 920:

/* Line 678 of lalr1.cc  */
#line 6789 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 921:

/* Line 678 of lalr1.cc  */
#line 6790 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 922:

/* Line 678 of lalr1.cc  */
#line 6791 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 923:

/* Line 678 of lalr1.cc  */
#line 6792 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 924:

/* Line 678 of lalr1.cc  */
#line 6793 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 925:

/* Line 678 of lalr1.cc  */
#line 6794 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 926:

/* Line 678 of lalr1.cc  */
#line 6795 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 927:

/* Line 678 of lalr1.cc  */
#line 6796 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 928:

/* Line 678 of lalr1.cc  */
#line 6797 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 929:

/* Line 678 of lalr1.cc  */
#line 6798 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 930:

/* Line 678 of lalr1.cc  */
#line 6799 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 931:

/* Line 678 of lalr1.cc  */
#line 6800 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 932:

/* Line 678 of lalr1.cc  */
#line 6801 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 933:

/* Line 678 of lalr1.cc  */
#line 6802 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 934:

/* Line 678 of lalr1.cc  */
#line 6803 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 935:

/* Line 678 of lalr1.cc  */
#line 6804 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 936:

/* Line 678 of lalr1.cc  */
#line 6805 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 937:

/* Line 678 of lalr1.cc  */
#line 6806 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 938:

/* Line 678 of lalr1.cc  */
#line 6807 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 939:

/* Line 678 of lalr1.cc  */
#line 6808 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 940:

/* Line 678 of lalr1.cc  */
#line 6809 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 941:

/* Line 678 of lalr1.cc  */
#line 6810 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 942:

/* Line 678 of lalr1.cc  */
#line 6811 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 943:

/* Line 678 of lalr1.cc  */
#line 6812 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 944:

/* Line 678 of lalr1.cc  */
#line 6813 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 945:

/* Line 678 of lalr1.cc  */
#line 6814 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 946:

/* Line 678 of lalr1.cc  */
#line 6815 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 947:

/* Line 678 of lalr1.cc  */
#line 6816 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 948:

/* Line 678 of lalr1.cc  */
#line 6817 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 949:

/* Line 678 of lalr1.cc  */
#line 6818 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 950:

/* Line 678 of lalr1.cc  */
#line 6819 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 951:

/* Line 678 of lalr1.cc  */
#line 6820 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 952:

/* Line 678 of lalr1.cc  */
#line 6821 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 953:

/* Line 678 of lalr1.cc  */
#line 6822 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 954:

/* Line 678 of lalr1.cc  */
#line 6823 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 955:

/* Line 678 of lalr1.cc  */
#line 6824 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 956:

/* Line 678 of lalr1.cc  */
#line 6825 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 957:

/* Line 678 of lalr1.cc  */
#line 6826 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 958:

/* Line 678 of lalr1.cc  */
#line 6827 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 959:

/* Line 678 of lalr1.cc  */
#line 6828 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 960:

/* Line 678 of lalr1.cc  */
#line 6829 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 961:

/* Line 678 of lalr1.cc  */
#line 6830 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 962:

/* Line 678 of lalr1.cc  */
#line 6831 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 963:

/* Line 678 of lalr1.cc  */
#line 6832 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 964:

/* Line 678 of lalr1.cc  */
#line 6833 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 965:

/* Line 678 of lalr1.cc  */
#line 6834 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 966:

/* Line 678 of lalr1.cc  */
#line 6835 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 967:

/* Line 678 of lalr1.cc  */
#line 6836 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 968:

/* Line 678 of lalr1.cc  */
#line 6837 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 969:

/* Line 678 of lalr1.cc  */
#line 6838 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 970:

/* Line 678 of lalr1.cc  */
#line 6839 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 971:

/* Line 678 of lalr1.cc  */
#line 6840 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 972:

/* Line 678 of lalr1.cc  */
#line 6841 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 973:

/* Line 678 of lalr1.cc  */
#line 6842 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 974:

/* Line 678 of lalr1.cc  */
#line 6843 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 975:

/* Line 678 of lalr1.cc  */
#line 6844 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 976:

/* Line 678 of lalr1.cc  */
#line 6845 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 977:

/* Line 678 of lalr1.cc  */
#line 6846 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 978:

/* Line 678 of lalr1.cc  */
#line 6847 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 979:

/* Line 678 of lalr1.cc  */
#line 6848 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 980:

/* Line 678 of lalr1.cc  */
#line 6849 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 981:

/* Line 678 of lalr1.cc  */
#line 6850 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 982:

/* Line 678 of lalr1.cc  */
#line 6851 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 983:

/* Line 678 of lalr1.cc  */
#line 6852 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 984:

/* Line 678 of lalr1.cc  */
#line 6853 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 985:

/* Line 678 of lalr1.cc  */
#line 6854 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 986:

/* Line 678 of lalr1.cc  */
#line 6855 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 987:

/* Line 678 of lalr1.cc  */
#line 6856 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 988:

/* Line 678 of lalr1.cc  */
#line 6857 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 989:

/* Line 678 of lalr1.cc  */
#line 6858 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 990:

/* Line 678 of lalr1.cc  */
#line 6859 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 991:

/* Line 678 of lalr1.cc  */
#line 6860 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 992:

/* Line 678 of lalr1.cc  */
#line 6861 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 993:

/* Line 678 of lalr1.cc  */
#line 6862 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 994:

/* Line 678 of lalr1.cc  */
#line 6863 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 995:

/* Line 678 of lalr1.cc  */
#line 6864 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 996:

/* Line 678 of lalr1.cc  */
#line 6865 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 997:

/* Line 678 of lalr1.cc  */
#line 6866 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 998:

/* Line 678 of lalr1.cc  */
#line 6867 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 999:

/* Line 678 of lalr1.cc  */
#line 6868 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1000:

/* Line 678 of lalr1.cc  */
#line 6869 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1001:

/* Line 678 of lalr1.cc  */
#line 6870 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1002:

/* Line 678 of lalr1.cc  */
#line 6871 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1003:

/* Line 678 of lalr1.cc  */
#line 6872 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 1004:

/* Line 678 of lalr1.cc  */
#line 6873 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 1005:

/* Line 678 of lalr1.cc  */
#line 6874 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1006:

/* Line 678 of lalr1.cc  */
#line 6875 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 1007:

/* Line 678 of lalr1.cc  */
#line 6876 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 1008:

/* Line 678 of lalr1.cc  */
#line 6877 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 1009:

/* Line 678 of lalr1.cc  */
#line 6878 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 1010:

/* Line 678 of lalr1.cc  */
#line 6883 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 678 of lalr1.cc  */
#line 12123 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1480;
  const short int
  xquery_parser::yypact_[] =
  {
      3375, -1480, -1480, -1480,  5233,  5233,  5233, -1480, -1480,    68,
     248, -1480,   391,   352, -1480, -1480, -1480,   776, -1480, -1480,
   -1480,   390,   446,   780,  3095,   488,   592,   812, -1480,   -13,
   -1480, -1480, -1480, -1480, -1480, -1480,   819, -1480,   614,   679,
   -1480, -1480, -1480, -1480,    87, -1480,   820, -1480,   704,   739,
   -1480,   156, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480,
   -1480, -1480, -1480, -1480, -1480, -1480,    75,   561, -1480, -1480,
   -1480, -1480,   692, 11104, -1480, -1480, -1480,   781, -1480, -1480,
   -1480,   794, -1480,   803,   846, -1480, -1480, 15476, -1480, -1480,
   -1480, -1480, -1480, -1480, -1480, -1480,   856, -1480, -1480,   863,
     889, -1480, -1480, -1480, -1480, -1480, -1480, -1480,  3997,  7087,
    7396, 15476, -1480, -1480, -1480, -1480, -1480, -1480, -1480,   860,
   -1480, -1480,   892, 11996, -1480, 12298,   893,   894, -1480, -1480,
   -1480,   896, -1480, 10486, -1480, -1480, -1480, -1480, -1480, -1480,
     866, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480,    79,
     805, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480,   -80,
     865,   -76, -1480,   -92,   -68, -1480, -1480, -1480, -1480, -1480,
   -1480,   904, -1480,   783,   784,   787, -1480, -1480,   869,   876,
   -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480,
   -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480,
   -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480,
   -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480,
   -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480,
   -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480,
   -1480, -1480, -1480,  7705,  8014, -1480,   718, -1480, -1480, -1480,
   -1480, -1480,  3686,  5542,  1032, -1480,  5851, -1480, -1480,   375,
     114, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480,
   -1480, -1480, -1480, -1480, -1480,   120, -1480, -1480, -1480, -1480,
   -1480, -1480,   146, -1480, -1480, -1480, -1480, -1480, -1480, -1480,
   -1480,  5233, -1480, -1480, -1480, -1480,    40, -1480, -1480, -1480,
   -1480, -1480, -1480, -1480, -1480,   926, -1480,   844, -1480, -1480,
   -1480,   519, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480,
     868,   944, -1480,   758,   789,   940,   229,   634,   221,    76,
   -1480,   988,   841,   941,   943,  9250, -1480, -1480, -1480,    32,
   -1480, -1480, 10795, -1480,   775, -1480,   887, 11104, -1480,   887,
   11104, -1480, -1480, -1480,   385, -1480, -1480, -1480, -1480, -1480,
   -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480,
   -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480,
   -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480,
   -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480,
   -1480, -1480, -1480, -1480, -1480, -1480,   898,   890, -1480, -1480,
   -1480, -1480, -1480,   864, -1480,  5233,   867,   870,   101,   101,
    1018,   675,   715,   509, 15763, 15476,   241,  1002, 15476,   905,
     938,   452, 11996,   736,   813, 15476, 15476,   756,   560,    64,
   -1480, -1480, -1480, 11996,  5233,   873,  5233,   138,  9559, 13180,
   15476, -1480,   782,   786, 15476,   945,   266,   908,  9559,  1069,
     124,   105, 15476,   953,   930,   966, -1480,  9559, 11700, 15476,
   15476, 15476,  5233,   888,  9559,  9559, 15476,  5233,   921,   923,
   -1480, -1480, -1480,  9559, 13467,   922, -1480,   924, -1480, -1480,
   -1480, -1480,   925, -1480,   927, -1480, -1480, -1480, -1480, -1480,
     928, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480,
   -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480,
   -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, 15476,
   -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480,
   -1480, -1480,   935, 15476, -1480, -1480, -1480,   895,  4306,   961,
     238,   929,   931,   932, 15476,  5233, -1480,   933,   231, -1480,
     615, -1480,    44,  1054,  9559, -1480, -1480,    99, -1480, -1480,
   -1480,  1073, -1480, -1480, -1480, -1480,  9559,   880, -1480,  1065,
    9559,  9559, 12597,   910,  9559,  9559,   824,  9559, 12597,  9559,
     871,   874, 15476,   912,   914,  9559,  9559,  3997,   851, -1480,
     -22, -1480,   -18,   951,  5542, -1480, -1480, -1480, -1480, -1480,
     391,   812,   122,   123,  1095,  6160,  6160,  6469,  6469,   794,
   -1480, -1480,   926,   794, -1480,  9559, -1480,   991,   410,   -13,
     942,   947,   949,  5233,  9559, -1480, -1480, -1480, -1480, -1480,
   -1480, -1480, -1480,  9868,  9868,  9868, -1480,  9868,  9868, -1480,
    9868, -1480,  9868, -1480, -1480, -1480, -1480, -1480, -1480, -1480,
    9868,  9868,  1041,  9868,  9868,  9868,  9868,  9868,  9868,  9868,
    9868,  9868,  9868,  9868,  9868,   882,  1019,  1026,  1027, -1480,
   -1480, -1480,  8323, -1480, -1480, 10486, 10486,  9559,   887, -1480,
   -1480,   887, -1480,  8632,   887,   977,  8941, -1480, -1480, -1480,
     250, -1480,   256, -1480, -1480, -1480, -1480, -1480, -1480,  1020,
    1021,   488,  1100, -1480, -1480, 15763,   907,   683, 15476,   970,
     971,   907,  1018,  1005,  1001, -1480, -1480, -1480,   299,   897,
    1040,   837, 15476,   994,  9559,  1022, 15476, 15476, -1480,  1006,
     955,  5233, -1480,   957,   924,   679, -1480,   956,   958,   267,
   -1480,   263,   291,  1037, -1480,    46, -1480, -1480,  1037, 15476,
      18, 15476,  1052,   307, -1480,  5233, -1480,   319, -1480, 11996,
    1051,  1103, 11996,  1018,  1053,   639, 15476,  9559,   -13,   351,
     963, -1480,   964,   965,   967,    55, -1480,    69,   969, -1480,
     329,   338,  1003, -1480,   973,  5233,  5233,   407, -1480,   353,
     367,   649,  9559,   139, -1480, -1480,  9559,  9559, -1480,  9559,
    9559,  9559, -1480,  9559, -1480,  9559, -1480, 15476,  1054, -1480,
     520,   425, -1480, -1480, -1480,   427, -1480,   406, -1480, -1480,
    1007,  1008,  1009,  1010,  1011,   385,   898, -1480,   148,   150,
    9559,  9559,  1061,   612,   934,   948,   936,    51, -1480,  1016,
   -1480, -1480,   975,   372,  4615,   429, 11404,   851, -1480, -1480,
   -1480,  9559, -1480,   375,   817,  1134,  1134, -1480, -1480,   125,
   -1480, -1480,   126, -1480,    54, -1480, -1480, -1480, -1480, -1480,
   -1480, -1480, 15476,   998,  9559,  1056, -1480, -1480, -1480,   944,
   -1480, -1480, -1480, -1480, -1480,  9868, -1480, -1480, -1480,    15,
   -1480,   634,   634,    31,   221,   221,   221,   221,    76,    76,
   -1480, -1480, 14615, 14615, 15476, 15476, -1480,   479, -1480, -1480,
     281, -1480, -1480, -1480,   384, -1480, -1480,   386,   101, -1480,
   -1480,   254,   606,   518, -1480,   488, -1480, -1480, -1480, -1480,
   -1480, -1480, -1480, -1480, -1480, -1480,   907, -1480,  1039, 14902,
    1033,  9559, -1480, -1480, -1480,  1075,  1018,  1018,   907, -1480,
     852,  1018,   663, 15476,   501,   645,  1147, -1480, -1480,   899,
     613, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480,
   -1480, -1480,   299,    25,   952,   400,  9559, -1480, 15476,  1083,
     881,  1018, -1480, -1480, -1480, -1480,  1028, 15476, -1480, 15476,
   -1480, 15189,  1055, 14615,  1062,  9559,    -2,  1036,    47,   453,
     937, -1480, -1480,   660,    18,  1075, 14615,  1067,  1092,  1004,
     990,  1057,  1018,  1031,  1060,  1097,  1018,  9559,    45, -1480,
   -1480, -1480,  1042, -1480, -1480, -1480, -1480,  1076,  9559,  9559,
    1049, -1480,  1099,  1101,  5233, -1480,  1013,  1024,  1047, 15476,
   -1480, 15476, -1480,  9559,  1063,  1012,  9559, -1480,  1082,   402,
     416,   420,  1169, -1480,   535, -1480,    83, -1480, -1480,  1177,
   -1480,   577,  9559,  9559,  9559,   650,  9559,  9559,  9559,   961,
     492,   313,  9559,  9559,  9559,  9559, 12597,  1094,  9559,  9559,
   -1480,  6778,  1058,  1059,  1064,  1066,   844,   681,   972, -1480,
       6, -1480,   333,   134,   141,    54,  6469,  6469,  6469,  1131,
   -1480,  9559,   778,  1110, -1480, 15476,  1111, -1480, -1480,  9559,
      15,   315,    37, -1480,   946,    78,   968,   974, -1480, -1480,
     813, -1480,   962,   489,  1068,  1071, 14902,  1078,  1079,  1081,
    1084,  1085, -1480,   568, -1480, -1480, -1480, -1480, -1480, -1480,
   -1480, -1480, -1480, -1480, -1480, -1480, -1480,  1087, -1480, -1480,
   -1480,  9559, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480,
   -1480,   726, -1480,  1193,   727, -1480, -1480, -1480, -1480, -1480,
   -1480, -1480, -1480, -1480,   954, -1480, -1480,  1194, -1480, -1480,
   -1480, -1480, -1480,   644,  1209, -1480,    88, -1480, -1480, -1480,
     922,   446,   925,   614,   927,   928,   865,  1079,  1081,  1084,
   -1480,   568,   568, 10177,   959,   950, -1480,  1075,    25,  1017,
    1070,  5233,  1077,  1080,  1098,  1086,  1088, 15476, -1480,    73,
   -1480, 15476, -1480,  9559,  1104,  9559,  1119,  9559,    56,  1105,
    9559,  1106, -1480,  1136,  1138,  9559, 15476,   891,  1181, -1480,
   -1480, -1480, -1480, -1480, -1480, 14615, -1480,  5233,  1018,  1155,
   -1480, -1480, -1480,  1018,  1155, -1480,  9559,  1121,  5233, 15476,
   -1480, -1480,  9559,  9559,   804, -1480,    41,   806, -1480, 13754,
     811, -1480,   814, -1480,  1090, -1480, -1480,  5233,  1091,  1093,
   -1480,  9559, -1480, -1480,  9559,  1072,  1099,  1166, -1480,  1139,
   -1480,   585, -1480, -1480,  1263, -1480, -1480,  5233, 15476, -1480,
     659, -1480, -1480, -1480,  1102,  1045,  1050, -1480, -1480, -1480,
    1074,  1089, -1480, -1480, -1480,  1096,  1109, -1480, -1480, -1480,
    1048,   225, 15476,  1107, -1480, -1480,  9559,  9559,  9559,  4924,
    6778, 11404,   972, -1480, 11404, -1480,  1113,  1134,   328, -1480,
   -1480, -1480,  1110, -1480,  1018, -1480,   855, -1480,   285,  1175,
   -1480,  9559,   738,  1056,   527,  1112, -1480,    15,  1023, -1480,
   -1480,   -36, -1480,   656,    81,  1034,    15,   656,  9868, -1480,
     100, -1480, -1480, -1480, -1480, -1480, -1480,    15,  1141,  1038,
     897,    81, -1480, -1480,  1000,  1212, -1480, -1480, -1480, 12893,
    1114,  1115,  1116,  1117,  1118,  1122,  1125, -1480, -1480, -1480,
   -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480,  1265,
     546,  1271,   546,  1043,  1201, -1480, -1480,  1144, 15476,  1124,
   -1480, -1480, 10177, -1480,  1133, -1480, -1480, -1480, -1480, -1480,
   -1480,  9559,  1173, -1480, -1480,  9559, -1480,    92, -1480,  9559,
    1176,  9559, -1480,  9559, 15476, 15476, -1480,   732, -1480,  9559,
   -1480,  1196,  1198,  1230,  1018,  1155, -1480,  9559,  1143, -1480,
   -1480, -1480,  1145, -1480,    49,  9559,  5233,  1146,    52, -1480,
   15476,  1148, 14041,    42, -1480, 14328,  1149, -1480, -1480,  1152,
   -1480, -1480, -1480, -1480,  9559,   821,  1169, 15476,   664, -1480,
    1153,  1169, 15476, -1480, -1480,  9559,  9559,  9559,  9559,  9559,
    9559,  9559,  9559, -1480,  9559,   435,   445,   467,   419, -1480,
   -1480,  9559, -1480, -1480, -1480,  1175, -1480, -1480, -1480,  1018,
    9559, -1480,  1187, -1480, -1480, -1480, -1480,  1154,  9868, -1480,
   -1480, -1480, -1480, -1480,    84,  9868,  9868,   593, -1480,   968,
   -1480,   188, -1480,   974,    15,  1180, -1480, -1480,  1108, -1480,
   -1480, -1480, -1480,  1248,  1156, -1480,   475, -1480, -1480, -1480,
   -1480, -1480, -1480, -1480, -1480,    95,    95, -1480,   546, -1480,
   -1480,   483, -1480,  1315,    81,  1249,  1162, 10177,   -20,  1120,
    1182, -1480, -1480,  9559, -1480,  9559,  1204, -1480,  9559, -1480,
   -1480, -1480,  1300, -1480, -1480,  6778,  9559,  1018, -1480, -1480,
   -1480,  9559,  9559, -1480, -1480, -1480,  6778,  6778,  1260,  5233,
   15476,  1170, 15476,  9559, 15476,  1171,  6778, -1480,   331,    36,
    1169, 15476, -1480,  1159,  1169, -1480, -1480, -1480, -1480, -1480,
    1262, -1480, -1480, -1480,  1163,  1099,  1101,  9559, -1480, -1480,
   -1480, -1480,  1253,  9559, -1480,   221,  9868,  9868,    31,   698,
   -1480, -1480, -1480, -1480, -1480, -1480,  9559, -1480, 14615, -1480,
   14615,  1267, -1480, -1480, -1480,  1333, -1480, -1480, -1480,  1126,
    1259, -1480, -1480,  1261, -1480,   623, 15476,  1251,  1157, 15476,
   10177, -1480, -1480,  9559, -1480,  1252, -1480, -1480,  1155, -1480,
   -1480, 14615, -1480, -1480,  1278,  9559,  1192, -1480,  1279,  6778,
   -1480, 15476,   622,   496, -1480,  1188,  1169, -1480,  1189,  1123,
    6778,   822,   530, -1480,  1253,    31,    31,  9868,   541, -1480,
   -1480, 14615, -1480, -1480,  1249, 10177, -1480,  1175,  1127, 15476,
    1273,  1168,  1261, -1480, 15476,  1197, 14615,  5233, 14615,  1208,
   -1480, -1480,  1302,   690, -1480, -1480, -1480, -1480,  1213,   706,
   -1480, -1480, -1480,  1202, -1480,  9559,  1281, -1480, -1480,    31,
   -1480, -1480, -1480, -1480, -1480,  9559,  1128, 15476,  1282, -1480,
    5233,  1211, -1480, -1480,  1216,  9559, -1480, -1480, -1480, -1480,
   -1480, -1480, -1480, -1480, 15476, -1480,  1129,  1130, 15476, -1480,
   -1480,  9559,  6778,  1217,  1135,  9559,  1137,  6778, 10177, -1480,
   10177, -1480,  1206,  1132, 15476,  1190,  1287, 15476,  1140, 10177,
   -1480
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       163,   456,   457,   458,   166,   166,   166,   805,  1010,   118,
     120,   612,   897,   906,   846,   810,   808,   790,   898,   901,
     853,   814,   791,   792,     0,   907,   794,   904,   875,   855,
     830,   850,   851,   902,   899,   849,   796,   905,   797,   798,
     946,   958,   945,   847,   866,   860,   799,   848,   801,   800,
     947,   884,   885,   852,   827,   968,   969,   970,   971,   972,
     973,   974,   975,   976,   977,   978,   992,   999,   874,   870,
     861,   841,   789,     0,   869,   877,   886,   993,   865,   482,
     842,   843,   900,   994,  1000,   862,   879,     0,   488,   445,
     484,   872,   807,   863,   864,   893,   867,   883,   892,   998,
    1001,   813,   854,   895,   483,   882,   888,   793,     0,     0,
       0,     0,   393,   880,   891,   896,   894,   873,   859,   948,
     857,   858,   995,     0,   392,     0,   996,  1002,   889,   844,
     868,   997,   423,     0,   455,   890,   871,   878,   887,   881,
     949,   835,   840,   839,   838,   837,   836,   802,   856,     0,
     806,   903,   828,   937,   936,   938,   812,   811,   831,   943,
     795,   935,   940,   941,   932,   834,   876,   934,   944,   942,
     933,   832,   939,   953,   954,   951,   952,   950,   803,   955,
     956,   957,   923,   922,   909,   826,   819,   916,   912,   829,
     825,   924,   925,   815,   816,   809,   818,   921,   920,   917,
     913,   930,   931,   929,   919,   915,   908,   817,   928,   927,
     821,   823,   822,   914,   918,   910,   824,   911,   820,   926,
     979,   980,   981,   982,   983,   984,   960,   961,   959,   965,
     966,   967,   962,   963,   964,   833,   985,   986,   987,   988,
     989,   990,   991,     0,     0,  1003,  1004,  1005,  1008,  1007,
    1006,  1009,   163,   163,     0,     2,   163,     7,     9,    21,
       0,    26,    29,    34,    35,    36,    37,    38,    39,    40,
      30,    56,    57,    31,    32,     0,    74,    77,    78,    33,
      79,    80,     0,   116,    81,    82,    83,    84,    16,   160,
     161,   162,   169,   171,   475,   172,     0,   173,   174,   175,
     176,   177,   178,   179,   182,   167,   208,   215,   210,   242,
     248,     0,   240,   241,   217,   211,   181,   212,   180,   213,
     216,   346,   348,   350,   360,   362,   366,   368,   371,   376,
     379,   382,   384,   386,   388,     0,   390,   396,   398,     0,
     414,   397,   419,   422,   424,   427,   429,     0,   434,   431,
       0,   442,   452,   454,   428,   459,   466,   480,   467,   468,
     469,   472,   473,   470,   471,   495,   497,   498,   499,   496,
     544,   545,   546,   547,   548,   549,   451,   586,   578,   585,
     584,   583,   580,   582,   579,   581,   481,   474,   613,   614,
      41,   218,   219,   221,   220,   222,   214,   477,   478,   479,
     476,   224,   227,   223,   225,   226,   453,   788,   804,   897,
     906,   904,   806,     0,   164,   165,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     124,   126,   127,     0,     0,     0,     0,     0,     0,     0,
       0,   252,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   270,   271,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     447,   450,   437,     0,     0,   790,   814,   792,   845,   907,
     794,   855,   796,   866,   799,   801,   800,   884,   992,   999,
     789,   993,   843,   994,  1000,   867,   998,  1001,   948,   995,
     996,  1002,   997,   949,   943,   935,   941,   932,   832,   953,
     954,   951,   803,   955,  1004,   443,   453,   788,   435,     0,
     189,   436,   439,   790,   791,   792,   796,   797,   798,   799,
     789,   795,   485,     0,   441,   440,   184,     0,     0,   208,
       0,   794,   801,   800,     0,   166,   764,   955,     0,   215,
       0,   486,     0,   511,     0,   446,   786,     0,   787,   417,
     418,     0,   449,   448,   438,   421,     0,     0,   540,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   766,
       0,   768,     0,     0,   163,     3,     4,     1,     8,    10,
       0,     0,     0,     0,     0,   163,   163,   163,   163,     0,
     117,   170,   168,     0,   187,     0,   196,     0,     0,     0,
       0,     0,     0,     0,     0,   201,   228,   247,   243,   249,
     244,   246,   245,     0,     0,     0,   407,     0,     0,   405,
       0,   355,     0,   406,   399,   404,   403,   402,   401,   400,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   395,
     394,   391,     0,   415,   420,     0,     0,     0,   430,   463,
     433,   432,   444,     0,   460,     0,     0,   551,   553,   557,
       0,   122,     0,   785,    45,    42,    43,    46,    47,     0,
       0,     0,     0,    48,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   623,   624,   625,     0,   101,
     140,     0,     0,   110,     0,     0,     0,     0,   125,     0,
       0,     0,   592,     0,     0,     0,   588,     0,     0,     0,
     602,     0,     0,   251,   253,     0,   230,   231,   250,     0,
       0,     0,   132,     0,   136,   166,   616,     0,    58,     0,
      67,     0,     0,     0,    59,     0,     0,     0,     0,     0,
       0,   593,     0,     0,     0,     0,   319,     0,     0,   591,
       0,     0,     0,   610,     0,     0,     0,     0,   596,     0,
       0,   191,     0,     0,   185,   183,     0,     0,   770,     0,
       0,     0,   485,     0,   765,     0,   487,   512,   511,   508,
       0,     0,   542,   541,   416,     0,   539,     0,   636,   637,
     790,   792,   796,   799,   789,   776,     0,   587,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   642,     0,
     199,   200,     0,     0,     0,     0,     0,   204,   205,   767,
     769,     0,     5,    22,     0,    23,     0,     6,    27,     0,
      13,    28,     0,    17,   897,    75,    14,    76,    18,   190,
     188,   209,     0,     0,     0,     0,   202,   229,   288,   347,
     349,   353,   359,   358,   357,     0,   354,   351,   352,     0,
     363,   370,   369,   367,   373,   374,   375,   372,   377,   378,
     381,   380,     0,     0,     0,     0,   412,     0,   425,   426,
       0,   464,   461,   493,     0,   615,   491,     0,     0,   119,
     121,     0,     0,     0,   100,     0,    90,    92,    93,    94,
      95,    97,    98,    99,    91,    96,    86,    87,     0,     0,
     106,     0,   102,   104,   105,   112,     0,     0,    85,    44,
       0,     0,     0,     0,     0,     0,     0,   714,   719,     0,
       0,   715,   749,   702,   704,   705,   706,   708,   710,   709,
     707,   711,     0,     0,     0,     0,     0,   109,     0,   142,
       0,     0,   556,   550,   589,   590,     0,     0,   606,     0,
     603,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   232,   233,     0,   238,   138,     0,     0,   133,     0,
       0,     0,     0,     0,     0,    60,     0,     0,     0,   269,
     275,   272,     0,   595,   594,   601,   609,     0,     0,     0,
       0,   555,     0,     0,     0,   408,     0,     0,     0,     0,
     599,     0,   597,     0,   192,     0,     0,   771,     0,     0,
       0,     0,   511,   509,     0,   500,     0,   489,   490,     0,
      11,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     197,     0,   794,   801,   800,   955,     0,     0,     0,   650,
       0,   206,     0,     0,     0,     0,   163,   163,   163,     0,
     239,     0,   303,   299,   301,     0,   289,   290,   356,     0,
       0,     0,     0,   680,   364,   653,   657,   659,   661,   663,
     666,   673,   674,   682,   907,   793,     0,   802,  1008,  1007,
    1006,  1009,   383,   562,   568,   569,   572,   617,   618,   573,
     574,   779,   780,   781,   577,   385,   387,   559,   389,   413,
     465,     0,   462,   492,   123,    54,    55,    52,    53,   129,
     128,     0,    88,     0,     0,   107,   108,   113,    72,    73,
      50,    51,    71,   720,     0,   723,   750,     0,   713,   712,
     717,   716,   748,     0,     0,   725,     0,   721,   724,   703,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,   144,   146,     0,     0,     0,   111,   114,     0,     0,
       0,   166,     0,     0,   610,     0,     0,     0,   255,     0,
     561,     0,   256,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   234,     0,     0,     0,     0,   282,     0,   279,
     284,   237,   139,   134,   137,     0,   186,     0,     0,    69,
      63,    66,    65,     0,    61,   273,     0,     0,   166,     0,
     317,   321,     0,     0,     0,   324,     0,     0,   330,     0,
       0,   337,     0,   341,     0,   410,   409,   166,     0,     0,
     193,     0,   195,   318,     0,     0,     0,     0,   512,     0,
     501,     0,   535,   532,     0,   536,   537,     0,     0,   531,
       0,   506,   534,   533,     0,     0,     0,   629,   630,   626,
       0,     0,   634,   635,   631,     0,     0,   640,   777,   638,
       0,     0,     0,     0,   644,   198,     0,     0,     0,     0,
       0,     0,   645,   646,     0,   207,     0,    24,     0,    15,
      19,    20,   300,   312,     0,   313,     0,   304,   305,   306,
     307,     0,   292,     0,     0,     0,   664,   677,     0,   361,
     365,     0,   696,     0,     0,     0,     0,     0,     0,   652,
     654,   655,   691,   692,   693,   695,   694,     0,     0,   668,
     667,     0,   671,   675,   689,   687,   686,   679,   683,     0,
       0,     0,     0,     0,     0,     0,     0,   565,   567,   566,
     563,   560,   494,   131,   130,    89,   103,   737,   718,     0,
     742,     0,   742,   731,   726,   145,   147,     0,     0,     0,
     115,   143,     0,    25,     0,   607,   608,   611,   604,   605,
     254,     0,     0,   268,   260,     0,   264,     0,   258,     0,
       0,     0,   277,     0,     0,     0,   236,   280,   283,     0,
     135,     0,     0,    68,     0,    62,   274,     0,     0,   320,
     322,   327,     0,   325,     0,     0,     0,     0,     0,   331,
       0,     0,     0,     0,   338,     0,     0,   342,   411,     0,
     600,   598,   194,   772,     0,     0,   511,     0,     0,   543,
       0,   511,     0,   507,    12,     0,     0,     0,     0,     0,
       0,     0,     0,   643,     0,     0,     0,     0,     0,   647,
     651,     0,   316,   314,   315,   308,   309,   310,   302,     0,
       0,   297,     0,   291,   681,   672,   678,     0,     0,   751,
     752,   762,   761,   760,     0,     0,     0,     0,   753,   658,
     759,     0,   656,   660,     0,     0,   665,   669,     0,   690,
     685,   688,   684,     0,     0,   575,     0,   570,   622,   564,
     783,   784,   782,   571,   738,     0,     0,   736,   743,   744,
     740,     0,   735,     0,   733,     0,     0,     0,     0,     0,
       0,   552,   257,     0,   266,     0,     0,   262,     0,   265,
     278,   286,   287,   281,   235,     0,     0,     0,    64,   276,
     558,     0,     0,   328,   332,   326,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   554,     0,     0,
     511,     0,   538,     0,   511,   627,   628,   632,   633,   773,
       0,   639,   778,   641,     0,     0,     0,     0,   648,   775,
     311,   298,   293,     0,   676,   763,     0,     0,   755,     0,
     701,   700,   699,   698,   697,   662,     0,   754,     0,   619,
       0,     0,   747,   746,   745,     0,   739,   732,   730,     0,
     727,   728,   722,   148,   150,   152,     0,     0,     0,     0,
       0,   261,   259,     0,   267,     0,   203,   345,    70,   323,
     329,     0,   343,   339,     0,     0,     0,   333,     0,     0,
     335,     0,   521,   515,   510,     0,   511,   502,     0,     0,
       0,     0,     0,   296,   294,   757,   756,     0,     0,   620,
     576,     0,   741,   734,     0,     0,   154,   153,     0,     0,
       0,     0,   149,   263,     0,     0,     0,     0,     0,     0,
     529,   523,     0,   522,   524,   530,   527,   517,     0,   516,
     518,   528,   504,     0,   503,     0,     0,   649,   295,   758,
     670,   621,   729,   151,   155,     0,     0,     0,     0,   285,
       0,     0,   336,   334,     0,     0,   514,   525,   526,   513,
     519,   520,   505,   774,     0,   156,     0,     0,     0,   344,
     340,     0,     0,     0,     0,     0,     0,     0,     0,   158,
       0,   157,     0,     0,     0,     0,     0,     0,     0,     0,
     159
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1480, -1480,  -222,  -197, -1480,  1160,  1161, -1480,  1165,  -541,
   -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480,
   -1015, -1480, -1480, -1480, -1480,  -220,  -587, -1480,   691,  -147,
   -1480, -1480, -1480, -1480, -1480,   237,   463, -1480, -1480,    -9,
    -164,  1014, -1480,   980, -1480, -1480,  -639, -1480,   403, -1480,
     204, -1480,  -265,  -309, -1480,  -539, -1480,    29,    23,    11,
    -240,  -169, -1480,  -868, -1480, -1480,  -424, -1480, -1480, -1480,
   -1480, -1480, -1480, -1480, -1480, -1480, -1480,   570,   -89,  1418,
       0, -1480, -1480, -1480, -1480,   414, -1480, -1480,  -292, -1480,
       8, -1480,   976,  -913,  -719,  -708, -1480, -1480,   651, -1480,
   -1480,   -21,   192, -1480, -1480, -1480,    72, -1137, -1480,   336,
      82, -1480, -1480,    86, -1296, -1480,   903,   179, -1480, -1480,
     175, -1005, -1480, -1480,   173, -1480, -1480, -1254, -1232, -1480,
     169, -1480, -1480,   809,   810, -1480,  -548,   790, -1480, -1480,
    -659,   335,  -645,   330,   332, -1480, -1480, -1480, -1480, -1480,
    1142, -1480, -1480, -1480, -1480,  -854,  -313, -1152, -1480,  -101,
   -1480, -1480, -1480, -1480, -1480, -1480, -1480,   -16,  -815, -1480,
    -542,    57,   260, -1480,  -417, -1480, -1480, -1480, -1480, -1480,
   -1480, -1480,   759, -1480, -1008, -1480,   157, -1480,   641,  -800,
   -1480, -1480, -1480, -1480, -1480,  -302,  -293, -1193,  -871, -1480,
   -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480,   547,
    -733,  -793,  -208,  -855, -1480,    93,  -846, -1480, -1480, -1480,
   -1480, -1480, -1480, -1480,  1025,  1044,  -160,   462,   290, -1480,
   -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480,
   -1480, -1480, -1480,   132, -1480, -1480,   128, -1480,   130, -1061,
   -1480, -1480, -1480,    90,    80,   -81,   354, -1480, -1480, -1480,
   -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480, -1480,
      94, -1480, -1480, -1480,   -73,   355,   499, -1480, -1480, -1480,
   -1480, -1480,   287, -1480, -1480, -1479, -1480, -1480, -1480,  -566,
   -1480,    65, -1480,   -90, -1480, -1480, -1480, -1480, -1277, -1480,
     109, -1480, -1480, -1480, -1480, -1480,   652, -1480, -1480, -1480,
   -1480, -1480,  -931, -1480, -1480, -1480,  -411,  -372,   210,   939,
   -1480
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   254,   866,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
    1259,   773,   272,   273,   274,   275,   276,   277,   946,   947,
     948,   278,   279,   280,   952,   953,   954,   281,   438,   282,
     283,   700,   284,   440,   441,   442,   457,   763,   764,   285,
    1210,   286,  1683,  1684,   287,   288,   289,   547,   290,   291,
     292,   293,   294,   766,   295,   296,   530,   297,   298,   299,
     300,   301,   302,   635,   303,   304,   857,   858,   305,   306,
     559,   308,   636,   455,  1013,  1014,   309,   637,   310,   639,
     560,   312,   753,   754,  1247,   464,   313,   465,   466,   760,
    1248,  1249,  1250,   640,   641,  1116,  1117,  1531,   642,  1113,
    1114,  1357,  1358,  1359,  1360,   314,   785,   786,   315,  1274,
    1275,  1474,   316,  1277,  1278,   317,   318,  1280,  1281,  1282,
    1283,   319,   320,   321,   322,   895,   323,   324,  1369,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   660,   661,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   694,   689,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   924,   364,   365,   366,  1310,   818,   819,   820,
    1714,  1758,  1759,  1752,  1753,  1760,  1754,  1311,  1312,   367,
     368,  1313,   369,   370,   371,   372,   373,   374,   375,  1156,
    1008,  1142,  1410,  1143,  1566,  1144,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   792,  1223,   386,   387,
     388,   389,  1146,  1147,  1148,  1149,   390,   391,   392,   393,
     394,   395,   847,   848,   396,  1342,  1343,  1648,  1100,  1124,
    1379,  1380,  1125,  1126,  1127,  1128,  1129,  1389,  1556,  1557,
    1130,  1392,  1131,  1537,  1132,  1133,  1397,  1398,  1562,  1560,
    1381,  1382,  1383,  1384,  1663,   729,   973,   974,   975,   976,
     977,   978,  1197,  1586,  1680,  1198,  1584,  1678,   979,  1422,
    1581,  1577,  1578,  1579,   980,   981,  1385,  1393,  1547,  1386,
    1543,  1370,   397,   398,   399,   400,   550,   401,   402,   403,
     404,   405,  1150,  1151,  1152,  1153,  1260,   567,   406,   407,
     408
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int xquery_parser::yytable_ninf_ = -846;
  const short int
  xquery_parser::yytable_[] =
  {
       307,   701,   701,   439,   307,   307,   307,   903,   311,   704,
     598,  1264,   311,   311,   311,   415,   415,   415,  1064,   638,
     558,   562,   904,   905,   906,   907,   683,   414,   414,   414,
     875,   877,   575,   413,   416,   417,  1006,  1276,   616,   613,
     835,  1099,  1028,  1495,    11,  1122,   843,  1007,  1484,   770,
     774,   621,  1212,   618,  1040,   605,   606,   525,  1309,  1365,
     724,  1427,  1526,  1527,  1200,  1170,  1145,  1145,  1054,  1201,
     744,   739,   933,  1010,   868,   871,   870,   873,   876,   878,
       9,    10,  1002,  1236,  1202,   625,  1203,   745,  1228,   625,
       9,    10,  1302,  1303,  1174,  1204,   782,   891,  1686,   892,
     893,   424,   894,  1145,   896,   462,  1681,   822,   307,   577,
     425,   424,   897,   898,  1558,   614,   311,  1503,   620,   548,
    1155,   614,  1205,   614,   614,    79,   614,   614,   427,  1712,
      11,   414,   587,   428,   703,   614,  1656,  1211,   427,    90,
    1003,  1475,  1004,  1004,   580,  1233,   581,   623,   584,  1475,
     585,   625,  1475,   703,   600,   602,   589,  1145,  1087,  1339,
    1622,   590,  1037,  1003,   104,   429,   430,  1109,  1119,  1004,
    1145,  1120,     9,    10,  1371,   621,   735,  1544,   420,   421,
    1539,   422,   423,   744,  1194,   682,  1304,  1266,  1004,   664,
    1367,  1419,   125,  1005,  1237,   879,  1371,   480,   426,   880,
     745,  1195,   622,  1449,  1687,   471,  1305,   665,  1306,   125,
    1230,    79,   673,  1657,   125,  1344,  1039,  1540,   771,  1713,
    1441,   588,  1177,  1253,   418,    90,   674,  1476,  1623,  1650,
     624,   816,   476,   582,  1011,  1612,  1307,   586,  1617,  1595,
     111,   684,  1071,  1038,  1075,   591,  1037,  1372,  1465,  1206,
     104,  1421,   307,   307,  1348,  1772,   307,   123,   619,   463,
     311,   311,  1299,  1484,   311,   772,  1122,  1122,   638,  1372,
     463,  1012,  1478,  1121,   823,   620,  1241,  1308,   875,   877,
    1590,  1401,  1252,   526,   769,  1088,  1688,  1212,   859,  1238,
    1145,   307,   578,  1309,   860,   149,  1171,   542,  1234,   311,
    1239,   432,  1309,  1414,   615,  1503,  1536,  1679,   621,   477,
     617,   959,   863,   865,  1440,  1106,  1108,   463,   463,   463,
    1267,   563,   868,   871,  1347,   746,   622,  1056,   463,  1373,
    1374,   690,  1375,   568,   692,   571,  1545,  1546,   625,  1376,
     435,  1207,  1208,  1209,    11,   807,   664,  1118,   436,  1377,
     736,  1373,  1374,   962,  1375,   963,   437,   928,   737,   749,
     433,  1378,  1025,   928,   665,  1072,  1073,  1076,  1077,   767,
     997,  1377,  1211,   719,   625,   720,   478,   479,   779,   687,
    1074,   693,  1078,  1378,   761,   790,   791,   664,   625,  1736,
     864,  1354,  1721,   886,   797,   869,   872,  1021,   999,   964,
    1024,   434,  1165,   688,   419,   665,   691,   862,   610,  1145,
     713,   450,  1356,   451,  1017,   307,   814,     9,    10,  1166,
     625,   671,   808,   311,   611,    79,   625,   666,   420,   421,
     672,   422,   423,  1145,   722,  1685,   625,   929,   424,    90,
     625,  1774,   714,   930,   307,   625,   307,   425,   426,  1711,
     998,   996,   311,   762,   311,   741,  1660,   741,   625,   622,
    1049,  1512,  1460,  1661,   104,   427,  1160,   740,  1119,   743,
     428,  1120,   307,  1662,  1051,   821,   452,   307,  1000,   625,
     311,   453,  1123,   741,  1430,   311,  1481,   825,   741,  1484,
    1309,  1161,   125,  1161,  1018,   788,   723,   719,  1326,   720,
     794,   621,   429,   430,   431,  1302,  1020,   853,   855,   625,
    1442,  1164,   443,  1122,   625,  1723,  1042,  1623,  1346,   875,
     877,   875,  1122,   625,  1756,  1043,  1099,   625,   454,  1520,
    1450,   721,   625,  1122,   625,  1032,   625,  1069,  1685,   687,
    1050,   693,   625,   446,  1331,  1178,  1179,  1003,   307,   965,
    1182,   432,   625,  1145,  1052,   307,   311,   526,   722,  1091,
     526,   627,   966,   311,   967,   628,   415,  1349,  1350,  1351,
     629,  1162,  1647,  1163,   625,   968,   969,   970,   414,   971,
    1220,   972,  1670,  1685,   918,   919,   625,  1768,   630,  1295,
    1675,  1048,  1698,   917,  1302,  1303,  1070,   307,   920,   807,
    1240,   439,   447,  1296,   307,   311,  1565,  1297,   854,  1067,
     433,  1068,   311,  1098,   621,   307,   307,   307,   307,  1305,
     723,  1306,  1644,   311,   311,   311,   311,  1750,  1344,  1532,
    1757,  1302,  1645,   307,   625,   712,  1145,   625,   716,  1145,
    1478,   311,   568,  1103,   456,   730,   731,  1107,   625,  1307,
    1065,   434,   622,   568,  1646,  1169,  1811,   627,  1812,   752,
     755,   628,  1671,  1159,   755,  1300,   629,  1820,  1302,  1303,
    1676,   765,   775,  1302,  1303,   709,  1325,   435,   568,   783,
     784,   787,  1575,   481,   630,   436,   793,   631,  1304,  1621,
     632,   710,  1625,   437,   800,  1750,  1629,   733,  1214,  1302,
    1122,  1633,   734,  1123,  1123,   633,  1083,  1215,  1305,  1194,
    1306,  1534,  1407,  1243,  1767,  1302,  1066,  1003,  1244,  1551,
    1059,  1060,  1061,   627,   855,  1770,  1195,   628,  1596,  1354,
     634,  1301,   629,  1003,  1756,  1394,  1395,  1245,  1307,   801,
    1419,   307,   111,  1003,  1408,  1305,  1576,  1306,   458,   311,
     630,   667,  1081,   787,  1167,  1751,  1004,  1420,  1396,   123,
     875,  1409,  1304,  1188,   812,   307,   687,  1304,   693,  1196,
     469,  1168,  1102,   311,  1189,  1307,   415,   949,  1246,  1497,
     668,  1027,  1305,   631,  1306,  1243,   632,  1305,   414,  1306,
    1244,  1053,   836,   669,  1019,   307,   307,   149,   836,  1172,
    1421,   815,   849,   311,   311,   638,   741,   741,  1315,   683,
    1316,  1172,  1307,  1305,   482,  1306,   111,  1307,  1046,  1047,
     950,   111,  1145,  1787,  1145,   951,   634,   670,  1004,  1305,
    1715,  1306,  1003,   123,  1718,   470,   459,  1222,   123,  1225,
    1790,  1755,  1761,  1307,  1529,   483,   460,  1463,   484,   631,
    1104,  1335,   632,  1502,  1096,  1145,   664,   705,  1631,  1307,
     474,  1660,  1097,  1413,   950,   439,   611,  1340,  1661,   951,
     706,   149,   461,  1353,   665,  1729,   149,  1730,  1662,   765,
    1530,  1320,  1755,  1321,  1354,  1145,  1658,  1659,  1761,  1288,
     645,  1289,   634,  1655,  1355,   475,  1727,   707,   646,   647,
    1145,   648,  1145,   528,  1273,  1356,  1273,  1190,  1745,   649,
     708,  1482,   529,   650,  1485,   651,  1763,  1472,  1191,  1477,
     652,  1482,  1482,  1541,  1483,   531,   598,  1486,   955,   444,
    1542,  1345,   445,   448,  1628,  1766,   449,   653,  1771,  1183,
    1184,  1185,   985,  1522,  1243,  1186,   989,   990,   921,  1244,
    1123,   921,  1737,  1781,   921,  1784,   725,   726,   727,  1123,
     654,   655,   656,   657,   658,   659,   685,   686,   532,  1009,
    1123,  1015,   467,   472,   543,   468,   473,   840,   841,   568,
    1180,  1181,   568,  1523,  1524,   544,  1029,   936,   937,   938,
     939,   940,   941,   942,   943,   944,   945,  1725,  1726,   901,
     902,   908,   909,  1425,  1426,   910,   911,  1157,  1157,  1672,
    1673,   545,   527,   564,   565,   572,   573,  1461,   574,   576,
     579,   583,   592,   593,   594,   596,   527,  1062,   595,   597,
    1364,   603,   607,   625,   626,   643,   644,   662,   675,   663,
     676,   687,   677,   695,   307,   678,   696,   703,   697,   715,
     527,   698,   311,  1608,   699,   741,   718,   717,   728,   732,
     742,   765,   527,   759,   527,   756,   526,  1284,  1769,   757,
     768,   776,   777,   778,   795,   789,   796,   802,   445,   804,
     449,   468,   806,   473,   484,   809,   813,   810,   811,   817,
     824,  1096,  1110,   826,   827,   856,   439,   837,   867,  1097,
     886,   845,   850,   846,   851,   861,   307,   307,   307,   882,
     883,   899,   912,   913,   311,   311,   311,   884,  1651,   885,
     914,   915,  1154,  1154,  1154,  1154,   925,   931,   932,   934,
     956,   957,   960,   961,   983,   984,   986,  1123,   991,   992,
     988,   993,   982,   994,  1001,   995,  1016,  1022,  1023,  1026,
    1033,  1034,  1035,  1041,  1036,  1082,  1044,  1045,  1089,  1154,
     444,   448,   467,   472,   483,  1090,  1086,  1105,  1111,  1003,
    1084,  1173,  1085,  1187,  1115,   951,  1192,  1218,  1213,  1219,
    1231,  1221,  1229,  1235,  1193,   761,  1255,  1257,  1256,  1258,
    1242,  1261,  1262,  1263,  1269,  1268,  1272,  1285,  1217,  1273,
    1287,  1279,  1292,  1294,  1298,  1291,  1314,  1224,  1286,  1224,
     721,   755,  1332,  1154,  1336,  1337,  1341,  1361,  1363,  1339,
    1338,   307,    11,  1418,  1399,  1387,  1154,  1400,  1391,   311,
    1368,  1411,   415,  1388,  1402,  1403,  1614,  1404,  1423,  1417,
    1405,  1406,  1437,  1432,   414,  1428,  1447,  1515,  1516,  1517,
    1434,  1445,  1451,  1453,  1454,  1429,  1455,   307,  1459,   793,
    1433,   793,  1464,  1467,  1435,   311,  1482,  1436,   307,  1494,
    1499,  1496,  1538,  1438,  1488,  1439,   311,  1505,  1490,   415,
    1491,  1354,  1506,  1548,  1511,  1559,   527,   307,  1554,   527,
    1561,   414,  1504,  1514,  1574,   311,   836,  1468,   415,  1535,
    1580,  1567,  1568,  1569,  1570,  1571,  1507,   307,  1585,  1572,
     414,  1521,  1573,  1583,  1587,   311,  1489,  1591,   741,  1555,
    1593,  1508,  1605,  1598,  1606,  1362,  1607,  1610,  1509,  1653,
    1500,  1611,  1616,  1666,  1619,  1626,  1627,  1632,  1654,  1096,
    1096,  1510,  1668,  1669,  1677,  1194,  1154,  1097,  1097,  1682,
     854,  1693,  1690,  1695,  1701,  1717,  1705,  1709,  1719,  1529,
    1720,  1731,  1732,   711,   527,  1696,  1734,   527,  1735,  1739,
    1744,   527,  1746,  1748,   527,   527,  1700,  1614,  1747,  1702,
    1589,  1740,   527,  1780,  1762,  1764,  1710,  1667,   527,   527,
    1733,  1777,  1778,   527,  1785,  1786,  1789,  1801,  1792,  1794,
    1798,   527,  1802,  1807,  1813,  1817,  1689,   527,   527,   527,
     527,  1416,   958,  1175,  1816,   527,   608,   609,  1814,   738,
    1254,  1804,  1431,   527,   612,  1742,  1773,  1101,  1251,  1031,
     758,  1775,  1796,   702,  1805,  1533,  1603,   755,  1765,  1458,
    1808,  1443,  1810,  1528,  1525,  1819,   803,  1352,  1469,  1473,
    1479,  1487,   889,   900,   890,   927,  1457,  1791,  1498,  1063,
    1788,  1226,  1158,  1415,  1513,  1154,  1549,  1553,   527,  1702,
    1519,  1518,   747,  1665,  1552,  1366,   307,   681,  1664,   787,
    1461,  1199,   527,  1424,   311,  1390,  1550,  1582,  1674,  1154,
       0,   748,  1080,   527,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1782,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1501,     0,
       0,     0,     0,     0,     0,     0,   549,     0,     0,     0,
       0,   527,     0,     0,     0,     0,     0,     0,     0,     0,
    1799,     0,   849,     0,     0,     0,     0,     0,     0,     0,
       0,   526,     0,     0,   526,     0,     0,     0,  1722,     0,
       0,     0,  1799,     0,     0,     0,     0,  1782,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1728,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1096,     0,     0,     0,  1154,
       0,     0,     0,  1097,     0,     0,  1096,  1096,     0,   307,
       0,     0,     0,     0,  1097,  1097,  1096,   311,     0,     0,
       0,     0,     0,     0,  1097,     0,     0,     0,  1588,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   935,     0,     0,   527,     0,     0,
       0,     0,     0,     0,  1601,  1602,     0,     0,     0,     0,
       0,   527,     0,     0,     0,   527,   527,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1618,     0,  1154,     0,     0,  1154,     0,     0,   527,     0,
     527,     0,     0,     0,     0,     0,     0,  1630,   527,  1096,
       0,   527,  1634,     0,     0,   527,     0,  1097,     0,     0,
    1096,     0,     0,     0,     0,     0,     0,     0,  1097,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   307,     0,     0,
       0,     0,     0,     0,     0,   311,   527,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     307,     0,     0,     0,     0,     0,     0,     0,   311,     0,
       0,     0,     0,     0,     0,   527,     0,     0,     0,     0,
       0,     0,  1096,     0,     0,     0,     0,  1096,     0,     0,
    1097,     0,     0,     0,     0,  1097,     0,     0,     0,     0,
       0,   527,     0,     0,     0,     0,     0,     0,     0,     0,
    1704,     0,  1706,     0,  1708,     0,     0,     0,     0,     0,
       0,  1716,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   527,   527,   527,   527,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1154,     0,
    1154,     0,     0,     0,     0,     0,     0,     0,   527,     0,
       0,     0,     0,     0,     0,     0,  1738,     0,     0,  1741,
       0,     0,   527,     0,     0,     0,     0,     0,     0,     0,
       0,  1154,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1749,     0,     0,     0,     0,     0,   527,     0,     0,
       0,     0,     0,     0,     0,     0,   527,     0,   527,     0,
     527,  1154,   527,     0,     0,     0,     0,     0,     0,  1776,
       0,     0,     0,     0,  1779,   527,  1154,     0,  1154,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   549,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1797,   527,     0,
     527,     0,     0,     0,     0,     0,     0,     0,   828,   829,
       0,     0,   838,   839,  1803,   842,     0,   844,  1806,     0,
       0,     0,     0,   852,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1815,     0,     0,  1818,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   881,     0,     0,     0,     0,     0,     0,
       0,   887,   888,     0,   527,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   527,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   923,     0,     0,   923,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   987,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   527,     0,     0,     0,
     527,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   527,     0,     0,     0,     0,
       0,     0,     0,     0,   527,  1030,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   527,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   527,     0,
    1055,     0,     0,     0,  1057,  1058,     0,     0,     0,     0,
       0,     0,     0,   887,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   527,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1079,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   527,     0,     0,     0,     0,     0,     0,     0,     0,
     527,     0,     0,   527,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1112,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   527,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   527,     0,  1176,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   527,   527,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1216,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   527,
       0,   527,     0,  1232,   527,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   527,     0,     0,     0,
       0,   527,     0,     0,     0,  1265,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1270,  1271,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1290,     0,     0,  1293,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1317,  1318,  1319,     0,  1322,  1323,  1324,     0,     0,     0,
    1327,  1328,  1329,  1330,     0,     0,  1333,  1334,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   527,
       0,   527,     0,   527,     0,     0,     0,     0,     0,     0,
     527,     0,     0,     0,     0,     0,     0,     0,     0,  1412,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   527,     0,   527,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   527,     0,     0,   527,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     527,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     527,  1444,     0,  1446,     0,  1448,     0,     0,  1452,     0,
       0,     0,     0,  1456,     0,     0,     0,     0,     0,     0,
     527,     0,     0,     0,     0,  1462,     0,     0,   527,     0,
       0,     0,     0,   527,  1466,   527,     0,   527,     0,     0,
    1470,  1471,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1492,
       0,     0,  1493,     0,     0,     0,   527,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   527,     0,     0,     0,   527,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   527,     0,     0,   527,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1592,
       0,     0,     0,  1594,     0,     0,     0,  1597,     0,  1599,
       0,  1600,     0,     0,     0,     0,     0,  1604,     0,     0,
       0,     0,     0,     0,     0,  1609,     0,     0,     0,     0,
       0,     0,     0,  1613,  1615,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1462,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1635,  1636,  1637,  1638,  1639,  1640,  1641,
    1642,     0,  1643,     0,     0,     0,     0,     0,     0,  1649,
       0,     0,     0,     0,     0,     0,     0,     0,  1652,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1691,     0,  1692,     0,     0,  1694,     0,     0,     0,
       0,     0,     0,     0,  1697,     0,     0,     0,     0,  1699,
    1615,     0,     0,     0,     0,     0,     0,  1703,     0,     0,
       0,  1707,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1724,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -845,   450,     0,   451,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1743,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1703,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -845,     0,     0,
       0,  -845,     0,     0,     0,  -845,  -845,     0,     0,     0,
    -845,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   452,     0,     0,  -845,  1783,   453,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1793,     0,     0,     0,  -845,     0,  -845,
    -845,  -845,     0,  1795,  -845,  -845,  -845,  -845,  1800,     0,
       0,  -845,  -845,  1783,     0,     0,     0,     0,  -845,     0,
       0,  -845,  -845,   454,     0,     0,  -845,     0,     0,  1800,
       0,  -845,  -845,  1809,     0,     0,     0,  -845,     0,     0,
       0,  -845,     0,     0,     0,  -845,  -845,     0,  -845,     0,
    -845,  -845,     0,     0,     0,  -845,  -845,     0,     0,  -845,
    -845,  -845,  -845,  -845,  -845,     0,     0,  -845,     0,     0,
       0,     0,  -845,  -845,     0,     0,  -845,     0,     0,     0,
       0,  -845,     0,     0,  -845,     0,     0,     0,     0,  -845,
    -845,  -845,  -845,  -845,     0,  -845,  -845,  -845,  -845,     0,
       0,     0,     0,  -845,  -845,  -845,     0,  -845,  -845,  -845,
    -845,  -845,  -845,     0,  -845,     0,  -845,     0,     0,     0,
       0,  -845,  -845,  -845,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -845,     0,  -845,
       0,  -845,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -845,     0,     0,     0,     0,  -845,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,     0,    11,  -845,     0,  -845,    12,    13,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,     0,    74,    75,    76,     0,     0,
      77,    78,     0,     0,     0,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,     0,     0,     0,    90,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
      96,    97,    98,    99,   100,     0,     0,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   108,   109,
       0,   110,   111,   112,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,     0,   123,
       0,   124,   125,     0,     0,   126,   127,   128,     0,     0,
       0,   129,     0,   130,   131,     0,   132,   133,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
     247,   248,   249,   250,   251,   252,   253,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,     0,     0,     0,    12,
      13,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,     0,    74,    75,    76,     0,
       0,    77,    78,     0,     0,     0,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,     0,     0,     0,
      90,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   108,
     109,     0,   110,   111,   112,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,     0,
     123,     0,   124,   125,     0,     0,   126,   127,   128,     0,
       0,     0,   129,     0,   130,   131,     0,   132,   133,   134,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,   149,     0,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,     0,   244,     0,   245,
     246,   247,   248,   249,   250,   251,     0,   604,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     9,    10,     0,    11,     0,     0,     0,
     409,   410,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,   411,    28,    29,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,     0,    74,    75,    76,
       0,     0,    77,    78,     0,     0,     0,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,     0,     0,
       0,    90,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,    96,    97,    98,    99,   100,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     108,   109,     0,   110,   111,   112,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
       0,   123,     0,   124,   125,     0,     0,   126,   127,   128,
       0,   546,     0,   129,     0,   130,   131,     0,   132,   133,
     134,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   412,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,     0,   244,     0,
     245,   246,   247,   248,   249,   250,   251,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,     0,     0,     0,   409,
     410,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,   411,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,     0,    74,    75,    76,     0,
       0,    77,    78,     0,     0,     0,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,     0,     0,     0,
      90,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   108,
     109,     0,   110,   111,   112,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,     0,
     123,     0,   124,   125,     0,     0,   126,   127,   128,     0,
     805,     0,   129,     0,   130,   131,     0,   132,   133,   134,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,   149,     0,
     412,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,     0,   244,     0,   245,
     246,   247,   248,   249,   250,   251,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,     0,    11,     0,     0,     0,   409,   410,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,  1092,   411,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,  1093,  1094,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,     0,    74,    75,    76,     0,     0,
      77,    78,     0,     0,     0,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,     0,     0,     0,    90,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
      96,    97,    98,    99,   100,     0,     0,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   108,   109,
       0,   110,   111,   112,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,     0,   123,
       0,   124,   125,     0,     0,   126,   127,   128,     0,   805,
       0,   129,     0,   130,   131,     0,   132,   133,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   412,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,  1095,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,   409,   410,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,  1092,   411,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,  1093,  1094,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   108,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,   546,     0,
     129,     0,   130,   131,     0,   132,   133,   134,     0,   135,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,   149,     0,   412,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,  1095,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,     0,   244,     0,   245,   246,   247,
     248,   249,   250,   251,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     9,
      10,     0,    11,     0,     0,     0,   409,   410,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,   411,    28,    29,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,     0,    74,    75,    76,     0,     0,    77,    78,
       0,     0,     0,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,     0,     0,     0,    90,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,    96,    97,
      98,    99,   100,     0,     0,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   108,   109,     0,   110,
     111,   112,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,     0,   123,     0,   124,
     125,     0,     0,   126,   127,   128,     0,     0,     0,   129,
       0,   130,   131,     0,   132,   133,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   412,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,   244,     0,   245,   246,   247,   248,
     249,   250,   251,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,     0,     0,     0,    12,    13,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   108,   109,     0,   110,   111,
     112,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,   124,   125,
       0,     0,   126,   127,   128,     0,     0,     0,   129,     0,
     130,   131,     0,   132,   133,   134,     0,   135,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,   149,     0,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,     0,   244,     0,   245,   246,   247,   248,   249,
     250,   251,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     9,    10,     0,
      11,     0,     0,     0,    12,    13,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
       0,    74,    75,    76,     0,     0,    77,    78,     0,     0,
       0,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,     0,     0,     0,    90,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,    96,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   108,   109,     0,   110,   111,   112,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,   121,   122,     0,   123,     0,   124,   125,     0,
       0,   126,   127,   128,     0,     0,     0,   129,     0,   130,
     131,     0,   132,   133,   134,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,   149,     0,   412,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,     0,   244,     0,   245,   246,   247,   248,   249,   250,
     251,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
       0,     0,     0,    12,   410,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,    73,     0,
      74,    75,    76,     0,     0,    77,    78,     0,     0,     0,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,     0,     0,     0,    90,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,    96,    97,    98,    99,   100,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   108,   109,     0,   110,   111,   112,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,     0,   123,     0,   124,   125,     0,     0,
     126,   127,   128,     0,     0,     0,   129,     0,   130,   131,
       0,   132,   133,   134,     0,   135,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,   149,     0,   412,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
       0,   244,     0,   245,   246,   247,   248,   249,   250,   251,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,     0,    11,     0,
       0,     0,   874,   410,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,   411,    28,
      29,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,     0,    74,
      75,    76,     0,     0,    77,    78,     0,     0,     0,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
       0,     0,     0,    90,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,    96,    97,    98,    99,   100,     0,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   108,   109,     0,   110,   111,   112,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,     0,   123,     0,   124,   125,     0,     0,   126,
     127,   128,     0,     0,     0,   129,     0,   130,   131,     0,
     132,   133,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   412,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,   409,   410,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,  1092,   411,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
    1093,  1094,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,   134,     0,   135,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
     149,     0,   412,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,  1095,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,     0,   244,
       0,   245,   246,   247,   248,   249,   250,   251,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     0,     0,     0,    11,     0,     0,     0,
     409,   410,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   551,   411,    28,    29,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,   552,
     553,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,     0,    74,    75,    76,
       0,     0,    77,    78,     0,     0,     0,    79,    80,   502,
      82,    83,    84,    85,    86,   554,    88,    89,     0,     0,
       0,    90,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,    96,    97,    98,    99,   100,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     555,   109,     0,   110,   111,   112,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
       0,   123,     0,   124,   125,     0,     0,   126,   127,   128,
       0,     0,   556,   129,     0,   130,   131,     0,   132,   133,
     134,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   412,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   519,   520,   521,   176,   177,   522,
     557,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,     0,   244,     0,
     245,   246,   247,   248,   249,   250,   251,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     0,     0,     0,    11,     0,     0,     0,   409,
     410,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   551,   411,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,   552,   553,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,     0,    74,    75,    76,     0,
       0,    77,    78,     0,     0,     0,    79,    80,   502,    82,
      83,    84,    85,    86,   554,    88,    89,     0,     0,     0,
      90,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   555,
     109,     0,   110,   111,   112,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,     0,
     123,     0,   124,   125,     0,     0,   126,   127,   128,     0,
       0,     0,   129,   561,   130,   131,     0,   132,   133,   134,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,   149,     0,
     412,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   519,   520,   521,   176,   177,   522,   557,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,     0,   244,     0,   245,
     246,   247,   248,   249,   250,   251,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     0,     0,     0,    11,     0,     0,     0,   409,   410,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   551,   411,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,   552,   553,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,     0,    74,    75,    76,     0,     0,
      77,    78,     0,     0,     0,    79,    80,   502,    82,    83,
      84,    85,    86,   554,    88,    89,     0,     0,     0,    90,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
      96,    97,    98,    99,   100,     0,     0,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   555,   109,
       0,   110,   111,   112,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,     0,   123,
       0,   124,   125,     0,     0,   126,   127,   128,     0,     0,
       0,   129,     0,   130,   131,     0,   132,   133,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   412,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   519,   520,   521,   176,   177,   522,   557,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   599,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   409,   410,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   551,   411,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,   552,   553,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   502,    82,    83,    84,
      85,    86,   554,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   555,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,     0,   130,   131,     0,   132,   133,   134,     0,   135,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,   149,     0,   412,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   519,   520,   521,   176,   177,   522,   557,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,     0,   244,   601,   245,   246,   247,
     248,   249,   250,   251,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     0,
       0,     0,    11,     0,     0,     0,   409,   410,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   551,   411,    28,    29,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,    45,    46,    47,   552,   553,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,     0,    74,    75,    76,     0,     0,    77,    78,
       0,     0,     0,    79,    80,   502,    82,    83,    84,    85,
      86,   554,    88,    89,     0,     0,     0,    90,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,    96,    97,
      98,    99,   100,     0,     0,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   555,   109,     0,   110,
     111,   112,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,     0,   123,     0,   124,
     125,     0,     0,   126,   127,   128,     0,   916,     0,   129,
       0,   130,   131,     0,   132,   133,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   412,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     519,   520,   521,   176,   177,   522,   557,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,   244,     0,   245,   246,   247,   248,
     249,   250,   251,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   409,   410,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     551,   411,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,   552,   553,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   502,    82,    83,    84,    85,    86,
     554,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   555,   109,     0,   110,   111,
     112,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,   124,   125,
       0,     0,   126,   127,   128,     0,     0,     0,   129,   922,
     130,   131,     0,   132,   133,   134,     0,   135,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,   149,     0,   412,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   519,
     520,   521,   176,   177,   522,   557,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,     0,   244,     0,   245,   246,   247,   248,   249,
     250,   251,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     0,     0,     0,
      11,     0,     0,     0,   409,   410,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,   551,
     411,    28,    29,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,   552,   553,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
       0,    74,    75,    76,     0,     0,    77,    78,     0,     0,
       0,    79,    80,   502,    82,    83,    84,    85,    86,   554,
      88,    89,     0,     0,     0,    90,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,    96,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   555,   109,     0,   110,   111,   112,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,   121,   122,     0,   123,     0,   124,   125,     0,
       0,   126,   127,   128,     0,     0,     0,   129,   926,   130,
     131,     0,   132,   133,   134,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,   149,     0,   412,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   519,   520,
     521,   176,   177,   522,   557,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,     0,   244,     0,   245,   246,   247,   248,   249,   250,
     251,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     0,     0,     0,    11,
       0,     0,     0,   409,   410,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   488,    25,   490,   411,
      28,   491,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,   493,     0,    45,
      46,    47,   495,   496,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,    73,     0,
      74,    75,    76,     0,     0,    77,    78,     0,     0,     0,
      79,    80,   502,    82,    83,    84,    85,    86,   554,    88,
      89,     0,     0,     0,    90,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   505,    97,    98,    99,   100,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   555,   109,     0,   110,   111,   679,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,     0,   123,     0,   680,   125,     0,     0,
     126,   127,   128,     0,     0,     0,   129,     0,   130,   131,
       0,   132,   133,   134,     0,   135,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,   149,     0,   412,   151,   152,   153,   154,   155,
     156,   157,   158,   514,   160,   515,   162,   516,   517,   165,
     166,   167,   168,   169,   170,   518,   172,   519,   520,   521,
     176,   177,   522,   523,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
       0,   244,     0,   245,   524,   247,   248,   249,   250,   251,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     0,     0,     0,    11,     0,
       0,     0,   409,   410,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   551,   411,    28,
      29,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,   552,   553,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,     0,    74,
      75,    76,     0,     0,    77,    78,     0,     0,     0,    79,
      80,   502,    82,    83,    84,    85,    86,   554,    88,    89,
       0,     0,     0,    90,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,    96,    97,    98,    99,   100,     0,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   555,   109,     0,   110,   111,   112,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,     0,   123,     0,   124,   125,     0,     0,   126,
     127,   128,     0,     0,     0,   129,     0,   130,   131,     0,
     132,   133,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   412,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   519,   520,   521,   176,
     177,   522,   557,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   409,   410,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   488,    25,   490,   411,    28,   491,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,   493,     0,    45,    46,    47,
     495,   496,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     502,    82,    83,    84,    85,    86,   554,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   505,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   555,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,   134,     0,   135,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
     149,     0,   412,   151,   152,   153,   154,   155,   156,   157,
     158,   514,   160,   515,   162,   516,   517,   165,   166,   167,
     168,   169,   170,   518,   172,   519,   520,   521,   176,   177,
     522,   523,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,     0,   244,
       0,   245,   524,   247,   248,   249,   250,   251,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     0,     0,     0,    11,     0,     0,     0,
     409,   410,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,   488,    25,   490,   411,    28,   491,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,   493,     0,    45,    46,    47,   495,
     496,    50,   497,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,     0,    74,    75,    76,
       0,     0,    77,    78,     0,     0,     0,    79,    80,   502,
      82,    83,    84,    85,    86,   554,    88,    89,     0,     0,
       0,    90,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   505,    97,    98,    99,   100,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     555,   109,     0,   110,   111,     0,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
       0,   123,     0,     0,     0,     0,     0,   126,   127,   128,
       0,     0,     0,   129,     0,   130,   131,     0,   132,   133,
     134,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   412,   151,   152,   153,   154,   155,   156,   157,   158,
     514,   160,   515,   162,   516,   517,   165,   166,   167,   168,
     169,   170,   518,   172,   519,   520,   521,   176,   177,   522,
     523,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,     0,   244,     0,
     245,   524,   247,   248,   249,   250,   251,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     0,     0,     0,    11,     0,     0,     0,   409,
     410,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,   488,    25,   490,   411,    28,   491,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,   493,     0,    45,    46,    47,   495,   496,
      50,   497,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,     0,    74,    75,    76,     0,
       0,    77,    78,     0,     0,     0,    79,    80,   502,    82,
      83,    84,    85,    86,   554,    88,    89,     0,     0,     0,
      90,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   505,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   555,
     109,     0,   110,   111,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,     0,
     123,     0,     0,     0,     0,     0,   126,   127,   128,     0,
       0,     0,   129,     0,   130,   131,     0,     0,     0,   134,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,   149,     0,
     412,   151,   152,   153,   154,   155,   156,   157,   158,   514,
     160,   515,   162,   516,   517,   165,   166,   167,   168,   169,
     170,   518,   172,   519,   520,   521,   176,   177,   522,   523,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,     0,   244,     0,   245,
     524,   247,   248,   249,   250,   251,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     0,     0,     0,    11,     0,     0,     0,   409,   410,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,   488,    25,   490,   411,    28,   491,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,   493,     0,    45,    46,    47,   495,   496,    50,
     497,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,     0,    74,    75,    76,     0,     0,
      77,    78,     0,     0,     0,    79,    80,   502,    82,    83,
      84,    85,    86,   554,    88,    89,     0,     0,     0,    90,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     505,     0,    98,    99,   100,     0,     0,     0,     0,     0,
       0,   101,   102,   103,   104,     0,   106,   107,   555,   109,
       0,   110,   111,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,     0,   123,
       0,     0,     0,     0,     0,   126,   127,   128,     0,     0,
       0,   129,     0,   130,   131,     0,     0,     0,   134,     0,
     135,     0,   136,     0,   138,     0,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   412,
     151,   152,   153,   154,   155,   156,   157,   158,   514,   160,
     515,   162,   516,   517,   165,   166,   167,   168,   169,   170,
     518,   172,   519,   520,   521,   176,   177,   522,   523,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   524,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     0,     0,     0,     7,     8,
       0,     0,     0,     0,     0,     0,     0,   409,   410,     0,
      14,    15,    16,   485,    18,    19,    20,   486,    22,   487,
     488,   489,   490,   411,    28,   491,    30,    31,     0,    32,
      33,    34,    35,   492,    37,    38,    39,    40,    41,    42,
      43,   493,     0,    45,   494,    47,   495,   496,    50,   497,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,   498,   499,    68,     0,    69,    70,
      71,   500,     0,     0,    74,    75,    76,     0,     0,   501,
      78,     0,     0,     0,     0,    80,   502,    82,   503,   504,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   505,
      97,    98,   506,   507,     0,     0,     0,     0,     0,     0,
     101,   102,   103,     0,   105,   106,   107,     0,     0,     0,
       0,     0,     0,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   508,   120,   121,   509,     0,     0,     0,
       0,     0,     0,     0,   510,   511,   128,     0,     0,     0,
     129,     0,   130,   512,     0,     0,     0,   134,     0,   135,
       0,   136,   137,   138,   139,   513,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,     0,     0,   412,   151,
     152,   153,   154,   155,   156,   157,   158,   514,   160,   515,
     162,   516,   517,   165,   166,   167,   168,   169,   170,   518,
     172,   519,   520,   521,   176,   177,   522,   523,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     0,     0,     1,     2,   245,   524,   247,
     248,   249,   250,   251,     3,     0,     0,     0,     7,     8,
       0,     0,     0,     0,     0,     0,     0,   409,   410,     0,
      14,    15,    16,   533,    18,    19,    20,   486,   534,   535,
     488,   489,   490,   411,    28,   491,    30,    31,     0,    32,
      33,    34,    35,   536,    37,   537,   538,    40,    41,    42,
      43,   493,     0,    45,   539,    47,   495,   496,    50,   497,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,   498,   499,    68,     0,    69,    70,
      71,   540,     0,     0,    74,    75,    76,     0,     0,   501,
      78,     0,     0,     0,     0,    80,   502,    82,   503,   504,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   505,
      97,    98,   506,   507,     0,     0,     0,     0,     0,     0,
     101,   102,   103,     0,   105,   106,   107,     0,     0,     0,
       0,     0,     0,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   508,   120,   121,   509,     0,     0,     0,
       0,     0,     0,     0,   510,   511,   128,     0,     0,     0,
     129,     0,   130,   512,     0,     0,     0,   134,     0,   135,
       0,   136,   137,   138,   139,   513,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,     0,     0,   412,   151,
     152,   153,   154,   155,   156,   157,   158,   514,   541,   515,
     162,   516,   517,   165,   166,   167,   168,   169,   170,   518,
     172,   519,   520,   521,   176,   177,   522,   523,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     0,     0,     0,   566,   245,   524,   247,
     248,   249,   250,   251,     7,     8,     0,     0,     0,   780,
       0,     0,     0,   409,   410,     0,    14,    15,    16,   533,
      18,    19,    20,   486,   534,   535,   488,   489,   490,   411,
      28,   491,    30,    31,     0,    32,    33,    34,    35,   536,
      37,   537,   538,    40,    41,    42,    43,   493,     0,    45,
     539,    47,   495,   496,    50,   497,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     498,   499,    68,     0,    69,    70,    71,   540,     0,     0,
      74,    75,    76,     0,     0,   501,    78,     0,     0,     0,
       0,    80,   502,    82,   503,   504,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   505,    97,    98,   506,   507,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
     105,   106,   107,     0,     0,     0,     0,     0,     0,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   508,
     120,   121,   509,     0,     0,     0,     0,     0,     0,     0,
     510,   511,   128,     0,     0,     0,   129,   781,   130,   512,
       0,     0,     0,     0,     0,   135,     0,   136,   137,   138,
     139,   513,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,     0,     0,   412,   151,   152,   153,   154,   155,
     156,   157,   158,   514,   541,   515,   162,   516,   517,   165,
     166,   167,   168,   169,   170,   518,   172,   519,   520,   521,
     176,   177,   522,   523,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     0,   566,   245,   524,   247,   248,   249,   250,   251,
       7,     8,     0,     0,     0,     0,     0,     0,     0,   409,
     410,     0,    14,    15,    16,   533,    18,    19,    20,   486,
     534,   535,   488,   489,   490,   411,    28,   491,    30,    31,
       0,    32,    33,    34,    35,   536,    37,   537,   538,    40,
      41,    42,    43,   493,     0,    45,   539,    47,   495,   496,
      50,   497,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   498,   499,    68,     0,
      69,    70,    71,   540,     0,     0,    74,    75,    76,     0,
       0,   501,    78,     0,     0,     0,     0,    80,   502,    82,
     503,   504,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   505,    97,    98,   506,   507,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,   107,     0,
       0,     0,     0,     0,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   508,   120,   121,   509,     0,
       0,     0,     0,     0,     0,     0,   510,   511,   128,     0,
       0,     0,   129,     0,   130,   512,     0,     0,     0,     0,
       0,   135,     0,   136,   137,   138,   139,   513,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,     0,     0,
     412,   151,   152,   153,   154,   155,   156,   157,   158,   514,
     541,   515,   162,   516,   517,   165,   166,   167,   168,   169,
     170,   518,   172,   519,   520,   521,   176,   177,   522,   523,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,     0,     0,     0,   245,
     524,   247,   248,   249,   250,   251,   569,   570,     0,     0,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,   409,   410,     0,    14,    15,    16,   533,    18,    19,
      20,   486,   534,   535,   488,   489,   490,   411,    28,   491,
      30,    31,     0,    32,    33,    34,    35,   536,    37,   537,
     538,    40,    41,    42,    43,   493,     0,    45,   539,    47,
     495,   496,    50,   497,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,   498,   499,
      68,     0,    69,    70,    71,   540,     0,     0,    74,    75,
      76,     0,     0,   501,    78,     0,     0,     0,     0,    80,
     502,    82,   503,   504,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   505,    97,    98,   506,   507,     0,     0,
       0,     0,     0,     0,   101,   102,   103,     0,   105,   106,
     107,     0,     0,     0,     0,     0,     0,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   508,   120,   121,
     509,     0,     0,     0,     0,     0,     0,     0,   510,   511,
     128,     0,     0,     0,   129,     0,   130,   512,     0,     0,
       0,     0,     0,   135,     0,   136,   137,   138,   139,   513,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
       0,     0,   412,   151,   152,   153,   154,   155,   156,   157,
     158,   514,   541,   515,   162,   516,   517,   165,   166,   167,
     168,   169,   170,   518,   172,   519,   520,   521,   176,   177,
     522,   523,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,     0,     0,     0,
       0,   245,   524,   247,   248,   249,   250,   251,     4,     5,
       6,     7,     8,     0,     0,     0,    11,     0,     0,     0,
     409,   410,     0,    14,    15,    16,   830,    18,    19,    20,
      21,   534,   831,   488,    25,   490,   411,    28,   491,    30,
      31,     0,    32,    33,    34,    35,   832,    37,   537,   538,
      40,    41,    42,    43,   493,     0,    45,   833,    47,   495,
     496,    50,   497,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   498,   499,    68,
       0,    69,    70,    71,   834,     0,     0,    74,    75,    76,
       0,     0,   501,    78,     0,     0,     0,    79,    80,   502,
      82,   503,   504,    85,    86,   554,    88,     0,     0,     0,
       0,    90,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   505,    97,    98,   506,   507,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     555,   109,     0,   110,   111,     0,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   509,
       0,   123,     0,     0,     0,     0,     0,   510,   511,   128,
       0,     0,     0,   129,     0,   130,   512,     0,     0,     0,
       0,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   412,   151,   152,   153,   154,   155,   156,   157,   158,
     514,   541,   515,   162,   516,   517,   165,   166,   167,   168,
     169,   170,   518,   172,   519,   520,   521,   176,   177,   522,
     523,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,     0,   244,     0,
     245,   524,   247,   248,   249,   250,   251,     7,     8,     0,
       0,     0,     0,     0,     0,     0,   409,   410,     0,    14,
      15,    16,   485,    18,    19,    20,   486,    22,   487,   488,
    1134,   490,   411,    28,   491,    30,    31,     0,    32,    33,
      34,    35,   492,    37,    38,    39,    40,    41,    42,    43,
     493,     0,    45,   494,    47,   495,   496,    50,   497,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   498,   499,    68,     0,    69,    70,    71,
     500,     0,     0,    74,    75,    76,     0,     0,   501,    78,
       0,     0,     0,     0,    80,   502,    82,   503,   504,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   505,    97,
      98,   506,   507,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,  1135,     0,     0,     0,  1136,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   508,   120,   121,   509,     0,     0,     0,     0,
       0,     0,     0,   510,   511,   128,     0,     0,     0,   129,
    1563,   130,   512,     0,     0,     0,  1564,     0,   135,     0,
     136,   137,   138,   139,   513,   141,   142,   143,   144,   145,
     146,     0,     0,  1137,   148,     0,     0,   412,   151,   152,
     153,   154,   155,   156,   157,   158,   514,   160,   515,   162,
     516,   517,   165,   166,   167,   168,   169,   170,   518,   172,
     519,   520,   521,   176,   177,   522,   523,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     0,     0,     7,     8,   245,   524,   247,  1138,
    1139,  1140,  1141,   409,   410,     0,    14,    15,    16,   533,
      18,    19,    20,   486,   534,   535,   488,   489,   490,   411,
      28,   491,    30,    31,     0,    32,    33,    34,    35,   536,
      37,   537,   538,    40,    41,    42,    43,   493,     0,    45,
     539,    47,   495,   496,    50,   497,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     498,   499,    68,     0,    69,    70,    71,   540,     0,     0,
      74,    75,    76,     0,     0,   501,    78,     0,     0,     0,
       0,    80,   502,    82,   503,   504,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   505,    97,    98,   506,   507,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
     105,   106,   107,     0,     0,     0,     0,     0,     0,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   508,
     120,   121,   509,     0,     0,     0,     0,     0,     0,     0,
     510,   511,   128,     0,     0,     0,   129,   750,   130,   512,
       0,     0,     0,   751,     0,   135,     0,   136,   137,   138,
     139,   513,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,     0,     0,   412,   151,   152,   153,   154,   155,
     156,   157,   158,   514,   541,   515,   162,   516,   517,   165,
     166,   167,   168,   169,   170,   518,   172,   519,   520,   521,
     176,   177,   522,   523,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     7,     8,   245,   524,   247,   248,   249,   250,   251,
     409,   410,     0,    14,    15,    16,   533,    18,    19,    20,
     486,   534,   535,   488,   489,   490,   411,    28,   491,    30,
      31,     0,    32,    33,    34,    35,   536,    37,   537,   538,
      40,    41,    42,    43,   493,     0,    45,   539,    47,   495,
     496,    50,   497,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   498,   499,    68,
       0,    69,    70,    71,   540,     0,     0,    74,    75,    76,
       0,     0,   501,    78,     0,     0,     0,     0,    80,   502,
      82,   503,   504,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   505,    97,    98,   506,   507,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,   107,
       0,     0,     0,     0,     0,     0,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   508,   120,   121,   509,
       0,     0,     0,     0,     0,     0,     0,   510,   511,   128,
       0,     0,     0,   129,   798,   130,   512,     0,     0,     0,
     799,     0,   135,     0,   136,   137,   138,   139,   513,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,     0,
       0,   412,   151,   152,   153,   154,   155,   156,   157,   158,
     514,   541,   515,   162,   516,   517,   165,   166,   167,   168,
     169,   170,   518,   172,   519,   520,   521,   176,   177,   522,
     523,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     0,     0,     7,     8,
     245,   524,   247,   248,   249,   250,   251,   409,   410,     0,
      14,    15,    16,   485,    18,    19,    20,   486,    22,   487,
     488,  1134,   490,   411,    28,   491,    30,    31,     0,    32,
      33,    34,    35,   492,    37,    38,    39,    40,    41,    42,
      43,   493,     0,    45,   494,    47,   495,   496,    50,   497,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,   498,   499,    68,     0,    69,    70,
      71,   500,     0,     0,    74,    75,    76,     0,     0,   501,
      78,     0,     0,     0,     0,    80,   502,    82,   503,   504,
      85,    86,  1480,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   505,
      97,    98,   506,   507,     0,     0,     0,     0,     0,     0,
     101,   102,   103,     0,   105,   106,  1135,     0,     0,     0,
    1136,     0,     0,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   508,   120,   121,   509,     0,     0,     0,
       0,     0,     0,     0,   510,   511,   128,     0,     0,     0,
     129,     0,   130,   512,     0,     0,     0,     0,     0,   135,
       0,   136,   137,   138,   139,   513,   141,   142,   143,   144,
     145,   146,     0,     0,  1137,   148,     0,     0,   412,   151,
     152,   153,   154,   155,   156,   157,   158,   514,   160,   515,
     162,   516,   517,   165,   166,   167,   168,   169,   170,   518,
     172,   519,   520,   521,   176,   177,   522,   523,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     0,     0,     7,     8,   245,   524,   247,
    1138,  1139,  1140,  1141,   409,   410,     0,    14,    15,    16,
     485,    18,    19,    20,   486,    22,   487,   488,  1134,   490,
     411,    28,   491,    30,    31,     0,    32,    33,    34,    35,
     492,    37,    38,    39,    40,    41,    42,    43,   493,     0,
      45,   494,    47,   495,   496,    50,   497,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   498,   499,    68,     0,    69,    70,    71,   500,     0,
       0,    74,    75,    76,     0,     0,   501,    78,     0,     0,
       0,     0,    80,   502,    82,   503,   504,    85,    86,  1620,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   505,    97,    98,   506,
     507,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,  1135,     0,     0,     0,  1136,     0,     0,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     508,   120,   121,   509,     0,     0,     0,     0,     0,     0,
       0,   510,   511,   128,     0,     0,     0,   129,     0,   130,
     512,     0,     0,     0,     0,     0,   135,     0,   136,   137,
     138,   139,   513,   141,   142,   143,   144,   145,   146,     0,
       0,  1137,   148,     0,     0,   412,   151,   152,   153,   154,
     155,   156,   157,   158,   514,   160,   515,   162,   516,   517,
     165,   166,   167,   168,   169,   170,   518,   172,   519,   520,
     521,   176,   177,   522,   523,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       0,     0,     7,     8,   245,   524,   247,  1138,  1139,  1140,
    1141,   409,   410,     0,    14,    15,    16,   485,    18,    19,
      20,   486,    22,   487,   488,  1134,   490,   411,    28,   491,
      30,    31,     0,    32,    33,    34,    35,   492,    37,    38,
      39,    40,    41,    42,    43,   493,     0,    45,   494,    47,
     495,   496,    50,   497,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,   498,   499,
      68,     0,    69,    70,    71,   500,     0,     0,    74,    75,
      76,     0,     0,   501,    78,     0,     0,     0,     0,    80,
     502,    82,   503,   504,    85,    86,  1624,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   505,    97,    98,   506,   507,     0,     0,
       0,     0,     0,     0,   101,   102,   103,     0,   105,   106,
    1135,     0,     0,     0,  1136,     0,     0,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   508,   120,   121,
     509,     0,     0,     0,     0,     0,     0,     0,   510,   511,
     128,     0,     0,     0,   129,     0,   130,   512,     0,     0,
       0,     0,     0,   135,     0,   136,   137,   138,   139,   513,
     141,   142,   143,   144,   145,   146,     0,     0,  1137,   148,
       0,     0,   412,   151,   152,   153,   154,   155,   156,   157,
     158,   514,   160,   515,   162,   516,   517,   165,   166,   167,
     168,   169,   170,   518,   172,   519,   520,   521,   176,   177,
     522,   523,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,     0,     0,     7,
       8,   245,   524,   247,  1138,  1139,  1140,  1141,   409,   410,
       0,    14,    15,    16,   485,    18,    19,    20,   486,    22,
     487,   488,  1134,   490,   411,    28,   491,    30,    31,     0,
      32,    33,    34,    35,   492,    37,    38,    39,    40,    41,
      42,    43,   493,     0,    45,   494,    47,   495,   496,    50,
     497,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,   498,   499,    68,     0,    69,
      70,    71,   500,     0,     0,    74,    75,    76,     0,     0,
     501,    78,     0,     0,     0,     0,    80,   502,    82,   503,
     504,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     505,    97,    98,   506,   507,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,  1135,     0,     0,
       0,  1136,     0,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   508,   120,   121,   509,     0,     0,
       0,     0,     0,     0,     0,   510,   511,   128,     0,     0,
       0,   129,     0,   130,   512,     0,     0,     0,     0,     0,
     135,     0,   136,   137,   138,   139,   513,   141,   142,   143,
     144,   145,   146,     0,     0,  1137,   148,     0,     0,   412,
     151,   152,   153,   154,   155,   156,   157,   158,   514,   160,
     515,   162,   516,   517,   165,   166,   167,   168,   169,   170,
     518,   172,   519,   520,   521,   176,   177,   522,   523,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,     0,     0,     7,     8,   245,   524,
     247,  1138,  1139,  1140,  1141,   409,   410,     0,    14,    15,
      16,   485,    18,    19,    20,   486,    22,   487,   488,  1134,
     490,   411,    28,   491,    30,    31,     0,    32,    33,    34,
      35,   492,    37,    38,    39,    40,    41,    42,    43,   493,
       0,    45,   494,    47,   495,   496,    50,   497,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   498,   499,    68,     0,    69,    70,    71,   500,
       0,     0,    74,    75,    76,     0,     0,   501,    78,     0,
       0,     0,     0,    80,   502,    82,   503,   504,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   505,    97,    98,
     506,   507,     0,     0,     0,     0,     0,     0,   101,   102,
     103,     0,   105,   106,  1135,     0,     0,     0,  1136,     0,
       0,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   508,   120,   121,   509,     0,     0,     0,     0,     0,
       0,     0,   510,   511,   128,     0,     0,     0,   129,     0,
     130,   512,     0,     0,     0,     0,     0,   135,     0,   136,
     137,   138,   139,   513,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,     0,     0,   412,   151,   152,   153,
     154,   155,   156,   157,   158,   514,   160,   515,   162,   516,
     517,   165,   166,   167,   168,   169,   170,   518,   172,   519,
     520,   521,   176,   177,   522,   523,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     0,     0,     7,     8,   245,   524,   247,  1138,  1139,
    1140,  1141,   409,   410,     0,    14,    15,    16,   533,    18,
      19,    20,   486,   534,   535,   488,   489,   490,   411,    28,
     491,    30,    31,     0,    32,    33,    34,    35,   536,    37,
     537,   538,    40,    41,    42,    43,   493,     0,    45,   539,
      47,   495,   496,    50,   497,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   498,
     499,    68,     0,    69,    70,    71,   540,     0,     0,    74,
      75,    76,     0,     0,   501,    78,     0,     0,     0,     0,
      80,   502,    82,   503,   504,    85,    86,  1227,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   505,    97,    98,   506,   507,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,   107,     0,     0,     0,     0,     0,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   508,   120,
     121,   509,     0,     0,     0,     0,     0,     0,     0,   510,
     511,   128,     0,     0,     0,   129,     0,   130,   512,     0,
       0,     0,     0,     0,   135,     0,   136,   137,   138,   139,
     513,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,     0,     0,   412,   151,   152,   153,   154,   155,   156,
     157,   158,   514,   541,   515,   162,   516,   517,   165,   166,
     167,   168,   169,   170,   518,   172,   519,   520,   521,   176,
     177,   522,   523,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     0,     0,
       7,     8,   245,   524,   247,   248,   249,   250,   251,   409,
     410,     0,    14,    15,    16,   533,    18,    19,    20,   486,
     534,   535,   488,   489,   490,   411,    28,   491,    30,    31,
       0,    32,    33,    34,    35,   536,    37,   537,   538,    40,
      41,    42,    43,   493,     0,    45,   539,    47,   495,   496,
      50,   497,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   498,   499,    68,     0,
      69,    70,    71,   540,     0,     0,    74,    75,    76,     0,
       0,   501,    78,     0,     0,     0,     0,    80,   502,    82,
     503,   504,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   505,    97,    98,   506,   507,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,   107,     0,
       0,     0,     0,     0,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   508,   120,   121,   509,     0,
       0,     0,     0,     0,     0,     0,   510,   511,   128,     0,
       0,     0,   129,     0,   130,   512,     0,     0,     0,     0,
       0,   135,     0,   136,   137,   138,   139,   513,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,     0,     0,
     412,   151,   152,   153,   154,   155,   156,   157,   158,   514,
     541,   515,   162,   516,   517,   165,   166,   167,   168,   169,
     170,   518,   172,   519,   520,   521,   176,   177,   522,   523,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,     0,     7,     8,   245,
     524,   247,   248,   249,   250,   251,   409,   410,     0,    14,
      15,    16,     0,    18,    19,    20,   486,     0,     0,   488,
     489,     0,   411,    28,   491,    30,    31,     0,    32,    33,
      34,    35,     0,    37,     0,     0,    40,    41,    42,    43,
     493,     0,    45,     0,    47,     0,     0,    50,   497,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   498,   499,    68,     0,    69,    70,    71,
       0,     0,     0,    74,    75,    76,     0,     0,   501,    78,
       0,     0,     0,     0,    80,   502,    82,   503,   504,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   505,    97,
      98,   506,   507,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,     0,     0,     0,     0,     0,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   508,   120,   121,   509,     0,     0,     0,     0,
       0,     0,     0,   510,   511,   128,     0,     0,     0,   129,
       0,   130,   512,     0,     0,     0,     0,     0,   135,     0,
     136,   137,   138,   139,   513,   141,   142,   143,   144,   145,
     146,     0,     0,     0,   148,     0,     0,   412,   151,   152,
     153,   154,   155,   156,   157,   158,   514,     0,   515,   162,
     516,   517,   165,   166,   167,   168,   169,   170,   518,   172,
     519,   520,   521,   176,   177,     0,   523,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     0,     0,     0,     0,   245,   524,   247,   248,
     249,   250,   251
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,   418,   419,    12,     4,     5,     6,   666,     0,   420,
     179,  1026,     4,     5,     6,     4,     5,     6,   818,   311,
     109,   110,   667,   668,   669,   670,   339,     4,     5,     6,
     617,   618,   133,     4,     5,     6,   755,  1042,   260,   259,
     582,   856,   775,  1297,    29,   899,   588,   755,  1280,   460,
     461,   291,   983,   275,   787,   252,   253,    73,  1066,  1120,
     432,  1213,  1358,  1359,    39,   933,   912,   913,   801,    44,
      45,   443,   711,    55,   615,   616,   615,   616,   617,   618,
      26,    27,    36,    36,    59,   107,    61,    62,  1001,   107,
      26,    27,     9,    10,   949,    70,   468,   645,   118,   647,
     648,    47,   650,   949,   652,   118,  1585,     8,   108,    30,
      56,    47,   660,   661,  1391,     1,   108,  1310,   282,   108,
     913,     1,    97,     1,     1,   110,     1,     1,    74,    93,
      29,   108,   224,    79,    29,     1,    52,   983,    74,   124,
      94,   100,    96,    96,   224,   147,   226,   107,   224,   100,
     226,   107,   100,    29,   243,   244,   224,  1003,   107,   153,
     118,   229,   107,    94,   149,   111,   112,   113,   153,    96,
    1016,   156,    26,    27,    96,   415,   112,    96,    37,    38,
     216,    40,    41,    45,    96,   153,   103,   142,    96,   158,
     153,    96,   177,   147,   147,   619,    96,   122,    57,   623,
      62,   113,   291,   147,   224,   118,   123,   176,   125,   177,
    1003,   110,   136,   129,   177,   209,   147,   253,   113,   183,
     147,   313,   955,  1016,   156,   124,   150,   186,   186,  1525,
     190,   187,    76,   313,   216,   186,   153,   313,   186,   147,
     157,   342,    94,   188,    94,   313,   107,   169,  1263,   224,
     149,   156,   252,   253,   113,  1734,   256,   174,   112,   272,
     252,   253,  1062,  1495,   256,   160,  1120,  1121,   560,   169,
     272,   253,  1277,   258,   175,   439,  1009,   194,   865,   866,
    1432,  1136,  1015,    73,   160,   234,   306,  1218,   310,  1008,
    1136,   291,   213,  1301,   312,   212,   935,    87,  1006,   291,
    1008,   160,  1310,  1171,   190,  1498,  1367,  1584,   548,   153,
     190,   722,   190,   190,  1227,   190,   190,   272,   272,   272,
    1028,   111,   863,   864,   190,   187,   415,   188,   272,   251,
     252,   347,   254,   123,   350,   125,   255,   256,   107,   261,
     286,   316,   317,   318,    29,   107,   158,   895,   294,   271,
     286,   251,   252,    54,   254,    56,   302,   107,   294,   448,
     219,   283,   773,   107,   176,   217,   218,   217,   218,   458,
     107,   271,  1218,    45,   107,    47,   220,   221,   467,   154,
     232,   156,   232,   283,   118,   474,   475,   158,   107,  1685,
     612,   106,  1646,   633,   483,   615,   616,   769,   107,   100,
     772,   260,   148,   346,   156,   176,   349,   604,    33,  1255,
     169,     1,   127,     3,   107,   415,   185,    26,    27,   165,
     107,   200,   184,   415,    49,   110,   107,   198,    37,    38,
     209,    40,    41,  1279,   106,  1587,   107,   187,    47,   124,
     107,  1737,   201,   187,   444,   107,   446,    56,    57,   118,
     187,   184,   444,   187,   446,   444,   268,   446,   107,   548,
     107,   236,  1255,   275,   149,    74,   185,   444,   153,   446,
      79,   156,   472,   285,   107,   564,    66,   477,   187,   107,
     472,    71,   899,   472,  1217,   477,  1279,   576,   477,  1721,
    1498,   107,   177,   107,   187,   472,   168,    45,   185,    47,
     477,   741,   111,   112,   113,     9,   187,   596,   597,   107,
    1229,   928,   160,  1367,   107,  1652,   187,   186,   185,  1106,
    1107,  1108,  1376,   107,    28,   187,  1341,   107,   118,  1344,
    1238,    79,   107,  1387,   107,   184,   107,   131,  1690,   154,
     187,   156,   107,   153,  1086,   956,   957,    94,   548,   250,
     961,   160,   107,  1399,   187,   555,   548,   347,   106,   187,
     350,    42,   263,   555,   265,    46,   555,  1106,  1107,  1108,
      51,   187,   153,   187,   107,   276,   277,   278,   555,   280,
     991,   282,   107,  1735,   685,   686,   107,  1724,    69,   187,
     107,   184,  1607,   682,     9,    10,   190,   597,   687,   107,
     147,   610,   156,   187,   604,   597,  1399,   187,   597,   184,
     219,   184,   604,   184,   854,   615,   616,   617,   618,   123,
     168,   125,   187,   615,   616,   617,   618,     5,   209,  1362,
     134,     9,   187,   633,   107,   425,  1482,   107,   428,  1485,
    1645,   633,   432,   863,   156,   435,   436,   869,   107,   153,
     130,   260,   741,   443,   187,   137,  1808,    42,  1810,   449,
     450,    46,   187,   184,   454,   130,    51,  1819,     9,    10,
     187,   153,   462,     9,    10,   166,   184,   286,   468,   469,
     470,   471,   136,   122,    69,   294,   476,   168,   103,  1482,
     171,   182,  1485,   302,   484,     5,  1496,   137,   298,     9,
    1554,  1501,   142,  1120,  1121,   186,    94,   307,   123,    96,
     125,   184,   144,    53,   184,     9,   196,    94,    58,  1378,
     809,   810,   811,    42,   813,   184,   113,    46,  1447,   106,
     211,   196,    51,    94,    28,   246,   247,    77,   153,   529,
      96,   741,   157,    94,   176,   123,   200,   125,   156,   741,
      69,   117,   841,   543,   148,   133,    96,   113,   269,   174,
    1347,   193,   103,   262,   554,   765,   154,   103,   156,   156,
     156,   165,   861,   765,   273,   153,   765,    94,   118,   194,
     146,   142,   123,   168,   125,    53,   171,   123,   765,   125,
      58,   142,   582,   159,   765,   795,   796,   212,   588,   946,
     156,   186,   592,   795,   796,  1097,   795,   796,   231,  1122,
     233,   958,   153,   123,   122,   125,   157,   153,   795,   796,
     137,   157,  1668,   133,  1670,   142,   211,   193,    96,   123,
    1630,   125,    94,   174,  1634,   156,    24,   997,   174,   999,
     134,  1712,  1713,   153,   106,   153,    34,  1258,   156,   168,
      33,  1091,   171,   194,   854,  1701,   158,   182,   194,   153,
     156,   268,   854,   137,   137,   874,    49,   186,   275,   142,
     195,   212,    60,    95,   176,  1668,   212,  1670,   285,   153,
     142,   231,  1753,   233,   106,  1731,  1545,  1546,  1759,  1049,
     132,  1051,   211,  1538,   116,   156,   198,   182,   140,   141,
    1746,   143,  1748,   122,   100,   127,   100,   262,  1701,   151,
     195,   100,   118,   155,   100,   157,  1716,   113,   273,   113,
     162,   100,   100,   267,   113,   122,  1095,   113,   718,   153,
     274,  1100,   156,   153,   113,   113,   156,   179,  1731,   276,
     277,   278,   732,  1354,    53,   282,   736,   737,   688,    58,
    1367,   691,  1685,  1746,   694,  1748,   220,   221,   222,  1376,
     202,   203,   204,   205,   206,   207,   191,   192,   122,   759,
    1387,   761,   153,   153,   118,   156,   156,   153,   154,   769,
     128,   129,   772,   128,   129,   122,   776,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,  1656,  1657,   664,
     665,   671,   672,  1211,  1212,   673,   674,   914,   915,  1575,
    1576,   122,    73,   153,   122,   122,   122,  1257,   122,   153,
     215,   156,   118,   240,   240,   156,    87,   817,   241,   153,
    1119,   313,     0,   107,   190,   167,    92,   248,    50,    99,
     199,   154,   101,   145,  1044,   102,   156,    29,   184,    47,
     111,   184,  1044,  1464,   184,  1044,   118,   152,   245,   303,
     187,   153,   123,   118,   125,   283,   856,  1044,  1727,   283,
       1,   118,   142,   107,   153,   187,   153,   142,   156,   184,
     156,   156,   121,   156,   156,   156,   153,   156,   156,    35,
      17,  1091,   882,   213,    29,   244,  1105,   187,     3,  1091,
    1340,   230,   190,   229,   190,   154,  1106,  1107,  1108,   118,
     168,    70,   230,    94,  1106,  1107,  1108,   170,  1529,   170,
      94,    94,   912,   913,   914,   915,   149,   107,   107,    29,
     160,   160,   127,   132,    94,   298,   142,  1554,   132,   184,
     118,   184,   245,   187,   107,   187,    94,    96,    45,    96,
     187,   187,   187,   184,   187,    94,   153,   184,   142,   949,
     153,   153,   153,   153,   153,   190,   230,    33,   170,    94,
     236,   132,   224,   963,   118,   142,    29,    94,   226,   298,
     118,   153,   127,   147,   285,   118,    94,   197,   184,   132,
     253,   160,   132,    96,   118,   153,   147,   184,   988,   100,
     153,   100,   190,   121,    35,   142,    29,   997,   184,   999,
      79,  1001,   118,  1003,   156,   156,   244,   107,   107,   153,
     156,  1221,    29,    29,   156,   257,  1016,   156,   266,  1221,
     284,   144,  1221,   259,   156,   156,  1476,   156,    29,   285,
     156,   156,   144,   226,  1221,   286,   127,  1336,  1337,  1338,
    1221,   147,   147,   147,   118,   305,   118,  1257,    77,  1049,
     190,  1051,   107,   142,   187,  1257,   100,   187,  1268,   197,
       7,   132,   249,   187,   184,   187,  1268,   232,   187,  1268,
     187,   106,   232,   249,   236,   285,   347,  1287,   147,   350,
      78,  1268,   190,   186,    29,  1287,  1086,  1268,  1287,   187,
      29,   187,   187,   187,   187,   187,   232,  1307,   107,   187,
    1287,   198,   187,   270,   170,  1307,  1287,   184,  1307,   281,
     147,   232,   126,   147,   126,  1115,    96,   184,   232,   142,
    1307,   186,   186,   153,   186,   186,   184,   184,   184,  1339,
    1340,   232,    94,   187,    29,    96,  1136,  1339,  1340,   187,
    1339,   147,   170,    53,    94,   196,   186,   186,    96,   106,
     197,    94,    29,   424,   425,  1605,   107,   428,   107,   118,
     118,   432,    94,    94,   435,   436,  1616,  1617,   186,  1619,
     256,   224,   443,   186,   196,   196,  1626,   279,   449,   450,
     264,   118,   224,   454,   186,    93,   183,   186,   196,   118,
     118,   462,   186,   186,   198,   118,   286,   468,   469,   470,
     471,  1174,   721,   950,   224,   476,   256,   256,   286,   439,
    1017,   292,  1218,   484,   259,  1690,  1735,   857,  1014,   778,
     454,   304,   304,   419,   304,  1363,  1457,  1227,   315,  1247,
     305,  1231,   305,  1361,  1358,   305,   543,  1111,  1269,  1274,
    1277,  1282,   643,   663,   644,   696,  1246,  1759,  1301,   818,
    1753,   999,   915,  1173,  1332,  1255,  1376,  1387,   529,  1709,
    1342,  1341,   447,  1554,  1380,  1121,  1476,   335,  1551,  1269,
    1720,   982,   543,  1196,  1476,  1130,  1377,  1422,  1578,  1279,
      -1,   447,   840,   554,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1747,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1308,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,
      -1,   592,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1780,    -1,  1332,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1341,    -1,    -1,  1344,    -1,    -1,    -1,  1647,    -1,
      -1,    -1,  1802,    -1,    -1,    -1,    -1,  1807,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1666,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1605,    -1,    -1,    -1,  1399,
      -1,    -1,    -1,  1605,    -1,    -1,  1616,  1617,    -1,  1619,
      -1,    -1,    -1,    -1,  1616,  1617,  1626,  1619,    -1,    -1,
      -1,    -1,    -1,    -1,  1626,    -1,    -1,    -1,  1428,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   715,    -1,    -1,   718,    -1,    -1,
      -1,    -1,    -1,    -1,  1454,  1455,    -1,    -1,    -1,    -1,
      -1,   732,    -1,    -1,    -1,   736,   737,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1480,    -1,  1482,    -1,    -1,  1485,    -1,    -1,   759,    -1,
     761,    -1,    -1,    -1,    -1,    -1,    -1,  1497,   769,  1709,
      -1,   772,  1502,    -1,    -1,   776,    -1,  1709,    -1,    -1,
    1720,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1720,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1747,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1747,   817,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1780,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1780,    -1,
      -1,    -1,    -1,    -1,    -1,   856,    -1,    -1,    -1,    -1,
      -1,    -1,  1802,    -1,    -1,    -1,    -1,  1807,    -1,    -1,
    1802,    -1,    -1,    -1,    -1,  1807,    -1,    -1,    -1,    -1,
      -1,   882,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1620,    -1,  1622,    -1,  1624,    -1,    -1,    -1,    -1,    -1,
      -1,  1631,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   912,   913,   914,   915,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1668,    -1,
    1670,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   949,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1686,    -1,    -1,  1689,
      -1,    -1,   963,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1701,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1711,    -1,    -1,    -1,    -1,    -1,   988,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   997,    -1,   999,    -1,
    1001,  1731,  1003,    -1,    -1,    -1,    -1,    -1,    -1,  1739,
      -1,    -1,    -1,    -1,  1744,  1016,  1746,    -1,  1748,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   555,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1777,  1049,    -1,
    1051,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   580,   581,
      -1,    -1,   584,   585,  1794,   587,    -1,   589,  1798,    -1,
      -1,    -1,    -1,   595,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1814,    -1,    -1,  1817,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   625,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   633,   634,    -1,  1115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1136,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   693,    -1,    -1,   696,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   734,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1227,    -1,    -1,    -1,
    1231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1246,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1255,   777,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1269,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1279,    -1,
     802,    -1,    -1,    -1,   806,   807,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   815,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1308,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   840,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1332,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1341,    -1,    -1,  1344,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   884,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1399,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1428,    -1,   951,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1454,  1455,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   986,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1480,
      -1,  1482,    -1,  1005,  1485,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1497,    -1,    -1,    -1,
      -1,  1502,    -1,    -1,    -1,  1027,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1038,  1039,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1053,    -1,    -1,  1056,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1072,  1073,  1074,    -1,  1076,  1077,  1078,    -1,    -1,    -1,
    1082,  1083,  1084,  1085,    -1,    -1,  1088,  1089,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1111,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1620,
      -1,  1622,    -1,  1624,    -1,    -1,    -1,    -1,    -1,    -1,
    1631,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1161,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1668,    -1,  1670,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1686,    -1,    -1,  1689,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1701,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1711,  1233,    -1,  1235,    -1,  1237,    -1,    -1,  1240,    -1,
      -1,    -1,    -1,  1245,    -1,    -1,    -1,    -1,    -1,    -1,
    1731,    -1,    -1,    -1,    -1,  1257,    -1,    -1,  1739,    -1,
      -1,    -1,    -1,  1744,  1266,  1746,    -1,  1748,    -1,    -1,
    1272,  1273,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1291,
      -1,    -1,  1294,    -1,    -1,    -1,  1777,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1794,    -1,    -1,    -1,  1798,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1814,    -1,    -1,  1817,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1361,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1441,
      -1,    -1,    -1,  1445,    -1,    -1,    -1,  1449,    -1,  1451,
      -1,  1453,    -1,    -1,    -1,    -1,    -1,  1459,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1467,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1475,  1476,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1494,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1505,  1506,  1507,  1508,  1509,  1510,  1511,
    1512,    -1,  1514,    -1,    -1,    -1,    -1,    -1,    -1,  1521,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1530,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1593,    -1,  1595,    -1,    -1,  1598,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1606,    -1,    -1,    -1,    -1,  1611,
    1612,    -1,    -1,    -1,    -1,    -1,    -1,  1619,    -1,    -1,
      -1,  1623,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1653,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     0,     1,    -1,     3,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1693,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1705,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    -1,    -1,    69,  1747,    71,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1765,    -1,    -1,    -1,    92,    -1,    94,
      95,    96,    -1,  1775,    99,   100,   101,   102,  1780,    -1,
      -1,   106,   107,  1785,    -1,    -1,    -1,    -1,   113,    -1,
      -1,   116,   117,   118,    -1,    -1,   121,    -1,    -1,  1801,
      -1,   126,   127,  1805,    -1,    -1,    -1,   132,    -1,    -1,
      -1,   136,    -1,    -1,    -1,   140,   141,    -1,   143,    -1,
     145,   146,    -1,    -1,    -1,   150,   151,    -1,    -1,   154,
     155,   156,   157,   158,   159,    -1,    -1,   162,    -1,    -1,
      -1,    -1,   167,   168,    -1,    -1,   171,    -1,    -1,    -1,
      -1,   176,    -1,    -1,   179,    -1,    -1,    -1,    -1,   184,
     185,   186,   187,   188,    -1,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,   199,   200,    -1,   202,   203,   204,
     205,   206,   207,    -1,   209,    -1,   211,    -1,    -1,    -1,
      -1,   216,   217,   218,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,    -1,   234,
      -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,   253,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,   310,    -1,   312,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    98,    -1,   100,   101,   102,    -1,    -1,
     105,   106,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    -1,    -1,    -1,   124,
      -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,
     135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,
      -1,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,   156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,    -1,   191,   192,   193,    -1,
     195,    -1,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,    -1,    -1,   210,   211,   212,    -1,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,    -1,   258,   259,   260,    -1,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,    -1,   311,    -1,   313,   314,
     315,   316,   317,   318,   319,   320,   321,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    98,    -1,   100,   101,   102,    -1,
      -1,   105,   106,    -1,    -1,    -1,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,    -1,    -1,    -1,
     124,    -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,
      -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   147,   148,   149,   150,   151,   152,   153,
     154,    -1,   156,   157,   158,   159,   160,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
     174,    -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,    -1,   188,   189,    -1,   191,   192,   193,
      -1,   195,    -1,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,    -1,   210,   211,   212,    -1,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,    -1,   311,    -1,   313,
     314,   315,   316,   317,   318,   319,    -1,   321,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    29,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    98,    -1,   100,   101,   102,
      -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    -1,    -1,
      -1,   124,    -1,   126,   127,   128,   129,    -1,   131,    -1,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,   156,   157,   158,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,   184,    -1,   186,    -1,   188,   189,    -1,   191,   192,
     193,    -1,   195,    -1,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,    -1,    -1,   210,   211,   212,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,    -1,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,    -1,   311,    -1,
     313,   314,   315,   316,   317,   318,   319,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    98,    -1,   100,   101,   102,    -1,
      -1,   105,   106,    -1,    -1,    -1,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,    -1,    -1,    -1,
     124,    -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,
      -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   147,   148,   149,   150,   151,   152,   153,
     154,    -1,   156,   157,   158,   159,   160,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
     174,    -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,
     184,    -1,   186,    -1,   188,   189,    -1,   191,   192,   193,
      -1,   195,    -1,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,    -1,   210,   211,   212,    -1,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,    -1,   311,    -1,   313,
     314,   315,   316,   317,   318,   319,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    98,    -1,   100,   101,   102,    -1,    -1,
     105,   106,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    -1,    -1,    -1,   124,
      -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,
     135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,
      -1,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,   156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,   184,
      -1,   186,    -1,   188,   189,    -1,   191,   192,   193,    -1,
     195,    -1,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,    -1,    -1,   210,   211,   212,    -1,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,    -1,   258,   259,   260,    -1,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,    -1,   311,    -1,   313,   314,
     315,   316,   317,   318,   319,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
     176,   177,    -1,    -1,   180,   181,   182,    -1,   184,    -1,
     186,    -1,   188,   189,    -1,   191,   192,   193,    -1,   195,
      -1,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,    -1,    -1,   210,   211,   212,    -1,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,    -1,   311,    -1,   313,   314,   315,
     316,   317,   318,   319,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    98,    -1,   100,   101,   102,    -1,    -1,   105,   106,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,   126,
     127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,
     137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,   156,
     157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,   174,    -1,   176,
     177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
      -1,   188,   189,    -1,   191,   192,   193,    -1,   195,    -1,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,    -1,    -1,   210,   211,   212,    -1,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
      -1,   258,   259,   260,    -1,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,    -1,   311,    -1,   313,   314,   315,   316,
     317,   318,   319,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      98,    -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    -1,    -1,    -1,   124,    -1,   126,   127,
     128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,
     138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,
     148,   149,   150,   151,   152,   153,   154,    -1,   156,   157,
     158,   159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,   174,    -1,   176,   177,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,
     188,   189,    -1,   191,   192,   193,    -1,   195,    -1,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
      -1,    -1,   210,   211,   212,    -1,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
     258,   259,   260,    -1,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,    -1,   311,    -1,   313,   314,   315,   316,   317,
     318,   319,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    98,
      -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,
      -1,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,    -1,    -1,   124,    -1,   126,   127,   128,
     129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,
     139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,   156,   157,   158,
     159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,   174,    -1,   176,   177,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,
     189,    -1,   191,   192,   193,    -1,   195,    -1,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,    -1,
      -1,   210,   211,   212,    -1,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,   258,
     259,   260,    -1,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,    -1,   311,    -1,   313,   314,   315,   316,   317,   318,
     319,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    98,    -1,
     100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,    -1,    -1,    -1,   124,    -1,   126,   127,   128,   129,
      -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,   139,
      -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    -1,   156,   157,   158,   159,
     160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,
      -1,   191,   192,   193,    -1,   195,    -1,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,    -1,    -1,
     210,   211,   212,    -1,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,   258,   259,
     260,    -1,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
      -1,   311,    -1,   313,   314,   315,   316,   317,   318,   319,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    98,    -1,   100,
     101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      -1,    -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,
     131,    -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,   156,   157,   158,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,
     191,   192,   193,    -1,   195,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,    -1,   210,
     211,   212,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,    -1,
     311,    -1,   313,   314,   315,   316,   317,   318,   319,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,   158,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,
     192,   193,    -1,   195,    -1,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,    -1,    -1,   210,   211,
     212,    -1,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,    -1,   311,
      -1,   313,   314,   315,   316,   317,   318,   319,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    98,    -1,   100,   101,   102,
      -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    -1,    -1,
      -1,   124,    -1,   126,   127,   128,   129,    -1,   131,    -1,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,   156,   157,   158,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,    -1,   185,   186,    -1,   188,   189,    -1,   191,   192,
     193,    -1,   195,    -1,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,    -1,    -1,   210,   211,   212,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,    -1,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,    -1,   311,    -1,
     313,   314,   315,   316,   317,   318,   319,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    98,    -1,   100,   101,   102,    -1,
      -1,   105,   106,    -1,    -1,    -1,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,    -1,    -1,    -1,
     124,    -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,
      -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   147,   148,   149,   150,   151,   152,   153,
     154,    -1,   156,   157,   158,   159,   160,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
     174,    -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,   187,   188,   189,    -1,   191,   192,   193,
      -1,   195,    -1,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,    -1,   210,   211,   212,    -1,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,    -1,   311,    -1,   313,
     314,   315,   316,   317,   318,   319,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    98,    -1,   100,   101,   102,    -1,    -1,
     105,   106,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    -1,    -1,    -1,   124,
      -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,
     135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,
      -1,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,   156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,    -1,   191,   192,   193,    -1,
     195,    -1,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,    -1,    -1,   210,   211,   212,    -1,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,    -1,   258,   259,   260,    -1,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,    -1,   313,   314,
     315,   316,   317,   318,   319,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
     176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,   191,   192,   193,    -1,   195,
      -1,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,    -1,    -1,   210,   211,   212,    -1,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,    -1,   311,   312,   313,   314,   315,
     316,   317,   318,   319,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    98,    -1,   100,   101,   102,    -1,    -1,   105,   106,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,   126,
     127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,
     137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,   156,
     157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,   174,    -1,   176,
     177,    -1,    -1,   180,   181,   182,    -1,   184,    -1,   186,
      -1,   188,   189,    -1,   191,   192,   193,    -1,   195,    -1,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,    -1,    -1,   210,   211,   212,    -1,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
      -1,   258,   259,   260,    -1,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,    -1,   311,    -1,   313,   314,   315,   316,
     317,   318,   319,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      98,    -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    -1,    -1,    -1,   124,    -1,   126,   127,
     128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,
     138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,
     148,   149,   150,   151,   152,   153,   154,    -1,   156,   157,
     158,   159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,   174,    -1,   176,   177,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,   187,
     188,   189,    -1,   191,   192,   193,    -1,   195,    -1,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
      -1,    -1,   210,   211,   212,    -1,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
     258,   259,   260,    -1,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,    -1,   311,    -1,   313,   314,   315,   316,   317,
     318,   319,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    98,
      -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,
      -1,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,    -1,    -1,   124,    -1,   126,   127,   128,
     129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,
     139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,   156,   157,   158,
     159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,   174,    -1,   176,   177,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,   187,   188,
     189,    -1,   191,   192,   193,    -1,   195,    -1,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,    -1,
      -1,   210,   211,   212,    -1,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,   258,
     259,   260,    -1,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,    -1,   311,    -1,   313,   314,   315,   316,   317,   318,
     319,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    98,    -1,
     100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,    -1,    -1,    -1,   124,    -1,   126,   127,   128,   129,
      -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,   139,
      -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    -1,   156,   157,   158,   159,
     160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,
      -1,   191,   192,   193,    -1,   195,    -1,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,    -1,    -1,
     210,   211,   212,    -1,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,   258,   259,
     260,    -1,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
      -1,   311,    -1,   313,   314,   315,   316,   317,   318,   319,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    98,    -1,   100,
     101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      -1,    -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,
     131,    -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,   156,   157,   158,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,
     191,   192,   193,    -1,   195,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,    -1,   210,
     211,   212,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,    -1,
     311,    -1,   313,   314,   315,   316,   317,   318,   319,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,   158,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,
     192,   193,    -1,   195,    -1,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,    -1,    -1,   210,   211,
     212,    -1,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,    -1,   311,
      -1,   313,   314,   315,   316,   317,   318,   319,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    98,    -1,   100,   101,   102,
      -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    -1,    -1,
      -1,   124,    -1,   126,   127,   128,   129,    -1,   131,    -1,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,   156,   157,    -1,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,   192,
     193,    -1,   195,    -1,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,    -1,    -1,   210,   211,   212,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,    -1,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,    -1,   311,    -1,
     313,   314,   315,   316,   317,   318,   319,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    98,    -1,   100,   101,   102,    -1,
      -1,   105,   106,    -1,    -1,    -1,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,    -1,    -1,    -1,
     124,    -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,
      -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   147,   148,   149,   150,   151,   152,   153,
     154,    -1,   156,   157,    -1,   159,   160,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
     174,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,   193,
      -1,   195,    -1,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,    -1,   210,   211,   212,    -1,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,    -1,   311,    -1,   313,
     314,   315,   316,   317,   318,   319,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    98,    -1,   100,   101,   102,    -1,    -1,
     105,   106,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    -1,    -1,    -1,   124,
      -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,
     135,    -1,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,
      -1,   146,   147,   148,   149,    -1,   151,   152,   153,   154,
      -1,   156,   157,    -1,   159,   160,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,    -1,    -1,    -1,   193,    -1,
     195,    -1,   197,    -1,   199,    -1,   201,   202,   203,   204,
     205,   206,   207,    -1,    -1,   210,   211,   212,    -1,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,    -1,   258,   259,   260,    -1,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,    -1,   311,    -1,   313,   314,
     315,   316,   317,   318,   319,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    -1,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,    -1,   150,   151,   152,    -1,    -1,    -1,
      -1,    -1,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,    -1,    -1,   193,    -1,   195,
      -1,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,    -1,    -1,   210,   211,    -1,    -1,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,    -1,    -1,    11,    12,   313,   314,   315,
     316,   317,   318,   319,    20,    -1,    -1,    -1,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    -1,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,    -1,   150,   151,   152,    -1,    -1,    -1,
      -1,    -1,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,    -1,    -1,   193,    -1,   195,
      -1,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,    -1,    -1,   210,   211,    -1,    -1,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,    -1,    -1,    -1,    16,   313,   314,   315,
     316,   317,   318,   319,    24,    25,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    -1,    -1,
     100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,
      -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,   139,
      -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,    -1,
     150,   151,   152,    -1,    -1,    -1,    -1,    -1,    -1,   159,
     160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,   187,   188,   189,
      -1,    -1,    -1,    -1,    -1,   195,    -1,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,    -1,    -1,
     210,   211,    -1,    -1,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,   258,   259,
     260,    -1,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,    -1,
      -1,    -1,    16,   313,   314,   315,   316,   317,   318,   319,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    -1,    -1,   100,   101,   102,    -1,
      -1,   105,   106,    -1,    -1,    -1,    -1,   111,   112,   113,
     114,   115,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,
      -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   147,   148,    -1,   150,   151,   152,    -1,
      -1,    -1,    -1,    -1,    -1,   159,   160,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,    -1,
      -1,   195,    -1,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,    -1,   210,   211,    -1,    -1,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,    -1,    -1,    -1,    -1,   313,
     314,   315,   316,   317,   318,   319,    18,    19,    -1,    -1,
      -1,    -1,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    -1,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,    -1,   150,   151,
     152,    -1,    -1,    -1,    -1,    -1,    -1,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,
      -1,    -1,    -1,   195,    -1,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,    -1,    -1,   210,   211,
      -1,    -1,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,    -1,    -1,    -1,
      -1,   313,   314,   315,   316,   317,   318,   319,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    -1,    -1,   100,   101,   102,
      -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,    -1,    -1,    -1,
      -1,   124,    -1,   126,   127,   128,   129,    -1,   131,    -1,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,   156,   157,    -1,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,
      -1,    -1,   195,    -1,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,    -1,    -1,   210,   211,   212,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,    -1,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,    -1,   311,    -1,
     313,   314,   315,   316,   317,   318,   319,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    -1,    -1,   100,   101,   102,    -1,    -1,   105,   106,
      -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,
     137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,    -1,   150,   151,   152,    -1,    -1,    -1,   156,
      -1,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
     187,   188,   189,    -1,    -1,    -1,   193,    -1,   195,    -1,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,    -1,    -1,   210,   211,    -1,    -1,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
      -1,   258,   259,   260,    -1,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,    -1,    -1,    24,    25,   313,   314,   315,   316,
     317,   318,   319,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    -1,    -1,
     100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,
      -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,   139,
      -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,    -1,
     150,   151,   152,    -1,    -1,    -1,    -1,    -1,    -1,   159,
     160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,   187,   188,   189,
      -1,    -1,    -1,   193,    -1,   195,    -1,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,    -1,    -1,
     210,   211,    -1,    -1,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,   258,   259,
     260,    -1,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,    -1,
      -1,    24,    25,   313,   314,   315,   316,   317,   318,   319,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    -1,    -1,   100,   101,   102,
      -1,    -1,   105,   106,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,   128,   129,    -1,   131,    -1,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,    -1,   150,   151,   152,
      -1,    -1,    -1,    -1,    -1,    -1,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,   187,   188,   189,    -1,    -1,    -1,
     193,    -1,   195,    -1,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,    -1,    -1,   210,   211,    -1,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,    -1,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,    -1,    -1,    24,    25,
     313,   314,   315,   316,   317,   318,   319,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    -1,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,    -1,   150,   151,   152,    -1,    -1,    -1,
     156,    -1,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,   195,
      -1,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,    -1,    -1,   210,   211,    -1,    -1,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,    -1,    -1,    24,    25,   313,   314,   315,
     316,   317,   318,   319,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    -1,
      -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,
     139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,
      -1,   150,   151,   152,    -1,    -1,    -1,   156,    -1,    -1,
     159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,
     189,    -1,    -1,    -1,    -1,    -1,   195,    -1,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,    -1,
      -1,   210,   211,    -1,    -1,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,   258,
     259,   260,    -1,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
      -1,    -1,    24,    25,   313,   314,   315,   316,   317,   318,
     319,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    -1,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,    -1,   150,   151,
     152,    -1,    -1,    -1,   156,    -1,    -1,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,
      -1,    -1,    -1,   195,    -1,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,    -1,    -1,   210,   211,
      -1,    -1,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,    -1,    -1,    24,
      25,   313,   314,   315,   316,   317,   318,   319,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    -1,    -1,   100,   101,   102,    -1,    -1,
     105,   106,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,
     135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,
      -1,   146,   147,   148,    -1,   150,   151,   152,    -1,    -1,
      -1,   156,    -1,    -1,   159,   160,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,
     195,    -1,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,    -1,    -1,   210,   211,    -1,    -1,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,    -1,   258,   259,   260,    -1,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,    -1,    -1,    24,    25,   313,   314,
     315,   316,   317,   318,   319,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      -1,    -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
     128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,
     138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,
     148,    -1,   150,   151,   152,    -1,    -1,    -1,   156,    -1,
      -1,   159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,
     188,   189,    -1,    -1,    -1,    -1,    -1,   195,    -1,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
      -1,    -1,   210,   211,    -1,    -1,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
     258,   259,   260,    -1,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,    -1,    -1,    24,    25,   313,   314,   315,   316,   317,
     318,   319,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    -1,    -1,   100,
     101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,    -1,
     131,    -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,    -1,   150,
     151,   152,    -1,    -1,    -1,    -1,    -1,    -1,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,
      -1,    -1,    -1,    -1,   195,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,    -1,   210,
     211,    -1,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,    -1,    -1,
      24,    25,   313,   314,   315,   316,   317,   318,   319,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    -1,    -1,   100,   101,   102,    -1,
      -1,   105,   106,    -1,    -1,    -1,    -1,   111,   112,   113,
     114,   115,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,
      -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   147,   148,    -1,   150,   151,   152,    -1,
      -1,    -1,    -1,    -1,    -1,   159,   160,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,    -1,
      -1,   195,    -1,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,    -1,   210,   211,    -1,    -1,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,    -1,    -1,    24,    25,   313,
     314,   315,   316,   317,   318,   319,    33,    34,    -1,    36,
      37,    38,    -1,    40,    41,    42,    43,    -1,    -1,    46,
      47,    -1,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    -1,    60,    -1,    -1,    63,    64,    65,    66,
      67,    -1,    69,    -1,    71,    -1,    -1,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      -1,    -1,    -1,   100,   101,   102,    -1,    -1,   105,   106,
      -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,
     137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,    -1,   150,   151,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
      -1,   188,   189,    -1,    -1,    -1,    -1,    -1,   195,    -1,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,    -1,    -1,    -1,   211,    -1,    -1,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,    -1,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,    -1,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
      -1,   258,   259,   260,    -1,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,    -1,    -1,    -1,    -1,   313,   314,   315,   316,
     317,   318,   319
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,    11,    12,    20,    21,    22,    23,    24,    25,    26,
      27,    29,    33,    34,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    94,
      95,    96,    97,    98,   100,   101,   102,   105,   106,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     124,   126,   127,   128,   129,   131,   135,   136,   137,   138,
     139,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     156,   157,   158,   159,   160,   165,   166,   167,   168,   169,
     170,   171,   172,   174,   176,   177,   180,   181,   182,   186,
     188,   189,   191,   192,   193,   195,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   210,   211,   212,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   258,   259,   260,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   311,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   333,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   354,   355,   356,   357,   358,   359,   363,   364,
     365,   369,   371,   372,   374,   381,   383,   386,   387,   388,
     390,   391,   392,   393,   394,   396,   397,   399,   400,   401,
     402,   403,   404,   406,   407,   410,   411,   412,   413,   418,
     420,   422,   423,   428,   447,   450,   454,   457,   458,   463,
     464,   465,   466,   468,   469,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   515,   516,   517,   531,   532,   534,
     535,   536,   537,   538,   539,   540,   548,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   560,   561,   562,   563,
     568,   569,   570,   571,   572,   573,   576,   634,   635,   636,
     637,   639,   640,   641,   642,   643,   650,   651,   652,    33,
      34,    49,   214,   389,   390,   391,   389,   389,   156,   156,
      37,    38,    40,    41,    47,    56,    57,    74,    79,   111,
     112,   113,   160,   219,   260,   286,   294,   302,   370,   371,
     375,   376,   377,   160,   153,   156,   153,   156,   153,   156,
       1,     3,    66,    71,   118,   415,   156,   378,   156,    24,
      34,    60,   118,   272,   427,   429,   430,   153,   156,   156,
     156,   118,   153,   156,   156,   156,    76,   153,   220,   221,
     122,   122,   122,   153,   156,    39,    43,    45,    46,    47,
      48,    51,    59,    67,    70,    72,    73,    75,    90,    91,
      97,   105,   112,   114,   115,   135,   138,   139,   169,   172,
     180,   181,   189,   201,   223,   225,   227,   228,   235,   237,
     238,   239,   242,   243,   314,   499,   650,   651,   122,   118,
     398,   122,   122,    39,    44,    45,    59,    61,    62,    70,
      97,   224,   650,   118,   122,   122,   184,   389,   391,   411,
     638,    48,    72,    73,   118,   153,   185,   243,   410,   412,
     422,   187,   410,   650,   153,   122,    16,   649,   650,    18,
      19,   650,   122,   122,   122,   491,   153,    30,   213,   215,
     224,   226,   313,   156,   224,   226,   313,   224,   313,   224,
     229,   313,   118,   240,   240,   241,   156,   153,   393,   310,
     410,   312,   410,   313,   321,   335,   335,     0,   337,   338,
      33,    49,   340,   357,     1,   190,   334,   190,   334,   112,
     372,   392,   410,   107,   190,   107,   190,    42,    46,    51,
      69,   168,   171,   186,   211,   405,   414,   419,   420,   421,
     435,   436,   440,   167,    92,   132,   140,   141,   143,   151,
     155,   157,   162,   179,   202,   203,   204,   205,   206,   207,
     483,   484,   248,    99,   158,   176,   198,   117,   146,   159,
     193,   200,   209,   136,   150,    50,   199,   101,   102,   158,
     176,   482,   153,   488,   491,   191,   192,   154,   503,   504,
     499,   503,   499,   156,   503,   145,   156,   184,   184,   184,
     373,   506,   373,    29,   648,   182,   195,   182,   195,   166,
     182,   651,   650,   169,   201,    47,   650,   152,   118,    45,
      47,    79,   106,   168,   649,   220,   221,   222,   245,   607,
     650,   650,   303,   137,   142,   112,   286,   294,   375,   649,
     390,   391,   187,   390,    45,    62,   187,   556,   557,   410,
     187,   193,   650,   424,   425,   650,   283,   283,   424,   118,
     431,   118,   187,   379,   380,   153,   395,   410,     1,   160,
     648,   113,   160,   353,   648,   650,   118,   142,   107,   410,
      29,   187,   649,   650,   650,   448,   449,   650,   390,   187,
     410,   410,   558,   650,   390,   153,   153,   410,   187,   193,
     650,   650,   142,   448,   184,   184,   121,   107,   184,   156,
     156,   156,   650,   153,   185,   186,   187,    35,   519,   520,
     521,   410,     8,   175,    17,   410,   213,    29,   411,   411,
      39,    45,    59,    70,    97,   502,   650,   187,   411,   411,
     153,   154,   411,   502,   411,   230,   229,   574,   575,   650,
     190,   190,   411,   410,   391,   410,   244,   408,   409,   310,
     312,   154,   335,   190,   334,   190,   334,     3,   341,   357,
     387,   341,   357,   387,    33,   358,   387,   358,   387,   398,
     398,   411,   118,   168,   170,   170,   392,   411,   411,   465,
     466,   468,   468,   468,   468,   467,   468,   468,   468,    70,
     469,   473,   473,   472,   474,   474,   474,   474,   475,   475,
     476,   476,   230,    94,    94,    94,   184,   410,   491,   491,
     410,   504,   187,   411,   514,   149,   187,   514,   107,   187,
     187,   107,   107,   378,    29,   651,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,   360,   361,   362,    94,
     137,   142,   366,   367,   368,   650,   160,   160,   360,   648,
     127,   132,    54,    56,   100,   250,   263,   265,   276,   277,
     278,   280,   282,   608,   609,   610,   611,   612,   613,   620,
     626,   627,   245,    94,   298,   650,   142,   411,   118,   650,
     650,   132,   184,   184,   187,   187,   184,   107,   187,   107,
     187,   107,    36,    94,    96,   147,   426,   427,   542,   650,
      55,   216,   253,   416,   417,   650,    94,   107,   187,   389,
     187,   649,    96,    45,   649,   648,    96,   142,   542,   650,
     411,   430,   184,   187,   187,   187,   187,   107,   188,   147,
     542,   184,   187,   187,   153,   184,   390,   390,   184,   107,
     187,   107,   187,   142,   542,   411,   188,   411,   411,   410,
     410,   410,   650,   520,   521,   130,   196,   184,   184,   131,
     190,    94,   217,   218,   232,    94,   217,   218,   232,   411,
     638,   410,    94,    94,   236,   224,   230,   107,   234,   142,
     190,   187,    48,    72,    73,   243,   412,   422,   184,   500,
     580,   409,   410,   357,    33,    33,   190,   334,   190,   113,
     650,   170,   411,   441,   442,   118,   437,   438,   468,   153,
     156,   258,   487,   506,   581,   584,   585,   586,   587,   588,
     592,   594,   596,   597,    47,   152,   156,   210,   316,   317,
     318,   319,   543,   545,   547,   548,   564,   565,   566,   567,
     644,   645,   646,   647,   650,   543,   541,   547,   541,   184,
     185,   107,   187,   187,   506,   148,   165,   148,   165,   137,
     395,   378,   361,   132,   545,   368,   411,   542,   648,   648,
     128,   129,   648,   276,   277,   278,   282,   650,   262,   273,
     262,   273,    29,   285,    96,   113,   156,   614,   617,   608,
      39,    44,    59,    61,    70,    97,   224,   316,   317,   318,
     382,   548,   644,   226,   298,   307,   411,   650,    94,   298,
     648,   153,   558,   559,   650,   558,   559,   118,   425,   127,
     543,   118,   411,   147,   427,   147,    36,   147,   426,   427,
     147,   542,   253,    53,    58,    77,   118,   426,   432,   433,
     434,   417,   542,   543,   380,    94,   184,   197,   132,   352,
     648,   160,   132,    96,   352,   411,   142,   427,   153,   118,
     411,   411,   147,   100,   451,   452,   453,   455,   456,   100,
     459,   460,   461,   462,   390,   184,   184,   153,   558,   558,
     411,   142,   190,   411,   121,   187,   187,   187,    35,   521,
     130,   196,     9,    10,   103,   123,   125,   153,   194,   516,
     518,   529,   530,   533,    29,   231,   233,   411,   411,   411,
     231,   233,   411,   411,   411,   184,   185,   411,   411,   411,
     411,   502,   118,   411,   411,   392,   156,   156,   156,   153,
     186,   244,   577,   578,   209,   393,   185,   190,   113,   387,
     387,   387,   441,    95,   106,   116,   127,   443,   444,   445,
     446,   107,   650,   107,   410,   581,   588,   153,   284,   470,
     633,    96,   169,   251,   252,   254,   261,   271,   283,   582,
     583,   602,   603,   604,   605,   628,   631,   257,   259,   589,
     607,   266,   593,   629,   246,   247,   269,   598,   599,   156,
     156,   545,   156,   156,   156,   156,   156,   144,   176,   193,
     544,   144,   411,   137,   395,   560,   367,   285,    29,    96,
     113,   156,   621,    29,   614,   544,   544,   489,   286,   305,
     542,   382,   226,   190,   389,   187,   187,   144,   187,   187,
     425,   147,   426,   650,   411,   147,   411,   127,   411,   147,
     427,   147,   411,   147,   118,   118,   411,   650,   434,    77,
     543,   392,   411,   648,   107,   352,   411,   142,   389,   449,
     411,   411,   113,   452,   453,   100,   186,   113,   453,   456,
     118,   543,   100,   113,   460,   100,   113,   462,   184,   389,
     187,   187,   411,   411,   197,   459,   132,   194,   518,     7,
     390,   650,   194,   529,   190,   232,   232,   232,   232,   232,
     232,   236,   236,   575,   186,   410,   410,   410,   580,   578,
     500,   198,   648,   128,   129,   445,   446,   446,   442,   106,
     142,   439,   542,   438,   184,   187,   581,   595,   249,   216,
     253,   267,   274,   632,    96,   255,   256,   630,   249,   585,
     632,   472,   602,   586,   147,   281,   590,   591,   630,   285,
     601,    78,   600,   187,   193,   543,   546,   187,   187,   187,
     187,   187,   187,   187,    29,   136,   200,   623,   624,   625,
      29,   622,   623,   270,   618,   107,   615,   170,   650,   256,
     489,   184,   411,   147,   411,   147,   426,   411,   147,   411,
     411,   650,   650,   433,   411,   126,   126,    96,   648,   411,
     184,   186,   186,   411,   392,   411,   186,   186,   650,   186,
     118,   543,   118,   186,   118,   543,   186,   184,   113,   521,
     650,   194,   184,   521,   650,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   187,   187,   187,   153,   579,   411,
     446,   648,   411,   142,   184,   474,    52,   129,   472,   472,
     268,   275,   285,   606,   606,   587,   153,   279,    94,   187,
     107,   187,   621,   621,   625,   107,   187,    29,   619,   630,
     616,   617,   187,   384,   385,   489,   118,   224,   306,   286,
     170,   411,   411,   147,   411,    53,   392,   411,   352,   411,
     392,    94,   392,   411,   650,   186,   650,   411,   650,   186,
     392,   118,    93,   183,   522,   521,   650,   196,   521,    96,
     197,   459,   410,   439,   411,   472,   472,   198,   410,   543,
     543,    94,    29,   264,   107,   107,   446,   542,   650,   118,
     224,   650,   384,   411,   118,   543,    94,   186,    94,   650,
       5,   133,   525,   526,   528,   530,    28,   134,   523,   524,
     527,   530,   196,   521,   196,   315,   113,   184,   439,   472,
     184,   543,   617,   385,   446,   304,   650,   118,   224,   650,
     186,   543,   392,   411,   543,   186,    93,   133,   528,   183,
     134,   527,   196,   411,   118,   411,   304,   650,   118,   392,
     411,   186,   186,   650,   292,   304,   650,   186,   305,   411,
     305,   489,   489,   198,   286,   650,   224,   118,   650,   305,
     489
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
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   332,   333,   333,   333,   333,   334,   335,   335,   335,
     335,   336,   336,   337,   337,   337,   337,   337,   337,   337,
     337,   338,   338,   338,   338,   339,   340,   340,   340,   341,
     341,   341,   341,   341,   342,   342,   342,   342,   342,   342,
     342,   342,   343,   343,   344,   345,   346,   346,   347,   347,
     348,   348,   349,   349,   349,   349,   350,   350,   350,   351,
     351,   351,   351,   352,   352,   353,   353,   354,   354,   354,
     354,   355,   356,   356,   357,   357,   357,   358,   358,   358,
     358,   358,   358,   358,   358,   359,   359,   360,   360,   361,
     362,   362,   362,   362,   362,   362,   362,   362,   362,   362,
     363,   364,   365,   366,   366,   367,   367,   367,   368,   369,
     369,   369,   370,   370,   370,   370,   371,   371,   372,   372,
     372,   372,   373,   373,   374,   374,   375,   375,   376,   376,
     377,   377,   378,   378,   378,   378,   379,   379,   380,   380,
     381,   381,   381,   381,   382,   382,   382,   382,   383,   383,
     384,   384,   385,   385,   385,   385,   386,   386,   386,   386,
     387,   388,   388,   388,   389,   389,   389,   390,   390,   391,
     391,   392,   392,   392,   392,   392,   392,   392,   392,   392,
     392,   392,   392,   393,   393,   394,   395,   396,   397,   397,
     397,   398,   398,   398,   398,   399,   400,   401,   402,   403,
     403,   404,   405,   406,   407,   408,   408,   409,   410,   410,
     411,   411,   411,   411,   411,   411,   412,   412,   412,   412,
     412,   412,   412,   412,   412,   412,   412,   412,   413,   414,
     415,   415,   416,   416,   416,   417,   417,   418,   418,   419,
     420,   420,   420,   421,   421,   421,   421,   421,   422,   422,
     423,   423,   423,   424,   424,   424,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   425,   426,   427,
     428,   429,   429,   430,   430,   430,   430,   431,   431,   432,
     432,   432,   433,   433,   433,   434,   434,   434,   435,   436,
     437,   437,   438,   438,   438,   438,   438,   438,   439,   440,
     440,   441,   441,   442,   442,   443,   443,   443,   443,   443,
     443,   443,   444,   444,   445,   445,   446,   447,   447,   448,
     448,   449,   449,   450,   451,   451,   452,   453,   453,   454,
     455,   455,   456,   457,   457,   458,   458,   459,   459,   460,
     460,   461,   461,   462,   462,   463,   464,   464,   465,   465,
     466,   466,   466,   466,   466,   467,   466,   466,   466,   466,
     468,   468,   469,   469,   470,   470,   471,   471,   472,   472,
     472,   473,   473,   473,   473,   473,   474,   474,   474,   475,
     475,   475,   476,   476,   477,   477,   478,   478,   479,   479,
     480,   480,   481,   481,   481,   481,   482,   482,   482,   483,
     483,   483,   483,   483,   483,   484,   484,   484,   485,   485,
     485,   485,   486,   486,   487,   487,   488,   488,   488,   489,
     489,   489,   489,   490,   491,   491,   491,   492,   492,   493,
     493,   493,   493,   494,   494,   495,   495,   495,   495,   495,
     495,   495,   496,   496,   497,   497,   498,   498,   498,   498,
     498,   499,   499,   500,   500,   501,   501,   501,   501,   502,
     502,   502,   502,   503,   503,   504,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     506,   506,   507,   507,   507,   508,   509,   509,   510,   511,
     512,   513,   513,   514,   514,   515,   515,   516,   516,   516,
     517,   517,   517,   517,   517,   517,   518,   518,   519,   519,
     520,   521,   521,   522,   522,   523,   523,   524,   524,   524,
     524,   525,   525,   526,   526,   526,   526,   527,   527,   528,
     528,   529,   529,   529,   529,   530,   530,   530,   530,   531,
     531,   532,   532,   533,   534,   534,   534,   534,   534,   534,
     535,   536,   536,   537,   537,   538,   539,   540,   540,   541,
     541,   542,   543,   543,   543,   544,   544,   544,   545,   545,
     545,   545,   545,   545,   545,   546,   546,   547,   548,   548,
     548,   548,   548,   548,   548,   548,   548,   549,   550,   550,
     550,   551,   552,   553,   553,   553,   554,   554,   554,   554,
     554,   555,   556,   556,   556,   556,   556,   556,   556,   557,
     558,   559,   560,   561,   561,   562,   563,   564,   564,   565,
     566,   566,   567,   568,   568,   568,   569,   569,   569,   569,
     569,   569,   569,   569,   569,   569,   570,   570,   571,   571,
     572,   573,   574,   574,   575,   576,   577,   577,   578,   579,
     580,   580,   581,   582,   582,   583,   583,   584,   584,   585,
     585,   586,   586,   587,   587,   588,   589,   589,   590,   590,
     591,   592,   592,   592,   593,   593,   594,   595,   595,   596,
     597,   597,   598,   598,   599,   599,   599,   600,   600,   601,
     601,   602,   602,   602,   602,   602,   603,   604,   605,   606,
     606,   606,   607,   607,   608,   608,   608,   608,   608,   608,
     608,   608,   609,   609,   609,   609,   610,   610,   611,   612,
     612,   613,   613,   613,   614,   614,   615,   615,   616,   616,
     617,   618,   618,   619,   619,   620,   620,   620,   621,   621,
     622,   622,   623,   623,   624,   624,   625,   625,   626,   627,
     627,   628,   628,   628,   629,   630,   630,   630,   630,   631,
     631,   632,   632,   633,   634,   634,   635,   635,   636,   636,
     637,   638,   638,   639,   639,   640,   641,   642,   643,   644,
     644,   644,   645,   646,   647,   648,   649,   649,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     652
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  xquery_parser::yyr2_[] =
  {
         0,     2,     1,     2,     2,     3,     2,     1,     2,     1,
       2,     4,     6,     3,     3,     5,     1,     3,     3,     5,
       5,     1,     3,     3,     5,     6,     1,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     4,     3,     3,     3,     3,     3,
       5,     5,     5,     5,     5,     5,     1,     1,     3,     3,
       4,     5,     6,     1,     3,     3,     3,     3,     6,     5,
       8,     5,     5,     5,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     3,     4,     3,     1,     1,     1,     2,     2,     4,
       3,     5,     3,     4,     4,     5,     1,     2,     1,     4,
       1,     4,     1,     3,     2,     3,     1,     1,     4,     4,
       5,     5,     2,     3,     4,     5,     1,     3,     2,     3,
       3,     5,     4,     6,     1,     2,     1,     2,     8,     9,
       1,     3,     1,     2,     2,     3,    11,    14,    13,    22,
       1,     1,     1,     0,     1,     1,     0,     1,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     3,     3,     2,     3,     2,
       3,     2,     3,     4,     5,     5,     2,     4,     5,     3,
       3,     2,     2,     8,     3,     1,     2,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     1,     1,     2,     4,     3,     5,     4,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       3,     3,     2,     1,     4,     3,     3,     5,     4,     6,
       4,     6,     5,     7,     4,     5,     5,     6,     3,     3,
       2,     1,     3,     4,     5,     3,     6,     4,     5,     1,
       2,     3,     1,     2,     1,     6,     3,     3,     2,     3,
       1,     3,     2,     4,     5,     6,     5,     3,     2,     3,
       4,     1,     3,     1,     2,     1,     1,     1,     2,     2,
       2,     3,     1,     1,     2,     2,     2,     5,     5,     1,
       4,     3,     4,     8,     1,     2,     3,     2,     3,     8,
       1,     2,     3,     8,    10,     8,    10,     1,     2,     4,
       7,     1,     2,     4,     7,     8,     1,     3,     1,     3,
       1,     3,     3,     3,     3,     0,     4,     3,     3,     3,
       1,     5,     1,     3,     0,     1,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     4,     1,     4,     1,     4,     1,     4,
       1,     2,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     5,
       5,     6,     3,     4,     1,     2,     3,     2,     2,     1,
       2,     2,     1,     1,     1,     3,     3,     1,     1,     1,
       2,     1,     2,     2,     1,     2,     2,     2,     2,     2,
       2,     2,     1,     2,     2,     1,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     4,     1,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     3,     1,     4,
       4,     3,     4,     1,     3,     1,     1,     1,     1,     1,
       4,     5,     8,     9,     9,    10,     1,     2,     1,     2,
       6,     0,     1,     3,     3,     0,     1,     1,     1,     2,
       2,     0,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       2,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       4,     3,     7,     3,     7,     4,     4,     3,     7,     1,
       2,     2,     1,     2,     3,     1,     1,     1,     1,     1,
       3,     3,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     4,
       4,     3,     3,     3,     4,     4,     3,     4,     6,     4,
       6,     4,     3,     4,     6,     6,     4,     6,     6,     4,
       1,     2,     1,     1,     1,     3,     3,     1,     1,     4,
       5,     6,     3,     3,     3,     3,     5,     7,     7,     5,
       5,     5,     7,     7,     5,     5,     3,     3,     5,     7,
       5,     7,     1,     4,     3,     5,     1,     2,     3,     3,
       1,     3,     2,     0,     1,     1,     2,     1,     3,     1,
       3,     1,     4,     1,     2,     3,     0,     1,     0,     1,
       4,     2,     3,     1,     0,     1,     4,     0,     1,     2,
       1,     3,     0,     1,     2,     2,     1,     0,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       1,     1,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     1,     2,     2,     3,     1,
       2,     2,     5,     2,     1,     1,     0,     2,     1,     3,
       4,     0,     2,     0,     2,     4,     4,     3,     2,     3,
       1,     3,     0,     1,     1,     2,     2,     2,     2,     1,
       2,     2,     2,     2,     3,     2,     3,     3,     4,     2,
       2,     1,     1,     3,     2,     3,     2,     3,     2,     3,
       3,     3,     5,     7,    10,     7,     3,     5,     7,     1,
       1,     1,     3,     3,     3,     1,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const xquery_parser::yytname_[] =
  {
    "\"'end of file'\"", "error", "$undefined", "\"'unrecognized'\"",
  "\"'error'\"", "\"'apos attribute content'\"", "\"'char literal'\"",
  "\"'char literal]]>'\"", "\"'char literal and pi end'\"",
  "\"'&#charref;'\"", "\"'element content'\"", "\"'pref:*'\"",
  "\"'ns:*'\"", "\"'&entity;'\"", "\"'comment literal'\"",
  "\"'pi <NCName {>'\"", "\"'NCName_sval'\"", "\"'pragma literal'\"",
  "\"'QName #)'\"", "\"'EQName #)'\"", "\"'*:QName'\"",
  "\"'element QName {'\"", "\"'attribute QName {'\"",
  "\"'processing-instruction NCName {'\"", "\"'QName'\"", "\"'EQName'\"",
  "\"'%QName'\"", "\"'%EQName'\"", "\"'quote attribute content'\"",
  "\"'STRING'\"", "\"'XML comment'\"", "\"'URI'\"", "\"'NCName'\"",
  "\"'declare'\"", "\"'module'\"", "\"'<blank>'\"", "\"'allowing'\"",
  "\"'base-uri'\"", "\"'boundary-space'\"", "\"'comment'\"",
  "\"'construction'\"", "\"'copy-namespaces'\"", "\"'count'\"",
  "\"'document'\"", "\"'document-node'\"", "\"'element'\"", "\"'for'\"",
  "\"'function'\"", "\"'if'\"", "\"'import'\"", "\"'instance'\"",
  "\"'let'\"", "\"'most'\"", "\"'next'\"", "\"'no'\"", "\"'only'\"",
  "\"'option'\"", "\"'ordering'\"", "\"'previous'\"",
  "\"'processing-instruction'\"", "\"'schema'\"", "\"'schema-attribute'\"",
  "\"'schema-element'\"", "\"'sequential'\"", "\"'set'\"", "\"'simple'\"",
  "\"'sliding'\"", "\"'some'\"", "\"'space'\"", "\"'stable'\"",
  "\"'text'\"", "\"'tumbling'\"", "\"'switch'\"", "\"'typeswitch'\"",
  "\"'updating'\"", "\"'validate'\"", "\"'type'\"", "\"'when'\"",
  "\"'word'\"", "\"'decimal-format'\"", "\"'decimal-separator'\"",
  "\"'grouping-separator'\"", "\"'infinity'\"", "\"'minus-sign'\"",
  "\"'NaN'\"", "\"'percent'\"", "\"'per-mille'\"", "\"'zero-digit'\"",
  "\"'digit'\"", "\"'pattern-separator'\"", "\"'ancestor'\"",
  "\"'ancestor-or-self'\"", "\"'and'\"", "\"'''\"", "\"'as'\"",
  "\"'ascending'\"", "\"'at'\"", "\"'attribute'\"", "\"'@'\"", "\"'||'\"",
  "\"'case'\"", "\"'castable'\"", "\"'cast'\"", "\"'CDATA[['\"",
  "\"']]'\"", "\"'child'\"", "\"'collation'\"", "\"','\"", "\"'(:'\"",
  "\"':)'\"", "\"'DECIMAL'\"", "\"'context'\"", "\"'variable'\"",
  "\"'default'\"", "\"'descendant'\"", "\"'descendant-or-self'\"",
  "\"'descending'\"", "\"'div'\"", "\"'$'\"", "\"'.'\"", "\"'..'\"",
  "\"':'\"", "\"'::'\"", "\"'{{'\"", "\"'DOUBLE'\"", "\"'<double {>'\"",
  "\"'else'\"", "\"'empty'\"", "\"'greatest'\"", "\"'least'\"", "\"'/>'\"",
  "\"'encoding'\"", "\"'='\"", "\"''''\"", "\"'\\\"\\\"'\"", "\"'every'\"",
  "\"'except'\"", "\"'external'\"", "\"'following'\"",
  "\"'following-sibling'\"", "\"'follows'\"", "\"'>='\"", "\"':='\"",
  "\"'>'\"", "\"'?'\"", "\"'#'\"", "\"'idiv'\"", "\"'in'\"",
  "\"'inherit'\"", "\"'INTEGER'\"", "\"'intersect'\"", "\"'is'\"",
  "\"'item'\"", "\"'{'\"", "\"'['\"", "\"'<='\"", "\"'('\"", "\"'<'\"",
  "\"'-'\"", "\"'mod'\"", "\"'namespace'\"", "\"'nan'\"", "\"'!='\"",
  "\"'nodecomp'\"", "\"'?""?'\"", "\"'<no inherit>'\"",
  "\"'<no preserve>'\"", "\"'or'\"", "\"'order'\"", "\"'ordered'\"",
  "\"'by'\"", "\"'group'\"", "\"'parent'\"", "\"'%'\"", "\"'<?'\"",
  "\"'?>'\"", "\"'+'\"", "\"'(#'\"", "\"'#)'\"", "\"'<<'\"",
  "\"'preceding'\"", "\"'preceding-sibling'\"", "\"'preserve'\"",
  "\"'\\\"'\"", "\"'}'\"", "\"']'\"", "\"'return'\"", "\"')'\"",
  "\"'satisfies'\"", "\"'self'\"", "\"';'\"", "\"'/'\"", "\"'//'\"",
  "\"'*'\"", "\"'</ (start tag end)'\"", "\"'strip'\"",
  "\"'> (tag end)'\"", "\"'then'\"", "\"'to'\"", "\"'treat'\"",
  "\"'union'\"", "\"'unordered'\"", "\"'eq'\"", "\"'ge'\"", "\"'gt'\"",
  "\"'le'\"", "\"'lt'\"", "\"'ne'\"", "\"'VALUECOMP'\"", "\"'|'\"",
  "\"'empty-sequence'\"", "\"'where'\"", "\"'<!--'\"", "\"'-->'\"",
  "\"'xquery'\"", "\"'version'\"", "\"'start'\"", "\"'after'\"",
  "\"'before'\"", "\"'revalidation'\"", "\"'strict'\"", "\"'lax'\"",
  "\"'skip'\"", "\"'delete'\"", "\"'node'\"", "\"'insert'\"",
  "\"'nodes'\"", "\"'rename'\"", "\"'replace'\"", "\"'value'\"",
  "\"'of'\"", "\"'first'\"", "\"'into'\"", "\"'last'\"", "\"'modify'\"",
  "\"'copy'\"", "\"'with'\"", "\"'break'\"", "\"'continue'\"",
  "\"'exit'\"", "\"'loop'\"", "\"'returning'\"", "\"'while'\"",
  "\"'try'\"", "\"'catch'\"", "\"'using'\"", "\"'all'\"", "\"'any'\"",
  "\"'contains'\"", "\"'content'\"", "\"'diacritics'\"", "\"'different'\"",
  "\"'distance'\"", "\"'end'\"", "\"'entire'\"", "\"'exactly'\"",
  "\"'from'\"", "\"'ftand'\"", "\"'ftnot'\"", "\"'not'\"",
  "\"'ft-option'\"", "\"'ftor'\"", "\"'insensitive'\"", "\"'language'\"",
  "\"'levels'\"", "\"'lowercase'\"", "\"'occurs'\"", "\"'paragraph'\"",
  "\"'paragraphs'\"", "\"'phrase'\"", "\"'relationship'\"", "\"'same'\"",
  "\"'score'\"", "\"'sensitive'\"", "\"'sentence'\"", "\"'sentences'\"",
  "\"'stemming'\"", "\"'stop'\"", "\"'thesaurus'\"", "\"'times'\"",
  "\"'uppercase'\"", "\"'weight'\"", "\"'wildcards'\"", "\"'window'\"",
  "\"'without'\"", "\"'words'\"", "\"'collection'\"", "\"'const'\"",
  "\"'append-only'\"", "\"'queue'\"", "\"'mutable'\"", "\"'read-only'\"",
  "\"'unique'\"", "\"'non'\"", "\"'index'\"", "\"'manually'\"",
  "\"'automatically'\"", "\"'maintained'\"", "\"'on'\"", "\"'range'\"",
  "\"'equality'\"", "\"'general'\"", "\"'integrity'\"", "\"'constraint'\"",
  "\"'check'\"", "\"'key'\"", "\"'foreach'\"", "\"'foreign'\"",
  "\"'keys'\"", "\"'{|'\"", "\"'|}'\"", "\"'{['\"", "\"']}'\"",
  "\"'json'\"", "\"'append'\"", "\"'position'\"", "\"'object'\"",
  "\"'array'\"", "\"'json-item'\"", "\"'structured-item'\"",
  "\"'BOM_UTF8'\"", "\"'#!/shebang\"", "RANGE_REDUCE",
  "SEQUENCE_TYPE_REDUCE", "ADDITIVE_REDUCE", "UNION_REDUCE",
  "INTERSECT_EXCEPT_REDUCE", "QVARINDECLLIST_REDUCE", "COMMA_DOLLAR",
  "UNARY_PREC", "STEP_REDUCE", "MULTIPLICATIVE_REDUCE", "$accept",
  "Module", "ERROR", "ModuleWithoutBOM", "VersionDecl", "MainModule",
  "LibraryModule", "ModuleDecl", "SIND_DeclList", "SIND_Decl", "Setter",
  "BoundarySpaceDecl", "DefaultCollationDecl", "BaseURIDecl",
  "ConstructionDecl", "OrderingModeDecl", "EmptyOrderDecl",
  "CopyNamespacesDecl", "Import", "SchemaImport", "URILiteralList",
  "SchemaPrefix", "ModuleImport", "NamespaceDecl", "DefaultNamespaceDecl",
  "VFO_DeclList", "VFO_Decl", "DecimalFormatDecl",
  "DecimalFormatParamList", "DecimalFormatParam", "DecimalFormatParamName",
  "OptionDecl", "FTOptionDecl", "CtxItemDecl", "CtxItemDecl2",
  "CtxItemDecl3", "CtxItemDecl4", "VarDecl", "VarNameAndType",
  "AnnotationList", "Annotation", "AnnotationLiteralList", "FunctionDecl",
  "FunctionDecl2", "FunctionDeclSimple", "FunctionDeclUpdating",
  "FunctionSig", "ParamList", "Param", "CollectionDecl",
  "CollectionTypeDecl", "IndexDecl", "IndexKeyList", "IndexKeySpec",
  "IntegrityConstraintDecl", "QueryBody", "StatementsAndOptionalExprTop",
  "StatementsAndOptionalExpr", "StatementsAndExpr", "Statements",
  "Statement", "BlockStatement", "BlockExpr",
  "EnclosedStatementsAndOptionalExpr", "VarDeclStatement",
  "BlockVarDeclList", "BlockVarDecl", "AssignStatement", "ApplyStatement",
  "ExitStatement", "WhileStatement", "FlowCtlStatement", "FLWORStatement",
  "ReturnStatement", "IfStatement", "TryStatement", "CatchListStatement",
  "CatchStatement", "Expr", "ExprSingle", "ExprSimple", "FLWORExpr",
  "ReturnExpr", "WindowType", "FLWORWinCondType", "FLWORWinCond",
  "WindowClause", "CountClause", "ForLetWinClause", "FLWORClause",
  "FLWORClauseList", "ForClause", "VarInDeclList", "VarInDecl",
  "PositionalVar", "FTScoreVar", "LetClause", "VarGetsDeclList",
  "VarGetsDecl", "WindowVarDecl", "WindowVars", "WindowVars3",
  "WindowVars2", "WhereClause", "GroupByClause", "GroupSpecList",
  "GroupSpec", "GroupCollationSpec", "OrderByClause", "OrderSpecList",
  "OrderSpec", "OrderModifier", "OrderDirSpec", "OrderEmptySpec",
  "OrderCollationSpec", "QuantifiedExpr", "QVarInDeclList", "QVarInDecl",
  "SwitchExpr", "SwitchCaseClauseList", "SwitchCaseClause",
  "SwitchCaseOperandList", "SwitchStatement", "SwitchCaseStatementList",
  "SwitchCaseStatement", "TypeswitchExpr", "TypeswitchStatement",
  "CaseClauseList", "CaseClause", "CaseStatementList", "CaseStatement",
  "IfExpr", "OrExpr", "AndExpr", "ComparisonExpr", "$@1", "FTContainsExpr",
  "StringConcatExpr", "opt_FTIgnoreOption", "RangeExpr", "AdditiveExpr",
  "MultiplicativeExpr", "UnionExpr", "IntersectExceptExpr",
  "InstanceofExpr", "TreatExpr", "CastableExpr", "CastExpr", "UnaryExpr",
  "SignList", "ValueExpr", "ValueComp", "NodeComp", "ValidateExpr",
  "ExtensionExpr", "Pragma_list", "Pragma", "PathExpr", "LeadingSlash",
  "RelativePathExpr", "StepExpr", "AxisStep", "ForwardStep", "ForwardAxis",
  "AbbrevForwardStep", "ReverseStep", "ReverseAxis", "NodeTest",
  "NameTest", "Wildcard", "FilterExpr", "PredicateList", "Predicate",
  "PrimaryExpr", "Literal", "NumericLiteral", "VarRef",
  "ParenthesizedExpr", "ContextItemExpr", "OrderedExpr", "UnorderedExpr",
  "FunctionCall", "ArgList", "Constructor", "DirectConstructor",
  "DirElemConstructor", "DirElemContentList", "DirAttributeList",
  "DirAttr", "OptionalBlank", "DirAttributeValue",
  "opt_QuoteAttrContentList", "QuoteAttrContentList",
  "opt_AposAttrContentList", "AposAttrContentList",
  "QuoteAttrValueContent", "AposAttrValueContent", "DirElemContent",
  "CommonContent", "DirCommentConstructor", "DirPIConstructor",
  "CDataSection", "ComputedConstructor", "CompDocConstructor",
  "CompElemConstructor", "CompAttrConstructor", "CompTextConstructor",
  "CompCommentConstructor", "CompPIConstructor", "SingleType",
  "TypeDeclaration", "SequenceType", "OccurrenceIndicator", "ItemType",
  "TypeList", "AtomicType", "KindTest", "AnyKindTest", "DocumentTest",
  "TextTest", "CommentTest", "PITest", "AttributeTest",
  "SchemaAttributeTest", "ElementTest", "SchemaElementTest", "TypeName",
  "TypeName_WITH_HOOK", "StringLiteral", "FunctionItemExpr",
  "LiteralFunctionItem", "InlineFunction", "FunctionTest",
  "AnyFunctionTest", "TypedFunctionTest", "ParenthesizedItemType",
  "RevalidationDecl", "InsertExpr", "DeleteExpr", "ReplaceExpr",
  "RenameExpr", "TransformExpr", "VarNameList", "VarNameDecl", "TryExpr",
  "CatchListExpr", "CatchExpr", "BracedExpr", "NameTestList",
  "FTSelection", "opt_FTPosFilter_list", "FTPosFilter_list", "FTOr",
  "FTAnd", "FTMildNot", "FTUnaryNot", "FTPrimaryWithOptions",
  "opt_FTMatchOptions", "opt_FTWeight", "FTWeight", "FTPrimary",
  "opt_FTTimes", "FTExtensionSelection", "opt_FTSelection", "FTWords",
  "FTWordsValue", "opt_FTAnyallOption", "FTAnyallOption", "opt_word",
  "opt_words", "FTPosFilter", "FTOrder", "FTWindow", "FTDistance",
  "FTUnit", "FTMatchOptions", "FTMatchOption", "FTCaseOption",
  "FTDiacriticsOption", "FTExtensionOption", "FTStemOption",
  "FTThesaurusOption", "FTThesaurusID_or_default", "opt_FTThesaurus_list",
  "FTThesaurus_list", "FTThesaurusID", "opt_relationship", "opt_levels",
  "FTStopWordOption", "FTStopWords", "STRING_LITERAL_list",
  "opt_FTStopWordsInclExcl_list", "FTStopWordsInclExcl_list",
  "FTStopWordsInclExcl", "FTLanguageOption", "FTWildCardOption",
  "FTContent", "FTTimes", "FTRange", "FTScope", "FTBigUnit",
  "FTIgnoreOption", "JSONArrayConstructor", "JSONSimpleObjectUnion",
  "JSONAccumulatorObjectUnion", "JSONObjectConstructor", "JSONPairList",
  "JSONInsertExpr", "JSONAppendExpr", "JSONDeleteExpr", "JSONRenameExpr",
  "JSONReplaceExpr", "JSONTest", "JSONItemTest", "JSONObjectTest",
  "JSONArrayTest", "URI_LITERAL", "NCNAME", "QNAME", "FUNCTION_NAME",
  "EQNAME", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const xquery_parser::rhs_number_type
  xquery_parser::yyrhs_[] =
  {
       333,     0,    -1,   335,    -1,   320,   335,    -1,   321,   335,
      -1,   320,   321,   335,    -1,     1,     3,    -1,   337,    -1,
     336,   337,    -1,   338,    -1,   336,   338,    -1,   214,   215,
      29,   190,    -1,   214,   215,    29,   131,    29,   190,    -1,
     340,   190,   387,    -1,   357,   190,   387,    -1,   340,   190,
     357,   190,   387,    -1,   387,    -1,   340,   334,   387,    -1,
     357,   334,   387,    -1,   340,   190,   357,   334,   387,    -1,
     340,   334,   357,   190,   387,    -1,   339,    -1,   339,   340,
     190,    -1,   339,   357,   190,    -1,   339,   340,   190,   357,
     190,    -1,    34,   160,   649,   132,   648,   190,    -1,   341,
      -1,   340,   190,   341,    -1,   340,   334,   341,    -1,   342,
      -1,   350,    -1,   355,    -1,   356,    -1,   364,    -1,   343,
      -1,   344,    -1,   345,    -1,   346,    -1,   347,    -1,   348,
      -1,   349,    -1,   568,    -1,    33,    38,   182,    -1,    33,
      38,   195,    -1,    33,   113,   106,   648,    -1,    33,    37,
     648,    -1,    33,    40,   182,    -1,    33,    40,   195,    -1,
      33,    57,   169,    -1,    33,    57,   201,    -1,    33,   113,
     168,   127,   128,    -1,    33,   113,   168,   127,   129,    -1,
      33,    41,   182,   107,   148,    -1,    33,    41,   182,   107,
     165,    -1,    33,    41,   166,   107,   148,    -1,    33,    41,
     166,   107,   165,    -1,   351,    -1,   354,    -1,    49,    24,
       1,    -1,    49,    60,   648,    -1,    49,    60,   353,   648,
      -1,    49,    60,   648,    96,   352,    -1,    49,    60,   353,
     648,    96,   352,    -1,   648,    -1,   352,   107,   648,    -1,
     160,   649,   132,    -1,   113,    45,   160,    -1,    49,    34,
     648,    -1,    49,    34,   160,   649,   132,   648,    -1,    49,
      34,   648,    96,   352,    -1,    49,    34,   160,   649,   132,
     648,    96,   352,    -1,    33,   160,   649,   132,   648,    -1,
      33,   113,    45,   160,   648,    -1,    33,   113,    47,   160,
     648,    -1,   358,    -1,   357,   190,   358,    -1,   357,   334,
     358,    -1,   359,    -1,   363,    -1,   365,    -1,   369,    -1,
     374,    -1,   381,    -1,   383,    -1,   386,    -1,    33,   113,
      79,   360,    -1,    33,    79,   650,   360,    -1,   361,    -1,
     360,   361,    -1,   362,   132,   560,    -1,    80,    -1,    88,
      -1,    81,    -1,    82,    -1,    83,    -1,    84,    -1,    89,
      -1,    85,    -1,    86,    -1,    87,    -1,    33,    56,   650,
      29,    -1,    33,   260,   607,    -1,    33,   111,   152,   366,
      -1,    94,   545,   367,    -1,   367,    -1,   368,    -1,   137,
      -1,   137,   368,    -1,   142,   411,    -1,    33,   370,   142,
     411,    -1,    33,   370,   137,    -1,    33,   370,   137,   142,
     411,    -1,   112,   118,   650,    -1,   112,   118,   650,   542,
      -1,   371,   112,   118,   650,    -1,   371,   112,   118,   650,
     542,    -1,   372,    -1,   371,   372,    -1,    26,    -1,    26,
     156,   373,   187,    -1,    27,    -1,    27,   156,   373,   187,
      -1,   506,    -1,   373,   107,   506,    -1,    33,   375,    -1,
      33,   371,   375,    -1,   376,    -1,   377,    -1,    47,   651,
     378,   395,    -1,    47,   651,   378,   137,    -1,    74,    47,
     651,   378,   395,    -1,    74,    47,   651,   378,   137,    -1,
     156,   187,    -1,   156,   379,   187,    -1,   156,   187,    94,
     543,    -1,   156,   379,   187,    94,   543,    -1,   380,    -1,
     379,   107,   380,    -1,   118,   650,    -1,   118,   650,   542,
      -1,    33,   286,   650,    -1,    33,   286,   650,    94,   382,
      -1,    33,   371,   286,   650,    -1,    33,   371,   286,   650,
      94,   382,    -1,   548,    -1,   548,   544,    -1,   644,    -1,
     644,   544,    -1,    33,   294,   650,   298,   226,   489,   170,
     384,    -1,    33,   371,   294,   650,   298,   226,   489,   170,
     384,    -1,   385,    -1,   384,   107,   385,    -1,   489,    -1,
     489,   542,    -1,   489,   446,    -1,   489,   542,   446,    -1,
      33,   302,   303,   650,   298,   286,   650,   118,   650,   304,
     411,    -1,    33,   302,   303,   650,   298,   286,   650,   224,
     118,   650,   304,   292,   305,   489,    -1,    33,   302,   303,
     650,   298,   286,   650,   306,   224,   118,   650,   304,   411,
      -1,    33,   302,   303,   650,   307,   305,   256,   286,   650,
     224,   118,   650,   305,   489,   198,   286,   650,   224,   118,
     650,   305,   489,    -1,   388,    -1,   390,    -1,   391,    -1,
      -1,   390,    -1,   391,    -1,    -1,   410,    -1,   391,   410,
      -1,   392,    -1,   391,   392,    -1,   393,    -1,   396,    -1,
     399,    -1,   400,    -1,   401,    -1,   402,    -1,   403,    -1,
     404,    -1,   406,    -1,   458,    -1,   454,    -1,   407,    -1,
     153,   391,   184,    -1,   153,   184,    -1,   153,   389,   184,
      -1,   153,   389,   184,    -1,   397,   190,    -1,   397,   107,
     398,    -1,   112,   398,    -1,   371,   112,   398,    -1,   118,
     650,    -1,   118,   650,   542,    -1,   118,   650,   142,   411,
      -1,   118,   650,   542,   142,   411,    -1,   118,   650,   142,
     411,   190,    -1,   412,   190,    -1,   239,   241,   411,   190,
      -1,   242,   156,   410,   187,   392,    -1,   237,   240,   190,
      -1,   238,   240,   190,    -1,   422,   405,    -1,   186,   392,
      -1,    48,   156,   410,   187,   197,   392,   126,   392,    -1,
     243,   393,   408,    -1,   409,    -1,   408,   409,    -1,   244,
     580,   393,    -1,   411,    -1,   410,   107,   411,    -1,   413,
      -1,   450,    -1,   457,    -1,   463,    -1,   576,    -1,   412,
      -1,   464,    -1,   447,    -1,   569,    -1,   570,    -1,   572,
      -1,   571,    -1,   573,    -1,   641,    -1,   639,    -1,   642,
      -1,   643,    -1,   640,    -1,   422,   414,    -1,   186,   411,
      -1,    66,   283,    -1,    71,   283,    -1,   216,    -1,   253,
      -1,    55,   253,    -1,   416,   432,    77,   411,    -1,   416,
      77,   411,    -1,    46,   415,   431,   417,   417,    -1,    46,
     415,   431,   417,    -1,    42,   118,   650,    -1,   423,    -1,
     428,    -1,   418,    -1,   420,    -1,   435,    -1,   440,    -1,
     436,    -1,   419,    -1,   420,    -1,   422,   421,    -1,    46,
     118,   424,    -1,    46,     1,   424,    -1,    46,     3,    -1,
     425,    -1,   424,   107,   118,   425,    -1,   424,   107,   425,
      -1,   650,   147,   411,    -1,   650,    36,   127,   147,   411,
      -1,   650,   542,   147,   411,    -1,   650,   542,    36,   127,
     147,   411,    -1,   650,   426,   147,   411,    -1,   650,    36,
     127,   426,   147,   411,    -1,   650,   542,   426,   147,   411,
      -1,   650,   542,    36,   127,   426,   147,   411,    -1,   650,
     427,   147,   411,    -1,   650,   542,   427,   147,   411,    -1,
     650,   426,   427,   147,   411,    -1,   650,   542,   426,   427,
     147,   411,    -1,    96,   118,   650,    -1,   272,   118,   650,
      -1,    51,   429,    -1,   430,    -1,   429,   107,   430,    -1,
     118,   650,   142,   411,    -1,   118,   650,   542,   142,   411,
      -1,   427,   142,   411,    -1,   118,   650,   542,   427,   142,
     411,    -1,   118,   650,   147,   411,    -1,   118,   650,   542,
     147,   411,    -1,   433,    -1,   118,   650,    -1,   118,   650,
     433,    -1,   426,    -1,   426,   434,    -1,   434,    -1,    58,
     118,   650,    53,   118,   650,    -1,    53,   118,   650,    -1,
      58,   118,   650,    -1,   211,   411,    -1,   171,   170,   437,
      -1,   438,    -1,   437,   107,   438,    -1,   118,   650,    -1,
     118,   650,   142,   411,    -1,   118,   650,   542,   142,   411,
      -1,   118,   650,   542,   142,   411,   439,    -1,   118,   650,
     142,   411,   439,    -1,   118,   650,   439,    -1,   106,   648,
      -1,   168,   170,   441,    -1,    69,   168,   170,   441,    -1,
     442,    -1,   441,   107,   442,    -1,   411,    -1,   411,   443,
      -1,   444,    -1,   445,    -1,   446,    -1,   444,   445,    -1,
     444,   446,    -1,   445,   446,    -1,   444,   445,   446,    -1,
      95,    -1,   116,    -1,   127,   128,    -1,   127,   129,    -1,
     106,   648,    -1,    67,   118,   448,   188,   411,    -1,   135,
     118,   448,   188,   411,    -1,   449,    -1,   448,   107,   118,
     449,    -1,   650,   147,   411,    -1,   650,   542,   147,   411,
      -1,    72,   156,   410,   187,   451,   113,   186,   411,    -1,
     452,    -1,   451,   452,    -1,   453,   186,   411,    -1,   100,
     411,    -1,   453,   100,   411,    -1,    72,   156,   410,   187,
     455,   113,   186,   392,    -1,   456,    -1,   455,   456,    -1,
     453,   186,   392,    -1,    73,   156,   410,   187,   459,   113,
     186,   411,    -1,    73,   156,   410,   187,   459,   113,   118,
     650,   186,   411,    -1,    73,   156,   410,   187,   461,   113,
     186,   392,    -1,    73,   156,   410,   187,   459,   113,   118,
     650,   186,   392,    -1,   460,    -1,   459,   460,    -1,   100,
     543,   186,   411,    -1,   100,   118,   650,    94,   543,   186,
     411,    -1,   462,    -1,   461,   462,    -1,   100,   543,   186,
     392,    -1,   100,   118,   650,    94,   543,   186,   392,    -1,
      48,   156,   410,   187,   197,   411,   126,   411,    -1,   465,
      -1,   464,   167,   465,    -1,   466,    -1,   465,    92,   466,
      -1,   468,    -1,   468,   483,   468,    -1,   468,   484,   468,
      -1,   468,   132,   468,    -1,   468,   162,   468,    -1,    -1,
     468,   157,   467,   468,    -1,   468,   155,   468,    -1,   468,
     143,   468,    -1,   468,   141,   468,    -1,   469,    -1,   469,
     248,    70,   581,   470,    -1,   471,    -1,   471,    99,   469,
      -1,    -1,   633,    -1,   472,    -1,   472,   198,   472,    -1,
     473,    -1,   472,   176,   473,    -1,   472,   158,   473,    -1,
     474,    -1,   473,   193,   474,    -1,   473,   117,   474,    -1,
     473,   146,   474,    -1,   473,   159,   474,    -1,   475,    -1,
     474,   200,   475,    -1,   474,   209,   475,    -1,   476,    -1,
     475,   150,   476,    -1,   475,   136,   476,    -1,   477,    -1,
     477,    50,   230,   543,    -1,   478,    -1,   478,   199,    94,
     543,    -1,   479,    -1,   479,   101,    94,   541,    -1,   480,
      -1,   480,   102,    94,   541,    -1,   482,    -1,   481,   482,
      -1,   176,    -1,   158,    -1,   481,   176,    -1,   481,   158,
      -1,   485,    -1,   489,    -1,   486,    -1,   202,    -1,   207,
      -1,   206,    -1,   205,    -1,   204,    -1,   203,    -1,   151,
      -1,   179,    -1,   140,    -1,    75,   153,   390,   184,    -1,
      75,   221,   153,   390,   184,    -1,    75,   220,   153,   390,
     184,    -1,    75,    76,   558,   153,   390,   184,    -1,   487,
     153,   184,    -1,   487,   153,   410,   184,    -1,   488,    -1,
     487,   488,    -1,   177,   650,    17,    -1,   177,    18,    -1,
     177,    19,    -1,   490,    -1,   490,   491,    -1,   192,   491,
      -1,   491,    -1,   191,    -1,   492,    -1,   492,   191,   491,
      -1,   492,   192,   491,    -1,   493,    -1,   502,    -1,   494,
      -1,   494,   503,    -1,   497,    -1,   497,   503,    -1,   495,
     499,    -1,   496,    -1,   105,   122,    -1,   114,   122,    -1,
      97,   122,    -1,   189,   122,    -1,   115,   122,    -1,   139,
     122,    -1,   138,   122,    -1,   499,    -1,    98,   499,    -1,
     498,   499,    -1,   120,    -1,   172,   122,    -1,    90,   122,
      -1,   181,   122,    -1,   180,   122,    -1,    91,   122,    -1,
     548,    -1,   500,    -1,   650,    -1,   501,    -1,   193,    -1,
      11,    -1,    12,    -1,    20,    -1,   505,    -1,   502,   503,
      -1,   502,   156,   187,    -1,   502,   156,   514,   187,    -1,
     504,    -1,   503,   504,    -1,   154,   410,   185,    -1,   506,
      -1,   508,    -1,   509,    -1,   510,    -1,   513,    -1,   515,
      -1,   511,    -1,   512,    -1,   561,    -1,   394,    -1,   637,
      -1,   634,    -1,   635,    -1,   636,    -1,   507,    -1,   560,
      -1,   110,    -1,   149,    -1,   124,    -1,   118,   650,    -1,
     156,   187,    -1,   156,   410,   187,    -1,   119,    -1,   169,
     153,   410,   184,    -1,   201,   153,   410,   184,    -1,   651,
     156,   187,    -1,   651,   156,   514,   187,    -1,   411,    -1,
     514,   107,   411,    -1,   516,    -1,   534,    -1,   517,    -1,
     531,    -1,   532,    -1,   157,   650,   521,   130,    -1,   157,
     650,   519,   521,   130,    -1,   157,   650,   521,   196,   194,
     650,   521,   196,    -1,   157,   650,   521,   196,   518,   194,
     650,   521,   196,    -1,   157,   650,   519,   521,   196,   194,
     650,   521,   196,    -1,   157,   650,   519,   521,   196,   518,
     194,   650,   521,   196,    -1,   529,    -1,   518,   529,    -1,
     520,    -1,   519,   520,    -1,    35,   650,   521,   132,   521,
     522,    -1,    -1,    35,    -1,   183,   523,   183,    -1,    93,
     525,    93,    -1,    -1,   524,    -1,   134,    -1,   527,    -1,
     524,   134,    -1,   524,   527,    -1,    -1,   526,    -1,   133,
      -1,   528,    -1,   526,   133,    -1,   526,   528,    -1,    28,
      -1,   530,    -1,     5,    -1,   530,    -1,   516,    -1,    10,
      -1,   533,    -1,   530,    -1,     9,    -1,   123,    -1,   125,
      -1,   153,   390,   184,    -1,   212,    30,   213,    -1,   212,
     213,    -1,   174,   649,   175,    -1,   174,   649,     8,    -1,
     103,     7,    -1,   535,    -1,   536,    -1,   537,    -1,   538,
      -1,   539,    -1,   540,    -1,    43,   153,   390,   184,    -1,
      21,   389,   184,    -1,    45,   153,   410,   184,   153,   389,
     184,    -1,    22,   389,   184,    -1,    97,   153,   410,   184,
     153,   389,   184,    -1,    70,   153,   390,   184,    -1,    39,
     153,   390,   184,    -1,    23,   389,   184,    -1,    59,   153,
     410,   184,   153,   389,   184,    -1,   547,    -1,   547,   144,
      -1,    94,   543,    -1,   545,    -1,   545,   544,    -1,   210,
     156,   187,    -1,   144,    -1,   193,    -1,   176,    -1,   547,
      -1,   548,    -1,   152,   156,   187,    -1,   319,   156,   187,
      -1,   564,    -1,   567,    -1,   644,    -1,   543,    -1,   546,
     107,   543,    -1,   650,    -1,   550,    -1,   556,    -1,   554,
      -1,   557,    -1,   555,    -1,   553,    -1,   552,    -1,   551,
      -1,   549,    -1,   224,   156,   187,    -1,    44,   156,   187,
      -1,    44,   156,   556,   187,    -1,    44,   156,   557,   187,
      -1,    70,   156,   187,    -1,    39,   156,   187,    -1,    59,
     156,   187,    -1,    59,   156,   649,   187,    -1,    59,   156,
      29,   187,    -1,    97,   156,   187,    -1,    97,   156,   650,
     187,    -1,    97,   156,   650,   107,   558,   187,    -1,    97,
     156,   193,   187,    -1,    97,   156,   193,   107,   558,   187,
      -1,    61,   156,   650,   187,    -1,    45,   156,   187,    -1,
      45,   156,   650,   187,    -1,    45,   156,   650,   107,   558,
     187,    -1,    45,   156,   650,   107,   559,   187,    -1,    45,
     156,   193,   187,    -1,    45,   156,   193,   107,   558,   187,
      -1,    45,   156,   193,   107,   559,   187,    -1,    62,   156,
     650,   187,    -1,   650,    -1,   650,   144,    -1,    29,    -1,
     562,    -1,   563,    -1,   650,   145,   149,    -1,    47,   378,
     395,    -1,   565,    -1,   566,    -1,    47,   156,   193,   187,
      -1,    47,   156,   187,    94,   543,    -1,    47,   156,   546,
     187,    94,   543,    -1,   156,   545,   187,    -1,    33,   219,
     220,    -1,    33,   219,   221,    -1,    33,   219,   222,    -1,
     225,   224,   411,   232,   411,    -1,   225,   224,   411,    94,
     231,   232,   411,    -1,   225,   224,   411,    94,   233,   232,
     411,    -1,   225,   224,   411,   217,   411,    -1,   225,   224,
     411,   218,   411,    -1,   225,   226,   411,   232,   411,    -1,
     225,   226,   411,    94,   231,   232,   411,    -1,   225,   226,
     411,    94,   233,   232,   411,    -1,   225,   226,   411,   217,
     411,    -1,   225,   226,   411,   218,   411,    -1,   223,   224,
     411,    -1,   223,   226,   411,    -1,   228,   224,   411,   236,
     411,    -1,   228,   229,   230,   224,   411,   236,   411,    -1,
     227,   224,   411,    94,   411,    -1,   235,   118,   574,   234,
     411,   186,   411,    -1,   575,    -1,   574,   107,   118,   575,
      -1,   650,   142,   411,    -1,   243,   153,   410,   184,   577,
      -1,   578,    -1,   577,   578,    -1,   244,   580,   579,    -1,
     153,   410,   184,    -1,   500,    -1,   580,   209,   500,    -1,
     584,   582,    -1,    -1,   583,    -1,   602,    -1,   583,   602,
      -1,   585,    -1,   584,   261,   585,    -1,   586,    -1,   585,
     257,   586,    -1,   587,    -1,   586,   259,   147,   587,    -1,
     588,    -1,   258,   588,    -1,   592,   589,   590,    -1,    -1,
     607,    -1,    -1,   591,    -1,   281,   153,   410,   184,    -1,
     596,   593,    -1,   156,   581,   187,    -1,   594,    -1,    -1,
     629,    -1,   487,   153,   595,   184,    -1,    -1,   581,    -1,
     597,   598,    -1,   506,    -1,   153,   410,   184,    -1,    -1,
     599,    -1,   247,   600,    -1,   246,   601,    -1,   269,    -1,
      -1,    78,    -1,    -1,   285,    -1,   603,    -1,   604,    -1,
     605,    -1,   631,    -1,   628,    -1,   169,    -1,   283,   472,
     606,    -1,   252,   630,   606,    -1,   285,    -1,   275,    -1,
     268,    -1,   245,   608,    -1,   607,   245,   608,    -1,   609,
      -1,   610,    -1,   611,    -1,   626,    -1,   612,    -1,   620,
      -1,   613,    -1,   627,    -1,   100,   273,    -1,   100,   262,
      -1,   265,    -1,   280,    -1,   250,   273,    -1,   250,   262,
      -1,    56,   650,    29,    -1,   276,    -1,    54,   276,    -1,
     278,   614,    -1,   278,   156,   614,   615,   187,    -1,    54,
     278,    -1,   617,    -1,   113,    -1,    -1,   107,   616,    -1,
     617,    -1,   616,   107,   617,    -1,    96,    29,   618,   619,
      -1,    -1,   270,    29,    -1,    -1,   630,   264,    -1,   277,
     285,   621,   623,    -1,   277,   285,   113,   623,    -1,    54,
     277,   285,    -1,    96,    29,    -1,   156,   622,   187,    -1,
      29,    -1,   622,   107,    29,    -1,    -1,   624,    -1,   625,
      -1,   624,   625,    -1,   200,   621,    -1,   136,   621,    -1,
     263,    29,    -1,   282,    -1,    54,   282,    -1,    96,   216,
      -1,    96,   253,    -1,   254,   249,    -1,   266,   630,   279,
      -1,   255,   472,    -1,    96,   129,   472,    -1,    96,    52,
     472,    -1,   256,   472,   198,   472,    -1,   271,   632,    -1,
     251,   632,    -1,   274,    -1,   267,    -1,   284,   249,   474,
      -1,   154,   185,    -1,   154,   410,   185,    -1,   309,   310,
      -1,   309,   410,   310,    -1,   311,   312,    -1,   311,   410,
     312,    -1,   153,   638,   184,    -1,   411,   121,   411,    -1,
     638,   107,   411,   121,   411,    -1,   225,   313,   153,   638,
     184,   232,   411,    -1,   225,   313,   154,   410,   185,   232,
     411,    96,   315,   411,    -1,   314,   313,   154,   410,   185,
     198,   411,    -1,   223,   313,   502,    -1,   227,   313,   502,
      94,   411,    -1,   228,   313,   229,   230,   502,   236,   411,
      -1,   645,    -1,   646,    -1,   647,    -1,   318,   156,   187,
      -1,   316,   156,   187,    -1,   317,   156,   187,    -1,    29,
      -1,    16,    -1,   650,    -1,   651,    -1,    97,    -1,    39,
      -1,    44,    -1,    45,    -1,   152,    -1,    48,    -1,   224,
      -1,    59,    -1,    61,    -1,    62,    -1,    70,    -1,    73,
      -1,    72,    -1,   210,    -1,   242,    -1,   652,    -1,    24,
      -1,   214,    -1,   127,    -1,    38,    -1,   260,    -1,    37,
      -1,   221,    -1,   220,    -1,   146,    -1,    43,    -1,   258,
      -1,   259,    -1,   273,    -1,   262,    -1,   250,    -1,   284,
      -1,   276,    -1,   278,    -1,   277,    -1,   282,    -1,   254,
      -1,   249,    -1,    78,    -1,   216,    -1,   253,    -1,    52,
      -1,   222,    -1,   235,    -1,   301,    -1,   229,    -1,   202,
      -1,   207,    -1,   206,    -1,   205,    -1,   204,    -1,   203,
      -1,    96,    -1,   111,    -1,   112,    -1,   186,    -1,    46,
      -1,    36,    -1,    66,    -1,    71,    -1,    58,    -1,    53,
      -1,    55,    -1,    77,    -1,    42,    -1,   147,    -1,    51,
      -1,   211,    -1,   170,    -1,   171,    -1,   168,    -1,    69,
      -1,    95,    -1,   116,    -1,   128,    -1,   129,    -1,   106,
      -1,    67,    -1,   135,    -1,   188,    -1,   100,    -1,    94,
      -1,   197,    -1,   126,    -1,   167,    -1,    92,    -1,    50,
      -1,   230,    -1,   101,    -1,   198,    -1,   117,    -1,   159,
      -1,   200,    -1,   150,    -1,   136,    -1,    75,    -1,    76,
      -1,   102,    -1,   199,    -1,   151,    -1,   182,    -1,   195,
      -1,   160,    -1,   137,    -1,   131,    -1,   166,    -1,   148,
      -1,   165,    -1,    33,    -1,    40,    -1,    57,    -1,   113,
      -1,    41,    -1,    56,    -1,   215,    -1,    49,    -1,    60,
      -1,    34,    -1,    47,    -1,   272,    -1,   248,    -1,   281,
      -1,   283,    -1,   252,    -1,   266,    -1,   279,    -1,   271,
      -1,   251,    -1,   265,    -1,   280,    -1,   270,    -1,   264,
      -1,   263,    -1,   247,    -1,   246,    -1,   255,    -1,   256,
      -1,   285,    -1,   275,    -1,   274,    -1,   269,    -1,   267,
      -1,   268,    -1,   228,    -1,   234,    -1,   231,    -1,   225,
      -1,   218,    -1,   217,    -1,   219,    -1,   236,    -1,   226,
      -1,   227,    -1,   233,    -1,   223,    -1,   232,    -1,    65,
      -1,    63,    -1,    74,    -1,   169,    -1,   201,    -1,   241,
      -1,   239,    -1,   240,    -1,   237,    -1,   238,    -1,   243,
      -1,   244,    -1,   245,    -1,    64,    -1,   294,    -1,   292,
      -1,   293,    -1,   298,    -1,   299,    -1,   300,    -1,   295,
      -1,   296,    -1,   297,    -1,    79,    -1,    80,    -1,    81,
      -1,    82,    -1,    83,    -1,    84,    -1,    85,    -1,    86,
      -1,    87,    -1,    88,    -1,    89,    -1,   286,    -1,   287,
      -1,   288,    -1,   289,    -1,   290,    -1,   291,    -1,   302,
      -1,   303,    -1,   304,    -1,   305,    -1,   306,    -1,   307,
      -1,   308,    -1,    90,    -1,   105,    -1,   114,    -1,   172,
      -1,   180,    -1,   189,    -1,   138,    -1,    91,    -1,   115,
      -1,   139,    -1,   181,    -1,   313,    -1,   314,    -1,   315,
      -1,   318,    -1,   317,    -1,   316,    -1,   319,    -1,    25,
      -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  xquery_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    11,    15,    18,    20,    23,
      25,    28,    33,    40,    44,    48,    54,    56,    60,    64,
      70,    76,    78,    82,    86,    92,    99,   101,   105,   109,
     111,   113,   115,   117,   119,   121,   123,   125,   127,   129,
     131,   133,   135,   139,   143,   148,   152,   156,   160,   164,
     168,   174,   180,   186,   192,   198,   204,   206,   208,   212,
     216,   221,   227,   234,   236,   240,   244,   248,   252,   259,
     265,   274,   280,   286,   292,   294,   298,   302,   304,   306,
     308,   310,   312,   314,   316,   318,   323,   328,   330,   333,
     337,   339,   341,   343,   345,   347,   349,   351,   353,   355,
     357,   362,   366,   371,   375,   377,   379,   381,   384,   387,
     392,   396,   402,   406,   411,   416,   422,   424,   427,   429,
     434,   436,   441,   443,   447,   450,   454,   456,   458,   463,
     468,   474,   480,   483,   487,   492,   498,   500,   504,   507,
     511,   515,   521,   526,   533,   535,   538,   540,   543,   552,
     562,   564,   568,   570,   573,   576,   580,   592,   607,   621,
     644,   646,   648,   650,   651,   653,   655,   656,   658,   661,
     663,   666,   668,   670,   672,   674,   676,   678,   680,   682,
     684,   686,   688,   690,   694,   697,   701,   705,   708,   712,
     715,   719,   722,   726,   731,   737,   743,   746,   751,   757,
     761,   765,   768,   771,   780,   784,   786,   789,   793,   795,
     799,   801,   803,   805,   807,   809,   811,   813,   815,   817,
     819,   821,   823,   825,   827,   829,   831,   833,   835,   838,
     841,   844,   847,   849,   851,   854,   859,   863,   869,   874,
     878,   880,   882,   884,   886,   888,   890,   892,   894,   896,
     899,   903,   907,   910,   912,   917,   921,   925,   931,   936,
     943,   948,   955,   961,   969,   974,   980,   986,   993,   997,
    1001,  1004,  1006,  1010,  1015,  1021,  1025,  1032,  1037,  1043,
    1045,  1048,  1052,  1054,  1057,  1059,  1066,  1070,  1074,  1077,
    1081,  1083,  1087,  1090,  1095,  1101,  1108,  1114,  1118,  1121,
    1125,  1130,  1132,  1136,  1138,  1141,  1143,  1145,  1147,  1150,
    1153,  1156,  1160,  1162,  1164,  1167,  1170,  1173,  1179,  1185,
    1187,  1192,  1196,  1201,  1210,  1212,  1215,  1219,  1222,  1226,
    1235,  1237,  1240,  1244,  1253,  1264,  1273,  1284,  1286,  1289,
    1294,  1302,  1304,  1307,  1312,  1320,  1329,  1331,  1335,  1337,
    1341,  1343,  1347,  1351,  1355,  1359,  1360,  1365,  1369,  1373,
    1377,  1379,  1385,  1387,  1391,  1392,  1394,  1396,  1400,  1402,
    1406,  1410,  1412,  1416,  1420,  1424,  1428,  1430,  1434,  1438,
    1440,  1444,  1448,  1450,  1455,  1457,  1462,  1464,  1469,  1471,
    1476,  1478,  1481,  1483,  1485,  1488,  1491,  1493,  1495,  1497,
    1499,  1501,  1503,  1505,  1507,  1509,  1511,  1513,  1515,  1520,
    1526,  1532,  1539,  1543,  1548,  1550,  1553,  1557,  1560,  1563,
    1565,  1568,  1571,  1573,  1575,  1577,  1581,  1585,  1587,  1589,
    1591,  1594,  1596,  1599,  1602,  1604,  1607,  1610,  1613,  1616,
    1619,  1622,  1625,  1627,  1630,  1633,  1635,  1638,  1641,  1644,
    1647,  1650,  1652,  1654,  1656,  1658,  1660,  1662,  1664,  1666,
    1668,  1671,  1675,  1680,  1682,  1685,  1689,  1691,  1693,  1695,
    1697,  1699,  1701,  1703,  1705,  1707,  1709,  1711,  1713,  1715,
    1717,  1719,  1721,  1723,  1725,  1727,  1730,  1733,  1737,  1739,
    1744,  1749,  1753,  1758,  1760,  1764,  1766,  1768,  1770,  1772,
    1774,  1779,  1785,  1794,  1804,  1814,  1825,  1827,  1830,  1832,
    1835,  1842,  1843,  1845,  1849,  1853,  1854,  1856,  1858,  1860,
    1863,  1866,  1867,  1869,  1871,  1873,  1876,  1879,  1881,  1883,
    1885,  1887,  1889,  1891,  1893,  1895,  1897,  1899,  1901,  1905,
    1909,  1912,  1916,  1920,  1923,  1925,  1927,  1929,  1931,  1933,
    1935,  1940,  1944,  1952,  1956,  1964,  1969,  1974,  1978,  1986,
    1988,  1991,  1994,  1996,  1999,  2003,  2005,  2007,  2009,  2011,
    2013,  2017,  2021,  2023,  2025,  2027,  2029,  2033,  2035,  2037,
    2039,  2041,  2043,  2045,  2047,  2049,  2051,  2053,  2057,  2061,
    2066,  2071,  2075,  2079,  2083,  2088,  2093,  2097,  2102,  2109,
    2114,  2121,  2126,  2130,  2135,  2142,  2149,  2154,  2161,  2168,
    2173,  2175,  2178,  2180,  2182,  2184,  2188,  2192,  2194,  2196,
    2201,  2207,  2214,  2218,  2222,  2226,  2230,  2236,  2244,  2252,
    2258,  2264,  2270,  2278,  2286,  2292,  2298,  2302,  2306,  2312,
    2320,  2326,  2334,  2336,  2341,  2345,  2351,  2353,  2356,  2360,
    2364,  2366,  2370,  2373,  2374,  2376,  2378,  2381,  2383,  2387,
    2389,  2393,  2395,  2400,  2402,  2405,  2409,  2410,  2412,  2413,
    2415,  2420,  2423,  2427,  2429,  2430,  2432,  2437,  2438,  2440,
    2443,  2445,  2449,  2450,  2452,  2455,  2458,  2460,  2461,  2463,
    2464,  2466,  2468,  2470,  2472,  2474,  2476,  2478,  2482,  2486,
    2488,  2490,  2492,  2495,  2499,  2501,  2503,  2505,  2507,  2509,
    2511,  2513,  2515,  2518,  2521,  2523,  2525,  2528,  2531,  2535,
    2537,  2540,  2543,  2549,  2552,  2554,  2556,  2557,  2560,  2562,
    2566,  2571,  2572,  2575,  2576,  2579,  2584,  2589,  2593,  2596,
    2600,  2602,  2606,  2607,  2609,  2611,  2614,  2617,  2620,  2623,
    2625,  2628,  2631,  2634,  2637,  2641,  2644,  2648,  2652,  2657,
    2660,  2663,  2665,  2667,  2671,  2674,  2678,  2681,  2685,  2688,
    2692,  2696,  2700,  2706,  2714,  2725,  2733,  2737,  2743,  2751,
    2753,  2755,  2757,  2761,  2765,  2769,  2771,  2773,  2775,  2777,
    2779,  2781,  2783,  2785,  2787,  2789,  2791,  2793,  2795,  2797,
    2799,  2801,  2803,  2805,  2807,  2809,  2811,  2813,  2815,  2817,
    2819,  2821,  2823,  2825,  2827,  2829,  2831,  2833,  2835,  2837,
    2839,  2841,  2843,  2845,  2847,  2849,  2851,  2853,  2855,  2857,
    2859,  2861,  2863,  2865,  2867,  2869,  2871,  2873,  2875,  2877,
    2879,  2881,  2883,  2885,  2887,  2889,  2891,  2893,  2895,  2897,
    2899,  2901,  2903,  2905,  2907,  2909,  2911,  2913,  2915,  2917,
    2919,  2921,  2923,  2925,  2927,  2929,  2931,  2933,  2935,  2937,
    2939,  2941,  2943,  2945,  2947,  2949,  2951,  2953,  2955,  2957,
    2959,  2961,  2963,  2965,  2967,  2969,  2971,  2973,  2975,  2977,
    2979,  2981,  2983,  2985,  2987,  2989,  2991,  2993,  2995,  2997,
    2999,  3001,  3003,  3005,  3007,  3009,  3011,  3013,  3015,  3017,
    3019,  3021,  3023,  3025,  3027,  3029,  3031,  3033,  3035,  3037,
    3039,  3041,  3043,  3045,  3047,  3049,  3051,  3053,  3055,  3057,
    3059,  3061,  3063,  3065,  3067,  3069,  3071,  3073,  3075,  3077,
    3079,  3081,  3083,  3085,  3087,  3089,  3091,  3093,  3095,  3097,
    3099,  3101,  3103,  3105,  3107,  3109,  3111,  3113,  3115,  3117,
    3119,  3121,  3123,  3125,  3127,  3129,  3131,  3133,  3135,  3137,
    3139,  3141,  3143,  3145,  3147,  3149,  3151,  3153,  3155,  3157,
    3159,  3161,  3163,  3165,  3167,  3169,  3171,  3173,  3175,  3177,
    3179,  3181,  3183,  3185,  3187,  3189,  3191,  3193,  3195,  3197,
    3199,  3201,  3203,  3205,  3207,  3209,  3211,  3213,  3215,  3217,
    3219
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1038,  1038,  1039,  1043,  1047,  1058,  1067,  1073,  1081,
    1087,  1098,  1103,  1111,  1118,  1125,  1134,  1141,  1149,  1157,
    1165,  1176,  1181,  1188,  1195,  1207,  1217,  1224,  1231,  1243,
    1244,  1245,  1246,  1247,  1252,  1253,  1254,  1255,  1256,  1257,
    1258,  1261,  1266,  1271,  1279,  1287,  1295,  1300,  1308,  1313,
    1321,  1326,  1334,  1341,  1348,  1355,  1365,  1367,  1370,  1380,
    1385,  1393,  1401,  1412,  1419,  1430,  1435,  1443,  1450,  1457,
    1466,  1479,  1487,  1494,  1504,  1511,  1518,  1529,  1530,  1531,
    1532,  1533,  1534,  1535,  1536,  1541,  1547,  1556,  1563,  1573,
    1583,  1584,  1585,  1586,  1587,  1588,  1589,  1590,  1591,  1592,
    1597,  1605,  1613,  1621,  1628,  1636,  1643,  1648,  1656,  1664,
    1678,  1692,  1709,  1714,  1722,  1730,  1741,  1746,  1755,  1760,
    1767,  1772,  1782,  1787,  1796,  1802,  1815,  1820,  1828,  1839,
    1854,  1866,  1881,  1886,  1891,  1896,  1904,  1911,  1922,  1927,
    1937,  1944,  1951,  1958,  1968,  1972,  1978,  1982,  1992,  2000,
    2011,  2017,  2026,  2031,  2038,  2045,  2056,  2066,  2076,  2086,
    2104,  2124,  2128,  2133,  2140,  2144,  2149,  2156,  2161,  2173,
    2180,  2192,  2193,  2194,  2195,  2196,  2197,  2198,  2200,  2201,
    2202,  2203,  2204,  2209,  2214,  2222,  2239,  2247,  2255,  2262,
    2269,  2280,  2289,  2298,  2307,  2320,  2328,  2336,  2344,  2359,
    2364,  2372,  2386,  2403,  2428,  2436,  2443,  2454,  2464,  2469,
    2484,  2485,  2486,  2487,  2488,  2489,  2494,  2495,  2498,  2499,
    2500,  2501,  2502,  2505,  2506,  2507,  2508,  2509,  2514,  2528,
    2536,  2541,  2549,  2554,  2559,  2567,  2576,  2588,  2598,  2611,
    2619,  2620,  2621,  2626,  2627,  2628,  2629,  2630,  2635,  2642,
    2652,  2658,  2666,  2676,  2683,  2691,  2702,  2712,  2722,  2732,
    2742,  2752,  2762,  2772,  2783,  2792,  2802,  2812,  2828,  2837,
    2846,  2854,  2860,  2872,  2880,  2890,  2898,  2910,  2916,  2927,
    2929,  2933,  2941,  2945,  2950,  2954,  2958,  2962,  2972,  2980,
    2987,  2993,  3003,  3007,  3011,  3019,  3027,  3035,  3047,  3055,
    3061,  3071,  3077,  3087,  3091,  3101,  3107,  3113,  3119,  3128,
    3137,  3146,  3159,  3163,  3171,  3177,  3187,  3195,  3204,  3217,
    3224,  3236,  3240,  3252,  3259,  3265,  3274,  3281,  3287,  3298,
    3305,  3311,  3320,  3329,  3336,  3347,  3354,  3366,  3372,  3384,
    3390,  3401,  3407,  3418,  3424,  3435,  3444,  3448,  3457,  3461,
    3469,  3473,  3483,  3490,  3499,  3509,  3508,  3522,  3531,  3540,
    3553,  3557,  3569,  3573,  3581,  3584,  3591,  3595,  3604,  3608,
    3612,  3620,  3624,  3630,  3636,  3642,  3652,  3656,  3660,  3668,
    3672,  3678,  3688,  3692,  3702,  3706,  3716,  3720,  3730,  3734,
    3744,  3748,  3756,  3760,  3764,  3768,  3778,  3782,  3786,  3794,
    3798,  3802,  3806,  3810,  3814,  3822,  3826,  3830,  3838,  3842,
    3846,  3850,  3861,  3867,  3877,  3883,  3893,  3897,  3901,  3939,
    3943,  3953,  3963,  3976,  3985,  3995,  3999,  4008,  4012,  4021,
    4027,  4035,  4041,  4053,  4059,  4069,  4073,  4077,  4081,  4085,
    4091,  4097,  4105,  4109,  4117,  4121,  4132,  4136,  4140,  4146,
    4150,  4164,  4168,  4176,  4180,  4190,  4194,  4198,  4202,  4211,
    4215,  4219,  4223,  4231,  4237,  4247,  4255,  4259,  4263,  4267,
    4271,  4275,  4279,  4283,  4287,  4291,  4296,  4300,  4304,  4308,
    4316,  4320,  4328,  4335,  4342,  4353,  4361,  4365,  4373,  4381,
    4389,  4443,  4447,  4460,  4466,  4476,  4480,  4488,  4492,  4496,
    4504,  4514,  4524,  4541,  4558,  4575,  4597,  4603,  4614,  4620,
    4631,  4642,  4644,  4648,  4653,  4663,  4666,  4673,  4679,  4685,
    4693,  4706,  4709,  4716,  4722,  4728,  4735,  4746,  4750,  4760,
    4764,  4774,  4778,  4782,  4787,  4796,  4802,  4808,  4814,  4822,
    4827,  4835,  4840,  4848,  4856,  4861,  4866,  4871,  4876,  4881,
    4890,  4898,  4902,  4919,  4923,  4931,  4939,  4947,  4951,  4959,
    4965,  4975,  4983,  4987,  4991,  5026,  5032,  5038,  5048,  5052,
    5056,  5060,  5064,  5068,  5072,  5079,  5085,  5095,  5103,  5107,
    5111,  5115,  5119,  5123,  5127,  5131,  5135,  5143,  5151,  5155,
    5159,  5169,  5177,  5185,  5189,  5193,  5201,  5205,  5211,  5217,
    5221,  5231,  5239,  5243,  5249,  5258,  5267,  5273,  5279,  5289,
    5306,  5313,  5328,  5364,  5368,  5376,  5384,  5396,  5400,  5408,
    5416,  5420,  5431,  5448,  5454,  5460,  5470,  5474,  5480,  5486,
    5490,  5496,  5500,  5506,  5512,  5519,  5529,  5534,  5542,  5548,
    5558,  5580,  5589,  5595,  5608,  5622,  5629,  5635,  5645,  5654,
    5662,  5668,  5686,  5694,  5698,  5705,  5710,  5718,  5722,  5729,
    5733,  5740,  5744,  5751,  5755,  5764,  5777,  5780,  5788,  5791,
    5799,  5807,  5815,  5819,  5827,  5830,  5838,  5850,  5853,  5861,
    5873,  5879,  5889,  5892,  5900,  5904,  5908,  5916,  5919,  5927,
    5930,  5938,  5942,  5946,  5950,  5954,  5962,  5970,  5982,  5994,
    5998,  6002,  6010,  6016,  6026,  6030,  6034,  6038,  6042,  6046,
    6050,  6054,  6062,  6066,  6070,  6074,  6082,  6088,  6098,  6108,
    6112,  6120,  6130,  6141,  6148,  6152,  6160,  6163,  6170,  6175,
    6184,  6194,  6197,  6204,  6208,  6216,  6225,  6232,  6242,  6246,
    6253,  6259,  6269,  6272,  6279,  6284,  6296,  6304,  6316,  6324,
    6328,  6336,  6340,  6344,  6352,  6360,  6364,  6368,  6372,  6380,
    6388,  6400,  6404,  6412,  6426,  6430,  6437,  6442,  6450,  6455,
    6464,  6472,  6478,  6488,  6494,  6501,  6508,  6537,  6566,  6595,
    6599,  6603,  6610,  6617,  6624,  6636,  6640,  6641,  6654,  6655,
    6656,  6657,  6658,  6659,  6660,  6661,  6662,  6663,  6664,  6665,
    6666,  6667,  6668,  6669,  6673,  6674,  6675,  6676,  6677,  6678,
    6679,  6680,  6681,  6682,  6683,  6684,  6685,  6686,  6687,  6688,
    6689,  6690,  6691,  6692,  6693,  6694,  6695,  6696,  6697,  6698,
    6699,  6700,  6701,  6702,  6703,  6704,  6705,  6706,  6707,  6708,
    6709,  6710,  6711,  6712,  6713,  6714,  6715,  6716,  6717,  6718,
    6719,  6720,  6721,  6722,  6723,  6724,  6725,  6726,  6727,  6728,
    6729,  6730,  6731,  6732,  6733,  6734,  6735,  6736,  6737,  6738,
    6739,  6740,  6741,  6742,  6743,  6744,  6745,  6746,  6747,  6748,
    6749,  6750,  6751,  6752,  6753,  6754,  6755,  6756,  6757,  6758,
    6759,  6760,  6761,  6762,  6763,  6764,  6765,  6766,  6767,  6768,
    6769,  6770,  6771,  6772,  6773,  6774,  6775,  6776,  6777,  6778,
    6779,  6780,  6781,  6782,  6783,  6784,  6785,  6786,  6787,  6788,
    6789,  6790,  6791,  6792,  6793,  6794,  6795,  6796,  6797,  6798,
    6799,  6800,  6801,  6802,  6803,  6804,  6805,  6806,  6807,  6808,
    6809,  6810,  6811,  6812,  6813,  6814,  6815,  6816,  6817,  6818,
    6819,  6820,  6821,  6822,  6823,  6824,  6825,  6826,  6827,  6828,
    6829,  6830,  6831,  6832,  6833,  6834,  6835,  6836,  6837,  6838,
    6839,  6840,  6841,  6842,  6843,  6844,  6845,  6846,  6847,  6848,
    6849,  6850,  6851,  6852,  6853,  6854,  6855,  6856,  6857,  6858,
    6859,  6860,  6861,  6862,  6863,  6864,  6865,  6866,  6867,  6868,
    6869,  6870,  6871,  6872,  6873,  6874,  6875,  6876,  6877,  6878,
    6883
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 16082;
  const int xquery_parser::yynnts_ = 321;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 607;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 332;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 586;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 17317 "/home/markos/zorba/repo/bug-900688/build-opt/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6887 "/home/markos/zorba/repo/bug-900688/src/compiler/parser/xquery_parser.y"


namespace zorba {

namespace parser {

const char *the_tumbling = "tumbling", *the_sliding = "sliding",
  *the_start = "start", *the_end = "end", *the_only_end = "only end",
  *the_declare = "declare", *the_create = "create";

} // namespace parser

/*
 *  The error member function registers the errors to the driver.
 */
void xquery_parser::error(zorba::xquery_parser::location_type const& loc, string const& msg)
{
  if (driver.parserError != NULL)
  {
    driver.set_expr(new ParseErrorNode(driver.parserError->loc, driver.parserError->err_code, driver.parserError->msg));
  }
  else
  {
    // remove the double quoting "''" from every token description
    string message = msg;
    int pos;
    while ((pos = message.find("\"'")) != -1 || (pos = message.find("'\"")) != -1)
      message.replace(pos, 2, "\"");
    driver.set_expr(new ParseErrorNode(driver.createQueryLoc(loc), err::XPST0003, message));
  }
}

} // namespace zorba

