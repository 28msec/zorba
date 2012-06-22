
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
#line 87 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"


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
#line 79 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 317 of lalr1.cc  */
#line 902 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 317 of lalr1.cc  */
#line 1018 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_scanner.h"

#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc  */
#line 109 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"

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
#line 178 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
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
#line 900 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 285 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 124: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 899 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 294 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 149: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 898 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 303 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 335: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 312 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 321 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 330 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 339 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 348 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 357 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 366 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 375 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 384 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 393 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 402 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 411 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 420 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 429 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 438 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 447 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 456 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 465 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 474 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 483 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 492 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 501 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 510 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 519 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 528 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 537 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 546 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 555 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 564 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 573 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 582 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 591 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 600 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 609 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 618 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 627 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 636 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 645 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 654 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 663 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 672 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 681 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 690 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 699 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 708 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 717 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 726 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 735 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 744 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 753 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 762 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 771 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 780 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 789 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 798 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 807 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 816 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 825 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 834 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 843 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 852 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 861 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 870 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 879 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 888 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 897 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 906 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 915 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 924 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 933 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 942 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 951 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 960 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 969 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 978 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 987 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 996 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1005 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1014 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1023 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1032 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1041 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1050 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1059 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1068 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1077 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1086 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1095 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1104 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1113 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1122 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1131 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1140 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1149 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1158 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1167 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1176 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1185 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1194 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1203 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1212 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1221 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1230 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1239 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1248 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1257 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1266 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1275 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1284 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1293 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1302 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1311 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1320 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1329 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1338 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1347 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1356 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1365 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1374 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1383 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1392 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1401 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1410 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1419 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1428 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1437 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1446 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1455 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1464 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1473 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1482 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1491 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1500 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1509 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1518 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1527 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1536 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1545 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1554 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1563 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1572 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1581 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1590 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1599 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1608 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1617 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1626 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1635 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1644 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1653 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1662 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1671 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1680 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1689 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1698 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1707 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1716 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1725 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1734 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1743 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1752 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1761 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1770 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1779 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1788 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1797 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1806 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1815 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1824 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1833 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1842 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1851 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1860 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1869 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1878 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1887 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1896 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1905 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1914 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1923 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1932 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1941 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1950 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1959 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1968 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1977 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1986 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1995 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2004 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2013 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2022 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2031 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2040 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2049 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2058 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2067 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2076 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2085 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2094 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2103 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2112 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2121 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2130 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2139 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2148 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2157 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2166 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2175 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2184 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2193 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2202 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2211 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2220 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2229 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2238 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2247 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2256 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2265 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2274 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2283 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2292 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2301 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2310 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2319 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2328 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2337 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2346 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2355 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2364 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2373 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2382 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2391 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2400 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2409 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2418 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2427 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2436 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2445 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2454 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2463 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2472 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2481 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2490 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2499 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2508 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2517 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2526 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2535 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 610: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2544 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 611: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2553 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 612: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2562 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 616: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2571 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 619: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2580 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2589 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 624: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2598 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 625: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2607 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 626: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2616 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 627: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2625 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 628: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2634 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 629: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2643 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 630: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2652 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 631: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2661 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 632: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2670 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 633: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2679 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 634: /* "JSONSimpleObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2688 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 635: /* "JSONAccumulatorObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2697 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 636: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2706 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 637: /* "JSONPairList" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2715 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 638: /* "JSONInsertExpr" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2724 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 639: /* "JSONAppendExpr" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2733 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 640: /* "JSONDeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2742 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 641: /* "JSONRenameExpr" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2751 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 642: /* "JSONReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2760 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 649: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2769 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 650: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2778 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 651: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2787 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
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
#line 140 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 553 of lalr1.cc  */
#line 2872 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"

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
#line 1036 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 678 of lalr1.cc  */
#line 1045 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 5:

/* Line 678 of lalr1.cc  */
#line 1054 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 6:

/* Line 678 of lalr1.cc  */
#line 1060 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 7:

/* Line 678 of lalr1.cc  */
#line 1068 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 8:

/* Line 678 of lalr1.cc  */
#line 1074 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 9:

/* Line 678 of lalr1.cc  */
#line 1085 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 10:

/* Line 678 of lalr1.cc  */
#line 1090 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 11:

/* Line 678 of lalr1.cc  */
#line 1098 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 12:

/* Line 678 of lalr1.cc  */
#line 1105 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 13:

/* Line 678 of lalr1.cc  */
#line 1112 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 14:

/* Line 678 of lalr1.cc  */
#line 1121 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 15:

/* Line 678 of lalr1.cc  */
#line 1128 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 16:

/* Line 678 of lalr1.cc  */
#line 1136 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 17:

/* Line 678 of lalr1.cc  */
#line 1144 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 18:

/* Line 678 of lalr1.cc  */
#line 1152 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 19:

/* Line 678 of lalr1.cc  */
#line 1163 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 20:

/* Line 678 of lalr1.cc  */
#line 1168 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 21:

/* Line 678 of lalr1.cc  */
#line 1175 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 22:

/* Line 678 of lalr1.cc  */
#line 1182 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 23:

/* Line 678 of lalr1.cc  */
#line 1194 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 24:

/* Line 678 of lalr1.cc  */
#line 1204 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 25:

/* Line 678 of lalr1.cc  */
#line 1211 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 26:

/* Line 678 of lalr1.cc  */
#line 1218 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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
#line 1253 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 41:

/* Line 678 of lalr1.cc  */
#line 1258 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 42:

/* Line 678 of lalr1.cc  */
#line 1266 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 43:

/* Line 678 of lalr1.cc  */
#line 1274 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 44:

/* Line 678 of lalr1.cc  */
#line 1282 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 45:

/* Line 678 of lalr1.cc  */
#line 1287 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 46:

/* Line 678 of lalr1.cc  */
#line 1295 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 47:

/* Line 678 of lalr1.cc  */
#line 1300 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 48:

/* Line 678 of lalr1.cc  */
#line 1308 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 49:

/* Line 678 of lalr1.cc  */
#line 1313 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 50:

/* Line 678 of lalr1.cc  */
#line 1321 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 51:

/* Line 678 of lalr1.cc  */
#line 1328 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 52:

/* Line 678 of lalr1.cc  */
#line 1335 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 53:

/* Line 678 of lalr1.cc  */
#line 1342 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 56:

/* Line 678 of lalr1.cc  */
#line 1357 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 57:

/* Line 678 of lalr1.cc  */
#line 1367 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 58:

/* Line 678 of lalr1.cc  */
#line 1372 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 59:

/* Line 678 of lalr1.cc  */
#line 1380 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 60:

/* Line 678 of lalr1.cc  */
#line 1388 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 61:

/* Line 678 of lalr1.cc  */
#line 1399 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 62:

/* Line 678 of lalr1.cc  */
#line 1406 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 63:

/* Line 678 of lalr1.cc  */
#line 1417 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 64:

/* Line 678 of lalr1.cc  */
#line 1422 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 65:

/* Line 678 of lalr1.cc  */
#line 1430 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 66:

/* Line 678 of lalr1.cc  */
#line 1437 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 67:

/* Line 678 of lalr1.cc  */
#line 1444 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 68:

/* Line 678 of lalr1.cc  */
#line 1453 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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
#line 1466 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 70:

/* Line 678 of lalr1.cc  */
#line 1474 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 71:

/* Line 678 of lalr1.cc  */
#line 1481 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 72:

/* Line 678 of lalr1.cc  */
#line 1491 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 73:

/* Line 678 of lalr1.cc  */
#line 1498 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 74:

/* Line 678 of lalr1.cc  */
#line 1505 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 83:

/* Line 678 of lalr1.cc  */
#line 1528 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 84:

/* Line 678 of lalr1.cc  */
#line 1534 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 85:

/* Line 678 of lalr1.cc  */
#line 1543 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 86:

/* Line 678 of lalr1.cc  */
#line 1550 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 87:

/* Line 678 of lalr1.cc  */
#line 1560 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 88:

/* Line 678 of lalr1.cc  */
#line 1569 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 89:

/* Line 678 of lalr1.cc  */
#line 1570 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 90:

/* Line 678 of lalr1.cc  */
#line 1571 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 91:

/* Line 678 of lalr1.cc  */
#line 1572 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 92:

/* Line 678 of lalr1.cc  */
#line 1573 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 93:

/* Line 678 of lalr1.cc  */
#line 1574 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 94:

/* Line 678 of lalr1.cc  */
#line 1575 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 95:

/* Line 678 of lalr1.cc  */
#line 1576 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 96:

/* Line 678 of lalr1.cc  */
#line 1577 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 97:

/* Line 678 of lalr1.cc  */
#line 1578 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 98:

/* Line 678 of lalr1.cc  */
#line 1584 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 99:

/* Line 678 of lalr1.cc  */
#line 1592 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 100:

/* Line 678 of lalr1.cc  */
#line 1600 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 101:

/* Line 678 of lalr1.cc  */
#line 1608 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 102:

/* Line 678 of lalr1.cc  */
#line 1615 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 103:

/* Line 678 of lalr1.cc  */
#line 1623 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 104:

/* Line 678 of lalr1.cc  */
#line 1630 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 105:

/* Line 678 of lalr1.cc  */
#line 1635 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 106:

/* Line 678 of lalr1.cc  */
#line 1643 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 107:

/* Line 678 of lalr1.cc  */
#line 1651 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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
#line 1666 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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
#line 1681 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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
#line 1699 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 111:

/* Line 678 of lalr1.cc  */
#line 1704 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 112:

/* Line 678 of lalr1.cc  */
#line 1712 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 113:

/* Line 678 of lalr1.cc  */
#line 1720 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 114:

/* Line 678 of lalr1.cc  */
#line 1731 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 115:

/* Line 678 of lalr1.cc  */
#line 1736 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 116:

/* Line 678 of lalr1.cc  */
#line 1745 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 117:

/* Line 678 of lalr1.cc  */
#line 1750 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 118:

/* Line 678 of lalr1.cc  */
#line 1757 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 119:

/* Line 678 of lalr1.cc  */
#line 1762 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 120:

/* Line 678 of lalr1.cc  */
#line 1772 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 121:

/* Line 678 of lalr1.cc  */
#line 1777 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 122:

/* Line 678 of lalr1.cc  */
#line 1786 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 123:

/* Line 678 of lalr1.cc  */
#line 1792 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 124:

/* Line 678 of lalr1.cc  */
#line 1805 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 125:

/* Line 678 of lalr1.cc  */
#line 1810 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 126:

/* Line 678 of lalr1.cc  */
#line 1818 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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
#line 1829 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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
#line 1844 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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
#line 1856 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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
#line 1871 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 131:

/* Line 678 of lalr1.cc  */
#line 1876 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 132:

/* Line 678 of lalr1.cc  */
#line 1881 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 133:

/* Line 678 of lalr1.cc  */
#line 1886 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 134:

/* Line 678 of lalr1.cc  */
#line 1894 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 135:

/* Line 678 of lalr1.cc  */
#line 1901 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 136:

/* Line 678 of lalr1.cc  */
#line 1912 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 137:

/* Line 678 of lalr1.cc  */
#line 1917 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 138:

/* Line 678 of lalr1.cc  */
#line 1927 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL);
    }
    break;

  case 139:

/* Line 678 of lalr1.cc  */
#line 1934 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 140:

/* Line 678 of lalr1.cc  */
#line 1941 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0);
    }
    break;

  case 141:

/* Line 678 of lalr1.cc  */
#line 1948 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 142:

/* Line 678 of lalr1.cc  */
#line 1958 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 143:

/* Line 678 of lalr1.cc  */
#line 1962 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 144:

/* Line 678 of lalr1.cc  */
#line 1972 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                             (yysemantic_stack_[(8) - (6)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                             NULL);
    }
    break;

  case 145:

/* Line 678 of lalr1.cc  */
#line 1980 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(9) - (4)].expr)),
                             (yysemantic_stack_[(9) - (7)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(9) - (9)].node)),
                             static_cast<AnnotationListParsenode*>((yysemantic_stack_[(9) - (2)].node)));
    }
    break;

  case 146:

/* Line 678 of lalr1.cc  */
#line 1991 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 147:

/* Line 678 of lalr1.cc  */
#line 1997 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 148:

/* Line 678 of lalr1.cc  */
#line 2006 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 149:

/* Line 678 of lalr1.cc  */
#line 2011 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 150:

/* Line 678 of lalr1.cc  */
#line 2018 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 151:

/* Line 678 of lalr1.cc  */
#line 2025 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 152:

/* Line 678 of lalr1.cc  */
#line 2037 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 153:

/* Line 678 of lalr1.cc  */
#line 2047 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 154:

/* Line 678 of lalr1.cc  */
#line 2057 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 155:

/* Line 678 of lalr1.cc  */
#line 2068 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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

  case 156:

/* Line 678 of lalr1.cc  */
#line 2084 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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

  case 157:

/* Line 678 of lalr1.cc  */
#line 2104 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 158:

/* Line 678 of lalr1.cc  */
#line 2108 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 159:

/* Line 678 of lalr1.cc  */
#line 2112 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 160:

/* Line 678 of lalr1.cc  */
#line 2120 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 161:

/* Line 678 of lalr1.cc  */
#line 2124 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 162:

/* Line 678 of lalr1.cc  */
#line 2128 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 163:

/* Line 678 of lalr1.cc  */
#line 2136 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:

/* Line 678 of lalr1.cc  */
#line 2141 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 165:

/* Line 678 of lalr1.cc  */
#line 2153 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 166:

/* Line 678 of lalr1.cc  */
#line 2160 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 179:

/* Line 678 of lalr1.cc  */
#line 2189 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 180:

/* Line 678 of lalr1.cc  */
#line 2194 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 181:

/* Line 678 of lalr1.cc  */
#line 2202 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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

  case 182:

/* Line 678 of lalr1.cc  */
#line 2219 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 183:

/* Line 678 of lalr1.cc  */
#line 2227 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 184:

/* Line 678 of lalr1.cc  */
#line 2235 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 185:

/* Line 678 of lalr1.cc  */
#line 2242 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 186:

/* Line 678 of lalr1.cc  */
#line 2249 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 187:

/* Line 678 of lalr1.cc  */
#line 2259 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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

  case 188:

/* Line 678 of lalr1.cc  */
#line 2271 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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

  case 189:

/* Line 678 of lalr1.cc  */
#line 2284 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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

  case 190:

/* Line 678 of lalr1.cc  */
#line 2296 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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

  case 191:

/* Line 678 of lalr1.cc  */
#line 2312 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 192:

/* Line 678 of lalr1.cc  */
#line 2320 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 193:

/* Line 678 of lalr1.cc  */
#line 2328 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 194:

/* Line 678 of lalr1.cc  */
#line 2336 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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

  case 195:

/* Line 678 of lalr1.cc  */
#line 2351 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 196:

/* Line 678 of lalr1.cc  */
#line 2356 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 197:

/* Line 678 of lalr1.cc  */
#line 2364 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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

  case 198:

/* Line 678 of lalr1.cc  */
#line 2378 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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

  case 199:

/* Line 678 of lalr1.cc  */
#line 2395 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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

  case 200:

/* Line 678 of lalr1.cc  */
#line 2420 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 201:

/* Line 678 of lalr1.cc  */
#line 2428 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 202:

/* Line 678 of lalr1.cc  */
#line 2435 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 203:

/* Line 678 of lalr1.cc  */
#line 2446 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 204:

/* Line 678 of lalr1.cc  */
#line 2456 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 205:

/* Line 678 of lalr1.cc  */
#line 2461 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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

  case 224:

/* Line 678 of lalr1.cc  */
#line 2506 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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

  case 225:

/* Line 678 of lalr1.cc  */
#line 2520 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 226:

/* Line 678 of lalr1.cc  */
#line 2528 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 227:

/* Line 678 of lalr1.cc  */
#line 2533 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 228:

/* Line 678 of lalr1.cc  */
#line 2541 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 229:

/* Line 678 of lalr1.cc  */
#line 2546 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 230:

/* Line 678 of lalr1.cc  */
#line 2551 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 231:

/* Line 678 of lalr1.cc  */
#line 2559 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)),
                            (yysemantic_stack_[(4) - (4)].expr),
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 232:

/* Line 678 of lalr1.cc  */
#line 2568 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            NULL,
                            (yysemantic_stack_[(3) - (3)].expr),
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 233:

/* Line 678 of lalr1.cc  */
#line 2580 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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

  case 234:

/* Line 678 of lalr1.cc  */
#line 2590 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 235:

/* Line 678 of lalr1.cc  */
#line 2603 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 244:

/* Line 678 of lalr1.cc  */
#line 2627 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 245:

/* Line 678 of lalr1.cc  */
#line 2634 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 246:

/* Line 678 of lalr1.cc  */
#line 2644 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 247:

/* Line 678 of lalr1.cc  */
#line 2652 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 248:

/* Line 678 of lalr1.cc  */
#line 2659 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 249:

/* Line 678 of lalr1.cc  */
#line 2669 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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

  case 250:

/* Line 678 of lalr1.cc  */
#line 2679 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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

  case 251:

/* Line 678 of lalr1.cc  */
#line 2689 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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

  case 252:

/* Line 678 of lalr1.cc  */
#line 2699 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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

  case 253:

/* Line 678 of lalr1.cc  */
#line 2709 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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

  case 254:

/* Line 678 of lalr1.cc  */
#line 2719 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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

  case 255:

/* Line 678 of lalr1.cc  */
#line 2729 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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

  case 256:

/* Line 678 of lalr1.cc  */
#line 2739 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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

  case 257:

/* Line 678 of lalr1.cc  */
#line 2750 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 258:

/* Line 678 of lalr1.cc  */
#line 2759 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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

  case 259:

/* Line 678 of lalr1.cc  */
#line 2769 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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

  case 260:

/* Line 678 of lalr1.cc  */
#line 2779 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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

  case 261:

/* Line 678 of lalr1.cc  */
#line 2795 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 262:

/* Line 678 of lalr1.cc  */
#line 2804 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 263:

/* Line 678 of lalr1.cc  */
#line 2813 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 264:

/* Line 678 of lalr1.cc  */
#line 2821 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 265:

/* Line 678 of lalr1.cc  */
#line 2827 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 266:

/* Line 678 of lalr1.cc  */
#line 2839 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 267:

/* Line 678 of lalr1.cc  */
#line 2847 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 268:

/* Line 678 of lalr1.cc  */
#line 2857 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 269:

/* Line 678 of lalr1.cc  */
#line 2865 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 270:

/* Line 678 of lalr1.cc  */
#line 2877 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 271:

/* Line 678 of lalr1.cc  */
#line 2883 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 273:

/* Line 678 of lalr1.cc  */
#line 2896 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 274:

/* Line 678 of lalr1.cc  */
#line 2900 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 275:

/* Line 678 of lalr1.cc  */
#line 2908 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 276:

/* Line 678 of lalr1.cc  */
#line 2912 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 278:

/* Line 678 of lalr1.cc  */
#line 2921 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 279:

/* Line 678 of lalr1.cc  */
#line 2925 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 280:

/* Line 678 of lalr1.cc  */
#line 2929 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 281:

/* Line 678 of lalr1.cc  */
#line 2939 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 282:

/* Line 678 of lalr1.cc  */
#line 2947 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 283:

/* Line 678 of lalr1.cc  */
#line 2954 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 284:

/* Line 678 of lalr1.cc  */
#line 2960 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 285:

/* Line 678 of lalr1.cc  */
#line 2970 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
    }
    break;

  case 286:

/* Line 678 of lalr1.cc  */
#line 2974 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 287:

/* Line 678 of lalr1.cc  */
#line 2978 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         NULL);
    }
    break;

  case 288:

/* Line 678 of lalr1.cc  */
#line 2986 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(6) - (3)].node)),
                         (yysemantic_stack_[(6) - (5)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 289:

/* Line 678 of lalr1.cc  */
#line 2994 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         NULL,
                         (yysemantic_stack_[(5) - (4)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 290:

/* Line 678 of lalr1.cc  */
#line 3002 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         NULL,
                         NULL,
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 291:

/* Line 678 of lalr1.cc  */
#line 3014 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 292:

/* Line 678 of lalr1.cc  */
#line 3022 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 293:

/* Line 678 of lalr1.cc  */
#line 3028 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 294:

/* Line 678 of lalr1.cc  */
#line 3038 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 295:

/* Line 678 of lalr1.cc  */
#line 3044 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 296:

/* Line 678 of lalr1.cc  */
#line 3054 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 297:

/* Line 678 of lalr1.cc  */
#line 3058 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 298:

/* Line 678 of lalr1.cc  */
#line 3068 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 299:

/* Line 678 of lalr1.cc  */
#line 3074 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 300:

/* Line 678 of lalr1.cc  */
#line 3080 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 301:

/* Line 678 of lalr1.cc  */
#line 3086 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 302:

/* Line 678 of lalr1.cc  */
#line 3095 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 303:

/* Line 678 of lalr1.cc  */
#line 3104 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 304:

/* Line 678 of lalr1.cc  */
#line 3113 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 305:

/* Line 678 of lalr1.cc  */
#line 3126 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 306:

/* Line 678 of lalr1.cc  */
#line 3130 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 307:

/* Line 678 of lalr1.cc  */
#line 3138 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 308:

/* Line 678 of lalr1.cc  */
#line 3144 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 309:

/* Line 678 of lalr1.cc  */
#line 3154 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 310:

/* Line 678 of lalr1.cc  */
#line 3162 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 311:

/* Line 678 of lalr1.cc  */
#line 3171 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 312:

/* Line 678 of lalr1.cc  */
#line 3184 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 313:

/* Line 678 of lalr1.cc  */
#line 3191 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 314:

/* Line 678 of lalr1.cc  */
#line 3203 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 315:

/* Line 678 of lalr1.cc  */
#line 3207 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 316:

/* Line 678 of lalr1.cc  */
#line 3219 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 317:

/* Line 678 of lalr1.cc  */
#line 3226 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 318:

/* Line 678 of lalr1.cc  */
#line 3232 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 319:

/* Line 678 of lalr1.cc  */
#line 3241 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 320:

/* Line 678 of lalr1.cc  */
#line 3248 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 321:

/* Line 678 of lalr1.cc  */
#line 3254 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 322:

/* Line 678 of lalr1.cc  */
#line 3265 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 323:

/* Line 678 of lalr1.cc  */
#line 3272 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 324:

/* Line 678 of lalr1.cc  */
#line 3278 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 325:

/* Line 678 of lalr1.cc  */
#line 3287 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 326:

/* Line 678 of lalr1.cc  */
#line 3296 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 327:

/* Line 678 of lalr1.cc  */
#line 3303 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 328:

/* Line 678 of lalr1.cc  */
#line 3314 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 329:

/* Line 678 of lalr1.cc  */
#line 3321 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 330:

/* Line 678 of lalr1.cc  */
#line 3333 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 331:

/* Line 678 of lalr1.cc  */
#line 3339 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 332:

/* Line 678 of lalr1.cc  */
#line 3351 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 333:

/* Line 678 of lalr1.cc  */
#line 3357 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 334:

/* Line 678 of lalr1.cc  */
#line 3368 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 335:

/* Line 678 of lalr1.cc  */
#line 3374 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 336:

/* Line 678 of lalr1.cc  */
#line 3385 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 337:

/* Line 678 of lalr1.cc  */
#line 3391 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 338:

/* Line 678 of lalr1.cc  */
#line 3402 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 339:

/* Line 678 of lalr1.cc  */
#line 3411 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 340:

/* Line 678 of lalr1.cc  */
#line 3415 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 341:

/* Line 678 of lalr1.cc  */
#line 3424 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 342:

/* Line 678 of lalr1.cc  */
#line 3428 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 343:

/* Line 678 of lalr1.cc  */
#line 3436 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 344:

/* Line 678 of lalr1.cc  */
#line 3440 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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

  case 345:

/* Line 678 of lalr1.cc  */
#line 3450 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 346:

/* Line 678 of lalr1.cc  */
#line 3457 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 347:

/* Line 678 of lalr1.cc  */
#line 3466 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 348:

/* Line 678 of lalr1.cc  */
#line 3475 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 349:

/* Line 678 of lalr1.cc  */
#line 3480 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 350:

/* Line 678 of lalr1.cc  */
#line 3489 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 351:

/* Line 678 of lalr1.cc  */
#line 3498 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 352:

/* Line 678 of lalr1.cc  */
#line 3507 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 353:

/* Line 678 of lalr1.cc  */
#line 3520 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 354:

/* Line 678 of lalr1.cc  */
#line 3524 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 355:

/* Line 678 of lalr1.cc  */
#line 3536 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 356:

/* Line 678 of lalr1.cc  */
#line 3540 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 357:

/* Line 678 of lalr1.cc  */
#line 3547 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 358:

/* Line 678 of lalr1.cc  */
#line 3551 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 359:

/* Line 678 of lalr1.cc  */
#line 3558 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 360:

/* Line 678 of lalr1.cc  */
#line 3562 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 361:

/* Line 678 of lalr1.cc  */
#line 3571 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 362:

/* Line 678 of lalr1.cc  */
#line 3575 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 363:

/* Line 678 of lalr1.cc  */
#line 3579 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 364:

/* Line 678 of lalr1.cc  */
#line 3587 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 365:

/* Line 678 of lalr1.cc  */
#line 3591 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 366:

/* Line 678 of lalr1.cc  */
#line 3597 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 367:

/* Line 678 of lalr1.cc  */
#line 3603 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 368:

/* Line 678 of lalr1.cc  */
#line 3609 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 369:

/* Line 678 of lalr1.cc  */
#line 3619 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 370:

/* Line 678 of lalr1.cc  */
#line 3623 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 371:

/* Line 678 of lalr1.cc  */
#line 3627 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 372:

/* Line 678 of lalr1.cc  */
#line 3635 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 373:

/* Line 678 of lalr1.cc  */
#line 3639 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 374:

/* Line 678 of lalr1.cc  */
#line 3645 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 375:

/* Line 678 of lalr1.cc  */
#line 3655 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 376:

/* Line 678 of lalr1.cc  */
#line 3659 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 377:

/* Line 678 of lalr1.cc  */
#line 3669 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 378:

/* Line 678 of lalr1.cc  */
#line 3673 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 379:

/* Line 678 of lalr1.cc  */
#line 3683 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 380:

/* Line 678 of lalr1.cc  */
#line 3687 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 381:

/* Line 678 of lalr1.cc  */
#line 3697 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 382:

/* Line 678 of lalr1.cc  */
#line 3701 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 383:

/* Line 678 of lalr1.cc  */
#line 3711 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 384:

/* Line 678 of lalr1.cc  */
#line 3715 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 385:

/* Line 678 of lalr1.cc  */
#line 3723 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 386:

/* Line 678 of lalr1.cc  */
#line 3727 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 387:

/* Line 678 of lalr1.cc  */
#line 3731 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 388:

/* Line 678 of lalr1.cc  */
#line 3735 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 389:

/* Line 678 of lalr1.cc  */
#line 3745 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 390:

/* Line 678 of lalr1.cc  */
#line 3749 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:

/* Line 678 of lalr1.cc  */
#line 3753 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 392:

/* Line 678 of lalr1.cc  */
#line 3761 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 393:

/* Line 678 of lalr1.cc  */
#line 3765 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 394:

/* Line 678 of lalr1.cc  */
#line 3769 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 395:

/* Line 678 of lalr1.cc  */
#line 3773 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 396:

/* Line 678 of lalr1.cc  */
#line 3777 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 397:

/* Line 678 of lalr1.cc  */
#line 3781 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 398:

/* Line 678 of lalr1.cc  */
#line 3789 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 399:

/* Line 678 of lalr1.cc  */
#line 3793 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 400:

/* Line 678 of lalr1.cc  */
#line 3797 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 401:

/* Line 678 of lalr1.cc  */
#line 3805 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 402:

/* Line 678 of lalr1.cc  */
#line 3809 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 403:

/* Line 678 of lalr1.cc  */
#line 3813 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 404:

/* Line 678 of lalr1.cc  */
#line 3817 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 405:

/* Line 678 of lalr1.cc  */
#line 3828 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 406:

/* Line 678 of lalr1.cc  */
#line 3834 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 407:

/* Line 678 of lalr1.cc  */
#line 3844 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 408:

/* Line 678 of lalr1.cc  */
#line 3850 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 409:

/* Line 678 of lalr1.cc  */
#line 3860 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 410:

/* Line 678 of lalr1.cc  */
#line 3864 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 411:

/* Line 678 of lalr1.cc  */
#line 3868 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 412:

/* Line 678 of lalr1.cc  */
#line 3906 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 413:

/* Line 678 of lalr1.cc  */
#line 3910 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 414:

/* Line 678 of lalr1.cc  */
#line 3920 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 415:

/* Line 678 of lalr1.cc  */
#line 3930 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 416:

/* Line 678 of lalr1.cc  */
#line 3943 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 417:

/* Line 678 of lalr1.cc  */
#line 3952 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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

  case 418:

/* Line 678 of lalr1.cc  */
#line 3962 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 419:

/* Line 678 of lalr1.cc  */
#line 3966 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 420:

/* Line 678 of lalr1.cc  */
#line 3975 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 421:

/* Line 678 of lalr1.cc  */
#line 3979 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 422:

/* Line 678 of lalr1.cc  */
#line 3988 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 423:

/* Line 678 of lalr1.cc  */
#line 3994 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 424:

/* Line 678 of lalr1.cc  */
#line 4002 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 425:

/* Line 678 of lalr1.cc  */
#line 4008 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 426:

/* Line 678 of lalr1.cc  */
#line 4020 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 427:

/* Line 678 of lalr1.cc  */
#line 4026 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 428:

/* Line 678 of lalr1.cc  */
#line 4036 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 429:

/* Line 678 of lalr1.cc  */
#line 4040 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 430:

/* Line 678 of lalr1.cc  */
#line 4044 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 431:

/* Line 678 of lalr1.cc  */
#line 4048 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 432:

/* Line 678 of lalr1.cc  */
#line 4052 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 433:

/* Line 678 of lalr1.cc  */
#line 4058 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 434:

/* Line 678 of lalr1.cc  */
#line 4064 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 435:

/* Line 678 of lalr1.cc  */
#line 4072 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 436:

/* Line 678 of lalr1.cc  */
#line 4076 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 437:

/* Line 678 of lalr1.cc  */
#line 4084 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 438:

/* Line 678 of lalr1.cc  */
#line 4088 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 439:

/* Line 678 of lalr1.cc  */
#line 4099 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 440:

/* Line 678 of lalr1.cc  */
#line 4103 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 441:

/* Line 678 of lalr1.cc  */
#line 4107 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 442:

/* Line 678 of lalr1.cc  */
#line 4113 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 443:

/* Line 678 of lalr1.cc  */
#line 4117 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 444:

/* Line 678 of lalr1.cc  */
#line 4131 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 445:

/* Line 678 of lalr1.cc  */
#line 4135 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 446:

/* Line 678 of lalr1.cc  */
#line 4143 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 447:

/* Line 678 of lalr1.cc  */
#line 4147 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 448:

/* Line 678 of lalr1.cc  */
#line 4157 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 449:

/* Line 678 of lalr1.cc  */
#line 4161 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 450:

/* Line 678 of lalr1.cc  */
#line 4165 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 451:

/* Line 678 of lalr1.cc  */
#line 4169 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 452:

/* Line 678 of lalr1.cc  */
#line 4178 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 453:

/* Line 678 of lalr1.cc  */
#line 4182 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 454:

/* Line 678 of lalr1.cc  */
#line 4186 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 455:

/* Line 678 of lalr1.cc  */
#line 4190 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 456:

/* Line 678 of lalr1.cc  */
#line 4198 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 457:

/* Line 678 of lalr1.cc  */
#line 4204 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 458:

/* Line 678 of lalr1.cc  */
#line 4214 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 459:

/* Line 678 of lalr1.cc  */
#line 4222 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 460:

/* Line 678 of lalr1.cc  */
#line 4226 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 461:

/* Line 678 of lalr1.cc  */
#line 4230 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 462:

/* Line 678 of lalr1.cc  */
#line 4234 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 463:

/* Line 678 of lalr1.cc  */
#line 4238 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 464:

/* Line 678 of lalr1.cc  */
#line 4242 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 465:

/* Line 678 of lalr1.cc  */
#line 4246 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 466:

/* Line 678 of lalr1.cc  */
#line 4250 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 467:

/* Line 678 of lalr1.cc  */
#line 4254 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 468:

/* Line 678 of lalr1.cc  */
#line 4258 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 469:

/* Line 678 of lalr1.cc  */
#line 4263 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 470:

/* Line 678 of lalr1.cc  */
#line 4267 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 471:

/* Line 678 of lalr1.cc  */
#line 4271 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 472:

/* Line 678 of lalr1.cc  */
#line 4275 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 473:

/* Line 678 of lalr1.cc  */
#line 4283 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 474:

/* Line 678 of lalr1.cc  */
#line 4287 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 475:

/* Line 678 of lalr1.cc  */
#line 4295 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 476:

/* Line 678 of lalr1.cc  */
#line 4302 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 477:

/* Line 678 of lalr1.cc  */
#line 4309 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 478:

/* Line 678 of lalr1.cc  */
#line 4320 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 479:

/* Line 678 of lalr1.cc  */
#line 4328 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 480:

/* Line 678 of lalr1.cc  */
#line 4332 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 481:

/* Line 678 of lalr1.cc  */
#line 4340 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 482:

/* Line 678 of lalr1.cc  */
#line 4348 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 483:

/* Line 678 of lalr1.cc  */
#line 4356 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 484:

/* Line 678 of lalr1.cc  */
#line 4410 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 485:

/* Line 678 of lalr1.cc  */
#line 4414 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 486:

/* Line 678 of lalr1.cc  */
#line 4427 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 487:

/* Line 678 of lalr1.cc  */
#line 4433 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 488:

/* Line 678 of lalr1.cc  */
#line 4443 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 489:

/* Line 678 of lalr1.cc  */
#line 4447 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 490:

/* Line 678 of lalr1.cc  */
#line 4455 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 491:

/* Line 678 of lalr1.cc  */
#line 4459 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 492:

/* Line 678 of lalr1.cc  */
#line 4463 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 493:

/* Line 678 of lalr1.cc  */
#line 4471 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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

  case 494:

/* Line 678 of lalr1.cc  */
#line 4481 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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

  case 495:

/* Line 678 of lalr1.cc  */
#line 4491 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemConstructor(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(8) - (2)].expr)),
                static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr)),
                NULL,
                NULL
            );
        }
    break;

  case 496:

/* Line 678 of lalr1.cc  */
#line 4501 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemConstructor(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
                static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
                NULL,
                dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node))
            );
        }
    break;

  case 497:

/* Line 678 of lalr1.cc  */
#line 4511 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemConstructor(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
                static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
                dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
                NULL
            );
        }
    break;

  case 498:

/* Line 678 of lalr1.cc  */
#line 4521 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemConstructor(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(10) - (2)].expr)),
                static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)),
                dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node))
            );
        }
    break;

  case 499:

/* Line 678 of lalr1.cc  */
#line 4536 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 500:

/* Line 678 of lalr1.cc  */
#line 4542 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 501:

/* Line 678 of lalr1.cc  */
#line 4553 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 502:

/* Line 678 of lalr1.cc  */
#line 4559 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 503:

/* Line 678 of lalr1.cc  */
#line 4570 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 506:

/* Line 678 of lalr1.cc  */
#line 4587 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 507:

/* Line 678 of lalr1.cc  */
#line 4592 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 508:

/* Line 678 of lalr1.cc  */
#line 4601 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 509:

/* Line 678 of lalr1.cc  */
#line 4605 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 510:

/* Line 678 of lalr1.cc  */
#line 4612 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 511:

/* Line 678 of lalr1.cc  */
#line 4618 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 512:

/* Line 678 of lalr1.cc  */
#line 4624 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 513:

/* Line 678 of lalr1.cc  */
#line 4632 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 514:

/* Line 678 of lalr1.cc  */
#line 4644 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 515:

/* Line 678 of lalr1.cc  */
#line 4648 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 516:

/* Line 678 of lalr1.cc  */
#line 4655 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 517:

/* Line 678 of lalr1.cc  */
#line 4661 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 518:

/* Line 678 of lalr1.cc  */
#line 4667 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 519:

/* Line 678 of lalr1.cc  */
#line 4674 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 520:

/* Line 678 of lalr1.cc  */
#line 4685 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 521:

/* Line 678 of lalr1.cc  */
#line 4689 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 522:

/* Line 678 of lalr1.cc  */
#line 4699 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 523:

/* Line 678 of lalr1.cc  */
#line 4703 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 524:

/* Line 678 of lalr1.cc  */
#line 4713 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 525:

/* Line 678 of lalr1.cc  */
#line 4717 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 526:

/* Line 678 of lalr1.cc  */
#line 4721 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 527:

/* Line 678 of lalr1.cc  */
#line 4726 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 528:

/* Line 678 of lalr1.cc  */
#line 4735 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 529:

/* Line 678 of lalr1.cc  */
#line 4741 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 530:

/* Line 678 of lalr1.cc  */
#line 4747 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 531:

/* Line 678 of lalr1.cc  */
#line 4753 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
        }
    break;

  case 532:

/* Line 678 of lalr1.cc  */
#line 4761 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 533:

/* Line 678 of lalr1.cc  */
#line 4766 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 534:

/* Line 678 of lalr1.cc  */
#line 4774 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 535:

/* Line 678 of lalr1.cc  */
#line 4779 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 536:

/* Line 678 of lalr1.cc  */
#line 4787 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 537:

/* Line 678 of lalr1.cc  */
#line 4795 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 538:

/* Line 678 of lalr1.cc  */
#line 4800 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 539:

/* Line 678 of lalr1.cc  */
#line 4805 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 540:

/* Line 678 of lalr1.cc  */
#line 4810 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 541:

/* Line 678 of lalr1.cc  */
#line 4815 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 542:

/* Line 678 of lalr1.cc  */
#line 4820 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 543:

/* Line 678 of lalr1.cc  */
#line 4829 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 544:

/* Line 678 of lalr1.cc  */
#line 4837 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 545:

/* Line 678 of lalr1.cc  */
#line 4841 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 546:

/* Line 678 of lalr1.cc  */
#line 4858 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 547:

/* Line 678 of lalr1.cc  */
#line 4862 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 548:

/* Line 678 of lalr1.cc  */
#line 4870 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 549:

/* Line 678 of lalr1.cc  */
#line 4878 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 550:

/* Line 678 of lalr1.cc  */
#line 4886 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 551:

/* Line 678 of lalr1.cc  */
#line 4890 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 552:

/* Line 678 of lalr1.cc  */
#line 4898 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 553:

/* Line 678 of lalr1.cc  */
#line 4904 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 554:

/* Line 678 of lalr1.cc  */
#line 4914 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 555:

/* Line 678 of lalr1.cc  */
#line 4922 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 556:

/* Line 678 of lalr1.cc  */
#line 4926 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 557:

/* Line 678 of lalr1.cc  */
#line 4930 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 558:

/* Line 678 of lalr1.cc  */
#line 4965 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 559:

/* Line 678 of lalr1.cc  */
#line 4971 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 560:

/* Line 678 of lalr1.cc  */
#line 4977 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 561:

/* Line 678 of lalr1.cc  */
#line 4987 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 562:

/* Line 678 of lalr1.cc  */
#line 4991 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 563:

/* Line 678 of lalr1.cc  */
#line 4995 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 564:

/* Line 678 of lalr1.cc  */
#line 4999 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 565:

/* Line 678 of lalr1.cc  */
#line 5003 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 566:

/* Line 678 of lalr1.cc  */
#line 5007 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 567:

/* Line 678 of lalr1.cc  */
#line 5011 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 568:

/* Line 678 of lalr1.cc  */
#line 5018 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 569:

/* Line 678 of lalr1.cc  */
#line 5024 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 570:

/* Line 678 of lalr1.cc  */
#line 5034 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 571:

/* Line 678 of lalr1.cc  */
#line 5042 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 572:

/* Line 678 of lalr1.cc  */
#line 5046 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 573:

/* Line 678 of lalr1.cc  */
#line 5050 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 574:

/* Line 678 of lalr1.cc  */
#line 5054 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 575:

/* Line 678 of lalr1.cc  */
#line 5058 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 576:

/* Line 678 of lalr1.cc  */
#line 5062 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 577:

/* Line 678 of lalr1.cc  */
#line 5066 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 578:

/* Line 678 of lalr1.cc  */
#line 5070 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 579:

/* Line 678 of lalr1.cc  */
#line 5074 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 580:

/* Line 678 of lalr1.cc  */
#line 5082 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 581:

/* Line 678 of lalr1.cc  */
#line 5090 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 582:

/* Line 678 of lalr1.cc  */
#line 5094 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 583:

/* Line 678 of lalr1.cc  */
#line 5098 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 584:

/* Line 678 of lalr1.cc  */
#line 5108 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 585:

/* Line 678 of lalr1.cc  */
#line 5116 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 586:

/* Line 678 of lalr1.cc  */
#line 5124 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 587:

/* Line 678 of lalr1.cc  */
#line 5128 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 588:

/* Line 678 of lalr1.cc  */
#line 5132 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 589:

/* Line 678 of lalr1.cc  */
#line 5140 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 590:

/* Line 678 of lalr1.cc  */
#line 5144 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 591:

/* Line 678 of lalr1.cc  */
#line 5150 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 592:

/* Line 678 of lalr1.cc  */
#line 5156 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 593:

/* Line 678 of lalr1.cc  */
#line 5160 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 594:

/* Line 678 of lalr1.cc  */
#line 5170 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 595:

/* Line 678 of lalr1.cc  */
#line 5178 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 596:

/* Line 678 of lalr1.cc  */
#line 5182 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 597:

/* Line 678 of lalr1.cc  */
#line 5188 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 598:

/* Line 678 of lalr1.cc  */
#line 5197 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 599:

/* Line 678 of lalr1.cc  */
#line 5206 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 600:

/* Line 678 of lalr1.cc  */
#line 5212 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 601:

/* Line 678 of lalr1.cc  */
#line 5218 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 602:

/* Line 678 of lalr1.cc  */
#line 5228 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 603:

/* Line 678 of lalr1.cc  */
#line 5245 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 604:

/* Line 678 of lalr1.cc  */
#line 5252 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 605:

/* Line 678 of lalr1.cc  */
#line 5267 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 606:

/* Line 678 of lalr1.cc  */
#line 5303 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 607:

/* Line 678 of lalr1.cc  */
#line 5307 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 608:

/* Line 678 of lalr1.cc  */
#line 5315 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 609:

/* Line 678 of lalr1.cc  */
#line 5323 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 610:

/* Line 678 of lalr1.cc  */
#line 5335 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 611:

/* Line 678 of lalr1.cc  */
#line 5339 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 612:

/* Line 678 of lalr1.cc  */
#line 5347 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 613:

/* Line 678 of lalr1.cc  */
#line 5355 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 614:

/* Line 678 of lalr1.cc  */
#line 5359 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 615:

/* Line 678 of lalr1.cc  */
#line 5370 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 616:

/* Line 678 of lalr1.cc  */
#line 5387 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 617:

/* Line 678 of lalr1.cc  */
#line 5393 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 618:

/* Line 678 of lalr1.cc  */
#line 5399 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 619:

/* Line 678 of lalr1.cc  */
#line 5409 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 620:

/* Line 678 of lalr1.cc  */
#line 5413 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 621:

/* Line 678 of lalr1.cc  */
#line 5419 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 622:

/* Line 678 of lalr1.cc  */
#line 5425 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 623:

/* Line 678 of lalr1.cc  */
#line 5429 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 624:

/* Line 678 of lalr1.cc  */
#line 5435 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 625:

/* Line 678 of lalr1.cc  */
#line 5439 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 626:

/* Line 678 of lalr1.cc  */
#line 5445 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 627:

/* Line 678 of lalr1.cc  */
#line 5451 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 628:

/* Line 678 of lalr1.cc  */
#line 5458 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 629:

/* Line 678 of lalr1.cc  */
#line 5468 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 630:

/* Line 678 of lalr1.cc  */
#line 5473 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 631:

/* Line 678 of lalr1.cc  */
#line 5481 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 632:

/* Line 678 of lalr1.cc  */
#line 5487 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 633:

/* Line 678 of lalr1.cc  */
#line 5497 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 634:

/* Line 678 of lalr1.cc  */
#line 5519 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 635:

/* Line 678 of lalr1.cc  */
#line 5528 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 636:

/* Line 678 of lalr1.cc  */
#line 5534 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 637:

/* Line 678 of lalr1.cc  */
#line 5547 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 638:

/* Line 678 of lalr1.cc  */
#line 5561 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 639:

/* Line 678 of lalr1.cc  */
#line 5568 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 640:

/* Line 678 of lalr1.cc  */
#line 5574 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 641:

/* Line 678 of lalr1.cc  */
#line 5584 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 642:

/* Line 678 of lalr1.cc  */
#line 5593 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 643:

/* Line 678 of lalr1.cc  */
#line 5601 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 644:

/* Line 678 of lalr1.cc  */
#line 5607 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 645:

/* Line 678 of lalr1.cc  */
#line 5625 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 646:

/* Line 678 of lalr1.cc  */
#line 5633 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 647:

/* Line 678 of lalr1.cc  */
#line 5637 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 648:

/* Line 678 of lalr1.cc  */
#line 5644 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 649:

/* Line 678 of lalr1.cc  */
#line 5649 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 650:

/* Line 678 of lalr1.cc  */
#line 5657 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 651:

/* Line 678 of lalr1.cc  */
#line 5661 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 652:

/* Line 678 of lalr1.cc  */
#line 5668 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 653:

/* Line 678 of lalr1.cc  */
#line 5672 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 654:

/* Line 678 of lalr1.cc  */
#line 5679 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 655:

/* Line 678 of lalr1.cc  */
#line 5683 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 656:

/* Line 678 of lalr1.cc  */
#line 5690 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 657:

/* Line 678 of lalr1.cc  */
#line 5694 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 658:

/* Line 678 of lalr1.cc  */
#line 5703 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 659:

/* Line 678 of lalr1.cc  */
#line 5715 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 660:

/* Line 678 of lalr1.cc  */
#line 5719 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 661:

/* Line 678 of lalr1.cc  */
#line 5726 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 662:

/* Line 678 of lalr1.cc  */
#line 5730 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 663:

/* Line 678 of lalr1.cc  */
#line 5738 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 664:

/* Line 678 of lalr1.cc  */
#line 5746 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 665:

/* Line 678 of lalr1.cc  */
#line 5754 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 666:

/* Line 678 of lalr1.cc  */
#line 5758 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 667:

/* Line 678 of lalr1.cc  */
#line 5765 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 668:

/* Line 678 of lalr1.cc  */
#line 5769 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 669:

/* Line 678 of lalr1.cc  */
#line 5777 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 670:

/* Line 678 of lalr1.cc  */
#line 5788 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 671:

/* Line 678 of lalr1.cc  */
#line 5792 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 672:

/* Line 678 of lalr1.cc  */
#line 5800 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 673:

/* Line 678 of lalr1.cc  */
#line 5812 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 674:

/* Line 678 of lalr1.cc  */
#line 5818 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 675:

/* Line 678 of lalr1.cc  */
#line 5827 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 676:

/* Line 678 of lalr1.cc  */
#line 5831 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 677:

/* Line 678 of lalr1.cc  */
#line 5839 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 678:

/* Line 678 of lalr1.cc  */
#line 5843 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 679:

/* Line 678 of lalr1.cc  */
#line 5847 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 680:

/* Line 678 of lalr1.cc  */
#line 5854 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 681:

/* Line 678 of lalr1.cc  */
#line 5858 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 682:

/* Line 678 of lalr1.cc  */
#line 5865 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 683:

/* Line 678 of lalr1.cc  */
#line 5869 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 684:

/* Line 678 of lalr1.cc  */
#line 5877 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 685:

/* Line 678 of lalr1.cc  */
#line 5881 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:

/* Line 678 of lalr1.cc  */
#line 5885 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 687:

/* Line 678 of lalr1.cc  */
#line 5889 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:

/* Line 678 of lalr1.cc  */
#line 5893 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 689:

/* Line 678 of lalr1.cc  */
#line 5901 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 690:

/* Line 678 of lalr1.cc  */
#line 5909 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 691:

/* Line 678 of lalr1.cc  */
#line 5921 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 692:

/* Line 678 of lalr1.cc  */
#line 5933 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 693:

/* Line 678 of lalr1.cc  */
#line 5937 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 694:

/* Line 678 of lalr1.cc  */
#line 5941 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 695:

/* Line 678 of lalr1.cc  */
#line 5949 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 696:

/* Line 678 of lalr1.cc  */
#line 5955 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 697:

/* Line 678 of lalr1.cc  */
#line 5965 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 698:

/* Line 678 of lalr1.cc  */
#line 5969 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 699:

/* Line 678 of lalr1.cc  */
#line 5973 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 700:

/* Line 678 of lalr1.cc  */
#line 5977 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 701:

/* Line 678 of lalr1.cc  */
#line 5981 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 702:

/* Line 678 of lalr1.cc  */
#line 5985 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 703:

/* Line 678 of lalr1.cc  */
#line 5989 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 704:

/* Line 678 of lalr1.cc  */
#line 5993 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 705:

/* Line 678 of lalr1.cc  */
#line 6001 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 706:

/* Line 678 of lalr1.cc  */
#line 6005 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 707:

/* Line 678 of lalr1.cc  */
#line 6009 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 708:

/* Line 678 of lalr1.cc  */
#line 6013 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 709:

/* Line 678 of lalr1.cc  */
#line 6021 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 710:

/* Line 678 of lalr1.cc  */
#line 6027 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 711:

/* Line 678 of lalr1.cc  */
#line 6037 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 712:

/* Line 678 of lalr1.cc  */
#line 6047 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 713:

/* Line 678 of lalr1.cc  */
#line 6051 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 714:

/* Line 678 of lalr1.cc  */
#line 6059 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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

  case 715:

/* Line 678 of lalr1.cc  */
#line 6069 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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

  case 716:

/* Line 678 of lalr1.cc  */
#line 6080 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 717:

/* Line 678 of lalr1.cc  */
#line 6087 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 718:

/* Line 678 of lalr1.cc  */
#line 6091 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 719:

/* Line 678 of lalr1.cc  */
#line 6098 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 720:

/* Line 678 of lalr1.cc  */
#line 6102 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 721:

/* Line 678 of lalr1.cc  */
#line 6109 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 722:

/* Line 678 of lalr1.cc  */
#line 6114 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 723:

/* Line 678 of lalr1.cc  */
#line 6123 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 724:

/* Line 678 of lalr1.cc  */
#line 6132 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = NULL;
        }
    break;

  case 725:

/* Line 678 of lalr1.cc  */
#line 6136 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 726:

/* Line 678 of lalr1.cc  */
#line 6143 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 727:

/* Line 678 of lalr1.cc  */
#line 6147 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 728:

/* Line 678 of lalr1.cc  */
#line 6155 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 729:

/* Line 678 of lalr1.cc  */
#line 6164 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 730:

/* Line 678 of lalr1.cc  */
#line 6171 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 731:

/* Line 678 of lalr1.cc  */
#line 6181 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 732:

/* Line 678 of lalr1.cc  */
#line 6185 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 733:

/* Line 678 of lalr1.cc  */
#line 6192 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 734:

/* Line 678 of lalr1.cc  */
#line 6198 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 735:

/* Line 678 of lalr1.cc  */
#line 6207 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 736:

/* Line 678 of lalr1.cc  */
#line 6211 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 737:

/* Line 678 of lalr1.cc  */
#line 6218 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 738:

/* Line 678 of lalr1.cc  */
#line 6223 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 739:

/* Line 678 of lalr1.cc  */
#line 6235 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 740:

/* Line 678 of lalr1.cc  */
#line 6243 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 741:

/* Line 678 of lalr1.cc  */
#line 6255 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 742:

/* Line 678 of lalr1.cc  */
#line 6263 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 743:

/* Line 678 of lalr1.cc  */
#line 6267 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 744:

/* Line 678 of lalr1.cc  */
#line 6275 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 745:

/* Line 678 of lalr1.cc  */
#line 6279 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 746:

/* Line 678 of lalr1.cc  */
#line 6283 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 747:

/* Line 678 of lalr1.cc  */
#line 6291 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 748:

/* Line 678 of lalr1.cc  */
#line 6299 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 749:

/* Line 678 of lalr1.cc  */
#line 6303 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 750:

/* Line 678 of lalr1.cc  */
#line 6307 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 751:

/* Line 678 of lalr1.cc  */
#line 6311 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 752:

/* Line 678 of lalr1.cc  */
#line 6319 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 753:

/* Line 678 of lalr1.cc  */
#line 6327 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 754:

/* Line 678 of lalr1.cc  */
#line 6339 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 755:

/* Line 678 of lalr1.cc  */
#line 6343 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 756:

/* Line 678 of lalr1.cc  */
#line 6351 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 757:

/* Line 678 of lalr1.cc  */
#line 6365 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 758:

/* Line 678 of lalr1.cc  */
#line 6369 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 759:

/* Line 678 of lalr1.cc  */
#line 6376 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 760:

/* Line 678 of lalr1.cc  */
#line 6381 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 761:

/* Line 678 of lalr1.cc  */
#line 6389 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 762:

/* Line 678 of lalr1.cc  */
#line 6394 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 763:

/* Line 678 of lalr1.cc  */
#line 6403 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 764:

/* Line 678 of lalr1.cc  */
#line 6411 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 765:

/* Line 678 of lalr1.cc  */
#line 6417 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 766:

/* Line 678 of lalr1.cc  */
#line 6427 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        static_cast<JSONPairList*>((yysemantic_stack_[(5) - (3)].node)),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 767:

/* Line 678 of lalr1.cc  */
#line 6433 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 768:

/* Line 678 of lalr1.cc  */
#line 6440 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 769:

/* Line 678 of lalr1.cc  */
#line 6447 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONDeleteExpr(LOC((yyloc)), (yysemantic_stack_[(6) - (3)].expr), (yysemantic_stack_[(6) - (5)].expr));
        }
    break;

  case 770:

/* Line 678 of lalr1.cc  */
#line 6454 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONRenameExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 771:

/* Line 678 of lalr1.cc  */
#line 6461 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONReplaceExpr(LOC((yyloc)), (yysemantic_stack_[(10) - (5)].expr), (yysemantic_stack_[(10) - (7)].expr), (yysemantic_stack_[(10) - (10)].expr));
        }
    break;

  case 772:

/* Line 678 of lalr1.cc  */
#line 6468 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 773:

/* Line 678 of lalr1.cc  */
#line 6472 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 774:

/* Line 678 of lalr1.cc  */
#line 6476 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 775:

/* Line 678 of lalr1.cc  */
#line 6483 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 776:

/* Line 678 of lalr1.cc  */
#line 6490 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 777:

/* Line 678 of lalr1.cc  */
#line 6497 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 780:

/* Line 678 of lalr1.cc  */
#line 6514 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
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

  case 782:

/* Line 678 of lalr1.cc  */
#line 6527 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 783:

/* Line 678 of lalr1.cc  */
#line 6528 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 784:

/* Line 678 of lalr1.cc  */
#line 6529 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 785:

/* Line 678 of lalr1.cc  */
#line 6530 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 786:

/* Line 678 of lalr1.cc  */
#line 6531 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 787:

/* Line 678 of lalr1.cc  */
#line 6532 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 788:

/* Line 678 of lalr1.cc  */
#line 6533 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 789:

/* Line 678 of lalr1.cc  */
#line 6534 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 790:

/* Line 678 of lalr1.cc  */
#line 6535 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 791:

/* Line 678 of lalr1.cc  */
#line 6536 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 792:

/* Line 678 of lalr1.cc  */
#line 6537 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 793:

/* Line 678 of lalr1.cc  */
#line 6538 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 794:

/* Line 678 of lalr1.cc  */
#line 6539 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 795:

/* Line 678 of lalr1.cc  */
#line 6540 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 796:

/* Line 678 of lalr1.cc  */
#line 6541 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 798:

/* Line 678 of lalr1.cc  */
#line 6546 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 799:

/* Line 678 of lalr1.cc  */
#line 6547 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 800:

/* Line 678 of lalr1.cc  */
#line 6548 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 801:

/* Line 678 of lalr1.cc  */
#line 6549 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 802:

/* Line 678 of lalr1.cc  */
#line 6550 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 803:

/* Line 678 of lalr1.cc  */
#line 6551 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 804:

/* Line 678 of lalr1.cc  */
#line 6552 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 805:

/* Line 678 of lalr1.cc  */
#line 6553 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 806:

/* Line 678 of lalr1.cc  */
#line 6554 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 807:

/* Line 678 of lalr1.cc  */
#line 6555 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 808:

/* Line 678 of lalr1.cc  */
#line 6556 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 809:

/* Line 678 of lalr1.cc  */
#line 6557 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 810:

/* Line 678 of lalr1.cc  */
#line 6558 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 811:

/* Line 678 of lalr1.cc  */
#line 6559 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 812:

/* Line 678 of lalr1.cc  */
#line 6560 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 813:

/* Line 678 of lalr1.cc  */
#line 6561 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 814:

/* Line 678 of lalr1.cc  */
#line 6562 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 815:

/* Line 678 of lalr1.cc  */
#line 6563 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 816:

/* Line 678 of lalr1.cc  */
#line 6564 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 817:

/* Line 678 of lalr1.cc  */
#line 6565 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 818:

/* Line 678 of lalr1.cc  */
#line 6566 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 819:

/* Line 678 of lalr1.cc  */
#line 6567 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 820:

/* Line 678 of lalr1.cc  */
#line 6568 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 821:

/* Line 678 of lalr1.cc  */
#line 6569 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 822:

/* Line 678 of lalr1.cc  */
#line 6570 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 823:

/* Line 678 of lalr1.cc  */
#line 6571 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 824:

/* Line 678 of lalr1.cc  */
#line 6572 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 825:

/* Line 678 of lalr1.cc  */
#line 6573 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 826:

/* Line 678 of lalr1.cc  */
#line 6574 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 827:

/* Line 678 of lalr1.cc  */
#line 6575 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 828:

/* Line 678 of lalr1.cc  */
#line 6576 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 829:

/* Line 678 of lalr1.cc  */
#line 6577 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 830:

/* Line 678 of lalr1.cc  */
#line 6578 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 831:

/* Line 678 of lalr1.cc  */
#line 6579 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 832:

/* Line 678 of lalr1.cc  */
#line 6580 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 833:

/* Line 678 of lalr1.cc  */
#line 6581 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 834:

/* Line 678 of lalr1.cc  */
#line 6582 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 835:

/* Line 678 of lalr1.cc  */
#line 6583 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 836:

/* Line 678 of lalr1.cc  */
#line 6584 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 837:

/* Line 678 of lalr1.cc  */
#line 6585 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 838:

/* Line 678 of lalr1.cc  */
#line 6586 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 839:

/* Line 678 of lalr1.cc  */
#line 6587 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 840:

/* Line 678 of lalr1.cc  */
#line 6588 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 841:

/* Line 678 of lalr1.cc  */
#line 6589 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 842:

/* Line 678 of lalr1.cc  */
#line 6590 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 843:

/* Line 678 of lalr1.cc  */
#line 6591 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 844:

/* Line 678 of lalr1.cc  */
#line 6592 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 845:

/* Line 678 of lalr1.cc  */
#line 6593 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 846:

/* Line 678 of lalr1.cc  */
#line 6594 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 847:

/* Line 678 of lalr1.cc  */
#line 6595 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 848:

/* Line 678 of lalr1.cc  */
#line 6596 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 849:

/* Line 678 of lalr1.cc  */
#line 6597 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 850:

/* Line 678 of lalr1.cc  */
#line 6598 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 851:

/* Line 678 of lalr1.cc  */
#line 6599 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 852:

/* Line 678 of lalr1.cc  */
#line 6600 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 853:

/* Line 678 of lalr1.cc  */
#line 6601 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 854:

/* Line 678 of lalr1.cc  */
#line 6602 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 855:

/* Line 678 of lalr1.cc  */
#line 6603 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 856:

/* Line 678 of lalr1.cc  */
#line 6604 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 857:

/* Line 678 of lalr1.cc  */
#line 6605 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 858:

/* Line 678 of lalr1.cc  */
#line 6606 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 859:

/* Line 678 of lalr1.cc  */
#line 6607 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 860:

/* Line 678 of lalr1.cc  */
#line 6608 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 861:

/* Line 678 of lalr1.cc  */
#line 6609 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 862:

/* Line 678 of lalr1.cc  */
#line 6610 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 863:

/* Line 678 of lalr1.cc  */
#line 6611 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 864:

/* Line 678 of lalr1.cc  */
#line 6612 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 865:

/* Line 678 of lalr1.cc  */
#line 6613 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 866:

/* Line 678 of lalr1.cc  */
#line 6614 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 867:

/* Line 678 of lalr1.cc  */
#line 6615 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 868:

/* Line 678 of lalr1.cc  */
#line 6616 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 869:

/* Line 678 of lalr1.cc  */
#line 6617 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 870:

/* Line 678 of lalr1.cc  */
#line 6618 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 871:

/* Line 678 of lalr1.cc  */
#line 6619 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 872:

/* Line 678 of lalr1.cc  */
#line 6620 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 873:

/* Line 678 of lalr1.cc  */
#line 6621 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 874:

/* Line 678 of lalr1.cc  */
#line 6622 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 875:

/* Line 678 of lalr1.cc  */
#line 6623 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 876:

/* Line 678 of lalr1.cc  */
#line 6624 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 877:

/* Line 678 of lalr1.cc  */
#line 6625 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 878:

/* Line 678 of lalr1.cc  */
#line 6626 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 879:

/* Line 678 of lalr1.cc  */
#line 6627 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 880:

/* Line 678 of lalr1.cc  */
#line 6628 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 881:

/* Line 678 of lalr1.cc  */
#line 6629 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 882:

/* Line 678 of lalr1.cc  */
#line 6630 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 883:

/* Line 678 of lalr1.cc  */
#line 6631 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 884:

/* Line 678 of lalr1.cc  */
#line 6632 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 885:

/* Line 678 of lalr1.cc  */
#line 6633 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 886:

/* Line 678 of lalr1.cc  */
#line 6634 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 887:

/* Line 678 of lalr1.cc  */
#line 6635 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 888:

/* Line 678 of lalr1.cc  */
#line 6636 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 889:

/* Line 678 of lalr1.cc  */
#line 6637 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 890:

/* Line 678 of lalr1.cc  */
#line 6638 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 891:

/* Line 678 of lalr1.cc  */
#line 6639 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 892:

/* Line 678 of lalr1.cc  */
#line 6640 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 893:

/* Line 678 of lalr1.cc  */
#line 6641 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 894:

/* Line 678 of lalr1.cc  */
#line 6642 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 895:

/* Line 678 of lalr1.cc  */
#line 6643 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 896:

/* Line 678 of lalr1.cc  */
#line 6644 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 897:

/* Line 678 of lalr1.cc  */
#line 6645 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 898:

/* Line 678 of lalr1.cc  */
#line 6646 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 899:

/* Line 678 of lalr1.cc  */
#line 6647 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 900:

/* Line 678 of lalr1.cc  */
#line 6648 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 901:

/* Line 678 of lalr1.cc  */
#line 6649 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 902:

/* Line 678 of lalr1.cc  */
#line 6650 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 903:

/* Line 678 of lalr1.cc  */
#line 6651 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 904:

/* Line 678 of lalr1.cc  */
#line 6652 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 905:

/* Line 678 of lalr1.cc  */
#line 6653 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 906:

/* Line 678 of lalr1.cc  */
#line 6654 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 907:

/* Line 678 of lalr1.cc  */
#line 6655 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 908:

/* Line 678 of lalr1.cc  */
#line 6656 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 909:

/* Line 678 of lalr1.cc  */
#line 6657 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 910:

/* Line 678 of lalr1.cc  */
#line 6658 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 911:

/* Line 678 of lalr1.cc  */
#line 6659 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 912:

/* Line 678 of lalr1.cc  */
#line 6660 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 913:

/* Line 678 of lalr1.cc  */
#line 6661 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 914:

/* Line 678 of lalr1.cc  */
#line 6662 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 915:

/* Line 678 of lalr1.cc  */
#line 6663 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 916:

/* Line 678 of lalr1.cc  */
#line 6664 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 917:

/* Line 678 of lalr1.cc  */
#line 6665 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 918:

/* Line 678 of lalr1.cc  */
#line 6666 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 919:

/* Line 678 of lalr1.cc  */
#line 6667 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 920:

/* Line 678 of lalr1.cc  */
#line 6668 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 921:

/* Line 678 of lalr1.cc  */
#line 6669 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 922:

/* Line 678 of lalr1.cc  */
#line 6670 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 923:

/* Line 678 of lalr1.cc  */
#line 6671 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 924:

/* Line 678 of lalr1.cc  */
#line 6672 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 925:

/* Line 678 of lalr1.cc  */
#line 6673 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 926:

/* Line 678 of lalr1.cc  */
#line 6674 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 927:

/* Line 678 of lalr1.cc  */
#line 6675 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 928:

/* Line 678 of lalr1.cc  */
#line 6676 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 929:

/* Line 678 of lalr1.cc  */
#line 6677 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 930:

/* Line 678 of lalr1.cc  */
#line 6678 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 931:

/* Line 678 of lalr1.cc  */
#line 6679 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 932:

/* Line 678 of lalr1.cc  */
#line 6680 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 933:

/* Line 678 of lalr1.cc  */
#line 6681 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 934:

/* Line 678 of lalr1.cc  */
#line 6682 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 935:

/* Line 678 of lalr1.cc  */
#line 6683 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 936:

/* Line 678 of lalr1.cc  */
#line 6684 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 937:

/* Line 678 of lalr1.cc  */
#line 6685 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 938:

/* Line 678 of lalr1.cc  */
#line 6686 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 939:

/* Line 678 of lalr1.cc  */
#line 6687 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 940:

/* Line 678 of lalr1.cc  */
#line 6688 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 941:

/* Line 678 of lalr1.cc  */
#line 6689 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 942:

/* Line 678 of lalr1.cc  */
#line 6690 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 943:

/* Line 678 of lalr1.cc  */
#line 6691 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 944:

/* Line 678 of lalr1.cc  */
#line 6692 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 945:

/* Line 678 of lalr1.cc  */
#line 6693 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 946:

/* Line 678 of lalr1.cc  */
#line 6694 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 947:

/* Line 678 of lalr1.cc  */
#line 6695 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 948:

/* Line 678 of lalr1.cc  */
#line 6696 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 949:

/* Line 678 of lalr1.cc  */
#line 6697 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 950:

/* Line 678 of lalr1.cc  */
#line 6698 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 951:

/* Line 678 of lalr1.cc  */
#line 6699 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 952:

/* Line 678 of lalr1.cc  */
#line 6700 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 953:

/* Line 678 of lalr1.cc  */
#line 6701 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 954:

/* Line 678 of lalr1.cc  */
#line 6702 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 955:

/* Line 678 of lalr1.cc  */
#line 6703 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 956:

/* Line 678 of lalr1.cc  */
#line 6704 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 957:

/* Line 678 of lalr1.cc  */
#line 6705 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 958:

/* Line 678 of lalr1.cc  */
#line 6706 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 959:

/* Line 678 of lalr1.cc  */
#line 6707 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 960:

/* Line 678 of lalr1.cc  */
#line 6708 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 961:

/* Line 678 of lalr1.cc  */
#line 6709 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 962:

/* Line 678 of lalr1.cc  */
#line 6710 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 963:

/* Line 678 of lalr1.cc  */
#line 6711 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 964:

/* Line 678 of lalr1.cc  */
#line 6712 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 965:

/* Line 678 of lalr1.cc  */
#line 6713 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 966:

/* Line 678 of lalr1.cc  */
#line 6714 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 967:

/* Line 678 of lalr1.cc  */
#line 6715 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 968:

/* Line 678 of lalr1.cc  */
#line 6716 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 969:

/* Line 678 of lalr1.cc  */
#line 6717 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 970:

/* Line 678 of lalr1.cc  */
#line 6718 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 971:

/* Line 678 of lalr1.cc  */
#line 6719 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 972:

/* Line 678 of lalr1.cc  */
#line 6720 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 973:

/* Line 678 of lalr1.cc  */
#line 6721 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 974:

/* Line 678 of lalr1.cc  */
#line 6722 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 975:

/* Line 678 of lalr1.cc  */
#line 6723 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 976:

/* Line 678 of lalr1.cc  */
#line 6724 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 977:

/* Line 678 of lalr1.cc  */
#line 6725 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 978:

/* Line 678 of lalr1.cc  */
#line 6726 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 979:

/* Line 678 of lalr1.cc  */
#line 6727 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 980:

/* Line 678 of lalr1.cc  */
#line 6728 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 981:

/* Line 678 of lalr1.cc  */
#line 6729 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 982:

/* Line 678 of lalr1.cc  */
#line 6730 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 983:

/* Line 678 of lalr1.cc  */
#line 6731 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 984:

/* Line 678 of lalr1.cc  */
#line 6732 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 985:

/* Line 678 of lalr1.cc  */
#line 6733 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 986:

/* Line 678 of lalr1.cc  */
#line 6734 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 987:

/* Line 678 of lalr1.cc  */
#line 6735 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 988:

/* Line 678 of lalr1.cc  */
#line 6736 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 989:

/* Line 678 of lalr1.cc  */
#line 6737 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 990:

/* Line 678 of lalr1.cc  */
#line 6738 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 991:

/* Line 678 of lalr1.cc  */
#line 6739 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 992:

/* Line 678 of lalr1.cc  */
#line 6740 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 993:

/* Line 678 of lalr1.cc  */
#line 6741 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 994:

/* Line 678 of lalr1.cc  */
#line 6742 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 995:

/* Line 678 of lalr1.cc  */
#line 6743 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 996:

/* Line 678 of lalr1.cc  */
#line 6744 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 997:

/* Line 678 of lalr1.cc  */
#line 6745 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 998:

/* Line 678 of lalr1.cc  */
#line 6746 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 999:

/* Line 678 of lalr1.cc  */
#line 6747 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 1000:

/* Line 678 of lalr1.cc  */
#line 6748 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 1001:

/* Line 678 of lalr1.cc  */
#line 6749 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 1002:

/* Line 678 of lalr1.cc  */
#line 6750 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 1003:

/* Line 678 of lalr1.cc  */
#line 6755 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 678 of lalr1.cc  */
#line 11970 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1495;
  const short int
  xquery_parser::yypact_[] =
  {
      3159, -1495, -1495, -1495,  4705,  4705,  4705, -1495, -1495,   198,
     273, -1495,    62,   478, -1495, -1495, -1495,   450, -1495, -1495,
   -1495,    15,   382,   679,   639,   574,   726,   119, -1495,   -21,
   -1495, -1495, -1495, -1495, -1495, -1495,   740, -1495,   731,   763,
   -1495, -1495, -1495, -1495,   636, -1495,   747, -1495,   772,   780,
   -1495,   330, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495,   709,   741, -1495, -1495,
   -1495, -1495,   702, 10576, -1495, -1495, -1495,   799, -1495, -1495,
   -1495,   822, -1495,   826,   829, -1495, -1495, 14661, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495,   837, -1495, -1495,   841,
     843, -1495, -1495, -1495, -1495, -1495, -1495, -1495,  3469,  6559,
    6868, 14661, -1495, -1495, -1495, -1495, -1495, -1495, -1495,   624,
   -1495, -1495,   844, 11468, -1495, 11770,   846,   848, -1495, -1495,
   -1495,   852, -1495,  9958, -1495, -1495, -1495, -1495, -1495, -1495,
     823, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,    45,
     770, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,   -78,
     821,   104, -1495,  -110,   178, -1495, -1495, -1495, -1495, -1495,
   -1495,   868, -1495,   748,   749,   750, -1495, -1495,   831,   845,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495,  7177,  7486, -1495,   677, -1495, -1495, -1495,
   -1495, -1495,  5014,   999, -1495,  5323, -1495, -1495,   510,    71,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495,   103, -1495, -1495, -1495, -1495, -1495,
   -1495,   291, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
    4705, -1495, -1495, -1495, -1495,    19, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495,   893, -1495,   812, -1495, -1495, -1495,
     270, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,   836,
     923, -1495,   790,   769,   919,   598,   633,   -40,   675, -1495,
     969,   824,   920,   918,  8722, -1495, -1495, -1495,     5, -1495,
   -1495, 10267, -1495,   707, -1495,   870, 10576, -1495,   870, 10576,
   -1495, -1495, -1495,   771, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495,   877,   869, -1495, -1495, -1495,
   -1495, -1495,   842, -1495,  4705,   847,   849,   347,   347,   998,
     322,   628,   529, 14948, 14661,   -20,   981, 14661,   880,   911,
     299, 11468,   688,   789, 14661, 14661,   732,    46,    47, -1495,
   -1495, -1495, 11468,  4705,   851,  4705,   122,  9031, 12652,   753,
     756, 14661,   922,   513,   888,  9031,  1041,    67,    63, 14661,
     926,   901,   939, -1495,  9031, 11172, 14661, 14661, 14661,  4705,
     860,  9031,  9031, 14661,  4705,   896,   897, -1495, -1495, -1495,
    9031, 12939,   895, -1495,   898, -1495, -1495, -1495, -1495,   902,
   -1495,   905, -1495, -1495, -1495, -1495, -1495,   906, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, 14661, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,   910,
   14661, -1495, -1495, -1495,   873,  3778,   932,   251,   907,   909,
     912, 14661,  4705, -1495,   914,    17, -1495,   419, -1495,   180,
    1034,  9031, -1495, -1495,   144, -1495, -1495, -1495,  1054, -1495,
   -1495, -1495, -1495,  9031,   859, -1495,  1044,  9031,  9031, 12069,
     887,  9031,  9031,  9031,  9031, 12069,  9031,   850,   856, 14661,
     885,   886,  9031,  9031,  3469,   833, -1495,   -39, -1495,   -28,
    9031, -1495, -1495, -1495, -1495,    62,   119,   109,   110,  1078,
    5632,  5632,  5941,  5941,   822, -1495, -1495,   893,   822, -1495,
    9031, -1495,   973,   639,   -21,   927,   917,   928,  4705,  9031,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,  9340,  9340,
    9340, -1495,  9340,  9340, -1495,  9340, -1495,  9340, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495,  9340,  9340,  1023,  9340,  9340,
    9340,  9340,  9340,  9340,  9340,  9340,  9340,  9340,  9340,  9340,
     866,  1008,  1010,  1011, -1495, -1495, -1495,  7795, -1495, -1495,
    9958,  9958,  9031,   870, -1495, -1495,   870, -1495,  8104,   870,
     961,  8413, -1495, -1495, -1495,   231, -1495,   244, -1495, -1495,
   -1495, -1495, -1495, -1495,  1004,  1005,   574,  1084, -1495, -1495,
   14948,   925,   646, 14661,   955,   957,   925,   998,   992,   993,
   -1495, -1495, -1495,   150,   881,  1033,   832, 14661,   987,  9031,
    1013, 14661, 14661, -1495,  1000,   949,  4705, -1495,   950,   898,
     763, -1495,   948,   951,   420, -1495,   255,   259, -1495, -1495,
    1030, -1495,    33, 14661,    26, 14661,  1045,   272, -1495,  4705,
   -1495,   292, -1495, 11468,  1046,  1095, 11468,   998,  1047,   505,
   14661,  9031,   -21,   461,   954, -1495,   958,   959,   960,    10,
   -1495,   290,   964, -1495,   326,   333,   996, -1495,   966,  4705,
    4705,   465, -1495,   371,   377,   643,  9031,    32, -1495, -1495,
    9031,  9031, -1495,  9031,  9031,  9031, -1495,  9031, -1495,  9031,
   -1495, 14661,  1034, -1495,   177,   501, -1495, -1495, -1495,   515,
   -1495,     1, -1495, -1495,  1001,  1002,  1003,  1006,  1007,   995,
     877, -1495,   153,   232,   -15,   -17,  1058,  1009,   921,   934,
     931,   -24, -1495,  1020, -1495, -1495,   974,   378,  4087,   519,
   10876,   833, -1495, -1495, -1495,   965,   510,   781,  1133,  1133,
   -1495, -1495,   111, -1495, -1495,   112, -1495,    51, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, 14661,   997,  9031,  1050, -1495,
   -1495, -1495,   923, -1495, -1495, -1495, -1495, -1495,  9340, -1495,
   -1495, -1495,    76, -1495,   633,   633,    -4,   -40,   -40,   -40,
     -40,   675,   675, -1495, -1495, 14087, 14087, 14661, 14661, -1495,
     520, -1495, -1495,   225, -1495, -1495, -1495,   396, -1495, -1495,
     414,   347, -1495, -1495,   533,   621,   696, -1495,   574, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,   925,
   -1495,  1037, 14374,  1028,  9031, -1495, -1495, -1495,  1077,   998,
     998,   925, -1495,   786,   998,   629, 14661,   163,   618,  1143,
   -1495, -1495,   889,   577, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495,   150,   169,   947,   588,  9031,
   -1495, 14661,  1081,   878,   998, -1495, -1495, -1495, -1495,  1024,
   14661, -1495, 14661, -1495,  1060,  1052, 14087,  1062,  9031,   -56,
    1038,    24,   315,   933, -1495, -1495,   616,    26,  1077, 14087,
    1066,  1093,  1012,   991,  1057,   998,  1031,  1061,  1094,   998,
    9031,   -60, -1495, -1495, -1495,  1039, -1495, -1495, -1495, -1495,
    1076,  9031,  9031,  1051, -1495,  1097,  1099,  4705, -1495,  1016,
    1017,  1049, 14661, -1495, 14661, -1495,  9031,  1063,  1014,  9031,
   -1495,  1086,   442,   455,   456,  1173, -1495,   212, -1495,   183,
   -1495, -1495,  1180, -1495,  9031,   701,  9031,  9031,  9031,   704,
    9031,  9031,  9031,  9031,  9031,  9031,  9031,  9031,  9031, 12069,
    1096,  9031,  9031, -1495,  6250,  1055,  1056,  1059,  1064,   812,
     538,   972, -1495,   435, -1495,  9031,   121,   200,    51,  5941,
    5941,  5941,  1134, -1495,  9031,   712,  1112, -1495, 14661,  1113,
   -1495, -1495,  9031,    76,   219,   210, -1495,   937,    98,   967,
     968, -1495, -1495,   789, -1495,   962,   -91,  1067,  1069, 14374,
    1070,  1073,  1074,  1075,  1079, -1495,   526, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
    1088, -1495, -1495, -1495,  9031, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495,   723, -1495,  1205,   554, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495,   952, -1495, -1495,
    1207, -1495, -1495, -1495, -1495, -1495,   635,  1209, -1495,   738,
   -1495, -1495, -1495,   895,   382,   902,   731,   905,   906,   821,
   -1495,   526,  9649,   953,   935, -1495,  1077,   169,  1015,  1053,
    4705,  1065,  1068,  1098,  1071,  1072, 14661,    48, -1495, 14661,
   -1495,  9031,  1100,  9031,  1119,  9031,   -46,  1101,  9031,  1102,
   -1495,  1132,  1136,  9031, 14661,   667,  1174, -1495, -1495, -1495,
   -1495, -1495, -1495, 14087, -1495,  4705,   998,  1150, -1495, -1495,
   -1495,   998,  1150, -1495,  9031,  1118,  4705, 14661, -1495, -1495,
    9031,  9031,   754, -1495,    70,   762, -1495, 13226,   765, -1495,
     768, -1495,  1082, -1495, -1495,  4705,  1083,  1085, -1495,  9031,
   -1495, -1495,  9031,  1080,  1097,  1161, -1495,  1130, -1495,   561,
   -1495, -1495,  1256, -1495, -1495,  4705, 14661, -1495,   564, -1495,
   -1495, -1495,  1091,  1087,  1089,  1090, -1495, -1495, -1495,  1103,
    1106, -1495, -1495, -1495,  1169, -1495, -1495,  1104, -1495,  1035,
    1117, 14661,  1092, -1495, -1495,  9031,  9031,  9031,  4396,  6250,
   10876,   972, -1495, 10876, -1495, -1495,  1133,   448, -1495, -1495,
   -1495,  1112, -1495,   998, -1495,   810, -1495,    60,  1163, -1495,
    9031,   666,  1050,   539,  1105, -1495,    76,  1027, -1495, -1495,
     418, -1495,   240,   -11,  1036,    76,   240,  9340, -1495,   235,
   -1495, -1495, -1495, -1495, -1495, -1495,    76,  1135,  1018,   881,
     -11, -1495, -1495,  1019,  1206, -1495, -1495, -1495, 12365,  1107,
    1109,  1110,  1114,  1115,  1120,  1122, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,  1257,   280,
    1259,   280,  1040,  1182, -1495,  1141, 14661,  1108, -1495, -1495,
    9649, -1495,  1116, -1495, -1495, -1495, -1495, -1495, -1495,  9031,
    1158, -1495, -1495,  9031, -1495,   325, -1495,  9031,  1159,  9031,
   -1495,  9031, 14661, 14661, -1495,   746, -1495,  9031, -1495,  1188,
    1189,  1220,   998,  1150, -1495,  9031,  1146, -1495, -1495, -1495,
    1139, -1495,    96,  9031,  4705,  1148,   175, -1495, 14661,  1153,
   13513,   179, -1495, 13800,  1154, -1495, -1495,  1160, -1495, -1495,
   -1495, -1495,  9031,   777,  1173, 14661,   569, -1495,  1162,  1173,
   14661, -1495, -1495, -1495,  9031,  9031,  9031,  9031,  1032,  1225,
    9031,  9031, -1495,  9031,   469,   470,   474,   488, -1495, -1495,
   -1495, -1495, -1495,  1163, -1495, -1495, -1495,   998,  9031, -1495,
    1178, -1495, -1495, -1495, -1495,  1164,  9340, -1495, -1495, -1495,
   -1495, -1495,   346,  9340,  9340,   534, -1495,   967, -1495,   390,
   -1495,   968,    76,  1190, -1495, -1495,  1048, -1495, -1495, -1495,
   -1495,  1248,  1166, -1495,   489, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495,   343,   343, -1495,   280, -1495, -1495,   491,
   -1495,  1316,   -11,  1253,  1167,  9649,   -23,  1111,  1185, -1495,
   -1495,  9031, -1495,  9031,  1203, -1495,  9031, -1495, -1495, -1495,
    1303, -1495, -1495,  6250,  9031,   998, -1495, -1495, -1495,  9031,
    9031, -1495, -1495, -1495,  6250,  6250,  1263,  4705, 14661,  1172,
   14661,  9031, 14661,  1175,  6250, -1495,   268,    41,  1173, 14661,
   -1495,  1170,  1173, -1495, -1495, -1495, -1495,  9031,  9031, -1495,
    1176, -1495,  1165,  1097,  1099,  9031, -1495, -1495, -1495,  1254,
    9031, -1495,   -40,  9340,  9340,    -4,   617, -1495, -1495, -1495,
   -1495, -1495, -1495,  9031, -1495, 14087, -1495, 14087,  1265, -1495,
   -1495, -1495,  1338, -1495, -1495, -1495,  1121,  1262, -1495, -1495,
    1264, -1495,   659, 14661,  1255,  1151, 14661,  9649, -1495, -1495,
    9031, -1495,  1258, -1495, -1495,  1150, -1495, -1495, 14087, -1495,
   -1495,  1278,  9031,  1191, -1495,  1280,  6250, -1495, 14661,   202,
     718, -1495,  1183,  1173, -1495,  1184, -1495, -1495,  1142,  6250,
     779,   548, -1495,  1254,    -4,    -4,  9340,   555, -1495, -1495,
   14087, -1495, -1495,  1253,  9649, -1495,  1163,  1123, 14661,  1266,
    1157,  1264, -1495, 14661,  1197, 14087,  4705, 14087,  1202, -1495,
   -1495,  1296,   527, -1495, -1495, -1495, -1495,  1208,   736, -1495,
   -1495, -1495,  1194, -1495,  9031,  1274, -1495, -1495,    -4, -1495,
   -1495, -1495, -1495, -1495,  9031,  1125, 14661,  1275, -1495,  4705,
    1210, -1495, -1495,  1212,  9031, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, 14661, -1495,  1124,  1126, 14661, -1495, -1495,
    9031,  6250,  1213,  1127,  9031,  1128,  6250,  9649, -1495,  9649,
   -1495,  1196,  1131, 14661,  1177,  1282, 14661,  1129,  9649, -1495
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       159,   449,   450,   451,   162,   162,   162,   798,  1003,   116,
     118,   605,   890,   899,   839,   803,   801,   783,   891,   894,
     846,   807,   784,   785,   838,   900,   787,   897,   868,   848,
     823,   843,   844,   895,   892,   842,   789,   898,   790,   791,
     939,   951,   938,   840,   859,   853,   792,   841,   794,   793,
     940,   877,   878,   845,   820,   961,   962,   963,   964,   965,
     966,   967,   968,   969,   970,   971,   985,   992,   867,   863,
     854,   834,   782,     0,   862,   870,   879,   986,   858,   475,
     835,   836,   893,   987,   993,   855,   872,     0,   481,   438,
     477,   865,   800,   856,   857,   886,   860,   876,   885,   991,
     994,   806,   847,   888,   476,   875,   881,   786,     0,     0,
       0,     0,   386,   873,   884,   889,   887,   866,   852,   941,
     850,   851,   988,     0,   385,     0,   989,   995,   882,   837,
     861,   990,   416,     0,   448,   883,   864,   871,   880,   874,
     942,   828,   833,   832,   831,   830,   829,   795,   849,     0,
     799,   896,   821,   930,   929,   931,   805,   804,   824,   936,
     788,   928,   933,   934,   925,   827,   869,   927,   937,   935,
     926,   825,   932,   946,   947,   944,   945,   943,   796,   948,
     949,   950,   916,   915,   902,   819,   812,   909,   905,   822,
     818,   917,   918,   808,   809,   802,   811,   914,   913,   910,
     906,   923,   924,   922,   912,   908,   901,   810,   921,   920,
     814,   816,   815,   907,   911,   903,   817,   904,   813,   919,
     972,   973,   974,   975,   976,   977,   953,   954,   952,   958,
     959,   960,   955,   956,   957,   826,   978,   979,   980,   981,
     982,   983,   984,     0,     0,   996,   997,   998,  1001,  1000,
     999,  1002,   159,     0,     2,   159,     5,     7,    19,     0,
      24,    27,    32,    33,    34,    35,    36,    37,    38,    28,
      54,    55,    29,    30,     0,    72,    75,    76,    31,    77,
      78,     0,   114,    79,    80,    81,    82,    14,   156,   157,
     158,   165,   167,   468,   168,     0,   169,   170,   171,   172,
     173,   174,   175,   178,   163,   204,   211,   206,   238,   244,
       0,   236,   237,   213,   207,   177,   208,   176,   209,   212,
     339,   341,   343,   353,   355,   359,   361,   364,   369,   372,
     375,   377,   379,   381,     0,   383,   389,   391,     0,   407,
     390,   412,   415,   417,   420,   422,     0,   427,   424,     0,
     435,   445,   447,   421,   452,   459,   473,   460,   461,   462,
     465,   466,   463,   464,   488,   490,   491,   492,   489,   537,
     538,   539,   540,   541,   542,   444,   579,   571,   578,   577,
     576,   573,   575,   572,   574,   474,   467,   606,   607,    39,
     214,   215,   217,   216,   218,   210,   470,   471,   472,   469,
     220,   223,   219,   221,   222,   446,   781,   797,   890,   899,
     897,   799,     0,   160,   161,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   122,
     124,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   263,   264,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   440,   443,   430,
       0,     0,   783,   807,   785,   838,   900,   787,   848,   789,
     859,   792,   794,   793,   877,   985,   992,   782,   986,   836,
     987,   993,   860,   991,   994,   941,   988,   989,   995,   990,
     942,   936,   928,   934,   925,   825,   946,   947,   944,   796,
     948,   997,   436,   446,   781,   428,     0,   185,   429,   432,
     783,   784,   785,   789,   790,   791,   792,   782,   788,   478,
       0,   434,   433,   180,     0,     0,   204,     0,   787,   794,
     793,     0,   162,   757,   948,     0,   211,     0,   479,     0,
     504,     0,   439,   779,     0,   780,   410,   411,     0,   442,
     441,   431,   414,     0,     0,   533,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   759,     0,   761,     0,
       0,     3,     1,     6,     8,     0,     0,     0,     0,     0,
     159,   159,   159,   159,     0,   115,   166,   164,     0,   183,
       0,   192,     0,     0,     0,     0,     0,     0,     0,     0,
     197,   224,   243,   239,   245,   240,   242,   241,     0,     0,
       0,   400,     0,     0,   398,     0,   348,     0,   399,   392,
     397,   396,   395,   394,   393,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   388,   387,   384,     0,   408,   413,
       0,     0,     0,   423,   456,   426,   425,   437,     0,   453,
       0,     0,   544,   546,   550,     0,   120,     0,   778,    43,
      40,    41,    44,    45,     0,     0,     0,     0,    46,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     616,   617,   618,     0,    99,   138,     0,     0,   108,     0,
       0,     0,     0,   123,     0,     0,     0,   585,     0,     0,
       0,   581,     0,     0,     0,   595,     0,     0,   226,   227,
     246,   247,     0,     0,     0,     0,   130,     0,   134,   162,
     609,     0,    56,     0,    65,     0,     0,     0,    57,     0,
       0,     0,     0,     0,     0,   586,     0,     0,     0,     0,
     312,     0,     0,   584,     0,     0,     0,   603,     0,     0,
       0,     0,   589,     0,     0,   187,     0,     0,   181,   179,
       0,     0,   763,     0,     0,     0,   478,     0,   758,     0,
     480,   505,   504,   501,     0,     0,   535,   534,   409,     0,
     532,     0,   629,   630,   783,   785,   789,   792,   782,     0,
       0,   580,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   635,     0,   195,   196,     0,     0,     0,     0,
       0,   200,   201,   760,   762,     0,    20,     0,    21,     0,
       4,    25,     0,    11,    26,     0,    15,   890,    73,    12,
      74,    16,   186,   184,   205,     0,     0,     0,     0,   198,
     225,   281,   340,   342,   346,   352,   351,   350,     0,   347,
     344,   345,     0,   356,   363,   362,   360,   366,   367,   368,
     365,   370,   371,   374,   373,     0,     0,     0,     0,   405,
       0,   418,   419,     0,   457,   454,   486,     0,   608,   484,
       0,     0,   117,   119,     0,     0,     0,    98,     0,    88,
      90,    91,    92,    93,    95,    96,    97,    89,    94,    84,
      85,     0,     0,   104,     0,   100,   102,   103,   110,     0,
       0,    83,    42,     0,     0,     0,     0,     0,     0,     0,
     707,   712,     0,     0,   708,   742,   695,   697,   698,   699,
     701,   703,   702,   700,   704,     0,     0,     0,     0,     0,
     107,     0,   140,     0,     0,   549,   543,   582,   583,     0,
       0,   599,     0,   596,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   228,   229,     0,   234,   136,     0,
       0,   131,     0,     0,     0,     0,     0,     0,    58,     0,
       0,     0,   262,   268,   265,     0,   588,   587,   594,   602,
       0,     0,     0,     0,   548,     0,     0,     0,   401,     0,
       0,     0,     0,   592,     0,   590,     0,   188,     0,     0,
     764,     0,     0,     0,     0,   504,   502,     0,   493,     0,
     482,   483,     0,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   193,     0,   787,   794,   793,   948,     0,
       0,     0,   643,     0,   202,     0,     0,     0,     0,   159,
     159,   159,     0,   235,     0,   296,   292,   294,     0,   282,
     283,   349,     0,     0,     0,     0,   673,   357,   646,   650,
     652,   654,   656,   659,   666,   667,   675,   900,   786,     0,
     795,  1001,  1000,   999,  1002,   376,   555,   561,   562,   565,
     610,   611,   566,   567,   772,   773,   774,   570,   378,   380,
     552,   382,   406,   458,     0,   455,   485,   121,    52,    53,
      50,    51,   127,   126,     0,    86,     0,     0,   105,   106,
     111,    70,    71,    48,    49,    69,   713,     0,   716,   743,
       0,   706,   705,   710,   709,   741,     0,     0,   718,     0,
     714,   717,   696,     0,     0,     0,     0,     0,     0,     0,
     139,   142,     0,     0,     0,   109,   112,     0,     0,     0,
     162,     0,     0,   603,     0,     0,     0,     0,   554,     0,
     249,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     230,     0,     0,     0,     0,   275,     0,   272,   277,   233,
     137,   132,   135,     0,   182,     0,     0,    67,    61,    64,
      63,     0,    59,   266,     0,     0,   162,     0,   310,   314,
       0,     0,     0,   317,     0,     0,   323,     0,     0,   330,
       0,   334,     0,   403,   402,   162,     0,     0,   189,     0,
     191,   311,     0,     0,     0,     0,   505,     0,   494,     0,
     528,   525,     0,   529,   530,     0,     0,   524,     0,   499,
     527,   526,     0,     0,     0,     0,   622,   623,   619,     0,
       0,   627,   628,   624,     0,   766,   633,     0,   631,     0,
       0,     0,     0,   637,   194,     0,     0,     0,     0,     0,
       0,   638,   639,     0,   203,   768,    22,     0,    13,    17,
      18,   293,   305,     0,   306,     0,   297,   298,   299,   300,
       0,   285,     0,     0,     0,   657,   670,     0,   354,   358,
       0,   689,     0,     0,     0,     0,     0,     0,   645,   647,
     648,   684,   685,   686,   688,   687,     0,     0,   661,   660,
       0,   664,   668,   682,   680,   679,   672,   676,     0,     0,
       0,     0,     0,     0,     0,     0,   558,   560,   559,   556,
     553,   487,   129,   128,    87,   101,   730,   711,     0,   735,
       0,   735,   724,   719,   143,     0,     0,     0,   113,   141,
       0,    23,     0,   600,   601,   604,   597,   598,   248,     0,
       0,   261,   253,     0,   257,     0,   251,     0,     0,     0,
     270,     0,     0,     0,   232,   273,   276,     0,   133,     0,
       0,    66,     0,    60,   267,     0,     0,   313,   315,   320,
       0,   318,     0,     0,     0,     0,     0,   324,     0,     0,
       0,     0,   331,     0,     0,   335,   404,     0,   593,   591,
     190,   765,     0,     0,   504,     0,     0,   536,     0,   504,
       0,   500,    10,   769,     0,     0,     0,     0,     0,     0,
       0,     0,   636,     0,     0,     0,     0,     0,   640,   644,
     309,   307,   308,   301,   302,   303,   295,     0,     0,   290,
       0,   284,   674,   665,   671,     0,     0,   744,   745,   755,
     754,   753,     0,     0,     0,     0,   746,   651,   752,     0,
     649,   653,     0,     0,   658,   662,     0,   683,   678,   681,
     677,     0,     0,   568,     0,   563,   615,   557,   776,   777,
     775,   564,   731,     0,     0,   729,   736,   737,   733,     0,
     728,     0,   726,     0,     0,     0,     0,     0,     0,   545,
     250,     0,   259,     0,     0,   255,     0,   258,   271,   279,
     280,   274,   231,     0,     0,     0,    62,   269,   551,     0,
       0,   321,   325,   319,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   547,     0,     0,   504,     0,
     531,     0,   504,   620,   621,   625,   626,     0,     0,   632,
       0,   634,     0,     0,     0,     0,   641,   304,   291,   286,
       0,   669,   756,     0,     0,   748,     0,   694,   693,   692,
     691,   690,   655,     0,   747,     0,   612,     0,     0,   740,
     739,   738,     0,   732,   725,   723,     0,   720,   721,   715,
     144,   146,   148,     0,     0,     0,     0,     0,   254,   252,
       0,   260,     0,   199,   338,    68,   316,   322,     0,   336,
     332,     0,     0,     0,   326,     0,     0,   328,     0,   514,
     508,   503,     0,   504,   495,     0,   767,   770,     0,     0,
       0,     0,   289,   287,   750,   749,     0,     0,   613,   569,
       0,   734,   727,     0,     0,   150,   149,     0,     0,     0,
       0,   145,   256,     0,     0,     0,     0,     0,     0,   522,
     516,     0,   515,   517,   523,   520,   510,     0,   509,   511,
     521,   497,     0,   496,     0,     0,   642,   288,   751,   663,
     614,   722,   147,   151,     0,     0,     0,     0,   278,     0,
       0,   329,   327,     0,     0,   507,   518,   519,   506,   512,
     513,   498,   771,     0,   152,     0,     0,     0,   337,   333,
       0,     0,     0,     0,     0,     0,     0,     0,   154,     0,
     153,     0,     0,     0,     0,     0,     0,     0,     0,   155
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1495, -1495,  -225,  1168, -1495,  1147,  1156, -1495,  1145,  -553,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
    -971, -1495, -1495, -1495, -1495,  -221,  -589, -1495,   689,   -67,
   -1495, -1495, -1495, -1495, -1495,   239,   466, -1495, -1495,   -10,
    -205,   994, -1495,   975, -1495, -1495,  -640, -1495,   404, -1495,
     215, -1495,  -258,  -301, -1495,  -571, -1495,    12,    57,    23,
    -281,  -176, -1495,  -873, -1495, -1495,  -217, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495,   573,   168,  1400,
       0, -1495, -1495, -1495, -1495,   424, -1495, -1495,  -295, -1495,
       8, -1495, -1495,   220,  -727,  -707, -1495, -1495,   654, -1495,
   -1495,    -8,   203, -1495, -1495, -1495,    83, -1494, -1495,   335,
      90, -1495, -1495,    94, -1292, -1495,   903,   185, -1495, -1495,
     182, -1000, -1495, -1495,   181, -1495, -1495, -1242, -1247, -1495,
     184, -1495, -1495,   807,   808, -1495,  -505,   791, -1495, -1495,
    -660,   283,  -632,   287,   288, -1495, -1495, -1495, -1495, -1495,
    1137, -1495, -1495, -1495, -1495,  -841,  -331, -1131, -1495,   -95,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495,   -26,  -796, -1495,
   -1495,   535,   237,  -535,  -398, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495,   757, -1495, -1013, -1495,   161, -1495,   640,  -801,
   -1495, -1495, -1495, -1495, -1495,  -297,  -289, -1218,  -948, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,   549,
    -759,  -791,   257,  -814, -1495,    52,  -819, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495,  1021,  1022,  -222,   464,   293, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495,   139, -1495, -1495,   130, -1495,   133, -1061,
   -1495, -1495, -1495,   100,    93,   -72,   359, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
     105, -1495, -1495, -1495,   -64,   353,   502, -1495, -1495, -1495,
   -1495, -1495,   289, -1495, -1495, -1489, -1495, -1495, -1495,  -602,
   -1495,    68, -1495,   -86, -1495, -1495, -1495, -1495, -1313, -1495,
     115, -1495, -1495, -1495, -1495, -1495,   899, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495,  -393,  -372,    74,   655,
   -1495
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   253,   859,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
    1247,   767,   271,   272,   273,   274,   275,   276,   939,   940,
     941,   277,   278,   279,   945,   946,   947,   280,   437,   281,
     282,   695,   283,   439,   440,   441,   454,   757,   758,   284,
    1200,   285,  1670,  1671,   286,   287,   288,   544,   289,   290,
     291,   292,   293,   760,   294,   295,   527,   296,   297,   298,
     299,   300,   301,   630,   302,   303,   851,   852,   304,   305,
     556,   307,   631,   452,  1006,  1007,   308,   632,   309,   634,
     557,   311,   750,   751,  1235,   461,   312,   462,   463,   754,
    1236,  1237,  1238,   635,   636,  1109,  1110,  1519,   637,  1106,
    1107,  1346,  1347,  1348,  1349,   313,   779,   780,   314,  1262,
    1263,  1462,   315,  1265,  1266,   316,   317,  1268,  1269,  1270,
    1271,   318,   319,   320,   321,   888,   322,   323,  1358,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   655,   656,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   683,   684,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   917,   363,   364,   365,  1298,   812,   813,   814,
    1701,  1747,  1748,  1741,  1742,  1749,  1743,  1299,  1300,   366,
     367,  1301,   368,   369,   370,   371,   372,   373,   374,  1149,
    1001,  1135,  1399,  1136,  1554,  1137,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   786,  1212,   385,   386,
     387,   388,  1139,  1140,  1141,  1142,   389,   390,   391,   392,
     393,   394,   841,   842,   395,  1331,  1332,  1636,  1093,  1117,
    1368,  1369,  1118,  1119,  1120,  1121,  1122,  1378,  1544,  1545,
    1123,  1381,  1124,  1525,  1125,  1126,  1386,  1387,  1550,  1548,
    1370,  1371,  1372,  1373,  1650,   724,   966,   967,   968,   969,
     970,   971,  1190,  1574,  1667,  1191,  1572,  1665,   972,  1411,
    1569,  1565,  1566,  1567,   973,   974,  1374,  1382,  1535,  1375,
    1531,  1359,   396,   397,   398,   399,   547,   400,   401,   402,
     403,   404,  1143,  1144,  1145,  1146,  1248,   564,   405,   406,
     407
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char xquery_parser::yytable_ninf_ = -1;
  const unsigned short int
  xquery_parser::yytable_[] =
  {
       306,   896,   438,   595,   306,   306,   306,   678,   310,   616,
    1021,  1057,   310,   310,   310,   633,   412,   415,   416,   696,
     696,  1472,  1033,   868,   870,   999,   699,   414,   414,   414,
     897,   898,   899,   900,   611,  1264,  1047,   608,   572,   863,
     866,   869,   871,  1483,   829,  1000,  1297,   522,  1252,   613,
     837,  1115,  1354,  1163,  1092,  1514,  1515,   861,   864,   719,
    1224,   413,   413,   413,   764,   768,   926,  1546,   620,   995,
     734,  1415,   609,     9,    10,   574,   615,     9,    10,   620,
    1491,  1003,  1254,  1080,  1668,  1532,  1138,  1138,     9,    10,
     801,  1221,   698,   776,   423,  1673,   698,   459,   423,   419,
     420,  1437,   421,   422,   609,    11,   800,   424,   306,   423,
     609,   609,   609,   609,   584,  1148,   310,  1030,   424,   425,
     997,   426,   609,  1138,   620,   426,   618,   996,  1167,   997,
     427,   545,  1062,   616,  1699,   884,   426,   885,   886,  1030,
     887,   427,   889,   456,   997,  1712,   577,   523,   578,   708,
     890,   891,   816,   457,   659,  1383,  1384,  1201,   677,   730,
     666,   539,   428,   429,  1102,   413,  1343,   739,   445,   667,
    1463,  1225,   660,   428,   429,   430,   765,  1138,  1385,   458,
     998,   709,   125,   728,   740,   560,    79,  1345,   729,  1170,
    1138,  1063,  1290,  1291,  1360,  1429,  1463,   565,  1031,   568,
      90,  1674,   808,   585,   955,  1218,   956,  1739,  1193,   619,
    1081,  1290,   460,  1194,   739,  1074,   460,  1073,  1241,  1757,
    1049,  1637,   431,   766,  1700,   104,   460,   763,  1195,  1112,
    1196,   740,  1113,   615,  1761,   579,  1472,   419,   420,  1197,
     421,   422,  1004,  1229,  1533,  1534,   679,  1065,    11,  1240,
     957,   460,   306,   125,  1287,   306,  1464,   425,   575,  1666,
     310,   610,   633,   310,   616,  1466,  1198,  1361,  1491,   868,
     870,   853,  1115,  1115,  1226,  1463,  1297,   555,   559,  1005,
    1453,   432,  1600,  1675,   854,  1297,  1292,   620,  1164,  1578,
     306,  1403,  1222,   612,  1227,  1524,   460,  1610,   310,   856,
     858,  1099,  1101,   861,   864,   460,  1293,  1058,  1294,   741,
    1138,  1336,   622,  1337,  1255,  1390,   623,     9,    10,   817,
     685,   624,   433,   687,   952,  1293,  1069,  1294,   581,    79,
     582,  1360,   620,   731,  1114,  1740,  1295,   434,   921,   625,
     111,   732,  1288,    90,   714,   435,   715,   879,   434,  1362,
    1363,   921,  1364,   436,   417,  1295,   435,   123,   801,  1365,
     431,  1605,   990,  1356,   436,  1611,   992,   810,   104,  1366,
    1066,  1067,  1112,  1059,  1018,  1113,    11,  1296,   716,  1010,
    1725,  1367,   857,  1111,   996,  1068,  1698,   125,  1201,   862,
     865,  1014,  1710,  1199,  1017,   149,   125,   872,  1643,   620,
     958,   873,   586,   614,  1361,   717,   473,   587,  1289,   996,
    1153,   597,   599,   959,   306,   960,  1563,   583,   922,   432,
     523,   997,   310,   523,  1138,  1181,   961,   962,   963,   418,
     964,   923,   965,   620,  1763,   802,  1182,  1032,   626,  1408,
     620,   627,   991,   306,  1672,   306,   993,  1418,  1138,  1070,
    1071,   310,  1448,   310,  1611,   616,   628,    79,   617,  1011,
     433,   622,  1228,  1472,  1072,   623,   736,   718,   736,   306,
     624,    90,  1583,  1297,   306,  1644,  1469,   310,  1042,  1013,
    1564,   629,   310,   474,  1044,   620,  1362,  1363,   625,  1364,
    1430,   588,   736,   714,  1116,   715,   104,   736,   707,  1410,
     735,   711,   738,  1154,   700,   565,  1366,  1529,   725,   726,
     868,   870,   868,  1035,  1530,  1115,   565,   701,  1367,  1438,
    1036,  1154,   747,  1157,  1115,   752,   782,   620,  1338,  1339,
    1340,   788,  1739,   769,  1092,  1115,  1290,  1509,   446,   565,
     777,   778,   781,   605,  1320,   306,  1672,   787,   659,   620,
     475,   476,   306,   310,   717,   794,  1171,  1172,  1043,   606,
     310,  1175,   620,   620,  1045,  1084,   660,   616,   620,  1138,
    1290,  1291,   620,  1290,  1291,   414,   620,   620,  1290,  1291,
     622,   620,   617,  1155,   623,   911,   912,   626,  1328,   624,
     627,  1209,  1520,  1672,   306,   438,  1657,  1553,  1662,   996,
     795,  1156,   310,   443,   989,   809,   444,   625,   620,   413,
     306,   306,   306,   306,   781,   744,   718,   848,   310,   310,
     310,   310,   620,   761,  1685,   806,   620,   620,   306,  1283,
     629,   755,   773,  1466,  1527,  1096,   310,  1100,   442,   784,
     785,  1635,  1284,  1285,  1333,  1025,   620,  1020,   791,  1041,
    1293,  1138,  1294,   830,  1138,   620,  1632,  1633,  1647,   830,
    1776,  1634,   620,   843,  1292,  1648,  1800,  1292,  1801,  1231,
    1396,  1528,  1292,  1187,  1232,  1649,  1658,  1809,  1663,  1609,
    1295,  1158,  1613,  1617,  1293,  1060,  1294,  1293,  1621,  1294,
    1188,   943,  1293,  1233,  1294,   704,   944,  1333,  1159,  1061,
     756,  1115,  1397,  1091,  1152,   449,   626,  1539,  1584,   627,
     450,   705,   997,   617,  1295,  1116,  1116,  1295,   111,  1398,
    1231,   111,  1295,  1522,  1329,  1232,   111,  1290,   524,   815,
     453,  1408,  1756,  1189,  1234,   123,   306,   996,   123,  1759,
     942,   819,   524,   123,   310,  1290,  1745,   868,  1409,   629,
     662,  1744,  1750,   996,   468,  1485,   659,   451,  1490,   306,
     996,   847,   849,  1619,  1745,  1343,   524,   310,  1211,  1160,
    1214,  1012,  1517,   149,   660,   659,   149,   561,   524,   663,
     524,   149,   414,   943,   678,  1046,  1161,   948,   944,   306,
     306,  1410,   664,   660,  1744,   633,   661,   310,   310,  1231,
    1750,   978,  1647,  1324,  1232,   982,   983,  1342,  1518,  1648,
     702,   668,   736,   736,  1097,  1716,   413,  1702,  1343,  1649,
    1276,  1705,  1277,   703,   479,   669,   665,  1002,  1344,  1008,
     606,   477,   447,  1162,  1187,   448,  1138,   565,  1138,  1345,
     565,  1293,   997,  1294,  1022,   910,  1039,  1040,  1089,   759,
     913,  1188,  1746,  1451,  1261,   480,  1090,   438,   481,  1293,
    1402,  1294,  1261,   478,  1718,  1470,  1719,  1460,  1473,  1138,
    1779,  1295,  1165,  1645,  1646,  1465,   759,  1470,  1471,  1470,
    1183,  1474,   455,   686,  1165,  1055,  1203,   466,   689,  1295,
    1616,  1184,  1755,   464,  1642,  1204,   465,  1734,   680,   681,
     469,  1138,  1752,   470,   617,  1176,  1177,  1178,   720,   721,
     722,  1179,   595,  1726,  1173,  1174,  1138,  1334,  1138,   467,
     914,   525,   640,   914,   523,   682,   914,   688,   471,  1760,
     641,   642,  1304,   643,  1305,  1309,   472,  1310,  1511,  1512,
     526,   644,   894,   895,  1770,   645,  1773,   646,   528,  1103,
    1510,   529,   647,   901,   902,   540,   903,   904,  1116,  1150,
    1150,  1659,  1660,   541,  1449,   542,   562,  1116,   569,   648,
     570,  1052,  1053,  1054,   571,   849,   573,   580,  1116,  1147,
    1147,  1147,  1147,  1714,  1715,   576,   589,   593,   590,   591,
     600,   592,   649,   650,   651,   652,   653,   654,   594,   602,
     620,   524,   621,   638,   524,   929,   930,   931,   932,   933,
     934,   935,   936,   937,   938,   639,  1147,   657,   658,   670,
     673,   672,   690,   671,   682,   691,   692,   698,   710,   713,
    1180,   693,   712,   694,   723,   727,   748,   306,   737,   749,
     753,   759,   762,   771,   770,   310,   772,   783,   879,   789,
     790,   444,   796,   800,   448,  1206,  1758,   798,   465,  1596,
     736,   470,   481,   803,  1213,   804,  1213,   807,   805,   811,
    1147,   818,   820,   821,   831,   844,   845,   850,   706,   524,
     839,   860,   524,  1147,  1089,   840,   524,   877,   438,   524,
     524,   875,  1090,   892,  1272,   876,   905,   524,   878,   306,
     306,   306,   906,   524,   907,   908,   524,   310,   310,   310,
     918,   924,   925,   927,   524,   949,   787,   950,   787,   953,
     524,   524,   524,   524,  1638,   954,   975,   976,   524,   979,
     977,   981,   984,   985,   986,   987,   524,   994,   988,  1009,
    1016,  1026,  1015,  1019,  1116,  1027,  1028,  1029,  1034,  1037,
    1038,  1064,  1075,   830,   443,   447,   464,  1077,  1078,   469,
     480,  1079,  1082,  1095,  1083,  1076,  1098,  1104,  1108,  1166,
     944,   996,  1185,  1202,  1186,  1207,  1208,  1210,  1216,  1217,
    1219,   524,  1351,  1602,   755,  1223,  1230,  1243,  1245,  1246,
    1251,  1249,  1256,  1250,  1257,   524,  1244,  1261,  1260,  1267,
    1273,  1274,  1275,  1147,  1280,  1279,   524,  1282,  1286,  1302,
     306,  1325,  1326,   716,  1321,  1327,  1330,  1328,   310,  1350,
    1352,  1357,  1422,  1388,  1376,  1389,  1391,  1377,  1380,  1392,
    1393,  1394,  1400,   414,    11,  1395,  1407,  1406,  1412,  1416,
    1417,  1420,  1425,  1421,   524,   306,  1435,  1433,  1439,  1441,
    1442,  1447,  1423,   310,  1443,  1424,   306,  1452,  1426,  1427,
    1455,  1470,  1484,  1487,   310,  1498,  1476,   413,  1456,  1343,
    1478,  1500,  1479,  1501,  1493,   306,  1526,  1482,  1503,   414,
    1353,  1492,  1542,   310,  1549,  1536,  1562,  1477,  1568,  1573,
     752,  1499,  1523,  1431,  1555,   306,  1556,  1557,   414,  1543,
    1579,  1558,  1559,   310,  1547,  1581,  1586,  1560,  1445,  1561,
    1571,  1575,  1683,   413,  1593,  1594,  1595,  1147,   736,  1628,
    1640,  1494,  1495,  1687,  1602,  1599,  1689,  1654,  1089,  1089,
    1598,   781,   413,  1697,  1604,  1496,  1090,  1090,  1497,  1607,
    1614,  1147,  1655,  1653,  1615,  1664,  1620,  1627,  1641,  1187,
    1680,   848,  1488,  1656,  1669,  1677,  1682,  1688,  1692,  1720,
    1517,  1696,  1709,  1708,  1577,   928,  1704,  1721,   524,  1723,
    1489,  1724,  1735,  1728,  1737,  1729,  1733,  1736,  1754,  1751,
    1753,  1767,   524,  1769,  1766,  1722,   524,   524,  1774,  1775,
    1781,  1778,  1783,  1787,  1802,   843,  1790,  1676,  1791,  1796,
    1806,  1805,   603,   607,   523,   951,  1405,   523,   524,  1168,
     524,   604,   697,   733,  1242,  1689,  1793,  1803,   524,  1731,
     601,   524,  1419,  1762,  1094,   524,  1024,  1764,  1449,  1785,
    1794,  1239,  1797,  1799,  1808,  1521,  1428,  1591,  1446,  1341,
    1516,  1513,  1457,   797,  1461,   882,  1467,   883,   920,   893,
    1486,  1780,  1056,  1777,  1475,  1771,  1215,  1151,  1414,  1404,
    1502,  1508,  1147,  1507,   306,  1537,   524,   742,   743,  1541,
    1652,   676,   310,  1355,  1540,  1651,  1379,  1192,  1413,  1570,
    1661,  1538,   835,     0,     0,     0,     0,     0,  1788,     0,
    1576,     0,     0,  1504,  1505,  1506,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   524,     0,     0,   546,     0,
    1788,     0,     0,     0,     0,  1771,  1589,  1590,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     524,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1606,     0,  1147,     0,     0,  1147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1618,
     524,   524,   524,   524,  1622,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1089,     0,     0,     0,   524,     0,     0,
       0,  1090,     0,     0,  1089,  1089,     0,   306,     0,     0,
       0,   524,  1090,  1090,  1089,   310,     0,     0,     0,     0,
       0,     0,  1090,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   524,     0,     0,     0,
       0,     0,     0,     0,     0,   524,     0,   524,     0,     0,
       0,   524,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   524,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1691,     0,  1693,     0,  1695,     0,     0,     0,
       0,     0,     0,  1703,     0,     0,  1089,   524,     0,   524,
       0,     0,     0,     0,  1090,     0,     0,     0,     0,  1089,
       0,     0,     0,     0,     0,     0,     0,  1090,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1147,
       0,  1147,     0,     0,     0,     0,   306,     0,     0,     0,
       0,     0,     0,     0,   310,     0,     0,  1727,     0,     0,
    1730,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1147,   524,     0,     0,     0,     0,     0,   306,
       0,     0,  1738,     0,     0,     0,     0,   310,     0,     0,
       0,     0,     0,     0,   524,     0,     0,     0,     0,     0,
       0,  1089,     0,     0,  1147,     0,  1089,     0,     0,  1090,
       0,     0,  1765,  1711,  1090,     0,     0,  1768,     0,  1147,
       0,  1147,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1717,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1786,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1792,     0,     0,
       0,  1795,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   524,     0,     0,   524,     0,     0,  1804,     0,     0,
    1807,     0,     0,     0,     0,     0,     0,     0,     0,   524,
       0,     0,     0,     0,     0,     0,     0,     0,   524,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   524,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   524,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   524,   546,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   524,   822,   823,     0,
       0,   832,   833,   834,   836,   524,   838,     0,   524,     0,
       0,     0,   846,     0,     0,     0,     0,     0,     0,     0,
     855,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     874,     0,     0,     0,     0,     0,     0,     0,   880,   881,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   524,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   524,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   916,     0,
       0,   916,     0,     0,     0,     0,     0,   524,   524,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   524,     0,   524,     0,     0,   524,   980,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     524,     0,     0,     0,     0,   524,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1023,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1048,     0,     0,     0,
    1050,  1051,     0,     0,     0,     0,     0,     0,     0,   880,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   524,     0,   524,     0,   524,     0,     0,
       0,     0,     0,     0,   524,     0,     0,  1105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     524,     0,   524,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   524,     0,
       0,   524,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   524,  1169,     0,     0,     0,     0,     0,
       0,     0,     0,   524,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   524,     0,     0,     0,  1205,
       0,     0,     0,   524,     0,     0,     0,     0,   524,     0,
     524,     0,   524,     0,     0,     0,     0,     0,  1220,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1253,   524,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1258,  1259,     0,     0,     0,     0,     0,   524,     0,
       0,     0,   524,     0,     0,     0,  1278,     0,     0,  1281,
       0,     0,     0,     0,     0,     0,     0,     0,   524,     0,
       0,   524,     0,     0,  1303,     0,  1306,  1307,  1308,     0,
    1311,  1312,  1313,  1314,  1315,  1316,  1317,  1318,  1319,     0,
       0,  1322,  1323,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1335,     0,     0,     0,     0,
       0,     0,     0,     0,  1105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1401,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1432,     0,  1434,     0,  1436,     0,     0,  1440,     0,
       0,     0,     0,  1444,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1450,     0,     0,     0,     0,
       0,     0,     0,     0,  1454,     0,     0,     0,     0,     0,
    1458,  1459,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1480,
       0,     0,  1481,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1105,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1580,
       0,     0,     0,  1582,     0,     0,     0,  1585,     0,  1587,
       0,  1588,     0,     0,     0,     0,     0,  1592,     0,     0,
       0,     0,     0,     0,     0,  1597,     0,     0,     0,     0,
       0,     0,     0,  1601,  1603,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1450,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1623,  1624,  1625,  1626,     0,     0,
    1629,  1630,     0,  1631,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1639,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1678,     0,  1679,     0,     0,  1681,     0,     0,     0,
       0,     0,     0,     0,  1684,     0,     0,     0,     0,  1686,
    1603,     0,     0,     0,     0,     0,     0,  1690,     0,     0,
       0,  1694,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1706,  1707,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1713,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1732,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1690,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1772,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1782,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1784,     0,     0,     0,     0,  1789,
       1,     2,     0,     0,  1772,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,     0,    11,     0,
    1789,     0,    12,    13,  1798,    14,    15,    16,    17,    18,
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
     244,     0,   245,   246,   247,   248,   249,   250,   251,   252,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,     0,    11,     0,
       0,     0,   408,   409,     0,    14,    15,    16,    17,    18,
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
     127,   128,     0,   543,     0,   129,     0,   130,   131,     0,
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
      20,    21,    22,    23,    24,    25,    26,   410,    28,    29,
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
     128,     0,   799,     0,   129,     0,   130,   131,     0,   132,
     133,   134,     0,   135,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
     149,     0,   411,   151,   152,   153,   154,   155,   156,   157,
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
     408,   409,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,  1085,   410,    28,    29,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,  1086,
    1087,    50,    51,    52,    53,    54,    55,    56,    57,    58,
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
       0,   799,     0,   129,     0,   130,   131,     0,   132,   133,
     134,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   411,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
    1088,   180,   181,   182,   183,   184,   185,   186,   187,   188,
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
      22,    23,    24,    25,  1085,   410,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,  1086,  1087,
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
     543,     0,   129,     0,   130,   131,     0,   132,   133,   134,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,   149,     0,
     411,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,  1088,
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
      23,    24,    25,    26,   410,    28,    29,    30,    31,     0,
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
     144,   145,   146,     0,     0,   147,   148,   149,     0,   411,
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
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,    12,    13,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,     0,    32,
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
     124,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,     0,   130,   131,     0,   132,   133,   134,     0,   135,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,   149,     0,   150,   151,
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
       0,    11,     0,     0,     0,    12,   409,     0,    14,    15,
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
       0,     0,   147,   148,   149,     0,   411,   151,   152,   153,
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
      11,     0,     0,     0,   867,   409,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
     410,    28,    29,    30,    31,     0,    32,    33,    34,    35,
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
       0,     0,     0,   408,   409,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,  1085,   410,
      28,    29,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,  1086,  1087,    50,    51,    52,    53,    54,    55,
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
     176,   177,   178,  1088,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
       0,   244,     0,   245,   246,   247,   248,   249,   250,   251,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     0,     0,     0,    11,     0,
       0,     0,   408,   409,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   548,   410,    28,
      29,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,   549,   550,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,     0,    74,
      75,    76,     0,     0,    77,    78,     0,     0,     0,    79,
      80,   499,    82,    83,    84,    85,    86,   551,    88,    89,
       0,     0,     0,    90,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,    96,    97,    98,    99,   100,     0,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   552,   109,     0,   110,   111,   112,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,     0,   123,     0,   124,   125,     0,     0,   126,
     127,   128,     0,     0,   553,   129,     0,   130,   131,     0,
     132,   133,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   411,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   516,   517,   518,   176,
     177,   519,   554,   180,   181,   182,   183,   184,   185,   186,
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
      20,    21,    22,    23,    24,    25,   548,   410,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     549,   550,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     499,    82,    83,    84,    85,    86,   551,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   552,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,   558,   130,   131,     0,   132,
     133,   134,     0,   135,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
     149,     0,   411,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   516,   517,   518,   176,   177,
     519,   554,   180,   181,   182,   183,   184,   185,   186,   187,
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
      21,    22,    23,    24,    25,   548,   410,    28,    29,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,   549,
     550,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,     0,    74,    75,    76,
       0,     0,    77,    78,     0,     0,     0,    79,    80,   499,
      82,    83,    84,    85,    86,   551,    88,    89,     0,     0,
       0,    90,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,    96,    97,    98,    99,   100,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     552,   109,     0,   110,   111,   112,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
       0,   123,     0,   124,   125,     0,     0,   126,   127,   128,
       0,     0,     0,   129,     0,   130,   131,     0,   132,   133,
     134,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   411,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   516,   517,   518,   176,   177,   519,
     554,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   596,   244,     0,
     245,   246,   247,   248,   249,   250,   251,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     0,     0,     0,    11,     0,     0,     0,   408,
     409,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   548,   410,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,   549,   550,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,     0,    74,    75,    76,     0,
       0,    77,    78,     0,     0,     0,    79,    80,   499,    82,
      83,    84,    85,    86,   551,    88,    89,     0,     0,     0,
      90,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   552,
     109,     0,   110,   111,   112,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,     0,
     123,     0,   124,   125,     0,     0,   126,   127,   128,     0,
       0,     0,   129,     0,   130,   131,     0,   132,   133,   134,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,   149,     0,
     411,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   516,   517,   518,   176,   177,   519,   554,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,     0,   244,   598,   245,
     246,   247,   248,   249,   250,   251,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     0,     0,     0,    11,     0,     0,     0,   408,   409,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   548,   410,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,   549,   550,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,     0,    74,    75,    76,     0,     0,
      77,    78,     0,     0,     0,    79,    80,   499,    82,    83,
      84,    85,    86,   551,    88,    89,     0,     0,     0,    90,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
      96,    97,    98,    99,   100,     0,     0,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   552,   109,
       0,   110,   111,   112,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,     0,   123,
       0,   124,   125,     0,     0,   126,   127,   128,     0,   909,
       0,   129,     0,   130,   131,     0,   132,   133,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   411,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   516,   517,   518,   176,   177,   519,   554,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   408,   409,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   548,   410,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,   549,   550,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   499,    82,    83,    84,
      85,    86,   551,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   552,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,   915,   130,   131,     0,   132,   133,   134,     0,   135,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,   149,     0,   411,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   516,   517,   518,   176,   177,   519,   554,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,     0,   244,     0,   245,   246,   247,
     248,   249,   250,   251,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     0,
       0,     0,    11,     0,     0,     0,   408,   409,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   548,   410,    28,    29,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,    45,    46,    47,   549,   550,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,     0,    74,    75,    76,     0,     0,    77,    78,
       0,     0,     0,    79,    80,   499,    82,    83,    84,    85,
      86,   551,    88,    89,     0,     0,     0,    90,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,    96,    97,
      98,    99,   100,     0,     0,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   552,   109,     0,   110,
     111,   112,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,     0,   123,     0,   124,
     125,     0,     0,   126,   127,   128,     0,     0,     0,   129,
     919,   130,   131,     0,   132,   133,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   411,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     516,   517,   518,   176,   177,   519,   554,   180,   181,   182,
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
      16,    17,    18,    19,    20,    21,    22,    23,   485,    25,
     487,   410,    28,   488,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,   490,
       0,    45,    46,    47,   492,   493,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   499,    82,    83,    84,    85,    86,
     551,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   502,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   552,   109,     0,   110,   111,
     674,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,   675,   125,
       0,     0,   126,   127,   128,     0,     0,     0,   129,     0,
     130,   131,     0,   132,   133,   134,     0,   135,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,   149,     0,   411,   151,   152,   153,
     154,   155,   156,   157,   158,   511,   160,   512,   162,   513,
     514,   165,   166,   167,   168,   169,   170,   515,   172,   516,
     517,   518,   176,   177,   519,   520,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,     0,   244,     0,   245,   521,   247,   248,   249,
     250,   251,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     0,     0,     0,
      11,     0,     0,     0,   408,   409,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,   548,
     410,    28,    29,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,   549,   550,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
       0,    74,    75,    76,     0,     0,    77,    78,     0,     0,
       0,    79,    80,   499,    82,    83,    84,    85,    86,   551,
      88,    89,     0,     0,     0,    90,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,    96,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   552,   109,     0,   110,   111,   112,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,   121,   122,     0,   123,     0,   124,   125,     0,
       0,   126,   127,   128,     0,     0,     0,   129,     0,   130,
     131,     0,   132,   133,   134,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,   149,     0,   411,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   516,   517,
     518,   176,   177,   519,   554,   180,   181,   182,   183,   184,
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
      18,    19,    20,    21,    22,    23,   485,    25,   487,   410,
      28,   488,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,   490,     0,    45,
      46,    47,   492,   493,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,    73,     0,
      74,    75,    76,     0,     0,    77,    78,     0,     0,     0,
      79,    80,   499,    82,    83,    84,    85,    86,   551,    88,
      89,     0,     0,     0,    90,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   502,    97,    98,    99,   100,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   552,   109,     0,   110,   111,   112,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,     0,   123,     0,   124,   125,     0,     0,
     126,   127,   128,     0,     0,     0,   129,     0,   130,   131,
       0,   132,   133,   134,     0,   135,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,   149,     0,   411,   151,   152,   153,   154,   155,
     156,   157,   158,   511,   160,   512,   162,   513,   514,   165,
     166,   167,   168,   169,   170,   515,   172,   516,   517,   518,
     176,   177,   519,   520,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
       0,   244,     0,   245,   521,   247,   248,   249,   250,   251,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     0,     0,     0,    11,     0,
       0,     0,   408,   409,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,   485,    25,   487,   410,    28,
     488,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,   490,     0,    45,    46,
      47,   492,   493,    50,   494,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,     0,    74,
      75,    76,     0,     0,    77,    78,     0,     0,     0,    79,
      80,   499,    82,    83,    84,    85,    86,   551,    88,    89,
       0,     0,     0,    90,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   502,    97,    98,    99,   100,     0,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   552,   109,     0,   110,   111,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,     0,   123,     0,     0,     0,     0,     0,   126,
     127,   128,     0,     0,     0,   129,     0,   130,   131,     0,
     132,   133,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   411,   151,   152,   153,   154,   155,   156,
     157,   158,   511,   160,   512,   162,   513,   514,   165,   166,
     167,   168,   169,   170,   515,   172,   516,   517,   518,   176,
     177,   519,   520,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   521,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   408,   409,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   485,    25,   487,   410,    28,   488,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,   490,     0,    45,    46,    47,
     492,   493,    50,   494,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     499,    82,    83,    84,    85,    86,   551,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   502,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   552,   109,     0,   110,   111,     0,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,     0,     0,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,     0,
       0,   134,     0,   135,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
     149,     0,   411,   151,   152,   153,   154,   155,   156,   157,
     158,   511,   160,   512,   162,   513,   514,   165,   166,   167,
     168,   169,   170,   515,   172,   516,   517,   518,   176,   177,
     519,   520,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,     0,   244,
       0,   245,   521,   247,   248,   249,   250,   251,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     0,     0,     0,    11,     0,     0,     0,
     408,   409,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,   485,    25,   487,   410,    28,   488,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,   490,     0,    45,    46,    47,   492,
     493,    50,   494,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,     0,    74,    75,    76,
       0,     0,    77,    78,     0,     0,     0,    79,    80,   499,
      82,    83,    84,    85,    86,   551,    88,    89,     0,     0,
       0,    90,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   502,     0,    98,    99,   100,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,     0,   106,   107,
     552,   109,     0,   110,   111,     0,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
       0,   123,     0,     0,     0,     0,     0,   126,   127,   128,
       0,     0,     0,   129,     0,   130,   131,     0,     0,     0,
     134,     0,   135,     0,   136,     0,   138,     0,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   411,   151,   152,   153,   154,   155,   156,   157,   158,
     511,   160,   512,   162,   513,   514,   165,   166,   167,   168,
     169,   170,   515,   172,   516,   517,   518,   176,   177,   519,
     520,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,     0,   244,     0,
     245,   521,   247,   248,   249,   250,   251,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     0,     0,     0,
       7,     8,     0,     0,     0,     0,     0,     0,     0,   408,
     409,     0,    14,    15,    16,   482,    18,    19,    20,   483,
      22,   484,   485,   486,   487,   410,    28,   488,    30,    31,
       0,    32,    33,    34,    35,   489,    37,    38,    39,    40,
      41,    42,    43,   490,     0,    45,   491,    47,   492,   493,
      50,   494,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   495,   496,    68,     0,
      69,    70,    71,   497,     0,     0,    74,    75,    76,     0,
       0,   498,    78,     0,     0,     0,     0,    80,   499,    82,
     500,   501,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   502,    97,    98,   503,   504,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,   107,     0,
       0,     0,     0,     0,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   505,   120,   121,   506,     0,
       0,     0,     0,     0,     0,     0,   507,   508,   128,     0,
       0,     0,   129,     0,   130,   509,     0,     0,     0,   134,
       0,   135,     0,   136,   137,   138,   139,   510,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,     0,     0,
     411,   151,   152,   153,   154,   155,   156,   157,   158,   511,
     160,   512,   162,   513,   514,   165,   166,   167,   168,   169,
     170,   515,   172,   516,   517,   518,   176,   177,   519,   520,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,     0,     1,     2,   245,
     521,   247,   248,   249,   250,   251,     3,     0,     0,     0,
       7,     8,     0,     0,     0,     0,     0,     0,     0,   408,
     409,     0,    14,    15,    16,   530,    18,    19,    20,   483,
     531,   532,   485,   486,   487,   410,    28,   488,    30,    31,
       0,    32,    33,    34,    35,   533,    37,   534,   535,    40,
      41,    42,    43,   490,     0,    45,   536,    47,   492,   493,
      50,   494,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   495,   496,    68,     0,
      69,    70,    71,   537,     0,     0,    74,    75,    76,     0,
       0,   498,    78,     0,     0,     0,     0,    80,   499,    82,
     500,   501,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   502,    97,    98,   503,   504,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,   107,     0,
       0,     0,     0,     0,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   505,   120,   121,   506,     0,
       0,     0,     0,     0,     0,     0,   507,   508,   128,     0,
       0,     0,   129,     0,   130,   509,     0,     0,     0,   134,
       0,   135,     0,   136,   137,   138,   139,   510,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,     0,     0,
     411,   151,   152,   153,   154,   155,   156,   157,   158,   511,
     538,   512,   162,   513,   514,   165,   166,   167,   168,   169,
     170,   515,   172,   516,   517,   518,   176,   177,   519,   520,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,     0,     0,   563,   245,
     521,   247,   248,   249,   250,   251,     7,     8,     0,     0,
       0,   774,     0,     0,     0,   408,   409,     0,    14,    15,
      16,   530,    18,    19,    20,   483,   531,   532,   485,   486,
     487,   410,    28,   488,    30,    31,     0,    32,    33,    34,
      35,   533,    37,   534,   535,    40,    41,    42,    43,   490,
       0,    45,   536,    47,   492,   493,    50,   494,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   495,   496,    68,     0,    69,    70,    71,   537,
       0,     0,    74,    75,    76,     0,     0,   498,    78,     0,
       0,     0,     0,    80,   499,    82,   500,   501,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   502,    97,    98,
     503,   504,     0,     0,     0,     0,     0,     0,   101,   102,
     103,     0,   105,   106,   107,     0,     0,     0,     0,     0,
       0,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   505,   120,   121,   506,     0,     0,     0,     0,     0,
       0,     0,   507,   508,   128,     0,     0,     0,   129,   775,
     130,   509,     0,     0,     0,     0,     0,   135,     0,   136,
     137,   138,   139,   510,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,     0,     0,   411,   151,   152,   153,
     154,   155,   156,   157,   158,   511,   538,   512,   162,   513,
     514,   165,   166,   167,   168,   169,   170,   515,   172,   516,
     517,   518,   176,   177,   519,   520,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     0,     0,     0,   563,   245,   521,   247,   248,   249,
     250,   251,     7,     8,     0,     0,     0,     0,     0,     0,
       0,   408,   409,     0,    14,    15,    16,   530,    18,    19,
      20,   483,   531,   532,   485,   486,   487,   410,    28,   488,
      30,    31,     0,    32,    33,    34,    35,   533,    37,   534,
     535,    40,    41,    42,    43,   490,     0,    45,   536,    47,
     492,   493,    50,   494,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,   495,   496,
      68,     0,    69,    70,    71,   537,     0,     0,    74,    75,
      76,     0,     0,   498,    78,     0,     0,     0,     0,    80,
     499,    82,   500,   501,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   502,    97,    98,   503,   504,     0,     0,
       0,     0,     0,     0,   101,   102,   103,     0,   105,   106,
     107,     0,     0,     0,     0,     0,     0,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   505,   120,   121,
     506,     0,     0,     0,     0,     0,     0,     0,   507,   508,
     128,     0,     0,     0,   129,     0,   130,   509,     0,     0,
       0,     0,     0,   135,     0,   136,   137,   138,   139,   510,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
       0,     0,   411,   151,   152,   153,   154,   155,   156,   157,
     158,   511,   538,   512,   162,   513,   514,   165,   166,   167,
     168,   169,   170,   515,   172,   516,   517,   518,   176,   177,
     519,   520,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,     0,     0,     0,
       0,   245,   521,   247,   248,   249,   250,   251,   566,   567,
       0,     0,     0,     0,     7,     8,     0,     0,     0,     0,
       0,     0,     0,   408,   409,     0,    14,    15,    16,   530,
      18,    19,    20,   483,   531,   532,   485,   486,   487,   410,
      28,   488,    30,    31,     0,    32,    33,    34,    35,   533,
      37,   534,   535,    40,    41,    42,    43,   490,     0,    45,
     536,    47,   492,   493,    50,   494,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     495,   496,    68,     0,    69,    70,    71,   537,     0,     0,
      74,    75,    76,     0,     0,   498,    78,     0,     0,     0,
       0,    80,   499,    82,   500,   501,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   502,    97,    98,   503,   504,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
     105,   106,   107,     0,     0,     0,     0,     0,     0,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   505,
     120,   121,   506,     0,     0,     0,     0,     0,     0,     0,
     507,   508,   128,     0,     0,     0,   129,     0,   130,   509,
       0,     0,     0,     0,     0,   135,     0,   136,   137,   138,
     139,   510,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,     0,     0,   411,   151,   152,   153,   154,   155,
     156,   157,   158,   511,   538,   512,   162,   513,   514,   165,
     166,   167,   168,   169,   170,   515,   172,   516,   517,   518,
     176,   177,   519,   520,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     0,     0,   245,   521,   247,   248,   249,   250,   251,
       4,     5,     6,     7,     8,     0,     0,     0,    11,     0,
       0,     0,   408,   409,     0,    14,    15,    16,   824,    18,
      19,    20,    21,   531,   825,   485,    25,   487,   410,    28,
     488,    30,    31,     0,    32,    33,    34,    35,   826,    37,
     534,   535,    40,    41,    42,    43,   490,     0,    45,   827,
      47,   492,   493,    50,   494,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   495,
     496,    68,     0,    69,    70,    71,   828,     0,     0,    74,
      75,    76,     0,     0,   498,    78,     0,     0,     0,    79,
      80,   499,    82,   500,   501,    85,    86,   551,    88,     0,
       0,     0,     0,    90,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   502,    97,    98,   503,   504,     0,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   552,   109,     0,   110,   111,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   506,     0,   123,     0,     0,     0,     0,     0,   507,
     508,   128,     0,     0,     0,   129,     0,   130,   509,     0,
       0,     0,     0,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   411,   151,   152,   153,   154,   155,   156,
     157,   158,   511,   538,   512,   162,   513,   514,   165,   166,
     167,   168,   169,   170,   515,   172,   516,   517,   518,   176,
     177,   519,   520,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   521,   247,   248,   249,   250,   251,     7,
       8,     0,     0,     0,     0,     0,     0,     0,   408,   409,
       0,    14,    15,    16,   482,    18,    19,    20,   483,    22,
     484,   485,  1127,   487,   410,    28,   488,    30,    31,     0,
      32,    33,    34,    35,   489,    37,    38,    39,    40,    41,
      42,    43,   490,     0,    45,   491,    47,   492,   493,    50,
     494,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,   495,   496,    68,     0,    69,
      70,    71,   497,     0,     0,    74,    75,    76,     0,     0,
     498,    78,     0,     0,     0,     0,    80,   499,    82,   500,
     501,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     502,    97,    98,   503,   504,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,  1128,     0,     0,
       0,  1129,     0,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   505,   120,   121,   506,     0,     0,
       0,     0,     0,     0,     0,   507,   508,   128,     0,     0,
       0,   129,  1551,   130,   509,     0,     0,     0,  1552,     0,
     135,     0,   136,   137,   138,   139,   510,   141,   142,   143,
     144,   145,   146,     0,     0,  1130,   148,     0,     0,   411,
     151,   152,   153,   154,   155,   156,   157,   158,   511,   160,
     512,   162,   513,   514,   165,   166,   167,   168,   169,   170,
     515,   172,   516,   517,   518,   176,   177,   519,   520,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,     0,     0,     7,     8,   245,   521,
     247,  1131,  1132,  1133,  1134,   408,   409,     0,    14,    15,
      16,   530,    18,    19,    20,   483,   531,   532,   485,   486,
     487,   410,    28,   488,    30,    31,     0,    32,    33,    34,
      35,   533,    37,   534,   535,    40,    41,    42,    43,   490,
       0,    45,   536,    47,   492,   493,    50,   494,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   495,   496,    68,     0,    69,    70,    71,   537,
       0,     0,    74,    75,    76,     0,     0,   498,    78,     0,
       0,     0,     0,    80,   499,    82,   500,   501,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   502,    97,    98,
     503,   504,     0,     0,     0,     0,     0,     0,   101,   102,
     103,     0,   105,   106,   107,     0,     0,     0,     0,     0,
       0,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   505,   120,   121,   506,     0,     0,     0,     0,     0,
       0,     0,   507,   508,   128,     0,     0,     0,   129,   745,
     130,   509,     0,     0,     0,   746,     0,   135,     0,   136,
     137,   138,   139,   510,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,     0,     0,   411,   151,   152,   153,
     154,   155,   156,   157,   158,   511,   538,   512,   162,   513,
     514,   165,   166,   167,   168,   169,   170,   515,   172,   516,
     517,   518,   176,   177,   519,   520,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     0,     0,     7,     8,   245,   521,   247,   248,   249,
     250,   251,   408,   409,     0,    14,    15,    16,   530,    18,
      19,    20,   483,   531,   532,   485,   486,   487,   410,    28,
     488,    30,    31,     0,    32,    33,    34,    35,   533,    37,
     534,   535,    40,    41,    42,    43,   490,     0,    45,   536,
      47,   492,   493,    50,   494,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   495,
     496,    68,     0,    69,    70,    71,   537,     0,     0,    74,
      75,    76,     0,     0,   498,    78,     0,     0,     0,     0,
      80,   499,    82,   500,   501,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   502,    97,    98,   503,   504,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,   107,     0,     0,     0,     0,     0,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   505,   120,
     121,   506,     0,     0,     0,     0,     0,     0,     0,   507,
     508,   128,     0,     0,     0,   129,   792,   130,   509,     0,
       0,     0,   793,     0,   135,     0,   136,   137,   138,   139,
     510,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,     0,     0,   411,   151,   152,   153,   154,   155,   156,
     157,   158,   511,   538,   512,   162,   513,   514,   165,   166,
     167,   168,   169,   170,   515,   172,   516,   517,   518,   176,
     177,   519,   520,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     0,     0,
       7,     8,   245,   521,   247,   248,   249,   250,   251,   408,
     409,     0,    14,    15,    16,   482,    18,    19,    20,   483,
      22,   484,   485,  1127,   487,   410,    28,   488,    30,    31,
       0,    32,    33,    34,    35,   489,    37,    38,    39,    40,
      41,    42,    43,   490,     0,    45,   491,    47,   492,   493,
      50,   494,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   495,   496,    68,     0,
      69,    70,    71,   497,     0,     0,    74,    75,    76,     0,
       0,   498,    78,     0,     0,     0,     0,    80,   499,    82,
     500,   501,    85,    86,  1468,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   502,    97,    98,   503,   504,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,  1128,     0,
       0,     0,  1129,     0,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   505,   120,   121,   506,     0,
       0,     0,     0,     0,     0,     0,   507,   508,   128,     0,
       0,     0,   129,     0,   130,   509,     0,     0,     0,     0,
       0,   135,     0,   136,   137,   138,   139,   510,   141,   142,
     143,   144,   145,   146,     0,     0,  1130,   148,     0,     0,
     411,   151,   152,   153,   154,   155,   156,   157,   158,   511,
     160,   512,   162,   513,   514,   165,   166,   167,   168,   169,
     170,   515,   172,   516,   517,   518,   176,   177,   519,   520,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,     0,     7,     8,   245,
     521,   247,  1131,  1132,  1133,  1134,   408,   409,     0,    14,
      15,    16,   482,    18,    19,    20,   483,    22,   484,   485,
    1127,   487,   410,    28,   488,    30,    31,     0,    32,    33,
      34,    35,   489,    37,    38,    39,    40,    41,    42,    43,
     490,     0,    45,   491,    47,   492,   493,    50,   494,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   495,   496,    68,     0,    69,    70,    71,
     497,     0,     0,    74,    75,    76,     0,     0,   498,    78,
       0,     0,     0,     0,    80,   499,    82,   500,   501,    85,
      86,  1608,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   502,    97,
      98,   503,   504,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,  1128,     0,     0,     0,  1129,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   505,   120,   121,   506,     0,     0,     0,     0,
       0,     0,     0,   507,   508,   128,     0,     0,     0,   129,
       0,   130,   509,     0,     0,     0,     0,     0,   135,     0,
     136,   137,   138,   139,   510,   141,   142,   143,   144,   145,
     146,     0,     0,  1130,   148,     0,     0,   411,   151,   152,
     153,   154,   155,   156,   157,   158,   511,   160,   512,   162,
     513,   514,   165,   166,   167,   168,   169,   170,   515,   172,
     516,   517,   518,   176,   177,   519,   520,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     0,     0,     7,     8,   245,   521,   247,  1131,
    1132,  1133,  1134,   408,   409,     0,    14,    15,    16,   482,
      18,    19,    20,   483,    22,   484,   485,  1127,   487,   410,
      28,   488,    30,    31,     0,    32,    33,    34,    35,   489,
      37,    38,    39,    40,    41,    42,    43,   490,     0,    45,
     491,    47,   492,   493,    50,   494,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     495,   496,    68,     0,    69,    70,    71,   497,     0,     0,
      74,    75,    76,     0,     0,   498,    78,     0,     0,     0,
       0,    80,   499,    82,   500,   501,    85,    86,  1612,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   502,    97,    98,   503,   504,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
     105,   106,  1128,     0,     0,     0,  1129,     0,     0,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   505,
     120,   121,   506,     0,     0,     0,     0,     0,     0,     0,
     507,   508,   128,     0,     0,     0,   129,     0,   130,   509,
       0,     0,     0,     0,     0,   135,     0,   136,   137,   138,
     139,   510,   141,   142,   143,   144,   145,   146,     0,     0,
    1130,   148,     0,     0,   411,   151,   152,   153,   154,   155,
     156,   157,   158,   511,   160,   512,   162,   513,   514,   165,
     166,   167,   168,   169,   170,   515,   172,   516,   517,   518,
     176,   177,   519,   520,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     7,     8,   245,   521,   247,  1131,  1132,  1133,  1134,
     408,   409,     0,    14,    15,    16,   482,    18,    19,    20,
     483,    22,   484,   485,  1127,   487,   410,    28,   488,    30,
      31,     0,    32,    33,    34,    35,   489,    37,    38,    39,
      40,    41,    42,    43,   490,     0,    45,   491,    47,   492,
     493,    50,   494,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   495,   496,    68,
       0,    69,    70,    71,   497,     0,     0,    74,    75,    76,
       0,     0,   498,    78,     0,     0,     0,     0,    80,   499,
      82,   500,   501,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   502,    97,    98,   503,   504,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,  1128,
       0,     0,     0,  1129,     0,     0,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   505,   120,   121,   506,
       0,     0,     0,     0,     0,     0,     0,   507,   508,   128,
       0,     0,     0,   129,     0,   130,   509,     0,     0,     0,
       0,     0,   135,     0,   136,   137,   138,   139,   510,   141,
     142,   143,   144,   145,   146,     0,     0,  1130,   148,     0,
       0,   411,   151,   152,   153,   154,   155,   156,   157,   158,
     511,   160,   512,   162,   513,   514,   165,   166,   167,   168,
     169,   170,   515,   172,   516,   517,   518,   176,   177,   519,
     520,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     0,     0,     7,     8,
     245,   521,   247,  1131,  1132,  1133,  1134,   408,   409,     0,
      14,    15,    16,   482,    18,    19,    20,   483,    22,   484,
     485,  1127,   487,   410,    28,   488,    30,    31,     0,    32,
      33,    34,    35,   489,    37,    38,    39,    40,    41,    42,
      43,   490,     0,    45,   491,    47,   492,   493,    50,   494,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,   495,   496,    68,     0,    69,    70,
      71,   497,     0,     0,    74,    75,    76,     0,     0,   498,
      78,     0,     0,     0,     0,    80,   499,    82,   500,   501,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   502,
      97,    98,   503,   504,     0,     0,     0,     0,     0,     0,
     101,   102,   103,     0,   105,   106,  1128,     0,     0,     0,
    1129,     0,     0,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   505,   120,   121,   506,     0,     0,     0,
       0,     0,     0,     0,   507,   508,   128,     0,     0,     0,
     129,     0,   130,   509,     0,     0,     0,     0,     0,   135,
       0,   136,   137,   138,   139,   510,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,     0,     0,   411,   151,
     152,   153,   154,   155,   156,   157,   158,   511,   160,   512,
     162,   513,   514,   165,   166,   167,   168,   169,   170,   515,
     172,   516,   517,   518,   176,   177,   519,   520,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     0,     0,     7,     8,   245,   521,   247,
    1131,  1132,  1133,  1134,   408,   409,     0,    14,    15,    16,
     530,    18,    19,    20,   483,   531,   532,   485,   486,   487,
     410,    28,   488,    30,    31,     0,    32,    33,    34,    35,
     533,    37,   534,   535,    40,    41,    42,    43,   490,     0,
      45,   536,    47,   492,   493,    50,   494,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   495,   496,    68,     0,    69,    70,    71,   537,     0,
       0,    74,    75,    76,     0,     0,   498,    78,     0,     0,
       0,     0,    80,   499,    82,   500,   501,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   502,    97,    98,   503,
     504,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,   107,     0,     0,     0,     0,     0,     0,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     505,   120,   121,   506,     0,     0,     0,     0,     0,     0,
       0,   507,   508,   128,     0,     0,     0,   129,     0,   130,
     509,     0,     0,     0,     0,     0,   135,     0,   136,   137,
     138,   139,   510,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,     0,     0,   411,   151,   152,   153,   154,
     155,   156,   157,   158,   511,   538,   512,   162,   513,   514,
     165,   166,   167,   168,   169,   170,   515,   172,   516,   517,
     518,   176,   177,   519,   520,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       0,     0,     7,     8,   245,   521,   247,   248,   249,   250,
     251,   408,   409,     0,    14,    15,    16,     0,    18,    19,
      20,   483,     0,     0,   485,   486,     0,   410,    28,   488,
      30,    31,     0,    32,    33,    34,    35,     0,    37,     0,
       0,    40,    41,    42,    43,   490,     0,    45,     0,    47,
       0,     0,    50,   494,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,   495,   496,
      68,     0,    69,    70,    71,     0,     0,     0,    74,    75,
      76,     0,     0,   498,    78,     0,     0,     0,     0,    80,
     499,    82,   500,   501,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   502,    97,    98,   503,   504,     0,     0,
       0,     0,     0,     0,   101,   102,   103,     0,   105,   106,
       0,     0,     0,     0,     0,     0,     0,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   505,   120,   121,
     506,     0,     0,     0,     0,     0,     0,     0,   507,   508,
     128,     0,     0,     0,   129,     0,   130,   509,     0,     0,
       0,     0,     0,   135,     0,   136,   137,   138,   139,   510,
     141,   142,   143,   144,   145,   146,     0,     0,     0,   148,
       0,     0,   411,   151,   152,   153,   154,   155,   156,   157,
     158,   511,     0,   512,   162,   513,   514,   165,   166,   167,
     168,   169,   170,   515,   172,   516,   517,   518,   176,   177,
       0,   520,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,     0,     0,     0,
       0,   245,   521,   247,   248,   249,   250,   251
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,   661,    12,   179,     4,     5,     6,   338,     0,   290,
     769,   812,     4,     5,     6,   310,     4,     5,     6,   417,
     418,  1268,   781,   612,   613,   752,   419,     4,     5,     6,
     662,   663,   664,   665,   259,  1035,   795,   258,   133,   610,
     611,   612,   613,  1285,   579,   752,  1059,    73,  1019,   274,
     585,   892,  1113,   926,   850,  1347,  1348,   610,   611,   431,
      36,     4,     5,     6,   457,   458,   706,  1380,   107,    36,
     442,  1202,     1,    26,    27,    30,   281,    26,    27,   107,
    1298,    55,   142,   107,  1573,    96,   905,   906,    26,    27,
     107,   147,    29,   465,    47,   118,    29,   118,    47,    37,
      38,   147,    40,    41,     1,    29,   121,    56,   108,    47,
       1,     1,     1,     1,   224,   906,   108,   107,    56,    57,
      96,    74,     1,   942,   107,    74,   107,    94,   942,    96,
      79,   108,   131,   414,    93,   640,    74,   642,   643,   107,
     645,    79,   647,    24,    96,  1639,   224,    73,   226,   169,
     655,   656,     8,    34,   158,   246,   247,   976,   153,   112,
     200,    87,   111,   112,   113,   108,   106,    45,   153,   209,
     100,   147,   176,   111,   112,   113,   113,   996,   269,    60,
     147,   201,   177,   137,    62,   111,   110,   127,   142,   948,
    1009,   190,     9,    10,    96,   147,   100,   123,   188,   125,
     124,   224,   185,   313,    54,   996,    56,     5,    39,   190,
     234,     9,   272,    44,    45,   232,   272,   232,  1009,  1713,
     188,  1513,   160,   160,   183,   149,   272,   160,    59,   153,
      61,    62,   156,   438,  1723,   313,  1483,    37,    38,    70,
      40,    41,   216,  1002,   255,   256,   341,    94,    29,  1008,
     100,   272,   252,   177,  1055,   255,   186,    57,   213,  1572,
     252,   190,   557,   255,   545,  1265,    97,   169,  1486,   858,
     859,   310,  1113,  1114,  1001,   100,  1289,   109,   110,   253,
    1251,   219,   186,   306,   312,  1298,   103,   107,   928,  1420,
     290,  1164,   999,   190,  1001,  1356,   272,   118,   290,   190,
     190,   190,   190,   856,   857,   272,   123,   130,   125,   187,
    1129,   190,    42,   113,  1021,  1129,    46,    26,    27,   175,
     346,    51,   260,   349,   717,   123,    94,   125,   224,   110,
     226,    96,   107,   286,   258,   133,   153,   286,   107,    69,
     157,   294,   130,   124,    45,   294,    47,   628,   286,   251,
     252,   107,   254,   302,   156,   153,   294,   174,   107,   261,
     160,   186,   107,   153,   302,   186,   107,   187,   149,   271,
     217,   218,   153,   196,   767,   156,    29,   194,    79,   107,
    1672,   283,   607,   888,    94,   232,   118,   177,  1207,   610,
     611,   763,  1634,   224,   766,   212,   177,   614,    52,   107,
     250,   618,   224,   112,   169,   106,    76,   229,   196,    94,
     185,   243,   244,   263,   414,   265,   136,   313,   187,   219,
     346,    96,   414,   349,  1243,   262,   276,   277,   278,   156,
     280,   187,   282,   107,  1726,   184,   273,   147,   168,    96,
     107,   171,   187,   443,  1575,   445,   187,  1206,  1267,   217,
     218,   443,  1243,   445,   186,   736,   186,   110,   290,   187,
     260,    42,   147,  1710,   232,    46,   443,   168,   445,   469,
      51,   124,   147,  1486,   474,   129,  1267,   469,   107,   187,
     200,   211,   474,   153,   107,   107,   251,   252,    69,   254,
    1217,   313,   469,    45,   892,    47,   149,   474,   424,   156,
     443,   427,   445,   107,   182,   431,   271,   267,   434,   435,
    1099,  1100,  1101,   187,   274,  1356,   442,   195,   283,  1226,
     187,   107,   448,   921,  1365,   451,   469,   107,  1099,  1100,
    1101,   474,     5,   459,  1330,  1376,     9,  1333,   156,   465,
     466,   467,   468,    33,  1079,   545,  1677,   473,   158,   107,
     220,   221,   552,   545,   106,   481,   949,   950,   187,    49,
     552,   954,   107,   107,   187,   187,   176,   848,   107,  1388,
       9,    10,   107,     9,    10,   552,   107,   107,     9,    10,
      42,   107,   414,   187,    46,   680,   681,   168,   153,    51,
     171,   984,  1351,  1724,   594,   605,   107,  1388,   107,    94,
     526,   187,   594,   153,   184,   186,   156,    69,   107,   552,
     610,   611,   612,   613,   540,   447,   168,   594,   610,   611,
     612,   613,   107,   455,  1595,   551,   107,   107,   628,   187,
     211,   118,   464,  1633,   216,   856,   628,   862,   160,   471,
     472,   153,   187,   187,   209,   184,   107,   142,   480,   184,
     123,  1470,   125,   579,  1473,   107,   187,   187,   268,   585,
     133,   187,   107,   589,   103,   275,  1797,   103,  1799,    53,
     144,   253,   103,    96,    58,   285,   187,  1808,   187,  1470,
     153,   148,  1473,  1484,   123,   184,   125,   123,  1489,   125,
     113,   137,   123,    77,   125,   166,   142,   209,   165,   184,
     187,  1542,   176,   184,   184,    66,   168,  1367,  1435,   171,
      71,   182,    96,   545,   153,  1113,  1114,   153,   157,   193,
      53,   157,   153,   184,   186,    58,   157,     9,    73,   561,
     156,    96,   184,   156,   118,   174,   736,    94,   174,   184,
      94,   573,    87,   174,   736,     9,    28,  1336,   113,   211,
     117,  1699,  1700,    94,   118,   194,   158,   118,   194,   759,
      94,   593,   594,   194,    28,   106,   111,   759,   990,   148,
     992,   759,   106,   212,   176,   158,   212,   153,   123,   146,
     125,   212,   759,   137,  1115,   142,   165,   713,   142,   789,
     790,   156,   159,   176,  1742,  1090,   198,   789,   790,    53,
    1748,   727,   268,  1084,    58,   731,   732,    95,   142,   275,
     182,   136,   789,   790,    33,   198,   759,  1618,   106,   285,
    1042,  1622,  1044,   195,   122,   150,   193,   753,   116,   755,
      49,   122,   153,   137,    96,   156,  1655,   763,  1657,   127,
     766,   123,    96,   125,   770,   677,   789,   790,   848,   153,
     682,   113,   134,  1246,   100,   153,   848,   867,   156,   123,
     137,   125,   100,   122,  1655,   100,  1657,   113,   100,  1688,
     134,   153,   939,  1533,  1534,   113,   153,   100,   113,   100,
     262,   113,   156,   348,   951,   811,   298,   156,   353,   153,
     113,   273,   113,   153,  1526,   307,   156,  1688,   191,   192,
     153,  1720,  1703,   156,   736,   276,   277,   278,   220,   221,
     222,   282,  1088,  1672,   128,   129,  1735,  1093,  1737,   156,
     683,   122,   132,   686,   850,   154,   689,   156,   156,  1720,
     140,   141,   231,   143,   233,   231,   156,   233,   128,   129,
     118,   151,   659,   660,  1735,   155,  1737,   157,   122,   875,
    1343,   122,   162,   666,   667,   118,   668,   669,  1356,   907,
     908,  1563,  1564,   122,  1245,   122,   122,  1365,   122,   179,
     122,   803,   804,   805,   122,   807,   153,   156,  1376,   905,
     906,   907,   908,  1643,  1644,   215,   118,   156,   240,   240,
     313,   241,   202,   203,   204,   205,   206,   207,   153,     0,
     107,   346,   190,   167,   349,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    92,   942,   248,    99,    50,
     102,   101,   145,   199,   154,   156,   184,    29,    47,   118,
     956,   184,   152,   184,   245,   303,   283,  1037,   187,   283,
     118,   153,     1,   142,   118,  1037,   107,   187,  1329,   153,
     153,   156,   142,   121,   156,   981,  1716,   184,   156,  1452,
    1037,   156,   156,   156,   990,   156,   992,   153,   156,    35,
     996,    17,   213,    29,   187,   190,   190,   244,   423,   424,
     230,     3,   427,  1009,  1084,   229,   431,   170,  1098,   434,
     435,   118,  1084,    70,  1037,   168,   230,   442,   170,  1099,
    1100,  1101,    94,   448,    94,    94,   451,  1099,  1100,  1101,
     149,   107,   107,    29,   459,   160,  1042,   160,  1044,   127,
     465,   466,   467,   468,  1517,   132,   245,    94,   473,   142,
     298,   118,   132,   184,   184,   187,   481,   107,   187,    94,
      45,   187,    96,    96,  1542,   187,   187,   187,   184,   153,
     184,   156,    94,  1079,   153,   153,   153,   236,   224,   153,
     153,   230,   142,   198,   190,   156,    33,   170,   118,   132,
     142,    94,    29,   226,   285,    94,   298,   153,   118,   127,
     118,   526,  1108,  1464,   118,   147,   253,    94,   197,   132,
      96,   160,   153,   132,   118,   540,   184,   100,   147,   100,
     184,   184,   153,  1129,   190,   142,   551,   121,    35,    29,
    1210,   156,   156,    79,   118,   156,   244,   153,  1210,   107,
     107,   284,  1210,   156,   257,   156,   156,   259,   266,   156,
     156,   156,   144,  1210,    29,   156,    29,   285,    29,   286,
     305,   226,   144,   190,   589,  1245,   127,   147,   147,   147,
     118,    77,   187,  1245,   118,   187,  1256,   107,   187,   187,
     142,   100,   132,     7,  1256,    96,   184,  1210,  1256,   106,
     187,   236,   187,   156,   187,  1275,   249,   197,   186,  1256,
    1112,   190,   147,  1275,    78,   249,    29,  1275,    29,   107,
    1216,   187,   187,  1219,   187,  1295,   187,   187,  1275,   281,
     184,   187,   187,  1295,   285,   147,   147,   187,  1234,   187,
     270,   170,  1593,  1256,   126,   126,    96,  1243,  1295,    94,
     142,   232,   232,  1604,  1605,   186,  1607,   279,  1328,  1329,
     184,  1257,  1275,  1614,   186,   232,  1328,  1329,   232,   186,
     186,  1267,    94,   153,   184,    29,   184,   315,   184,    96,
     147,  1328,  1295,   187,   187,   170,    53,    94,   186,    94,
     106,   186,   197,   187,   256,   710,   196,    29,   713,   107,
    1296,   107,    94,   118,    94,   224,   118,   186,   236,   196,
     196,   224,   727,   186,   118,   264,   731,   732,   186,    93,
     196,   183,   118,   118,   198,  1321,   186,   286,   186,   186,
     118,   224,   255,   258,  1330,   716,  1167,  1333,   753,   943,
     755,   255,   418,   438,  1010,  1696,   292,   286,   763,  1677,
     252,   766,  1207,  1724,   851,   770,   772,   304,  1709,   304,
     304,  1007,   305,   305,   305,  1352,  1216,  1445,  1235,  1104,
    1350,  1347,  1257,   540,  1262,   638,  1265,   639,   691,   658,
    1289,  1748,   812,  1742,  1270,  1736,   992,   908,  1201,  1166,
    1321,  1331,  1388,  1330,  1464,  1365,   811,   446,   446,  1376,
    1542,   334,  1464,  1114,  1369,  1539,  1123,   975,  1189,  1411,
    1566,  1366,   583,    -1,    -1,    -1,    -1,    -1,  1769,    -1,
    1416,    -1,    -1,  1325,  1326,  1327,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   850,    -1,    -1,   108,    -1,
    1791,    -1,    -1,    -1,    -1,  1796,  1442,  1443,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     875,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1468,    -1,  1470,    -1,    -1,  1473,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1485,
     905,   906,   907,   908,  1490,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1593,    -1,    -1,    -1,   942,    -1,    -1,
      -1,  1593,    -1,    -1,  1604,  1605,    -1,  1607,    -1,    -1,
      -1,   956,  1604,  1605,  1614,  1607,    -1,    -1,    -1,    -1,
      -1,    -1,  1614,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   981,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   990,    -1,   992,    -1,    -1,
      -1,   996,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1009,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1608,    -1,  1610,    -1,  1612,    -1,    -1,    -1,
      -1,    -1,    -1,  1619,    -1,    -1,  1696,  1042,    -1,  1044,
      -1,    -1,    -1,    -1,  1696,    -1,    -1,    -1,    -1,  1709,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1709,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1655,
      -1,  1657,    -1,    -1,    -1,    -1,  1736,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1736,    -1,    -1,  1673,    -1,    -1,
    1676,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1688,  1108,    -1,    -1,    -1,    -1,    -1,  1769,
      -1,    -1,  1698,    -1,    -1,    -1,    -1,  1769,    -1,    -1,
      -1,    -1,    -1,    -1,  1129,    -1,    -1,    -1,    -1,    -1,
      -1,  1791,    -1,    -1,  1720,    -1,  1796,    -1,    -1,  1791,
      -1,    -1,  1728,  1635,  1796,    -1,    -1,  1733,    -1,  1735,
      -1,  1737,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1653,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1766,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1783,    -1,    -1,
      -1,  1787,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1216,    -1,    -1,  1219,    -1,    -1,  1803,    -1,    -1,
    1806,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1234,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1243,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1267,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1296,   552,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1321,   577,   578,    -1,
      -1,   581,   582,   583,   584,  1330,   586,    -1,  1333,    -1,
      -1,    -1,   592,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     600,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     620,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   628,   629,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1388,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   688,    -1,
      -1,   691,    -1,    -1,    -1,    -1,    -1,  1442,  1443,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1468,    -1,  1470,    -1,    -1,  1473,   729,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1485,    -1,    -1,    -1,    -1,  1490,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   771,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   796,    -1,    -1,    -1,
     800,   801,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   809,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1608,    -1,  1610,    -1,  1612,    -1,    -1,
      -1,    -1,    -1,    -1,  1619,    -1,    -1,   877,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1655,    -1,  1657,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1673,    -1,
      -1,  1676,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1688,   944,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1698,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1720,    -1,    -1,    -1,   979,
      -1,    -1,    -1,  1728,    -1,    -1,    -1,    -1,  1733,    -1,
    1735,    -1,  1737,    -1,    -1,    -1,    -1,    -1,   998,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1020,  1766,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1031,  1032,    -1,    -1,    -1,    -1,    -1,  1783,    -1,
      -1,    -1,  1787,    -1,    -1,    -1,  1046,    -1,    -1,  1049,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1803,    -1,
      -1,  1806,    -1,    -1,  1064,    -1,  1066,  1067,  1068,    -1,
    1070,  1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,    -1,
      -1,  1081,  1082,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1095,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1104,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1221,    -1,  1223,    -1,  1225,    -1,    -1,  1228,    -1,
      -1,    -1,    -1,  1233,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1245,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1254,    -1,    -1,    -1,    -1,    -1,
    1260,  1261,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1279,
      -1,    -1,  1282,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1350,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1429,
      -1,    -1,    -1,  1433,    -1,    -1,    -1,  1437,    -1,  1439,
      -1,  1441,    -1,    -1,    -1,    -1,    -1,  1447,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1455,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1463,  1464,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1482,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1494,  1495,  1496,  1497,    -1,    -1,
    1500,  1501,    -1,  1503,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1518,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1581,    -1,  1583,    -1,    -1,  1586,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1594,    -1,    -1,    -1,    -1,  1599,
    1600,    -1,    -1,    -1,    -1,    -1,    -1,  1607,    -1,    -1,
      -1,  1611,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1627,  1628,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1640,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1680,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1692,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1736,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1754,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1764,    -1,    -1,    -1,    -1,  1769,
      11,    12,    -1,    -1,  1774,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    29,    -1,
    1790,    -1,    33,    34,  1794,    36,    37,    38,    39,    40,
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
     311,    -1,   313,   314,   315,   316,   317,   318,   319,   320,
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
     181,   182,    -1,   184,    -1,   186,    -1,   188,   189,    -1,
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
     182,    -1,   184,    -1,   186,    -1,   188,   189,    -1,   191,
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
     181,   182,    -1,    -1,   185,   186,    -1,   188,   189,    -1,
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
     303,   304,   305,   306,   307,   308,   309,   310,   311,    -1,
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
     304,   305,   306,   307,   308,   309,    -1,   311,   312,   313,
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
     186,   187,   188,   189,    -1,   191,   192,   193,    -1,   195,
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
     151,   152,   153,   154,    -1,   156,   157,    -1,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,   174,    -1,    -1,    -1,    -1,    -1,   180,
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
     152,   153,   154,    -1,   156,   157,    -1,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,
      -1,   193,    -1,   195,    -1,   197,   198,   199,   200,   201,
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
      -1,    -1,   135,    -1,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,   149,    -1,   151,   152,
     153,   154,    -1,   156,   157,    -1,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,
     193,    -1,   195,    -1,   197,    -1,   199,    -1,   201,   202,
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
      -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,
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
      -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,   193,
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
     304,   305,   306,   307,   308,    -1,    -1,    11,    12,   313,
     314,   315,   316,   317,   318,   319,    20,    -1,    -1,    -1,
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
      -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,   193,
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
     304,   305,   306,   307,   308,    -1,    -1,    -1,    16,   313,
     314,   315,   316,   317,   318,   319,    24,    25,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
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
     148,    -1,   150,   151,   152,    -1,    -1,    -1,    -1,    -1,
      -1,   159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,   187,
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
     308,    -1,    -1,    -1,    16,   313,   314,   315,   316,   317,
     318,   319,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,   313,   314,   315,   316,   317,   318,   319,    18,    19,
      -1,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,   313,   314,   315,   316,   317,   318,   319,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    -1,    -1,   100,
     101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,    -1,
      -1,    -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,
     131,    -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,   156,   157,    -1,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,   174,    -1,    -1,    -1,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,
      -1,    -1,    -1,    -1,   195,    -1,   197,   198,   199,   200,
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
     311,    -1,   313,   314,   315,   316,   317,   318,   319,    24,
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
      -1,   156,    -1,    -1,   159,   160,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,   187,   188,   189,    -1,    -1,    -1,   193,    -1,
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
     148,    -1,   150,   151,   152,    -1,    -1,    -1,    -1,    -1,
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
     114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,
      -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   147,   148,    -1,   150,   151,   152,    -1,
      -1,    -1,   156,    -1,    -1,   159,   160,    -1,    -1,    -1,
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
     113,   114,   115,   116,   117,    -1,    -1,    -1,    -1,    -1,
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
      -1,   150,   151,   152,    -1,    -1,    -1,    -1,    -1,    -1,
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
     319,    33,    34,    -1,    36,    37,    38,    -1,    40,    41,
      42,    43,    -1,    -1,    46,    47,    -1,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    -1,    60,    -1,
      -1,    63,    64,    65,    66,    67,    -1,    69,    -1,    71,
      -1,    -1,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    -1,    -1,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,    -1,   150,   151,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,
      -1,    -1,    -1,   195,    -1,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,    -1,    -1,    -1,   211,
      -1,    -1,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,    -1,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
      -1,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,    -1,    -1,    -1,
      -1,   313,   314,   315,   316,   317,   318,   319
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
     375,   376,   160,   153,   156,   153,   156,   153,   156,    66,
      71,   118,   414,   156,   377,   156,    24,    34,    60,   118,
     272,   426,   428,   429,   153,   156,   156,   156,   118,   153,
     156,   156,   156,    76,   153,   220,   221,   122,   122,   122,
     153,   156,    39,    43,    45,    46,    47,    48,    51,    59,
      67,    70,    72,    73,    75,    90,    91,    97,   105,   112,
     114,   115,   135,   138,   139,   169,   172,   180,   181,   189,
     201,   223,   225,   227,   228,   235,   237,   238,   239,   242,
     243,   314,   498,   649,   650,   122,   118,   397,   122,   122,
      39,    44,    45,    59,    61,    62,    70,    97,   224,   649,
     118,   122,   122,   184,   388,   390,   410,   637,    48,    72,
      73,   118,   153,   185,   243,   409,   411,   421,   187,   409,
     649,   153,   122,    16,   648,   649,    18,    19,   649,   122,
     122,   122,   490,   153,    30,   213,   215,   224,   226,   313,
     156,   224,   226,   313,   224,   313,   224,   229,   313,   118,
     240,   240,   241,   156,   153,   392,   310,   409,   312,   409,
     313,   334,     0,   336,   337,    33,    49,   339,   356,     1,
     190,   333,   190,   333,   112,   371,   391,   409,   107,   190,
     107,   190,    42,    46,    51,    69,   168,   171,   186,   211,
     404,   413,   418,   419,   420,   434,   435,   439,   167,    92,
     132,   140,   141,   143,   151,   155,   157,   162,   179,   202,
     203,   204,   205,   206,   207,   482,   483,   248,    99,   158,
     176,   198,   117,   146,   159,   193,   200,   209,   136,   150,
      50,   199,   101,   102,   158,   176,   481,   153,   487,   490,
     191,   192,   154,   502,   503,   498,   502,   498,   156,   502,
     145,   156,   184,   184,   184,   372,   505,   372,    29,   647,
     182,   195,   182,   195,   166,   182,   650,   649,   169,   201,
      47,   649,   152,   118,    45,    47,    79,   106,   168,   648,
     220,   221,   222,   245,   606,   649,   649,   303,   137,   142,
     112,   286,   294,   374,   648,   389,   390,   187,   389,    45,
      62,   187,   555,   556,   409,   187,   193,   649,   283,   283,
     423,   424,   649,   118,   430,   118,   187,   378,   379,   153,
     394,   409,     1,   160,   647,   113,   160,   352,   647,   649,
     118,   142,   107,   409,    29,   187,   648,   649,   649,   447,
     448,   649,   389,   187,   409,   409,   557,   649,   389,   153,
     153,   409,   187,   193,   649,   649,   142,   447,   184,   184,
     121,   107,   184,   156,   156,   156,   649,   153,   185,   186,
     187,    35,   518,   519,   520,   409,     8,   175,    17,   409,
     213,    29,   410,   410,    39,    45,    59,    70,    97,   504,
     649,   187,   410,   410,   410,   637,   410,   504,   410,   230,
     229,   573,   574,   649,   190,   190,   410,   409,   390,   409,
     244,   407,   408,   310,   312,   410,   190,   333,   190,   333,
       3,   340,   356,   386,   340,   356,   386,    33,   357,   386,
     357,   386,   397,   397,   410,   118,   168,   170,   170,   391,
     410,   410,   464,   465,   467,   467,   467,   467,   466,   467,
     467,   467,    70,   468,   472,   472,   471,   473,   473,   473,
     473,   474,   474,   475,   475,   230,    94,    94,    94,   184,
     409,   490,   490,   409,   503,   187,   410,   513,   149,   187,
     513,   107,   187,   187,   107,   107,   377,    29,   650,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,   359,
     360,   361,    94,   137,   142,   365,   366,   367,   649,   160,
     160,   359,   647,   127,   132,    54,    56,   100,   250,   263,
     265,   276,   277,   278,   280,   282,   607,   608,   609,   610,
     611,   612,   619,   625,   626,   245,    94,   298,   649,   142,
     410,   118,   649,   649,   132,   184,   184,   187,   187,   184,
     107,   187,   107,   187,   107,    36,    94,    96,   147,   425,
     426,   541,   649,    55,   216,   253,   415,   416,   649,    94,
     107,   187,   388,   187,   648,    96,    45,   648,   647,    96,
     142,   541,   649,   410,   429,   184,   187,   187,   187,   187,
     107,   188,   147,   541,   184,   187,   187,   153,   184,   389,
     389,   184,   107,   187,   107,   187,   142,   541,   410,   188,
     410,   410,   409,   409,   409,   649,   519,   520,   130,   196,
     184,   184,   131,   190,   156,    94,   217,   218,   232,    94,
     217,   218,   232,   232,   232,    94,   156,   236,   224,   230,
     107,   234,   142,   190,   187,    48,    72,    73,   243,   411,
     421,   184,   499,   579,   408,   198,   356,    33,    33,   190,
     333,   190,   113,   649,   170,   410,   440,   441,   118,   436,
     437,   467,   153,   156,   258,   486,   505,   580,   583,   584,
     585,   586,   587,   591,   593,   595,   596,    47,   152,   156,
     210,   316,   317,   318,   319,   542,   544,   546,   547,   563,
     564,   565,   566,   643,   644,   645,   646,   649,   542,   540,
     546,   540,   184,   185,   107,   187,   187,   505,   148,   165,
     148,   165,   137,   394,   377,   360,   132,   544,   367,   410,
     541,   647,   647,   128,   129,   647,   276,   277,   278,   282,
     649,   262,   273,   262,   273,    29,   285,    96,   113,   156,
     613,   616,   607,    39,    44,    59,    61,    70,    97,   224,
     381,   547,   226,   298,   307,   410,   649,    94,   298,   647,
     153,   557,   558,   649,   557,   558,   118,   127,   542,   118,
     410,   147,   426,   147,    36,   147,   425,   426,   147,   541,
     253,    53,    58,    77,   118,   425,   431,   432,   433,   416,
     541,   542,   379,    94,   184,   197,   132,   351,   647,   160,
     132,    96,   351,   410,   142,   426,   153,   118,   410,   410,
     147,   100,   450,   451,   452,   454,   455,   100,   458,   459,
     460,   461,   389,   184,   184,   153,   557,   557,   410,   142,
     190,   410,   121,   187,   187,   187,    35,   520,   130,   196,
       9,    10,   103,   123,   125,   153,   194,   515,   517,   528,
     529,   532,    29,   410,   231,   233,   410,   410,   410,   231,
     233,   410,   410,   410,   410,   410,   410,   410,   410,   410,
     504,   118,   410,   410,   391,   156,   156,   156,   153,   186,
     244,   576,   577,   209,   392,   410,   190,   113,   386,   386,
     386,   440,    95,   106,   116,   127,   442,   443,   444,   445,
     107,   649,   107,   409,   580,   587,   153,   284,   469,   632,
      96,   169,   251,   252,   254,   261,   271,   283,   581,   582,
     601,   602,   603,   604,   627,   630,   257,   259,   588,   606,
     266,   592,   628,   246,   247,   269,   597,   598,   156,   156,
     544,   156,   156,   156,   156,   156,   144,   176,   193,   543,
     144,   410,   137,   394,   559,   366,   285,    29,    96,   113,
     156,   620,    29,   613,   543,   488,   286,   305,   541,   381,
     226,   190,   388,   187,   187,   144,   187,   187,   424,   147,
     425,   649,   410,   147,   410,   127,   410,   147,   426,   147,
     410,   147,   118,   118,   410,   649,   433,    77,   542,   391,
     410,   647,   107,   351,   410,   142,   388,   448,   410,   410,
     113,   451,   452,   100,   186,   113,   452,   455,   118,   542,
     100,   113,   459,   100,   113,   461,   184,   388,   187,   187,
     410,   410,   197,   458,   132,   194,   517,     7,   389,   649,
     194,   528,   190,   187,   232,   232,   232,   232,    96,   187,
     236,   156,   574,   186,   409,   409,   409,   579,   577,   499,
     647,   128,   129,   444,   445,   445,   441,   106,   142,   438,
     541,   437,   184,   187,   580,   594,   249,   216,   253,   267,
     274,   631,    96,   255,   256,   629,   249,   584,   631,   471,
     601,   585,   147,   281,   589,   590,   629,   285,   600,    78,
     599,   187,   193,   542,   545,   187,   187,   187,   187,   187,
     187,   187,    29,   136,   200,   622,   623,   624,    29,   621,
     622,   270,   617,   107,   614,   170,   649,   256,   488,   184,
     410,   147,   410,   147,   425,   410,   147,   410,   410,   649,
     649,   432,   410,   126,   126,    96,   647,   410,   184,   186,
     186,   410,   391,   410,   186,   186,   649,   186,   118,   542,
     118,   186,   118,   542,   186,   184,   113,   520,   649,   194,
     184,   520,   649,   410,   410,   410,   410,   315,    94,   410,
     410,   410,   187,   187,   187,   153,   578,   445,   647,   410,
     142,   184,   473,    52,   129,   471,   471,   268,   275,   285,
     605,   605,   586,   153,   279,    94,   187,   107,   187,   620,
     620,   624,   107,   187,    29,   618,   629,   615,   616,   187,
     383,   384,   488,   118,   224,   306,   286,   170,   410,   410,
     147,   410,    53,   391,   410,   351,   410,   391,    94,   391,
     410,   649,   186,   649,   410,   649,   186,   391,   118,    93,
     183,   521,   520,   649,   196,   520,   410,   410,   187,   197,
     458,   409,   438,   410,   471,   471,   198,   409,   542,   542,
      94,    29,   264,   107,   107,   445,   541,   649,   118,   224,
     649,   383,   410,   118,   542,    94,   186,    94,   649,     5,
     133,   524,   525,   527,   529,    28,   134,   522,   523,   526,
     529,   196,   520,   196,   236,   113,   184,   438,   471,   184,
     542,   616,   384,   445,   304,   649,   118,   224,   649,   186,
     542,   391,   410,   542,   186,    93,   133,   527,   183,   134,
     526,   196,   410,   118,   410,   304,   649,   118,   391,   410,
     186,   186,   649,   292,   304,   649,   186,   305,   410,   305,
     488,   488,   198,   286,   649,   224,   118,   649,   305,   488
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
     380,   380,   381,   381,   382,   382,   383,   383,   384,   384,
     384,   384,   385,   385,   385,   385,   386,   387,   387,   387,
     388,   388,   388,   389,   389,   390,   390,   391,   391,   391,
     391,   391,   391,   391,   391,   391,   391,   391,   391,   392,
     392,   393,   394,   395,   396,   396,   396,   397,   397,   397,
     397,   398,   399,   400,   401,   402,   402,   403,   404,   405,
     406,   407,   407,   408,   409,   409,   410,   410,   410,   410,
     410,   410,   411,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   412,   413,   414,   414,   415,   415,
     415,   416,   416,   417,   417,   418,   419,   419,   419,   420,
     420,   420,   420,   420,   421,   421,   422,   423,   423,   424,
     424,   424,   424,   424,   424,   424,   424,   424,   424,   424,
     424,   425,   426,   427,   428,   428,   429,   429,   429,   429,
     430,   430,   431,   431,   431,   432,   432,   432,   433,   433,
     433,   434,   435,   436,   436,   437,   437,   437,   437,   437,
     437,   438,   439,   439,   440,   440,   441,   441,   442,   442,
     442,   442,   442,   442,   442,   443,   443,   444,   444,   445,
     446,   446,   447,   447,   448,   448,   449,   450,   450,   451,
     452,   452,   453,   454,   454,   455,   456,   456,   457,   457,
     458,   458,   459,   459,   460,   460,   461,   461,   462,   463,
     463,   464,   464,   465,   465,   465,   465,   465,   466,   465,
     465,   465,   465,   467,   467,   468,   468,   469,   469,   470,
     470,   471,   471,   471,   472,   472,   472,   472,   472,   473,
     473,   473,   474,   474,   474,   475,   475,   476,   476,   477,
     477,   478,   478,   479,   479,   480,   480,   480,   480,   481,
     481,   481,   482,   482,   482,   482,   482,   482,   483,   483,
     483,   484,   484,   484,   484,   485,   485,   486,   486,   487,
     487,   487,   488,   488,   488,   488,   489,   490,   490,   490,
     491,   491,   492,   492,   492,   492,   493,   493,   494,   494,
     494,   494,   494,   494,   494,   495,   495,   496,   496,   497,
     497,   497,   497,   497,   498,   498,   499,   499,   500,   500,
     500,   500,   501,   501,   501,   501,   502,   502,   503,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   504,   505,   505,   506,   506,   506,   507,   508,
     508,   509,   510,   511,   512,   512,   513,   513,   514,   514,
     515,   515,   515,   516,   516,   516,   516,   516,   516,   517,
     517,   518,   518,   519,   520,   520,   521,   521,   522,   522,
     523,   523,   523,   523,   524,   524,   525,   525,   525,   525,
     526,   526,   527,   527,   528,   528,   528,   528,   529,   529,
     529,   529,   530,   530,   531,   531,   532,   533,   533,   533,
     533,   533,   533,   534,   535,   535,   536,   536,   537,   538,
     539,   539,   540,   540,   541,   542,   542,   542,   543,   543,
     543,   544,   544,   544,   544,   544,   544,   544,   545,   545,
     546,   547,   547,   547,   547,   547,   547,   547,   547,   547,
     548,   549,   549,   549,   550,   551,   552,   552,   552,   553,
     553,   553,   553,   553,   554,   555,   555,   555,   555,   555,
     555,   555,   556,   557,   558,   559,   560,   560,   561,   562,
     563,   563,   564,   565,   565,   566,   567,   567,   567,   568,
     568,   568,   568,   568,   568,   568,   568,   568,   568,   569,
     569,   570,   570,   571,   572,   573,   573,   574,   575,   576,
     576,   577,   578,   579,   579,   580,   581,   581,   582,   582,
     583,   583,   584,   584,   585,   585,   586,   586,   587,   588,
     588,   589,   589,   590,   591,   591,   591,   592,   592,   593,
     594,   594,   595,   596,   596,   597,   597,   598,   598,   598,
     599,   599,   600,   600,   601,   601,   601,   601,   601,   602,
     603,   604,   605,   605,   605,   606,   606,   607,   607,   607,
     607,   607,   607,   607,   607,   608,   608,   608,   608,   609,
     609,   610,   611,   611,   612,   612,   612,   613,   613,   614,
     614,   615,   615,   616,   617,   617,   618,   618,   619,   619,
     619,   620,   620,   621,   621,   622,   622,   623,   623,   624,
     624,   625,   626,   626,   627,   627,   627,   628,   629,   629,
     629,   629,   630,   630,   631,   631,   632,   633,   633,   634,
     634,   635,   635,   636,   637,   637,   638,   638,   639,   640,
     641,   642,   643,   643,   643,   644,   645,   646,   647,   648,
     648,   649,   649,   649,   649,   649,   649,   649,   649,   649,
     649,   649,   649,   649,   649,   649,   649,   650,   650,   650,
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
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   651
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
       4,     6,     1,     2,     8,     9,     1,     3,     1,     2,
       2,     3,    11,    14,    13,    22,     1,     1,     1,     0,
       1,     1,     0,     1,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     3,     3,     2,     3,     2,     3,     2,     3,     4,
       5,     5,     2,     4,     5,     3,     3,     2,     2,     8,
       3,     1,     2,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     1,     1,
       2,     4,     3,     5,     4,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     1,     4,     3,
       5,     4,     6,     4,     6,     5,     7,     4,     5,     5,
       6,     3,     3,     2,     1,     3,     4,     5,     3,     6,
       4,     5,     1,     2,     3,     1,     2,     1,     6,     3,
       3,     2,     3,     1,     3,     2,     4,     5,     6,     5,
       3,     2,     3,     4,     1,     3,     1,     2,     1,     1,
       1,     2,     2,     2,     3,     1,     1,     2,     2,     2,
       5,     5,     1,     4,     3,     4,     8,     1,     2,     3,
       2,     3,     8,     1,     2,     3,     8,    10,     8,    10,
       1,     2,     4,     7,     1,     2,     4,     7,     8,     1,
       3,     1,     3,     1,     3,     3,     3,     3,     0,     4,
       3,     3,     3,     1,     5,     1,     3,     0,     1,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     4,     1,     4,     1,
       4,     1,     4,     1,     2,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     5,     5,     6,     3,     4,     1,     2,     3,
       2,     2,     1,     2,     2,     1,     1,     1,     3,     3,
       1,     1,     1,     2,     1,     2,     2,     1,     2,     2,
       2,     2,     2,     2,     2,     1,     2,     2,     1,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     4,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       3,     1,     4,     4,     3,     4,     1,     3,     1,     1,
       1,     1,     1,     4,     5,     8,     9,     9,    10,     1,
       2,     1,     2,     6,     0,     1,     3,     3,     0,     1,
       1,     1,     2,     2,     0,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     2,     3,     3,     2,     1,     1,     1,
       1,     1,     1,     4,     3,     7,     3,     7,     4,     4,
       3,     7,     1,     2,     2,     1,     2,     3,     1,     1,
       1,     1,     1,     3,     3,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     4,     4,     3,     3,     3,     4,     4,     3,
       4,     6,     4,     6,     4,     3,     4,     6,     6,     4,
       6,     6,     4,     1,     2,     1,     1,     1,     3,     3,
       1,     1,     4,     5,     6,     3,     3,     3,     3,     5,
       7,     7,     5,     5,     5,     7,     7,     5,     5,     3,
       3,     5,     7,     5,     7,     1,     4,     3,     5,     1,
       2,     3,     3,     1,     3,     2,     0,     1,     1,     2,
       1,     3,     1,     3,     1,     4,     1,     2,     3,     0,
       1,     0,     1,     4,     2,     3,     1,     0,     1,     4,
       0,     1,     2,     1,     3,     0,     1,     2,     2,     1,
       0,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     1,     1,     1,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     1,     2,
       2,     3,     1,     2,     2,     5,     2,     1,     1,     0,
       2,     1,     3,     4,     0,     2,     0,     2,     4,     4,
       3,     2,     3,     1,     3,     0,     1,     1,     2,     2,
       2,     2,     1,     2,     2,     2,     2,     3,     2,     3,
       3,     4,     2,     2,     1,     1,     3,     2,     3,     2,
       3,     2,     3,     3,     3,     5,     5,     8,     5,     6,
       8,    10,     1,     1,     1,     3,     3,     3,     1,     1,
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
       1,     1,     1,     1
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
      -1,    33,   294,   649,   298,   226,   488,   170,   383,    -1,
      33,   370,   294,   649,   298,   226,   488,   170,   383,    -1,
     384,    -1,   383,   107,   384,    -1,   488,    -1,   488,   541,
      -1,   488,   445,    -1,   488,   541,   445,    -1,    33,   302,
     303,   649,   298,   286,   649,   118,   649,   304,   410,    -1,
      33,   302,   303,   649,   298,   286,   649,   224,   118,   649,
     304,   292,   305,   488,    -1,    33,   302,   303,   649,   298,
     286,   649,   306,   224,   118,   649,   304,   410,    -1,    33,
     302,   303,   649,   307,   305,   256,   286,   649,   224,   118,
     649,   305,   488,   198,   286,   649,   224,   118,   649,   305,
     488,    -1,   387,    -1,   389,    -1,   390,    -1,    -1,   389,
      -1,   390,    -1,    -1,   409,    -1,   390,   409,    -1,   391,
      -1,   390,   391,    -1,   392,    -1,   395,    -1,   398,    -1,
     399,    -1,   400,    -1,   401,    -1,   402,    -1,   403,    -1,
     405,    -1,   457,    -1,   453,    -1,   406,    -1,   153,   390,
     184,    -1,   153,   184,    -1,   153,   388,   184,    -1,   153,
     388,   184,    -1,   396,   190,    -1,   396,   107,   397,    -1,
     112,   397,    -1,   370,   112,   397,    -1,   118,   649,    -1,
     118,   649,   541,    -1,   118,   649,   142,   410,    -1,   118,
     649,   541,   142,   410,    -1,   118,   649,   142,   410,   190,
      -1,   411,   190,    -1,   239,   241,   410,   190,    -1,   242,
     156,   409,   187,   391,    -1,   237,   240,   190,    -1,   238,
     240,   190,    -1,   421,   404,    -1,   186,   391,    -1,    48,
     156,   409,   187,   197,   391,   126,   391,    -1,   243,   392,
     407,    -1,   408,    -1,   407,   408,    -1,   244,   579,   392,
      -1,   410,    -1,   409,   107,   410,    -1,   412,    -1,   449,
      -1,   456,    -1,   462,    -1,   575,    -1,   411,    -1,   463,
      -1,   446,    -1,   568,    -1,   569,    -1,   571,    -1,   570,
      -1,   572,    -1,   640,    -1,   638,    -1,   641,    -1,   642,
      -1,   639,    -1,   421,   413,    -1,   186,   410,    -1,    66,
     283,    -1,    71,   283,    -1,   216,    -1,   253,    -1,    55,
     253,    -1,   415,   431,    77,   410,    -1,   415,    77,   410,
      -1,    46,   414,   430,   416,   416,    -1,    46,   414,   430,
     416,    -1,    42,   118,   649,    -1,   422,    -1,   427,    -1,
     417,    -1,   419,    -1,   434,    -1,   439,    -1,   435,    -1,
     418,    -1,   419,    -1,   421,   420,    -1,    46,   118,   423,
      -1,   424,    -1,   423,   107,   118,   424,    -1,   649,   147,
     410,    -1,   649,    36,   127,   147,   410,    -1,   649,   541,
     147,   410,    -1,   649,   541,    36,   127,   147,   410,    -1,
     649,   425,   147,   410,    -1,   649,    36,   127,   425,   147,
     410,    -1,   649,   541,   425,   147,   410,    -1,   649,   541,
      36,   127,   425,   147,   410,    -1,   649,   426,   147,   410,
      -1,   649,   541,   426,   147,   410,    -1,   649,   425,   426,
     147,   410,    -1,   649,   541,   425,   426,   147,   410,    -1,
      96,   118,   649,    -1,   272,   118,   649,    -1,    51,   428,
      -1,   429,    -1,   428,   107,   429,    -1,   118,   649,   142,
     410,    -1,   118,   649,   541,   142,   410,    -1,   426,   142,
     410,    -1,   118,   649,   541,   426,   142,   410,    -1,   118,
     649,   147,   410,    -1,   118,   649,   541,   147,   410,    -1,
     432,    -1,   118,   649,    -1,   118,   649,   432,    -1,   425,
      -1,   425,   433,    -1,   433,    -1,    58,   118,   649,    53,
     118,   649,    -1,    53,   118,   649,    -1,    58,   118,   649,
      -1,   211,   410,    -1,   171,   170,   436,    -1,   437,    -1,
     436,   107,   437,    -1,   118,   649,    -1,   118,   649,   142,
     410,    -1,   118,   649,   541,   142,   410,    -1,   118,   649,
     541,   142,   410,   438,    -1,   118,   649,   142,   410,   438,
      -1,   118,   649,   438,    -1,   106,   647,    -1,   168,   170,
     440,    -1,    69,   168,   170,   440,    -1,   441,    -1,   440,
     107,   441,    -1,   410,    -1,   410,   442,    -1,   443,    -1,
     444,    -1,   445,    -1,   443,   444,    -1,   443,   445,    -1,
     444,   445,    -1,   443,   444,   445,    -1,    95,    -1,   116,
      -1,   127,   128,    -1,   127,   129,    -1,   106,   647,    -1,
      67,   118,   447,   188,   410,    -1,   135,   118,   447,   188,
     410,    -1,   448,    -1,   447,   107,   118,   448,    -1,   649,
     147,   410,    -1,   649,   541,   147,   410,    -1,    72,   156,
     409,   187,   450,   113,   186,   410,    -1,   451,    -1,   450,
     451,    -1,   452,   186,   410,    -1,   100,   410,    -1,   452,
     100,   410,    -1,    72,   156,   409,   187,   454,   113,   186,
     391,    -1,   455,    -1,   454,   455,    -1,   452,   186,   391,
      -1,    73,   156,   409,   187,   458,   113,   186,   410,    -1,
      73,   156,   409,   187,   458,   113,   118,   649,   186,   410,
      -1,    73,   156,   409,   187,   460,   113,   186,   391,    -1,
      73,   156,   409,   187,   458,   113,   118,   649,   186,   391,
      -1,   459,    -1,   458,   459,    -1,   100,   542,   186,   410,
      -1,   100,   118,   649,    94,   542,   186,   410,    -1,   461,
      -1,   460,   461,    -1,   100,   542,   186,   391,    -1,   100,
     118,   649,    94,   542,   186,   391,    -1,    48,   156,   409,
     187,   197,   410,   126,   410,    -1,   464,    -1,   463,   167,
     464,    -1,   465,    -1,   464,    92,   465,    -1,   467,    -1,
     467,   482,   467,    -1,   467,   483,   467,    -1,   467,   132,
     467,    -1,   467,   162,   467,    -1,    -1,   467,   157,   466,
     467,    -1,   467,   155,   467,    -1,   467,   143,   467,    -1,
     467,   141,   467,    -1,   468,    -1,   468,   248,    70,   580,
     469,    -1,   470,    -1,   470,    99,   468,    -1,    -1,   632,
      -1,   471,    -1,   471,   198,   471,    -1,   472,    -1,   471,
     176,   472,    -1,   471,   158,   472,    -1,   473,    -1,   472,
     193,   473,    -1,   472,   117,   473,    -1,   472,   146,   473,
      -1,   472,   159,   473,    -1,   474,    -1,   473,   200,   474,
      -1,   473,   209,   474,    -1,   475,    -1,   474,   150,   475,
      -1,   474,   136,   475,    -1,   476,    -1,   476,    50,   230,
     542,    -1,   477,    -1,   477,   199,    94,   542,    -1,   478,
      -1,   478,   101,    94,   540,    -1,   479,    -1,   479,   102,
      94,   540,    -1,   481,    -1,   480,   481,    -1,   176,    -1,
     158,    -1,   480,   176,    -1,   480,   158,    -1,   484,    -1,
     488,    -1,   485,    -1,   202,    -1,   207,    -1,   206,    -1,
     205,    -1,   204,    -1,   203,    -1,   151,    -1,   179,    -1,
     140,    -1,    75,   153,   389,   184,    -1,    75,   221,   153,
     389,   184,    -1,    75,   220,   153,   389,   184,    -1,    75,
      76,   557,   153,   389,   184,    -1,   486,   153,   184,    -1,
     486,   153,   409,   184,    -1,   487,    -1,   486,   487,    -1,
     177,   649,    17,    -1,   177,    18,    -1,   177,    19,    -1,
     489,    -1,   489,   490,    -1,   192,   490,    -1,   490,    -1,
     191,    -1,   491,    -1,   491,   191,   490,    -1,   491,   192,
     490,    -1,   492,    -1,   501,    -1,   493,    -1,   493,   502,
      -1,   496,    -1,   496,   502,    -1,   494,   498,    -1,   495,
      -1,   105,   122,    -1,   114,   122,    -1,    97,   122,    -1,
     189,   122,    -1,   115,   122,    -1,   139,   122,    -1,   138,
     122,    -1,   498,    -1,    98,   498,    -1,   497,   498,    -1,
     120,    -1,   172,   122,    -1,    90,   122,    -1,   181,   122,
      -1,   180,   122,    -1,    91,   122,    -1,   547,    -1,   499,
      -1,   649,    -1,   500,    -1,   193,    -1,    11,    -1,    12,
      -1,    20,    -1,   504,    -1,   501,   502,    -1,   501,   156,
     187,    -1,   501,   156,   513,   187,    -1,   503,    -1,   502,
     503,    -1,   154,   409,   185,    -1,   505,    -1,   507,    -1,
     508,    -1,   509,    -1,   512,    -1,   514,    -1,   510,    -1,
     511,    -1,   560,    -1,   393,    -1,   636,    -1,   633,    -1,
     634,    -1,   635,    -1,   506,    -1,   559,    -1,   110,    -1,
     149,    -1,   124,    -1,   118,   649,    -1,   156,   187,    -1,
     156,   409,   187,    -1,   119,    -1,   169,   153,   409,   184,
      -1,   201,   153,   409,   184,    -1,   650,   156,   187,    -1,
     650,   156,   513,   187,    -1,   410,    -1,   513,   107,   410,
      -1,   515,    -1,   533,    -1,   516,    -1,   530,    -1,   531,
      -1,   157,   649,   520,   130,    -1,   157,   649,   518,   520,
     130,    -1,   157,   649,   520,   196,   194,   649,   520,   196,
      -1,   157,   649,   520,   196,   517,   194,   649,   520,   196,
      -1,   157,   649,   518,   520,   196,   194,   649,   520,   196,
      -1,   157,   649,   518,   520,   196,   517,   194,   649,   520,
     196,    -1,   528,    -1,   517,   528,    -1,   519,    -1,   518,
     519,    -1,    35,   649,   520,   132,   520,   521,    -1,    -1,
      35,    -1,   183,   522,   183,    -1,    93,   524,    93,    -1,
      -1,   523,    -1,   134,    -1,   526,    -1,   523,   134,    -1,
     523,   526,    -1,    -1,   525,    -1,   133,    -1,   527,    -1,
     525,   133,    -1,   525,   527,    -1,    28,    -1,   529,    -1,
       5,    -1,   529,    -1,   515,    -1,    10,    -1,   532,    -1,
     529,    -1,     9,    -1,   123,    -1,   125,    -1,   153,   389,
     184,    -1,   212,    30,   213,    -1,   212,   213,    -1,   174,
     648,   175,    -1,   174,   648,     8,    -1,   103,     7,    -1,
     534,    -1,   535,    -1,   536,    -1,   537,    -1,   538,    -1,
     539,    -1,    43,   153,   389,   184,    -1,    21,   388,   184,
      -1,    45,   153,   409,   184,   153,   388,   184,    -1,    22,
     388,   184,    -1,    97,   153,   409,   184,   153,   388,   184,
      -1,    70,   153,   389,   184,    -1,    39,   153,   389,   184,
      -1,    23,   388,   184,    -1,    59,   153,   409,   184,   153,
     388,   184,    -1,   546,    -1,   546,   144,    -1,    94,   542,
      -1,   544,    -1,   544,   543,    -1,   210,   156,   187,    -1,
     144,    -1,   193,    -1,   176,    -1,   546,    -1,   547,    -1,
     152,   156,   187,    -1,   319,   156,   187,    -1,   563,    -1,
     566,    -1,   643,    -1,   542,    -1,   545,   107,   542,    -1,
     649,    -1,   549,    -1,   555,    -1,   553,    -1,   556,    -1,
     554,    -1,   552,    -1,   551,    -1,   550,    -1,   548,    -1,
     224,   156,   187,    -1,    44,   156,   187,    -1,    44,   156,
     555,   187,    -1,    44,   156,   556,   187,    -1,    70,   156,
     187,    -1,    39,   156,   187,    -1,    59,   156,   187,    -1,
      59,   156,   648,   187,    -1,    59,   156,    29,   187,    -1,
      97,   156,   187,    -1,    97,   156,   649,   187,    -1,    97,
     156,   649,   107,   557,   187,    -1,    97,   156,   193,   187,
      -1,    97,   156,   193,   107,   557,   187,    -1,    61,   156,
     649,   187,    -1,    45,   156,   187,    -1,    45,   156,   649,
     187,    -1,    45,   156,   649,   107,   557,   187,    -1,    45,
     156,   649,   107,   558,   187,    -1,    45,   156,   193,   187,
      -1,    45,   156,   193,   107,   557,   187,    -1,    45,   156,
     193,   107,   558,   187,    -1,    62,   156,   649,   187,    -1,
     649,    -1,   649,   144,    -1,    29,    -1,   561,    -1,   562,
      -1,   649,   145,   149,    -1,    47,   377,   394,    -1,   564,
      -1,   565,    -1,    47,   156,   193,   187,    -1,    47,   156,
     187,    94,   542,    -1,    47,   156,   545,   187,    94,   542,
      -1,   156,   544,   187,    -1,    33,   219,   220,    -1,    33,
     219,   221,    -1,    33,   219,   222,    -1,   225,   224,   410,
     232,   410,    -1,   225,   224,   410,    94,   231,   232,   410,
      -1,   225,   224,   410,    94,   233,   232,   410,    -1,   225,
     224,   410,   217,   410,    -1,   225,   224,   410,   218,   410,
      -1,   225,   226,   410,   232,   410,    -1,   225,   226,   410,
      94,   231,   232,   410,    -1,   225,   226,   410,    94,   233,
     232,   410,    -1,   225,   226,   410,   217,   410,    -1,   225,
     226,   410,   218,   410,    -1,   223,   224,   410,    -1,   223,
     226,   410,    -1,   228,   224,   410,   236,   410,    -1,   228,
     229,   230,   224,   410,   236,   410,    -1,   227,   224,   410,
      94,   410,    -1,   235,   118,   573,   234,   410,   186,   410,
      -1,   574,    -1,   573,   107,   118,   574,    -1,   649,   142,
     410,    -1,   243,   153,   409,   184,   576,    -1,   577,    -1,
     576,   577,    -1,   244,   579,   578,    -1,   153,   409,   184,
      -1,   499,    -1,   579,   209,   499,    -1,   583,   581,    -1,
      -1,   582,    -1,   601,    -1,   582,   601,    -1,   584,    -1,
     583,   261,   584,    -1,   585,    -1,   584,   257,   585,    -1,
     586,    -1,   585,   259,   147,   586,    -1,   587,    -1,   258,
     587,    -1,   591,   588,   589,    -1,    -1,   606,    -1,    -1,
     590,    -1,   281,   153,   409,   184,    -1,   595,   592,    -1,
     156,   580,   187,    -1,   593,    -1,    -1,   628,    -1,   486,
     153,   594,   184,    -1,    -1,   580,    -1,   596,   597,    -1,
     505,    -1,   153,   409,   184,    -1,    -1,   598,    -1,   247,
     599,    -1,   246,   600,    -1,   269,    -1,    -1,    78,    -1,
      -1,   285,    -1,   602,    -1,   603,    -1,   604,    -1,   630,
      -1,   627,    -1,   169,    -1,   283,   471,   605,    -1,   252,
     629,   605,    -1,   285,    -1,   275,    -1,   268,    -1,   245,
     607,    -1,   606,   245,   607,    -1,   608,    -1,   609,    -1,
     610,    -1,   625,    -1,   611,    -1,   619,    -1,   612,    -1,
     626,    -1,   100,   273,    -1,   100,   262,    -1,   265,    -1,
     280,    -1,   250,   273,    -1,   250,   262,    -1,    56,   649,
      29,    -1,   276,    -1,    54,   276,    -1,   278,   613,    -1,
     278,   156,   613,   614,   187,    -1,    54,   278,    -1,   616,
      -1,   113,    -1,    -1,   107,   615,    -1,   616,    -1,   615,
     107,   616,    -1,    96,    29,   617,   618,    -1,    -1,   270,
      29,    -1,    -1,   629,   264,    -1,   277,   285,   620,   622,
      -1,   277,   285,   113,   622,    -1,    54,   277,   285,    -1,
      96,    29,    -1,   156,   621,   187,    -1,    29,    -1,   621,
     107,    29,    -1,    -1,   623,    -1,   624,    -1,   623,   624,
      -1,   200,   620,    -1,   136,   620,    -1,   263,    29,    -1,
     282,    -1,    54,   282,    -1,    96,   216,    -1,    96,   253,
      -1,   254,   249,    -1,   266,   629,   279,    -1,   255,   471,
      -1,    96,   129,   471,    -1,    96,    52,   471,    -1,   256,
     471,   198,   471,    -1,   271,   631,    -1,   251,   631,    -1,
     274,    -1,   267,    -1,   284,   249,   473,    -1,   154,   185,
      -1,   154,   409,   185,    -1,   309,   310,    -1,   309,   409,
     310,    -1,   311,   312,    -1,   311,   409,   312,    -1,   153,
     637,   184,    -1,   410,   121,   410,    -1,   637,   107,   410,
     121,   410,    -1,   225,   313,   637,   232,   410,    -1,   225,
     313,   410,   232,   410,    96,   315,   410,    -1,   314,   313,
     410,   198,   410,    -1,   223,   313,   504,   156,   410,   187,
      -1,   227,   313,   504,   156,   410,   187,    94,   410,    -1,
     228,   313,   229,   230,   504,   156,   410,   187,   236,   410,
      -1,   644,    -1,   645,    -1,   646,    -1,   318,   156,   187,
      -1,   316,   156,   187,    -1,   317,   156,   187,    -1,    29,
      -1,    16,    -1,   649,    -1,   650,    -1,    97,    -1,    39,
      -1,    44,    -1,    45,    -1,   152,    -1,    48,    -1,   224,
      -1,    59,    -1,    61,    -1,    62,    -1,    70,    -1,    73,
      -1,    72,    -1,   210,    -1,   242,    -1,   651,    -1,    24,
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
     514,   519,   526,   528,   531,   540,   550,   552,   556,   558,
     561,   564,   568,   580,   595,   609,   632,   634,   636,   638,
     639,   641,   643,   644,   646,   649,   651,   654,   656,   658,
     660,   662,   664,   666,   668,   670,   672,   674,   676,   678,
     682,   685,   689,   693,   696,   700,   703,   707,   710,   714,
     719,   725,   731,   734,   739,   745,   749,   753,   756,   759,
     768,   772,   774,   777,   781,   783,   787,   789,   791,   793,
     795,   797,   799,   801,   803,   805,   807,   809,   811,   813,
     815,   817,   819,   821,   823,   826,   829,   832,   835,   837,
     839,   842,   847,   851,   857,   862,   866,   868,   870,   872,
     874,   876,   878,   880,   882,   884,   887,   891,   893,   898,
     902,   908,   913,   920,   925,   932,   938,   946,   951,   957,
     963,   970,   974,   978,   981,   983,   987,   992,   998,  1002,
    1009,  1014,  1020,  1022,  1025,  1029,  1031,  1034,  1036,  1043,
    1047,  1051,  1054,  1058,  1060,  1064,  1067,  1072,  1078,  1085,
    1091,  1095,  1098,  1102,  1107,  1109,  1113,  1115,  1118,  1120,
    1122,  1124,  1127,  1130,  1133,  1137,  1139,  1141,  1144,  1147,
    1150,  1156,  1162,  1164,  1169,  1173,  1178,  1187,  1189,  1192,
    1196,  1199,  1203,  1212,  1214,  1217,  1221,  1230,  1241,  1250,
    1261,  1263,  1266,  1271,  1279,  1281,  1284,  1289,  1297,  1306,
    1308,  1312,  1314,  1318,  1320,  1324,  1328,  1332,  1336,  1337,
    1342,  1346,  1350,  1354,  1356,  1362,  1364,  1368,  1369,  1371,
    1373,  1377,  1379,  1383,  1387,  1389,  1393,  1397,  1401,  1405,
    1407,  1411,  1415,  1417,  1421,  1425,  1427,  1432,  1434,  1439,
    1441,  1446,  1448,  1453,  1455,  1458,  1460,  1462,  1465,  1468,
    1470,  1472,  1474,  1476,  1478,  1480,  1482,  1484,  1486,  1488,
    1490,  1492,  1497,  1503,  1509,  1516,  1520,  1525,  1527,  1530,
    1534,  1537,  1540,  1542,  1545,  1548,  1550,  1552,  1554,  1558,
    1562,  1564,  1566,  1568,  1571,  1573,  1576,  1579,  1581,  1584,
    1587,  1590,  1593,  1596,  1599,  1602,  1604,  1607,  1610,  1612,
    1615,  1618,  1621,  1624,  1627,  1629,  1631,  1633,  1635,  1637,
    1639,  1641,  1643,  1645,  1648,  1652,  1657,  1659,  1662,  1666,
    1668,  1670,  1672,  1674,  1676,  1678,  1680,  1682,  1684,  1686,
    1688,  1690,  1692,  1694,  1696,  1698,  1700,  1702,  1704,  1707,
    1710,  1714,  1716,  1721,  1726,  1730,  1735,  1737,  1741,  1743,
    1745,  1747,  1749,  1751,  1756,  1762,  1771,  1781,  1791,  1802,
    1804,  1807,  1809,  1812,  1819,  1820,  1822,  1826,  1830,  1831,
    1833,  1835,  1837,  1840,  1843,  1844,  1846,  1848,  1850,  1853,
    1856,  1858,  1860,  1862,  1864,  1866,  1868,  1870,  1872,  1874,
    1876,  1878,  1882,  1886,  1889,  1893,  1897,  1900,  1902,  1904,
    1906,  1908,  1910,  1912,  1917,  1921,  1929,  1933,  1941,  1946,
    1951,  1955,  1963,  1965,  1968,  1971,  1973,  1976,  1980,  1982,
    1984,  1986,  1988,  1990,  1994,  1998,  2000,  2002,  2004,  2006,
    2010,  2012,  2014,  2016,  2018,  2020,  2022,  2024,  2026,  2028,
    2030,  2034,  2038,  2043,  2048,  2052,  2056,  2060,  2065,  2070,
    2074,  2079,  2086,  2091,  2098,  2103,  2107,  2112,  2119,  2126,
    2131,  2138,  2145,  2150,  2152,  2155,  2157,  2159,  2161,  2165,
    2169,  2171,  2173,  2178,  2184,  2191,  2195,  2199,  2203,  2207,
    2213,  2221,  2229,  2235,  2241,  2247,  2255,  2263,  2269,  2275,
    2279,  2283,  2289,  2297,  2303,  2311,  2313,  2318,  2322,  2328,
    2330,  2333,  2337,  2341,  2343,  2347,  2350,  2351,  2353,  2355,
    2358,  2360,  2364,  2366,  2370,  2372,  2377,  2379,  2382,  2386,
    2387,  2389,  2390,  2392,  2397,  2400,  2404,  2406,  2407,  2409,
    2414,  2415,  2417,  2420,  2422,  2426,  2427,  2429,  2432,  2435,
    2437,  2438,  2440,  2441,  2443,  2445,  2447,  2449,  2451,  2453,
    2455,  2459,  2463,  2465,  2467,  2469,  2472,  2476,  2478,  2480,
    2482,  2484,  2486,  2488,  2490,  2492,  2495,  2498,  2500,  2502,
    2505,  2508,  2512,  2514,  2517,  2520,  2526,  2529,  2531,  2533,
    2534,  2537,  2539,  2543,  2548,  2549,  2552,  2553,  2556,  2561,
    2566,  2570,  2573,  2577,  2579,  2583,  2584,  2586,  2588,  2591,
    2594,  2597,  2600,  2602,  2605,  2608,  2611,  2614,  2618,  2621,
    2625,  2629,  2634,  2637,  2640,  2642,  2644,  2648,  2651,  2655,
    2658,  2662,  2665,  2669,  2673,  2677,  2683,  2689,  2698,  2704,
    2711,  2720,  2731,  2733,  2735,  2737,  2741,  2745,  2749,  2751,
    2753,  2755,  2757,  2759,  2761,  2763,  2765,  2767,  2769,  2771,
    2773,  2775,  2777,  2779,  2781,  2783,  2785,  2787,  2789,  2791,
    2793,  2795,  2797,  2799,  2801,  2803,  2805,  2807,  2809,  2811,
    2813,  2815,  2817,  2819,  2821,  2823,  2825,  2827,  2829,  2831,
    2833,  2835,  2837,  2839,  2841,  2843,  2845,  2847,  2849,  2851,
    2853,  2855,  2857,  2859,  2861,  2863,  2865,  2867,  2869,  2871,
    2873,  2875,  2877,  2879,  2881,  2883,  2885,  2887,  2889,  2891,
    2893,  2895,  2897,  2899,  2901,  2903,  2905,  2907,  2909,  2911,
    2913,  2915,  2917,  2919,  2921,  2923,  2925,  2927,  2929,  2931,
    2933,  2935,  2937,  2939,  2941,  2943,  2945,  2947,  2949,  2951,
    2953,  2955,  2957,  2959,  2961,  2963,  2965,  2967,  2969,  2971,
    2973,  2975,  2977,  2979,  2981,  2983,  2985,  2987,  2989,  2991,
    2993,  2995,  2997,  2999,  3001,  3003,  3005,  3007,  3009,  3011,
    3013,  3015,  3017,  3019,  3021,  3023,  3025,  3027,  3029,  3031,
    3033,  3035,  3037,  3039,  3041,  3043,  3045,  3047,  3049,  3051,
    3053,  3055,  3057,  3059,  3061,  3063,  3065,  3067,  3069,  3071,
    3073,  3075,  3077,  3079,  3081,  3083,  3085,  3087,  3089,  3091,
    3093,  3095,  3097,  3099,  3101,  3103,  3105,  3107,  3109,  3111,
    3113,  3115,  3117,  3119,  3121,  3123,  3125,  3127,  3129,  3131,
    3133,  3135,  3137,  3139,  3141,  3143,  3145,  3147,  3149,  3151,
    3153,  3155,  3157,  3159,  3161,  3163,  3165,  3167,  3169,  3171,
    3173,  3175,  3177,  3179,  3181,  3183,  3185,  3187,  3189,  3191,
    3193,  3195,  3197,  3199
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
    1940,  1947,  1957,  1961,  1971,  1979,  1990,  1996,  2005,  2010,
    2017,  2024,  2035,  2045,  2055,  2065,  2083,  2103,  2107,  2112,
    2119,  2123,  2128,  2135,  2140,  2152,  2159,  2171,  2172,  2173,
    2174,  2175,  2176,  2177,  2179,  2180,  2181,  2182,  2183,  2188,
    2193,  2201,  2218,  2226,  2234,  2241,  2248,  2258,  2270,  2283,
    2295,  2311,  2319,  2327,  2335,  2350,  2355,  2363,  2377,  2394,
    2419,  2427,  2434,  2445,  2455,  2460,  2475,  2476,  2477,  2478,
    2479,  2480,  2485,  2486,  2489,  2490,  2491,  2492,  2493,  2496,
    2497,  2498,  2499,  2500,  2505,  2519,  2527,  2532,  2540,  2545,
    2550,  2558,  2567,  2579,  2589,  2602,  2610,  2611,  2612,  2617,
    2618,  2619,  2620,  2621,  2626,  2633,  2643,  2651,  2658,  2668,
    2678,  2688,  2698,  2708,  2718,  2728,  2738,  2749,  2758,  2768,
    2778,  2794,  2803,  2812,  2820,  2826,  2838,  2846,  2856,  2864,
    2876,  2882,  2893,  2895,  2899,  2907,  2911,  2916,  2920,  2924,
    2928,  2938,  2946,  2953,  2959,  2969,  2973,  2977,  2985,  2993,
    3001,  3013,  3021,  3027,  3037,  3043,  3053,  3057,  3067,  3073,
    3079,  3085,  3094,  3103,  3112,  3125,  3129,  3137,  3143,  3153,
    3161,  3170,  3183,  3190,  3202,  3206,  3218,  3225,  3231,  3240,
    3247,  3253,  3264,  3271,  3277,  3286,  3295,  3302,  3313,  3320,
    3332,  3338,  3350,  3356,  3367,  3373,  3384,  3390,  3401,  3410,
    3414,  3423,  3427,  3435,  3439,  3449,  3456,  3465,  3475,  3474,
    3488,  3497,  3506,  3519,  3523,  3535,  3539,  3547,  3550,  3557,
    3561,  3570,  3574,  3578,  3586,  3590,  3596,  3602,  3608,  3618,
    3622,  3626,  3634,  3638,  3644,  3654,  3658,  3668,  3672,  3682,
    3686,  3696,  3700,  3710,  3714,  3722,  3726,  3730,  3734,  3744,
    3748,  3752,  3760,  3764,  3768,  3772,  3776,  3780,  3788,  3792,
    3796,  3804,  3808,  3812,  3816,  3827,  3833,  3843,  3849,  3859,
    3863,  3867,  3905,  3909,  3919,  3929,  3942,  3951,  3961,  3965,
    3974,  3978,  3987,  3993,  4001,  4007,  4019,  4025,  4035,  4039,
    4043,  4047,  4051,  4057,  4063,  4071,  4075,  4083,  4087,  4098,
    4102,  4106,  4112,  4116,  4130,  4134,  4142,  4146,  4156,  4160,
    4164,  4168,  4177,  4181,  4185,  4189,  4197,  4203,  4213,  4221,
    4225,  4229,  4233,  4237,  4241,  4245,  4249,  4253,  4257,  4262,
    4266,  4270,  4274,  4282,  4286,  4294,  4301,  4308,  4319,  4327,
    4331,  4339,  4347,  4355,  4409,  4413,  4426,  4432,  4442,  4446,
    4454,  4458,  4462,  4470,  4480,  4490,  4500,  4510,  4520,  4535,
    4541,  4552,  4558,  4569,  4580,  4582,  4586,  4591,  4601,  4604,
    4611,  4617,  4623,  4631,  4644,  4647,  4654,  4660,  4666,  4673,
    4684,  4688,  4698,  4702,  4712,  4716,  4720,  4725,  4734,  4740,
    4746,  4752,  4760,  4765,  4773,  4778,  4786,  4794,  4799,  4804,
    4809,  4814,  4819,  4828,  4836,  4840,  4857,  4861,  4869,  4877,
    4885,  4889,  4897,  4903,  4913,  4921,  4925,  4929,  4964,  4970,
    4976,  4986,  4990,  4994,  4998,  5002,  5006,  5010,  5017,  5023,
    5033,  5041,  5045,  5049,  5053,  5057,  5061,  5065,  5069,  5073,
    5081,  5089,  5093,  5097,  5107,  5115,  5123,  5127,  5131,  5139,
    5143,  5149,  5155,  5159,  5169,  5177,  5181,  5187,  5196,  5205,
    5211,  5217,  5227,  5244,  5251,  5266,  5302,  5306,  5314,  5322,
    5334,  5338,  5346,  5354,  5358,  5369,  5386,  5392,  5398,  5408,
    5412,  5418,  5424,  5428,  5434,  5438,  5444,  5450,  5457,  5467,
    5472,  5480,  5486,  5496,  5518,  5527,  5533,  5546,  5560,  5567,
    5573,  5583,  5592,  5600,  5606,  5624,  5632,  5636,  5643,  5648,
    5656,  5660,  5667,  5671,  5678,  5682,  5689,  5693,  5702,  5715,
    5718,  5726,  5729,  5737,  5745,  5753,  5757,  5765,  5768,  5776,
    5788,  5791,  5799,  5811,  5817,  5827,  5830,  5838,  5842,  5846,
    5854,  5857,  5865,  5868,  5876,  5880,  5884,  5888,  5892,  5900,
    5908,  5920,  5932,  5936,  5940,  5948,  5954,  5964,  5968,  5972,
    5976,  5980,  5984,  5988,  5992,  6000,  6004,  6008,  6012,  6020,
    6026,  6036,  6046,  6050,  6058,  6068,  6079,  6086,  6090,  6098,
    6101,  6108,  6113,  6122,  6132,  6135,  6142,  6146,  6154,  6163,
    6170,  6180,  6184,  6191,  6197,  6207,  6210,  6217,  6222,  6234,
    6242,  6254,  6262,  6266,  6274,  6278,  6282,  6290,  6298,  6302,
    6306,  6310,  6318,  6326,  6338,  6342,  6350,  6364,  6368,  6375,
    6380,  6388,  6393,  6402,  6410,  6416,  6426,  6432,  6439,  6446,
    6453,  6460,  6467,  6471,  6475,  6482,  6489,  6496,  6508,  6512,
    6513,  6526,  6527,  6528,  6529,  6530,  6531,  6532,  6533,  6534,
    6535,  6536,  6537,  6538,  6539,  6540,  6541,  6545,  6546,  6547,
    6548,  6549,  6550,  6551,  6552,  6553,  6554,  6555,  6556,  6557,
    6558,  6559,  6560,  6561,  6562,  6563,  6564,  6565,  6566,  6567,
    6568,  6569,  6570,  6571,  6572,  6573,  6574,  6575,  6576,  6577,
    6578,  6579,  6580,  6581,  6582,  6583,  6584,  6585,  6586,  6587,
    6588,  6589,  6590,  6591,  6592,  6593,  6594,  6595,  6596,  6597,
    6598,  6599,  6600,  6601,  6602,  6603,  6604,  6605,  6606,  6607,
    6608,  6609,  6610,  6611,  6612,  6613,  6614,  6615,  6616,  6617,
    6618,  6619,  6620,  6621,  6622,  6623,  6624,  6625,  6626,  6627,
    6628,  6629,  6630,  6631,  6632,  6633,  6634,  6635,  6636,  6637,
    6638,  6639,  6640,  6641,  6642,  6643,  6644,  6645,  6646,  6647,
    6648,  6649,  6650,  6651,  6652,  6653,  6654,  6655,  6656,  6657,
    6658,  6659,  6660,  6661,  6662,  6663,  6664,  6665,  6666,  6667,
    6668,  6669,  6670,  6671,  6672,  6673,  6674,  6675,  6676,  6677,
    6678,  6679,  6680,  6681,  6682,  6683,  6684,  6685,  6686,  6687,
    6688,  6689,  6690,  6691,  6692,  6693,  6694,  6695,  6696,  6697,
    6698,  6699,  6700,  6701,  6702,  6703,  6704,  6705,  6706,  6707,
    6708,  6709,  6710,  6711,  6712,  6713,  6714,  6715,  6716,  6717,
    6718,  6719,  6720,  6721,  6722,  6723,  6724,  6725,  6726,  6727,
    6728,  6729,  6730,  6731,  6732,  6733,  6734,  6735,  6736,  6737,
    6738,  6739,  6740,  6741,  6742,  6743,  6744,  6745,  6746,  6747,
    6748,  6749,  6750,  6755
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
  const int xquery_parser::yylast_ = 15267;
  const int xquery_parser::yynnts_ = 321;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 602;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 331;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 585;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


/* Line 1054 of lalr1.cc  */
#line 1 "[Bison:b4_percent_define_default]"

} // zorba

/* Line 1054 of lalr1.cc  */
#line 16988 "/home/markos/zorba/repo/jsoniq-deactivated/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1056 of lalr1.cc  */
#line 6759 "/home/markos/zorba/repo/jsoniq-deactivated/src/compiler/parser/xquery_parser.y"


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

