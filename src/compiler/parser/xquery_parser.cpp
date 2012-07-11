
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
#line 87 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"


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
#line 79 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 902 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 317 of lalr1.cc  */
#line 1018 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_scanner.h"

#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc  */
#line 109 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"

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
#line 178 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
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
#line 900 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 285 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 124: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 899 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 294 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 149: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 898 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 303 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 312 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 321 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 330 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 339 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 348 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 357 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 366 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 375 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 384 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 393 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 402 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 411 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 420 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 429 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 438 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 447 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 456 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 465 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 474 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 483 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 492 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 501 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 510 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 519 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 528 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 537 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 546 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 555 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 564 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 573 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 582 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 591 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 600 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 609 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 618 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 627 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 636 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 645 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 654 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 663 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 672 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 681 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 690 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 699 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 708 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 717 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 726 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 735 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 744 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 753 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 762 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 771 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 780 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 789 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 798 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 825 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 834 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 843 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 861 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 870 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 897 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 906 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 915 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 933 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 942 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 951 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 960 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 969 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 978 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 987 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 996 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1005 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1014 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1023 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1032 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1041 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1050 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1059 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1068 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1077 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1086 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1095 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1104 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1113 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1122 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1131 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1140 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1149 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1158 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1167 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1176 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1185 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1194 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1203 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1212 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1221 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1230 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1239 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1248 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1257 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1266 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1275 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1284 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1293 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1302 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1311 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1320 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1329 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1338 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1347 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1356 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1365 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1374 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1383 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1392 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1401 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1410 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1419 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1428 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1437 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1446 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1455 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1464 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1473 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1482 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1491 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1500 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1509 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1518 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1527 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1536 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1545 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1554 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1563 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1572 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1581 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1590 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1599 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1608 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1617 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1626 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1635 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1644 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1653 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1662 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1671 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1680 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1689 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1698 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1707 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1716 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1725 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1734 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1743 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1752 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1761 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1770 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1779 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1788 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1797 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1806 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1815 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1824 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1833 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1842 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1851 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1860 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1869 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1878 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1887 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1896 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1905 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1914 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1923 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1932 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1941 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1950 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1959 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1968 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1977 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1986 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1995 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2004 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2013 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2022 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2031 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2040 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2049 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2058 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2067 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2076 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2085 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2094 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2103 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2112 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2121 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2130 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2139 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2148 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2157 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2166 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2175 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2184 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2193 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2202 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2211 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2220 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2229 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2238 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2247 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2256 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2265 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2274 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2283 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2292 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2301 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2310 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2319 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2328 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2337 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2346 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2355 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2364 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2373 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2382 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2391 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2400 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2409 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2418 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2427 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2436 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2445 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2454 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2463 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2472 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2481 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2490 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2499 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2508 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2517 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2526 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2535 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 610: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2544 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 611: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2553 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 612: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2562 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 616: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2571 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 619: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2580 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2589 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 624: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2598 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 625: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2607 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 626: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2616 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 627: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2625 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 628: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2634 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 629: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2643 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 630: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2652 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 631: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2661 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 632: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2670 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 633: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2679 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 634: /* "JSONSimpleObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2688 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 635: /* "JSONAccumulatorObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2697 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 636: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2706 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 637: /* "JSONPairList" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2715 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 638: /* "JSONInsertExpr" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2724 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 639: /* "JSONAppendExpr" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2733 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 640: /* "JSONDeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2742 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 641: /* "JSONRenameExpr" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2751 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 642: /* "JSONReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2760 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 649: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2769 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 650: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2778 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 651: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2787 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
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
#line 140 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 553 of lalr1.cc  */
#line 2872 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"

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
#line 1036 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 1045 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 1054 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 1060 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 1068 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 1074 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 1085 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 1090 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 1098 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1105 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1112 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1121 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1128 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1136 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1144 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1152 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1163 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1168 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1175 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 1182 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 1194 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 1204 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 1211 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 1218 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      // error
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 40:

/* Line 678 of lalr1.cc  */
#line 1253 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1258 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1266 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1274 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1282 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1287 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1295 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1300 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1308 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1313 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1321 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1328 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1335 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1342 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 1357 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1367 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 1372 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 1380 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1388 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1399 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1406 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1417 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1422 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1430 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1437 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1444 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1453 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(8) - (4)].sval)),
                            SYMTAB((yysemantic_stack_[(8) - (6)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
    }
    break;

  case 69:

/* Line 678 of lalr1.cc  */
#line 1466 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1474 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1481 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1491 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1498 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1505 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1528 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1534 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1543 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1550 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1560 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1569 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1570 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1571 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1572 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1573 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1574 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1575 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1576 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1577 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1578 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1584 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1592 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1600 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1608 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1615 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1623 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1630 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1635 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1643 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1651 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (2)].varnametype)));

      (yyval.node) = new VarDecl(LOC((yyloc)),
                       nt->theName,
                       nt->theType,
                       (yysemantic_stack_[(4) - (4)].expr),
                       nt->get_annotations(),
                       true,    // global
                       false);  // not external

      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 108:

/* Line 678 of lalr1.cc  */
#line 1666 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (2)].varnametype)));

      (yyval.node) = new VarDecl(LOC((yyloc)),
                       nt->theName,
                       nt->theType,
                       NULL,   // no init expr
                       nt->get_annotations(),
                       true,   // global
                       true);  // external

      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
    }
    break;

  case 109:

/* Line 678 of lalr1.cc  */
#line 1681 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(5) - (2)].varnametype)));

      (yyval.node) = new VarDecl(LOC((yyloc)),
                       nt->theName,
                       nt->theType,
                       (yysemantic_stack_[(5) - (5)].expr),     // init expr
                       nt->get_annotations(),
                       true,   // global
                       true);  // external

      dynamic_cast<VarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 110:

/* Line 678 of lalr1.cc  */
#line 1699 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1704 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1712 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1720 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1731 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1736 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1745 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1750 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1757 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1762 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1772 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1777 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1786 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1792 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1805 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1810 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1818 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 127:

/* Line 678 of lalr1.cc  */
#line 1829 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 128:

/* Line 678 of lalr1.cc  */
#line 1844 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 129:

/* Line 678 of lalr1.cc  */
#line 1856 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 130:

/* Line 678 of lalr1.cc  */
#line 1871 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1876 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1881 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1886 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1894 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1901 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1912 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1927 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL);
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1934 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1941 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0);
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1948 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1958 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1962 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1968 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1972 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));

    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1982 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                             (yysemantic_stack_[(8) - (6)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                             NULL);
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1990 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(9) - (4)].expr)),
                             (yysemantic_stack_[(9) - (7)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(9) - (9)].node)),
                             static_cast<AnnotationListParsenode*>((yysemantic_stack_[(9) - (2)].node)));
    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 2001 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 2007 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 2016 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 2021 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 2028 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 2035 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 2047 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 2057 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 156:

/* Line 678 of lalr1.cc  */
#line 2067 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 157:

/* Line 678 of lalr1.cc  */
#line 2078 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 158:

/* Line 678 of lalr1.cc  */
#line 2094 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 159:

/* Line 678 of lalr1.cc  */
#line 2114 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 2118 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 2122 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 2130 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 2134 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2138 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 2146 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 2151 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 167:

/* Line 678 of lalr1.cc  */
#line 2163 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 168:

/* Line 678 of lalr1.cc  */
#line 2170 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2199 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 182:

/* Line 678 of lalr1.cc  */
#line 2204 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 2212 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 184:

/* Line 678 of lalr1.cc  */
#line 2229 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 2237 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 2245 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 2252 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 188:

/* Line 678 of lalr1.cc  */
#line 2259 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 189:

/* Line 678 of lalr1.cc  */
#line 2269 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)),
                                NULL,  // no type
                                NULL,  // no init expr
                                NULL,  // no annotations
                                false, // not global
                                false);// not external
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 190:

/* Line 678 of lalr1.cc  */
#line 2281 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                                dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)), // type
                                NULL,  // no init expr
                                NULL,  // no annotations
                                false, // not global
                                false);// not external

      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 191:

/* Line 678 of lalr1.cc  */
#line 2294 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                NULL,  // no type
                                (yysemantic_stack_[(4) - (4)].expr),    // init expr
                                NULL,  // no annotations
                                false, // not global
                                false);// not external
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 2306 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarDecl* vd = new VarDecl(LOC((yyloc)),
                                static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)), // type
                                (yysemantic_stack_[(5) - (5)].expr),    // init expr
                                NULL,  // no annotations
                                false, // not global
                                false);// not external
      vd->set_global(false);
      (yyval.node) = vd;
    }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 2322 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 2330 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 195:

/* Line 678 of lalr1.cc  */
#line 2338 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 2346 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 197:

/* Line 678 of lalr1.cc  */
#line 2361 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 198:

/* Line 678 of lalr1.cc  */
#line 2366 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 199:

/* Line 678 of lalr1.cc  */
#line 2374 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 200:

/* Line 678 of lalr1.cc  */
#line 2388 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 201:

/* Line 678 of lalr1.cc  */
#line 2405 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 202:

/* Line 678 of lalr1.cc  */
#line 2430 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 2438 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 2445 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 2456 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 206:

/* Line 678 of lalr1.cc  */
#line 2466 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 207:

/* Line 678 of lalr1.cc  */
#line 2471 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 226:

/* Line 678 of lalr1.cc  */
#line 2516 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 227:

/* Line 678 of lalr1.cc  */
#line 2530 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 2538 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 2543 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 2551 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 2556 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 2561 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 2569 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)),
                            (yysemantic_stack_[(4) - (4)].expr),
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 234:

/* Line 678 of lalr1.cc  */
#line 2578 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            NULL,
                            (yysemantic_stack_[(3) - (3)].expr),
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 2590 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 236:

/* Line 678 of lalr1.cc  */
#line 2600 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 237:

/* Line 678 of lalr1.cc  */
#line 2613 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2637 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 2644 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2654 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2660 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected QName \""
          + static_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node))->operator[](0)->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      YYERROR;
    }
    break;

  case 250:

/* Line 678 of lalr1.cc  */
#line 2668 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL; // to prevent the Bison warning
      error((yylocation_stack_[(2) - (2)]), ""); // the error message is already set in the driver's parseError member
      YYERROR;
    }
    break;

  case 251:

/* Line 678 of lalr1.cc  */
#line 2678 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 252:

/* Line 678 of lalr1.cc  */
#line 2685 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 253:

/* Line 678 of lalr1.cc  */
#line 2693 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (3)]), "syntax error, unexpected QName \""
          + static_cast<VarInDecl*>((yysemantic_stack_[(3) - (3)].node))->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      YYERROR;
    }
    break;

  case 254:

/* Line 678 of lalr1.cc  */
#line 2704 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 255:

/* Line 678 of lalr1.cc  */
#line 2714 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 256:

/* Line 678 of lalr1.cc  */
#line 2724 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 257:

/* Line 678 of lalr1.cc  */
#line 2734 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 258:

/* Line 678 of lalr1.cc  */
#line 2744 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 259:

/* Line 678 of lalr1.cc  */
#line 2754 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 260:

/* Line 678 of lalr1.cc  */
#line 2764 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 261:

/* Line 678 of lalr1.cc  */
#line 2774 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 262:

/* Line 678 of lalr1.cc  */
#line 2785 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2794 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 264:

/* Line 678 of lalr1.cc  */
#line 2804 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 265:

/* Line 678 of lalr1.cc  */
#line 2814 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 266:

/* Line 678 of lalr1.cc  */
#line 2830 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2839 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2848 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2856 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2862 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2874 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 272:

/* Line 678 of lalr1.cc  */
#line 2882 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2892 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2900 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2912 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2918 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2931 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2935 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2943 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2947 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2956 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2960 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2964 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2974 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2982 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2989 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2995 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 3005 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 3009 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 3013 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         NULL);
    }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 3021 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(6) - (3)].node)),
                         (yysemantic_stack_[(6) - (5)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 3029 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         NULL,
                         (yysemantic_stack_[(5) - (4)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 3037 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         NULL,
                         NULL,
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 3049 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 3057 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 3063 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 3073 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 3079 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 3089 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3093 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3103 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3109 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3115 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3121 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3130 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3139 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3148 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3161 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3165 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3173 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3179 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3189 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3197 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3206 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3219 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3226 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3238 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3242 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3254 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3261 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3267 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3276 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3283 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3289 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3300 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3307 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3313 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3322 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3331 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3338 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3349 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3356 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3368 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3374 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3386 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3392 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3403 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3409 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3420 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3426 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3437 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3446 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 345:

/* Line 678 of lalr1.cc  */
#line 3450 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3459 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3463 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3471 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3475 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 350:

/* Line 678 of lalr1.cc  */
#line 3485 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3492 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3501 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3510 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3515 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3524 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3533 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3542 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3555 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3559 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3571 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3575 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3582 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3586 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3593 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3597 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3606 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3610 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3614 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3622 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3626 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3632 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3638 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3644 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3654 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3658 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3662 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3670 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3674 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3680 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3690 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3694 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3704 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3708 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3718 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3722 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3732 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3736 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3746 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3750 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3758 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3762 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3766 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3770 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3780 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3784 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3788 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3796 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3800 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3804 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3808 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3812 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3816 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3824 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3828 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3832 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3840 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3844 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3848 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3852 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3863 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3869 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3879 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3885 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3895 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3899 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3903 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3941 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 418:

/* Line 678 of lalr1.cc  */
#line 3945 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3955 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3965 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3978 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3987 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 423:

/* Line 678 of lalr1.cc  */
#line 3997 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 4001 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 4010 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 4014 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 4023 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 4029 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 4037 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 4043 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 4055 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 4061 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 4071 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 4075 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 4079 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 4083 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 4087 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4093 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4099 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4107 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4111 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4119 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4123 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4134 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4138 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4142 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4148 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4152 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4166 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4170 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4178 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4182 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4192 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4196 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4200 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4204 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4213 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4217 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4221 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4225 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4233 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4239 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4249 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4257 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4261 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4265 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4269 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4273 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4277 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4281 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4285 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4289 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4293 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4298 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4302 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4306 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4310 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4318 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4322 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4330 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4337 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4344 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4355 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4363 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4367 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4375 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4383 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4391 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4445 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4449 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4462 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4468 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4478 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 494:

/* Line 678 of lalr1.cc  */
#line 4482 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 495:

/* Line 678 of lalr1.cc  */
#line 4490 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4494 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4498 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4506 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 499:

/* Line 678 of lalr1.cc  */
#line 4516 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 500:

/* Line 678 of lalr1.cc  */
#line 4526 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 501:

/* Line 678 of lalr1.cc  */
#line 4543 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 502:

/* Line 678 of lalr1.cc  */
#line 4560 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 503:

/* Line 678 of lalr1.cc  */
#line 4577 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 504:

/* Line 678 of lalr1.cc  */
#line 4599 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 505:

/* Line 678 of lalr1.cc  */
#line 4605 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4616 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4622 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4633 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4650 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4655 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4664 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4668 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4675 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4681 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4687 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4695 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4707 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4711 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4718 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4724 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4730 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4737 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4748 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4752 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4762 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4766 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4776 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4780 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4784 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4789 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4798 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4804 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4810 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4816 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
        }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4824 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4829 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4837 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4842 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4850 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4858 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4863 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4868 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4873 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4878 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4883 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4892 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4900 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4904 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4921 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4925 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4933 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4941 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 4949 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 4953 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 4961 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 4967 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 4977 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 4985 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 4989 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 4993 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 5028 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 5034 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 5040 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 5050 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 5054 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 5058 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5062 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5066 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5070 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5074 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5081 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5087 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5097 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5105 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5109 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5113 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5117 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5121 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5125 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5129 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5133 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5137 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5145 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5153 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5157 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5161 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5171 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5179 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5187 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5191 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5195 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5203 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5207 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5213 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5219 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5223 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5233 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5241 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5245 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5251 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5260 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5269 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5275 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5281 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5291 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5308 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5315 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5330 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5366 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5370 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5378 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5386 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5398 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5402 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5410 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5418 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5422 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5433 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5450 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5456 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5462 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5472 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5476 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5482 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5488 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5492 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5498 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5502 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5508 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5514 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5521 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5531 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5536 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5544 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5550 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5560 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5582 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5591 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5597 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5610 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5624 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5631 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5637 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5647 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5656 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5664 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5670 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5688 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5696 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5700 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5707 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5712 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5720 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5724 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5731 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5735 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5742 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5746 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5753 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5757 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5766 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5778 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5782 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5789 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5793 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5801 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5809 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5817 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5821 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5828 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5832 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5840 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5851 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5855 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5863 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5875 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5881 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5890 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5894 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5902 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5906 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5910 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5917 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5921 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5928 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5932 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5940 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5944 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5948 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5952 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5956 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5964 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5972 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5984 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5996 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 6000 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 6004 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 6012 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 6018 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 6028 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 6032 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 6036 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 6040 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 6044 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 6048 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 6052 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 6056 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 6064 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 6068 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 6072 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 6076 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 6084 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 715:

/* Line 678 of lalr1.cc  */
#line 6090 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 716:

/* Line 678 of lalr1.cc  */
#line 6100 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 6110 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 6114 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 6122 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 720:

/* Line 678 of lalr1.cc  */
#line 6132 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 721:

/* Line 678 of lalr1.cc  */
#line 6143 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 6150 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 6154 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 6161 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 6165 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 6172 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 6177 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 6186 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 6195 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 6199 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 6206 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 6210 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 6218 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 6227 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 6234 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 6244 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 6248 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 6255 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 6261 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 6270 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 6274 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 6281 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 6286 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 6298 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 6306 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 6318 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 6326 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 6330 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 6338 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 6342 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 6346 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 6354 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 6362 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 6366 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 6370 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 6374 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 6382 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 6390 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 6402 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 6406 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 6414 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 6428 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 6432 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 6439 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 6444 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 6452 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 6457 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 6466 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 6474 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 6480 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 6490 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        static_cast<JSONPairList*>((yysemantic_stack_[(7) - (4)].node)),
                                        (yysemantic_stack_[(7) - (7)].expr));
        }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 6496 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 6503 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(7) - (4)].expr), (yysemantic_stack_[(7) - (7)].expr));
        }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 6510 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 775:

/* Line 678 of lalr1.cc  */
#line 6539 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 776:

/* Line 678 of lalr1.cc  */
#line 6568 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 777:

/* Line 678 of lalr1.cc  */
#line 6597 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 778:

/* Line 678 of lalr1.cc  */
#line 6601 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 779:

/* Line 678 of lalr1.cc  */
#line 6605 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 6612 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 781:

/* Line 678 of lalr1.cc  */
#line 6619 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 782:

/* Line 678 of lalr1.cc  */
#line 6626 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 6643 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 787:

/* Line 678 of lalr1.cc  */
#line 6656 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 6657 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 6658 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 6659 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 6660 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 6661 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 6662 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 6663 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 6664 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 6665 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 797:

/* Line 678 of lalr1.cc  */
#line 6666 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 6667 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 6668 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 6669 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 6670 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 6675 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 6676 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 6677 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 6678 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 6679 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 6680 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 6681 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 6682 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 6683 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 6684 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 6685 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 6686 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 6687 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 6688 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 6689 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 6690 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 6691 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 6692 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 6693 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 6694 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 6695 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 6696 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 6697 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 6698 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 6699 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 6700 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 6701 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 6702 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 6703 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 6704 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 6705 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 6706 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 6707 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 6708 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 6709 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 6710 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 6711 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 6712 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 6713 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 6714 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 6715 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 6716 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 6717 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 6718 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 6719 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 6720 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 6721 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 6722 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 6723 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 6724 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 6725 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 6726 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 6727 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 6728 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 6729 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 6730 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 6731 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 6732 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 6733 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 6734 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 6735 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 6736 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 6737 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 6738 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 6739 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 6740 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 6741 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 6742 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 6743 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6744 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6745 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6746 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6747 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6748 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6749 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6750 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 6751 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 6752 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 6753 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 6754 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 6755 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 6756 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 6757 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 6758 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 6759 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 6760 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 6761 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 6762 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 6763 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 6764 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 6765 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6766 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6767 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 6768 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 6769 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 898:

/* Line 678 of lalr1.cc  */
#line 6770 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 899:

/* Line 678 of lalr1.cc  */
#line 6771 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 900:

/* Line 678 of lalr1.cc  */
#line 6772 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 901:

/* Line 678 of lalr1.cc  */
#line 6773 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 902:

/* Line 678 of lalr1.cc  */
#line 6774 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 903:

/* Line 678 of lalr1.cc  */
#line 6775 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 904:

/* Line 678 of lalr1.cc  */
#line 6776 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 905:

/* Line 678 of lalr1.cc  */
#line 6777 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 906:

/* Line 678 of lalr1.cc  */
#line 6778 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 907:

/* Line 678 of lalr1.cc  */
#line 6779 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 908:

/* Line 678 of lalr1.cc  */
#line 6780 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 909:

/* Line 678 of lalr1.cc  */
#line 6781 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 910:

/* Line 678 of lalr1.cc  */
#line 6782 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 911:

/* Line 678 of lalr1.cc  */
#line 6783 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 912:

/* Line 678 of lalr1.cc  */
#line 6784 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 913:

/* Line 678 of lalr1.cc  */
#line 6785 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 914:

/* Line 678 of lalr1.cc  */
#line 6786 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 915:

/* Line 678 of lalr1.cc  */
#line 6787 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 916:

/* Line 678 of lalr1.cc  */
#line 6788 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 917:

/* Line 678 of lalr1.cc  */
#line 6789 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 918:

/* Line 678 of lalr1.cc  */
#line 6790 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 919:

/* Line 678 of lalr1.cc  */
#line 6791 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 920:

/* Line 678 of lalr1.cc  */
#line 6792 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 921:

/* Line 678 of lalr1.cc  */
#line 6793 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 922:

/* Line 678 of lalr1.cc  */
#line 6794 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 923:

/* Line 678 of lalr1.cc  */
#line 6795 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 924:

/* Line 678 of lalr1.cc  */
#line 6796 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 925:

/* Line 678 of lalr1.cc  */
#line 6797 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 926:

/* Line 678 of lalr1.cc  */
#line 6798 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 927:

/* Line 678 of lalr1.cc  */
#line 6799 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 928:

/* Line 678 of lalr1.cc  */
#line 6800 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 929:

/* Line 678 of lalr1.cc  */
#line 6801 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 930:

/* Line 678 of lalr1.cc  */
#line 6802 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 931:

/* Line 678 of lalr1.cc  */
#line 6803 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 932:

/* Line 678 of lalr1.cc  */
#line 6804 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 933:

/* Line 678 of lalr1.cc  */
#line 6805 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 934:

/* Line 678 of lalr1.cc  */
#line 6806 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 935:

/* Line 678 of lalr1.cc  */
#line 6807 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 936:

/* Line 678 of lalr1.cc  */
#line 6808 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 937:

/* Line 678 of lalr1.cc  */
#line 6809 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 938:

/* Line 678 of lalr1.cc  */
#line 6810 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 939:

/* Line 678 of lalr1.cc  */
#line 6811 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 940:

/* Line 678 of lalr1.cc  */
#line 6812 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 941:

/* Line 678 of lalr1.cc  */
#line 6813 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 942:

/* Line 678 of lalr1.cc  */
#line 6814 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 943:

/* Line 678 of lalr1.cc  */
#line 6815 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 944:

/* Line 678 of lalr1.cc  */
#line 6816 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 945:

/* Line 678 of lalr1.cc  */
#line 6817 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 946:

/* Line 678 of lalr1.cc  */
#line 6818 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 947:

/* Line 678 of lalr1.cc  */
#line 6819 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 948:

/* Line 678 of lalr1.cc  */
#line 6820 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 949:

/* Line 678 of lalr1.cc  */
#line 6821 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 950:

/* Line 678 of lalr1.cc  */
#line 6822 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 951:

/* Line 678 of lalr1.cc  */
#line 6823 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 952:

/* Line 678 of lalr1.cc  */
#line 6824 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 953:

/* Line 678 of lalr1.cc  */
#line 6825 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 954:

/* Line 678 of lalr1.cc  */
#line 6826 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 955:

/* Line 678 of lalr1.cc  */
#line 6827 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 956:

/* Line 678 of lalr1.cc  */
#line 6828 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 957:

/* Line 678 of lalr1.cc  */
#line 6829 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 958:

/* Line 678 of lalr1.cc  */
#line 6830 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 959:

/* Line 678 of lalr1.cc  */
#line 6831 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 960:

/* Line 678 of lalr1.cc  */
#line 6832 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 961:

/* Line 678 of lalr1.cc  */
#line 6833 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 962:

/* Line 678 of lalr1.cc  */
#line 6834 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 963:

/* Line 678 of lalr1.cc  */
#line 6835 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 964:

/* Line 678 of lalr1.cc  */
#line 6836 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 965:

/* Line 678 of lalr1.cc  */
#line 6837 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 966:

/* Line 678 of lalr1.cc  */
#line 6838 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 967:

/* Line 678 of lalr1.cc  */
#line 6839 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 968:

/* Line 678 of lalr1.cc  */
#line 6840 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 969:

/* Line 678 of lalr1.cc  */
#line 6841 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 970:

/* Line 678 of lalr1.cc  */
#line 6842 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 971:

/* Line 678 of lalr1.cc  */
#line 6843 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 972:

/* Line 678 of lalr1.cc  */
#line 6844 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 973:

/* Line 678 of lalr1.cc  */
#line 6845 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 974:

/* Line 678 of lalr1.cc  */
#line 6846 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 975:

/* Line 678 of lalr1.cc  */
#line 6847 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 976:

/* Line 678 of lalr1.cc  */
#line 6848 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 977:

/* Line 678 of lalr1.cc  */
#line 6849 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 978:

/* Line 678 of lalr1.cc  */
#line 6850 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 979:

/* Line 678 of lalr1.cc  */
#line 6851 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 980:

/* Line 678 of lalr1.cc  */
#line 6852 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 981:

/* Line 678 of lalr1.cc  */
#line 6853 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 982:

/* Line 678 of lalr1.cc  */
#line 6854 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 983:

/* Line 678 of lalr1.cc  */
#line 6855 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 984:

/* Line 678 of lalr1.cc  */
#line 6856 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 985:

/* Line 678 of lalr1.cc  */
#line 6857 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 986:

/* Line 678 of lalr1.cc  */
#line 6858 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 987:

/* Line 678 of lalr1.cc  */
#line 6859 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 988:

/* Line 678 of lalr1.cc  */
#line 6860 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 989:

/* Line 678 of lalr1.cc  */
#line 6861 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 990:

/* Line 678 of lalr1.cc  */
#line 6862 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 991:

/* Line 678 of lalr1.cc  */
#line 6863 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 992:

/* Line 678 of lalr1.cc  */
#line 6864 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 993:

/* Line 678 of lalr1.cc  */
#line 6865 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 994:

/* Line 678 of lalr1.cc  */
#line 6866 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 995:

/* Line 678 of lalr1.cc  */
#line 6867 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 996:

/* Line 678 of lalr1.cc  */
#line 6868 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 997:

/* Line 678 of lalr1.cc  */
#line 6869 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 998:

/* Line 678 of lalr1.cc  */
#line 6870 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 999:

/* Line 678 of lalr1.cc  */
#line 6871 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1000:

/* Line 678 of lalr1.cc  */
#line 6872 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1001:

/* Line 678 of lalr1.cc  */
#line 6873 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 1002:

/* Line 678 of lalr1.cc  */
#line 6874 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 1003:

/* Line 678 of lalr1.cc  */
#line 6875 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1004:

/* Line 678 of lalr1.cc  */
#line 6876 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 1005:

/* Line 678 of lalr1.cc  */
#line 6877 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 1006:

/* Line 678 of lalr1.cc  */
#line 6878 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 1007:

/* Line 678 of lalr1.cc  */
#line 6879 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 1008:

/* Line 678 of lalr1.cc  */
#line 6884 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 678 of lalr1.cc  */
#line 12120 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1484;
  const short int
  xquery_parser::yypact_[] =
  {
      3397, -1484, -1484, -1484,  4943,  4943,  4943, -1484, -1484,    47,
     250, -1484,   109,   218, -1484, -1484, -1484,   662, -1484, -1484,
   -1484,   288,   319,   730,  3117,   491,   529,   713, -1484,   -27,
   -1484, -1484, -1484, -1484, -1484, -1484,   741, -1484,   549,   630,
   -1484, -1484, -1484, -1484,   438, -1484,   748, -1484,   700,   736,
   -1484,    94, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484,   629,   747, -1484, -1484,
   -1484, -1484,    38, 11123, -1484, -1484, -1484,   776, -1484, -1484,
   -1484,   790, -1484,   789,   808, -1484, -1484, 15495, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484,   814, -1484, -1484,   820,
     824, -1484, -1484, -1484, -1484, -1484, -1484, -1484,  3707,  6797,
    7106, 15495, -1484, -1484, -1484, -1484, -1484, -1484, -1484,   794,
   -1484, -1484,   826, 12015, -1484, 12317,   827,   828, -1484, -1484,
   -1484,   829, -1484, 10505, -1484, -1484, -1484, -1484, -1484, -1484,
     799, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,    69,
     743, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,   -85,
     803,   -73, -1484,   -90,   -86, -1484, -1484, -1484, -1484, -1484,
   -1484,   843, -1484,   722,   723,   724, -1484, -1484,   810,   815,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484,  7415,  7724, -1484,   654, -1484, -1484, -1484,
   -1484, -1484,  5252,   970, -1484,  5561, -1484, -1484,   407,    80,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484,    97, -1484, -1484, -1484, -1484, -1484,
   -1484,   355, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
    4943, -1484, -1484, -1484, -1484,   214, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484,   865, -1484,   783, -1484, -1484, -1484,
     555, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,   807,
     884, -1484,   984,   729,   879,   578,   509,   440,   215, -1484,
     929,   782,   881,   885,  8960, -1484, -1484, -1484,    10, -1484,
   -1484, 10814, -1484,   651, -1484,   834, 11123, -1484,   834, 11123,
   -1484, -1484, -1484,   698, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484,   844,   835, -1484, -1484, -1484,
   -1484, -1484,   813, -1484,  4943,   816,   817,   334,   334,   965,
     175,   624,   518, 15782, 15495,    -2,   951, 15495,   847,   886,
     292, 12015,   685,   757, 15495, 15495,   702,   608,    59, -1484,
   -1484, -1484, 12015,  4943,   823,  4943,    50,  9269, 13199, 15495,
   -1484,   720,   728, 15495,   889,    27,   856,  9269,  1012,    90,
      89, 15495,   896,   873,   909, -1484,  9269, 11719, 15495, 15495,
   15495,  4943,   831,  9269,  9269, 15495,  4943,   866,   868, -1484,
   -1484, -1484,  9269, 13486,   867, -1484,   869, -1484, -1484, -1484,
   -1484,   871, -1484,   875, -1484, -1484, -1484, -1484, -1484,   876,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, 15495, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484,   880, 15495, -1484, -1484, -1484,   840,  4016,   908,   301,
     882,   887,   888, 15495,  4943, -1484,   883,   132, -1484,   689,
   -1484,    21,  1000,  9269, -1484, -1484,    82, -1484, -1484, -1484,
    1025, -1484, -1484, -1484, -1484,  9269,   832, -1484,  1017,  9269,
    9269, 12616,   862,  9269,  9269,  9578,  9269, 12616,  9269,   821,
     825, 15495,   860,   863,  9269,  9269,  3707,   811, -1484,   -34,
   -1484,   -32,   898, -1484, -1484, -1484, -1484,   109,   713,    99,
     110,  1054,  5870,  5870,  6179,  6179,   790, -1484, -1484,   865,
     790, -1484,  9269, -1484,   940,   371,   -27,   893,   892,   894,
    4943,  9269, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
    9887,  9887,  9887, -1484,  9887,  9887, -1484,  9887, -1484,  9887,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484,  9887,  9887,   993,
    9887,  9887,  9887,  9887,  9887,  9887,  9887,  9887,  9887,  9887,
    9887,  9887,   845,   971,   979,   982, -1484, -1484, -1484,  8033,
   -1484, -1484, 10505, 10505,  9269,   834, -1484, -1484,   834, -1484,
    8342,   834,   930,  8651, -1484, -1484, -1484,    23, -1484,   205,
   -1484, -1484, -1484, -1484, -1484, -1484,   973,   974,   491,  1049,
   -1484, -1484, 15782,  1084,   570, 15495,   922,   923,  1084,   965,
     957,   953, -1484, -1484, -1484,   310,   848,   995,   792, 15495,
     950,  9269,   977, 15495, 15495, -1484,   964,   915,  4943, -1484,
     916,   869,   630, -1484,   911,   917,   306, -1484,   222,   225,
     998, -1484,    31, -1484, -1484,   998, 15495,    28, 15495,  1013,
     261, -1484,  4943, -1484,   268, -1484, 12015,  1016,  1068, 12015,
     965,  1018,   576, 15495,  9269,   -27,   332,   931, -1484,   932,
     934,   936,     2, -1484,   580,   933, -1484,   270,   281,   976,
   -1484,   946,  4943,  4943,   400, -1484,   282,   283,   587,  9269,
      48, -1484, -1484,  9269,  9269, -1484,  9269,  9269,  9269, -1484,
    9269, -1484,  9269, -1484, 15495,  1000, -1484,    46,   405, -1484,
   -1484, -1484,   461, -1484,   468, -1484, -1484,   978,   980,   981,
     983,   985,   698,   844, -1484,   183,   201,  4943,   900,  1043,
     515,   904,   918,   913,    -4, -1484,  1002, -1484, -1484,   955,
     286,  4325,   469, 11423,   811, -1484, -1484, -1484,  9269,   407,
     761,  1115,  1115, -1484, -1484,   116, -1484, -1484,   119, -1484,
     105, -1484, -1484, -1484, -1484, -1484, -1484, -1484, 15495,   987,
    9269,  1031, -1484, -1484, -1484,   884, -1484, -1484, -1484, -1484,
   -1484,  9887, -1484, -1484, -1484,    85, -1484,   509,   509,   191,
     440,   440,   440,   440,   215,   215, -1484, -1484, 14634, 14634,
   15495, 15495, -1484,   470, -1484, -1484,   217, -1484, -1484, -1484,
     309, -1484, -1484,   316,   334, -1484, -1484,   613,   615,   659,
   -1484,   491, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484,  1084, -1484,  1019, 14921,  1008,  9269, -1484, -1484,
   -1484,  1058,   965,   965,  1084, -1484,   774,   965,   507, 15495,
     561,   585,  1124, -1484, -1484,   870,   548, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,   310,    43,
     928,   542,  9269, -1484, 15495,  1064,   861,   965, -1484, -1484,
   -1484, -1484,  1007, 15495, -1484, 15495, -1484, 15208,  1034, 14634,
    1044,  9269,   -37,  1027,    33,   581,   924, -1484, -1484,   634,
      28,  1058, 14634,  1057,  1082,   996,   997,  1047,   965,  1021,
    1050,  1088,   965,  9269,   -41, -1484, -1484, -1484,  1039, -1484,
   -1484, -1484, -1484,  1075,  9269,  9269,  1048, -1484,  1096,  1097,
    4943, -1484,  1014,  1015,  1051, 15495, -1484, 15495, -1484,  9269,
    1059,  1010,  9269, -1484,  1081,   321,   374,   387,  1168, -1484,
     455, -1484,   223, -1484, -1484,  1176, -1484,   632,  9269,  9269,
    9269,   657,  9269,  9269,  9269,   473,  9269,  9269,  9269,  9269,
    9269, 12616,  1089,  9269,  9269, -1484,  6488,  1052,  1053,  1055,
    1060,   783,   822,   966, -1484,   342, -1484,   249,   123,   595,
     105,  6179,  6179,  6179,  1133, -1484,  9269,   583,  1107, -1484,
   15495,  1108, -1484, -1484,  9269,    85,   524,   591, -1484,   935,
      79,   960,   959, -1484, -1484,   757, -1484,   954,   510,  1066,
    1067, 14921,  1069,  1070,  1071,  1072,  1073, -1484,   539, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484,  1086, -1484, -1484, -1484,  9269, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484,   660, -1484,  1202,   745,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,   947,
   -1484, -1484,  1204, -1484, -1484, -1484, -1484, -1484,   550,  1205,
   -1484,   668, -1484, -1484, -1484,   867,   319,   871,   549,   875,
     876,   803,  1070,  1071,  1072, -1484,   539,   539, 10196,   949,
     937, -1484,  1058,    43,  1011,  1046,  4943,  1056,  1061,  1094,
    1062,  1063, 15495, -1484,    58, -1484, 15495, -1484,  9269,  1092,
    9269,  1113,  9269,    30,  1099,  9269,  1100, -1484,  1123,  1126,
    9269, 15495,   809,  1174, -1484, -1484, -1484, -1484, -1484, -1484,
   14634, -1484,  4943,   965,  1146, -1484, -1484, -1484,   965,  1146,
   -1484,  9269,  1112,  4943, 15495, -1484, -1484,  9269,  9269,   707,
   -1484,    15,   711, -1484, 13773,   716, -1484,   717, -1484,  1074,
   -1484, -1484,  4943,  1077,  1078, -1484,  9269, -1484, -1484,  9269,
    1065,  1096,  1156, -1484,  1125, -1484,   818, -1484, -1484,  1252,
   -1484, -1484,  4943, 15495, -1484,   903, -1484, -1484, -1484,  1076,
    1029,  1035, -1484, -1484, -1484,  1038,  1040, -1484, -1484, -1484,
    1041,  1178, -1484, -1484, -1484,  1042,   -12, 15495,  1090, -1484,
   -1484,  9269,  9269,  9269,  4634,  6488, 11423,   966, -1484, 11423,
   -1484,  1079,  1115,   380, -1484, -1484, -1484,  1107, -1484,   965,
   -1484,   786, -1484,    62,  1169, -1484,  9269,   627,  1031,   495,
    1093, -1484,    85,  1030, -1484, -1484,   -47, -1484,   579,    63,
    1032,    85,   579,  9887, -1484,   178, -1484, -1484, -1484, -1484,
   -1484, -1484,    85,  1136,  1003,   848,    63, -1484, -1484,  1001,
    1207, -1484, -1484, -1484, 12912,  1101,  1102,  1104,  1109,  1111,
    1116,  1119, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484,  1265,   443,  1266,   443,  1045,  1192,
   -1484, -1484,  1130, 15495,  1080, -1484, -1484, 10196, -1484,  1129,
   -1484, -1484, -1484, -1484, -1484, -1484,  9269,  1161, -1484, -1484,
    9269, -1484,    68, -1484,  9269,  1162,  9269, -1484,  9269, 15495,
   15495, -1484,   681, -1484,  9269, -1484,  1188,  1191,  1222,   965,
    1146, -1484,  9269,  1135, -1484, -1484, -1484,  1134, -1484,    57,
    9269,  4943,  1141,   172, -1484, 15495,  1142, 14060,   341, -1484,
   14347,  1143, -1484, -1484,  1137, -1484, -1484, -1484, -1484,  9269,
     725,  1168, 15495,   914, -1484,  1138,  1168, 15495, -1484, -1484,
    9269,  9269,  9269,  9269,  9269,  1022,  9269,  9269, -1484,  9269,
     391,   394,   406,   463, -1484, -1484,  9269, -1484, -1484, -1484,
    1169, -1484, -1484, -1484,   965,  9269, -1484,  1190, -1484, -1484,
   -1484, -1484,  1154,  9887, -1484, -1484, -1484, -1484, -1484,   553,
    9887,  9887,   520, -1484,   960, -1484,   229, -1484,   959,    85,
    1177, -1484, -1484,  1083, -1484, -1484, -1484, -1484,  1246,  1157,
   -1484,   408, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
     240,   240, -1484,   443, -1484, -1484,   450, -1484,  1312,    63,
    1249,  1159, 10196,   -52,  1085,  1180, -1484, -1484,  9269, -1484,
    9269,  1200, -1484,  9269, -1484, -1484, -1484,  1295, -1484, -1484,
    6488,  9269,   965, -1484, -1484, -1484,  9269,  9269, -1484, -1484,
   -1484,  6488,  6488,  1258,  4943, 15495,  1167, 15495,  9269, 15495,
    1170,  6488, -1484,   464,    14,  1168, 15495, -1484,  1158,  1168,
   -1484, -1484, -1484, -1484, -1484,  9269, -1484, -1484, -1484,  1160,
    1096,  1097,  9269, -1484, -1484, -1484, -1484,  1253,  9269, -1484,
     440,  9887,  9887,   191,   584, -1484, -1484, -1484, -1484, -1484,
   -1484,  9269, -1484, 14634, -1484, 14634,  1261, -1484, -1484, -1484,
    1329, -1484, -1484, -1484,  1103,  1254, -1484, -1484,  1257, -1484,
      87, 15495,  1242,  1144, 15495, 10196, -1484, -1484,  9269, -1484,
    1247, -1484, -1484,  1146, -1484, -1484, 14634, -1484, -1484,  1272,
    9269,  1183, -1484,  1278,  6488, -1484, 15495,   202,   313, -1484,
    1179,  1168, -1484,  1181, -1484,  6488,   726,   511, -1484,  1253,
     191,   191,  9887,   512, -1484, -1484, 14634, -1484, -1484,  1249,
   10196, -1484,  1169,  1087, 15495,  1255,  1150,  1257, -1484, 15495,
    1193, 14634,  4943, 14634,  1194, -1484, -1484,  1283,   329, -1484,
   -1484, -1484, -1484,  1198,   563, -1484, -1484, -1484,  1186, -1484,
    1267, -1484, -1484,   191, -1484, -1484, -1484, -1484, -1484,  9269,
    1095, 15495,  1268, -1484,  4943,  1197, -1484, -1484,  1201,  9269,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, 15495, -1484,  1106,
    1105, 15495, -1484, -1484,  9269,  6488,  1203,  1098,  9269,  1110,
    6488, 10196, -1484, 10196, -1484,  1195,  1114, 15495,  1164,  1274,
   15495,  1117, 10196, -1484
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       161,   454,   455,   456,   164,   164,   164,   803,  1008,   116,
     118,   610,   895,   904,   844,   808,   806,   788,   896,   899,
     851,   812,   789,   790,     0,   905,   792,   902,   873,   853,
     828,   848,   849,   900,   897,   847,   794,   903,   795,   796,
     944,   956,   943,   845,   864,   858,   797,   846,   799,   798,
     945,   882,   883,   850,   825,   966,   967,   968,   969,   970,
     971,   972,   973,   974,   975,   976,   990,   997,   872,   868,
     859,   839,   787,     0,   867,   875,   884,   991,   863,   480,
     840,   841,   898,   992,   998,   860,   877,     0,   486,   443,
     482,   870,   805,   861,   862,   891,   865,   881,   890,   996,
     999,   811,   852,   893,   481,   880,   886,   791,     0,     0,
       0,     0,   391,   878,   889,   894,   892,   871,   857,   946,
     855,   856,   993,     0,   390,     0,   994,  1000,   887,   842,
     866,   995,   421,     0,   453,   888,   869,   876,   885,   879,
     947,   833,   838,   837,   836,   835,   834,   800,   854,     0,
     804,   901,   826,   935,   934,   936,   810,   809,   829,   941,
     793,   933,   938,   939,   930,   832,   874,   932,   942,   940,
     931,   830,   937,   951,   952,   949,   950,   948,   801,   953,
     954,   955,   921,   920,   907,   824,   817,   914,   910,   827,
     823,   922,   923,   813,   814,   807,   816,   919,   918,   915,
     911,   928,   929,   927,   917,   913,   906,   815,   926,   925,
     819,   821,   820,   912,   916,   908,   822,   909,   818,   924,
     977,   978,   979,   980,   981,   982,   958,   959,   957,   963,
     964,   965,   960,   961,   962,   831,   983,   984,   985,   986,
     987,   988,   989,     0,     0,  1001,  1002,  1003,  1006,  1005,
    1004,  1007,   161,     0,     2,   161,     5,     7,    19,     0,
      24,    27,    32,    33,    34,    35,    36,    37,    38,    28,
      54,    55,    29,    30,     0,    72,    75,    76,    31,    77,
      78,     0,   114,    79,    80,    81,    82,    14,   158,   159,
     160,   167,   169,   473,   170,     0,   171,   172,   173,   174,
     175,   176,   177,   180,   165,   206,   213,   208,   240,   246,
       0,   238,   239,   215,   209,   179,   210,   178,   211,   214,
     344,   346,   348,   358,   360,   364,   366,   369,   374,   377,
     380,   382,   384,   386,     0,   388,   394,   396,     0,   412,
     395,   417,   420,   422,   425,   427,     0,   432,   429,     0,
     440,   450,   452,   426,   457,   464,   478,   465,   466,   467,
     470,   471,   468,   469,   493,   495,   496,   497,   494,   542,
     543,   544,   545,   546,   547,   449,   584,   576,   583,   582,
     581,   578,   580,   577,   579,   479,   472,   611,   612,    39,
     216,   217,   219,   218,   220,   212,   475,   476,   477,   474,
     222,   225,   221,   223,   224,   451,   786,   802,   895,   904,
     902,   804,     0,   162,   163,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   122,
     124,   125,     0,     0,     0,     0,     0,     0,     0,     0,
     250,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   268,   269,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   445,
     448,   435,     0,     0,   788,   812,   790,   843,   905,   792,
     853,   794,   864,   797,   799,   798,   882,   990,   997,   787,
     991,   841,   992,   998,   865,   996,   999,   946,   993,   994,
    1000,   995,   947,   941,   933,   939,   930,   830,   951,   952,
     949,   801,   953,  1002,   441,   451,   786,   433,     0,   187,
     434,   437,   788,   789,   790,   794,   795,   796,   797,   787,
     793,   483,     0,   439,   438,   182,     0,     0,   206,     0,
     792,   799,   798,     0,   164,   762,   953,     0,   213,     0,
     484,     0,   509,     0,   444,   784,     0,   785,   415,   416,
       0,   447,   446,   436,   419,     0,     0,   538,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   764,     0,
     766,     0,     0,     3,     1,     6,     8,     0,     0,     0,
       0,     0,   161,   161,   161,   161,     0,   115,   168,   166,
       0,   185,     0,   194,     0,     0,     0,     0,     0,     0,
       0,     0,   199,   226,   245,   241,   247,   242,   244,   243,
       0,     0,     0,   405,     0,     0,   403,     0,   353,     0,
     404,   397,   402,   401,   400,   399,   398,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   393,   392,   389,     0,
     413,   418,     0,     0,     0,   428,   461,   431,   430,   442,
       0,   458,     0,     0,   549,   551,   555,     0,   120,     0,
     783,    43,    40,    41,    44,    45,     0,     0,     0,     0,
      46,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   621,   622,   623,     0,    99,   138,     0,     0,
     108,     0,     0,     0,     0,   123,     0,     0,     0,   590,
       0,     0,     0,   586,     0,     0,     0,   600,     0,     0,
     249,   251,     0,   228,   229,   248,     0,     0,     0,   130,
       0,   134,   164,   614,     0,    56,     0,    65,     0,     0,
       0,    57,     0,     0,     0,     0,     0,     0,   591,     0,
       0,     0,     0,   317,     0,     0,   589,     0,     0,     0,
     608,     0,     0,     0,     0,   594,     0,     0,   189,     0,
       0,   183,   181,     0,     0,   768,     0,     0,     0,   483,
       0,   763,     0,   485,   510,   509,   506,     0,     0,   540,
     539,   414,     0,   537,     0,   634,   635,   788,   790,   794,
     797,   787,   774,     0,   585,     0,     0,   164,     0,     0,
       0,     0,     0,     0,     0,   640,     0,   197,   198,     0,
       0,     0,     0,     0,   202,   203,   765,   767,     0,    20,
       0,    21,     0,     4,    25,     0,    11,    26,     0,    15,
     895,    73,    12,    74,    16,   188,   186,   207,     0,     0,
       0,     0,   200,   227,   286,   345,   347,   351,   357,   356,
     355,     0,   352,   349,   350,     0,   361,   368,   367,   365,
     371,   372,   373,   370,   375,   376,   379,   378,     0,     0,
       0,     0,   410,     0,   423,   424,     0,   462,   459,   491,
       0,   613,   489,     0,     0,   117,   119,     0,     0,     0,
      98,     0,    88,    90,    91,    92,    93,    95,    96,    97,
      89,    94,    84,    85,     0,     0,   104,     0,   100,   102,
     103,   110,     0,     0,    83,    42,     0,     0,     0,     0,
       0,     0,     0,   712,   717,     0,     0,   713,   747,   700,
     702,   703,   704,   706,   708,   707,   705,   709,     0,     0,
       0,     0,     0,   107,     0,   140,     0,     0,   554,   548,
     587,   588,     0,     0,   604,     0,   601,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   230,   231,     0,
     236,   136,     0,     0,   131,     0,     0,     0,     0,     0,
       0,    58,     0,     0,     0,   267,   273,   270,     0,   593,
     592,   599,   607,     0,     0,     0,     0,   553,     0,     0,
       0,   406,     0,     0,     0,     0,   597,     0,   595,     0,
     190,     0,     0,   769,     0,     0,     0,     0,   509,   507,
       0,   498,     0,   487,   488,     0,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   195,     0,   792,   799,   798,
     953,     0,     0,     0,   648,     0,   204,     0,     0,     0,
       0,   161,   161,   161,     0,   237,     0,   301,   297,   299,
       0,   287,   288,   354,     0,     0,     0,     0,   678,   362,
     651,   655,   657,   659,   661,   664,   671,   672,   680,   905,
     791,     0,   800,  1006,  1005,  1004,  1007,   381,   560,   566,
     567,   570,   615,   616,   571,   572,   777,   778,   779,   575,
     383,   385,   557,   387,   411,   463,     0,   460,   490,   121,
      52,    53,    50,    51,   127,   126,     0,    86,     0,     0,
     105,   106,   111,    70,    71,    48,    49,    69,   718,     0,
     721,   748,     0,   711,   710,   715,   714,   746,     0,     0,
     723,     0,   719,   722,   701,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   139,   142,   144,     0,     0,
       0,   109,   112,     0,     0,     0,   164,     0,     0,   608,
       0,     0,     0,   253,     0,   559,     0,   254,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   232,     0,     0,
       0,     0,   280,     0,   277,   282,   235,   137,   132,   135,
       0,   184,     0,     0,    67,    61,    64,    63,     0,    59,
     271,     0,     0,   164,     0,   315,   319,     0,     0,     0,
     322,     0,     0,   328,     0,     0,   335,     0,   339,     0,
     408,   407,   164,     0,     0,   191,     0,   193,   316,     0,
       0,     0,     0,   510,     0,   499,     0,   533,   530,     0,
     534,   535,     0,     0,   529,     0,   504,   532,   531,     0,
       0,     0,   627,   628,   624,     0,     0,   632,   633,   629,
     768,     0,   638,   775,   636,     0,     0,     0,     0,   642,
     196,     0,     0,     0,     0,     0,     0,   643,   644,     0,
     205,     0,    22,     0,    13,    17,    18,   298,   310,     0,
     311,     0,   302,   303,   304,   305,     0,   290,     0,     0,
       0,   662,   675,     0,   359,   363,     0,   694,     0,     0,
       0,     0,     0,     0,   650,   652,   653,   689,   690,   691,
     693,   692,     0,     0,   666,   665,     0,   669,   673,   687,
     685,   684,   677,   681,     0,     0,     0,     0,     0,     0,
       0,     0,   563,   565,   564,   561,   558,   492,   129,   128,
      87,   101,   735,   716,     0,   740,     0,   740,   729,   724,
     143,   145,     0,     0,     0,   113,   141,     0,    23,     0,
     605,   606,   609,   602,   603,   252,     0,     0,   266,   258,
       0,   262,     0,   256,     0,     0,     0,   275,     0,     0,
       0,   234,   278,   281,     0,   133,     0,     0,    66,     0,
      60,   272,     0,     0,   318,   320,   325,     0,   323,     0,
       0,     0,     0,     0,   329,     0,     0,     0,     0,   336,
       0,     0,   340,   409,     0,   598,   596,   192,   770,     0,
       0,   509,     0,     0,   541,     0,   509,     0,   505,    10,
       0,     0,     0,     0,     0,     0,     0,     0,   641,     0,
       0,     0,     0,     0,   645,   649,     0,   314,   312,   313,
     306,   307,   308,   300,     0,     0,   295,     0,   289,   679,
     670,   676,     0,     0,   749,   750,   760,   759,   758,     0,
       0,     0,     0,   751,   656,   757,     0,   654,   658,     0,
       0,   663,   667,     0,   688,   683,   686,   682,     0,     0,
     573,     0,   568,   620,   562,   781,   782,   780,   569,   736,
       0,     0,   734,   741,   742,   738,     0,   733,     0,   731,
       0,     0,     0,     0,     0,     0,   550,   255,     0,   264,
       0,     0,   260,     0,   263,   276,   284,   285,   279,   233,
       0,     0,     0,    62,   274,   556,     0,     0,   326,   330,
     324,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   552,     0,     0,   509,     0,   536,     0,   509,
     625,   626,   630,   631,   771,     0,   637,   776,   639,     0,
       0,     0,     0,   646,   773,   309,   296,   291,     0,   674,
     761,     0,     0,   753,     0,   699,   698,   697,   696,   695,
     660,     0,   752,     0,   617,     0,     0,   745,   744,   743,
       0,   737,   730,   728,     0,   725,   726,   720,   146,   148,
     150,     0,     0,     0,     0,     0,   259,   257,     0,   265,
       0,   201,   343,    68,   321,   327,     0,   341,   337,     0,
       0,     0,   331,     0,     0,   333,     0,   519,   513,   508,
       0,   509,   500,     0,   772,     0,     0,     0,   294,   292,
     755,   754,     0,     0,   618,   574,     0,   739,   732,     0,
       0,   152,   151,     0,     0,     0,     0,   147,   261,     0,
       0,     0,     0,     0,     0,   527,   521,     0,   520,   522,
     528,   525,   515,     0,   514,   516,   526,   502,     0,   501,
       0,   647,   293,   756,   668,   619,   727,   149,   153,     0,
       0,     0,     0,   283,     0,     0,   334,   332,     0,     0,
     512,   523,   524,   511,   517,   518,   503,     0,   154,     0,
       0,     0,   342,   338,     0,     0,     0,     0,     0,     0,
       0,     0,   156,     0,   155,     0,     0,     0,     0,     0,
       0,     0,     0,   157
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1484, -1484,  -236,  1132, -1484,  1139,  1149, -1484,  1147,  -549,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1002, -1484, -1484, -1484, -1484,  -228,  -583, -1484,   683,  -167,
   -1484, -1484, -1484, -1484, -1484,   237,   462, -1484, -1484,    -9,
    -185,   989, -1484,   972, -1484, -1484,  -647, -1484,   399, -1484,
     200, -1484,  -268,  -312, -1484,  -536, -1484,     5,    88,    29,
    -288,  -161, -1484,  -873, -1484, -1484,   133, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484,   565,    64,  1458,
       0, -1484, -1484, -1484, -1484,   410, -1484, -1484,  -293, -1484,
       8, -1484,   968,  -923,  -733,  -708, -1484, -1484,   648, -1484,
   -1484,   -28,   184, -1484, -1484, -1484,    67, -1227, -1484,   322,
      73, -1484, -1484,    77, -1301, -1484,   890,   167, -1484, -1484,
     164,  -999, -1484, -1484,   162, -1484, -1484, -1247, -1239, -1484,
     158, -1484, -1484,   796,   797, -1484,  -587,   777, -1484, -1484,
    -656,   255,  -638,   251,   256, -1484, -1484, -1484, -1484, -1484,
    1118, -1484, -1484, -1484, -1484,  -830,  -314, -1136, -1484,  -112,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484,   -26,  -810, -1484,
    -541,  -163,   208, -1484,  -402, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484,   746, -1484, -1013, -1484,   144, -1484,   626,  -793,
   -1484, -1484, -1484, -1484, -1484,  -311,  -306, -1225,  -983, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,   533,
    -747,  -786,  -271,  -856, -1484,    34,  -787, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484,   999,  1004,  -273,   451,   279, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
   -1484, -1484, -1484,   121, -1484, -1484,   112, -1484,   115, -1065,
   -1484, -1484, -1484,    84,    71,   -93,   343, -1484, -1484, -1484,
   -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484, -1484,
      83, -1484, -1484, -1484,   -89,   335,   483, -1484, -1484, -1484,
   -1484, -1484,   271, -1484, -1484, -1483, -1484, -1484, -1484,  -633,
   -1484,    49, -1484,  -110, -1484, -1484, -1484, -1484, -1318, -1484,
      92, -1484, -1484, -1484, -1484, -1484,   628, -1484, -1484, -1484,
   -1484, -1484,  -925, -1484, -1484, -1484,  -418,  -383,    75,  1182,
   -1484
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   253,   862,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
    1254,   770,   271,   272,   273,   274,   275,   276,   942,   943,
     944,   277,   278,   279,   948,   949,   950,   280,   437,   281,
     282,   697,   283,   439,   440,   441,   456,   760,   761,   284,
    1205,   285,  1678,  1679,   286,   287,   288,   546,   289,   290,
     291,   292,   293,   763,   294,   295,   529,   296,   297,   298,
     299,   300,   301,   632,   302,   303,   854,   855,   304,   305,
     558,   307,   633,   454,  1009,  1010,   308,   634,   309,   636,
     559,   311,   750,   751,  1242,   463,   312,   464,   465,   757,
    1243,  1244,  1245,   637,   638,  1111,  1112,  1526,   639,  1108,
    1109,  1352,  1353,  1354,  1355,   313,   782,   783,   314,  1269,
    1270,  1469,   315,  1272,  1273,   316,   317,  1275,  1276,  1277,
    1278,   318,   319,   320,   321,   891,   322,   323,  1364,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   657,   658,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   691,   686,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   920,   363,   364,   365,  1305,   815,   816,   817,
    1709,  1753,  1754,  1747,  1748,  1755,  1749,  1306,  1307,   366,
     367,  1308,   368,   369,   370,   371,   372,   373,   374,  1151,
    1004,  1137,  1405,  1138,  1561,  1139,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   789,  1218,   385,   386,
     387,   388,  1141,  1142,  1143,  1144,   389,   390,   391,   392,
     393,   394,   844,   845,   395,  1337,  1338,  1643,  1095,  1119,
    1374,  1375,  1120,  1121,  1122,  1123,  1124,  1384,  1551,  1552,
    1125,  1387,  1126,  1532,  1127,  1128,  1392,  1393,  1557,  1555,
    1376,  1377,  1378,  1379,  1658,   726,   969,   970,   971,   972,
     973,   974,  1192,  1581,  1675,  1193,  1579,  1673,   975,  1417,
    1576,  1572,  1573,  1574,   976,   977,  1380,  1388,  1542,  1381,
    1538,  1365,   396,   397,   398,   399,   549,   400,   401,   402,
     403,   404,  1145,  1146,  1147,  1148,  1255,   566,   405,   406,
     407
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const short int xquery_parser::yytable_ninf_ = -844;
  const short int
  xquery_parser::yytable_[] =
  {
       306,   701,   618,   438,   306,   306,   306,   899,   310,   412,
     415,   416,   310,   310,   310,   698,   698,   635,   597,  1002,
    1259,   574,  1060,   613,   680,  1024,   900,   901,   902,   903,
     610,   871,   873,   414,   414,   414,  1479,  1036,   615,  1271,
     832,   767,   771,  1094,  1003,  1490,   840,   524,   721,  1304,
    1360,  1050,  1521,  1522,  1207,   887,  1165,   888,   889,   736,
     890,   929,   892,   864,   867,  1117,  1681,   998,  1553,  1231,
     893,   894,  1422,   622,  1223,   622,   866,   869,   872,   874,
    1498,   611,  1195,  1006,   779,     9,    10,  1196,   741,  1169,
     819,   461,   413,   413,   413,   741,   617,  1676,   611,   576,
     611,  1261,  1197,  1082,  1198,   742,   423,  1707,   306,  1033,
    1228,   611,   742,  1199,    11,  1470,   310,   611,   700,   700,
     611,  1140,  1140,  1150,   611,   999,   618,  1000,   622,  1000,
     924,     9,    10,   426,   586,     9,    10,   547,   588,   579,
    1200,   580,   684,   589,   690,   758,   419,   420,   525,   421,
     422,   583,   423,   584,  1000,  1033,   423,  1470,  1140,  1539,
     481,   424,   541,   679,  1000,   424,   425,   710,  1349,  1534,
     475,   732,  1682,   557,   561,  1366,  1061,  1444,  1001,   426,
    1232,   999,   685,   426,   427,   688,   562,   125,   427,  1351,
    1034,   482,  1206,  1349,   483,    79,   413,  1708,   567,   711,
     570,  1471,   768,   417,  1172,  1436,  1535,  1745,   813,    90,
     925,  1297,  1140,  1225,   759,  1590,   428,   429,  1104,  1645,
     428,   429,   430,   587,  1507,  1140,  1248,   590,   581,   681,
    1083,   462,  1297,  1298,   104,   462,  1052,   743,  1114,   622,
     585,  1115,  1062,  1607,  1007,   462,  1766,   476,  1367,   769,
     766,  1479,   306,   617,  1683,   306,  1460,   820,  1236,   618,
     310,  1674,   125,   310,  1247,  1294,   635,  1201,  1498,   431,
     612,  1233,  1470,  1473,  1366,  1396,   856,  1067,   871,   873,
     857,  1008,   577,  1304,  1166,  1117,  1117,   614,  1207,   859,
     306,  1585,  1304,  1409,  1229,  1071,  1234,  1531,   310,  1435,
     861,   955,   462,   462,  1113,   462,  1101,   599,   601,  1103,
     864,   867,   924,  1342,   477,   478,  1262,   811,  1540,  1541,
     687,   620,  1297,   689,   622,  1300,  1299,  1301,   432,   993,
    1368,  1369,   995,  1370,  1745,  1746,  1414,   716,  1297,   717,
    1371,  1751,   882,  1116,  1140,   733,  1300,  1367,  1301,   661,
    1372,   670,  1021,   734,   619,  1302,   622,   702,  1612,  1202,
    1203,  1204,  1373,    11,   958,   671,   959,   662,  1013,   433,
     703,   718,   449,   860,   450,   622,  1302,   622,   442,  1731,
     111,     9,    10,  1017,   865,   868,  1020,   661,   622,  1045,
    1047,   434,   926,   622,  1716,   434,  1416,   123,   719,   435,
    1068,  1069,  1155,   435,   621,   662,   418,   436,   804,   994,
     960,   436,   996,   622,   306,  1070,  1156,  1303,  1072,  1073,
    1718,   525,   310,  1156,   525,   716,  1206,   717,   622,  1368,
    1369,  1768,  1370,  1074,  1341,   149,  1300,   451,  1301,   622,
     607,   445,   452,   306,    79,   306,  1680,  1752,  1014,  1372,
     618,   310,  1300,   310,  1301,  1016,   608,  1038,    90,  1617,
     720,  1373,  1781,  1140,  1455,  1425,  1302,   616,  1039,  1046,
    1048,   306,   738,  1086,   738,   446,   306,  1479,   619,   310,
    1304,   622,  1302,   104,   310,   805,   719,  1140,  1476,   453,
     992,  1437,  1762,  1118,   622,  1334,  1157,  1655,   622,   709,
     738,   622,   713,  1158,  1656,   738,   567,   622,  1290,   727,
     728,   746,   622,   622,  1657,  1665,  1028,   567,   871,   873,
     871,   764,  1159,   749,   752,  1445,  1094,  1618,   752,  1515,
     776,   737,  1117,   740,  1173,  1174,   772,   787,   788,  1177,
    1326,  1117,   567,   780,   781,   784,   794,   306,   720,  1680,
     790,  1339,  1117,    11,   306,   310,   470,  1670,   797,   785,
     961,  1291,   310,   618,   791,  1344,  1345,  1346,   622,  1215,
     914,   915,  1297,   962,  1292,   963,   622,   622,  1639,  1570,
     804,  1640,  1706,   414,  1044,  1295,   964,   965,   966,  1063,
     967,  1751,   968,  1641,  1680,  1666,   306,   624,   438,  1065,
    1693,   625,   622,   798,   310,  1651,   626,  1140,  1560,  1078,
    1527,   619,   306,   306,   306,   306,  1642,   784,   622,   622,
     310,   310,   310,   310,   627,   851,   664,   818,   809,  1102,
     306,  1098,   419,   420,    79,   421,   422,  1671,   310,   822,
     668,  1473,   413,  1571,  1189,  1064,  1414,   455,    90,   669,
    1618,  1296,   425,  1093,  1154,   665,   833,  1320,  1066,   850,
     852,  1190,   833,  1415,   945,  1804,   846,  1805,   666,   684,
     999,   690,  1339,   104,   999,   999,  1813,  1114,  1348,  1529,
    1115,   999,  1652,  1402,   706,   457,  1300,  1238,  1301,  1349,
    1140,  1616,  1239,  1140,  1620,  1761,  1764,  1784,  1624,  1350,
     707,   125,   667,  1628,  1191,   468,  1416,   946,  1343,  1591,
    1351,  1240,   947,  1118,  1118,  1403,  1302,  1546,  1023,  1117,
    1217,   999,  1220,   628,  1750,  1756,   629,  1035,  1235,  1049,
    1000,   624,  1404,  1524,  1238,   625,   661,   458,   306,  1239,
     626,   630,   661,   913,  1362,   730,   310,   459,   916,   875,
     731,   479,  1241,   876,   662,   431,  1389,  1390,   627,   871,
     662,  1160,   306,  1162,  1189,  1750,   631,  1015,   125,  1525,
     310,  1756,  1283,   460,  1284,  1167,   663,  1000,  1161,  1391,
    1163,  1190,  1722,  1178,  1179,  1180,   469,  1167,  1655,  1181,
     951,   414,   306,   306,  1099,  1656,  1164,  1408,  1330,   635,
     310,   310,   619,   680,   981,  1657,   704,  1268,   985,   986,
     608,  1268,   762,   762,   432,   443,  1477,  1480,   444,   705,
    1467,   738,   738,  1183,  1472,  1477,  1477,  1297,  1298,  1478,
    1481,  1005,  1710,  1011,  1184,  1458,  1713,   306,  1623,  1760,
    1209,   567,   682,   683,   567,   310,  1536,  1185,  1025,  1210,
     413,  1091,   684,  1537,   690,   433,   473,   628,  1186,  1092,
     629,   438,  1238,  1310,   624,  1311,   414,  1239,   625,   480,
    1055,  1056,  1057,   626,   852,   812,  1140,  1724,  1140,  1725,
    1042,  1043,   946,   447,  1653,  1654,   448,   947,  1315,  1058,
    1316,   627,   474,   917,   466,  1650,   917,   467,   527,   917,
     631,   471,  1175,  1176,   472,   722,   723,   724,   528,  1140,
    1740,   530,  1297,  1298,  1518,  1519,   897,   898,  1758,   904,
     905,  1299,  1097,  1297,  1298,   413,   906,   907,   525,   597,
     531,  1517,   542,  1732,  1340,  1420,  1421,  1667,  1668,  1140,
    1765,  1300,   543,  1301,  1152,  1152,   544,   563,   564,   571,
     572,   573,   575,  1105,  1140,  1775,  1140,  1778,   578,   582,
    1118,   591,   592,   593,  1456,   594,   595,   602,   596,  1118,
     604,  1302,   622,   623,   640,   111,   641,   659,   660,   672,
    1118,   673,   674,  1149,  1149,  1149,  1149,   675,   684,   692,
     628,   693,   123,   629,   700,  1720,  1721,   694,   712,   714,
     695,   696,   725,   753,   715,   729,  1299,   756,  1335,   762,
     739,   754,  1492,   765,   773,   774,   775,  1299,   786,   792,
    1149,   793,   799,   444,   801,   448,  1300,   467,  1301,   803,
     149,   472,   483,   631,  1182,   814,   810,  1300,   806,  1301,
     306,  1603,   821,   807,   808,   823,   824,   882,   310,   834,
     847,   842,   858,   848,   843,   853,  1302,   863,   878,  1212,
     111,   879,   880,   895,   881,   909,  1763,  1302,  1219,   738,
    1219,   111,   752,   910,  1149,   908,   911,   123,   930,   921,
     927,   928,   952,   953,   956,   957,  1091,  1149,   123,   979,
     980,   438,   982,   978,  1092,   984,   987,  1497,   990,   988,
     989,   306,   306,   306,   991,   997,  1646,  1012,  1626,   310,
     310,   310,  1018,  1019,  1022,   149,   642,  1037,  1029,  1030,
     790,  1031,   790,  1032,   643,   644,   149,   645,  1279,  1040,
    1041,   443,  1076,   447,   466,   646,   471,  1077,   482,   647,
    1079,   648,  1080,  1081,  1084,  1085,   649,  1118,  1100,  1110,
     947,  1168,   999,  1187,  1208,  1188,   833,  1106,  1213,  1214,
    1216,  1224,  1226,   650,   932,   933,   934,   935,   936,   937,
     938,   939,   940,   941,  1230,   758,  1250,  1237,  1359,  1253,
    1251,  1256,  1257,  1609,  1258,  1357,   651,   652,   653,   654,
     655,   656,  1263,  1264,  1252,  1267,  1268,  1274,  1280,  1281,
    1287,  1286,  1289,  1293,  1282,  1309,  1149,  1327,  1331,  1332,
    1336,  1333,   718,  1334,  1356,  1358,   306,  1382,  1383,  1363,
    1386,  1429,  1394,  1395,   310,  1397,  1398,  1399,  1400,  1401,
    1406,    11,  1412,  1413,  1418,  1423,  1428,  1427,  1432,  1440,
    1442,  1449,  1424,  1430,  1450,   414,  1446,  1448,  1431,  1433,
    1434,  1454,   306,  1459,  1462,   526,  1477,  1491,  1483,  1494,
     310,  1500,  1489,   306,  1485,  1486,  1499,  1501,  1463,   526,
    1502,   310,  1503,  1504,  1505,  1349,  1509,  1516,  1506,  1533,
    1530,  1543,   306,  1549,  1550,  1556,  1554,  1484,  1562,  1563,
     310,  1564,   414,   526,  1569,  1575,  1565,   752,  1566,  1580,
    1582,  1438,   306,  1567,   413,   526,  1568,   526,  1588,  1593,
     310,   414,  1691,  1586,  1600,  1578,  1452,  1601,  1602,  1605,
    1606,  1622,  1627,  1695,  1609,  1149,  1697,  1611,  1614,  1621,
    1661,   738,  1648,  1705,  1091,  1091,  1584,  1635,  1649,   784,
    1663,  1672,  1092,  1092,  1664,  1189,  1677,  1688,  1690,  1149,
    1685,   413,  1696,  1700,  1712,  1726,  1704,  1715,  1727,  1524,
    1734,  1729,  1662,   851,  1730,  1739,  1741,  1728,  1735,  1742,
     413,  1684,  1743,  1771,  1772,  1757,  1780,  1759,  1496,  1774,
    1779,  1783,  1786,  1794,   603,  1787,  1791,  1795,  1809,  1800,
    1495,  1769,  1810,  1806,   605,  1510,  1511,  1512,  1797,  1789,
    1807,   954,   846,  1801,   606,   609,  1411,   699,  1170,  1798,
     735,   525,  1249,  1426,   525,  1803,  1697,  1737,  1767,  1096,
    1246,   755,  1812,  1027,  1598,  1528,  1453,  1456,  1347,  1523,
    1520,  1464,   800,  1468,  1474,  1482,   885,   896,   886,   923,
    1493,  1059,  1782,  1785,  1153,   744,  1221,  1410,  1508,  1514,
     745,  1513,   678,  1548,  1776,  1544,  1660,  1659,  1547,  1361,
    1385,  1194,  1419,  1669,  1545,  1075,  1577,     0,     0,  1149,
       0,   306,     0,     0,     0,     0,     0,     0,     0,   310,
       0,     0,     0,     0,     0,     0,  1792,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1583,     0,
       0,     0,     0,     0,     0,     0,     0,  1792,     0,     0,
       0,     0,  1776,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1596,  1597,     0,     0,   526,     0,
       0,   526,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1613,     0,  1149,     0,     0,  1149,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   548,  1625,     0,     0,
       0,     0,  1629,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1091,     0,     0,     0,     0,   708,   526,     0,  1092,   526,
       0,  1091,  1091,   526,   306,     0,   526,   526,     0,  1092,
    1092,  1091,   310,     0,   526,     0,     0,     0,     0,  1092,
     526,   526,     0,     0,     0,   526,     0,     0,     0,     0,
       0,     0,     0,   526,     0,     0,     0,     0,     0,   526,
     526,   526,   526,     0,     0,     0,     0,   526,     0,     0,
       0,     0,     0,     0,     0,   526,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1699,     0,  1701,     0,  1703,     0,     0,     0,     0,     0,
       0,  1711,     0,     0,  1091,     0,  1717,     0,     0,     0,
     526,     0,  1092,     0,     0,  1091,     0,     0,     0,     0,
       0,     0,     0,  1092,   526,  1723,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   526,     0,     0,  1149,     0,
    1149,     0,   306,     0,     0,     0,     0,     0,     0,     0,
     310,     0,     0,     0,     0,     0,  1733,     0,     0,  1736,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1149,     0,   526,   306,     0,     0,     0,     0,     0,
       0,  1744,   310,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1091,     0,     0,     0,     0,
    1091,  1149,     0,  1092,     0,     0,     0,     0,  1092,  1770,
       0,     0,     0,     0,  1773,     0,  1149,     0,  1149,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1790,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1796,     0,     0,     0,  1799,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1808,     0,     0,  1811,     0,     0,     0,     0,
       0,     0,     0,     0,   931,     0,     0,   526,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   526,     0,     0,     0,   526,   526,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   526,     0,
     526,     0,     0,     0,     0,     0,     0,     0,   526,     0,
       0,   526,     0,     0,     0,   526,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   526,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   548,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   526,     0,   825,   826,     0,
       0,   835,   836,   838,   839,     0,   841,     0,     0,     0,
       0,     0,   849,     0,     0,     0,     0,     0,     0,     0,
     526,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     877,     0,     0,     0,     0,     0,     0,     0,   883,   884,
     526,   526,   526,   526,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   526,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   526,     0,     0,     0,     0,     0,     0,   919,     0,
       0,   919,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   526,     0,     0,     0,
       0,     0,     0,     0,     0,   526,     0,   526,     0,   526,
       0,   526,     0,     0,     0,     0,     0,     0,     0,   983,
       0,     0,     0,     0,   526,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   526,     0,   526,
       0,     0,  1026,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1051,     0,     0,
       0,  1053,  1054,     0,     0,     0,     0,     0,     0,     0,
     883,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   526,     0,     0,   548,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   526,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   526,  1171,     0,     0,   526,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   526,     0,     0,     0,     0,     0,     0,
       0,     0,   526,     0,     0,     0,     0,     0,     0,     0,
    1211,     0,     0,     0,     0,     0,   526,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   526,     0,     0,  1227,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1260,     0,     0,     0,   526,     0,     0,     0,     0,
       0,     0,  1265,  1266,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1285,     0,   526,
    1288,     0,     0,     0,     0,     0,     0,     0,   526,     0,
       0,   526,     0,     0,     0,     0,  1312,  1313,  1314,     0,
    1317,  1318,  1319,     0,  1321,  1322,  1323,  1324,  1325,     0,
       0,  1328,  1329,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   526,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   526,     0,     0,     0,     0,
       0,     0,     0,     0,  1407,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   526,   526,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   526,     0,   526,
       0,     0,   526,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   526,     0,     0,     0,     0,   526,
       0,     0,     0,     0,     0,     0,  1439,     0,  1441,     0,
    1443,     0,     0,  1447,     0,     0,     0,     0,  1451,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1457,     0,     0,     0,     0,     0,     0,     0,     0,  1461,
       0,     0,     0,     0,     0,  1465,  1466,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1487,     0,     0,  1488,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   526,     0,   526,
       0,   526,     0,     0,     0,     0,     0,     0,   526,     0,
       0,     0,     0,     0,  1107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   526,     0,   526,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   526,     0,     0,   526,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   526,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   526,     0,
       0,     0,     0,     0,  1587,     0,     0,     0,  1589,     0,
       0,     0,  1592,     0,  1594,     0,  1595,     0,   526,     0,
       0,     0,  1599,     0,     0,     0,   526,     0,     0,     0,
    1604,   526,     0,   526,     0,   526,     0,     0,  1608,  1610,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1457,     0,     0,
       0,     0,     0,   526,     0,     0,     0,     0,  1630,  1631,
    1632,  1633,  1634,     0,  1636,  1637,     0,  1638,     0,   526,
       0,     0,     0,   526,  1644,     0,     0,     0,     0,     0,
       0,     0,     0,  1647,     0,     0,     0,     0,     0,   526,
       0,     0,   526,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1686,     0,  1687,     0,
       0,  1689,     0,     0,     0,     0,     0,     0,     0,  1692,
       0,     0,     0,     0,  1694,  1610,     0,     0,     0,     0,
       0,     0,  1698,     0,     0,     0,  1702,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1714,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1719,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -843,   449,     0,
     450,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1738,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1698,  -843,
       0,     0,     0,  -843,     0,     0,     0,  -843,  -843,     0,
       0,     0,  -843,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   451,     0,     0,  -843,     0,   452,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1777,     0,     0,     0,     0,     0,     0,     0,     0,  -843,
       0,  -843,  -843,  -843,     0,     0,  -843,  -843,  -843,  -843,
       0,     0,     0,  -843,  -843,     0,     0,  1788,     0,     0,
    -843,     0,  1793,  -843,  -843,   453,     0,  1777,  -843,     0,
       0,     0,     0,  -843,  -843,     0,     0,     0,     0,  -843,
       0,     0,  1793,  -843,     0,     0,  1802,  -843,  -843,     0,
    -843,     0,  -843,  -843,     0,     0,     0,  -843,  -843,     0,
       0,  -843,  -843,  -843,  -843,  -843,  -843,     0,     0,  -843,
       0,     0,     0,     0,  -843,  -843,     0,     0,  -843,     0,
       0,     0,     0,  -843,     0,     0,  -843,     0,     0,     0,
       0,  -843,  -843,  -843,  -843,  -843,     0,  -843,  -843,  -843,
    -843,     0,     0,     0,     0,  -843,  -843,  -843,     0,  -843,
    -843,  -843,  -843,  -843,  -843,     0,  -843,     0,  -843,     0,
       0,     0,     0,  -843,  -843,  -843,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -843,
       0,  -843,     0,  -843,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -843,     0,     0,     0,     0,
    -843,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     9,    10,     0,    11,  -843,     0,  -843,
      12,    13,     0,    14,    15,    16,    17,    18,    19,    20,
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
       0,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,     0,   244,     0,
     245,   246,   247,   248,   249,   250,   251,   252,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     9,    10,     0,    11,     0,     0,     0,
     408,   409,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,   410,    28,    29,    30,
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
       0,   545,     0,   129,     0,   130,   131,     0,   132,   133,
     134,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   411,   151,   152,   153,   154,   155,   156,   157,   158,
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
       7,     8,     9,    10,     0,    11,     0,     0,     0,   408,
     409,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,   410,    28,    29,    30,    31,
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
     802,     0,   129,     0,   130,   131,     0,   132,   133,   134,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,   149,     0,
     411,   151,   152,   153,   154,   155,   156,   157,   158,   159,
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
       8,     9,    10,     0,    11,     0,     0,     0,   408,   409,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,  1087,   410,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,  1088,  1089,    50,
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
       0,   124,   125,     0,     0,   126,   127,   128,     0,   802,
       0,   129,     0,   130,   131,     0,   132,   133,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   411,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,  1090,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,   408,   409,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,  1087,   410,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,  1088,  1089,    50,    51,
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
     124,   125,     0,     0,   126,   127,   128,     0,   545,     0,
     129,     0,   130,   131,     0,   132,   133,   134,     0,   135,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,   149,     0,   411,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,  1090,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,     0,   244,     0,   245,   246,   247,
     248,   249,   250,   251,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     9,
      10,     0,    11,     0,     0,     0,   408,   409,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,   410,    28,    29,    30,    31,     0,    32,    33,
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
     146,     0,     0,   147,   148,   149,     0,   411,   151,   152,
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
       0,   147,   148,   149,     0,   411,   151,   152,   153,   154,
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
       0,     0,     0,    12,   409,     0,    14,    15,    16,    17,
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
     147,   148,   149,     0,   411,   151,   152,   153,   154,   155,
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
       0,     0,   870,   409,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,   410,    28,
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
     148,   149,     0,   411,   151,   152,   153,   154,   155,   156,
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
       0,   408,   409,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,  1087,   410,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
    1088,  1089,    50,    51,    52,    53,    54,    55,    56,    57,
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
     149,     0,   411,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,  1090,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,     0,   244,
       0,   245,   246,   247,   248,   249,   250,   251,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     0,     0,     0,    11,     0,     0,     0,
     408,   409,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   550,   410,    28,    29,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,   551,
     552,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,     0,    74,    75,    76,
       0,     0,    77,    78,     0,     0,     0,    79,    80,   501,
      82,    83,    84,    85,    86,   553,    88,    89,     0,     0,
       0,    90,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,    96,    97,    98,    99,   100,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     554,   109,     0,   110,   111,   112,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
       0,   123,     0,   124,   125,     0,     0,   126,   127,   128,
       0,     0,   555,   129,     0,   130,   131,     0,   132,   133,
     134,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   411,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   518,   519,   520,   176,   177,   521,
     556,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,     0,   244,     0,
     245,   246,   247,   248,   249,   250,   251,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     0,     0,     0,    11,     0,     0,     0,   408,
     409,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   550,   410,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,   551,   552,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,     0,    74,    75,    76,     0,
       0,    77,    78,     0,     0,     0,    79,    80,   501,    82,
      83,    84,    85,    86,   553,    88,    89,     0,     0,     0,
      90,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   554,
     109,     0,   110,   111,   112,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,     0,
     123,     0,   124,   125,     0,     0,   126,   127,   128,     0,
       0,     0,   129,   560,   130,   131,     0,   132,   133,   134,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,   149,     0,
     411,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   518,   519,   520,   176,   177,   521,   556,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,     0,   244,     0,   245,
     246,   247,   248,   249,   250,   251,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     0,     0,     0,    11,     0,     0,     0,   408,   409,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   550,   410,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,   551,   552,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,     0,    74,    75,    76,     0,     0,
      77,    78,     0,     0,     0,    79,    80,   501,    82,    83,
      84,    85,    86,   553,    88,    89,     0,     0,     0,    90,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
      96,    97,    98,    99,   100,     0,     0,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   554,   109,
       0,   110,   111,   112,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,     0,   123,
       0,   124,   125,     0,     0,   126,   127,   128,     0,     0,
       0,   129,     0,   130,   131,     0,   132,   133,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   411,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   518,   519,   520,   176,   177,   521,   556,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   598,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   408,   409,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   550,   410,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,   551,   552,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   501,    82,    83,    84,
      85,    86,   553,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   554,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,     0,   130,   131,     0,   132,   133,   134,     0,   135,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,   149,     0,   411,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   518,   519,   520,   176,   177,   521,   556,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,     0,   244,   600,   245,   246,   247,
     248,   249,   250,   251,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     0,
       0,     0,    11,     0,     0,     0,   408,   409,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   550,   410,    28,    29,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,    45,    46,    47,   551,   552,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,     0,    74,    75,    76,     0,     0,    77,    78,
       0,     0,     0,    79,    80,   501,    82,    83,    84,    85,
      86,   553,    88,    89,     0,     0,     0,    90,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,    96,    97,
      98,    99,   100,     0,     0,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   554,   109,     0,   110,
     111,   112,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,     0,   123,     0,   124,
     125,     0,     0,   126,   127,   128,     0,   912,     0,   129,
       0,   130,   131,     0,   132,   133,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   411,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     518,   519,   520,   176,   177,   521,   556,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,   244,     0,   245,   246,   247,   248,
     249,   250,   251,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   408,   409,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     550,   410,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,   551,   552,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   501,    82,    83,    84,    85,    86,
     553,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   554,   109,     0,   110,   111,
     112,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,   124,   125,
       0,     0,   126,   127,   128,     0,     0,     0,   129,   918,
     130,   131,     0,   132,   133,   134,     0,   135,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,   149,     0,   411,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   518,
     519,   520,   176,   177,   521,   556,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,     0,   244,     0,   245,   246,   247,   248,   249,
     250,   251,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     0,     0,     0,
      11,     0,     0,     0,   408,   409,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,   550,
     410,    28,    29,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,   551,   552,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
       0,    74,    75,    76,     0,     0,    77,    78,     0,     0,
       0,    79,    80,   501,    82,    83,    84,    85,    86,   553,
      88,    89,     0,     0,     0,    90,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,    96,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   554,   109,     0,   110,   111,   112,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,   121,   122,     0,   123,     0,   124,   125,     0,
       0,   126,   127,   128,     0,     0,     0,   129,   922,   130,
     131,     0,   132,   133,   134,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,   149,     0,   411,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   518,   519,
     520,   176,   177,   521,   556,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,     0,   244,     0,   245,   246,   247,   248,   249,   250,
     251,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     0,     0,     0,    11,
       0,     0,     0,   408,   409,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   487,    25,   489,   410,
      28,   490,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,   492,     0,    45,
      46,    47,   494,   495,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,    73,     0,
      74,    75,    76,     0,     0,    77,    78,     0,     0,     0,
      79,    80,   501,    82,    83,    84,    85,    86,   553,    88,
      89,     0,     0,     0,    90,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   504,    97,    98,    99,   100,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   554,   109,     0,   110,   111,   676,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,     0,   123,     0,   677,   125,     0,     0,
     126,   127,   128,     0,     0,     0,   129,     0,   130,   131,
       0,   132,   133,   134,     0,   135,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,   149,     0,   411,   151,   152,   153,   154,   155,
     156,   157,   158,   513,   160,   514,   162,   515,   516,   165,
     166,   167,   168,   169,   170,   517,   172,   518,   519,   520,
     176,   177,   521,   522,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
       0,   244,     0,   245,   523,   247,   248,   249,   250,   251,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     0,     0,     0,    11,     0,
       0,     0,   408,   409,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   550,   410,    28,
      29,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,   551,   552,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,     0,    74,
      75,    76,     0,     0,    77,    78,     0,     0,     0,    79,
      80,   501,    82,    83,    84,    85,    86,   553,    88,    89,
       0,     0,     0,    90,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,    96,    97,    98,    99,   100,     0,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   554,   109,     0,   110,   111,   112,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,     0,   123,     0,   124,   125,     0,     0,   126,
     127,   128,     0,     0,     0,   129,     0,   130,   131,     0,
     132,   133,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   411,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   518,   519,   520,   176,
     177,   521,   556,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   408,   409,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   550,   410,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     551,   552,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     501,    82,    83,    84,    85,    86,   553,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   837,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,   134,     0,   135,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
     149,     0,   411,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   518,   519,   520,   176,   177,
     521,   556,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,     0,   244,
       0,   245,   246,   247,   248,   249,   250,   251,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     0,     0,     0,    11,     0,     0,     0,
     408,   409,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,   487,    25,   489,   410,    28,   490,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,   492,     0,    45,    46,    47,   494,
     495,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,     0,    74,    75,    76,
       0,     0,    77,    78,     0,     0,     0,    79,    80,   501,
      82,    83,    84,    85,    86,   553,    88,    89,     0,     0,
       0,    90,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   504,    97,    98,    99,   100,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     554,   109,     0,   110,   111,   112,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
       0,   123,     0,   124,   125,     0,     0,   126,   127,   128,
       0,     0,     0,   129,     0,   130,   131,     0,   132,   133,
     134,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   411,   151,   152,   153,   154,   155,   156,   157,   158,
     513,   160,   514,   162,   515,   516,   165,   166,   167,   168,
     169,   170,   517,   172,   518,   519,   520,   176,   177,   521,
     522,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,     0,   244,     0,
     245,   523,   247,   248,   249,   250,   251,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     0,     0,     0,    11,     0,     0,     0,   408,
     409,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,   487,    25,   489,   410,    28,   490,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,   492,     0,    45,    46,    47,   494,   495,
      50,   496,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,     0,    74,    75,    76,     0,
       0,    77,    78,     0,     0,     0,    79,    80,   501,    82,
      83,    84,    85,    86,   553,    88,    89,     0,     0,     0,
      90,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   504,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   554,
     109,     0,   110,   111,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,     0,
     123,     0,     0,     0,     0,     0,   126,   127,   128,     0,
       0,     0,   129,     0,   130,   131,     0,   132,   133,   134,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,   149,     0,
     411,   151,   152,   153,   154,   155,   156,   157,   158,   513,
     160,   514,   162,   515,   516,   165,   166,   167,   168,   169,
     170,   517,   172,   518,   519,   520,   176,   177,   521,   522,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,     0,   244,     0,   245,
     523,   247,   248,   249,   250,   251,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     0,     0,     0,    11,     0,     0,     0,   408,   409,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,   487,    25,   489,   410,    28,   490,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,   492,     0,    45,    46,    47,   494,   495,    50,
     496,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,     0,    74,    75,    76,     0,     0,
      77,    78,     0,     0,     0,    79,    80,   501,    82,    83,
      84,    85,    86,   553,    88,    89,     0,     0,     0,    90,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     504,    97,    98,    99,   100,     0,     0,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   554,   109,
       0,   110,   111,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,     0,   123,
       0,     0,     0,     0,     0,   126,   127,   128,     0,     0,
       0,   129,     0,   130,   131,     0,     0,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   411,
     151,   152,   153,   154,   155,   156,   157,   158,   513,   160,
     514,   162,   515,   516,   165,   166,   167,   168,   169,   170,
     517,   172,   518,   519,   520,   176,   177,   521,   522,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   523,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   408,   409,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     487,    25,   489,   410,    28,   490,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,   492,     0,    45,    46,    47,   494,   495,    50,   496,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   501,    82,    83,    84,
      85,    86,   553,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   504,
       0,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,     0,   106,   107,   554,   109,     0,
     110,   111,     0,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
       0,     0,     0,     0,   126,   127,   128,     0,     0,     0,
     129,     0,   130,   131,     0,     0,     0,   134,     0,   135,
       0,   136,     0,   138,     0,   140,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,   149,     0,   411,   151,
     152,   153,   154,   155,   156,   157,   158,   513,   160,   514,
     162,   515,   516,   165,   166,   167,   168,   169,   170,   517,
     172,   518,   519,   520,   176,   177,   521,   522,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,     0,   244,     0,   245,   523,   247,
     248,   249,   250,   251,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     0,     0,     0,     7,     8,     0,
       0,     0,     0,     0,     0,     0,   408,   409,     0,    14,
      15,    16,   484,    18,    19,    20,   485,    22,   486,   487,
     488,   489,   410,    28,   490,    30,    31,     0,    32,    33,
      34,    35,   491,    37,    38,    39,    40,    41,    42,    43,
     492,     0,    45,   493,    47,   494,   495,    50,   496,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   497,   498,    68,     0,    69,    70,    71,
     499,     0,     0,    74,    75,    76,     0,     0,   500,    78,
       0,     0,     0,     0,    80,   501,    82,   502,   503,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   504,    97,
      98,   505,   506,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,   107,     0,     0,     0,     0,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   507,   120,   121,   508,     0,     0,     0,     0,
       0,     0,     0,   509,   510,   128,     0,     0,     0,   129,
       0,   130,   511,     0,     0,     0,   134,     0,   135,     0,
     136,   137,   138,   139,   512,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,     0,     0,   411,   151,   152,
     153,   154,   155,   156,   157,   158,   513,   160,   514,   162,
     515,   516,   165,   166,   167,   168,   169,   170,   517,   172,
     518,   519,   520,   176,   177,   521,   522,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     0,     0,     1,     2,   245,   523,   247,   248,
     249,   250,   251,     3,     0,     0,     0,     7,     8,     0,
       0,     0,     0,     0,     0,     0,   408,   409,     0,    14,
      15,    16,   532,    18,    19,    20,   485,   533,   534,   487,
     488,   489,   410,    28,   490,    30,    31,     0,    32,    33,
      34,    35,   535,    37,   536,   537,    40,    41,    42,    43,
     492,     0,    45,   538,    47,   494,   495,    50,   496,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   497,   498,    68,     0,    69,    70,    71,
     539,     0,     0,    74,    75,    76,     0,     0,   500,    78,
       0,     0,     0,     0,    80,   501,    82,   502,   503,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   504,    97,
      98,   505,   506,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,   107,     0,     0,     0,     0,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   507,   120,   121,   508,     0,     0,     0,     0,
       0,     0,     0,   509,   510,   128,     0,     0,     0,   129,
       0,   130,   511,     0,     0,     0,   134,     0,   135,     0,
     136,   137,   138,   139,   512,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,     0,     0,   411,   151,   152,
     153,   154,   155,   156,   157,   158,   513,   540,   514,   162,
     515,   516,   165,   166,   167,   168,   169,   170,   517,   172,
     518,   519,   520,   176,   177,   521,   522,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     0,     0,     0,   565,   245,   523,   247,   248,
     249,   250,   251,     7,     8,     0,     0,     0,   777,     0,
       0,     0,   408,   409,     0,    14,    15,    16,   532,    18,
      19,    20,   485,   533,   534,   487,   488,   489,   410,    28,
     490,    30,    31,     0,    32,    33,    34,    35,   535,    37,
     536,   537,    40,    41,    42,    43,   492,     0,    45,   538,
      47,   494,   495,    50,   496,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   497,
     498,    68,     0,    69,    70,    71,   539,     0,     0,    74,
      75,    76,     0,     0,   500,    78,     0,     0,     0,     0,
      80,   501,    82,   502,   503,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   504,    97,    98,   505,   506,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,   107,     0,     0,     0,     0,     0,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   507,   120,
     121,   508,     0,     0,     0,     0,     0,     0,     0,   509,
     510,   128,     0,     0,     0,   129,   778,   130,   511,     0,
       0,     0,     0,     0,   135,     0,   136,   137,   138,   139,
     512,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,     0,     0,   411,   151,   152,   153,   154,   155,   156,
     157,   158,   513,   540,   514,   162,   515,   516,   165,   166,
     167,   168,   169,   170,   517,   172,   518,   519,   520,   176,
     177,   521,   522,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     0,     0,
       0,   565,   245,   523,   247,   248,   249,   250,   251,     7,
       8,     0,     0,     0,     0,     0,     0,     0,   408,   409,
       0,    14,    15,    16,   532,    18,    19,    20,   485,   533,
     534,   487,   488,   489,   410,    28,   490,    30,    31,     0,
      32,    33,    34,    35,   535,    37,   536,   537,    40,    41,
      42,    43,   492,     0,    45,   538,    47,   494,   495,    50,
     496,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,   497,   498,    68,     0,    69,
      70,    71,   539,     0,     0,    74,    75,    76,     0,     0,
     500,    78,     0,     0,     0,     0,    80,   501,    82,   502,
     503,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     504,    97,    98,   505,   506,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,   107,     0,     0,
       0,     0,     0,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   507,   120,   121,   508,     0,     0,
       0,     0,     0,     0,     0,   509,   510,   128,     0,     0,
       0,   129,     0,   130,   511,     0,     0,     0,     0,     0,
     135,     0,   136,   137,   138,   139,   512,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,     0,     0,   411,
     151,   152,   153,   154,   155,   156,   157,   158,   513,   540,
     514,   162,   515,   516,   165,   166,   167,   168,   169,   170,
     517,   172,   518,   519,   520,   176,   177,   521,   522,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,     0,     0,     0,     0,   245,   523,
     247,   248,   249,   250,   251,   568,   569,     0,     0,     0,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
     408,   409,     0,    14,    15,    16,   532,    18,    19,    20,
     485,   533,   534,   487,   488,   489,   410,    28,   490,    30,
      31,     0,    32,    33,    34,    35,   535,    37,   536,   537,
      40,    41,    42,    43,   492,     0,    45,   538,    47,   494,
     495,    50,   496,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   497,   498,    68,
       0,    69,    70,    71,   539,     0,     0,    74,    75,    76,
       0,     0,   500,    78,     0,     0,     0,     0,    80,   501,
      82,   502,   503,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   504,    97,    98,   505,   506,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,   107,
       0,     0,     0,     0,     0,     0,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   507,   120,   121,   508,
       0,     0,     0,     0,     0,     0,     0,   509,   510,   128,
       0,     0,     0,   129,     0,   130,   511,     0,     0,     0,
       0,     0,   135,     0,   136,   137,   138,   139,   512,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,     0,
       0,   411,   151,   152,   153,   154,   155,   156,   157,   158,
     513,   540,   514,   162,   515,   516,   165,   166,   167,   168,
     169,   170,   517,   172,   518,   519,   520,   176,   177,   521,
     522,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     0,     0,     0,     0,
     245,   523,   247,   248,   249,   250,   251,     4,     5,     6,
       7,     8,     0,     0,     0,    11,     0,     0,     0,   408,
     409,     0,    14,    15,    16,   827,    18,    19,    20,    21,
     533,   828,   487,    25,   489,   410,    28,   490,    30,    31,
       0,    32,    33,    34,    35,   829,    37,   536,   537,    40,
      41,    42,    43,   492,     0,    45,   830,    47,   494,   495,
      50,   496,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   497,   498,    68,     0,
      69,    70,    71,   831,     0,     0,    74,    75,    76,     0,
       0,   500,    78,     0,     0,     0,    79,    80,   501,    82,
     502,   503,    85,    86,   553,    88,     0,     0,     0,     0,
      90,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   504,    97,    98,   505,   506,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   554,
     109,     0,   110,   111,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   508,     0,
     123,     0,     0,     0,     0,     0,   509,   510,   128,     0,
       0,     0,   129,     0,   130,   511,     0,     0,     0,     0,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,   149,     0,
     411,   151,   152,   153,   154,   155,   156,   157,   158,   513,
     540,   514,   162,   515,   516,   165,   166,   167,   168,   169,
     170,   517,   172,   518,   519,   520,   176,   177,   521,   522,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,     0,   244,     0,   245,
     523,   247,   248,   249,   250,   251,     7,     8,     0,     0,
       0,     0,     0,     0,     0,   408,   409,     0,    14,    15,
      16,   484,    18,    19,    20,   485,    22,   486,   487,  1129,
     489,   410,    28,   490,    30,    31,     0,    32,    33,    34,
      35,   491,    37,    38,    39,    40,    41,    42,    43,   492,
       0,    45,   493,    47,   494,   495,    50,   496,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   497,   498,    68,     0,    69,    70,    71,   499,
       0,     0,    74,    75,    76,     0,     0,   500,    78,     0,
       0,     0,     0,    80,   501,    82,   502,   503,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   504,    97,    98,
     505,   506,     0,     0,     0,     0,     0,     0,   101,   102,
     103,     0,   105,   106,  1130,     0,     0,     0,  1131,     0,
       0,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   507,   120,   121,   508,     0,     0,     0,     0,     0,
       0,     0,   509,   510,   128,     0,     0,     0,   129,  1558,
     130,   511,     0,     0,     0,  1559,     0,   135,     0,   136,
     137,   138,   139,   512,   141,   142,   143,   144,   145,   146,
       0,     0,  1132,   148,     0,     0,   411,   151,   152,   153,
     154,   155,   156,   157,   158,   513,   160,   514,   162,   515,
     516,   165,   166,   167,   168,   169,   170,   517,   172,   518,
     519,   520,   176,   177,   521,   522,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     0,     0,     7,     8,   245,   523,   247,  1133,  1134,
    1135,  1136,   408,   409,     0,    14,    15,    16,   532,    18,
      19,    20,   485,   533,   534,   487,   488,   489,   410,    28,
     490,    30,    31,     0,    32,    33,    34,    35,   535,    37,
     536,   537,    40,    41,    42,    43,   492,     0,    45,   538,
      47,   494,   495,    50,   496,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   497,
     498,    68,     0,    69,    70,    71,   539,     0,     0,    74,
      75,    76,     0,     0,   500,    78,     0,     0,     0,     0,
      80,   501,    82,   502,   503,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   504,    97,    98,   505,   506,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,   107,     0,     0,     0,     0,     0,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   507,   120,
     121,   508,     0,     0,     0,     0,     0,     0,     0,   509,
     510,   128,     0,     0,     0,   129,   747,   130,   511,     0,
       0,     0,   748,     0,   135,     0,   136,   137,   138,   139,
     512,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,     0,     0,   411,   151,   152,   153,   154,   155,   156,
     157,   158,   513,   540,   514,   162,   515,   516,   165,   166,
     167,   168,   169,   170,   517,   172,   518,   519,   520,   176,
     177,   521,   522,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     0,     0,
       7,     8,   245,   523,   247,   248,   249,   250,   251,   408,
     409,     0,    14,    15,    16,   532,    18,    19,    20,   485,
     533,   534,   487,   488,   489,   410,    28,   490,    30,    31,
       0,    32,    33,    34,    35,   535,    37,   536,   537,    40,
      41,    42,    43,   492,     0,    45,   538,    47,   494,   495,
      50,   496,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   497,   498,    68,     0,
      69,    70,    71,   539,     0,     0,    74,    75,    76,     0,
       0,   500,    78,     0,     0,     0,     0,    80,   501,    82,
     502,   503,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   504,    97,    98,   505,   506,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,   107,     0,
       0,     0,     0,     0,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   507,   120,   121,   508,     0,
       0,     0,     0,     0,     0,     0,   509,   510,   128,     0,
       0,     0,   129,   795,   130,   511,     0,     0,     0,   796,
       0,   135,     0,   136,   137,   138,   139,   512,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,     0,     0,
     411,   151,   152,   153,   154,   155,   156,   157,   158,   513,
     540,   514,   162,   515,   516,   165,   166,   167,   168,   169,
     170,   517,   172,   518,   519,   520,   176,   177,   521,   522,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,     0,     7,     8,   245,
     523,   247,   248,   249,   250,   251,   408,   409,     0,    14,
      15,    16,   484,    18,    19,    20,   485,    22,   486,   487,
    1129,   489,   410,    28,   490,    30,    31,     0,    32,    33,
      34,    35,   491,    37,    38,    39,    40,    41,    42,    43,
     492,     0,    45,   493,    47,   494,   495,    50,   496,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   497,   498,    68,     0,    69,    70,    71,
     499,     0,     0,    74,    75,    76,     0,     0,   500,    78,
       0,     0,     0,     0,    80,   501,    82,   502,   503,    85,
      86,  1475,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   504,    97,
      98,   505,   506,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,  1130,     0,     0,     0,  1131,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   507,   120,   121,   508,     0,     0,     0,     0,
       0,     0,     0,   509,   510,   128,     0,     0,     0,   129,
       0,   130,   511,     0,     0,     0,     0,     0,   135,     0,
     136,   137,   138,   139,   512,   141,   142,   143,   144,   145,
     146,     0,     0,  1132,   148,     0,     0,   411,   151,   152,
     153,   154,   155,   156,   157,   158,   513,   160,   514,   162,
     515,   516,   165,   166,   167,   168,   169,   170,   517,   172,
     518,   519,   520,   176,   177,   521,   522,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     0,     0,     7,     8,   245,   523,   247,  1133,
    1134,  1135,  1136,   408,   409,     0,    14,    15,    16,   484,
      18,    19,    20,   485,    22,   486,   487,  1129,   489,   410,
      28,   490,    30,    31,     0,    32,    33,    34,    35,   491,
      37,    38,    39,    40,    41,    42,    43,   492,     0,    45,
     493,    47,   494,   495,    50,   496,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     497,   498,    68,     0,    69,    70,    71,   499,     0,     0,
      74,    75,    76,     0,     0,   500,    78,     0,     0,     0,
       0,    80,   501,    82,   502,   503,    85,    86,  1615,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   504,    97,    98,   505,   506,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
     105,   106,  1130,     0,     0,     0,  1131,     0,     0,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   507,
     120,   121,   508,     0,     0,     0,     0,     0,     0,     0,
     509,   510,   128,     0,     0,     0,   129,     0,   130,   511,
       0,     0,     0,     0,     0,   135,     0,   136,   137,   138,
     139,   512,   141,   142,   143,   144,   145,   146,     0,     0,
    1132,   148,     0,     0,   411,   151,   152,   153,   154,   155,
     156,   157,   158,   513,   160,   514,   162,   515,   516,   165,
     166,   167,   168,   169,   170,   517,   172,   518,   519,   520,
     176,   177,   521,   522,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     7,     8,   245,   523,   247,  1133,  1134,  1135,  1136,
     408,   409,     0,    14,    15,    16,   484,    18,    19,    20,
     485,    22,   486,   487,  1129,   489,   410,    28,   490,    30,
      31,     0,    32,    33,    34,    35,   491,    37,    38,    39,
      40,    41,    42,    43,   492,     0,    45,   493,    47,   494,
     495,    50,   496,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   497,   498,    68,
       0,    69,    70,    71,   499,     0,     0,    74,    75,    76,
       0,     0,   500,    78,     0,     0,     0,     0,    80,   501,
      82,   502,   503,    85,    86,  1619,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   504,    97,    98,   505,   506,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,  1130,
       0,     0,     0,  1131,     0,     0,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   507,   120,   121,   508,
       0,     0,     0,     0,     0,     0,     0,   509,   510,   128,
       0,     0,     0,   129,     0,   130,   511,     0,     0,     0,
       0,     0,   135,     0,   136,   137,   138,   139,   512,   141,
     142,   143,   144,   145,   146,     0,     0,  1132,   148,     0,
       0,   411,   151,   152,   153,   154,   155,   156,   157,   158,
     513,   160,   514,   162,   515,   516,   165,   166,   167,   168,
     169,   170,   517,   172,   518,   519,   520,   176,   177,   521,
     522,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     0,     0,     7,     8,
     245,   523,   247,  1133,  1134,  1135,  1136,   408,   409,     0,
      14,    15,    16,   484,    18,    19,    20,   485,    22,   486,
     487,  1129,   489,   410,    28,   490,    30,    31,     0,    32,
      33,    34,    35,   491,    37,    38,    39,    40,    41,    42,
      43,   492,     0,    45,   493,    47,   494,   495,    50,   496,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,   497,   498,    68,     0,    69,    70,
      71,   499,     0,     0,    74,    75,    76,     0,     0,   500,
      78,     0,     0,     0,     0,    80,   501,    82,   502,   503,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   504,
      97,    98,   505,   506,     0,     0,     0,     0,     0,     0,
     101,   102,   103,     0,   105,   106,  1130,     0,     0,     0,
    1131,     0,     0,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   507,   120,   121,   508,     0,     0,     0,
       0,     0,     0,     0,   509,   510,   128,     0,     0,     0,
     129,     0,   130,   511,     0,     0,     0,     0,     0,   135,
       0,   136,   137,   138,   139,   512,   141,   142,   143,   144,
     145,   146,     0,     0,  1132,   148,     0,     0,   411,   151,
     152,   153,   154,   155,   156,   157,   158,   513,   160,   514,
     162,   515,   516,   165,   166,   167,   168,   169,   170,   517,
     172,   518,   519,   520,   176,   177,   521,   522,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     0,     0,     7,     8,   245,   523,   247,
    1133,  1134,  1135,  1136,   408,   409,     0,    14,    15,    16,
     484,    18,    19,    20,   485,    22,   486,   487,  1129,   489,
     410,    28,   490,    30,    31,     0,    32,    33,    34,    35,
     491,    37,    38,    39,    40,    41,    42,    43,   492,     0,
      45,   493,    47,   494,   495,    50,   496,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   497,   498,    68,     0,    69,    70,    71,   499,     0,
       0,    74,    75,    76,     0,     0,   500,    78,     0,     0,
       0,     0,    80,   501,    82,   502,   503,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   504,    97,    98,   505,
     506,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,  1130,     0,     0,     0,  1131,     0,     0,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     507,   120,   121,   508,     0,     0,     0,     0,     0,     0,
       0,   509,   510,   128,     0,     0,     0,   129,     0,   130,
     511,     0,     0,     0,     0,     0,   135,     0,   136,   137,
     138,   139,   512,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,     0,     0,   411,   151,   152,   153,   154,
     155,   156,   157,   158,   513,   160,   514,   162,   515,   516,
     165,   166,   167,   168,   169,   170,   517,   172,   518,   519,
     520,   176,   177,   521,   522,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       0,     0,     7,     8,   245,   523,   247,  1133,  1134,  1135,
    1136,   408,   409,     0,    14,    15,    16,   532,    18,    19,
      20,   485,   533,   534,   487,   488,   489,   410,    28,   490,
      30,    31,     0,    32,    33,    34,    35,   535,    37,   536,
     537,    40,    41,    42,    43,   492,     0,    45,   538,    47,
     494,   495,    50,   496,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,   497,   498,
      68,     0,    69,    70,    71,   539,     0,     0,    74,    75,
      76,     0,     0,   500,    78,     0,     0,     0,     0,    80,
     501,    82,   502,   503,    85,    86,  1222,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   504,    97,    98,   505,   506,     0,     0,
       0,     0,     0,     0,   101,   102,   103,     0,   105,   106,
     107,     0,     0,     0,     0,     0,     0,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   507,   120,   121,
     508,     0,     0,     0,     0,     0,     0,     0,   509,   510,
     128,     0,     0,     0,   129,     0,   130,   511,     0,     0,
       0,     0,     0,   135,     0,   136,   137,   138,   139,   512,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
       0,     0,   411,   151,   152,   153,   154,   155,   156,   157,
     158,   513,   540,   514,   162,   515,   516,   165,   166,   167,
     168,   169,   170,   517,   172,   518,   519,   520,   176,   177,
     521,   522,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,     0,     0,     7,
       8,   245,   523,   247,   248,   249,   250,   251,   408,   409,
       0,    14,    15,    16,   532,    18,    19,    20,   485,   533,
     534,   487,   488,   489,   410,    28,   490,    30,    31,     0,
      32,    33,    34,    35,   535,    37,   536,   537,    40,    41,
      42,    43,   492,     0,    45,   538,    47,   494,   495,    50,
     496,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,   497,   498,    68,     0,    69,
      70,    71,   539,     0,     0,    74,    75,    76,     0,     0,
     500,    78,     0,     0,     0,     0,    80,   501,    82,   502,
     503,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     504,    97,    98,   505,   506,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,   107,     0,     0,
       0,     0,     0,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   507,   120,   121,   508,     0,     0,
       0,     0,     0,     0,     0,   509,   510,   128,     0,     0,
       0,   129,     0,   130,   511,     0,     0,     0,     0,     0,
     135,     0,   136,   137,   138,   139,   512,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,     0,     0,   411,
     151,   152,   153,   154,   155,   156,   157,   158,   513,   540,
     514,   162,   515,   516,   165,   166,   167,   168,   169,   170,
     517,   172,   518,   519,   520,   176,   177,   521,   522,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,     0,     0,     7,     8,   245,   523,
     247,   248,   249,   250,   251,   408,   409,     0,    14,    15,
      16,     0,    18,    19,    20,   485,     0,     0,   487,   488,
       0,   410,    28,   490,    30,    31,     0,    32,    33,    34,
      35,     0,    37,     0,     0,    40,    41,    42,    43,   492,
       0,    45,     0,    47,     0,     0,    50,   496,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   497,   498,    68,     0,    69,    70,    71,     0,
       0,     0,    74,    75,    76,     0,     0,   500,    78,     0,
       0,     0,     0,    80,   501,    82,   502,   503,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   504,    97,    98,
     505,   506,     0,     0,     0,     0,     0,     0,   101,   102,
     103,     0,   105,   106,     0,     0,     0,     0,     0,     0,
       0,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   507,   120,   121,   508,     0,     0,     0,     0,     0,
       0,     0,   509,   510,   128,     0,     0,     0,   129,     0,
     130,   511,     0,     0,     0,     0,     0,   135,     0,   136,
     137,   138,   139,   512,   141,   142,   143,   144,   145,   146,
       0,     0,     0,   148,     0,     0,   411,   151,   152,   153,
     154,   155,   156,   157,   158,   513,     0,   514,   162,   515,
     516,   165,   166,   167,   168,   169,   170,   517,   172,   518,
     519,   520,   176,   177,     0,   522,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     0,     0,     0,     0,   245,   523,   247,   248,   249,
     250,   251
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,   419,   290,    12,     4,     5,     6,   663,     0,     4,
       5,     6,     4,     5,     6,   417,   418,   310,   179,   752,
    1022,   133,   815,   259,   338,   772,   664,   665,   666,   667,
     258,   614,   615,     4,     5,     6,  1275,   784,   274,  1038,
     581,   459,   460,   853,   752,  1292,   587,    73,   431,  1062,
    1115,   798,  1353,  1354,   979,   642,   929,   644,   645,   442,
     647,   708,   649,   612,   613,   895,   118,    36,  1386,    36,
     657,   658,  1208,   107,   997,   107,   612,   613,   614,   615,
    1305,     1,    39,    55,   467,    26,    27,    44,    45,   945,
       8,   118,     4,     5,     6,    45,   281,  1580,     1,    30,
       1,   142,    59,   107,    61,    62,    47,    93,   108,   107,
     147,     1,    62,    70,    29,   100,   108,     1,    29,    29,
       1,   908,   909,   909,     1,    94,   414,    96,   107,    96,
     107,    26,    27,    74,   224,    26,    27,   108,   224,   224,
      97,   226,   154,   229,   156,   118,    37,    38,    73,    40,
      41,   224,    47,   226,    96,   107,    47,   100,   945,    96,
     122,    56,    87,   153,    96,    56,    57,   169,   106,   216,
      76,   112,   224,   109,   110,    96,   130,   147,   147,    74,
     147,    94,   345,    74,    79,   348,   111,   177,    79,   127,
     188,   153,   979,   106,   156,   110,   108,   183,   123,   201,
     125,   186,   113,   156,   951,   147,   253,     5,   187,   124,
     187,     9,   999,   999,   187,   147,   111,   112,   113,  1520,
     111,   112,   113,   313,   236,  1012,  1012,   313,   313,   341,
     234,   272,     9,    10,   149,   272,   188,   187,   153,   107,
     313,   156,   196,   186,   216,   272,  1729,   153,   169,   160,
     160,  1490,   252,   438,   306,   255,  1258,   175,  1005,   547,
     252,  1579,   177,   255,  1011,  1058,   559,   224,  1493,   160,
     190,  1004,   100,  1272,    96,  1131,   310,    94,   861,   862,
     312,   253,   213,  1296,   931,  1115,  1116,   190,  1213,   190,
     290,  1427,  1305,  1166,  1002,    94,  1004,  1362,   290,  1222,
     190,   719,   272,   272,   891,   272,   190,   243,   244,   190,
     859,   860,   107,   190,   220,   221,  1024,   185,   255,   256,
     346,   107,     9,   349,   107,   123,   103,   125,   219,   107,
     251,   252,   107,   254,     5,   133,    96,    45,     9,    47,
     261,    28,   630,   258,  1131,   286,   123,   169,   125,   158,
     271,   136,   770,   294,   290,   153,   107,   182,   186,   316,
     317,   318,   283,    29,    54,   150,    56,   176,   107,   260,
     195,    79,     1,   609,     3,   107,   153,   107,   160,  1680,
     157,    26,    27,   766,   612,   613,   769,   158,   107,   107,
     107,   286,   187,   107,  1641,   286,   156,   174,   106,   294,
     217,   218,   185,   294,   190,   176,   156,   302,   107,   187,
     100,   302,   187,   107,   414,   232,   107,   194,   217,   218,
    1647,   346,   414,   107,   349,    45,  1213,    47,   107,   251,
     252,  1732,   254,   232,   185,   212,   123,    66,   125,   107,
      33,   153,    71,   443,   110,   445,  1582,   134,   187,   271,
     738,   443,   123,   445,   125,   187,    49,   187,   124,   118,
     168,   283,   133,  1250,  1250,  1212,   153,   112,   187,   187,
     187,   471,   443,   187,   445,   156,   476,  1716,   414,   471,
    1493,   107,   153,   149,   476,   184,   106,  1274,  1274,   118,
     184,  1224,  1719,   895,   107,   153,   187,   268,   107,   424,
     471,   107,   427,   187,   275,   476,   431,   107,   187,   434,
     435,   447,   107,   107,   285,   107,   184,   442,  1101,  1102,
    1103,   457,   924,   448,   449,  1233,  1336,   186,   453,  1339,
     466,   443,  1362,   445,   952,   953,   461,   473,   474,   957,
    1081,  1371,   467,   468,   469,   470,   482,   547,   168,  1685,
     475,   209,  1382,    29,   554,   547,   118,   107,   483,   471,
     250,   187,   554,   851,   476,  1101,  1102,  1103,   107,   987,
     682,   683,     9,   263,   187,   265,   107,   107,   187,   136,
     107,   187,   118,   554,   184,   130,   276,   277,   278,   184,
     280,    28,   282,   187,  1730,   187,   596,    42,   607,   131,
    1602,    46,   107,   528,   596,    52,    51,  1394,  1394,    94,
    1357,   547,   612,   613,   614,   615,   153,   542,   107,   107,
     612,   613,   614,   615,    69,   596,   117,   563,   553,   865,
     630,   859,    37,    38,   110,    40,    41,   187,   630,   575,
     200,  1640,   554,   200,    96,   184,    96,   156,   124,   209,
     186,   196,    57,   184,   184,   146,   581,   184,   190,   595,
     596,   113,   587,   113,    94,  1801,   591,  1803,   159,   154,
      94,   156,   209,   149,    94,    94,  1812,   153,    95,   184,
     156,    94,   129,   144,   166,   156,   123,    53,   125,   106,
    1477,  1477,    58,  1480,  1480,   184,   184,   134,  1491,   116,
     182,   177,   193,  1496,   156,   156,   156,   137,   113,  1442,
     127,    77,   142,  1115,  1116,   176,   153,  1373,   142,  1549,
     993,    94,   995,   168,  1707,  1708,   171,   147,   147,   142,
      96,    42,   193,   106,    53,    46,   158,    24,   738,    58,
      51,   186,   158,   679,   153,   137,   738,    34,   684,   616,
     142,   122,   118,   620,   176,   160,   246,   247,    69,  1342,
     176,   148,   762,   148,    96,  1748,   211,   762,   177,   142,
     762,  1754,  1045,    60,  1047,   942,   198,    96,   165,   269,
     165,   113,   198,   276,   277,   278,   156,   954,   268,   282,
     715,   762,   792,   793,    33,   275,   137,   137,  1086,  1092,
     792,   793,   738,  1117,   729,   285,   182,   100,   733,   734,
      49,   100,   153,   153,   219,   153,   100,   100,   156,   195,
     113,   792,   793,   262,   113,   100,   100,     9,    10,   113,
     113,   756,  1625,   758,   273,  1253,  1629,   837,   113,   113,
     298,   766,   191,   192,   769,   837,   267,   262,   773,   307,
     762,   851,   154,   274,   156,   260,   156,   168,   273,   851,
     171,   870,    53,   231,    42,   233,   837,    58,    46,   122,
     806,   807,   808,    51,   810,   186,  1663,  1663,  1665,  1665,
     792,   793,   137,   153,  1540,  1541,   156,   142,   231,   814,
     233,    69,   156,   685,   153,  1533,   688,   156,   122,   691,
     211,   153,   128,   129,   156,   220,   221,   222,   118,  1696,
    1696,   122,     9,    10,   128,   129,   661,   662,  1711,   668,
     669,   103,   858,     9,    10,   837,   670,   671,   853,  1090,
     122,  1349,   118,  1680,  1095,  1206,  1207,  1570,  1571,  1726,
    1726,   123,   122,   125,   910,   911,   122,   153,   122,   122,
     122,   122,   153,   878,  1741,  1741,  1743,  1743,   215,   156,
    1362,   118,   240,   240,  1252,   241,   156,   313,   153,  1371,
       0,   153,   107,   190,   167,   157,    92,   248,    99,    50,
    1382,   199,   101,   908,   909,   910,   911,   102,   154,   145,
     168,   156,   174,   171,    29,  1651,  1652,   184,    47,   152,
     184,   184,   245,   283,   118,   303,   103,   118,   186,   153,
     187,   283,   194,     1,   118,   142,   107,   103,   187,   153,
     945,   153,   142,   156,   184,   156,   123,   156,   125,   121,
     212,   156,   156,   211,   959,    35,   153,   123,   156,   125,
    1040,  1459,    17,   156,   156,   213,    29,  1335,  1040,   187,
     190,   230,   154,   190,   229,   244,   153,     3,   118,   984,
     157,   168,   170,    70,   170,    94,  1722,   153,   993,  1040,
     995,   157,   997,    94,   999,   230,    94,   174,    29,   149,
     107,   107,   160,   160,   127,   132,  1086,  1012,   174,    94,
     298,  1100,   142,   245,  1086,   118,   132,   194,   187,   184,
     184,  1101,  1102,  1103,   187,   107,  1524,    94,   194,  1101,
    1102,  1103,    96,    45,    96,   212,   132,   184,   187,   187,
    1045,   187,  1047,   187,   140,   141,   212,   143,  1040,   153,
     184,   153,   232,   153,   153,   151,   153,    94,   153,   155,
     236,   157,   224,   230,   142,   190,   162,  1549,    33,   118,
     142,   132,    94,    29,   226,   285,  1081,   170,    94,   298,
     153,   127,   118,   179,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,   147,   118,    94,   253,  1114,   132,
     184,   160,   132,  1471,    96,  1110,   202,   203,   204,   205,
     206,   207,   153,   118,   197,   147,   100,   100,   184,   184,
     190,   142,   121,    35,   153,    29,  1131,   118,   156,   156,
     244,   156,    79,   153,   107,   107,  1216,   257,   259,   284,
     266,  1216,   156,   156,  1216,   156,   156,   156,   156,   156,
     144,    29,   285,    29,    29,   286,   190,   226,   144,   147,
     127,   118,   305,   187,   118,  1216,   147,   147,   187,   187,
     187,    77,  1252,   107,   142,    73,   100,   132,   184,     7,
    1252,   232,   197,  1263,   187,   187,   190,   232,  1263,    87,
     232,  1263,   232,   232,    96,   106,   186,   198,   236,   249,
     187,   249,  1282,   147,   281,    78,   285,  1282,   187,   187,
    1282,   187,  1263,   111,    29,    29,   187,  1222,   187,   107,
     170,  1226,  1302,   187,  1216,   123,   187,   125,   147,   147,
    1302,  1282,  1600,   184,   126,   270,  1241,   126,    96,   184,
     186,   184,   184,  1611,  1612,  1250,  1614,   186,   186,   186,
     153,  1302,   142,  1621,  1334,  1335,   256,   315,   184,  1264,
      94,    29,  1334,  1335,   187,    96,   187,   147,    53,  1274,
     170,  1263,    94,   186,   196,    94,   186,   197,    29,   106,
     118,   107,   279,  1334,   107,   118,    94,   264,   224,   186,
    1282,   286,    94,   118,   224,   196,    93,   196,  1303,   186,
     186,   183,   196,   186,   252,   118,   118,   186,   224,   186,
    1302,   304,   118,   198,   255,  1331,  1332,  1333,   292,   304,
     286,   718,  1327,   305,   255,   258,  1169,   418,   946,   304,
     438,  1336,  1013,  1213,  1339,   305,  1704,  1685,  1730,   854,
    1010,   453,   305,   775,  1452,  1358,  1242,  1715,  1106,  1356,
    1353,  1264,   542,  1269,  1272,  1277,   640,   660,   641,   693,
    1296,   815,  1748,  1754,   911,   446,   995,  1168,  1327,  1337,
     446,  1336,   334,  1382,  1742,  1371,  1549,  1546,  1375,  1116,
    1125,   978,  1191,  1573,  1372,   837,  1417,    -1,    -1,  1394,
      -1,  1471,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1471,
      -1,    -1,    -1,    -1,    -1,    -1,  1774,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1423,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1795,    -1,    -1,
      -1,    -1,  1800,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1449,  1450,    -1,    -1,   346,    -1,
      -1,   349,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1475,    -1,  1477,    -1,    -1,  1480,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,  1492,    -1,    -1,
      -1,    -1,  1497,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1600,    -1,    -1,    -1,    -1,   423,   424,    -1,  1600,   427,
      -1,  1611,  1612,   431,  1614,    -1,   434,   435,    -1,  1611,
    1612,  1621,  1614,    -1,   442,    -1,    -1,    -1,    -1,  1621,
     448,   449,    -1,    -1,    -1,   453,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   461,    -1,    -1,    -1,    -1,    -1,   467,
     468,   469,   470,    -1,    -1,    -1,    -1,   475,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   483,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1615,    -1,  1617,    -1,  1619,    -1,    -1,    -1,    -1,    -1,
      -1,  1626,    -1,    -1,  1704,    -1,  1642,    -1,    -1,    -1,
     528,    -1,  1704,    -1,    -1,  1715,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1715,   542,  1661,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   553,    -1,    -1,  1663,    -1,
    1665,    -1,  1742,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1742,    -1,    -1,    -1,    -1,    -1,  1681,    -1,    -1,  1684,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1696,    -1,   591,  1774,    -1,    -1,    -1,    -1,    -1,
      -1,  1706,  1774,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1795,    -1,    -1,    -1,    -1,
    1800,  1726,    -1,  1795,    -1,    -1,    -1,    -1,  1800,  1734,
      -1,    -1,    -1,    -1,  1739,    -1,  1741,    -1,  1743,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1771,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1787,    -1,    -1,    -1,  1791,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1807,    -1,    -1,  1810,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   712,    -1,    -1,   715,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   729,    -1,    -1,    -1,   733,   734,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   756,    -1,
     758,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   766,    -1,
      -1,   769,    -1,    -1,    -1,   773,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   814,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   554,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   853,    -1,   579,   580,    -1,
      -1,   583,   584,   585,   586,    -1,   588,    -1,    -1,    -1,
      -1,    -1,   594,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     878,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     622,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   630,   631,
     908,   909,   910,   911,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   945,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   959,    -1,    -1,    -1,    -1,    -1,    -1,   690,    -1,
      -1,   693,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   984,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   993,    -1,   995,    -1,   997,
      -1,   999,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   731,
      -1,    -1,    -1,    -1,  1012,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1045,    -1,  1047,
      -1,    -1,   774,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   799,    -1,    -1,
      -1,   803,   804,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     812,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1110,    -1,    -1,   837,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1131,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   880,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1222,   947,    -1,    -1,  1226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1241,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     982,    -1,    -1,    -1,    -1,    -1,  1264,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1274,    -1,    -1,  1001,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1023,    -1,    -1,    -1,  1303,    -1,    -1,    -1,    -1,
      -1,    -1,  1034,  1035,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1049,    -1,  1327,
    1052,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1336,    -1,
      -1,  1339,    -1,    -1,    -1,    -1,  1068,  1069,  1070,    -1,
    1072,  1073,  1074,    -1,  1076,  1077,  1078,  1079,  1080,    -1,
      -1,  1083,  1084,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1394,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1423,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1156,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1449,  1450,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1475,    -1,  1477,
      -1,    -1,  1480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1492,    -1,    -1,    -1,    -1,  1497,
      -1,    -1,    -1,    -1,    -1,    -1,  1228,    -1,  1230,    -1,
    1232,    -1,    -1,  1235,    -1,    -1,    -1,    -1,  1240,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1261,
      -1,    -1,    -1,    -1,    -1,  1267,  1268,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1286,    -1,    -1,  1289,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1615,    -1,  1617,
      -1,  1619,    -1,    -1,    -1,    -1,    -1,    -1,  1626,    -1,
      -1,    -1,    -1,    -1,  1356,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1663,    -1,  1665,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1681,    -1,    -1,  1684,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1696,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1706,    -1,
      -1,    -1,    -1,    -1,  1436,    -1,    -1,    -1,  1440,    -1,
      -1,    -1,  1444,    -1,  1446,    -1,  1448,    -1,  1726,    -1,
      -1,    -1,  1454,    -1,    -1,    -1,  1734,    -1,    -1,    -1,
    1462,  1739,    -1,  1741,    -1,  1743,    -1,    -1,  1470,  1471,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1489,    -1,    -1,
      -1,    -1,    -1,  1771,    -1,    -1,    -1,    -1,  1500,  1501,
    1502,  1503,  1504,    -1,  1506,  1507,    -1,  1509,    -1,  1787,
      -1,    -1,    -1,  1791,  1516,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1525,    -1,    -1,    -1,    -1,    -1,  1807,
      -1,    -1,  1810,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1588,    -1,  1590,    -1,
      -1,  1593,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1601,
      -1,    -1,    -1,    -1,  1606,  1607,    -1,    -1,    -1,    -1,
      -1,    -1,  1614,    -1,    -1,    -1,  1618,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1635,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1648,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,     1,    -1,
       3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1688,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1700,    42,
      -1,    -1,    -1,    46,    -1,    -1,    -1,    50,    51,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    -1,    -1,    69,    -1,    71,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1742,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      -1,    94,    95,    96,    -1,    -1,    99,   100,   101,   102,
      -1,    -1,    -1,   106,   107,    -1,    -1,  1769,    -1,    -1,
     113,    -1,  1774,   116,   117,   118,    -1,  1779,   121,    -1,
      -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,   132,
      -1,    -1,  1794,   136,    -1,    -1,  1798,   140,   141,    -1,
     143,    -1,   145,   146,    -1,    -1,    -1,   150,   151,    -1,
      -1,   154,   155,   156,   157,   158,   159,    -1,    -1,   162,
      -1,    -1,    -1,    -1,   167,   168,    -1,    -1,   171,    -1,
      -1,    -1,    -1,   176,    -1,    -1,   179,    -1,    -1,    -1,
      -1,   184,   185,   186,   187,   188,    -1,   190,   191,   192,
     193,    -1,    -1,    -1,    -1,   198,   199,   200,    -1,   202,
     203,   204,   205,   206,   207,    -1,   209,    -1,   211,    -1,
      -1,    -1,    -1,   216,   217,   218,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,
      -1,   234,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,
     253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    29,   310,    -1,   312,
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
     313,   314,   315,   316,   317,   318,   319,   320,    11,    12,
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
     154,    -1,   156,   157,    -1,   159,   160,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
     174,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,
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
      -1,   156,   157,    -1,   159,   160,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,    -1,    -1,    -1,   193,    -1,
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
      -1,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,    -1,   151,   152,   153,   154,    -1,
     156,   157,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,    -1,    -1,   193,    -1,   195,
      -1,   197,    -1,   199,    -1,   201,   202,   203,   204,   205,
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
      -1,    -1,    -1,    20,    -1,    -1,    -1,    24,    25,    -1,
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
      -1,   188,   189,    -1,    -1,    -1,   193,    -1,   195,    -1,
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
     307,   308,    -1,    -1,    11,    12,   313,   314,   315,   316,
     317,   318,   319,    20,    -1,    -1,    -1,    24,    25,    -1,
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
      -1,   188,   189,    -1,    -1,    -1,   193,    -1,   195,    -1,
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
     307,   308,    -1,    -1,    -1,    16,   313,   314,   315,   316,
     317,   318,   319,    24,    25,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
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
     151,   152,    -1,    -1,    -1,    -1,    -1,    -1,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,   187,   188,   189,    -1,
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
      -1,    16,   313,   314,   315,   316,   317,   318,   319,    24,
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
     315,   316,   317,   318,   319,    18,    19,    -1,    -1,    -1,
      -1,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,
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
     303,   304,   305,   306,   307,   308,    -1,    -1,    -1,    -1,
     313,   314,   315,   316,   317,   318,   319,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    -1,    -1,   100,   101,   102,    -1,
      -1,   105,   106,    -1,    -1,    -1,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,    -1,
     124,    -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,
      -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   147,   148,   149,   150,   151,   152,   153,
     154,    -1,   156,   157,    -1,   159,   160,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
     174,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,    -1,
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
     314,   315,   316,   317,   318,   319,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
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
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,   187,
     188,   189,    -1,    -1,    -1,   193,    -1,   195,    -1,   197,
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
     151,   152,    -1,    -1,    -1,    -1,    -1,    -1,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,   187,   188,   189,    -1,
      -1,    -1,   193,    -1,   195,    -1,   197,   198,   199,   200,
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
      -1,    -1,   186,   187,   188,   189,    -1,    -1,    -1,   193,
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
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,
     137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,    -1,   150,   151,   152,    -1,    -1,    -1,   156,
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
     317,   318,   319,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    -1,    -1,
     100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,
      -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,   139,
      -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,    -1,
     150,   151,   152,    -1,    -1,    -1,   156,    -1,    -1,   159,
     160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,
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
      -1,    24,    25,   313,   314,   315,   316,   317,   318,   319,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    -1,    -1,   100,   101,   102,
      -1,    -1,   105,   106,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,   128,   129,    -1,   131,    -1,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,    -1,   150,   151,   152,
      -1,    -1,    -1,   156,    -1,    -1,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,
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
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,    -1,
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
     305,   306,   307,   308,    -1,    -1,    24,    25,   313,   314,
     315,   316,   317,   318,   319,    33,    34,    -1,    36,    37,
      38,    -1,    40,    41,    42,    43,    -1,    -1,    46,    47,
      -1,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    -1,    60,    -1,    -1,    63,    64,    65,    66,    67,
      -1,    69,    -1,    71,    -1,    -1,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    -1,
      -1,    -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
     128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,
     138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,
     148,    -1,   150,   151,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,
     188,   189,    -1,    -1,    -1,    -1,    -1,   195,    -1,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
      -1,    -1,    -1,   211,    -1,    -1,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,    -1,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,    -1,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
     258,   259,   260,    -1,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,    -1,    -1,    -1,    -1,   313,   314,   315,   316,   317,
     318,   319
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
     318,   319,   320,   332,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   353,   354,   355,   356,   357,   358,   362,   363,   364,
     368,   370,   371,   373,   380,   382,   385,   386,   387,   389,
     390,   391,   392,   393,   395,   396,   398,   399,   400,   401,
     402,   403,   405,   406,   409,   410,   411,   412,   417,   419,
     421,   422,   427,   446,   449,   453,   456,   457,   462,   463,
     464,   465,   467,   468,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   504,   505,   506,   507,   508,   509,
     510,   511,   512,   514,   515,   516,   530,   531,   533,   534,
     535,   536,   537,   538,   539,   547,   548,   549,   550,   551,
     552,   553,   554,   555,   556,   559,   560,   561,   562,   567,
     568,   569,   570,   571,   572,   575,   633,   634,   635,   636,
     638,   639,   640,   641,   642,   649,   650,   651,    33,    34,
      49,   214,   388,   389,   390,   388,   388,   156,   156,    37,
      38,    40,    41,    47,    56,    57,    74,    79,   111,   112,
     113,   160,   219,   260,   286,   294,   302,   369,   370,   374,
     375,   376,   160,   153,   156,   153,   156,   153,   156,     1,
       3,    66,    71,   118,   414,   156,   377,   156,    24,    34,
      60,   118,   272,   426,   428,   429,   153,   156,   156,   156,
     118,   153,   156,   156,   156,    76,   153,   220,   221,   122,
     122,   122,   153,   156,    39,    43,    45,    46,    47,    48,
      51,    59,    67,    70,    72,    73,    75,    90,    91,    97,
     105,   112,   114,   115,   135,   138,   139,   169,   172,   180,
     181,   189,   201,   223,   225,   227,   228,   235,   237,   238,
     239,   242,   243,   314,   498,   649,   650,   122,   118,   397,
     122,   122,    39,    44,    45,    59,    61,    62,    70,    97,
     224,   649,   118,   122,   122,   184,   388,   390,   410,   637,
      48,    72,    73,   118,   153,   185,   243,   409,   411,   421,
     187,   409,   649,   153,   122,    16,   648,   649,    18,    19,
     649,   122,   122,   122,   490,   153,    30,   213,   215,   224,
     226,   313,   156,   224,   226,   313,   224,   313,   224,   229,
     313,   118,   240,   240,   241,   156,   153,   392,   310,   409,
     312,   409,   313,   334,     0,   336,   337,    33,    49,   339,
     356,     1,   190,   333,   190,   333,   112,   371,   391,   409,
     107,   190,   107,   190,    42,    46,    51,    69,   168,   171,
     186,   211,   404,   413,   418,   419,   420,   434,   435,   439,
     167,    92,   132,   140,   141,   143,   151,   155,   157,   162,
     179,   202,   203,   204,   205,   206,   207,   482,   483,   248,
      99,   158,   176,   198,   117,   146,   159,   193,   200,   209,
     136,   150,    50,   199,   101,   102,   158,   176,   481,   153,
     487,   490,   191,   192,   154,   502,   503,   498,   502,   498,
     156,   502,   145,   156,   184,   184,   184,   372,   505,   372,
      29,   647,   182,   195,   182,   195,   166,   182,   650,   649,
     169,   201,    47,   649,   152,   118,    45,    47,    79,   106,
     168,   648,   220,   221,   222,   245,   606,   649,   649,   303,
     137,   142,   112,   286,   294,   374,   648,   389,   390,   187,
     389,    45,    62,   187,   555,   556,   409,   187,   193,   649,
     423,   424,   649,   283,   283,   423,   118,   430,   118,   187,
     378,   379,   153,   394,   409,     1,   160,   647,   113,   160,
     352,   647,   649,   118,   142,   107,   409,    29,   187,   648,
     649,   649,   447,   448,   649,   389,   187,   409,   409,   557,
     649,   389,   153,   153,   409,   187,   193,   649,   649,   142,
     447,   184,   184,   121,   107,   184,   156,   156,   156,   649,
     153,   185,   186,   187,    35,   518,   519,   520,   409,     8,
     175,    17,   409,   213,    29,   410,   410,    39,    45,    59,
      70,    97,   501,   649,   187,   410,   410,   153,   410,   410,
     501,   410,   230,   229,   573,   574,   649,   190,   190,   410,
     409,   390,   409,   244,   407,   408,   310,   312,   154,   190,
     333,   190,   333,     3,   340,   356,   386,   340,   356,   386,
      33,   357,   386,   357,   386,   397,   397,   410,   118,   168,
     170,   170,   391,   410,   410,   464,   465,   467,   467,   467,
     467,   466,   467,   467,   467,    70,   468,   472,   472,   471,
     473,   473,   473,   473,   474,   474,   475,   475,   230,    94,
      94,    94,   184,   409,   490,   490,   409,   503,   187,   410,
     513,   149,   187,   513,   107,   187,   187,   107,   107,   377,
      29,   650,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,   359,   360,   361,    94,   137,   142,   365,   366,
     367,   649,   160,   160,   359,   647,   127,   132,    54,    56,
     100,   250,   263,   265,   276,   277,   278,   280,   282,   607,
     608,   609,   610,   611,   612,   619,   625,   626,   245,    94,
     298,   649,   142,   410,   118,   649,   649,   132,   184,   184,
     187,   187,   184,   107,   187,   107,   187,   107,    36,    94,
      96,   147,   425,   426,   541,   649,    55,   216,   253,   415,
     416,   649,    94,   107,   187,   388,   187,   648,    96,    45,
     648,   647,    96,   142,   541,   649,   410,   429,   184,   187,
     187,   187,   187,   107,   188,   147,   541,   184,   187,   187,
     153,   184,   389,   389,   184,   107,   187,   107,   187,   142,
     541,   410,   188,   410,   410,   409,   409,   409,   649,   519,
     520,   130,   196,   184,   184,   131,   190,    94,   217,   218,
     232,    94,   217,   218,   232,   637,   232,    94,    94,   236,
     224,   230,   107,   234,   142,   190,   187,    48,    72,    73,
     243,   411,   421,   184,   499,   579,   408,   409,   356,    33,
      33,   190,   333,   190,   113,   649,   170,   410,   440,   441,
     118,   436,   437,   467,   153,   156,   258,   486,   505,   580,
     583,   584,   585,   586,   587,   591,   593,   595,   596,    47,
     152,   156,   210,   316,   317,   318,   319,   542,   544,   546,
     547,   563,   564,   565,   566,   643,   644,   645,   646,   649,
     542,   540,   546,   540,   184,   185,   107,   187,   187,   505,
     148,   165,   148,   165,   137,   394,   377,   360,   132,   544,
     367,   410,   541,   647,   647,   128,   129,   647,   276,   277,
     278,   282,   649,   262,   273,   262,   273,    29,   285,    96,
     113,   156,   613,   616,   607,    39,    44,    59,    61,    70,
      97,   224,   316,   317,   318,   381,   547,   643,   226,   298,
     307,   410,   649,    94,   298,   647,   153,   557,   558,   649,
     557,   558,   118,   424,   127,   542,   118,   410,   147,   426,
     147,    36,   147,   425,   426,   147,   541,   253,    53,    58,
      77,   118,   425,   431,   432,   433,   416,   541,   542,   379,
      94,   184,   197,   132,   351,   647,   160,   132,    96,   351,
     410,   142,   426,   153,   118,   410,   410,   147,   100,   450,
     451,   452,   454,   455,   100,   458,   459,   460,   461,   389,
     184,   184,   153,   557,   557,   410,   142,   190,   410,   121,
     187,   187,   187,    35,   520,   130,   196,     9,    10,   103,
     123,   125,   153,   194,   515,   517,   528,   529,   532,    29,
     231,   233,   410,   410,   410,   231,   233,   410,   410,   410,
     184,   410,   410,   410,   410,   410,   501,   118,   410,   410,
     391,   156,   156,   156,   153,   186,   244,   576,   577,   209,
     392,   185,   190,   113,   386,   386,   386,   440,    95,   106,
     116,   127,   442,   443,   444,   445,   107,   649,   107,   409,
     580,   587,   153,   284,   469,   632,    96,   169,   251,   252,
     254,   261,   271,   283,   581,   582,   601,   602,   603,   604,
     627,   630,   257,   259,   588,   606,   266,   592,   628,   246,
     247,   269,   597,   598,   156,   156,   544,   156,   156,   156,
     156,   156,   144,   176,   193,   543,   144,   410,   137,   394,
     559,   366,   285,    29,    96,   113,   156,   620,    29,   613,
     543,   543,   488,   286,   305,   541,   381,   226,   190,   388,
     187,   187,   144,   187,   187,   424,   147,   425,   649,   410,
     147,   410,   127,   410,   147,   426,   147,   410,   147,   118,
     118,   410,   649,   433,    77,   542,   391,   410,   647,   107,
     351,   410,   142,   388,   448,   410,   410,   113,   451,   452,
     100,   186,   113,   452,   455,   118,   542,   100,   113,   459,
     100,   113,   461,   184,   388,   187,   187,   410,   410,   197,
     458,   132,   194,   517,     7,   389,   649,   194,   528,   190,
     232,   232,   232,   232,   232,    96,   236,   236,   574,   186,
     409,   409,   409,   579,   577,   499,   198,   647,   128,   129,
     444,   445,   445,   441,   106,   142,   438,   541,   437,   184,
     187,   580,   594,   249,   216,   253,   267,   274,   631,    96,
     255,   256,   629,   249,   584,   631,   471,   601,   585,   147,
     281,   589,   590,   629,   285,   600,    78,   599,   187,   193,
     542,   545,   187,   187,   187,   187,   187,   187,   187,    29,
     136,   200,   622,   623,   624,    29,   621,   622,   270,   617,
     107,   614,   170,   649,   256,   488,   184,   410,   147,   410,
     147,   425,   410,   147,   410,   410,   649,   649,   432,   410,
     126,   126,    96,   647,   410,   184,   186,   186,   410,   391,
     410,   186,   186,   649,   186,   118,   542,   118,   186,   118,
     542,   186,   184,   113,   520,   649,   194,   184,   520,   649,
     410,   410,   410,   410,   410,   315,   410,   410,   410,   187,
     187,   187,   153,   578,   410,   445,   647,   410,   142,   184,
     473,    52,   129,   471,   471,   268,   275,   285,   605,   605,
     586,   153,   279,    94,   187,   107,   187,   620,   620,   624,
     107,   187,    29,   618,   629,   615,   616,   187,   383,   384,
     488,   118,   224,   306,   286,   170,   410,   410,   147,   410,
      53,   391,   410,   351,   410,   391,    94,   391,   410,   649,
     186,   649,   410,   649,   186,   391,   118,    93,   183,   521,
     520,   649,   196,   520,   410,   197,   458,   409,   438,   410,
     471,   471,   198,   409,   542,   542,    94,    29,   264,   107,
     107,   445,   541,   649,   118,   224,   649,   383,   410,   118,
     542,    94,   186,    94,   649,     5,   133,   524,   525,   527,
     529,    28,   134,   522,   523,   526,   529,   196,   520,   196,
     113,   184,   438,   471,   184,   542,   616,   384,   445,   304,
     649,   118,   224,   649,   186,   542,   391,   410,   542,   186,
      93,   133,   527,   183,   134,   526,   196,   118,   410,   304,
     649,   118,   391,   410,   186,   186,   649,   292,   304,   649,
     186,   305,   410,   305,   488,   488,   198,   286,   649,   224,
     118,   649,   305,   488
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
     585
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   331,   332,   332,   333,   334,   334,   334,   334,   335,
     335,   336,   336,   336,   336,   336,   336,   336,   336,   337,
     337,   337,   337,   338,   339,   339,   339,   340,   340,   340,
     340,   340,   341,   341,   341,   341,   341,   341,   341,   341,
     342,   342,   343,   344,   345,   345,   346,   346,   347,   347,
     348,   348,   348,   348,   349,   349,   349,   350,   350,   350,
     350,   351,   351,   352,   352,   353,   353,   353,   353,   354,
     355,   355,   356,   356,   356,   357,   357,   357,   357,   357,
     357,   357,   357,   358,   358,   359,   359,   360,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   361,   362,   363,
     364,   365,   365,   366,   366,   366,   367,   368,   368,   368,
     369,   369,   369,   369,   370,   370,   371,   371,   371,   371,
     372,   372,   373,   373,   374,   374,   375,   375,   376,   376,
     377,   377,   377,   377,   378,   378,   379,   379,   380,   380,
     380,   380,   381,   381,   381,   381,   382,   382,   383,   383,
     384,   384,   384,   384,   385,   385,   385,   385,   386,   387,
     387,   387,   388,   388,   388,   389,   389,   390,   390,   391,
     391,   391,   391,   391,   391,   391,   391,   391,   391,   391,
     391,   392,   392,   393,   394,   395,   396,   396,   396,   397,
     397,   397,   397,   398,   399,   400,   401,   402,   402,   403,
     404,   405,   406,   407,   407,   408,   409,   409,   410,   410,
     410,   410,   410,   410,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,   412,   413,   414,   414,
     415,   415,   415,   416,   416,   417,   417,   418,   419,   419,
     419,   420,   420,   420,   420,   420,   421,   421,   422,   422,
     422,   423,   423,   423,   424,   424,   424,   424,   424,   424,
     424,   424,   424,   424,   424,   424,   425,   426,   427,   428,
     428,   429,   429,   429,   429,   430,   430,   431,   431,   431,
     432,   432,   432,   433,   433,   433,   434,   435,   436,   436,
     437,   437,   437,   437,   437,   437,   438,   439,   439,   440,
     440,   441,   441,   442,   442,   442,   442,   442,   442,   442,
     443,   443,   444,   444,   445,   446,   446,   447,   447,   448,
     448,   449,   450,   450,   451,   452,   452,   453,   454,   454,
     455,   456,   456,   457,   457,   458,   458,   459,   459,   460,
     460,   461,   461,   462,   463,   463,   464,   464,   465,   465,
     465,   465,   465,   466,   465,   465,   465,   465,   467,   467,
     468,   468,   469,   469,   470,   470,   471,   471,   471,   472,
     472,   472,   472,   472,   473,   473,   473,   474,   474,   474,
     475,   475,   476,   476,   477,   477,   478,   478,   479,   479,
     480,   480,   480,   480,   481,   481,   481,   482,   482,   482,
     482,   482,   482,   483,   483,   483,   484,   484,   484,   484,
     485,   485,   486,   486,   487,   487,   487,   488,   488,   488,
     488,   489,   490,   490,   490,   491,   491,   492,   492,   492,
     492,   493,   493,   494,   494,   494,   494,   494,   494,   494,
     495,   495,   496,   496,   497,   497,   497,   497,   497,   498,
     498,   499,   499,   500,   500,   500,   500,   501,   501,   501,
     501,   502,   502,   503,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   505,   505,
     506,   506,   506,   507,   508,   508,   509,   510,   511,   512,
     512,   513,   513,   514,   514,   515,   515,   515,   516,   516,
     516,   516,   516,   516,   517,   517,   518,   518,   519,   520,
     520,   521,   521,   522,   522,   523,   523,   523,   523,   524,
     524,   525,   525,   525,   525,   526,   526,   527,   527,   528,
     528,   528,   528,   529,   529,   529,   529,   530,   530,   531,
     531,   532,   533,   533,   533,   533,   533,   533,   534,   535,
     535,   536,   536,   537,   538,   539,   539,   540,   540,   541,
     542,   542,   542,   543,   543,   543,   544,   544,   544,   544,
     544,   544,   544,   545,   545,   546,   547,   547,   547,   547,
     547,   547,   547,   547,   547,   548,   549,   549,   549,   550,
     551,   552,   552,   552,   553,   553,   553,   553,   553,   554,
     555,   555,   555,   555,   555,   555,   555,   556,   557,   558,
     559,   560,   560,   561,   562,   563,   563,   564,   565,   565,
     566,   567,   567,   567,   568,   568,   568,   568,   568,   568,
     568,   568,   568,   568,   569,   569,   570,   570,   571,   572,
     573,   573,   574,   575,   576,   576,   577,   578,   579,   579,
     580,   581,   581,   582,   582,   583,   583,   584,   584,   585,
     585,   586,   586,   587,   588,   588,   589,   589,   590,   591,
     591,   591,   592,   592,   593,   594,   594,   595,   596,   596,
     597,   597,   598,   598,   598,   599,   599,   600,   600,   601,
     601,   601,   601,   601,   602,   603,   604,   605,   605,   605,
     606,   606,   607,   607,   607,   607,   607,   607,   607,   607,
     608,   608,   608,   608,   609,   609,   610,   611,   611,   612,
     612,   612,   613,   613,   614,   614,   615,   615,   616,   617,
     617,   618,   618,   619,   619,   619,   620,   620,   621,   621,
     622,   622,   623,   623,   624,   624,   625,   626,   626,   627,
     627,   627,   628,   629,   629,   629,   629,   630,   630,   631,
     631,   632,   633,   633,   634,   634,   635,   635,   636,   637,
     637,   638,   638,   639,   640,   641,   642,   643,   643,   643,
     644,   645,   646,   647,   648,   648,   649,   649,   649,   649,
     649,   649,   649,   649,   649,   649,   649,   649,   649,   649,
     649,   649,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   651
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  xquery_parser::yyr2_[] =
  {
         0,     2,     1,     2,     2,     1,     2,     1,     2,     4,
       6,     3,     3,     5,     1,     3,     3,     5,     5,     1,
       3,     3,     5,     6,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     4,     3,     3,     3,     3,     3,     5,     5,
       5,     5,     5,     5,     1,     1,     3,     3,     4,     5,
       6,     1,     3,     3,     3,     3,     6,     5,     8,     5,
       5,     5,     1,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     3,
       4,     3,     1,     1,     1,     2,     2,     4,     3,     5,
       3,     4,     4,     5,     1,     2,     1,     4,     1,     4,
       1,     3,     2,     3,     1,     1,     4,     4,     5,     5,
       2,     3,     4,     5,     1,     3,     2,     3,     3,     5,
       4,     6,     1,     2,     1,     2,     8,     9,     1,     3,
       1,     2,     2,     3,    11,    14,    13,    22,     1,     1,
       1,     0,     1,     1,     0,     1,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     3,     3,     2,     3,     2,     3,     2,
       3,     4,     5,     5,     2,     4,     5,     3,     3,     2,
       2,     8,     3,     1,     2,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       1,     1,     2,     4,     3,     5,     4,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     3,
       2,     1,     4,     3,     3,     5,     4,     6,     4,     6,
       5,     7,     4,     5,     5,     6,     3,     3,     2,     1,
       3,     4,     5,     3,     6,     4,     5,     1,     2,     3,
       1,     2,     1,     6,     3,     3,     2,     3,     1,     3,
       2,     4,     5,     6,     5,     3,     2,     3,     4,     1,
       3,     1,     2,     1,     1,     1,     2,     2,     2,     3,
       1,     1,     2,     2,     2,     5,     5,     1,     4,     3,
       4,     8,     1,     2,     3,     2,     3,     8,     1,     2,
       3,     8,    10,     8,    10,     1,     2,     4,     7,     1,
       2,     4,     7,     8,     1,     3,     1,     3,     1,     3,
       3,     3,     3,     0,     4,     3,     3,     3,     1,     5,
       1,     3,     0,     1,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     4,     1,     4,     1,     4,     1,     4,     1,     2,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     5,     5,     6,
       3,     4,     1,     2,     3,     2,     2,     1,     2,     2,
       1,     1,     1,     3,     3,     1,     1,     1,     2,     1,
       2,     2,     1,     2,     2,     2,     2,     2,     2,     2,
       1,     2,     2,     1,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       4,     1,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     3,     1,     4,     4,     3,
       4,     1,     3,     1,     1,     1,     1,     1,     4,     5,
       8,     9,     9,    10,     1,     2,     1,     2,     6,     0,
       1,     3,     3,     0,     1,     1,     1,     2,     2,     0,
       1,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     2,     3,
       3,     2,     1,     1,     1,     1,     1,     1,     4,     3,
       7,     3,     7,     4,     4,     3,     7,     1,     2,     2,
       1,     2,     3,     1,     1,     1,     1,     1,     3,     3,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     4,     4,     3,
       3,     3,     4,     4,     3,     4,     6,     4,     6,     4,
       3,     4,     6,     6,     4,     6,     6,     4,     1,     2,
       1,     1,     1,     3,     3,     1,     1,     4,     5,     6,
       3,     3,     3,     3,     5,     7,     7,     5,     5,     5,
       7,     7,     5,     5,     3,     3,     5,     7,     5,     7,
       1,     4,     3,     5,     1,     2,     3,     3,     1,     3,
       2,     0,     1,     1,     2,     1,     3,     1,     3,     1,
       4,     1,     2,     3,     0,     1,     0,     1,     4,     2,
       3,     1,     0,     1,     4,     0,     1,     2,     1,     3,
       0,     1,     2,     2,     1,     0,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     1,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     2,     2,     3,     1,     2,     2,
       5,     2,     1,     1,     0,     2,     1,     3,     4,     0,
       2,     0,     2,     4,     4,     3,     2,     3,     1,     3,
       0,     1,     1,     2,     2,     2,     2,     1,     2,     2,
       2,     2,     3,     2,     3,     3,     4,     2,     2,     1,
       1,     3,     2,     3,     2,     3,     2,     3,     3,     3,
       5,     7,     8,     7,     3,     5,     7,     1,     1,     1,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1
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
  "\"'BOM_UTF8'\"", "RANGE_REDUCE", "SEQUENCE_TYPE_REDUCE",
  "ADDITIVE_REDUCE", "UNION_REDUCE", "INTERSECT_EXCEPT_REDUCE",
  "QVARINDECLLIST_REDUCE", "COMMA_DOLLAR", "UNARY_PREC", "STEP_REDUCE",
  "MULTIPLICATIVE_REDUCE", "$accept", "Module", "ERROR",
  "ModuleWithoutBOM", "VersionDecl", "MainModule", "LibraryModule",
  "ModuleDecl", "SIND_DeclList", "SIND_Decl", "Setter",
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
       332,     0,    -1,   334,    -1,   320,   334,    -1,     1,     3,
      -1,   336,    -1,   335,   336,    -1,   337,    -1,   335,   337,
      -1,   214,   215,    29,   190,    -1,   214,   215,    29,   131,
      29,   190,    -1,   339,   190,   386,    -1,   356,   190,   386,
      -1,   339,   190,   356,   190,   386,    -1,   386,    -1,   339,
     333,   386,    -1,   356,   333,   386,    -1,   339,   190,   356,
     333,   386,    -1,   339,   333,   356,   190,   386,    -1,   338,
      -1,   338,   339,   190,    -1,   338,   356,   190,    -1,   338,
     339,   190,   356,   190,    -1,    34,   160,   648,   132,   647,
     190,    -1,   340,    -1,   339,   190,   340,    -1,   339,   333,
     340,    -1,   341,    -1,   349,    -1,   354,    -1,   355,    -1,
     363,    -1,   342,    -1,   343,    -1,   344,    -1,   345,    -1,
     346,    -1,   347,    -1,   348,    -1,   567,    -1,    33,    38,
     182,    -1,    33,    38,   195,    -1,    33,   113,   106,   647,
      -1,    33,    37,   647,    -1,    33,    40,   182,    -1,    33,
      40,   195,    -1,    33,    57,   169,    -1,    33,    57,   201,
      -1,    33,   113,   168,   127,   128,    -1,    33,   113,   168,
     127,   129,    -1,    33,    41,   182,   107,   148,    -1,    33,
      41,   182,   107,   165,    -1,    33,    41,   166,   107,   148,
      -1,    33,    41,   166,   107,   165,    -1,   350,    -1,   353,
      -1,    49,    24,     1,    -1,    49,    60,   647,    -1,    49,
      60,   352,   647,    -1,    49,    60,   647,    96,   351,    -1,
      49,    60,   352,   647,    96,   351,    -1,   647,    -1,   351,
     107,   647,    -1,   160,   648,   132,    -1,   113,    45,   160,
      -1,    49,    34,   647,    -1,    49,    34,   160,   648,   132,
     647,    -1,    49,    34,   647,    96,   351,    -1,    49,    34,
     160,   648,   132,   647,    96,   351,    -1,    33,   160,   648,
     132,   647,    -1,    33,   113,    45,   160,   647,    -1,    33,
     113,    47,   160,   647,    -1,   357,    -1,   356,   190,   357,
      -1,   356,   333,   357,    -1,   358,    -1,   362,    -1,   364,
      -1,   368,    -1,   373,    -1,   380,    -1,   382,    -1,   385,
      -1,    33,   113,    79,   359,    -1,    33,    79,   649,   359,
      -1,   360,    -1,   359,   360,    -1,   361,   132,   559,    -1,
      80,    -1,    88,    -1,    81,    -1,    82,    -1,    83,    -1,
      84,    -1,    89,    -1,    85,    -1,    86,    -1,    87,    -1,
      33,    56,   649,    29,    -1,    33,   260,   606,    -1,    33,
     111,   152,   365,    -1,    94,   544,   366,    -1,   366,    -1,
     367,    -1,   137,    -1,   137,   367,    -1,   142,   410,    -1,
      33,   369,   142,   410,    -1,    33,   369,   137,    -1,    33,
     369,   137,   142,   410,    -1,   112,   118,   649,    -1,   112,
     118,   649,   541,    -1,   370,   112,   118,   649,    -1,   370,
     112,   118,   649,   541,    -1,   371,    -1,   370,   371,    -1,
      26,    -1,    26,   156,   372,   187,    -1,    27,    -1,    27,
     156,   372,   187,    -1,   505,    -1,   372,   107,   505,    -1,
      33,   374,    -1,    33,   370,   374,    -1,   375,    -1,   376,
      -1,    47,   650,   377,   394,    -1,    47,   650,   377,   137,
      -1,    74,    47,   650,   377,   394,    -1,    74,    47,   650,
     377,   137,    -1,   156,   187,    -1,   156,   378,   187,    -1,
     156,   187,    94,   542,    -1,   156,   378,   187,    94,   542,
      -1,   379,    -1,   378,   107,   379,    -1,   118,   649,    -1,
     118,   649,   541,    -1,    33,   286,   649,    -1,    33,   286,
     649,    94,   381,    -1,    33,   370,   286,   649,    -1,    33,
     370,   286,   649,    94,   381,    -1,   547,    -1,   547,   543,
      -1,   643,    -1,   643,   543,    -1,    33,   294,   649,   298,
     226,   488,   170,   383,    -1,    33,   370,   294,   649,   298,
     226,   488,   170,   383,    -1,   384,    -1,   383,   107,   384,
      -1,   488,    -1,   488,   541,    -1,   488,   445,    -1,   488,
     541,   445,    -1,    33,   302,   303,   649,   298,   286,   649,
     118,   649,   304,   410,    -1,    33,   302,   303,   649,   298,
     286,   649,   224,   118,   649,   304,   292,   305,   488,    -1,
      33,   302,   303,   649,   298,   286,   649,   306,   224,   118,
     649,   304,   410,    -1,    33,   302,   303,   649,   307,   305,
     256,   286,   649,   224,   118,   649,   305,   488,   198,   286,
     649,   224,   118,   649,   305,   488,    -1,   387,    -1,   389,
      -1,   390,    -1,    -1,   389,    -1,   390,    -1,    -1,   409,
      -1,   390,   409,    -1,   391,    -1,   390,   391,    -1,   392,
      -1,   395,    -1,   398,    -1,   399,    -1,   400,    -1,   401,
      -1,   402,    -1,   403,    -1,   405,    -1,   457,    -1,   453,
      -1,   406,    -1,   153,   390,   184,    -1,   153,   184,    -1,
     153,   388,   184,    -1,   153,   388,   184,    -1,   396,   190,
      -1,   396,   107,   397,    -1,   112,   397,    -1,   370,   112,
     397,    -1,   118,   649,    -1,   118,   649,   541,    -1,   118,
     649,   142,   410,    -1,   118,   649,   541,   142,   410,    -1,
     118,   649,   142,   410,   190,    -1,   411,   190,    -1,   239,
     241,   410,   190,    -1,   242,   156,   409,   187,   391,    -1,
     237,   240,   190,    -1,   238,   240,   190,    -1,   421,   404,
      -1,   186,   391,    -1,    48,   156,   409,   187,   197,   391,
     126,   391,    -1,   243,   392,   407,    -1,   408,    -1,   407,
     408,    -1,   244,   579,   392,    -1,   410,    -1,   409,   107,
     410,    -1,   412,    -1,   449,    -1,   456,    -1,   462,    -1,
     575,    -1,   411,    -1,   463,    -1,   446,    -1,   568,    -1,
     569,    -1,   571,    -1,   570,    -1,   572,    -1,   640,    -1,
     638,    -1,   641,    -1,   642,    -1,   639,    -1,   421,   413,
      -1,   186,   410,    -1,    66,   283,    -1,    71,   283,    -1,
     216,    -1,   253,    -1,    55,   253,    -1,   415,   431,    77,
     410,    -1,   415,    77,   410,    -1,    46,   414,   430,   416,
     416,    -1,    46,   414,   430,   416,    -1,    42,   118,   649,
      -1,   422,    -1,   427,    -1,   417,    -1,   419,    -1,   434,
      -1,   439,    -1,   435,    -1,   418,    -1,   419,    -1,   421,
     420,    -1,    46,   118,   423,    -1,    46,     1,   423,    -1,
      46,     3,    -1,   424,    -1,   423,   107,   118,   424,    -1,
     423,   107,   424,    -1,   649,   147,   410,    -1,   649,    36,
     127,   147,   410,    -1,   649,   541,   147,   410,    -1,   649,
     541,    36,   127,   147,   410,    -1,   649,   425,   147,   410,
      -1,   649,    36,   127,   425,   147,   410,    -1,   649,   541,
     425,   147,   410,    -1,   649,   541,    36,   127,   425,   147,
     410,    -1,   649,   426,   147,   410,    -1,   649,   541,   426,
     147,   410,    -1,   649,   425,   426,   147,   410,    -1,   649,
     541,   425,   426,   147,   410,    -1,    96,   118,   649,    -1,
     272,   118,   649,    -1,    51,   428,    -1,   429,    -1,   428,
     107,   429,    -1,   118,   649,   142,   410,    -1,   118,   649,
     541,   142,   410,    -1,   426,   142,   410,    -1,   118,   649,
     541,   426,   142,   410,    -1,   118,   649,   147,   410,    -1,
     118,   649,   541,   147,   410,    -1,   432,    -1,   118,   649,
      -1,   118,   649,   432,    -1,   425,    -1,   425,   433,    -1,
     433,    -1,    58,   118,   649,    53,   118,   649,    -1,    53,
     118,   649,    -1,    58,   118,   649,    -1,   211,   410,    -1,
     171,   170,   436,    -1,   437,    -1,   436,   107,   437,    -1,
     118,   649,    -1,   118,   649,   142,   410,    -1,   118,   649,
     541,   142,   410,    -1,   118,   649,   541,   142,   410,   438,
      -1,   118,   649,   142,   410,   438,    -1,   118,   649,   438,
      -1,   106,   647,    -1,   168,   170,   440,    -1,    69,   168,
     170,   440,    -1,   441,    -1,   440,   107,   441,    -1,   410,
      -1,   410,   442,    -1,   443,    -1,   444,    -1,   445,    -1,
     443,   444,    -1,   443,   445,    -1,   444,   445,    -1,   443,
     444,   445,    -1,    95,    -1,   116,    -1,   127,   128,    -1,
     127,   129,    -1,   106,   647,    -1,    67,   118,   447,   188,
     410,    -1,   135,   118,   447,   188,   410,    -1,   448,    -1,
     447,   107,   118,   448,    -1,   649,   147,   410,    -1,   649,
     541,   147,   410,    -1,    72,   156,   409,   187,   450,   113,
     186,   410,    -1,   451,    -1,   450,   451,    -1,   452,   186,
     410,    -1,   100,   410,    -1,   452,   100,   410,    -1,    72,
     156,   409,   187,   454,   113,   186,   391,    -1,   455,    -1,
     454,   455,    -1,   452,   186,   391,    -1,    73,   156,   409,
     187,   458,   113,   186,   410,    -1,    73,   156,   409,   187,
     458,   113,   118,   649,   186,   410,    -1,    73,   156,   409,
     187,   460,   113,   186,   391,    -1,    73,   156,   409,   187,
     458,   113,   118,   649,   186,   391,    -1,   459,    -1,   458,
     459,    -1,   100,   542,   186,   410,    -1,   100,   118,   649,
      94,   542,   186,   410,    -1,   461,    -1,   460,   461,    -1,
     100,   542,   186,   391,    -1,   100,   118,   649,    94,   542,
     186,   391,    -1,    48,   156,   409,   187,   197,   410,   126,
     410,    -1,   464,    -1,   463,   167,   464,    -1,   465,    -1,
     464,    92,   465,    -1,   467,    -1,   467,   482,   467,    -1,
     467,   483,   467,    -1,   467,   132,   467,    -1,   467,   162,
     467,    -1,    -1,   467,   157,   466,   467,    -1,   467,   155,
     467,    -1,   467,   143,   467,    -1,   467,   141,   467,    -1,
     468,    -1,   468,   248,    70,   580,   469,    -1,   470,    -1,
     470,    99,   468,    -1,    -1,   632,    -1,   471,    -1,   471,
     198,   471,    -1,   472,    -1,   471,   176,   472,    -1,   471,
     158,   472,    -1,   473,    -1,   472,   193,   473,    -1,   472,
     117,   473,    -1,   472,   146,   473,    -1,   472,   159,   473,
      -1,   474,    -1,   473,   200,   474,    -1,   473,   209,   474,
      -1,   475,    -1,   474,   150,   475,    -1,   474,   136,   475,
      -1,   476,    -1,   476,    50,   230,   542,    -1,   477,    -1,
     477,   199,    94,   542,    -1,   478,    -1,   478,   101,    94,
     540,    -1,   479,    -1,   479,   102,    94,   540,    -1,   481,
      -1,   480,   481,    -1,   176,    -1,   158,    -1,   480,   176,
      -1,   480,   158,    -1,   484,    -1,   488,    -1,   485,    -1,
     202,    -1,   207,    -1,   206,    -1,   205,    -1,   204,    -1,
     203,    -1,   151,    -1,   179,    -1,   140,    -1,    75,   153,
     389,   184,    -1,    75,   221,   153,   389,   184,    -1,    75,
     220,   153,   389,   184,    -1,    75,    76,   557,   153,   389,
     184,    -1,   486,   153,   184,    -1,   486,   153,   409,   184,
      -1,   487,    -1,   486,   487,    -1,   177,   649,    17,    -1,
     177,    18,    -1,   177,    19,    -1,   489,    -1,   489,   490,
      -1,   192,   490,    -1,   490,    -1,   191,    -1,   491,    -1,
     491,   191,   490,    -1,   491,   192,   490,    -1,   492,    -1,
     501,    -1,   493,    -1,   493,   502,    -1,   496,    -1,   496,
     502,    -1,   494,   498,    -1,   495,    -1,   105,   122,    -1,
     114,   122,    -1,    97,   122,    -1,   189,   122,    -1,   115,
     122,    -1,   139,   122,    -1,   138,   122,    -1,   498,    -1,
      98,   498,    -1,   497,   498,    -1,   120,    -1,   172,   122,
      -1,    90,   122,    -1,   181,   122,    -1,   180,   122,    -1,
      91,   122,    -1,   547,    -1,   499,    -1,   649,    -1,   500,
      -1,   193,    -1,    11,    -1,    12,    -1,    20,    -1,   504,
      -1,   501,   502,    -1,   501,   156,   187,    -1,   501,   156,
     513,   187,    -1,   503,    -1,   502,   503,    -1,   154,   409,
     185,    -1,   505,    -1,   507,    -1,   508,    -1,   509,    -1,
     512,    -1,   514,    -1,   510,    -1,   511,    -1,   560,    -1,
     393,    -1,   636,    -1,   633,    -1,   634,    -1,   635,    -1,
     506,    -1,   559,    -1,   110,    -1,   149,    -1,   124,    -1,
     118,   649,    -1,   156,   187,    -1,   156,   409,   187,    -1,
     119,    -1,   169,   153,   409,   184,    -1,   201,   153,   409,
     184,    -1,   650,   156,   187,    -1,   650,   156,   513,   187,
      -1,   410,    -1,   513,   107,   410,    -1,   515,    -1,   533,
      -1,   516,    -1,   530,    -1,   531,    -1,   157,   649,   520,
     130,    -1,   157,   649,   518,   520,   130,    -1,   157,   649,
     520,   196,   194,   649,   520,   196,    -1,   157,   649,   520,
     196,   517,   194,   649,   520,   196,    -1,   157,   649,   518,
     520,   196,   194,   649,   520,   196,    -1,   157,   649,   518,
     520,   196,   517,   194,   649,   520,   196,    -1,   528,    -1,
     517,   528,    -1,   519,    -1,   518,   519,    -1,    35,   649,
     520,   132,   520,   521,    -1,    -1,    35,    -1,   183,   522,
     183,    -1,    93,   524,    93,    -1,    -1,   523,    -1,   134,
      -1,   526,    -1,   523,   134,    -1,   523,   526,    -1,    -1,
     525,    -1,   133,    -1,   527,    -1,   525,   133,    -1,   525,
     527,    -1,    28,    -1,   529,    -1,     5,    -1,   529,    -1,
     515,    -1,    10,    -1,   532,    -1,   529,    -1,     9,    -1,
     123,    -1,   125,    -1,   153,   389,   184,    -1,   212,    30,
     213,    -1,   212,   213,    -1,   174,   648,   175,    -1,   174,
     648,     8,    -1,   103,     7,    -1,   534,    -1,   535,    -1,
     536,    -1,   537,    -1,   538,    -1,   539,    -1,    43,   153,
     389,   184,    -1,    21,   388,   184,    -1,    45,   153,   409,
     184,   153,   388,   184,    -1,    22,   388,   184,    -1,    97,
     153,   409,   184,   153,   388,   184,    -1,    70,   153,   389,
     184,    -1,    39,   153,   389,   184,    -1,    23,   388,   184,
      -1,    59,   153,   409,   184,   153,   388,   184,    -1,   546,
      -1,   546,   144,    -1,    94,   542,    -1,   544,    -1,   544,
     543,    -1,   210,   156,   187,    -1,   144,    -1,   193,    -1,
     176,    -1,   546,    -1,   547,    -1,   152,   156,   187,    -1,
     319,   156,   187,    -1,   563,    -1,   566,    -1,   643,    -1,
     542,    -1,   545,   107,   542,    -1,   649,    -1,   549,    -1,
     555,    -1,   553,    -1,   556,    -1,   554,    -1,   552,    -1,
     551,    -1,   550,    -1,   548,    -1,   224,   156,   187,    -1,
      44,   156,   187,    -1,    44,   156,   555,   187,    -1,    44,
     156,   556,   187,    -1,    70,   156,   187,    -1,    39,   156,
     187,    -1,    59,   156,   187,    -1,    59,   156,   648,   187,
      -1,    59,   156,    29,   187,    -1,    97,   156,   187,    -1,
      97,   156,   649,   187,    -1,    97,   156,   649,   107,   557,
     187,    -1,    97,   156,   193,   187,    -1,    97,   156,   193,
     107,   557,   187,    -1,    61,   156,   649,   187,    -1,    45,
     156,   187,    -1,    45,   156,   649,   187,    -1,    45,   156,
     649,   107,   557,   187,    -1,    45,   156,   649,   107,   558,
     187,    -1,    45,   156,   193,   187,    -1,    45,   156,   193,
     107,   557,   187,    -1,    45,   156,   193,   107,   558,   187,
      -1,    62,   156,   649,   187,    -1,   649,    -1,   649,   144,
      -1,    29,    -1,   561,    -1,   562,    -1,   649,   145,   149,
      -1,    47,   377,   394,    -1,   564,    -1,   565,    -1,    47,
     156,   193,   187,    -1,    47,   156,   187,    94,   542,    -1,
      47,   156,   545,   187,    94,   542,    -1,   156,   544,   187,
      -1,    33,   219,   220,    -1,    33,   219,   221,    -1,    33,
     219,   222,    -1,   225,   224,   410,   232,   410,    -1,   225,
     224,   410,    94,   231,   232,   410,    -1,   225,   224,   410,
      94,   233,   232,   410,    -1,   225,   224,   410,   217,   410,
      -1,   225,   224,   410,   218,   410,    -1,   225,   226,   410,
     232,   410,    -1,   225,   226,   410,    94,   231,   232,   410,
      -1,   225,   226,   410,    94,   233,   232,   410,    -1,   225,
     226,   410,   217,   410,    -1,   225,   226,   410,   218,   410,
      -1,   223,   224,   410,    -1,   223,   226,   410,    -1,   228,
     224,   410,   236,   410,    -1,   228,   229,   230,   224,   410,
     236,   410,    -1,   227,   224,   410,    94,   410,    -1,   235,
     118,   573,   234,   410,   186,   410,    -1,   574,    -1,   573,
     107,   118,   574,    -1,   649,   142,   410,    -1,   243,   153,
     409,   184,   576,    -1,   577,    -1,   576,   577,    -1,   244,
     579,   578,    -1,   153,   409,   184,    -1,   499,    -1,   579,
     209,   499,    -1,   583,   581,    -1,    -1,   582,    -1,   601,
      -1,   582,   601,    -1,   584,    -1,   583,   261,   584,    -1,
     585,    -1,   584,   257,   585,    -1,   586,    -1,   585,   259,
     147,   586,    -1,   587,    -1,   258,   587,    -1,   591,   588,
     589,    -1,    -1,   606,    -1,    -1,   590,    -1,   281,   153,
     409,   184,    -1,   595,   592,    -1,   156,   580,   187,    -1,
     593,    -1,    -1,   628,    -1,   486,   153,   594,   184,    -1,
      -1,   580,    -1,   596,   597,    -1,   505,    -1,   153,   409,
     184,    -1,    -1,   598,    -1,   247,   599,    -1,   246,   600,
      -1,   269,    -1,    -1,    78,    -1,    -1,   285,    -1,   602,
      -1,   603,    -1,   604,    -1,   630,    -1,   627,    -1,   169,
      -1,   283,   471,   605,    -1,   252,   629,   605,    -1,   285,
      -1,   275,    -1,   268,    -1,   245,   607,    -1,   606,   245,
     607,    -1,   608,    -1,   609,    -1,   610,    -1,   625,    -1,
     611,    -1,   619,    -1,   612,    -1,   626,    -1,   100,   273,
      -1,   100,   262,    -1,   265,    -1,   280,    -1,   250,   273,
      -1,   250,   262,    -1,    56,   649,    29,    -1,   276,    -1,
      54,   276,    -1,   278,   613,    -1,   278,   156,   613,   614,
     187,    -1,    54,   278,    -1,   616,    -1,   113,    -1,    -1,
     107,   615,    -1,   616,    -1,   615,   107,   616,    -1,    96,
      29,   617,   618,    -1,    -1,   270,    29,    -1,    -1,   629,
     264,    -1,   277,   285,   620,   622,    -1,   277,   285,   113,
     622,    -1,    54,   277,   285,    -1,    96,    29,    -1,   156,
     621,   187,    -1,    29,    -1,   621,   107,    29,    -1,    -1,
     623,    -1,   624,    -1,   623,   624,    -1,   200,   620,    -1,
     136,   620,    -1,   263,    29,    -1,   282,    -1,    54,   282,
      -1,    96,   216,    -1,    96,   253,    -1,   254,   249,    -1,
     266,   629,   279,    -1,   255,   471,    -1,    96,   129,   471,
      -1,    96,    52,   471,    -1,   256,   471,   198,   471,    -1,
     271,   631,    -1,   251,   631,    -1,   274,    -1,   267,    -1,
     284,   249,   473,    -1,   154,   185,    -1,   154,   409,   185,
      -1,   309,   310,    -1,   309,   409,   310,    -1,   311,   312,
      -1,   311,   409,   312,    -1,   153,   637,   184,    -1,   410,
     121,   410,    -1,   637,   107,   410,   121,   410,    -1,   225,
     313,   153,   637,   184,   232,   410,    -1,   225,   313,   410,
     232,   410,    96,   315,   410,    -1,   314,   313,   154,   409,
     185,   198,   410,    -1,   223,   313,   501,    -1,   227,   313,
     501,    94,   410,    -1,   228,   313,   229,   230,   501,   236,
     410,    -1,   644,    -1,   645,    -1,   646,    -1,   318,   156,
     187,    -1,   316,   156,   187,    -1,   317,   156,   187,    -1,
      29,    -1,    16,    -1,   649,    -1,   650,    -1,    97,    -1,
      39,    -1,    44,    -1,    45,    -1,   152,    -1,    48,    -1,
     224,    -1,    59,    -1,    61,    -1,    62,    -1,    70,    -1,
      73,    -1,    72,    -1,   210,    -1,   242,    -1,   651,    -1,
      24,    -1,   214,    -1,   127,    -1,    38,    -1,   260,    -1,
      37,    -1,   221,    -1,   220,    -1,   146,    -1,    43,    -1,
     258,    -1,   259,    -1,   273,    -1,   262,    -1,   250,    -1,
     284,    -1,   276,    -1,   278,    -1,   277,    -1,   282,    -1,
     254,    -1,   249,    -1,    78,    -1,   216,    -1,   253,    -1,
      52,    -1,   222,    -1,   235,    -1,   301,    -1,   229,    -1,
     202,    -1,   207,    -1,   206,    -1,   205,    -1,   204,    -1,
     203,    -1,    96,    -1,   111,    -1,   112,    -1,   186,    -1,
      46,    -1,    36,    -1,    66,    -1,    71,    -1,    58,    -1,
      53,    -1,    55,    -1,    77,    -1,    42,    -1,   147,    -1,
      51,    -1,   211,    -1,   170,    -1,   171,    -1,   168,    -1,
      69,    -1,    95,    -1,   116,    -1,   128,    -1,   129,    -1,
     106,    -1,    67,    -1,   135,    -1,   188,    -1,   100,    -1,
      94,    -1,   197,    -1,   126,    -1,   167,    -1,    92,    -1,
      50,    -1,   230,    -1,   101,    -1,   198,    -1,   117,    -1,
     159,    -1,   200,    -1,   150,    -1,   136,    -1,    75,    -1,
      76,    -1,   102,    -1,   199,    -1,   151,    -1,   182,    -1,
     195,    -1,   160,    -1,   137,    -1,   131,    -1,   166,    -1,
     148,    -1,   165,    -1,    33,    -1,    40,    -1,    57,    -1,
     113,    -1,    41,    -1,    56,    -1,   215,    -1,    49,    -1,
      60,    -1,    34,    -1,    47,    -1,   272,    -1,   248,    -1,
     281,    -1,   283,    -1,   252,    -1,   266,    -1,   279,    -1,
     271,    -1,   251,    -1,   265,    -1,   280,    -1,   270,    -1,
     264,    -1,   263,    -1,   247,    -1,   246,    -1,   255,    -1,
     256,    -1,   285,    -1,   275,    -1,   274,    -1,   269,    -1,
     267,    -1,   268,    -1,   228,    -1,   234,    -1,   231,    -1,
     225,    -1,   218,    -1,   217,    -1,   219,    -1,   236,    -1,
     226,    -1,   227,    -1,   233,    -1,   223,    -1,   232,    -1,
      65,    -1,    63,    -1,    74,    -1,   169,    -1,   201,    -1,
     241,    -1,   239,    -1,   240,    -1,   237,    -1,   238,    -1,
     243,    -1,   244,    -1,   245,    -1,    64,    -1,   294,    -1,
     292,    -1,   293,    -1,   298,    -1,   299,    -1,   300,    -1,
     295,    -1,   296,    -1,   297,    -1,    79,    -1,    80,    -1,
      81,    -1,    82,    -1,    83,    -1,    84,    -1,    85,    -1,
      86,    -1,    87,    -1,    88,    -1,    89,    -1,   286,    -1,
     287,    -1,   288,    -1,   289,    -1,   290,    -1,   291,    -1,
     302,    -1,   303,    -1,   304,    -1,   305,    -1,   306,    -1,
     307,    -1,   308,    -1,    90,    -1,   105,    -1,   114,    -1,
     172,    -1,   180,    -1,   189,    -1,   138,    -1,    91,    -1,
     115,    -1,   139,    -1,   181,    -1,   313,    -1,   314,    -1,
     315,    -1,   318,    -1,   317,    -1,   316,    -1,   319,    -1,
      25,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  xquery_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    11,    13,    16,    18,    21,
      26,    33,    37,    41,    47,    49,    53,    57,    63,    69,
      71,    75,    79,    85,    92,    94,    98,   102,   104,   106,
     108,   110,   112,   114,   116,   118,   120,   122,   124,   126,
     128,   132,   136,   141,   145,   149,   153,   157,   161,   167,
     173,   179,   185,   191,   197,   199,   201,   205,   209,   214,
     220,   227,   229,   233,   237,   241,   245,   252,   258,   267,
     273,   279,   285,   287,   291,   295,   297,   299,   301,   303,
     305,   307,   309,   311,   316,   321,   323,   326,   330,   332,
     334,   336,   338,   340,   342,   344,   346,   348,   350,   355,
     359,   364,   368,   370,   372,   374,   377,   380,   385,   389,
     395,   399,   404,   409,   415,   417,   420,   422,   427,   429,
     434,   436,   440,   443,   447,   449,   451,   456,   461,   467,
     473,   476,   480,   485,   491,   493,   497,   500,   504,   508,
     514,   519,   526,   528,   531,   533,   536,   545,   555,   557,
     561,   563,   566,   569,   573,   585,   600,   614,   637,   639,
     641,   643,   644,   646,   648,   649,   651,   654,   656,   659,
     661,   663,   665,   667,   669,   671,   673,   675,   677,   679,
     681,   683,   687,   690,   694,   698,   701,   705,   708,   712,
     715,   719,   724,   730,   736,   739,   744,   750,   754,   758,
     761,   764,   773,   777,   779,   782,   786,   788,   792,   794,
     796,   798,   800,   802,   804,   806,   808,   810,   812,   814,
     816,   818,   820,   822,   824,   826,   828,   831,   834,   837,
     840,   842,   844,   847,   852,   856,   862,   867,   871,   873,
     875,   877,   879,   881,   883,   885,   887,   889,   892,   896,
     900,   903,   905,   910,   914,   918,   924,   929,   936,   941,
     948,   954,   962,   967,   973,   979,   986,   990,   994,   997,
     999,  1003,  1008,  1014,  1018,  1025,  1030,  1036,  1038,  1041,
    1045,  1047,  1050,  1052,  1059,  1063,  1067,  1070,  1074,  1076,
    1080,  1083,  1088,  1094,  1101,  1107,  1111,  1114,  1118,  1123,
    1125,  1129,  1131,  1134,  1136,  1138,  1140,  1143,  1146,  1149,
    1153,  1155,  1157,  1160,  1163,  1166,  1172,  1178,  1180,  1185,
    1189,  1194,  1203,  1205,  1208,  1212,  1215,  1219,  1228,  1230,
    1233,  1237,  1246,  1257,  1266,  1277,  1279,  1282,  1287,  1295,
    1297,  1300,  1305,  1313,  1322,  1324,  1328,  1330,  1334,  1336,
    1340,  1344,  1348,  1352,  1353,  1358,  1362,  1366,  1370,  1372,
    1378,  1380,  1384,  1385,  1387,  1389,  1393,  1395,  1399,  1403,
    1405,  1409,  1413,  1417,  1421,  1423,  1427,  1431,  1433,  1437,
    1441,  1443,  1448,  1450,  1455,  1457,  1462,  1464,  1469,  1471,
    1474,  1476,  1478,  1481,  1484,  1486,  1488,  1490,  1492,  1494,
    1496,  1498,  1500,  1502,  1504,  1506,  1508,  1513,  1519,  1525,
    1532,  1536,  1541,  1543,  1546,  1550,  1553,  1556,  1558,  1561,
    1564,  1566,  1568,  1570,  1574,  1578,  1580,  1582,  1584,  1587,
    1589,  1592,  1595,  1597,  1600,  1603,  1606,  1609,  1612,  1615,
    1618,  1620,  1623,  1626,  1628,  1631,  1634,  1637,  1640,  1643,
    1645,  1647,  1649,  1651,  1653,  1655,  1657,  1659,  1661,  1664,
    1668,  1673,  1675,  1678,  1682,  1684,  1686,  1688,  1690,  1692,
    1694,  1696,  1698,  1700,  1702,  1704,  1706,  1708,  1710,  1712,
    1714,  1716,  1718,  1720,  1723,  1726,  1730,  1732,  1737,  1742,
    1746,  1751,  1753,  1757,  1759,  1761,  1763,  1765,  1767,  1772,
    1778,  1787,  1797,  1807,  1818,  1820,  1823,  1825,  1828,  1835,
    1836,  1838,  1842,  1846,  1847,  1849,  1851,  1853,  1856,  1859,
    1860,  1862,  1864,  1866,  1869,  1872,  1874,  1876,  1878,  1880,
    1882,  1884,  1886,  1888,  1890,  1892,  1894,  1898,  1902,  1905,
    1909,  1913,  1916,  1918,  1920,  1922,  1924,  1926,  1928,  1933,
    1937,  1945,  1949,  1957,  1962,  1967,  1971,  1979,  1981,  1984,
    1987,  1989,  1992,  1996,  1998,  2000,  2002,  2004,  2006,  2010,
    2014,  2016,  2018,  2020,  2022,  2026,  2028,  2030,  2032,  2034,
    2036,  2038,  2040,  2042,  2044,  2046,  2050,  2054,  2059,  2064,
    2068,  2072,  2076,  2081,  2086,  2090,  2095,  2102,  2107,  2114,
    2119,  2123,  2128,  2135,  2142,  2147,  2154,  2161,  2166,  2168,
    2171,  2173,  2175,  2177,  2181,  2185,  2187,  2189,  2194,  2200,
    2207,  2211,  2215,  2219,  2223,  2229,  2237,  2245,  2251,  2257,
    2263,  2271,  2279,  2285,  2291,  2295,  2299,  2305,  2313,  2319,
    2327,  2329,  2334,  2338,  2344,  2346,  2349,  2353,  2357,  2359,
    2363,  2366,  2367,  2369,  2371,  2374,  2376,  2380,  2382,  2386,
    2388,  2393,  2395,  2398,  2402,  2403,  2405,  2406,  2408,  2413,
    2416,  2420,  2422,  2423,  2425,  2430,  2431,  2433,  2436,  2438,
    2442,  2443,  2445,  2448,  2451,  2453,  2454,  2456,  2457,  2459,
    2461,  2463,  2465,  2467,  2469,  2471,  2475,  2479,  2481,  2483,
    2485,  2488,  2492,  2494,  2496,  2498,  2500,  2502,  2504,  2506,
    2508,  2511,  2514,  2516,  2518,  2521,  2524,  2528,  2530,  2533,
    2536,  2542,  2545,  2547,  2549,  2550,  2553,  2555,  2559,  2564,
    2565,  2568,  2569,  2572,  2577,  2582,  2586,  2589,  2593,  2595,
    2599,  2600,  2602,  2604,  2607,  2610,  2613,  2616,  2618,  2621,
    2624,  2627,  2630,  2634,  2637,  2641,  2645,  2650,  2653,  2656,
    2658,  2660,  2664,  2667,  2671,  2674,  2678,  2681,  2685,  2689,
    2693,  2699,  2707,  2716,  2724,  2728,  2734,  2742,  2744,  2746,
    2748,  2752,  2756,  2760,  2762,  2764,  2766,  2768,  2770,  2772,
    2774,  2776,  2778,  2780,  2782,  2784,  2786,  2788,  2790,  2792,
    2794,  2796,  2798,  2800,  2802,  2804,  2806,  2808,  2810,  2812,
    2814,  2816,  2818,  2820,  2822,  2824,  2826,  2828,  2830,  2832,
    2834,  2836,  2838,  2840,  2842,  2844,  2846,  2848,  2850,  2852,
    2854,  2856,  2858,  2860,  2862,  2864,  2866,  2868,  2870,  2872,
    2874,  2876,  2878,  2880,  2882,  2884,  2886,  2888,  2890,  2892,
    2894,  2896,  2898,  2900,  2902,  2904,  2906,  2908,  2910,  2912,
    2914,  2916,  2918,  2920,  2922,  2924,  2926,  2928,  2930,  2932,
    2934,  2936,  2938,  2940,  2942,  2944,  2946,  2948,  2950,  2952,
    2954,  2956,  2958,  2960,  2962,  2964,  2966,  2968,  2970,  2972,
    2974,  2976,  2978,  2980,  2982,  2984,  2986,  2988,  2990,  2992,
    2994,  2996,  2998,  3000,  3002,  3004,  3006,  3008,  3010,  3012,
    3014,  3016,  3018,  3020,  3022,  3024,  3026,  3028,  3030,  3032,
    3034,  3036,  3038,  3040,  3042,  3044,  3046,  3048,  3050,  3052,
    3054,  3056,  3058,  3060,  3062,  3064,  3066,  3068,  3070,  3072,
    3074,  3076,  3078,  3080,  3082,  3084,  3086,  3088,  3090,  3092,
    3094,  3096,  3098,  3100,  3102,  3104,  3106,  3108,  3110,  3112,
    3114,  3116,  3118,  3120,  3122,  3124,  3126,  3128,  3130,  3132,
    3134,  3136,  3138,  3140,  3142,  3144,  3146,  3148,  3150,  3152,
    3154,  3156,  3158,  3160,  3162,  3164,  3166,  3168,  3170,  3172,
    3174,  3176,  3178,  3180,  3182,  3184,  3186,  3188,  3190,  3192,
    3194,  3196,  3198,  3200,  3202,  3204,  3206,  3208,  3210
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1034,  1034,  1035,  1044,  1053,  1059,  1067,  1073,  1084,
    1089,  1097,  1104,  1111,  1120,  1127,  1135,  1143,  1151,  1162,
    1167,  1174,  1181,  1193,  1203,  1210,  1217,  1229,  1230,  1231,
    1232,  1233,  1238,  1239,  1240,  1241,  1242,  1243,  1244,  1247,
    1252,  1257,  1265,  1273,  1281,  1286,  1294,  1299,  1307,  1312,
    1320,  1327,  1334,  1341,  1351,  1353,  1356,  1366,  1371,  1379,
    1387,  1398,  1405,  1416,  1421,  1429,  1436,  1443,  1452,  1465,
    1473,  1480,  1490,  1497,  1504,  1515,  1516,  1517,  1518,  1519,
    1520,  1521,  1522,  1527,  1533,  1542,  1549,  1559,  1569,  1570,
    1571,  1572,  1573,  1574,  1575,  1576,  1577,  1578,  1583,  1591,
    1599,  1607,  1614,  1622,  1629,  1634,  1642,  1650,  1665,  1680,
    1698,  1703,  1711,  1719,  1730,  1735,  1744,  1749,  1756,  1761,
    1771,  1776,  1785,  1791,  1804,  1809,  1817,  1828,  1843,  1855,
    1870,  1875,  1880,  1885,  1893,  1900,  1911,  1916,  1926,  1933,
    1940,  1947,  1957,  1961,  1967,  1971,  1981,  1989,  2000,  2006,
    2015,  2020,  2027,  2034,  2045,  2055,  2065,  2075,  2093,  2113,
    2117,  2122,  2129,  2133,  2138,  2145,  2150,  2162,  2169,  2181,
    2182,  2183,  2184,  2185,  2186,  2187,  2189,  2190,  2191,  2192,
    2193,  2198,  2203,  2211,  2228,  2236,  2244,  2251,  2258,  2268,
    2280,  2293,  2305,  2321,  2329,  2337,  2345,  2360,  2365,  2373,
    2387,  2404,  2429,  2437,  2444,  2455,  2465,  2470,  2485,  2486,
    2487,  2488,  2489,  2490,  2495,  2496,  2499,  2500,  2501,  2502,
    2503,  2506,  2507,  2508,  2509,  2510,  2515,  2529,  2537,  2542,
    2550,  2555,  2560,  2568,  2577,  2589,  2599,  2612,  2620,  2621,
    2622,  2627,  2628,  2629,  2630,  2631,  2636,  2643,  2653,  2659,
    2667,  2677,  2684,  2692,  2703,  2713,  2723,  2733,  2743,  2753,
    2763,  2773,  2784,  2793,  2803,  2813,  2829,  2838,  2847,  2855,
    2861,  2873,  2881,  2891,  2899,  2911,  2917,  2928,  2930,  2934,
    2942,  2946,  2951,  2955,  2959,  2963,  2973,  2981,  2988,  2994,
    3004,  3008,  3012,  3020,  3028,  3036,  3048,  3056,  3062,  3072,
    3078,  3088,  3092,  3102,  3108,  3114,  3120,  3129,  3138,  3147,
    3160,  3164,  3172,  3178,  3188,  3196,  3205,  3218,  3225,  3237,
    3241,  3253,  3260,  3266,  3275,  3282,  3288,  3299,  3306,  3312,
    3321,  3330,  3337,  3348,  3355,  3367,  3373,  3385,  3391,  3402,
    3408,  3419,  3425,  3436,  3445,  3449,  3458,  3462,  3470,  3474,
    3484,  3491,  3500,  3510,  3509,  3523,  3532,  3541,  3554,  3558,
    3570,  3574,  3582,  3585,  3592,  3596,  3605,  3609,  3613,  3621,
    3625,  3631,  3637,  3643,  3653,  3657,  3661,  3669,  3673,  3679,
    3689,  3693,  3703,  3707,  3717,  3721,  3731,  3735,  3745,  3749,
    3757,  3761,  3765,  3769,  3779,  3783,  3787,  3795,  3799,  3803,
    3807,  3811,  3815,  3823,  3827,  3831,  3839,  3843,  3847,  3851,
    3862,  3868,  3878,  3884,  3894,  3898,  3902,  3940,  3944,  3954,
    3964,  3977,  3986,  3996,  4000,  4009,  4013,  4022,  4028,  4036,
    4042,  4054,  4060,  4070,  4074,  4078,  4082,  4086,  4092,  4098,
    4106,  4110,  4118,  4122,  4133,  4137,  4141,  4147,  4151,  4165,
    4169,  4177,  4181,  4191,  4195,  4199,  4203,  4212,  4216,  4220,
    4224,  4232,  4238,  4248,  4256,  4260,  4264,  4268,  4272,  4276,
    4280,  4284,  4288,  4292,  4297,  4301,  4305,  4309,  4317,  4321,
    4329,  4336,  4343,  4354,  4362,  4366,  4374,  4382,  4390,  4444,
    4448,  4461,  4467,  4477,  4481,  4489,  4493,  4497,  4505,  4515,
    4525,  4542,  4559,  4576,  4598,  4604,  4615,  4621,  4632,  4643,
    4645,  4649,  4654,  4664,  4667,  4674,  4680,  4686,  4694,  4707,
    4710,  4717,  4723,  4729,  4736,  4747,  4751,  4761,  4765,  4775,
    4779,  4783,  4788,  4797,  4803,  4809,  4815,  4823,  4828,  4836,
    4841,  4849,  4857,  4862,  4867,  4872,  4877,  4882,  4891,  4899,
    4903,  4920,  4924,  4932,  4940,  4948,  4952,  4960,  4966,  4976,
    4984,  4988,  4992,  5027,  5033,  5039,  5049,  5053,  5057,  5061,
    5065,  5069,  5073,  5080,  5086,  5096,  5104,  5108,  5112,  5116,
    5120,  5124,  5128,  5132,  5136,  5144,  5152,  5156,  5160,  5170,
    5178,  5186,  5190,  5194,  5202,  5206,  5212,  5218,  5222,  5232,
    5240,  5244,  5250,  5259,  5268,  5274,  5280,  5290,  5307,  5314,
    5329,  5365,  5369,  5377,  5385,  5397,  5401,  5409,  5417,  5421,
    5432,  5449,  5455,  5461,  5471,  5475,  5481,  5487,  5491,  5497,
    5501,  5507,  5513,  5520,  5530,  5535,  5543,  5549,  5559,  5581,
    5590,  5596,  5609,  5623,  5630,  5636,  5646,  5655,  5663,  5669,
    5687,  5695,  5699,  5706,  5711,  5719,  5723,  5730,  5734,  5741,
    5745,  5752,  5756,  5765,  5778,  5781,  5789,  5792,  5800,  5808,
    5816,  5820,  5828,  5831,  5839,  5851,  5854,  5862,  5874,  5880,
    5890,  5893,  5901,  5905,  5909,  5917,  5920,  5928,  5931,  5939,
    5943,  5947,  5951,  5955,  5963,  5971,  5983,  5995,  5999,  6003,
    6011,  6017,  6027,  6031,  6035,  6039,  6043,  6047,  6051,  6055,
    6063,  6067,  6071,  6075,  6083,  6089,  6099,  6109,  6113,  6121,
    6131,  6142,  6149,  6153,  6161,  6164,  6171,  6176,  6185,  6195,
    6198,  6205,  6209,  6217,  6226,  6233,  6243,  6247,  6254,  6260,
    6270,  6273,  6280,  6285,  6297,  6305,  6317,  6325,  6329,  6337,
    6341,  6345,  6353,  6361,  6365,  6369,  6373,  6381,  6389,  6401,
    6405,  6413,  6427,  6431,  6438,  6443,  6451,  6456,  6465,  6473,
    6479,  6489,  6495,  6502,  6509,  6538,  6567,  6596,  6600,  6604,
    6611,  6618,  6625,  6637,  6641,  6642,  6655,  6656,  6657,  6658,
    6659,  6660,  6661,  6662,  6663,  6664,  6665,  6666,  6667,  6668,
    6669,  6670,  6674,  6675,  6676,  6677,  6678,  6679,  6680,  6681,
    6682,  6683,  6684,  6685,  6686,  6687,  6688,  6689,  6690,  6691,
    6692,  6693,  6694,  6695,  6696,  6697,  6698,  6699,  6700,  6701,
    6702,  6703,  6704,  6705,  6706,  6707,  6708,  6709,  6710,  6711,
    6712,  6713,  6714,  6715,  6716,  6717,  6718,  6719,  6720,  6721,
    6722,  6723,  6724,  6725,  6726,  6727,  6728,  6729,  6730,  6731,
    6732,  6733,  6734,  6735,  6736,  6737,  6738,  6739,  6740,  6741,
    6742,  6743,  6744,  6745,  6746,  6747,  6748,  6749,  6750,  6751,
    6752,  6753,  6754,  6755,  6756,  6757,  6758,  6759,  6760,  6761,
    6762,  6763,  6764,  6765,  6766,  6767,  6768,  6769,  6770,  6771,
    6772,  6773,  6774,  6775,  6776,  6777,  6778,  6779,  6780,  6781,
    6782,  6783,  6784,  6785,  6786,  6787,  6788,  6789,  6790,  6791,
    6792,  6793,  6794,  6795,  6796,  6797,  6798,  6799,  6800,  6801,
    6802,  6803,  6804,  6805,  6806,  6807,  6808,  6809,  6810,  6811,
    6812,  6813,  6814,  6815,  6816,  6817,  6818,  6819,  6820,  6821,
    6822,  6823,  6824,  6825,  6826,  6827,  6828,  6829,  6830,  6831,
    6832,  6833,  6834,  6835,  6836,  6837,  6838,  6839,  6840,  6841,
    6842,  6843,  6844,  6845,  6846,  6847,  6848,  6849,  6850,  6851,
    6852,  6853,  6854,  6855,  6856,  6857,  6858,  6859,  6860,  6861,
    6862,  6863,  6864,  6865,  6866,  6867,  6868,  6869,  6870,  6871,
    6872,  6873,  6874,  6875,  6876,  6877,  6878,  6879,  6884
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
     325,   326,   327,   328,   329,   330
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 16101;
  const int xquery_parser::yynnts_ = 321;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 604;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 331;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 585;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 17310 "/home/markos/zorba/repo/jsoniq/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6888 "/home/markos/zorba/repo/jsoniq/src/compiler/parser/xquery_parser.y"


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

