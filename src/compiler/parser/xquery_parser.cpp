
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
#line 87 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"


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
#line 79 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 906 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 317 of lalr1.cc  */
#line 1022 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_scanner.h"

#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc  */
#line 109 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"

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
#line 178 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
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
#line 904 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 285 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 124: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 903 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 294 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 149: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 902 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 303 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 312 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 321 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 330 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 339 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 348 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 357 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 366 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 375 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 384 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 393 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 402 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 411 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 420 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 429 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 438 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 447 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 456 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 465 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 474 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 483 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 492 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 501 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 510 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 519 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 528 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 537 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 546 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 555 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 564 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 573 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 582 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 591 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 600 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 609 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 618 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 627 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 636 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 645 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 654 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 663 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 672 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 681 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 690 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 699 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 708 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 717 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 726 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 735 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 744 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 753 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 762 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 771 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 780 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 789 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 798 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 825 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 834 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 843 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 861 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 870 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 897 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 906 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 915 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 933 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 942 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 951 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 960 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 969 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 978 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 987 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 996 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1005 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1014 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1023 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1032 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1041 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1050 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1059 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1068 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1077 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1086 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1095 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1104 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1113 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1122 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1131 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1140 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1149 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1158 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1167 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1176 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1185 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1194 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1203 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1212 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1221 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1230 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1239 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1248 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1257 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1266 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1275 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1284 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1293 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1302 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1311 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1320 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1329 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1338 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1347 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1356 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1365 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1374 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1383 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1392 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1401 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1410 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1419 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1428 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1437 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1446 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1455 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1464 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1473 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1482 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1491 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1500 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1509 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1518 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1527 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1536 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1545 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1554 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1563 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1572 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1581 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1590 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1599 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1608 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1617 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1626 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1635 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1644 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1653 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1662 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1671 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1680 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1689 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1698 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1707 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1716 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1725 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1734 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1743 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1752 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1761 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1770 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1779 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1788 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1797 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1806 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1815 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1824 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1833 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1842 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1851 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1860 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1869 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1878 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1887 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1896 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1905 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1914 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1923 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1932 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1941 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1950 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1959 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1968 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1977 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1986 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1995 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2004 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2013 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2022 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2031 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2040 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2049 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2058 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2067 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2076 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2085 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2094 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2103 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2112 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2121 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2130 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2139 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2148 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2157 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2166 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2175 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2184 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2193 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2202 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2211 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2220 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2229 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2238 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2247 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2256 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2265 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2274 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2283 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2292 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2301 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2310 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2319 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2328 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2337 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2346 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2355 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2364 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2373 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2382 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2391 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2400 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2409 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2418 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2427 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2436 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2445 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2454 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2463 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2472 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2481 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2490 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2499 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2508 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2517 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2526 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 610: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2535 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 611: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2544 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 612: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2553 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 613: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2562 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 617: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2571 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2580 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 621: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2589 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 625: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2598 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 626: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2607 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 627: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2616 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 628: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2625 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 629: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2634 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 630: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2643 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 631: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2652 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 632: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2661 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 633: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2670 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 634: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2679 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 635: /* "JSONSimpleObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2688 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 636: /* "JSONAccumulatorObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2697 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 637: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2706 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 638: /* "JSONPairList" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2715 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 639: /* "JSONInsertExpr" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2724 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 640: /* "JSONAppendExpr" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2733 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 641: /* "JSONDeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2742 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 642: /* "JSONRenameExpr" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2751 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 643: /* "JSONReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2760 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 650: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2769 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 651: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2778 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 652: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 927 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2787 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
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
#line 140 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 553 of lalr1.cc  */
#line 2872 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"

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
#line 1040 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 1044 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 1048 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 1059 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 1068 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 1074 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 1082 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 1088 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 1099 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1104 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1112 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1119 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1126 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1135 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1142 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1150 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1158 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1166 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1177 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 1182 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 1189 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 1196 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 1208 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 1218 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 27:

/* Line 678 of lalr1.cc  */
#line 1225 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 28:

/* Line 678 of lalr1.cc  */
#line 1232 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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
#line 1267 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1272 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1280 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1288 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1296 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1301 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1309 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1314 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1322 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1327 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1335 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1342 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 54:

/* Line 678 of lalr1.cc  */
#line 1349 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 55:

/* Line 678 of lalr1.cc  */
#line 1356 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 1371 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 1381 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1386 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1394 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1402 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1413 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1420 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1431 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1436 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1444 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1451 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1458 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1467 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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
#line 1480 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1488 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1495 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1505 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 75:

/* Line 678 of lalr1.cc  */
#line 1512 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 76:

/* Line 678 of lalr1.cc  */
#line 1519 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1542 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1548 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1557 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1564 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1574 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1583 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1584 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1585 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1586 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1587 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1588 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1589 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1590 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1591 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1592 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1598 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1606 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1614 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1622 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1629 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1637 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1644 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1649 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 1657 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 1665 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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
#line 1679 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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
#line 1693 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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
#line 1710 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1715 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1723 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1731 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1742 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1747 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1756 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1761 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1768 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1773 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1783 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1788 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1797 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1803 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1816 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 127:

/* Line 678 of lalr1.cc  */
#line 1821 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 128:

/* Line 678 of lalr1.cc  */
#line 1829 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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
#line 1840 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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
#line 1855 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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
#line 1867 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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
#line 1882 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1887 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1892 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1897 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1905 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1912 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1923 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1928 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1938 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL);
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1945 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1952 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0);
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1959 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1969 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1973 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1979 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1983 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));

    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 1993 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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
#line 2001 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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
#line 2012 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 2018 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 2027 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 2032 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 2039 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 2046 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 2058 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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
#line 2068 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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
#line 2078 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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
#line 2089 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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
#line 2105 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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
#line 2125 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 2129 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 2133 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2141 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 2145 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 2149 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 2157 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 2162 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 169:

/* Line 678 of lalr1.cc  */
#line 2174 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 170:

/* Line 678 of lalr1.cc  */
#line 2181 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 2210 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 2215 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 2223 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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
#line 2240 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 2248 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 2256 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 2263 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 2270 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 2281 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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
#line 2290 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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
#line 2299 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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
#line 2308 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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
#line 2321 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 2329 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 2337 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 2345 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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
#line 2360 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 200:

/* Line 678 of lalr1.cc  */
#line 2365 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2373 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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
#line 2387 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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
#line 2404 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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
#line 2429 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 2437 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 2444 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 2455 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 208:

/* Line 678 of lalr1.cc  */
#line 2465 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 209:

/* Line 678 of lalr1.cc  */
#line 2470 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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

  case 210:

/* Line 678 of lalr1.cc  */
#line 2482 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(4) - (1)].expr); // to prevent the Bison warning
      (yyval.expr) = (yysemantic_stack_[(4) - (3)].expr); // to prevent the Bison warning
      error((yylocation_stack_[(4) - (2)]), "syntax error, unexpected ExprSingle (missing comma \",\" between expressions?)");
      YYERROR;
    }
    break;

  case 211:

/* Line 678 of lalr1.cc  */
#line 2489 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      // This rule will never be reached, as the ERROR rule will stop the parser,
      // but it is nevertheless needed to fix a testcase with an unterminated comment which
      // would otherwise cycle indefinitely
      (yyval.expr) = (yysemantic_stack_[(3) - (1)].expr); // to prevent the Bison warning
      (yyval.expr) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      YYERROR;
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 2532 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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

  case 231:

/* Line 678 of lalr1.cc  */
#line 2546 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 2554 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 2559 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 2567 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 2572 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 236:

/* Line 678 of lalr1.cc  */
#line 2577 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 2585 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)),
                            (yysemantic_stack_[(4) - (4)].expr),
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 238:

/* Line 678 of lalr1.cc  */
#line 2594 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            NULL,
                            (yysemantic_stack_[(3) - (3)].expr),
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 239:

/* Line 678 of lalr1.cc  */
#line 2606 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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

  case 240:

/* Line 678 of lalr1.cc  */
#line 2616 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 241:

/* Line 678 of lalr1.cc  */
#line 2629 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2653 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2660 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 2670 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2676 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected QName \""
          + static_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node))->operator[](0)->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (3)].node);
      YYERROR;
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 2685 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL; // to prevent the Bison warning
      error((yylocation_stack_[(2) - (2)]), ""); // the error message is already set in the driver's parseError member
      YYERROR;
    }
    break;

  case 255:

/* Line 678 of lalr1.cc  */
#line 2695 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 256:

/* Line 678 of lalr1.cc  */
#line 2702 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 257:

/* Line 678 of lalr1.cc  */
#line 2710 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (3)]), "syntax error, unexpected QName \""
          + static_cast<VarInDecl*>((yysemantic_stack_[(3) - (3)].node))->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (1)].node);
      YYERROR;
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 2722 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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

  case 259:

/* Line 678 of lalr1.cc  */
#line 2732 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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

  case 260:

/* Line 678 of lalr1.cc  */
#line 2742 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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

  case 261:

/* Line 678 of lalr1.cc  */
#line 2752 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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

  case 262:

/* Line 678 of lalr1.cc  */
#line 2762 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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

  case 263:

/* Line 678 of lalr1.cc  */
#line 2772 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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

  case 264:

/* Line 678 of lalr1.cc  */
#line 2782 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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

  case 265:

/* Line 678 of lalr1.cc  */
#line 2792 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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

  case 266:

/* Line 678 of lalr1.cc  */
#line 2803 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2812 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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

  case 268:

/* Line 678 of lalr1.cc  */
#line 2822 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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

  case 269:

/* Line 678 of lalr1.cc  */
#line 2832 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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

  case 270:

/* Line 678 of lalr1.cc  */
#line 2848 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2857 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2866 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2874 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2880 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2892 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2900 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 277:

/* Line 678 of lalr1.cc  */
#line 2910 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2930 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2936 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2949 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2953 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2961 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2965 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2974 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2978 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2982 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 2992 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 3000 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 3007 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 3013 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 3023 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 3027 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 3031 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         NULL);
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 3039 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(6) - (3)].node)),
                         (yysemantic_stack_[(6) - (5)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 3047 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         NULL,
                         (yysemantic_stack_[(5) - (4)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 3055 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         NULL,
                         NULL,
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 3067 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 3075 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3081 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3091 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3097 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3107 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3111 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3121 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3127 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3133 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3139 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3148 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3157 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3166 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3179 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3183 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3191 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3197 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3207 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3215 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3224 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3237 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3244 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3256 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3260 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3272 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3279 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3285 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3294 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3301 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3307 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3318 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3325 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3331 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3340 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3349 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3356 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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
#line 3367 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3374 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3386 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3392 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3404 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3410 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3421 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3427 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3438 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3444 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3455 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3464 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3468 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3477 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3481 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3489 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3493 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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

  case 354:

/* Line 678 of lalr1.cc  */
#line 3503 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3510 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3519 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3528 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3533 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3542 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3551 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3560 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3573 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3577 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3589 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3593 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3600 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3604 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3611 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3615 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3624 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3628 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3632 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3640 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3644 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3650 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3656 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3662 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3672 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3676 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3680 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3688 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3692 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3698 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3708 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3712 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3722 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3726 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3736 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3740 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3750 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3754 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3764 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3768 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3776 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3780 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3784 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3788 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3798 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3802 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3806 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3814 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3818 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3822 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3826 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3830 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3834 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3842 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3846 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3850 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3858 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3862 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3866 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3870 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3881 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3887 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3897 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3903 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3913 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3917 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3921 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3959 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3963 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3973 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 3983 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 3996 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 4005 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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

  case 427:

/* Line 678 of lalr1.cc  */
#line 4015 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 4019 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 4028 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 4032 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 4041 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 4047 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 4055 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 4061 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 4073 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 4079 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 4089 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4093 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4097 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4101 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4105 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4111 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4117 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4125 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4129 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4137 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4141 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4152 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4156 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4160 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4166 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4170 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4184 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4188 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4196 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4200 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4210 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4214 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4218 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4222 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4231 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4235 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4239 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4243 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4251 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4257 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4267 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4275 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4279 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4283 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4287 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4291 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4295 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4299 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4303 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4307 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4311 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4316 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4320 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4324 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4328 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4336 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4340 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4348 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4355 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4362 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4373 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4381 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4385 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4393 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4401 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4409 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4463 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4467 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4480 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4486 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4496 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4500 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4508 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4512 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4516 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4524 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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

  case 503:

/* Line 678 of lalr1.cc  */
#line 4534 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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

  case 504:

/* Line 678 of lalr1.cc  */
#line 4544 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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

  case 505:

/* Line 678 of lalr1.cc  */
#line 4561 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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

  case 506:

/* Line 678 of lalr1.cc  */
#line 4578 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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

  case 507:

/* Line 678 of lalr1.cc  */
#line 4595 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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

  case 508:

/* Line 678 of lalr1.cc  */
#line 4617 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4623 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4634 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4640 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4651 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4668 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4673 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4682 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4686 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4693 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4699 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4705 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4713 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4725 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4729 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4736 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4742 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4748 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4755 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4766 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4770 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4780 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4784 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4794 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4798 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4802 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4807 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4816 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4822 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4828 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4834 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
        }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4842 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4847 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4855 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4860 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4868 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4876 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4881 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4886 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4891 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4896 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4901 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4910 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4918 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4922 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 4939 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 4943 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 4951 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 4959 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 4967 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 4971 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 4979 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 4985 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 4995 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 5003 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 5007 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 5011 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 5046 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 5052 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5058 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5068 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5072 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5076 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5080 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5084 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5088 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5092 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5099 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5105 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5115 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5123 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5127 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5131 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5135 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5139 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5143 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5147 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5151 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5155 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5163 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5171 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5175 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5179 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5189 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5197 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5205 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5209 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5213 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5221 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5225 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5231 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5237 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5241 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5251 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5259 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5263 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5269 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5278 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5287 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5293 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5299 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5309 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5326 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5333 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5348 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5384 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5388 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5396 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5404 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5416 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5420 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5428 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5436 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5440 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5451 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5468 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5474 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5480 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5490 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5494 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5500 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5506 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5510 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5516 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5520 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5526 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5532 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5539 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5549 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5554 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5562 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5568 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5578 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5600 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5609 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5615 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5628 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5642 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5649 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5655 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5665 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5674 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5682 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5688 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5706 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5714 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5718 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5725 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5730 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5738 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5742 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5749 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5753 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5760 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5764 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5771 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5775 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5784 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5796 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5800 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5807 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5811 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5819 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5827 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5835 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5839 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5846 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5850 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5858 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5869 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5873 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5881 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5893 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5899 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5908 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5912 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5920 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5924 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5928 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5935 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5939 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5946 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5950 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5958 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5962 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5966 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5970 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5974 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5982 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5990 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 6002 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 6014 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 6018 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 6022 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 6030 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 6036 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 6046 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 6050 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 6054 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 6058 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 6062 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 6066 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 6070 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 6074 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 6082 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 6086 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 6090 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 6094 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 6102 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 6108 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 6118 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 6128 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 6132 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 6140 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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

  case 724:

/* Line 678 of lalr1.cc  */
#line 6150 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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

  case 725:

/* Line 678 of lalr1.cc  */
#line 6161 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 6168 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 6172 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 6179 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 6183 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 6190 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 6195 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 6204 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 6213 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 6217 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 6224 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 6228 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 6236 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 6245 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 6252 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 6262 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 6266 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 6273 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 6279 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 6288 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 6292 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 6299 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 6304 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 6316 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 6324 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 6336 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 6344 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 6348 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 6356 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 6360 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 6364 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 6372 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 6380 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 6384 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 6388 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 6392 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 6400 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 6408 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 6420 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 6424 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 6432 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 6446 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 6450 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 6457 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 6462 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 6470 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 6475 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 6484 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 6492 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 6498 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 6508 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        static_cast<JSONPairList*>((yysemantic_stack_[(7) - (4)].node)),
                                        (yysemantic_stack_[(7) - (7)].expr));
        }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 6514 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(10) - (4)].expr), (yysemantic_stack_[(10) - (7)].expr), (yysemantic_stack_[(10) - (10)].expr));
        }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 6521 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(7) - (4)].expr), (yysemantic_stack_[(7) - (7)].expr));
        }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 6528 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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

  case 779:

/* Line 678 of lalr1.cc  */
#line 6557 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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

  case 780:

/* Line 678 of lalr1.cc  */
#line 6586 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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

  case 781:

/* Line 678 of lalr1.cc  */
#line 6615 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 6619 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 6623 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 6630 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 6637 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 6644 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 6661 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
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

  case 791:

/* Line 678 of lalr1.cc  */
#line 6674 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 6675 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 6676 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 6677 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 6678 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 6679 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 6680 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 6681 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 6682 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 6683 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 6684 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 6685 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 6686 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 6687 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 6688 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 6693 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 6694 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 6695 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 6696 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 6697 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 6698 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 6699 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 6700 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 6701 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 6702 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 6703 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 6704 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 6705 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 6706 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 6707 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 6708 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 6709 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 6710 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 6711 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 6712 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 6713 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 6714 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 6715 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 6716 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 6717 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 6718 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 6719 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 6720 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 6721 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 6722 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 6723 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 6724 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 6725 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 6726 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 6727 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 6728 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 6729 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 6730 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 6731 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 6732 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 6733 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 6734 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 6735 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 6736 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 6737 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 6738 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 6739 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 6740 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 6741 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 6742 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 6743 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 6744 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 6745 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 6746 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 6747 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 6748 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 6749 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 6750 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 6751 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 6752 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 6753 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 6754 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 6755 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 6756 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 6757 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6758 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6759 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6760 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6761 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6762 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6763 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6764 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 6765 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 6766 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 6767 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 6768 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 6769 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 6770 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 6771 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 6772 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 6773 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 6774 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 6775 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 6776 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 6777 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 6778 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 6779 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6780 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6781 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 6782 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 6783 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 898:

/* Line 678 of lalr1.cc  */
#line 6784 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 899:

/* Line 678 of lalr1.cc  */
#line 6785 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 900:

/* Line 678 of lalr1.cc  */
#line 6786 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 901:

/* Line 678 of lalr1.cc  */
#line 6787 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 902:

/* Line 678 of lalr1.cc  */
#line 6788 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 903:

/* Line 678 of lalr1.cc  */
#line 6789 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 904:

/* Line 678 of lalr1.cc  */
#line 6790 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 905:

/* Line 678 of lalr1.cc  */
#line 6791 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 906:

/* Line 678 of lalr1.cc  */
#line 6792 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 907:

/* Line 678 of lalr1.cc  */
#line 6793 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 908:

/* Line 678 of lalr1.cc  */
#line 6794 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 909:

/* Line 678 of lalr1.cc  */
#line 6795 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 910:

/* Line 678 of lalr1.cc  */
#line 6796 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 911:

/* Line 678 of lalr1.cc  */
#line 6797 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 912:

/* Line 678 of lalr1.cc  */
#line 6798 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 913:

/* Line 678 of lalr1.cc  */
#line 6799 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 914:

/* Line 678 of lalr1.cc  */
#line 6800 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 915:

/* Line 678 of lalr1.cc  */
#line 6801 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 916:

/* Line 678 of lalr1.cc  */
#line 6802 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 917:

/* Line 678 of lalr1.cc  */
#line 6803 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 918:

/* Line 678 of lalr1.cc  */
#line 6804 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 919:

/* Line 678 of lalr1.cc  */
#line 6805 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 920:

/* Line 678 of lalr1.cc  */
#line 6806 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 921:

/* Line 678 of lalr1.cc  */
#line 6807 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 922:

/* Line 678 of lalr1.cc  */
#line 6808 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 923:

/* Line 678 of lalr1.cc  */
#line 6809 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 924:

/* Line 678 of lalr1.cc  */
#line 6810 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 925:

/* Line 678 of lalr1.cc  */
#line 6811 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 926:

/* Line 678 of lalr1.cc  */
#line 6812 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 927:

/* Line 678 of lalr1.cc  */
#line 6813 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 928:

/* Line 678 of lalr1.cc  */
#line 6814 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 929:

/* Line 678 of lalr1.cc  */
#line 6815 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 930:

/* Line 678 of lalr1.cc  */
#line 6816 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 931:

/* Line 678 of lalr1.cc  */
#line 6817 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 932:

/* Line 678 of lalr1.cc  */
#line 6818 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 933:

/* Line 678 of lalr1.cc  */
#line 6819 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 934:

/* Line 678 of lalr1.cc  */
#line 6820 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 935:

/* Line 678 of lalr1.cc  */
#line 6821 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 936:

/* Line 678 of lalr1.cc  */
#line 6822 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 937:

/* Line 678 of lalr1.cc  */
#line 6823 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 938:

/* Line 678 of lalr1.cc  */
#line 6824 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 939:

/* Line 678 of lalr1.cc  */
#line 6825 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 940:

/* Line 678 of lalr1.cc  */
#line 6826 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 941:

/* Line 678 of lalr1.cc  */
#line 6827 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 942:

/* Line 678 of lalr1.cc  */
#line 6828 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 943:

/* Line 678 of lalr1.cc  */
#line 6829 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 944:

/* Line 678 of lalr1.cc  */
#line 6830 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 945:

/* Line 678 of lalr1.cc  */
#line 6831 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 946:

/* Line 678 of lalr1.cc  */
#line 6832 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 947:

/* Line 678 of lalr1.cc  */
#line 6833 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 948:

/* Line 678 of lalr1.cc  */
#line 6834 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 949:

/* Line 678 of lalr1.cc  */
#line 6835 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 950:

/* Line 678 of lalr1.cc  */
#line 6836 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 951:

/* Line 678 of lalr1.cc  */
#line 6837 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 952:

/* Line 678 of lalr1.cc  */
#line 6838 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 953:

/* Line 678 of lalr1.cc  */
#line 6839 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 954:

/* Line 678 of lalr1.cc  */
#line 6840 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 955:

/* Line 678 of lalr1.cc  */
#line 6841 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 956:

/* Line 678 of lalr1.cc  */
#line 6842 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 957:

/* Line 678 of lalr1.cc  */
#line 6843 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 958:

/* Line 678 of lalr1.cc  */
#line 6844 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 959:

/* Line 678 of lalr1.cc  */
#line 6845 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 960:

/* Line 678 of lalr1.cc  */
#line 6846 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 961:

/* Line 678 of lalr1.cc  */
#line 6847 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 962:

/* Line 678 of lalr1.cc  */
#line 6848 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 963:

/* Line 678 of lalr1.cc  */
#line 6849 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 964:

/* Line 678 of lalr1.cc  */
#line 6850 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 965:

/* Line 678 of lalr1.cc  */
#line 6851 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 966:

/* Line 678 of lalr1.cc  */
#line 6852 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 967:

/* Line 678 of lalr1.cc  */
#line 6853 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 968:

/* Line 678 of lalr1.cc  */
#line 6854 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 969:

/* Line 678 of lalr1.cc  */
#line 6855 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 970:

/* Line 678 of lalr1.cc  */
#line 6856 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 971:

/* Line 678 of lalr1.cc  */
#line 6857 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 972:

/* Line 678 of lalr1.cc  */
#line 6858 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 973:

/* Line 678 of lalr1.cc  */
#line 6859 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 974:

/* Line 678 of lalr1.cc  */
#line 6860 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 975:

/* Line 678 of lalr1.cc  */
#line 6861 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 976:

/* Line 678 of lalr1.cc  */
#line 6862 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 977:

/* Line 678 of lalr1.cc  */
#line 6863 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 978:

/* Line 678 of lalr1.cc  */
#line 6864 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 979:

/* Line 678 of lalr1.cc  */
#line 6865 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 980:

/* Line 678 of lalr1.cc  */
#line 6866 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 981:

/* Line 678 of lalr1.cc  */
#line 6867 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 982:

/* Line 678 of lalr1.cc  */
#line 6868 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 983:

/* Line 678 of lalr1.cc  */
#line 6869 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 984:

/* Line 678 of lalr1.cc  */
#line 6870 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 985:

/* Line 678 of lalr1.cc  */
#line 6871 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 986:

/* Line 678 of lalr1.cc  */
#line 6872 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 987:

/* Line 678 of lalr1.cc  */
#line 6873 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 988:

/* Line 678 of lalr1.cc  */
#line 6874 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 989:

/* Line 678 of lalr1.cc  */
#line 6875 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 990:

/* Line 678 of lalr1.cc  */
#line 6876 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 991:

/* Line 678 of lalr1.cc  */
#line 6877 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 992:

/* Line 678 of lalr1.cc  */
#line 6878 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 993:

/* Line 678 of lalr1.cc  */
#line 6879 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 994:

/* Line 678 of lalr1.cc  */
#line 6880 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 995:

/* Line 678 of lalr1.cc  */
#line 6881 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 996:

/* Line 678 of lalr1.cc  */
#line 6882 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 997:

/* Line 678 of lalr1.cc  */
#line 6883 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 998:

/* Line 678 of lalr1.cc  */
#line 6884 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 999:

/* Line 678 of lalr1.cc  */
#line 6885 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1000:

/* Line 678 of lalr1.cc  */
#line 6886 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1001:

/* Line 678 of lalr1.cc  */
#line 6887 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1002:

/* Line 678 of lalr1.cc  */
#line 6888 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1003:

/* Line 678 of lalr1.cc  */
#line 6889 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1004:

/* Line 678 of lalr1.cc  */
#line 6890 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1005:

/* Line 678 of lalr1.cc  */
#line 6891 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 1006:

/* Line 678 of lalr1.cc  */
#line 6892 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 1007:

/* Line 678 of lalr1.cc  */
#line 6893 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1008:

/* Line 678 of lalr1.cc  */
#line 6894 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 1009:

/* Line 678 of lalr1.cc  */
#line 6895 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 1010:

/* Line 678 of lalr1.cc  */
#line 6896 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 1011:

/* Line 678 of lalr1.cc  */
#line 6897 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 1012:

/* Line 678 of lalr1.cc  */
#line 6902 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 678 of lalr1.cc  */
#line 12151 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1512;
  const short int
  xquery_parser::yypact_[] =
  {
      3462, -1512, -1512, -1512,  5320,  5320,  5320, -1512, -1512,    61,
     280, -1512,   636,    18, -1512, -1512, -1512,   826, -1512, -1512,
   -1512,   311,   326,   832,  2591,   349,   385,   136, -1512,    46,
   -1512, -1512, -1512, -1512, -1512, -1512,   834, -1512,   457,   472,
   -1512, -1512, -1512, -1512,   520, -1512,   836, -1512,   524,   535,
   -1512,   267, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512,   587,   623, -1512, -1512,
   -1512, -1512,   543, 11191, -1512, -1512, -1512,   633, -1512, -1512,
   -1512,   662, -1512,   693,   695, -1512, -1512, 15563, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512,   714, -1512, -1512,   724,
     731, -1512, -1512, -1512, -1512, -1512, -1512, -1512,  4084,  7174,
    7483, 15563, -1512, -1512, -1512, -1512, -1512, -1512, -1512,   715,
   -1512, -1512,   752, 12083, -1512, 12385,   830,   851, -1512, -1512,
   -1512,   858, -1512, 10573, -1512, -1512, -1512, -1512, -1512, -1512,
     838, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,    84,
     788, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,  -103,
     850,   148, -1512,  -102,   -83, -1512, -1512, -1512, -1512, -1512,
   -1512,   893, -1512,   773,   797,   811, -1512, -1512,   898,   908,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512,  7792,  8101, -1512,   754, -1512, -1512, -1512,
   -1512, -1512,  3773,  5629,  1068, -1512,  5938, -1512, -1512,   140,
      92, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512,    96, -1512, -1512, -1512, -1512,
   -1512, -1512,   130, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512,  5320, -1512, -1512, -1512, -1512,    42, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512,   129, -1512,   879, -1512, -1512,
   -1512,   717, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
     904,   981, -1512,  1017,   835,   975,   526,   661,   410,   459,
   -1512,  1030,   883,   985,   986,  9337, -1512, -1512, -1512,   534,
   -1512, -1512, 10882, -1512,   718, -1512,   933, 11191, -1512,   933,
   11191, -1512, -1512, -1512,   428, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512,   944,   934, -1512, -1512,
   -1512, -1512, -1512,   907, -1512,  5320,   912,   913,   324,   324,
    1064,   297,   628,   500, 15850, 15563,   252,  1051, 15563,   948,
     983,   870, 12083,   780,   857, 15563, 15563,   801,   694,    51,
   -1512, -1512, -1512, 12083,  5320,   918,  5320,   137,  9646, 13267,
   15563, -1512,   823,   825, 15563,   989,   394,   956,  9646,  1112,
      88,   344, 15563,   996,   973,  1009, -1512,  9646, 11787, 15563,
   15563, 15563,  5320,   930,  9646,  9646, 15563,  5320,   968,   971,
   -1512, -1512, -1512,  9646, 13554,   967, -1512,   969, -1512, -1512,
   -1512, -1512,   974, -1512,   976, -1512, -1512, -1512, -1512, -1512,
     977, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, 15563,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512,   984, 15563, -1512, -1512, -1512,   943,  4393,  1008,
     279,   978,   979,   980, 15563,  5320, -1512,   987,    95, -1512,
     743, -1512,    83,  1096,  9646, -1512, -1512,    80, -1512, -1512,
   -1512,  1122, -1512, -1512, -1512, -1512,  9646,   929, -1512,  1114,
    9646,  9646, 12684,   957,  9646,  9646,   855,  9646, 12684,  9646,
     915,   919, 15563,   988,   990,  9646,  9646,  4084,   903, -1512,
      60, -1512,    59,  1005,  5629, -1512, -1512, -1512, -1512, -1512,
     636,   136,   100,   105,  1158,  6247,  6247,  6556,  6556,   662,
   -1512, -1512,   233,   662, -1512,  3153,  9646,  9646, -1512,  1045,
     444,    46,   997,   994,   999,  5320,  9646, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512,  9955,  9955,  9955, -1512,  9955,
    9955, -1512,  9955, -1512,  9955, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512,  9955,  9955,  1097,  9955,  9955,  9955,  9955,  9955,
    9955,  9955,  9955,  9955,  9955,  9955,  9955,   936,  1076,  1077,
    1079, -1512, -1512, -1512,  8410, -1512, -1512, 10573, 10573,  9646,
     933, -1512, -1512,   933, -1512,  8719,   933,  1026,  9028, -1512,
   -1512, -1512,    13, -1512,   273, -1512, -1512, -1512, -1512, -1512,
   -1512,  1069,  1070,   349,  1153, -1512, -1512, 15850,   942,   514,
   15563,  1023,  1024,   942,  1064,  1058,  1054, -1512, -1512, -1512,
     464,   945,  1093,   890, 15563,  1049,  9646,  1074, 15563, 15563,
   -1512,  1061,  1010,  5320, -1512,  1011,   969,   472, -1512,  1012,
    1014,   242, -1512,   304,   321,  1090, -1512,    40, -1512, -1512,
    1090, 15563,    30, 15563,  1104,   364, -1512,  5320, -1512,   111,
   -1512, 12083,  1106,  1159, 12083,  1064,  1109,    53, 15563,  9646,
      46,   248,  1019, -1512,  1020,  1021,  1022,    43, -1512,    50,
    1027, -1512,   147,   164,  1057, -1512,  1028,  5320,  5320,   258,
   -1512,   391,   393,   594,  9646,   249, -1512, -1512,  9646,  9646,
   -1512,  9646,  9646,  9646, -1512,  9646, -1512,  9646, -1512, 15563,
    1096, -1512,   220,   362, -1512, -1512, -1512,   368, -1512,   309,
   -1512, -1512,  1060,  1062,  1063,  1065,  1072,   428,   944, -1512,
     285,   318,  9646,  9646,  1120,   476,   991,   993,  1000,    31,
   -1512,  1087, -1512, -1512,  1041,   167,  4702,   377, 11491,   903,
   -1512, -1512, -1512,  9646, -1512,   140,   727,  1199,  1199, -1512,
   -1512,   106, -1512, -1512,   110, -1512,   165, -1512, -1512, -1512,
   -1512, -1512, -1512,  1232, -1512, -1512, 15563,  1066,  9646,  1117,
   -1512, -1512, -1512,   981, -1512, -1512, -1512, -1512, -1512,  9955,
   -1512, -1512, -1512,    70, -1512,   661,   661,    17,   410,   410,
     410,   410,   459,   459, -1512, -1512, 14702, 14702, 15563, 15563,
   -1512,   390, -1512, -1512,   237, -1512, -1512, -1512,   414, -1512,
   -1512,   442,   324, -1512, -1512,    23,   455,   613, -1512,   349,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
     942, -1512,  1108, 14989,  1100,  9646, -1512, -1512, -1512,  1144,
    1064,  1064,   942, -1512,   889,  1064,   683, 15563,   611,   680,
    1215, -1512, -1512,   960,   480, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512,   464,    65,  1029,   532,
    9646, -1512, 15563,  1152,   950,  1064, -1512, -1512, -1512, -1512,
    1101, 15563, -1512, 15563, -1512, 15276,  1130, 14702,  1131,  9646,
     -14,  1111,    32,   495,  1006, -1512, -1512,   617,    30,  1144,
   14702,  1142,  1167,  1081,  1071,  1134,  1064,  1107,  1137,  1175,
    1064,  9646,   218, -1512, -1512, -1512,  1119, -1512, -1512, -1512,
   -1512,  1156,  9646,  9646,  1128, -1512,  1176,  1177,  5320, -1512,
    1094,  1095,  1127, 15563, -1512, 15563, -1512,  9646,  1140,  1098,
    9646, -1512,  1162,   180,   212,   213,  1249, -1512,   335, -1512,
     544, -1512, -1512,  1256, -1512,   -47,  9646,  9646,  9646,   712,
    9646,  9646,  9646,  1008,   348,   239,  9646,  9646,  9646,  9646,
   12684,  1168,  9646,  9646, -1512,  6865,  1139,  1143,  1145,  1149,
     879,   970,  1043, -1512,    -2, -1512,   250,   112,   102,   165,
    6556,  6556,  6556,  1211, -1512, -1512,  9646,   786,  1186, -1512,
   15563,  1189, -1512, -1512,  9646,    70,   723,   584, -1512,  1025,
      81,  1046,  1039, -1512, -1512,   857, -1512,  1038,   596,  1150,
    1151, 14989,  1155,  1161,  1163,  1165,  1166, -1512,   588, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512,  1164, -1512, -1512, -1512,  9646, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512,   666, -1512,  1276,   809,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,  1033,
   -1512, -1512,  1285, -1512, -1512, -1512, -1512, -1512,   703,  1286,
   -1512,   658, -1512, -1512, -1512,   967,   326,   974,   457,   976,
     977,   850,  1161,  1163,  1165, -1512,   588,   588, 10264,  1037,
    1032, -1512,  1144,    65,  1105,  1148,  5320,  1146,  1147,  1180,
    1154,  1170, 15563, -1512,   451, -1512, 15563, -1512,  9646,  1183,
    9646,  1200,  9646,    57,  1185,  9646,  1188, -1512,  1221,  1222,
    9646, 15563,   909,  1266, -1512, -1512, -1512, -1512, -1512, -1512,
   14702, -1512,  5320,  1064,  1241, -1512, -1512, -1512,  1064,  1241,
   -1512,  9646,  1208,  5320, 15563, -1512, -1512,  9646,  9646,   767,
   -1512,   290,   769, -1512, 13841,   812, -1512,   819, -1512,  1171,
   -1512, -1512,  5320,  1172,  1173, -1512,  9646, -1512, -1512,  9646,
    1157,  1176,  1251, -1512,  1226, -1512,   774, -1512, -1512,  1354,
   -1512, -1512,  5320, 15563, -1512,   783, -1512, -1512, -1512,  1174,
    1133,  1135, -1512, -1512, -1512,  1138,  1141, -1512, -1512, -1512,
    1160,  1169, -1512, -1512, -1512,  1126,   386, 15563,  1190, -1512,
   -1512,  9646,  9646,  9646,  5011,  6865, 11491,  1043, -1512, 11491,
   -1512,  1182,  1199,   521, -1512, -1512, -1512,  1186, -1512,  1064,
   -1512,   891, -1512,   302,  1257, -1512,  9646,   707,  1117,   404,
    1179, -1512,    70,  1123, -1512, -1512,   150, -1512,   -91,   139,
    1125,    70,   -91,  9955, -1512,   179, -1512, -1512, -1512, -1512,
   -1512, -1512,    70,  1228,  1102,   945,   139, -1512, -1512,  1099,
    1300, -1512, -1512, -1512, 12980,  1194,  1198,  1201,  1202,  1203,
    1204,  1207, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512,  1358,    22,  1366,    22,  1129,  1289,
   -1512, -1512,  1227, 15563,  1178, -1512, -1512, 10264, -1512,  1214,
   -1512, -1512, -1512, -1512, -1512, -1512,  9646,  1253, -1512, -1512,
    9646, -1512,   510, -1512,  9646,  1255,  9646, -1512,  9646, 15563,
   15563, -1512,   704, -1512,  9646, -1512,  1277,  1280,  1312,  1064,
    1241, -1512,  9646,  1225, -1512, -1512, -1512,  1224, -1512,   292,
    9646,  5320,  1229,   307, -1512, 15563,  1230, 14128,    19, -1512,
   14415,  1231, -1512, -1512,  1234, -1512, -1512, -1512, -1512,  9646,
     820,  1249, 15563,   841, -1512,  1235,  1249, 15563, -1512, -1512,
    9646,  9646,  9646,  9646,  9646,  9646,  9646,  9646, -1512,  9646,
     215,   219,   223,    16, -1512, -1512,  9646, -1512, -1512, -1512,
    1257, -1512, -1512, -1512,  1064,  9646, -1512,  1269, -1512, -1512,
   -1512, -1512,  1236,  9955, -1512, -1512, -1512, -1512, -1512,    79,
    9955,  9955,   577, -1512,  1046, -1512,   502, -1512,  1039,    70,
    1259, -1512, -1512,  1181, -1512, -1512, -1512, -1512,  1319,  1237,
   -1512,   453, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
     475,   475, -1512,    22, -1512, -1512,   458, -1512,  1392,   139,
    1326,  1238, 10264,   -18,  1184,  1258, -1512, -1512,  9646, -1512,
    9646,  1279, -1512,  9646, -1512, -1512, -1512,  1370, -1512, -1512,
    6865,  9646,  1064, -1512, -1512, -1512,  9646,  9646, -1512, -1512,
   -1512,  6865,  6865,  1335,  5320, 15563,  1244, 15563,  9646, 15563,
    1245,  6865, -1512,   338,    26,  1249, 15563, -1512,  1239,  1249,
   -1512, -1512, -1512, -1512, -1512,  1336, -1512, -1512, -1512,  1240,
    1176,  1177,  9646, -1512, -1512, -1512, -1512,  1327,  9646, -1512,
     410,  9955,  9955,    17,   650, -1512, -1512, -1512, -1512, -1512,
   -1512,  9646, -1512, 14702, -1512, 14702,  1342, -1512, -1512, -1512,
    1409, -1512, -1512, -1512,  1187,  1332, -1512, -1512,  1333, -1512,
     789, 15563,  1323,  1218, 15563, 10264, -1512, -1512,  9646, -1512,
    1325, -1512, -1512,  1241, -1512, -1512, 14702, -1512, -1512,  1350,
    9646,  1260, -1512,  1351,  6865, -1512, 15563,   434,   605, -1512,
    1252,  1249, -1512,  1254,  1132,  6865,   824,   412, -1512,  1327,
      17,    17,  9955,   418, -1512, -1512, 14702, -1512, -1512,  1326,
   10264, -1512,  1257,  1191, 15563,  1331,  1233,  1333, -1512, 15563,
    1267, 14702,  5320, 14702,  1268, -1512, -1512,  1359,   649, -1512,
   -1512, -1512, -1512,  1272,   816, -1512, -1512, -1512,  1262, -1512,
    9646,  1338, -1512, -1512,    17, -1512, -1512, -1512, -1512, -1512,
    9646,  1195, 15563,  1341, -1512,  5320,  1275, -1512, -1512,  1278,
    9646, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, 15563,
   -1512,  1192,  1196, 15563, -1512, -1512,  9646,  6865,  1281,  1193,
    9646,  1197,  6865, 10264, -1512, 10264, -1512,  1264,  1205, 15563,
    1247,  1345, 15563,  1206, 10264, -1512
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       163,   458,   459,   460,   166,   166,   166,   807,  1012,   118,
     120,   614,   899,   908,   848,   812,   810,   792,   900,   903,
     855,   816,   793,   794,     0,   909,   796,   906,   877,   857,
     832,   852,   853,   904,   901,   851,   798,   907,   799,   800,
     948,   960,   947,   849,   868,   862,   801,   850,   803,   802,
     949,   886,   887,   854,   829,   970,   971,   972,   973,   974,
     975,   976,   977,   978,   979,   980,   994,  1001,   876,   872,
     863,   843,   791,     0,   871,   879,   888,   995,   867,   484,
     844,   845,   902,   996,  1002,   864,   881,     0,   490,   447,
     486,   874,   809,   865,   866,   895,   869,   885,   894,  1000,
    1003,   815,   856,   897,   485,   884,   890,   795,     0,     0,
       0,     0,   395,   882,   893,   898,   896,   875,   861,   950,
     859,   860,   997,     0,   394,     0,   998,  1004,   891,   846,
     870,   999,   425,     0,   457,   892,   873,   880,   889,   883,
     951,   837,   842,   841,   840,   839,   838,   804,   858,     0,
     808,   905,   830,   939,   938,   940,   814,   813,   833,   945,
     797,   937,   942,   943,   934,   836,   878,   936,   946,   944,
     935,   834,   941,   955,   956,   953,   954,   952,   805,   957,
     958,   959,   925,   924,   911,   828,   821,   918,   914,   831,
     827,   926,   927,   817,   818,   811,   820,   923,   922,   919,
     915,   932,   933,   931,   921,   917,   910,   819,   930,   929,
     823,   825,   824,   916,   920,   912,   826,   913,   822,   928,
     981,   982,   983,   984,   985,   986,   962,   963,   961,   967,
     968,   969,   964,   965,   966,   835,   987,   988,   989,   990,
     991,   992,   993,     0,     0,  1005,  1006,  1007,  1010,  1009,
    1008,  1011,   163,   163,     0,     2,   163,     7,     9,    21,
       0,    26,    29,    34,    35,    36,    37,    38,    39,    40,
      30,    56,    57,    31,    32,     0,    74,    77,    78,    33,
      79,    80,     0,   116,    81,    82,    83,    84,    16,   160,
     161,   162,   169,   171,   477,   172,     0,   173,   174,   175,
     176,   177,   178,   179,   182,     0,   208,   217,   212,   244,
     250,     0,   242,   243,   219,   213,   181,   214,   180,   215,
     218,   348,   350,   352,   362,   364,   368,   370,   373,   378,
     381,   384,   386,   388,   390,     0,   392,   398,   400,     0,
     416,   399,   421,   424,   426,   429,   431,     0,   436,   433,
       0,   444,   454,   456,   430,   461,   468,   482,   469,   470,
     471,   474,   475,   472,   473,   497,   499,   500,   501,   498,
     546,   547,   548,   549,   550,   551,   453,   588,   580,   587,
     586,   585,   582,   584,   581,   583,   483,   476,   615,   616,
      41,   220,   221,   223,   222,   224,   216,   479,   480,   481,
     478,   226,   229,   225,   227,   228,   455,   790,   806,   899,
     908,   906,   808,     0,   164,   165,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     124,   126,   127,     0,     0,     0,     0,     0,     0,     0,
       0,   254,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   272,   273,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     449,   452,   439,     0,     0,   792,   816,   794,   847,   909,
     796,   857,   798,   868,   801,   803,   802,   886,   994,  1001,
     791,   995,   845,   996,  1002,   869,  1000,  1003,   950,   997,
     998,  1004,   999,   951,   945,   937,   943,   934,   834,   955,
     956,   953,   805,   957,  1006,   445,   455,   790,   437,     0,
     189,   438,   441,   792,   793,   794,   798,   799,   800,   801,
     791,   797,   487,     0,   443,   442,   184,     0,     0,   208,
       0,   796,   803,   802,     0,   166,   766,   957,     0,   217,
       0,   488,     0,   513,     0,   448,   788,     0,   789,   419,
     420,     0,   451,   450,   440,   423,     0,     0,   542,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   768,
       0,   770,     0,     0,   163,     3,     4,     1,     8,    10,
       0,     0,     0,     0,     0,   163,   163,   163,   163,     0,
     117,   170,     0,     0,   187,     0,     0,     0,   196,     0,
       0,     0,     0,     0,     0,     0,     0,   201,   230,   249,
     245,   251,   246,   248,   247,     0,     0,     0,   409,     0,
       0,   407,     0,   357,     0,   408,   401,   406,   405,   404,
     403,   402,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   397,   396,   393,     0,   417,   422,     0,     0,     0,
     432,   465,   435,   434,   446,     0,   462,     0,     0,   553,
     555,   559,     0,   122,     0,   787,    45,    42,    43,    46,
      47,     0,     0,     0,     0,    48,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   625,   626,   627,
       0,   101,   140,     0,     0,   110,     0,     0,     0,     0,
     125,     0,     0,     0,   594,     0,     0,     0,   590,     0,
       0,     0,   604,     0,     0,   253,   255,     0,   232,   233,
     252,     0,     0,     0,   132,     0,   136,   166,   618,     0,
      58,     0,    67,     0,     0,     0,    59,     0,     0,     0,
       0,     0,     0,   595,     0,     0,     0,     0,   321,     0,
       0,   593,     0,     0,     0,   612,     0,     0,     0,     0,
     598,     0,     0,   191,     0,     0,   185,   183,     0,     0,
     772,     0,     0,     0,   487,     0,   767,     0,   489,   514,
     513,   510,     0,     0,   544,   543,   418,     0,   541,     0,
     638,   639,   792,   794,   798,   801,   791,   778,     0,   589,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     644,     0,   199,   200,     0,     0,     0,     0,     0,   204,
     205,   769,   771,     0,     5,    22,     0,    23,     0,     6,
      27,     0,    13,    28,     0,    17,   899,    75,    14,    76,
      18,   190,   188,     0,   209,   211,     0,     0,     0,     0,
     202,   231,   290,   349,   351,   355,   361,   360,   359,     0,
     356,   353,   354,     0,   365,   372,   371,   369,   375,   376,
     377,   374,   379,   380,   383,   382,     0,     0,     0,     0,
     414,     0,   427,   428,     0,   466,   463,   495,     0,   617,
     493,     0,     0,   119,   121,     0,     0,     0,   100,     0,
      90,    92,    93,    94,    95,    97,    98,    99,    91,    96,
      86,    87,     0,     0,   106,     0,   102,   104,   105,   112,
       0,     0,    85,    44,     0,     0,     0,     0,     0,     0,
       0,   716,   721,     0,     0,   717,   751,   704,   706,   707,
     708,   710,   712,   711,   709,   713,     0,     0,     0,     0,
       0,   109,     0,   142,     0,     0,   558,   552,   591,   592,
       0,     0,   608,     0,   605,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   234,   235,     0,   240,   138,
       0,     0,   133,     0,     0,     0,     0,     0,     0,    60,
       0,     0,     0,   271,   277,   274,     0,   597,   596,   603,
     611,     0,     0,     0,     0,   557,     0,     0,     0,   410,
       0,     0,     0,     0,   601,     0,   599,     0,   192,     0,
       0,   773,     0,     0,     0,     0,   513,   511,     0,   502,
       0,   491,   492,     0,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   197,     0,   796,   803,   802,   957,
       0,     0,     0,   652,     0,   206,     0,     0,     0,     0,
     163,   163,   163,     0,   210,   241,     0,   305,   301,   303,
       0,   291,   292,   358,     0,     0,     0,     0,   682,   366,
     655,   659,   661,   663,   665,   668,   675,   676,   684,   909,
     795,     0,   804,  1010,  1009,  1008,  1011,   385,   564,   570,
     571,   574,   619,   620,   575,   576,   781,   782,   783,   579,
     387,   389,   561,   391,   415,   467,     0,   464,   494,   123,
      54,    55,    52,    53,   129,   128,     0,    88,     0,     0,
     107,   108,   113,    72,    73,    50,    51,    71,   722,     0,
     725,   752,     0,   715,   714,   719,   718,   750,     0,     0,
     727,     0,   723,   726,   705,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,   144,   146,     0,     0,
       0,   111,   114,     0,     0,     0,   166,     0,     0,   612,
       0,     0,     0,   257,     0,   563,     0,   258,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   236,     0,     0,
       0,     0,   284,     0,   281,   286,   239,   139,   134,   137,
       0,   186,     0,     0,    69,    63,    66,    65,     0,    61,
     275,     0,     0,   166,     0,   319,   323,     0,     0,     0,
     326,     0,     0,   332,     0,     0,   339,     0,   343,     0,
     412,   411,   166,     0,     0,   193,     0,   195,   320,     0,
       0,     0,     0,   514,     0,   503,     0,   537,   534,     0,
     538,   539,     0,     0,   533,     0,   508,   536,   535,     0,
       0,     0,   631,   632,   628,     0,     0,   636,   637,   633,
       0,     0,   642,   779,   640,     0,     0,     0,     0,   646,
     198,     0,     0,     0,     0,     0,     0,   647,   648,     0,
     207,     0,    24,     0,    15,    19,    20,   302,   314,     0,
     315,     0,   306,   307,   308,   309,     0,   294,     0,     0,
       0,   666,   679,     0,   363,   367,     0,   698,     0,     0,
       0,     0,     0,     0,   654,   656,   657,   693,   694,   695,
     697,   696,     0,     0,   670,   669,     0,   673,   677,   691,
     689,   688,   681,   685,     0,     0,     0,     0,     0,     0,
       0,     0,   567,   569,   568,   565,   562,   496,   131,   130,
      89,   103,   739,   720,     0,   744,     0,   744,   733,   728,
     145,   147,     0,     0,     0,   115,   143,     0,    25,     0,
     609,   610,   613,   606,   607,   256,     0,     0,   270,   262,
       0,   266,     0,   260,     0,     0,     0,   279,     0,     0,
       0,   238,   282,   285,     0,   135,     0,     0,    68,     0,
      62,   276,     0,     0,   322,   324,   329,     0,   327,     0,
       0,     0,     0,     0,   333,     0,     0,     0,     0,   340,
       0,     0,   344,   413,     0,   602,   600,   194,   774,     0,
       0,   513,     0,     0,   545,     0,   513,     0,   509,    12,
       0,     0,     0,     0,     0,     0,     0,     0,   645,     0,
       0,     0,     0,     0,   649,   653,     0,   318,   316,   317,
     310,   311,   312,   304,     0,     0,   299,     0,   293,   683,
     674,   680,     0,     0,   753,   754,   764,   763,   762,     0,
       0,     0,     0,   755,   660,   761,     0,   658,   662,     0,
       0,   667,   671,     0,   692,   687,   690,   686,     0,     0,
     577,     0,   572,   624,   566,   785,   786,   784,   573,   740,
       0,     0,   738,   745,   746,   742,     0,   737,     0,   735,
       0,     0,     0,     0,     0,     0,   554,   259,     0,   268,
       0,     0,   264,     0,   267,   280,   288,   289,   283,   237,
       0,     0,     0,    64,   278,   560,     0,     0,   330,   334,
     328,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   556,     0,     0,   513,     0,   540,     0,   513,
     629,   630,   634,   635,   775,     0,   641,   780,   643,     0,
       0,     0,     0,   650,   777,   313,   300,   295,     0,   678,
     765,     0,     0,   757,     0,   703,   702,   701,   700,   699,
     664,     0,   756,     0,   621,     0,     0,   749,   748,   747,
       0,   741,   734,   732,     0,   729,   730,   724,   148,   150,
     152,     0,     0,     0,     0,     0,   263,   261,     0,   269,
       0,   203,   347,    70,   325,   331,     0,   345,   341,     0,
       0,     0,   335,     0,     0,   337,     0,   523,   517,   512,
       0,   513,   504,     0,     0,     0,     0,     0,   298,   296,
     759,   758,     0,     0,   622,   578,     0,   743,   736,     0,
       0,   154,   153,     0,     0,     0,     0,   149,   265,     0,
       0,     0,     0,     0,     0,   531,   525,     0,   524,   526,
     532,   529,   519,     0,   518,   520,   530,   506,     0,   505,
       0,     0,   651,   297,   760,   672,   623,   731,   151,   155,
       0,     0,     0,     0,   287,     0,     0,   338,   336,     0,
       0,   516,   527,   528,   515,   521,   522,   507,   776,     0,
     156,     0,     0,     0,   346,   342,     0,     0,     0,     0,
       0,     0,     0,     0,   158,     0,   157,     0,     0,     0,
       0,     0,     0,     0,     0,   159
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1512, -1512,  -237,  -195, -1512,  1209,  1213, -1512,  1216,  -550,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1027, -1512, -1512, -1512, -1512,  -219,  -583, -1512,   750,   -15,
   -1512, -1512, -1512, -1512, -1512,   295,   522, -1512, -1512,   -10,
    -202,  1059, -1512,  1040, -1512, -1512,  -622, -1512,   456, -1512,
     257, -1512,  -213,  -257, -1512,  -567, -1512,    21,    37,    24,
    -217,  -178, -1512,  -868, -1512, -1512,   268, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512,   626,   -90,  1378,
       0, -1512, -1512, -1512, -1512,   470, -1512, -1512,  -287, -1512,
       8, -1512,  1036,  -922,  -718,  -705, -1512, -1512,   713, -1512,
   -1512,    39,   240, -1512, -1512, -1512,   135, -1502, -1512,   388,
     141, -1512, -1512,   142, -1301, -1512,   963,   235, -1512, -1512,
     234, -1001, -1512, -1512,   230, -1512, -1512, -1247, -1231, -1512,
     227, -1512, -1512,   871,   869, -1512,  -560,   852, -1512, -1512,
    -657,   375,  -654,   373,   374, -1512, -1512, -1512, -1512, -1512,
    1210, -1512, -1512, -1512, -1512,  -859,  -332, -1165, -1512,   -97,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512,    -9,  -812, -1512,
    -551,   647,   288, -1512,  -409, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512,   821, -1512, -1014, -1512,   216, -1512,   698,  -798,
   -1512, -1512, -1512, -1512, -1512,  -243,  -235, -1210,  -860, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,   609,
    -756,  -846,  -157,  -838, -1512,   145,  -835, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512,  1082,  1083,  -192,   528,   354, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512,   196, -1512, -1512,   187, -1512,   190, -1058,
   -1512, -1512, -1512,   156,   146,   -20,   415, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
     155, -1512, -1512, -1512,   -13,   407,   558, -1512, -1512, -1512,
   -1512, -1512,   345, -1512, -1512, -1511, -1512, -1512, -1512,  -515,
   -1512,   120, -1512,   -35, -1512, -1512, -1512, -1512, -1310, -1512,
     168, -1512, -1512, -1512, -1512, -1512,   709, -1512, -1512, -1512,
   -1512, -1512,  -912, -1512, -1512, -1512,  -388,  -373,   236,   608,
   -1512
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   254,   627,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
    1264,   775,   272,   273,   274,   275,   276,   277,   950,   951,
     952,   278,   279,   280,   956,   957,   958,   281,   438,   282,
     283,   702,   284,   440,   441,   442,   457,   765,   766,   285,
    1215,   286,  1688,  1689,   287,   288,   289,   547,   290,   291,
     292,   293,   294,   768,   295,   296,   530,   297,   298,   299,
     300,   301,   302,   637,   303,   304,   859,   860,   305,   306,
     559,   308,   638,   455,  1017,  1018,   309,   639,   310,   641,
     560,   312,   755,   756,  1252,   464,   313,   465,   466,   762,
    1253,  1254,  1255,   642,   643,  1121,  1122,  1536,   644,  1118,
    1119,  1362,  1363,  1364,  1365,   314,   787,   788,   315,  1279,
    1280,  1479,   316,  1282,  1283,   317,   318,  1285,  1286,  1287,
    1288,   319,   320,   321,   322,   899,   323,   324,  1374,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   662,   663,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   696,   691,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   928,   364,   365,   366,  1315,   820,   821,   822,
    1719,  1763,  1764,  1757,  1758,  1765,  1759,  1316,  1317,   367,
     368,  1318,   369,   370,   371,   372,   373,   374,   375,  1161,
    1012,  1147,  1415,  1148,  1571,  1149,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   794,  1228,   386,   387,
     388,   389,  1151,  1152,  1153,  1154,   390,   391,   392,   393,
     394,   395,   849,   850,   396,  1347,  1348,  1653,  1104,  1129,
    1384,  1385,  1130,  1131,  1132,  1133,  1134,  1394,  1561,  1562,
    1135,  1397,  1136,  1542,  1137,  1138,  1402,  1403,  1567,  1565,
    1386,  1387,  1388,  1389,  1668,   731,   977,   978,   979,   980,
     981,   982,  1202,  1591,  1685,  1203,  1589,  1683,   983,  1427,
    1586,  1582,  1583,  1584,   984,   985,  1390,  1398,  1552,  1391,
    1548,  1375,   397,   398,   399,   400,   550,   401,   402,   403,
     404,   405,  1155,  1156,  1157,  1158,  1265,   567,   406,   407,
     408
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int xquery_parser::yytable_ninf_ = -848;
  const short int
  xquery_parser::yytable_[] =
  {
       307,   598,   439,  1269,   307,   307,   307,   685,   311,   703,
     703,   907,   311,   311,   311,   908,   909,   910,   911,   558,
     562,  1032,  1068,   616,   640,   413,   416,   417,   415,   415,
     415,   837,   706,  1044,   877,   879,   575,   845,   618,  1010,
     613,   414,   414,   414,  1127,  1281,  1103,  1058,   872,   875,
     878,   880,  1011,  1432,  1489,  1500,  1314,   605,   606,   726,
     625,   625,  1531,  1532,   525,   870,   873,  1370,  1241,  1175,
     741,  1160,   772,   776,   621,  1217,  1006,     9,    10,  1686,
     620,  1150,  1150,  1233,   625,  1014,  1563,   895,   824,   896,
     897,   937,   898,   614,   900,   784,   625,   614,   424,    11,
    1691,   614,   901,   902,  1205,  1508,   614,   614,   307,  1206,
     746,   614,   625,   614,   577,  1179,   311,   705,  1150,  1717,
     932,   580,   587,   581,  1207,   427,  1208,   747,  1008,  -167,
     625,  1661,   548,  1238,  1007,  1209,  1008,  1627,  1091,   420,
     421,   589,   422,   423,  1007,   414,   590,  1007,   625,   623,
    1041,  1344,  1216,   600,   602,  1728,     9,    10,  1580,   426,
     459,  1235,  1210,   737,   462,   625,   626,   626,   625,  1652,
     460,  1170,  1150,   610,  1258,   666,  1546,  1376,   443,  1242,
      79,   625,   746,  1547,  1320,  1150,  1321,  1009,  1171,   611,
     626,     9,    10,   667,    90,  1031,   461,  1043,   621,   747,
     933,   622,   626,  1182,  1454,  1628,  1692,  1349,  1662,  1718,
     582,   588,   424,   625,   625,  1353,   625,   418,   626,   104,
     625,   425,  1581,  1124,   625,  1349,  1125,  1773,  1777,  1655,
     591,  1042,   624,  -168,   625,  1549,   626,   620,   625,   427,
     625,  1470,   619,   625,   428,   686,  1015,   125,   771,   625,
    1377,   625,   307,   307,   626,   825,   307,  1246,   463,   625,
     311,   311,   432,  1257,   311,  1092,  1127,  1127,  1304,  1489,
     818,   626,  1595,   640,   626,  1376,   429,   430,  1113,  1684,
     816,  1483,   615,  1016,   877,   879,   617,   626,  1693,  1211,
     865,   307,  1314,  1508,  1243,   867,  1110,   578,  1024,   311,
    1112,  1314,  1352,  1406,   463,  1239,  1150,  1244,  1419,   526,
    1445,  1217,   463,  -167,  1541,   870,   873,  1176,   463,   626,
     626,   433,   626,   542,   748,   622,   626,  1272,  1126,   463,
     626,   621,  1378,  1379,  1046,  1380,   963,   738,   692,  1123,
     626,   694,  1381,   476,   626,   739,   626,   563,  1377,   626,
    1069,  1047,  1382,    11,  1095,   626,  1041,   626,   751,   568,
    1271,   571,   434,   625,  1383,   626,  1544,  1300,   769,   625,
     861,   862,   584,   705,   585,   866,   868,   781,   625,  1075,
     932,  1212,  1213,  1214,   792,   793,   809,  1029,  1216,  1741,
    1480,   625,  1480,   799,  1550,  1551,   871,   874,  1025,  1301,
    1302,  1028,  1649,  1545,  1726,   625,  1650,  1480,  1359,   864,
    1651,  1001,  1079,   625,  1465,   307,  1070,  -168,   890,   625,
     477,   715,  1165,   311,  1331,  1150,  1000,  1690,  1003,  1361,
    1378,  1379,  1036,  1380,    79,  1351,   419,  1060,  1486,  1755,
    1073,  1779,  1052,  1307,   307,   450,   307,   451,    90,  1150,
    1382,   435,   311,   716,   311,   809,  1716,   773,   622,   436,
     934,   586,  1383,   810,   446,  1305,  1435,   437,   743,   626,
     743,  1021,   307,   104,   823,   626,  1481,   307,  1617,   707,
     311,   742,   447,   745,   626,   311,   827,   478,   479,  1314,
     463,  1002,   708,  1622,  1128,  1489,   743,   626,  1053,  1074,
    1055,   743,  1076,  1077,   774,   456,   855,   857,  1004,   790,
     452,   626,   763,  1127,   796,   453,  1447,  1078,   966,   626,
     967,  1166,  1127,  1169,  1628,   626,   621,   877,   879,   877,
    1690,  1306,  1330,  1127,  1103,  1080,  1081,  1525,  1455,  1336,
     689,   458,   695,  1354,  1355,  1356,  1071,  1008,   307,  1166,
    1082,  1022,  1072,  1307,  1308,   307,   311,  1310,  1570,  1311,
    1675,  1102,   454,   311,   968,  1680,   721,  1756,   722,  1150,
    1087,  1424,  1183,  1184,  1164,  1690,  1199,  1187,  1054,   415,
    1056,   764,   689,   526,   695,  1703,   526,  1312,  1539,  1007,
     922,   923,   414,  1200,   921,   675,  1772,   307,  1446,   924,
     439,  1167,  1775,  1172,   307,   311,  1008,  1225,   953,   676,
     673,  1537,   311,   469,  1307,   307,   307,   307,   307,   674,
    1173,   856,  1517,   311,   311,   311,   311,   724,   470,  1168,
     689,  1426,   695,  1761,  1111,   307,  1201,   868,   471,   621,
    1676,  1626,  1245,   311,  1630,  1681,  1107,  1309,  1816,  1483,
    1817,   954,  1150,   622,  1755,  1150,   955,  1600,  1307,  1825,
     666,   714,     9,    10,   718,   482,   711,  1310,   568,  1311,
    1248,   732,   733,   420,   421,  1249,   422,   423,   667,   568,
     474,   527,   712,   424,   666,   754,   757,   684,  1007,   725,
     757,   475,   425,   426,  1250,   527,   483,  1312,   777,   484,
    1127,   111,   667,  1634,   568,   785,   786,   789,  1638,   480,
     427,   125,   795,  1008,   969,   428,  1128,  1128,   123,   527,
     802,  1063,  1064,  1065,   668,   857,  1556,   970,  1310,   971,
    1311,   527,  1412,   527,  1601,  1251,  1057,  1372,  1313,  1762,
     972,   973,   974,   307,   975,   481,   976,   429,   430,   431,
    1174,   311,    11,  1085,  1199,   528,   149,  1248,  1312,   629,
    1108,   125,  1249,   630,  1413,   803,   767,   307,   631,   877,
    1665,  1200,  1310,  1106,  1311,   311,   611,  1666,   669,   789,
     529,  1414,  1792,  1307,  1308,   629,   632,  1667,  1023,   630,
     814,   415,  1307,  1308,   631,   685,   432,   307,   307,  1424,
    1008,  1007,  1312,  1418,   414,   311,   311,   670,   666,  1227,
     709,  1230,   632,  1534,   640,   531,  1425,   532,   838,   767,
     671,   743,   743,   710,   838,  1307,   667,  1734,   851,  1735,
    1219,   735,   543,    79,  1050,  1051,   736,  1720,  1150,  1220,
    1150,  1723,  1399,  1400,  1761,  1665,   544,    90,  1732,  1535,
    1307,  1308,  1666,   545,   672,   433,  1100,  1760,  1766,  1426,
    1750,  1293,  1667,  1294,  1101,  1401,   439,  1278,   564,  1278,
     868,  1150,   104,  1193,   565,  1468,  1124,  1309,  1340,  1125,
    1477,  1358,  1482,  1007,  1194,   633,  1309,   881,   634,  1660,
    1776,   882,  1359,  1663,  1664,  1359,   434,  1310,  1760,  1311,
     125,  1150,  1360,   635,  1766,  1786,  1310,  1789,  1311,   687,
     688,   633,  1487,  1361,   634,   721,  1150,   722,  1150,  1490,
    1487,   598,   435,  1768,  1487,  1488,  1350,  1312,   636,   817,
     436,   111,  1491,  1633,  1742,  1177,  1312,  1771,   437,  1310,
     111,  1311,  1195,  1325,  1309,  1326,   954,  1177,   123,   723,
    1795,   955,   572,  1196,   636,   527,   959,   123,   527,  1188,
    1189,  1190,  1248,  1128,  1310,  1191,  1311,  1249,  1502,  1312,
     989,  1527,  1128,   573,   993,   994,   724,  1507,   925,   444,
     574,   925,   445,  1128,   925,   448,   149,   467,   449,   472,
     468,   576,   473,   690,  1312,   149,   693,  1013,   111,  1019,
     727,   728,   729,   579,  1730,  1731,   583,   568,   842,   843,
     568,   592,   629,   593,  1033,   123,   630,  1185,  1186,  1528,
    1529,   631,   940,   941,   942,   943,   944,   945,   946,   947,
     948,   949,   713,   527,  1369,  1636,   527,   594,   725,   632,
     527,   905,   906,   527,   527,  1466,   912,   913,   307,   914,
     915,   527,   595,   149,   596,  1066,   311,   527,   527,  1430,
    1431,   597,   527,  1162,  1162,  1677,  1678,   603,   607,   628,
     527,   645,   743,   646,   665,  1774,   527,   527,   527,   527,
     677,  1613,   678,   664,   527,  1289,   679,   689,   680,   697,
     698,   699,   527,   705,   526,  1100,   700,   701,   717,   439,
     719,   720,   730,  1101,   734,   744,   758,   761,   759,   767,
     307,   307,   307,   770,   778,   779,   780,   791,   311,   311,
     311,   797,  1115,   445,   798,   449,   804,   806,   890,   808,
     468,   819,   473,   484,   811,   812,   813,   527,   633,   826,
     815,   634,   828,   829,   839,   847,  1656,   858,   848,   647,
    1128,   527,  1159,  1159,  1159,  1159,  1345,   648,   649,   863,
     650,   869,   527,   886,   888,   887,   916,   903,   651,   889,
     917,   918,   652,   919,   653,   929,   935,   936,   852,   654,
     853,   636,   938,   960,   961,   964,   965,   987,   988,  1159,
     986,   990,   992,   995,   996,   997,   655,  1005,  1020,   998,
     527,   999,  1026,  1192,  1027,  1030,  1037,  1038,  1039,  1040,
    1048,  1045,  1049,   444,  1086,   448,   467,  1089,   472,   656,
     657,   658,   659,   660,   661,   483,   307,  1088,  1222,  1093,
    1090,  1094,  1109,  1114,   311,  1120,  1116,  1229,  1007,  1229,
    1178,   757,   955,  1159,  1197,  1198,  1223,  1439,  1224,  1236,
     415,  1520,  1521,  1522,  1226,  1218,  1159,  1234,  1240,  1247,
     763,  1260,   307,   414,  1619,  1261,  1263,  1266,  1262,  1267,
     311,  1268,  1273,   307,  1274,  1277,  1278,  1284,  1290,  1291,
    1292,   311,  1296,  1299,  1303,  1319,  1337,  1346,  1297,   795,
     723,   795,   307,  1366,  1473,  1341,  1368,   415,  1393,  1342,
     311,  1343,  1344,  1392,  1396,    11,  1404,  1405,  1416,  1373,
     414,  1407,   307,  1494,  1423,  1428,   415,  1408,  1422,  1409,
     311,  1410,  1411,  1433,  1442,   939,   838,  1452,   527,   414,
    1450,  1437,  1456,  1440,  1441,  1458,   743,  1434,  1438,  1459,
    1460,  1443,   527,  1464,  1100,  1100,   527,   527,  1469,  1505,
    1472,  1487,  1101,  1101,  1499,  1493,  1367,  1444,  1501,  1495,
    1496,  1504,  1516,  1359,  1509,  1510,  1540,  1511,   856,   527,
    1512,   527,  1543,  1513,  1553,  1559,  1519,  1159,  1566,   527,
    1526,  1572,   527,  1560,  1564,  1573,   527,  1579,  1574,  1575,
    1576,  1577,  1514,  1701,  1578,  1585,  1590,  1592,  1596,  1588,
    1598,  1515,  1603,  1610,  1705,  1619,  1611,  1707,  1612,  1615,
    1616,  1658,  1671,  1673,  1715,  1621,  1624,  1631,  1632,  1637,
    1659,  1682,  1199,  1700,  1674,  1687,  1698,   527,  1695,  1706,
    1710,  1714,  1724,  1534,  1594,  1722,  1736,  1725,  1737,  1739,
    1740,  1744,  1745,  1749,  1751,  1753,  1752,  1770,  1767,  1782,
    1769,  1738,  1791,  1785,  1790,  1794,  1799,  1783,  1797,  1803,
    1672,  1806,  1818,  1822,  1807,   608,   527,  1812,   757,   609,
    1694,  1821,  1448,   962,  1421,   612,  1180,  1259,   704,   740,
    1436,   307,  1747,  1778,  1809,  1105,   549,  1462,  1256,   311,
     760,  1819,  1463,  1035,   527,  1780,  1159,  1707,  1813,  1801,
    1810,  1608,  1815,  1538,  1357,  1530,   805,  1533,  1466,  1474,
     789,  1824,  1484,  1478,  1492,   894,   893,   904,  1067,   931,
    1159,  1796,  1503,  1793,   527,   527,   527,   527,  1163,   749,
     750,  1231,  1420,  1518,  1524,  1787,  1523,  1554,  1558,  1670,
    1557,  1371,  1395,  1669,  1204,   683,  1429,  1587,  1679,  1506,
    1555,  1084,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   527,  1727,     0,     0,     0,     0,     0,  1804,     0,
       0,     0,     0,   851,     0,   527,     0,     0,     0,     0,
       0,  1733,   526,     0,     0,   526,     0,     0,     0,     0,
    1804,     0,     0,     0,     0,  1787,     0,     0,     0,     0,
     527,     0,     0,     0,     0,     0,     0,     0,     0,   527,
    1100,   527,     0,   527,     0,   527,     0,     0,  1101,     0,
       0,  1100,  1100,     0,   307,     0,     0,     0,   527,  1101,
    1101,  1100,   311,     0,     0,     0,     0,     0,     0,  1101,
    1159,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   527,     0,   527,     0,     0,     0,     0,     0,  1593,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1606,  1607,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1100,     0,     0,     0,     0,     0,
       0,  1623,  1101,  1159,     0,  1100,  1159,     0,   527,     0,
       0,     0,     0,  1101,     0,     0,     0,     0,  1635,     0,
       0,     0,     0,  1639,     0,     0,     0,     0,     0,   527,
       0,     0,   307,     0,     0,     0,     0,     0,     0,     0,
     311,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   307,     0,     0,     0,     0,
       0,     0,     0,   311,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1100,     0,     0,
       0,     0,  1100,     0,     0,  1101,     0,     0,     0,     0,
    1101,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     527,     0,     0,     0,   527,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   527,
       0,  1709,     0,  1711,     0,  1713,     0,     0,   527,     0,
       0,     0,  1721,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   527,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   527,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1159,
       0,  1159,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   527,     0,     0,     0,     0,     0,  1743,     0,     0,
    1746,     0,     0,   549,     0,     0,     0,     0,     0,     0,
       0,     0,  1159,     0,     0,   527,     0,     0,     0,     0,
       0,     0,  1754,     0,   527,     0,     0,   527,   830,   831,
       0,     0,   840,   841,     0,   844,     0,   846,     0,     0,
       0,     0,  1159,   854,     0,     0,     0,     0,     0,     0,
    1781,     0,     0,     0,     0,  1784,     0,  1159,     0,  1159,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   883,   884,   885,     0,     0,     0,     0,
       0,     0,   527,   891,   892,     0,     0,     0,  1802,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1808,     0,     0,     0,  1811,
       0,   527,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1820,     0,     0,  1823,     0,
       0,     0,     0,     0,     0,     0,     0,   527,   527,     0,
       0,     0,     0,   927,     0,     0,   927,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   527,     0,   527,     0,     0,   527,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     527,     0,     0,     0,   991,   527,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1034,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1059,     0,     0,     0,  1061,  1062,     0,     0,
       0,     0,     0,     0,     0,   891,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1083,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   527,     0,   527,     0,   527,     0,     0,
       0,     0,     0,     0,   527,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   527,     0,   527,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   527,
       0,     0,   527,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   527,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   527,     0,     0,     0,     0,     0,
       0,     0,     0,  1181,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   527,     0,     0,     0,     0,     0,
       0,     0,   527,     0,     0,     0,     0,   527,     0,   527,
       0,   527,     0,     0,     0,     0,     0,     0,  1221,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1237,     0,     0,
     527,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   527,     0,  1270,
       0,   527,     0,     0,     0,     0,     0,     0,     0,     0,
    1275,  1276,     0,     0,     0,     0,     0,   527,     0,     0,
     527,     0,     0,     0,     0,  1295,     0,     0,  1298,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1322,  1323,  1324,     0,  1327,  1328,
    1329,     0,     0,     0,  1332,  1333,  1334,  1335,     0,     0,
    1338,  1339,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1417,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -847,   450,     0,   451,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1449,     0,  1451,     0,
    1453,     0,     0,  1457,     0,     0,     0,     0,  1461,     0,
       0,     0,     0,  -847,     0,     0,     0,  -847,     0,     0,
    1467,  -847,  -847,     0,     0,     0,  -847,     0,     0,  1471,
       0,     0,     0,     0,     0,  1475,  1476,   452,     0,     0,
    -847,     0,   453,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1497,     0,     0,  1498,     0,     0,
       0,     0,     0,  -847,     0,  -847,  -847,  -847,     0,     0,
    -847,  -847,  -847,  -847,     0,     0,     0,  -847,  -847,     0,
       0,     0,     0,     0,  -847,     0,     0,  -847,  -847,   454,
       0,     0,  -847,     0,     0,     0,     0,  -847,  -847,     0,
       0,     0,     0,  -847,     0,     0,     0,  -847,     0,     0,
       0,  -847,  -847,     0,  -847,     0,  -847,  -847,     0,     0,
       0,  -847,  -847,     0,  1117,  -847,  -847,  -847,  -847,  -847,
    -847,     0,     0,  -847,     0,     0,     0,     0,  -847,  -847,
       0,     0,  -847,     0,     0,     0,     0,  -847,     0,     0,
    -847,     0,     0,     0,     0,  -847,  -847,  -847,  -847,  -847,
       0,  -847,  -847,  -847,  -847,     0,     0,     0,     0,  -847,
    -847,  -847,     0,  -847,  -847,  -847,  -847,  -847,  -847,     0,
    -847,     0,  -847,     0,     0,     0,     0,  -847,  -847,  -847,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -847,  1597,  -847,     0,  -847,  1599,     0,
       0,     0,  1602,     0,  1604,     0,  1605,     0,     0,  -847,
       0,     0,  1609,     0,  -847,     0,     0,     0,     0,     0,
    1614,     0,     0,     0,     0,     0,     0,     0,  1618,  1620,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1467,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1640,  1641,
    1642,  1643,  1644,  1645,  1646,  1647,     0,  1648,     0,     0,
       0,  -847,     0,  -847,  1654,     0,     0,     0,     0,     0,
       0,     0,     0,  1657,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1696,     0,  1697,     0,
       0,  1699,     0,     0,     0,     0,     0,     0,     0,  1702,
       0,     0,     0,     0,  1704,  1620,     0,     0,     0,     0,
       0,     0,  1708,     0,     0,     0,  1712,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1729,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1748,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1708,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1788,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1798,     0,
       0,     0,     0,     0,     0,     0,   869,     0,  1800,     0,
       0,     0,     0,  1805,     1,     2,     0,     0,  1788,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     0,
       0,     0,    11,     0,  1805,     0,   409,   410,  1814,    14,
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
     125,     0,     0,   126,   127,   128,     0,     0,     0,   129,
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
     250,   251,   252,   253,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     9,
      10,     0,    11,     0,     0,     0,    12,    13,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,     0,    32,    33,
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
     146,     0,     0,   147,   148,   149,     0,   150,   151,   152,
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
     249,   250,   251,     0,   604,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,   409,   410,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,   411,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,    48,    49,    50,    51,
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
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
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
     125,     0,     0,   126,   127,   128,     0,   807,     0,   129,
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
       0,    11,     0,     0,     0,   409,   410,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    1096,   411,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,  1097,  1098,    50,    51,    52,    53,
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
       0,     0,   126,   127,   128,     0,   807,     0,   129,     0,
     130,   131,     0,   132,   133,   134,     0,   135,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,   149,     0,   412,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,  1099,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,     0,   244,     0,   245,   246,   247,   248,   249,
     250,   251,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     9,    10,     0,
      11,     0,     0,     0,   409,   410,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,  1096,
     411,    28,    29,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,  1097,  1098,    50,    51,    52,    53,    54,
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
       0,   126,   127,   128,     0,   546,     0,   129,     0,   130,
     131,     0,   132,   133,   134,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,   149,     0,   412,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,  1099,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,     0,   244,     0,   245,   246,   247,   248,   249,   250,
     251,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
       0,     0,     0,   409,   410,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,   411,
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
       0,     0,    12,    13,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
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
     148,   149,     0,   150,   151,   152,   153,   154,   155,   156,
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
       0,    12,    13,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
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
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,     0,   244,
       0,   245,   246,   247,   248,   249,   250,   251,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     9,    10,     0,    11,     0,     0,     0,
      12,   410,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
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
       0,     0,     0,   129,     0,   130,   131,     0,   132,   133,
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
       7,     8,     9,    10,     0,    11,     0,     0,     0,   876,
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
       0,     0,   129,     0,   130,   131,     0,   132,   133,   134,
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
      23,    24,    25,  1096,   411,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,  1097,  1098,    50,
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
     144,   145,   146,     0,     0,   147,   148,   149,     0,   412,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,  1099,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
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
     124,   125,     0,     0,   126,   127,   128,     0,     0,   556,
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
     240,   241,   242,   243,     0,   244,     0,   245,   246,   247,
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
     125,     0,     0,   126,   127,   128,     0,     0,     0,   129,
     561,   130,   131,     0,   132,   133,   134,     0,   135,     0,
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
       0,     0,   126,   127,   128,     0,     0,     0,   129,     0,
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
     242,   243,   599,   244,     0,   245,   246,   247,   248,   249,
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
       0,   126,   127,   128,     0,     0,     0,   129,     0,   130,
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
     243,     0,   244,   601,   245,   246,   247,   248,   249,   250,
     251,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     0,     0,     0,    11,
       0,     0,     0,   409,   410,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   551,   411,
      28,    29,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,   552,   553,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,    73,     0,
      74,    75,    76,     0,     0,    77,    78,     0,     0,     0,
      79,    80,   502,    82,    83,    84,    85,    86,   554,    88,
      89,     0,     0,     0,    90,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,    96,    97,    98,    99,   100,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   555,   109,     0,   110,   111,   112,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,     0,   123,     0,   124,   125,     0,     0,
     126,   127,   128,     0,   920,     0,   129,     0,   130,   131,
       0,   132,   133,   134,     0,   135,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,   149,     0,   412,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   519,   520,   521,
     176,   177,   522,   557,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
       0,   244,     0,   245,   246,   247,   248,   249,   250,   251,
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
     127,   128,     0,     0,     0,   129,   926,   130,   131,     0,
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
      20,    21,    22,    23,    24,    25,   551,   411,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     552,   553,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     502,    82,    83,    84,    85,    86,   554,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   555,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,   930,   130,   131,     0,   132,
     133,   134,     0,   135,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
     149,     0,   412,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   519,   520,   521,   176,   177,
     522,   557,   180,   181,   182,   183,   184,   185,   186,   187,
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
      21,    22,    23,   488,    25,   490,   411,    28,   491,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,   493,     0,    45,    46,    47,   495,
     496,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,     0,    74,    75,    76,
       0,     0,    77,    78,     0,     0,     0,    79,    80,   502,
      82,    83,    84,    85,    86,   554,    88,    89,     0,     0,
       0,    90,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   505,    97,    98,    99,   100,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     555,   109,     0,   110,   111,   681,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
       0,   123,     0,   682,   125,     0,     0,   126,   127,   128,
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
       0,     0,   129,     0,   130,   131,     0,   132,   133,   134,
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
      23,   488,    25,   490,   411,    28,   491,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,   493,     0,    45,    46,    47,   495,   496,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,     0,    74,    75,    76,     0,     0,
      77,    78,     0,     0,     0,    79,    80,   502,    82,    83,
      84,    85,    86,   554,    88,    89,     0,     0,     0,    90,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     505,    97,    98,    99,   100,     0,     0,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   555,   109,
       0,   110,   111,   112,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,     0,   123,
       0,   124,   125,     0,     0,   126,   127,   128,     0,     0,
       0,   129,     0,   130,   131,     0,   132,   133,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
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
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   409,   410,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     488,    25,   490,   411,    28,   491,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,   493,     0,    45,    46,    47,   495,   496,    50,   497,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   502,    82,    83,    84,
      85,    86,   554,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   505,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   555,   109,     0,
     110,   111,     0,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
       0,     0,     0,     0,   126,   127,   128,     0,     0,     0,
     129,     0,   130,   131,     0,   132,   133,   134,     0,   135,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,   149,     0,   412,   151,
     152,   153,   154,   155,   156,   157,   158,   514,   160,   515,
     162,   516,   517,   165,   166,   167,   168,   169,   170,   518,
     172,   519,   520,   521,   176,   177,   522,   523,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,     0,   244,     0,   245,   524,   247,
     248,   249,   250,   251,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     0,
       0,     0,    11,     0,     0,     0,   409,   410,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,   488,
      25,   490,   411,    28,   491,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
     493,     0,    45,    46,    47,   495,   496,    50,   497,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,     0,    74,    75,    76,     0,     0,    77,    78,
       0,     0,     0,    79,    80,   502,    82,    83,    84,    85,
      86,   554,    88,    89,     0,     0,     0,    90,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   505,    97,
      98,    99,   100,     0,     0,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   555,   109,     0,   110,
     111,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,     0,   123,     0,     0,
       0,     0,     0,   126,   127,   128,     0,     0,     0,   129,
       0,   130,   131,     0,     0,     0,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   412,   151,   152,
     153,   154,   155,   156,   157,   158,   514,   160,   515,   162,
     516,   517,   165,   166,   167,   168,   169,   170,   518,   172,
     519,   520,   521,   176,   177,   522,   523,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,   244,     0,   245,   524,   247,   248,
     249,   250,   251,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   409,   410,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,   488,    25,
     490,   411,    28,   491,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,   493,
       0,    45,    46,    47,   495,   496,    50,   497,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   502,    82,    83,    84,    85,    86,
     554,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   505,     0,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,     0,   106,   107,   555,   109,     0,   110,   111,
       0,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,     0,     0,
       0,     0,   126,   127,   128,     0,     0,     0,   129,     0,
     130,   131,     0,     0,     0,   134,     0,   135,     0,   136,
       0,   138,     0,   140,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,   149,     0,   412,   151,   152,   153,
     154,   155,   156,   157,   158,   514,   160,   515,   162,   516,
     517,   165,   166,   167,   168,   169,   170,   518,   172,   519,
     520,   521,   176,   177,   522,   523,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,     0,   244,     0,   245,   524,   247,   248,   249,
     250,   251,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     0,     0,     0,     7,     8,     0,     0,     0,
       0,     0,     0,     0,   409,   410,     0,    14,    15,    16,
     485,    18,    19,    20,   486,    22,   487,   488,   489,   490,
     411,    28,   491,    30,    31,     0,    32,    33,    34,    35,
     492,    37,    38,    39,    40,    41,    42,    43,   493,     0,
      45,   494,    47,   495,   496,    50,   497,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   498,   499,    68,     0,    69,    70,    71,   500,     0,
       0,    74,    75,    76,     0,     0,   501,    78,     0,     0,
       0,     0,    80,   502,    82,   503,   504,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   505,    97,    98,   506,
     507,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,   107,     0,     0,     0,     0,     0,     0,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     508,   120,   121,   509,     0,     0,     0,     0,     0,     0,
       0,   510,   511,   128,     0,     0,     0,   129,     0,   130,
     512,     0,     0,     0,   134,     0,   135,     0,   136,   137,
     138,   139,   513,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,     0,     0,   412,   151,   152,   153,   154,
     155,   156,   157,   158,   514,   160,   515,   162,   516,   517,
     165,   166,   167,   168,   169,   170,   518,   172,   519,   520,
     521,   176,   177,   522,   523,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       0,     0,     1,     2,   245,   524,   247,   248,   249,   250,
     251,     3,     0,     0,     0,     7,     8,     0,     0,     0,
       0,     0,     0,     0,   409,   410,     0,    14,    15,    16,
     533,    18,    19,    20,   486,   534,   535,   488,   489,   490,
     411,    28,   491,    30,    31,     0,    32,    33,    34,    35,
     536,    37,   537,   538,    40,    41,    42,    43,   493,     0,
      45,   539,    47,   495,   496,    50,   497,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   498,   499,    68,     0,    69,    70,    71,   540,     0,
       0,    74,    75,    76,     0,     0,   501,    78,     0,     0,
       0,     0,    80,   502,    82,   503,   504,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   505,    97,    98,   506,
     507,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,   107,     0,     0,     0,     0,     0,     0,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     508,   120,   121,   509,     0,     0,     0,     0,     0,     0,
       0,   510,   511,   128,     0,     0,     0,   129,     0,   130,
     512,     0,     0,     0,   134,     0,   135,     0,   136,   137,
     138,   139,   513,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,     0,     0,   412,   151,   152,   153,   154,
     155,   156,   157,   158,   514,   541,   515,   162,   516,   517,
     165,   166,   167,   168,   169,   170,   518,   172,   519,   520,
     521,   176,   177,   522,   523,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       0,     0,     0,   566,   245,   524,   247,   248,   249,   250,
     251,     7,     8,     0,     0,     0,   782,     0,     0,     0,
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
       0,     0,     0,   129,   783,   130,   512,     0,     0,     0,
       0,     0,   135,     0,   136,   137,   138,   139,   513,   141,
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
     237,   238,   239,   240,   241,   242,     0,     0,     0,   566,
     245,   524,   247,   248,   249,   250,   251,     7,     8,     0,
       0,     0,     0,     0,     0,     0,   409,   410,     0,    14,
      15,    16,   533,    18,    19,    20,   486,   534,   535,   488,
     489,   490,   411,    28,   491,    30,    31,     0,    32,    33,
      34,    35,   536,    37,   537,   538,    40,    41,    42,    43,
     493,     0,    45,   539,    47,   495,   496,    50,   497,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   498,   499,    68,     0,    69,    70,    71,
     540,     0,     0,    74,    75,    76,     0,     0,   501,    78,
       0,     0,     0,     0,    80,   502,    82,   503,   504,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   505,    97,
      98,   506,   507,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,   107,     0,     0,     0,     0,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   508,   120,   121,   509,     0,     0,     0,     0,
       0,     0,     0,   510,   511,   128,     0,     0,     0,   129,
       0,   130,   512,     0,     0,     0,     0,     0,   135,     0,
     136,   137,   138,   139,   513,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,     0,     0,   412,   151,   152,
     153,   154,   155,   156,   157,   158,   514,   541,   515,   162,
     516,   517,   165,   166,   167,   168,   169,   170,   518,   172,
     519,   520,   521,   176,   177,   522,   523,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     0,     0,     0,     0,   245,   524,   247,   248,
     249,   250,   251,   569,   570,     0,     0,     0,     0,     7,
       8,     0,     0,     0,     0,     0,     0,     0,   409,   410,
       0,    14,    15,    16,   533,    18,    19,    20,   486,   534,
     535,   488,   489,   490,   411,    28,   491,    30,    31,     0,
      32,    33,    34,    35,   536,    37,   537,   538,    40,    41,
      42,    43,   493,     0,    45,   539,    47,   495,   496,    50,
     497,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,   498,   499,    68,     0,    69,
      70,    71,   540,     0,     0,    74,    75,    76,     0,     0,
     501,    78,     0,     0,     0,     0,    80,   502,    82,   503,
     504,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     505,    97,    98,   506,   507,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,   107,     0,     0,
       0,     0,     0,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   508,   120,   121,   509,     0,     0,
       0,     0,     0,     0,     0,   510,   511,   128,     0,     0,
       0,   129,     0,   130,   512,     0,     0,     0,     0,     0,
     135,     0,   136,   137,   138,   139,   513,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,     0,     0,   412,
     151,   152,   153,   154,   155,   156,   157,   158,   514,   541,
     515,   162,   516,   517,   165,   166,   167,   168,   169,   170,
     518,   172,   519,   520,   521,   176,   177,   522,   523,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,     0,     0,     0,     0,   245,   524,
     247,   248,   249,   250,   251,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   409,   410,     0,
      14,    15,    16,   832,    18,    19,    20,    21,   534,   833,
     488,    25,   490,   411,    28,   491,    30,    31,     0,    32,
      33,    34,    35,   834,    37,   537,   538,    40,    41,    42,
      43,   493,     0,    45,   835,    47,   495,   496,    50,   497,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,   498,   499,    68,     0,    69,    70,
      71,   836,     0,     0,    74,    75,    76,     0,     0,   501,
      78,     0,     0,     0,    79,    80,   502,    82,   503,   504,
      85,    86,   554,    88,     0,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   505,
      97,    98,   506,   507,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   555,   109,     0,
     110,   111,     0,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   509,     0,   123,     0,
       0,     0,     0,     0,   510,   511,   128,     0,     0,     0,
     129,     0,   130,   512,     0,     0,     0,     0,     0,   135,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,   149,     0,   412,   151,
     152,   153,   154,   155,   156,   157,   158,   514,   541,   515,
     162,   516,   517,   165,   166,   167,   168,   169,   170,   518,
     172,   519,   520,   521,   176,   177,   522,   523,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,     0,   244,     0,   245,   524,   247,
     248,   249,   250,   251,     7,     8,     0,     0,     0,     0,
       0,     0,     0,   409,   410,     0,    14,    15,    16,   485,
      18,    19,    20,   486,    22,   487,   488,  1139,   490,   411,
      28,   491,    30,    31,     0,    32,    33,    34,    35,   492,
      37,    38,    39,    40,    41,    42,    43,   493,     0,    45,
     494,    47,   495,   496,    50,   497,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     498,   499,    68,     0,    69,    70,    71,   500,     0,     0,
      74,    75,    76,     0,     0,   501,    78,     0,     0,     0,
       0,    80,   502,    82,   503,   504,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   505,    97,    98,   506,   507,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
     105,   106,  1140,     0,     0,     0,  1141,     0,     0,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   508,
     120,   121,   509,     0,     0,     0,     0,     0,     0,     0,
     510,   511,   128,     0,     0,     0,   129,  1568,   130,   512,
       0,     0,     0,  1569,     0,   135,     0,   136,   137,   138,
     139,   513,   141,   142,   143,   144,   145,   146,     0,     0,
    1142,   148,     0,     0,   412,   151,   152,   153,   154,   155,
     156,   157,   158,   514,   160,   515,   162,   516,   517,   165,
     166,   167,   168,   169,   170,   518,   172,   519,   520,   521,
     176,   177,   522,   523,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     7,     8,   245,   524,   247,  1143,  1144,  1145,  1146,
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
       0,     0,     0,   129,   752,   130,   512,     0,     0,     0,
     753,     0,   135,     0,   136,   137,   138,   139,   513,   141,
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
     129,   800,   130,   512,     0,     0,     0,   801,     0,   135,
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
     240,   241,   242,     0,     0,     7,     8,   245,   524,   247,
     248,   249,   250,   251,   409,   410,     0,    14,    15,    16,
     485,    18,    19,    20,   486,    22,   487,   488,  1139,   490,
     411,    28,   491,    30,    31,     0,    32,    33,    34,    35,
     492,    37,    38,    39,    40,    41,    42,    43,   493,     0,
      45,   494,    47,   495,   496,    50,   497,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   498,   499,    68,     0,    69,    70,    71,   500,     0,
       0,    74,    75,    76,     0,     0,   501,    78,     0,     0,
       0,     0,    80,   502,    82,   503,   504,    85,    86,  1485,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   505,    97,    98,   506,
     507,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,  1140,     0,     0,     0,  1141,     0,     0,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     508,   120,   121,   509,     0,     0,     0,     0,     0,     0,
       0,   510,   511,   128,     0,     0,     0,   129,     0,   130,
     512,     0,     0,     0,     0,     0,   135,     0,   136,   137,
     138,   139,   513,   141,   142,   143,   144,   145,   146,     0,
       0,  1142,   148,     0,     0,   412,   151,   152,   153,   154,
     155,   156,   157,   158,   514,   160,   515,   162,   516,   517,
     165,   166,   167,   168,   169,   170,   518,   172,   519,   520,
     521,   176,   177,   522,   523,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       0,     0,     7,     8,   245,   524,   247,  1143,  1144,  1145,
    1146,   409,   410,     0,    14,    15,    16,   485,    18,    19,
      20,   486,    22,   487,   488,  1139,   490,   411,    28,   491,
      30,    31,     0,    32,    33,    34,    35,   492,    37,    38,
      39,    40,    41,    42,    43,   493,     0,    45,   494,    47,
     495,   496,    50,   497,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,   498,   499,
      68,     0,    69,    70,    71,   500,     0,     0,    74,    75,
      76,     0,     0,   501,    78,     0,     0,     0,     0,    80,
     502,    82,   503,   504,    85,    86,  1625,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   505,    97,    98,   506,   507,     0,     0,
       0,     0,     0,     0,   101,   102,   103,     0,   105,   106,
    1140,     0,     0,     0,  1141,     0,     0,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   508,   120,   121,
     509,     0,     0,     0,     0,     0,     0,     0,   510,   511,
     128,     0,     0,     0,   129,     0,   130,   512,     0,     0,
       0,     0,     0,   135,     0,   136,   137,   138,   139,   513,
     141,   142,   143,   144,   145,   146,     0,     0,  1142,   148,
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
       8,   245,   524,   247,  1143,  1144,  1145,  1146,   409,   410,
       0,    14,    15,    16,   485,    18,    19,    20,   486,    22,
     487,   488,  1139,   490,   411,    28,   491,    30,    31,     0,
      32,    33,    34,    35,   492,    37,    38,    39,    40,    41,
      42,    43,   493,     0,    45,   494,    47,   495,   496,    50,
     497,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,   498,   499,    68,     0,    69,
      70,    71,   500,     0,     0,    74,    75,    76,     0,     0,
     501,    78,     0,     0,     0,     0,    80,   502,    82,   503,
     504,    85,    86,  1629,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     505,    97,    98,   506,   507,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,  1140,     0,     0,
       0,  1141,     0,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   508,   120,   121,   509,     0,     0,
       0,     0,     0,     0,     0,   510,   511,   128,     0,     0,
       0,   129,     0,   130,   512,     0,     0,     0,     0,     0,
     135,     0,   136,   137,   138,   139,   513,   141,   142,   143,
     144,   145,   146,     0,     0,  1142,   148,     0,     0,   412,
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
     247,  1143,  1144,  1145,  1146,   409,   410,     0,    14,    15,
      16,   485,    18,    19,    20,   486,    22,   487,   488,  1139,
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
     103,     0,   105,   106,  1140,     0,     0,     0,  1141,     0,
       0,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   508,   120,   121,   509,     0,     0,     0,     0,     0,
       0,     0,   510,   511,   128,     0,     0,     0,   129,     0,
     130,   512,     0,     0,     0,     0,     0,   135,     0,   136,
     137,   138,   139,   513,   141,   142,   143,   144,   145,   146,
       0,     0,  1142,   148,     0,     0,   412,   151,   152,   153,
     154,   155,   156,   157,   158,   514,   160,   515,   162,   516,
     517,   165,   166,   167,   168,   169,   170,   518,   172,   519,
     520,   521,   176,   177,   522,   523,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     0,     0,     7,     8,   245,   524,   247,  1143,  1144,
    1145,  1146,   409,   410,     0,    14,    15,    16,   485,    18,
      19,    20,   486,    22,   487,   488,  1139,   490,   411,    28,
     491,    30,    31,     0,    32,    33,    34,    35,   492,    37,
      38,    39,    40,    41,    42,    43,   493,     0,    45,   494,
      47,   495,   496,    50,   497,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   498,
     499,    68,     0,    69,    70,    71,   500,     0,     0,    74,
      75,    76,     0,     0,   501,    78,     0,     0,     0,     0,
      80,   502,    82,   503,   504,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   505,    97,    98,   506,   507,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,  1140,     0,     0,     0,  1141,     0,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   508,   120,
     121,   509,     0,     0,     0,     0,     0,     0,     0,   510,
     511,   128,     0,     0,     0,   129,     0,   130,   512,     0,
       0,     0,     0,     0,   135,     0,   136,   137,   138,   139,
     513,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,     0,     0,   412,   151,   152,   153,   154,   155,   156,
     157,   158,   514,   160,   515,   162,   516,   517,   165,   166,
     167,   168,   169,   170,   518,   172,   519,   520,   521,   176,
     177,   522,   523,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     0,     0,
       7,     8,   245,   524,   247,  1143,  1144,  1145,  1146,   409,
     410,     0,    14,    15,    16,   533,    18,    19,    20,   486,
     534,   535,   488,   489,   490,   411,    28,   491,    30,    31,
       0,    32,    33,    34,    35,   536,    37,   537,   538,    40,
      41,    42,    43,   493,     0,    45,   539,    47,   495,   496,
      50,   497,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   498,   499,    68,     0,
      69,    70,    71,   540,     0,     0,    74,    75,    76,     0,
       0,   501,    78,     0,     0,     0,     0,    80,   502,    82,
     503,   504,    85,    86,  1232,     0,     0,     0,     0,     0,
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
      15,    16,   533,    18,    19,    20,   486,   534,   535,   488,
     489,   490,   411,    28,   491,    30,    31,     0,    32,    33,
      34,    35,   536,    37,   537,   538,    40,    41,    42,    43,
     493,     0,    45,   539,    47,   495,   496,    50,   497,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   498,   499,    68,     0,    69,    70,    71,
     540,     0,     0,    74,    75,    76,     0,     0,   501,    78,
       0,     0,     0,     0,    80,   502,    82,   503,   504,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   505,    97,
      98,   506,   507,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,   107,     0,     0,     0,     0,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   508,   120,   121,   509,     0,     0,     0,     0,
       0,     0,     0,   510,   511,   128,     0,     0,     0,   129,
       0,   130,   512,     0,     0,     0,     0,     0,   135,     0,
     136,   137,   138,   139,   513,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,     0,     0,   412,   151,   152,
     153,   154,   155,   156,   157,   158,   514,   541,   515,   162,
     516,   517,   165,   166,   167,   168,   169,   170,   518,   172,
     519,   520,   521,   176,   177,   522,   523,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     0,     0,     7,     8,   245,   524,   247,   248,
     249,   250,   251,   409,   410,     0,    14,    15,    16,     0,
      18,    19,    20,   486,     0,     0,   488,   489,     0,   411,
      28,   491,    30,    31,     0,    32,    33,    34,    35,     0,
      37,     0,     0,    40,    41,    42,    43,   493,     0,    45,
       0,    47,     0,     0,    50,   497,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     498,   499,    68,     0,    69,    70,    71,     0,     0,     0,
      74,    75,    76,     0,     0,   501,    78,     0,     0,     0,
       0,    80,   502,    82,   503,   504,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   505,    97,    98,   506,   507,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
     105,   106,     0,     0,     0,     0,     0,     0,     0,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   508,
     120,   121,   509,     0,     0,     0,     0,     0,     0,     0,
     510,   511,   128,     0,     0,     0,   129,     0,   130,   512,
       0,     0,     0,     0,     0,   135,     0,   136,   137,   138,
     139,   513,   141,   142,   143,   144,   145,   146,     0,     0,
       0,   148,     0,     0,   412,   151,   152,   153,   154,   155,
     156,   157,   158,   514,     0,   515,   162,   516,   517,   165,
     166,   167,   168,   169,   170,   518,   172,   519,   520,   521,
     176,   177,     0,   523,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     0,     0,   245,   524,   247,   248,   249,   250,   251
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,   179,    12,  1030,     4,     5,     6,   339,     0,   418,
     419,   668,     4,     5,     6,   669,   670,   671,   672,   109,
     110,   777,   820,   260,   311,     4,     5,     6,     4,     5,
       6,   582,   420,   789,   617,   618,   133,   588,   275,   757,
     259,     4,     5,     6,   903,  1046,   858,   803,   615,   616,
     617,   618,   757,  1218,  1285,  1302,  1070,   252,   253,   432,
       1,     1,  1363,  1364,    73,   615,   616,  1125,    36,   937,
     443,   917,   460,   461,   291,   987,    36,    26,    27,  1590,
     282,   916,   917,  1005,     1,    55,  1396,   647,     8,   649,
     650,   713,   652,     1,   654,   468,     1,     1,    47,    29,
     118,     1,   662,   663,    39,  1315,     1,     1,   108,    44,
      45,     1,     1,     1,    30,   953,   108,    29,   953,    93,
     107,   224,   224,   226,    59,    74,    61,    62,    96,     0,
       1,    52,   108,   147,    94,    70,    96,   118,   107,    37,
      38,   224,    40,    41,    94,   108,   229,    94,     1,   107,
     107,   153,   987,   243,   244,  1657,    26,    27,   136,    57,
      24,  1007,    97,   112,   118,     1,   107,   107,     1,   153,
      34,   148,  1007,    33,  1020,   158,   267,    96,   160,   147,
     110,     1,    45,   274,   231,  1020,   233,   147,   165,    49,
     107,    26,    27,   176,   124,   142,    60,   147,   415,    62,
     187,   291,   107,   959,   147,   186,   224,   209,   129,   183,
     313,   313,    47,     1,     1,   113,     1,   156,   107,   149,
       1,    56,   200,   153,     1,   209,   156,  1729,  1739,  1530,
     313,   188,   190,     0,     1,    96,   107,   439,     1,    74,
       1,  1268,   112,     1,    79,   342,   216,   177,   160,     1,
     169,     1,   252,   253,   107,   175,   256,  1013,   272,     1,
     252,   253,   160,  1019,   256,   234,  1125,  1126,  1066,  1500,
     187,   107,  1437,   560,   107,    96,   111,   112,   113,  1589,
     185,  1282,   190,   253,   867,   868,   190,   107,   306,   224,
     190,   291,  1306,  1503,  1012,   190,   190,   213,   187,   291,
     190,  1315,   190,  1141,   272,  1010,  1141,  1012,  1176,    73,
    1232,  1223,   272,   184,  1372,   865,   866,   939,   272,   107,
     107,   219,   107,    87,   187,   415,   107,  1032,   258,   272,
     107,   548,   251,   252,   187,   254,   724,   286,   347,   899,
     107,   350,   261,    76,   107,   294,   107,   111,   169,   107,
     130,   187,   271,    29,   187,   107,   107,   107,   448,   123,
     142,   125,   260,     1,   283,   107,   216,   187,   458,     1,
     310,   312,   224,    29,   226,   612,   613,   467,     1,    94,
     107,   316,   317,   318,   474,   475,   107,   775,  1223,  1690,
     100,     1,   100,   483,   255,   256,   615,   616,   771,   187,
     187,   774,   187,   253,  1651,     1,   187,   100,   106,   604,
     187,   107,    94,     1,  1260,   415,   196,   184,   635,     1,
     153,   169,   185,   415,   185,  1260,   184,  1592,   107,   127,
     251,   252,   184,   254,   110,   185,   156,   188,  1284,     5,
     131,  1742,   184,     9,   444,     1,   446,     3,   124,  1284,
     271,   286,   444,   201,   446,   107,   118,   113,   548,   294,
     187,   313,   283,   184,   153,   130,  1222,   302,   444,   107,
     446,   107,   472,   149,   564,   107,   186,   477,   186,   182,
     472,   444,   156,   446,   107,   477,   576,   220,   221,  1503,
     272,   187,   195,   186,   903,  1726,   472,   107,   107,   190,
     107,   477,   217,   218,   160,   156,   596,   597,   187,   472,
      66,   107,   118,  1372,   477,    71,  1234,   232,    54,   107,
      56,   107,  1381,   932,   186,   107,   743,  1110,  1111,  1112,
    1695,   196,   184,  1392,  1346,   217,   218,  1349,  1243,  1090,
     154,   156,   156,  1110,  1111,  1112,   184,    96,   548,   107,
     232,   187,   184,     9,    10,   555,   548,   123,  1404,   125,
     107,   184,   118,   555,   100,   107,    45,   133,    47,  1404,
      94,    96,   960,   961,   184,  1740,    96,   965,   187,   555,
     187,   187,   154,   347,   156,  1612,   350,   153,   184,    94,
     687,   688,   555,   113,   684,   136,   184,   597,   147,   689,
     610,   187,   184,   148,   604,   597,    96,   995,    94,   150,
     200,  1367,   604,   156,     9,   615,   616,   617,   618,   209,
     165,   597,   236,   615,   616,   617,   618,   106,   156,   187,
     154,   156,   156,    28,   871,   635,   156,   874,   118,   856,
     187,  1487,   147,   635,  1490,   187,   865,   103,  1813,  1650,
    1815,   137,  1487,   743,     5,  1490,   142,   147,     9,  1824,
     158,   425,    26,    27,   428,   122,   166,   123,   432,   125,
      53,   435,   436,    37,    38,    58,    40,    41,   176,   443,
     156,    73,   182,    47,   158,   449,   450,   153,    94,   168,
     454,   156,    56,    57,    77,    87,   153,   153,   462,   156,
    1559,   157,   176,  1501,   468,   469,   470,   471,  1506,   122,
      74,   177,   476,    96,   250,    79,  1125,  1126,   174,   111,
     484,   811,   812,   813,   198,   815,  1383,   263,   123,   265,
     125,   123,   144,   125,  1452,   118,   142,   153,   194,   134,
     276,   277,   278,   743,   280,   122,   282,   111,   112,   113,
     137,   743,    29,   843,    96,   122,   212,    53,   153,    42,
      33,   177,    58,    46,   176,   529,   153,   767,    51,  1352,
     268,   113,   123,   863,   125,   767,    49,   275,   117,   543,
     118,   193,   133,     9,    10,    42,    69,   285,   767,    46,
     554,   767,     9,    10,    51,  1127,   160,   797,   798,    96,
      96,    94,   153,   137,   767,   797,   798,   146,   158,  1001,
     182,  1003,    69,   106,  1101,   122,   113,   122,   582,   153,
     159,   797,   798,   195,   588,     9,   176,  1673,   592,  1675,
     298,   137,   118,   110,   797,   798,   142,  1635,  1673,   307,
    1675,  1639,   246,   247,    28,   268,   122,   124,   198,   142,
       9,    10,   275,   122,   193,   219,   856,  1717,  1718,   156,
    1706,  1053,   285,  1055,   856,   269,   876,   100,   153,   100,
    1107,  1706,   149,   262,   122,  1263,   153,   103,  1095,   156,
     113,    95,   113,    94,   273,   168,   103,   619,   171,  1543,
    1736,   623,   106,  1550,  1551,   106,   260,   123,  1758,   125,
     177,  1736,   116,   186,  1764,  1751,   123,  1753,   125,   191,
     192,   168,   100,   127,   171,    45,  1751,    47,  1753,   100,
     100,  1099,   286,  1721,   100,   113,  1104,   153,   211,   186,
     294,   157,   113,   113,  1690,   950,   153,   113,   302,   123,
     157,   125,   262,   231,   103,   233,   137,   962,   174,    79,
     134,   142,   122,   273,   211,   347,   720,   174,   350,   276,
     277,   278,    53,  1372,   123,   282,   125,    58,   194,   153,
     734,  1359,  1381,   122,   738,   739,   106,   194,   690,   153,
     122,   693,   156,  1392,   696,   153,   212,   153,   156,   153,
     156,   153,   156,   346,   153,   212,   349,   761,   157,   763,
     220,   221,   222,   215,  1661,  1662,   156,   771,   153,   154,
     774,   118,    42,   240,   778,   174,    46,   128,   129,   128,
     129,    51,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,   424,   425,  1124,   194,   428,   240,   168,    69,
     432,   666,   667,   435,   436,  1262,   673,   674,  1048,   675,
     676,   443,   241,   212,   156,   819,  1048,   449,   450,  1216,
    1217,   153,   454,   918,   919,  1580,  1581,   313,     0,   190,
     462,   167,  1048,    92,    99,  1732,   468,   469,   470,   471,
      50,  1469,   199,   248,   476,  1048,   101,   154,   102,   145,
     156,   184,   484,    29,   858,  1095,   184,   184,    47,  1109,
     152,   118,   245,  1095,   303,   187,   283,   118,   283,   153,
    1110,  1111,  1112,     1,   118,   142,   107,   187,  1110,  1111,
    1112,   153,   886,   156,   153,   156,   142,   184,  1345,   121,
     156,    35,   156,   156,   156,   156,   156,   529,   168,    17,
     153,   171,   213,    29,   187,   230,  1534,   244,   229,   132,
    1559,   543,   916,   917,   918,   919,   186,   140,   141,   154,
     143,     3,   554,   118,   170,   168,   230,    70,   151,   170,
      94,    94,   155,    94,   157,   149,   107,   107,   190,   162,
     190,   211,    29,   160,   160,   127,   132,    94,   298,   953,
     245,   142,   118,   132,   184,   184,   179,   107,    94,   187,
     592,   187,    96,   967,    45,    96,   187,   187,   187,   187,
     153,   184,   184,   153,    94,   153,   153,   224,   153,   202,
     203,   204,   205,   206,   207,   153,  1226,   236,   992,   142,
     230,   190,    33,     1,  1226,   118,   170,  1001,    94,  1003,
     132,  1005,   142,  1007,    29,   285,    94,  1226,   298,   118,
    1226,  1341,  1342,  1343,   153,   226,  1020,   127,   147,   253,
     118,    94,  1262,  1226,  1481,   184,   132,   160,   197,   132,
    1262,    96,   153,  1273,   118,   147,   100,   100,   184,   184,
     153,  1273,   142,   121,    35,    29,   118,   244,   190,  1053,
      79,  1055,  1292,   107,  1273,   156,   107,  1273,   259,   156,
    1292,   156,   153,   257,   266,    29,   156,   156,   144,   284,
    1273,   156,  1312,  1292,    29,    29,  1292,   156,   285,   156,
    1312,   156,   156,   286,   144,   717,  1090,   127,   720,  1292,
     147,   226,   147,   187,   187,   147,  1312,   305,   190,   118,
     118,   187,   734,    77,  1344,  1345,   738,   739,   107,  1312,
     142,   100,  1344,  1345,   197,   184,  1120,   187,   132,   187,
     187,     7,   236,   106,   190,   232,   187,   232,  1344,   761,
     232,   763,   249,   232,   249,   147,   186,  1141,    78,   771,
     198,   187,   774,   281,   285,   187,   778,    29,   187,   187,
     187,   187,   232,  1610,   187,    29,   107,   170,   184,   270,
     147,   232,   147,   126,  1621,  1622,   126,  1624,    96,   184,
     186,   142,   153,    94,  1631,   186,   186,   186,   184,   184,
     184,    29,    96,    53,   187,   187,   147,   819,   170,    94,
     186,   186,    96,   106,   256,   196,    94,   197,    29,   107,
     107,   118,   224,   118,    94,    94,   186,   315,   196,   118,
     196,   264,    93,   186,   186,   183,   118,   224,   196,   118,
     279,   186,   198,   118,   186,   256,   858,   186,  1232,   256,
     286,   224,  1236,   723,  1179,   259,   954,  1021,   419,   439,
    1223,  1481,  1695,  1740,   292,   859,   108,  1251,  1018,  1481,
     454,   286,  1252,   780,   886,   304,  1260,  1714,   305,   304,
     304,  1462,   305,  1368,  1116,  1363,   543,  1366,  1725,  1274,
    1274,   305,  1282,  1279,  1287,   646,   645,   665,   820,   698,
    1284,  1764,  1306,  1758,   916,   917,   918,   919,   919,   447,
     447,  1003,  1178,  1337,  1347,  1752,  1346,  1381,  1392,  1559,
    1385,  1126,  1135,  1556,   986,   335,  1201,  1427,  1583,  1313,
    1382,   842,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   953,  1652,    -1,    -1,    -1,    -1,    -1,  1785,    -1,
      -1,    -1,    -1,  1337,    -1,   967,    -1,    -1,    -1,    -1,
      -1,  1671,  1346,    -1,    -1,  1349,    -1,    -1,    -1,    -1,
    1807,    -1,    -1,    -1,    -1,  1812,    -1,    -1,    -1,    -1,
     992,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1001,
    1610,  1003,    -1,  1005,    -1,  1007,    -1,    -1,  1610,    -1,
      -1,  1621,  1622,    -1,  1624,    -1,    -1,    -1,  1020,  1621,
    1622,  1631,  1624,    -1,    -1,    -1,    -1,    -1,    -1,  1631,
    1404,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1053,    -1,  1055,    -1,    -1,    -1,    -1,    -1,  1433,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1459,  1460,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1714,    -1,    -1,    -1,    -1,    -1,
      -1,  1485,  1714,  1487,    -1,  1725,  1490,    -1,  1120,    -1,
      -1,    -1,    -1,  1725,    -1,    -1,    -1,    -1,  1502,    -1,
      -1,    -1,    -1,  1507,    -1,    -1,    -1,    -1,    -1,  1141,
      -1,    -1,  1752,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1752,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1785,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1785,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1807,    -1,    -1,
      -1,    -1,  1812,    -1,    -1,  1807,    -1,    -1,    -1,    -1,
    1812,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1232,    -1,    -1,    -1,  1236,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1251,
      -1,  1625,    -1,  1627,    -1,  1629,    -1,    -1,  1260,    -1,
      -1,    -1,  1636,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1274,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1284,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1673,
      -1,  1675,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1313,    -1,    -1,    -1,    -1,    -1,  1691,    -1,    -1,
    1694,    -1,    -1,   555,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1706,    -1,    -1,  1337,    -1,    -1,    -1,    -1,
      -1,    -1,  1716,    -1,  1346,    -1,    -1,  1349,   580,   581,
      -1,    -1,   584,   585,    -1,   587,    -1,   589,    -1,    -1,
      -1,    -1,  1736,   595,    -1,    -1,    -1,    -1,    -1,    -1,
    1744,    -1,    -1,    -1,    -1,  1749,    -1,  1751,    -1,  1753,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   625,   626,   627,    -1,    -1,    -1,    -1,
      -1,    -1,  1404,   635,   636,    -1,    -1,    -1,  1782,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1799,    -1,    -1,    -1,  1803,
      -1,  1433,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1819,    -1,    -1,  1822,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1459,  1460,    -1,
      -1,    -1,    -1,   695,    -1,    -1,   698,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1485,    -1,  1487,    -1,    -1,  1490,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1502,    -1,    -1,    -1,   736,  1507,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   779,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   804,    -1,    -1,    -1,   808,   809,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   817,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     842,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1625,    -1,  1627,    -1,  1629,    -1,    -1,
      -1,    -1,    -1,    -1,  1636,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   888,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1673,    -1,  1675,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1691,
      -1,    -1,  1694,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1706,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1716,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   955,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1736,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1744,    -1,    -1,    -1,    -1,  1749,    -1,  1751,
      -1,  1753,    -1,    -1,    -1,    -1,    -1,    -1,   990,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1009,    -1,    -1,
    1782,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1799,    -1,  1031,
      -1,  1803,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1042,  1043,    -1,    -1,    -1,    -1,    -1,  1819,    -1,    -1,
    1822,    -1,    -1,    -1,    -1,  1057,    -1,    -1,  1060,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1076,  1077,  1078,    -1,  1080,  1081,
    1082,    -1,    -1,    -1,  1086,  1087,  1088,  1089,    -1,    -1,
    1092,  1093,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1166,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     0,     1,    -1,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1238,    -1,  1240,    -1,
    1242,    -1,    -1,  1245,    -1,    -1,    -1,    -1,  1250,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    46,    -1,    -1,
    1262,    50,    51,    -1,    -1,    -1,    55,    -1,    -1,  1271,
      -1,    -1,    -1,    -1,    -1,  1277,  1278,    66,    -1,    -1,
      69,    -1,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1296,    -1,    -1,  1299,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    94,    95,    96,    -1,    -1,
      99,   100,   101,   102,    -1,    -1,    -1,   106,   107,    -1,
      -1,    -1,    -1,    -1,   113,    -1,    -1,   116,   117,   118,
      -1,    -1,   121,    -1,    -1,    -1,    -1,   126,   127,    -1,
      -1,    -1,    -1,   132,    -1,    -1,    -1,   136,    -1,    -1,
      -1,   140,   141,    -1,   143,    -1,   145,   146,    -1,    -1,
      -1,   150,   151,    -1,  1366,   154,   155,   156,   157,   158,
     159,    -1,    -1,   162,    -1,    -1,    -1,    -1,   167,   168,
      -1,    -1,   171,    -1,    -1,    -1,    -1,   176,    -1,    -1,
     179,    -1,    -1,    -1,    -1,   184,   185,   186,   187,   188,
      -1,   190,   191,   192,   193,    -1,    -1,    -1,    -1,   198,
     199,   200,    -1,   202,   203,   204,   205,   206,   207,    -1,
     209,    -1,   211,    -1,    -1,    -1,    -1,   216,   217,   218,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   232,  1446,   234,    -1,   236,  1450,    -1,
      -1,    -1,  1454,    -1,  1456,    -1,  1458,    -1,    -1,   248,
      -1,    -1,  1464,    -1,   253,    -1,    -1,    -1,    -1,    -1,
    1472,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1480,  1481,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1499,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1510,  1511,
    1512,  1513,  1514,  1515,  1516,  1517,    -1,  1519,    -1,    -1,
      -1,   310,    -1,   312,  1526,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1535,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1598,    -1,  1600,    -1,
      -1,  1603,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1611,
      -1,    -1,    -1,    -1,  1616,  1617,    -1,    -1,    -1,    -1,
      -1,    -1,  1624,    -1,    -1,    -1,  1628,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1658,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1698,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1710,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1752,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1770,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,  1780,    -1,
      -1,    -1,    -1,  1785,    11,    12,    -1,    -1,  1790,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    29,    -1,  1806,    -1,    33,    34,  1810,    36,
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
     318,   319,   320,   321,    11,    12,    -1,    -1,    -1,    -1,
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
     317,   318,   319,    -1,   321,    11,    12,    -1,    -1,    -1,
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
      -1,    -1,   180,   181,   182,    -1,   184,    -1,   186,    -1,
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
      -1,   180,   181,   182,    -1,   184,    -1,   186,    -1,   188,
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
     176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,   185,
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
     177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
     187,   188,   189,    -1,   191,   192,   193,    -1,   195,    -1,
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
     308,   309,   310,   311,    -1,   313,   314,   315,   316,   317,
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
     309,    -1,   311,   312,   313,   314,   315,   316,   317,   318,
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
     180,   181,   182,    -1,   184,    -1,   186,    -1,   188,   189,
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
     181,   182,    -1,    -1,    -1,   186,   187,   188,   189,    -1,
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
     182,    -1,    -1,    -1,   186,   187,   188,   189,    -1,   191,
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
     305,   306,   307,   308,   309,    -1,   311,    -1,   313,   314,
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
     156,   157,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
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
     157,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,   174,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
      -1,   188,   189,    -1,    -1,    -1,   193,    -1,   195,    -1,
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
     128,   129,    -1,   131,    -1,    -1,    -1,   135,    -1,   137,
     138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,
     148,   149,    -1,   151,   152,   153,   154,    -1,   156,   157,
      -1,   159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,   174,    -1,    -1,    -1,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,
     188,   189,    -1,    -1,    -1,   193,    -1,   195,    -1,   197,
      -1,   199,    -1,   201,   202,   203,   204,   205,   206,   207,
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
      -1,    20,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    -1,
      -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,
     139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,
      -1,   150,   151,   152,    -1,    -1,    -1,    -1,    -1,    -1,
     159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,
     189,    -1,    -1,    -1,   193,    -1,   195,    -1,   197,   198,
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
      -1,    -1,    11,    12,   313,   314,   315,   316,   317,   318,
     319,    20,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    -1,
      -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,
     139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,
      -1,   150,   151,   152,    -1,    -1,    -1,    -1,    -1,    -1,
     159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,
     189,    -1,    -1,    -1,   193,    -1,   195,    -1,   197,   198,
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
      -1,    -1,    -1,    16,   313,   314,   315,   316,   317,   318,
     319,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
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
      -1,    -1,   195,    -1,   197,   198,   199,   200,   201,   202,
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
     303,   304,   305,   306,   307,   308,    -1,    -1,    -1,    16,
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
     147,   148,    -1,   150,   151,   152,    -1,    -1,    -1,    -1,
      -1,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
      -1,   188,   189,    -1,    -1,    -1,    -1,    -1,   195,    -1,
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
     307,   308,    -1,    -1,    -1,    -1,   313,   314,   315,   316,
     317,   318,   319,    18,    19,    -1,    -1,    -1,    -1,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,
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
      -1,    -1,    -1,    -1,   159,   160,    -1,    -1,    -1,    -1,
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
     305,   306,   307,   308,    -1,    -1,    -1,    -1,   313,   314,
     315,   316,   317,   318,   319,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    -1,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,    -1,   124,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,   195,
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
     316,   317,   318,   319,    24,    25,    -1,    -1,    -1,    -1,
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
     150,   151,   152,    -1,    -1,    -1,   156,    -1,    -1,   159,
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
     116,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,    -1,   150,   151,   152,    -1,    -1,    -1,
      -1,    -1,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,   187,   188,   189,    -1,    -1,    -1,   193,    -1,   195,
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
     115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,
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
     111,   112,   113,   114,   115,   116,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,    -1,
     131,    -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,    -1,   150,
     151,   152,    -1,    -1,    -1,   156,    -1,    -1,   159,   160,
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
     114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,
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
     147,   148,    -1,   150,   151,   152,    -1,    -1,    -1,    -1,
      -1,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
      -1,   188,   189,    -1,    -1,    -1,    -1,    -1,   195,    -1,
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
     317,   318,   319,    33,    34,    -1,    36,    37,    38,    -1,
      40,    41,    42,    43,    -1,    -1,    46,    47,    -1,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    -1,
      60,    -1,    -1,    63,    64,    65,    66,    67,    -1,    69,
      -1,    71,    -1,    -1,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    -1,    -1,    -1,
     100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,
      -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,   139,
      -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,    -1,
     150,   151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,
     160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,
      -1,    -1,    -1,    -1,    -1,   195,    -1,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,    -1,    -1,
      -1,   211,    -1,    -1,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,    -1,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,    -1,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,   258,   259,
     260,    -1,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,    -1,
      -1,    -1,    -1,   313,   314,   315,   316,   317,   318,   319
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
     372,   392,   410,   107,   190,     1,   107,   334,   190,    42,
      46,    51,    69,   168,   171,   186,   211,   405,   414,   419,
     420,   421,   435,   436,   440,   167,    92,   132,   140,   141,
     143,   151,   155,   157,   162,   179,   202,   203,   204,   205,
     206,   207,   483,   484,   248,    99,   158,   176,   198,   117,
     146,   159,   193,   200,   209,   136,   150,    50,   199,   101,
     102,   158,   176,   482,   153,   488,   491,   191,   192,   154,
     503,   504,   499,   503,   499,   156,   503,   145,   156,   184,
     184,   184,   373,   506,   373,    29,   648,   182,   195,   182,
     195,   166,   182,   651,   650,   169,   201,    47,   650,   152,
     118,    45,    47,    79,   106,   168,   649,   220,   221,   222,
     245,   607,   650,   650,   303,   137,   142,   112,   286,   294,
     375,   649,   390,   391,   187,   390,    45,    62,   187,   556,
     557,   410,   187,   193,   650,   424,   425,   650,   283,   283,
     424,   118,   431,   118,   187,   379,   380,   153,   395,   410,
       1,   160,   648,   113,   160,   353,   648,   650,   118,   142,
     107,   410,    29,   187,   649,   650,   650,   448,   449,   650,
     390,   187,   410,   410,   558,   650,   390,   153,   153,   410,
     187,   193,   650,   650,   142,   448,   184,   184,   121,   107,
     184,   156,   156,   156,   650,   153,   185,   186,   187,    35,
     519,   520,   521,   410,     8,   175,    17,   410,   213,    29,
     411,   411,    39,    45,    59,    70,    97,   502,   650,   187,
     411,   411,   153,   154,   411,   502,   411,   230,   229,   574,
     575,   650,   190,   190,   411,   410,   391,   410,   244,   408,
     409,   310,   312,   154,   335,   190,   334,   190,   334,     3,
     341,   357,   387,   341,   357,   387,    33,   358,   387,   358,
     387,   398,   398,   411,   411,   411,   118,   168,   170,   170,
     392,   411,   411,   465,   466,   468,   468,   468,   468,   467,
     468,   468,   468,    70,   469,   473,   473,   472,   474,   474,
     474,   474,   475,   475,   476,   476,   230,    94,    94,    94,
     184,   410,   491,   491,   410,   504,   187,   411,   514,   149,
     187,   514,   107,   187,   187,   107,   107,   378,    29,   651,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
     360,   361,   362,    94,   137,   142,   366,   367,   368,   650,
     160,   160,   360,   648,   127,   132,    54,    56,   100,   250,
     263,   265,   276,   277,   278,   280,   282,   608,   609,   610,
     611,   612,   613,   620,   626,   627,   245,    94,   298,   650,
     142,   411,   118,   650,   650,   132,   184,   184,   187,   187,
     184,   107,   187,   107,   187,   107,    36,    94,    96,   147,
     426,   427,   542,   650,    55,   216,   253,   416,   417,   650,
      94,   107,   187,   389,   187,   649,    96,    45,   649,   648,
      96,   142,   542,   650,   411,   430,   184,   187,   187,   187,
     187,   107,   188,   147,   542,   184,   187,   187,   153,   184,
     390,   390,   184,   107,   187,   107,   187,   142,   542,   411,
     188,   411,   411,   410,   410,   410,   650,   520,   521,   130,
     196,   184,   184,   131,   190,    94,   217,   218,   232,    94,
     217,   218,   232,   411,   638,   410,    94,    94,   236,   224,
     230,   107,   234,   142,   190,   187,    48,    72,    73,   243,
     412,   422,   184,   500,   580,   409,   410,   357,    33,    33,
     190,   334,   190,   113,     1,   650,   170,   411,   441,   442,
     118,   437,   438,   468,   153,   156,   258,   487,   506,   581,
     584,   585,   586,   587,   588,   592,   594,   596,   597,    47,
     152,   156,   210,   316,   317,   318,   319,   543,   545,   547,
     548,   564,   565,   566,   567,   644,   645,   646,   647,   650,
     543,   541,   547,   541,   184,   185,   107,   187,   187,   506,
     148,   165,   148,   165,   137,   395,   378,   361,   132,   545,
     368,   411,   542,   648,   648,   128,   129,   648,   276,   277,
     278,   282,   650,   262,   273,   262,   273,    29,   285,    96,
     113,   156,   614,   617,   608,    39,    44,    59,    61,    70,
      97,   224,   316,   317,   318,   382,   548,   644,   226,   298,
     307,   411,   650,    94,   298,   648,   153,   558,   559,   650,
     558,   559,   118,   425,   127,   543,   118,   411,   147,   427,
     147,    36,   147,   426,   427,   147,   542,   253,    53,    58,
      77,   118,   426,   432,   433,   434,   417,   542,   543,   380,
      94,   184,   197,   132,   352,   648,   160,   132,    96,   352,
     411,   142,   427,   153,   118,   411,   411,   147,   100,   451,
     452,   453,   455,   456,   100,   459,   460,   461,   462,   390,
     184,   184,   153,   558,   558,   411,   142,   190,   411,   121,
     187,   187,   187,    35,   521,   130,   196,     9,    10,   103,
     123,   125,   153,   194,   516,   518,   529,   530,   533,    29,
     231,   233,   411,   411,   411,   231,   233,   411,   411,   411,
     184,   185,   411,   411,   411,   411,   502,   118,   411,   411,
     392,   156,   156,   156,   153,   186,   244,   577,   578,   209,
     393,   185,   190,   113,   387,   387,   387,   441,    95,   106,
     116,   127,   443,   444,   445,   446,   107,   650,   107,   410,
     581,   588,   153,   284,   470,   633,    96,   169,   251,   252,
     254,   261,   271,   283,   582,   583,   602,   603,   604,   605,
     628,   631,   257,   259,   589,   607,   266,   593,   629,   246,
     247,   269,   598,   599,   156,   156,   545,   156,   156,   156,
     156,   156,   144,   176,   193,   544,   144,   411,   137,   395,
     560,   367,   285,    29,    96,   113,   156,   621,    29,   614,
     544,   544,   489,   286,   305,   542,   382,   226,   190,   389,
     187,   187,   144,   187,   187,   425,   147,   426,   650,   411,
     147,   411,   127,   411,   147,   427,   147,   411,   147,   118,
     118,   411,   650,   434,    77,   543,   392,   411,   648,   107,
     352,   411,   142,   389,   449,   411,   411,   113,   452,   453,
     100,   186,   113,   453,   456,   118,   543,   100,   113,   460,
     100,   113,   462,   184,   389,   187,   187,   411,   411,   197,
     459,   132,   194,   518,     7,   390,   650,   194,   529,   190,
     232,   232,   232,   232,   232,   232,   236,   236,   575,   186,
     410,   410,   410,   580,   578,   500,   198,   648,   128,   129,
     445,   446,   446,   442,   106,   142,   439,   542,   438,   184,
     187,   581,   595,   249,   216,   253,   267,   274,   632,    96,
     255,   256,   630,   249,   585,   632,   472,   602,   586,   147,
     281,   590,   591,   630,   285,   601,    78,   600,   187,   193,
     543,   546,   187,   187,   187,   187,   187,   187,   187,    29,
     136,   200,   623,   624,   625,    29,   622,   623,   270,   618,
     107,   615,   170,   650,   256,   489,   184,   411,   147,   411,
     147,   426,   411,   147,   411,   411,   650,   650,   433,   411,
     126,   126,    96,   648,   411,   184,   186,   186,   411,   392,
     411,   186,   186,   650,   186,   118,   543,   118,   186,   118,
     543,   186,   184,   113,   521,   650,   194,   184,   521,   650,
     411,   411,   411,   411,   411,   411,   411,   411,   411,   187,
     187,   187,   153,   579,   411,   446,   648,   411,   142,   184,
     474,    52,   129,   472,   472,   268,   275,   285,   606,   606,
     587,   153,   279,    94,   187,   107,   187,   621,   621,   625,
     107,   187,    29,   619,   630,   616,   617,   187,   384,   385,
     489,   118,   224,   306,   286,   170,   411,   411,   147,   411,
      53,   392,   411,   352,   411,   392,    94,   392,   411,   650,
     186,   650,   411,   650,   186,   392,   118,    93,   183,   522,
     521,   650,   196,   521,    96,   197,   459,   410,   439,   411,
     472,   472,   198,   410,   543,   543,    94,    29,   264,   107,
     107,   446,   542,   650,   118,   224,   650,   384,   411,   118,
     543,    94,   186,    94,   650,     5,   133,   525,   526,   528,
     530,    28,   134,   523,   524,   527,   530,   196,   521,   196,
     315,   113,   184,   439,   472,   184,   543,   617,   385,   446,
     304,   650,   118,   224,   650,   186,   543,   392,   411,   543,
     186,    93,   133,   528,   183,   134,   527,   196,   411,   118,
     411,   304,   650,   118,   392,   411,   186,   186,   650,   292,
     304,   650,   186,   305,   411,   305,   489,   489,   198,   286,
     650,   224,   118,   650,   305,   489
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
     410,   410,   411,   411,   411,   411,   411,   411,   412,   412,
     412,   412,   412,   412,   412,   412,   412,   412,   412,   412,
     413,   414,   415,   415,   416,   416,   416,   417,   417,   418,
     418,   419,   420,   420,   420,   421,   421,   421,   421,   421,
     422,   422,   423,   423,   423,   424,   424,   424,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   425,   425,   425,
     426,   427,   428,   429,   429,   430,   430,   430,   430,   431,
     431,   432,   432,   432,   433,   433,   433,   434,   434,   434,
     435,   436,   437,   437,   438,   438,   438,   438,   438,   438,
     439,   440,   440,   441,   441,   442,   442,   443,   443,   443,
     443,   443,   443,   443,   444,   444,   445,   445,   446,   447,
     447,   448,   448,   449,   449,   450,   451,   451,   452,   453,
     453,   454,   455,   455,   456,   457,   457,   458,   458,   459,
     459,   460,   460,   461,   461,   462,   462,   463,   464,   464,
     465,   465,   466,   466,   466,   466,   466,   467,   466,   466,
     466,   466,   468,   468,   469,   469,   470,   470,   471,   471,
     472,   472,   472,   473,   473,   473,   473,   473,   474,   474,
     474,   475,   475,   475,   476,   476,   477,   477,   478,   478,
     479,   479,   480,   480,   481,   481,   481,   481,   482,   482,
     482,   483,   483,   483,   483,   483,   483,   484,   484,   484,
     485,   485,   485,   485,   486,   486,   487,   487,   488,   488,
     488,   489,   489,   489,   489,   490,   491,   491,   491,   492,
     492,   493,   493,   493,   493,   494,   494,   495,   495,   495,
     495,   495,   495,   495,   496,   496,   497,   497,   498,   498,
     498,   498,   498,   499,   499,   500,   500,   501,   501,   501,
     501,   502,   502,   502,   502,   503,   503,   504,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   506,   506,   507,   507,   507,   508,   509,   509,
     510,   511,   512,   513,   513,   514,   514,   515,   515,   516,
     516,   516,   517,   517,   517,   517,   517,   517,   518,   518,
     519,   519,   520,   521,   521,   522,   522,   523,   523,   524,
     524,   524,   524,   525,   525,   526,   526,   526,   526,   527,
     527,   528,   528,   529,   529,   529,   529,   530,   530,   530,
     530,   531,   531,   532,   532,   533,   534,   534,   534,   534,
     534,   534,   535,   536,   536,   537,   537,   538,   539,   540,
     540,   541,   541,   542,   543,   543,   543,   544,   544,   544,
     545,   545,   545,   545,   545,   545,   545,   546,   546,   547,
     548,   548,   548,   548,   548,   548,   548,   548,   548,   549,
     550,   550,   550,   551,   552,   553,   553,   553,   554,   554,
     554,   554,   554,   555,   556,   556,   556,   556,   556,   556,
     556,   557,   558,   559,   560,   561,   561,   562,   563,   564,
     564,   565,   566,   566,   567,   568,   568,   568,   569,   569,
     569,   569,   569,   569,   569,   569,   569,   569,   570,   570,
     571,   571,   572,   573,   574,   574,   575,   576,   577,   577,
     578,   579,   580,   580,   581,   582,   582,   583,   583,   584,
     584,   585,   585,   586,   586,   587,   587,   588,   589,   589,
     590,   590,   591,   592,   592,   592,   593,   593,   594,   595,
     595,   596,   597,   597,   598,   598,   599,   599,   599,   600,
     600,   601,   601,   602,   602,   602,   602,   602,   603,   604,
     605,   606,   606,   606,   607,   607,   608,   608,   608,   608,
     608,   608,   608,   608,   609,   609,   609,   609,   610,   610,
     611,   612,   612,   613,   613,   613,   614,   614,   615,   615,
     616,   616,   617,   618,   618,   619,   619,   620,   620,   620,
     621,   621,   622,   622,   623,   623,   624,   624,   625,   625,
     626,   627,   627,   628,   628,   628,   629,   630,   630,   630,
     630,   631,   631,   632,   632,   633,   634,   634,   635,   635,
     636,   636,   637,   638,   638,   639,   639,   640,   641,   642,
     643,   644,   644,   644,   645,   646,   647,   648,   649,   649,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   651,   651,   651,   651,
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
     651,   651,   652
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
       4,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     1,     1,     2,     4,     3,     5,
       4,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     3,     2,     1,     4,     3,     3,     5,
       4,     6,     4,     6,     5,     7,     4,     5,     5,     6,
       3,     3,     2,     1,     3,     4,     5,     3,     6,     4,
       5,     1,     2,     3,     1,     2,     1,     6,     3,     3,
       2,     3,     1,     3,     2,     4,     5,     6,     5,     3,
       2,     3,     4,     1,     3,     1,     2,     1,     1,     1,
       2,     2,     2,     3,     1,     1,     2,     2,     2,     5,
       5,     1,     4,     3,     4,     8,     1,     2,     3,     2,
       3,     8,     1,     2,     3,     8,    10,     8,    10,     1,
       2,     4,     7,     1,     2,     4,     7,     8,     1,     3,
       1,     3,     1,     3,     3,     3,     3,     0,     4,     3,
       3,     3,     1,     5,     1,     3,     0,     1,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     4,     1,     4,     1,     4,
       1,     4,     1,     2,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     5,     5,     6,     3,     4,     1,     2,     3,     2,
       2,     1,     2,     2,     1,     1,     1,     3,     3,     1,
       1,     1,     2,     1,     2,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     1,     2,     2,     1,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     4,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       1,     4,     4,     3,     4,     1,     3,     1,     1,     1,
       1,     1,     4,     5,     8,     9,     9,    10,     1,     2,
       1,     2,     6,     0,     1,     3,     3,     0,     1,     1,
       1,     2,     2,     0,     1,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     2,     3,     3,     2,     1,     1,     1,     1,
       1,     1,     4,     3,     7,     3,     7,     4,     4,     3,
       7,     1,     2,     2,     1,     2,     3,     1,     1,     1,
       1,     1,     3,     3,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     4,     4,     3,     3,     3,     4,     4,     3,     4,
       6,     4,     6,     4,     3,     4,     6,     6,     4,     6,
       6,     4,     1,     2,     1,     1,     1,     3,     3,     1,
       1,     4,     5,     6,     3,     3,     3,     3,     5,     7,
       7,     5,     5,     5,     7,     7,     5,     5,     3,     3,
       5,     7,     5,     7,     1,     4,     3,     5,     1,     2,
       3,     3,     1,     3,     2,     0,     1,     1,     2,     1,
       3,     1,     3,     1,     4,     1,     2,     3,     0,     1,
       0,     1,     4,     2,     3,     1,     0,     1,     4,     0,
       1,     2,     1,     3,     0,     1,     2,     2,     1,     0,
       1,     0,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     1,     1,     1,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     2,     2,
       3,     1,     2,     2,     5,     2,     1,     1,     0,     2,
       1,     3,     4,     0,     2,     0,     2,     4,     4,     3,
       2,     3,     1,     3,     0,     1,     1,     2,     2,     2,
       2,     1,     2,     2,     2,     2,     3,     2,     3,     3,
       4,     2,     2,     1,     1,     3,     2,     3,     2,     3,
       2,     3,     3,     3,     5,     7,    10,     7,     3,     5,
       7,     1,     1,     1,     3,     3,     3,     1,     1,     1,
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
       1,     1,     1
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
     580,   393,    -1,   411,    -1,   410,   107,   411,    -1,   410,
       1,   411,     1,    -1,   410,   334,   411,    -1,   413,    -1,
     450,    -1,   457,    -1,   463,    -1,   576,    -1,   412,    -1,
     464,    -1,   447,    -1,   569,    -1,   570,    -1,   572,    -1,
     571,    -1,   573,    -1,   641,    -1,   639,    -1,   642,    -1,
     643,    -1,   640,    -1,   422,   414,    -1,   186,   411,    -1,
      66,   283,    -1,    71,   283,    -1,   216,    -1,   253,    -1,
      55,   253,    -1,   416,   432,    77,   411,    -1,   416,    77,
     411,    -1,    46,   415,   431,   417,   417,    -1,    46,   415,
     431,   417,    -1,    42,   118,   650,    -1,   423,    -1,   428,
      -1,   418,    -1,   420,    -1,   435,    -1,   440,    -1,   436,
      -1,   419,    -1,   420,    -1,   422,   421,    -1,    46,   118,
     424,    -1,    46,     1,   424,    -1,    46,     3,    -1,   425,
      -1,   424,   107,   118,   425,    -1,   424,   107,   425,    -1,
     650,   147,   411,    -1,   650,    36,   127,   147,   411,    -1,
     650,   542,   147,   411,    -1,   650,   542,    36,   127,   147,
     411,    -1,   650,   426,   147,   411,    -1,   650,    36,   127,
     426,   147,   411,    -1,   650,   542,   426,   147,   411,    -1,
     650,   542,    36,   127,   426,   147,   411,    -1,   650,   427,
     147,   411,    -1,   650,   542,   427,   147,   411,    -1,   650,
     426,   427,   147,   411,    -1,   650,   542,   426,   427,   147,
     411,    -1,    96,   118,   650,    -1,   272,   118,   650,    -1,
      51,   429,    -1,   430,    -1,   429,   107,   430,    -1,   118,
     650,   142,   411,    -1,   118,   650,   542,   142,   411,    -1,
     427,   142,   411,    -1,   118,   650,   542,   427,   142,   411,
      -1,   118,   650,   147,   411,    -1,   118,   650,   542,   147,
     411,    -1,   433,    -1,   118,   650,    -1,   118,   650,   433,
      -1,   426,    -1,   426,   434,    -1,   434,    -1,    58,   118,
     650,    53,   118,   650,    -1,    53,   118,   650,    -1,    58,
     118,   650,    -1,   211,   411,    -1,   171,   170,   437,    -1,
     438,    -1,   437,   107,   438,    -1,   118,   650,    -1,   118,
     650,   142,   411,    -1,   118,   650,   542,   142,   411,    -1,
     118,   650,   542,   142,   411,   439,    -1,   118,   650,   142,
     411,   439,    -1,   118,   650,   439,    -1,   106,   648,    -1,
     168,   170,   441,    -1,    69,   168,   170,   441,    -1,   442,
      -1,   441,   107,   442,    -1,   411,    -1,   411,   443,    -1,
     444,    -1,   445,    -1,   446,    -1,   444,   445,    -1,   444,
     446,    -1,   445,   446,    -1,   444,   445,   446,    -1,    95,
      -1,   116,    -1,   127,   128,    -1,   127,   129,    -1,   106,
     648,    -1,    67,   118,   448,   188,   411,    -1,   135,   118,
     448,   188,   411,    -1,   449,    -1,   448,   107,   118,   449,
      -1,   650,   147,   411,    -1,   650,   542,   147,   411,    -1,
      72,   156,   410,   187,   451,   113,   186,   411,    -1,   452,
      -1,   451,   452,    -1,   453,   186,   411,    -1,   100,   411,
      -1,   453,   100,   411,    -1,    72,   156,   410,   187,   455,
     113,   186,   392,    -1,   456,    -1,   455,   456,    -1,   453,
     186,   392,    -1,    73,   156,   410,   187,   459,   113,   186,
     411,    -1,    73,   156,   410,   187,   459,   113,   118,   650,
     186,   411,    -1,    73,   156,   410,   187,   461,   113,   186,
     392,    -1,    73,   156,   410,   187,   459,   113,   118,   650,
     186,   392,    -1,   460,    -1,   459,   460,    -1,   100,   543,
     186,   411,    -1,   100,   118,   650,    94,   543,   186,   411,
      -1,   462,    -1,   461,   462,    -1,   100,   543,   186,   392,
      -1,   100,   118,   650,    94,   543,   186,   392,    -1,    48,
     156,   410,   187,   197,   411,   126,   411,    -1,   465,    -1,
     464,   167,   465,    -1,   466,    -1,   465,    92,   466,    -1,
     468,    -1,   468,   483,   468,    -1,   468,   484,   468,    -1,
     468,   132,   468,    -1,   468,   162,   468,    -1,    -1,   468,
     157,   467,   468,    -1,   468,   155,   468,    -1,   468,   143,
     468,    -1,   468,   141,   468,    -1,   469,    -1,   469,   248,
      70,   581,   470,    -1,   471,    -1,   471,    99,   469,    -1,
      -1,   633,    -1,   472,    -1,   472,   198,   472,    -1,   473,
      -1,   472,   176,   473,    -1,   472,   158,   473,    -1,   474,
      -1,   473,   193,   474,    -1,   473,   117,   474,    -1,   473,
     146,   474,    -1,   473,   159,   474,    -1,   475,    -1,   474,
     200,   475,    -1,   474,   209,   475,    -1,   476,    -1,   475,
     150,   476,    -1,   475,   136,   476,    -1,   477,    -1,   477,
      50,   230,   543,    -1,   478,    -1,   478,   199,    94,   543,
      -1,   479,    -1,   479,   101,    94,   541,    -1,   480,    -1,
     480,   102,    94,   541,    -1,   482,    -1,   481,   482,    -1,
     176,    -1,   158,    -1,   481,   176,    -1,   481,   158,    -1,
     485,    -1,   489,    -1,   486,    -1,   202,    -1,   207,    -1,
     206,    -1,   205,    -1,   204,    -1,   203,    -1,   151,    -1,
     179,    -1,   140,    -1,    75,   153,   390,   184,    -1,    75,
     221,   153,   390,   184,    -1,    75,   220,   153,   390,   184,
      -1,    75,    76,   558,   153,   390,   184,    -1,   487,   153,
     184,    -1,   487,   153,   410,   184,    -1,   488,    -1,   487,
     488,    -1,   177,   650,    17,    -1,   177,    18,    -1,   177,
      19,    -1,   490,    -1,   490,   491,    -1,   192,   491,    -1,
     491,    -1,   191,    -1,   492,    -1,   492,   191,   491,    -1,
     492,   192,   491,    -1,   493,    -1,   502,    -1,   494,    -1,
     494,   503,    -1,   497,    -1,   497,   503,    -1,   495,   499,
      -1,   496,    -1,   105,   122,    -1,   114,   122,    -1,    97,
     122,    -1,   189,   122,    -1,   115,   122,    -1,   139,   122,
      -1,   138,   122,    -1,   499,    -1,    98,   499,    -1,   498,
     499,    -1,   120,    -1,   172,   122,    -1,    90,   122,    -1,
     181,   122,    -1,   180,   122,    -1,    91,   122,    -1,   548,
      -1,   500,    -1,   650,    -1,   501,    -1,   193,    -1,    11,
      -1,    12,    -1,    20,    -1,   505,    -1,   502,   503,    -1,
     502,   156,   187,    -1,   502,   156,   514,   187,    -1,   504,
      -1,   503,   504,    -1,   154,   410,   185,    -1,   506,    -1,
     508,    -1,   509,    -1,   510,    -1,   513,    -1,   515,    -1,
     511,    -1,   512,    -1,   561,    -1,   394,    -1,   637,    -1,
     634,    -1,   635,    -1,   636,    -1,   507,    -1,   560,    -1,
     110,    -1,   149,    -1,   124,    -1,   118,   650,    -1,   156,
     187,    -1,   156,   410,   187,    -1,   119,    -1,   169,   153,
     410,   184,    -1,   201,   153,   410,   184,    -1,   651,   156,
     187,    -1,   651,   156,   514,   187,    -1,   411,    -1,   514,
     107,   411,    -1,   516,    -1,   534,    -1,   517,    -1,   531,
      -1,   532,    -1,   157,   650,   521,   130,    -1,   157,   650,
     519,   521,   130,    -1,   157,   650,   521,   196,   194,   650,
     521,   196,    -1,   157,   650,   521,   196,   518,   194,   650,
     521,   196,    -1,   157,   650,   519,   521,   196,   194,   650,
     521,   196,    -1,   157,   650,   519,   521,   196,   518,   194,
     650,   521,   196,    -1,   529,    -1,   518,   529,    -1,   520,
      -1,   519,   520,    -1,    35,   650,   521,   132,   521,   522,
      -1,    -1,    35,    -1,   183,   523,   183,    -1,    93,   525,
      93,    -1,    -1,   524,    -1,   134,    -1,   527,    -1,   524,
     134,    -1,   524,   527,    -1,    -1,   526,    -1,   133,    -1,
     528,    -1,   526,   133,    -1,   526,   528,    -1,    28,    -1,
     530,    -1,     5,    -1,   530,    -1,   516,    -1,    10,    -1,
     533,    -1,   530,    -1,     9,    -1,   123,    -1,   125,    -1,
     153,   390,   184,    -1,   212,    30,   213,    -1,   212,   213,
      -1,   174,   649,   175,    -1,   174,   649,     8,    -1,   103,
       7,    -1,   535,    -1,   536,    -1,   537,    -1,   538,    -1,
     539,    -1,   540,    -1,    43,   153,   390,   184,    -1,    21,
     389,   184,    -1,    45,   153,   410,   184,   153,   389,   184,
      -1,    22,   389,   184,    -1,    97,   153,   410,   184,   153,
     389,   184,    -1,    70,   153,   390,   184,    -1,    39,   153,
     390,   184,    -1,    23,   389,   184,    -1,    59,   153,   410,
     184,   153,   389,   184,    -1,   547,    -1,   547,   144,    -1,
      94,   543,    -1,   545,    -1,   545,   544,    -1,   210,   156,
     187,    -1,   144,    -1,   193,    -1,   176,    -1,   547,    -1,
     548,    -1,   152,   156,   187,    -1,   319,   156,   187,    -1,
     564,    -1,   567,    -1,   644,    -1,   543,    -1,   546,   107,
     543,    -1,   650,    -1,   550,    -1,   556,    -1,   554,    -1,
     557,    -1,   555,    -1,   553,    -1,   552,    -1,   551,    -1,
     549,    -1,   224,   156,   187,    -1,    44,   156,   187,    -1,
      44,   156,   556,   187,    -1,    44,   156,   557,   187,    -1,
      70,   156,   187,    -1,    39,   156,   187,    -1,    59,   156,
     187,    -1,    59,   156,   649,   187,    -1,    59,   156,    29,
     187,    -1,    97,   156,   187,    -1,    97,   156,   650,   187,
      -1,    97,   156,   650,   107,   558,   187,    -1,    97,   156,
     193,   187,    -1,    97,   156,   193,   107,   558,   187,    -1,
      61,   156,   650,   187,    -1,    45,   156,   187,    -1,    45,
     156,   650,   187,    -1,    45,   156,   650,   107,   558,   187,
      -1,    45,   156,   650,   107,   559,   187,    -1,    45,   156,
     193,   187,    -1,    45,   156,   193,   107,   558,   187,    -1,
      45,   156,   193,   107,   559,   187,    -1,    62,   156,   650,
     187,    -1,   650,    -1,   650,   144,    -1,    29,    -1,   562,
      -1,   563,    -1,   650,   145,   149,    -1,    47,   378,   395,
      -1,   565,    -1,   566,    -1,    47,   156,   193,   187,    -1,
      47,   156,   187,    94,   543,    -1,    47,   156,   546,   187,
      94,   543,    -1,   156,   545,   187,    -1,    33,   219,   220,
      -1,    33,   219,   221,    -1,    33,   219,   222,    -1,   225,
     224,   411,   232,   411,    -1,   225,   224,   411,    94,   231,
     232,   411,    -1,   225,   224,   411,    94,   233,   232,   411,
      -1,   225,   224,   411,   217,   411,    -1,   225,   224,   411,
     218,   411,    -1,   225,   226,   411,   232,   411,    -1,   225,
     226,   411,    94,   231,   232,   411,    -1,   225,   226,   411,
      94,   233,   232,   411,    -1,   225,   226,   411,   217,   411,
      -1,   225,   226,   411,   218,   411,    -1,   223,   224,   411,
      -1,   223,   226,   411,    -1,   228,   224,   411,   236,   411,
      -1,   228,   229,   230,   224,   411,   236,   411,    -1,   227,
     224,   411,    94,   411,    -1,   235,   118,   574,   234,   411,
     186,   411,    -1,   575,    -1,   574,   107,   118,   575,    -1,
     650,   142,   411,    -1,   243,   153,   410,   184,   577,    -1,
     578,    -1,   577,   578,    -1,   244,   580,   579,    -1,   153,
     410,   184,    -1,   500,    -1,   580,   209,   500,    -1,   584,
     582,    -1,    -1,   583,    -1,   602,    -1,   583,   602,    -1,
     585,    -1,   584,   261,   585,    -1,   586,    -1,   585,   257,
     586,    -1,   587,    -1,   586,   259,   147,   587,    -1,   588,
      -1,   258,   588,    -1,   592,   589,   590,    -1,    -1,   607,
      -1,    -1,   591,    -1,   281,   153,   410,   184,    -1,   596,
     593,    -1,   156,   581,   187,    -1,   594,    -1,    -1,   629,
      -1,   487,   153,   595,   184,    -1,    -1,   581,    -1,   597,
     598,    -1,   506,    -1,   153,   410,   184,    -1,    -1,   599,
      -1,   247,   600,    -1,   246,   601,    -1,   269,    -1,    -1,
      78,    -1,    -1,   285,    -1,   603,    -1,   604,    -1,   605,
      -1,   631,    -1,   628,    -1,   169,    -1,   283,   472,   606,
      -1,   252,   630,   606,    -1,   285,    -1,   275,    -1,   268,
      -1,   245,   608,    -1,   607,   245,   608,    -1,   609,    -1,
     610,    -1,   611,    -1,   626,    -1,   612,    -1,   620,    -1,
     613,    -1,   627,    -1,   100,   273,    -1,   100,   262,    -1,
     265,    -1,   280,    -1,   250,   273,    -1,   250,   262,    -1,
      56,   650,    29,    -1,   276,    -1,    54,   276,    -1,   278,
     614,    -1,   278,   156,   614,   615,   187,    -1,    54,   278,
      -1,   617,    -1,   113,    -1,    -1,   107,   616,    -1,   617,
      -1,   616,   107,   617,    -1,    96,    29,   618,   619,    -1,
      -1,   270,    29,    -1,    -1,   630,   264,    -1,   277,   285,
     621,   623,    -1,   277,   285,   113,   623,    -1,    54,   277,
     285,    -1,    96,    29,    -1,   156,   622,   187,    -1,    29,
      -1,   622,   107,    29,    -1,    -1,   624,    -1,   625,    -1,
     624,   625,    -1,   200,   621,    -1,   136,   621,    -1,   263,
      29,    -1,   282,    -1,    54,   282,    -1,    96,   216,    -1,
      96,   253,    -1,   254,   249,    -1,   266,   630,   279,    -1,
     255,   472,    -1,    96,   129,   472,    -1,    96,    52,   472,
      -1,   256,   472,   198,   472,    -1,   271,   632,    -1,   251,
     632,    -1,   274,    -1,   267,    -1,   284,   249,   474,    -1,
     154,   185,    -1,   154,   410,   185,    -1,   309,   310,    -1,
     309,   410,   310,    -1,   311,   312,    -1,   311,   410,   312,
      -1,   153,   638,   184,    -1,   411,   121,   411,    -1,   638,
     107,   411,   121,   411,    -1,   225,   313,   153,   638,   184,
     232,   411,    -1,   225,   313,   154,   410,   185,   232,   411,
      96,   315,   411,    -1,   314,   313,   154,   410,   185,   198,
     411,    -1,   223,   313,   502,    -1,   227,   313,   502,    94,
     411,    -1,   228,   313,   229,   230,   502,   236,   411,    -1,
     645,    -1,   646,    -1,   647,    -1,   318,   156,   187,    -1,
     316,   156,   187,    -1,   317,   156,   187,    -1,    29,    -1,
      16,    -1,   650,    -1,   651,    -1,    97,    -1,    39,    -1,
      44,    -1,    45,    -1,   152,    -1,    48,    -1,   224,    -1,
      59,    -1,    61,    -1,    62,    -1,    70,    -1,    73,    -1,
      72,    -1,   210,    -1,   242,    -1,   652,    -1,    24,    -1,
     214,    -1,   127,    -1,    38,    -1,   260,    -1,    37,    -1,
     221,    -1,   220,    -1,   146,    -1,    43,    -1,   258,    -1,
     259,    -1,   273,    -1,   262,    -1,   250,    -1,   284,    -1,
     276,    -1,   278,    -1,   277,    -1,   282,    -1,   254,    -1,
     249,    -1,    78,    -1,   216,    -1,   253,    -1,    52,    -1,
     222,    -1,   235,    -1,   301,    -1,   229,    -1,   202,    -1,
     207,    -1,   206,    -1,   205,    -1,   204,    -1,   203,    -1,
      96,    -1,   111,    -1,   112,    -1,   186,    -1,    46,    -1,
      36,    -1,    66,    -1,    71,    -1,    58,    -1,    53,    -1,
      55,    -1,    77,    -1,    42,    -1,   147,    -1,    51,    -1,
     211,    -1,   170,    -1,   171,    -1,   168,    -1,    69,    -1,
      95,    -1,   116,    -1,   128,    -1,   129,    -1,   106,    -1,
      67,    -1,   135,    -1,   188,    -1,   100,    -1,    94,    -1,
     197,    -1,   126,    -1,   167,    -1,    92,    -1,    50,    -1,
     230,    -1,   101,    -1,   198,    -1,   117,    -1,   159,    -1,
     200,    -1,   150,    -1,   136,    -1,    75,    -1,    76,    -1,
     102,    -1,   199,    -1,   151,    -1,   182,    -1,   195,    -1,
     160,    -1,   137,    -1,   131,    -1,   166,    -1,   148,    -1,
     165,    -1,    33,    -1,    40,    -1,    57,    -1,   113,    -1,
      41,    -1,    56,    -1,   215,    -1,    49,    -1,    60,    -1,
      34,    -1,    47,    -1,   272,    -1,   248,    -1,   281,    -1,
     283,    -1,   252,    -1,   266,    -1,   279,    -1,   271,    -1,
     251,    -1,   265,    -1,   280,    -1,   270,    -1,   264,    -1,
     263,    -1,   247,    -1,   246,    -1,   255,    -1,   256,    -1,
     285,    -1,   275,    -1,   274,    -1,   269,    -1,   267,    -1,
     268,    -1,   228,    -1,   234,    -1,   231,    -1,   225,    -1,
     218,    -1,   217,    -1,   219,    -1,   236,    -1,   226,    -1,
     227,    -1,   233,    -1,   223,    -1,   232,    -1,    65,    -1,
      63,    -1,    74,    -1,   169,    -1,   201,    -1,   241,    -1,
     239,    -1,   240,    -1,   237,    -1,   238,    -1,   243,    -1,
     244,    -1,   245,    -1,    64,    -1,   294,    -1,   292,    -1,
     293,    -1,   298,    -1,   299,    -1,   300,    -1,   295,    -1,
     296,    -1,   297,    -1,    79,    -1,    80,    -1,    81,    -1,
      82,    -1,    83,    -1,    84,    -1,    85,    -1,    86,    -1,
      87,    -1,    88,    -1,    89,    -1,   286,    -1,   287,    -1,
     288,    -1,   289,    -1,   290,    -1,   291,    -1,   302,    -1,
     303,    -1,   304,    -1,   305,    -1,   306,    -1,   307,    -1,
     308,    -1,    90,    -1,   105,    -1,   114,    -1,   172,    -1,
     180,    -1,   189,    -1,   138,    -1,    91,    -1,   115,    -1,
     139,    -1,   181,    -1,   313,    -1,   314,    -1,   315,    -1,
     318,    -1,   317,    -1,   316,    -1,   319,    -1,    25,    -1
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
     799,   804,   808,   810,   812,   814,   816,   818,   820,   822,
     824,   826,   828,   830,   832,   834,   836,   838,   840,   842,
     844,   847,   850,   853,   856,   858,   860,   863,   868,   872,
     878,   883,   887,   889,   891,   893,   895,   897,   899,   901,
     903,   905,   908,   912,   916,   919,   921,   926,   930,   934,
     940,   945,   952,   957,   964,   970,   978,   983,   989,   995,
    1002,  1006,  1010,  1013,  1015,  1019,  1024,  1030,  1034,  1041,
    1046,  1052,  1054,  1057,  1061,  1063,  1066,  1068,  1075,  1079,
    1083,  1086,  1090,  1092,  1096,  1099,  1104,  1110,  1117,  1123,
    1127,  1130,  1134,  1139,  1141,  1145,  1147,  1150,  1152,  1154,
    1156,  1159,  1162,  1165,  1169,  1171,  1173,  1176,  1179,  1182,
    1188,  1194,  1196,  1201,  1205,  1210,  1219,  1221,  1224,  1228,
    1231,  1235,  1244,  1246,  1249,  1253,  1262,  1273,  1282,  1293,
    1295,  1298,  1303,  1311,  1313,  1316,  1321,  1329,  1338,  1340,
    1344,  1346,  1350,  1352,  1356,  1360,  1364,  1368,  1369,  1374,
    1378,  1382,  1386,  1388,  1394,  1396,  1400,  1401,  1403,  1405,
    1409,  1411,  1415,  1419,  1421,  1425,  1429,  1433,  1437,  1439,
    1443,  1447,  1449,  1453,  1457,  1459,  1464,  1466,  1471,  1473,
    1478,  1480,  1485,  1487,  1490,  1492,  1494,  1497,  1500,  1502,
    1504,  1506,  1508,  1510,  1512,  1514,  1516,  1518,  1520,  1522,
    1524,  1529,  1535,  1541,  1548,  1552,  1557,  1559,  1562,  1566,
    1569,  1572,  1574,  1577,  1580,  1582,  1584,  1586,  1590,  1594,
    1596,  1598,  1600,  1603,  1605,  1608,  1611,  1613,  1616,  1619,
    1622,  1625,  1628,  1631,  1634,  1636,  1639,  1642,  1644,  1647,
    1650,  1653,  1656,  1659,  1661,  1663,  1665,  1667,  1669,  1671,
    1673,  1675,  1677,  1680,  1684,  1689,  1691,  1694,  1698,  1700,
    1702,  1704,  1706,  1708,  1710,  1712,  1714,  1716,  1718,  1720,
    1722,  1724,  1726,  1728,  1730,  1732,  1734,  1736,  1739,  1742,
    1746,  1748,  1753,  1758,  1762,  1767,  1769,  1773,  1775,  1777,
    1779,  1781,  1783,  1788,  1794,  1803,  1813,  1823,  1834,  1836,
    1839,  1841,  1844,  1851,  1852,  1854,  1858,  1862,  1863,  1865,
    1867,  1869,  1872,  1875,  1876,  1878,  1880,  1882,  1885,  1888,
    1890,  1892,  1894,  1896,  1898,  1900,  1902,  1904,  1906,  1908,
    1910,  1914,  1918,  1921,  1925,  1929,  1932,  1934,  1936,  1938,
    1940,  1942,  1944,  1949,  1953,  1961,  1965,  1973,  1978,  1983,
    1987,  1995,  1997,  2000,  2003,  2005,  2008,  2012,  2014,  2016,
    2018,  2020,  2022,  2026,  2030,  2032,  2034,  2036,  2038,  2042,
    2044,  2046,  2048,  2050,  2052,  2054,  2056,  2058,  2060,  2062,
    2066,  2070,  2075,  2080,  2084,  2088,  2092,  2097,  2102,  2106,
    2111,  2118,  2123,  2130,  2135,  2139,  2144,  2151,  2158,  2163,
    2170,  2177,  2182,  2184,  2187,  2189,  2191,  2193,  2197,  2201,
    2203,  2205,  2210,  2216,  2223,  2227,  2231,  2235,  2239,  2245,
    2253,  2261,  2267,  2273,  2279,  2287,  2295,  2301,  2307,  2311,
    2315,  2321,  2329,  2335,  2343,  2345,  2350,  2354,  2360,  2362,
    2365,  2369,  2373,  2375,  2379,  2382,  2383,  2385,  2387,  2390,
    2392,  2396,  2398,  2402,  2404,  2409,  2411,  2414,  2418,  2419,
    2421,  2422,  2424,  2429,  2432,  2436,  2438,  2439,  2441,  2446,
    2447,  2449,  2452,  2454,  2458,  2459,  2461,  2464,  2467,  2469,
    2470,  2472,  2473,  2475,  2477,  2479,  2481,  2483,  2485,  2487,
    2491,  2495,  2497,  2499,  2501,  2504,  2508,  2510,  2512,  2514,
    2516,  2518,  2520,  2522,  2524,  2527,  2530,  2532,  2534,  2537,
    2540,  2544,  2546,  2549,  2552,  2558,  2561,  2563,  2565,  2566,
    2569,  2571,  2575,  2580,  2581,  2584,  2585,  2588,  2593,  2598,
    2602,  2605,  2609,  2611,  2615,  2616,  2618,  2620,  2623,  2626,
    2629,  2632,  2634,  2637,  2640,  2643,  2646,  2650,  2653,  2657,
    2661,  2666,  2669,  2672,  2674,  2676,  2680,  2683,  2687,  2690,
    2694,  2697,  2701,  2705,  2709,  2715,  2723,  2734,  2742,  2746,
    2752,  2760,  2762,  2764,  2766,  2770,  2774,  2778,  2780,  2782,
    2784,  2786,  2788,  2790,  2792,  2794,  2796,  2798,  2800,  2802,
    2804,  2806,  2808,  2810,  2812,  2814,  2816,  2818,  2820,  2822,
    2824,  2826,  2828,  2830,  2832,  2834,  2836,  2838,  2840,  2842,
    2844,  2846,  2848,  2850,  2852,  2854,  2856,  2858,  2860,  2862,
    2864,  2866,  2868,  2870,  2872,  2874,  2876,  2878,  2880,  2882,
    2884,  2886,  2888,  2890,  2892,  2894,  2896,  2898,  2900,  2902,
    2904,  2906,  2908,  2910,  2912,  2914,  2916,  2918,  2920,  2922,
    2924,  2926,  2928,  2930,  2932,  2934,  2936,  2938,  2940,  2942,
    2944,  2946,  2948,  2950,  2952,  2954,  2956,  2958,  2960,  2962,
    2964,  2966,  2968,  2970,  2972,  2974,  2976,  2978,  2980,  2982,
    2984,  2986,  2988,  2990,  2992,  2994,  2996,  2998,  3000,  3002,
    3004,  3006,  3008,  3010,  3012,  3014,  3016,  3018,  3020,  3022,
    3024,  3026,  3028,  3030,  3032,  3034,  3036,  3038,  3040,  3042,
    3044,  3046,  3048,  3050,  3052,  3054,  3056,  3058,  3060,  3062,
    3064,  3066,  3068,  3070,  3072,  3074,  3076,  3078,  3080,  3082,
    3084,  3086,  3088,  3090,  3092,  3094,  3096,  3098,  3100,  3102,
    3104,  3106,  3108,  3110,  3112,  3114,  3116,  3118,  3120,  3122,
    3124,  3126,  3128,  3130,  3132,  3134,  3136,  3138,  3140,  3142,
    3144,  3146,  3148,  3150,  3152,  3154,  3156,  3158,  3160,  3162,
    3164,  3166,  3168,  3170,  3172,  3174,  3176,  3178,  3180,  3182,
    3184,  3186,  3188,  3190,  3192,  3194,  3196,  3198,  3200,  3202,
    3204,  3206,  3208,  3210,  3212,  3214,  3216,  3218,  3220,  3222,
    3224,  3226,  3228
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
    2481,  2488,  2501,  2502,  2503,  2504,  2505,  2506,  2511,  2512,
    2515,  2516,  2517,  2518,  2519,  2522,  2523,  2524,  2525,  2526,
    2531,  2545,  2553,  2558,  2566,  2571,  2576,  2584,  2593,  2605,
    2615,  2628,  2636,  2637,  2638,  2643,  2644,  2645,  2646,  2647,
    2652,  2659,  2669,  2675,  2684,  2694,  2701,  2709,  2721,  2731,
    2741,  2751,  2761,  2771,  2781,  2791,  2802,  2811,  2821,  2831,
    2847,  2856,  2865,  2873,  2879,  2891,  2899,  2909,  2917,  2929,
    2935,  2946,  2948,  2952,  2960,  2964,  2969,  2973,  2977,  2981,
    2991,  2999,  3006,  3012,  3022,  3026,  3030,  3038,  3046,  3054,
    3066,  3074,  3080,  3090,  3096,  3106,  3110,  3120,  3126,  3132,
    3138,  3147,  3156,  3165,  3178,  3182,  3190,  3196,  3206,  3214,
    3223,  3236,  3243,  3255,  3259,  3271,  3278,  3284,  3293,  3300,
    3306,  3317,  3324,  3330,  3339,  3348,  3355,  3366,  3373,  3385,
    3391,  3403,  3409,  3420,  3426,  3437,  3443,  3454,  3463,  3467,
    3476,  3480,  3488,  3492,  3502,  3509,  3518,  3528,  3527,  3541,
    3550,  3559,  3572,  3576,  3588,  3592,  3600,  3603,  3610,  3614,
    3623,  3627,  3631,  3639,  3643,  3649,  3655,  3661,  3671,  3675,
    3679,  3687,  3691,  3697,  3707,  3711,  3721,  3725,  3735,  3739,
    3749,  3753,  3763,  3767,  3775,  3779,  3783,  3787,  3797,  3801,
    3805,  3813,  3817,  3821,  3825,  3829,  3833,  3841,  3845,  3849,
    3857,  3861,  3865,  3869,  3880,  3886,  3896,  3902,  3912,  3916,
    3920,  3958,  3962,  3972,  3982,  3995,  4004,  4014,  4018,  4027,
    4031,  4040,  4046,  4054,  4060,  4072,  4078,  4088,  4092,  4096,
    4100,  4104,  4110,  4116,  4124,  4128,  4136,  4140,  4151,  4155,
    4159,  4165,  4169,  4183,  4187,  4195,  4199,  4209,  4213,  4217,
    4221,  4230,  4234,  4238,  4242,  4250,  4256,  4266,  4274,  4278,
    4282,  4286,  4290,  4294,  4298,  4302,  4306,  4310,  4315,  4319,
    4323,  4327,  4335,  4339,  4347,  4354,  4361,  4372,  4380,  4384,
    4392,  4400,  4408,  4462,  4466,  4479,  4485,  4495,  4499,  4507,
    4511,  4515,  4523,  4533,  4543,  4560,  4577,  4594,  4616,  4622,
    4633,  4639,  4650,  4661,  4663,  4667,  4672,  4682,  4685,  4692,
    4698,  4704,  4712,  4725,  4728,  4735,  4741,  4747,  4754,  4765,
    4769,  4779,  4783,  4793,  4797,  4801,  4806,  4815,  4821,  4827,
    4833,  4841,  4846,  4854,  4859,  4867,  4875,  4880,  4885,  4890,
    4895,  4900,  4909,  4917,  4921,  4938,  4942,  4950,  4958,  4966,
    4970,  4978,  4984,  4994,  5002,  5006,  5010,  5045,  5051,  5057,
    5067,  5071,  5075,  5079,  5083,  5087,  5091,  5098,  5104,  5114,
    5122,  5126,  5130,  5134,  5138,  5142,  5146,  5150,  5154,  5162,
    5170,  5174,  5178,  5188,  5196,  5204,  5208,  5212,  5220,  5224,
    5230,  5236,  5240,  5250,  5258,  5262,  5268,  5277,  5286,  5292,
    5298,  5308,  5325,  5332,  5347,  5383,  5387,  5395,  5403,  5415,
    5419,  5427,  5435,  5439,  5450,  5467,  5473,  5479,  5489,  5493,
    5499,  5505,  5509,  5515,  5519,  5525,  5531,  5538,  5548,  5553,
    5561,  5567,  5577,  5599,  5608,  5614,  5627,  5641,  5648,  5654,
    5664,  5673,  5681,  5687,  5705,  5713,  5717,  5724,  5729,  5737,
    5741,  5748,  5752,  5759,  5763,  5770,  5774,  5783,  5796,  5799,
    5807,  5810,  5818,  5826,  5834,  5838,  5846,  5849,  5857,  5869,
    5872,  5880,  5892,  5898,  5908,  5911,  5919,  5923,  5927,  5935,
    5938,  5946,  5949,  5957,  5961,  5965,  5969,  5973,  5981,  5989,
    6001,  6013,  6017,  6021,  6029,  6035,  6045,  6049,  6053,  6057,
    6061,  6065,  6069,  6073,  6081,  6085,  6089,  6093,  6101,  6107,
    6117,  6127,  6131,  6139,  6149,  6160,  6167,  6171,  6179,  6182,
    6189,  6194,  6203,  6213,  6216,  6223,  6227,  6235,  6244,  6251,
    6261,  6265,  6272,  6278,  6288,  6291,  6298,  6303,  6315,  6323,
    6335,  6343,  6347,  6355,  6359,  6363,  6371,  6379,  6383,  6387,
    6391,  6399,  6407,  6419,  6423,  6431,  6445,  6449,  6456,  6461,
    6469,  6474,  6483,  6491,  6497,  6507,  6513,  6520,  6527,  6556,
    6585,  6614,  6618,  6622,  6629,  6636,  6643,  6655,  6659,  6660,
    6673,  6674,  6675,  6676,  6677,  6678,  6679,  6680,  6681,  6682,
    6683,  6684,  6685,  6686,  6687,  6688,  6692,  6693,  6694,  6695,
    6696,  6697,  6698,  6699,  6700,  6701,  6702,  6703,  6704,  6705,
    6706,  6707,  6708,  6709,  6710,  6711,  6712,  6713,  6714,  6715,
    6716,  6717,  6718,  6719,  6720,  6721,  6722,  6723,  6724,  6725,
    6726,  6727,  6728,  6729,  6730,  6731,  6732,  6733,  6734,  6735,
    6736,  6737,  6738,  6739,  6740,  6741,  6742,  6743,  6744,  6745,
    6746,  6747,  6748,  6749,  6750,  6751,  6752,  6753,  6754,  6755,
    6756,  6757,  6758,  6759,  6760,  6761,  6762,  6763,  6764,  6765,
    6766,  6767,  6768,  6769,  6770,  6771,  6772,  6773,  6774,  6775,
    6776,  6777,  6778,  6779,  6780,  6781,  6782,  6783,  6784,  6785,
    6786,  6787,  6788,  6789,  6790,  6791,  6792,  6793,  6794,  6795,
    6796,  6797,  6798,  6799,  6800,  6801,  6802,  6803,  6804,  6805,
    6806,  6807,  6808,  6809,  6810,  6811,  6812,  6813,  6814,  6815,
    6816,  6817,  6818,  6819,  6820,  6821,  6822,  6823,  6824,  6825,
    6826,  6827,  6828,  6829,  6830,  6831,  6832,  6833,  6834,  6835,
    6836,  6837,  6838,  6839,  6840,  6841,  6842,  6843,  6844,  6845,
    6846,  6847,  6848,  6849,  6850,  6851,  6852,  6853,  6854,  6855,
    6856,  6857,  6858,  6859,  6860,  6861,  6862,  6863,  6864,  6865,
    6866,  6867,  6868,  6869,  6870,  6871,  6872,  6873,  6874,  6875,
    6876,  6877,  6878,  6879,  6880,  6881,  6882,  6883,  6884,  6885,
    6886,  6887,  6888,  6889,  6890,  6891,  6892,  6893,  6894,  6895,
    6896,  6897,  6902
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
  const int xquery_parser::yylast_ = 16169;
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
#line 17361 "/home/markos/zorba/repo/gen-flwor-opt/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6906 "/home/markos/zorba/repo/gen-flwor-opt/src/compiler/parser/xquery_parser.y"


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

